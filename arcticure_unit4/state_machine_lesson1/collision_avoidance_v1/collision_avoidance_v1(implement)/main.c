/*
 * main.c
 *
 *  Created on: Aug 3, 2024
 *      Author: thomas ashraf zaki
 */

#include"CA.h"


void setup()
{
	//init drivers
	//init IRQS
	//init hal---us_driver dc_motor_driver
	//init block
	//init pointer that point to fun
	CA_ptr=state(CA_waiting);
}
void main(void)
{
	setup();
	while(1)
	{
		CA_ptr();
	}
}

