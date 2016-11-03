#ifndef WATER_SENSOR_H
#define WATER_SENSOR_H


class WaterSensor

{

public:
	
	WaterSensor(int pinNumber);
	
	int getWetness();
		
private:

	int _wetness;

};


#endif
