/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of the AUTOSAR module Dem function
 ** Dem_GetFreezeFrameDataIdentifierByDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetFreezeFrameDataIdentifierByDTC.c 2480 2011-03-21 16:00:06Z olho2924 $
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

#include <Dem_Internal_Depend_Specific.h> /* API and internal declarations,
                                           * dependent and static part */

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

FUNC(Dem_ReturnGetFreezeFrameDataIdentifierByDTCType, DEM_CODE)
Dem_GetFreezeFrameDataIdentifierByDTC(
   Dem_DTCType                               DTC,
   Dem_DTCKindType                           DTCKind,
   Dem_DTCOriginType                         DTCOrigin,
   uint8                                     RecordNumber,
   P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)    ArraySize,
   P2VAR(P2CONST(uint16, AUTOMATIC, DEM_APPL_CONST), AUTOMATIC, DEM_APPL_DATA)
                                             DataId)
{
   Dem_ReturnGetFreezeFrameDataIdentifierByDTCType result;
   Dem_EventIdType EvId;

#if (DEM_DEV_ERROR_DETECT == STD_ON)
   /* check of Dem_InitializationState is not necessary:
    * it's allowed to get FF data Ids even if DEM is uninitialized */

   if ((DTC == (Dem_DTCType)0UL) || (DTC > (Dem_DTCType)0xFFFFFFUL))
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetFreezeFrameDataIdentifierByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_ID_WRONG_DTC;
   }
   if (   (DTCKind != DEM_DTC_KIND_ALL_DTCS)
       && (DTCKind != DEM_DTC_KIND_EMISSION_REL_DTCS)
      )
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetFreezeFrameDataIdentifierByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_ID_WRONG_DTCKIND;
   }
   if (   (    (DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            && (DTCOrigin != DEM_DTC_ORIGIN_SECONDARY_MEMORY) )
       && (     DTCOrigin != DEM_DTC_ORIGIN_MIRROR_MEMORY ) )
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetFreezeFrameDataIdentifierByDTC, DEM_E_PARAM_DATA);
      return DEM_GET_ID_WRONG_DTCORIGIN;
   }
   if (ArraySize == NULL_PTR)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetFreezeFrameDataIdentifierByDTC, DEM_E_PARAM_ADDRESS);
      return DEM_GET_ID_WRONG_DTC;
   }
   if (DataId == NULL_PTR)
   {
      DEM_REPORT_ERROR(
         DEM_SID_GetFreezeFrameDataIdentifierByDTC, DEM_E_PARAM_ADDRESS);
      return DEM_GET_ID_WRONG_DTC;
   }
#endif /* DEM_DEV_ERROR_DETECT */

   /* search event Id by DTC and map return value */
   switch (Dem_GetEvIdByDTC(DTC, DTCKind, DTCOrigin, &EvId))
   {
      case DEM_EIBD_OK:
         result = DEM_GET_ID_OK;
         break;
      case DEM_EIBD_WRONG_DTC:
         result = DEM_GET_ID_WRONG_DTC;
         break;
      case DEM_EIBD_WRONG_DTCKIND:
         result = DEM_GET_ID_WRONG_DTCKIND;
         break;
      case DEM_EIBD_WRONG_DTCORIGIN:
         result = DEM_GET_ID_WRONG_DTCORIGIN;
         break;
      default: /* should never be reached */
         result = DEM_GET_ID_WRONG_DTC;
         break;
   }

   if (result == DEM_GET_ID_OK)
   {
      const Dem_FFIdxType MaxNumFF = Dem_GbiMaxNumFF(EvId);

      /* return data Ids, if record number is valid */
      /* it is not checked, wether an entry is actually stored or not */
      if (((RecordNumber >= 1U) && (RecordNumber <= MaxNumFF))
           || (RecordNumber == 0xFFU))
      {
         /* get freeze frame class layout */
         CONSTP2CONST(Dem_FFClassType, AUTOMATIC, DEM_CONST) FFClass =
            Dem_FFClasses[Dem_GbiFFClassIdx(EvId)];

         /* copy number of FF segments value */
         *ArraySize = FFClass->NumFFSegs;
         /* copy pointer to data Id array */
         *DataId    = FFClass->DataID;
      }
      else
      {
         result = DEM_GET_ID_WRONG_FF_TYPE;
      }
   }

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
