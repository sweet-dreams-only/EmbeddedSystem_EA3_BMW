/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_StoreFF().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_StoreFF.c 2485 2011-03-28 13:44:31Z olho2924 $
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

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */


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

FUNC(void, DEM_CODE) Dem_StoreFF(
#if (DEM_DEV_ERROR_DETECT == STD_ON)
   uint8                                               ServiceId,
#endif /* DEM_DEV_ERROR_DETECT */
   P2VAR(Dem_EntryDataType, AUTOMATIC, DEM_VAR_NOINIT) EntryData,
   CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass)
{
   Std_ReturnType dataPresent = E_NOT_OK;
   Dem_FFSegIdxType SegIndex;

   /* get data values to all data Ids of the freeze frame class */
   for (SegIndex = 0U; SegIndex < FFClass->NumFFSegs; ++SegIndex)
   {
#if (DEM_GET_DATA_VALUE_BY_DATAID_RTE_USAGE == STD_ON)
      dataPresent = Rte_Call_DataValueByDataId_GetDataValueByDataIdentifier(
         FFClass->DataID[SegIndex],
         &EntryData[FFClass->StartByte[SegIndex]]);
#else
      dataPresent = DEM_CBK_FUNCPTR_GET_DATA_VALUE_BY_DATAID(
         FFClass->DataID[SegIndex],
         &EntryData[FFClass->StartByte[SegIndex]]);
#endif

      if (dataPresent != E_OK)
      {
         Dem_SizeEntryDataType index;

         /* fill FF segment with padding values */
         for (index = FFClass->StartByte[SegIndex];
              index < (FFClass->StartByte[SegIndex] + FFClass->Size[SegIndex]);
              ++index)
         {
            EntryData[index] = DEM_DATA_PADDING_VALUE;
         }

#if (DEM_DEV_ERROR_DETECT == STD_ON)
         /* report non-available data for FFS */
         DEM_REPORT_ERROR(ServiceId, DEM_E_NODATAAVAILABLE);
#endif /* DEM_DEV_ERROR_DETECT */
      }
   }
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
