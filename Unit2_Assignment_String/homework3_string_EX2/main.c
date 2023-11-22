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
	printf("Enter the numbers of elements : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&n);
	//Enter the matrix
	printf("Enter a string : ");
	fflush(stdin);    	fflush(stdout);
	gets(a);
	for(i=0;a[i]!=0;i++)
	{
		counter=i+1;
	}
   printf("Length of string = %d",counter);
}





