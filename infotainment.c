#include "STD_TYPES.h"
#include"MACROS.h"
#include "infotanment.h"
#include"keypad.h"
#include"LCD.h"
/************************************************************************/
/*                    Global Variables                                   */
/************************************************************************/
uint8 Infotainment_Status = INFOTAINMENT_IDLE;
/************************************************************************/
/*		Shared Variables   (between Tasks)                              */
/************************************************************************/
static uint8 Infotainment_NewDataFlag_g  ;
static uint8 Infotainment_Result_g ;
static uint8 Infotainment_Question_Index_g ;
static uint8 Infotainment_Score = 0;
extern uint8 value_keypad ;
/************************************************************************/
/*   Questions Array of strings					   					  */
/************************************************************************/
uint8* quesArrPtr[5] = {"5+5 = 10?",
		"4+4 = 20?",
		"3+3 = 88?",
		"1+1=1?",
		"4*5 = 1?"};
/************************************************************************/
/*   Infotainment Answers Array of chars					   					  */
/************************************************************************/
 const uint8 answArrPtr[5] = {YES, NO, NO, NO, NO};
/************************************************************************"
/*						Function Definitions
************************************************************************/

void Infotainment_Start(void)
{
	static uint8 result ;
	Infotainment_Question_Index_g = 0 ;
	Infotainment_Result_g = 0;
	Infotainment_Score =0 ;
	if (value_keypad == YES)
	{
		LCD_clear();
	LCD_displayString("start game");
	Infotainment_Status = INFOTAINMENT_QUESTION;
	Infotainment_NewDataFlag_g = 1u;
	}
	else if (result == NO )
	{
		/*nothing */
	}
}

void Infotainment_PrintQuestion (void)
{

	if (Infotainment_NewDataFlag_g==1u)
	{
	LCD_clearScreen();
	LCD_displayString(quesArrPtr[5]) ;
	Infotainment_Question_Index_g ++;
	Infotainment_Status = INFOTAINMENT_GET_ANSWER ;
	}

	else
	{
		/*Do nothing*/
	}
}

void Infotainment_GetAnswer (void)
{
	if (value_keypad == YES)
	{
	Infotainment_Result_g = 'Y' ;
	Infotainment_NewDataFlag_g = 1u;
	Infotainment_Status = INFOTAINMENT_SCORE ;
	}
	else if (value_keypad == NO)
	{
	Infotainment_Result_g = 'N' ;
	Infotainment_NewDataFlag_g = 1u;
	Infotainment_Status = INFOTAINMENT_SCORE ;
	}
	else
	{
		//Infotainment_NewDataFlag_g = 0u;
	}

}

void Infotainment_ScoreDisplay (void)
{


	if (Infotainment_Result_g == answArrPtr[Infotainment_Question_Index_g -1])
	 {
		 Infotainment_Score ++ ;
		 LCD_clearScreen();
		 LCD_displayString(" Correct:)");
		 Infotainment_NewDataFlag_g = 1u;
	 }
	 else
	 {
		 LCD_clearScreen();
		 LCD_displayString(" Wrong :(");
		 Infotainment_NewDataFlag_g = 1u;
	 }
	 if (Infotainment_Question_Index_g == INFOTAINMENT_NUMBER_OF_QUESTIONS)
	 {
		 Infotainment_Status = INFOTAINMENT_FINAL ;

	 }
	 else if (Infotainment_Question_Index_g < INFOTAINMENT_NUMBER_OF_QUESTIONS)
	 {
		 Infotainment_Status = INFOTAINMENT_QUESTION ;
	 }
}

void Infotainment_FinalScore(void)
{
	LCD_clearScreen();
	LCD_displayString(" Final Score = ");
	integer_to_string(Infotainment_Score);
	Infotainment_NewDataFlag_g = 0u;
	Infotainment_Status = INFOTAINMENT_IDLE ;
}
