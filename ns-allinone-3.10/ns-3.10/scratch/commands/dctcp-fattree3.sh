#!/bin/bash

echo "create screen, then run simulation"
# parameters: run, load, scheme, gap for flowlet, network scale, coreosp, and torosp
for run in 3 
do 
  for load in 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8
  do
    for scheme in 3 
    do 
      for gap in 0.0001
      do
        for k in 12
        do
          for coreosp in 2
          do
            for torosp in 1
            do
          	    sleep 2
                screen -d -m -S FDCTCP$run$load$scheme$gap$k$coreosp$torosp /proj/expeditus/ns-allinone-3.10/ns-3.10/scratch/FDCTCP.sh $run $load $scheme $gap $k $coreosp $torosp
            done
          done
        done
      done
    done
  done
done
