
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */
int Ones_In_BinaryNum (int num);
int ones=0;
#include <stdio.h>
#include <string.h>
void main (void)
{
	int num;
	int result=0;
	printf("Enter an number : ");
	fflush(stdin);    	fflush(stdout);
	scanf("%d",&num);
	result=Ones_In_BinaryNum (num);
	printf("Numbers Of Ones in  %d = %d",num,result);

}
int Ones_In_BinaryNum (int num)
{

	if(num!=0)
		{
		if(num%2!=0)
			ones++;
		Ones_In_BinaryNum (num/2);
		}
return ones;
}


