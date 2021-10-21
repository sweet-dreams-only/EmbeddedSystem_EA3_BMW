
#ifndef DEM_API_CFG_SPECIFIC_H
/** \brief preprocessor exclusion definition */
#define DEM_API_CFG_SPECIFIC_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the all public configuration declarations for the
 ** AUTOSAR module Dem that are target independent, which are
 ** variant specific.
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

/*==================[includes]==============================================*/

#include <Dem_Api_Cfg.h>                               /* Base class header */

/*==================[macros]================================================*/


/*------------------[DM Debug Filter configuration]-------------------------*/

/** \brief Number of events being part of the network group
 **
 ** These are the events belonging to the DTC-group "network com DTCs". */
#define DEM_NUMBER_OF_LOCKABLE_EVENTS  51U

/** \brief Number of events with "response on event"
 **
 ** These are the events having "trigger on error entry" activated in the
 ** configuration. */
#define DEM_NUMBER_OF_ROE_EVENTS       87U


/*------------------[Memory size configuration]-----------------------------*/

/* 2 - Event DM_Queue_FULL: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event DM_Queue_DELETED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event NVM_E_REQ_FAILED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event NVM_E_INTEGRITY_FAILED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event VSM_EVENT_OPMODE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event DM_TEST_APPL: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event DM_TEST_COM: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event DM_EVENT_ZEITBOTSCHAFTTIMEOUT: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CODING_EVENT_NOT_CODED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CODING_EVENT_TRANSACTION_FAILED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CODING_EVENT_SIGNATURE_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CODING_EVENT_WRONG_VEHICLE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CODING_EVENT_INVALID_DATA: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event ECUM_E_ALL_RUN_REQUESTS_KILLED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event COMM_E_NET_START_IND_CHANNEL_0: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event WDGM_E_ALIVE_SUPERVISION: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event FR_E_ACCESS: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event FRTRCV_E_FR_NO_TRCV_CONTROL: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event MTRPOS_FAILED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event INVERTER_FAILED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event TRQSNSR_FAILED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event BATTHIGH: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ROM_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event FAHRGESTELLNUMMER_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event FAHRGESTELLNUMMER_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event V_VEH_VEH_2_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CRC_V_VEH_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ALIV_V_VEH_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event V_VEH_VEH_2_MULTSIG_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event V_VEH_VEH_2_MULTSIG_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event KILOMETERSTAND_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event QU_V_VEH_COG_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event IGNITION_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event LOW_VOLT_LARGE_ASST_RED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event THERMAL_LIMIT: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event FR_PHYS_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event FR_COMM_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event OFFS_QUAD_EPS_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ALIV_OFFS_QUAD_EPS_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CRC_OFFS_QUAD_EPS_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event OFFS_QUAD_EPS_MULTSIG_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event OFFS_QUAD_EPS_MULTSIG_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event TAR_QTA_STRMOM_DV_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event TAR_STMOM_DV_ACT_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ALIV_TAR_QTA_STMOM_DV_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ALIV_TAR_STMOM_DV_ACT_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CRC_TAR_QTA_STMOM_DV_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CRC_TAR_STMOM_DV_ACT_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event SU_CLE_DRDY_DXP_SPEC_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event SU_CLU_STMOM_SFE_DXP_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event SU_CLU_STMOM_SFE_DXP_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event STEA_OFFS_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event STEA_OFFS_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event STEA_OFFS_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event SWA_SENSOR_LOSS_MULTITURN: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event PWRPK_FAILURE_REDPERF: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event PWRSPLY_GLOBAL_SURGE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event SWA_NOT_STRAIGHT_LINE_LEARNED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event MOTOR_SENSOR_GENERAL: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event PWRSPLY_GLOBAL_UNDVOLT: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event HIGH_TEMP_ASST_RED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event TRNSCTR_NVR_ASLEEP: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event IPDUM_E_TRANSMIT_FAILED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CODING_TUNING_ID_NOT_FOUND: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event DAMPING_FIREWALL_TOUCHED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event ASSIST_FIREWALL_TOUCHED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event RETURN_FIREWALL_TOUCHED: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event DAMPING_FIREWALL_FLTMD: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event ASSIST_FIREWALL_FLTMD: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event VBIC_FAULT_MODE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event PARK_ASSIST_DEACTIVATION: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event MANUFACTURING_PROCESS: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 2 - Event SNSR_ROTPOS_STRANGLOSS: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event STEERING_ANGLE_SNSR_HW_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event STEERING_ANGLE_SNSR_HW_FAILURE_INT: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event NVM_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event RAM_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event GENERAL_MCU_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event SOFTWARE_RUNTIME_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event WATCHDOG_EVENT: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event EEPROM_TO_FEE_COPY_FAILURE: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event SOFTWARE_RUNTIME_FAILURE_NONOBD: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event GENERAL_MCU_FAILURE_NONOBD: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event GLOBAL_PWR_MGMT_REDUCEDASSIST: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event VYAW_VEH_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CRC_VYAW_VEH_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ALIV_VYAW_VEH_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event VYAW_VEH_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CRC_CON_VEH_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ACLNX_ACLNY_MASSCNTR_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CRC_ACLNY_COG_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ACLNX_ACLNY_MASSCNTR_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ALIV_CON_VEH_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ENERG_DGR_DRDY_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CON_VEH_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event MAX_I_SPEC_EPS_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CON_VEH_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event MAX_I_SPEC_EPS_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CON_VEH_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ST_CENG_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ST_CENG_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CTR_VIB_STW_MISSING: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ST_CENG_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event ALIV_ST_CENG_ERROR: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CTR_WARN_ILVL_VIB_EPS_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CTR_WARN_PTRN_VIB_EPS_INVALID: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */
/* 1 - Event CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC: DemExtendedDataClass1 + 2 * DemFreezeFrameClass1 = 45 */

/* entry data sizes (ED + Num * FF) of prm memory:  45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 */
/* entry data sizes (ED + Num * FF) of sec memory:  45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 45 */
/* entry data sizes (ED + Num * FF) of mir memory:  */


#if (defined DEM_SIZE_GATE_ENTRY_DATA_PRIMARY)
#error DEM_SIZE_GATE_ENTRY_DATA_PRIMARY already defined
#endif
/** \brief Size of gate entry data for primary memory */
#define DEM_SIZE_GATE_ENTRY_DATA_PRIMARY    45U

#if (defined DEM_SIZE_GATE_ENTRY_DATA_SECONDARY)
#error DEM_SIZE_GATE_ENTRY_DATA_SECONDARY already defined
#endif
/** \brief Size of gate entry data for secondary memory */
#define DEM_SIZE_GATE_ENTRY_DATA_SECONDARY  45U

#if (defined DEM_SIZE_GATE_ENTRY_DATA_MIRROR)
#error DEM_SIZE_GATE_ENTRY_DATA_MIRROR already defined
#endif
/** \brief Size of gate entry data for mirror memory */
#define DEM_SIZE_GATE_ENTRY_DATA_MIRROR     1U


#if (defined DEM_ZERO_END)
#error DEM_ZERO_END already defined
#endif
/** \brief Zero value to be added to each size, whose involved patterns could
 ** be none */
#define DEM_ZERO_END                  0U

#if (defined DEM_SIZE_ENTRY_DATA_PRIMARY)
#error DEM_SIZE_ENTRY_DATA_PRIMARY already defined
#endif
/** Size of dynamic primary entry data
 **
 ** The N (primary memory entry number) maximal sizes are added.
 **
 ** \note The DEM_ZERO_END is not necessary here, because primary event memory
 **       is always > 0.
 **/
#define DEM_SIZE_ENTRY_DATA_PRIMARY   \
   (45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U)

#if (defined DEM_SIZE_ENTRY_DATA_SECONDARY)
#error DEM_SIZE_ENTRY_DATA_SECONDARY already defined
#endif
/** Size of dynamic secondary entry data
 **
 ** The N (secondary memory entry number) maximal sizes are added.
 **/
#define DEM_SIZE_ENTRY_DATA_SECONDARY \
   (45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 45U + 0U + 0U + 0U + 0U + 0U + DEM_ZERO_END)

#if (defined DEM_SIZE_ENTRY_DATA_MIRROR)
#error DEM_SIZE_ENTRY_DATA_MIRROR already defined
#endif
/** Size of dynamic mirror entry data
 **
 ** The N (mirror memory entry number) maximal sizes are added.
 **/
#define DEM_SIZE_ENTRY_DATA_MIRROR    \
   (DEM_ZERO_END)


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef DEM_API_CFG_SPECIFIC_H */
/*==================[end of file]===========================================*/
