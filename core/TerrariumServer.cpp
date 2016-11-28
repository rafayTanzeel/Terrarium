#include "TerrariumServer.h"

void* listener(void* arg){
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

void returnPacket(char* message) {
	//TODO: return packets sent from node.js
}