#!/bin/bash
g++ -o sr_lla `root-config --cflags --glibs` sr_lla.C
./sr_lla
