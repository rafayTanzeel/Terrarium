#ifndef RELAY_H
#define RELAY_H

class Relay

{

public:
	Relay(int pinNumber, bool initiallyOn = false);
	
	bool GetState();
	bool setState(bool on);

	
private:
	int _pinNumber;

};


#endif
