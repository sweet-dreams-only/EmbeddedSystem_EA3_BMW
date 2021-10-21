/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the internal functions needed for
 ** time based event debouncing.
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_DebounceTimeBased.c 2561 2011-09-09 12:08:40Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise
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
#if (DEM_NUM_DEBOUNCE_TIME > 0U)

/*==================[macros]================================================*/

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

FUNC(void, DEM_CODE) Dem_ResetDebounceTimeBased(Dem_EventIdType EventId)
{
   const Dem_EventIdType DebounceIdx = Dem_GbiDebounceIdx(EventId);
   CONSTP2VAR(Dem_DebounceTimeStatusType, AUTOMATIC, DEM_VAR_NOINIT)
      DebounceStatus = &Dem_DebounceTimeStatus[DebounceIdx];

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   /* (re-)initialize Dem_DebounceTimeStatus */
   DebounceStatus->TimerValue = 0U;
   DebounceStatus->Direction  = DEM_EVENT_STATUS_FAILED;
   DebounceStatus->SavedFDC   = DEM_FDC_VALUE_UNQUALIFIED;

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
}

/*------------------[debounce an event entry]-------------------------------*/

FUNC(void, DEM_CODE) Dem_DebounceEventTimeBased(
   Dem_EventIdType                                      EventId,
   P2VAR(Dem_EventStatusType, AUTOMATIC, DEM_APPL_DATA) EventStatus)
{
   const Dem_EventIdType DebounceIdx = Dem_GbiDebounceIdx(EventId);
   CONSTP2CONST(Dem_DebounceTimeCfgType, AUTOMATIC, DEM_CONST)
      DebounceCfg = &Dem_DebounceTimeCfg[DebounceIdx];
   CONSTP2VAR(Dem_DebounceTimeStatusType, AUTOMATIC, DEM_VAR_NOINIT)
      DebounceStatus = &Dem_DebounceTimeStatus[DebounceIdx];

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   switch (*EventStatus)
   {
      case DEM_EVENT_STATUS_PREPASSED:

         /*
          * if either
          *  - the timer is already running, but as a "failed" timer
          * or
          *  - the timer is not running and the event has not been qualified
          *    as "passed" yet
          * then the "passed" timer must be (re-)started
          */
         if (   (   (DebounceStatus->TimerValue != 0U)
                 && (DebounceStatus->Direction == DEM_EVENT_STATUS_FAILED)
                )
             || (   (DebounceStatus->TimerValue == 0U)
                 && (DebounceStatus->SavedFDC != DEM_FDC_VALUE_PASSED)
                )
            )
         {
            /* if TimePassedThreshold = 0, no debouncing is started */
            DebounceStatus->TimerValue = DebounceCfg->TimePassedThreshold;
            DebounceStatus->Direction  = DEM_EVENT_STATUS_PASSED;
         }
         /*
          * in all other cases ("passed" timer already running or event
          * already qualified as "passed" and no timer running) there's
          * nothing to do.
          */
         break;

      case DEM_EVENT_STATUS_PREFAILED:

         /* see description above, exchanging "passed" and "failed" */

         if (   (   (DebounceStatus->TimerValue != 0U)
                 && (DebounceStatus->Direction == DEM_EVENT_STATUS_PASSED)
                )
             || (   (DebounceStatus->TimerValue == 0U)
                 && (DebounceStatus->SavedFDC != DEM_FDC_VALUE_FAILED)
                )
            )
         {
            /* if TimeFailedThreshold = 0, no debouncing is started */
            DebounceStatus->TimerValue = DebounceCfg->TimeFailedThreshold;
            DebounceStatus->Direction  = DEM_EVENT_STATUS_FAILED;
         }

         break;

      case DEM_EVENT_STATUS_PASSED:

         /* stop any running timer, set "passed" FDC */

         DebounceStatus->TimerValue = 0U;
         DebounceStatus->SavedFDC   = DEM_FDC_VALUE_PASSED;

         break;

      default: /* DEM_EVENT_STATUS_FAILED */

         /* stop any running timer, set "failed" FDC */

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

FUNC(Std_ReturnType, DEM_CODE) Dem_GetFDCTimeBased(
   Dem_EventIdType                                                EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC)
{
   const Dem_EventIdType DebounceIdx = Dem_GbiDebounceIdx(EventId);
   CONSTP2VAR(Dem_DebounceTimeStatusType, AUTOMATIC, DEM_VAR_NOINIT)
      DebounceStatus = &Dem_DebounceTimeStatus[DebounceIdx];

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   if (DebounceStatus->TimerValue != 0U)
   {
      /* timer is running */
      /* quoting DEM SWS: "While the timer is running, the DTCFaultDetection-
       * Counter could be set to all other values other than minimum or
       * maximum value." */
      if (DebounceStatus->Direction == DEM_EVENT_STATUS_PASSED)
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

FUNC(void, DEM_CODE) Dem_DebounceTimeTimerTick(void)
{
   Dem_EventIdType DebounceIdx;

   /*
    * ENTER critical section
    */
   SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

   for (DebounceIdx = 0U; DebounceIdx < DEM_NUM_DEBOUNCE_TIME; DebounceIdx++)
   {
      CONSTP2CONST(Dem_DebounceTimeCfgType, AUTOMATIC, DEM_CONST)
         DebounceCfg = &Dem_DebounceTimeCfg[DebounceIdx];
      const Dem_EventIdType EventId = DebounceCfg->EventId;

      if (Dem_OpCycleState[Dem_GbiOpCycleIdx(EventId)] != DEM_CYCLE_STATE_END)
      {
         CONSTP2VAR(Dem_DebounceTimeStatusType, AUTOMATIC, DEM_VAR_NOINIT)
            DebounceStatus = &Dem_DebounceTimeStatus[DebounceIdx];

         if (DebounceStatus->TimerValue != 0U)
         {
            /* timer running -> decrease timer */
            DebounceStatus->TimerValue--;

            if (DebounceStatus->TimerValue == 0U)
            {
               /* timer did expire */

               boolean UnusedErrorFlag;

               /*
                * LEAVE critical section
                */
               SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);

               /* event debouncing complete */

               /* note: Dem_InternalSetEventStatus() will call
                *       Dem_DebounceEventTimeBased() for the event, which in
                *       turn will reset the Debouncing status */
#if (DEM_DEV_ERROR_DETECT == STD_ON)
               {
                  Std_ReturnType result = Dem_InternalSetEventStatus(EventId,
                                                                     DebounceStatus->Direction,
                                                                     &UnusedErrorFlag);

                  if (result != E_OK)
                  {
                     DEM_REPORT_ERROR(DEM_SID_MainFunction, DEM_E_PARAM_CONFIG);
                  }
               }
#else /* DEM_DEV_ERROR_DETECT */

               /* evaluation of return value is done with DET:ON */
               (void) Dem_InternalSetEventStatus(EventId,
                                                 DebounceStatus->Direction,
                                                 &UnusedErrorFlag);

#endif /* DEM_DEV_ERROR_DETECT */

               /*
                * ENTER critical section
                */
               SchM_Enter_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
            }
         }
      }
   } /* for (every time based debounced event) */

   /*
    * LEAVE critical section
    */
   SchM_Exit_Dem(SCHM_DEM_INSTANCE_0, SCHM_DEM_EXCLUSIVE_AREA_0);
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_NUM_DEBOUNCE_TIME */
#endif /* DEM_USE_DEBOUNCE */

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
