CC=arm-linux-gnueabihf-g++
CFLAGS=-lm -pthread -g


all: TSL2591

TSL2591: TSLTest.cpp Adafruit_TSL2591.cpp Wire.cpp
	$(CC) TSLTest.cpp Adafruit_TSL2591.cpp Wire.cpp -o TSL2591 $(CFLAGS)
	cp -f $@ /home/glengallagher/cmpt433/public/myApps/$@

