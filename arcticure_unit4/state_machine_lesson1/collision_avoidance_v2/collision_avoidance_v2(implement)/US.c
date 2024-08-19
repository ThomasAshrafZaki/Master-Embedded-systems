/*
 * US.c
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#include "stdio.h"
#include "stdlib.h"
#include "US.h"
#include "platform_t.h"
//variables
vuint32_t US_distance=0;
vuint32_t US_threshold=50;
US_state_id US_CurrentState=US_busy;

//pointer to fun
void(*US_ptr)();

void US_init(){

	printf("\n init_US");
}
// state functions definition
state_fun_(US_busy)
{
	//state name
	US_CurrentState=US_busy;
	//state action
	US_distance=US_get_distance_random(40,55);
	//state event //state transition
	set_distance(US_distance);
	US_ptr=state(US_busy);
}
//function that get a random num
int US_get_distance_random(int min,int max)
{

		int rand_num =(rand() % (max-min+1))+min;
		return rand_num;
}

