#ifndef TERRARIUM_CONTROLLER_H
#define TERRARIUM_CONTROLLER_H


class LightController;
class ClimateController;

class TerrariumController 
{
//Setters return 0 on success

public:
	TerrariumController(ClimateController*& climateController, LightController*& lightController);
	~TerrariumController();
	
	void run();
	
	//Automatic Control (sets both day and night)
	int setColorTemperature(int temp, bool useAnalogLEDs = false);
	int setBrightnessLux(int lux, bool useAnalogLEDs = false);
	int setBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false);
	int setHumidity(int humidity);
	int setTemperature(int temperature); //celsius
	int setWetnessAlarmThreshold(int threshold);

	//Automatic w/ day/night cycle
	int setDayTime(int hours, int minutes, int seconds);
	int setNightTime(int hours, int minutes, int seconds);
	int setDayColorTemperature(int temp, bool useAnalogLEDs = false);
	int setNightColorTemperature(int temp, bool useAnalogLEDs = false);
	int setDayBrightnessLux(int lux, bool useAnalogLEDs = false);
	int setNightBrightnessLux(int lux, bool useAnalogLEDs = false);
	int setDayBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false);
	int setNightBrightnessFootcandles(int footcandles, bool useAnalogLEDs = false);
	int setDayHumidity(int humidity);
	int setNightHumidity(int humidity);
	int setDayTemperature(int temperature); //celsius
	int setNightTemperature(int temperature); //celsius

	//Manual Control
	int setIntakeFanStatus(bool on);
	int setExhaustFanStatus(bool on);
	int setCirculationFanStatus(bool on);
	int setFoggerStatus(bool on);
	int setCoolerStatus(bool on);
	int setAnalogLEDBrightness(int brightness);
	int setRGBColor(int r, int g, int b);
	int cycleRGBEffects();

	// Status
	int getColorTemperature();
	int getBrightnessLux();
	int getBrightnessFootCandles();
	double getHumidity();
	double getTemperature();
	int getIntakeFanStatus();
	int getExhaustFanStatus();
	int getCirculationFanStatus();
	bool getFoggerStatus();
	bool getCoolerStatus();
	double getWetness();
	int getAnalogLEDBrightness();
	int getRGBColor(int& r, int& g, int& b);
	
private:
	 ClimateController* _climateController;
	 LightController* _lightController;
	 	
};

#endif
