# Using Scheduler

Follow the instruction below to schedule for ROS node with Fixed-Priority.
`$(TOPDIR)` represents your top working directory.

## 1. How to use

 Please list ROS node informations you schedule in `$(TOPDIR)/YAMLs/scheduler_rosch.yaml`.
 Then, please change `core`, `run_time`, and `sched_info` as necessary.
After that, launch ROS nodes listed in __scheduler_rosch.yaml__.

Required ROS node information:
  
 * __nodename__ : the name of ROS node
 * __core__ : if this node uses n cores, core is n.
 * __sub_topic__ : topic for subscribe
 * __pub_topic__ : topic for publish
 * __run_time__ : the execution time
 * __sched_info__ : scheduling parameters (i.g., `core`, `priority`, `start_time`, `run_time`). Note that `core` at sched_info indicates tha place to assign ROS node.

## 2. How to Install

```sh
$ cd $(TOPDIR)/Scheduler
$ ./install.sh
``` 

## Uninstall or Re-install

```sh
$ cd $(TOPDIR)/Scheduling
$ ./uninstall.sh
```

If you change config or source files, please put following commond.

``` 
$ cd $(TOPDIR)/Schedluing
$ ./reinstall.sh
``` 
