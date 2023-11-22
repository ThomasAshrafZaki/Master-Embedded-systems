/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	float num1,num2;
	char operator ;


	printf("Enter operator either + or - or * or / : ");
	fflush(stdin);     fflush(stdout);
	scanf("%c",&operator);

	printf("Enter two operands: ");
	fflush(stdin);     fflush(stdout);
	scanf("%f %f",&num1,&num2);

	switch(operator)
	{
	case '+' : {printf("%f %c %f = %f",num1,operator,num2,(num1+num2));	break;}
	case '-' : {printf("%f %c %f = %f",num1,operator,num2,(num1-num2));	break;}
	case '*' : {printf("%f %c %f = %f",num1,operator,num2,(num1*num2));	break;}
	case '/' : {printf("%f %c %f = %f",num1,operator,num2,(num1/num2));	break;}
	default  : {printf("Error!!! you donot enter operator ");}
	}
}

