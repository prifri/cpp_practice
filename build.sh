#!/bin/bash
# ../build.sh {bin} {std version}
FILE=$1
EXTEN=${FILE##*.}

if [ "$EXTEN" == "cpp" ]; then
	echo $1 is cpp file. input only main name.
	exit
elif [ "$EXTEN" == "c" ]; then
	echo $1 is c file. input only main name.
	exit
elif [ "$EXTEN" == "sh" ]; then
	echo $1 is c file. input only main name.
	exit
elif [ "$EXTEN" == "h" ]; then
	echo $1 is c file. input only main name.
	exit
fi

rm ./$1
#clear

if [ $# -eq 2 ];then
	g++  -g -o $1 $1.cpp ../lib/comm.cpp -W -Werror  -std=c++$2 \
		-lX11 -lXrandr
else
	g++  -g -o $1 $1.cpp ../lib/comm.cpp -W -Werror \
		-lX11 -lXrandr
fi
./$1
