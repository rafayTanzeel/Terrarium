#ifndef HUMIDITY_CONTROLLER_H
#define HUMIDITY_CONTROLLER_H


class HumidityController 
{
//Setters return 0 on success

public:

	HumidityController();

	//Automatic Control (sets both day and night)

	int setHumidity(int humidity);


	//Automatic w/ day/night cycle

	int setDayTime(int hours, int minutes, int seconds);

	int setNightTime(int hours, int minutes, int seconds);

	int setDayHumidity(int humidity);

	int setNightHumidity(int humidity);


	//Manual Control

	int setIntakeFanStatus(bool on);

	int setExhaustFanStatus(bool on);

	int setCirculationFanStatus(bool on);

	int setFoggerStatus(bool on);

	int setCoolerStatus(bool on);

	int setAnalogLEDBrightness(int brightness);

	int setRGBColor(int r, int g, int b);

	// Status
	float getHumidity();
	
private:


};

#endif
