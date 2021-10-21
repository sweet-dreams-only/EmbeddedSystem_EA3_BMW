/*******************************************************************************
**                                                                            **
**  SRC-MODULE: SysTimeClient.c                                               **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : The SysTimeClient module receives the System Time,            **
**              which is sent by the SysTimeMaster, and provides the          **
**              received System Time to other modules on the ECU.             **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
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
** mani         Markus Nirschl             EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.3.2: 07.06.2011, olho: CR70903: Added critical sections
 *         08.09.2011, olho: CR71032: corrected void casts
 * V1.3.1: 30.03.2011, olho: CR71019: Checked with MISRA 2004
 * V1.3.0: 26.11.2009, mani: CR70410: adapt to SWS version 1.3
 * V1.2.1: 19.10.2009, mani: BSCSYSTIME-39: add version check of
 *                           SysTimeClient_Wrapper.h
 * V1.2.0: 11.03.2008, mani: init currentSyncTime (RT#11369)
 *         13.02.2008, mani: MISRA checked
 *         05.02.2008, mani: reworked after review
 * V1.1.0: 24.01.2008, mani: set Dem-entry to 'passed' after timeout has expired
 *                           (error memory is expected to be unlocked, RT#10009)
 *         21.12.2007, mani: adaptions for RTE usage
 * V1.0.0: 30.11.2007, mani: initial version based on SC6 Systime module 5.1.0
 */


/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/
/* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 8.3 (required)
  *   For each function parameter the type given in the declaration and
  *   definition shall be identical, and the return types shall also be
  *   identical.
  *
  *   Reason:
  *   uint32 can not be described within the RTE configuration.
  */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "SysTimeClient_Cfg.h"       /* SysTimeClient configuration file      */
#include "SysTimeClient.h"           /* SysTimeClient heade file              */
#include "SysTimeClient_Wrapper.h"   /* include SysTimeClient Wrapper API     */


/*******************************************************************************
**                Configuration and version checking                          **
*******************************************************************************/
#if (     (SYSTIMECLIENT_MAJOR_VERSION != 2u) \
       || (SYSTIMECLIENT_MINOR_VERSION != 1u) )
  #error "Wrong version of SysTimeClient.h found!!"
#endif

#if (     (SYSTIMECLIENT_CFG_MAJOR_VERSION != 2u) \
       || (SYSTIMECLIENT_CFG_MINOR_VERSION != 1u) )
  #error "Wrong version of SysTimeClient_Cfg.h found!!"
#endif

#if (     (SYSTIMECLIENT_WRAPPER_MAJOR_VERSION != 2u) \
       || (SYSTIMECLIENT_WRAPPER_MINOR_VERSION != 1u) )
  #error "Wrong version of SysTimeClient_Wrapper.h found!!"
#endif


/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/* value, that symbolize a received invalid message                           */
#define SYSTIMECLIENT_ERROR                     0xFFFFFFFFul
/* return value for the requested time in the error state                     */
#define SYSTIMECLIENT_SIGNAL_INVALID            0xFFFFFFFFul
/* return value for the requested time at the startup time                    */
#define SYSTIMECLIENT_STARTUP                   0x0ul
/* value for a deactivated startup counter                                    */
#define SYSTIMECLIENT_STARTCOUNTER_DEACTIVATED  0xFFu
/* value for a deactivated internal counter                                   */
#define SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED 0xFFFFu


/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Local data                                            **
*******************************************************************************/
#define SYSTIMECLIENT_START_SEC_VAR_32BIT
#include "MemMap.h"
/* current system time (can be absolute or relative, can be sync. or not sync,
 * depending on state)
 */
_STATIC_ VAR(uint32, SYSTIMECLIENT_VAR) currentSyncTime = SYSTIMECLIENT_STARTUP;
#define SYSTIMECLIENT_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#define SYSTIMECLIENT_START_SEC_VAR_16BIT
#include "MemMap.h"
/* internal timer (used to check message timeouts and to update relative time if
 * no SysTime message messages arrive)
 */
_STATIC_ VAR(uint16, SYSTIMECLIENT_VAR) internalTimerInMs;

/* internal error lock timer (used to avoid writing a Dem-entry too early)
 */
_STATIC_ VAR(uint16, SYSTIMECLIENT_VAR) internalErrorLockTimerInMs;
#define SYSTIMECLIENT_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define SYSTIMECLIENT_START_SEC_VAR_8BIT
#include "MemMap.h"
/* internal counter (in s) during startup
 * if no SysTime message messages arrive
 */
_STATIC_ VAR(uint8, SYSTIMECLIENT_VAR) internalStartCounter;
#define SYSTIMECLIENT_STOP_SEC_VAR_8BIT
#include "MemMap.h"


/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/
#define SYSTIMECLIENT_START_SEC_CODE
#include "MemMap.h"

_STATIC_ FUNC(void, SYSTIMECLIENT_PRIVATE_CODE) SysTimeClient_HandleMessages(void);
_STATIC_ FUNC(void, SYSTIMECLIENT_PRIVATE_CODE) SysTimeClient_UpdateInternalTimeCounter(void);

#define SYSTIMECLIENT_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/
#define SYSTIMECLIENT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :   SysTimeClient_HandleMessages                             **
**                                                                            **
** DESCRIPTION   :   Called every time a SysTimeClient message message        **
**                   arrives.                                                 **
**                                                                            **
** PRECONDITIONS :   ---                                                      **
**                                                                            **
** PARAMETER     :   ---                                                      **
**                                                                            **
** RETURN        :   ---                                                      **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, SYSTIMECLIENT_PRIVATE_CODE) SysTimeClient_HandleMessages(void)
{
   _STATIC_ VAR(boolean, SYSTIMECLIENT_VAR) makeErrorEntryPassed = FALSE;
   VAR(uint32, SYSTIMECLIENT_VAR) tempSyncTime;

   /* Check for received new message */
   if( SYSTIMECLIENT_IND_FLAG_SET() )
   {
      /* reset indication flag */
      SYSTIMECLIENT_RES_IND_FLAG();

      /* retrieve message */
      tempSyncTime = SysTimeClient_ReceiveSignal();

      /* Message contains special error value (see Lastenheft DiagnosticManager) */
      if( tempSyncTime == SYSTIMECLIENT_ERROR )
      {
         /* ### --> SysTime_ErrorTime ### */

         SysTimeClient_EnterCriticalSection();
         {
            /* invalid SysTime value received */
            currentSyncTime = SYSTIMECLIENT_SIGNAL_INVALID;
         }
         SysTimeClient_ExitCriticalSection();

         /* stop internal timer in error state */
         internalTimerInMs = (uint16)SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED;
      }
      else
      {
         /* ### --> SysTime_Ok ### */

         SysTimeClient_EnterCriticalSection();
         {
            /* Accept the Current SystemTime from message */
            currentSyncTime = tempSyncTime;
         }
         SysTimeClient_ExitCriticalSection();

         /* SysTime message arrived => reset internal timer */
         internalTimerInMs = (uint16)0u;
      }

      if( internalStartCounter != (uint8)SYSTIMECLIENT_STARTCOUNTER_DEACTIVATED )
      {
         /* ### SysTime_Start ### */

         /* time message has received at startup
          * -> set error entry to OK-status
          */
         makeErrorEntryPassed = TRUE;

         /* stop internal start counter */
         internalStartCounter = SYSTIMECLIENT_STARTCOUNTER_DEACTIVATED;
      }
   }

   /* only one time set an error entry with passed state, if a time
    * message has received at startup time
    */
   if( makeErrorEntryPassed == TRUE )
   {
      /* is timeout expired? (error memory is expected to be unlocked, RT#10009) */
      if( internalErrorLockTimerInMs == (uint16)SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED )
      {
        /* valid time message has received at startup
         * -> set error entry to OK-status
         */
        SysTimeClient_SetEventStatus(SYSTIMECLIENT_STATUS_PASSED);

        makeErrorEntryPassed = FALSE;
      }
   }
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :   SysTimeClient_UpdateInternalTimeCounter                  **
**                                                                            **
** DESCRIPTION   :   Called by system every <SysTimeClientMainTaskCycle>      **
**                   ms to monitor and update internal timers                 **
**                   and the internal state.                                  **
**                                                                            **
** PRECONDITIONS :   ---                                                      **
**                                                                            **
** PARAMETER     :   ---                                                      **
**                                                                            **
** RETURN        :   ---                                                      **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
_STATIC_ FUNC(void, SYSTIMECLIENT_PRIVATE_CODE) SysTimeClient_UpdateInternalTimeCounter(void)
{
   VAR(BusStateType, SYSTIMECLIENT_VAR) BusState = SYSTIMECLIENT_BUS_AWAKE;

   /* count internalErrorLockTimerInMs until timeout is reached (RT#10009) */
   if( internalErrorLockTimerInMs != (uint16)SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED )
   {
   	  internalErrorLockTimerInMs = internalErrorLockTimerInMs + (uint16)SysTimeClientMainTaskCycle;
   	  if( internalErrorLockTimerInMs >= (uint16)(SysTimeClientTimeout * 1000u) )
   	  {
   	  	internalErrorLockTimerInMs = (uint16)SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED;
   	  }
   }

   /* bus in active mode? (counter is started) */
   if( internalTimerInMs != (uint16)SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED )
   {
      /* Increment the TimeStamp in steps of task cycle time (in ms) */
      internalTimerInMs = internalTimerInMs + (uint16)SysTimeClientMainTaskCycle;
      /* check for bus activ mode - only then increment SysTime */
      SysTimeClient_GetCurrentComMode(&BusState);
      if( BusState != SYSTIMECLIENT_BUS_AWAKE )
      {
         /* stop internal timer in bus inactive mode */
         internalTimerInMs = (uint16)SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED;
      }
      /* Check if one second passed */
      if( ( internalTimerInMs >= (uint16)1000u ) &&
          ( internalTimerInMs != (uint16)SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED ) )
      {
         /* reset internal timer */
         internalTimerInMs = (uint16)0u;

         /* check start counter for startup phase */
         if( internalStartCounter != (uint8)SYSTIMECLIENT_STARTCOUNTER_DEACTIVATED )
         {
            /* ### SysTime_Start ### */
            /* Increment the start counter (in s) */
            internalStartCounter++;

            /* in startup mode if SysTimeTimeout has arrived */
            if( internalStartCounter >= (uint8)SysTimeClientTimeout )
            {
               /* ### SysTime_Start ### --> ### SysTime_ErrorEntry ### */

               /* trigger an error entry with failed status */
               SysTimeClient_SetEventStatus(SYSTIMECLIENT_STATUS_FAILED);

               /* stop internal start counter */
               internalStartCounter = SYSTIMECLIENT_STARTCOUNTER_DEACTIVATED;

               SysTimeClient_EnterCriticalSection();
               {
                  /* ### --> SysTime_ErrorTime ### */
                  currentSyncTime = SYSTIMECLIENT_SIGNAL_INVALID;
               }
               SysTimeClient_ExitCriticalSection();
            }
         }
         else
         {
         	  if( currentSyncTime != SYSTIMECLIENT_SIGNAL_INVALID )
            {
               /* ### SysTime_Increment ### */

               SysTimeClient_EnterCriticalSection();
               {
                  /* Increment SysTime, bus active mode is present */
                  currentSyncTime++;
               }
               SysTimeClient_ExitCriticalSection();
            }
            else
            {
               /* ### SysTime_ErrorTime ### */
               /* do nothing - currentSyncTime is already SYSTIMECLIENT_SIGNAL_INVALID */
            }
         }
      }
   }
   else if( currentSyncTime == SYSTIMECLIENT_SIGNAL_INVALID )
   {
      /* ### SysTime_ErrorTime ### */
      /* do nothing - currentSyncTime is already SYSTIMECLIENT_SIGNAL_INVALID */
   }
   else
   {
      /* ### SysTime_Start or bus inactive at SysTime_OK or SysTime_Increment ### */
      /* check for bus activ mode after startup */
      SysTimeClient_GetCurrentComMode(&BusState);
      if( BusState == SYSTIMECLIENT_BUS_AWAKE )
      {
         /* start internal timer with initial value */
         internalTimerInMs = (uint16)0u;
      }
      else
      {
         /* internal counter stays deactivated */
      }
   }
}


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :   SysTimeClient_Init                                       **
**                                                                            **
** DESCRIPTION   :   Initialization: called once on startup                   **
**                   by EcuM                                                  **
**                                                                            **
** PRECONDITIONS :   ---                                                      **
**                                                                            **
** PARAMETER     :   ---                                                      **
**                                                                            **
** RETURN        :   ---                                                      **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
FUNC(void, SYSTIMECLIENT_PUBLIC_CODE) SysTimeClient_Init(void)
{
   /*  --> state SysTime_Start */
   /* initial value of SyncTime before time signal has arrrived */
   currentSyncTime = SYSTIMECLIENT_STARTUP;
   /* initial value of startup counter */
   internalStartCounter = (uint8)0u;
   /* init internal timer -> deactivated while no bus is activ */
   internalTimerInMs = (uint16)SYSTIMECLIENT_INTERNALTIMER_DEACTIVATED;
   /* init internal error lock timer */
   internalErrorLockTimerInMs = (uint16)0u;
   /* reset indication flag */
   SYSTIMECLIENT_RES_IND_FLAG();
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :   SysTimeClient_GetTime                                    **
**                                                                            **
** DESCRIPTION   :   Called by any application to get                         **
**                   the current system time                                  **
**                                                                            **
** PRECONDITIONS :   ---                                                      **
**                                                                            **
** PARAMETER     :   ---                                                      **
**                                                                            **
** RETURN        :   currentSyncTime                                          **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
/* Deviation MISRA-1 */
FUNC(Std_ReturnType, SYSTIMECLIENT_PUBLIC_CODE) SysTimeClient_GetTime(uint32 *currentTime)
{
   SysTimeClient_EnterCriticalSection();
   {
      /* Return current network time or internal Counter*/
      *currentTime = currentSyncTime;
   }
   SysTimeClient_ExitCriticalSection();

   return E_OK;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :   SysTimeClient_MainFunction                               **
**                                                                            **
** DESCRIPTION   :   Called cyclic to handle the time message and update the  **
**                   internal timer every second, if the time message does    **
**                   not receive                                              **
**                                                                            **
** PRECONDITIONS :   ---                                                      **
**                                                                            **
** PARAMETER     :   ---                                                      **
**                                                                            **
** RETURN        :   ---                                                      **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
FUNC(void, SYSTIMECLIENT_PUBLIC_CODE) SysTimeClient_MainFunction(void)
{
   /* handle message with actual time signal                               */
   SysTimeClient_HandleMessages();

   /* Increments internal TimerCounter to check if the time message        */
   /* is missing and to increment internal time (even if message is        */
   /* missing)                                                             */
   SysTimeClient_UpdateInternalTimeCounter();
}

#define SYSTIMECLIENT_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
