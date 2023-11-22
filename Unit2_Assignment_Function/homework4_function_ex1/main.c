/*
 * main.c
 *
 *  Created on: 15/11/2023
 *      Author: Thomas Ashraf Zaki
 */
void prime_number (int num1,int num2);
#include <stdio.h>
#include <string.h>
void main (void)
{

	int n1,n2;
	printf("Enter two numbers : ");
	fflush(stdin);    	fflush(stdout);
	scanf("%d %d",&n1,&n2);
	prime_number (n1,n2);

}
void prime_number (int num1,int num2)
{
	printf("Prime Numbers between %d and %d = ",num1,num2);
	if(num2>num1)
	{
		for(int i=num1;i<=num2;i++)
		{
			if(i==2||i==3||i==5)
				printf("%d ",i);
			else if (!(i%2==0||i%5==0||i%3==0))
				printf("%d ",i);
		}
	}
	else
		for(int i=num2;i<=num1;i++)
		{
			if(i==2||i==3||i==5)
				printf("%d ",i);
			else if (!(i%2==0||i%5==0||i%3==0))
				printf("%d ",i);
		}
}
