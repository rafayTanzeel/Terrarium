#include "TempHumiditySensor.h"
#include <unistd.h>

TempHumiditySensor::TempHumiditySensor(const char * filename, uint8_t addr) 
{
	// Setup Temp&Hum sensor
	_sht31 = Adafruit_SHT31();
	_sht31.setI2CFile(filename, addr);
}

float TempHumiditySensor::getHumidity() 
{
	return _sht31.readHumidity();
}

float TempHumiditySensor::getTemperature() 
{
	return _sht31.readTemperature();
}

bool TempHumiditySensor::runHeater(int milliseconds) 
{
	_sht31.heater(true);
	usleep(milliseconds*1000);
	_sht31.heater(false);
	return 0;
}
