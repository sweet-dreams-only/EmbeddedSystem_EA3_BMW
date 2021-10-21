/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all definitions of the configuration of the
 ** AUTOSAR module Dem that are target independent.
 **
 ** It contains also the implementation of the Dem API functions:
 ** Dem_PreInit(), Dem_Init(), Dem_Shutdown() and Dem_MainFunction().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Static.c 2558 2011-09-09 10:30:11Z olho2924 $
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
 **/

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Static.h>                    /* API and internal declarations */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

#define DEM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* Status of the DEM */
VAR(Dem_InitializationStateType, DEM_VAR) Dem_InitializationState =
   DEM_UNINITIALIZED;

/* Status of DTC-filter */
VAR(Dem_DTCFilterType, DEM_VAR) Dem_DTCFilter =
{
   0xFFU,                         /* DTC status mask */
   DEM_DTC_KIND_ALL_DTCS,         /* DTC kind */
   DEM_DTC_ORIGIN_PRIMARY_MEMORY, /* DTC Origin */
   DEM_FILTER_WITH_SEVERITY_NO,   /* filter with severity */
   DEM_SEVERITY_NO_SEVERITY,      /* severity */
   DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO, /* filter for FDC */
   1U                             /* index of event to read next */
};

#define DEM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/* Status of record-filter */
VAR(uint8, DEM_VAR_NOINIT) Dem_RecordFilterIdx;

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* Lock for DCM access */
VAR(boolean, DEM_VAR_NOINIT) Dem_DcmAccessInProgress;

/* DTC record update flag */
VAR(boolean, DEM_VAR_NOINIT) Dem_DTCRecordUpdate;

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[API core-function definitions]-------------------------*/

FUNC(void, DEM_CODE) Dem_Shutdown(void)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_Shutdown, DEM_E_UNINIT);
      return;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* before shutdown, mark internal flag */
   Dem_InitializationState = DEM_POSTINITIALIZED;

   /* reset DCM-Access-Flag to enable main functionality (if disabled) */
   Dem_DcmAccessInProgress = FALSE;
   /* finalize all pending operations */
   /* discard return value -> Dem_MainFunction returns always E_OK */
   (void)Dem_MainFunction();

   /* shutdown RAM mirror of non volatile data */
   Dem_ShutdownNvData();
}

/*==================[internal function definitions]=========================*/

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/** @} doxygen end group definition */
/*============================[end of file]=================================*/
