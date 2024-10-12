/*
 * STM32_F103x6.h
 *
 *  Created on: Sep 23, 2024
 *      Author: Office
 */

#ifndef INC_STM32_F103X6_H_
#define INC_STM32_F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include "stdio.h"
#include "platform_t.h"
//================================================================================
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_Base_Address             							0x08000000UL//unsigned long
#define SystemMemory_Base_Address           					0x1FFFF000UL

#define SRAM_Base_Address             						    0x20000000UL

#define Peripherals_Base_Address           					    0x40000000UL

#define Cortex_M3_Internal_Peripherals_Base_Address             0xE0000000UL
//================================================================================
//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//GPIO
//A,B fully included in  LQFP48 package
#define GPIOA_Base_Address             						    0x40010800UL
#define GPIOB_Base_Address             						    0x40010C00UL
//C,D partial included in  LQFP48 package
#define GPIOC_Base_Address             						    0x40011000UL
#define GPIOD_Base_Address             						    0x40011400UL
//E not included in  LQFP48 package
#define GPIOE_Base_Address             						    0x40011800UL

//EXTI
#define EXTI_Base_Address             						    0x40010400UL

//AFIO
#define AFIO_Base_Address             						    0x40010000UL
//================================================================================
//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------
//================================================================================
//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
//RCC
#define RCC_Base_Address             						    0x40021000UL
//================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register
//-*-*-*-*-*-*-*-*-*-*-*

//GPIO
typedef struct {
	vuint32_t CRL;
	vuint32_t CRH;
	vuint32_t IDR;
	vuint32_t ODR;
	vuint32_t BSRR;
	vuint32_t BRR;
	vuint32_t LCKR;
}GPIO_Register_t;

//AFIO
typedef struct {
	vuint32_t EVCR;
	vuint32_t MAPR;
	vuint32_t EXTICR1;
	vuint32_t EXTICR2;
	vuint32_t EXTICR3;
	vuint32_t EXTICR4;//0x14
	vuint32_t Reserved0;//0x18
	vuint32_t MAPR2;//0x1C
}AFIO_Register_t;

//EXTI
typedef struct {
	vuint32_t IMR;
	vuint32_t EMR;
	vuint32_t RTSR;
	vuint32_t FTSR;
	vuint32_t SWIER;
	vuint32_t PR;
}EXTI_Register_t;

//RCC
typedef struct {
	vuint32_t CR;
	vuint32_t CFGR;
	vuint32_t CIR;
	vuint32_t APB2RSTR;
	vuint32_t APB1RSTR;
	vuint32_t AHBENR;
	vuint32_t APB2ENR;
	vuint32_t APB1ENR;
	vuint32_t BDCR;
	vuint32_t CSR;
}RCC_Register_t;

//====================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define   GPIOA            ((GPIO_Register_t*)(GPIOA_Base_Address))
#define   GPIOB            ((GPIO_Register_t*)(GPIOB_Base_Address))
#define   GPIOC            ((GPIO_Register_t*)(GPIOC_Base_Address))
#define   GPIOD            ((GPIO_Register_t*)(GPIOD_Base_Address))
#define   GPIOE            ((GPIO_Register_t*)(GPIOE_Base_Address))

#define   RCC              ((RCC_Register_t*)(RCC_Base_Address))

#define   AFIO             ((AFIO_Register_t*)(AFIO_Base_Address))

#define   EXTI             ((EXTI_Register_t*)(EXTI_Base_Address))
//====================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_Clock_EN()    (RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_Clock_EN()    (RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_Clock_EN()    (RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_Clock_EN()    (RCC->APB2ENR |=1<<5)
#define RCC_GPIOE_Clock_EN()    (RCC->APB2ENR |=1<<6)

#define RCC_AFIO_Clock_EN()    (RCC->APB2ENR |=1<<0)

//====================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif /* INC_STM32_F103X6_H_ */
