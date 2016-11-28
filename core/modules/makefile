CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

all: TempHumiditySensor

TempHumiditySensor:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TempHumiditySensor.cpp

clean: 
	rm -f *o
