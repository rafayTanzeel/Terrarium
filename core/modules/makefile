CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

all: TempHumiditySensor ColorSensor Fan LightSensor PWMLightStrip Relay RGBLightStrip WaterSensor

TempHumiditySensor:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TempHumiditySensor.cpp
	
ColorSensor:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c ColorSensor.cpp
	
Fan:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Fan.cpp
	
LightSensor:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c LightSensor.cpp
	
PWMLightStrip:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c PWMLightStrip.cpp
	
Relay:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Relay.cpp
	
RGBLightStrip:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c RGBLightStrip.cpp
	
WaterSensor:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c WaterSensor.cpp

clean: 
	rm -f *o
