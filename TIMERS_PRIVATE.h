/*
 * TIMERS_PRIVATE.h
 *
 *  Created on: Aug 18, 2019
 *      Author: Youssef Hatem
 */

#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_
#define SREG *((volatile uint8*)0x5f)
#define TCCR0 *((volatile uint8*)0x53)
#define TIMSK *((volatile uint8*)0x59)
#define TIFR *((volatile uint8*)0x58)
#define OCR0 *((volatile uint8*)0x5c)
#define TCNT0 *((volatile uint8*)0x52)
/*---PINS---*/
//TIMSK
#define TOIE0 0
#define OCIE0 1
//TIFR
#define OCF0  1
#define TOV0  0
//TCCR0
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7


#endif /* TIMERS_PRIVATE_H_ */
