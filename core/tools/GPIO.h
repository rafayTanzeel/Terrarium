#ifndef GPIO_H
#define GPIO_H


int exportGPIO(int pinNumber);

int setDirectionIn(int pinNumber);
int setDirectionOut(int pinNumber);

int setValue(int pinNumber, int value);
int getValue(int pinNumber);


#endif

