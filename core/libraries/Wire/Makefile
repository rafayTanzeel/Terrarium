CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror -std=c++11
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

all: Wire.o
	cp $^ ..
	rm $^

Wire.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Wire.cpp
