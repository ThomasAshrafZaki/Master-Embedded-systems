/*
 * state.h
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#ifndef STATE_H_
#define STATE_H_

//state functions (macros)
#define state_fun_(_type_)    void  ST_##_type_() //##to connect st with parameter as a name of fun
#define state(_type_)       ST_##_type_

//funtionS transactions
void set_distance(int distance);
void set_speed(int speed);

#endif /* STATE_H_ */
