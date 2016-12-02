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
	string str(message);

	// Status
	if(str.compare(0, 14, "get_env_status") == 0) {
		sprintf(message, "%f, %f",
		  _terrariumController->getHumidity(),
		  _terrariumController->getTemperature());
	}
	else if(str.compare(0, 13, "get_hw_status") == 0) {
		sprintf(message, "%d, %d, %d, %d, %f",
				  _terrariumController->getIntakeFanStatus(),
				  _terrariumController->getExhaustFanStatus(),
//				  _terrariumController->getCirculationFanStatus(),
				  _terrariumController->getFoggerStatus(),
				  _terrariumController->getCoolerStatus(),
				  _terrariumController->getWetness());
	}
	else if(str.compare(0, 16, "get_light_status") == 0) {
		int r,b,g;
		_terrariumController->getRGBColor(r, b, g);
		sprintf(message, "%d, %d, %d, %d, %d, %d, %d",
				_terrariumController->getColorTemperature(),
				_terrariumController->getBrightnessLux(),
				_terrariumController->getBrightnessFootCandles(),
				_terrariumController->getAnalogLEDBrightness(),
				r, b, g);
	}

	// Manual
	else if(str.compare(0, 9, "intakeFan") == 0) {
		str.erase(0, 9);

		int val = stoi(str);
		_terrariumController->setIntakeFanStatus(val);
	}
	else if(str.compare(0, 10, "exhaustFan") == 0) {
		str.erase(0, 10);

		int val = stoi(str);
		_terrariumController->setExhaustFanStatus(val);
	}
	else if(str.compare(0, 14, "circulationFan") == 0) {
		str.erase(0, 14);

		int val = stoi(str);
		_terrariumController->setCirculationFanStatus(val);
	}
	else if(str.compare(0, 6, "fogger") == 0) {
		str.erase(0, 6);

		int val = stoi(str);
		_terrariumController->setFoggerStatus(val);
	}
	else if(str.compare(0, 6, "cooler") == 0) {
		str.erase(0, 6);

		int val = stoi(str);
		_terrariumController->setCoolerStatus(val);
	}
	else if(str.compare(0, 12, "manualbright") == 0) {
		str.erase(0, 12);

		int val = stoi(str);
		_terrariumController->setAnalogLEDBrightness(val);
	}
	else if(str.compare(0, 3, "rbg") == 0) {
		str.erase(0, 3);
		vector<string> result = split(str, ',');

		int r = stoi(result.at(0));
		int g = stoi(result.at(1));
		int b = stoi(result.at(2));
		_terrariumController->setRGBColor(r, g, b);
	}

	// Auto Ctrl
	else if(str.compare(0, 7, "humidIn") == 0) {
		str.erase(0, 7);

		int val = stoi(str);
		_terrariumController->setHumidity(val);
	}
	else if(str.compare(0, 8, "AutoTemp") == 0) {
		str.erase(0, 8);

		int val = stoi(str);
		_terrariumController->setTemperature(val);
	}
	else if(str.compare(0, 14, "wetAlarmThresh") == 0) {
		str.erase(0, 14);

		int val = stoi(str);
		_terrariumController->setWetnessAlarmThreshold(val);
	}
	else if(str.compare(0, 9, "colorTemp") == 0) {
		str.erase(0, 9);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setColorTemperature(val, flag);
	}
	else if(str.compare(0, 14, "colorBrightLux") == 0) {
		str.erase(0, 14);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setBrightnessLux(val, flag);
	}
	else if(str.compare(0, 22, "colorBrightFootcandles") == 0) {
		str.erase(0, 22);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setBrightnessFootcandles(val, flag);
	}

	// Auto D/N Ctrl
	else if(str.compare(0, 10, "NightTime:") == 0) {
		str.erase(0, 10);
		vector<string> result = split(str, ':');

		int h = stoi(result.at(0));
		int m = stoi(result.at(1));
		int s = stoi(result.at(2));
		_terrariumController->setNightTime(h, m, s);
	}
	else if(str.compare(0, 8, "DayTime:") == 0) {
		str.erase(0, 8);
		vector<string> result = split(str, ':');

		int h = stoi(result.at(0));
		int m = stoi(result.at(1));
		int s = stoi(result.at(2));
		_terrariumController->setDayTime(h, m, s);
	}
	else if(str.compare(0, 12, "dayBrightLux") == 0) {
		str.erase(0, 12);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setDayBrightnessLux(val, flag);
	}
	else if(str.compare(0, 14, "nightBrightLux") == 0) {
		str.erase(0, 14);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setNightBrightnessLux(val, flag);
	}
	else if(str.compare(0, 11, "dayBrightFC") == 0) {
		str.erase(0, 11);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setDayBrightnessFootcandles(val, flag);
	}
	else if(str.compare(0, 13, "nightBrightFC") == 0) {
		str.erase(0, 13);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setNightBrightnessFootcandles(val, flag);
	}
	else if(str.compare(0, 10, "DayhumidIn") == 0) {
		str.erase(0, 10);

		int val = stoi(str);
		_terrariumController->setDayHumidity(val);
	}
	else if(str.compare(0, 12, "NighthumidIn") == 0) {
		str.erase(0, 12);

		int val = stoi(str);
		_terrariumController->setNightHumidity(val);
	}
	else if(str.compare(0, 12, "dayColorTemp") == 0) {
		str.erase(0, 12);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setDayColorTemperature(val, flag);
	}
	else if(str.compare(0, 14, "nightColorTemp") == 0) {
		str.erase(0, 14);
		vector<string> result = split(str, ',');

		int val = stoi(result.at(0));
		int flag = stoi(result.at(1));
		_terrariumController->setNightColorTemperature(val, flag);
	}
	else if(str.compare(0, 7, "dayTemp") == 0) {
		str.erase(0, 7);

		int val = stoi(str);
		_terrariumController->setDayTemperature(val);
	}
	else if(str.compare(0, 9, "nightTemp") == 0) {
		str.erase(0, 9);

		int val = stoi(str);
		_terrariumController->setNightTemperature(val);
	}
}


/*
 * This method is from http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c
 */
vector<string> TerrariumServer::split(string str, char delimiter) {
	vector<string> result;
	stringstream ss(str);
	string tok;

	while(getline(ss, tok, delimiter)) {
		result.push_back(tok);
	}
	return result;
}
