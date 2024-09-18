
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */

#include <stdio.h>
#include <string.h>
int res,ones,check;
int Num_Of_Bits_In_Number (int num);
void Max_ones_between_two_zeros (int Num_Of_Bits,int num);
void main (void)
{
	int num;
	printf("enter the number: ");
	fflush(stdin);		fflush(stdout);
	scanf("%d",&num);
	int Num_Of_Bits = Num_Of_Bits_In_Number ( num);
	Max_ones_between_two_zeros (Num_Of_Bits,num);
}
int Num_Of_Bits_In_Number (int num)
{

	if(num!=0)
	{
		num=num>>1;
		res++;
		Num_Of_Bits_In_Number (num);

	}
	return res;
}
void Max_ones_between_two_zeros (int Num_Of_Bits,int num)
{
	while((num&1)==1)//to avoid the first right bit =1
	{
		num=num>>1;
		Num_Of_Bits--;//to be professional
	}
	for(int i=0;i<=Num_Of_Bits;i++)//i<=Num_Of_Bits------>for ex 5 (0101)----sum of bit=4
	{
		if((num&1)==1)
		{
			ones++;
		}
		else//my goal is if num&1==0-------->ones=0
		{
			if(ones>=check)
		{
			 check=ones;
			 ones=0;
		}
		   else
			 {ones=0;}
		}
		num=num>>1;
	}
	printf("the max of ones between two zeros = %d",check);
}


//finshhhhh#
