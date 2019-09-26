/*
 * infotainment.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Taher & Youssef
 */

#include "infotainment.h"

#include <util/delay.h>

/************************************************************************/
/*   Infotainment Array of Ques					   				 	   */
/************************************************************************/
uint8* quesArrPtr[5] ={"5+5 = 10?",
		"4+4 = 20?",
		"3+3 = 88?",
		"1+1=1?",
		"4*5 = 1?"};
/************************************************************************/
/*   Infotainment Answers Array of chars					   			*/
/************************************************************************/
const uint8 answArrPtr[5] = {YES, NO, NO, NO, NO};


static Infotainment_GameState_t Infotainment_State = START;
static uint8 Infotainment_DisplayFlag_2Sec = TRUE;
static uint8 Infotainment_DisplayFlag_5Sec = TRUE;
static uint8 Start_Flag = YES;


void Infotainment_Task(void)
{
	static uint8 key = 0;
	static uint8 i = 0;
	static uint8 QuesFlag = ANSWERED;
	static uint8 result = 0;

	switch(Infotainment_State)
	{
	case START:
		if(Start_Flag == YES)
		{
			LCD_displayString(" wlcm to game :)");
			LCD_gotoRowColumn(2, 1);
			LCD_displayString("press 9 start");
			Start_Flag = NO;
			Infotainment_State = DISPLAY_QS;
		}

		break;

	case DISPLAY_QS:
		if((Keypad_getKey() == 9) && (Start_Flag == NO))
		{
			LCD_clear();
			Start_Flag = YES;
		}

		if(i<6 && QuesFlag == ANSWERED && Start_Flag == YES && Infotainment_DisplayFlag_2Sec == TRUE)
		{
			LCD_clear();
			LCD_displayString(quesArrPtr[i]);
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
					i++;
					key = 0;
					QuesFlag = ANSWERED;
					Infotainment_DisplayFlag_2Sec = FALSE;
				}
				else
				{
					LCD_clear();
					LCD_displayString("WRONG :(");
					i++;
					key = 0;
					QuesFlag = ANSWERED;
					Infotainment_DisplayFlag_2Sec = FALSE;
				}

			}
			else if(key == 3)
			{
				if(answArrPtr[i] == NO)
				{
					LCD_clear();
					LCD_displayString("CORRECT :)");
					result++;
					i++;
					key = 0;
					QuesFlag = ANSWERED;
					Infotainment_DisplayFlag_2Sec = FALSE;
				}
				else
				{
					LCD_clear();
					LCD_displayString("WRONG :(");
					i++;
					key = 0;
					QuesFlag = ANSWERED;
					Infotainment_DisplayFlag_2Sec = FALSE;
				}

			}
			else
			{

			}


			if(i==5)
			{
				Infotainment_State = DISPLAY_RESULT;
			}

		}


		break;

	case DISPLAY_RESULT:
		if( Infotainment_DisplayFlag_2Sec == TRUE)
		{
			LCD_clear();
			LCD_displayString("Your RESULT = ");
			Infotainment_DisplayFlag_2Sec = FALSE;
			LCD_gotoRowColumn(0, 15);
			LCD_DispalyNumber(result);
			Start_Flag = YES;
			i=0;
			Infotainment_State = START;

		}
		break;
	default:break;
	}
}


void Infotainment_Delay_2Sec(void)
{
	Infotainment_DisplayFlag_2Sec = TRUE;
}

void Infotainment_Delay_5Sec(void)
{
	Infotainment_DisplayFlag_5Sec = TRUE;
	Start_Flag = YES;
}
