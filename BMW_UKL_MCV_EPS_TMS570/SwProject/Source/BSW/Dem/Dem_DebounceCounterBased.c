/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the internal functions needed for
 ** counter based event debouncing.
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_DebounceCounterBased.c 2061 2010-01-18 12:10:39Z olho2924 $
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

#include <Dem_Internal_Depend_Specific.h> /* API and internal declarations,
                                           * dependent and static part */

#if (DEM_USE_DEBOUNCE == STD_ON)
#if (DEM_NUM_DEBOUNCE_COUNTER > 0U)

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

FUNC(void, DEM_CODE) Dem_ResetDebounceCounterBased(Dem_EventIdType EventId)
{
   const Dem_EventIdType DebounceIdx = Dem_GbiDebounceIdx(EventId);

   /* (re-)initialize Dem_DebounceCounterStatus */
   Dem_DebounceCounterStatus[DebounceIdx].FDC = DEM_FDC_VALUE_UNQUALIFIED;
}

/*------------------[debounce an event entry]-------------------------------*/

FUNC(void, DEM_CODE) Dem_DebounceEventCounterBased(
   Dem_EventIdType                                      EventId,
   P2VAR(Dem_EventStatusType, AUTOMATIC, DEM_APPL_DATA) EventStatus)
{
   const Dem_EventIdType DebounceIdx = Dem_GbiDebounceIdx(EventId);
   CONSTP2CONST(Dem_DebounceCounterCfgType, AUTOMATIC, DEM_CONST)
      DebounceCfg = &Dem_DebounceCounterCfg[DebounceIdx];
   CONSTP2VAR(Dem_DebounceCounterStatusType, AUTOMATIC, DEM_VAR_NOINIT)
      DebounceStatus = &Dem_DebounceCounterStatus[DebounceIdx];

   /* As two monitor paths can never manipulate the same EventId, no exclusive
    * area is needed for the following operations on debounce status */

   switch (*EventStatus)
   {
      case DEM_EVENT_STATUS_PREPASSED:

         if (   (DebounceCfg->JumpDown != FALSE)
             && (DebounceStatus->FDC > DEM_FDC_VALUE_UNQUALIFIED))
         {
            /* jump down */
            DebounceStatus->FDC = DEM_FDC_VALUE_UNQUALIFIED;
         }

         if (   DebounceStatus->FDC
              > (   DEM_FDC_VALUE_PASSED
                  + (sint16_least) DebounceCfg->CountOutStepSize) )
         {
            /* step down */
            DebounceStatus->FDC -= (Dem_FaultDetectionCounterType)
                                   DebounceCfg->CountOutStepSize;
         }
         else
         {
            /* qualify event as passed */
            DebounceStatus->FDC = DEM_FDC_VALUE_PASSED;
            *EventStatus = DEM_EVENT_STATUS_PASSED;
         }

         break;

      case DEM_EVENT_STATUS_PREFAILED:

         if (   (DebounceCfg->JumpUp != FALSE)
             && (DebounceStatus->FDC < DEM_FDC_VALUE_UNQUALIFIED))
         {
            /* jump up */
            DebounceStatus->FDC = DEM_FDC_VALUE_UNQUALIFIED;
         }

         if (   DebounceStatus->FDC
              < (   DEM_FDC_VALUE_FAILED
                  - (sint16_least) DebounceCfg->CountInStepSize) )
         {
            /* step up */
            DebounceStatus->FDC += (Dem_FaultDetectionCounterType)
                                   DebounceCfg->CountInStepSize;
         }
         else
         {
            /* qualify event as failed */
            DebounceStatus->FDC = DEM_FDC_VALUE_FAILED;
            *EventStatus = DEM_EVENT_STATUS_FAILED;
         }

         break;

      case DEM_EVENT_STATUS_PASSED:

         DebounceStatus->FDC = DEM_FDC_VALUE_PASSED;
         break;

      default: /* DEM_EVENT_STATUS_FAILED */

         DebounceStatus->FDC = DEM_FDC_VALUE_FAILED;
         break;

   } /* event status */
}

/*------------------[return FDC for an event]-------------------------------*/

FUNC(Std_ReturnType, DEM_CODE) Dem_GetFDCCounterBased(
   Dem_EventIdType                                                EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC)
{
   *FDC = Dem_DebounceCounterStatus[Dem_GbiDebounceIdx(EventId)].FDC;

   return E_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DEM_NUM_DEBOUNCE_COUNTER */
#endif /* DEM_USE_DEBOUNCE */

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
