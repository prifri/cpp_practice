#!/bin/bash
# sudo apt install libx11-dev libxrandr-dev

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


WOPT="-W -Wall -Werror"
WNOPT="-Wno-ignored-qualifiers"

g++  -g -o $NAME $NAME.$EXTEN ../lib/comm.cpp \
	$WOPT $WNOPT $RTTI \
	$STD \
	-lX11 -lXrandr

if [ "$CLEAR" == "ON" ]; then
	clear
fi

./$NAME
