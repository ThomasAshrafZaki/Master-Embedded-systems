
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */

#include <stdio.h>
#include <string.h>
#define size 7
int check_unique;
void unique_num (int arr[size]);
void main (void)
{
	int arr[size];
	printf("enter the elements: ");
	fflush(stdin);		fflush(stdout);
	for (int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("int arr [%d]={",size);
	for (int i=0;i<size;i++)
		{
		printf("%d",arr[i]);
		fflush(stdin);		fflush(stdout);
		if(i!=size-1)
		printf(",");
		}
		printf("}\n");
	unique_num (arr);
}
void unique_num (int arr[size])
{
	printf("unique elements are ={",size);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if (i!=j)//this condition to avoid check the same element
			{
				if(arr[i]==arr[j])
				{check_unique=1;}//we know that this element not unique
			}
		}
		if(!check_unique)
		{
			printf("%d ",arr[i]);
		}

		else
			check_unique=0;
	}
	printf("}\n");
}
