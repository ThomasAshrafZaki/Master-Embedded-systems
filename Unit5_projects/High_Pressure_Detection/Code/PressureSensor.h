
#ifndef _PRESSURE_SENSOR_
#define _PRESSURE_SENSOR_

#include "states.h"
#include "driver.h"
//-----------------------------
//funtions
state_fun(init_PS);
state_fun(reading_PS);
//-----------------------------
//Pointer To Function
void (*ptr_PS)();
//-----------------------------
#endif