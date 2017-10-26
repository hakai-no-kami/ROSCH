#!/bin/sh

cp ../YAMLs/measure_rosch.yaml /tmp/
cd ./RESCH
make
sudo make install
cd ../
cd ./RT-ROS/
make install
#roscore
