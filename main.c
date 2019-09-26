/*
 * main.c
 *
 *  Created on: Sep 23, 2019
 *      Author: Khaled
 */

#include"STD_TYPES.h"
#include"Macros.h"
#include"Dio.h"
#include"TIMERS_INTERFACE.h"
#include"TIMERS2_INTERFACE.h"
#include "keypad.h"
#include "LCD.h"
#include"os_interface.h"
#include "infotainment.h"

int main(void)
{

	LCD_init();
	Keypad_init();
	OS_voidStart();
	OS_voidCreateTask(Infotainment_Task, 10, 2);
	OS_voidCreateTask(Infotainment_Delay_2Sec, 2000, 3);
	OS_voidCreateTask(Infotainment_Delay_5Sec, 5000, 4);
	OS_voidCreateTask(Keypad_UpdateState, 20, 1);
	os_run();
}
