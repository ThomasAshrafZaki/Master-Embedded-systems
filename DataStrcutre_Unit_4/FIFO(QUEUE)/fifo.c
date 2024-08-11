/*
 * fifo.c
 *
 *  Created on: Jul 31, 2024
 *      Author: THOMAS ASHRAF ZAKI
 */

#include "stdio.h"
#include "fifo.h"
//APIS
fifo_status FIFO_INIT(fifo_buffer_t* fifo_buffer , element_type* buffer ,vuint32_t length )
{
	//check if fifo point null
	if(buffer==NULL)
		return fifo_null;
	//init of buffer
	fifo_buffer->base=buffer;
	fifo_buffer->head=buffer;
	fifo_buffer->tail=buffer;
	fifo_buffer->length=length;
	fifo_buffer->size=length*sizeof(element_type);
	fifo_buffer->count=0;
}
fifo_status FIFO_ENQUEUE(fifo_buffer_t* fifo_buffer ,element_type item )
{
	//check if fifo point null
	if(!fifo_buffer->head||!fifo_buffer->base||!fifo_buffer->tail)
		return fifo_null;
	//check if lifo is full
	if(FIFO_FULL(fifo_buffer)==fifo_full)
		return fifo_full;
	fifo_buffer->count++;//increment count
	//check if head point on the last of the buffer
	if (fifo_buffer->head==(fifo_buffer->base+fifo_buffer->size)){
		fifo_buffer->head=fifo_buffer->base;
		//add item
		*(fifo_buffer->head)=item;
		fifo_buffer->head++;
	}
	else{
		*(fifo_buffer->head)=item;
		//add item
		fifo_buffer->head++;
	}

}
fifo_status FIFO_DEQUEUE(fifo_buffer_t* fifo_buffer ,element_type* item )
{
	//check if fifo point null
	if(!fifo_buffer->head||!fifo_buffer->base)
		return fifo_null;
	//check if fifo is full
	if(FIFO_EMPTY(fifo_buffer)==fifo_empty)
		return fifo_empty;
	fifo_buffer->count--;//decrement count
	//check if tail point on the last of the buffer
	if (fifo_buffer->tail==(fifo_buffer->base+fifo_buffer->size)){
		fifo_buffer->tail=fifo_buffer->base;
		//add item
		*item=*(fifo_buffer->tail);
	}
	else{
		*item=*(fifo_buffer->tail);
		//add item
		fifo_buffer->tail++;
	}

}
fifo_status FIFO_EMPTY(fifo_buffer_t* fifo_buffer)
{
	//check if fifo point null
	if(!fifo_buffer->head||!fifo_buffer->base||!fifo_buffer->tail)
		return fifo_null;
	if(fifo_buffer->count==0)
		return fifo_empty;
	return fifo_no_error;
}
fifo_status FIFO_FULL(fifo_buffer_t* fifo_buffer)
{
	//check if fifo point null
	if(!fifo_buffer->head||!fifo_buffer->base||!fifo_buffer->tail)
		return fifo_null;
	if(fifo_buffer->count==fifo_buffer->length)
		return fifo_full;
	return fifo_no_error;
}
void FIFO_PRINT(fifo_buffer_t* fifo_buffer)
{
	int x=fifo_buffer->count;
	if(fifo_buffer->count==0)
		printf("buffer is empty.");
	else{
		printf("\n------fifo content------");
		element_type*item=fifo_buffer->base;//item =base----->to print from begging if head circular
		for(int i=x;i>0;--i){
			if((fifo_buffer->head)>(fifo_buffer->tail)){
				break;
			}
			else if((fifo_buffer->head)>item )//check if head >= item in address-----i take from base to reach heap
			{

				printf("\n %x",*item);
				item++;
			}
			else//if item=head
				break;
		}

		item=fifo_buffer->tail;//item =tail----->to make item print from tail
		for(int i=x;i>0;--i){
			if((fifo_buffer->head)<=(fifo_buffer->tail))//check if head > item in address-----i take from base to reach heap
			{
				if(item<(fifo_buffer->base+fifo_buffer->size))//check if item not reach to the top of buffer
					printf("\n %x",*item);
				item++;
			}
			else if((fifo_buffer->head)>(fifo_buffer->tail)){//check if head > tail
				if(item>=(fifo_buffer->tail)&&item<(fifo_buffer->head)){
					printf("\n %x",*item);
					item++;
				}
			}
		}


	}
	printf("\n------------------------------------------");
}


