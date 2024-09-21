#include "Alarm_Led.h"
#include "AlarmMonitor.h"
//variables
state_t state_Alarm=LedOn;
//-----------------------------
state_fun(init_Alarm){
	//set the value of pointer
	ptr_AlarmLed=state(idle);
}
//-----------------------------
state_fun(idle){
	//return here
}
//-----------------------------
void start_alarm(){
	//set the value of pointer
	state_call(LedOn);//call
}
//-----------------------------
void stop_alarm(){
	//set the value of pointer
	state_call(LedOff);//call
}
//-----------------------------
state_fun(LedOn){
	//state name
	state_Alarm=LedOn;
	//state action
	Set_Alarm_actuator(0);
	ptr_AlarmLed=state(idle);
}
//-----------------------------
state_fun(LedOff){
	//state name
	state_Alarm=LedOff;
	//state action
	Set_Alarm_actuator(1);
	Delay(10000);
	ptr_AlarmLed=state(idle);
}