/*
 * lcd.h
 *
 *  Created on: Apr 25, 2019
 *      Author: Khaled
 */

#ifndef LCD_H_
#define LCD_H_



#define E_PIN   6
///////////////////////////#define RW_PIN  5
#define RS_PIN  7

#define LCD_DATA_PORT     PORTA
#define LCD_DATA_DDR      DDRA
#define LCD_DATA_MASK     0xF0

#define LCD_CONTROL_PORT   PORTB
#define LCD_CONTROL_DDR    DDRB


#define FunctionSet8bit     0x38          // 8-bit data, 2-line display, 5 x 7 font
#define DisplayOn     		0x0C 		  // display on, cursor off, don't blink character
#define Clear_Display       0x01          // replace all characters with ASCII 'space'
#define EntryModeSet        0x06          // shift cursor from left to right on read/write
#define lcd_ShiftRight		0b00011100	//Shift display right without changing DDRAM content
#define lcd_ShiftLeft		0b00011000	//Shift display left without changing DDRAM content

#define HIGH    1
#define LOW     0

#define ALL_OUTPUT  0xFF





void LCD_Init(void);
void LCD_SendCommand(uint8 COM);
void LCD_WriteCharctr(uint8 DATA);
void LCD_DispString(uint8* str);
void Gotoxy (uint8 Y,uint8 X);
void LCD_Clear(void);
void LCD_ShiftDisplayRight(void);
void LCD_ShiftDisplayLeft(void);

#endif /* LCD_H_ */
