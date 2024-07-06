
/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


/*
Write Source Code to Swap Two Numbers without temp variable.
  */
#include <stdio.h>
void main (void)
{
	float a=0,b=0;
	printf("Enter value of a: ");
	fflush(stdin);     fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdin);     fflush(stdout);
	scanf("%f",&b);
	float sum=a+b;
	a=sum-a;
	b=sum-b;
	printf("After swapping, value of a = %.2f",a);
	printf("\nAfter swapping, value of b = %.2f",b);
}
