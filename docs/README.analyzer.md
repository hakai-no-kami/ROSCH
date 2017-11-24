# Using Analyzer

Follow the instruction below to analyze task allocation with fixted priority scheduling. 
Analyzer dipicts a graph and a scheduling result. 
`$(TOPDIR)` represents your top working directory.

## 1. Preparation

Please, prepare __anazlyzer_rosch.yaml__ in `$(TOPDIR)/YAMLs/`.

Required ROS node information:

 * __nodename__ : the name of ROS node
 * __core__ : if this node uses n cores (e.g., OpenMP), core is n.
 * __sub_topic__ : topics for subscribe
 * __pub_topic__ : topics for publish
 * __run_time__ : the execution time
 * __deadline__ : if an end node, set a deadline. Otherwise set to 0.
 * __period__ : if an entry node, set a period. Otherwise set to 0.


## 2. How to make

```sh
$ cd $(TOPDIR)/Analyzer
$ make
``` 

## 3. How to use

```sh 
$ cd $(TOPDIR)/Analyzer/bin
$ ./Analyzer
```

