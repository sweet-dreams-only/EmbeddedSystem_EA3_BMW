

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains all definitions of the configuration of the
 ** AUTOSAR module Dem that are target independent.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
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

#include "Edch_EventStatusChanged.h"
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*------------------[Freeze frame classes configuration]--------------------*/

/** \brief DataIDs of segments on freeze frame class DemFreezeFrameClass1
 **
 ** \note ACCESSED by API */
_STATIC_ CONST(uint16, DEM_APPL_CONST) Dem_FFDataIdsDemFreezeFrameClass1[10] =
{
   DEM_FFS_DID_KILOMETER,
   DEM_FFS_DID_ABSOLUTE_TIME,
   DEM_FFS_DID_SS_VEHSPD,
   DEM_FFS_DID_SS_ST_DRV_VEH,
   DEM_FFS_DID_SS_ECU_VLTS_SUPP,
   DEM_FFS_DID_SS_STRWHL_ANGLE,
   DEM_FFS_DID_SS_CMD_MTR_TRQ,
   DEM_FFS_DID_SS_HW_TRQ,
   DEM_FFS_DID_SS_NTC_NUM,
   DEM_FFS_DID_SS_PSCM_STATUS,
};

/** \brief Start bytes of segments on freeze frame class DemFreezeFrameClass1 */
_STATIC_ CONST(uint8, DEM_CONST) Dem_FFStartBytesDemFreezeFrameClass1[10] =
{
   0U, 3U, 7U, 8U, 9U, 10U, 12U, 14U, 16U, 20U,
};

/** \brief Sizes of segments on freeze frame class DemFreezeFrameClass1 */
_STATIC_ CONST(uint8, DEM_CONST) Dem_FFSizesDemFreezeFrameClass1[10] =
{
   3U, 4U, 1U, 1U, 1U, 2U, 2U, 2U, 4U, 2U,
};

/** \brief Data layout structure of freeze frame class DemFreezeFrameClass1 */
_STATIC_ CONST(Dem_FFClassType, DEM_CONST) Dem_FFClassDemFreezeFrameClass1 =
{
   10U, /* number of segments */
   Dem_FFDataIdsDemFreezeFrameClass1,
   Dem_FFStartBytesDemFreezeFrameClass1,
   Dem_FFSizesDemFreezeFrameClass1
};


/* Array containing the freeze frame classes (exported to be used in the
 * DEM library). */
CONSTP2CONST(Dem_FFClassType, DEM_CONST, DEM_CONST)
Dem_FFClasses[DEM_NUM_FFCLS] =
{
   &Dem_FFClassDemFreezeFrameClass1,
};



/* pre calculated position of entry data */
CONST(Dem_SizeEntryDataType, DEM_CONST) Dem_PFFEntryDataStartPos[DEM_NBR_OF_EVENTS_WITH_PFF + 1] =
{
  /* first element is not used to be able to use index from configuration directly */
  0U,
 
};


/*------------------[Extended data classes configuration]-------------------*/

/* extended data configuration and storage layout is variant specific and
 * therefore done in Dem_Cfg_Specific.c */

/*------------------[DTC groups configuration]------------------------------*/

/* Array containing the DTC group values */
CONST(Dem_DTCGroupType, DEM_CONST) Dem_DTCGroups[DEM_NUM_DTC_GROUPS] =
{
   DEM_DTC_GROUP_EMISSION_REL_DTCS,
   DEM_DTC_GROUP_POWERTRAIN_DTCS,
   DEM_DTC_GROUP_CHASSIS_DTCS,
   DEM_DTC_GROUP_BODY_DTCS,
   DEM_DTC_GROUP_NETWORK_COM_DTCS,
};

/*------------------[Events configuration]----------------------------------*/


/* Event configuration description table (uses 'bit packing scheme) */
CONST(Dem_EventDescType, DEM_CONST) Dem_EventDesc[DEM_NUMBER_OF_EVENTS] =
{
   { 0U, 0U },                                /* invalid event id entry */
   { /* event: DM_Queue_FULL */
      /* DTC value */
      0x4823CEU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: DM_Queue_DELETED */
      /* DTC value */
      0x4823CFU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: NVM_E_REQ_FAILED */
      /* DTC value */
      0x482286U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: NVM_E_INTEGRITY_FAILED */
      /* DTC value */
      0x482289U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: VSM_EVENT_OPMODE */
      /* DTC value */
      0x023000U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_CHECK_IMMEDIATELY */
      | (uint32)( (uint32)3U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_VSM_OPMODE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: DM_TEST_APPL */
      /* DTC value */
      0x02FF30U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_CHECK_IMMEDIATELY */
      | (uint32)( (uint32)3U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: DM_TEST_COM */
      /* DTC value */
      0xD50BFFU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_CHECK_IMMEDIATELY */
      | (uint32)( (uint32)3U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: DM_EVENT_ZEITBOTSCHAFTTIMEOUT */
      /* DTC value */
      0x4823CDU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CODING_EVENT_NOT_CODED */
      /* DTC value */
      0x023008U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CODING_EVENT_TRANSACTION_FAILED */
      /* DTC value */
      0x023009U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CODING_EVENT_SIGNATURE_ERROR */
      /* DTC value */
      0x02300AU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CODING_EVENT_WRONG_VEHICLE */
      /* DTC value */
      0x02300BU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CODING_EVENT_INVALID_DATA */
      /* DTC value */
      0x02300CU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ECUM_E_ALL_RUN_REQUESTS_KILLED */
      /* DTC value */
      0x48228AU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: COMM_E_NET_START_IND_CHANNEL_0 */
      /* DTC value */
      0x48228DU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: WDGM_E_ALIVE_SUPERVISION */
      /* DTC value */
      0x482296U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: FR_E_ACCESS */
      /* DTC value */
      0x48228EU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: FRTRCV_E_FR_NO_TRCV_CONTROL */
      /* DTC value */
      0x482292U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: MTRPOS_FAILED */
      /* DTC value */
      0x4823D2U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: INVERTER_FAILED */
      /* DTC value */
      0x4823E4U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: TRQSNSR_FAILED */
      /* DTC value */
      0x4823ECU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: BATTHIGH */
      /* DTC value */
      0x482399U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ROM_FAILURE */
      /* DTC value */
      0x4822DFU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: FAHRGESTELLNUMMER_INVALID */
      /* DTC value */
      0xD5144EU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: FAHRGESTELLNUMMER_MISSING */
      /* DTC value */
      0xD51482U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: V_VEH_VEH_2_MISSING */
      /* DTC value */
      0xD514B8U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CRC_V_VEH_ERROR */
      /* DTC value */
      0xD514B9U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ALIV_V_VEH_ERROR */
      /* DTC value */
      0xD514BAU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: V_VEH_VEH_2_MULTSIG_INVALID */
      /* DTC value */
      0xD514BEU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: V_VEH_VEH_2_MULTSIG_ERROR */
      /* DTC value */
      0xD514BFU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: KILOMETERSTAND_MISSING */
      /* DTC value */
      0xD514F2U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: QU_V_VEH_COG_ERROR */
      /* DTC value */
      0xD51A3EU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: IGNITION_FAILURE */
      /* DTC value */
      0x48238DU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: LOW_VOLT_LARGE_ASST_RED */
      /* DTC value */
      0x4823FCU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: THERMAL_LIMIT */
      /* DTC value */
      0x4823FAU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: FR_PHYS_FAILURE */
      /* DTC value */
      0xD5041FU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: FR_COMM_FAILURE */
      /* DTC value */
      0xD50420U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: OFFS_QUAD_EPS_MISSING */
      /* DTC value */
      0xD51458U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ALIV_OFFS_QUAD_EPS_ERROR */
      /* DTC value */
      0xD5145AU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CRC_OFFS_QUAD_EPS_ERROR */
      /* DTC value */
      0xD51459U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: OFFS_QUAD_EPS_MULTSIG_INVALID */
      /* DTC value */
      0xD5145BU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: OFFS_QUAD_EPS_MULTSIG_ERROR */
      /* DTC value */
      0xD5145CU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: TAR_QTA_STRMOM_DV_MISSING */
      /* DTC value */
      0xD51C12U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: TAR_STMOM_DV_ACT_MISSING */
      /* DTC value */
      0xD51C20U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ALIV_TAR_QTA_STMOM_DV_ERROR */
      /* DTC value */
      0xD51C14U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ALIV_TAR_STMOM_DV_ACT_ERROR */
      /* DTC value */
      0xD51C22U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CRC_TAR_QTA_STMOM_DV_ERROR */
      /* DTC value */
      0xD51C13U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CRC_TAR_STMOM_DV_ACT_ERROR */
      /* DTC value */
      0xD51C21U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: SU_CLE_DRDY_DXP_SPEC_MISSING */
      /* DTC value */
      0xD5150AU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: SU_CLU_STMOM_SFE_DXP_INVALID */
      /* DTC value */
      0xD51510U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: SU_CLU_STMOM_SFE_DXP_ERROR */
      /* DTC value */
      0xD51511U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: STEA_OFFS_MISSING */
      /* DTC value */
      0xD51B30U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: STEA_OFFS_INVALID */
      /* DTC value */
      0xD51B34U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: STEA_OFFS_ERROR */
      /* DTC value */
      0xD51B35U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: SWA_SENSOR_LOSS_MULTITURN */
      /* DTC value */
      0x482394U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: PWRPK_FAILURE_REDPERF */
      /* DTC value */
      0x4822DAU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: PWRSPLY_GLOBAL_SURGE */
      /* DTC value */
      0x48238EU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: SWA_NOT_STRAIGHT_LINE_LEARNED */
      /* DTC value */
      0x4823C2U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: MOTOR_SENSOR_GENERAL */
      /* DTC value */
      0x4823C6U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: PWRSPLY_GLOBAL_UNDVOLT */
      /* DTC value */
      0x4823D4U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: HIGH_TEMP_ASST_RED */
      /* DTC value */
      0x4823F9U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: TRNSCTR_NVR_ASLEEP */
      /* DTC value */
      0x482297U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: IPDUM_E_TRANSMIT_FAILED */
      /* DTC value */
      0x8BAC63U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CODING_TUNING_ID_NOT_FOUND */
      /* DTC value */
      0x4822F7U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: DAMPING_FIREWALL_TOUCHED */
      /* DTC value */
      0x4822D5U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ASSIST_FIREWALL_TOUCHED */
      /* DTC value */
      0x4822C6U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: RETURN_FIREWALL_TOUCHED */
      /* DTC value */
      0x4822D8U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: DAMPING_FIREWALL_FLTMD */
      /* DTC value */
      0x4822D6U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ASSIST_FIREWALL_FLTMD */
      /* DTC value */
      0x4822D4U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: VBIC_FAULT_MODE */
      /* DTC value */
      0x4822D7U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: PARK_ASSIST_DEACTIVATION */
      /* DTC value */
      0x4822DCU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: MANUFACTURING_PROCESS */
      /* DTC value */
      0x4822DBU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* No severity specified for DTC */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: SNSR_ROTPOS_STRANGLOSS */
      /* DTC value */
      0x482451U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_SECONDARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* Healing disabled (HealingCycles = 0) */
      | (uint32)( (uint32)0U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: STEERING_ANGLE_SNSR_HW_FAILURE */
      /* DTC value */
      0x4823C5U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: STEERING_ANGLE_SNSR_HW_FAILURE_INT */
      /* DTC value */
      0x4822DEU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: NVM_FAILURE */
      /* DTC value */
      0x4822E0U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: RAM_FAILURE */
      /* DTC value */
      0x4822E3U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: GENERAL_MCU_FAILURE */
      /* DTC value */
      0x4822E4U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: SOFTWARE_RUNTIME_FAILURE */
      /* DTC value */
      0x4822E6U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: WATCHDOG_EVENT */
      /* DTC value */
      0x4822E7U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      OBD_CYCLE
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: EEPROM_TO_FEE_COPY_FAILURE */
      /* DTC value */
      0x4822F1U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: SOFTWARE_RUNTIME_FAILURE_NONOBD */
      /* DTC value */
      0x4822F6U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: GENERAL_MCU_FAILURE_NONOBD */
      /* DTC value */
      0x4822F5U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: GLOBAL_PWR_MGMT_REDUCEDASSIST */
      /* DTC value */
      0x4822ECU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: VYAW_VEH_MISSING */
      /* DTC value */
      0xD514C2U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CRC_VYAW_VEH_ERROR */
      /* DTC value */
      0xD514C3U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ALIV_VYAW_VEH_ERROR */
      /* DTC value */
      0xD514C4U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: VYAW_VEH_INVALID */
      /* DTC value */
      0xD514C8U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CRC_CON_VEH_ERROR */
      /* DTC value */
      0xD514FFU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ACLNX_ACLNY_MASSCNTR_MISSING */
      /* DTC value */
      0xD51542U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CRC_ACLNY_COG_ERROR */
      /* DTC value */
      0xD51543U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ACLNX_ACLNY_MASSCNTR_INVALID */
      /* DTC value */
      0xD51548U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ALIV_CON_VEH_ERROR */
      /* DTC value */
      0xD51565U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ENERG_DGR_DRDY_MISSING */
      /* DTC value */
      0xD51600U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CON_VEH_MISSING */
      /* DTC value */
      0xD5160CU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: MAX_I_SPEC_EPS_INVALID */
      /* DTC value */
      0xD51645U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CON_VEH_INVALID */
      /* DTC value */
      0xD5165EU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: MAX_I_SPEC_EPS_ERROR */
      /* DTC value */
      0xD51853U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CON_VEH_ERROR */
      /* DTC value */
      0xD51858U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ST_CENG_INVALID */
      /* DTC value */
      0xD51966U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ST_CENG_MISSING */
      /* DTC value */
      0xD519CCU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CTR_VIB_STW_MISSING */
      /* DTC value */
      0xD519E2U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ST_CENG_ERROR */
      /* DTC value */
      0xD51A38U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: ALIV_ST_CENG_ERROR */
      /* DTC value */
      0xD51A4BU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CTR_WARN_ILVL_VIB_EPS_INVALID */
      /* DTC value */
      0xD51ADBU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CTR_WARN_PTRN_VIB_EPS_INVALID */
      /* DTC value */
      0xD51AEBU
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_NETWORK_COM_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* No warning indicator used */
      | (uint8)( (uint8)0U << DEM_INDICATORUSED_OFFSET )
   },
   { /* event: CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC */
      /* DTC value */
      0x482285U
      /* Origin of DTC */
      | (uint32)( (uint32)DEM_DTC_ORIGIN_PRIMARY_MEMORY << DEM_DTCORIGIN_OFFSET )
      /* Group of DTC */
      | (uint32)( (uint32)DEM_DTCGRP_IDX_BODY_DTCS << DEM_DTCGROUP_OFFSET )
      /* Severity of DTC: corresponds to DEM_SEVERITY_NO_SEVERITY */
      | (uint32)( (uint32)0U << DEM_DTCSEVERITY_OFFSET )
      /* global healing enabled (DEM_GLOBAL_HEALINGCYCLES_VALUE) */
      | (uint32)( (uint32)1U << DEM_HEALINGCYCLES_OFFSET )
      ,
      /* Operation cycle Id */
      DEM_OPCYCLE_DEFAULT
      /* Warning indicator used */
      | (uint8)( (uint8)1U << DEM_INDICATORUSED_OFFSET )
   },
};

/*------------------[Warning indicators configuration]----------------------*/

/* Warning indicator configuration description table */
CONST(Dem_IndicatorDescType, DEM_CONST)
   Dem_IndicatorDesc[DEM_NUMBER_OF_INDICATORS] =
{
   { /* warning indicator: EPS_LAMP (= ID 0) */
      /* number: */ 27U, /* index: */ 0U
   },
};

/* Warning indicator-link configuration link table */
CONST(Dem_IndicatorLinkType, DEM_CONST)
   Dem_IndicatorLink[DEM_NUM_INDICATOR_LINKS] =
{
   /* indicator-links of EPS_LAMP (= ID 0) */
   {
      CODING_EVENT_NOT_CODED,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      CODING_EVENT_TRANSACTION_FAILED,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      CODING_EVENT_SIGNATURE_ERROR,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      CODING_EVENT_WRONG_VEHICLE,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      CODING_EVENT_INVALID_DATA,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      MTRPOS_FAILED,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      INVERTER_FAILED,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      TRQSNSR_FAILED,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      BATTHIGH,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      ROM_FAILURE,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      LOW_VOLT_LARGE_ASST_RED,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      THERMAL_LIMIT,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      SWA_NOT_STRAIGHT_LINE_LEARNED,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      MOTOR_SENSOR_GENERAL,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      CODING_TUNING_ID_NOT_FOUND,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      STEERING_ANGLE_SNSR_HW_FAILURE,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      STEERING_ANGLE_SNSR_HW_FAILURE_INT,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      NVM_FAILURE,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      RAM_FAILURE,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      GENERAL_MCU_FAILURE,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      SOFTWARE_RUNTIME_FAILURE,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      WATCHDOG_EVENT,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      EEPROM_TO_FEE_COPY_FAILURE,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      SOFTWARE_RUNTIME_FAILURE_NONOBD,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      GENERAL_MCU_FAILURE_NONOBD,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      GLOBAL_PWR_MGMT_REDUCEDASSIST,
      DEM_INDICATOR_CONTINUOUS
   },
   {
      CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC,
      DEM_INDICATOR_CONTINUOUS
   },
};

/* no debouncing */

/*------------------[RTE / C-callback notifications]------------------------*/

/* Event callback property table */
CONST(Dem_CbkPropertyType, DEM_CONST) Dem_CbkProperty[DEM_NUMBER_OF_EVENTS] =
{
   0U,                                           /* invalid event id entry */
   /* event: DM_Queue_FULL */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: DM_Queue_DELETED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: NVM_E_REQ_FAILED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: NVM_E_INTEGRITY_FAILED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: VSM_EVENT_OPMODE */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: DM_TEST_APPL */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: DM_TEST_COM */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: DM_EVENT_ZEITBOTSCHAFTTIMEOUT */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CODING_EVENT_NOT_CODED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CODING_EVENT_TRANSACTION_FAILED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CODING_EVENT_SIGNATURE_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CODING_EVENT_WRONG_VEHICLE */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CODING_EVENT_INVALID_DATA */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ECUM_E_ALL_RUN_REQUESTS_KILLED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: COMM_E_NET_START_IND_CHANNEL_0 */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: WDGM_E_ALIVE_SUPERVISION */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: FR_E_ACCESS */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: FRTRCV_E_FR_NO_TRCV_CONTROL */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: MTRPOS_FAILED */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: INVERTER_FAILED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: TRQSNSR_FAILED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: BATTHIGH */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ROM_FAILURE */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: FAHRGESTELLNUMMER_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: FAHRGESTELLNUMMER_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: V_VEH_VEH_2_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CRC_V_VEH_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ALIV_V_VEH_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: V_VEH_VEH_2_MULTSIG_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: V_VEH_VEH_2_MULTSIG_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: KILOMETERSTAND_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: QU_V_VEH_COG_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: IGNITION_FAILURE */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: LOW_VOLT_LARGE_ASST_RED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: THERMAL_LIMIT */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: FR_PHYS_FAILURE */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: FR_COMM_FAILURE */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: OFFS_QUAD_EPS_MISSING */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ALIV_OFFS_QUAD_EPS_ERROR */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CRC_OFFS_QUAD_EPS_ERROR */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: OFFS_QUAD_EPS_MULTSIG_INVALID */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: OFFS_QUAD_EPS_MULTSIG_ERROR */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: TAR_QTA_STRMOM_DV_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: TAR_STMOM_DV_ACT_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ALIV_TAR_QTA_STMOM_DV_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ALIV_TAR_STMOM_DV_ACT_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CRC_TAR_QTA_STMOM_DV_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CRC_TAR_STMOM_DV_ACT_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: SU_CLE_DRDY_DXP_SPEC_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: SU_CLU_STMOM_SFE_DXP_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: SU_CLU_STMOM_SFE_DXP_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: STEA_OFFS_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: STEA_OFFS_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: STEA_OFFS_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: SWA_SENSOR_LOSS_MULTITURN */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: PWRPK_FAILURE_REDPERF */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: PWRSPLY_GLOBAL_SURGE */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: SWA_NOT_STRAIGHT_LINE_LEARNED */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: MOTOR_SENSOR_GENERAL */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: PWRSPLY_GLOBAL_UNDVOLT */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: HIGH_TEMP_ASST_RED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: TRNSCTR_NVR_ASLEEP */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: IPDUM_E_TRANSMIT_FAILED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CODING_TUNING_ID_NOT_FOUND */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: DAMPING_FIREWALL_TOUCHED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ASSIST_FIREWALL_TOUCHED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: RETURN_FIREWALL_TOUCHED */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: DAMPING_FIREWALL_FLTMD */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ASSIST_FIREWALL_FLTMD */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: VBIC_FAULT_MODE */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: PARK_ASSIST_DEACTIVATION */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: MANUFACTURING_PROCESS */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: SNSR_ROTPOS_STRANGLOSS */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: STEERING_ANGLE_SNSR_HW_FAILURE */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: STEERING_ANGLE_SNSR_HW_FAILURE_INT */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: NVM_FAILURE */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: RAM_FAILURE */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: GENERAL_MCU_FAILURE */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: SOFTWARE_RUNTIME_FAILURE */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: WATCHDOG_EVENT */
      /* no init monitor callback *//* no trigger on event status port */DEM_C_CBK_TRIGGER_ON_EV_STATUS | DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: EEPROM_TO_FEE_COPY_FAILURE */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: SOFTWARE_RUNTIME_FAILURE_NONOBD */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: GENERAL_MCU_FAILURE_NONOBD */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: GLOBAL_PWR_MGMT_REDUCEDASSIST */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: VYAW_VEH_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CRC_VYAW_VEH_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ALIV_VYAW_VEH_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: VYAW_VEH_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CRC_CON_VEH_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ACLNX_ACLNY_MASSCNTR_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CRC_ACLNY_COG_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ACLNX_ACLNY_MASSCNTR_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ALIV_CON_VEH_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ENERG_DGR_DRDY_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CON_VEH_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: MAX_I_SPEC_EPS_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CON_VEH_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: MAX_I_SPEC_EPS_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CON_VEH_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ST_CENG_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ST_CENG_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CTR_VIB_STW_MISSING */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ST_CENG_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: ALIV_ST_CENG_ERROR */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CTR_WARN_ILVL_VIB_EPS_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CTR_WARN_PTRN_VIB_EPS_INVALID */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
   /* event: CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC */
      /* no init monitor callback *//* no trigger on event status port *//* no trigger on event status c-callbacks */DEM_C_CBK_FAULT_DETECTION_CTR | DEM_ZERO_END,
};


#if (DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE != 0U)
/* C-Callback function pointer table for InitMonitor */
CONST(Dem_CbkFuncPtrInitMonitorType, DEM_CONST)
   Dem_InitMonitorCallback[DEM_C_CALLBACK_TABLE_INIT_MONITOR_SIZE] =
{
};
#endif

#if (DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE != 0U)
/* RTE-Lookup table for InitMonitor */
CONST(Dem_EventIdType, DEM_CONST)
   Dem_RteLookupTableInitMonitor[DEM_RTE_LOOKUP_TABLE_INIT_MONITOR_SIZE] =
{
};
#endif


#if (DEM_C_CALLBACK_TABLE_TRIGGER_ON_EVENT_SIZE != 0U)
/* C-Callback function pointer table for TriggerOnEventStatus */
CONST(Dem_CbkFuncPtrTriggerOnEventType, DEM_CONST)
   Dem_CbkFuncPtrTriggerOnEvent[DEM_C_CALLBACK_TABLE_TRIGGER_ON_EVENT_SIZE] =
{
   &Edch_EventStatusChanged,
};
#endif

#if (DEM_C_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE != 0U)
/* C-Lookup table for TriggerOnEventStatus */
CONST(Dem_CbkLookupTableType, DEM_CONST)
   Dem_CbkLookupTableTriggerOnEvent[DEM_C_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE] =
{
   { 19U, 0U }, /* event: MTRPOS_FAILED */
   { 23U, 0U }, /* event: ROM_FAILURE */
   { 36U, 0U }, /* event: FR_PHYS_FAILURE */
   { 37U, 0U }, /* event: FR_COMM_FAILURE */
   { 38U, 0U }, /* event: OFFS_QUAD_EPS_MISSING */
   { 39U, 0U }, /* event: ALIV_OFFS_QUAD_EPS_ERROR */
   { 40U, 0U }, /* event: CRC_OFFS_QUAD_EPS_ERROR */
   { 41U, 0U }, /* event: OFFS_QUAD_EPS_MULTSIG_INVALID */
   { 42U, 0U }, /* event: OFFS_QUAD_EPS_MULTSIG_ERROR */
   { 55U, 0U }, /* event: SWA_SENSOR_LOSS_MULTITURN */
   { 58U, 0U }, /* event: SWA_NOT_STRAIGHT_LINE_LEARNED */
   { 74U, 0U }, /* event: STEERING_ANGLE_SNSR_HW_FAILURE */
   { 75U, 0U }, /* event: STEERING_ANGLE_SNSR_HW_FAILURE_INT */
   { 76U, 0U }, /* event: NVM_FAILURE */
   { 77U, 0U }, /* event: RAM_FAILURE */
   { 78U, 0U }, /* event: GENERAL_MCU_FAILURE */
   { 79U, 0U }, /* event: SOFTWARE_RUNTIME_FAILURE */
   { 80U, 0U }, /* event: WATCHDOG_EVENT */
};
#endif

#if (DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE != 0U)
/* RTE-Lookup table for TriggerOnEventStatus */
CONST(Dem_EventIdType, DEM_CONST)
   Dem_RteLookupTableTriggerOnEvent[DEM_RTE_LOOKUP_TABLE_TRIGGER_ON_EVENT_SIZE] =
{
};
#endif


#if (DEM_C_CALLBACK_TABLE_GET_FDC_SIZE != 0U)
/* C-Callback function pointer table for GetFaultDetectionCounter */
CONST(Dem_CbkFuncPtrGetFDCType, DEM_CONST)
   Dem_CbkFuncPtrGetFaultDetectionCounter[DEM_C_CALLBACK_TABLE_GET_FDC_SIZE] =
{
   &Xxx_DemGetFaultDetectionCounter,
};
#endif

#if (DEM_C_LOOKUP_TABLE_GET_FDC_SIZE != 0U)
/* C-Lookup table for GetFaultDetectionCounter */
CONST(Dem_CbkLookupTableType, DEM_CONST)
   Dem_CbkLookupTableGetFaultDetectionCounter[DEM_C_LOOKUP_TABLE_GET_FDC_SIZE] =
{
   { 1U, 0U }, /* event: DM_Queue_FULL */
   { 2U, 0U }, /* event: DM_Queue_DELETED */
   { 3U, 0U }, /* event: NVM_E_REQ_FAILED */
   { 4U, 0U }, /* event: NVM_E_INTEGRITY_FAILED */
   { 5U, 0U }, /* event: VSM_EVENT_OPMODE */
   { 6U, 0U }, /* event: DM_TEST_APPL */
   { 7U, 0U }, /* event: DM_TEST_COM */
   { 8U, 0U }, /* event: DM_EVENT_ZEITBOTSCHAFTTIMEOUT */
   { 9U, 0U }, /* event: CODING_EVENT_NOT_CODED */
   { 10U, 0U }, /* event: CODING_EVENT_TRANSACTION_FAILED */
   { 11U, 0U }, /* event: CODING_EVENT_SIGNATURE_ERROR */
   { 12U, 0U }, /* event: CODING_EVENT_WRONG_VEHICLE */
   { 13U, 0U }, /* event: CODING_EVENT_INVALID_DATA */
   { 14U, 0U }, /* event: ECUM_E_ALL_RUN_REQUESTS_KILLED */
   { 15U, 0U }, /* event: COMM_E_NET_START_IND_CHANNEL_0 */
   { 16U, 0U }, /* event: WDGM_E_ALIVE_SUPERVISION */
   { 17U, 0U }, /* event: FR_E_ACCESS */
   { 18U, 0U }, /* event: FRTRCV_E_FR_NO_TRCV_CONTROL */
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
   { 63U, 0U }, /* event: IPDUM_E_TRANSMIT_FAILED */
   { 64U, 0U }, /* event: CODING_TUNING_ID_NOT_FOUND */
   { 65U, 0U }, /* event: DAMPING_FIREWALL_TOUCHED */
   { 66U, 0U }, /* event: ASSIST_FIREWALL_TOUCHED */
   { 67U, 0U }, /* event: RETURN_FIREWALL_TOUCHED */
   { 68U, 0U }, /* event: DAMPING_FIREWALL_FLTMD */
   { 69U, 0U }, /* event: ASSIST_FIREWALL_FLTMD */
   { 70U, 0U }, /* event: VBIC_FAULT_MODE */
   { 71U, 0U }, /* event: PARK_ASSIST_DEACTIVATION */
   { 72U, 0U }, /* event: MANUFACTURING_PROCESS */
   { 73U, 0U }, /* event: SNSR_ROTPOS_STRANGLOSS */
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

#if (DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE != 0U)
/* RTE-Lookup table for GetFaultDetectionCounter */
CONST(Dem_EventIdType, DEM_CONST)
   Dem_RteLookupTableGetFaultDetectionCounter[DEM_RTE_LOOKUP_TABLE_GET_FDC_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
