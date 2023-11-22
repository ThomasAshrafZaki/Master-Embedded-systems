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

	int i,n,n_search;
	printf("Enter the numbers of elements : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&n);
	int a[n];
	//Enter the matrix
	for(i=0;i<n;i++)
	{
		printf("Enter num :");
		fflush(stdin);		fflush(stdout);
		scanf("%d",&a[i]);
	}
	//Display the matrix
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	//Enter the element to be searched
	printf("\nEnter the element to be searched : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&n_search);
	//to search
	for(i=n-1;i>=0;i--)
	{
		if (a[i]==n_search)
			break;
	}
   printf("Number found at location = %d",i+1);
}




