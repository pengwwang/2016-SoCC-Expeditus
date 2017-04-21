
***Expeditus Simulation*** is conducted on packet-level simulator ns-3.10 to compare Expeditus with CONGA and ECMP in various scenarios. 

## Installation

To install ns-3.10 on Ubuntu 14.04 LTS, you have to make g++-4.4 be the default compiler and diable some features in ns-3.10. 

### Replace g++
```bash
$ sudo apt-get install -y g++-4.4
$ CXX=g++-4.4
$ sudo mv /usr/bin/g++ /usr/bin/g++.bak
$ sudo cp /usr/bin/g++-4.4 /usr/bin/g++
```

### Modify ns-3.10
```bash
$ vim ns-3.10/src/core/unix-system-wall-clock-ms.cc
  add headfile: '#include <unistd.h>'
$ python waf configure --disable-python --with-nsc ../nsc-0.5.2 
$ vim build.py
  #comment out line 59 
  'run_command(cmd);'
$ export CXXFLAGS="-Wall"

```

## References

Please refer to the following papers for the details of Expeditus: 

<a href="http://www.cs.cityu.edu.hk/~hxu/share/peng-socc16.pdf"> Expeditus: Congestion-aware Load Balancing in Clos Data Center Networks</a>, Peng Wang, Hong Xu, Zhixiong Niu, Dongsu Han, Yongqiang Xiong, ACM, SoCC, 2016.
