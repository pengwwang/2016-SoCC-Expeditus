/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2007 University of Washington
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
 */
#include <iostream>
#include "ns3/simulator.h"
#include "ns3/nstime.h"
#include "ns3/log.h"
#include "ns3/boolean.h"
#include "ns3/enum.h"
#include "ns3/uinteger.h"
#include "ns3/packet.h"
#include "ns3/ipv4-header.h"
#include "ns3/ppp-header.h"
#include "drop-tail-queue.h"

NS_LOG_COMPONENT_DEFINE ("DropTailQueue");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (DropTailQueue);

TypeId DropTailQueue::GetTypeId (void) 
{
  static TypeId tid = TypeId ("ns3::DropTailQueue")
    .SetParent<Queue> ()
    .AddConstructor<DropTailQueue> ()
    .AddAttribute ("Mode", 
                   "Whether to use Bytes (see MaxBytes) or Packets (see MaxPackets) as the maximum queue size metric.",
                   EnumValue (PACKETS),
                   MakeEnumAccessor (&DropTailQueue::SetMode),
                   MakeEnumChecker (BYTES, "Bytes",
                                    PACKETS, "Packets"))
    .AddAttribute ("MaxPackets", 
                   "The maximum number of packets accepted by this DropTailQueue.",
                   UintegerValue (100),
                   MakeUintegerAccessor (&DropTailQueue::m_maxPackets),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("MaxBytes", 
                   "The maximum number of bytes accepted by this DropTailQueue.",
                   UintegerValue (100 * 65535),
                   MakeUintegerAccessor (&DropTailQueue::m_maxBytes),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("MarkLine", 
	           "Use ECN to mark every packets if the queue length is larger than MarkLine.",
				 UintegerValue (20),
				 MakeUintegerAccessor (&DropTailQueue::m_markLine),
				 MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("EnablePriority",
                   "Enable priority queue setting",
                   BooleanValue (false),
                   MakeBooleanAccessor (&DropTailQueue::m_enablePriority),
                   MakeBooleanChecker ())
    ;
  
  return tid;
}

DropTailQueue::DropTailQueue () :
  Queue (),
  m_bytesInQueue (0)
{
  m_priQueues = new std::queue<Ptr<Packet> >[2];
  NS_LOG_FUNCTION_NOARGS ();
}

DropTailQueue::~DropTailQueue ()
{
  NS_LOG_FUNCTION_NOARGS ();
}

void 
DropTailQueue::SetMode (enum Mode mode)
{
  NS_LOG_FUNCTION (mode);
  m_mode = mode;
}

  DropTailQueue::Mode
DropTailQueue::GetMode (void)
{
  NS_LOG_FUNCTION_NOARGS ();
  return m_mode;
}

bool 
DropTailQueue::DoEnqueue (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this << p);

  // Get the ipv4header
  PppHeader pppHeader;
  Ipv4Header ipv4Header;
  Ptr<Packet> q = p->Copy ();
  q->RemoveHeader (pppHeader);
  q->RemoveHeader (ipv4Header);
  // 1 - low priority; 0 - high priority 
  int priority = uint32_t(ipv4Header.GetTos() >> 2);

  // using default drop tail queue, all packets' priority number is 0
  if (!m_enablePriority)
      priority = 0; 
  
  if (m_mode == PACKETS && (m_priQueues[0].size () + m_priQueues[1].size () >= m_maxPackets))
    {
      NS_LOG_LOGIC ("Queue full (at max packets) -- droppping pkt");
      // If low priority queue is not empty, drop low priority packets first and enque high priority packet into high priority queue
      if ((!m_priQueues[1].empty()) && (priority == 0))
      {
         Ptr<Packet> p_d = m_priQueues[1].front ();
         Drop (p_d);
         m_priQueues[1].pop ();
         m_bytesInQueue = m_bytesInQueue - p_d->GetSize ();
      }
      else 
      {
         Drop (p);
         return false;
      }
    }

    if (m_mode == BYTES && (m_bytesInQueue + p->GetSize () >= m_maxBytes))
    {
      NS_LOG_LOGIC ("Queue full (packet would exceed max bytes) -- droppping pkt");
      if ((!m_priQueues[1].empty()) && (priority == 0))
      {
         Ptr<Packet> p_d = m_priQueues[1].front ();
         Drop (p_d);
         m_priQueues[1].pop ();
         m_priQueues[0].push (p);
         m_bytesInQueue = m_bytesInQueue - p_d->GetSize ();
      }
      else 
      {
         Drop (p);
         return false;
      }
    }

  m_priQueues[priority].push(p);
  m_bytesInQueue += p->GetSize ();

  NS_LOG_LOGIC ("Number packets " << m_priQueues[0].size () + m_priQueues[1].size ());
  NS_LOG_LOGIC ("Number bytes " << m_bytesInQueue);

  return true;
}

Ptr<Packet>
DropTailQueue::DoDequeue (void)
{
  NS_LOG_FUNCTION (this);

  if (!m_priQueues[0].empty())
  {
     Ptr<Packet> p = m_priQueues[0].front ();
     m_priQueues[0].pop ();
     m_bytesInQueue -= p->GetSize ();

     NS_LOG_LOGIC ("Popped " << p);
     NS_LOG_LOGIC ("Number packets " << m_priQueues[0].size () + m_priQueues[1].size ());
     NS_LOG_LOGIC ("Number bytes " << m_bytesInQueue);

     return p;
  }
  else if (!m_priQueues[1].empty()) 
  { 
     Ptr<Packet> p = m_priQueues[1].front ();
     m_priQueues[1].pop ();
     m_bytesInQueue -= p->GetSize ();

     NS_LOG_LOGIC ("Popped " << p);
     NS_LOG_LOGIC ("Number packets " << m_priQueues[0].size () + m_priQueues[1].size ());
     NS_LOG_LOGIC ("Number bytes " << m_bytesInQueue);

     return p;
  }  
  else 
  {
     NS_LOG_LOGIC ("Queue empty");
     return 0;
  }
}

Ptr<const Packet>
DropTailQueue::DoPeek (void) const
{
  NS_LOG_FUNCTION (this);

  if (!m_priQueues[0].empty())
  {
       Ptr<Packet> p = m_priQueues[0].front ();
       return p;
  }
  else if (!m_priQueues[1].empty())
  {
       Ptr<Packet> p = m_priQueues[1].front ();
       return p;
  }
  else  
  {
       NS_LOG_LOGIC ("Queue empty");
       return 0;
  }

  NS_LOG_LOGIC ("Number packets " << m_priQueues[0].size () + m_priQueues[1].size ());
  NS_LOG_LOGIC ("Number bytes " << m_bytesInQueue);
}

} // namespace ns3

#include "ns3/test.h"

namespace ns3 {

class DropTailQueueTestCase : public TestCase
{
public:
  DropTailQueueTestCase ();
  virtual bool DoRun (void);
};

DropTailQueueTestCase::DropTailQueueTestCase ()
  : TestCase ("Sanity check on the drop tail queue implementation")
{}
bool 
DropTailQueueTestCase::DoRun (void)
{
  Ptr<DropTailQueue> queue = CreateObject<DropTailQueue> ();
  NS_TEST_EXPECT_MSG_EQ (queue->SetAttributeFailSafe ("MaxPackets", UintegerValue (3)), true, 
                         "Verify that we can actually set the attribute");
  
  Ptr<Packet> p1, p2, p3, p4;
  p1 = Create<Packet> ();
  p2 = Create<Packet> ();
  p3 = Create<Packet> ();
  p4 = Create<Packet> ();

  NS_TEST_EXPECT_MSG_EQ (queue->GetNPackets (), 0, "There should be no packets in there");
  queue->Enqueue (p1);
  NS_TEST_EXPECT_MSG_EQ (queue->GetNPackets (), 1, "There should be one packet in there");
  queue->Enqueue (p2);
  NS_TEST_EXPECT_MSG_EQ (queue->GetNPackets (), 2, "There should be two packets in there");
  queue->Enqueue (p3);
  NS_TEST_EXPECT_MSG_EQ (queue->GetNPackets (), 3, "There should be three packets in there");
  queue->Enqueue (p4); // will be dropped
  NS_TEST_EXPECT_MSG_EQ (queue->GetNPackets (), 3, "There should be still three packets in there");

  Ptr<Packet> p;

  p = queue->Dequeue ();
  NS_TEST_EXPECT_MSG_EQ ((p != 0), true, "I want to remove the first packet");
  NS_TEST_EXPECT_MSG_EQ (queue->GetNPackets (), 2, "There should be two packets in there");
  NS_TEST_EXPECT_MSG_EQ (p->GetUid (), p1->GetUid (), "was this the first packet ?");

  p = queue->Dequeue ();
  NS_TEST_EXPECT_MSG_EQ ((p != 0), true, "I want to remove the second packet");
  NS_TEST_EXPECT_MSG_EQ (queue->GetNPackets (), 1, "There should be one packet in there");
  NS_TEST_EXPECT_MSG_EQ (p->GetUid (), p2->GetUid (), "Was this the second packet ?");

  p = queue->Dequeue ();
  NS_TEST_EXPECT_MSG_EQ ((p != 0), true, "I want to remove the third packet");
  NS_TEST_EXPECT_MSG_EQ (queue->GetNPackets (), 0, "There should be no packets in there");
  NS_TEST_EXPECT_MSG_EQ (p->GetUid (), p3->GetUid (), "Was this the third packet ?");

  p = queue->Dequeue ();
  NS_TEST_EXPECT_MSG_EQ ((p == 0), true, "There are really no packets in there");

  return false;
}

static class DropTailQueueTestSuite : public TestSuite
{
public:
  DropTailQueueTestSuite ()
    : TestSuite ("drop-tail-queue", UNIT)
  {
    AddTestCase (new DropTailQueueTestCase ());
  }
} g_dropTailQueueTestSuite;

} // namespace ns3
