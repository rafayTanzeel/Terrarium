CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

PUBDIR = $(HOME)/cmpt433/public/myApps
SRC = Terrarium.cpp
TARGET = terrarium
LINKER = -lpthread -lm

all: app

app: TerrariumServer.o
	$(MAKE) -C libraries
	$(MAKE) -C modules
	$(CC_C)$(CXX) $(CXXFLAGS) TerrariumServer.o modules/TempHumiditySensor.o libraries/Adafruit_SHT31_Library/Adafruit_SHT31.o libraries/Wire/Wire.o $(SRC) -o $(TARGET) $(LINKER)
	cp $(TARGET) $(PUBDIR)/$(TARGET)

TerrariumServer.o: TerrariumServer.cpp
	$(CC_C)$(CXX) $(CXXFLAGS) -c TerrariumServer.cpp

clean: 
	rm -f *o $(PUBDIR)/$(TARGET)
	rm -f *o $(TARGET)
	find . -type f -name '*.o' -delete
