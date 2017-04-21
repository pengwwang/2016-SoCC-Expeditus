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
 * Author: Peng Wang <pengwang.xd@gmail.com>
 */

#ifndef CONGA_HEADER_H
#define CONGA_HEADER_H

#include <stdint.h>
#include "ns3/header.h"
#include "ns3/buffer.h"

namespace ns3 {

/**
 * \ingroup CONGA header
 * \brief Header to contain the path congestion information 
 *
 * This class has a vector which presents congestion information for each path
 */

class CongaHeader: public Header 
{
public:
  CongaHeader (uint8_t LBTag, uint8_t CE, uint8_t FB_LBTag, uint8_t  FB_Metric);
  CongaHeader ();
  virtual ~CongaHeader ();

  //Setters
  void SetLBTag (uint8_t LBTag);
  void SetCE (uint8_t CE);
  void SetFB_LBTag (uint8_t FB_LBTag);
  void SetFB_Metric (uint8_t FB_Metric);

  //Getters
   uint8_t GetLBTag ();
   uint8_t GetCE ();
   uint8_t GetFB_LBTag ();
   uint8_t GetFB_Metric ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual void Print (std::ostream &os) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);

private:
  uint8_t m_LBTag;
  uint8_t m_CE;
  uint8_t m_FB_LBTag;
  uint8_t m_FB_Metric;
};

}; // namespace ns3

#endif /* CONGA_HEADER */
