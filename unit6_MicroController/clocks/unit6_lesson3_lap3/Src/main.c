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
 * sysclk--->32 Mhz
 * Hclk--->32 Mhz
 * apb2--->8 Mhz
 * apb1--->16 Mhz
 *
 ******************************************************************************
 */


#include"stdio.h"
#include "platform_t.h"

#define GPIO_PA_base  0x40010800

#define   CRH_R      *(vuint32_t *)(0x40010800+0x04)
#define   ODR_R      *(vuint32_t *)(0x40010800+0x0C)

#define RCC_base      0x40021000

#define   RCC_APB2ENR      *(vuint32_t *)(0x40021000+0x18)
#define   RCC_CFGR         *(vuint32_t *)(0x40021000+0x04)
#define   RCC_CR         *(vuint32_t *)(0x40021000+0x0)
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
volatile accses_pins * CR=(volatile accses_pins *)(0x40021000+0x0);
int main(void)
{
	/*Bits 1:0 SW[1:0]: System clock Switch
	Set and cleared by software to select SYSCLK source.
	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of failure of
	the HSE oscillator used directly or indirectly as system clock (if the Clock Security System is
	enabled).
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock
	11: Not allowed*/

	//10: PLL selected as system clock
	CFGR->Spin.pin0=0;
	CFGR->Spin.pin1=1;
	//-----------------------


	/*Bit 16 PLLSRC: PLL entry clock source
	Set and cleared by software to select PLL clock source. This bit can be written only when PLL is
	disabled.
	0: HSI oscillator clock / 2 selected as PLL input clock
	1: Clock from PREDIV1 selected as PLL input clock
	Note: When changing the main PLL’s entry clock source, the original clock source must be switched
	off only after the selection of the new clock source.*/

	CFGR->Spin.pin16=0;//0: HSI oscillator clock / 2 selected as PLL input clock
	//-----------------------

	/*Bits 21:18 PLLMUL[3:0]: PLL multiplication factor
	These bits are written by software to define the PLL multiplication factor. They can be written only
	when PLL is disabled.
	000x: Reserved
	0010: PLL input clock x 4
	0011: PLL input clock x 5
	0100: PLL input clock x 6
	0101: PLL input clock x 7
	0110: PLL input clock x 8
	0111: PLL input clock x 9
	10xx: Reserved
	1100: Reserved
	1101: PLL input clock x 6.5
	111x: Reserved*/

	//i want 8/2=4 from hsi *8=32 sysclk
	//0110: PLL input clock x 8
	CFGR->Spin.pin18=0;
	CFGR->Spin.pin19=1;
	CFGR->Spin.pin20=1;
	CFGR->Spin.pin21=0;
	//-----------------------

	/*Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/

	//101: HCLK divided by 4
	// apb2--->8 Mhz
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
	//apb1--->16 Mhz
	CFGR->Spin.pin8=0;
	CFGR->Spin.pin9=0;
	CFGR->Spin.pin10=1;
	//-----------------------
	/*Bit 24 PLLON: PLL enable
		Set and cleared by software to enable PLL.
		Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
		PLL clock is used as system clock or is selected to become the system clock. Software
		must disable the USB OTG FS clock before clearing this bit.
		0: PLL OFF
		1: PLL ON*/
		CR->Spin.pin24=1;
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
