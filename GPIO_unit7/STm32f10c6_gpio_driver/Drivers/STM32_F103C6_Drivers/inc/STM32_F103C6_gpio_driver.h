/*
 * STM32_F103C6_gpio_driver.h
 *
 *  Created on: Sep 23, 2024
 *      Author: Office
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include  "STM32_F103x6.h"
//=========================================
//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct {
	vuint16_t GPIO_pin_number;//specifies the number of pin in GPIO to be configuration
							// must used the value @ref GPIO_pin_define
	vuint8_t  GPIO_mode;     //specifies the mode of pin in GPIO to be configuration
							// must used the value @ref GPIO_mode_define
	vuint8_t  GPIO_speed;    //specifies the speed of pin in GPIO to be configuration
							// must used the value @ref GPIO_speed_define
}GPIO_pin_config_t;
//=========================================
//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_pin_define
#define    GPIO_pin_0     (vuint16_t)(1<<0)	 //0x0001  /*pin0 selected*/
#define    GPIO_pin_1     (vuint16_t)(1<<1)	 //0x0002  /*pin1 selected*/
#define    GPIO_pin_2     (vuint16_t)(1<<2)	 //0x0004  /*pin2 selected*/
#define    GPIO_pin_3     (vuint16_t)(1<<3)	 //0x0008  /*pin3 selected*/
#define    GPIO_pin_4     (vuint16_t)(1<<4)	 //0x0010  /*pin4 selected*/
#define    GPIO_pin_5     (vuint16_t)(1<<5)	 //0x0020  /*pin5 selected*/
#define    GPIO_pin_6     (vuint16_t)(1<<6) 	 //0x0040  /*pin6 selected*/
#define    GPIO_pin_7     (vuint16_t)(1<<7)	 //0x0080  /*pin7 selected*/
#define    GPIO_pin_8     (vuint16_t)(1<<8) 	 //0x0100  /*pin8 selected*/
#define    GPIO_pin_9     (vuint16_t)(1<<9) 	 //0x0200  /*pin8 selected*/
#define    GPIO_pin_10    (vuint16_t)(1<<10)  //0x0400 /*pin10 selected*/
#define    GPIO_pin_11    (vuint16_t)(1<<11)  //0x0800 /*pin11 selected*/
#define    GPIO_pin_12    (vuint16_t)(1<<12)  //0x1000 /*pin12 selected*/
#define    GPIO_pin_13    (vuint16_t)(1<<13)  //0x2000 /*pin13 selected*/
#define    GPIO_pin_14    (vuint16_t)(1<<14)  //0x4000 /*pin14 selected*/
#define    GPIO_pin_15    (vuint16_t)(1<<15)  //0x8000 /*pin15 selected*/
#define    GPIO_pin_ALL   (vuint16_t)(0xFFFF) //0x0001/*ALL pins selected*/
#define    GPIO_pin_MASK  0x0000FFFF         //0x0001 /*MASK pins to test*/

//@ref GPIO_mode_define
/*
0: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with pull-down
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function input
 */
#define    GPIO_mode_Analog     	0x00000000u 	   /*Analog mode selected*/
#define    GPIO_mode_Input_FLO   	0x00000001u 	   /*Floating input selected*/
#define    GPIO_mode_Input_PU   	0x00000002u 	   /*Input with pull-up selected*/
#define    GPIO_mode_Input_PD   	0x00000003u 	   /*Input with pull-down selected*/
#define    GPIO_mode_output_PP      0x00000004u 	   /*Alternate function output Push-pull selected*/
#define    GPIO_mode_output_OD      0x00000005u 	   /*Alternate function output Open-drain selected*/
#define    GPIO_mode_AF_output_PP   0x00000006u 	   /*Alternate function output Push-pull selected*/
#define    GPIO_mode_AF_output_OD   0x00000007u 	   /*Alternate function output Open-drain selected*/
#define    GPIO_mode_AF_input       0x00000008u  	   /*Alternate function input selected*/

//@ref GPIO_speed_define
/*
1: Output mode, max speed 10 MHz.
2: Output mode, max speed 2  MHz.
3: Output mode, max speed 50 MHz.
 */
#define    GPIO_speed_10_MHz     	0x00000001u 	   /*Output mode, max speed 10 MHz selected*/
#define    GPIO_speed_2_MHz   	    0x00000002u 	   /*Output mode, max speed 2 MHz selected*/
#define    GPIO_speed_50_MHz   	    0x00000003u 	   /*Output mode, max speed 50 MHz selected*/

//@ref GPIO_ReadPin_state
#define    GPIO_ReadPin_set   	    0x00000001u 	   /*Read from pin 0*/
#define    GPIO_ReadPin_reset  	    0x00000000u	   /*Read from pin 1*/

//@ref GPIO_Lockpin_state
#define    GPIO_Lockpin_ok   	    0x00000001u 	   /*lock is successful*/
#define    GPIO_Lockpin_error  	    0x00000000u 	   /*lock failed */

//=========================================
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_GPIO_Init  (GPIO_Register_t* GPIOx ,GPIO_pin_config_t * PinConfig);
void MCAL_GPIO_DeInit(GPIO_Register_t* GPIOx);

vuint8_t MCAL_GPIO_ReadPin(GPIO_Register_t* GPIOx,vuint16_t PinNumber);
vuint16_t MCAL_GPIO_ReadPort(GPIO_Register_t* GPIOx);

void MCAL_GPIO_WritePin(GPIO_Register_t* GPIOx,vuint16_t PinNumber,vuint8_t value);
void MCAL_GPIO_WritePort(GPIO_Register_t* GPIOx,vuint16_t value);

void MCAL_GPIO_TogglePin(GPIO_Register_t* GPIOx,vuint16_t PinNumber);

vuint8_t MCAL_GPIO_LockPin(GPIO_Register_t* GPIOx,vuint16_t PinNumber);

//=========================================
#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
