// ClimateController.cpp
#include "ClimateController.h"
#include "../modules/Fan.h"
#include "../modules/Relay.h"
#include "../modules/TempHumiditySensor.h"
#include "../modules/WaterSensor.h"

#include <unistd.h>
#include <time.h>

ClimateController::ClimateController(Fan*& exhaustFan, Fan*& intakeFan, Fan*& circulationFan, Relay*& fogger, Relay*& cooler, TempHumiditySensor*& tempHumiditySensor, WaterSensor*& waterSensor) : _exhaustFan(exhaustFan),
               _intakeFan(intakeFan),
               _circulationFan(circulationFan),
               _fogger(fogger),
               _cooler(cooler),
               _tempHumiditySensor(tempHumiditySensor),
               _waterSensor(waterSensor)                           
{
    exhaustFan = nullptr;
    intakeFan = nullptr;
    circulationFan = nullptr;
    fogger = nullptr;
    cooler = nullptr;
    tempHumiditySensor = nullptr;
    waterSensor = nullptr;
}

ClimateController::~ClimateController()
{
    delete _exhaustFan; _exhaustFan = nullptr;
    delete _intakeFan; _intakeFan = nullptr;
    delete _circulationFan; _circulationFan = nullptr;
    delete _fogger; _fogger = nullptr;
    delete _cooler; _cooler = nullptr;
    delete _tempHumiditySensor; _tempHumiditySensor = nullptr;
    delete _waterSensor; _waterSensor = nullptr;
}

void* ClimateController::threadFn(void * object)
{
    return ((ClimateController*)object)->doClimateControl(); 
}


void* ClimateController::doClimateControl()
{
    bool runControllerLocal = true;
	while(runControllerLocal) {
		pthread_mutex_lock(&_controllerMutex);
		{
			runControllerLocal = _runController;
		}
		pthread_mutex_unlock(&_controllerMutex);
		if (!runControllerLocal) {
		    break;
		}
		
		double humidity = getHumidity();
		double temperature = getTemperature();
		
	    printf("Humidity: %f\n", humidity);
	    printf("Temperature: %f\n", temperature);
	    
	    if (autoClimate) {
	    if (isDayTime()) {      
	        if (humidity < _dayHumidity) {
	            setFoggerStatus(true);
	            printf("Day: Fogger on\n");
	            setIntakeFanStatus(false);
	            setExhaustFanStatus(false);
	        }
	        else {
	            setFoggerStatus(false);
	            printf("Day: Fogger off\n");
	            printf("Day: Exhaust/Intake Fans on\n");
	            setIntakeFanStatus(true);
	            setExhaustFanStatus(true);
	           
	        }
	        //setCoolerStatus(temperature < _dayTemperature);
	    }
	    else {
	    	setFoggerStatus(humidity < _nightHumidity);
	    	if (humidity < _nightHumidity) {
	        printf("Night: Fogger on\n");
	        }
	        else {
	        printf("Night: Fogger off\n");
	        }
	    	//setCoolerStatus(temperature < _nightTemperature);
	    }
	    autoClimate = true;
	    }
	    	    
	    sleep(1);
	}
	
	return NULL;
}

bool ClimateController::running()
{
    bool runControllerLocal;
	pthread_mutex_lock(&_controllerMutex);
	{
		runControllerLocal = _runController;
	}
	pthread_mutex_unlock(&_controllerMutex);
    
    return runControllerLocal;
}

void ClimateController::launchThread()
{	
	pthread_mutex_lock(&_controllerMutex);
	{
		_runController = true;
	}
	pthread_mutex_unlock(&_controllerMutex);
	
	pthread_create(&_id, NULL, &ClimateController::threadFn, (void*)this);
}

void ClimateController::stopThread(void)
{
	pthread_mutex_lock(&_controllerMutex);
	{
	    _runController = false;
	}
	pthread_mutex_unlock(&_controllerMutex);

	pthread_join(_id, NULL);
}

	
//Automatic Control (sets both day and night)

int ClimateController::setTemperature(int temperature) //celsius
{ 
    autoClimate = true;
    setDayTemperature(temperature);
    setNightTemperature(temperature);
    return 0;
} 

int ClimateController::setHumidity(int humidity)
{
    autoClimate = true;
    setDayHumidity(humidity);
    setNightHumidity(humidity);
    return 0;
}

int ClimateController::setWetnessAlarmThreshold(int threshold)
{
    _wetnessThreshold = threshold;
    return 0;
}
	
//Automatic w/ day/night cycle

int ClimateController::setDayTime(int hours, int minutes, int seconds)
{
    autoClimate = true;
    if (hours > 23 || minutes > 59 || seconds > 59 || hours < 0 || minutes < 0 || seconds < 0) {
        return -1;
    }
    
    _dayTime.hours = hours;
    _dayTime.minutes = minutes;
    _dayTime.seconds = seconds;

    return 0;
}

int ClimateController::setNightTime(int hours, int minutes, int seconds)
{
    autoClimate = true;
    if (hours > 23 || minutes > 59 || seconds > 59 || hours < 0 || minutes < 0 || seconds < 0) {
        return -1;
    }
    
    _nightTime.hours = hours;
    _nightTime.minutes = minutes;
    _nightTime.seconds = seconds;    
    
    return 0;
}

int ClimateController::setDayTemperature(int temperature) //celsius
{
    autoClimate = true;
    _dayTemperature = temperature;
    return 0;
}

int ClimateController::setNightTemperature(int temperature) //celsius
{
    autoClimate = true;
    _nightTemperature = temperature;
    return 0;
}

int ClimateController::setDayHumidity(int humidity)
{
    autoClimate = true;
    _dayHumidity = humidity;
    return 0;
}

int ClimateController::setNightHumidity(int humidity)
{
    autoClimate = true;
    _nightHumidity = humidity;
    return 0;
}

//Manual Control

int ClimateController::setCoolerStatus(bool on)
{
    autoClimate = false;
    return _cooler->setState(on);
}

int ClimateController::setIntakeFanStatus(bool on)
{
    autoClimate = false;
    return _intakeFan->setState(on);
}

int ClimateController::setExhaustFanStatus(bool on)
{
    autoClimate = false;
    return _exhaustFan->setState(on);
}

int ClimateController::setCirculationFanStatus(bool on)
{
    autoClimate = false;
    return _circulationFan->setState(on);
}

int ClimateController::setFoggerStatus(bool on)
{
    autoClimate = false;
    return _fogger->setState(on);
}
	
// Status

double ClimateController::getTemperature()
{
    return _tempHumiditySensor->getTemperature();
}

bool ClimateController::getCoolerStatus()
{
    return _cooler->getState();
}

bool ClimateController::getFoggerStatus()
{
    return _fogger->getState();
}

double ClimateController::getHumidity()
{
    return _tempHumiditySensor->getHumidity();
}

int ClimateController::getIntakeFanStatus()
{
    return _intakeFan->getState();
}

int ClimateController::getExhaustFanStatus()
{
    return _exhaustFan->getState();
}

int ClimateController::getCirculationFanStatus()
{
    return _circulationFan->getState();
}

double ClimateController::getWetness()
{
    return _waterSensor->getWetness();
}

bool ClimateController::isDayTime() const
{
    int dayTimeSeconds = _dayTime.hours*60*60 + _dayTime.minutes*60 + _dayTime.seconds;
    int nightTimeSeconds = _nightTime.hours*60*60 + _nightTime.minutes*60 + _nightTime.seconds;
    bool flippedDayTime = false;
    
    if (dayTimeSeconds > nightTimeSeconds) {
        int tempDayTimeSeconds = dayTimeSeconds; 
        dayTimeSeconds = nightTimeSeconds;
        nightTimeSeconds = tempDayTimeSeconds;
        
        flippedDayTime = true;
    }
    
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    int currentTimeSeconds = timeinfo->tm_hour*60*60 + timeinfo->tm_min*60 + timeinfo->tm_sec;
    
    printf("currentTime: %iH, %iM %iS\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    printf("daytime: = %iH, %iM %iS\n", _dayTime.hours, _dayTime.minutes, _dayTime.seconds);
    printf("nighttime: = %iH, %iM %iS\n", _nightTime.hours, _nightTime.minutes, _nightTime.seconds);
    
    if (currentTimeSeconds > nightTimeSeconds) {
        if (currentTimeSeconds < dayTimeSeconds) { //shouldn't happen because we made sure night > day
            return flippedDayTime;
        }
        else { //currentTimeSeconds >= dayTimeSeconds
            return flippedDayTime;
        }       
    }
    else { //currentTimeSeconds <= nightTimeSeconds
        if (currentTimeSeconds < dayTimeSeconds) {
            return flippedDayTime;
        }
        else { //currentTimeSeconds >= dayTimeSeconds
            return !flippedDayTime;
        }
    }  
}


