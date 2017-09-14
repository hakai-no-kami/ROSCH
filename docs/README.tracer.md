# Using Tracer

Tracer supports tracing and vizualization for processes including ROS nodes.

## 1. How to Install

```sh
$ cd $(TOPDIR)/Tracer
$ make
``` 

## 2. How to use

Please list the nodes to trace_rosch.yaml.
After that, please run the following command.

```sh
$ ./Tracer
``` 

Required ROS node information:

 * `nodename`: the name of ROS node (process)
 * `deadline`: period (Not compulsory)

