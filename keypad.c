/*
 * keypad.c
 *
 *  Created on: Apr 23, 2019
 *      Author: Khaled
 */

#include"STD_TYPES.h"
#include"Macros.h"
#include"Dio.h"
#include "util/delay.h"
#include "keypad.h"
uint8 Ci = 0;
uint8 Ri = 0;
static uint8 var=0 ;
static uint8 Press_count 	= 1;
static uint8 Release_count = 10;
static uint8 g_row;
static uint8 g_return;
uint8 ProgramSteps=0;
void ButtonTask(void);
void Keypad_init(void)
{
	/*
		1- ROWS -> O/P , High
		2- CLOS -> I/P , High
	 */

	setBits(KEYPAD_DDR,ROWS_MASK);    // O/P
	setBits(KEYPAD_PORT,ROWS_MASK);   // High

	clearBits(KEYPAD_DDR,COLS_MASK);  // I/P
	setBits(KEYPAD_PORT,COLS_MASK);   // High

}

uint8 Keypad_getKey(void)
{
	/*
		for each row :
			activate this row (0)
			for each column :
				is it activated (0) ?
				yes -> return 4*Ri + Ci + 1
			end
		end
		return 0
	 */



	for(Ri=0 ; Ri<ROWS_NUM ; Ri++)
	{
		setBits(KEYPAD_PORT,ROWS_MASK);
		Clear_Bit(KEYPAD_PORT,(Ri+2));
		//_delay_us(10);  // Wait for a little bit time ->
		for(Ci=0 ; Ci<COLS_NUM ; Ci++)
		{

			if(Get_Bit(KEYPAD_PIN,(5+Ci)) == 0)
			{
				// Unreachable code or Dead code
				OS_voidCreateTask(2,5,ButtonTask);
			}
		}
	}

	return 0;
}
void ButtonTask(void)
{
	static uint8 Button_State = PRE_PRESSED;
	switch(Button_State)
	{
	case PRE_PRESSED:
		if(Get_Bit(KEYPAD_PIN,(5+Ci)) == 0)
		{
			Press_count++;
			if(Press_count == 10)
			{
				Button_State = PRESSED;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		break;
	case PRESSED:
		if(Get_Bit(KEYPAD_PIN,(5+Ci)) == 0)
		{
			var=(3*Ri + Ci + 1);

		}
		Button_State = PRE_RELEASED;
		Press_count = 1;
		break;
	case PRE_RELEASED:
		if(Get_Bit(KEYPAD_PIN,(5+Ci)) == 1)
		{
			Release_count--;
			if(Release_count == 1)
			{
				Button_State = RELEASED;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		break;
	case RELEASED:
		Release_count = 10;
		Button_State = PRE_PRESSED;
		OS_voidDelete(ButtonTask);
		break;
	default : break;
	}
}

