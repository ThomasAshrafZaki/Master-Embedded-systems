
/*
 * main.c
 *
 *  Created on: 23/10/2023
 *      Author: Thomas Ashraf Zaki
 */

#include <stdio.h>
#include <string.h>
void main (void)
{

	int i,temp;
	char a[99];
	//Enter the matrix
	printf("Enter a string : ");
	fflush(stdin);    	fflush(stdout);
	gets(a);
	for(i=0;i<strlen(a)/2;i++)
	{
		temp=a[i];
		a[i]=a[strlen(a)-1-i];
		a[strlen(a)-1-i]=temp;
	}
	printf("Reverse of string is : %s",a);
}

