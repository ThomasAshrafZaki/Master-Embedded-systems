
/*
 * main.c
 *
 *  Created on: 1/12/2023
 *      Author: Thomas Ashraf Zaki
 */

#include <stdio.h>
#include <string.h>
void reverse_Words_In_String(char arr[100],char num1[50],char num2[50]);
int  check1;
void main (void)
{
	char arr[100];
	char num1[50];
	char num2[50];
	//to enter words
	printf("Enter Here :");
	fflush(stdin); 		fflush(stdout);
	gets(arr);
	reverse_Words_In_String(arr,num1,num2);
}
void reverse_Words_In_String(char arr[100],char num1[50],char num2[50])
{
//to reverse words
for (int j=0;j<100;j++)
{
	if(arr[j]==32)//32 assci of space
	{check1=j;
	num1[j]=NULL;//to end the array
	break;
	}
	num1[j]=arr[j];
}
	//condition to know that we are in the second name
for (int j=0;j<100;j++)
{
	if(arr[j+check1+1]==NULL)//because when use gets the array of arr end after the last element by null automatically
		{
		num2[j]=NULL;//to end the array
			break;
		}
	num2[j]=arr[j+check1+1];

}
strcat(num2," ");
strcat(num2,num1);
//to print
puts(num2);

}



