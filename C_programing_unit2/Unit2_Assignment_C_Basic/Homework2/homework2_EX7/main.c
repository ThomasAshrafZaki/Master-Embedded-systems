/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	int num=0,fact=1;

	printf("Enter an integer: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&num);
	if(num==0)
		printf("factorial = 1");
	else if (num<0)
		printf("Error!!! factorial of negative number doesnot exist ");
	else
	{
		for (int i=1;i<=num;i++)
		{
			fact *=i;
		}
		printf("factorial = %d",fact);
	}
}




