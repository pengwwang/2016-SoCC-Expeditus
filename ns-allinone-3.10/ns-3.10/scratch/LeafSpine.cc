// Code for Expeditus experiment is modified from code for tinyflow experiment
// Author: Peng Wang <pewang@cityu.edu.hk>
// City University of Hong Kong

// Tinyflow experiment
// Author: Hong Xu <henry.xu@cityu.edu.hk>
// City University of Hong Kong
// 

/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
* Copyright (c) 2014 Hong Xu <henry.xu@cityu.edu.hk>

	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "ns3/core-module.h"
#include "ns3/helper-module.h"
#include "ns3/node-module.h"
#include "ns3/simulator-module.h"
#include "ns3/log.h"
#include "ns3/ptr.h"
#include <time.h>
#include "ns3/internet-stack-helper.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/queue.h"
#include "ns3/uinteger.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/ipv4-address-generator.h"
#include "ns3/ipv4-hash-routing-helper.h"
#include "ns3/random-variable.h"
#include "ns3/packet-sink.h"
#include "ns3/leaf-spine-helper.h"
#include "ns3/flow-monitor-helper.h"
#include "ns3/point-to-point-helper.h"

#define ECMP 0
#define OPTIMAL 1
#define EXPEDITUS 2
#define CONGA 3
/*

- The code is constructed in the following order:
1. Creation of Node Containers 
2. Initialize settings for On/Off Application
3. Connect hosts to edge switches
4. Connect edge switches to aggregate switches
5. Connect aggregate switches to core switches
6. Start Simulation

- Addressing scheme:
1. Address of host: 10.pod.switch.0 /24
2. Address of edge and aggregation switch: 10.pod.switch.0 /16
3. Address of core switch: 10.(group number + k).switch.0 /8
(Note: there are k/2 group of core switch)

- On/Off Traffic of the simulation: addresses of client and server are randomly selected everytime
	
- Simulation Settings:
- Number of pods (k): 4-72 (run the simulation with varying values of k)
- Number of nodes: 16-3400
- Simulation running time: 0.05 seconds
- Packet size: 1460 bytes
- Data rate for packet sending: 1000 Mbps
- Data rate for device channel: 1000 Mbps
- Delay time for device: 0.001 ms
- Communication pairs selection: Random Selection with uniform probability

- Statistics Output:
- Flowmonitor XML output file: Fat-tree.xml is located in the /statistics folder
            

*/

using namespace ns3;
using namespace std;
NS_LOG_COMPONENT_DEFINE ("LeafSpine");


// Main function
//
int 
	main(int argc, char *argv[])
{
	//=========== Define parameters for topology ===========//
	int k = 4;					// Number of pods 
   
	//int total_flows = 50; 	// Number of flows
	double linkDelay = 5e-9;	// Link delay in seconds (5ns = 1m wire)
	double linkBw = 1e10;		// Link bandwidth in bps	
       int torosp = 2;
	   
  //============Define parameters for load balancing========//
      int scheme = ECMP;  // Default load balancing scheme
      double flowletGap = 2e-4; // default 200us for flowlet
//double flowletGap = 2; // default 200us for flowlet

      double routeEntryExpire = 0.1; // default 100ms for each route entry to be expired  
      double congEntryExpire = 0.01; // default 10ms for each congestion entry to be expired

        
	//=========== Define variables for On/Off Application  ===========//
	uint32_t nsender;
	uint32_t nreceiver;
	int port = 1000;
	int packetSize = 1400;
     
        double interarrival = 0.00028;	// Interarrival mean time
	int cdftype = 1;				// Flow size ditribution to choose: 1 for DCTCP, 2 for VL2
	double tSim = 0.05;				// Simulation time
        int flowNumber = 1e9;                          // number of flow generated for simulation 
	int run = 1;					// Number of simulation run
	double load = 0.2;

	//int maxBytes = 300000;		// start with 30KB

	// Initialize other variables
	int i = 0;	


         //============ Parameters Got from Command Line ===========//
      CommandLine cmd;
      cmd.AddValue ("cdftype", "Which traffic distribution", cdftype);
      cmd.AddValue ("scheme", "Which scheme to select path", scheme);
	cmd.AddValue ("k", "Number of pods", k);	
      cmd.AddValue ("torosp", "Oversubscription ratio at ToR tier", torosp);	
      cmd.AddValue ("flowNumber", "Number of flows generated", flowNumber);
      cmd.AddValue ("tSim", "Simulation time", tSim);
      cmd.AddValue ("gap", "Flowlet gap time", flowletGap);
      cmd.AddValue ("load", "Load of the network (<1)", load);
	cmd.AddValue ("run", "Which run to use", run);
	cmd.Parse (argc, argv);

           // =========== Configure routing ====================//
        Config::SetDefault ("ns3::HashRouting::Scheme", UintegerValue (scheme));
        Config::SetDefault ("ns3::HashRouting::RoutingEntryLifetime", TimeValue(Seconds (routeEntryExpire)));
        Config::SetDefault ("ns3::HashRouting::CongestionEntryLifetime", TimeValue(Seconds (congEntryExpire)));
        Config::SetDefault ("ns3::HashRouting::FlowletGap", TimeValue(Seconds (flowletGap)));
        Config::SetDefault ("ns3::HashRouting::ToROsp", UintegerValue(torosp));
 
	//=========== Configure applications and transport protocols  ===========//
	
	// Important TCP tuning and queue sizes
//	Config::SetDefault ("ns3::TcpSocket::SegmentSize", UintegerValue(1460));
        Config::SetDefault ("ns3::TcpSocket::SegmentSize", UintegerValue(1400));
	Config::SetDefault("ns3::TcpSocket::DelAckCount", UintegerValue (0));
	Config::SetDefault("ns3::TcpSocket::DelAckTimeout", TimeValue(Seconds (0.005)));

	Config::SetDefault("ns3::RttEstimator::InitialEstimation", TimeValue(MicroSeconds(200))); 
	Config::SetDefault("ns3::RttEstimator::MinRTO", TimeValue(MicroSeconds(200))); // The fabric rtt is ~32 us across pods
	// This helps to reduce the initial delay for TCP flows
	//Config::SetDefault ("ns3::TcpL4Protocol::SocketFactory", StringValue("ns3::TcpNewReno"));
	Config::SetDefault ("ns3::TcpSocket::SlowStartThreshold", UintegerValue(65535));
//	 Config::SetDefault ("ns3::TcpSocket::SndBufSize", UintegerValue(13107200));
//	 Config::SetDefault ("ns3::TcpSocket::RcvBufSize", UintegerValue(13107200));

       
        //=========== Configure queues  ===========//
	Config::SetDefault ("ns3::DropTailQueue::Mode", StringValue("Packets"));
	Config::SetDefault ("ns3::DropTailQueue::MaxPackets", UintegerValue(100));
      
        //=========== Configure devices ===========// 
        Config::SetDefault ("ns3::SpNetDevice::MultiplicativeFactor", DoubleValue(0.7));
        Config::SetDefault ("ns3::SpNetDevice::DecrementInterval", UintegerValue(20));
        Config::SetDefault ("ns3::SpNetDevice::CongestionLevel", UintegerValue(8));
        Config::SetDefault ("ns3::SpNetDevice::LinkSpeed", UintegerValue(10)); // 10Gbps link capacity



	int n = k/2;					//  Number of spines
	int total_host = torosp*k*k/4;	// Number of hosts in the entire network
	// Create the Leaf-spine topology
	NodeContainer hosts;
	Ptr<LeafSpineHelper> net = CreateObject<LeafSpineHelper>(n);
      net->SetAttribute("ToROsp", UintegerValue(torosp));
	net->SetAttribute("HeDelay", TimeValue(Seconds(linkDelay)));
	net->SetAttribute("EaDelay", TimeValue(Seconds(linkDelay)));
	net->SetAttribute("HeDataRate", DataRateValue(DataRate(linkBw)));
	net->SetAttribute("EaDataRate", DataRateValue(DataRate(linkBw)));


	net->Create();
	hosts = net->HostNodes();
	
	char *filename = (char *)malloc(100*sizeof(char));
    // struct passwd *pw = getpwuid(getuid());
     // char *homedir = pw->pw_dir;
	if (cdftype == 1)
		sprintf(filename, "/proj/expeditus/SOCC-Results-Leafspine/DCTCP/Run-%d-%d-%.2f-%.4f-%.1f-%d-%d.xml", run, scheme, tSim, flowletGap, load, k, torosp);

	else if (cdftype == 2)	
		sprintf(filename, "/proj/expeditus/SOCC-Results-Leafspine/VL2/Run-%d-%d-%.2f-%.4f-%.1f-%d-%d.xml", run,  scheme, tSim, flowletGap, load, k, torosp);
	else {
		std::cout << "Wrong traffic distribution type selected!\n";
		return 0;
	}
	
	// Calculate interarrival time for a given load
	if (cdftype == 1) {
		// DCTCP mean flow size is 1134KB
		// Hong reports issue about oversubscription
	//	interarrival = static_cast<double>(8.0*1134/total_host) / static_cast<double>((linkBw/1e3)*load); 
		interarrival = static_cast<double>(8.0*1134/(total_host/torosp)) / static_cast<double>((linkBw/1e3)*load); 
	}
        if (cdftype == 2) {
                // VL2 mean flow size is 2126KB
		// Hong reports issue about oversubscription
               // interarrival = static_cast<double>(8.0*2126/total_host) / static_cast<double>((linkBw/1e3)*load);
                interarrival = static_cast<double>(8.0*2126/(total_host/torosp)) / static_cast<double>((linkBw/1e3)*load);
        } 
	std::cout << "Interarrival time is " << interarrival << " for load " << load << endl;
	// Generate traffics for the simulation
	ApplicationContainer flows;
	ApplicationContainer sinkApps;
	// Different runs use different run number for RNG
	SeedManager::SetSeed ( (run));
	ExponentialVariable x(interarrival);
	double tflow = 0;
	EmpiricalVariable fsize;
	if (cdftype == 1) {		// DCTCP traffic trace
		fsize.CDF (6.0, 0.15);
		fsize.CDF (13.0, 0.2);
		fsize.CDF (19.0, 0.3);
		fsize.CDF (33.0, 0.4);
		fsize.CDF (53.0, 0.53);
		fsize.CDF (133.0, 0.6);
		fsize.CDF (667.0, 0.7);
		fsize.CDF (1333.0, 0.8);
		fsize.CDF (3333.0, 0.9);
		fsize.CDF (6667.0, 0.97);
		fsize.CDF (20000.0, 1.0);
	}
	else if (cdftype == 2) {	// VL2 traffic trace
		fsize.CDF (1.0, 0.5);
		fsize.CDF (2.0, 0.6);
		fsize.CDF (3.0, 0.7);
		fsize.CDF (7.0, 0.8);
		fsize.CDF (267.0, 0.9);
		fsize.CDF (2107.0, 0.95);
// Hong reports this issue
		fsize.CDF (66667.0, 0.99);
		fsize.CDF (666667.0, 1.0);
	}



	for (i=0; tflow <= tSim ;i++, port++){
		tflow += x.GetValue(); // Generate a flow starting time
                // Set the amount of data to send in bytes.  Zero is unlimited.               
	        int tempsize = fsize.GetInteger();

		if (i == flowNumber)   
 	 		break;
                
		nreceiver = rand() % total_host; // Randomly select a receiver
			
		// Randomly select a sender
		nsender = rand() % total_host;

		while (nsender == nreceiver){
			nsender = rand() % total_host;
		} // to make sure that client and server are different

		Ptr<Node> receiver = hosts.Get(nreceiver);
		Ptr<NetDevice> ren = receiver->GetDevice(0);
		Ptr<Ipv4> ipv4 = receiver->GetObject<Ipv4> ();

		NS_ASSERT_MSG (ipv4, "NetDevice is associated"
                		" with a node without IPv4 stack installed -> fail "
						"(maybe need to use InternetStackHelper?)");
		Ipv4InterfaceAddress r_ip = ipv4->GetAddress (1,0);
		Ipv4Address r_ipaddr = r_ip.GetLocal();
            
		// Initialize On/Off Application with addresss of receiver
	        OnOffHelper source ("ns3::TcpSocketFactory", Address (InetSocketAddress(r_ipaddr, port)));
	        source.SetAttribute ("OnTime", RandomVariableValue (ConstantVariable (1)));
	        source.SetAttribute ("OffTime", RandomVariableValue (ConstantVariable (0)));
		source.SetAttribute ("DataRate", DataRateValue (DataRate(linkBw))); 

		// r_ipaddr.Print (std::cout); std::cout<<endl;	

	        source.SetAttribute ("MaxBytes", UintegerValue (tempsize*1000));
		source.SetAttribute("PacketSize",UintegerValue (packetSize));
	
		
		// Install sink	
		PacketSinkHelper sink("ns3::TcpSocketFactory", Address(InetSocketAddress(Ipv4Address::GetAny(), port)));
		sinkApps.Add(sink.Install(hosts.Get(nreceiver)));
		
		// Install source to the sender
		NodeContainer onoff;
		onoff.Add(hosts.Get(nsender));
		flows.Add(source.Install (onoff));
		// Get the current flow
		Ptr<Application> the_flow = flows.Get(flows.GetN()-1);
		the_flow->SetStartTime(Seconds(tflow));
		
		// Initialize the duplicated flow with addresss of server	
	}	

	flows.Stop(Seconds(tSim+1));
	sinkApps.Start(Seconds(0));
	sinkApps.Stop(Seconds(tSim+1));
	std::cout << "Finished creating "<< i << " flows for " << tSim << " seconds...\n";
	
	//=========== Start the simulation ===========//
	std::cout << "Start Simulation.. "<<"\n";

	// Calculate Throughput using Flowmonitor
	FlowMonitorHelper flowmon;
	Ptr<FlowMonitor> monitor = flowmon.InstallAll();

//PointToPointHelper pointToPoint; 		
//pointToPoint.EnablePcap ("LeafSpine", (hosts.Get(0))->GetDevice(1));

	// Run simulation.
	NS_LOG_INFO ("Run Simulation.");
	Simulator::Stop (Seconds(tSim+1));
	Simulator::Run ();

	cout << "Run finished, now writing output...\n";
	monitor->CheckForLostPackets ();
	monitor->SerializeToXmlFile(filename, false, false);

	std::cout << "Simulation finished "<<"\n";

	Simulator::Destroy ();
	NS_LOG_INFO ("Done.");


	return 0;
}




