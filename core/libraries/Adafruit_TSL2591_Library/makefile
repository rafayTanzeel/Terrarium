CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror -std=c++11
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

all: Adafruit_TSL2591

Adafruit_TSL2591:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Adafruit_TSL2591.cpp $(CFLAGS)

TSL2591: TSLTest.cpp Adafruit_TSL2591.cpp ../Wire/Wire.cpp
	$(CC) TSLTest.cpp Adafruit_TSL2591.cpp ../Wire/Wire.cpp -o TSL2591 $(CFLAGS)
	cp -f $@ /home/glengallagher/cmpt433/public/myApps/$@

