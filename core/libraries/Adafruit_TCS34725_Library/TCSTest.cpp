
#include <stdio.h>

#include "Adafruit_TCS34725.h"


int main()
{
	Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_60X);
	
	tcs.setI2CFile("/dev/i2c-2", 0x29);
	tcs.begin();
	
	uint16_t r = 0;
	uint16_t g = 0;
	uint16_t b = 0;
	uint16_t c = 0;
	
	tcs.getRawData(&r, &g, &b, &c);
	
	printf("Color temperature: %iK\n", tcs.calculateColorTemperature(r, g, b));
	
	printf("r %i\n", r);
	printf("g %i\n", g);
	printf("b %i\n", b);
	printf("c %i\n", c);

}
