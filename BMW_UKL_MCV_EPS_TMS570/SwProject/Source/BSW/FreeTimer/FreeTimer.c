/*******************************************************************************
**                                                                            **
**  SRC-MODULE: FreeTimer.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : MPC55xx                                                       **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Free Running Timer driver                                     **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.1: 27.01.2010, gema: CR70524: Compiler switches shall have defined values
 * V1.0.0: 14.11.2007, miwe: ported from SC6.7.2 file version V1.1.0
 */

#define FREETIMER_C

/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/
/*
 *
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "sc_types_arch.h"
#include "FreeTimer.h"                      /* Module header file             */
#include "Gpt.h"                            /* This example uses the Gpt to drive the free running timer */


/*******************************************************************************
**                      global Local Data                                     **
*******************************************************************************/
#if (FREETIMER_DISABLE_MEASUREMENTAPI == STD_OFF)
   static FreeTimer_TimeInTicksType   initialTimeInTicks;
#endif

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  FreeTimer_Init                                            **
**                                                                            **
** DESCRIPTION   :  Initializes the free running timer driver and the         **
                    free running timer register.                              **
**                                                                            **
** PRECONDITIONS :  Gpt_Init() has been called                                **
**                                                                            **
** PARAMETER     :  ---                                                       **
**                                                                            **
** RETURN        :  ---                                                       **
**                                                                            **
** REMARKS       :  The free running driver and prescaler must be configured, **
**                  so that only one overrun of the free running timer        **
**                  register occurs between start and end of time measurement **
**                                                                            **
*******************************************************************************/
void FreeTimer_Init( void )
{
  /* Start timer */
  
  /* Nothing to do, Nxtr EA3.0 design is mapping the SystemTick free running timer
   * to this modules API.  The SystemTick is started prior to Os start in the EA3.0
   * start up sequence.  Simply return if this function is called in the design.
   */
}

#if (FREETIMER_DISABLE_MEASUREMENTAPI == STD_OFF)

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  FreeTimer_StartTimeMeasurement                            **
**                                                                            **
** DESCRIPTION   :  Saves the current value of the timer register.            **
**                                                                            **
** PRECONDITIONS :  ---                                                       **
**                                                                            **
** PARAMETER     :  ---                                                       **
**                                                                            **
** RETURN        :  Time in ticks                                             **
**                                                                            **
** REMARKS       :  The free running driver and prescaler must be configured, **
**                  so that only one overrun of the free running timer        **
**                  register occurs between start and end of time measurement **
**                                                                            **
*******************************************************************************/
void FreeTimer_StartTimeMeasurement( void )
{
   initialTimeInTicks = Gpt_GetTimeElapsed(SystemTime_uS);
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  FreeTimer_GetTimeInTicks                                  **
**                                                                            **
** DESCRIPTION   :  Returns the elapsed time since the last call of           **
**                  FreeTimer_StartTimeMeasurement.                           **
**                                                                            **
** PRECONDITIONS :  ---                                                       **
**                                                                            **
** PARAMETER     :  ---                                                       **
**                                                                            **
** RETURN        :  Time in ticks                                             **
**                                                                            **
** REMARKS       :  The free running driver and prescaler must be configured, **
**                  so that only one overrun of the free running timer        **
**                  register occurs between start and end of time measurement **
**                                                                            **
*******************************************************************************/
FreeTimer_TimeInTicksType FreeTimer_GetTimeInTicks( void )
{
   sint32 diff;
   FreeTimer_TimeInTicksType result;
   FreeTimer_TimeInTicksType elapsedTimeInTicks = Gpt_GetTimeElapsed(SystemTime_uS);

   diff = initialTimeInTicks-elapsedTimeInTicks;
   if (diff < 0) {
     result = 1-diff;
   } else {
     result = diff;
   }

   return result;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  FreeTimer_ConvertMs2Ticks                                 **
**                                                                            **
** DESCRIPTION   :  Converts time from milliseconds to ticks.                 **
**                                                                            **
** PRECONDITIONS :  ---                                                       **
**                                                                            **
** PARAMETER     :  Time in milliseconds                                      **
**                                                                            **
** RETURN        :  Time in ticks                                             **
**                                                                            **
** REMARKS       :  ---                                                       **
**                                                                            **
*******************************************************************************/
FreeTimer_TimeInTicksType FreeTimer_ConvertMs2Ticks( const FreeTimer_TimeInMsType mS )
{
  return (FreeTimer_TimeInTicksType)(mS * ((uint32)((FREETIMER_BUS_FREQ_HZ/1000)/(Gpt_Runtime.ChannelConfig_pt[SystemTime_uS].ChannelPrescale_u32))));
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  FreeTimer_ConvertTicks2Ms                                 **
**                                                                            **
** DESCRIPTION   :  Converts ticks to milliseconds                            **
**                                                                            **
** PRECONDITIONS :  ---                                                       **
**                                                                            **
** PARAMETER     :  Time in ticks                                             **
**                                                                            **
** RETURN        :  Time in milliseconds                                      **
**                                                                            **
** REMARKS       :  ---                                                       **
**                                                                            **
*******************************************************************************/
FreeTimer_TimeInMsType FreeTimer_ConvertTicks2Ms (const FreeTimer_TimeInTicksType ticks)
{
   return (FreeTimer_TimeInMsType)(ticks / ((uint32)((FREETIMER_BUS_FREQ_HZ/1000)/(Gpt_Runtime.ChannelConfig_pt[SystemTime_uS].ChannelPrescale_u32))));
}


#endif /* FREETIMER_DISABLE_MEASUREMENTAPI==STD_OFF */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  FreeTimer_CreateRandomNumber                              **
**                                                                            **
** DESCRIPTION   :  Return the current time in Tick, that can be used as      **
**                  random number for crypto                                  **
**                                                                            **
** PRECONDITIONS :  ---                                                       **
**                                                                            **
** PARAMETER     :  ---                                                       **
**                                                                            **
** RETURN        :  Time in ticks                                             **
**                                                                            **
** REMARKS       :  ---                                                       **
**                                                                            **
*******************************************************************************/
FreeTimer_TimeInTicksType FreeTimer_CreateRandomNumber( void )
{
   FreeTimer_TimeInTicksType   elapsedTime = Gpt_GetTimeElapsed(SystemTime_uS);

   return elapsedTime;
}

/*** End of file **************************************************************/
