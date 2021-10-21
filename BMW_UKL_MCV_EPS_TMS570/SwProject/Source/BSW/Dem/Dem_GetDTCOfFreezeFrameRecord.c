/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetDTCOfFreezeFrameRecord().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetDTCOfFreezeFrameRecord.c 2160 2010-03-31 10:54:54Z olho2924 $
 ** Release: $3SOFT_DELIVERY_VERSION_INFORMATION$
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2005,2006 by 3SOFT GmbH
 ** All rights exclusively reserved for 3SOFT GmbH,
 ** unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Dem_Helper.h>                                /* Dem helper macros */
#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Static.h>                    /* API and internal declarations */

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

FUNC(Dem_ReturnGetDTCOfFreezeFrameRecordType, DEM_CODE)
   Dem_GetDTCOfFreezeFrameRecord(
      uint8                                         RecordNumber,
      Dem_DTCOriginType                             DTCOrigin,
      Dem_DTCKindType                               DTCKind,
      P2VAR(Dem_DTCType, AUTOMATIC, DEM_APPL_DATA)  DTC)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCOfFreezeFrameRecord, DEM_E_UNINIT);
      return DEM_GET_DTCOFFF_WRONG_RECORD;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY ) )
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCOfFreezeFrameRecord, DEM_E_PARAM_DATA);
      return DEM_GET_DTCOFFF_WRONG_RECORD;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_GetDTCOfFreezeFrameRecord, DEM_E_PARAM_DATA);
      return DEM_GET_DTCOFFF_WRONG_DTCKIND;
   }
   if (DTC == NULL_PTR)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetDTCOfFreezeFrameRecord, DEM_E_PARAM_ADDRESS);
      return DEM_GET_DTCOFFF_WRONG_RECORD;
   }
#else /* DEM_DEV_ERROR_DETECT */
   DEM_PARAM_UNUSED(DTCOrigin);
   DEM_PARAM_UNUSED(DTCKind);
#endif /* DEM_DEV_ERROR_DETECT */

   /* Function NOT fully implemented yet.
    * Implementation is scheduled for future releases. */
   DEM_PARAM_UNUSED(RecordNumber);

   *DTC = 0U; /* invalid DTC */

   return DEM_GET_DTCOFFF_WRONG_RECORD;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
