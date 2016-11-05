#include <stdio.h>
//#include <time.h>
//#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//#include <pthread.h>
#include <map>
#include <cstring>
#include "PWM.h"

static const char* SLOTS_DIR = "/sys/devices/platform/bone_capemgr/slots";

static const char* PINMUX_DIR = "/sys/devices/platform/ocp/ocp:";
static const char* PWM_DIR = "/sys/class/pwm";

struct PinInfo
{
	int pinNumber;
	char headerNumber[6];
	int pwmChipNumber;
	int exportNumber;
};

static const std::map<int, PinInfo> pinInfoLookup = {{50,  PinInfo{50,  "P9_14", 4, 1}},
			   									  	 {51,  PinInfo{51,  "P9_16", 6, 0}},
			   										 {3,   PinInfo{3,   "P9_21", 0, 0}},
			   										 {2,   PinInfo{2,   "P9_22", 2, 0}},
			   										 {123, PinInfo{123, "P9_28", 0, 0}},
			   										 {121, PinInfo{121, "P9_29", 0, 0}},
			   										 {120, PinInfo{120, "P9_31", 0, 0}},
			   										 {23,  PinInfo{23,  "P8_13", 0, 0}},
			   										 {22,  PinInfo{22,  "P8_19", 4, 0}},
			   										 {81,  PinInfo{81,  "P8_34", 0, 0}},
			   										 {80,  PinInfo{80,  "P8_36", 0, 0}},
			   										 {70,  PinInfo{70,  "P8_45", 0, 0}},
			   										 {71,  PinInfo{71,  "P8_46", 0, 0}}};


int loadCape(const char* capeName)
{
	// Use fopen() to open the file for write access.
	FILE *pfile = fopen(SLOTS_DIR, "w");
	if (pfile == NULL) {
	printf("ERROR: Unable to open cape file.\n");
	return -1;
	}
	// Write to data to the file using fprintf():
	if (strlen(capeName) != fprintf(pfile, "%s", capeName)) {
		printf("ERROR: Unable to write to cape file.\n");
	return -2;
	}
	// Close the file using fclose():
	fclose(pfile);
	return 0;
}

int configPinMux(int pinNumber) {
	if (pinInfoLookup.end() == pinInfoLookup.find(pinNumber)) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	const char* headerNumber = pinInfoLookup.at(pinNumber).headerNumber;
	
	// Use fopen() to open the file for write access.
	char fileName[50];
 	
 	sprintf(fileName, "%s%s_pinmux/state", PINMUX_DIR, headerNumber); 
	
	FILE *pfile = fopen(fileName, "w");
	if (pfile == NULL) {
	printf("ERROR: Unable to open pinmux file.\n %s\n", fileName);
	return -1;
	}
	// Write to data to the file using fprintf():
	if (strlen("pwm") != fprintf(pfile, "%s", "pwm")) {
		printf("ERROR: Unable to set pinmux.\n");
	return -1;
	}
	// Close the file using fclose():
	fclose(pfile);
	return 0;
}


int exportPWM(int pinNumber)
{
	if (pinInfoLookup.end() == pinInfoLookup.find(pinNumber)) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	
	int pwmChipNumber = pinInfoLookup.at(pinNumber).pwmChipNumber;
	int exportNumber = pinInfoLookup.at(pinNumber).exportNumber;
	
	char fileName[50];
 	
 	sprintf(fileName, "%s/pwmchip%i/export", PWM_DIR, pwmChipNumber); 
	
	
	// Use fopen() to open the file for write access.
	FILE *pfile = fopen(fileName, "w");
	if (pfile == NULL) {
		printf("ERROR: Unable to open export file.\n");
		return -1;
	}
	// Write to data to the file using fprintf():	
	char exportNumString[4];
	sprintf(exportNumString, "%d", exportNumber);
	if (strlen(exportNumString) != fprintf(pfile, "%s", exportNumString)) {
		printf("ERROR: Unable to export pin.\n");
		return -1;
	}
	// Close the file using fclose():
	fclose(pfile);
	return 0;
}


int setDutyCycle(int pinNumber, int value)
{
 	char fileName[50];
 	
 	sprintf(fileName, "/sys/class/pwm/pwm%d/value", pinNumber); 
	int returnValue = 0;
	
	FILE *file = fopen(fileName, "w");

	if (NULL == file) {
		printf("ERROR OPENING %s.", fileName);
		returnValue = -1;
	}
	else {
		int charWritten = fprintf(file, "%i", value);
		if (charWritten <= 0) { 
			printf("ERROR WRITING DATA");
			returnValue = -1;
		}
	}
	fclose(file);
	return returnValue;

}

int setPeriod(int pinNumber, int value)
{
 	char fileName[50];
 	
 	sprintf(fileName, "/sys/class/gpio/gpio%d/value", pinNumber); 
	int returnValue = 0;
	
	FILE *file = fopen(fileName, "w");

	if (NULL == file) {
		printf("ERROR OPENING %s.", fileName);
		returnValue = -1;
	}
	else {
		int charWritten = fprintf(file, "%i", value);
		if (charWritten <= 0) { 
			printf("ERROR WRITING DATA");
			returnValue = -1;
		}
	}
	fclose(file);
	return returnValue;

}

int getDutyCycle(int pinNumber)
{


}


int getPeriod(int pinNumber)
{



}


int main()
{
	loadCape("cape-universaln");
	configPinMux(50);
	exportPWM(50);

}

