#ifndef PWM_LIGHTSTRIP_H
#define PWM_LIGHTSTRIP_H


class PWMLightStrip
{

public:
	
	PWMLightStrip(int pinNumber);
			
	int getBrightness();
	bool setBrightness(int value);
		
private:

	bool getState();
	bool setState(bool on);
	int _brightness;
	bool _on;
};


#endif
