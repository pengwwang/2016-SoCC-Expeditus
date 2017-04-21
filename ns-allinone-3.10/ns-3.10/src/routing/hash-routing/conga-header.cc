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
#include "conga-header.h"
#include "ns3/buffer.h"
#include "ns3/log.h"
#include "ns3/uinteger.h"

NS_LOG_COMPONENT_DEFINE ("CongaHeader");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (CongaHeader);

CongaHeader::CongaHeader (uint8_t LBTag, uint8_t CE, uint8_t FB_LBTag, uint8_t FB_Metric)
  : m_LBTag(LBTag), m_CE(CE), m_FB_LBTag(FB_LBTag), m_FB_Metric(FB_Metric)
{
}

CongaHeader::CongaHeader ()
   : m_LBTag(0), m_CE(0), m_FB_LBTag(0), m_FB_Metric(0)
{}

CongaHeader::~CongaHeader ()
{}

TypeId 
CongaHeader::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::CognaHeader")
    .SetParent<Header> ()
    .AddConstructor<CongaHeader> ()
     ;
  return tid;
}

// Setters
void CongaHeader::SetLBTag (uint8_t LBTag)
{
  m_LBTag = LBTag;
}

void CongaHeader::SetCE (uint8_t CE)
{
  m_CE = CE;
}

void CongaHeader::SetFB_LBTag (uint8_t FB_LBTag)
{
  m_FB_LBTag = FB_LBTag;
}

void CongaHeader::SetFB_Metric (uint8_t FB_Metric)
{
  m_FB_Metric = FB_Metric;
}

// Getters
uint8_t CongaHeader::GetLBTag ()
{
  return m_LBTag;
}

uint8_t CongaHeader::GetCE ()
{
  return m_CE;
}

uint8_t CongaHeader::GetFB_LBTag ()
{
  return m_FB_LBTag;
}

uint8_t CongaHeader::GetFB_Metric ()
{
  return m_FB_Metric;
}

TypeId 
CongaHeader::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}
void CongaHeader::Print (std::ostream &os) const
{ 
}

uint32_t CongaHeader::GetSerializedSize (void)  const
{   
  return 4;
}


void CongaHeader::Serialize (Buffer::Iterator start) const
{
  start.WriteU8 (m_LBTag);
  start.WriteU8 (m_CE);
  start.WriteU8 (m_FB_LBTag);
  start.WriteU8 (m_FB_Metric);
}

uint32_t CongaHeader::Deserialize (Buffer::Iterator start)
{
  m_LBTag = start.ReadU8 ();
  m_CE = start.ReadU8 ();
  m_FB_LBTag = start.ReadU8 ();
  m_FB_Metric = start.ReadU8 ();
  return GetSerializedSize ();
}

}; // namespace ns3
