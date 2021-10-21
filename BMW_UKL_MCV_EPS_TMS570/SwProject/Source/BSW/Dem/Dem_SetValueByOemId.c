/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_SetValueByOemId().
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SetValueByOemId.c 2160 2010-03-31 10:54:54Z olho2924 $
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

FUNC(Std_ReturnType, DEM_CODE) Dem_SetValueByOemId(
   uint16                                 OemID,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DemDataValueByDataIDBuffer,
   uint8                                  DemDataValueByDataIDBufferLength)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_SetValueByOemId, DEM_E_UNINIT);
      return E_NOT_OK;
   }
   if (DemDataValueByDataIDBuffer == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_SetValueByOemId, DEM_E_PARAM_ADDRESS);
      return E_NOT_OK;
   }
#else /* DEM_DEV_ERROR_DETECT */
   DEM_PARAM_UNUSED(DemDataValueByDataIDBuffer);
#endif /* DEM_DEV_ERROR_DETECT */

   /* Function NOT fully implemented yet.
    * Implementation is scheduled for future releases. */
   DEM_PARAM_UNUSED(OemID);
   DEM_PARAM_UNUSED(DemDataValueByDataIDBufferLength);

   return E_NOT_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
