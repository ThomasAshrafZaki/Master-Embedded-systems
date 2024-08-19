/*
 * main.c
 *
 *  Created on: Aug 11, 2024
 *      Author: thomas ashraf zaki
 */

#include "platform_t.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#include "DB.h"
int main(void)
{
	while(1){
		int state_num;
		print_states();
		fflush(stdin);fflush(stdout);
		scanf("%d",&state_num);
		printf("\n----------------------------------------------------- ");
		switch(state_num){
		case 1:{
			ADD_STUDENT();
			break;
		}
		case 2:{
			DELET_STUDENT();
			break;
		}
		case 3:{
			DELET_AllSTUDENT();
			break;
		}
		case 4:{
			Show_List();
			break;
		}
		case 5:{
			Find_MiddleRecord();
			break;
		}
		case 6:{
			printf("\n the first student--->index=0");
			Give_Index_ToPrintData();
			break;
		}
		case 7:{
			printf("\n the end student--->index=0");
            Give_Index_ToPrintData_FromEnd();
            break;
		}
		case 8:{
			printf("\n The length = %d",Find_Length(GPFirst_student));
			break;
		}
		default:{
			printf("\n The State NOT FOUND!!");
		}
		}

	}
	return 0;
}
