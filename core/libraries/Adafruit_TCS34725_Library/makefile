CC=arm-linux-gnueabihf-g++
CFLAGS=-lm -pthread -g


all: Adafruit_TCS34725

Adafruit_TCS34725:
	$(CC) -c Adafruit_TCS34725.cpp $(CFLAGS)

TCS34725: TCSTest.cpp Adafruit_TCS34725.cpp ../Wire/Wire.cpp
	$(CC) TCSTest.cpp Adafruit_TCS34725.cpp ../Wire/Wire.cpp -o TCS34725 $(CFLAGS)
	cp -f $@ /home/glengallagher/cmpt433/public/myApps/$@

