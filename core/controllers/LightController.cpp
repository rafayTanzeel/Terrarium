// LightController.cpp
#include "LightController.h"
#include "../modules/ColorSensor.h"
#include "../modules/LightSensor.h"
#include "../modules/PWMLightStrip.h"
#include "../modules/RGBLightStrip.h"

LightController::LightController(ColorSensor*& colorSensor, LightSensor*& lightSensor, RGBLightStrip*& rgbLightStrip, PWMLightStrip*& pwmLightStrip) : _colorSensor(colorSensor),
                                                                _lightSensor(lightSensor),
                                                                _rgbLightStrip(rgbLightStrip),
                                                                _pwmLightStrip(pwmLightStrip)
{
    colorSensor = nullptr;
    lightSensor = nullptr;
    rgbLightStrip = nullptr;
    pwmLightStrip = nullptr;
}

LightController::~LightController()
{
    delete _colorSensor; _colorSensor = nullptr;
    delete _lightSensor; _lightSensor = nullptr;
    delete _rgbLightStrip; _rgbLightStrip = nullptr;
    delete _pwmLightStrip; _pwmLightStrip = nullptr;
}

//Automatic Control (sets both day and night)
int LightController::setColorTemperature(int temp, bool useAnalogLEDs)
{
    setDayColorTemperature(temp, useAnalogLEDs);
    setNightColorTemperature(temp, useAnalogLEDs);
    return 0;
}

int LightController::setBrightnessLux(int lux, bool useAnalogLEDs)
{
    setDayBrightnessLux(lux, useAnalogLEDs);
    setNightBrightnessLux(lux, useAnalogLEDs);
    return 0;
}

int LightController::setBrightnessFootcandles(int footcandles, bool useAnalogLEDs)
{
    setDayBrightnessFootcandles(footcandles, useAnalogLEDs);
    setNightBrightnessFootcandles(footcandles, useAnalogLEDs);
    return 0;
}

//Automatic w/ day/night cycle

int LightController::setDayTime(int hours, int minutes, int seconds)
{
    if (hours > 23 || minutes > 59 || seconds > 59 || hours < 0 || minutes < 0 || seconds < 0) {
        return -1;
    }
    
    _dayTime.hours = hours;
    _dayTime.minutes = minutes;
    _dayTime.seconds = seconds;

    return 0;
}

int LightController::setNightTime(int hours, int minutes, int seconds)
{
    if (hours > 23 || minutes > 59 || seconds > 59 || hours < 0 || minutes < 0 || seconds < 0) {
        return -1;
    }
    
    _nightTime.hours = hours;
    _nightTime.minutes = minutes;
    _nightTime.seconds = seconds;    
    
    return 0;
}

int LightController::setDayColorTemperature(int temp, bool useAnalogLEDs)
{
    _dayColorTemperature.light = temp;
    _dayColorTemperature.useAnalogLEDs = useAnalogLEDs;
    return 0;
}

int LightController::setNightColorTemperature(int temp, bool useAnalogLEDs)
{
    _nightColorTemperature.light = temp;
    _nightColorTemperature.useAnalogLEDs = useAnalogLEDs;
    return 0;
}

int LightController::setDayBrightnessLux(int lux, bool useAnalogLEDs)
{
    _dayBrightnessLux.light = lux;
    _dayBrightnessLux.useAnalogLEDs = useAnalogLEDs;
    return 0;
}

int LightController::setNightBrightnessLux(int lux, bool useAnalogLEDs)
{
    _nightBrightnessLux.light = lux;
    _nightBrightnessLux.useAnalogLEDs = useAnalogLEDs;
    return 0;
}

int LightController::setDayBrightnessFootcandles(int footcandles, bool useAnalogLEDs)
{
    _dayBrightnessLux.light = static_cast<int>(footCandlesToLux(static_cast<float>(footcandles)));
    _dayBrightnessLux.useAnalogLEDs = useAnalogLEDs;
    return 0;
}

int LightController::setNightBrightnessFootcandles(int footcandles, bool useAnalogLEDs)
{
    _nightBrightnessLux.light = static_cast<int>(footCandlesToLux(static_cast<float>(footcandles)));
    _nightBrightnessLux.useAnalogLEDs = useAnalogLEDs;
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

int LightController::cycleRGBEffects()
{
    return 0;
}


// Status

double LightController::getColorTemperature()
{
    return 0;
}

double LightController::getBrightnessLux()
{
    return 0;
}

double LightController::getBrightnessFootCandles()
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

double LightController::luxToFootCandles(double lux)
{
    return lux * 0.09290304;
}

double LightController::footCandlesToLux(double footcandles)
{
    return footcandles / 0.09290304;
}



