// Relay.cpp
#include "Relay.h"
#include "../tools/GPIO.h"


Relay::Relay(int pinNumber, bool initiallyOn)
{
	exportGPIO(pinNumber);
	setDirectionOut(pinNumber);
	_pinNumber = pinNumber;

	setState(initiallyOn);
}

Relay::~Relay()
{
}
	
bool Relay::getState()
{
	return getValue(_pinNumber);
}
	
int Relay::setState(bool on)
{
	return setValue(_pinNumber, on);
}

	
