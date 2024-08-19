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

#endif /* PLATFORM_T_H_ */
