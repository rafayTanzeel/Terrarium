#ifndef _TWOWIRE_H_
#define _TWOWIRE_H_

#include <stdint.h>

class TwoWire
{
 public:
 	int openI2C(const char * filename, uint8_t addr);
	int readI2C(int file, int len, unsigned char * buff);
	int writeI2C(int file, int len, unsigned char * buff);
	
	uint8_t read8(int file, uint8_t addr);
	int write8(int file, uint8_t addr, uint8_t send);
	
	int readBytes(int file, int num, uint8_t* bytes);
	
 private:

};

extern TwoWire Wire;

#endif






