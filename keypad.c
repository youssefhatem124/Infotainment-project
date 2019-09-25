/*
 * keypad.c
 *
 *  Created on: Apr 23, 2019
 *      Author: Taher & Youssef
 */

#include"STD_TYPES.h"
#include"Macros.h"
#include"Dio.h"
#include "util/delay.h"
#include "keypad.h"

#define SAMPLES_NUM		(2U)
#define PRESSED_LEVEL	(0U)
#define RELEASED_LEVEL	(1U)


static uint8 KeyPadButton[ROWS_NUM][COLS_NUM][SAMPLES_NUM];
static uint8 KeyPadButton_State[ROWS_NUM][COLS_NUM];


void Keypad_init(void)
{
	uint8 Ci = 0;
	uint8 Ri = 0;

	/*
		1- ROWS -> O/P , High
		2- CLOS -> I/P , High
	 */

	setBits(KEYPAD_DDR,ROWS_MASK);    // O/P
	setBits(KEYPAD_PORT,ROWS_MASK);   // High

	clearBits(KEYPAD_DDR,COLS_MASK);  // I/P
	setBits(KEYPAD_PORT,COLS_MASK);   // High

	for(Ri=0 ; Ri < ROWS_NUM ; Ri++)
	{
		for(Ci = 0U; Ci < COLS_NUM; Ci++)
		{
			KeyPadButton[Ri][Ci][0] = RELEASED_LEVEL;
			KeyPadButton[Ri][Ci][1] = RELEASED_LEVEL;
			KeyPadButton_State[Ri][Ci] = RELEASED;
		}
	}
}


void Keypad_UpdateState(void)
{
	uint8 Ci = 0;
	uint8 Ri = 0;

	for(Ri=0 ; Ri<ROWS_NUM ; Ri++)
	{
		setBits(KEYPAD_PORT,ROWS_MASK);
		Clear_Bit(KEYPAD_PORT,(Ri+2));

		for(Ci=0 ; Ci<COLS_NUM ; Ci++)
		{
			KeyPadButton[Ri][Ci][0] = KeyPadButton[Ri][Ci][1];

			KeyPadButton[Ri][Ci][1] = Get_Bit(KEYPAD_PIN,(5+Ci));
			switch(KeyPadButton_State[Ri][Ci])
			{
			case RELEASED:
				if((KeyPadButton[Ri][Ci][0] == PRESSED_LEVEL) && (KeyPadButton[Ri][Ci][1] == PRESSED_LEVEL))
				{
					KeyPadButton_State[Ri][Ci] = PRE_PRESSED;
				}
				else
				{
					/* Do Nothing */
				}
				break;

			case PRE_PRESSED:
				if((KeyPadButton[Ri][Ci][0] == PRESSED_LEVEL) && (KeyPadButton[Ri][Ci][1] == PRESSED_LEVEL))
				{
					KeyPadButton_State[Ri][Ci] = PRESSED;
				}
				else
				{
					/* Do Nothing */
				}
				break;

			case PRESSED:

				if((KeyPadButton[Ri][Ci][0] == RELEASED_LEVEL) && (KeyPadButton[Ri][Ci][1] == RELEASED_LEVEL))
				{
					KeyPadButton_State[Ri][Ci] = PRE_RELEASED;
				}
				else
				{
					/* Do Nothing */
				}
				break;

			case PRE_RELEASED:
				if((KeyPadButton[Ri][Ci][0] == RELEASED_LEVEL) && (KeyPadButton[Ri][Ci][1] == RELEASED_LEVEL))
				{
					KeyPadButton_State[Ri][Ci] = RELEASED;
				}
				else
				{
					/* Do Nothing */
				}
				break;
			default:
				break;
			}

		}
	}
}


uint8 Keypad_getKey(void)
{
	uint8 Ci = 0;
	uint8 Ri = 0;
	uint8 ret_value = 0;

	//		for each row :
	//			activate this row (0)
	//			for each column :
	//				is it activated (0) ?
	//				yes -> return 4*Ri + Ci + 1
	//			end


	for(Ri=0 ; Ri<ROWS_NUM ; Ri++)
	{
		setBits(KEYPAD_PORT,ROWS_MASK);
		Clear_Bit(KEYPAD_PORT,(Ri+2));
		for(Ci=0 ; Ci<COLS_NUM ; Ci++)
		{
			if(KeyPadButton_State[Ri][Ci] == PRE_RELEASED)
			{
				ret_value = (3*Ri + Ci + 1);
			}
			else
			{

			}
		}
	}
	return ret_value;
}


