/*
 * os_interface.h
 *
 *  Created on: Sep 15, 2019
 *      Author: Youssef Hatem
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_
typedef enum
{
	ready,
	waiting,
	running,
	delete

}Function_state_s;
typedef enum
{
	Success,
	fail
}EnumOSError_t;

 extern void OS_voidCreateTask(void(*TaskHandler)(void),uint16 periodicity,uint8 priority);




/**************************************************************************
 * Function Name : Create_Task
 *
 * Description	 : Creating Tasks and assign it in the buffer
 *
 * INPUTS		 : pointer to function ,periodicity and priority
 *
 * OUTPUTS 		 : void
 *
 * Return		 : state
 **************************************************************************/
extern EnumOSError_t OS_voidStart(void);
/**************************************************************************
 * Function Name : Start_Task
 *
 * Description	 : Creating Tasks and assign it in the buffer
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : EnumOSError_t
 **************************************************************************/
extern EnumOSError_t os_run(void);
/**************************************************************************
 * Function Name : Start_Task
 *
 * Description	 : Check which task should run
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : EnumOSError_t
 *
 * Return		 : EnumOSError_t
 **************************************************************************/
extern EnumOSError_t OS_voidDelete( void(*taskDelete)(void));
/**************************************************************************
 * Function Name : Start_Task
 *
 * Description	 : Check which task should be deleted
 *
 * INPUTS		 : pointer to function
 *
 * OUTPUTS 		 : EnumOSError_t
 *
 * Return		 : EnumOSError_t
 **************************************************************************/

extern void OS_Longterm (void);
/**************************************************************************
 * Function Name : Start_Task
 *
 * Description	 : ISR CODE
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : EnumOSError_t
 *
 * Return		 : EnumOSError_t
 **************************************************************************/
#define NULL  ((void *)0)
#endif /* OS_INTERFACE_H_ */
