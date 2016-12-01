#ifndef TYPES_H
#define TYPES_H

#define I2C_BUS_1 "/dev/i2c-1"
#define I2C_BUS_2 "/dev/i2c-2"

struct Time 
{
    int hours, minutes, seconds;
};

struct LightParms
{
    int light;
    bool useAnalogLEDs;
};


#endif
