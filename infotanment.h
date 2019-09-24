#ifndef INFOTAINMENT_H_
#define INFOTAINMENT_H_


/************************************************************************/
/*         preprocessor definitions                                                                    */
/************************************************************************/
/* *****************Infotainment status ******************/
#define INFOTAINMENT_IDLE 0
#define INFOTAINMENT_QUESTION 1
#define INFOTAINMENT_GET_ANSWER 2
#define INFOTAINMENT_SCORE   3
#define INFOTAINMENT_FINAL 4
#define INFOTAINMENT_NUMBER_OF_QUESTIONS 5

/*Answers definitions*/

#define YES 1 //button 1 is Yes
#define NO 9 //button 9 is NO
/************************************************************************/
/*				Global Variables                                        */
/************************************************************************/
extern uint8 Infotainment_Status ;
/************************************************************************/
/*					Functions Declarations                                                                     */
/************************************************************************/
/**************************************************************************
* function name : Infotainment_PrintQuestion
*
* function description : It check if question is answered so it prints the new question
*
* Periodicity : It is Called in the Game task every 250 ms
*
*In / Out / return : NULL
*************************************************************************/
extern void Infotainment_PrintQuestion (void);
/************ *************************************************************
* function name : Infotainment_GetAnswer
*
* function description : It check if question is answered so it prints the new question
*
*In / Out / return : NULL
*************************************************************************/
extern void Infotainment_GetAnswer (void);
extern void Infotainment_ScoreDisplay (void);
extern void Infotainment_FinalScore(void);
extern void Infotainment_Start(void) ;
#endif /* INFOTAINMENT_H_ */
