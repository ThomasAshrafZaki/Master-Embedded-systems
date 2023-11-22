/* main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	float num;

	printf("Enter a nubmer :");
	fflush(stdin);     fflush(stdout);
	scanf("%f",&num);
	if (num>0)
		printf("%.2f is positive",num);
	else if (num<0)
		printf("%.2f is negative",num);
	else
		printf("You entered zero");
}




