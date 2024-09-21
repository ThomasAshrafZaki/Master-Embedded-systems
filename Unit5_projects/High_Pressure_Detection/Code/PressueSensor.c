//-----------------------------
#include "PressureSensor.h"
//-----------------------------

//variables
volatile unsigned int Pressure_Val=0;
state_t state_PS=reading_PS;

//-----------------------------

state_fun(init_PS){
	//set the value of pointer
	ptr_PS=state(reading_PS);
}
//-----------------------------

state_fun(reading_PS){
	//state name
	state_PS=reading_PS;
	//state action--->get the val of pressure
	Pressure_Val=getPressureVal();
	//state event 
	set_pressure_val(Pressure_Val);
	Delay(66666);
}