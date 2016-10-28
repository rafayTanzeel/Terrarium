/**************************************************************************/
/*!
    @file     Adafruit_TSL2591.cpp
    @author   KT0WN (adafruit.com)

    This is a library for the Adafruit TSL2591 breakout board
    This library works with the Adafruit TSL2591 breakout
    ----> https://www.adafruit.com/products/1980

    Check out the links above for our tutorials and wiring diagrams
    These chips use I2C to communicate

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2014 Adafruit Industries
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "Adafruit_TSL2591.h"
#include "Wire.h"

Adafruit_TSL2591::Adafruit_TSL2591(int32_t sensorID)
{
  _initialized = false;
  _integration = TSL2591_INTEGRATIONTIME_100MS;
  _gain        = TSL2591_GAIN_MED;
  _sensorID    = sensorID;

  // we cant do wire initialization till later, because we havent loaded Wire yet
}

bool Adafruit_TSL2591::begin(void)
{

  
  for (uint8_t i=0; i<0x20; i++)
  {
    uint8_t id = read8(0x12);
    printf("$"); 
    printf("%x", i);
    printf(" = 0x"); 
    printf("%x\n", read8(i));
  }
  

  uint8_t id = read8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_DEVICE_ID);
  if (id == 0x50 )
  {
      printf("Found Adafruit_TSL2591\n");
  }
  else
  {
    return false;
  }

  _initialized = true;

  // Set default integration time and gain
  setTiming(_integration);
  setGain(_gain);

  // Note: by default, the device is in power down mode on bootup
  disable();

  return true;
}

void Adafruit_TSL2591::setI2CFile(const char * filename, uint8_t addr)
{
	_file = Wire.openI2C(filename, addr);
}

void Adafruit_TSL2591::enable(void)
{
  if (!_initialized)
  {
    if (!begin())
    {
      return;
    }
  }

  // Enable the device by setting the control bit to 0x01
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_ENABLE, TSL2591_ENABLE_POWERON | TSL2591_ENABLE_AEN | TSL2591_ENABLE_AIEN | TSL2591_ENABLE_NPIEN);
}

void Adafruit_TSL2591::disable(void)
{
  if (!_initialized)
  {
    if (!begin())
    {
      return;
    }
  }

  // Disable the device by setting the control bit to 0x00
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_ENABLE, TSL2591_ENABLE_POWEROFF);
}

void Adafruit_TSL2591::setGain(tsl2591Gain_t gain)
{
  if (!_initialized)
  {
    if (!begin())
    {
      return;
    }
  }

  enable();
  _gain = gain;
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_CONTROL, _integration | _gain);
  disable();
}

tsl2591Gain_t Adafruit_TSL2591::getGain()
{
  return _gain;
}

void Adafruit_TSL2591::setTiming(tsl2591IntegrationTime_t integration)
{
  if (!_initialized)
  {
    if (!begin())
    {
      return;
    }
  }

  enable();
  _integration = integration;
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_CONTROL, _integration | _gain);
  disable();
}

tsl2591IntegrationTime_t Adafruit_TSL2591::getTiming()
{
  return _integration;
}

uint32_t Adafruit_TSL2591::calculateLux(uint16_t ch0, uint16_t ch1)
{
  float    atime, again;
  float    cpl, lux1, lux2, lux;
  uint32_t chan0, chan1;

  // Check for overflow conditions first
  if ((ch0 == 0xFFFF) | (ch1 == 0xFFFF))
  {
    // Signal an overflow
    return 0;
  }

  // Note: This algorithm is based on preliminary coefficients
  // provided by AMS and may need to be updated in the future

  switch (_integration)
  {
    case TSL2591_INTEGRATIONTIME_100MS :
      atime = 100.0F;
      break;
    case TSL2591_INTEGRATIONTIME_200MS :
      atime = 200.0F;
      break;
    case TSL2591_INTEGRATIONTIME_300MS :
      atime = 300.0F;
      break;
    case TSL2591_INTEGRATIONTIME_400MS :
      atime = 400.0F;
      break;
    case TSL2591_INTEGRATIONTIME_500MS :
      atime = 500.0F;
      break;
    case TSL2591_INTEGRATIONTIME_600MS :
      atime = 600.0F;
      break;
    default: // 100ms
      atime = 100.0F;
      break;
  }

  switch (_gain)
  {
    case TSL2591_GAIN_LOW :
      again = 1.0F;
      break;
    case TSL2591_GAIN_MED :
      again = 25.0F;
      break;
    case TSL2591_GAIN_HIGH :
      again = 428.0F;
      break;
    case TSL2591_GAIN_MAX :
      again = 9876.0F;
      break;
    default:
      again = 1.0F;
      break;
  }

  // cpl = (ATIME * AGAIN) / DF
  cpl = (atime * again) / TSL2591_LUX_DF;

  lux1 = ( (float)ch0 - (TSL2591_LUX_COEFB * (float)ch1) ) / cpl;
  lux2 = ( ( TSL2591_LUX_COEFC * (float)ch0 ) - ( TSL2591_LUX_COEFD * (float)ch1 ) ) / cpl;
  lux = lux1 > lux2 ? lux1 : lux2;

  // Alternate lux calculation
  //lux = ( (float)ch0 - ( 1.7F * (float)ch1 ) ) / cpl;

  // Signal I2C had no errors
  return (uint32_t)lux;
}

uint32_t Adafruit_TSL2591::getFullLuminosity (void)
{
  if (!_initialized)
  {
    if (!begin())
    {
   		printf("early exit\n");
      return 0;
    }
  }

  // Enable the device
  enable();

  // Wait x ms for ADC to complete
  for (uint8_t d=0; d<=_integration; d++)
  {
    usleep(120000);
  }

  uint32_t x;
  x = read16(TSL2591_COMMAND_BIT | TSL2591_REGISTER_CHAN1_LOW);
  x <<= 16;
  x |= read16(TSL2591_COMMAND_BIT | TSL2591_REGISTER_CHAN0_LOW);

  disable();

  return x;
}

uint16_t Adafruit_TSL2591::getLuminosity (uint8_t channel)
{
  uint32_t x = getFullLuminosity();
  


  if (channel == TSL2591_FULLSPECTRUM)
  {
  	printf("Full spectrum\n");
    // Reads two byte value from channel 0 (visible + infrared)
    return (x & 0xFFFF);
  }
  else if (channel == TSL2591_INFRARED)
  {
  	printf("Infrared\n");
    // Reads two byte value from channel 1 (infrared)
    return (x >> 16);
  }
  else if (channel == TSL2591_VISIBLE)
  {
  	printf("Visible\n");
    // Reads all and subtracts out just the visible!
    return ( (x & 0xFFFF) - (x >> 16));
  }

  // unknown channel!
  return 0;
}

void Adafruit_TSL2591::registerInterrupt(uint16_t lowerThreshold, uint16_t upperThreshold)
{
  if (!_initialized)
  {
    if (!begin())
    {
      return;
    }
  }

  enable();
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_THRESHOLD_NPAILTL, lowerThreshold);
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_THRESHOLD_NPAILTH, lowerThreshold >> 8);
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_THRESHOLD_NPAIHTL, upperThreshold);
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_THRESHOLD_NPAIHTH, upperThreshold >> 8);
  disable();
}

void Adafruit_TSL2591::registerInterrupt(uint16_t lowerThreshold, uint16_t upperThreshold, tsl2591Persist_t persist)
{
  if (!_initialized)
  {
    if (!begin())
    {
      return;
    }
  }

  enable();
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_PERSIST_FILTER,  persist);
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_THRESHOLD_AILTL, lowerThreshold);
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_THRESHOLD_AILTH, lowerThreshold >> 8);
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_THRESHOLD_AIHTL, upperThreshold);
  write8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_THRESHOLD_AIHTH, upperThreshold >> 8);
  disable();
}

void Adafruit_TSL2591::clearInterrupt()
{
  if (!_initialized)
  {
    if (!begin())
    {
      return;
    }
  }

  enable();
  write8(TSL2591_CLEAR_INT);
  disable();
}


uint8_t Adafruit_TSL2591::getStatus()
{
  if (!_initialized)
  {
    if (!begin())
    {
      return 0;
    }
  }

  // Enable the device
  enable();
  uint8_t x;
  x = read8(TSL2591_COMMAND_BIT | TSL2591_REGISTER_DEVICE_STATUS);
  disable();
  return x;
}


uint8_t Adafruit_TSL2591::read8(uint8_t reg)
{
	return Wire.read8(_file, reg);
}

uint16_t Adafruit_TSL2591::read16(uint8_t reg)
{
	return Wire.read16(_file, reg);
}

void Adafruit_TSL2591::write8 (uint8_t reg, uint8_t value)
{
	printf(" write8 returned: %i\n", Wire.write8(_file, reg, value));
}


void Adafruit_TSL2591::write8 (uint8_t reg)
{
	printf(" write8 returned: %i\n", Wire.write8(_file, reg));
}

