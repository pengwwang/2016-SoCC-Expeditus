#!/bin/bash

# Proper header for a Bash script.
# script for SoCC'16 experiment

run=$1 # run
load=$2 # network load
scheme=$3 # scheme used for load balancing traffic
gap=$4  # This parameter only works for flowlet switching
k=$5 # network scale
coreosp=$6 # network oversubscription at core tier
torosp=$7 # network oversubscription at tor tier

cd /proj/expeditus/ns-allinone-3.10/ns-3.10
./waf --run "scratch/FatTree --cdftype=2 --scheme=$scheme --gap=$gap --k=$k --coreosp=$coreosp --torosp=$torosp --tSim=0.05 --load=$load --run=$run"

exit
