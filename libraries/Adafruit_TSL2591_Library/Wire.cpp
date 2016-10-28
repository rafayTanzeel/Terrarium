#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Wire.h"

int TwoWire::openI2C(const char * filename, uint8_t addr){
	int file;
	if((file = open(filename, O_RDWR)) < 0){
		/* Check Error Number */
		perror("Failed to open the i2c bus");
		return 0;
	}

	if(ioctl(file, I2C_SLAVE, addr) < 0){
		printf("Failed to acquire bus access and/or talk to slave.\n");
		return 0;
	}

	return file;
}

int TwoWire::readI2C(int file, int len, unsigned char * buff){
	if(read(file, buff, len) != len){
		printf("Failed to read from i2c bus.\n");
		return -1;
	}
	return 1;
}

int TwoWire::writeI2C(int file, int len, unsigned char * buff){
	if(write(file, buff, len) != len){
		printf("Failed to write to i2c bus.\n");
		return -1;
	}
	return 1;
}

uint8_t TwoWire::read8(int file, uint8_t addr){
	writeI2C(file, 1, &addr);
	usleep(100);
	uint8_t recv;
	readI2C(file, 1, &recv);
	return recv;
}

uint16_t TwoWire::read16(int file, uint8_t addr){
	writeI2C(file, 1, &addr);
	usleep(100);
	uint16_t recv;
	readI2C(file, 2, (uint8_t*)&recv);
	return recv;
}

int TwoWire::write8(int file, uint8_t addr, uint8_t send){
	int e = 0;
	
 	uint8_t buff[2];
 	buff[0] = addr;
 	buff[1] = send;
	e += writeI2C(file, 2, buff);
	return e;
}


int TwoWire::write8(int file, uint8_t addr){
	int e = 0;
	e += writeI2C(file, 1, &addr);
	return e;
}

int TwoWire::write16(int file, uint8_t addr){
	int e = 0;
	e += writeI2C(file, 1, &addr);
	return e;
}


TwoWire Wire = TwoWire();

//int main(int argc, char *argv[]){

	//int file = openI2C("/dev/i2c-3", 0x29);

//	uint8_t id = read8(file, TSL2591_COMMAND_BIT | TSL2591_REGISTER_DEVICE_ID);

//	cout << id << endl;

//}
