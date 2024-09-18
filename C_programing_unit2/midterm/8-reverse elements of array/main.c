
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */
void reverse_array(int arr[],int num);
#include <stdio.h>
#include <string.h>
void main (void)
{
	int result ,arr[10];
	for (int i=0;i<10;i++)
	{
		printf("Enter an element :");
		fflush(stdin);		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	printf("Reverse of elements array are {");
	reverse_array(arr,10);
	printf(" }");

}
void reverse_array(int arr[],int num)
{
	if(num>0)
	{
		printf(" %d",arr[num-1]);
		reverse_array( arr,-- num);
	}

}





