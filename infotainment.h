/*
 * infotainment.h
 *
 *  Created on: Sep 25, 2019
 *      Author: Doaa
 */

#ifndef INFOTAINMENT_H_
#define INFOTAINMENT_H_

#include"STD_TYPES.h"
#include"Macros.h"
#include"Dio.h"
#include"TIMERS_INTERFACE.h"
#include"TIMERS2_INTERFACE.h"
#include "keypad.h"
#include "LCD.h"
#include"os_interface.h"

#define ANSWERED		(1)
#define NOT_ANSWERED	(0)
#define NO				(0)
#define YES				(1)
#define FALSE_			(0)
#define TRUE_			(1)

typedef enum
{
	START,
	DISPLAY_QS,
	DISPLAY_RESULT
}Infotainment_GameState_t;

void Infotainment_Task(void);
void Infotainment_Delay_2Sec(void);
void Infotainment_Delay_5Sec(void);

#endif /* INFOTAINMENT_H_ */
