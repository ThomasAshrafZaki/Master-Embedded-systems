/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software used to toggle led by manage clock input
 * apb2--->2 Mhz
 * apb1--->4 Mhz
 ******************************************************************************
 */

#include"stdio.h"
#include "platform_t.h"

#define GPIO_PA_base  0x40010800

#define   CRH_R      *(vuint32_t *)(0x40010800+0x04)
#define   ODR_R      *(vuint32_t *)(0x40010800+0x0C)

#define RCC_base      0x40021000

#define   RCC_APB2ENR      *(vuint32_t *)(0x40021000+0x18)
#define   RCC_CFGR         *(vuint32_t *)(0x40021000+0x04)//to control clock in APB2,APB1

typedef union {
	vuint32_t allpins ;
	volatile struct
	{
		vuint32_t reserved:13;
		vuint32_t pin13:1;
	}Spin;
}register_accses;

volatile accses_pins * CFGR =(volatile accses_pins *)(0x40021000+0x04);
volatile accses_pins * ODR=(volatile accses_pins *)(0x40010800+0x0C);

int main(void)
{
	/*Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	//101: HCLK divided by 4
	// apb2--->2 Mhz
	CFGR->Spin.pin11=1;
	CFGR->Spin.pin12=0;
	CFGR->Spin.pin13=1;
	//-----------------------
	/*Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	//100: HCLK divided by 2
	//apb1--->4 Mhz
	CFGR->Spin.pin8=0;
	CFGR->Spin.pin9=0;
	CFGR->Spin.pin10=1;
	//-----------------------
	//enable clock on porta
	RCC_APB2ENR |=1<<2;
	CRH_R &=0xff0fffff;
	CRH_R |=0x00200000;
	while(1)
	{
		//ODR_R |=1<<13;
		ODR->Spin.pin13=1;
		for(int x=0;x<=100000;x++);
		//ODR_R &=~(1<<13);s
		ODR->Spin.pin13=0;
		for(int x=0;x<=100000;x++);
	}
}
