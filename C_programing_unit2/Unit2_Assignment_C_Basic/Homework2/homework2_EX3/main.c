/* main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	float num1,num2,num3;

	printf("Enter three nubmers :");
	fflush(stdin);     fflush(stdout);
	scanf("%f %f %f",&num1,&num2,&num3);
	if (num1>num2)
	{
		if(num1>num3)
			printf("Largest number = %f",num1);
		else
			printf("Largest number = %f",num3);
	}
	else
	{
		if(num2>num3)
			printf("Largest number = %f",num2);
		else
			printf("Largest number = %f",num3);
	}
}



