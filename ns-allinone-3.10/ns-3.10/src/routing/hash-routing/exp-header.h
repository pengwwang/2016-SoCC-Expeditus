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

#ifndef EXP_HEADER_H
#define EXP_HEADER_H

#include <stdint.h>
#include "ns3/header.h"
#include "ns3/buffer.h"

#include <vector>
#include <iterator> // std::back_inserter
#include <algorithm> // std::copy

namespace ns3 {

/**
 * \ingroup overlay header
 * \brief Header to contain the path congestion information 
 *
 * This class has a vector which presents congestion information for each path
 */

class ExpHeader : public Header 
{
public:
  ExpHeader (std::vector<uint8_t> &pathcong, uint8_t size);
//  ExpHeader (uint32_t data);
  ExpHeader ();
  virtual ~ExpHeader ();

//Setters
  /**
   * \param path congestion information
   */
  void SetPathcong (std::vector<uint8_t>& pathcong, uint8_t size);
//    void SetData (uint32_t data);    

//Getters
  /**
   * \return The path congestion information
   */
   std::vector<uint8_t> GetPathcong ();
//     uint32_t GetData();

   uint8_t GetSize ();

  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;
  virtual void Print (std::ostream &os) const;
  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (Buffer::Iterator start) const;
  virtual uint32_t Deserialize (Buffer::Iterator start);

private:
  std::vector<uint8_t> m_pathcong;
  uint8_t m_size;
};

}; // namespace ns3

#endif /* EXP_HEADER */
