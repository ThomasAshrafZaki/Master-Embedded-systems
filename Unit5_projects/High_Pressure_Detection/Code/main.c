//-----------------------------
#include "PressureSensor.h"
#include "Algorithm.h"
#include "AlarmMonitor.h"
#include "Alarm_Led.h"
#include "states.h"
#include "driver.h"
//-----------------------------

void setup(){
	//init GPIO
	GPIO_INITIALIZATION ();
	//init PressureSensor
	state_call(init_PS);
	//init ALARM
	state_call(init_Alarm);
	//init the pointers
	ptr_Detection=state(high_presseure_detection);
	ptr_Monitor=state(AlarmOff);
	Set_Alarm_actuator(1);
}
//-----------------------------

void main(void){
	//call setup
	setup();
	//loop
	while(1){
		ptr_PS();
		ptr_Detection();
		ptr_Monitor();
	}
}