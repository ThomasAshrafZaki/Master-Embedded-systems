/*
 * main.c
 *
 *  Created on: 23/10/2023
 *      Author: Thomas Ashraf Zaki
 */
//display the transpose of the matrix
#include <stdio.h>
#include <string.h>
void main (void)
{
	int i,j,r,c;
	int a[10][10],t[10][10];
	printf("Enter rows and colums of the matrix : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d%d",&r,&c);
//initalize matrix element values
	for(i=0;i<r;i++)
	{
		if(i==0)
			printf("Enter the elements of 1st matrix :\n");
		for(j=0;j<c;j++)
		{
			printf("Enter element a%d%d : ",i+1,j+1);
			fflush(stdin);		fflush(stdout);
			scanf("%d",&a[i][j]);
		}
	}
	//display matrix element values
	printf("Entered matrix : \n");
		for(i=0;i<r;i++)
		{
			if (i>0)
				printf("\n");
			for(j=0;j<c;j++)
			{
			  printf("%d ",a[i][j]);
			}
		}
	//initalize transpose element values
	for(i=0;i<r;i++)
	{
		if (i>0)
			printf("\n");
		for(j=0;j<c;j++)
		{
			t[j][i]=a[i][j];
		}
	}
	//display transpose element values
	printf("\ntranspose of matrix : \n");
	for(i=0;i<c;i++)
		{
			if (i>0)
				printf("\n");
			for(j=0;j<r;j++)
			{
			  printf("%d ",t[i][j]);
			}
		}
}
