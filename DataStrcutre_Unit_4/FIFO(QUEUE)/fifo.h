/*
 * fifo.h
 *
 *  Created on: Jul 31, 2024
 *      Author: THOMAS ASHRAF ZAKI
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "platform_t.h"

//user configrations
#define element_type  vuint8_t  //(vuint8_t ,vuint32_t ,......)
#define num_status  3
#define num_of_buf  2
#define length_buffer 6
//typedefs
typedef struct {
	element_type* base;
	element_type* head;
	element_type* tail;
	vuint32_t length;
	vuint32_t size;
	vuint32_t count;
}fifo_buffer_t;

typedef enum {    //status of error
	fifo_null,
	fifo_no_error,
	fifo_full,
	fifo_empty
}fifo_status;
//APIS
fifo_status FIFO_ENQUEUE(fifo_buffer_t* fifo_buffer ,element_type item );
fifo_status FIFO_DEQUEUE(fifo_buffer_t* fifo_buffer ,element_type* item );
fifo_status FIFO_INIT(fifo_buffer_t* fifo_buffer , element_type* buffer ,vuint32_t length );
fifo_status FIFO_EMPTY(fifo_buffer_t* fifo_buffer);
fifo_status FIFO_FULL(fifo_buffer_t* fifo_buffer);
void FIFO_PRINT(fifo_buffer_t* fifo_buffer);
#endif /* FIFO_H_ */
