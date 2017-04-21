/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 New York University
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
 * Modified by Peng Wang<pewang4-c@my.cityu.edu.hk>
 */
#ifndef LEAF_SPINE_HELPER_H
#define LEAF_SPINE_HELPER_H

#include "ns3/type-id.h"
#include "ns3/node-container.h"
#include "ns3/data-rate.h"
#include "ns3/nstime.h"
#include "ns3/ipv4-interface-container.h"
#include "ns3/net-device-container.h"
#include "ns3/object-factory.h"
#include "ns3/ptr.h"

namespace ns3 {

class LeafSpineHelper : public Object
{
public:
  static TypeId GetTypeId (void);
  LeafSpineHelper(unsigned n);
  virtual ~LeafSpineHelper();
  void Create(void);
  /**
   * Each point to point net device must have a queue to pass packets through.
   * This method allows one to set the type of the queue that is automatically
   * created when the device is created and attached to a node.
   *
   * \param type the type of queue
   * \param n1 the name of the attribute to set on the queue
   * \param v1 the value of the attribute to set on the queue
   * \param n2 the name of the attribute to set on the queue
   * \param v2 the value of the attribute to set on the queue
   * \param n3 the name of the attribute to set on the queue
   * \param v3 the value of the attribute to set on the queue
   * \param n4 the name of the attribute to set on the queue
   * \param v4 the value of the attribute to set on the queue
   *
   * Set the type of queue to create and associated to each
   * PointToPointNetDevice created.
   */
   void SetQueue (std::string type,
    std::string n1 = "", const AttributeValue &v1 = EmptyAttributeValue (),
    std::string n2 = "", const AttributeValue &v2 = EmptyAttributeValue (),
    std::string n3 = "", const AttributeValue &v3 = EmptyAttributeValue (),
    std::string n4 = "", const AttributeValue &v4 = EmptyAttributeValue ());

  // Functions to retrieve nodes and interfaces
  NodeContainer& AllNodes(void)  { return m_node; };
  NodeContainer& AggrNodes(void) { return m_aggr; };
  NodeContainer& EdgeNodes(void) { return m_edge; };
  NodeContainer& HostNodes(void) { return m_host; };
  Ipv4InterfaceContainer& AggrInterfaces(void) { return m_aggrIface; };
  Ipv4InterfaceContainer& EdgeInterfaces(void) { return m_edgeIface; };
  Ipv4InterfaceContainer& HostInterfaces(void) { return m_hostIface; };

private:
  // Aux functions
  void  AssignIP (Ptr<NetDevice> c, uint32_t address, Ipv4InterfaceContainer &con);
  NetDeviceContainer  InstallCpCp (Ptr<Node> a, Ptr<Node> b);
  // Parameters
  static unsigned m_size;   //< This is ugly, but necessary for PathTranslate()
  DataRate  m_heRate;
  DataRate  m_eaRate;
  Time  m_heDelay;
  Time  m_eaDelay;
  uint32_t m_torosp;
  uint32_t m_coreosp; 
  NodeContainer m_node;
  NodeContainer m_aggr;
  NodeContainer m_host;
  NodeContainer m_edge;
  Ipv4InterfaceContainer  m_hostIface;
  Ipv4InterfaceContainer  m_edgeIface;
  Ipv4InterfaceContainer  m_aggrIface;
  ObjectFactory m_channelFactory;
  ObjectFactory m_ppFactory;
  ObjectFactory m_queueFactory;
};
};

#endif
