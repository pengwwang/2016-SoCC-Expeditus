/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

// # Copyright (c) 2014 Hong Xu
// # This is a point-to-point device that samples packets. It's to simulate
// a switch port with packet sampling in order to detect elephant flows. 
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

// # Author: Hong Xu, <henry.xu@cityu.edu.hk>

#include "ns3/log.h"
#include "ns3/uinteger.h"
#include "ns3/pointer.h"
#include "ns3/double.h"
#include "ns3/ppp-header.h"
#include "ns3/ipv4-header.h"
#include "ns3/tcp-header.h"
#include "ns3/ipv4.h"
#include "ns3/queue.h"
#include "ns3/random-variable.h"
#include "ns3/error-model.h"
#include "ns3/sp-net-device.h"
#include "ns3/cn-header.h"
#include "ns3/boolean.h"
#include "ns3/simulator.h"

NS_LOG_COMPONENT_DEFINE ("SpNetDevice");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (SpNetDevice);

TypeId
SpNetDevice::GetTypeId (void)
{
	static TypeId tid = TypeId ("ns3::SpNetDevice")
	.SetParent<PointToPointNetDevice> ()
	.AddConstructor<SpNetDevice> ()
	.AddAttribute (	"MultiplicativeFactor",
			"multiplicative factor for bytes counter",
			DoubleValue (0.8),
			MakeDoubleAccessor (&SpNetDevice::m_w),
			MakeDoubleChecker<double>())
	.AddAttribute (	"DecrementInterval",
			"Decrement interval for bytes counter",
			// default to 20, will be configured in the program
			UintegerValue (20),
			MakeUintegerAccessor (&SpNetDevice::m_decrement_interval),
			MakeUintegerChecker<uint32_t>())
        .AddAttribute (	"CongestionLevel",
			"The number of levels used to describe congesiton information",
			// default to 4, will be configured in the program
			UintegerValue (8),
			MakeUintegerAccessor (&SpNetDevice::m_clevels),
			MakeUintegerChecker<uint32_t>())   
        .AddAttribute ( "LinkSpeed",
                        "The default data rate for point to point links",
                        UintegerValue (10),
			MakeUintegerAccessor (&SpNetDevice::m_linkSpeed),
			MakeUintegerChecker<uint32_t>())   
	;
	return tid;
}


SpNetDevice::SpNetDevice ()
{
	// Most things are done by the underlying PointToPointNetDevice
	NS_LOG_FUNCTION (this);
        m_inBytes = 0;
        m_outBytes = 0;
        m_startInCounter = true;
        m_startOutCounter = true;
}

SpNetDevice::~SpNetDevice ()
{
}

void
SpNetDevice::Receive(Ptr<Packet> packet)
{
        if (m_startInCounter)
        {
                m_startInCounter = false; 
                InBytesClear ();
        }
        m_inBytes += packet->GetSize();
        PointToPointNetDevice::Receive(packet);
}

bool
SpNetDevice::Send(Ptr<Packet> packet, const Address &dest, uint16_t protocolNumber)
{
	NS_LOG_FUNCTION (this << packet << dest << protocolNumber);

	// Rely on PointToPointNetDevice::Send() to put the packet into wire.
	// If failed, return and do nothing;
	// otherwise, check if we need to send a sampling signal
	Ptr<Packet> p = packet->Copy();
	bool ok = PointToPointNetDevice::Send(packet, dest, protocolNumber);
	if (!ok) return false;

        if (m_startOutCounter)
        {
                m_startOutCounter = false; 
                OutBytesClear ();
        }

        m_outBytes += packet->GetSize();

	return true;
};

uint32_t 
SpNetDevice::InRate ()
{
        // Refer CONGA paper for the parameter settings
        return m_inBytes/(m_linkSpeed*1e9*m_decrement_interval*1e-6/(1-m_w)/8/m_clevels);
}

uint32_t 
SpNetDevice::OutRate ()
{
        return m_outBytes/(m_linkSpeed*1e9*m_decrement_interval*1e-6/(1-m_w)/8/m_clevels);
}

void
SpNetDevice::InBytesClear ()
{
  m_inBytes = m_inBytes * m_w;
  Simulator::Schedule (MicroSeconds(m_decrement_interval), &SpNetDevice::InBytesClear, this);
}  

void
SpNetDevice::OutBytesClear ()
{
  m_outBytes = m_outBytes * m_w;
  Simulator::Schedule (MicroSeconds(m_decrement_interval), &SpNetDevice::OutBytesClear, this);
}  

} // namespace ns3
