/*
 * DC.h
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
// states id
typedef enum {
	DC_idle,
	DC_busy
}DC_state_id;

// state functions
state_fun_(DC_idle);
state_fun_(DC_busy);
//to init all drivers
void DC_init();

//pointer to fun
extern void(*DC_ptr)();


#endif /* DC_H_ */
