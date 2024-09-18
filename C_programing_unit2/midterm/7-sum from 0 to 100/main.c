
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */
int Sum_0_To_100 (int num);
int sum=0;
#include <stdio.h>
#include <string.h>
void main (void)
{
	int result = Sum_0_To_100 (100);
	printf("Sum from 1 to 100 = %d",result);

}
int Sum_0_To_100 (int num)
{

	if(num!=0)
		{
		sum+=num;
		Sum_0_To_100 (--num);
		}
return sum;
}





