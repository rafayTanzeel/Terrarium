#include "TempHumiditySensor.h"

TempHumiditySensor::TempHumiditySensor(const char * filename, uint8_t addr) {
	// Setup Temp&Hum sensor
	sht31 = Adafruit_SHT31();
	sht31.setI2CFile(filename, addr);
}

float TempHumiditySensor::getHumidity() {
	return sht31.readHumidity();
}

float TempHumiditySensor::getTemperature() {
	return sht31.readTemperature();
}