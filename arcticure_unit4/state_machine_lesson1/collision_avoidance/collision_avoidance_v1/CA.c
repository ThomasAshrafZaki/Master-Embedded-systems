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
CA_state_id CurrentState=CA_waiting;

//pointer to fun
void(*CA_ptr)();

// state functions definition
state_CAfun_(CA_waiting)
{
	//state name
	CurrentState=CA_waiting;
	//state action
	CA_speed=0;
	//state event //state transition
	CA_distance=CA_get_distance_random(45,55);//to get a random value of distance
	(CA_distance<=CA_threshold)?(CA_ptr=state(CA_waiting)):(CA_ptr=state(CA_driving));
	printf("\n the car in waiting state with distance = %d & speed = %d ",CA_distance,CA_speed);
}
state_CAfun_(CA_driving)
{
	//state name
	CurrentState=CA_driving;
	//state action
	CA_speed=30;
	//state event //state transition
	CA_distance=CA_get_distance_random(45,55);//to get a random value of distance
	(CA_distance<=CA_threshold)?(CA_ptr=state(CA_waiting)):(CA_ptr=state(CA_driving));
	printf("\n the car in driving state with distance = %d & speed = %d ",CA_distance,CA_speed);
}

//function that get a random num
int CA_get_distance_random(int min,int max)
{

		int rand_num =(rand() % (max-min+1))+min;
		return rand_num;
}

