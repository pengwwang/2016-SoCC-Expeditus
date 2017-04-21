/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
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
 * Author: Adrian S.-W. Tam <adrian.sw.tam@gmail.com>
 */

#include <stdint.h>
#include <iostream>
#include "cn-header.h"
#include "ns3/buffer.h"
#include "ns3/address-utils.h"
#include "ns3/log.h"

NS_LOG_COMPONENT_DEFINE ("CnHeader");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (CnHeader);

CnHeader::CnHeader (const flowid& fid, uint8_t q)
  : m_fid(fid), m_qfb(q)
{
  NS_LOG_LOGIC("CN got the flow id " << std::hex << m_fid.hi << "+" << m_fid.lo << std::dec);
}

CnHeader::CnHeader ()
  : m_fid(), m_qfb(0)
{}

CnHeader::~CnHeader ()
{}

void CnHeader::SetFlow (const flowid& fid)
{
  m_fid = fid;
}
void CnHeader::SetQfb (uint8_t q)
{
  m_qfb = q;
}

flowid CnHeader::GetFlow () const
{
  return m_fid;
}
uint8_t CnHeader::GetQfb () const
{
  return m_qfb;
}

TypeId 
CnHeader::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::CnHeader")
    .SetParent<Header> ()
    .AddConstructor<CnHeader> ()
    ;
  return tid;
}
TypeId 
CnHeader::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
void CnHeader::Print (std::ostream &os) const
{
  m_fid.Print(os);
  os << " qFb=" << (unsigned) m_qfb;
}
uint32_t CnHeader::GetSerializedSize (void)  const
{
  return 16;
}
void CnHeader::Serialize (Buffer::Iterator start)  const
{
  uint64_t hibyte = m_fid.hi;
  uint64_t lobyte = m_fid.lo;
  lobyte = (lobyte & 0x00FFFFFFFFFFFFFFLLU) | (static_cast<uint64_t>(m_qfb)<<56);
  start.WriteU64 (hibyte);
  start.WriteU64 (lobyte);
  NS_LOG_LOGIC("CN Seriealized as " << std::hex << hibyte << "+" << lobyte << std::dec);
}

uint32_t CnHeader::Deserialize (Buffer::Iterator start)
{
  uint64_t hibyte = start.ReadU64 ();
  uint64_t lobyte = start.ReadU64 ();
  NS_LOG_LOGIC("CN deseriealized as " << std::hex << hibyte << "+" << lobyte << std::dec);
  m_qfb = static_cast<uint8_t>(lobyte>>56);
  m_fid.hi = hibyte;
  m_fid.lo = lobyte & 0x00FFFFFFFFFFFFFFLLU;
  return GetSerializedSize ();
}


}; // namespace ns3
