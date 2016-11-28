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
	
bool Relay::GetState()
{
	return getValue(_pinNumber);
}
	
bool Relay::setState(bool on)
{
	return setValue(_pinNumber, on);
}

	
