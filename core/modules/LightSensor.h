#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H


class LightSensor

{

public:
	
  LightSensor(const char * filename, uint8_t addr);
  
  uint16_t getLux();
  
  uint16_t getFootCandles();
	
private:

	Adafruit_TSL2591 _tsl2591;
  	
};


#endif
