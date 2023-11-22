/*
 * main.c
 *
 *  Created on: 15/11/2023
 *      Author: Thomas Ashraf Zaki
 */
int factorial (int num);
int fact=1;
#include <stdio.h>
#include <string.h>
void main (void)
{
	int num,result;
	printf("Enter an positive num : ");
	fflush(stdin);    	fflush(stdout);
	scanf("%d",&num);
    result=factorial (num);
    printf("factorial of %d = %d",num,result);
}
int factorial (int num)
{
	fact *=num;
	num--;
	if(num>1)
	factorial(num);
	return fact;
}
