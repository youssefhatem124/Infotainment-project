/*
 * lcd.c
 *
 *  Created on: Apr 23, 2019
 *      Author: Khaled
 */

#include"STD_TYPES.h"
#include"Macros.h"
#include"Dio.h"
#include "lcd.h"
#include "util/delay.h"


void LCD_Init(void)
{
		//set Pins Directions
		setBits(LCD_DATA_DDR,ALL_OUTPUT);
		Set_Bit(LCD_CONTROL_DDR,E_PIN);
		///////////////////////setBit(LCD_CONTROL_DDR,RW_PIN);
		Set_Bit(LCD_CONTROL_DDR,RS_PIN);

		/* Delay 30ms to ensure the initialization of the LCD driver */
		_delay_ms(30);
		/* Function Set  */
		LCD_SendCommand(FunctionSet8bit);
		_delay_ms(1);
		/* Display ON OFF Control */
		LCD_SendCommand(DisplayOn);
		_delay_ms(1);
		/* Clear Display */
		LCD_SendCommand(Clear_Display);
		_delay_ms(3);
		/* Entry Mode Set  */
		LCD_SendCommand(EntryModeSet);
		_delay_ms(2);
	}





  void LCD_SendCommand(uint8 COM)
{
		/* Set RS to LOW -> to write a command*/
	  	Clear_Bit(LCD_CONTROL_PORT,RS_PIN);

		/* Set R/W to LOW */
	  	////////////////////////clearBit(LCD_CONTROL_PORT,RW_PIN);
		/* Set E to HIGH  */
		Set_Bit(LCD_CONTROL_PORT,E_PIN);

		/* Load Command on Data bus */
		LCD_DATA_PORT=COM;

		/* Set E to LOW */
		Clear_Bit(LCD_CONTROL_PORT,E_PIN);

		/* Wait for E to settle */
		_delay_ms(5);
		/* Set E to HIGH */
		Set_Bit(LCD_CONTROL_PORT,E_PIN);
		/* Delay for 10ms to let the LCD execute command */
		_delay_ms(10);
}




void LCD_WriteCharctr(uint8 DATA)
{
			/* Set RS to HIGH -> to write data*/
			Set_Bit(LCD_CONTROL_PORT,RS_PIN);

			/* Set R/W to LOW */
			/////////////////////////////clearBit(LCD_CONTROL_PORT,RW_PIN);

			/* Set E to HIGH  */
			Set_Bit(LCD_CONTROL_PORT,E_PIN);

			/* Load Command on Data bus */
			LCD_DATA_PORT=DATA;

			/* Set E to LOW */
			Clear_Bit(LCD_CONTROL_PORT,E_PIN);
			/* Wait for E to settle */
			_delay_ms(5);
			/* Set E to HIGH */
			Set_Bit(LCD_CONTROL_PORT,E_PIN);
			/* Delay for 10ms to let the LCD execute command */
			_delay_ms(10);
}


void LCD_DispString(uint8* str)
{
		uint8 ind = 0;
		while(str[ind]!= '\0')
		{
			LCD_WriteCharctr(str[ind]);
			ind++;
		}
}
void Gotoxy (uint8 Y,uint8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	LCD_SendCommand(X+127); /* DDRAM Address "1000 0000",the first
		    								position in first line is 0x00 -1 equals X
		    							    then add X to DDRAM Address equals 127
		    								so when you add one
		    								it will be the first address
		    								in the first line in the
		    								panel and you can write in*/
		    break;
		    case 2:
		    	LCD_SendCommand(X+191);/* DDRAM Address "1000 0000",the first
		    								position in second line is 0x40 -1 equals X
		    								then add X to DDRAM Address equals 127
		    								so when you add one
		    								it will be the first address
		    								in the second line in the
		    								panel and you can write in*/
		    break;
		    default:
		    break;
	    }
	}
}

void LCD_ShiftDisplayRight(void)
{
	LCD_SendCommand(lcd_ShiftRight);
}

void LCD_ShiftDisplayLeft(void)
{
	LCD_SendCommand(lcd_ShiftLeft);
}

void LCD_Clear(void)
{
	LCD_SendCommand(Clear_Display);
}

