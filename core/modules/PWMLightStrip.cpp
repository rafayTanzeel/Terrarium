// PWMLightStrip.cpp
#include "PWMLightStrip.h"

static int period = 100000; //nanoseconds

PWMLightStrip::PWMLightStrip(int pinNumber) : _pwm(pinNumber),
                                              _brightness(0),
                                              _on(false)
{
    _pwm.setPeriod(period);
}

PWMLightStrip::~PWMLightStrip()
{
}
	
bool PWMLightStrip::getState()
{
    return _on;
}

bool PWMLightStrip::setState(bool on)
{
    if (on) {
        _pwm.enable();
    }
    else {
        _pwm.disable();
    }
    _on = on;
    
    return true;
}
			
int PWMLightStrip::getBrightness()
{
    return _pwm.getDutyCycle();
}

bool PWMLightStrip::setBrightness(int percent)
{   
    if (percent > 100) {
        percent = 100;
    }  
    else if (percent < 0) {
        percent = 0;
    }
    int period = _pwm.getPeriod();
    int dutyCycle = period * percent;
    _pwm.setDutyCycle(dutyCycle);
    return true;
}

	
