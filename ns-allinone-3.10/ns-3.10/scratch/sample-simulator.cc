/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2010 INRIA
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
 * Authors: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */

#include <iostream>
#include "ns3/simulator.h"
#include "ns3/nstime.h"
#include "ns3/command-line.h"
#include "ns3/random-variable.h"

using namespace ns3;

class MyModel
{
public:
  void Start (void);
  void Rep (void);
private:
  void HandleEvent (double eventValue);
};

void
MyModel::Start (void)
{
  if (Simulator::Now().GetSeconds()>100)
     return; 
  std::cout << "S start at: " << Simulator::Now().GetSeconds() << std::endl;
  Simulator::Schedule (Seconds(10.0),
//                       &MyModel::HandleEvent,
                       &MyModel::Start,
//                       this, Simulator::Now ().GetSeconds ());
                       this);
}

void
MyModel::Rep (void)
{
  if (Simulator::Now().GetSeconds()>200)
     return;
  std::cout << "rep start at: " << Simulator::Now().GetSeconds() << std::endl;
  Simulator::Schedule (Seconds(20.0),
//                       &MyModel::HandleEvent,
                       &MyModel::Rep,
//                       this, Simulator::Now ().GetSeconds ());
                       this);
}

//void
//MyModel::HandleEvent (double value)
//{
//  std::cout << "Member method received event at "
//            << Simulator::Now ().GetSeconds ()
//            << "s started at " << value << "s" << std::endl;
//}

static void
ExampleFunction (MyModel *model)
{
  std::cout << "ExampleFunction received event at "
            << Simulator::Now ().GetSeconds () << "s" << std::endl;
  model->Start ();
}

static void
RandomFunction (MyModel *model)
{
  std::cout << "RandomFunction received event at "
            << Simulator::Now ().GetSeconds () << "s" << std::endl;
  model->Rep ();
}

static void
CancelledEvent (void)
{
  std::cout << "I should never be called... " << std::endl;
}

int main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc, argv);

  MyModel model;
  UniformVariable v = UniformVariable (10, 20);

  Simulator::ScheduleNow (&ExampleFunction, &model);

//  Simulator::ScheduleNow (&ExampleFunction, &model);
  std::cout << "in the main function" << std::endl;
  Simulator::Schedule (Seconds (v.GetValue ()), &RandomFunction, &model);

  EventId id = Simulator::Schedule (Seconds (110.0), &CancelledEvent);
  Simulator::Cancel (id);
  
  Simulator::Run ();

  Simulator::Destroy ();
}