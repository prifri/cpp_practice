#!/bin/bash

FILE=$1

rm ./$1
clear
g++  -g -o $1 $1.cpp ../lib/comm.cpp -W -Werror 
./$1
