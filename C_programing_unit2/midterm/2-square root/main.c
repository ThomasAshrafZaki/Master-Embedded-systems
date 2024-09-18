
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */
float square_root (float num);
#include <stdio.h>
#include <string.h>
void main (void)
{
	float num;
	float result;
	printf("Enter an number : ");
	fflush(stdin);    	fflush(stdout);
	scanf("%f",&num);
	result= square_root (num);
	if(num==(int)num)
	 printf("square root of %d = %0.3f",(int)num,result);
	else
	 printf("square root of %0.3f = %0.3f",num,result);
}
float square_root (float num)
{
//by using Newton algorithm
	float x=1,x0=0,x1=0;
	do
	{
		x0=0.5*(x+(num/x));
		x1=x;
		x=x0;
	}while (x1!=x0);
return x1;
}
