/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the Dem_GetVersionInfo().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetVersionInfo.c 2556 2011-09-08 11:34:37Z olho2924 $
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


FUNC(void, DEM_CODE) Dem_GetVersionInfo(
   CONSTP2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA) VersionInfoPtr)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (VersionInfoPtr == NULL_PTR)
   {
      DEM_REPORT_ERROR(DEM_SID_GetVersionInfo, DEM_E_PARAM_ADDRESS);
      return;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   VersionInfoPtr->vendorID         = DEM_VENDOR_ID;
   VersionInfoPtr->moduleID         = DEM_MODULE_ID;
   VersionInfoPtr->sw_major_version = DEM_SW_MAJOR_VERSION;
   VersionInfoPtr->sw_minor_version = DEM_SW_MINOR_VERSION;
   VersionInfoPtr->sw_patch_version = DEM_SW_PATCH_VERSION;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
