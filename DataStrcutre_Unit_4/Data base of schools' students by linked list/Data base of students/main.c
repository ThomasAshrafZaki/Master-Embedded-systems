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

void main(void)
{

	while(1){
		print_states();
		int state_num;
		//enter state
		Dprint("\n Enter the num of state : ");
		scanf("%d",state_num);
		Dprint("\n--------------------------------------- ");
		switch(state_num){
		case1:{
			ADD_STUDENT();
			break;
		}
		case2:{
			DELET_STUDENT();
			break;
		}
		case3:{
			DELET_AllSTUDENT();
			break;
		}
		case4:{
			Show_List();
			break;
		}
		case5:{
			Find_MiddleRecord();
			break;
		}
		case6:{
			Give_Index_ToPrintData();
			break;
		}
		case7:{
			Give_Index_ToPrintData_FromEnd();
			break;
		}
		case8:{
			int length;
			length=Find_Length(GPFirst_student);
			Dprint("The length = %d",length);
			break;
		}
		default:{
			Dprint("The State NOT FOUND!!");
		}
		}

	}
}
