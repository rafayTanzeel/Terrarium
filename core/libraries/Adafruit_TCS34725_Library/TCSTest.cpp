
#include <stdio.h>

#include "Adafruit_TCS34725.h"


int main()
{
	Adafruit_TCS34725 tcs = Adafruit_TCS34725();
	
	tcs.setI2CFile("/dev/i2c-2", 0x29);
	tcs.begin();
	
	uint16_t r,g,b,c;
	
	tcs.getRawData(&r, &g, &b, &c);
	
	printf("r %i\n", r);
	printf("g %i\n", g);
	printf("b %i\n", b);
	printf("c %i\n", c);

}
