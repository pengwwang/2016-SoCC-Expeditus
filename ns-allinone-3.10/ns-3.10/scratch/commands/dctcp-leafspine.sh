#!/bin/bash

echo "create screen, then run simulation"
# parameters: run, load, scheme, gap for flowlet, network scale, coreosp, and torosp
for run in 1  
do 
  for load in 0.1 0.3 0.5 0.7
  do
    for scheme in 0 2 3
    do 
      for gap in 2.0000
      do
        for k in 16
        do
          for torosp in 2
          do
          	sleep 2
                screen -d -m -S LDCTCP$run$load$scheme$gap$k$torosp /proj/expeditus/ns-allinone-3.10/ns-3.10/scratch/LDCTCP.sh $run $load $scheme $gap $k $torosp
          done
        done
      done
    done
  done
done
