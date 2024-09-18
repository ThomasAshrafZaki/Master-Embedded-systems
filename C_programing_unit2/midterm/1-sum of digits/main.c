/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */
int sum_of_digits (int num);

#include <stdio.h>
#include <string.h>
void main (void)
{
	int num,sum;
	printf("Enter an number : ");
	fflush(stdin);    	fflush(stdout);
	scanf("%d",&num);
	sum=sum_of_digits (num);
	printf("Sum of digits of %d = %d",num,sum);
}
int sum_of_digits (int num)
{
	int digit;
	if (num!=0)
	{
		digit= num%10;
		num/=10;
		return digit+sum_of_digits (num);
	}
}
