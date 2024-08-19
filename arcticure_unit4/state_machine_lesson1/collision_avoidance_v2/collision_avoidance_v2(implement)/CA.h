/*
 * CA.h
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
// states id
typedef enum {
	CA_waiting,
	CA_driving
}CA_state_id;

// state functions
state_fun_(CA_waiting);
state_fun_(CA_driving);

//pointer to fun
extern void(*CA_ptr)();


#endif /* CA_H_ */
