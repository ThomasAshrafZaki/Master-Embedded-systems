
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */
void Prime_Num (int num1,int num2);

#include <stdio.h>
#include <string.h>
void main (void)
{
	int num1,num2;
	printf("Enter an number 1 : ");
	fflush(stdin);    	fflush(stdout);
	scanf("%d",&num1);
	printf("Enter an number 2 : ");
	fflush(stdin);    	fflush(stdout);
	scanf("%d",&num2);
	printf("Numbers of prime numbers :");
	Prime_Num ( num1, num2);
}
void Prime_Num (int num1,int num2)
{
	int i,c=0;
	if(num1>num2)
	{
		int temp=num1;
		num1=num2;
		num2=temp;
	}
	if(num1==num2)
		printf("No Prime Number Found");

	for(i=num1;i<num2;i++)
	{ if(i==2||i==3||i==5||i==7)
	{
		printf(" %d",i);
		c=1;
	}

	else if(i%2 !=0 && i%3 !=0 && i%5 !=0 && i%7 !=0)
	{
		printf(" %d",i);
		c=1;
	}
	}
	if(c==0)
		printf("No Prime Number Found");

}
