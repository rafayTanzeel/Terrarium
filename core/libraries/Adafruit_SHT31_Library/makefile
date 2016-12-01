CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror -std=c++11
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

all: Adafruit_SHT31.o
	cp $^ ..
	rm $^

Adafruit_SHT31.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Adafruit_SHT31.cpp $(CFLAGS)

SHT31: SHTTest.cpp Adafruit_SHT31.cpp ../Wire/Wire.cpp
	$(CC) SHTTest.cpp Adafruit_SHT31.cpp ../Wire/Wire.cpp -o SHT31 $(CFLAGS)
	cp -f $@ /home/glengallagher/cmpt433/public/myApps/$@

