
/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all definitions of the configuration of the
 ** AUTOSAR module Dem that are target independent, which is variant specific.
 **
 ** \project AUTOSAR Standard Core
 ** \author Marko Schneider
 ** \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** Copyright 2007 by Elektrobit Automotive GmbH and BMW Group
 ** All rights exclusively reserved for Elektrobit Automotive GmbH and
 ** BMW Group, unless expressly agreed to otherwise */

/** \addtogroup Dem Diagnostic Event Manager
 ** @{ */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <Dem_Internal_Depend_Specific.h> /* Variant specific API and internal
                                           * declarations, dependent and
                                           * static part */

#include <ApplMain.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*------------------[Extended data classes configuration]-------------------*/

/** \brief Numbers of segments on extended data class DemExtendedDataClass1 */
_STATIC_ CONST(uint8, DEM_CONST) Dem_EDNumbersDemExtendedDataClass1[1] =
{
   DEM_EDS_NUM_HEALING_COUNTER,
};

/** \brief Start bytes of segments on extended data class DemExtendedDataClass1 */
_STATIC_ CONST(uint8, DEM_CONST) Dem_EDStartBytesDemExtendedDataClass1[1] =
{
   0U,
};

/** \brief Sizes of segments on extended data class DemExtendedDataClass1 */
_STATIC_ CONST(uint8, DEM_CONST) Dem_EDSizesDemExtendedDataClass1[1] =
{
   1U,
};

/** \brief Data layout structure of extended data class DemExtendedDataClass1 */
_STATIC_ CONST(Dem_EDClassType, DEM_CONST) Dem_EDClassDemExtendedDataClass1 =
{
   1U, /* number of segments */
   Dem_EDNumbersDemExtendedDataClass1,
   Dem_EDStartBytesDemExtendedDataClass1,
   Dem_EDSizesDemExtendedDataClass1
};

/* Array containing the extended data classes (exported to be used in the
 * DEM library). */
CONSTP2CONST(Dem_EDClassType, DEM_CONST, DEM_CONST)
Dem_EDClasses[DEM_NUM_EDCLS] =
{
   &Dem_EDClassDemExtendedDataClass1,
};

/*------------------[Events configuration]----------------------------------*/

/* Specific event configuration description table (uses 'bit packing scheme')
 *
 * Note: For immediate storage it is mandatory, that the description for
 * DEM_EVENT_ID_INVALID is set to ImmediateStorage = false. */
CONST(Dem_EventDescSpecificType, DEM_CONST)
Dem_EventDescSpecific[DEM_NUMBER_OF_EVENTS] =
{
   { 0U },                                       /* invalid event id entry */
   { /* event: DM_Queue_FULL */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: DM_Queue_DELETED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: NVM_E_REQ_FAILED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: NVM_E_INTEGRITY_FAILED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: VSM_EVENT_OPMODE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 1U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: DM_TEST_APPL */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: DM_TEST_COM */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: DM_EVENT_ZEITBOTSCHAFTTIMEOUT */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CODING_EVENT_NOT_CODED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CODING_EVENT_TRANSACTION_FAILED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CODING_EVENT_SIGNATURE_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CODING_EVENT_WRONG_VEHICLE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CODING_EVENT_INVALID_DATA */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ECUM_E_ALL_RUN_REQUESTS_KILLED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: COMM_E_NET_START_IND_CHANNEL_0 */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: WDGM_E_ALIVE_SUPERVISION */
        ( 1U << DEM_IMMSTORAGE_OFFSET )       /* immediate storage enabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: FR_E_ACCESS */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: FRTRCV_E_FR_NO_TRCV_CONTROL */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: MTRPOS_FAILED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: INVERTER_FAILED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: TRQSNSR_FAILED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: BATTHIGH */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ROM_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: FAHRGESTELLNUMMER_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: FAHRGESTELLNUMMER_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: V_VEH_VEH_2_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CRC_V_VEH_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ALIV_V_VEH_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: V_VEH_VEH_2_MULTSIG_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: V_VEH_VEH_2_MULTSIG_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: KILOMETERSTAND_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: QU_V_VEH_COG_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: IGNITION_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: LOW_VOLT_LARGE_ASST_RED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: THERMAL_LIMIT */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: FR_PHYS_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: FR_COMM_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: OFFS_QUAD_EPS_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ALIV_OFFS_QUAD_EPS_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CRC_OFFS_QUAD_EPS_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: OFFS_QUAD_EPS_MULTSIG_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: OFFS_QUAD_EPS_MULTSIG_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: TAR_QTA_STRMOM_DV_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: TAR_STMOM_DV_ACT_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ALIV_TAR_QTA_STMOM_DV_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ALIV_TAR_STMOM_DV_ACT_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CRC_TAR_QTA_STMOM_DV_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CRC_TAR_STMOM_DV_ACT_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: SU_CLE_DRDY_DXP_SPEC_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: SU_CLU_STMOM_SFE_DXP_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: SU_CLU_STMOM_SFE_DXP_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: STEA_OFFS_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: STEA_OFFS_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: STEA_OFFS_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: SWA_SENSOR_LOSS_MULTITURN */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: PWRPK_FAILURE_REDPERF */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: PWRSPLY_GLOBAL_SURGE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: SWA_NOT_STRAIGHT_LINE_LEARNED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: MOTOR_SENSOR_GENERAL */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: PWRSPLY_GLOBAL_UNDVOLT */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: HIGH_TEMP_ASST_RED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: TRNSCTR_NVR_ASLEEP */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: IPDUM_E_TRANSMIT_FAILED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CODING_TUNING_ID_NOT_FOUND */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: DAMPING_FIREWALL_TOUCHED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ASSIST_FIREWALL_TOUCHED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: RETURN_FIREWALL_TOUCHED */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: DAMPING_FIREWALL_FLTMD */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ASSIST_FIREWALL_FLTMD */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: VBIC_FAULT_MODE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: PARK_ASSIST_DEACTIVATION */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: MANUFACTURING_PROCESS */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: SNSR_ROTPOS_STRANGLOSS */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 0U << DEM_ROEACTIVE_OFFSET )       /* response on event disabled */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 0U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: STEERING_ANGLE_SNSR_HW_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: STEERING_ANGLE_SNSR_HW_FAILURE_INT */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: NVM_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: RAM_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: GENERAL_MCU_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: SOFTWARE_RUNTIME_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: WATCHDOG_EVENT */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: EEPROM_TO_FEE_COPY_FAILURE */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: SOFTWARE_RUNTIME_FAILURE_NONOBD */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: GENERAL_MCU_FAILURE_NONOBD */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: GLOBAL_PWR_MGMT_REDUCEDASSIST */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: VYAW_VEH_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CRC_VYAW_VEH_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ALIV_VYAW_VEH_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: VYAW_VEH_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CRC_CON_VEH_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ACLNX_ACLNY_MASSCNTR_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CRC_ACLNY_COG_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ACLNX_ACLNY_MASSCNTR_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ALIV_CON_VEH_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ENERG_DGR_DRDY_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CON_VEH_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: MAX_I_SPEC_EPS_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CON_VEH_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: MAX_I_SPEC_EPS_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CON_VEH_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ST_CENG_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ST_CENG_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CTR_VIB_STW_MISSING */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ST_CENG_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: ALIV_ST_CENG_ERROR */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CTR_WARN_ILVL_VIB_EPS_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CTR_WARN_PTRN_VIB_EPS_INVALID */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
   { /* event: CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC */
        ( 0U << DEM_IMMSTORAGE_OFFSET )      /* immediate storage disabled */
      | ( 1U << DEM_ROEACTIVE_OFFSET )         /* response on event active */
      | ( 0U << DEM_RTE_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_C_CBK_CLEAR_EV_ALLOWED )
      | ( 0U << DEM_RTE_CBK_TRIGGER_ON_EV_ERROR )
      | ( 1U << DEM_C_CBK_TRIGGER_ON_EV_ERROR )
   },
};


/*------------------[RTE / C-callback notifications]------------------------*/

/* Combined lookup table for ClearEventAllowed */
#if (DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE > 0U)
CONST(Dem_ClrEvCallbackType, DEM_CONST)
   Dem_CbkLookupTableClrEvAllowed[DEM_C_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE] =
{
   { 5U, &Cdc_DemClearEventAllowed }, /* event: VSM_EVENT_OPMODE */
};
#endif

/* RTE-Callback function lookup table for ClearEventAllowed */
#if (DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE > 0U)
CONST(Dem_EventIdType, DEM_CONST)
   Dem_RteLookupTableClrEvAllowed[DEM_RTE_LOOKUP_TABLE_CLR_EV_ALLOWED_SIZE] =
{
};
#endif


/** \brief C-Callback function pointer table for TriggerOnError
**/
#if (DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE > 0U)
CONST(Dem_CbkFuncPtrTriggerOnErrorType, DEM_CONST)
   Dem_CbkFuncPtrTriggerOnError[DEM_C_CALLBACK_TABLE_TRIGGER_ON_ERROR_SIZE] =
{
   &Darh_TriggerOnErrorEntry,
};
#endif

/* C-Callback function lookup table for TriggerOnError */
#if (DEM_C_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE > 0U)
CONST(Dem_CbkLookupTableType, DEM_CONST)
   Dem_CbkLookupTableTriggerOnError[DEM_C_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE] =
{
   { 6U, 0U }, /* event: DM_TEST_APPL */
   { 7U, 0U }, /* event: DM_TEST_COM */
   { 9U, 0U }, /* event: CODING_EVENT_NOT_CODED */
   { 10U, 0U }, /* event: CODING_EVENT_TRANSACTION_FAILED */
   { 11U, 0U }, /* event: CODING_EVENT_SIGNATURE_ERROR */
   { 12U, 0U }, /* event: CODING_EVENT_WRONG_VEHICLE */
   { 13U, 0U }, /* event: CODING_EVENT_INVALID_DATA */
   { 19U, 0U }, /* event: MTRPOS_FAILED */
   { 20U, 0U }, /* event: INVERTER_FAILED */
   { 21U, 0U }, /* event: TRQSNSR_FAILED */
   { 22U, 0U }, /* event: BATTHIGH */
   { 23U, 0U }, /* event: ROM_FAILURE */
   { 24U, 0U }, /* event: FAHRGESTELLNUMMER_INVALID */
   { 25U, 0U }, /* event: FAHRGESTELLNUMMER_MISSING */
   { 26U, 0U }, /* event: V_VEH_VEH_2_MISSING */
   { 27U, 0U }, /* event: CRC_V_VEH_ERROR */
   { 28U, 0U }, /* event: ALIV_V_VEH_ERROR */
   { 29U, 0U }, /* event: V_VEH_VEH_2_MULTSIG_INVALID */
   { 30U, 0U }, /* event: V_VEH_VEH_2_MULTSIG_ERROR */
   { 31U, 0U }, /* event: KILOMETERSTAND_MISSING */
   { 32U, 0U }, /* event: QU_V_VEH_COG_ERROR */
   { 33U, 0U }, /* event: IGNITION_FAILURE */
   { 34U, 0U }, /* event: LOW_VOLT_LARGE_ASST_RED */
   { 35U, 0U }, /* event: THERMAL_LIMIT */
   { 36U, 0U }, /* event: FR_PHYS_FAILURE */
   { 37U, 0U }, /* event: FR_COMM_FAILURE */
   { 38U, 0U }, /* event: OFFS_QUAD_EPS_MISSING */
   { 39U, 0U }, /* event: ALIV_OFFS_QUAD_EPS_ERROR */
   { 40U, 0U }, /* event: CRC_OFFS_QUAD_EPS_ERROR */
   { 41U, 0U }, /* event: OFFS_QUAD_EPS_MULTSIG_INVALID */
   { 42U, 0U }, /* event: OFFS_QUAD_EPS_MULTSIG_ERROR */
   { 43U, 0U }, /* event: TAR_QTA_STRMOM_DV_MISSING */
   { 44U, 0U }, /* event: TAR_STMOM_DV_ACT_MISSING */
   { 45U, 0U }, /* event: ALIV_TAR_QTA_STMOM_DV_ERROR */
   { 46U, 0U }, /* event: ALIV_TAR_STMOM_DV_ACT_ERROR */
   { 47U, 0U }, /* event: CRC_TAR_QTA_STMOM_DV_ERROR */
   { 48U, 0U }, /* event: CRC_TAR_STMOM_DV_ACT_ERROR */
   { 49U, 0U }, /* event: SU_CLE_DRDY_DXP_SPEC_MISSING */
   { 50U, 0U }, /* event: SU_CLU_STMOM_SFE_DXP_INVALID */
   { 51U, 0U }, /* event: SU_CLU_STMOM_SFE_DXP_ERROR */
   { 52U, 0U }, /* event: STEA_OFFS_MISSING */
   { 53U, 0U }, /* event: STEA_OFFS_INVALID */
   { 54U, 0U }, /* event: STEA_OFFS_ERROR */
   { 55U, 0U }, /* event: SWA_SENSOR_LOSS_MULTITURN */
   { 56U, 0U }, /* event: PWRPK_FAILURE_REDPERF */
   { 57U, 0U }, /* event: PWRSPLY_GLOBAL_SURGE */
   { 58U, 0U }, /* event: SWA_NOT_STRAIGHT_LINE_LEARNED */
   { 59U, 0U }, /* event: MOTOR_SENSOR_GENERAL */
   { 60U, 0U }, /* event: PWRSPLY_GLOBAL_UNDVOLT */
   { 61U, 0U }, /* event: HIGH_TEMP_ASST_RED */
   { 62U, 0U }, /* event: TRNSCTR_NVR_ASLEEP */
   { 64U, 0U }, /* event: CODING_TUNING_ID_NOT_FOUND */
   { 72U, 0U }, /* event: MANUFACTURING_PROCESS */
   { 74U, 0U }, /* event: STEERING_ANGLE_SNSR_HW_FAILURE */
   { 75U, 0U }, /* event: STEERING_ANGLE_SNSR_HW_FAILURE_INT */
   { 76U, 0U }, /* event: NVM_FAILURE */
   { 77U, 0U }, /* event: RAM_FAILURE */
   { 78U, 0U }, /* event: GENERAL_MCU_FAILURE */
   { 79U, 0U }, /* event: SOFTWARE_RUNTIME_FAILURE */
   { 80U, 0U }, /* event: WATCHDOG_EVENT */
   { 81U, 0U }, /* event: EEPROM_TO_FEE_COPY_FAILURE */
   { 82U, 0U }, /* event: SOFTWARE_RUNTIME_FAILURE_NONOBD */
   { 83U, 0U }, /* event: GENERAL_MCU_FAILURE_NONOBD */
   { 84U, 0U }, /* event: GLOBAL_PWR_MGMT_REDUCEDASSIST */
   { 85U, 0U }, /* event: VYAW_VEH_MISSING */
   { 86U, 0U }, /* event: CRC_VYAW_VEH_ERROR */
   { 87U, 0U }, /* event: ALIV_VYAW_VEH_ERROR */
   { 88U, 0U }, /* event: VYAW_VEH_INVALID */
   { 89U, 0U }, /* event: CRC_CON_VEH_ERROR */
   { 90U, 0U }, /* event: ACLNX_ACLNY_MASSCNTR_MISSING */
   { 91U, 0U }, /* event: CRC_ACLNY_COG_ERROR */
   { 92U, 0U }, /* event: ACLNX_ACLNY_MASSCNTR_INVALID */
   { 93U, 0U }, /* event: ALIV_CON_VEH_ERROR */
   { 94U, 0U }, /* event: ENERG_DGR_DRDY_MISSING */
   { 95U, 0U }, /* event: CON_VEH_MISSING */
   { 96U, 0U }, /* event: MAX_I_SPEC_EPS_INVALID */
   { 97U, 0U }, /* event: CON_VEH_INVALID */
   { 98U, 0U }, /* event: MAX_I_SPEC_EPS_ERROR */
   { 99U, 0U }, /* event: CON_VEH_ERROR */
   { 100U, 0U }, /* event: ST_CENG_INVALID */
   { 101U, 0U }, /* event: ST_CENG_MISSING */
   { 102U, 0U }, /* event: CTR_VIB_STW_MISSING */
   { 103U, 0U }, /* event: ST_CENG_ERROR */
   { 104U, 0U }, /* event: ALIV_ST_CENG_ERROR */
   { 105U, 0U }, /* event: CTR_WARN_ILVL_VIB_EPS_INVALID */
   { 106U, 0U }, /* event: CTR_WARN_PTRN_VIB_EPS_INVALID */
   { 107U, 0U }, /* event: CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC */
};
#endif


/* RTE-Callback function lookup table for TriggerOnError */
#if (DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE > 0U)
CONST(Dem_EventIdType, DEM_CONST)
   Dem_RteLookupTableTriggerOnError[DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_ERROR_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define DEM_START_SEC_CODE
#include "MemMap.h"

/*------------------[interface to vendor-specific functions]----------------*/

FUNC(void, DEM_CODE) Dem_StorageWaitNvMReady(uint16 BlockId)
{
   Appl_WaitNvMReady(BlockId, TRUE);
}

#define DEM_STOP_SEC_CODE
#include "MemMap.h"

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
