#ifndef _TWOWIRE_H_
#define _TWOWIRE_H_


class TwoWire
{
 public:
 	int openI2C(const char * filename, uint8_t addr);
	int readI2C(int file, int len, unsigned char * buff);
	int writeI2C(int file, int len, unsigned char * buff);
	uint8_t read8(int file, uint8_t addr);
	uint16_t read16(int file, uint8_t addr);
	int write8(int file, uint8_t addr, uint8_t send);
	int write8(int file, uint8_t addr);
	int write16(int file, uint8_t addr);
	

 private:

};

extern TwoWire Wire;

#endif






