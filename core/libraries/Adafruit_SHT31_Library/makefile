CC=arm-linux-gnueabihf-g++
CFLAGS=-lm -pthread -g


all: SHT31

SHT31: SHTTest.cpp Adafruit_SHT31.cpp ../Wire/Wire.cpp
	$(CC) SHTTest.cpp Adafruit_SHT31.cpp ../Wire/Wire.cpp -o SHT31 $(CFLAGS)
	cp -f $@ /home/glengallagher/cmpt433/public/myApps/$@

