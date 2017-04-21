/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2005 INRIA
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
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 * Modified by: Peng Wang <pewang@cityu.edu.hk>
 */

#include "ns3/assert.h"
#include "ns3/abort.h"
#include "ns3/log.h"
#include "ns3/header.h"
#include "ipv4-header.h"
#include "ns3/uinteger.h"

NS_LOG_COMPONENT_DEFINE ("Ipv4Header");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (Ipv4Header);

Ipv4Header::Ipv4Header ()
  : m_calcChecksum (false),
    m_payloadSize (0),
    m_identification (0),
    m_tos (0),
    m_ttl (0),
    m_protocol (0),
    m_flags (0),
    m_fragmentOffset (0),
    m_checksum(0),
    m_goodChecksum (true),
//  m_headerSize(5*4)
    m_headerSize(8*4)   
{
//    m_options.PathID = 0;
    m_options.lbTag = 0;
    m_options.ce = 0;
    m_options.fb_lbTag = 0;
    m_options.fb_metric = 0;
    m_options.dqueue = 0;
    m_options.uqueue = 0;
}

void 
Ipv4Header::EnableChecksum (void)
{
  m_calcChecksum = true;
}

void 
Ipv4Header::SetPayloadSize (uint16_t size)
{
  m_payloadSize = size;
}
uint16_t 
Ipv4Header::GetPayloadSize (void) const
{
  return m_payloadSize;
}

uint16_t 
Ipv4Header::GetIdentification (void) const
{
  return m_identification;
}
void 
Ipv4Header::SetIdentification (uint16_t identification)
{
  m_identification = identification;
}



void 
Ipv4Header::SetTos (uint8_t tos)
{
  m_tos = tos;
}

void
Ipv4Header::SetEcn (EcnType ecn)
{
  NS_LOG_FUNCTION (this << ecn);
  m_tos &= 0xFC; // Clear out the ECN part, retain 6 bits of DSCP
  m_tos |= ecn;
}

Ipv4Header::EcnType 
Ipv4Header::GetEcn (void) const
{
  NS_LOG_FUNCTION (this);
  // Extract only last 2 bits of TOS byte, i.e 0x3
  return EcnType (m_tos & 0x3);
}

std::string 
Ipv4Header::EcnTypeToString (EcnType ecn) const
{
  NS_LOG_FUNCTION (this << ecn);
  switch (ecn)
    {
      case NotECT:
        return "Not-ECT";
      case ECT1:
        return "ECT (1)";
      case ECT0:
        return "ECT (0)";
      case CE:
        return "CE";      
      default:
        return "Unknown ECN";
    };
}

uint8_t 
Ipv4Header::GetTos (void) const
{
  return m_tos;
}
void 
Ipv4Header::SetMoreFragments (void)
{
  m_flags |= MORE_FRAGMENTS;
}
void
Ipv4Header::SetLastFragment (void)
{
  m_flags &= ~MORE_FRAGMENTS;
}
bool 
Ipv4Header::IsLastFragment (void) const
{
  return !(m_flags & MORE_FRAGMENTS);
}

void 
Ipv4Header::SetDontFragment (void)
{
  m_flags |= DONT_FRAGMENT;
}
void 
Ipv4Header::SetMayFragment (void)
{
  m_flags &= ~DONT_FRAGMENT;
}
bool 
Ipv4Header::IsDontFragment (void) const
{
  return (m_flags & DONT_FRAGMENT);
}

void 
Ipv4Header::SetFragmentOffset (uint16_t offsetBytes)
{
  // check if the user is trying to set an invalid offset
  NS_ABORT_MSG_IF ((offsetBytes & 0x7), "offsetBytes must be multiple of 8 bytes");
  m_fragmentOffset = offsetBytes;
}
uint16_t 
Ipv4Header::GetFragmentOffset (void) const
{
  if ((m_fragmentOffset+m_payloadSize+m_headerSize) > 65535)
    {
      NS_LOG_WARN("Fragment will exceed the maximum packet size once reassembled");
    }
  return m_fragmentOffset;
}

void 
Ipv4Header::SetTtl (uint8_t ttl)
{
  m_ttl = ttl;
}
uint8_t 
Ipv4Header::GetTtl (void) const
{
  return m_ttl;
}
  
uint8_t 
Ipv4Header::GetProtocol (void) const
{
  return m_protocol;
}
void 
Ipv4Header::SetProtocol (uint8_t protocol)
{
  m_protocol = protocol;
}

void 
Ipv4Header::SetSource (Ipv4Address source)
{
  m_source = source;
}
Ipv4Address
Ipv4Header::GetSource (void) const
{
  return m_source;
}

//void
//Ipv4Header::SetPathID (uint32_t PathID)
//{ 
//  m_options.PathID = PathID;
//}
//uint32_t
//Ipv4Header::GetPathID (void)
//{
// return m_options.PathID;
//}

void
Ipv4Header::SetLBTag (uint8_t path)
{
  m_options.lbTag = path;
}
uint8_t
Ipv4Header::GetLBTag (void)
{
  return m_options.lbTag;
}

void
Ipv4Header::SetCE (uint8_t queue)
{
  m_options.ce = queue;
}
uint8_t
Ipv4Header::GetCE (void)
{
  return m_options.ce;
}

void
Ipv4Header::SetFB_LBTag (uint8_t path)
{
  m_options.fb_lbTag = path;
}
uint8_t
Ipv4Header::GetFB_LBTag (void)
{
  return m_options.fb_lbTag;
}

void
Ipv4Header::SetFB_Metric (uint8_t queue)
{
  m_options.fb_metric = queue;
}
uint8_t
Ipv4Header::GetFB_Metric (void)
{
  return m_options.fb_metric;
}

void
Ipv4Header::SetDqueue (uint32_t queue)
{
  m_options.dqueue = queue;
}
uint32_t 
Ipv4Header::GetDqueue (void)
{
  return m_options.dqueue;
}

void
Ipv4Header::SetUqueue (uint32_t queue)
{
  m_options.uqueue = queue;
}
uint32_t
Ipv4Header::GetUqueue (void)
{
  return m_options.uqueue;
}

void
Ipv4Header::SetDestination (Ipv4Address dst)
{
  m_destination = dst;
}
Ipv4Address
Ipv4Header::GetDestination (void) const
{
  return m_destination;
}


bool
Ipv4Header::IsChecksumOk (void) const
{
  return m_goodChecksum;
}

TypeId 
Ipv4Header::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::Ipv4Header")
    .SetParent<Header> ()
    .AddConstructor<Ipv4Header> ()
    ;
  return tid;
}
TypeId 
Ipv4Header::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
void 
Ipv4Header::Print (std::ostream &os) const
{
  // ipv4, right ?
  std::string flags;
  if (m_flags == 0)
    {
      flags = "none";
    }
  else if (m_flags & MORE_FRAGMENTS &&
           m_flags & DONT_FRAGMENT)
    {
      flags = "MF|DF";
    }
  else if (m_flags & DONT_FRAGMENT)
    {
      flags = "DF";
    }
  else if (m_flags & MORE_FRAGMENTS)
    {
      flags = "MF";
    }
  else
    {
      flags = "XX";
    }
  os << "tos 0x" << std::hex << m_tos << std::dec << " "
     << "ECN " << EcnTypeToString (GetEcn ()) << " "
     << "ttl " << m_ttl << " "
     << "id " << m_identification << " "
     << "protocol " << m_protocol << " "
     << "offset " << m_fragmentOffset << " "
     << "flags [" << flags << "] "
     << "length: " << (m_payloadSize + m_headerSize)
     << " " 
     << m_source << " > " << m_destination
    ;
}
uint32_t 
Ipv4Header::GetSerializedSize (void) const
{
  NS_ASSERT((m_headerSize%4 == 0) && (m_headerSize/4 < 16));
	return m_headerSize;
}

void
Ipv4Header::Serialize (Buffer::Iterator start) const
{
  Buffer::Iterator i = start;
  NS_ASSERT((m_headerSize%4 == 0) && (m_headerSize/4 < 16));
  uint8_t verIhl = (4 << 4) | (m_headerSize/4);
  i.WriteU8 (verIhl);
  i.WriteU8 (m_tos);
  i.WriteHtonU16 (m_payloadSize + m_headerSize);
  i.WriteHtonU16 (m_identification);
  uint32_t fragmentOffset = m_fragmentOffset / 8;
  uint8_t flagsFrag = (fragmentOffset >> 8) & 0x1f;
  if (m_flags & DONT_FRAGMENT) 
    {
      flagsFrag |= (1<<6);
    }
  if (m_flags & MORE_FRAGMENTS) 
    {
      flagsFrag |= (1<<5);
    }
  i.WriteU8 (flagsFrag);
  uint8_t frag = fragmentOffset & 0xff;
  i.WriteU8 (frag);
  i.WriteU8 (m_ttl);
  i.WriteU8 (m_protocol);
  i.WriteHtonU16 (0);
  i.WriteHtonU32 (m_source.Get ());
  i.WriteHtonU32 (m_destination.Get ());

// i.WriteHtonU32 (m_options.PathID);
  i.WriteU8 (m_options.lbTag);
  i.WriteU8 (m_options.ce);
  i.WriteU8 (m_options.fb_lbTag);
  i.WriteU8 (m_options.fb_metric);
  i.WriteHtonU32 (m_options.uqueue);
  i.WriteHtonU32 (m_options.dqueue); 
 
  if (m_calcChecksum) 
    {
      i = start;
      uint16_t checksum = i.CalculateIpChecksum(m_headerSize);
      NS_LOG_LOGIC ("checksum=" <<checksum);
      i = start;
      i.Next (10);
      i.WriteU16 (checksum);
    }
}
uint32_t
Ipv4Header::Deserialize (Buffer::Iterator start)
{
  Buffer::Iterator i = start;
  uint8_t verIhl = i.ReadU8 ();
  uint8_t ihl = verIhl & 0x0f; 
  uint16_t headerSize = ihl * 4;
  NS_ASSERT ((verIhl >> 4) == 4);
  m_tos = i.ReadU8 ();
  uint16_t size = i.ReadNtohU16 ();
  m_payloadSize = size - headerSize;
  m_identification = i.ReadNtohU16 ();
  uint8_t flags = i.ReadU8 ();
  m_flags = 0;
  if (flags & (1<<6)) 
    {
      m_flags |= DONT_FRAGMENT;
    }
  if (flags & (1<<5)) 
    {
      m_flags |= MORE_FRAGMENTS;
    }
  i.Prev ();
  m_fragmentOffset = i.ReadU8 () & 0x1f;
  m_fragmentOffset <<= 8;
  m_fragmentOffset |= i.ReadU8 ();
  m_fragmentOffset <<= 3;
  m_ttl = i.ReadU8 ();
  m_protocol = i.ReadU8 ();
  m_checksum = i.ReadU16();
  /* i.Next (2); // checksum */
  m_source.Set (i.ReadNtohU32 ());
  m_destination.Set (i.ReadNtohU32 ());
  m_headerSize = headerSize;

//  m_options.PathID = i.ReadNtohU32 ();

  m_options.lbTag = i.ReadU8 ();
  m_options.ce = i.ReadU8 ();
  m_options.fb_lbTag = i.ReadU8 ();
  m_options.fb_metric = i.ReadU8 ();
  m_options.uqueue = i.ReadNtohU32 ();
  m_options.dqueue = i.ReadNtohU32 (); 

  if (m_calcChecksum) 
    {
      i = start;
      uint16_t checksum = i.CalculateIpChecksum(headerSize);
      NS_LOG_LOGIC ("checksum=" <<checksum);

      m_goodChecksum = (checksum == 0);
    }
  return GetSerializedSize ();
}

}; // namespace ns3
