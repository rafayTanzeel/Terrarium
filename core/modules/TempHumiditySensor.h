#ifndef TEMP_HUMIDITY_SENSOR_H
#define TEMP_HUMIDITY_SENSOR_H


class TempHumiditySensor

{

public:
	
	TempHumiditySensor(const char * filename, uint8_t addr);
	
	float getHumidity();
		
	float getTemperature();
	
	
private:

	bool runHeater(int milliseconds);

	Adafruit_SHT31 _sht31;
};


#endif
