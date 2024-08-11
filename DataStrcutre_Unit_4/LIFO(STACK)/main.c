/*
 * main.c
 *
 *  Created on: Jul 30, 2024
 *      Author: thomas ashraf
 */

#include "lifo.h"
#include "platform_t.h"
#include "stdio.h"
#include "stdlib.h"



//declerate buffer area
element_type buffer1[length_buffer];
element_type* buffer2;
int main (void)
{
	//dynamic buffer
	element_type* buffer2=(element_type* )malloc(length_buffer*sizeof(int));
	//the item to get data
	element_type item=0;
	//array of buffers
	lifo_buffer_t arr[num_of_buf];
	//create array of pointer to vuint32_t
	element_type* buf[num_of_buf] ={buffer1 , buffer2};
	//to init buffers
	for(element_type x =0 ;x<num_of_buf ;x++)
	{
		if(!(LIFO_INIT(&arr[x] , buf[x] , length_buffer))){
			printf("\nthe buffer%x is point to null",x+1);
			exit(0);
			}
		else
			printf("\n buffer%x is created",x+1);
	}

	//to add items
	for(element_type x =0 ;x<length_buffer ;x++)
	{
	     if(LIFO_ADD_ITEM(&arr[0] ,x)==lifo_full){
			printf("\n buffer is full");
			break;
		}
		else
			{
			printf("\n buffer%x add : %x ",1,x);
			}
	}
	//to pop items
	for(element_type x =0 ;x<length_buffer ;x++)
		{
		     if(LIFO_POP_ITEM(&arr[0] ,&item)==lifo_empty){
				printf("\n buffer is empty");
				break;
			}
			else
				{
				printf("\n buffer%x pop : %x ",1,item);
				}
		}

	return 0;
}
