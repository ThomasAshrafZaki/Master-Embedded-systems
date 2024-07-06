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

	int i,n;
	float a[n];
	float sum=0;
	printf("Enter the numbers of data : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter num :");
		fflush(stdin);		fflush(stdout);
		scanf("%f",&a[i]);
		sum+=a[i];
	}
	printf("Average = %f ",sum/n);

}
