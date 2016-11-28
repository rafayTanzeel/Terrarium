#include "LightController.h"

LightController::LightController()
{
}

//Automatic Control (sets both day and night)
int LightController::setColorTemperature(int temp, bool useAnalogLEDs)
{
    return 0;
}

int LightController::setBrightnessLux(int lux, bool useAnalogLEDs)
{
    return 0;
}

int LightController::setBrightnessFootcandles(int footcandles, bool useAnalogLEDs)
{
    return 0;
}

//Automatic w/ day/night cycle

int LightController::setDayTime(int hours, int minutes, int seconds)
{
    return 0;
}

int LightController::setNightTime(int hours, int minutes, int seconds)
{
    return 0;
}

int LightController::setDayColorTemperature(int temp, bool useAnalogLEDs)
{
    return 0;
}

int LightController::setNightColorTemperature(int temp, bool useAnalogLEDs)
{
    return 0;
}

int LightController::setDayBrightnessLux(int lux, bool useAnalogLEDs)
{
    return 0;
}

int LightController::setNightBrightnessLux(int lux, bool useAnalogLEDs)
{
    return 0;
}

int LightController::setDayBrightnessFootcandles(int footcandles, bool useAnalogLEDs)
{
    return 0;
}

int LightController::setNightBrightnessFootcandles(int footcandles, bool useAnalogLEDs)
{
    return 0;
}

//Manual Control

int LightController::setAnalogLEDBrightness(int brightness)
{
    return 0;
}

int LightController::setRGBColor(int r, int g, int b)
{
    return 0;
}

// Status

int LightController::getColorTemperature()
{
    return 0;
}

int LightController::getBrightnessLux()
{
    return 0;
}

int LightController::getBrightnessFootCandles()
{
    return 0;
}

int LightController::getAnalogLEDBrightness()
{
    return 0;
}

int LightController::getRGBColor(int& r, int& g, int& b)
{
    return 0;
}

