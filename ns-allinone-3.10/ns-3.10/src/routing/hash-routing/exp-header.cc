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
 * Author: Peng Wang <pengwang.xd@gamil.com>
 */

#include <stdint.h>
#include <iostream>
#include "exp-header.h"
#include "ns3/buffer.h"
#include "ns3/log.h"
#include "ns3/uinteger.h"
#define CONGINFO_SIZE 1


NS_LOG_COMPONENT_DEFINE ("ExpHeader");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (ExpHeader);

ExpHeader::ExpHeader (std::vector<uint8_t> &pathcong, uint8_t size)
  : m_pathcong(pathcong), m_size(size)
{
}

ExpHeader::ExpHeader ()
   : m_pathcong (0), m_size(0)
{}

ExpHeader::~ExpHeader ()
{}

TypeId 
ExpHeader::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::ExpHeader")
    .SetParent<Header> ()
    .AddConstructor<ExpHeader> ()
     ;
  return tid;
}

void ExpHeader::SetPathcong (std::vector<uint8_t>& pathcong, uint8_t size)
{
  m_size = size;
  m_pathcong.clear ();
  m_pathcong.erase (m_pathcong.begin(), m_pathcong.end());
  m_pathcong.reserve(pathcong.size());
  std::copy (pathcong.begin(), pathcong.end(), back_inserter(m_pathcong));
}

std::vector<uint8_t> ExpHeader::GetPathcong () 
{
  return m_pathcong;
}

uint8_t ExpHeader::GetSize ()
{
  return m_size;
}

TypeId 
ExpHeader::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
void ExpHeader::Print (std::ostream &os) const
{
    os << "( The path information << ";

    for (std::vector<uint8_t>::const_iterator iter = m_pathcong.begin(); iter != m_pathcong.end(); iter++)
    {
        os << *iter << " ";
    }
    
}

uint32_t ExpHeader::GetSerializedSize (void)  const
{   
  return (m_pathcong.size() * CONGINFO_SIZE + 1);
}


void ExpHeader::Serialize (Buffer::Iterator start) const
{
  start.WriteU8 (m_size);
  for (std::vector<uint8_t>::const_iterator iter = m_pathcong.begin ();
       iter != m_pathcong.end (); iter++)
    {
       start.WriteU8 (*iter);
    }
}

uint32_t ExpHeader::Deserialize (Buffer::Iterator start)
{
  m_size = start.ReadU8 ();
  m_pathcong.clear ();
  m_pathcong.erase (m_pathcong.begin(), m_pathcong.end());
  for (uint8_t n = 0; n < m_size; n++)
  {
     m_pathcong.push_back (uint8_t (start.ReadU8 ()));
  }
  return m_pathcong.size() * CONGINFO_SIZE;
}

}; // namespace ns3
