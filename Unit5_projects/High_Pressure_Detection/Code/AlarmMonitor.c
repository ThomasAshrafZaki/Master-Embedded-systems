//-----------------------------
#include "Algorithm.h"
#include "AlarmMonitor.h"
//-----------------------------

//variables
state_t state_monitor=AlarmOff;

//-----------------------------

void high_pressure_detection(){
	//set the value of pointer
	ptr_Monitor=state(AlarmON);
}
//-----------------------------

state_fun(AlarmON){
	//state name
	state_monitor=AlarmON;
	//state action
	start_alarm();
	state_call(waiting);//call function
	stop_alarm();
	//return to idle
	ptr_Monitor=state(AlarmOff);
}

//-----------------------------

state_fun(AlarmOff){
	//state name
	state_monitor=AlarmOff;
	ptr_Monitor=state(AlarmOff);
}
state_fun(waiting){
	//wait 60s
	Delay(66666);
}