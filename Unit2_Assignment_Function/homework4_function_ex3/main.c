/*
 * main.c
 *
 *  Created on: 15/11/2023
 *      Author: Thomas Ashraf Zaki
 */

#include <stdio.h>
#include <string.h>
void reverse ();
void main (void)
{
	printf("Enter Sentence : ");
	fflush(stdin); fflush(stdout);
	reverse();
}
void reverse ()
{
	char c;
	scanf("%c",&c);
	if (c!='\n')
	{ reverse();
	printf("%c",c);
	}


}

