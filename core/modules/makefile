CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -Wconversion -g -Werror -std=c++11
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

SRC = TempHumiditySensor.cpp ColorSensor.cpp Fan.cpp LightSensor.cpp PWMLightStrip.cpp Relay.cpp RGBLightStrip.cpp WaterSensor.cpp
OBJS = $(subst .cpp,.o,$(SRC))
LIB = modules.a

all: $(OBJS)
	ar rcs $(LIB) $^

TempHumiditySensor.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TempHumiditySensor.cpp
	
ColorSensor.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c ColorSensor.cpp
	
Fan.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Fan.cpp
	
LightSensor.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c LightSensor.cpp
	
PWMLightStrip.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c PWMLightStrip.cpp
	
Relay.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c Relay.cpp
	
RGBLightStrip.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c RGBLightStrip.cpp
	
WaterSensor.o:
	$(CC_C)$(CXX) $(CXX_FLAGS) -c WaterSensor.cpp

clean: 
	rm -f *o
