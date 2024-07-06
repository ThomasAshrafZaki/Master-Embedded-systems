/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	int num=0;

	printf("Enter a integer: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&num);
	printf("You entered: %d",num);
}
