/*
 * state.h
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#ifndef STATE_H_
#define STATE_H_

//state functions (macros)
#define state_CAfun_(_CAfun_)    void  ST_##_CAfun_() //##to connect st with parameter as a name of fun
#define state(_CAfun_)       ST_##_CAfun_

#endif /* STATE_H_ */
