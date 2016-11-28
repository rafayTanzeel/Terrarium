#ifndef FAN_H
#define FAN_H

#include "../tools/PWM.h"

class Fan
{

public:
	
	Fan(int pinNumber, int maxRPM);
	
	bool getState();
	bool setState(bool on);
		
	int getSpeedRPM();
	bool setSpeedRPM(int RPM);
	
	int getSpeedPercent();		
	bool setSpeedPercent(int percent);
	
	int getMaxRPM();
	bool setMaxRPM(int maxRPM);
	
private:

	PWM _pwm;
	int _maxRPM;
	int _speedPercent;
	bool _on;
	
};


#endif
