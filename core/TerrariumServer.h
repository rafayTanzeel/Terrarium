#ifndef TERRARIUMSERVER_H
#define TERRARIUMSERVER_H

#include "controllers/TerrariumController.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MSG_MAX_LEN 1024
#define PORT 1337

extern _Bool stopping;

void* listener(void* arg);
void returnPacket(char* message);

#endif