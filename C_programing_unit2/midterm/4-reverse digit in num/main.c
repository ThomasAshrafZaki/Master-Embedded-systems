
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */
void Reverse_Digit_Of_Num (int num);

#include <stdio.h>
#include <string.h>
void main (void)
{
	int num;
	int result;
	printf("Enter an number : ");
	fflush(stdin);    	fflush(stdout);
	scanf("%d",&num);
	printf("Reverse Digit Of %d =",num);
	if(num!=0)
	Reverse_Digit_Of_Num (num);
	else
		printf(" %d",0);

}
void Reverse_Digit_Of_Num (int num)
{
	int digit =num%10;
	if(num!=0)
	{
	printf("%d",digit);
	Reverse_Digit_Of_Num (num/10);

	}

}



