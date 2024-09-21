#ifndef _ALARM_MONITOR_
#define _ALARM_MONITOR_

#include "states.h"
#include "driver.h"
//-----------------------------
//funtions
state_fun(AlarmON);
state_fun(AlarmOff);
state_fun(waiting);
//-----------------------------
//Pointer To Function
void (*ptr_Monitor)();
//-----------------------------

#endif