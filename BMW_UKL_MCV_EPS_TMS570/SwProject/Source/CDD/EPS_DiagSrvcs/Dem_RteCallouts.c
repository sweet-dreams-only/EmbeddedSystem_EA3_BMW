/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all static external API declarations of the
 ** AUTOSAR module Dem.
 **
 ** \project AUTOSAR Standard Core
 ** \author Stephanie Muehlenmeister
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** Dem_RteCallouts.c
 ** Release: 
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2008 by Elektrobit Automotive GmbH
 ** All rights exclusively reserved for Elektrobit Automotive GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem.h>                                /* Diagnostic Event Manager */

/* #include your callback-function header-file(s) here */

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

FUNC(Std_ReturnType, DEM_CODE) Xxx_DemGetFaultDetectionCounter(
   Dem_EventIdType                                                EventId,
   P2VAR(Dem_FaultDetectionCounterType, AUTOMATIC, DEM_APPL_DATA) FDC)
{
   *FDC = 0;
   return E_OK;
}

/* if RTE is not available provide following callouts */
#if (DEM_INCLUDE_RTE == STD_OFF)

FUNC(void, DEM_CODE) Dem_RteInitMonitorForEvent(
   const Dem_EventIdType         EventId,
   const Dem_InitMonitorKindType InitMonitorKind)
{
}

FUNC(void, DEM_CODE) Dem_RteTriggerOnEventStatus(
   const Dem_EventIdType       EventId,
   const Dem_DTCStatusMaskType OldDTCStatusMask,
   const Dem_DTCStatusMaskType NewDTCStatusMask)
{
}

FUNC(Std_ReturnType, DEM_CODE) Dem_RteGetDataValueByDataIdentifier(
   uint16                                 DataID,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer)
{
   /* insert your code here */

   return E_OK;
}

FUNC(Std_ReturnType, DEM_CODE) Dem_RteGetExtendedDataRecord(
   uint8                                  ExtendedDataRecordNumber,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) ExtendedDataRecord)
{
   /* insert your code here */

   return E_OK;
}

#endif /* DEM_INCLUDE_RTE == STD_ON */

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
