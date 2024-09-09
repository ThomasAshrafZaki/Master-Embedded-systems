/*
 * student.c
 *
 *  Created on: Aug 19, 2024
 *      Author: thomas ashraf
 */
#include "stdio.h"
#include "student_information.h"
#include "platform_t.h"
#include "stdbool.h"

//global num to select state
extern int check_while;
extern element_type* buf_ptr;
int check_file=0;
//APIS
void Add_Student_from_File(fifo_buffer_t* fifo_buffer) {
	if(check_file){
		printf("\n[ERROR]You Add this data before");
		return;
	}
	FILE *file = fopen("students.txt", "r");
	if (file == NULL) {
		printf("\n[Error] The File Is Empty");
		return;
	}
	char line[256];
	element_type item;
	loop:
	while (fgets(line, sizeof(line), file)) {
		enter_student(line, &item);
		//========check if he enter same id=============
		fifo_buffer_t temp=*fifo_buffer;//this cannot be pointer becouase it reach to reference(*-->becouse i use fifo_buffer_t temp not fifo_buffer_t*temp)
		while(temp.count)
		{
			if(item.unique_roll==(temp.tail->unique_roll)){
				printf("\n[ERROR]NOT ADDING %s %s that have same id of %s %s",item.first_name,item.last_name,temp.tail->first_name,temp.tail->last_name);
				printf("\n==========================");
				goto loop;
			}
			else{
				temp.count--;
				temp.tail++;//to loop in buffer checking the unique_roll
			}
		}
		if(FIFO_ENQUEUE(fifo_buffer,item)==fifo_full)//if buffer full
		{
			printf("\n[ERROR] the list is full please delete student");
		}
		else{//i want to increase length every time when add (to donot take space in memory the user donnot use it now)
			increment_length_buf(fifo_buffer);//call
			printf("\n[INFO]ADDING %s %s to the list",item.first_name,item.last_name);
			printf("\n==========================");
		}
	}
	check_file=1;
	//to count and print the remain
	Count_Students(fifo_buffer);//call
	fclose(file);
}

//-------------------------------------------------
void Add_Student_Manualy(fifo_buffer_t* fifo_buffer){
	//init the parameters
	element_type item ;
	//enter First Name
	printf("\n Enter First Name : ");
	fflush(stdin);fflush(stdout);
	scanf("%s",item.first_name);
	//enter last Name
	printf("\n Enter last Name : ");
	fflush(stdin);fflush(stdout);
	scanf("%s",item.last_name);
	//enter unique roll
	printf("\n Enter unique roll : ");
	fflush(stdin);fflush(stdout);
	scanf("%u",&item.unique_roll);
	//========check if he enter same id=============
	fifo_buffer_t temp=*fifo_buffer;//this cannot be pointer becouase it reach to reference(*-->becouse i use fifo_buffer_t temp not fifo_buffer_t*temp)

	while(temp.count)
	{
		if(item.unique_roll==(temp.tail->unique_roll)){
			printf("\n [ERROR]NOT ADD %s %s that have same id of %s %s",item.first_name,item.last_name,temp.tail->first_name,temp.tail->last_name);
			return;
		}
		else{
			temp.count--;
			temp.tail++;//to loop in buffer checking the unique_roll
		}
	}
	//==================
	//enter GPA
	printf("\n Enter GPA : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&item.GPA);
	//enter ID Courses
	printf("\n Enter ID Courses");
	//loop to enter 5 courses
	for(int i=0;i<5;i++)
	{
		printf("\n \t Enter ID Course(%d) : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%u",&item.ID_Courses[i]);
		//to check if this student add the same id course twice
		for(int j=0;j<i;j++)
		{
			if(item.ID_Courses[i]==item.ID_Courses[j])// to check that this not the same element in the array(i want to check with the anthors )
			{
				printf("\n-------------------------");
				printf("\n[ERROR] this id course added before-->enter the true id course");
				printf("\n-------------------------");
				i--;//to return enter this element
				continue;// go to enter again
			}
		}
	}
	printf("\n==========================");
	if(FIFO_ENQUEUE(fifo_buffer,item)==fifo_full)//if buffer full
	{
		printf("\n[ERROR] the list is full please delete student");
	}
	else{//i want to increase length every time when add (to donot take space in memory the user donnot use it now)
		increment_length_buf(fifo_buffer);//call
		printf("\n[INFO]Student Details is added ");
		printf("\n==========================");
		//to count and print the remain
		Count_Students(fifo_buffer);//call
	}
}
//-------------------------------------------------
void Find_by_id(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		//variable of id
		unsigned int id;
		//enter id to find student
		printf("\n [INFO] Enter unique roll to find student: ");
		fflush(stdin);fflush(stdout);
		scanf("%u",&id);
		//========check if this ID is found=============
		fifo_buffer_t temp=*fifo_buffer;//this cannot be pointer becouase it reach to reference(*-->becouse i use fifo_buffer_t temp not fifo_buffer_t*temp)

		while(temp.count)
		{
			if(id==(temp.tail->unique_roll)){
				printf("\n ==============================");
				printf("\n This is student details :");
				printf("\n The first name : %s",temp.tail->first_name);
				printf("\n--------------------------------------------");
				printf("\n The last name : %s",temp.tail->last_name);
				printf("\n--------------------------------------------");
				printf("\n The unique roll : %u",temp.tail->unique_roll);
				printf("\n--------------------------------------------");
				printf("\n The GPA : %f",temp.tail->GPA);
				printf("\n--------------------------------------------");
				printf("\n ID Courses is");
				//loop to enter 5 courses
				for(int i=0;i<5;i++)
				{
					printf("\n \t the Course(%d) id : %u ",i+1,temp.tail->ID_Courses[i]);
				}
				return;
			}
			else{
				temp.count--;
				temp.tail++;//to loop in buffer checking the unique_roll
			}
		}

		//==================
		printf("\n[ERROR]This ID = (%d) NOT FOUND",id);
	}
	else{
		printf("\n[ERROR] NO Student added");
	}
}
//-------------------------------------------------
void find_by_FirstName(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		//array of first name
		unsigned char first_name[30];
		//enter first name to find student
		printf("\n [INFO] Enter first name to find student: ");
		fflush(stdin);fflush(stdout);
		scanf("%s",first_name);
		//========check if this first name is found=============
		fifo_buffer_t temp=*fifo_buffer;//this cannot be pointer becouase it reach to reference(*-->becouse i use fifo_buffer_t temp not fifo_buffer_t*temp)
		boolean check =FALSE;//to check if never have this
		while(temp.count)
		{

			if(strcmp(first_name, temp.tail->first_name)==0){//strcmp compare between two string to check if it return 0 it is equal
				check=TRUE;//becouse i find item that have the searched name
				printf("\n ==============================");
				printf("\n This is student details :");
				printf("\n The first name : %s",temp.tail->first_name);
				printf("\n--------------------------------------------");
				printf("\n The last name : %s",temp.tail->last_name);
				printf("\n--------------------------------------------");
				printf("\n The unique roll : %u",temp.tail->unique_roll);
				printf("\n--------------------------------------------");
				printf("\n The GPA : %f",temp.tail->GPA);
				printf("\n--------------------------------------------");
				printf("\n ID Courses is");
				//loop to enter 5 courses
				for(int i=0;i<5;i++){
					printf("\n \t the Course(%d) id : %u ",i+1,temp.tail->ID_Courses[i]);
				}
				printf("\n=================================");
			}
			//i made this becouse it will be infinte without those ,they help to enter the next item without go to else
			temp.count--;
			temp.tail++;
			//i donot make return becouse we can find two student that have same first name
		}

		//==================
		if(!check)
			printf("\n[ERROR]This first name : (%s) NOT FOUND",first_name);
	}
	else{
		printf("\n[ERROR] NO Student added");
	}
}
//-------------------------------------------------
void find_by_LastName(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		//array of last name
		unsigned char last_name[30];
		//enter last name to find student
		printf("\n [INFO] Enter last name to find student: ");
		fflush(stdin);fflush(stdout);
		scanf("%s",last_name);
		//========check if this last name is found=============
		fifo_buffer_t temp=*fifo_buffer;//this cannot be pointer becouase it reach to reference(*-->becouse i use fifo_buffer_t temp not fifo_buffer_t*temp)
		boolean check =FALSE;//to check if never have this
		while(temp.count)
		{

			if(strcmp(last_name, temp.tail->last_name)==0){//strcmp compare between two string to check if it return 0 it is equal
				check=TRUE;//becouse i find item that have the searched name
				printf("\n ==============================");
				printf("\n This is student details :");
				printf("\n The first name : %s",temp.tail->first_name);
				printf("\n--------------------------------------------");
				printf("\n The last name : %s",temp.tail->last_name);
				printf("\n--------------------------------------------");
				printf("\n The unique roll : %u",temp.tail->unique_roll);
				printf("\n--------------------------------------------");
				printf("\n The GPA : %f",temp.tail->GPA);
				printf("\n--------------------------------------------");
				printf("\n ID Courses is");
				//loop to enter 5 courses
				for(int i=0;i<5;i++){
					printf("\n \t the Course(%d) id : %u ",i+1,temp.tail->ID_Courses[i]);
				}
				printf("\n=================================");
			}
			//i made this becouse it will be infinte without those ,they help to enter the next item without go to else
			temp.count--;
			temp.tail++;
			//i donot make return becouse we can find two student that have same last name
		}

		//==================
		if(!check)
			printf("\n[ERROR]This last name : (%s) NOT FOUND",last_name);
	}
	else{
		printf("\n[ERROR] NO Student added");
	}
}
//-------------------------------------------------
void find_by_GPA(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		//variable of GPA
		float GPA;
		//enter GPA to find student
		printf("\n [INFO] Enter GPA to find student: ");
		fflush(stdin);fflush(stdout);
		scanf("%f",&GPA);
		//========check if this GPA is found=============
		fifo_buffer_t temp=*fifo_buffer;//this cannot be pointer becouase it reach to reference(*-->becouse i use fifo_buffer_t temp not fifo_buffer_t*temp)
		boolean check =FALSE;//to check if never have this
		while(temp.count)
		{

			if(GPA==temp.tail->GPA){
				check=TRUE;//becouse i find item that have the searched name
				printf("\n ==============================");
				printf("\n This is student details :");
				printf("\n The first name : %s",temp.tail->first_name);
				printf("\n--------------------------------------------");
				printf("\n The last name : %s",temp.tail->last_name);
				printf("\n--------------------------------------------");
				printf("\n The unique roll : %u",temp.tail->unique_roll);
				printf("\n--------------------------------------------");
				printf("\n The GPA : %f",temp.tail->GPA);
				printf("\n--------------------------------------------");
				printf("\n ID Courses is");
				//loop to enter 5 courses
				for(int i=0;i<5;i++){
					printf("\n \t the Course(%d) id : %u ",i+1,temp.tail->ID_Courses[i]);
				}
				printf("\n=================================");
			}
			//i made this becouse it will be infinte without those ,they help to enter the next item without go to else
			temp.count--;
			temp.tail++;
			//i donot make return becouse we can find two student that have same last name
		}

		//==================
		if(!check)
			printf("\n[ERROR]This GPA : (%f) NOT FOUND",GPA);
	}
	else{
		printf("\n[ERROR] NO Student added");
	}
}
//-------------------------------------------------
void find_by_Registered_Courses(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		//array of id course
		unsigned int id_course;
		//enter id course to find student
		printf("\n [INFO] Enter id course to find student: ");
		fflush(stdin);fflush(stdout);
		scanf("%u",&id_course);
		//========check if this id course is found=============
		fifo_buffer_t temp=*fifo_buffer;//this cannot be pointer becouase it reach to reference(*-->becouse i use fifo_buffer_t temp not fifo_buffer_t*temp)
		boolean check =FALSE;//to check if never have this
		while(temp.count)
		{
			for(int i=0;i<5;i++){//to check the id from the 5 courses
				if(id_course==temp.tail->ID_Courses[i]){
					check=TRUE;//becouse i find item that have the searched name
					printf("\n ==============================");
					printf("\n This is student details :");
					printf("\n The first name : %s",temp.tail->first_name);
					printf("\n--------------------------------------------");
					printf("\n The last name : %s",temp.tail->last_name);
					printf("\n--------------------------------------------");
					printf("\n The unique roll : %u",temp.tail->unique_roll);
					printf("\n--------------------------------------------");
					printf("\n The GPA : %f",temp.tail->GPA);
					printf("\n--------------------------------------------");
					printf("\n ID Courses is");
					//loop to enter 5 courses
					for(int j=0;j<5;j++){// becouse there ara i in outter loop
						printf("\n \t the Course(%d) id : %u ",j+1,temp.tail->ID_Courses[j]);
					}
					printf("\n=================================");
				}
			}
			//i made this becouse it will be infinte without those ,they help to enter the next item without go to else
			temp.count--;
			temp.tail++;
			//i donot make return becouse we can find two student that have same id course
		}
		//==================
		if(!check)
			printf("\n[ERROR]This id course : (%u) NOT FOUND",id_course);
	}
	else{
		printf("\n[ERROR] NO Student added");
	}
}
//-------------------------------------------------
void Count_Students(fifo_buffer_t* fifo_buffer){
	printf("\n[INFO]the total number of student =  %d",fifo_buffer->count);
	printf("\n[INFO]you can up to 50 student");
	printf("\n[INFO]Now you add %d student ",50-fifo_buffer->count);
}
//-------------------------------------------------
void Delete_student(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		//variable of id
		unsigned int id;
		//enter id to delete student
		printf("\n [INFO] Enter unique roll to delete student: ");
		fflush(stdin);fflush(stdout);
		scanf("%u",&id);
		//========check if this ID is found=============
		//you can fifo_buffer_t temp=*fifo_buffer buuuut i prefere to use that to protect stack from alot of variables i donnot use
		vuint32_t count=fifo_buffer->count;
		element_type* temp=fifo_buffer->tail;
		while(count)
		{
			if(id==(temp->unique_roll)){//condition of check id
				//printf("\n %p       %p",temp,fifo_buffer->head);-->to know where is temp and head
				while((fifo_buffer->head-1)!=temp){//now i detect the space i want to delete .i will not use free becouse i cannot reach to this space again
					//i slove that by take the next value temp+1 to temp until reach to head-1 that can i touch the end value
					*(temp)=*(temp+1);
					temp++;
				}
				fifo_buffer->head--;//after that condition is fail and make head-- to return one step becouse the last two element is equal
				fifo_buffer->length--;//i decrement the length becouse i delete one element
				printf("\n [INFO] The student with this ID : %u is deleted",id);
				fifo_buffer->count--;
				//printf("\n %p     %p",temp,fifo_buffer->head);here temp==head
				//i want to fill this free area with
				return;
			}
			else{
				count--;//i make it value that take the value of fifo_buffer->count becouse i donot need to
				temp++;//to loop in buffer checking the unique_roll
			}
		}
		//==================
		printf("\n[ERROR]This ID = (%d) NOT FOUND",id);
	}
	else{
		printf("\n[ERROR] NO Student added");
	}
}
//-------------------------------------------------
void Delete_All_Student(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		fifo_buffer_t* temp=fifo_buffer;
		while(temp->count){
			temp->tail=fifo_buffer->tail;
			fifo_buffer->tail++;
			free(temp->tail);
			temp->count--;
		}
		printf("\n [INFO] ALL Student deleted.");
	}
	else{
		printf("\n[ERROR] NO Student added");}
}
//-------------------------------------------------
void Updata_Data_of_student(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		//variable of id
		unsigned int id;
		//enter id to delete student
		printf("\n [INFO] Enter unique roll to update data of student: ");
		fflush(stdin);fflush(stdout);
		scanf("%u",&id);
		//========check if this ID is found=============
		//you can fifo_buffer_t temp=*fifo_buffer buuuut i prefere to use that to protect stack from alot of variables i donnot use
		vuint32_t count=fifo_buffer->count;
		element_type* temp=fifo_buffer->tail;
		while(count)
		{
			if(id==(temp->unique_roll)){//condition of check id
				printf("\n [INFO] Each of this you want to update");
				printf("\n \t 1- First Name");
				printf("\n \t 2- Second Name");
				printf("\n \t 3- ID");
				printf("\n \t 4- GPA");
				printf("\n \t 5- Registered Courses");
				//variable of check
				unsigned int check;
				//enter num to update
				printf("\n [INFO] Enter number of the last list : ");
				fflush(stdin);fflush(stdout);
				scanf("%u",&check);
				//to chose each of them i will update
				switch(check){
				case 1:{
					printf("\n [INFO] update the first name : ");
					fflush(stdin);fflush(stdout);
					scanf("%s",temp->first_name);
					break;
				}
				case 2:{
					printf("\n [INFO] update the last name : ");
					fflush(stdin);fflush(stdout);
					scanf("%s",temp->last_name);
					break;
				}
				case 3:{
					printf("\n [INFO] update the ID : ");
					fflush(stdin);fflush(stdout);
					scanf("%u",&temp->unique_roll);
					break;
				}
				case 4:{
					printf("\n [INFO] update the GPA : ");
					fflush(stdin);fflush(stdout);
					scanf("%f",&temp->GPA);
					break;
				}
				case 5:{
					printf("\n [INFO] update the Registered courses : ");
					for(int i=0;i<5;i++)
					{
						printf("\n \t Enter ID Course(%d) : ",i+1);
						fflush(stdin);fflush(stdout);
						scanf("%u",&temp->ID_Courses[i]);
						//to check if this student add the same id course twice
						for(int j=0;j<i;j++)
						{
							if(temp->ID_Courses[i]==temp->ID_Courses[j])// to check that this not the same element in the array(i want to check with the anthors )
							{
								printf("\n-------------------------");
								printf("\n[ERROR] this id course added before-->enter the true id course");
								printf("\n-------------------------");
								i--;//to return enter this element
								continue;// go to enter again
							}
						}
					}
					break;
				}
				default:{
					printf("\n -------");
					printf("\n [ERROR] You enter invalid number!!!!!");
					printf("\n -------");
					continue;//retrn to while again
				}}
				return;
			}
			else{
				count--;//i make it value that take the value of fifo_buffer->count becouse i donot need to
				temp++;//to loop in buffer checking the unique_roll
			}
		}
		printf("\n[ERROR]This ID = (%d) NOT FOUND",id);//if i donot found the id
	}
	else{
		printf("\n[ERROR] NO Student added");
	}
}
//-------------------------------------------------
void Show_students(fifo_buffer_t* fifo_buffer){
	//check empty
	//-----------------------
	if(fifo_buffer->count){
		fifo_buffer_t temp=*fifo_buffer;//this cannot be pointer becouase it reach to reference(*-->becouse i use fifo_buffer_t temp not fifo_buffer_t*temp)
		while(temp.count)
		{
			printf("\n ==============================");
			printf("\n This is student details :");
			printf("\n The first name : %s",temp.tail->first_name);
			printf("\n--------------------------------------------");
			printf("\n The last name : %s",temp.tail->last_name);
			printf("\n--------------------------------------------");
			printf("\n The unique roll : %u",temp.tail->unique_roll);
			printf("\n--------------------------------------------");
			printf("\n The GPA : %f",temp.tail->GPA);
			printf("\n--------------------------------------------");
			printf("\n ID Courses is");
			//loop to enter 5 courses
			for(int i=0;i<5;i++){
				printf("\n \t the Course(%d) id : %u ",i+1,temp.tail->ID_Courses[i]);
			}
			printf("\n=================================");
			//i made this becouse it will be infinte without those ,they help to enter the next item without go to else
			temp.count--;
			temp.tail++;
			//i donot make return becouse we can find two student that have same last name
		}
	}
	//==================
	else{
		printf("\n[ERROR] NO Student added");
	}
}
//-------------------------------------------------
void increment_length_buf(fifo_buffer_t* fifo_buffer){//to add anther element if you add again by limitting with 50 student
	if(fifo_buffer->count<50){
		fifo_buffer->length++;
		fifo_buffer->size=fifo_buffer->length*sizeof(element_type);
	}
}
//----------------------------------------------------------
void enter_student(char* line, element_type* student) {
	// Assuming the file format is: roll first_name last_name GPA id1 id2 id3 id4 id5
	sscanf(line, "%u %s %s %f %u %u %u %u %u",
			&student->unique_roll,
			student->first_name,
			student->last_name,
			&student->GPA,
			&student->ID_Courses[0],
			&student->ID_Courses[1],
			&student->ID_Courses[2],
			&student->ID_Courses[3],
			&student->ID_Courses[4]);
}
//---------------------------------------------------------
void print_states(){
	printf("\n=======================================");
	printf("\n Chose from this states");
	printf("\n \t 1- Add Student from file");
	printf("\n \t 2- Add Student manually");
	printf("\n \t 3- find student by ID");
	printf("\n \t 4- find student by first name");
	printf("\n \t 5- find student by last name");
	printf("\n \t 6- find student by GPA");
	printf("\n \t 7- find student by registered courses");
	printf("\n \t 8- count the students");
	printf("\n \t 9- delete student ");
	printf("\n \t 10- delete ALl student ");
	printf("\n \t 11- view All student ");
	printf("\n \t 12- update student ");
	printf("\n \t 13- Exit from program ");
	printf("\n Enter the state : ");//enter state
}
void Exit(){
	check_while=0;
	printf("\n Thanks..\n program end!!");
}
//================END=================================
