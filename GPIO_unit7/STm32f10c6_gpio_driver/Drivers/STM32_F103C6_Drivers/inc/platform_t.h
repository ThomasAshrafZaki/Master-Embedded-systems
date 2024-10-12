/*
 * platform_t.h
 *
 *  Created on: Jul 4, 2024
 *      Author: Thomas Ashraf Zaki
 */

#ifndef PLATFORM_T_H_
#define PLATFORM_T_H_

#include <stdio.h>
#include <stdint.h>


#ifndef _Bool
#define _Bool unsigned char
#endif


#define CPU_TYPE				CPU_TYPE_32
#define	CPU_BIT_ORDER			LSB_FIRST
#define	CPU_BYTE_ORDER			LOW_BYTE_FIRST


#ifndef FALSE
#define FALSE                   (boolean)false  //(unsigned char for false=(int variable =0))
#endif

#ifndef TRUE
#define TRUE                    (boolean)true    //(unsigned char for true=(int variable =1))
#endif


#ifndef types
#define types

typedef _Bool   boolean;

typedef unsigned char        uint8;
typedef unsigned short       uint16;
typedef unsigned int         uint32;
typedef unsigned long long   uint64;
typedef volatile unsigned char        vuint8_t;
typedef volatile unsigned short       vuint16_t;
typedef volatile unsigned int         vuint32_t;
typedef volatile unsigned long long   vuint64_t;

typedef signed char        sint8;
typedef signed short       sint16;
typedef signed int         sint32;
typedef signed long long   sint64;
typedef volatile signed char        vsint8_t;
typedef volatile signed short       vsint16_t;
typedef volatile signed int         vsint32_t;
typedef volatile signed long long   vsint64_t;

#endif

#ifndef accses_pin
#define accses_pin
typedef union {
	vuint32_t allpins ;
	volatile struct
	{
		vuint32_t pin0:1;
		vuint32_t pin1:1;
		vuint32_t pin2:1;
		vuint32_t pin3:1;
		vuint32_t pin4:1;
		vuint32_t pin5:1;
		vuint32_t pin6:1;
		vuint32_t pin7:1;
		vuint32_t pin8:1;
		vuint32_t pin9:1;
		vuint32_t pin10:1;
		vuint32_t pin11:1;
		vuint32_t pin12:1;
		vuint32_t pin13:1;
		vuint32_t pin14:1;
		vuint32_t pin15:1;
		vuint32_t pin16:1;
		vuint32_t pin17:1;
		vuint32_t pin18:1;
		vuint32_t pin19:1;
		vuint32_t pin20:1;
		vuint32_t pin21:1;
		vuint32_t pin22:1;
		vuint32_t pin23:1;
		vuint32_t pin24:1;
		vuint32_t pin25:1;
		vuint32_t pin26:1;
		vuint32_t pin27:1;
		vuint32_t pin28:1;
		vuint32_t pin29:1;
		vuint32_t pin30:1;
		vuint32_t pin31:1;
	}Spin;
}accses_pins;
#endif

#endif /* PLATFORM_T_H_ */
