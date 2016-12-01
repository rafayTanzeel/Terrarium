CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -Wconversion -g -Werror -std=c++11
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

LIB = controllers.a

all: ClimateController.o LightController.o TerrariumController.o
	ar rcs $(LIB) $^

ClimateController.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c ClimateController.cpp
	
LightController.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c LightController.cpp
	
TerrariumController.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TerrariumController.cpp

clean: 
	rm -f *o
