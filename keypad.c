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

	uint8 Ci = 0;
	uint8 Ri = 0;

	for(Ri=0 ; Ri<ROWS_NUM ; Ri++)
	{
		setBits(KEYPAD_PORT,ROWS_MASK);
		Clear_Bit(KEYPAD_PORT,(Ri+2));
		//_delay_us(10);  // Wait for a little bit time ->
		for(Ci=0 ; Ci<COLS_NUM ; Ci++)
		{
			if(Get_Bit(KEYPAD_PIN,(5+Ci)) == 0)
			{
				while(Get_Bit(KEYPAD_PIN,(COLS_OFFSET+Ci) == 0)); // Unreachable code or Dead code
				return (3*Ri + Ci + 1);
			}
		}
	}

	return 0;
}
