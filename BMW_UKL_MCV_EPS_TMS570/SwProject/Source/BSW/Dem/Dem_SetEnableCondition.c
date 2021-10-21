/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_SetEnableCondition().
 **
 ** \project AUTOSAR Standard Core
 ** \author Tobias Jordan
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_SetEnableCondition.c 2061 2010-01-18 12:10:39Z olho2924 $
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

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

#if (DEM_USE_ENABLE_CONDITION == STD_ON)

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

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition(
   uint8     EnableConditionID,
   boolean   ConditionFulfilled)
{
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   if (Dem_InitializationState != DEM_INITIALIZED)
   {
      DEM_REPORT_ERROR(DEM_SID_SetEnableCondition, DEM_E_UNINIT);
      return E_NOT_OK;
   }
   if (EnableConditionID >= DEM_NUM_ENABLECONDITIONS)
   {
      DEM_REPORT_ERROR(DEM_SID_SetEnableCondition, DEM_E_PARAM_CONFIG);
      return E_NOT_OK;
   }
   if (   (ConditionFulfilled != FALSE)
       && (ConditionFulfilled != TRUE)
      )
   {
      DEM_REPORT_ERROR(DEM_SID_SetEnableCondition, DEM_E_PARAM_DATA);
      return E_NOT_OK;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   Dem_EnableCondition[EnableConditionID] = ConditionFulfilled;

   return E_OK;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

#endif /* DEM_USE_ENABLE_CONDITION */

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
