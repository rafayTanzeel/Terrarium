// LightSensor.cpp
#include "LightSensor.h"

LightSensor::LightSensor(const char * filename, uint8_t addr) 
{
	_tsl2591 = Adafruit_TSL2591(SENSOR_ID);
	_tsl2591.setI2CFile(filename, addr);
	_tsl2591.begin();
}

uint32_t LightSensor::getLux() 
{
	uint16_t luminosity_full = _tsl2591.getLuminosity(TSL2591_FULLSPECTRUM);
	uint16_t luminosity_infared = _tsl2591.getLuminosity(TSL2591_INFRARED);
	return _tsl2591.calculateLux(luminosity_full, luminosity_infared);
}

uint32_t LightSensor::getFootCandles()
{
	uint16_t luminosity_full = _tsl2591.getLuminosity(TSL2591_FULLSPECTRUM);
	uint16_t luminosity_infared = _tsl2591.getLuminosity(TSL2591_INFRARED);
	uint32_t lux = _tsl2591.calculateLux(luminosity_full, luminosity_infared);
	
	return lux * 0.09290304;
}
