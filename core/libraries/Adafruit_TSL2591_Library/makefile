CC=arm-linux-gnueabihf-g++
CFLAGS=-lm -pthread -g


all: Adafruit_TSL2591

Adafruit_TSL2591:
	$(CC) -c Adafruit_TSL2591.cpp $(CFLAGS)

TSL2591: TSLTest.cpp Adafruit_TSL2591.cpp ../Wire/Wire.cpp
	$(CC) TSLTest.cpp Adafruit_TSL2591.cpp ../Wire/Wire.cpp -o TSL2591 $(CFLAGS)
	cp -f $@ /home/glengallagher/cmpt433/public/myApps/$@

