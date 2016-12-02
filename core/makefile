CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -Wconversion -g -Werror -std=c++11 -static
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

PUBDIR = $(HOME)/cmpt433/public/myApps
TARGET = terrarium
LINKER = -lpthread -lm

SRC = Terrarium.cpp TerrariumServer.cpp
OBJS = $(subst .cpp,.o,$(SRC))
STATIC_LIBS = controllers/controllers.a libraries/libraries.a modules/modules.a tools/tools.a
JOINED_LIB = lib.a

all: app

app: $(OBJS) server
	$(MAKE) -C tools
	$(MAKE) -C libraries
	$(MAKE) -C modules
	$(MAKE) -C controllers
	ar crsT $(JOINED_LIB) $(STATIC_LIBS)
	$(CC_C)$(CXX) $(CXX_FLAGS) -o $(TARGET) $(OBJS) $(JOINED_LIB) $(LINKER)
	cp $(TARGET) $(PUBDIR)/$(TARGET)

Terrarium.o: Terrarium.cpp TerrariumServer.o
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Terrarium.cpp

TerrariumServer.o: TerrariumServer.cpp
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TerrariumServer.cpp

server:
	mkdir -p $(PUBDIR)/terrarium-server-copy
	cp -R ../WebUI/* $(PUBDIR)/terrarium-server-copy

server_clean:
	rm -rf $(PUBDIR)/terrarium-server-copy

clean: 
	rm -f *o $(PUBDIR)/$(TARGET)
	rm -f *o $(TARGET)
	find . -type f -name '*.o' -delete
	find . -type f -name '*.a' -delete