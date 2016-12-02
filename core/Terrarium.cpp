#include "Terrarium.h"

#include "controllers/TerrariumController.h"
#include "controllers/ClimateController.h"
#include "controllers/LightController.h"

#include "modules/TempHumiditySensor.h"
#include "modules/ColorSensor.h"
#include "modules/LightSensor.h"
#include "modules/Fan.h"
#include "modules/PWMLightStrip.h"
#include "modules/RGBLightStrip.h"
#include "modules/Relay.h"
#include "modules/WaterSensor.h"


int main() {
	// Run our program!
	printf("Beginning of Terrarium program..\n");

	TerrariumController terrariumController = buildTerrariumController();
	
	// Setup thread attributes
	pthread_attr_t attr;
	pthread_t* tid = (pthread_t*)malloc(sizeof(*tid)*NUM_THREADS);
	pthread_attr_init(&attr);

	// Create threads
	pthread_create(&tid[0], &attr, TerrariumServer::listener, (void*)&terrariumController); 	// Server Thread

	// Run Terrarium controller
	terrariumController.run();

	// Wait for threads to finish
	for(int i = 0; i < NUM_THREADS; i++) {
		pthread_join(tid[i], NULL);
	}

	free(tid);
	
	
	printf("Stopping Terrarium program..\n");
}


TerrariumController buildTerrariumController()
{
    Fan* exhaustFan = new Fan(22, 4200);
    Fan* intakeFan = new Fan(23, 4200);
    Fan* circulationFan = new Fan(51, 1400);
    
    Relay* fogger = new Relay(115, false);
    Relay* cooler = new Relay(117, false);
    TempHumiditySensor* tempHumiditySensor = new TempHumiditySensor(I2C_BUS_2, SHT31_DEFAULT_ADDR);
    WaterSensor* waterSensor = new WaterSensor(0);
    
	ClimateController* climateController = new ClimateController(exhaustFan, intakeFan, circulationFan, fogger, cooler, tempHumiditySensor, waterSensor);
	

	ColorSensor* colorSensor = new ColorSensor(I2C_BUS_1, TCS34725_ADDRESS);
	LightSensor* lightSensor = new LightSensor(I2C_BUS_2, TSL2591_ADDR);
	RGBLightStrip* rgbLightStrip = new RGBLightStrip();
	PWMLightStrip* pwmLightStrip = new PWMLightStrip(50);
	
	LightController* lightController = new LightController(colorSensor, lightSensor, rgbLightStrip, pwmLightStrip);

    return TerrariumController(climateController, lightController);
}



