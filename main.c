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
#define ANSWERED		(1)
#define NOT_ANSWERED	(0)
#define NO				(0)
#define YES				(1)
int main(void)
{
	OS_voidStart();
	Keypad_init();
	LCD_init(); /* initialize LCD */
	OS_voidCreateTask(1,200,Keypad_getKey);
	os_run();

	/*uint8 key = 0;
	uint8 i = 0;
	uint8 QuesFlag = ANSWERED;
	uint8 FinalRes_Flag = NO;
	uint8 Start_Flag = NO;
	static uint8 result = 0;
	LCD_init();
	Keypad_init();
	LCD_clear();
	DIO_SetPinDirection(12,0);
	if( Start_Flag == NO)
			{
				LCD_displayString(" wlcm to game :)");
				LCD_gotoRowColumn(2, 1);
				LCD_displayString("press 9 start");
			}
	while(1)
	{


		if(Keypad_getKey() == 9 && Start_Flag == NO)
		{
			LCD_clear();
			Start_Flag = YES;
		}

		if(i<6 && QuesFlag == ANSWERED && Start_Flag == YES)
		{
			LCD_displayString(quesArrPtr[i]);
			//			TMR_delay(1000);
			QuesFlag = NOT_ANSWERED;
		}

		if((i<6) && (QuesFlag == NOT_ANSWERED))
		{
			key = Keypad_getKey();
			if(1 ==  key)
			{
				if(answArrPtr[i] == YES)
				{
					LCD_clear();
					LCD_displayString("CORRECT :)");
					result++;
					QuesFlag = ANSWERED;
					TMR_delay(1000);
					LCD_clear();
					i++;
					key = 0;
				}
				else
				{
					LCD_clear();
					LCD_displayString("WRONG :(");
					DIO_WritePin(12,1);
					QuesFlag = ANSWERED;
					TMR_delay(1000);
					LCD_clear();
					i++;
					key = 0;
				}

			}
			else if(key == 3)
			{
				if(answArrPtr[i] == NO)
				{
					LCD_clear();
					LCD_displayString("CORRECT :)");
					result++;
					QuesFlag = ANSWERED;
					TMR_delay(1000);
					LCD_clear();
					i++;
					key = 0;
				}
				else
				{
					LCD_clear();
					LCD_displayString("WRONG :(");
					DIO_WritePin(12,1);
					QuesFlag = ANSWERED;
					TMR_delay(1000);
					LCD_clear();
					i++;
					key = 0;
				}
			}
			else
			{

			}

		}
		if(i==5)
		{
			//FinalRes_Flag = YES;
			LCD_displayString("Your RESULT = ");
			LCD_gotoRowColumn(0, 15);
			LCD_DispalyNumber(result);
			TMR_delay(5000);
			result = 0;
			LCD_clear();
			i=0;
			Start_Flag = NO;
			LCD_displayString("press 9 start");
		}
	}*/
}

