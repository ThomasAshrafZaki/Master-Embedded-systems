//-----------------------------
#include "Algorithm.h"
#include "PressureSensor.h"
//-----------------------------

//variables
volatile unsigned int Pressure=0;
volatile unsigned int Threshold=20;
state_t state_alg=high_presseure_detection;

//-----------------------------

void set_pressure_val(int Pressure_Val){
	//recieve pressure value
	Pressure=Pressure_Val;
	//set the value of pointer
	ptr_Detection=state(high_presseure_detection);
}
//-----------------------------

state_fun(high_presseure_detection){
	//state name
	state_alg=high_presseure_detection;
	//check the high pressure
	if(Pressure>Threshold)
		high_pressure_detection();
	else
		ptr_Detection=state(high_presseure_detection);
}