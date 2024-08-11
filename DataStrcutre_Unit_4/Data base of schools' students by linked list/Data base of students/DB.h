/*
 * DB.h
 *
 *  Created on: Aug 11, 2024
 *      Author: thomas ashraf zaki
 */

#ifndef DB_H_
#define DB_H_

#include "platform_t.h"

typedef struct
{
	vuint32_t ID ;
	vuint8_t name[30];
	float length;
}Sdata_t;

//Dprint to solve debug issue in eclipse
#define Dprint(...)    {fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}
typedef struct SStudent
{
	Sdata_t student;
	struct SStudent * PNext_student;
}SStudent_t;

SStudent_t * GPFirst_student;

//states
typedef enum {
	done,
	delete_record,
	add_record,
	empty,
	non_empty
}DB_states_t;
//APIS
void ADD_STUDENT();
int DELET_STUDENT();
void DELET_AllSTUDENT();
void Show_List();
void Find_MiddleRecord();
int Find_Length(SStudent_t * student);
void Give_Index_ToPrintData();
void Give_Index_ToPrintData_FromEnd();
void point_To_NULL(SStudent_t *student);
void print_states();

#endif /* DB_H_ */
