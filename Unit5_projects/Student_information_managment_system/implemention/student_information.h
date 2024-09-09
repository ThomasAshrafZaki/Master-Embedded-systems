/*
 * student.h
 *
 *  Created on: Aug 19, 2024
 *      Author: thomas ashraf
 */

#ifndef STUDENT_INFORMATION_H_
#define STUDENT_INFORMATION_H_

#include "platform_t.h"
//typedefs

#define element_type SData_Student_t
typedef enum {    //status of error
	fifo_null,
	fifo_no_error,
	fifo_full,
	fifo_empty
}fifo_status;
//data of each student
typedef struct {
	char first_name [30];
	char last_name [30];
	unsigned int unique_roll;
	float GPA;
	unsigned int ID_Courses[5];
}SData_Student_t;

typedef struct {
	element_type* base;
	element_type* head;
	element_type* tail;
	vuint32_t length;
	vuint32_t size;
	vuint32_t count;
}fifo_buffer_t;
//APIS
void Add_Student_from_File(fifo_buffer_t* fifo_buffer );
void Add_Student_Manualy( fifo_buffer_t* fifo_buffer );
void Find_by_id(fifo_buffer_t* fifo_buffer);
void find_by_FirstName(fifo_buffer_t* fifo_buffer);
void find_by_LastName(fifo_buffer_t* fifo_buffer);
void find_by_GPA(fifo_buffer_t* fifo_buffer);
void find_by_Registered_Courses(fifo_buffer_t* fifo_buffer);
void Count_Students(fifo_buffer_t* fifo_buffer);
void Delete_student(fifo_buffer_t* fifo_buffer);
void Delete_All_Student(fifo_buffer_t* fifo_buffer);
void Updata_Data_of_student(fifo_buffer_t* fifo_buffer);
void Show_students(fifo_buffer_t* fifo_buffer);
void increment_length_buf(fifo_buffer_t* fifo_buffer);
void print_states();
void enter_student(char* line, element_type* student);
void Exit();

//APIS of fifo
fifo_status FIFO_ENQUEUE(fifo_buffer_t* fifo_buffer ,element_type item );
fifo_status FIFO_DEQUEUE(fifo_buffer_t* fifo_buffer ,element_type* item );
fifo_status FIFO_INIT(fifo_buffer_t* fifo_buffer , element_type* buffer ,vuint32_t length );
fifo_status FIFO_EMPTY(fifo_buffer_t* fifo_buffer);
fifo_status FIFO_FULL(fifo_buffer_t* fifo_buffer);
void FIFO_PRINT(fifo_buffer_t* fifo_buffer);
#endif /* STUDENT_INFORMATION_H_ */
