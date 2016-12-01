#ifndef LIGHT_CONTROLLER_H
#define LIGHT_CONTROLLER_H

#include "../Types.h"

class ColorSensor;
class LightSensor;
class RGBLightStrip;
class PWMLightStrip;

class LightController 
{
//Setters return 0 on success

public:

	LightController(ColorSensor*& colorSensor, LightSensor*& lightSensor, RGBLightStrip*& rgbLightStrip, PWMLightStrip*& pwmLightStrip);
	~LightController();

	//Automatic Control (sets both day and night)
	int setColorTemperature(int temp, bool useAnalogLEDs = false);
	int setBrightnessLux(int lux, bool useAnalogLEDs = false);
	int setBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false);

	//Automatic w/ day/night cycle
	int setDayTime(int hours, int minutes, int seconds);
	int setNightTime(int hours, int minutes, int seconds);
	int setDayColorTemperature(int temp, bool useAnalogLEDs = false);
	int setNightColorTemperature(int temp, bool useAnalogLEDs = false);
	int setDayBrightnessLux(int lux, bool useAnalogLEDs = false);
	int setNightBrightnessLux(int lux, bool useAnalogLEDs = false);
	int setDayBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false);
	int setNightBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false);

	//Manual Control
	int setAnalogLEDBrightness(int brightness);
	int setRGBColor(int r, int g, int b);
	int cycleRGBEffects();

	// Status
	int getColorTemperature();
	int getBrightnessLux();
	int getBrightnessFootCandles();
	int getAnalogLEDBrightness();
	int getRGBColor(int& r, int& g, int& b);
	
	static int luxToFootCandles(int lux);
    static int footCandlesToLux(int footcandles);
	
private:

    ColorSensor* _colorSensor;
    LightSensor* _lightSensor;
    RGBLightStrip* _rgbLightStrip;
    PWMLightStrip* _pwmLightStrip;
    
    Time _dayTime;
    Time _nightTime;
    
    LightParms _dayColorTemperature;
    LightParms _nightColorTemperature;
    LightParms _dayBrightnessLux;
    LightParms _nightBrightnessLux;
    
};

#endif
