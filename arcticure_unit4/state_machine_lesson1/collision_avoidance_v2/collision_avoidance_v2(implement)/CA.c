/*
 * CA.c
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#include "stdio.h"
#include "stdlib.h"
#include "CA.h"
#include "platform_t.h"
//variables
vuint32_t CA_speed=0;
vuint32_t CA_distance=0;
vuint32_t CA_threshold=50;
CA_state_id CA_CurrentState=CA_waiting;

//pointer to fun
void(*CA_ptr)();

void set_distance(int distance){
	CA_distance=distance;
	printf("\n US-----send distance=%d------->---to CA",CA_distance);
	//event
	if(CA_distance<=CA_threshold){
			(CA_ptr=state(CA_waiting));
		}

		else{
			(CA_ptr=state(CA_driving));
		}
}
// state functions definition
state_fun_(CA_waiting)
{
	//state name
	CA_CurrentState=CA_waiting;
	printf("\n the car in waiting state ----- distance = %d",CA_distance);
	//state action
	CA_speed=0;
	//call DC Motor
	set_speed(CA_speed);

}
state_fun_(CA_driving)
{
	//state name
	CA_CurrentState=CA_driving;
	printf("\n the car in driving state ----- distance = %d",CA_distance);
	//state action
	CA_speed=30;
	//call DC Motor
	set_speed(CA_speed);
}


