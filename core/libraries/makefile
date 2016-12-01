LIB = libraries.a

all: Wire.o Adafruit_SHT31.o Adafruit_TCS34725.o Adafruit_TSL2591.o
	ar rcs $(LIB) $^

Wire.o:
	$(MAKE) -C Wire

Adafruit_SHT31.o:
	$(MAKE) -C Adafruit_SHT31_Library

Adafruit_TCS34725.o:
	$(MAKE) -C Adafruit_TCS34725_Library

Adafruit_TSL2591.o:
	$(MAKE) -C Adafruit_TSL2591_Library