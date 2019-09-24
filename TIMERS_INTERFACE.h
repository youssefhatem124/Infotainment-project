/*
 * TIMERS_INTERFACE.h
 *
 *  Created on: Aug 18, 2019
 *      Author: Youssef Hatem
 */

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

void TMR_vidInit_ctc(uint16 time);
void TMR_vidInit_ovf(void);
void TMR_vidInit_pwm(uint8 y);
void TMR_delay(uint32 delay);
void timer_stop(void);
void TIMER_interruptEnable(void);
void OS_Setcallback(void(*a_ptr)(void));
#endif /* TIMERS_INTERFACE_H_ */
