/* --------{ BMW C Source File }-------- */
/* !LINKSTO EDCH_SDD_0002, 1
 */

#ifndef EDCH_H
#define EDCH_H

/*==================[inclusions]==============================================*/

#include <Std_Types.h>           /* AUTOSAR standard types */
#include <Rte_Edch.h>
#include <Edch_NvM.h>
#include <Edch_Cfg.h>            /* Module configuration */

/*==================[macros]==================================================*/

/*------------------[Keyword static]------------------------------------------*/

#if !(defined EDCH_STATIC)
/**
 * \brief Macro for "static" keyword
 *
 * Macro can be redefined to set the static keyword
 */
#define EDCH_STATIC static
#endif

/*------------------[Instance ID]---------------------------------------------*/

/* !LINKSTO EDCH_SDD_0266, 1
 */
#if (defined EDCH_INSTANCE_ID)
#error EDCH_INSTANCE_ID is already defined
#endif
/**
 * \brief Instance of the module
 *
 *  Instance ID is always 0x00U because there shall be only one EDCH module
 *  available per ECU.
 */
#define EDCH_INSTANCE_ID                                                   0x00U

/*------------------[API service IDs]-----------------------------------------*/

/* !LINKSTO EDCH_060, 1
 * !LINKSTO EDCH_SDD_0271, 1
 */
#if (defined EDCH_SID_INIT)
#error EDCH_SID_INIT is already defined
#endif
/**
 * \brief Edch_Init() service id
 */
#define EDCH_SID_INIT                                                      0x01U

/* !LINKSTO EDCH_157, 1
 * !LINKSTO EDCH_SDD_0291, 1
 */
#if (defined EDCH_SID_MAIN)
#error EDCH_SID_MAIN is already defined
#endif
/**
 * \brief Edch_Main() service id
 */
#define EDCH_SID_MAIN                                                      0x02U

/* !LINKSTO EDCH_082, 1
 * !LINKSTO EDCH_SDD_0292, 1
 */
#if (defined EDCH_SID_SENDCYCLIC)
#error EDCH_SID_SENDCYCLIC is already defined
#endif
/**
 * \brief Edch_SendCyclic() service id
 */
#define EDCH_SID_SENDCYCLIC                                                0x03U

/* !LINKSTO EDCH_082, 1
 * !LINKSTO EDCH_SDD_0293, 1
 */
#if (defined EDCH_SID_CLEARERRORMEM)
#error EDCH_SID_CLEARERRORMEM is already defined
#endif
/**
 * \brief Edch_ClearErrorMem() service id
 */
#define EDCH_SID_CLEARERRORMEM                                             0x04U

/* !LINKSTO EDCH_118, 1
 * !LINKSTO EDCH_SDD_0315, 1
 */
#if (defined EDCH_SID_INITSEND)
#error EDCH_SID_INITSEND is already defined
#endif
/**
 * \brief Edch_InitSend() service id
 */
#define EDCH_SID_INITSEND                                                  0x05U

/* !LINKSTO EDCH_125, 1
 * !LINKSTO EDCH_SDD_0294, 1
 */
#if (defined EDCH_SID_CODINGSTARTNOTIFICATION)
#error EDCH_SID_CODINGSTARTNOTIFICATION is already defined
#endif
/**
 * \brief Edch_CodingStartNotification() service id
 */
#define EDCH_SID_CODINGSTARTNOTIFICATION                                   0x06U

/* !LINKSTO EDCH_129, 1
 * !LINKSTO EDCH_SDD_0295, 1
 */
#if (defined EDCH_SID_CODINGENDNOTIFICATION)
#error EDCH_SID_CODINGENDNOTIFICATION is already defined
#endif
/**
 * \brief Edch_CodingEndNotification() service id
 */
#define EDCH_SID_CODINGENDNOTIFICATION                                     0x07U

/* !LINKSTO EDCH_144, 2
 * !LINKSTO EDCH_SDD_0296, 2
 */
#if (defined EDCH_SID_OPERATIONCYCLEUPDATED)
#error EDCH_SID_OPERATIONCYCLEUPDATED is already defined
#endif
/**
 * \brief Edch_OperationCycleUpdated() service id
 */
#define EDCH_SID_OPERATIONCYCLEUPDATED                                     0x08U

/* !LINKSTO EDCH_160, 1
 * !LINKSTO EDCH_SDD_0297, 1
 */
#if (defined EDCH_SID_CALCULATECALID)
#error EDCH_SID_CALCULATECALID is already defined
#endif
/**
 * \brief Edch_CalculateCalId() service id
 */
#define EDCH_SID_CALCULATECALID                                            0x09U

/* !LINKSTO EDCH_168, 1
 * !LINKSTO EDCH_SDD_0298, 1
 */
#if (defined EDCH_SID_CALCULATECVN)
#error EDCH_SID_CALCULATECVN is already defined
#endif
/**
 * \brief Edch_CalculateCvn() service id
 */
#define EDCH_SID_CALCULATECVN                                              0x0AU

/* !LINKSTO EDCH_175, 1
 * !LINKSTO EDCH_SDD_0272, 1
 */
#if (defined EDCH_SID_CALCULATESUBCVN)
#error EDCH_SID_CALCULATESUBCVN is already defined
#endif
/**
 * \brief Edch_CalculateSubCvn() service id
 */
#define EDCH_SID_CALCULATESUBCVN                                           0x0BU

/* !LINKSTO EDCH_175, 1
 * !LINKSTO EDCH_SDD_0299, 1
 */
#if (defined EDCH_SID_CALCULATECODINGCVN)
#error EDCH_SID_CALCULATECODINGCVN is already defined
#endif
/**
 * \brief Edch_CalculateCodingCvn() service id
 */
#define EDCH_SID_CALCULATECODINGCVN                                        0x0CU

/* !LINKSTO EDCH_185, 1
 * !LINKSTO EDCH_SDD_0273, 1
 */
#if (defined EDCH_SID_CODINGRECEIVE)
#error EDCH_SID_CODINGRECEIVE is already defined
#endif
/**
 * \brief Edch_CodingReceive() service id
 */
#define EDCH_SID_CODINGRECEIVE                                             0x0DU

/* !LINKSTO EDCH_305, 2
 * !LINKSTO EDCH_SDD_0274, 2
 */
#if (defined EDCH_SID_DATASERVICEPORTREAD)
#error EDCH_SID_DATASERVICEPORTREAD is already defined
#endif
/**
 * \brief Edch_DataServicePort_Read() service id
 */
#define EDCH_SID_DATASERVICEPORTREAD                                       0x0EU

/* !LINKSTO EDCH_070, 1
 */
#if (defined EDCH_SID_EVENSTATUSCHANGED_BASE)
#error EDCH_SID_EVENSTATUSCHANGED_BASE is already defined
#endif
/**
 * \brief First Edch_EventStatusChanged<EventId>() service id
 */
#define EDCH_SID_EVENSTATUSCHANGED_BASE                                    0x0FU

/* !LINKSTO EDCH_363, 1
 * !LINKSTO EDCH_SDD_0317, 1
 */
#if (defined EDCH_SID_MONITORENABLESTATUS)
#error EDCH_SID_MONITORENABLESTATUS is already defined
#endif
/**
 * \brief Edch_MonitorEnableStatusIN() service id
 */
#define EDCH_SID_MONITORENABLESTATUS                                       0x10U
/*------------------[Development error codes]---------------------------------*/

/* !LINKSTO EDCH_298, 1
 * !LINKSTO EDCH_SDD_0275, 1
 */
#if (defined EDCH_E_CVNTABLE)
#error EDCH_E_CVNTABLE is already defined
#endif
/**
 * \brief Error code for faulty CVN definition block
 */
#define EDCH_E_CVNTABLE                                                    0x01U

/* !LINKSTO EDCH_298, 1
 * !LINKSTO EDCH_SDD_0276, 1
 */
#if (defined EDCH_E_CODINGBLOCK)
#error EDCH_E_CODINGBLOCK is already defined
#endif
/**
 * \brief Error code for wrong configured Coding switches
 */
#define EDCH_E_CODINGBLOCK                                                 0x02U

/* !LINKSTO EDCH_298, 1
 * !LINKSTO EDCH_SDD_0277, 1
 */
#if (defined EDCH_E_PARAM)
#error EDCH_E_PARAM is already defined
#endif
/**
 * \brief Error code for wrong function parameter
 */
#define EDCH_E_PARAM                                                       0x03U

/* !LINKSTO EDCH_298, 1
 * !LINKSTO EDCH_SDD_0248, 1
 */
#if (defined EDCH_E_INIT)
#error EDCH_E_INIT is already defined
#endif
/**
 * \brief Error code for uninitialized module
 */
#define EDCH_E_INIT                                                        0x04U

/* !LINKSTO EDCH_298, 1
 */
#if (defined EDCH_E_NVM)
#error EDCH_E_NVM is already defined
#endif
/**
 * \brief Error code for not correctly initialized NvM RAM mirrors
 */
#define EDCH_E_NVM                                                         0x05U

/*------------------[Edch diagnostic states]----------------------------------*/

/* !LINKSTO EDCH_047, 1
 */
#if (defined EDCH_TEST_NOT_COMPL)
#error EDCH_TEST_NOT_COMPL is already defined
#endif
/**
 * \brief Diagnostic state sub-signal for "test not completed this operation cycle"
 */
#define EDCH_TEST_NOT_COMPL                                                0x01U

/* !LINKSTO EDCH_047, 1
 */
#if (defined EDCH_TEST_FAILED)
#error EDCH_TEST_FAILED is already defined
#endif
/**
 * \brief Diagnostic state sub-signal for "test failed"
 */
#define EDCH_TEST_FAILED                                                   0x02U

/* !LINKSTO EDCH_047, 1
 */
#if (defined EDCH_TEST_FAILED_CURR)
#error EDCH_TEST_FAILED_CURR is already defined
#endif
/**
 * \brief Diagnostic state sub-signal for "test failed currently"
 */
#define EDCH_TEST_FAILED_CURR                                              0x04U

/* !LINKSTO EDCH_047, 1
 */
#if (defined EDCH_TEST_ACTIVE)
#error EDCH_TEST_ACTIVE is already defined
#endif
/**
 * \brief Diagnostic state signal for "test active currently"
 */
#define EDCH_TEST_ACTIVE                                                   0x08U

/* !LINKSTO EDCH_047, 1
 */
#if (defined EDCH_TEST_RESERVED)
#error EDCH_TEST_RESERVED is already defined
#endif
/**
 * \brief reserved bits for diagnostic state sub-signal
 */
#define EDCH_TEST_RESERVED                                                 0x30U

/*------------------[Edch reporting timing]-----------------------------------*/

/* !LINKSTO EDCH_082, 1
 */
#if (defined EDCH_BURSTCYCLE_MS)
#error EDCH_BURSTCYCLE_MS is already defined
#endif
/**
 * \brief Time of burst-cycle in milliseconds
 */
#define EDCH_BURSTCYCLE_MS                                                  160U

#if (defined EDCH_REPORTCYCLE_MS)
#error EDCH_REPORTCYCLE_MS is already defined
#endif
/**
 * \brief Time of regular report-cycle in milliseconds
 */
#define EDCH_REPORTCYCLE_MS                                                 960U

/* !LINKSTO EDCH_122, 1
 */
#if (defined EDCH_WAIT_500MS_IN_SENDCYCLIC)
#error EDCH_WAIT_500MS_IN_SENDCYCLIC is already defined
#endif
/**
 * \brief Count of SendCyclic runs to wait 500 resp. 480 msec
 */
#define EDCH_WAIT_500MS_IN_SENDCYCLIC                                      3U

/* !LINKSTO EDCH_094, 1
 */
#if (defined EDCH_REPORT2BURSTCYCLE_RATIO)
#error EDCH_REPORT2BURSTCYCLE_RATIO is already defined
#endif
/**
 * \brief Ratio between time of burst- and report-cycle
 */
#define EDCH_REPORT2BURSTCYCLE_RATIO    (EDCH_REPORTCYCLE_MS/EDCH_BURSTCYCLE_MS)

/*==================[type definitions]========================================*/

/* !LINKSTO EDCH_254, 1
 */
/**
 * \brief Type for posible states of the calculated checksums
 */
typedef enum {
  EDCH_CRC_VALID,
  EDCH_CRC_WAIT4COD,
  EDCH_CRC_READY,
  EDCH_CRC_INVALID,
  EDCH_CRC_CALC
}Edch_ChecksumStateType;

/*==================[external function declarations]==========================*/

#define EDCH_START_SEC_APPL_CODE
#include "MemMap.h"

extern FUNC(void, EDCH_APPL_CODE) Edch_SetEventStatus
(
  Edch_EventIdxType Idx
);

extern FUNC(void, EDCH_APPL_CODE) Edch_CalculateCalId(void);

extern FUNC(void, EDCH_APPL_CODE) Edch_CalculateCvn(void);

#define EDCH_STOP_SEC_APPL_CODE
#include "MemMap.h"

/*==================[external constants]======================================*/

/*==================[internal constants]======================================*/

/*==================[external data]===========================================*/

/*==================[internal data]===========================================*/

/*==================[external function definitions]===========================*/

/*==================[internal function definitions]===========================*/

#endif /* if (!defined EDCH_H) */
/*==================[end of file]=============================================*/

