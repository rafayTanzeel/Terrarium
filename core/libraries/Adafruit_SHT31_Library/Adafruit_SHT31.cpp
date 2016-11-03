/*************************************************** 
  This is a library for the SHT31 Digital Humidity & Temp Sensor

  Designed specifically to work with the SHT31 Digital sensor from Adafruit
  ----> https://www.adafruit.com/products/2857

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>

#include "Adafruit_SHT31.h"
#include "../Wire/Wire.h"


Adafruit_SHT31::Adafruit_SHT31() {
}

void Adafruit_SHT31::setI2CFile(const char * filename, uint8_t addr)
{
	_file = Wire.openI2C(filename, addr);
}


bool Adafruit_SHT31::begin() {
  reset();
  //return (readStatus() == 0x40);
  return true;
}

uint16_t Adafruit_SHT31::readStatus(void) {
  writeCommand(SHT31_READSTATUS);
  
  uint16_t stat;
  Wire.readBytes(_file, 1, (uint8_t*)&stat);
  stat <<= 8;
  uint16_t statTemp;
  Wire.readBytes(_file, 1, (uint8_t*)&statTemp);
  stat |= statTemp;
  
  //Serial.println(stat, HEX);
  return stat;
}

void Adafruit_SHT31::reset(void) {
  if (1 != writeCommand(SHT31_SOFTRESET)) {
  printf("Failed to reset device\n");
  }
  usleep(10000);
}

void Adafruit_SHT31::heater(bool h) {
  if (h)
    writeCommand(SHT31_HEATEREN);
  else
    writeCommand(SHT31_HEATERDIS);
}


float Adafruit_SHT31::readTemperature(void) {
  if (! readTempHum()) return NAN;

  return temp;
}
  

float Adafruit_SHT31::readHumidity(void) {
  if (! readTempHum()) return NAN;

  return humidity;
}


bool Adafruit_SHT31::readTempHum(void) {
  uint8_t readbuffer[6] = {0};

  writeCommand(SHT31_MEAS_HIGHREP);
  usleep(1000000);
  Wire.readBytes(_file, 6, readbuffer);
  
  for (int i = 0; i < 6; ++i) {
     printf("readbuffer[%i]: %x\n", i, readbuffer[i]);
  }

  uint16_t ST, SRH;
  ST = readbuffer[0];
  ST <<= 8;
  ST |= readbuffer[1];

  if (readbuffer[2] != crc8(readbuffer, 2)) return false;

  SRH = readbuffer[3];
  SRH <<= 8;
  SRH |= readbuffer[4];

  if (readbuffer[5] != crc8(readbuffer+3, 2)) return false;

  printf("ST = %i\n", ST);
 // Serial.print("ST = "); Serial.println(ST);
  double stemp = ST;
  stemp *= 175;
  stemp /= 0xffff;
  stemp = -45 + stemp;
  temp = stemp;
  
  printf("SRH = %i\n", SRH);
//  Serial.print("SRH = "); Serial.println(SRH);
  double shum = SRH;
  shum *= 100;
  shum /= 0xFFFF;
  
  humidity = shum;
  
  return true;
}

int Adafruit_SHT31::writeCommand(uint16_t cmd) {
	uint8_t cmd8[2];
	cmd8[0] = cmd >> 8;
	cmd8[1] = cmd & 0xFF;
	int e = Wire.write8(_file, cmd8[0], cmd8[1]);
	if (e != 1) {
		printf("Failed to write command: %x\n", cmd);
		printf("e: %i\n", e);
	}
	return e;
}

uint8_t Adafruit_SHT31::crc8(const uint8_t *data, int len)
{
/*
*
 * CRC-8 formula from page 14 of SHT spec pdf
 *
 * Test data 0xBE, 0xEF should yield 0x92
 *
 * Initialization data 0xFF
 * Polynomial 0x31 (x8 + x5 +x4 +1)
 * Final XOR 0x00
 */

  const uint8_t POLYNOMIAL(0x31);
  uint8_t crc(0xFF);
  
  for ( int j = len; j; --j ) {
      crc ^= *data++;

      for ( int i = 8; i; --i ) {
	crc = ( crc & 0x80 )
	  ? (crc << 1) ^ POLYNOMIAL
	  : (crc << 1);
      }
  }
  return crc;
}

/*********************************************************************/
