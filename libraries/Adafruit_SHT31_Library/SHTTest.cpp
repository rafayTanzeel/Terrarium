
#include <stdio.h>

#include "Adafruit_SHT31.h"


int main()
{
	Adafruit_SHT31 sht = Adafruit_SHT31();
	
	sht.setI2CFile("/dev/i2c-2", SHT31_DEFAULT_ADDR);
	//sht.begin();
	
	
	printf("temp: %f\n", sht.readTemperature());
	printf("humidity: %f\n", sht.readHumidity());
}
