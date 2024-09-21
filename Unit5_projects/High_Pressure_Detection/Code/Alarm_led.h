#ifndef _ALARM_LED_
#define _ALARM_LED_

#include "states.h"
#include "driver.h"
//-----------------------------
//funtions
state_fun(init_Alarm);
state_fun(LedOn);
state_fun(LedOff);
state_fun(idle);
//-----------------------------
//Pointer To Function
void (*ptr_AlarmLed)();
//-----------------------------
#endif