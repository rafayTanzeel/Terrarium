CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror -std=c++11
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

PUBDIR = $(HOME)/cmpt433/public/myApps
TARGET = terrarium
LINKER = -lpthread -lm

SRC = Terrarium.cpp TerrariumServer.cpp
OBJS = $(subst .cpp,.o,$(SRC))

all: app

app: $(OBJS)
	$(MAKE) -C libraries
	$(MAKE) -C modules
	$(MAKE) -C controllers
	$(CC_C)$(CXX) $(CXX_FLAGS) -o $(TARGET) $(OBJS) $(LINKER)
	cp $(TARGET) $(PUBDIR)/$(TARGET)

Terrarium.o: Terrarium.cpp TerrariumServer.o
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Terrarium.cpp

TerrariumServer.o: TerrariumServer.cpp
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TerrariumServer.cpp

clean: 
	rm -f *o $(PUBDIR)/$(TARGET)
	rm -f *o $(TARGET)
	find . -type f -name '*.o' -delete

