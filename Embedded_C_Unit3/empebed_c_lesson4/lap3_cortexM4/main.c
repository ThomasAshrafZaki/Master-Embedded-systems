/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE

 ******************************************************************************
 */
#include"stdio.h"
#include "platform_t.h"

#define   SYSCTL_RCGC2_R     *(vuint32_t *)(0x400FE108)
#define   GPIO_PORTF_DIR_R   *(vuint32_t *)(0x40025400)   
#define   GPIO_PORTF_DEN_R   *(vuint32_t *)(0x4002551C) 
#define   GPIO_PORTF_DATA_R  *(vuint32_t *)(0x400253FC)  

int main(void)
{
	vuint32_t DELAY;
	SYSCTL_RCGC2_R =0X00000020;
	for(DELAY=0;DELAY<=200;DELAY++);
	GPIO_PORTF_DIR_R |=1<<3;
	GPIO_PORTF_DEN_R |=1<<3;
	while(1)
	{
		GPIO_PORTF_DATA_R |=1<<3;		
		for(int x=0;x<=400000;x++);
		GPIO_PORTF_DATA_R &=~(1<<3);		
		for(int x=0;x<=400000;x++);
	}
}
