// Analog.cpp
// Not working yet

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <map>
#include <unistd.h>
#include <dirent.h>
#include "Analog.h"

/*static const char* SLOTS_FILE = "/sys/devices/platform/bone_capemgr/slots";

static const char* OCP_DIR = "/sys/devices/platform/ocp/";
static const char* Analog_DIR = "/sys/class/analog/";

#define A2D_VOLTAGE_REF_V 1.8
#define A2D_MAX_READING 4095

bool Analog::_capeLoaded = false; 


Analog::Analog(int pinNumber)
{
	_pinNumber = pinNumber;
	initPinFS();
	configPinMux();
	exportAnalog();
}



// This method heavily based off of code provided by Pierre-Louis Constant at: https://groups.google.com/d/msg/beagleboard/gL-IobsCJ_s/p3BvBZaBBgAJ
int Analog::initPinFS()
{
	loadCape("cape-universaln");


	if (pinHeaderLookup.end() == pinHeaderLookup.find(_pinNumber)) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	const char* headerNumber = pinHeaderLookup.at(_pinNumber);

    //Find chip name
    std::string chipAddress;
    std::string analogNumber;
    //EHRAnalog0A
    if (headerNumber == "P9_22" || headerNumber == "P9_31") {
        chipAddress = "48300200.ehranalog";
        _exportNumber = 0;
        analogNumber = "analog0";
        }
    //EHRAnalog0B
    if (headerNumber == "P9_21" || headerNumber == "P9_29") {
        chipAddress = "48300200.ehranalog";
        _exportNumber = 1;
        analogNumber = "analog1";
        }
    //EHRAnalog1A
    if (headerNumber == "P9_14" || headerNumber == "P8_36") {
        chipAddress = "48302200.ehranalog";
        _exportNumber = 0;
        analogNumber = "analog0";
        }
    //EHRAnalog1B
    if (headerNumber == "P9_16" || headerNumber == "P8_34") {
        chipAddress = "48302200.ehranalog";
        _exportNumber = 1;
        analogNumber = "analog1";
        }
    //EHRAnalog2A
    if (headerNumber == "P8_19" || headerNumber == "P8_45") {
        chipAddress = "48304200.ehranalog";
        _exportNumber = 0;
        analogNumber = "analog0";
        }
    //EHRAnalog2B
    if (headerNumber == "P8_13" || headerNumber == "P8_46") {
        chipAddress = "48304200.ehranalog";
        _exportNumber = 1;
        analogNumber = "analog1";
                }
    //ECAPAnalog0
    if (headerNumber == "P9_42") {
        chipAddress = "48300100.ecap";
        _exportNumber = 0;
        analogNumber = "analog0";
        }\
    //EHCAPAnalog2
    if (headerNumber == "P9_28") {
        chipAddress = "48300200.ecap";
        _exportNumber = 0;
        analogNumber = "analog0";
        }
               
    std::string chipPath;
    
    chipPath = std::string(OCP_DIR) + "subsystem/devices/" + chipAddress +"/analog/";
    
    _analogChip = getFullNameOfFileInDirectory(chipPath, "analogchip");
    
    std::string pinInterfacePath = std::string(Analog_DIR) + _analogChip + "/" + analogNumber + "/";
    
    _dutyCyclePath = pinInterfacePath + "duty_cycle";
    _periodPath = pinInterfacePath + "period";
    _polarityPath = pinInterfacePath + "polarity";
    _enablePath = pinInterfacePath + "enable";

}



// This method is taken from https://github.com/SaadAhmad/beaglebone-black-cpp-Analog/blob/master/library/Analog.cpp
// A bunch of helper functions to get us locations in the file system.
// They are used so that we can manipulate the analog driver through the /sys interface
std::string Analog::getFullNameOfFileInDirectory(const std::string & dirName, const std::string & fileNameToFind)
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


int Analog::loadCape(const char* capeName)
{
	if (!_capeLoaded) {
	printf("Loading Cape\n");
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


int Analog::configPinMux() {
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
	if (strlen("analog") != fprintf(pfile, "%s", "analog")) {
		printf("ERROR: Unable to set pinmux.\n");
	return -1;
	}
	// Close the file using fclose():
	fclose(pfile);
	return 0;
}


int Analog::exportAnalog()
{
	if (pinHeaderLookup.end() == pinHeaderLookup.find(_pinNumber)) {
		printf("ERROR: Invalid pin number specified\n");
		return -1;
	}
	const char* headerNumber = pinHeaderLookup.at(_pinNumber);
	
	char fileName[50];
 	
 	sprintf(fileName, "%s%s/export", Analog_DIR, _analogChip.c_str()); 
	
	
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


int Analog::setDutyCycle(int nanoseconds)
{
	int returnValue = 0;
	
	printf("%s\n", _dutyCyclePath.c_str());
	
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

int Analog::setPeriod(int nanoseconds)
{
	int returnValue = 0;
	
	printf("%s\n", _periodPath.c_str());
	
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

int Analog::enable()
{
	int returnValue = 0;
	
	printf("%s\n", _enablePath.c_str());
	
	FILE *file = fopen(_enablePath.c_str(), "w");

	if (NULL == file) {
		printf("ERROR OPENING %s.", _enablePath.c_str());
		returnValue = -1;
	}
	else {
		int charWritten = fprintf(file, "1");
		if (charWritten <= 0) { 
			printf("ERROR WRITING DATA");
			returnValue = -1;
		}
	}
	fclose(file);
	return returnValue;
}

int Analog::disable()
{
	int returnValue = 0;
	
	printf("%s\n", _enablePath.c_str());
	
	FILE *file = fopen(_enablePath.c_str(), "w");

	if (NULL == file) {
		printf("ERROR OPENING %s.", _enablePath.c_str());
		returnValue = -1;
	}
	else {
		int charWritten = fprintf(file, "0");
		if (charWritten <= 0) { 
			printf("ERROR WRITING DATA");
			returnValue = -1;
		}
	}
	fclose(file);
	return returnValue;
}

int Analog::getDutyCycle()
{


}


int Analog::getPeriod()
{



}


int main()
{
	Analog analog50(51);
	printf("Enabling Analog on GPIO50\n");
	printf("Analog Pin directories:\n");
	
	analog50.setPeriod(10000000);
	analog50.setDutyCycle(5000000);
	analog50.enable();
}*/

