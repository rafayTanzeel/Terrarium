// LightSensor.cpp
#include "LightSensor.h"

static const double LUX_FOOTCANDLE_FACTOR = 0.09290304;

LightSensor::LightSensor(const char * filename, uint8_t addr) 
{
	_tsl2591 = Adafruit_TSL2591(SENSOR_ID);
	_tsl2591.setI2CFile(filename, addr);
	_tsl2591.begin();
}

LightSensor::~LightSensor()
{
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
	
	return static_cast<uint32_t>(lux * LUX_FOOTCANDLE_FACTOR);
}
