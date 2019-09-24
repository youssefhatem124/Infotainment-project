/*
 * LCD.h
 *
 *  Created on: Sep 24, 2019
 *      Author: Youssef Hatem
 */

///*
// * lcd.h
// *
// *  Created on: Apr 25, 2019
// *      Author: Khaled
// */
#ifndef DRIVERS_LCD_LCD_H_
#define DRIVERS_LCD_LCD_H_


#include <util/delay.h>
#include "Dio.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define Clear_display 0x01
#define Return_home 0x02
#define Display_noshift 0x06
#define Display_shift 0x07
#define Display_off 0x08
#define Displayon_Cursoroff	0x0C
#define Display_on 0x0E
#define Init_4bit_1 0x33
#define Init_4bit_2 0x32
#define FunctionSet4bit 0x28
#define FunctionSet8bit 0x38
#define SET_CGRAM_addr 0x40
#define SET_DDRAM_addr 0x80

#define Register_Select PIN1
#define Read_Write PIN2
#define Enable_LCD PIN3

#define lcd_line_1_address  0x7F
#define lcd_line_2_address  0xBF

#define LINE_1      1
#define LINE_2      2

#define COLUMN_MIN   0
#define COLUMN_MAX   16

 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

 void LCD_init (void);
 void LCD_sendCommand(uint8 command);
 void LCD_displayChar(uint8 character);
 void LCD_displayString(uint8 string[]);
 void LCD_displayStringRowColumn(uint8 string[],uint8 row, uint8 column);
 void LCD_gotoRowColumn(uint8 LINE,uint8 COLUMN);
 void LCD_clear(void);
 void LCD_Write_Integer_Number (sint32 number );
 void LCD_DispalyNumber(uint32 x);
#endif /* LCD_H_ */
