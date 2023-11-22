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

	int i,n,n_insert,loc;
	printf("Enter the numbers of elements : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&n);
	int a[n+1];
	//Enter the matrix
	for(i=0;i<n;i++)
	{
		printf("Enter num :");
		fflush(stdin);		fflush(stdout);
		scanf("%d",&a[i]);
	}
	//Display the matrix before inserted
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	//Enter the element to be inserted
	printf("\nEnter the element to be inserted : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&n_insert);
	//Enter the location to be inserted
	printf("\nEnter the location to be inserted : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&loc);
	//to insert
	for(i=n+1;i>=loc;i--)
	{
		a[i]=a[i-1];
	}
   a[loc-1]=n_insert;
   //Display the matrix after inserted
   for(i=0;i<=n;i++)
   	{
   		printf("%d ",a[i]);
   	}
}

