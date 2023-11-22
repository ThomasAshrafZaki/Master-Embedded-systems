/* main.c
 *
 *  Created on: 15/10/2023
 *      Author: Thomas Ashraf Zaki
 */


#include <stdio.h>
void main (void)
{
	char character;

	printf("Enter an alphabet :");
	fflush(stdin);     fflush(stdout);
	scanf("%c",&character);
	if (((int)character>=65 && (int)character<=90)||((int)character>=97 && (int)character<=122))
		{
			(character=='a'||character=='A'||character=='o'||character=='O'||character=='e'||character=='E'||character=='i'||character=='I'||character=='u'||character=='U')? printf("%c is a vowel.",character):printf("%c is a consonant.",character);

		}
		else
			printf("%c Not an alphabet",character);
}

