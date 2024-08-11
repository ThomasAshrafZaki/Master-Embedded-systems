/*
 * main.c
 *
 *  Created on: Jul 31, 2024
 *      Author: thomas ashraf zaki
 */

#include "stdio.h"
#include "fifo.h"
#include "stdlib.h"

element_type buf[length_buffer];//elements init 0 not pointer(buf)--->point to addres in memory but not changes because it global and const array size
void main (void)
{
	element_type GET_ITEM;
	fifo_buffer_t uart_buffer;
	FIFO_INIT(&uart_buffer,buf,length_buffer);

	for(int x=0;x<(length_buffer+2);x++){
		if(FIFO_ENQUEUE(&uart_buffer,x)==fifo_full){
			printf("\n---fifo is full now--- ");
			FIFO_PRINT(&uart_buffer);//to print the buffer to know the changes
			x--;//to delete the loop that fifo_full(if x=6 and check is correct then in the next loop i add 7 not 6)
			FIFO_DEQUEUE(&uart_buffer,&GET_ITEM);
			printf("\n fifo get : %x",GET_ITEM);
		}
		else
			printf("\n fifo add : %x",x);
	}
	FIFO_PRINT(&uart_buffer);
}

