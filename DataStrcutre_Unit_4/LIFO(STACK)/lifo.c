/*
 * lifo.c
 *
 *  Created on: Jul 30, 2024
 *      Author: thomas ashraf zaki
 */

#include "lifo.h"
#include "platform_t.h"
#include "stdio.h"

#define check_full    2
#define check_empty   3

//APIS ----->Application programming interfaces
lifo_status LIFO_ADD_ITEM(lifo_buffer_t* lifo_buffer ,element_type item)
{
	//check if lifo point null
	if(!lifo_buffer->head||!lifo_buffer->base)
		return lifo_null;
	//check if lifo is full
	if(LIFO_FULL(lifo_buffer)==check_full)
		return lifo_full;
	//add item to buffer
	*(lifo_buffer->head)=item;
	lifo_buffer->head++;
	lifo_buffer->count++;
	return lifo_no_error;
}
lifo_status LIFO_POP_ITEM(lifo_buffer_t* lifo_buffer ,element_type* item)
{
	//check if lifo point null
	if(!lifo_buffer->head||!lifo_buffer->base)
		return lifo_null;
	//check if lifo is full
	if(LIFO_EMPTY(lifo_buffer)==check_empty)
		return lifo_empty;
	//POP item from buffer
	lifo_buffer->head--;
	*item=*(lifo_buffer->head);
	lifo_buffer->count--;
	return lifo_no_error;
}
lifo_status LIFO_INIT(lifo_buffer_t* lifo_buffer , element_type* buffer ,vuint32_t length )
{
	//check if lifo point null
	if(buffer==NULL)
		return lifo_null;
	//init of buffer
	lifo_buffer->base=buffer;
	lifo_buffer->head=buffer;
	lifo_buffer->length=length;
	lifo_buffer->size=length*sizeof(int);
	lifo_buffer->count=0;

	return lifo_no_error;
}
lifo_status LIFO_EMPTY(lifo_buffer_t* lifo_buffer)
{
	//check if lifo point null
	if(!lifo_buffer->head||!lifo_buffer->base)
		return lifo_null;
	if(lifo_buffer->base==lifo_buffer->head)
		return lifo_empty;
	return lifo_no_error;
}
lifo_status LIFO_FULL(lifo_buffer_t* lifo_buffer)
{
	//check if lifo point null
	if(!lifo_buffer->head||!lifo_buffer->base)
		return lifo_null;
	if(lifo_buffer->head >=(lifo_buffer->base + lifo_buffer->size))
		return lifo_full;
	return lifo_no_error;
}


