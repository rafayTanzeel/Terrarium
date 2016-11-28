// ColorSensor.cpp
#include "ColorSensor.h"

ColorSensor::ColorSensor(const char * filename, uint8_t addr) 
{
	_tcs34725 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_60X);
	_tcs34725.setI2CFile(filename, addr);
	_tcs34725.begin();
}

void ColorSensor::getRawData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c) 
{
	_tcs34725.getRawData(r, g, b, c);
}

uint16_t ColorSensor::getColorTemperature() 
{
	uint16_t r, g, b, c;
	getRawData(&r, &g, &b, &c);
	return _tcs34725.calculateColorTemperature(r, g, b);
}

uint16_t ColorSensor::getLux() 
{
	uint16_t r, g, b, c;
	getRawData(&r, &g, &b, &c);
	return _tcs34725.calculateLux(r, g, b);
}
