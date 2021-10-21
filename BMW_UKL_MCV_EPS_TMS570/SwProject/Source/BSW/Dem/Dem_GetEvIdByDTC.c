/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the implementation of internal static function
 ** Dem_GetEvIdByDTC().
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_GetEvIdByDTC.c 2480 2011-03-21 16:00:06Z olho2924 $
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

FUNC(Dem_ReturnGetEvIdByDTCType, DEM_CODE) Dem_GetEvIdByDTC(
   Dem_DTCType                                     DTC,
   Dem_DTCKindType                                 DTCKind,
   Dem_DTCOriginType                               DTCOrigin,
   CONSTP2VAR(Dem_EventIdType, AUTOMATIC, DEM_VAR) EventId)
{
   Dem_ReturnGetEvIdByDTCType result = DEM_EIBD_WRONG_DTC;
   Dem_EvIdLeastType EvId = 1U; /* event Id 0 is skipped */
   boolean DTCFound = FALSE;

   /* DTC origin is not supported */
   if (Dem_SizeEventMem[DTCOrigin - 1U] == (Dem_SizeEvMemEntryType)0U)
   {
      result = DEM_EIBD_WRONG_DTCORIGIN;
   }
   else /* DTC origin is supported */
   {
      /* search for event Id of unique DTC */
      while ( (EvId <= (DEM_NUMBER_OF_EVENTS - 1U)) && (DTCFound == FALSE) )
      {
         if ( DTC == Dem_GbiDTC((Dem_EventIdType)EvId) )
         {
            DTCFound = TRUE;
         }
         else
         {
            EvId++;
         }
      }

      /* DTC matches to the current event Id */
      if (EvId <= (DEM_NUMBER_OF_EVENTS - 1U))
      {
         boolean DTCKindValid = TRUE;

         /* check DTC kind */
         if ( DTCKind != DEM_DTC_KIND_ALL_DTCS )
         {
            DTCKindValid = (boolean)((DTCKind == Dem_GbiDTCKind((Dem_EventIdType)EvId)) ? TRUE : FALSE);
         }

         if ( DTCKindValid == TRUE )
         {
            /* check DTC origin */
            if (DTCOrigin == Dem_GbiDTCOrigin((Dem_EventIdType)EvId))
            {
               *EventId = (Dem_EventIdType)EvId;

               /* fully matching entry found */
               result = DEM_EIBD_OK;
            }
            /* else: DTC origin does not match:
             *       result remains DEM_EIBD_WRONG_DTC */
         }
         else
         {
            /* DTC kind does not match */
            result = DEM_EIBD_WRONG_DTCKIND;
         }
      }
   }

   /* not necessary to set EventId = DEM_EVENT_ID_INVALID,
    * if result != DEM_EIBD_OK */

   return result;
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
