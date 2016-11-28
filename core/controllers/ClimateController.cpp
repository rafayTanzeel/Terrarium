#include "ClimateController.h"

ClimateController::ClimateController()
{
}
	
//Automatic Control (sets both day and night)

int ClimateController::setTemperature(int temperature) //celsius
{ 
    return 0;
} 

int ClimateController::setHumidity(int humidity)
{
    return 0;
}

int ClimateController::setWetnessAlarmThreshold(int threshold)
{
    return 0;
}
	
//Automatic w/ day/night cycle

int ClimateController::setDayTime(int hours, int minutes, int seconds)
{
    return 0;
}

int ClimateController::setNightTime(int hours, int minutes, int seconds)
{
    return 0;
}

int ClimateController::setDayTemperature(int temperature) //celsius
{
    return 0;
}

int ClimateController::setNightTemperature(int temperature) //celsius
{
    return 0;
}

int ClimateController::setDayHumidity(int humidity)
{
    return 0;
}

int ClimateController::setNightHumidity(int humidity)
{
    return 0;
}

//Manual Control

int ClimateController::setCoolerStatus(bool on)
{
    return 0;
}

int ClimateController::setIntakeFanStatus(bool on)
{
    return 0;
}

int ClimateController::setExhaustFanStatus(bool on)
{
    return 0;
}

int ClimateController::setCirculationFanStatus(bool on)
{
    return 0;
}

int ClimateController::setFoggerStatus(bool on)
{
    return 0;
}
	
// Status

float ClimateController::getTemperature()
{
    return 0.0;
}

bool ClimateController::getCoolerStatus()
{
    return false;
}

bool ClimateController::getFoggerStatus()
{
    return false;
}

float ClimateController::getHumidity()
{
    return 0.0;
}

int ClimateController::getIntakeFanStatus()
{
    return 0;
}

int ClimateController::getExhaustFanStatus()
{
    return 0;
}

int ClimateController::getCirculationFanStatus()
{
    return 0;
}

float ClimateController::getWetness()
{
    return 0.0;
}

