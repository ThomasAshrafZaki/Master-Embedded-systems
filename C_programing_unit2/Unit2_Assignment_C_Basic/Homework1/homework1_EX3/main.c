/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	int num1=0,num2=0;

	printf("Enter two integer: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d %d",&num1,&num2);
	printf("Sum: %d",(num1+num2));
}
