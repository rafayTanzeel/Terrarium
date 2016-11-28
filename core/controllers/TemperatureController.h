#ifndef TEMPERATURE_CONTROLLER_H
#define TEMPERATURE_CONTROLLER_H


class TemperatureController 
{
//Setters return 0 on success

public:

	TemperatureController();

	//Automatic Control (sets both day and night)

	int setTemperature(int temperature); //celsius


	//Automatic w/ day/night cycle

	int setDayTime(int hours, int minutes, int seconds);

	int setNightTime(int hours, int minutes, int seconds);

	int setDayTemperature(int temperature); //celsius

	int setNightTemperature(int temperature); //celsius


	//Manual Control

	int setCoolerStatus(bool on);
	

	// Status

	float getTemperature();

	bool getCoolerStatus();

	
private:

};

#endif
