/*
 * main.c
 *
 *  Created on: Jul 28, 2024
 *      Author: thomas ashraf
 */
//use realloc() and malloc()
#include "stdio.h"
#include "stdlib.h"

void main (void)
{
	//decleration of num & sum & ptr
	int num ,sum =0;
	int *ptr;
	//enter the num
	printf("enter the number....>");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&num);
	//init the ptr
	ptr = (int *)malloc(num*sizeof(int));
	if (ptr==NULL)
	{
		printf("\n error! memory heap not allocated");
		exit(0);
	}
	printf("\n enter the data : ");
	//entering of data
	for(int i =0;i<num;i++)
	{
		fflush(stdin);		fflush(stdout);
		scanf("%d",ptr+i);
		sum+=*(ptr+i);
	}
	printf("\n the sum = %d",sum);
	//decleration of num_extantion
	int num_extantion;
	//enter the num_extantion
	printf(" \nenter the number of extantion....>");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&num_extantion);
	//re init the ptr
	ptr=realloc(ptr,num_extantion);
	//entering of data extantion
	printf("\n enter the data extantion : ");
	for(int i =0;i<num_extantion;i++)
		{
			fflush(stdin);		fflush(stdout);
			scanf("%d",ptr+i);
			sum+=*(ptr+i);
		}
	printf("\n the sum = %d",sum);
	free(ptr);

}
