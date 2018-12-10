#!/bin/bash
g++ -o sr_ll `root-config --cflags --glibs` sr_ll.C
./sr_ll
