#!/bin/bash

FILE=$1

clear
g++ -o $1 $1.cpp ../lib/comm.cpp
./$1
