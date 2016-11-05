#ifndef PWM_H
#define PWM_H


int exportPWM(int pinNumber);

int setDutyCycle(int pinNumber, int value);
int setPeriod(int pinNumber, int value);

int getDutyCycle(int pinNumber);
int getPeriod(int pinNumber);


/*50 = 9_14 = 3

51 = 9_16 = 4

3  = 9_21 = 1
2  =  9_22 = 0

123	= 9_28 = 7
	
121	= 9_29 = 1
	
120	= 9_31 = 0
	
23	= 8_13 = 6
	
22	= 8_19 = 5
	
81	= 8_34 = 4
80	= 8_36 = 3
70	= 8_45 = 5
71	= 8_46 = 6*/


#endif
