CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

all: HumidityController LightController TemperatureController TerrariumController

HumidityController:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c HumidityController.cpp
	
LightController:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c LightController.cpp

TemperatureController:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TemperatureController.cpp
	
TerrariumController:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TerrariumController.cpp

clean: 
	rm -f *o
