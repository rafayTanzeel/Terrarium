CC=arm-linux-gnueabihf-g++
CFLAGS=-lm -pthread -g


all: TCS34725

TCS34725: TCSTest.cpp Adafruit_TCS34725.cpp ../Wire/Wire.cpp
	$(CC) TCSTest.cpp Adafruit_TCS34725.cpp ../Wire/Wire.cpp -o TCS34725 $(CFLAGS)
	cp -f $@ /home/glengallagher/cmpt433/public/myApps/$@

