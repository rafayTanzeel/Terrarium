#ifndef PWM_LIGHTSTRIP_H
#define PWM_LIGHTSTRIP_H


class PWMLightStrip

{

public:
	
	PWMLightStrip(int pinNumber);
	
	bool getState();
	bool setState(bool on);
		
	int getBrightness();
	bool setBrightness(int value);
		
private:

	int _brightness;
	bool _on;
};


#endif
