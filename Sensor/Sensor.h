#ifndef __SENSOR_H
#define __SENSOR_H

#include "sys.h"


#define P1          DL_GPIO_readPins(Sensor_P1_PORT,Sensor_P1_PIN)
#define P2          DL_GPIO_readPins(Sensor_P2_PORT,Sensor_P2_PIN)
#define P3          DL_GPIO_readPins(Sensor_P3_PORT,Sensor_P3_PIN)
#define P4          DL_GPIO_readPins(Sensor_P4_PORT,Sensor_P4_PIN)
#define P5          DL_GPIO_readPins(Sensor_P5_PORT,Sensor_P5_PIN)
#define P6          DL_GPIO_readPins(Sensor_P6_PORT,Sensor_P6_PIN)
#define P7          DL_GPIO_readPins(Sensor_P7_PORT,Sensor_P7_PIN)
#define P8          DL_GPIO_readPins(Sensor_P8_PORT,Sensor_P8_PIN)



int Follow_Route(void);
int Follow_Route_Mode3(int stop);
int Follow_Route_Mode4(void);

int Incremental_Quantity(void);
int Incremental_Quantity3(void);
int Incremental_Quantity4(void);
#endif
