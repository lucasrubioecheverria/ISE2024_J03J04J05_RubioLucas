#include "cmsis_os2.h"                          // CMSIS RTOS header file
#include "rtc.h"

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
osThreadId_t tid_ThAlarm;                        // thread id
 
extern osTimerId_t tim_5s;
extern osTimerId_t tim_500ms;

void ThAlarm (void *argument);                   // thread function
 
int Init_ThAlarm (void) {
 
  tid_ThAlarm = osThreadNew(ThAlarm, NULL, NULL);
  if (tid_ThAlarm == NULL) {
    return(-1);
  }
 
  return(0);
}
 
void ThAlarm (void *argument) {
 
	Init_Timer5();
	Init_Timer_500();
	
  while (1) {

		osThreadFlagsWait(0x00000001U, osFlagsWaitAny, osWaitForever);
		osTimerStart(tim_500ms,500U);
		osTimerStart(tim_5s,5000U);
    osThreadYield();                            // suspend thread
  }
}
