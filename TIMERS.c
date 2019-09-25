#include"STD_TYPES.h"
#include"Macros.h"
#include"TIMERS_PRIVATE.h"
#include"TIMERS_INTERFACE.h"
#include"os_interface.h"
static void (*OS_CallBackPtr_g)(void) = NULL;
void __vector_10 (void)  __attribute__((signal,__INTR_ATTRS));
/**********Initializing the function in the CTC MODE******/
void TMR_vidInit_ctc(uint16 time)
{
	TCNT0=0;
	switch(time)
	{
	case 1:  OCR0=125;break;
	case 2:  OCR0=250;break;
	}
	Set_Bit(TCCR0,FOC0);
	Set_Bit(TCCR0,WGM01);
	Set_Bit(TCCR0,CS00);
	Set_Bit(TCCR0,CS01);


}
/*************Enabling timer interrupt ******/
void TIMER_interruptEnable(void)
{
	Set_Bit(SREG,7);
	Set_Bit(TIMSK,OCIE0);
}
/*************timer delay enable ********/
void TMR_delay(uint32 delay)
{
	uint32 i;
	TCNT0=0;
	TMR_vidInit_ctc(1);
	for(i=0;i<(delay/2);i++)
	{
		while(!(TIFR&(1<<OCF0)));
		Set_Bit(TIFR,OCF0);
	}
}

void timer_stop(void)
{
	TCCR0=0;
}
void OS_SetCallBack(void(*a_ptr)(void))
{
	OS_CallBackPtr_g=a_ptr;
}
void __vector_10 (void)
{
	if(OS_CallBackPtr_g != NULL)
	{
		OS_CallBackPtr_g();
	}
}
