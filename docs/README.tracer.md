# Using Tracer

Tracer supports tracing and vizualization for processes including ROS node.

## 1. How to Install

```sh
$ cd $(TOPDIR)/ROSCH/Tracer
$ make
``` 

## 2. How to use

Please list the nodes you want to trace on the trace_rosch.yaml.
After that, please run following commands.

```sh
$ cd bin
$ ./Tracer
``` 

Required ROS node information:

 * `nodename`: the name of ROS node (process)
 * `deadline`: period  (Not compulsory)

## 3. If core dump occurs

Please comment out or uncomment `#DEFINE CORE_DUMP` in tracer.h.
