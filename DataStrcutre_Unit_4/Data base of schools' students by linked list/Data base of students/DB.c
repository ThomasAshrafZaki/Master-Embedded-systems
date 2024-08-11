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
	SStudent_t *PNewStudent;
	SStudent_t *PLastStudent;
	vuint8_t  buf[70];
	//check if list is empty==yes
	if (!GPFirst_student){
		//use this fun to add and check that pointer not point to null(malloc return value )
		check_malloc_return (PNewStudent);
		GPFirst_student=PNewStudent;
	}
	//check if list is empty==no
	else{
		//check until reach to the end record
		PLastStudent=GPFirst_student;
		while(PLastStudent->PNext_student)
			PLastStudent=PLastStudent->PNext_student;

		//use this fun to add and check that pointer not point to null(malloc return value )
		check_malloc_return (PNewStudent);

		PLastStudent->PNext_student=PNewStudent;

		//SET the values of New Record
		//enter ID
		Dprint("\n Enter The ID : ");
		gets(buf);
		PNewStudent->student.ID=atoi(buf);
		//enter name
		Dprint("\n Enter The Name : ");
		gets(buf);
		//enter length
		Dprint("\n Enter The Length : ");
		gets(buf);
		PNewStudent->student.ID=atof(buf);
		//set the next of new recort==null
		PNewStudent->PNext_student=NULL;
	}
}
int DELET_STUDENT(){
	SStudent_t *PSelectStudent=GPFirst_student;
	SStudent_t *PPreviousStudent=NULL;
	vuint32_t ID;
	//enter the ID you want to delete
	Dprint("\n Enter The ID : ");
	scanf("%d",ID);
	//check if list is empty==yes
	if(GPFirst_student)
	{

		while(PSelectStudent)
		{
			//if that is ID wanted to delete
			if(PSelectStudent->student.ID=ID)
			{
				//if it is  1st record
				if(PPreviousStudent){
					GPFirst_student=PSelectStudent->PNext_student;
				}
				//if the list have muti records
				else{
					PPreviousStudent=PSelectStudent->PNext_student;
				}
				//delete the record
				free(PSelectStudent);
				return delete_record;

			}
			PPreviousStudent=PSelectStudent;
			PSelectStudent=PSelectStudent->PNext_student;
		}
		Dprint("Entered ID is error ");
	}
	//check if list is empty==no
	Dprint("The list is empty");
}
void DELET_AllSTUDENT(){
	SStudent_t *PCurrentStudent=GPFirst_student;
	SStudent_t *PTempStudent;
	PCurrentStudent=GPFirst_student;
	//loop on the list until NUll
	while (PCurrentStudent->PNext_student){
		PTempStudent=PCurrentStudent;
		PCurrentStudent=PCurrentStudent->PNext_student;
		free(PTempStudent);
	}
	PCurrentStudent=NULL;
}
void Show_List(){
	SStudent_t *PCurrentStudent=GPFirst_student;
	PCurrentStudent=GPFirst_student;
	//loop on the list until NUll
	while (PCurrentStudent->PNext_student){
		int count=1;
		Dprint("\n Data of student(%d)",count);
		Dprint("\n \t The ID : %d",PCurrentStudent->student.ID);
		Dprint("\n \t The Name : %s",PCurrentStudent->student.name);
		Dprint("\n \t The Length %f: ",PCurrentStudent->student.length);
		count++;
	}
}
void Find_MiddleRecord(){
	//set pointer to check
	SStudent_t *PJumpStudent=GPFirst_student;
	SStudent_t *PMainStudent=GPFirst_student;
	//counter
	vuint32_t count=0;
	//check empty
	if(GPFirst_student)
	{
		//if 1 record in the list
		if(PMainStudent->PNext_student==NULL){
			Dprint("\n Data of student(%d)",count+1);
			Dprint("\n \t The ID : %d",PMainStudent->student.ID);
			Dprint("\n \t The Name : %s",PMainStudent->student.name);
			Dprint("\n \t The Length %f: ",PMainStudent->student.length);
		}else if(PMainStudent->PNext_student->PNext_student==NULL){//the list have 2 record -->no middle
			Dprint("\n The list have 2 student ==NO MIDDLE RECORD!!");
		}else{
			//loop to until the end of list
			while(PJumpStudent->PNext_student)
			{
				PMainStudent=PMainStudent->PNext_student;//make PMainStudent --->++
				PJumpStudent=PJumpStudent->PNext_student;//make PJumpStudent --->++
				//i want to make PJumpStudent jump again to make difference with main 2 (this a fast algorithm to find the middle)
				if(PJumpStudent)
					PJumpStudent=PJumpStudent->PNext_student;//make PJumpStudent --->++
				else{//if PJumpStudent ==NULL---<in this state print if length is even
					Dprint("\n Data of student(%d)",count+1);
					Dprint("\n \t The ID : %d",PMainStudent->student.ID);
					Dprint("\n \t The Name : %s",PMainStudent->student.name);
					Dprint("\n \t The Length %f: ",PMainStudent->student.length);
				}
			}//print if the length of list is odd
			Dprint("\n Data of student(%d)",count+1);
			Dprint("\n \t The ID : %d",PMainStudent->student.ID);
			Dprint("\n \t The Name : %s",PMainStudent->student.name);
			Dprint("\n \t The Length %f: ",PMainStudent->student.length);

		}
	}else{
		Dprint("\n No Student in the list");
	}

}
int Find_Length(SStudent_t * first_student){//by recursion function
	if(GPFirst_student){
		if(first_student)
			return 1+Find_Length(first_student->PNext_student);//count the length when returning 1+1+1....
	}
	else{
		Dprint("\n No Student in the list");
		return 0;//no record
	}
}
void Give_Index_ToPrintData(){
	//enter index   1st student--->index=0
	vuint32_t index;
	Dprint("\n Enter The Index : ");
	scanf("%d",index);
	//counter
	vuint32_t count=0;
	//set pointer to check
	SStudent_t *PCurrentStudent=GPFirst_student;
	//check empty
	if(GPFirst_student)
	{
		//loop to get the exactly index
		while(count<=index)
		{
			if(count==index)
			{
				Dprint("\n Data of student(%d)",count+1);
				Dprint("\n \t The ID : %d",PCurrentStudent->student.ID);
				Dprint("\n \t The Name : %s",PCurrentStudent->student.name);
				Dprint("\n \t The Length %f: ",PCurrentStudent->student.length);
				break;
			}
			count++;
			PCurrentStudent=PCurrentStudent->PNext_student;
		}
		//here the index over length
		Dprint("\n The index over length of list -->check length first");
	}
	else{
		Dprint("\n No Student in the list");
	}
}

void Give_Index_ToPrintData_FromEnd(){
	//enter index     1st student--->index=0
	vuint32_t index;
	Dprint("\n Enter The Index : ");
	scanf("%d",index);
	//count to calculate PCurrentStudent jumping
	//counter
	vuint32_t count_current=0;
	//set pointer to check
	SStudent_t *PCurrentStudent=GPFirst_student;
	SStudent_t *PMainStudent=GPFirst_student;
	//counter of Pmain
	vuint32_t count=0;
	//check empty
	if(GPFirst_student)
	{
		boolean check;//to check if index in the range
		//loop until end & make distance between them=index
		while(PCurrentStudent){
			//check if difference between count and Count_current =index
			if(count_current-count==index){
				PMainStudent=PMainStudent->PNext_student;
				PCurrentStudent=PCurrentStudent->PNext_student;
				count++;
				check=TRUE;
			}
			else
				PCurrentStudent=PCurrentStudent->PNext_student;
		}
		if(check=TRUE){
			Dprint("\n Data of student(%d)",count+1);
			Dprint("\n \t The ID : %d",PMainStudent->student.ID);
			Dprint("\n \t The Name : %s",PMainStudent->student.name);
			Dprint("\n \t The Length %f: ",PMainStudent->student.length);
		}
		else
			{
			Dprint("\n The index over length of list -->check length first");
			count_current++;
			}

	}else{
		Dprint("\n No Student in the list");
	}
}
void check_malloc_return (SStudent_t *student){
	//use this fun to add and check that pointer not point to null(malloc return value )
	while (!student){
		student=malloc(sizeof(SStudent_t));
	}
}
void print_states(){
	Dprint("Chose from this states");
	Dprint("\n \t 1- Add Student To list");
	Dprint("\n \t 2- Delete Student from list");
	Dprint("\n \t 3- Delete All Student from list");
	Dprint("\n \t 4- Show All Student in the list");
	Dprint("\n \t 5- The middle of list");
	Dprint("\n \t 6- Give index of student");
	Dprint("\n \t 7- Give index of student from end of list");
	Dprint("\n \t 8- The Length of list ");
	Dprint("\n----------------------------------------------------- ");
}
