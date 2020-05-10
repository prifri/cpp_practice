#!/bin/bash

FILE=$1

g++ -o $1 $1.cpp ../lib/comm.cpp
