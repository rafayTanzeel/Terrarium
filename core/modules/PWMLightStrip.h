#ifndef PWM_LIGHTSTRIP_H
#define PWM_LIGHTSTRIP_H

#include "../tools/PWM.h"

class PWMLightStrip
{

public:
	
	PWMLightStrip(int pinNumber);
	~PWMLightStrip();
			
	int getBrightness();
	bool setBrightness(int value);
		
private:

    PWM _pwm;
	bool getState();
	bool setState(bool on);
	int _brightness;
	bool _on;
};


#endif
