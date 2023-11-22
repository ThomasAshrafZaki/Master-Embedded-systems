/* main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	char character;

	printf("Enter a character :");
	fflush(stdin);     fflush(stdout);
	scanf("%c",&character);
	if (((int)character>=65 && (int)character<=90)||((int)character>=97 && (int)character<=122))
	{
		printf("%c is an alphabet",character);
	}
	else
		printf("%c is Not an alphabet",character);
}


