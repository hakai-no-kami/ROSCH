#!/bin/sh

cp ./sched_rosch.yaml /tmp/
cd ./RESCH
sudo make uninstall
make
sudo make install
cd ../
cd ./RT-ROS/
make install
roscore
