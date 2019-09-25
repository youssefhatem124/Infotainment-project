/*
 * Macros.h
 *
 *  Created on: Sep 17, 2019
 *      Author: Khaled
 */

#ifndef MACROS_H_
#define MACROS_H_

/* Assign a single bit */
#define Set_Bit(PORT,PIN) ((PORT)|=(1<<(PIN)))
#define Clear_Bit(PORT,PIN) ((PORT)&=~(1<<(PIN)))
#define Get_Bit(REGISTER, BIT)		((REGISTER & (1 << BIT)) >> BIT)
#define Toggle_Bit(PORT,PIN) ((PORT)^=(1<<(PIN)))

/* Assign a multiple bits */
#define setBits(PORT,MASK)     (PORT|=MASK)
#define clearBits(PORT,MASK)   (PORT&=~MASK)
#define toggleBits(PORT,MASK)  (PORT^=MASK)

/* Assign all bits */
#define setAllBits(PORT)       (PORT=0xFF)
#define clearAllBits(PORT)     (PORT=0x00)
#define toggleAllBits(PORT)    (PORT^=0xFF)

#define ALL_INPUT		0x00
#define ALL_OUTPUT		0xFF
#define ALL_HIGH		0xFF
#define ALL_LOW			0x00
#define HIGH_NIPP		0xF0
#define LOW_NIPP		0x0F

#endif /* MACROS_H_ */
