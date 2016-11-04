// Relay.cpp
#include "Relay.h"
#include "../tools/GPIO.h"


Relay::Relay(int pinNumber, bool initiallyOn = false)
{
	exportGPIO(pinNumber);
	setDirectionOut(pinNumber);
	int setValue(pinNumber, initiallyOn);
	
	_pinNumber = pinNumber;
}
	
bool Relay::GetState()
{
	return getValue(_pinNumber);
}
	
bool Relay::setState(_bool on)
{
	return setValue(_pinNumber, on);
}

	
