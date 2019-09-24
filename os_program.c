
#include"STD_TYPES.h"
#include"Macros.h"
#include"TIMERS_INTERFACE.h"
#include"TIMERS_PRIVATE.h"
#include"Os_PBCfg.h"
#include"os_interface.h"
 extern uint16 ticktime;
static volatile uint32 sos_u32_Tickcounter=0;
uint8 check_array[NUM_OF_TASKS];
/********array of struct to assign priority ,periodicity and name for each function */
typedef struct
{
	void(*Ptr_TaskHandler)(void);
	uint16 periodicity;
	uint8 priority;
	Function_state_s State;
}TCB;
TCB SysTasks [NUM_OF_TASKS];
/*******creating task ***/
void  OS_voidCreateTask(void(*TaskHandler)(void),uint16 periodicity,uint8 priority)
{
	if(check_array[priority]==0)
	{
		SysTasks [priority].Ptr_TaskHandler=TaskHandler;
			SysTasks [priority].periodicity=periodicity;
			SysTasks [priority].priority=priority;
			SysTasks [priority].State=ready;
			check_array[priority]=1;
	}


	else
	{
	}
}
/*******Starting timer interrupt and assigning values with zeros and nulls at the beginnning *********/
EnumOSError_t OS_voidStart(void)
{
	TMR_vidInit_ctc(ticktime);
	TIMER_interruptEnable();
	OS_SetCallBack(OS_Longterm);
	uint8 SOSLoopcounter;
	for(SOSLoopcounter=0;SOSLoopcounter<NUM_OF_TASKS;SOSLoopcounter++)
	{
		SysTasks [SOSLoopcounter].Ptr_TaskHandler=NULL;
		SysTasks [SOSLoopcounter].periodicity=0;;
		SysTasks [SOSLoopcounter].priority=0;
		SysTasks [SOSLoopcounter].State=0;

	}
	return Success;

}
/*********function to delete the task you want ******/
EnumOSError_t OS_voidDelete( void(*taskDelete)(void))
{
	uint8 SOSLoopcounter;
	for(SOSLoopcounter=0;SOSLoopcounter<NUM_OF_TASKS;SOSLoopcounter++)
	{
		if(SysTasks [SOSLoopcounter].Ptr_TaskHandler==taskDelete)
		{
			SysTasks [SOSLoopcounter].Ptr_TaskHandler=NULL;
			SysTasks [SOSLoopcounter].periodicity=0;
			break;
		}
		else
		{

		}


	}
	return Success;

}
/********check which function should run****/
EnumOSError_t os_run(void)
{
	uint8 SOSLoopcounter;
	while(1)
	{
		for(SOSLoopcounter=0;SOSLoopcounter<NUM_OF_TASKS;SOSLoopcounter++)
		{
			if(	(SysTasks [SOSLoopcounter].State==ready)&&(SysTasks[SOSLoopcounter].Ptr_TaskHandler!=NULL))
			{
				SysTasks [SOSLoopcounter].State=running;
				SysTasks[SOSLoopcounter].Ptr_TaskHandler();
				SysTasks [SOSLoopcounter].State=waiting;
			}
		}
	}
	return Success;
}
/**************interrupt to check if the timer time to execute has come or not *********/
void OS_Longterm (void)
{
	/*****Check for the indices of the arrays***/
	uint8 SOSLoopcounter;
	/******variable to count number of ticks *****/
	sos_u32_Tickcounter++;
	for(SOSLoopcounter=0;SOSLoopcounter<NUM_OF_TASKS;SOSLoopcounter++)
	{
		if(sos_u32_Tickcounter % SysTasks [SOSLoopcounter].periodicity==0)/*****check if the function time came or not ****/
		{
			SysTasks [SOSLoopcounter].State=ready;
		}
		else
		{
		}
	}
}
