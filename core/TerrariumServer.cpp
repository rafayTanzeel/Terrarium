#include "TerrariumServer.h"

bool TerrariumServer::stopping = false;
TerrariumController* TerrariumServer::_terrariumController = nullptr;

void* TerrariumServer::listener(void* arg)
{
	_terrariumController = (TerrariumController *) arg;
	char message[MSG_MAX_LEN];

	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_port = htons(PORT);

	int socketDesc = socket(PF_INET, SOCK_DGRAM, 0);

	bind(socketDesc, (struct sockaddr*) &sin, sizeof(sin));

	while (!stopping) {
		unsigned int sin_len = sizeof(sin);
		int bytesRx = recvfrom(socketDesc, message, MSG_MAX_LEN, 0, (struct sockaddr *) &sin, &sin_len);

		message[bytesRx] = 0;
		printf("Message received (%d bytes): \n\n'%s'\n", bytesRx, message);

		returnPacket(message);

		sin_len = sizeof(sin);
		sendto(socketDesc, message, strlen(message), 0, (struct sockaddr *) &sin, sin_len);
	}

	close(socketDesc);
	puts("Server thread exiting.");
	pthread_exit(0);
}

void TerrariumServer::returnPacket(char* message) 
{
	std::string str(message);
	//TODO: return packets sent from node.js

	if(str.compare("get status") == 0) {
		// int r,g,b;
		sprintf(message, "%d, %d, %d, %f, %f, %d, %d, %d, %d, %d, %f, %d, %d",
		 _terrariumController->getColorTemperature(), 
		 _terrariumController->getBrightnessLux(), 
		 _terrariumController->getBrightnessFootCandles(), 
		 _terrariumController->getHumidity(), 
		 _terrariumController->getTemperature(), 
		 _terrariumController->getIntakeFanStatus(), 
		 _terrariumController->getExhaustFanStatus(), 
		 _terrariumController->getCirculationFanStatus(), 
		 _terrariumController->getFoggerStatus(), 
		 _terrariumController->getCoolerStatus(), 
		 _terrariumController->getWetness(), 
		 _terrariumController->getAnalogLEDBrightness(), 
		 // _terrariumController->getRGBColor(&r, &b, &g));
		 13);
	}
}