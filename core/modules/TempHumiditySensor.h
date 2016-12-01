#ifndef TEMP_HUMIDITY_SENSOR_H
#define TEMP_HUMIDITY_SENSOR_H

#include "../libraries/Adafruit_SHT31_Library/Adafruit_SHT31.h"
#include <time.h>

class TempHumiditySensor 
{

public:
	TempHumiditySensor(const char * filename, uint8_t addr);
	~TempHumiditySensor();
	
	double getHumidity();
	double getTemperature();
	bool runHeater(int milliseconds);	

private:
	
	Adafruit_SHT31 _sht31;
	time_t _heaterLastRun;
	
};

#endif
