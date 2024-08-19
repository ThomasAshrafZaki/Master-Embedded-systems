/*
 * US.h
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#ifndef US_H_
#define US_H_

#include "state.h"
// states id
typedef enum {
	US_busy
}US_state_id;

// state functions
state_fun_(US_busy);
//to init all drivers
void US_init();
//function that give a random num
int US_get_distance_random(int min,int max);
//pointer to fun
extern void(*US_ptr)();


#endif /* US_H_ */
