/* -*- Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */

// # Copyright (c) 2014 Peng Wang

// # This is hash routing, ECMP implementation, with CONGA
// # path selection support.  
// # 
// # This program is free software: you can redistribute it and/or modify
// # it under the terms of the GNU General Public License as published by
// # the Free Software Foundation, either version 3 of the License, or
// # (at your option) any later version.

// # This program is distributed in the hope that it will be useful,
// # but WITHOUT ANY WARRANTY; without even the implied warranty of
// # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// # GNU General Public License for more details.

// # You should have received a copy of the GNU General Public License
// # along with this program.  If not, see <http://www.gnu.org/licenses/>.

// # Author: Peng Wang <pewang@cityu.edu.hk>

#include "ns3/log.h"
#include "ns3/object.h"
#include "ns3/packet.h"
#include "ns3/net-device.h"
#include "ns3/ipv4-route.h"
#include "ns3/ipv4-routing-table-entry.h"
#include "hash-routing.h"
#include "hsieh.h"
#include "ns3/boolean.h"
#include "ns3/uinteger.h"
#include "ns3/tcp-header.h"
#include "ns3/udp-header.h"

#include "ns3/channel.h"
#include "ns3/node.h"
#include "ns3/random-variable.h"
#include "ns3/point-to-point-net-device.h"
#include "ns3/sp-net-device.h"
#include "ns3/queue.h"
#include "ns3/conga-header.h"
#include "ns3/exp-header.h"
#include "ns3/double.h"

#define ECMP 0
#define OPTIMAL 1
#define EXPEDITUS 2
#define CONGA 3

NS_LOG_COMPONENT_DEFINE ("HashRouting");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (HashRouting);

inline unsigned HostAddrToSubtree(uint32_t addr)
{
	return ((addr & 0x00FF0000) >> 17);
};

inline unsigned HostAddrToEdge(uint32_t addr)
{
	return ((addr & 0x0000FF00) >> 10);
};

inline unsigned HostAddrToPort(uint32_t addr)
{
	return (addr & 0x000000FF);
};

TypeId 
HashRouting::GetTypeId (void)
{ 
  static TypeId tid = TypeId ("ns3::HashRouting")
    .SetParent<Ipv4RoutingProtocol> ()
    .AddAttribute ("RoutingEntryLifetime",
                   "Lifetime for routing entry",
                   TimeValue (Seconds (0.1)),
                   MakeTimeAccessor (&HashRouting::m_lifetime),
                   MakeTimeChecker ())
     // Set life time of congestion entries in congestion-to-leaf table and congestion-from-leaf table
    .AddAttribute ("CongestionEntryLifetime",
                   "Lifetime for entry in cogestion table",
                   TimeValue (Seconds (0.01)), // 10 ms
                   MakeTimeAccessor (&HashRouting::m_congLifetime),
                   MakeTimeChecker ())
      // Scheme used to load balance traffic
    .AddAttribute ("Scheme",
                   "Scheme used to select path",
                   UintegerValue (0),
                   MakeUintegerAccessor (&HashRouting::m_scheme),                    
                   MakeUintegerChecker<uint32_t> ())
      // oversubscription ratio at ToR layer
      .AddAttribute ("ToROsp", "network oversubscription ratio at ToR layer",
                    UintegerValue (1),
                    MakeUintegerAccessor (&HashRouting::m_torosp),                    
                    MakeUintegerChecker<uint32_t> ())
    	.AddAttribute ("CoreOsp", "oversubscription ratio at core layer",
           					 DoubleValue (1),
            				 MakeDoubleAccessor (&HashRouting::m_coreosp),                    
            				 MakeDoubleChecker<double> ())
     // gap for flowlet
      .AddAttribute ("FlowletGap",
                    "gap for flowlet switching",
                    TimeValue (Seconds (2e-4)), // 200 us
                    MakeTimeAccessor (&HashRouting::m_flowletGap),
                    MakeTimeChecker ())
    ;
  return tid;
}

HashRouting::HashRouting ()
{
  m_iniTable = false;
  NS_LOG_FUNCTION_NOARGS ();
}

HashRouting::~HashRouting ()
{
  NS_LOG_FUNCTION_NOARGS ();
}

void
HashRouting::AddRoute (const Ipv4Address& dest, const Ipv4Mask& mask, uint32_t interface)
{
	Ptr<DestRoute> r = Create<DestRoute>(dest, mask, interface);
	m_destRouteTable.push_back(r);
	NS_LOG_LOGIC("New route for interface "<< interface <<": "<< dest <<"/"<< mask);
};
        
flowid
HashRouting::GetTuple(Ptr<Packet> packet, Ipv4Header& header)
{
	flowid tuple = flowid(header);
	if (header.GetProtocol() == 17) {
		// UDP packet
		UdpHeader udph;
		packet->PeekHeader(udph);
		tuple.SetSPort(udph.GetSourcePort());
		// temp = static_cast<uint16_t>(UniformVariable(0,100).GetValue());
		tuple.SetDPort(udph.GetDestinationPort());
	} else if (header.GetProtocol() == 6) {
		// TCP packet
		TcpHeader tcph;
		packet->PeekHeader(tcph);
		// uint16_t temp=0;
		tuple.SetSPort(tcph.GetSourcePort());
		// temp = static_cast<uint16_t>(UniformVariable(0,100).GetValue());
		tuple.SetDPort(tcph.GetDestinationPort());
	};
	return tuple;
};

uint32_t
HashRouting::Lookup (flowid fid)
{
	NS_LOG_FUNCTION(this);
	uint32_t outPort;
	const Ipv4Address destAddr = Ipv4Address(fid.GetDAddr());
	if (RequestDestRoute(destAddr, outPort) ) {
		NS_LOG_LOGIC("Destination "<< destAddr << " routed to port "<< outPort);
  } 
  else 
  {
	   // Hash-based routing
      uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
      outPort = (Hash(fid) % numUpPorts) + m_torosp*numUpPorts + 1;

    if (IsAgg())
    {
      numUpPorts = (m_ipv4->GetNInterfaces()-1)/2;
      outPort = (Hash(fid) % int(numUpPorts/m_coreosp)) + numUpPorts + 1;
    }
		
		NS_LOG_LOGIC("Packet of "<< fid <<" hash-routed to port "<< outPort);
	};
        
	return outPort;
}


Ptr<Ipv4Route>
HashRouting::RouteOutput (Ptr<Packet> p, Ipv4Header &header, Ptr<NetDevice> oif, Socket::SocketErrno &sockerr)
{      
	// Hash-routing is for unicast destination only
	Ipv4Address a = header.GetDestination();
	if (a.IsMulticast() || a.IsBroadcast()) {
		NS_LOG_LOGIC("Non-unicast destination is not supported");
		sockerr = Socket::ERROR_NOROUTETOHOST;
		return 0;
	};
	// Check for a route, and construct the Ipv4Route object
	sockerr = Socket::ERROR_NOTERROR;

	uint32_t iface = Lookup(GetTuple(p, header));


   	Ptr<NetDevice> dev = m_ipv4->GetNetDevice(iface); // Convert output port to device

   	Ptr<Channel> channel = dev->GetChannel(); // Channel used by the device
	uint32_t otherEnd = (channel->GetDevice(0)==dev)?1:0; // Which end of the channel?
	Ptr<Node> nextHop = channel->GetDevice(otherEnd)->GetNode(); // Node at other end
   	uint32_t nextIf = channel->GetDevice(otherEnd)->GetIfIndex(); // Iface num at other end
	Ipv4Address nextHopAddr = nextHop->GetObject<Ipv4>()->GetAddress(nextIf,0).GetLocal(); // Addr of other end
//std::cout << "next hop: " << nextHopAddr << std::endl;
	Ptr<Ipv4Route> r = Create<Ipv4Route> ();
	r->SetOutputDevice(m_ipv4->GetNetDevice(iface));
	r->SetGateway(nextHopAddr);
	r->SetSource(m_ipv4->GetAddress(iface,0).GetLocal());
	r->SetDestination(a);
     
	return r;
}

bool 
HashRouting::RouteInput  (Ptr<Packet> p, Ipv4Header &header, Ptr<const NetDevice> idev,
		UnicastForwardCallback ucb, MulticastForwardCallback mcb,
		LocalDeliverCallback lcb, ErrorCallback ecb) 
{ 
	NS_LOG_FUNCTION (this << p << header << header.GetSource () << header.GetDestination () << idev);
	// Check if input device supports IP
	NS_ASSERT (m_ipv4->GetInterfaceForDevice (idev) >= 0);
	uint32_t iif = m_ipv4->GetInterfaceForDevice (idev);
	uint32_t outPort;
	Ipv4Address a = header.GetDestination();
      
        // Hash-routing is for unicast destination only
	if (a.IsMulticast() || a.IsBroadcast()) {
		NS_LOG_LOGIC("Non-unicast destination is not supported");
		return false;
	};

	// Check if the destination is local
	if (IsLocal(a)) {
		NS_LOG_LOGIC ("local destination- calling local callback");
		lcb (p, header, iif);
		return true;
	};
	// Check if input device supports IP forwarding
	if (m_ipv4->IsForwarding (iif) == false) {
		NS_LOG_LOGIC ("Forwarding disabled for this interface");
		ecb (p, header, Socket::ERROR_NOROUTETOHOST);
		return false;
	}

          if (IsSourceEdge(header) || IsDstEdge(header))
          {
                // Initiate congestion-from-rack table, congestion-to-rack table and round-robin counter for each rack
                if (!m_iniTable)
                { 
                  uint32_t numRacks = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
                  IniMetricTable(numRacks);
                  IniFB_MetricTable(numRacks);
                  IniCounter(numRacks);
                  m_iniTable=true;
                }  
          } 

        // Next, try to find a route
        outPort = Lookup(GetTuple(p, header)); 


       if ((m_scheme == CONGA) && IsIntraPodTraffic(header))
       {
         if (IsSourceEdge(header))
         {
             uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
             uint32_t pathID = outPort - m_torosp*numUpPorts - 1;
             TcpHeader tcpHeader;    
             CongaHeader ch;

             // Insert LBTag and CE
             CongaRoute(GetTuple(p, header), pathID);

             ch.SetLBTag(uint8_t(pathID));
             ch.SetCE(uint8_t(GetOutRate(pathID+numUpPorts*m_torosp+1))); 

             // Insert FB_LBTag and FB_Metric
             uint32_t DestLeaf = (header.GetDestination().Get() & 0x0000FC00) >> 10;
             ch.SetFB_LBTag(uint8_t(m_counter[DestLeaf]));
             m_counter[DestLeaf] = (m_counter[DestLeaf]+1)%numUpPorts;

             for (std::vector<Ptr<MetricRecord> >::iterator iter = FB_MetricTable[DestLeaf].begin(); iter != FB_MetricTable[DestLeaf].end(); iter++)  
            {
                 if (Simulator::Now()-(*iter)->last > m_congLifetime)
                 {
                    (*iter)->metric = 0;
                    (*iter)->last = Simulator::Now();
                 }
            }
             ch.SetFB_Metric((FB_MetricTable[DestLeaf][uint32_t(ch.GetFB_LBTag())])->metric);
             p->RemoveHeader(tcpHeader); 
             p->AddHeader(ch);         
             p->AddHeader(tcpHeader);
             // TODO
             header.SetPayloadSize(header.GetPayloadSize()+4); 
             // index of netdevice
             outPort = pathID+numUpPorts*m_torosp+1;
       }

        // Update CE. Note that congestion metric is the sum of queue occupancy of output port at each switch on the end-to-end path. 
       if (IsAgg())
       {   
             TcpHeader tcpHeader;     
             CongaHeader ch;
             p->RemoveHeader(tcpHeader);  
             p->PeekHeader (ch);
             p->AddHeader(tcpHeader);
            if (GetOutRate(Lookup(GetTuple(p, header)) > ch.GetCE()))
                ch.SetCE(uint8_t(GetOutRate(Lookup(GetTuple(p, header)))));
       }

        if (IsDstEdge(header))
        {
             // Remove conga header
             TcpHeader tcpHeader;     
             CongaHeader ch;
             p->RemoveHeader(tcpHeader);
             p->RemoveHeader(ch);
             p->AddHeader(tcpHeader);
             header.SetPayloadSize(header.GetPayloadSize()-4);  
  
             // Update Congestion-From-Leaf Table
             uint32_t SourceLeaf = (header.GetSource().Get() & 0x0000FC00) >> 10;
             (FB_MetricTable[SourceLeaf][uint32_t(ch.GetLBTag())])->metric = ch.GetCE();
             (FB_MetricTable[SourceLeaf][uint32_t(ch.GetLBTag())])->last = Simulator::Now();

             // Update Congestion-To-Leaf Table 
             (MetricTable[SourceLeaf][uint32_t(ch.GetFB_LBTag())])->metric = ch.GetFB_Metric();
             (MetricTable[SourceLeaf][uint32_t(ch.GetFB_LBTag())])->last = Simulator::Now();
        }
      }

      if ((m_scheme == CONGA) && IsInterPodTraffic(header))
      {
        if (IsSourceEdge(header))
        {
             uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
             uint32_t pathID = outPort - m_torosp*numUpPorts - 1;

             // Insert LBTag and CE
             FlowletRoute(GetTuple(p, header), pathID);

             // index of netdevice
             outPort = pathID+numUpPorts*m_torosp+1;
        }
      }
	
        if ((m_scheme == EXPEDITUS) && IsIntraPodTraffic(header))
        {
          TcpHeader tcpHeader;  
          ExpHeader expHeader;   
          p->PeekHeader (tcpHeader);
          
          // SYN-ACK packet 
          if ((tcpHeader.GetFlags() & (TcpHeader::SYN)) && (tcpHeader.GetFlags() & (TcpHeader::ACK)))
          { 
             uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
             if (IsSourceEdge(header))        
             {
                std::vector<uint8_t> pathCong(numUpPorts);
                for (uint32_t i=0; i < numUpPorts; i++)
                {
                    pathCong[i] = GetInRate(i+1+m_torosp*numUpPorts);
                }  
                expHeader.SetPathcong(pathCong, uint8_t(numUpPorts)); 
                p->RemoveHeader(tcpHeader);
                p->AddHeader(expHeader);
                p->AddHeader(tcpHeader);
                header.SetPayloadSize(20+numUpPorts+1);
             }
             
              if (IsDstEdge(header))
              {
                 std::vector<uint32_t> pathCong(numUpPorts);
                 p->RemoveHeader(tcpHeader);
                 p->RemoveHeader(expHeader);
                 p->AddHeader(tcpHeader);
                 header.SetPayloadSize(20);  
                 for (uint32_t i=0; i < numUpPorts; i++)
                 {
                      if (GetOutRate(i+1+m_torosp*numUpPorts) > expHeader.GetPathcong()[i])
                          pathCong[i] = GetOutRate(i+1+m_torosp*numUpPorts);
                      else 
                          pathCong[i] = uint32_t(expHeader.GetPathcong()[i]);
                  } 

                  std::vector <uint32_t> indices;
                  std::vector <uint32_t>::iterator it = pathCong.begin();
                  while (it != pathCong.end())
                  {
                    if ((*it) == *min_element(pathCong.begin(), pathCong.end()))
                       indices.push_back( distance(pathCong.begin(), it));
                    it++;
                  }

                  std::random_shuffle(indices.begin(), indices.end());
                  flowid ftp = flowid(header.GetDestination().Get(), header.GetSource().Get(), header.GetProtocol(), tcpHeader.GetDestinationPort(), tcpHeader.GetSourcePort());
                   Ptr<FlowRoute> f = Create<FlowRoute>(ftp, Simulator::Now(), *indices.begin());
                   m_flowRouteTable.push_back(f);   
              }  
          } 
  
          if (IsSourceEdge(header))  
          {
             uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
             uint32_t pathID = outPort - m_torosp*numUpPorts - 1;
             ExpRoute(GetTuple(p, header), pathID);
             outPort = pathID+numUpPorts*m_torosp+1;
          }
        } 

        if ((m_scheme == OPTIMAL) && IsIntraPodTraffic(header))
        {
          TcpHeader tcpHeader;  
          p->PeekHeader (tcpHeader);
          // SYN packet 
          if((tcpHeader.GetFlags() & (TcpHeader::SYN)) && (!(tcpHeader.GetFlags() & (TcpHeader::ACK))) && IsSourceEdge(header))
          {
            uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
            std::vector<uint32_t> pathCong(numUpPorts);
            for (uint32_t i=0; i < numUpPorts; i++)
            {
              Ptr<NetDevice> dev = m_ipv4->GetNetDevice(m_torosp*numUpPorts+1+i); // Convert output port to device
              Ptr<SpNetDevice> spdev = StaticCast<SpNetDevice> (dev);                      
              uint32_t outrate = spdev -> OutRate ();
              Ptr<Channel> channel = dev->GetChannel(); // Channel used by the device
              uint32_t otherEnd = (channel->GetDevice(0)==dev)?1:0; // Which end of the channel?
              Ptr<Node> nextHop = channel->GetDevice(otherEnd)->GetNode(); // Get aggregation switch
              uint32_t aggPort = (header.GetDestination().Get() & 0x0000FC00) >> 10;  // Get the index of destination edge
              dev = nextHop->GetDevice(1+aggPort);
              spdev = StaticCast<SpNetDevice> (dev);                      
              pathCong[i] = ((spdev -> OutRate ()) > outrate) ? (spdev -> OutRate ()):outrate; // Get the bottleneck link load of each path
            }
            Ptr<FlowRoute> f = Create<FlowRoute>(GetTuple(p, header), Simulator::Now(), MinValue(pathCong));
            m_flowRouteTable.push_back(f);   
          }
          if (IsSourceEdge(header))  
          {
             uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
             uint32_t pathID = outPort - m_torosp*numUpPorts - 1;
             ExpRoute(GetTuple(p, header), pathID);
             outPort = pathID+numUpPorts*m_torosp+1;
          }
        }  

        if ((m_scheme == EXPEDITUS) && IsInterPodTraffic(header))
        {
           TcpHeader tcpHeader;  
           ExpHeader expHeader;   
           p->PeekHeader (tcpHeader);
           // SYN packet          
           if ((tcpHeader.GetFlags() & (TcpHeader::SYN)) && (!(tcpHeader.GetFlags() & (TcpHeader::ACK))))            
           {
               uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
               if (IsSourceEdge(header))         
               {
                   std::vector<uint8_t> pathCong(numUpPorts); // Vector created for storing NCIT (Northbound Congestion Information Table)
                   for (uint32_t i=0; i<numUpPorts; i++) 
                   {    
                       pathCong[i] = uint8_t(GetOutRate(i+m_torosp*numUpPorts+1));
                   }           

                   // add the Expeditus header to SYN
                   expHeader.SetPathcong(pathCong, uint8_t(numUpPorts)); 
                   p->RemoveHeader(tcpHeader);
                   p->AddHeader(expHeader);
                   p->AddHeader(tcpHeader);
                   header.SetPayloadSize(20+numUpPorts+1);      
                }

                
                if (IsDstEdge(header)) 
                {
                    std::vector<uint32_t> pathCong(numUpPorts); // vector created for storing SCIT at destination edge switch             
                    p->RemoveHeader(tcpHeader);
                    p->RemoveHeader(expHeader);
                    p->AddHeader(tcpHeader);
                    header.SetPayloadSize(20);                     
                    for (uint32_t i=0; i < numUpPorts; i++)
                    {
                        if (GetInRate(i+1+m_torosp*numUpPorts) > expHeader.GetPathcong()[i])
                           pathCong[i] = GetInRate(i+1+m_torosp*numUpPorts);
                        else 
                           pathCong[i] = uint32_t(expHeader.GetPathcong()[i]);
                    }
                 
                    std::vector <uint32_t> indices;
                    std::vector <uint32_t>::iterator it = pathCong.begin();
                    while (it != pathCong.end())
                    {
                       if ((*it) == *min_element(pathCong.begin(), pathCong.end()))
                          indices.push_back( distance(pathCong.begin(), it));
                       it++;
                    }

                    std::random_shuffle(indices.begin(), indices.end());
                    flowid ftp = flowid(header.GetDestination().Get(), header.GetSource().Get(), header.GetProtocol(), tcpHeader.GetDestinationPort(), tcpHeader.GetSourcePort()); 
                    Ptr<FlowRoute> f = Create<FlowRoute>(ftp, Simulator::Now(), *indices.begin());
                    m_flowRouteTable.push_back(f);         
                } 
            }
               
            // SYN-ACK packet        
            if ((tcpHeader.GetFlags() & (TcpHeader::SYN)) && (tcpHeader.GetFlags() & (TcpHeader::ACK)))
            {
                uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/2; 
                if (IsSourceAggr(header))
                {          
                                
                    std::vector<uint8_t> pathCong(int(numUpPorts/m_coreosp));
                    
                    for (uint32_t i=0; i < uint32_t(numUpPorts/m_coreosp); i++)
                    {
                         pathCong[i] = uint8_t(GetInRate(i+1+numUpPorts));   
                    }  
                    expHeader.SetPathcong(pathCong, uint8_t(int(numUpPorts/m_coreosp)));
                    p->RemoveHeader(tcpHeader);
                    p->AddHeader(expHeader);
                    p->AddHeader(tcpHeader);
                    header.SetPayloadSize(20+int(numUpPorts/m_coreosp)+1);

                 }

                      
                if (IsDstAggr(header))
                {
                    std::vector<uint32_t> pathCong(int(numUpPorts/m_coreosp));             
                    p->RemoveHeader(tcpHeader);
                    p->RemoveHeader(expHeader);
                    p->AddHeader(tcpHeader);
                    header.SetPayloadSize(20);  

                    for (uint32_t i=0; i < uint32_t(numUpPorts/m_coreosp); i++)
                    {
                        if (GetOutRate(i+1+numUpPorts) > expHeader.GetPathcong()[i])
                           pathCong[i] = GetOutRate(i+1+numUpPorts);
                        else 
                           pathCong[i] = uint32_t(expHeader.GetPathcong()[i]);
                    }

                    std::vector <uint32_t> indices;
                    std::vector <uint32_t>::iterator it = pathCong.begin();
                    while (it != pathCong.end())
                    {
                       if ((*it) == *min_element(pathCong.begin(), pathCong.end()))
                          indices.push_back( distance(pathCong.begin(), it));
                       it++;
                    }
                    std::random_shuffle(indices.begin(), indices.end());
                    flowid ftp = flowid(header.GetDestination().Get(), header.GetSource().Get(), header.GetProtocol(), tcpHeader.GetDestinationPort(), tcpHeader.GetSourcePort()); 
                    Ptr<FlowRoute> f = Create<FlowRoute>(ftp, Simulator::Now(), *indices.begin());
                    m_flowRouteTable.push_back(f);          
                 }       
                      

                 if (IsDstEdge(header))     
                 {
                     numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp); 
                     flowid ftp = flowid(header.GetDestination().Get(), header.GetSource().Get(), header.GetProtocol(), tcpHeader.GetDestinationPort(), tcpHeader.GetSourcePort());      
                     Ptr<FlowRoute> f = Create<FlowRoute>(ftp, Simulator::Now(), iif-m_torosp*numUpPorts-1);
                     m_flowRouteTable.push_back(f);                  
                } 
            } 

            if (IsSourceEdge(header))  
            {
               uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
               uint32_t pathID = outPort - m_torosp*numUpPorts - 1;
               ExpRoute(GetTuple(p, header), pathID);
               outPort = pathID+numUpPorts*m_torosp+1;
           }

           if (IsSourceAggr(header))  
           {
               uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/2;
               uint32_t pathID = outPort - numUpPorts - 1;
               ExpRoute(GetTuple(p, header), pathID);
               outPort = pathID+numUpPorts+1;
           }
        }


        if ((m_scheme == OPTIMAL) && IsInterPodTraffic(header))
        {    
          TcpHeader tcpHeader;  
          p->PeekHeader (tcpHeader);
          // SYN packet 
          if((tcpHeader.GetFlags() & (TcpHeader::SYN)) && (!(tcpHeader.GetFlags() & (TcpHeader::ACK))))
          {
            if (IsSourceEdge(header))
            {
                uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
                std::vector<uint32_t> pathCong(numUpPorts*((int(numUpPorts/m_coreosp)))); // bottlenec link utilization for each path
                for (uint32_t i=0; i < numUpPorts; i++)  // Each output port for edge switch
                {
                    for (uint32_t j=0; j < (uint32_t(numUpPorts/m_coreosp)); j++) // Each output port for aggregation switch
                    {
                        Ptr<NetDevice> dev = m_ipv4->GetNetDevice(m_torosp*numUpPorts+1+i); // Convert output port to device
                        Ptr<SpNetDevice> spdev = StaticCast<SpNetDevice> (dev);                      
                        uint32_t outrate1 = spdev -> OutRate (); // source edge switch outgoing link load
                        pathCong[i*(int(numUpPorts/m_coreosp))+j] = outrate1;

                    	  Ptr<Channel> channel = dev->GetChannel(); // Channel used by the device
                      	uint32_t otherEnd = (channel->GetDevice(0)==dev)?1:0; // Which end of the channel?
                        Ptr<Node> nextHop = channel->GetDevice(otherEnd)->GetNode(); // Get aggregation switch
       	                dev = nextHop->GetDevice(numUpPorts+1+j);
                        spdev = StaticCast<SpNetDevice> (dev);  
                        uint32_t outrate2 = spdev -> OutRate (); // source aggregation switch outgoing link load
                        pathCong[i*(int(numUpPorts/m_coreosp))+j] = (outrate2 > pathCong[i*(int(numUpPorts/m_coreosp))+j]) ? (outrate2):pathCong[i*(int(numUpPorts/m_coreosp))+j];
                        channel = dev->GetChannel(); // Channel used by the device
                    	  otherEnd = (channel->GetDevice(0)==dev)?1:0; // Which end of the channel?
                        nextHop = channel->GetDevice(otherEnd)->GetNode(); // Get core switch
                        uint32_t corePort = (header.GetDestination().Get() & 0x00FE0000) >> 17; 
       	                dev = nextHop->GetDevice(corePort+1);
                        spdev = StaticCast<SpNetDevice> (dev);  
                        uint32_t outrate3 = spdev -> OutRate (); // core switch outgoing link load
                        pathCong[i*(int(numUpPorts/m_coreosp))+j] = (outrate3 > pathCong[i*(int(numUpPorts/m_coreosp))+j]) ? (outrate3):pathCong[i*(int(numUpPorts/m_coreosp))+j];

                        channel = dev->GetChannel(); // Channel used by the device
                    	  otherEnd = (channel->GetDevice(0)==dev)?1:0; // Which end of the channel?
                        nextHop = channel->GetDevice(otherEnd)->GetNode(); // Get destination aggregation switch
                        uint32_t aggPort = (header.GetDestination().Get() & 0x0000FC00) >> 10;
       	                dev = nextHop->GetDevice(aggPort+1);
                        spdev = StaticCast<SpNetDevice> (dev);  
                        uint32_t outrate4 = spdev -> OutRate (); // destination aggregation switch outgoing link load
                        pathCong[i*(int(numUpPorts/m_coreosp))+j] = (outrate4 > pathCong[i*(int(numUpPorts/m_coreosp))+j]) ? (outrate4):pathCong[i*(int(numUpPorts/m_coreosp))+j];
                    }
                }

                uint16_t pathID = uint16_t(MinValue(pathCong));

                // TODO: check fragment offset of SYN packet
                header.SetFragmentOffset(8*pathID);
                Ptr<FlowRoute> f = Create<FlowRoute>(GetTuple(p, header), Simulator::Now(), pathID/(int(numUpPorts/m_coreosp)));
                m_flowRouteTable.push_back(f); 
            }
            if (IsSourceAggr(header))
            {
              uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/2;
              // Retrieve pathid from syn packet offset field
              uint16_t pathID = header.GetFragmentOffset()/8;
              header.SetFragmentOffset(0);
              Ptr<FlowRoute> f = Create<FlowRoute>(GetTuple(p, header), Simulator::Now(), pathID%(int(numUpPorts/m_coreosp)));
              m_flowRouteTable.push_back(f);    
            }
         } 

         if (IsSourceEdge(header))  
          {
             uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
             uint32_t pathID = outPort - m_torosp*numUpPorts - 1;
             ExpRoute(GetTuple(p, header), pathID);
             outPort = pathID+numUpPorts*m_torosp+1;
         }

         if (IsSourceAggr(header))  
         {
             uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/2;
             uint32_t pathID = outPort - numUpPorts - 1;
             ExpRoute(GetTuple(p, header), pathID);
             outPort = pathID+numUpPorts+1;
         }
      }   

   	Ptr<NetDevice> dev = m_ipv4->GetNetDevice(outPort); // Convert output port to device
   	Ptr<Channel> channel = dev->GetChannel(); // Channel used by the device
	  uint32_t otherEnd = (channel->GetDevice(0)==dev)?1:0; // Which end of the channel?
	  Ptr<Node> nextHop = channel->GetDevice(otherEnd)->GetNode(); // Node at other end
   	uint32_t nextIf = channel->GetDevice(otherEnd)->GetIfIndex(); // Iface num at other end
	 Ipv4Address nextHopAddr = nextHop->GetObject<Ipv4>()->GetAddress(nextIf,0).GetLocal(); // Addr of other end

	Ptr<Ipv4Route> r = Create<Ipv4Route> ();
	r->SetOutputDevice(m_ipv4->GetNetDevice(outPort));
	r->SetGateway(nextHopAddr);
	r->SetSource(m_ipv4->GetAddress(outPort,0).GetLocal());
	r->SetDestination(a);
	NS_LOG_LOGIC ("Found unicast destination- calling unicast callback");
	ucb(r, p, header);

	return true;
}


bool
HashRouting::IsLocal (const Ipv4Address& dest)
{
	if (dest.IsBroadcast()) {
		NS_LOG_LOGIC (dest <<" is broadcast address");
		return true;
	};
	uint32_t destAddr = dest.Get();
	if (localAddrCache.size() == 0) {
		for (uint32_t j = 0; j < m_ipv4->GetNInterfaces (); j++) {
			for (uint32_t i = 0; i < m_ipv4->GetNAddresses (j); i++) {
				localAddrCache.insert( m_ipv4->GetAddress (j, i).GetLocal().Get() );
			}
		}
	};
	if (localAddrCache.find(destAddr) != localAddrCache.end()) {
		return true;
	};
	NS_LOG_LOGIC ("Address "<< dest << " is not local");
	return false;
}

void 
HashRouting::SetIpv4 (Ptr<Ipv4> ipv4)
{
	NS_LOG_FUNCTION(this << ipv4);
	NS_ASSERT (m_ipv4 == 0 && ipv4 != 0);
	m_ipv4 = ipv4;
}

uint32_t
HashRouting::Hash(const flowid& tuple) const
{
	return (*m_hash)(m_ipv4->GetAddress(1,0).GetLocal().Get(), tuple);
};

void
HashRouting::DoDispose (void)
{
	m_ipv4 = 0;
	while (!m_destRouteTable.empty()) {
		m_destRouteTable.pop_back();
	};
	Ipv4RoutingProtocol::DoDispose ();
};

bool
HashRouting::RequestDestRoute(const Ipv4Address& addr, uint32_t& outPort)
{
	NS_LOG_LOGIC("Dest IP to route: "<< std::hex << addr << std::dec);
	// Linear search for matching entry
	for(DestRouteTable::iterator it = m_destRouteTable.begin(); it != m_destRouteTable.end(); it++) {
		NS_LOG_LOGIC("Route in table: "<< std::hex << (*it)->dest << "/" << (*it)->mask << std::dec);
		if((*it)->mask.IsMatch(addr, (*it)->dest)) {
			NS_LOG_LOGIC("Route matched");
			outPort = (*it)->outPort;
			return true;
		};
	};
	return false;
};

void
HashRouting::PrintRoutingTable (Ptr<OutputStreamWrapper> stream) const
{
	return;
}

bool
HashRouting::IsIntraPodTraffic(Ipv4Header &header)
{
    uint32_t src = header.GetSource().Get();
    uint32_t dst = header.GetDestination().Get();
    return (((src & 0x00FE0000) == (dst & 0x00FE0000)) && ((src & 0x0000FC00) != (dst & 0x0000FC00)));
}

bool
HashRouting::IsInterPodTraffic(Ipv4Header &header)
{
        uint32_t src = header.GetSource().Get();
        uint32_t dst = header.GetDestination().Get();
        return ((src & 0x00FE0000) != (dst & 0x00FE0000));
}

bool
HashRouting::IsSourceEdge(Ipv4Header &header)
{
    uint32_t a = header.GetSource().Get();  // Source IP of packet
    uint32_t b = m_ipv4->GetAddress(1,0).GetLocal().Get(); // Address of local switch
    return (((b & 0x00010300) == 0x00000200) &&
                 ((a & 0x0000FC00) == (b & 0x0000FC00) && (a & 0x00FE0000) == (b & 0x00FE0000)));
}

bool
HashRouting::IsDstEdge(Ipv4Header &header)
{
    uint32_t a = header.GetDestination().Get();  // Source IP of packet
    uint32_t b = m_ipv4->GetAddress(1,0).GetLocal().Get(); // Address of local switch
    return (((b & 0x00010300) == 0x00000200) &&
                 ((a & 0x0000FC00) == (b & 0x0000FC00) && (a & 0x00FE0000) == (b & 0x00FE0000)));
}

bool
HashRouting::IsDstAggr(Ipv4Header &header)
{ 
        uint32_t a = header.GetDestination().Get();
        uint32_t b = m_ipv4->GetAddress(1,0).GetLocal().Get();
        return (((b & 0x00010100)==0x00000100) && ((a & 0x00FE0000) == (b & 0x00FE0000)));      
}

bool
HashRouting::IsSourceAggr(Ipv4Header &header)
{ 
        uint32_t a = header.GetSource().Get();
        uint32_t b = m_ipv4->GetAddress(1,0).GetLocal().Get();
        return (((b & 0x00010100)==0x00000100) && ((a & 0x00FE0000) == (b & 0x00FE0000)));      
}

bool 
HashRouting::IsAgg() 
{
        uint32_t b = m_ipv4->GetAddress(1,0).GetLocal().Get(); // Address of local switch
        return ((b & 0x00010100)==0x00000100);
}

// Flowlet table: flow's five tuple, valid bit, and an age bit
void
HashRouting::FlowletRoute(const flowid& tuple, uint32_t& pathID)
{

  NS_LOG_FUNCTION(this);
  uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
  // Linear search for matching entry
  FlowRouteTable::iterator it = m_flowRouteTable.begin();

  while (it != m_flowRouteTable.end()) 
  {
     if ((*it)->last + m_lifetime < Simulator::Now()) 
     {
         // Erase expired entry
         it = m_flowRouteTable.erase(it);
         continue;
     };

     if (tuple == (*it)->fid) 
     {
        if ((*it)->last + m_flowletGap < Simulator::Now())  
        {         
           // new flowlet is detected, and new load balancing decision is made
          (*it)->pathID =  UniformVariable(0,numUpPorts).GetValue();
        }
          (*it)->last = Simulator::Now();
          pathID = (*it)->pathID;  
          return;   
     };
     it++;
  };

  // Fail to match any entry; make new load balancing decision
   pathID = UniformVariable(0,numUpPorts).GetValue();
   Ptr<FlowRoute> f = Create<FlowRoute>(tuple, Simulator::Now(), pathID);
   m_flowRouteTable.push_back(f);       
}

// Flowlet table: flow's five tuple, valid bit, and an age bit
void
HashRouting::CongaRoute(const flowid& tuple, uint32_t& pathID)
{

  NS_LOG_FUNCTION(this);
  uint32_t destLeaf = (tuple.GetDAddr() & 0x0000FC00) >> 10;
  // Linear search for matching entry
  FlowRouteTable::iterator it = m_flowRouteTable.begin();

  while (it != m_flowRouteTable.end()) 
  {
     if ((*it)->last + m_lifetime < Simulator::Now()) 
     {
         // Erase expired entry
         it = m_flowRouteTable.erase(it);
         continue;
     };

     if (tuple == (*it)->fid) 
     {
        if ((*it)->last + m_flowletGap < Simulator::Now())  
        {         
           // new flowlet is detected, and new load balancing decision is made
          (*it)->pathID = PathSelection(destLeaf);
        }
          (*it)->last = Simulator::Now();
          pathID = (*it)->pathID;  
          return;   
     };
     it++;
  };
  // Fail to match any entry; make new load balancing decision
   pathID = PathSelection(destLeaf);
   Ptr<FlowRoute> f = Create<FlowRoute>(tuple, Simulator::Now(), pathID);
   m_flowRouteTable.push_back(f);       
}

uint32_t 
HashRouting::PathSelection (uint32_t destLeaf)
{
      std::vector<uint32_t> pathCong;
      // check the MetricTable, and reset the outdated metric
      for (std::vector<Ptr<MetricRecord> >::iterator iter = MetricTable[destLeaf].begin(); iter != MetricTable[destLeaf].end(); iter++)                 
      {   
         if (Simulator::Now()-(*iter)->last > m_congLifetime)
         {
            (*iter)->metric = 0;
            (*iter)->last = Simulator::Now();
         }
         pathCong.push_back(uint32_t((*iter)->metric));
       }
      std::vector <uint32_t> indices;
      std::vector <uint32_t>::iterator it = pathCong.begin();
     while (it != pathCong.end())
     {
        if ((*it) == *min_element(pathCong.begin(), pathCong.end()))
          indices.push_back( distance(pathCong.begin(), it));
        it++;
     }

  std::random_shuffle(indices.begin(), indices.end());
  return *indices.begin();
}

uint32_t 
HashRouting::MinValue (std::vector<uint32_t> V)
{
  std::vector <uint32_t> indices;
  std::vector <uint32_t>::iterator it = V.begin();
  while (it != V.end())
  {
     if ((*it) == *min_element(V.begin(), V.end()))
        indices.push_back( distance(V.begin(), it));
     it++;
  }

  std::random_shuffle(indices.begin(), indices.end());
  return *indices.begin();
}

void 
HashRouting::IniMetricTable (uint32_t numRacks)
{
        for (uint32_t edge=0; edge<numRacks; edge++)
        { 
            std::vector<Ptr<MetricRecord> > vec;
            // number of paths is same as number of racks in our topo
            for (uint32_t p=0; p<numRacks; p++)
            {
                Time t = Seconds (0);
                Ptr<MetricRecord> m = Create<MetricRecord>(uint8_t(0), t);
                vec.push_back(m);
            }
            MetricTable.push_back(vec);
        } 
}

void
HashRouting::IniFB_MetricTable (uint32_t numRacks)
{
        for (uint32_t edge=0; edge<numRacks; edge++)
        { 
            std::vector<Ptr<MetricRecord> > vec;
            // number of paths is same as number of racks in our topo
            for (uint32_t p=0; p<numRacks; p++)
            {
                Time t = Seconds (0);
                Ptr<MetricRecord> m = Create<MetricRecord>(uint8_t(0), t);
                vec.push_back(m);
            }
            FB_MetricTable.push_back(vec);
        }
}        

void
HashRouting::IniCounter (uint32_t numRacks)
{
        for (uint32_t edge=0; edge<numRacks; edge++)
        {
            uint32_t start = UniformVariable(0, numRacks).GetValue();
            m_counter.push_back(start); 
        }
}



uint32_t 
HashRouting::GetInRate (uint32_t port)
{
        Ptr<NetDevice> dev = m_ipv4->GetNetDevice(port);
        Ptr<SpNetDevice> spdev = StaticCast<SpNetDevice> (dev);
        uint32_t inrate = spdev -> InRate ();
        return inrate;
}

uint32_t 
HashRouting::GetOutRate (uint32_t port)
{
        Ptr<NetDevice> dev = m_ipv4->GetNetDevice(port);
        Ptr<SpNetDevice> spdev = StaticCast<SpNetDevice> (dev);
        uint32_t outrate = spdev -> OutRate ();
        return outrate;
}

void 
HashRouting::DisplayVector (std::vector<uint32_t>& v)
{
  std::copy(v.begin(), v.end(), std::ostream_iterator<uint32_t>(std::cout, "  "));
  std::cout << std::endl;
}

void
HashRouting::ExpRoute(const flowid& tuple, uint32_t& pathID)
{

  NS_LOG_FUNCTION(this);
  // Linear search for matching entry
  FlowRouteTable::iterator it = m_flowRouteTable.begin();

  while (it != m_flowRouteTable.end()) 
  {
     if ((*it)->last + m_lifetime < Simulator::Now()) 
     {
         // Erase expired entry
         it = m_flowRouteTable.erase(it);
         continue;
     };

     if (tuple == (*it)->fid) 
     {
          (*it)->last = Simulator::Now();
          pathID = (*it)->pathID;  
          return;   
     };
     it++;
  };
   // Fail to match any entry; do hash routing
   uint32_t numUpPorts = (m_ipv4->GetNInterfaces()-1)/(1+m_torosp);
   pathID = Hash(tuple) % numUpPorts;
   if (IsAgg())
   {
     numUpPorts = (m_ipv4->GetNInterfaces()-1)/2;
     pathID = Hash(tuple) % (int(numUpPorts/m_coreosp));
   }
}

}//namespace ns3
