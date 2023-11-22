/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	float num1=0,num2=0;

	printf("Enter two numbers: ");
	fflush(stdin);     fflush(stdout);
	scanf("%f %f",&num1,&num2);
	printf("Sum: %f",(num1+num2));
}



