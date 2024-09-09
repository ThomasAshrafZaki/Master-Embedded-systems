/*
 * main.c
 *
 *  Created on: Aug 19, 2024
 *      Author: thomas ashraf
 */

//this project manage the information of students
//==========================================
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "student_information.h"
//the length of buffer
 vuint32_t length_buffer=1;
//global num to select state
 int check_while=1;
 //pointer in buffer
 element_type* buf_ptr;
void main (){
	element_type student;
	fifo_buffer_t buffer;
	 buf_ptr =(element_type*)malloc(length_buffer *sizeof(element_type));
	//to check if fifo return null and slove it
	while(FIFO_INIT( &buffer , buf_ptr,length_buffer )==fifo_null)
	{
		printf("\n[ERROR] buffer return NULL-->i will try again to slove it");
		buf_ptr =(element_type*)malloc(length_buffer *sizeof(element_type));
	}
	printf("\n[INFO] buffer is init");//sucssesful init buffer
	while(check_while){
		int state_num;
		print_states();
		fflush(stdin);fflush(stdout);
		scanf("%d",&state_num);
		printf("\n============================================= ");
		switch(state_num){
		case 1:{
			Add_Student_from_File(&buffer);
			break;
		}
		case 2:{
			Add_Student_Manualy(&buffer);
			break;
		}
		case 3:{
			Find_by_id(&buffer);
			break;
		}
		case 4:{
			find_by_FirstName(&buffer);
			break;
		}
		case 5:{
			find_by_LastName(&buffer);
			break;
		}
		case 6:{
			find_by_GPA(&buffer);
			break;
		}
		case 7:{
			find_by_Registered_Courses(&buffer);
			break;
		}
		case 8:{
			Count_Students(&buffer);
            break;
		}
		case 9:{
			Delete_student(&buffer);
			break;
		}
		case 10:{
			Delete_All_Student(&buffer);
			break;
		}
		case 11:{
			Show_students(&buffer);
			break;
		}
		case 12:{
			Updata_Data_of_student(&buffer);
			break;
		}
		case 13:{
			Exit();
			break;
		}
		default:{
			printf("\n The State NOT FOUND!!");
		}
		}
	}
}
