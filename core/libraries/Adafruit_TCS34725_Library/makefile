CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror -std=c++11
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++


all: Adafruit_TCS34725.o
	cp $^ ..
	rm $^

Adafruit_TCS34725.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Adafruit_TCS34725.cpp $(CFLAGS)

TCS34725: TCSTest.cpp Adafruit_TCS34725.cpp ../Wire/Wire.cpp
	$(CC) TCSTest.cpp Adafruit_TCS34725.cpp ../Wire/Wire.cpp -o TCS34725 $(CFLAGS)
	cp -f $@ /home/glengallagher/cmpt433/public/myApps/$@

