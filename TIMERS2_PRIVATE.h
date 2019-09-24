/*
 * TIMERS_PRIVATE.h
 *
 *  Created on: Aug 18, 2019
 *      Author: Youssef Hatem
 */

#ifndef TIMERS2_PRIVATE_H_
#define TIMERS2_PRIVATE_H_
#define SREG *((volatile uint8*)0x5f)
#define TCCR2 *((volatile uint8*)0x45)
#define TIFR *((volatile uint8*)0x58)
#define OCR2 *((volatile uint8*)0x43)
#define TCNT2 *((volatile uint8*)0x44)

/*---PINS---*/

//TIFR
enum TIMER_Flags_t
{
	overflowflag=6,
	outputcomparematchflag=7
};
enum TIMER_CLK_t
{
	NO_CLOCK,
	F_CPU_CLOCK,
	F_CPU_8,
	F_CPU_64,
	F_CPU_256,
	F_CPU_1024
};
enum TIMER_Mode_t
{
	normalmode=0,
	pwm_mode=64,
	CTC_mode=8,
	Fast_pwm=72
};
#define FOC2  7
enum TIMER_FORCEOUPUTCOMPARE_t
{
	FORCEOUTPUTCOMPAREENABLE=0,
	FORCEOUTPUTCOMPAREDISABLE=1
};
enum Timer_mode
{
	one_millisecondsresolution=250,
	two_millisecondsresolution=125
};
#endif /* TIMERS2_PRIVATE_H_ */
