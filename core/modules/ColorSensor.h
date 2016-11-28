#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include "../libraries/Adafruit_TCS34725_Library/Adafruit_TCS34725.h"

class ColorSensor
{

public:
	ColorSensor(const char * filename, uint8_t addr);
	~ColorSensor();
	
	void getRawData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c);
	uint16_t getColorTemperature();
	uint16_t getLux();

private:

	Adafruit_TCS34725 _tcs34725;
};

#endif
