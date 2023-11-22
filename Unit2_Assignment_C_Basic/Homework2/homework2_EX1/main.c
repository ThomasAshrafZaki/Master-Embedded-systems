/*
 * main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	int num;

	printf("Enter an integer you want to check :");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&num);
	 (num%2==0)? printf("%d is even ",num): printf("%d is odd ",num);


}




