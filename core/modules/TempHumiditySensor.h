#ifndef TEMP_HUMIDITY_SENSOR_H
#define TEMP_HUMIDITY_SENSOR_H

#include "libraries/Adafruit_SHT31_Library/Adafruit_SHT31.h"

class TempHumiditySensor {

public:
	TempHumiditySensor(const char * filename, uint8_t addr);
	float getHumidity();
	float getTemperature();
	
private:
	Adafruit_SHT31 _sht31;
	bool runHeater(int milliseconds);
};


#endif
