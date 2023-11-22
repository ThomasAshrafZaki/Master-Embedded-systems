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

	int i,n,counter=0;
	char a[n];
	char check;
	printf("Enter the numbers of elements : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&n);
	//Enter the matrix
	printf("Enter a string : ");
	fflush(stdin);    	fflush(stdout);
	gets(a);
	printf("Enter the number to Know his frecquency : ");
	fflush(stdin);		fflush(stdout);
	scanf("%c",&check);
	//to Know frecquency
	printf("The length of string = %d",strlen(a));
	for(i=0;i<strlen(a);i++)
	{
		if (a[i]==check)
			counter++;
	}
   printf("\nfrecquency of '%c' = %d",check,counter);
}

