// ClimateController.cpp
#include "ClimateController.h"
#include "../modules/Fan.h"
#include "../modules/Relay.h"
#include "../modules/TempHumiditySensor.h"
#include "../modules/WaterSensor.h"

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
	
//Automatic Control (sets both day and night)

int ClimateController::setTemperature(int temperature) //celsius
{ 
    _dayTemperature = temperature;
    _nightTemperature = temperature;
    return 0;
} 

int ClimateController::setHumidity(int humidity)
{
    _dayHumidity = humidity;
    _nightHumidity = humidity;
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
    _dayTemperature = temperature;
    return 0;
}

int ClimateController::setNightTemperature(int temperature) //celsius
{
    _nightTemperature = temperature;
    return 0;
}

int ClimateController::setDayHumidity(int humidity)
{
    _dayHumidity = humidity;
    return 0;
}

int ClimateController::setNightHumidity(int humidity)
{
    _nightHumidity = humidity;
    return 0;
}

//Manual Control

int ClimateController::setCoolerStatus(bool on)
{
    return _cooler->setState(on);
}

int ClimateController::setIntakeFanStatus(bool on)
{
    return _intakeFan->setState(on);
}

int ClimateController::setExhaustFanStatus(bool on)
{
    return _exhaustFan->setState(on);
}

int ClimateController::setCirculationFanStatus(bool on)
{
    return _circulationFan->setState(on);
}

int ClimateController::setFoggerStatus(bool on)
{
    return _fogger->setState(on);
}
	
// Status

float ClimateController::getTemperature()
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

float ClimateController::getHumidity()
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

float ClimateController::getWetness()
{
    return _waterSensor->getWetness();
}

