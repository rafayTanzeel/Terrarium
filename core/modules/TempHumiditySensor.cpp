#include "TempHumiditySensor.h"

void TempHumiditySensor(const char * filename, uint8_t addr) {
	_sht31 = Adafruit_SHT31();
	
	_sht31.setI2CFile(filename, addr);
}

float getHumidity() {
	return _sht31.getHumidity();
}

float getTemperature() {
	return _sht31.getTemperature();
}