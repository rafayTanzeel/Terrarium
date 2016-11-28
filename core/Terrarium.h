#ifndef TERRARIUM_H
#define TERRARIUM_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "controllers/TerrariumController.h"
#include "TerrariumServer.h"

#define SHT31_DEFAULT_ADDR 0x44
#define I2CDRV_LINUX_BUS0 "/dev/i2c-0"
#define I2CDRV_LINUX_BUS1 "/dev/i2c-1"
#define I2CDRV_LINUX_BUS2 "/dev/i2c-2"

#define NUM_THREADS 1

_Bool stopping = false;

TerrariumServer _terrariumServer;

#endif

