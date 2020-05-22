#!/bin/bash
# sudo apt install libx11-dev libxrandr-dev
# example : ../build.sh -v 11 NsTest.cpp Utils.cpp
# example : ../build.sh NsTest.cpp Utils.cpp
# example : ../build.sh NsTest Utils.cpp

help() {
	echo "splt [OPTIONS] FILE"
	echo "    -v [num]   std version"
	echo "    -r         rtti off"
	echo "    -c         clear"
	exit 0
}

while getopts "v:rhc" opt
do
	case $opt in
		v) STD="-std=c++"$OPTARG
			;;
		r) RTTI="-fno-rtti"
			;;
		c) CLEAR="ON"
			;;
		h) help ;;
		?) help ;;
	esac
done

shift $(( $OPTIND - 1))

FILE=$1
NAME=${FILE%%.*}
EXTEN=${FILE##*.}

shift 
while (( "$#" )); do 
	ADD_FILES=$ADD_FILES" "$1
	shift 
done

if [ "$EXTEN" == "cpp" ]; then
	TMP=0
elif [ "$EXTEN" == "c" ]; then
	TMP=0
elif [ "$EXTEN" == "sh" ]; then
	echo $1 is c file. input only main name.
	exit
elif [ "$EXTEN" == "h" ]; then
	echo $1 is c file. input only main name.
	exit
else
	EXTEN="cpp"
fi

rm ./$NAME > /dev/null 2>&1

WOPT="-W -Wall -Werror"
WNOPT="-Wno-ignored-qualifiers"

g++  -g -o $NAME $NAME.$EXTEN $ADD_FILES ../lib/comm.cpp \
	$WOPT $WNOPT $RTTI \
	$STD \
	-lX11 -lXrandr -lXcursor

if [ "$CLEAR" == "ON" ]; then
	clear
fi

./$NAME
