/*
 * main.c
 *
 *  Created on: Sep 23, 2019
 *      Author: Khaled
 */

#include"STD_TYPES.h"
#include"Macros.h"
#include"Dio.h"
#include"TIMERS2_INTERFACE.h"
#include "keypad.h"
#include "lcd.h"
int main(void)
{

DIO_SetPinDirection(12,OUTPUT);
	while(1)
	{
		DIO_WritePin(12,1);
		TMR2_delay(1000);
		DIO_WritePin(12,0);
		TMR2_delay(1000);

	}
}
