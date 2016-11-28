#ifndef TEMP_HUMIDITY_SENSOR_H
#define TEMP_HUMIDITY_SENSOR_H

#include "../libraries/Adafruit_SHT31_Library/Adafruit_SHT31.h"

class TempHumiditySensor {

private:
	Adafruit_SHT31 sht31;
	bool runHeater(int milliseconds);

public:
	TempHumiditySensor(const char * filename, uint8_t addr);
	float getHumidity();
	float getTemperature();
};

#endif
