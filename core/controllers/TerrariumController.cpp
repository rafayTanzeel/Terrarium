// TerrariumController.cpp
#include "TerrariumController.h"
#include "LightController.h"
#include "ClimateController.h"

TerrariumController::TerrariumController(ClimateController*& climateController, LightController*& lightController)
{
}

TerrariumController::~TerrariumController()
{
}

//Automatic Control (sets both day and night)
int TerrariumController::setColorTemperature(int temp, bool useAnalogLEDs) 
{
	return _lightController->setColorTemperature(temp, useAnalogLEDs);
}

int TerrariumController::setBrightnessLux(int lux, bool useAnalogLEDs) 
{
	return _lightController->setBrightnessLux(lux, useAnalogLEDs);
}

int TerrariumController::setBrightnessFootcandles(int footcandles, bool useAnalogLEDs) 
{
	return _lightController->setBrightnessFootcandles(footcandles, useAnalogLEDs);
}

int TerrariumController::setHumidity(int humidity) 
{
	return _climateController->setHumidity(humidity);
}

int TerrariumController::setTemperature(int temperature) //celsius
{ 
	return _climateController->setTemperature(temperature);
}

int TerrariumController::setWetnessAlarmThreshold(int threshold) 
{
	return _climateController->setWetnessAlarmThreshold(threshold);
}


//Automatic w/ day/night cycle
int TerrariumController::setDayTime(int hours, int minutes, int seconds) 
{
	return (_lightController->setNightTime(hours, minutes, seconds) ||   // if this short-circuits we already did something wrong
            _climateController->setNightTime(hours, minutes, seconds));
}

int TerrariumController::setNightTime(int hours, int minutes, int seconds) 
{
    return (_lightController->setNightTime(hours, minutes, seconds) ||  // if this short-circuits we already did something wrong
            _climateController->setNightTime(hours, minutes, seconds));
	 
}

int TerrariumController::setDayColorTemperature(int temp, bool useAnalogLEDs) 
{
	return _lightController->setDayColorTemperature(temp, useAnalogLEDs);
}

int TerrariumController::setNightColorTemperature(int temp, bool useAnalogLEDs) 
{
	return _lightController->setNightColorTemperature(temp, useAnalogLEDs);
}

int TerrariumController::setDayBrightnessLux(int lux, bool useAnalogLEDs) 
{
	return _lightController->setDayBrightnessLux(lux, useAnalogLEDs);
}

int TerrariumController::setNightBrightnessLux(int lux, bool useAnalogLEDs) 
{
	return _lightController->setNightBrightnessLux(lux, useAnalogLEDs);
}

int TerrariumController::setDayBrightnessFootcandles(int footcandles, bool useAnalogLEDs) 
{
	return _lightController->setDayBrightnessFootcandles(footcandles, useAnalogLEDs);
}

int TerrariumController::setNightBrightnessFootcandles(int footcandles, bool useAnalogLEDs) 
{
	return _lightController->setNightBrightnessFootcandles(footcandles, useAnalogLEDs);
}

int TerrariumController::setDayHumidity(int humidity) 
{
	return _climateController->setDayHumidity(humidity);
}

int TerrariumController::setNightHumidity(int humidity) 
{
	return _climateController->setNightHumidity(humidity);
}

int TerrariumController::setDayTemperature(int temperature) //celsius
{ 
	return _climateController->setDayTemperature(temperature);
}

int TerrariumController::setNightTemperature(int temperature) //celsius
{ 
	return _climateController->setNightTemperature(temperature);
}


//Manual Control
int TerrariumController::setIntakeFanStatus(bool on) {

	return _climateController->setIntakeFanStatus(on);
}

int TerrariumController::setExhaustFanStatus(bool on) 
{
	return _climateController->setExhaustFanStatus(on);
}

int TerrariumController::setCirculationFanStatus(bool on) 
{
	return _climateController->setCirculationFanStatus(on);
}

int TerrariumController::setFoggerStatus(bool on) 
{
	return _climateController->setFoggerStatus(on);
}

int TerrariumController::setCoolerStatus(bool on) 
{
	return _climateController->setCoolerStatus(on);
}

int TerrariumController::setAnalogLEDBrightness(int brightness) 
{
	return _lightController->setAnalogLEDBrightness(brightness);
}

int TerrariumController::setRGBColor(int r, int g, int b) 
{
	return _lightController->setRGBColor(r, g, b);
}

int TerrariumController::cycleRGBEffects()
{
    return _lightController->cycleRGBEffects();
}


// Status
int TerrariumController::getColorTemperature() 
{
	return _lightController->getColorTemperature();
}

int TerrariumController::getBrightnessLux() 
{
	return _lightController->getBrightnessLux();
}

int TerrariumController::getBrightnessFootCandles() 
{
	return _lightController->getBrightnessFootCandles();
}

float TerrariumController::getHumidity() 
{
	return _climateController->getHumidity();
}

float TerrariumController::getTemperature() 
{
	return _climateController->getTemperature();
}

int TerrariumController::getIntakeFanStatus() 
{
	return _climateController->getIntakeFanStatus();
}

int TerrariumController::getExhaustFanStatus() 
{
	return _climateController->getExhaustFanStatus();
}

int TerrariumController::getCirculationFanStatus() 
{
	return _climateController->getCirculationFanStatus();
}

bool TerrariumController::getFoggerStatus() 
{
	return _climateController->getFoggerStatus();
}

bool TerrariumController::getCoolerStatus() 
{
	return _climateController->getCoolerStatus();
}

float TerrariumController::getWetness() 
{
	return _climateController->getWetness();
}

int TerrariumController::getAnalogLEDBrightness() 
{
	return _lightController->getAnalogLEDBrightness();
}

int TerrariumController::getRGBColor(int& r, int& g, int& b)
{
	return _lightController->getRGBColor(r, g, b);
}
