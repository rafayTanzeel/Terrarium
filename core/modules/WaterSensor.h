#ifndef WATER_SENSOR_H
#define WATER_SENSOR_H


class WaterSensor

{

public:
	
	WaterSensor(int pinNumber);
	~WaterSensor();
	
	double getWetness();
		
private:

	double _wetness;

};


#endif
