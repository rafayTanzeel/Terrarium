CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -Wconversion -g -Werror -std=c++11
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

LIB = tools.a

all: Analog.o GPIO.o PWM.o
	ar rcs $(LIB) $^

Analog.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Analog.cpp
	
GPIO.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c GPIO.cpp
	
PWM.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c PWM.cpp

clean: 
	rm -f *o
