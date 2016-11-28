CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

all: ClimateController LightController TerrariumController

ClimateController:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c ClimateController.cpp
	
LightController:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c LightController.cpp
	
TerrariumController:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TerrariumController.cpp

clean: 
	rm -f *o
