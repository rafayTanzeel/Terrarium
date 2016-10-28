
#include <stdio.h>

#include "Adafruit_TSL2591.h"


int main()
{
	Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);
	
	tsl.setI2CFile("/dev/i2c-2", 0x29);
	tsl.begin();
	
	uint16_t luminosity = tsl.getLuminosity(0);
	uint16_t luminosity1 = tsl.getLuminosity(1);
	
	uint32_t lux = tsl.calculateLux(luminosity, luminosity1);
	
	printf("luminosity0 %i\n", luminosity);
	printf("luminosity1 %i\n", luminosity1);
	printf("lux %i\n", lux);

}
