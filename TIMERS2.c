
 /* TIMERS.c

 *
 *  Created on: Aug 18, 2019
 *      Author: Youssef Hatem
 */
#include"STD_TYPES.h"
#include"Macros.h"
#include "TIMERS2_INTERFACE.h"
#include "TIMERS2_PRIVATE.h"
void TMR2_vidInit_ctc(void)
{

	/* Configure the timer control register
	 * for WGM21, WGM20
	 * 0. Normal Mode
	 * 1. PWM, Phase Correct
	 * 2. CTC Mode
	 * 3. Fast PWM
	 */
	TCNT2=0;
	OCR2=one_millisecondsresolution;
	TCCR2 =(1<<FORCEOUTPUTCOMPAREDISABLE) |CTC_mode |F_CPU_64;
}

/*************timer delay enable ********/
void TMR2_delay(uint32 Delay)
{
	/*Enabling CTC_timer timer to work on delay */
	uint32 Index;
	TCNT2=0;
	TMR2_vidInit_ctc();
	for(Index=0;Index<(Delay);Index++)
	{
		while(!(TIFR&(1<<outputcomparematchflag)));
		Set_Bit(TIFR,outputcomparematchflag);
	}
}


