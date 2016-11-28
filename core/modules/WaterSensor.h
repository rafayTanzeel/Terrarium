#ifndef WATER_SENSOR_H
#define WATER_SENSOR_H


class WaterSensor

{

public:
	
	WaterSensor(int pinNumber);
	~WaterSensor();
	
	int getWetness();
		
private:

	int _wetness;

};


#endif
