#ifndef TERRARIUM_SERVER_H
#define TERRARIUM_SERVER_H

#include "controllers/TerrariumController.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <string>

#define MSG_MAX_LEN 1024
#define PORT 1337

class TerrariumServer
{

public:

static void* listener(void* arg);
static void returnPacket(char* message);

private:

static bool stopping;
static TerrariumController* _terrariumController;

};

#endif