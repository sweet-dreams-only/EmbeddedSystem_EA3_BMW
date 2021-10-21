/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the internal functions needed for
 ** frequency based event debouncing.
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_DebounceFrequencyBased.c 2556 2011-09-08 11:34:37Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise
 **
 ** Misra Deviations:
 ** 1) Deviation against MISRA-C:2004 Rule 19.7 (advisory) @ MisraDeviation#1:
 **    A function should be used in preference to a function-like macro.
 **
 **    Reason:
 **    As the function is called very often and consists only of a one line
 **    the macro based implmentation is more run time efficient.
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <SchM_Dem.h>             /* for the locking of the exclusive areas */

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

#if (DEM_USE_DEBOUNCE == STD_ON)
#if (DEM_NUM_DEBOUNCE_FREQUENCY > 0U)

/*==================[macros]================================================*/

/** \brief Internal Macro to reset passed counter, failed counter and FDC in
 ** frequency based debouncing status structure */
#define DEM_RESETFREQBASEDCOUNTERS(debounceStatus)                 \
   do                                                              \
   {                                                               \
      (debounceStatus)->PassedCounter = 0U;                        \
      (debounceStatus)->FailedCounter = 0U;                        \
      (debounceStatus)->SavedFDC      = DEM_FDC_VALUE_UNQUALIFIED; \
   } while(0)


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[reset debounce status]---------------------------------*/

FUNC(void, DEM_CODE) Dem_ResetDebounceFrequencyBased(Dem_EventIdType EventId)
{
   const Dem_EventIdType DebounceIdx = Dem_GbiDebounceIdx(EventId);
   CONSTP2VAR(Dem_DebounceFrequencyStatusType, AUTOMATIC, DEM_VAR_NOINIT)
      DebounceStatus = &Dem_DebounceFrequencyStatus[DebounceIdx];

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   /* (re-)initialize Dem_DebounceFrequencyStatus */
   DebounceStatus->TimerValue = 0U;
   /* not necessary to reset DebounceStatus->PassedCounter (= 0) */
   /* not necessary to reset DebounceStatus->FailedCounter (= 0) */
   DebounceStatus->SavedFDC   = DEM_FDC_VALUE_UNQUALIFIED;

   /*
    * ENTER critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0); /* Nxtr Patch: Changed to Exit call from SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);  */
}

/*------------------[debounce an event entry]-------------------------------*/

FUNC(void, DEM_CODE) Dem_DebounceEventFrequencyBased(
   Dem_EventIdType                                      EventId,
   P2VAR(Dem_EventStatusType, AUTOMATIC, DEM_APPL_DATA) EventStatus)
{
   const Dem_EventIdType DebounceIdx = Dem_GbiDebounceIdx(EventId);
   CONSTP2CONST(Dem_DebounceFrequencyCfgType, AUTOMATIC, DEM_CONST)
      DebounceCfg = &Dem_DebounceFrequencyCfg[DebounceIdx];
   CONSTP2VAR(Dem_DebounceFrequencyStatusType, AUTOMATIC, DEM_VAR_NOINIT)
      DebounceStatus = &Dem_DebounceFrequencyStatus[DebounceIdx];

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   switch (*EventStatus)
   {
      case DEM_EVENT_STATUS_PREPASSED:

         if (DebounceStatus->TimerValue == 0U)
         {
            /* timer not running -> start timer */
            DebounceStatus->TimerValue = DebounceCfg->TimeWindowDuration;
            DEM_RESETFREQBASEDCOUNTERS(DebounceStatus);
         }

         if (   DebounceStatus->PassedCounter
              < DebounceCfg->ThresholdBeforeEvPassed)
         {
            DebounceStatus->PassedCounter++;
         }
         else /* passed-threshold reached */
         {
            /* qualify event as PASSED */
            DebounceStatus->SavedFDC = DEM_FDC_VALUE_PASSED;
            /* not necessary to perform DebounceStatus->PassedCounter++ */
            DebounceStatus->TimerValue = 0U;
            *EventStatus = DEM_EVENT_STATUS_PASSED;
         }

         break;

      case DEM_EVENT_STATUS_PREFAILED:

         if (DebounceStatus->TimerValue == 0U)
         {
            /* timer not running -> start timer */
            DebounceStatus->TimerValue = DebounceCfg->TimeWindowDuration;
            DEM_RESETFREQBASEDCOUNTERS(DebounceStatus);
         }

         if (   DebounceStatus->FailedCounter
              < DebounceCfg->ThresholdBeforeEvFailed)
         {
            DebounceStatus->FailedCounter++;
         }
         else /* failed-threshold reached */
         {
            /* qualify event as FAILED */
            DebounceStatus->SavedFDC = DEM_FDC_VALUE_FAILED;
            /* not necessary to perform DebounceStatus->FailedCounter++ */
            DebounceStatus->TimerValue = 0U;
            *EventStatus = DEM_EVENT_STATUS_FAILED;
         }

         break;

      case DEM_EVENT_STATUS_PASSED:

         /* stop timer, set "passed" FDC */
         DebounceStatus->TimerValue = 0U;
         DebounceStatus->SavedFDC   = DEM_FDC_VALUE_PASSED;

         break;

      default: /* DEM_EVENT_STATUS_FAILED */

         /* stop timer, set "failed" FDC */
         DebounceStatus->TimerValue = 0U;
         DebounceStatus->SavedFDC   = DEM_FDC_VALUE_FAILED;

         break;

   } /* event status */

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
}

/*------------------[return FDC for an event]-------------------------------*/

FUNC(Std_ReturnType, DEM_CODE) Dem_GetFDCFrequencyBased(
   Dem_EventIdType                                                EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC)
{
   const Dem_EventIdType DebounceIdx = Dem_GbiDebounceIdx(EventId);
   CONSTP2VAR(Dem_DebounceFrequencyStatusType, AUTOMATIC, DEM_VAR_NOINIT)
      DebounceStatus = &Dem_DebounceFrequencyStatus[DebounceIdx];

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   if (DebounceStatus->TimerValue != 0U)
   {
      /* timer is running */
      /* quoting DEM SWS: "While the time window is open, the DTCFault-
       * DetectionCounter could be set to values differing from the minimum
       * or maximum value." */
      if (DebounceStatus->FailedCounter < DebounceStatus->PassedCounter)
      {
         *FDC = DEM_FDC_VALUE_UNQUALIFIED - 1;
      }
      else
      {
         *FDC = DEM_FDC_VALUE_UNQUALIFIED + 1;
      }
   }
   else
   {
      /* timer not running -> use saved FDC */
      *FDC = DebounceStatus->SavedFDC;
   }

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   return E_OK;
}

/*------------------[perform "timer tick" for all running timers]-----------*/

FUNC(void, DEM_CODE) Dem_DebounceFrequencyTimerTick(void)
{
   Dem_EventIdType DebounceIdx;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   for (DebounceIdx = 0U;
        DebounceIdx < (Dem_EventIdType)DEM_NUM_DEBOUNCE_FREQUENCY;
        DebounceIdx++)
   {
#if (!defined DEM_GLOBAL_OPCYCLEIDX_VALUE)
      CONSTP2CONST(Dem_DebounceFrequencyCfgType, AUTOMATIC, DEM_CONST)
         DebounceCfg = &Dem_DebounceFrequencyCfg[DebounceIdx];
      /* EventId is only be used if Dem_GbiOpCycleIdx is not a function
       * like macro*/
      const Dem_EventIdType EvId = DebounceCfg->EventId;
#endif

      if (Dem_OpCycleState[Dem_GbiOpCycleIdx(EvId)] != DEM_CYCLE_STATE_END)
      {
         CONSTP2VAR(Dem_DebounceFrequencyStatusType, AUTOMATIC, DEM_VAR_NOINIT)
            DebounceStatus = &Dem_DebounceFrequencyStatus[DebounceIdx];

         if (DebounceStatus->TimerValue != 0U)
         {
            /* timer running -> decrease timer */
            DebounceStatus->TimerValue--;

            if (DebounceStatus->TimerValue == 0U)
            {
               /* timer did expire */
               /* if neither threshold is reached within the time window, the
                * event is 'unqualified' (readiness is not set) */
               DebounceStatus->SavedFDC = DEM_FDC_VALUE_UNQUALIFIED;
            }
         }
      }
   } /* for (every frequency based debounced event) */

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_NUM_DEBOUNCE_FREQUENCY */
#endif /* DEM_USE_DEBOUNCE */

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
