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
#include "STM32_F103C6_gpio_driver.h"
#include "STM32_F103x6.h"

void GPIO_INIT(void){
	GPIO_pin_config_t *PinConfig;
	//pA1--->input
	//00: Input mode (reset state)
	//01: Floating input (reset state)
	PinConfig->GPIO_mode=GPIO_mode_Input_FLO;
	PinConfig->GPIO_pin_number=GPIO_pin_1;
	MCAL_GPIO_Init(GPIOA, PinConfig);
	//pB1--->output
	//00: General purpose output push-pull
	//01: Output mode, max speed 10 MHz.
	PinConfig->GPIO_mode=GPIO_mode_output_PP;
	PinConfig->GPIO_pin_number=GPIO_pin_1;
	PinConfig->GPIO_speed=GPIO_speed_10_MHz;
	MCAL_GPIO_Init(GPIOB, PinConfig);
	//pA13--->input
	//00: Input mode (reset state)
	//01: Floating input (reset state)
	PinConfig->GPIO_mode=GPIO_mode_Input_FLO;
	PinConfig->GPIO_pin_number=GPIO_pin_13;
	MCAL_GPIO_Init(GPIOA, PinConfig);
	//pB13--->output
	//00: General purpose output push-pull
	//01: Output mode, max speed 10 MHz.
	PinConfig->GPIO_mode=GPIO_mode_output_PP;
	PinConfig->GPIO_pin_number=GPIO_pin_13;
	PinConfig->GPIO_speed=GPIO_speed_10_MHz;
	MCAL_GPIO_Init(GPIOB, PinConfig);
}
void CLOCK_INIT(void){
	//enable clock on portA
	RCC_GPIOA_Clock_EN();
	//enable clock on portB
	RCC_GPIOB_Clock_EN();
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
		if((MCAL_GPIO_ReadPin(GPIOA, GPIO_pin_1)==(vuint8_t)0))//i will make mask to this register to access pin (the total value not changed becouse this mask in if condition)
		{
			//toggle to led in PB1
			MCAL_GPIO_TogglePin(GPIOB, GPIO_pin_1);
			//check if you still press(signal pressing)
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_pin_1)==(vuint8_t)0);
		}
		//check if the button in portA pin13 is==1(external pull down)
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_pin_13)==(vuint8_t)1)//i will make mask to this register to access pin (the total value not changed becouse this mask in if condition)
		{
			//toggle to led in PB13
			MCAL_GPIO_TogglePin(GPIOB, GPIO_pin_13);
			//(multi pressing)
		}
		wait(1);
	}
}
