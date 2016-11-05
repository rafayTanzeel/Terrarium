#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <pthread.h>
#include <map>
#include <string>
#include "PWM.cpp"

static const char* SLOTS_DIR = "/sys/devices/platform/bone_capemgr/slots";

static const char* PINMUX_DIR = "/sys/devices/platform/ocp/ocp\\:"
static const char* PWM_DIR = "/sys/class/pwm";

struct PinInfo
{
	int pinNumber;
	char headerNumber[4];
	int pwmChipNumber;
	int exportNumber;
}

static const map<int, PinInfo> pinInfoLookup = {{50,  {50,  "9_14", 4, 0}},
		   										{51,  {51,  "9_16", 4, 0}},
		   										{3,   {3,   "9_21", 4, 0}},
		   										{2,   {2,   "9_22", 4, 0}},
		   										{123, {123, "9_28", 4, 0}},
		   										{121, {121, "9_29", 4, 0}},
		   										{120, {120, "9_31", 4, 0}},
		   										{23,  {23,  "8_13", 4, 0}},
		   										{22,  {22,  "8_19", 4, 0}},
		   										{81,  {81,  "8_34", 4, 0}},
		   										{80,  {80,  "8_36", 4, 0}},
		   										{70,  {70,  "8_45", 4, 0}},
		   										{71,  {71,  "8_46", 4, 0}}}


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
	if (map::end == pinInfoLookup.find(pinNumber) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	const char* headerNumber = pinToHeaderLookup[pinNumber].headerNumber;
	
	// Use fopen() to open the file for write access.
	char fileName[50];
 	
 	sprintf(fileName, "%s%s_pinmux/state", PINMUX_DIR, headerNumber); 
	
	FILE *pfile = fopen(fileName, "w");
	if (pfile == NULL) {
	printf("ERROR: Unable to open pinmux file.\n");
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
	if (map::end == pinInfoLookup.find(pinNumber) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	
	int pwmChipNumber = pinInfoLookup[pinNumber].pwmChipNumber;
	int exportNumber = pinInfoLookup[pinNumber].exportNumber;
	
	char fileName[50];
 	
 	sprintf(fileName, "%s/pwmchip%i/export", PWM_DIR, pwmChipNumber); 
	
	
	// Use fopen() to open the file for write access.
	FILE *pfile = fopen(fileName, "w");
	if (pfile == NULL) {
		printf("ERROR: Unable to open export file.\n");
		return -1;
	}
	// Write to data to the file using fprintf():	
	if (strlen(itoa(exportNumber)) != fprintf(pfile, "%d", exportNumber)) {
		printf("ERROR: Unable to export pin.\n");
		return -1;
		
	// Close the file using fclose():
	fclose(pfile);
	return 0;
}


int setDutyCycle(int pinNumber, int value);
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

int setPeriod(int pinNumber, int value);
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

int getDutyCycle(int pinNumber);
{


}


int getPeriod(int pinNumber);
{



}
