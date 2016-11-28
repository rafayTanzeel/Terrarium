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
	$(MAKE) -C libraries
	$(MAKE) -C modules
	$(MAKE) -C controllers

app: TerrariumServer.o
	
	$(CC_C)$(CXX) $(CXXFLAGS) TerrariumServer.o  $(SRC) -o $(TARGET) $(LINKER)
	cp $(TARGET) $(PUBDIR)/$(TARGET)

TerrariumServer.o: TerrariumServer.cpp
	$(CC_C)$(CXX) $(CXXFLAGS) TerrariumServer.cpp -c TerrariumServer.cpp


clean: 
	rm -f *o $(PUBDIR)/$(TARGET)
	rm -f *o $(TARGET)
	find . -type f -name '*.o' -delete
