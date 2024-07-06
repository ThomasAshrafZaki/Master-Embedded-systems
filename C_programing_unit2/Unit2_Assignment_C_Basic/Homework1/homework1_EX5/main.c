
/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	char character ;

	printf("Enter a character: ");
	fflush(stdin);     fflush(stdout);
	scanf("%c",&character);
	printf("ASCII value of %c = %d",character,character);
}



