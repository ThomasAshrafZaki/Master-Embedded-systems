/*
 * DC.c
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#include "stdio.h"
#include "stdlib.h"
#include "DC.h"
#include "platform_t.h"
//variables
vuint32_t DC_speed=0;
DC_state_id DC_CurrentState=DC_idle;

//pointer to fun
void(*DC_ptr)();

void DC_init(){

	printf("\n init_DC");
}

void set_speed(int speed){
	DC_speed=speed;
	printf("\n CA-----send speed=%d------->---to DC",DC_speed);
	DC_ptr=state(DC_busy);
}
// state functions definition
state_fun_(DC_idle)
{
	//state name
	DC_CurrentState=DC_idle;
	printf("\n the motor in idle state ----- speed = %d",DC_speed);
	//state action
	//state event //state transition
}
state_fun_(DC_busy)
{
	//state name
	DC_CurrentState=DC_busy;
	//state action
	printf("\n the motor in busy state ----- speed = %d",DC_speed);
	//state event //state transition
	DC_ptr=state(DC_idle);//to loop to idle but in fact it not go to it because when us send again ,DC_ptr = state(DC_busy);(just do this like state machine)

}



