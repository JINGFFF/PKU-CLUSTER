#!/bin/bash
g++ -o sr_drla `root-config --cflags --glibs` sr_drla.C
./sr_drla
