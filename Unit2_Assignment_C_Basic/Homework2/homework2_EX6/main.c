/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	int num=0,sum=0;

	printf("Enter an integer: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&num);
	for (int i=1;i<=num;i++)
	{
		sum +=i;
	}
	printf("sum = %d",sum);
}

