#ifndef PWM_H
#define PWM_H

#include <string>

int exportPWM(int pinNumber);

int setDutyCycle(int pinNumber, int value);
int setPeriod(int pinNumber, int value);

int getDutyCycle(int pinNumber);
int getPeriod(int pinNumber);

class PWM

{

public:
	
	PWM(int pinNumber);
	
	int setDutyCycle(int value);
	int setPeriod(int value);

	int getDutyCycle();
	int getPeriod();
	
	int enable();
	int disable();
		
private:

	int initPinFS();
	
	static int loadCape(const char* capeName);
	
	std::string getFullNameOfFileInDirectory(const std::string & dirName, const std::string & fileNameToFind);
	
	int configPinMux();
	
	int exportPWM();

	static bool _capeLoaded;

	int _pinNumber;
	int _exportNumber;
	
	//char headerNumber[6];
	
	std::string _pwmChip;
	
	std::string _dutyCyclePath;
	std::string _periodPath;   
	std::string _polarityPath;
	std::string _enablePath;
};


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
