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
	float a[2][2], b[2][2],sum[2][2] ;
	int i,j;
	for(i=1;i<=2;i++)
	{
		if(i==1)
			printf("Enter the elements of 1st matrix :\n");
		for(j=1;j<=2;j++)
		{
			printf("Enter a%d%d : ",i,j);
			fflush(stdin);		fflush(stdout);
			scanf("%f",&a[i-1][j-1]);
		}
	}

	for(i=1;i<=2;i++)
	{   if(i==1)
		printf("Enter the elements of 2nd matrix :\n");
		for(j=1;j<=2;j++)
		{
			printf("Enter b%d%d : ",i,j);
			fflush(stdin);		fflush(stdout);
			scanf("%f",&b[i-1][j-1]);
			sum[i-1][j-1]=a[i-1][j-1]+b[i-1][j-1];
		}
	}
printf("sum of matrix :\n")	;
	for(i=1;i<=2;i++)
	{
		if (i==2)
			printf("\n");
		for(j=1;j<=2;j++)
		{
			if(j==1)
				printf("%f\t",sum[i-1][j-1]);
			else
				printf("%f",sum[i-1][j-1]);
		}
	}
}

