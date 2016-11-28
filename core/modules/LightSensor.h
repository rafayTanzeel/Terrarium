#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "../libraries/Adafruit_TSL2591_Library/Adafruit_TSL2591.h"

#define SENSOR_ID 2591

class LightSensor
{
public:
	LightSensor(const char * filename, uint8_t addr);
	uint32_t getLux();
	uint32_t getFootCandles();
	
private:
	Adafruit_TSL2591 _tsl2591;
  	
};

#endif
