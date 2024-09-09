/**
 ******************************************************************************
 * @file           : main.c
 * @author         : thomas ashraf zaki
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software used to toggle led by manage gpio input pins
 ******************************************************************************
 */

#include"stdio.h"
#include "platform_t.h"

//GPIOA
#define GPIO_PA_base  0x40010800
#define   CRH_R_PA      *(vuint32_t *)(GPIO_PA_base+0x04)
#define   CRL_R_PA      *(vuint32_t *)(GPIO_PA_base+0x0)
#define   ODR_R_PA      *(vuint32_t *)(GPIO_PA_base+0x0C)
#define   IDR_R_PA      *(vuint32_t *)(GPIO_PA_base+0x08)


//GPIOB
#define GPIO_PB_base  0x40010C00
#define   CRH_R_PB      *(vuint32_t *)(GPIO_PB_base+0x04)
#define   CRL_R_PB      *(vuint32_t *)(GPIO_PB_base+0x0)
#define   ODR_R_PB      *(vuint32_t *)(GPIO_PB_base+0x0C)
#define   IDR_R_PB      *(vuint32_t *)(GPIO_PB_base+0x08)


//RCC
#define RCC_base      0x40021000
#define RCC_APB2ENR      *(vuint32_t *)(RCC_base+0x18)

void GPIO_INIT(void){
	CRL_R_PA=0x0;
	CRL_R_PB=0x0;
	CRH_R_PA=0x0;
	CRH_R_PB=0x0;
	//pA1--->input
	//00: Input mode (reset state)
	//01: Floating input (reset state)
	CRL_R_PA |=((0b00)<<4);
	CRL_R_PA |=((0b01)<<6);
	//pB1--->output
	//00: General purpose output push-pull
	//01: Output mode, max speed 10 MHz.
	CRL_R_PB |=((0b01)<<4);
	CRL_R_PB |=((0b00)<<6);
	//pA13--->input
	//00: Input mode (reset state)
	//01: Floating input (reset state)
	CRH_R_PA |=((0b00)<<20);
	CRH_R_PA |=((0b01)<<22);
	//pB13--->output
	//00: General purpose output push-pull
	//01: Output mode, max speed 10 MHz.
	CRH_R_PB |=((0b01)<<20);
	CRH_R_PB |=((0b00)<<22);
}
void CLOCK_INIT(void){
	//enable clock on portA
	RCC_APB2ENR |=1<<2;
	//enable clock on portB
	RCC_APB2ENR |=1<<3;
}
void wait(int x){
	for(unsigned int i=0;i<x;i++)
		for(unsigned int j=0;j<255;j++);
}
void main(void){
	CLOCK_INIT();
	GPIO_INIT();
	while(1){
		//check if the button in portA pin1 is==0(external pull up)
		if((IDR_R_PA &(1<<1))>>1==0)//i will make mask to this register to access pin (the total value not changed becouse this mask in if condition)
		{
			//toggle to led in PB1
			ODR_R_PB ^=(1<<1);
			//check if you still press(signal pressing)
			while((IDR_R_PA &(1<<1))>>1==0);
		}
		//check if the button in portA pin13 is==1(external pull down)
		if((IDR_R_PA &(1<<13))>>13==1)//i will make mask to this register to access pin (the total value not changed becouse this mask in if condition)
		{
			//toggle to led in PB13
			ODR_R_PB ^=(1<<13);
			//(multi pressing)
		}
		wait(1);
	}
}
