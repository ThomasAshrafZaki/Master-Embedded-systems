/* main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: thomas ashraf
 */


/*ATMEGA32
 *
 * this program used INT0 , INT1 ,INT2 to make interrupt to turn led for 1s
 *
 *   */

#include "stdio.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include "avr/delay.h"

//base address
#define   io_base     0x20
//EXTI
#define   GICR      *(volatile unsigned int *)(io_base+0x3B)//to enable the external bit interrupt
#define   GIFR      *(volatile unsigned int *)(io_base+0x3A)//to enable flag that clear directly
#define   MCUCSR     *(volatile unsigned int *)(io_base+0x34)//to detect edge INT2
#define   MCUCR      *(volatile unsigned int *)(io_base+0x35)//to detect edge INT0 , INT1


//AVR CPU
#define   SREG      *(volatile unsigned int *)(0x3F)//enable global interrupt

#define F_CPU 8000000ul

void IOPorts_INIT(void){
	// portD pin5 output--->led
	DDRD |=(1<<5);
	// portD pin6 output--->led
	DDRD |=(1<<6);
	// portD pin7 output--->led
	DDRD |=(1<<7);
	// portD pin2 input--->button
	DDRD &=~(1<<2);//--->INT0
	// portD pin3 input--->button
	DDRD &=~(1<<3);//--->INT1
	// portB pin2 input--->button
	DDRB &=~(1<<2);//--->INT2
}
void main(void){
	IOPorts_INIT();
	sei();
	//detect any logical change to INT0
	MCUCR |=(1<<0);
	//detect any rising edge to INT1
	MCUCR |=(1<<2);
	MCUCR |=(1<<3);
	//detect any falling edge to INT2
	MCUCSR &=~(1<<6);
	//enable PA0 to INT0
	GICR |=(1<<6);
	//enable PA0 to INT1
	GICR |=(1<<7);
	//enable PA0 to INT2
	GICR |=(1<<5);


	while(1){
		PORTD &=~(1<<5);
		PORTD &=~(1<<6);
		PORTD &=~(1<<7);
	}
}
ISR(INT0_vect){
	//turn on led in portD pin5
	PORTD |=(1<<5);
	//wait 1s
	_delay_ms(1000);
}
ISR(INT1_vect){
	//turn on led in portD pin6
	PORTD |=(1<<6);
	//wait 1s
	_delay_ms(1000);
}
ISR(INT2_vect){
	//turn on led in portD pin7
	PORTD |=(1<<7);
	//wait 1s
	_delay_ms(1000);
}
