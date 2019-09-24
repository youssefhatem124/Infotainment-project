/*
// * lcd.c
// *
// *  Created on: Apr 23, 2019
// *      Author: Khaled
// */
#include"Macros.h"
#include"STD_TYPES.h"
#include"Dio.h"
#include "LCD.h"
#include"TIMERS2_INTERFACE.h"

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
 * Function Name:	LCD_init
 *
 * Description:
 *
 * Inputs:
 *
 * Outputs:
 *
 * Return:
 *******************************************************************************/
void LCD_init (void){
	/* Data Direction Configuration */
	DDRA = 0xFF;
	TMR2_delay(1);
	/* Initialize LCD to work in 4_bit mode */
	LCD_sendCommand(Init_4bit_1);
	TMR2_delay(1);
	LCD_sendCommand(Init_4bit_2);
	TMR2_delay(1);
	LCD_sendCommand(FunctionSet4bit);

	/* LCD Initialization */
	LCD_sendCommand(Return_home); /* Start from home Position */
	TMR2_delay(1);
	LCD_sendCommand(Displayon_Cursoroff);  /* LCD display On */
	TMR2_delay(1);
	LCD_sendCommand(Display_noshift); /*  mode set */
	TMR2_delay(1);
	LCD_sendCommand(Clear_display); /* Clear LCD display */
	TMR2_delay(1);
}

/*******************************************************************************
 * Function Name:	LCD_sendCommand
 *
 * Description:
 *
 * Inputs:
 *
 * Outputs:
 *
 * Return:
 *******************************************************************************/
void LCD_sendCommand(uint8 command){
	/* Control Signals Configuration */
	DIO_WritePin(Register_Select,LOW);  /* Select instruction register */
	DIO_WritePin(Read_Write,LOW);		/* Write operation */
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	TMR2_delay(2);
	/* Sending High nibble */
	PORTA = (PORTA & 0x0F) | (command & 0xF0);
	TMR2_delay(1);
	DIO_WritePin(Enable_LCD,LOW);       /* Disable Signal */
	TMR2_delay(1);
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	TMR2_delay(1);

	/* Sending Low nibble */
	PORTA = (PORTA & 0x0F) | ((command & 0x0F) << 4 );
	TMR2_delay(1);
	DIO_WritePin(Enable_LCD,LOW);       /* Disable Signal */
	TMR2_delay(1);
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	TMR2_delay(1);
}

/*******************************************************************************
 * Function Name:	LCD_displayChar
 *
 * Description:
 *
 * Inputs:
 *
 * Outputs:
 *
 * Return:
 *******************************************************************************/
void LCD_displayChar(uint8 character){
	/* Control Signals Configuration */
	DIO_WritePin(Register_Select,HIGH);  /* Select data register */
	DIO_WritePin(Read_Write,LOW);		/* Write operation */
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	TMR2_delay(1);
	/* Sending High nibble */
	PORTA = (PORTA & 0x0F) | (character & 0xF0);
	TMR2_delay(1);
	DIO_WritePin(Enable_LCD,LOW);       /* Disable Signal */
	TMR2_delay(1);
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	TMR2_delay(1);

	/* Sending low nibble */
	PORTA = (PORTA & 0x0F) | ((character & 0x0F) << 4 );
	TMR2_delay(1);
	DIO_WritePin(Enable_LCD,LOW);       /* Disable Signal */
	TMR2_delay(1);
	DIO_WritePin(Enable_LCD,HIGH);		/* Enable Signal */
	TMR2_delay(1);
}

/*******************************************************************************
 * Function Name:	LCD_gotoRowColumn
 *
 * Description:
 *
 * Inputs:
 *
 * Outputs:
 *
 * Return:
 *******************************************************************************/
void LCD_gotoRowColumn(uint8 LINE,uint8 COLUMN){
	if ( ( COLUMN > COLUMN_MIN ) && ( COLUMN <= COLUMN_MAX ) ){
		switch (LINE)
		{
			case LINE_1 :	LCD_sendCommand( ( lcd_line_1_address ) + ( COLUMN ) );
							break;

			case LINE_2 :	LCD_sendCommand( ( lcd_line_2_address ) + ( COLUMN ) );
							break;

			default :		break;
		}
	}else{
		/* Do Nothing */
	}

}

/*******************************************************************************
 * Function Name:	LCD_displayString
 *
 * Description:
 *
 * Inputs:
 *
 * Outputs:
 *
 * Return:
 *******************************************************************************/
void LCD_displayString(uint8 string[]){
	uint8 iterator = 0;
	while(string[iterator] != '\0')
	{
		LCD_displayChar(string[iterator]);
		iterator++;
	}
}

/*******************************************************************************
 * Function Name:	LCD_displayStringRowColumn
 *
 * Description:
 *
 * Inputs:
 *
 * Outputs:
 *
 * Return:
 *******************************************************************************/
void LCD_displayStringRowColumn(uint8 string[],uint8 row, uint8 column){
	LCD_gotoRowColumn(row,column);
	LCD_displayString(string);
}


/*******************************************************************************
 * Function Name:	LCD_clear
 *
 * Description:
 *
 * Inputs:
 *
 * Outputs:
 *
 * Return:
 *******************************************************************************/
void LCD_clear(void){
	LCD_sendCommand(Clear_display);
	TMR2_delay(100);
	LCD_sendCommand(Return_home);
}




// a function to reverse a string
void reverse (uint8 *str, uint8 length)
{
	uint8 start = 0;
	uint8 end = length-1;
	while( start < end )
	{
		uint8 temp = str[start] ;

		str[start] = str[end];

		str[end] = temp;

		start++;
		end--;
	}

}

uint8* integer_to_string (sint32 number,uint8* str,uint8 base){
	// index for length

	uint8 i = 0;
	uint8 isNegative = 0;

	// Handle 0 explicitely

	if (number == 0)
	{
		str[i++] = '0';
		str[i] = '\0';  // the end of the string
		return str;
	}

	// negative numbers are handled only with
	// base 10. Otherwise numbers are considered unsigned

	if (number <0 && base ==10)
	{
		isNegative = 1;
		number = -number; // to get the absolute value of the number
	}

	while (number != 0)
	{

		uint8 remainder = number % base ;
		if (remainder > 9)
		{
			str[i++] = (remainder-10) + 'A';  // for hexa-decimal only

		}
		else
		{
			str[i++] = remainder + '0';
		}
		number=number/base;
	}

	if (isNegative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';  // the end of the string

	reverse(str,i); // where i  index for the length of the string

	return str;
}

 void LCD_DispalyNumber(uint32 x)
{
	uint32 y = 1;
	if (x == 0)
	{
		LCD_displayChar('0');
	}
	if (x < 0) {
		LCD_displayChar('-');
		x *= -1;
	}
	while (x != 0) {
		y = ((y * 10) + (x % 10));
		x = (x / 10);
	}
	while (y != 1) {
		LCD_displayChar((y % 10) + 48);
		y = (y / 10);
	}
}

