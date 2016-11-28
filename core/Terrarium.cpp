#include "Terrarium.h"

int main() {
	// Run our program!
	printf("Beginning of Terrarium program..\n");

	// Setup
	TempHumiditySensor ths = TempHumiditySensor(I2CDRV_LINUX_BUS2, SHT31_DEFAULT_ADDR);

	float temp = ths.getTemperature();
	float hum = ths.getHumidity();

	printf("TEMP: %f -- HUM: %f\n", temp, hum);

	// // Setup thread attributes
	// pthread_attr_t attr;
	// pthread_t* tid = (pthread_t*)malloc(sizeof(*tid)*NUM_THREADS);
	// pthread_attr_init(&attr);

	// // Create threads
	// pthread_create(&tid[0], &attr, listener, NULL); 	// Server Thread

	// // Wait for threads to finish
	// for(int i = 0; i < NUM_THREADS; i++) {
	// 	pthread_join(tid[i], NULL);
	// }

	// free(tid);
	printf("Stopping Terrarium program..");
}
