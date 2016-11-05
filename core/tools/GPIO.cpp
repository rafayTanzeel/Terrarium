#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <pthread.h>
#include "GPIO.h"


int exportGPIO(int pinNumber)
{
	// Use fopen() to open the file for write access.
	FILE *pfile = fopen("/sys/class/gpio/export", "w");
	if (pfile == NULL) {
	printf("ERROR: Unable to open export file.\n");
	return -1;
	}
	// Write to data to the file using fprintf():
	fprintf(pfile, "%d", pinNumber);
	// Close the file using fclose():
	fclose(pfile);
	return 0;
}

int setDirectionIn(int pinNumber)
{	
 	char fileName[50];
 	
 	sprintf(fileName, "/sys/class/gpio/gpio%d/direction", pinNumber); 
	int returnValue = 0;
	
	FILE *file = fopen(fileName, "w");

	if (NULL == file) {
		printf("ERROR OPENING %s.", fileName);
		returnValue = -1;
	}
	else {
		int charWritten = fprintf(file, "%s", "in");
		if (charWritten <= 0) { 
			printf("ERROR WRITING DATA");
			returnValue = -1;
		}
	}
	fclose(file);
	return returnValue;
}


int setDirectionOut(int pinNumber)
{	
 	char fileName[50];
 	
 	sprintf(fileName, "/sys/class/gpio/gpio%d/direction", pinNumber); 
	int returnValue = 0;
	
	FILE *file = fopen(fileName, "w");

	if (NULL == file) {
		printf("ERROR OPENING %s.", fileName);
		returnValue = -1;
	}
	else {
		int charWritten = fprintf(file, "%s", "out");
		if (charWritten <= 0) { 
			printf("ERROR WRITING DATA");
			returnValue = -1;
		}
	}
	fclose(file);
	return returnValue;
}



int setValue(int pinNumber, int value)
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


int getValue(int pinNumber)
{
	char fileName[50];
 	
 	sprintf(fileName, "/sys/class/gpio/gpio%d/value", pinNumber); 
	
	FILE *file = fopen(fileName, "r");
	if (NULL == file) {
		printf("ERROR: Unable to open file (%s) for read\n", fileName);
		exit(-1);
	}

	// Read string (line)
	const int max_length = 8;
	char buff[max_length];
	fgets(buff, max_length, file);
	
	// Close
	fclose(file);
	
	return atoi(buff);
}


