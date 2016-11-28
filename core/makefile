CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

PUBDIR = $(HOME)/cmpt433/public/myApps
TARGET = terrarium
LINKER = -lpthread -lm

SRC = Terrarium.cpp TerrariumServer.cpp
OBJS = $(subst .cpp,.o,$(SRC))

all: app
<<<<<<< HEAD:core/makefile
	$(MAKE) -C libraries
	$(MAKE) -C modules
	$(MAKE) -C controllers

app: TerrariumServer.o
	
	$(CC_C)$(CXX) $(CXXFLAGS) TerrariumServer.o  $(SRC) -o $(TARGET) $(LINKER)
=======

app: $(OBJS)
	$(MAKE) -C libraries
	$(MAKE) -C modules
	$(CC_C)$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LINKER)
>>>>>>> d5548c0f92a9264917f923a913484434279cd4fa:core/Makefile
	cp $(TARGET) $(PUBDIR)/$(TARGET)

Terrarium.o: Terrarium.cpp
	$(CC_C)$(CXX) $(CXXFLAGS) -c Terrarium.cpp

<<<<<<< HEAD:core/makefile
=======
TerrariumServer.o: TerrariumServer.cpp
	$(CC_C)$(CXX) $(CXXFLAGS) -c TerrariumServer.cpp
>>>>>>> d5548c0f92a9264917f923a913484434279cd4fa:core/Makefile

clean: 
	rm -f *o $(PUBDIR)/$(TARGET)
	rm -f *o $(TARGET)
	find . -type f -name '*.o' -delete
