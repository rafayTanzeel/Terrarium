#ifndef TERRARIUM_SERVER_H
#define TERRARIUM_SERVER_H

#include "controllers/TerrariumController.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

#define MSG_MAX_LEN 1024
#define PORT 1337

using namespace std;

class TerrariumServer
{

public:

static void* listener(void* arg);
static void returnPacket(char* message);

private:

static bool stopping;
static TerrariumController* _terrariumController;

static vector<string> split(string str, char delimiter);

};

#endif
