/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 Polytechnic Institute of NYU
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Adrian S. Tam <adrian.sw.tam@gmail.com>
 * Author: Fan Wang <amywangfan1985@yahoo.com.cn>
 * Modified by Peng Wang <pewang4-c@my.cityu.edu.hk>

 */

 #include <sstream>
#include <stdint.h>
#include <stdlib.h>

#include "leaf-spine-helper.h"

#include "ns3/log.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/queue.h"
#include "ns3/sp-net-device.h"
#include "ns3/boolean.h"
#include "ns3/uinteger.h"
#include "ns3/point-to-point-channel.h"
#include "ns3/ipv4-address-generator.h"
#include "ns3/ipv4-hash-routing-helper.h"
#include "ns3/config.h"
#include "ns3/abort.h"
#include "ns3/double.h"
#include "ns3/point-to-point-helper.h"

namespace ns3 {
NS_LOG_COMPONENT_DEFINE ("LeafSpineHelper");

NS_OBJECT_ENSURE_REGISTERED (LeafSpineHelper);

unsigned LeafSpineHelper::m_size = 0; // Defining static variable

TypeId
LeafSpineHelper::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::LeafSpineHelper")
    .SetParent<Object> ()
    .AddAttribute ("HeDataRate",
                   "The default data rate for point to point links",
                   DataRateValue (DataRate ("1Gbps")),
                   MakeDataRateAccessor (&LeafSpineHelper::m_heRate),
                   MakeDataRateChecker ())
    .AddAttribute ("EaDataRate",
                   "The default data rate for point to point links",
                   DataRateValue (DataRate ("1Gbps")),
                   MakeDataRateAccessor (&LeafSpineHelper::m_eaRate),
                   MakeDataRateChecker ())
    .AddAttribute ("HeDelay", "Transmission delay through the channel",
                   TimeValue (NanoSeconds (500)),
                   MakeTimeAccessor (&LeafSpineHelper::m_heDelay),
                   MakeTimeChecker ())
    .AddAttribute ("EaDelay", "Transmission delay through the channel",
                   TimeValue (NanoSeconds (500)),
                   MakeTimeAccessor (&LeafSpineHelper::m_eaDelay),
                   MakeTimeChecker ())
    .AddAttribute ("ToROsp", "oversubscription ratio at ToR tier for the network",
                    UintegerValue (2),
                    MakeUintegerAccessor (&LeafSpineHelper::m_torosp),                    
                    MakeUintegerChecker<uint32_t> ())
 ;

  return tid;
}

LeafSpineHelper::LeafSpineHelper(unsigned N)
{
  m_size = N;                                                                     
  m_channelFactory.SetTypeId ("ns3::PointToPointChannel");
  m_ppFactory.SetTypeId ("ns3::SpNetDevice"); 
  // use droptail queue by default
  m_queueFactory.SetTypeId ("ns3::DropTailQueue");
}

LeafSpineHelper::~LeafSpineHelper()
{
}

void 
LeafSpineHelper::SetQueue (std::string type,
                              std::string n1, const AttributeValue &v1,
                              std::string n2, const AttributeValue &v2,
                              std::string n3, const AttributeValue &v3,
                              std::string n4, const AttributeValue &v4)
{
  m_queueFactory.SetTypeId (type);
  m_queueFactory.Set (n1, v1);
  m_queueFactory.Set (n2, v2);
  m_queueFactory.Set (n3, v3);
  m_queueFactory.Set (n4, v4);
}

/* Create the whole topology */
void
LeafSpineHelper::Create()
{

  const unsigned N = m_size;
  const unsigned numAggr = N;
  const unsigned numEdge = N;
  const unsigned numHost = numEdge * N * m_torosp;
  const unsigned numTotal= numAggr + numEdge + numHost;

  /*
   * Create nodes and distribute them into different node container.
   * We create N^2+2N nodes at a batch, where the first 2N nodes are the
   * edge and aggregation switches. The last N^2 nodes are end hosts.
   */
  NS_LOG_LOGIC ("Creating leaf spine nodes.");
  m_node.Create(numTotal);


  for(unsigned i=0; i<=N-1; i++) { // First N nodes
      m_edge.Add(m_node.Get(i));
  }
    for(unsigned i=N; i<=2*N-1; i++) { // Last N nodes
      m_aggr.Add(m_node.Get(i));
  }
  for(unsigned i=2*N; i<numTotal; i++) {
    m_host.Add(m_node.Get(i));
  };

  /*
   * Connect nodes by adding netdevice and set up IP addresses to them.
   *
   * The formula is as follows. We have a leaf spine of parameter N, and
   * there are six categories of netdevice, namely, (1) on host;
   * (2) edge towards host; (3) edge towards aggr; (4) aggr towards
   * edge;  There are 2N^3 devices
   * in each category which makes up to 12N^3 netdevices. The IP addrs
   * are assigned in the subnet 10.0.0.0/8 with the 24 bits filled as
   * follows: (Assume N is representable in 6 bits)
   *
   * Address         Scheme
   *               | 7 bit      | 1 bit |  6 bit  | 2 bit | 8 bit   |
   * Host (to edge)| Subtree ID |   0   | Edge ID |  00   | Host ID |
   * Edge (to host)| Subtree ID |   0   | Edge ID |  10   | Host ID |
   * Edge (to aggr)| Subtree ID |   0   | Edge ID |  11   | Aggr ID |
   * Agg. (to edge)| Subtree ID |   0   | Edge ID |  01   | Aggr ID |
   *
  
   * All ID are numbered from 0 onward. Subtree ID is numbered from left to
   * right according to the leaf spine diagram. Host ID is numbered from
   * left to right within the same attached edge switch. Edge and aggr
   * ID are numbered within the same subtree. 
   */
  NS_LOG_LOGIC ("Creating connections and set-up addresses.");
  Ipv4HashRoutingHelper hashHelper;
  InternetStackHelper internet;
  internet.SetRoutingHelper(hashHelper);
  internet.Install (m_node);
  
  m_ppFactory.Set ("DataRate", DataRateValue(m_heRate));          /* Host to Edge */
  m_channelFactory.Set ("Delay", TimeValue(m_heDelay));
 
    for(unsigned i=0; i<N; i++) { // For each edge
      for(unsigned m=0; m<N*m_torosp; m++) { // For each port of edge
        // Connect edge to host
        Ptr<Node> eNode = m_edge.Get(i);
        Ptr<Node> hNode = m_host.Get(i*N*m_torosp+m);
        NetDeviceContainer devices;
        devices = InstallCpCp(eNode, hNode);
        // Set routing for end host: Default route only
        Ptr<HashRouting> hr = hashHelper.GetHashRouting(hNode->GetObject<Ipv4>());
        hr->AddRoute(Ipv4Address(0U), Ipv4Mask(0U), 1);                               
        // Set IP address for end host
        uint32_t address = (((((((10<<7))<<7)+i)<<2)+0x0)<<8)+m;
        AssignIP(devices.Get(1), address, m_hostIface);

        // Set routing for edge switch
        hr = hashHelper.GetHashRouting(eNode->GetObject<Ipv4>());
        hr->AddRoute(Ipv4Address(address), Ipv4Mask(0xFFFFFFFFU), m+1);
        // Set IP address for edge switch
        address = (((((((10<<7))<<7)+i)<<2)+0x2)<<8)+m;
        AssignIP(devices.Get(0), address, m_edgeIface);
      };
    };

    m_ppFactory.Set ("DataRate", DataRateValue(m_eaRate));  /* Edge to Aggr */
    m_channelFactory.Set ("Delay", TimeValue(m_eaDelay));
    for(unsigned i=0; i<N; i++) { // For each edge
      for(unsigned m=0; m<N; m++) { // For each aggregation
        // Connect edge to aggregation
        Ptr<Node> aNode = m_aggr.Get(m);
        Ptr<Node> eNode = m_edge.Get(i);
        NetDeviceContainer devices;
        devices = InstallCpCp(eNode, aNode);
        // NetDeviceContainer devices = InstallCpCp(aNode, eNode);
        // Set IP address for aggregation switch
        uint32_t address = (((((((10<<7))<<7)+i)<<2)+0x1)<<8)+m;

        AssignIP(devices.Get(1), address, m_aggrIface);

        // Set routing for aggregation switch
        Ptr<HashRouting> hr = hashHelper.GetHashRouting(aNode->GetObject<Ipv4>());
        hr->AddRoute(Ipv4Address(address & 0xFFFFFC00U), Ipv4Mask(0xFFFFFC00U), i+1);

        // Set IP address for edge switch
        address = (((((((10<<7))<<7)+i)<<2)+0x3)<<8)+m;

        AssignIP(devices.Get(0), address, m_edgeIface);
      } ;
    };


#ifdef NS3_LOG_ENABLE
  if (! g_log.IsEnabled(ns3::LOG_DEBUG)) {
    return;
  };
  for(unsigned i = 0; i< numTotal; i++) {
    Ptr<Ipv4> m_ipv4 = m_node.Get(i)->GetObject<Ipv4>();
    for(unsigned j=1; j<m_ipv4->GetNInterfaces(); j++) {
      for(unsigned k=0; k<m_ipv4->GetNAddresses(j); k++) {
        NS_LOG_DEBUG("Addr of node " << i << " iface " << j << ": " << m_ipv4->GetAddress(j,k));
      }
    }
  }
#endif
} // LeafSpineHelper::Create()

void
LeafSpineHelper::AssignIP (Ptr<NetDevice> c, uint32_t address, Ipv4InterfaceContainer &con)
{
  NS_LOG_FUNCTION_NOARGS ();

  Ptr<Node> node = c->GetNode ();
  NS_ASSERT_MSG (node, "LeafSpineHelper::AssignIP(): Bad node");

  Ptr<Ipv4> ipv4 = node->GetObject<Ipv4> ();
  NS_ASSERT_MSG (ipv4, "LeafSpineHelper::AssignIP(): Bad ipv4");

  int32_t ifIndex = ipv4->GetInterfaceForDevice (c);
  if (ifIndex == -1) {
    ifIndex = ipv4->AddInterface (c);
  };
  NS_ASSERT_MSG (ifIndex >= 0, "LeafSpineHelper::AssignIP(): Interface index not found");

  Ipv4Address addr(address);
  Ipv4InterfaceAddress ifaddr(addr, 0xFFFFFFFF);
  ipv4->AddAddress (ifIndex, ifaddr);
  ipv4->SetMetric (ifIndex, 1);
  ipv4->SetUp (ifIndex);
  con.Add (ipv4, ifIndex);
  Ipv4AddressGenerator::AddAllocated (addr);
}

NetDeviceContainer
LeafSpineHelper::InstallCpCp (Ptr<Node> a, Ptr<Node> b)
{
  NetDeviceContainer container;

  Ptr<PointToPointNetDevice> devA = m_ppFactory.Create<PointToPointNetDevice> ();
  devA->SetAddress (Mac48Address::Allocate ());
  a->AddDevice (devA);
  // we need to add a queue to each netdevice. default is droptail queue
  Ptr<Queue> queueA = m_queueFactory.Create<Queue> ();
    devA->SetQueue (queueA);
  Ptr<PointToPointNetDevice> devB = m_ppFactory.Create<PointToPointNetDevice> ();
  devB->SetAddress (Mac48Address::Allocate ());
  b->AddDevice (devB);
  Ptr<Queue> queueB = m_queueFactory.Create<Queue> ();
    devB->SetQueue (queueB);
  Ptr<PointToPointChannel> channel = m_channelFactory.Create<PointToPointChannel> ();
  devA->Attach (channel);
  devB->Attach (channel);
  container.Add (devA);
  container.Add (devB);

  return container;
}

}//namespace
