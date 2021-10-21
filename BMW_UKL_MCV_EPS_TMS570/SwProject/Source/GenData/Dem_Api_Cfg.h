

#ifndef DEM_API_CFG_H
/** \brief preprocessor exclusion definition */
#define DEM_API_CFG_H

/** \file
 ** \brief AUTOSAR Dem Diagnostic Event Manager
 **
 ** This file contains the all public configuration declarations for the
 ** AUTOSAR module Dem that are target independent.
 **
 ** \project AUTOSAR Standard Core
 ** \author Georg Drenkhahn
 ** \author Marko Schneider
 ** \author 3SOFT GmbH, 91058 Erlangen, Germany
 **
 ** $Id: Dem_Api_Cfg.h 1541 2008-12-18 15:55:25Z masc2461 $
 ** Release: 2008.a.BMW_Dem_V3.1.0_MPC_MPC5567
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

/*==================[includes]==============================================*/

/*==================[macros]================================================*/
/*------------------[General]-----------------------------------------------*/

#if (defined DEM_TYPE_OF_ORIGIN_SUPPORTED)
#error DEM_TYPE_OF_ORIGIN_SUPPORTED already defined
#endif
/** \brief Supported origin types
 **
 ** This macro is only exported and not used internally.
 ** It is derived from ::DEM_MAX_NUMBER_EVENT_ENTRY_PRM,
 ** ::DEM_MAX_NUMBER_EVENT_ENTRY_SEC and ::DEM_MAX_NUMBER_EVENT_ENTRY_MIR.
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_TYPE_OF_ORIGIN_SUPPORTED 3U

#if (defined DEM_TYPE_OF_DTC_SUPPORTED)
#error DEM_TYPE_OF_DTC_SUPPORTED already defined
#endif
/** \brief Supported DTC types
 **
 ** This macro is only exported and not used internally.
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_TYPE_OF_DTC_SUPPORTED    2U


/*------------------[Configuration dependent switches]-----------------------*/

/* macro to en-/disable enable condition */
#if (defined DEM_USE_ENABLE_CONDITION)
#error DEM_USE_ENABLE_CONDITION already defined
#endif
#define DEM_USE_ENABLE_CONDITION    STD_OFF

/* macro to en-/disable indicator */
#if (defined DEM_USE_INDICATOR)
#error DEM_USE_INDICATOR already defined
#endif
#define DEM_USE_INDICATOR     STD_ON

/*------------------[Freeze frame configuration]----------------------------*/

#if (defined DEM_MAX_NUMBER_PRESTORED_FF)
#error DEM_MAX_NUMBER_PRESTORED_FF already defined
#endif
/** \brief Maximum number of available prestored freeze frames
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_MAX_NUMBER_PRESTORED_FF 0U


/*------------------[Memory size configuration]-----------------------------*/

#if (defined DEM_BSW_ERROR_BUFFER_SIZE)
#error DEM_BSW_ERROR_BUFFER_SIZE already defined
#endif
/** \brief Maximal number of error-queue entries
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_BSW_ERROR_BUFFER_SIZE 25U


/*------------------[Events configuration]----------------------------------*/

#if (defined DEM_MAX_NUMBER_EVENT_ENTRY_PRM)
#error DEM_MAX_NUMBER_EVENT_ENTRY_PRM already defined
#endif
/** \brief Maximum number of events which can be stored in the primary memory
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_MAX_NUMBER_EVENT_ENTRY_PRM 30U

#if (defined DEM_MAX_NUMBER_EVENT_ENTRY_SEC)
#error DEM_MAX_NUMBER_EVENT_ENTRY_SEC already defined
#endif
/** \brief Maximum number of events which can be stored in the secondary
 ** memory
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_MAX_NUMBER_EVENT_ENTRY_SEC 24U

#if (defined DEM_MAX_NUMBER_EVENT_ENTRY_MIR)
#error DEM_MAX_NUMBER_EVENT_ENTRY_MIR already defined
#endif
/** \brief Maximum number of events which can be stored in the mirror memory
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_MAX_NUMBER_EVENT_ENTRY_MIR 0U


/* Symbolic names of configured event IDs */

#if (defined DM_Queue_FULL)
#error DM_Queue_FULL already defined
#endif
/** \brief Symbolic name of event DM_Queue_FULL */
#define DM_Queue_FULL                    1U

#if (defined DM_Queue_DELETED)
#error DM_Queue_DELETED already defined
#endif
/** \brief Symbolic name of event DM_Queue_DELETED */
#define DM_Queue_DELETED                 2U

#if (defined NVM_E_REQ_FAILED)
#error NVM_E_REQ_FAILED already defined
#endif
/** \brief Symbolic name of event NVM_E_REQ_FAILED */
#define NVM_E_REQ_FAILED                 3U

#if (defined NVM_E_INTEGRITY_FAILED)
#error NVM_E_INTEGRITY_FAILED already defined
#endif
/** \brief Symbolic name of event NVM_E_INTEGRITY_FAILED */
#define NVM_E_INTEGRITY_FAILED           4U

#if (defined VSM_EVENT_OPMODE)
#error VSM_EVENT_OPMODE already defined
#endif
/** \brief Symbolic name of event VSM_EVENT_OPMODE */
#define VSM_EVENT_OPMODE                 5U

#if (defined DM_TEST_APPL)
#error DM_TEST_APPL already defined
#endif
/** \brief Symbolic name of event DM_TEST_APPL */
#define DM_TEST_APPL                     6U

#if (defined DM_TEST_COM)
#error DM_TEST_COM already defined
#endif
/** \brief Symbolic name of event DM_TEST_COM */
#define DM_TEST_COM                      7U

#if (defined DM_EVENT_ZEITBOTSCHAFTTIMEOUT)
#error DM_EVENT_ZEITBOTSCHAFTTIMEOUT already defined
#endif
/** \brief Symbolic name of event DM_EVENT_ZEITBOTSCHAFTTIMEOUT */
#define DM_EVENT_ZEITBOTSCHAFTTIMEOUT    8U

#if (defined CODING_EVENT_NOT_CODED)
#error CODING_EVENT_NOT_CODED already defined
#endif
/** \brief Symbolic name of event CODING_EVENT_NOT_CODED */
#define CODING_EVENT_NOT_CODED           9U

#if (defined CODING_EVENT_TRANSACTION_FAILED)
#error CODING_EVENT_TRANSACTION_FAILED already defined
#endif
/** \brief Symbolic name of event CODING_EVENT_TRANSACTION_FAILED */
#define CODING_EVENT_TRANSACTION_FAILED  10U

#if (defined CODING_EVENT_SIGNATURE_ERROR)
#error CODING_EVENT_SIGNATURE_ERROR already defined
#endif
/** \brief Symbolic name of event CODING_EVENT_SIGNATURE_ERROR */
#define CODING_EVENT_SIGNATURE_ERROR     11U

#if (defined CODING_EVENT_WRONG_VEHICLE)
#error CODING_EVENT_WRONG_VEHICLE already defined
#endif
/** \brief Symbolic name of event CODING_EVENT_WRONG_VEHICLE */
#define CODING_EVENT_WRONG_VEHICLE       12U

#if (defined CODING_EVENT_INVALID_DATA)
#error CODING_EVENT_INVALID_DATA already defined
#endif
/** \brief Symbolic name of event CODING_EVENT_INVALID_DATA */
#define CODING_EVENT_INVALID_DATA        13U

#if (defined ECUM_E_ALL_RUN_REQUESTS_KILLED)
#error ECUM_E_ALL_RUN_REQUESTS_KILLED already defined
#endif
/** \brief Symbolic name of event ECUM_E_ALL_RUN_REQUESTS_KILLED */
#define ECUM_E_ALL_RUN_REQUESTS_KILLED   14U

#if (defined COMM_E_NET_START_IND_CHANNEL_0)
#error COMM_E_NET_START_IND_CHANNEL_0 already defined
#endif
/** \brief Symbolic name of event COMM_E_NET_START_IND_CHANNEL_0 */
#define COMM_E_NET_START_IND_CHANNEL_0   15U

#if (defined WDGM_E_ALIVE_SUPERVISION)
#error WDGM_E_ALIVE_SUPERVISION already defined
#endif
/** \brief Symbolic name of event WDGM_E_ALIVE_SUPERVISION */
#define WDGM_E_ALIVE_SUPERVISION         16U

#if (defined FR_E_ACCESS)
#error FR_E_ACCESS already defined
#endif
/** \brief Symbolic name of event FR_E_ACCESS */
#define FR_E_ACCESS                      17U

#if (defined FRTRCV_E_FR_NO_TRCV_CONTROL)
#error FRTRCV_E_FR_NO_TRCV_CONTROL already defined
#endif
/** \brief Symbolic name of event FRTRCV_E_FR_NO_TRCV_CONTROL */
#define FRTRCV_E_FR_NO_TRCV_CONTROL      18U

#if (defined MTRPOS_FAILED)
#error MTRPOS_FAILED already defined
#endif
/** \brief Symbolic name of event MTRPOS_FAILED */
#define MTRPOS_FAILED                    19U

#if (defined INVERTER_FAILED)
#error INVERTER_FAILED already defined
#endif
/** \brief Symbolic name of event INVERTER_FAILED */
#define INVERTER_FAILED                  20U

#if (defined TRQSNSR_FAILED)
#error TRQSNSR_FAILED already defined
#endif
/** \brief Symbolic name of event TRQSNSR_FAILED */
#define TRQSNSR_FAILED                   21U

#if (defined BATTHIGH)
#error BATTHIGH already defined
#endif
/** \brief Symbolic name of event BATTHIGH */
#define BATTHIGH                         22U

#if (defined ROM_FAILURE)
#error ROM_FAILURE already defined
#endif
/** \brief Symbolic name of event ROM_FAILURE */
#define ROM_FAILURE                      23U

#if (defined FAHRGESTELLNUMMER_INVALID)
#error FAHRGESTELLNUMMER_INVALID already defined
#endif
/** \brief Symbolic name of event FAHRGESTELLNUMMER_INVALID */
#define FAHRGESTELLNUMMER_INVALID        24U

#if (defined FAHRGESTELLNUMMER_MISSING)
#error FAHRGESTELLNUMMER_MISSING already defined
#endif
/** \brief Symbolic name of event FAHRGESTELLNUMMER_MISSING */
#define FAHRGESTELLNUMMER_MISSING        25U

#if (defined V_VEH_VEH_2_MISSING)
#error V_VEH_VEH_2_MISSING already defined
#endif
/** \brief Symbolic name of event V_VEH_VEH_2_MISSING */
#define V_VEH_VEH_2_MISSING              26U

#if (defined CRC_V_VEH_ERROR)
#error CRC_V_VEH_ERROR already defined
#endif
/** \brief Symbolic name of event CRC_V_VEH_ERROR */
#define CRC_V_VEH_ERROR                  27U

#if (defined ALIV_V_VEH_ERROR)
#error ALIV_V_VEH_ERROR already defined
#endif
/** \brief Symbolic name of event ALIV_V_VEH_ERROR */
#define ALIV_V_VEH_ERROR                 28U

#if (defined V_VEH_VEH_2_MULTSIG_INVALID)
#error V_VEH_VEH_2_MULTSIG_INVALID already defined
#endif
/** \brief Symbolic name of event V_VEH_VEH_2_MULTSIG_INVALID */
#define V_VEH_VEH_2_MULTSIG_INVALID      29U

#if (defined V_VEH_VEH_2_MULTSIG_ERROR)
#error V_VEH_VEH_2_MULTSIG_ERROR already defined
#endif
/** \brief Symbolic name of event V_VEH_VEH_2_MULTSIG_ERROR */
#define V_VEH_VEH_2_MULTSIG_ERROR        30U

#if (defined KILOMETERSTAND_MISSING)
#error KILOMETERSTAND_MISSING already defined
#endif
/** \brief Symbolic name of event KILOMETERSTAND_MISSING */
#define KILOMETERSTAND_MISSING           31U

#if (defined QU_V_VEH_COG_ERROR)
#error QU_V_VEH_COG_ERROR already defined
#endif
/** \brief Symbolic name of event QU_V_VEH_COG_ERROR */
#define QU_V_VEH_COG_ERROR               32U

#if (defined IGNITION_FAILURE)
#error IGNITION_FAILURE already defined
#endif
/** \brief Symbolic name of event IGNITION_FAILURE */
#define IGNITION_FAILURE                 33U

#if (defined LOW_VOLT_LARGE_ASST_RED)
#error LOW_VOLT_LARGE_ASST_RED already defined
#endif
/** \brief Symbolic name of event LOW_VOLT_LARGE_ASST_RED */
#define LOW_VOLT_LARGE_ASST_RED          34U

#if (defined THERMAL_LIMIT)
#error THERMAL_LIMIT already defined
#endif
/** \brief Symbolic name of event THERMAL_LIMIT */
#define THERMAL_LIMIT                    35U

#if (defined FR_PHYS_FAILURE)
#error FR_PHYS_FAILURE already defined
#endif
/** \brief Symbolic name of event FR_PHYS_FAILURE */
#define FR_PHYS_FAILURE                  36U

#if (defined FR_COMM_FAILURE)
#error FR_COMM_FAILURE already defined
#endif
/** \brief Symbolic name of event FR_COMM_FAILURE */
#define FR_COMM_FAILURE                  37U

#if (defined OFFS_QUAD_EPS_MISSING)
#error OFFS_QUAD_EPS_MISSING already defined
#endif
/** \brief Symbolic name of event OFFS_QUAD_EPS_MISSING */
#define OFFS_QUAD_EPS_MISSING            38U

#if (defined ALIV_OFFS_QUAD_EPS_ERROR)
#error ALIV_OFFS_QUAD_EPS_ERROR already defined
#endif
/** \brief Symbolic name of event ALIV_OFFS_QUAD_EPS_ERROR */
#define ALIV_OFFS_QUAD_EPS_ERROR         39U

#if (defined CRC_OFFS_QUAD_EPS_ERROR)
#error CRC_OFFS_QUAD_EPS_ERROR already defined
#endif
/** \brief Symbolic name of event CRC_OFFS_QUAD_EPS_ERROR */
#define CRC_OFFS_QUAD_EPS_ERROR          40U

#if (defined OFFS_QUAD_EPS_MULTSIG_INVALID)
#error OFFS_QUAD_EPS_MULTSIG_INVALID already defined
#endif
/** \brief Symbolic name of event OFFS_QUAD_EPS_MULTSIG_INVALID */
#define OFFS_QUAD_EPS_MULTSIG_INVALID    41U

#if (defined OFFS_QUAD_EPS_MULTSIG_ERROR)
#error OFFS_QUAD_EPS_MULTSIG_ERROR already defined
#endif
/** \brief Symbolic name of event OFFS_QUAD_EPS_MULTSIG_ERROR */
#define OFFS_QUAD_EPS_MULTSIG_ERROR      42U

#if (defined TAR_QTA_STRMOM_DV_MISSING)
#error TAR_QTA_STRMOM_DV_MISSING already defined
#endif
/** \brief Symbolic name of event TAR_QTA_STRMOM_DV_MISSING */
#define TAR_QTA_STRMOM_DV_MISSING        43U

#if (defined TAR_STMOM_DV_ACT_MISSING)
#error TAR_STMOM_DV_ACT_MISSING already defined
#endif
/** \brief Symbolic name of event TAR_STMOM_DV_ACT_MISSING */
#define TAR_STMOM_DV_ACT_MISSING         44U

#if (defined ALIV_TAR_QTA_STMOM_DV_ERROR)
#error ALIV_TAR_QTA_STMOM_DV_ERROR already defined
#endif
/** \brief Symbolic name of event ALIV_TAR_QTA_STMOM_DV_ERROR */
#define ALIV_TAR_QTA_STMOM_DV_ERROR      45U

#if (defined ALIV_TAR_STMOM_DV_ACT_ERROR)
#error ALIV_TAR_STMOM_DV_ACT_ERROR already defined
#endif
/** \brief Symbolic name of event ALIV_TAR_STMOM_DV_ACT_ERROR */
#define ALIV_TAR_STMOM_DV_ACT_ERROR      46U

#if (defined CRC_TAR_QTA_STMOM_DV_ERROR)
#error CRC_TAR_QTA_STMOM_DV_ERROR already defined
#endif
/** \brief Symbolic name of event CRC_TAR_QTA_STMOM_DV_ERROR */
#define CRC_TAR_QTA_STMOM_DV_ERROR       47U

#if (defined CRC_TAR_STMOM_DV_ACT_ERROR)
#error CRC_TAR_STMOM_DV_ACT_ERROR already defined
#endif
/** \brief Symbolic name of event CRC_TAR_STMOM_DV_ACT_ERROR */
#define CRC_TAR_STMOM_DV_ACT_ERROR       48U

#if (defined SU_CLE_DRDY_DXP_SPEC_MISSING)
#error SU_CLE_DRDY_DXP_SPEC_MISSING already defined
#endif
/** \brief Symbolic name of event SU_CLE_DRDY_DXP_SPEC_MISSING */
#define SU_CLE_DRDY_DXP_SPEC_MISSING     49U

#if (defined SU_CLU_STMOM_SFE_DXP_INVALID)
#error SU_CLU_STMOM_SFE_DXP_INVALID already defined
#endif
/** \brief Symbolic name of event SU_CLU_STMOM_SFE_DXP_INVALID */
#define SU_CLU_STMOM_SFE_DXP_INVALID     50U

#if (defined SU_CLU_STMOM_SFE_DXP_ERROR)
#error SU_CLU_STMOM_SFE_DXP_ERROR already defined
#endif
/** \brief Symbolic name of event SU_CLU_STMOM_SFE_DXP_ERROR */
#define SU_CLU_STMOM_SFE_DXP_ERROR       51U

#if (defined STEA_OFFS_MISSING)
#error STEA_OFFS_MISSING already defined
#endif
/** \brief Symbolic name of event STEA_OFFS_MISSING */
#define STEA_OFFS_MISSING                52U

#if (defined STEA_OFFS_INVALID)
#error STEA_OFFS_INVALID already defined
#endif
/** \brief Symbolic name of event STEA_OFFS_INVALID */
#define STEA_OFFS_INVALID                53U

#if (defined STEA_OFFS_ERROR)
#error STEA_OFFS_ERROR already defined
#endif
/** \brief Symbolic name of event STEA_OFFS_ERROR */
#define STEA_OFFS_ERROR                  54U

#if (defined SWA_SENSOR_LOSS_MULTITURN)
#error SWA_SENSOR_LOSS_MULTITURN already defined
#endif
/** \brief Symbolic name of event SWA_SENSOR_LOSS_MULTITURN */
#define SWA_SENSOR_LOSS_MULTITURN        55U

#if (defined PWRPK_FAILURE_REDPERF)
#error PWRPK_FAILURE_REDPERF already defined
#endif
/** \brief Symbolic name of event PWRPK_FAILURE_REDPERF */
#define PWRPK_FAILURE_REDPERF            56U

#if (defined PWRSPLY_GLOBAL_SURGE)
#error PWRSPLY_GLOBAL_SURGE already defined
#endif
/** \brief Symbolic name of event PWRSPLY_GLOBAL_SURGE */
#define PWRSPLY_GLOBAL_SURGE             57U

#if (defined SWA_NOT_STRAIGHT_LINE_LEARNED)
#error SWA_NOT_STRAIGHT_LINE_LEARNED already defined
#endif
/** \brief Symbolic name of event SWA_NOT_STRAIGHT_LINE_LEARNED */
#define SWA_NOT_STRAIGHT_LINE_LEARNED    58U

#if (defined MOTOR_SENSOR_GENERAL)
#error MOTOR_SENSOR_GENERAL already defined
#endif
/** \brief Symbolic name of event MOTOR_SENSOR_GENERAL */
#define MOTOR_SENSOR_GENERAL             59U

#if (defined PWRSPLY_GLOBAL_UNDVOLT)
#error PWRSPLY_GLOBAL_UNDVOLT already defined
#endif
/** \brief Symbolic name of event PWRSPLY_GLOBAL_UNDVOLT */
#define PWRSPLY_GLOBAL_UNDVOLT           60U

#if (defined HIGH_TEMP_ASST_RED)
#error HIGH_TEMP_ASST_RED already defined
#endif
/** \brief Symbolic name of event HIGH_TEMP_ASST_RED */
#define HIGH_TEMP_ASST_RED               61U

#if (defined TRNSCTR_NVR_ASLEEP)
#error TRNSCTR_NVR_ASLEEP already defined
#endif
/** \brief Symbolic name of event TRNSCTR_NVR_ASLEEP */
#define TRNSCTR_NVR_ASLEEP               62U

#if (defined IPDUM_E_TRANSMIT_FAILED)
#error IPDUM_E_TRANSMIT_FAILED already defined
#endif
/** \brief Symbolic name of event IPDUM_E_TRANSMIT_FAILED */
#define IPDUM_E_TRANSMIT_FAILED          63U

#if (defined CODING_TUNING_ID_NOT_FOUND)
#error CODING_TUNING_ID_NOT_FOUND already defined
#endif
/** \brief Symbolic name of event CODING_TUNING_ID_NOT_FOUND */
#define CODING_TUNING_ID_NOT_FOUND       64U

#if (defined DAMPING_FIREWALL_TOUCHED)
#error DAMPING_FIREWALL_TOUCHED already defined
#endif
/** \brief Symbolic name of event DAMPING_FIREWALL_TOUCHED */
#define DAMPING_FIREWALL_TOUCHED         65U

#if (defined ASSIST_FIREWALL_TOUCHED)
#error ASSIST_FIREWALL_TOUCHED already defined
#endif
/** \brief Symbolic name of event ASSIST_FIREWALL_TOUCHED */
#define ASSIST_FIREWALL_TOUCHED          66U

#if (defined RETURN_FIREWALL_TOUCHED)
#error RETURN_FIREWALL_TOUCHED already defined
#endif
/** \brief Symbolic name of event RETURN_FIREWALL_TOUCHED */
#define RETURN_FIREWALL_TOUCHED          67U

#if (defined DAMPING_FIREWALL_FLTMD)
#error DAMPING_FIREWALL_FLTMD already defined
#endif
/** \brief Symbolic name of event DAMPING_FIREWALL_FLTMD */
#define DAMPING_FIREWALL_FLTMD           68U

#if (defined ASSIST_FIREWALL_FLTMD)
#error ASSIST_FIREWALL_FLTMD already defined
#endif
/** \brief Symbolic name of event ASSIST_FIREWALL_FLTMD */
#define ASSIST_FIREWALL_FLTMD            69U

#if (defined VBIC_FAULT_MODE)
#error VBIC_FAULT_MODE already defined
#endif
/** \brief Symbolic name of event VBIC_FAULT_MODE */
#define VBIC_FAULT_MODE                  70U

#if (defined PARK_ASSIST_DEACTIVATION)
#error PARK_ASSIST_DEACTIVATION already defined
#endif
/** \brief Symbolic name of event PARK_ASSIST_DEACTIVATION */
#define PARK_ASSIST_DEACTIVATION         71U

#if (defined MANUFACTURING_PROCESS)
#error MANUFACTURING_PROCESS already defined
#endif
/** \brief Symbolic name of event MANUFACTURING_PROCESS */
#define MANUFACTURING_PROCESS            72U

#if (defined SNSR_ROTPOS_STRANGLOSS)
#error SNSR_ROTPOS_STRANGLOSS already defined
#endif
/** \brief Symbolic name of event SNSR_ROTPOS_STRANGLOSS */
#define SNSR_ROTPOS_STRANGLOSS           73U

#if (defined STEERING_ANGLE_SNSR_HW_FAILURE)
#error STEERING_ANGLE_SNSR_HW_FAILURE already defined
#endif
/** \brief Symbolic name of event STEERING_ANGLE_SNSR_HW_FAILURE */
#define STEERING_ANGLE_SNSR_HW_FAILURE   74U

#if (defined STEERING_ANGLE_SNSR_HW_FAILURE_INT)
#error STEERING_ANGLE_SNSR_HW_FAILURE_INT already defined
#endif
/** \brief Symbolic name of event STEERING_ANGLE_SNSR_HW_FAILURE_INT */
#define STEERING_ANGLE_SNSR_HW_FAILURE_INT 75U

#if (defined NVM_FAILURE)
#error NVM_FAILURE already defined
#endif
/** \brief Symbolic name of event NVM_FAILURE */
#define NVM_FAILURE                      76U

#if (defined RAM_FAILURE)
#error RAM_FAILURE already defined
#endif
/** \brief Symbolic name of event RAM_FAILURE */
#define RAM_FAILURE                      77U

#if (defined GENERAL_MCU_FAILURE)
#error GENERAL_MCU_FAILURE already defined
#endif
/** \brief Symbolic name of event GENERAL_MCU_FAILURE */
#define GENERAL_MCU_FAILURE              78U

#if (defined SOFTWARE_RUNTIME_FAILURE)
#error SOFTWARE_RUNTIME_FAILURE already defined
#endif
/** \brief Symbolic name of event SOFTWARE_RUNTIME_FAILURE */
#define SOFTWARE_RUNTIME_FAILURE         79U

#if (defined WATCHDOG_EVENT)
#error WATCHDOG_EVENT already defined
#endif
/** \brief Symbolic name of event WATCHDOG_EVENT */
#define WATCHDOG_EVENT                   80U

#if (defined EEPROM_TO_FEE_COPY_FAILURE)
#error EEPROM_TO_FEE_COPY_FAILURE already defined
#endif
/** \brief Symbolic name of event EEPROM_TO_FEE_COPY_FAILURE */
#define EEPROM_TO_FEE_COPY_FAILURE       81U

#if (defined SOFTWARE_RUNTIME_FAILURE_NONOBD)
#error SOFTWARE_RUNTIME_FAILURE_NONOBD already defined
#endif
/** \brief Symbolic name of event SOFTWARE_RUNTIME_FAILURE_NONOBD */
#define SOFTWARE_RUNTIME_FAILURE_NONOBD  82U

#if (defined GENERAL_MCU_FAILURE_NONOBD)
#error GENERAL_MCU_FAILURE_NONOBD already defined
#endif
/** \brief Symbolic name of event GENERAL_MCU_FAILURE_NONOBD */
#define GENERAL_MCU_FAILURE_NONOBD       83U

#if (defined GLOBAL_PWR_MGMT_REDUCEDASSIST)
#error GLOBAL_PWR_MGMT_REDUCEDASSIST already defined
#endif
/** \brief Symbolic name of event GLOBAL_PWR_MGMT_REDUCEDASSIST */
#define GLOBAL_PWR_MGMT_REDUCEDASSIST    84U

#if (defined VYAW_VEH_MISSING)
#error VYAW_VEH_MISSING already defined
#endif
/** \brief Symbolic name of event VYAW_VEH_MISSING */
#define VYAW_VEH_MISSING                 85U

#if (defined CRC_VYAW_VEH_ERROR)
#error CRC_VYAW_VEH_ERROR already defined
#endif
/** \brief Symbolic name of event CRC_VYAW_VEH_ERROR */
#define CRC_VYAW_VEH_ERROR               86U

#if (defined ALIV_VYAW_VEH_ERROR)
#error ALIV_VYAW_VEH_ERROR already defined
#endif
/** \brief Symbolic name of event ALIV_VYAW_VEH_ERROR */
#define ALIV_VYAW_VEH_ERROR              87U

#if (defined VYAW_VEH_INVALID)
#error VYAW_VEH_INVALID already defined
#endif
/** \brief Symbolic name of event VYAW_VEH_INVALID */
#define VYAW_VEH_INVALID                 88U

#if (defined CRC_CON_VEH_ERROR)
#error CRC_CON_VEH_ERROR already defined
#endif
/** \brief Symbolic name of event CRC_CON_VEH_ERROR */
#define CRC_CON_VEH_ERROR                89U

#if (defined ACLNX_ACLNY_MASSCNTR_MISSING)
#error ACLNX_ACLNY_MASSCNTR_MISSING already defined
#endif
/** \brief Symbolic name of event ACLNX_ACLNY_MASSCNTR_MISSING */
#define ACLNX_ACLNY_MASSCNTR_MISSING     90U

#if (defined CRC_ACLNY_COG_ERROR)
#error CRC_ACLNY_COG_ERROR already defined
#endif
/** \brief Symbolic name of event CRC_ACLNY_COG_ERROR */
#define CRC_ACLNY_COG_ERROR              91U

#if (defined ACLNX_ACLNY_MASSCNTR_INVALID)
#error ACLNX_ACLNY_MASSCNTR_INVALID already defined
#endif
/** \brief Symbolic name of event ACLNX_ACLNY_MASSCNTR_INVALID */
#define ACLNX_ACLNY_MASSCNTR_INVALID     92U

#if (defined ALIV_CON_VEH_ERROR)
#error ALIV_CON_VEH_ERROR already defined
#endif
/** \brief Symbolic name of event ALIV_CON_VEH_ERROR */
#define ALIV_CON_VEH_ERROR               93U

#if (defined ENERG_DGR_DRDY_MISSING)
#error ENERG_DGR_DRDY_MISSING already defined
#endif
/** \brief Symbolic name of event ENERG_DGR_DRDY_MISSING */
#define ENERG_DGR_DRDY_MISSING           94U

#if (defined CON_VEH_MISSING)
#error CON_VEH_MISSING already defined
#endif
/** \brief Symbolic name of event CON_VEH_MISSING */
#define CON_VEH_MISSING                  95U

#if (defined MAX_I_SPEC_EPS_INVALID)
#error MAX_I_SPEC_EPS_INVALID already defined
#endif
/** \brief Symbolic name of event MAX_I_SPEC_EPS_INVALID */
#define MAX_I_SPEC_EPS_INVALID           96U

#if (defined CON_VEH_INVALID)
#error CON_VEH_INVALID already defined
#endif
/** \brief Symbolic name of event CON_VEH_INVALID */
#define CON_VEH_INVALID                  97U

#if (defined MAX_I_SPEC_EPS_ERROR)
#error MAX_I_SPEC_EPS_ERROR already defined
#endif
/** \brief Symbolic name of event MAX_I_SPEC_EPS_ERROR */
#define MAX_I_SPEC_EPS_ERROR             98U

#if (defined CON_VEH_ERROR)
#error CON_VEH_ERROR already defined
#endif
/** \brief Symbolic name of event CON_VEH_ERROR */
#define CON_VEH_ERROR                    99U

#if (defined ST_CENG_INVALID)
#error ST_CENG_INVALID already defined
#endif
/** \brief Symbolic name of event ST_CENG_INVALID */
#define ST_CENG_INVALID                  100U

#if (defined ST_CENG_MISSING)
#error ST_CENG_MISSING already defined
#endif
/** \brief Symbolic name of event ST_CENG_MISSING */
#define ST_CENG_MISSING                  101U

#if (defined CTR_VIB_STW_MISSING)
#error CTR_VIB_STW_MISSING already defined
#endif
/** \brief Symbolic name of event CTR_VIB_STW_MISSING */
#define CTR_VIB_STW_MISSING              102U

#if (defined ST_CENG_ERROR)
#error ST_CENG_ERROR already defined
#endif
/** \brief Symbolic name of event ST_CENG_ERROR */
#define ST_CENG_ERROR                    103U

#if (defined ALIV_ST_CENG_ERROR)
#error ALIV_ST_CENG_ERROR already defined
#endif
/** \brief Symbolic name of event ALIV_ST_CENG_ERROR */
#define ALIV_ST_CENG_ERROR               104U

#if (defined CTR_WARN_ILVL_VIB_EPS_INVALID)
#error CTR_WARN_ILVL_VIB_EPS_INVALID already defined
#endif
/** \brief Symbolic name of event CTR_WARN_ILVL_VIB_EPS_INVALID */
#define CTR_WARN_ILVL_VIB_EPS_INVALID    105U

#if (defined CTR_WARN_PTRN_VIB_EPS_INVALID)
#error CTR_WARN_PTRN_VIB_EPS_INVALID already defined
#endif
/** \brief Symbolic name of event CTR_WARN_PTRN_VIB_EPS_INVALID */
#define CTR_WARN_PTRN_VIB_EPS_INVALID    106U

#if (defined CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC)
#error CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC already defined
#endif
/** \brief Symbolic name of event CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC */
#define CTRL_INTERNAL_MULTIPLE_START_ERROR_PROC 107U


#if (defined DEM_NUMBER_OF_EVENTS)
#error DEM_NUMBER_OF_EVENTS already defined
#endif
/** \brief Number of events which are present in the system
 **
 ** Calculated by number of event IDs listed above including
 ** ::DEM_EVENT_ID_INVALID.
 **
 ** Number of events as given in the configuration (value = 500)
 ** is NOT used in this version of the DEM.
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_NUMBER_OF_EVENTS 108U


#if (defined DEM_USE_DYNAMIC_DTC)
#error DEM_USE_DYNAMIC_DTC already defined
#endif
#define DEM_USE_DYNAMIC_DTC   STD_OFF

/*------------------[DTC groups configuration]------------------------------*/

/* Symbolic names of configured DTC groups */

#if (defined DEM_DTC_GROUP_EMISSION_REL_DTCS)
#error DEM_DTC_GROUP_EMISSION_REL_DTCS already defined
#endif
/** \brief Symbolic name of DTC group OBD-relevant */
#define DEM_DTC_GROUP_EMISSION_REL_DTCS  0x000000U

#if (defined DEM_DTC_GROUP_POWERTRAIN_DTCS)
#error DEM_DTC_GROUP_POWERTRAIN_DTCS already defined
#endif
/** \brief Symbolic name of DTC group powertrain */
#define DEM_DTC_GROUP_POWERTRAIN_DTCS    0x000100U

#if (defined DEM_DTC_GROUP_CHASSIS_DTCS)
#error DEM_DTC_GROUP_CHASSIS_DTCS already defined
#endif
/** \brief Symbolic name of DTC group chassis */
#define DEM_DTC_GROUP_CHASSIS_DTCS       0x000200U

#if (defined DEM_DTC_GROUP_BODY_DTCS)
#error DEM_DTC_GROUP_BODY_DTCS already defined
#endif
/** \brief Symbolic name of DTC group body */
#define DEM_DTC_GROUP_BODY_DTCS          0x001000U

#if (defined DEM_DTC_GROUP_NETWORK_COM_DTCS)
#error DEM_DTC_GROUP_NETWORK_COM_DTCS already defined
#endif
/** \brief Symbolic name of DTC group network communication */
#define DEM_DTC_GROUP_NETWORK_COM_DTCS   0xC90A00U


/*------------------[Views configuration]-----------------------------------*/

#if (defined DEM_NUMBER_OF_VIEWS)
#error DEM_NUMBER_OF_VIEWS already defined
#endif
/** \brief Views are NOT supported in this version
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_NUMBER_OF_VIEWS      0U


/*------------------[Warning indicators configuration]----------------------*/

/* Symbolic names of configured warning indicator IDs */

#if (defined EPS_LAMP)
#error EPS_LAMP already defined
#endif
/** \brief Symbolic name of warning indicator EPS_LAMP */
#define EPS_LAMP                         0U


#if (defined DEM_NUMBER_OF_INDICATORS)
#error DEM_NUMBER_OF_INDICATORS already defined
#endif
/** \brief Number of warning indicators which are present in the system
 **
 ** \note Macro name is conform to the vague definition in chapter 10 of SWS.
 **/
#define DEM_NUMBER_OF_INDICATORS 1U


/*------------------[Rte configuration]-------------------------------------*/

#if (defined DEM_INCLUDE_RTE)
#error DEM_INCLUDE_RTE already defined
#endif
/** \brief Switch, indicating if RTE is available and can be used from DEM */
#define DEM_INCLUDE_RTE STD_ON

/* Nxtr Patch Start.  Modified to allow inter-operability with Vector Rte Generator */
#if (DEM_INCLUDE_RTE == STD_ON)
#include "Rte_Type.h"
#else
/* Nxtr Patch End */

/* Symbolic names of configured operation cycles */

#if (defined DEM_OPCYCLE_DEFAULT)
#error DEM_OPCYCLE_DEFAULT already defined
#endif
/** \brief Symbolic name of operation cycle DEM_OPCYCLE_DEFAULT */
#define DEM_OPCYCLE_DEFAULT              0U

#if (defined DEM_OPCYCLE_VSM_OPMODE)
#error DEM_OPCYCLE_VSM_OPMODE already defined
#endif
/** \brief Symbolic name of operation cycle DEM_OPCYCLE_VSM_OPMODE */
#define DEM_OPCYCLE_VSM_OPMODE           1U

#if (defined BUS_ACTIVE)
#error BUS_ACTIVE already defined
#endif
/** \brief Symbolic name of operation cycle BUS_ACTIVE */
#define BUS_ACTIVE                       2U

#if (defined OBD_CYCLE)
#error OBD_CYCLE already defined
#endif
/** \brief Symbolic name of operation cycle OBD_CYCLE */
#define OBD_CYCLE                        3U


/* Symbolic names of configured freeze frame data IDs */

#if (defined DEM_FFS_DID_KILOMETER)
#error DEM_FFS_DID_KILOMETER already defined
#endif
/** \brief Symbolic name of data ID KILOMETER */
#define DEM_FFS_DID_KILOMETER 5888U

#if (defined DEM_FFS_DID_ABSOLUTE_TIME)
#error DEM_FFS_DID_ABSOLUTE_TIME already defined
#endif
/** \brief Symbolic name of data ID ABSOLUTE_TIME */
#define DEM_FFS_DID_ABSOLUTE_TIME 5889U

#if (defined DEM_FFS_DID_CSM_ERROR_CODE)
#error DEM_FFS_DID_CSM_ERROR_CODE already defined
#endif
/** \brief Symbolic name of data ID CSM_ERROR_CODE */
#define DEM_FFS_DID_CSM_ERROR_CODE 5890U

#if (defined DEM_FFS_DID_SS_VEHSPD)
#error DEM_FFS_DID_SS_VEHSPD already defined
#endif
/** \brief Symbolic name of data ID SS_VEHSPD */
#define DEM_FFS_DID_SS_VEHSPD 20490U

#if (defined DEM_FFS_DID_SS_ST_DRV_VEH)
#error DEM_FFS_DID_SS_ST_DRV_VEH already defined
#endif
/** \brief Symbolic name of data ID SS_ST_DRV_VEH */
#define DEM_FFS_DID_SS_ST_DRV_VEH 20484U

#if (defined DEM_FFS_DID_SS_ECU_VLTS_SUPP)
#error DEM_FFS_DID_SS_ECU_VLTS_SUPP already defined
#endif
/** \brief Symbolic name of data ID SS_ECU_VLTS_SUPP */
#define DEM_FFS_DID_SS_ECU_VLTS_SUPP 20486U

#if (defined DEM_FFS_DID_SS_STRWHL_ANGLE)
#error DEM_FFS_DID_SS_STRWHL_ANGLE already defined
#endif
/** \brief Symbolic name of data ID SS_STRWHL_ANGLE */
#define DEM_FFS_DID_SS_STRWHL_ANGLE 20483U

#if (defined DEM_FFS_DID_SS_CMD_MTR_TRQ)
#error DEM_FFS_DID_SS_CMD_MTR_TRQ already defined
#endif
/** \brief Symbolic name of data ID SS_CMD_MTR_TRQ */
#define DEM_FFS_DID_SS_CMD_MTR_TRQ 20495U

#if (defined DEM_FFS_DID_SS_HW_TRQ)
#error DEM_FFS_DID_SS_HW_TRQ already defined
#endif
/** \brief Symbolic name of data ID SS_HW_TRQ */
#define DEM_FFS_DID_SS_HW_TRQ 20494U

#if (defined DEM_FFS_DID_SS_NTC_NUM)
#error DEM_FFS_DID_SS_NTC_NUM already defined
#endif
/** \brief Symbolic name of data ID SS_NTC_NUM */
#define DEM_FFS_DID_SS_NTC_NUM 20530U

#if (defined DEM_FFS_DID_SS_PSCM_STATUS)
#error DEM_FFS_DID_SS_PSCM_STATUS already defined
#endif
/** \brief Symbolic name of data ID SS_PSCM_STATUS */
#define DEM_FFS_DID_SS_PSCM_STATUS 20492U


/* Symbolic names of configured extended data record numbers */

#if (defined DEM_EDS_NUM_CONDITION_BYTE)
#error DEM_EDS_NUM_CONDITION_BYTE already defined
#endif
/** \brief Symbolic name of extended data CONDITION_BYTE */
#define DEM_EDS_NUM_CONDITION_BYTE 1U

#if (defined DEM_EDS_NUM_OCCURRENCE_COUNTER)
#error DEM_EDS_NUM_OCCURRENCE_COUNTER already defined
#endif
/** \brief Symbolic name of extended data OCCURRENCE_COUNTER */
#define DEM_EDS_NUM_OCCURRENCE_COUNTER 2U

#if (defined DEM_EDS_NUM_HEALING_COUNTER)
#error DEM_EDS_NUM_HEALING_COUNTER already defined
#endif
/** \brief Symbolic name of extended data HEALING_COUNTER */
#define DEM_EDS_NUM_HEALING_COUNTER 3U

#endif /* DEM_INCLUDE_RTE == STD_OFF */


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
#endif /* ifndef DEM_API_CFG_H */
/*==================[end of file]===========================================*/
