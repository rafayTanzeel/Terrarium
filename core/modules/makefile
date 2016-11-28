CC_FLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror
CXX_FLAGS = -Wall -g -Werror
CC_C = arm-linux-gnueabihf-
CC = gcc
CXX = g++

SRC = TempHumiditySensor.cpp ColorSensor.cpp LightSensor.cpp
OBJS = $(subst .cpp,.o,$(SRC))

all: $(OBJS)

TempHumiditySensor.o: TempHumiditySensor.cpp
	$(CC_C)$(CXX) $(CXX_FLAGS) -c TempHumiditySensor.cpp

ColorSensor.o: ColorSensor.cpp
	$(CC_C)$(CXX) $(CXX_FLAGS) -c ColorSensor.cpp

LightSensor.o: LightSensor.cpp
	$(CC_C)$(CXX) $(CXX_FLAGS) -c LightSensor.cpp

clean: 
	rm -f *o
