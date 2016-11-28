#include "TerrariumController.h"


TerrariumController::TerrariumController()
{

}

//Automatic Control (sets both day and night)

int TerrariumController::setColorTemperature(int temp, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setBrightnessLux(int lux, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setHumidity(int humidity)
{
	return 0;
}

int TerrariumController::setTemperature(int temperature) //celsius
{
	return 0;
}

int TerrariumController::setWetnessAlarmThreshold(int threshold)
{
	return 0;
}


//Automatic w/ day/night cycle

int TerrariumController::setDayTime(int hours, int minutes, int seconds)
{
	return 0;
}

int TerrariumController::setNightTime(int hours, int minutes, int seconds)
{
	return 0;
}

int TerrariumController::setDayColorTemperature(int temp, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setNightColorTemperature(int temp, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setDayBrightnessLux(int lux, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setNightBrightnessLux(int lux, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setDayBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setNightBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false)
{
	return 0;
}

int TerrariumController::setDayHumidity(int humidity)
{
	return 0;
}

int TerrariumController::setNightHumidity(int humidity)
{
	return 0;
}

int TerrariumController::setDayTemperature(int temperature) //celsius
{
	return 0;
}

int TerrariumController::setNightTemperature(int temperature) //celsius
{
	return 0;
}


//Manual Control

int TerrariumController::setIntakeFanStatus(bool on)
{
	return 0;
}

int TerrariumController::setExhaustFanStatus(bool on)
{
	return 0;
}

int TerrariumController::setCirculationFanStatus(bool on)
{
	return 0;
}

int TerrariumController::setFoggerStatus(bool on)
{
	return 0;
}

int TerrariumController::setCoolerStatus(bool on)
{
	return 0;
}

int TerrariumController::setAnalogLEDBrightness(int brightness)
{
	return 0;
}

int TerrariumController::setRGBColor(int r, int g, int b)
{
	return 0;
}



// Status

int TerrariumController::getColorTemperature()
{
	return 0;
}

int TerrariumController::getBrightnessLux()
{
	return 0;
}

int TerrariumController::getBrightnessFootCandles()
{
	return 0;
}

float TerrariumController::getHumidity()
{
	return 0;
}

float TerrariumController::getTemperature()
{
	return 0;
}

int TerrariumController::getIntakeFanStatus()
{
	return 0;
}

int TerrariumController::getExhaustFanStatus()
{
	return 0;
}

int TerrariumController::getCirculationFanStatus()
{
	return 0;
}

bool TerrariumController::getFoggerStatus()
{
	return true;
}

bool TerrariumController::getCoolerStatus()
{
	return true;
}

float TerrariumController::getWetness()
{
	return 0.0;
}

int TerrariumController::getAnalogLEDBrightness()
{
	return 0;
}

int TerrariumController::getRGBColor(int& r, int& g, int& b)
{
	return 0;
}
	
private:

};

#endif
