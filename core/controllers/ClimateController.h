#ifndef CLIMATE_CONTROLLER_H
#define CLIMATE_CONTROLLER_H

#include "../Types.h"
#include <pthread.h>

class Fan;
class Relay;
class TempHumiditySensor;
class WaterSensor;

class ClimateController 
{
//Setters return 0 on success

public:

	ClimateController(Fan*& exhaustFan, Fan*& intakeFan, Fan*& circulationFan, Relay*& fogger, Relay*& cooler, TempHumiditySensor*& tempHumiditySensor, WaterSensor*& waterSensor);
	~ClimateController();
	
	//Automatic Control (sets both day and night)
	int setTemperature(int temperature); //celsius
    int setHumidity(int humidity);
    int setWetnessAlarmThreshold(int threshold);
	
	//Automatic w/ day/night cycle
	int setDayTime(int hours, int minutes, int seconds);
	int setNightTime(int hours, int minutes, int seconds);
	int setDayTemperature(int temperature); //celsius
	int setNightTemperature(int temperature); //celsius
	int setDayHumidity(int humidity);
	int setNightHumidity(int humidity);

	//Manual Control
	int setCoolerStatus(bool on);
	int setIntakeFanStatus(bool on);
	int setExhaustFanStatus(bool on);
	int setCirculationFanStatus(bool on);
	int setFoggerStatus(bool on);
	
	// Status
	double getTemperature();
	bool getCoolerStatus();
	bool getFoggerStatus();
	double getHumidity();
	int getIntakeFanStatus();
	int getExhaustFanStatus();
	int getCirculationFanStatus();
	double getWetness();
	
	bool running();
	void launchThread();
	void stopThread();
	
private:
    
    static void* threadFn(void * object);
    void* doClimateControl();
    
    Fan* _exhaustFan;
    Fan* _intakeFan;
    Fan* _circulationFan;
    Relay* _fogger;
    Relay* _cooler;
    TempHumiditySensor* _tempHumiditySensor;
    WaterSensor* _waterSensor;
    
    Time _dayTime = {8, 0, 0};
    Time _nightTime = {23, 0, 0};
    
    int _dayTemperature;
    int _nightTemperature;
    int _dayHumidity;
    int _nightHumidity;
    int _wetnessThreshold;
    
    pthread_t _id; //ID of processing thread
    bool _runController = false;
    pthread_mutex_t _controllerMutex = PTHREAD_MUTEX_INITIALIZER;
      
};

#endif
