/*
 * lifo.h
 *
 *  Created on: Jul 30, 2024
 *      Author: thomas ashraf zaki
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "platform_t.h"
//user configrations
#define element_type vuint32_t //(vuint8_t ,vuint32_t ,......)
#define num_status  3
#define num_of_buf  2
#define length_buffer 6
//typedefs
typedef struct {
	vuint32_t count;
	vuint32_t length;
	vuint32_t size;
	vuint32_t* base;
	vuint32_t* head;
}lifo_buffer_t;

typedef enum {    //status of error
	lifo_null,
	lifo_no_error,
	lifo_full,
	lifo_empty
}lifo_status;
//APIS ----->Application programming interfaces
lifo_status LIFO_ADD_ITEM(lifo_buffer_t* lifo_buffer ,element_type item );
lifo_status LIFO_POP_ITEM(lifo_buffer_t* lifo_buffer ,element_type* item );
lifo_status LIFO_INIT(lifo_buffer_t* lifo_buffer , element_type* buffer ,vuint32_t length );
lifo_status LIFO_EMPTY(lifo_buffer_t* lifo_buffer);
lifo_status LIFO_FULL(lifo_buffer_t* lifo_buffer);
#endif /* LIFO_H_ */
