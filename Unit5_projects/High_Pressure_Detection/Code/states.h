
#ifndef _STATES_H
#define _STATES_H
//-----------------------------
//states 
typedef enum 
{
	//states of pressure detection
	init_PS,
	reading_PS,
	//state of algorithm
	high_presseure_detection,
	//states of monitor
	AlarmON,
	AlarmOff,
	waiting,
	//states of alarmDriver
	init_Alarm,
	idle,
	LedOn,
	LedOff
}state_t;
//-----------------------------
//state functions (macros)
#define state_fun(_type_)  	 void ST_##_type_()
#define state(_type_)  	   	 ST_##_type_
#define state_call(_type_) 	 ST_##_type_()
//-----------------------------
//function of transifer signals
void set_pressure_val(int pressure_val);
void high_pressure_detection();
void start_alarm();
void stop_alarm();
//-----------------------------
#endif