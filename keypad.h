/*
 * keypad.h
 *
 *  Created on: Apr 23, 2019
 *      Author: Khaled
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


#define KEYPAD_PORT  PORTC
#define KEYPAD_DDR   DDRC
#define KEYPAD_PIN   PINC
#define ROWS_MASK    0x1C    // (1<<PD0)|(1<<PD1)|(1<<PD2)|(1<<PD3)
#define COLS_MASK    0xE0	 // (1<<PD4)|(1<<PD5)|(1<<PD6)|(1<<PD7)
#define ROWS_NUM     3
#define COLS_NUM     3
#define ROWS_OFFSET  3
#define COLS_OFFSET  3
#define key1        1
#define key2        2
#define key3        3
#define keyA        4
#define key4        5
#define key5        6
#define key6        7
#define keyB        8
#define key7        9
#define key8        10
#define key9        11
#define keyC        12

#define key0        14

#define keyD        16

typedef enum
{
	RELEASED,
	PRE_PRESSED,
	PRESSED,
	PRE_RELEASED
}KeyPadSW_State_t;

/*
	No pressed keys -> return 0
	1:16 if any key pressed from K1:K16

*/
void Keypad_init(void);
uint8 Keypad_getKey(void);

#endif /* KEYPAD_H_ */
