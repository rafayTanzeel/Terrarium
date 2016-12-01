// Fan.cpp
#include "Fan.h"

static int period = 100000; //nanoseconds


Fan::Fan(int pinNumber, int maxRPM) : _pwm(pinNumber), 
                                      _maxRPM(maxRPM), 
                                      _speedPercent(100), 
                                      _on(false)
{
    _pwm.setPeriod(period);
}

Fan::~Fan()
{
}

	
bool Fan::getState()
{
    return _on;
}

bool Fan::setState(bool on)
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
		
int Fan::getSpeedRPM()
{
    return _maxRPM * getSpeedPercent();
}

bool Fan::setSpeedRPM(int RPM)
{
    if (RPM > _maxRPM) {
        RPM = _maxRPM;
    }
    else if (RPM < 0) {
        RPM = 0;
    }
    
    int dutyCycle = RPM / _maxRPM;
    _pwm.setDutyCycle(dutyCycle);
    
    setState(RPM <= 0 ? false : true);
    return true;
}
	
int Fan::getSpeedPercent()
{
    return _pwm.getDutyCycle();
}

bool Fan::setSpeedPercent(int percent)
{   
    if (percent > 100) {
        percent = 100;
    }
    else if (percent < 0)
    {
        percent = 0;
    }
    int period = _pwm.getPeriod();
    int dutyCycle = period * percent;
    _pwm.setDutyCycle(dutyCycle);
    return true;
}
	
int Fan::getMaxRPM()
{
    return _maxRPM;
}

bool Fan::setMaxRPM(int maxRPM)
{
    _maxRPM = maxRPM;
    return true;
}
	
