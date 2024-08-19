/*
 * main.c
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#include"CA.h"
#include"DC.h"
#include"US.h"
void setup()
{
	//init drivers
	//init IRQS
	//init hal---us_driver dc_motor_driver
	//init block
	//init pointer that point to fun
	US_init();
	DC_init();
	CA_ptr=state(CA_waiting);
	US_ptr=state(US_busy);
	DC_ptr=state(DC_idle);
}
void main(void)
{
	setup();
	while(1)
	{
		US_ptr();
		CA_ptr();
		DC_ptr();
	}
}

