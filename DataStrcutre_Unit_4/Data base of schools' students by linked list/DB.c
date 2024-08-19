/*
 * DB.c
 *
 *  Created on: Aug 11, 2024
 *      Author: thomas ashraf zaki
 */

#include "platform_t.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "stdbool.h"
#include "DB.h"
//APIS
void ADD_STUDENT(){
	struct SStudent *PNewStudent;
	struct SStudent *PLastStudent;
	//check if list is empty==yes
	if (!GPFirst_student){
		//use this fun to add and check that pointer not point to null(malloc return value )
		PNewStudent=check_malloc_return ();
		GPFirst_student=PNewStudent;
	}
	//check if list is empty==no
	else{
		//check until reach to the end record
		PLastStudent=GPFirst_student;
		while(PLastStudent->PNext_student)
			PLastStudent=PLastStudent->PNext_student;

		//use this fun to add and check that pointer not point to null(malloc return value )
		PNewStudent=check_malloc_return ();

		PLastStudent->PNext_student=PNewStudent;
	}
	//SET the values of New Record
	//enter ID
	printf("\n Enter The ID : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&PNewStudent->student.ID);
	//enter name
	printf("\n Enter The Name : ");
	fflush(stdin);fflush(stdout);
	scanf("%s",&PNewStudent->student.name);
	//enter length
	printf("\n Enter The Length : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&PNewStudent->student.length);
	//set the next of new recort==null
	PNewStudent->PNext_student=NULL;
}

int DELET_STUDENT(){
	struct SStudent *PSelectStudent=GPFirst_student;
	struct SStudent *PPreviousStudent=NULL;
	vuint32_t ID;
	//enter the ID you want to delete
	printf("\n Enter The ID : ");
	fflush(stdin);	fflush(stdout);
	scanf("%u",&ID);
	//check if list is empty==no
	if(GPFirst_student)
	{
		while(PSelectStudent)
		{
			//if that is ID wanted to delete
			if(PSelectStudent->student.ID==ID)
			{
				//if it is  1st record
				if(!PPreviousStudent){
					GPFirst_student=PSelectStudent->PNext_student;
				}
				//if the list have muti records
				else{
					PPreviousStudent->PNext_student=PSelectStudent->PNext_student;
				}
				//delete the record
				free(PSelectStudent);
				printf("\n the student is deleted from list");
				return delete_record;

			}
			PPreviousStudent=PSelectStudent;
			PSelectStudent=PSelectStudent->PNext_student;
		}
		printf("\n Entered ID is error ");
		return 0;
	}else{
		//check if list is empty==yes
		printf("\n The list is empty");
		return 0;
	}
}
void DELET_AllSTUDENT(){
	struct SStudent *PCurrentStudent=GPFirst_student;
	struct SStudent *PTempStudent;
	//check if list is empty==no
	if(GPFirst_student){//loop on the list until NUll
		while (PCurrentStudent){
			PTempStudent=PCurrentStudent;
			PCurrentStudent=PCurrentStudent->PNext_student;
			free(PTempStudent);
		}
		GPFirst_student=NULL;
		printf("\n All students deleted ");
	}else{	//check if list is empty==yes
		printf("\n The list is empty");
	}

}
void Show_List(){
	struct SStudent *PCurrentStudent=GPFirst_student;
	//check if list is empty==no
	//counter
	vuint32_t count=0;
	if(GPFirst_student){//loop on the list until NUll
		while (PCurrentStudent){
			printf("\n Data of student(%u)",count+1);
			printf("\n \t The ID : %u",PCurrentStudent->student.ID);
			printf("\n \t The Name : %s",PCurrentStudent->student.name);
			printf("\n \t The Length %f: ",PCurrentStudent->student.length);
			count++;
			PCurrentStudent=PCurrentStudent->PNext_student;
		}
	}else{	//check if list is empty==yes
		printf("\n The list is empty");
	}
}
int Find_MiddleRecord(){
	//set pointer to check
	struct SStudent *PJumpStudent=GPFirst_student;
	struct SStudent *PMainStudent=GPFirst_student;
	//check empty
	if(GPFirst_student)
	{
		//if 1 record in the list
		if(PMainStudent->PNext_student==NULL){
			printf("\n Data of student");
			printf("\n \t The ID : %u",PMainStudent->student.ID);
			printf("\n \t The Name : %s",PMainStudent->student.name);
			printf("\n \t The Length %f: ",PMainStudent->student.length);
			return 0;
		}else{
			//loop to until the end of list
			while(PJumpStudent->PNext_student)
			{
				PMainStudent=PMainStudent->PNext_student;//make PMainStudent --->++
				PJumpStudent=PJumpStudent->PNext_student;//make PJumpStudent --->++
				//i want to make PJumpStudent jump again to make difference with main 2 (this a fast algorithm to find the middle)
				if(PJumpStudent->PNext_student)
					PJumpStudent=PJumpStudent->PNext_student;//make PJumpStudent --->++
				}
			}
			printf("\n Data of student");
			printf("\n \t The ID : %u",PMainStudent->student.ID);
			printf("\n \t The Name : %s",PMainStudent->student.name);
			printf("\n \t The Length %f: ",PMainStudent->student.length);

	}else{
		printf("\n No Student in the list");
	}

}
int Find_Length(struct SStudent * first_student){//by recursion function
	if(GPFirst_student){
		if(first_student){
			return 1 + Find_Length(first_student->PNext_student);//count the length when returning 1+1+1....
		}
		else
			return 0;//if fun reatch to null
	}
	else{
		printf("\n No Student in the list");
		return 0;//no record
	}
}
int Give_Index_ToPrintData(){
	//enter index   1st student--->index=0
	vuint32_t index;
	printf("\n Enter The Index : ");
	fflush(stdin);	fflush(stdout);
	scanf("%u",&index);
	//counter
	vuint32_t count=0;
	//set pointer to check
	struct SStudent *PCurrentStudent=GPFirst_student;
	//check empty
	if(GPFirst_student)
	{
		//loop to get the exactly index
		while(PCurrentStudent)
		{
			if(count==index)
			{
				printf("\n Data of student(%u)",count+1);
				printf("\n \t The ID : %u",PCurrentStudent->student.ID);
				printf("\n \t The Name : %s",PCurrentStudent->student.name);
				printf("\n \t The Length %f: ",PCurrentStudent->student.length);
				return 0;//to exit if i find index
			}
			count++;
			PCurrentStudent=PCurrentStudent->PNext_student;
		}
		//here the index over length
		printf("\n The index over length of list -->check length first");
	}
	else{
		printf("\n No Student in the list");
	}
}

int Give_Index_ToPrintData_FromEnd(){
	//enter index     1st student--->index=0
	vuint32_t index;
	printf("\n Enter The Index : ");
	fflush(stdin);	fflush(stdout);
	scanf("%u",&index);
	//count to calculate PCurrentStudent jumping
	//counter
	vuint32_t count=0;
	//set pointer to check
	struct SStudent *PCurrentStudent=GPFirst_student;
	struct SStudent *PMainStudent=GPFirst_student;

	//check empty
	if(GPFirst_student)
	{
		boolean check =FALSE;
		//loop until end & make distance between them=index
		while(PCurrentStudent){
			if((!PCurrentStudent->PNext_student)&&count==index){//this to check if the end element = null to print Pmain
																//and this cond make check if index == the end element of list it print and return
				printf("\n Data of student");
				printf("\n \t The ID : %u",PMainStudent->student.ID);
				printf("\n \t The Name : %s",PMainStudent->student.name);
				printf("\n \t The Length %f: ",PMainStudent->student.length);
				return 0;
			}
			//first this cond donot work until count to reach the index to make the difference between two pointer =index
			if(count==index){//check if difference between count and Count_current =index
				PMainStudent=PMainStudent->PNext_student;
				check=TRUE;
				count--;//to make difference const when i reach the difference between the two pointer =index
			}
			count++;
			PCurrentStudent=PCurrentStudent->PNext_student;
		}
		if(check==FALSE){
			printf("\n The index over length of list -->check length first");}

	}else{
		printf("\n No Student in the list");
	}
}
struct SStudent* check_malloc_return() {
	struct SStudent *student = NULL;
	while (!student) {
		student = (struct SStudent *)malloc(sizeof(struct SStudent));
	}
	return student;
}
void print_states(){
	printf("\n----------------------------------------");
	printf("\n Chose from this states");
	printf("\n \t 1- Add Student To list");
	printf("\n \t 2- Delete Student from list");
	printf("\n \t 3- Delete All Student from list");
	printf("\n \t 4- Show All Student in the list");
	printf("\n \t 5- The middle of list");
	printf("\n \t 6- Give index of student");
	printf("\n \t 7- Give index of student from end of list");
	printf("\n \t 8- The Length of list ");
	printf("\n Enter the state : ");//enter state
}
