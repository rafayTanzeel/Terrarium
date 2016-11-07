#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <map>
#include <cstring>
#include <unistd.h>
#include <dirent.h>
#include "PWM.h"

static const char* SLOTS_FILE = "/sys/devices/platform/bone_capemgr/slots";

static const char* OCP_DIR = "/sys/devices/platform/ocp/";
static const char* PWM_DIR = "/sys/class/pwm/";

bool PWM::_capeLoaded = false; 

static const std::map<int, const char*> pinHeaderLookup = {{50,  "P9_14"},
			   									  	   	   {51,  "P9_16"},
				   										   {3,   "P9_21"},
				   										   {2,   "P9_22"},
				   										   {123, "P9_28"},
				   										   {121, "P9_29"},
				   										   {120, "P9_31"},
				   										   {23,  "P8_13"},
				   										   {22,  "P8_19"},
				   										   {81,  "P8_34"},
				   										   {80,  "P8_36"},
				   										   {70,  "P8_45"},
				   										   {71,  "P8_46"}};



PWM::PWM(int pinNumber)
{
	_pinNumber = pinNumber;
	initPinFS();
	configPinMux();
	exportPWM();
}



// This method heavily based off of code provided by Pierre-Louis Constant at: https://groups.google.com/d/msg/beagleboard/gL-IobsCJ_s/p3BvBZaBBgAJ
int PWM::initPinFS()
{
	loadCape("cape-universaln");


	if (pinHeaderLookup.end() == pinHeaderLookup.find(_pinNumber)) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	const char* headerNumber = pinHeaderLookup.at(_pinNumber);

    //Find chip name
    std::string chipAddress;
    std::string pwmNumber;
    //EHRPWM0A
    if (headerNumber == "P9_22" || headerNumber == "P9_31") {
        chipAddress = "48300200.ehrpwm";
        _exportNumber = 0;
        pwmNumber = "pwm0";
        }
    //EHRPWM0B
    if (headerNumber == "P9_21" || headerNumber == "P9_29") {
        chipAddress = "48300200.ehrpwm";
        _exportNumber = 1;
        pwmNumber = "pwm1";
        }
    //EHRPWM1A
    if (headerNumber == "P9_14" || headerNumber == "P8_36") {
        chipAddress = "48302200.ehrpwm";
        _exportNumber = 0;
        pwmNumber = "pwm0";
        }
    //EHRPWM1B
    if (headerNumber == "P9_16" || headerNumber == "P8_34") {
        chipAddress = "48302200.ehrpwm";
        _exportNumber = 1;
        pwmNumber = "pwm1";
        }
    //EHRPWM2A
    if (headerNumber == "P8_19" || headerNumber == "P8_45") {
        chipAddress = "48304200.ehrpwm";
        _exportNumber = 0;
        pwmNumber = "pwm0";
        }
    //EHRPWM2B
    if (headerNumber == "P8_13" || headerNumber == "P8_46") {
        chipAddress = "48304200.ehrpwm";
        _exportNumber = 1;
        pwmNumber = "pwm1";
                }
    //ECAPPWM0
    if (headerNumber == "P9_42") {
        chipAddress = "48300100.ecap";
        _exportNumber = 0;
        pwmNumber = "pwm0";
        }\
    //EHCAPPWM2
    if (headerNumber == "P9_28") {
        chipAddress = "48300200.ecap";
        _exportNumber = 0;
        pwmNumber = "pwm0";
        }
               
    std::string chipPath;
    
    chipPath = std::string(OCP_DIR) + "subsystem/devices/" + chipAddress +"/pwm/";
    
    _pwmChip = getFullNameOfFileInDirectory(chipPath, "pwmchip");
    
    std::string pinInterfacePath = std::string(PWM_DIR) + _pwmChip + "/";
    
    _dutyCyclePath = pinInterfacePath + "duty_cycle";
    _periodPath = pinInterfacePath + "period";
    _polarityPath = pinInterfacePath + "polarity";
    _enablePath = pinInterfacePath + "enable";

}



// This method is taken from https://github.com/SaadAhmad/beaglebone-black-cpp-PWM/blob/master/library/PWM.cpp
// A bunch of helper functions to get us locations in the file system.
// They are used so that we can manipulate the pwm driver through the /sys interface
std::string PWM::getFullNameOfFileInDirectory(const std::string & dirName, const std::string & fileNameToFind)
{
	DIR *pDir;

	dirent *pFile;
	if ((pDir = opendir(dirName.c_str())) == NULL)
	{
		printf("Directory doesn't exist\n");
		throw std::bad_exception();
	}
	while ((pFile = readdir(pDir)) != NULL)
	{
		std::string currentFileName = (pFile->d_name);
		if (currentFileName.find(fileNameToFind) != std::string::npos)
		{
			return currentFileName;
		}
	}
	return std::string("");
}


int PWM::loadCape(const char* capeName)
{
	if (!_capeLoaded) {
	// Use fopen() to open the file for write access.
	FILE *pfile = fopen(SLOTS_FILE, "w");
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
	_capeLoaded = true;
	}
	return 0;
}


int PWM::configPinMux() {
	if (pinHeaderLookup.end() == pinHeaderLookup.find(_pinNumber)) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	const char* headerNumber = pinHeaderLookup.at(_pinNumber);
	
	// Use fopen() to open the file for write access.
	char fileName[50];
 	
 	sprintf(fileName, "%socp:%s_pinmux/state", OCP_DIR, headerNumber); 
	
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


int PWM::exportPWM()
{
	if (pinHeaderLookup.end() == pinHeaderLookup.find(_pinNumber)) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	const char* headerNumber = pinHeaderLookup.at(_pinNumber);
	
	char fileName[50];
 	
 	sprintf(fileName, "%s%s/export", PWM_DIR, _pwmChip.c_str()); 
	
	
	// Use fopen() to open the file for write access.
	FILE *pfile = fopen(fileName, "w");
	if (pfile == NULL) {
		printf("ERROR: Unable to open export file.\n");
		return -1;
	}
	// Write to data to the file using fprintf():	
	if (1 != fprintf(pfile, "%i", _exportNumber)) {
		printf("ERROR: Unable to export pin.\n");
		return -1;
	}
	// Close the file using fclose():
	fclose(pfile);
	return 0;
}


int PWM::setDutyCycle(int nanoseconds)
{
	int returnValue = 0;
	
	FILE *file = fopen(_dutyCyclePath.c_str(), "w");

	if (NULL == file) {
		printf("ERROR OPENING %s.", _dutyCyclePath.c_str());
		returnValue = -1;
	}
	else {
		int charWritten = fprintf(file, "%i", nanoseconds);
		if (charWritten <= 0) { 
			printf("ERROR WRITING DATA");
			returnValue = -1;
		}
	}
	fclose(file);
	return returnValue;

}

int PWM::setPeriod(int nanoseconds)
{
	int returnValue = 0;
	
	FILE *file = fopen(_periodPath.c_str(), "w");

	if (NULL == file) {
		printf("ERROR OPENING %s.", _periodPath.c_str());
		returnValue = -1;
	}
	else {
		int charWritten = fprintf(file, "%i", nanoseconds);
		if (charWritten <= 0) { 
			printf("ERROR WRITING DATA");
			returnValue = -1;
		}
	}
	fclose(file);
	return returnValue;

}

int PWM::getDutyCycle()
{


}


int PWM::getPeriod()
{



}


int main()
{
	PWM pwm50(50);

}

