/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

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

#ifndef SP_NET_DEVICE_H
#define SP_NET_DEVICE_H

#include "ns3/type-id.h"
#include "ns3/point-to-point-net-device.h"
#include "ns3/fivetuple.h"

namespace ns3 {

/**
 * \class SpNetDevice
 * \brief Packet Sampling Point Device for a Point to Point Network Link
 *
 * This SpNetDevice class extends PointToPointNetDevice
 * to support sampling in order to detect elephant flows.
 * A signal (CN message in IEEE 802.1 qau) is sent for sampling.
 * Elephants are detected by hash routing.
 */
class SpNetDevice : public PointToPointNetDevice
{
public:
	static TypeId GetTypeId (void);

	SpNetDevice ();
	virtual ~SpNetDevice ();

	/**
	 * Queue up a packet to send out of this device
	 *
	 * This is a specialization of the pure virtual function inherited from
	 * NetDevice class. We extended the verison from PointToPointNetDevice
	 * to send packet sample signals.
	 */
	virtual bool Send(Ptr<Packet> packet, const Address &dest, uint16_t protocolNumber);
        
         /**
	 * Receive packets from lower level
	 *
	 * This is a specialization of the pure virtual function inherited from
	 * NetDevice class. We extended the verison from PointToPointNetDevice
	 * to collect the number of bytes received.
	 */
        virtual void Receive(Ptr<Packet> packet);

        uint32_t OutRate ();
        uint32_t InRate ();
        uint32_t FlowsinCounter ();
protected:
        struct FlowElement{
                Time last;
                flowid fid;                 
        };
        std::vector<FlowElement> m_flowRecord;
	// uint8_t ShouldSendCN(flowdid& fid, uint32_t pktSize);
//	uint8_t ShouldSendCN(uint32_t pktSize);
//	uint32_t m_qeq;
//	uint32_t m_speedup;
        uint32_t m_clevels;
	uint32_t m_decrement_interval;
        uint32_t m_linkSpeed;
	double m_w;
	// int32_t m_qOld[qCnt];
	int32_t m_startInCounter;
        int32_t m_startOutCounter;
//	bool m_enable;
        uint32_t m_outBytes;
        uint32_t m_inBytes;
        uint32_t m_flows;
        
        void InBytesClear ();
        void OutBytesClear ();
 //       bool m_StartSample;
};

} // namespace ns3

#endif // SP_NET_DEVICE_H
