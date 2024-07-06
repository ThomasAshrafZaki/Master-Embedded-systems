/*
 * main.c
 *
 *  Created on: 15/11/2023
 *      Author: Thomas Ashraf Zaki
 */

#include <stdio.h>
#include <string.h>
int power (int base,int powr);
void main (void)
{int n ;
int powr;

	printf("Enter Base Num : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("Enter Power Num (Positive num) : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&powr);
		int res=power(n,powr);
		printf("Power Of %d = %d",n,res);
}
int power (int base,int powr)
{
	powr--;
	if(powr>0)
	return	base*=power(base,powr);




}


