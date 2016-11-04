#ifndef PWM_H
#define PWM_H


int exportPWM(int pinNumber);

int setDutyCycle(int pinNumber, int value);
int setPeriod(int pinNumber, int value);

int getDutyCycle(int pinNumber);
int getPeriod(int pinNumber);


#endif
