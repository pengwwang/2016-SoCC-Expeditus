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

#ifndef HASH_ROUTING_H
#define HASH_ROUTING_H

#include <list>
#include <set>
#include <stdint.h>
#include <algorithm>
 #include <vector>
 #include <iterator>
#include "ns3/ipv4-address.h"
#include "ns3/ptr.h"
#include "ns3/ipv4.h"
#include "ns3/simulator.h"
#include "ns3/ipv4-routing-protocol.h"
#include "ns3/ref-count-base.h"
#include "fivetuple.h"
#include "hash-function.h"
#include "ns3/tcp-header.h"

namespace ns3 {

class Packet;
class NetDevice;
class Ipv4Interface;
class Ipv4Address;
class Ipv4Header;
class Ipv4RoutingTableEntry;
class Ipv4MulticastRoutingTableEntry;
class Node;

// Destination-based routing table
class DestRoute : public RefCountBase
{
public:
	DestRoute(Ipv4Address const& d, Ipv4Mask const& m, uint32_t i) : dest(d), mask(m), outPort(i) {};
	Ipv4Address dest;
	Ipv4Mask mask;
	uint32_t outPort;
};

typedef std::list<Ptr<DestRoute> > DestRouteTable;

// Flow routing table indexed by five-tuple in switch
class FlowRoute : public RefCountBase
{
public:
       FlowRoute(const flowid& f, const Time& t, uint32_t p) : fid(f), last(t), pathID(p) {};
	flowid fid;
	Time last;
	uint32_t pathID;
};
typedef std::list<Ptr<FlowRoute> > FlowRouteTable;

// Metric record: include metric itself and last update time
class MetricRecord : public RefCountBase
{
public:
        MetricRecord(uint8_t m, Time& t) : metric(m), last(t) {};
        uint8_t metric;
        Time last;
};


// Class for hash-based routing logic
class HashRouting : public Ipv4RoutingProtocol
{
public:
	static TypeId GetTypeId (void);
	HashRouting ();
	virtual ~HashRouting ();

	// Functions defined in Ipv4RoutingProtocol
	virtual Ptr<Ipv4Route> RouteOutput (Ptr<Packet> p,
			Ipv4Header &header,
			Ptr<NetDevice> oif, Socket::SocketErrno &sockerr);
	virtual bool RouteInput  (Ptr<Packet> p,
			Ipv4Header &header, Ptr<const NetDevice> idev,
			UnicastForwardCallback ucb, MulticastForwardCallback mcb,
			LocalDeliverCallback lcb, ErrorCallback ecb);
	virtual void NotifyInterfaceUp (uint32_t interface) {};
	virtual void NotifyInterfaceDown (uint32_t interface) {};
	virtual void NotifyAddAddress (uint32_t interface, Ipv4InterfaceAddress address) {};
	virtual void NotifyRemoveAddress (uint32_t interface, Ipv4InterfaceAddress address) {};
	virtual void SetIpv4 (Ptr<Ipv4> ipv4);
        virtual void PrintRoutingTable (Ptr<OutputStreamWrapper> stream) const;

	/**
	 * \brief Add a destination-based route to the routing table.
	 *
	 * \param dest The Ipv4Address network for this route.
	 * \param mask The Ipv4Mask to extract the network.
	 * \param interface The network interface index used to send packets to the
	 * destination.
	 *
	 * \see Ipv4Address
	 */
	void AddRoute (const Ipv4Address& dest, const Ipv4Mask& mask, uint32_t interface);
	

	/**
	 * \brief Set the hash function to be used in the hash-based routing
	 *
	 * \param hash The pointer to a hash function object
	 */
  	void SetHashFunction (Ptr<HashFunction> hash) { m_hash = hash; };
protected:
	flowid GetTuple(Ptr<Packet> packet, Ipv4Header& header);
	uint32_t Lookup (flowid fid);
	bool IsLocal (const Ipv4Address& dest);

	/*
	 * \brief Get the output port for the destination address
	 *
	 * This function is called by the RequestIfIndex() function when this node is
	 * an edge switch.
	 *
	 * \param iph		The Ipv4Header of the packet to be routed
	 * \param outPort 	Output port number to be filled
	 * \return true if a route is found, false otherwise
	 */
	bool RequestDestRoute(const Ipv4Address& addr, uint32_t &outPort);
    
      /*
	 * \brief Get the output port from Edge switch flow-based routing table
	 *
	 * \param tuple		The flow id as five tuple
	 * \param outPort 	Output port number to be filled
	 * \return true if a route is found, false otherwise
	 */
	void CongaRoute(const flowid& tuple, uint32_t& pathID);
	void FlowletRoute(const flowid& tuple, uint32_t& pathID);
    void ExpRoute(const flowid& tuple, uint32_t& pathID);

	uint32_t PathSelection (uint32_t destLeaf);

	/*
	 * Given the flow Id, return a 32-but hash value
	 *
	 * \param tuple	The flow id as five tuple
	 * \return 32-bit hash value specific to this incarnation of routing module
	 */
	uint32_t Hash(const flowid& tuple) const;

	/*
	 * Clean up everything to make this object virtually dead
	 */
  	virtual void DoDispose (void);

  	bool IsAgg();
  	bool IsSourceEdge(Ipv4Header &header);
  	bool IsDstEdge(Ipv4Header &header);
  	bool IsSourceAggr(Ipv4Header &header); 
  	bool IsDstAggr(Ipv4Header &header);
  	bool IsIntraPodTraffic(Ipv4Header &header);
        bool IsInterPodTraffic(Ipv4Header &header);
  	uint32_t GetInRate (uint32_t port);
      uint32_t GetOutRate (uint32_t port);
      void IniMetricTable (uint32_t numRacks);
       void IniFB_MetricTable (uint32_t numRacks);
       void IniCounter (uint32_t numRacks);
       void DisplayVector (std::vector<uint32_t>& v);
       uint32_t MinValue (std::vector<uint32_t> V);
protected:
	Ptr<HashFunction> m_hash;

	DestRouteTable m_destRouteTable;
	FlowRouteTable m_flowRouteTable;

	std::vector<std::vector<Ptr<MetricRecord> > > MetricTable;
      std::vector<std::vector<Ptr<MetricRecord> > > FB_MetricTable;
      std::vector<uint32_t> m_counter;

	std::set<uint32_t> localAddrCache;
  
  	bool m_iniTable; // construct tables for each ToR switch
	Ptr<Ipv4> m_ipv4;	// Hook to the Ipv4 object of this node
	int m_scheme;        // load balancing scheme
	Time m_flowletGap; // gap for flowlet switching 
	Time m_lifetime;	// Lifetime for routing entry
       Time m_congLifetime;    // Lifetime of a congestion metric record
       uint32_t m_torosp; // oversubscription ratio at ToR tier
       uint32_t m_coreosp; // oversubscription ratio at core tier

};

} // Namespace ns3

#endif /* HASH_ROUTING_H */
