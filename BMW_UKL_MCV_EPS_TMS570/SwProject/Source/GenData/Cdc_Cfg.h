

/*******************************************************************************
**
**  This file was generated. Do not modify!
**
**  SRC-MODULE        : Cdc_Cfg.h
**
**  Copyright (C) BMW Group 2011
**
**  TARGET            : ALL
**
**  PROJECT           : BMW Standard Core
**
**  AUTHOR            : EB Automotive
**
**  PURPOSE           : Configuration file of the cdc module
**
**  GENERATOR         : artt 2.0.2.0
**
**  CONFIGURATION FILE: n.a.
**
**
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** dabu         Daniel Buder               EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.5 : 26.09.2011, anam: CR71086: CDC: TRUE and FALSE (in capital letters) are not specified in AUTOSAR as xsd:boolean
 * V1.1.4 : 13.05.2011, ft  : CR70811: CDC: Missing SWT-Preparation 
 *                      anam: CR71056: SVK Read: Optimize RAM Usage
 * V1.1.3 : 15.11.2010, anam: CR70803: Switch from Com-Callbacks to Polling mode for MILE_KM  
 *                      anam: CR70875: CDC: Modifications due to CR70555
 * V1.1.3 : 22.06.2010, anam: CR70612: Configuration of UserExtension for asynchronous request handling  
 * V1.1.2 : 08.04.2010, anam: CR70611: Adapt *.bmd files to support AR Rel. 3.1 configuration process
                              CR70629: Cdc uses old CommunicationControl Api for BAC 3.0 
 * V1.1.1 : 08.04.2010, anam: CR70580: BMWAutosarCoreVersion should be now a 
 *                                     constant expression in bmd file
 * V1.1.1 : 08.04.2010, anam: CR70520: SGBD-ID configuration parameter shall be dynamic  
 * V1.1.0 : 23.02.2010, gema: CR70417, CDC: Module extension to 3.0
 * V1.0.3 : 13.01.2009, gema: CR70474: Use Appl_WaitNvmReady() in FAST Mode
 *                            CR70390, Compiler switches shall have defined values
 * V1.0.2 : 25.06.2009, dabu: CR70223: Implementation of Cdc review results
 *          23.06.2009, dabu: CR70225: CdcSgbdIndex is now configurable
 * V1.0.1 : 17.11.2008, dabu: CR70041: removed check of VSM_EVENT_OPMODE number
 *                                     to prevent wrong rte configuration
 * V1.0.0 : 27.11.2007, dabu: Initial version
 */

#ifndef CDC_CFG_H
#define CDC_CFG_H

/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/
/*
 * This file has been misra checked with the following settings
 *    BMW rule set  : BMW_basic_60_1_2.p_s
 *    Misra rule set: mcm (1998)
 *
 * The following rule violations could not be resolved:
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* -------------------------------------------------------------------------- */
#include <SysTimeClient.h>     /* SysTimeClient modul specific include        */
/* -------------------------------------------------------------------------- */
#include <Darh.h>              /* Diagnostic active response handler          */
/* -------------------------------------------------------------------------- */
#if (SC_CSM_ENABLE == STD_ON)
   #include <Csm.h>            /* Csm module                                  */
#endif
/* -------------------------------------------------------------------------- */
#include <Vsm_Client.h>        /* VSM modul specific include                  */
/* -------------------------------------------------------------------------- */
#if (SC_CODING_ENABLE == STD_ON)
   #include <Coding_Diagnostic.h>   /* Coding module DCM services             */
#endif
/* -------------------------------------------------------------------------- */
#include <Dem.h>               /* DEM Api                                     */
/* -------------------------------------------------------------------------- */
#include <FreeTimer.h>         /* free running timer driver initialization    */
/* -------------------------------------------------------------------------- */
#if (SC_SWT_ENABLE == STD_ON)
   #include <Swt_Dcm.h>        /* Swt (module) DCM services                   */
#endif
/* -------------------------------------------------------------------------- */
#if (SC_LED_DEMO_ON == STD_ON) /*Nxtr patch*/
#include <Led.h>               /* LED Api                                     */
#endif
/* -------------------------------------------------------------------------- */
#if (STANDARD_CORE_TEST == STD_ON)
   #include <Appl_Test.h>
#endif


/* -------------------------------------------------------------------------- */
#include <applmain.h>          /* Access to Appl_WaitNvMReady()               */
/* -------------------------------------------------------------------------- */
#include <Appl_Src_Cfg.h>      /* Module configuration header                 */
/* -------------------------------------------------------------------------- */
#include <sc_types.h>          /* Contains architecture independent           */
                               /* typedefinitions that shall be unique for    */
                               /* all modules.                                */
/* -------------------------------------------------------------------------- */
#include <sc_target.h>         /* Contains architecture independent general   */
                               /* definitions.                                */
/* -------------------------------------------------------------------------- */
#include <sc_target_arch.h>    /* Contains architecture specific general      */
                               /* definitions.                                */
/* -------------------------------------------------------------------------- */
#include <Bootloader_Cfg.h>    /* Programming specific timing parameters      */
/* -------------------------------------------------------------------------- */
#include <sc_ee_data.h>        /* Contains extern declaration of struct       */
                               /* 'Boot_NvData'. It is accessed in some of    */
                               /* the subsequent diagnostic services.         */
/* -------------------------------------------------------------------------- */
#include <AddressTable.h>      /* Header file dedicated to 'AddressTable.c'.  */
/* -------------------------------------------------------------------------- */
#include <DataLogistic.h>      /* SVK internal structure definition           */
/* -------------------------------------------------------------------------- */
#include <ApplNetInterface.h>  /* contains all communication bus dependent    */
                               /* functions                                   */
/* -------------------------------------------------------------------------- */
#include <flash.h>             /* Flash API for 'flashAddress_t'              */
/* -------------------------------------------------------------------------- */
#include <Dcm.h>               /* DCM Api                                     */
/* -------------------------------------------------------------------------- */
#include <StandardCore_Cfg.h>  /* for SC-version macros                       */
/* -------------------------------------------------------------------------- */
#include <ScModuleVersions.h>  /* Installed BMW module IDs and versions       */
                               /* generated by APM Tool                       */
/* -------------------------------------------------------------------------- */
#ifdef BOOTLOADER
   /* n.a. */
#else
   #include <Crypto.h>           /* include crypto routines                   */
#endif

#include <Cdc.h>


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*** Public Part (used by Cdc API) ********************************************/

/* Definitions for BAC Versions                                               */
#define CDC_BAC21 (0u)
#define CDC_BAC3X (1u)

   /*
    * File version information
    */
   #define CDC_CFG_H_MAJOR_VERSION   1u
   #define CDC_CFG_H_MINOR_VERSION   1u
   #define CDC_CFG_H_PATCH_VERSION   3u

/* Define for internal modultest */
#ifndef CDC_MODULETEST_ENABLED
#define CDC_MODULETEST_ENABLED STD_OFF
#endif

/*
    BAC Version
    Specification, in which BAC Version, Cdc is integrated
*/

#define CDC_BAC_VERSION   CDC_BAC3X


#if (CDC_BAC_VERSION == CDC_BAC3X)
#include <Vsm_Client.h>         /* Vsm Api for CommunicationControl           */
#endif
#if (CDC_BAC_VERSION == CDC_BAC21)
#include <ComM.h>              /* ComM Api for CommunicationControl           */
#endif
   
/*
 * Defines if Cdc is used in a RTE scenario:
 *    STD_ON  - RTE is used
 *    STD_OFF - RTE is not used
 */
#define CdcUseRte                                                        STD_OFF

/*
 * Defines if user specific diagnostic services in Cdc_User.h exists:
 *    STD_ON  - an user extension in Cdc_User.h exists
 *    STD_OFF - an user extension in Cdc_User.h dont't exists
 */
#define CdcUseUserExtension                                               STD_ON

/*
 * Defines if asynchronous request handling is enabled for user specific diagnostic services.
 * When enabled the functions Rte_DcmECUReset_User, Rte_DcmReadDataByIdentifier_User, 
 * Rte_DcmWriteDataByIdentifier_User and Rte_DcmRoutineControl_User are responsible for
 *   - calling Dcm_ProcessingDone()
 *   - calling Dcm_SetNegResponse() if needed
 * This parameter is only applicable when CdcUseUserExtension is enabled!!
 *
 *    STD_ON  - asynchronous request handling is enabled
 *    STD_OFF - asynchronous request handling is disabled
 */
#define CdcEnableAsyncRequestHandling                                     STD_OFF

/*
 * Defines if Cdc is used in a application or bootloader scenario:
 *    STD_ON  - Cdc is used in this specific scenario
 *    STD_OFF - Cdc is not used
 */
#define CdcScenarioApplication                                            STD_ON
#define CdcScenarioBootloader                                            STD_OFF

#if ( ( (CdcScenarioApplication == STD_ON) && (CdcScenarioBootloader == STD_ON) ) ||   \
      ( (CdcScenarioApplication == STD_OFF) && (CdcScenarioBootloader == STD_OFF) ) )
   #error Cdc_Cfg.h: Wrong configuration of the CdcScenario !!!
#endif

/*
 * 3-bytes SGBD-Index used by DIAG_DID_F150_SGBD_INDEX
 * used to identify the actual implementation version of the diagnosis module
 */
 
/* Start of dynamic SGBD  */ 
 

#if (defined CDC_USE_DYNAMIC_SGBD)
#error CDC_USE_DYNAMIC_SGBD already defined
#endif
#define CDC_USE_DYNAMIC_SGBD   STD_OFF

#define CDC_SGBD_INDEX_FIRST_BYTE  15
#define CDC_SGBD_INDEX_SECOND_BYTE 25
#define CDC_SGBD_INDEX_THIRD_BYTE  128

 
/* End of dynamic SGBD  */

/*
 * Reference to event in the DEM which is used to report that the operating mode
 * was set to a non-default value.
 */
#define CdcVsmEventOpModeRef                                    VSM_EVENT_OPMODE

/*
 * Reference to event DM_TEST_COM in the DEM.
 */
#define CdcDmTestComEventRef                                         DM_TEST_COM

/*
 * Reference to event DM_TEST_APPL in the DEM.
 */
#define CdcDmTestApplEventRef                                       DM_TEST_APPL

/*
 * Reference to the CDC block id in the NvM for the Teststamp.
 */
#define CdcNvMTestStampBlockIdRef                             NVM_BLOCK_CDC_DATA

/*
 * Reference to the signal in COM which is used to receive the current
 * kilometer value.
 * This reference is only necessary when CdcUseRte is STD_OFF
 */
#define CdcKmValueComSignalIdRef   Com_MILE_KM__KILOMETERSTAND                                         


/*
 * Diagnostic UDS service values
 */
#define DIAG_UDS10_SERVICE_DIAGNOSTIC_SESSION_CONTROL                      0x10u
#define DIAG_UDS11_SERVICE_ECU_RESET                                       0x11u
#define DIAG_UDS22_SERVICE_READ_DATA_BY_IDENTIFIER                         0x22u
#define DIAG_UDS27_SERVICE_SECURITY_ACCESS                                 0x27u
#define DIAG_UDS28_SERVICE_COMMUNICATION_CONTROL                           0x28u
#define DIAG_UDS2E_SERVICE_WRITE_DATA_BY_IDENTIFIER                        0x2Eu
#define DIAG_UDS31_SERVICE_ROUTINE_CONTROL                                 0x31u
#define DIAG_UDS34_SERVICE_REQUEST_DOWNLOAD                                0x34u
#define DIAG_UDS36_SERVICE_TRANSFER_DATA                                   0x36u
#define DIAG_UDS37_SERVICE_REQUEST_TRANSFER_EXIT                           0x37u
#define DIAG_UDS3E_SERVICE_TESTER_PRESENT                                  0x3Eu
#define DIAG_UDS85_SERVICE_CONTROL_DTC_SETTING                             0x85u
#define DIAG_UDS86_SERVICE_RESPONSE_ON_EVENT                               0x86u

/*
 * Diagnostic UDS service sub parameter values
 */
/*----- DIAG_UDS11_SERVICE_ECU_RESET -----------------------------------------*/
#define DIAG_UDS11_01_HARD_RESET                                           0x01u
#define DIAG_UDS11_02_KEY_OFF_ON_RESET                                     0x02u
#define DIAG_UDS11_03_SOFT_RESET                                           0x03u
#define DIAG_UDS11_04_ENABLE_RAPID_POWER_SHUTDOWN                          0x04u
#define DIAG_UDS11_41_ERROR_POWER_SHUTDOWN                                 0x41u

/*----- DIAG_UDS27_SERVICE_SECURITY_ACCESS -----------------------------------*/
#define DIAG_UDS27_01_CODING_SESSION_GET_SEED                              0x01u
#define DIAG_UDS27_02_CODING_SESSION_COMPARE_KEY                           0x02u
#define DIAG_UDS27_11_PROGRAMMING_SESSION_GET_SEED                         0x11u
#define DIAG_UDS27_12_PROGRAMMING_SESSION_COMPARE_KEY                      0x12u

/* NXTR SWT - added for SWT security access */
#define DIAG_UDS27_13_SWT_SESSION_GET_SEED                         			0x13u
#define DIAG_UDS27_14_SWT_SESSION_COMPARE_KEY                     			0x14u

/*----- DIAG_UDS28_SERVICE_COMMUNICATION_CONTROL -----------------------------*/
#define DIAG_UDS28_00_ENABLE_RX_AND_TX                  COMM_DIAG_ENABLE_RX_AND_TX
#define DIAG_UDS28_01_ENABLE_RX_AND_DISABLE_TX  COMM_DIAG_ENABLE_RX_AND_DISABLE_TX
#define DIAG_UDS28_02_DISABLE_RX_AND_ENABLE_TX  COMM_DIAG_DISABLE_RX_AND_ENABLE_TX
#define DIAG_UDS28_03_DISABLE_RX_AND_TX                COMM_DIAG_DISABLE_RX_AND_TX

#define DIAG_UDS28_01_NORMAL_COMM_MSG                  COMM_DIAG_NORMAL_COMM_MSG
#define DIAG_UDS28_02_NM_COMM_MSG                          COMM_DIAG_NM_COMM_MSG
#define DIAG_UDS28_03_NORMAL_AND_NM_COMM_MSG    COMM_DIAG_NORMAL_AND_NM_COMM_MSG

/*----- DIAG_UDS31_SERVICE_ROUTINE_CONTROL -----------------------------------*/
#define DIAG_UDS31_01_START_ROUTINE                                        0x01u
#define DIAG_UDS31_02_STOP_ROUTINE                                         0x02u
#define DIAG_UDS31_03_REQUEST_RESULT                                       0x03u

/*----- ROUTINE_CONTROL ERASE FLASH METHODS-----------------------------------*/
#define DIAG_FLASH_ERASE_METHOD_ADDRESSED                                  0x01u
#define DIAG_FLASH_ERASE_METHOD_INDICATED                                  0x02u
#define DIAG_FLASH_ERASE_METHOD_SPECIFIC                                   0x03u

/*----- ROUTINE_CONTROL CHECK MEMORY METHODS----------------------------------*/
#define DIAG_CHECK_MEMORY_METHOD_ADDRESSED                                 0x11u
#define DIAG_CHECK_MEMORY_METHOD_INDICATED                                 0x12u

/*----- DIAG_UDS85_SERVICE_CONTROL_DTC_SETTING -------------------------------*/
#define DIAG_UDS85_01_ON                                                   0x01u
#define DIAG_UDS85_02_OFF                                                  0x02u

/*
 * Diagnostic data identifier values
 * Used by Read/WriteDataByIdentifier
 */
#define DIAG_DID_1000_TEST_STAMP                                         0x1000u
#define DIAG_DID_100A_VSM_OPERATION_MODE                                 0x100Au
#define DIAG_DID_100E_VSM_OPERATION_MODE_EXTENSION                       0x100Eu
#define DIAG_DID_1234_STANDARD_CORE_TEST                                 0x1234u
#define DIAG_DID_1700_KILOMETER                                          0x1700u
#define DIAG_DID_1701_RELATIVE_TIME                                      0x1701u
#define DIAG_DID_1704_DARH_DTC                                           0x1704u
#define DIAG_DID_1720_STANDARD_CORE_VERSION                              0x1720u
#define DIAG_DID_1723_IS_DTC_ACTIVE_RESPONSE                             0x1723u
#define DIAG_DID_1724_IS_DTC_LOCKABLE                                    0x1724u
#define DIAG_DID_1726_STANDARD_CORE_MODULE_VERSIONS                      0x1726u
#define DIAG_DID_2000_DTCS_OF_SECONDARY_ERR_MEM                          0x2000u
#define DIAG_DID_2001_DTC_RANGE_MIN_VALUE                                0x2001u
#define DIAG_DID_21FF_DTC_RANGE_MAX_VALUE                                0x21FFu
#define DIAG_DID_2501_MEMORY_SEGMENTATION_TABLE                          0x2501u
#define DIAG_DID_2502_PROG_COUNTER                                       0x2502u
#define DIAG_DID_2503_PROG_COUNTER_MAX_VALUE                             0x2503u
#define DIAG_DID_2504_FLASH_TIMING_PARAMS                                0x2504u

#define DIAG_DID_2506_READ_MEMORY_ADDRESS                                0x2506u
#define DIAG_DID_3000_CODING_BLOCK_RANGE_MIN                             0x3000u
#define DIAG_DID_37FD_CODING_BLOCK_RANGE_MAX                             0x37FDu
#define DIAG_DID_37FE_CODING_TESTSTAMP                                   0x37FEu
#define DIAG_DID_3F03_SWT_READ_ECU_SWTLIST                               0x3F03u
#define DIAG_DID_F101_SVK_AKTUELL                                        0xF101u
#define DIAG_DID_F102_SVK_SYSTEM_SUPPLIER                                0xF102u
#define DIAG_DID_F103_SVK_PLANT                                          0xF103u
#define DIAG_DID_F104_SVK_BACKUP_MIN                                     0xF104u
#define DIAG_DID_F140_SVK_BACKUP_MAX                                     0xF140u

#if (NUMBEROFSVKBACKUPS \
      >                 \
    (DIAG_DID_F140_SVK_BACKUP_MAX - DIAG_DID_F104_SVK_BACKUP_MIN + 1u))
   #error "Cdc_Cfg.h: NUMBEROFSVKBACKUPS must be less or equal 61"
#endif

#define DIAG_DID_F150_SGBD_INDEX                                         0xF150u
#define DIAG_DID_F15A_FINGERPRINT                                        0xF15Au
#define DIAG_DID_F186_ACTIVE_DIAG_SESSION                                0xF186u
#define DIAG_DID_F18B_ECU_MANUFACTURING_DATA                             0xF18Bu
#define DIAG_DID_F18C_ECU_SERIAL_NUMBER                                  0xF18Cu
#define DIAG_DID_F190_VIN                                                0xF190u

/*
 * Diagnostic routine identifier values
 * Used by RoutineControl
 */
#define DIAG_RID_0202_CHECK_MEMORY                                       0x0202u
#define DIAG_RID_0203_CHECK_PROGRAMMING_PRECONDITIONS                    0x0203u
#define DIAG_RID_0204_READ_SWE_PROGRAMMING_STATUS                        0x0204u
#define DIAG_RID_0205_READ_DEVELOPMENT_INFO                              0x0205u
#define DIAG_RID_0209_WATCHDOG_TRIGGER_STOP                              0x0209u
#define DIAG_RID_020C_CSM_F30                                            0x020Cu
#define DIAG_RID_020D_CSM_F40                                            0x020Du
#define DIAG_RID_020E_CSM_F60                                            0x020Eu
#define DIAG_RID_020F_CSM_F70                                            0x020Fu
#define DIAG_RID_0302_STANDARD_CORE_TEST                                 0x0302u
#define DIAG_RID_0303_DIAG_COMM_LOOPBACK                                 0x0303u
#define DIAG_RID_0304_DM_TEST                                            0x0304u
#define DIAG_RID_0F01_CHECK_CODING_SIGNATURE                             0x0F01u
#define DIAG_RID_0F06_CLEAR_DTC_SECONDARY_MEMORY                         0x0F06u
#define DIAG_RID_0F0C_SET_VSM_OPERATION_MODE                             0x0F0Cu
#define DIAG_RID_0F1F_SWT_OPERATION                                      0x0F1Fu
#define DIAG_RID_1003_SET_VSM_OPERATION_MODE_EXTENSION                   0x1003u
#define DIAG_RID_FF00_ERASE_MEMORY                                       0xFF00u
#define DIAG_RID_FF01_CHECK_REPROGRAMMING_DEPENDENCIES                   0xFF01u

/*
 * Response length for diagnostic services to check it at compile time
 */
/* max. response length for service ReadDataByIdentifier                      */
#define DIAG_RDBYID_RESPONSE_LENGTH    (9u)
/* response length for appropriate diagnostic services                        */
#define DIAG_DID_1000_RESPONSE_LENGTH  (2u + 3u)
#define DIAG_DID_100A_RESPONSE_LENGTH  (2u + 1u)
#define DIAG_DID_100E_RESPONSE_LENGTH  (2u + 1u)
#define DIAG_DID_1700_RESPONSE_LENGTH  (2u + 3u)
#define DIAG_DID_1701_RESPONSE_LENGTH  (2u + 4u)
#define DIAG_DID_1704_RESPONSE_LENGTH  (2u + (kDarhCountOfElementsPerTx * 7u) )
#define DIAG_DID_1720_RESPONSE_LENGTH  (2u + 4u)
#define DIAG_DID_2501_RESPONSE_LENGTH  (2u + 3u + (FLASH_SEGMENT_NUMBER_ALL * 10u) )
#define DIAG_DID_2502_RESPONSE_LENGTH  (2u + 4u)
#define DIAG_DID_2503_RESPONSE_LENGTH  (2u + 2u)
#define DIAG_DID_2504_RESPONSE_LENGTH  (2u + TIMINGPARAMETERLENGTH)
#define DIAG_DID_F150_RESPONSE_LENGTH  (2u + 3u)
#define DIAG_DID_F186_RESPONSE_LENGTH  (2u + 2u)
#define DIAG_DID_F18B_RESPONSE_LENGTH  (2u + ECUMANUFACTURINGDATALENGTH)
#define DIAG_DID_F18C_RESPONSE_LENGTH  (2u + ECUSERIALNUMBERLENGTH)
#define DIAG_DID_F190_RESPONSE_LENGTH  (2u + VINLENGTH)
#define DIAG_RID_0205_RESPONSE_LENGTH  (1u + 2u + 1u + MAX_XWE_DEV_INFO_LENGTH)


/*
 * Authentication security level
 * SC does only support authentification level 3
 */
#define CDC_AUTH_LEVEL 0x04u /*NXTR SWT PATCH 9/29/12 needed for level 4 security access, value was 0x03u */

/*
 * Authentication key length in bytes
 * Depends on authentication method which can be defined in StandardCore.mcfg
 */
#if defined (CRYPTO_AUTH_ASYM)
   #define SG_KEY_LEN                         ((CR_DEF_AUTH_KEY_LENGTH) * 0x04u)
#elif defined (CRYPTO_AUTH_SYM)
   #define SG_KEY_LEN                                                      0x10u
#else
   #error "Cdc_Cfg.h: No crypto method defined. Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'."
#endif

/*
 * This parameter is used to indicate to the function 'GetCurrentSvk' that the
 * SVK will be used for storing in EEPROM and not as a diag response
 */
#define GET_SVK_CURRENT_FOR_HISTORY_MEM                                  0x0000u

/*
 * Used to access the programming dependencies in stream of 'GetCurrentSvk'
 */
#define DIAG_SVK_POS_PROGDEP                                               0x01u

/*
 * The diagnosis data are received/sent high byte first.
 * If the endianess of the microcontroller fits to the diagnosis endianess,
 * simple memcopy operations can be performed instead of copying 'manually'
 */
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
   #define DIAG_ENDIANESS_FITS                                            STD_ON
#else
   #define DIAG_ENDIANESS_FITS                                           STD_OFF
#endif

/*
 * specified addressControlInfo values
 */
#define DIAG_ADDR_CTRL_INFO_SEGMENT_BOUNDARY                               0x00u
#define DIAG_ADDR_CTRL_INFO_MEMORY_CELL                                    0x10u

/*
 * SGBM identifier default value according to FP_5750
 */
#define DIAG_SGBM_ID_DEFAULT_VALUE                                         0x00u

/*
 * according to FP_5871 the ECUs shall only support one valid addess and lengh
 * format identifier
 */
#define DIAG_ADDRESS_FORMAT_IDENTIFIER                                     0x04u
#define DIAG_LENGTH_FORMAT_IDENTIFIER                                      0x40u
#define DIAG_ADDRESS_AND_LENGTH_FORMAT_IDENTIFIER                              \
                (DIAG_ADDRESS_FORMAT_IDENTIFIER | DIAG_LENGTH_FORMAT_IDENTIFIER)
#define DIAG_SIZEOF_OF_ADDRESS_PARAM                                           \
                (DIAG_ADDRESS_FORMAT_IDENTIFIER)
#define DIAG_SIZEOF_OF_LENGTH_PARAM                                            \
                (DIAG_LENGTH_FORMAT_IDENTIFIER >> 0x04u)
#define DIAG_SIZEOF_OF_ADDRESS_AND_LENGTH_PARAMS                               \
                (DIAG_SIZEOF_OF_ADDRESS_PARAM + DIAG_SIZEOF_OF_LENGTH_PARAM)

/* for special rcu reset handling                                             */
#define ECU_HARD_RESET_REQ                                                 0x01u
#define ECU_HARD_RESET_ACK                                                 0x10u
#define ECU_PROG_SES_CHANGE_REQ                                            0x02u
#define ECU_PROG_SES_CHANGE_ACK                                            0x20u

#define RESPONSE_FIT_INTO_BUFFER                                         0xFFFFu

/*
 * valid parameter(s) of set extended operation mode from module VSM
 */
#define CDC_VSM_MM_MODE_EXTENSION_FLASH_ENABLED                            0x01u


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* only CDC internal types !                                                  */

/*
 * Pending diag context type:
 * Used to save diag parameters for PostHandler
 */
typedef struct
{
   uint8               SubFunction;          /* used to save the actual       */
                                             /* subfunction. E.g. for post    */
                                             /* handler                       */
   uint16              DataOrRoutineId;      /* used to save the actual       */
                                             /* Data- or Routine-Identifier.  */
                                             /* E.g. for post handler         */
} pendingDiagContextType;

/*
 * Type for the paged buffer processing functionality.
 * Parameters for the page-update-functions.
 */
#if (DCM_PAGEDBUFFER_ENABLED == STD_ON)
typedef P2FUNC(void,DCM_APPL_CODE, Rte_DcmUpdatePageType)
(
   Dcm_MsgType dataBufPtr,
   Dcm_MsgLenType dataLen
);
#endif

/* return value type of the function CheckProgDepStatus                       */
typedef enum
{
   SWE_CHECK_RESULT_FAILED = 0x00u,       /* at least one SWE is invalid      */
   SWE_CHECK_RESULT_OK     = 0x01u,       /* all SWEs are valid               */
   SWE_CHECK_RESULT_BLU_OK = 0x02u        /* valid BLU found                  */
} CheckSweResultType;

/* The following enum type contains the 'testerKennungType' types             */
typedef enum
{
   TESTERTYPFREEREPAIRSHOP                         = 0x9u,
   TESTERTYPSERVICEBMWHO                           = 0xAu,
   TESTERTYPSYSTEMSUPPLIER                         = 0xBu,
   TESTERTYPCARFACTORY                             = 0xDu,
   TESTERTYPSPAREPARTFACTORY                       = 0xEu,
   TESTERTYPDEVELOPMENT                            = 0xFu
} testerKennungType;

/* the following enum type contains the 'programmingCounterStatusType'        */
typedef enum
{
   SEVERALTIMES                                    = 0x00u,
   ATLEASTONETIME                                  = 0x01u,
   NEVERMORE                                       = 0x02u
} programmingCounterStatusType;

/* The following enum describes the possible types of the svk history memory  */
typedef enum
{
   SVKHISTORY_SYSTEMSUPPLIER                       = 0x01u,
   SVKHISTORY_PLANT                                = 0x02u,
   SVKHISTORY_BACKUP                               = 0x03u
} SvkHistoryType;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* only CDC internal global data !                                            */

#define CDC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

   extern VAR(SubSessionType, CDC_VAR_DCMDATA) activeSubSession;

   /*
    * Pending diag context type
    * Used to save diag parameters for asynchronous processing in 'BackgroundTask'
    */
   extern VAR(pendingDiagContextType, CDC_VAR_DCMDATA) pendingDiagContext;

#define CDC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/


/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/


/*******************************************************************************
**                      Mapping of external API                               **
*******************************************************************************/

#ifdef STANDARD_CORE_TEST
   #define CDC_STANDARD_CORE_TEST                           STANDARD_CORE_TEST
#else
   #define CDC_STANDARD_CORE_TEST                           STD_OFF
#endif
#ifdef SC_APPL_CRYPTO_ENABLE
   #define CDC_SC_APPL_CRYPTO_ENABLE                        SC_APPL_CRYPTO_ENABLE
#else
   #define CDC_SC_APPL_CRYPTO_ENABLE                        STD_OFF
#endif
#ifdef SC_BOOT_CRYPTO_ENABLE
   #define CDC_SC_BOOT_CRYPTO_ENABLE                        SC_BOOT_CRYPTO_ENABLE
#else
   #define CDC_SC_BOOT_CRYPTO_ENABLE                        STD_OFF
#endif
#ifdef SC_CODING_ENABLE
   #define CDC_SC_CODING_ENABLE                             SC_CODING_ENABLE
#else
   #define CDC_SC_CODING_ENABLE                             STD_OFF
#endif
#ifdef SC_CSM_ENABLE
   #define CDC_SC_CSM_ENABLE                                SC_CSM_ENABLE
#else
   #define CDC_SC_CSM_ENABLE                                STD_OFF
#endif
#ifdef SC_SWT_ENABLE
   #if (SC_SWT_ENABLE == STD_ON)
       #define CDC_SC_SWT_ENABLE                            STD_ON
   #else 
       #define CDC_SC_SWT_ENABLE                            STD_OFF
   #endif
#else
   #define CDC_SC_SWT_ENABLE                                STD_OFF
#endif
#ifdef SC_LED_DEMO_ON
   #define CDC_SC_LED_DEMO_ON                               SC_LED_DEMO_ON
#else
   #define CDC_SC_LED_DEMO_ON                               STD_OFF
#endif
#ifdef DM_TEST
   #define CDC_DM_TEST                                      DM_TEST
#else
   #define CDC_DM_TEST                                      STD_OFF
#endif

/*
 * Mapping of the functionality of the module SystimeClient
 */
#define CDC_SYSTIMECLIENT_GETTIME(time)                     SysTimeClient_GetTime(time)

/*
 * Mapping of the functionality of the module CSM
 */
#define CDC_CSM_DEMERRORCODE                                Csm_DemErrorCode

#define CDC_CSM_TPRECEIVEMESSAGE(pMsgC)                     Csm_TPReceiveMessage(pMsgC)
#define CDC_CSM_TPREQUESTRESULT(pMsgC)                      Csm_TPRequestResult(pMsgC)
#define CDC_CSM_TPSENDCONFIRMATION(service)                 Csm_TPSendConfirmation(service)

/*
 * Mapping of the functionality of the module DARH
 */
#define CDC_ROE_IS_STOPPED                                  ROE_IS_STOPPED
#define CDC_ROE_IS_STARTED                                  ROE_IS_STARTED
#define CDC_ROE_STOP_SUSPENDED                              ROE_STOP_SUSPENDED
#define CDC_ROE_START_SUSPENDED                             ROE_START_SUSPENDED

#define CDC_DARH_ROEENGINETYPE                              Darh_RoeEngineType
#define CDC_DARH_ROESTOREBITTYPE                            Darh_RoeStoreBitType
#define CDC_DARH_ROEISSTARTEDTYPE                           Darh_RoeIsStartedType

#define CDC_DARH_GETROESTATUS(roeEngine)                    Darh_GetRoeStatus(roeEngine)
#define CDC_DARH_SETROESTATUS(roeEngine)                    Darh_SetRoeStatus(roeEngine)

#define CDC_DARH_GETACTIVERESPONSEPAYLOAD(dataPtr, dataLen) Darh_GetActiveResponsePayload(dataPtr, dataLen)
#define CDC_DARH_READDATABYIDTRANSMISSION(status)           Darh_ReadDataByIdTransmission(status)


/*
 * Mapping of the functionality of the module VsmClient
 */
#define CDC_VSM_MM_MODE_BMW_FLASH                           VSM_MM_MODE_BMW_FLASH
#define CDC_VSM_MM_MODE_NORMAL                              VSM_MM_MODE_NORMAL
#define CDC_VSM_MM_MODE_ASSEMBLY                            VSM_MM_MODE_ASSEMBLY
#define CDC_VSM_MM_MODE_TRANSPORT                           VSM_MM_MODE_TRANSPORT

#define CDC_VSM_OPERATINGMODETYPE                           Vsm_OperatingModeType
#define CDC_VSM_OPERATINGMODEEXTENSIONTYPE                  Vsm_OperatingModeExtensionType

#define CDC_VSM_GETMODE(op_mode)                            Vsm_GetMode(op_mode)
#define CDC_VSM_GETMODEEXTENSION(op_mode)                   Vsm_GetModeExtension(op_mode)
#define CDC_VSM_DIAGMODECHANGE(newOpMode)                   Vsm_DiagModeChange(newOpMode)
#define CDC_VSM_DIAGMODEEXTENSIONCHANGE(newExtOpMode)       Vsm_DiagModeExtensionChange(newExtOpMode)

/*
 * Mapping of the functionality of the module Coding
 */
#define CDC_CODING_DIAGREADDATABYIDENTIFIER(pMsgC, did)     Coding_DiagReadDataByIdentifier(pMsgC, did)
#define CDC_CODING_DIAGWRITEDATABYIDENTIFIER(pMsgC, did)    Coding_DiagWriteDataByIdentifier(pMsgC, did)
#define CDC_CODING_DIAGROUTINECONTROLCHECKSIGNATURE(pMsgC)  Coding_DiagRoutineControlCheckSignature(pMsgC)
#define CDC_CODING_DIAGGETSESSIONSTARTPERMISSION()          Coding_DiagGetSessionStartPermission()
#define CDC_CODING_DIAGSESSIONENDINDICATION()               Coding_DiagSessionEndIndication()
#define CDC_CODING_DIAGGETNUMBEROFCODEDAREAS()              Coding_DiagGetNumberOfCodedAreas()
#define CDC_CODING_DIAGGETCAFIDSOFCODEDAREAS(dataPtr)       Coding_DiagGetCafIdsOfCodedAreas(dataPtr)

/*
 * Mapping of the non-Autosar functionality of the module Dem
 */
#define CDC_DEM_DMDEBUG_FILTER_ROEACTIVE                    DEM_DMDEBUG_FILTER_ROEACTIVE
#define CDC_DEM_DMDEBUG_FILTER_LOCKABLE                     DEM_DMDEBUG_FILTER_LOCKABLE

#define CDC_DEM_GETNEXTFILTEREDDMDEBUGDTC(DTCKind,DTC)      Dem_GetNextFilteredDMDebugDTC(DTCKind,DTC)
#define CDC_DEM_SETDMDEBUGFILTER(Filter)                    Dem_SetDMDebugFilter(Filter)

/*
 * Mapping of the functionality of the file ComM.h
 */
#if (CDC_BAC_VERSION == CDC_BAC3X)
#define CDC_SETCOMMUNICATIONMODE(commMode, commType)        Vsm_CommunicationControl(commMode, commType)
#endif
#if (CDC_BAC_VERSION == CDC_BAC21)
#define CDC_SETCOMMUNICATIONMODE(commMode, commType)        ComM_CommunicationControl(commMode, commType)
#endif

/*
 * Mapping of the functionality of the module FreeTimer
 */
#define CDC_FREETIMER_CREATERANDOMNUMBER()                  FreeTimer_CreateRandomNumber()

/*
 * Mapping of the functionality of the module SWT
 */
#if (CDC_SC_SWT_ENABLE == STD_ON)
	#define CDC_SWT_DCMREADDATABYIDENTIFIERREADECUSWTLIST(pMsgC)   Swt_DcmReadDataByIdentifierReadEcuSwtList(pMsgC)
   /* NXTR SWT */	//changed Cdc_Dispatcher to call Swt_DcmRoutineControlSwtOperation directly    #define CDC_SWT_DCMROUTINECONTROLSWTOPERATION(0x30, pMsgC)           Swt_DcmRoutineControlSwtOperation( Sgid, pMsgC )///* NXTR SWT */ - CDCSWT compatibility issues Swt_DcmRoutineControlSwtOperation(pMsgC)
	#define CDC_SWT_DCMGETSESSIONSTARTPERMISSION()                 Swt_DcmGetSessionStartPermission()
#endif

/*
 * Mapping of the functionality of the module LED
 */
#define CDC_LED_CLEAR(led)                                  Led_Clear(led)
#define CDC_LED_SET(led)                                    Led_Set(led)

/*
 * Mapping of the test-functionality
 */
#define CDC_CBK_TESTUPDATEPAGE                              Appl_TestUpdatePage

#define CDC_CBK_TESTREADDATABYIDENTIFIER(pMsgC,pIsPPE)      Appl_TestReadDataByIdentifier(pMsgC,pIsPPE)
#define CDC_CBK_TESTSTARTROUTINE(pMsgC)                     Appl_TestStartRoutine(pMsgC)
#define CDC_CBK_TESTSTOPROUTINE(pMsgC)                      Appl_TestStopRoutine(pMsgC)
#define CDC_CBK_TESTREQUESTROUTINERESULT(pMsgC)             Appl_TestRequestRoutineResult(pMsgC)
#define CDC_CBK_TESTCONFIRMATION()                          Appl_TestConfirmation()

/*
 * Mapping of the functionality of the file applmain.h
 */
#define CDC_NV_WRITE_OPERATION                              NV_WRITE_OPERATION

#define CDC_WAITNVMREADY(blockNumber)                       Appl_WaitNvMReady(blockNumber, TRUE)

/*
 * Mapping for SVK NVM Blocks
 */
#define CDC_NVM_READ_BLOCK(blockNumber, NvM_DstPtr)     NvM_ReadBlock( blockNumber, NvM_DstPtr)

#define CDC_NVM_BLOCK_SVK_SYS_SUPP      NVM_BLOCK_SVK_SYS_SUPP
#define CDC_NVM_BLOCK_SVK_PLANT         NVM_BLOCK_SVK_PLANT

#define CDC_NVM_BLOCK_SVK_BACKUP_ARRAY  \
{ \
}


/*
 * Mapping of the functionality of the file bootmain.h
 */
#define CDC_NVM_BLOCK_BOOT_PROG_DATA                        NVM_BLOCK_BOOT_PROG_DATA

#define CDC_OPERATENVDATA(blockNumber, optype)              OperateNvData(blockNumber, optype)

/*
 * Mapping of the functionality of the file Appl_Src_Cfg.h
 */
#define CDC_APPL_CHECKPROGRAMMINGPRECONDITIONS()            Appl_CheckProgrammingPreConditions()
#define CDC_USERCALLBACK_CHECKPROGRAMMINGPRECONDITIONS(pD)  UserCallback_CheckProgrammingPreConditions(pD)
#define CDC_USERCALLBACK_WATCHDOGTRIGGERSTOP(remTimeInS)    UserCallback_WatchdogTriggerStop(remTimeInS)

/*
 * Mapping of the functionality of the file sc_target_arch.h
 */
#define CDC_SC_MEMCPY_ROM                                   SC_MEMCPY_ROM
#define CDC_SC_MEMCPY                                       SC_MEMCPY
#define CDC_SC_MEMCMP_ROM                                   SC_MEMCMP_ROM
#define CDC_SC_MEMMOVE                                      SC_MEMMOVE
#define CDC_SC_MEMSET_ROM                                   SC_MEMSET_ROM

/*
 * Mapping of the functionality of the file Bootloader_Cfg.h or Bootloader_Cfg_xxx.h
 */
#define CDC_NUMBEROFSVKBACKUPS                              NUMBEROFSVKBACKUPS
#define CDC_NUMBEROFHWESGBMIDS                              NUMBEROFHWESGBMIDS
#define CDC_HWEDEVELOPMENTINFOLENGTH                        HWEDEVELOPMENTINFOLENGTH
#define CDC_ECUSERIALNUMBERLENGTH                           ECUSERIALNUMBERLENGTH

#define CDC_SWENUMBEROFALLSWE                               SWENUMBEROFALLSWE
#define CDC_FLASH_SEGMENT_NUMBER_ALL                        FLASH_SEGMENT_NUMBER_ALL

/*
 * Mapping of the functionality of the file DataLogistik.h
 */
#define CDC_ECUMANUFACTURINGDATALENGTH                      ECUMANUFACTURINGDATALENGTH

/*
 * Mapping of the functionality of the file flash.h
 */
#define CDC_FLASHADDRESS_T                                  flashAddress_t

/*
 * Mapping of the functionality of the file ScModuleVersions.h
 */
#define CDC_SC_PACKAGE_IDS                                  SC_PACKAGE_IDS

/*
 * Mapping of the functionality of the file StandardCore_Cfg.h
 */
#define CDC_STANDARDCORE_MAJOR_VERSION                STANDARDCORE_MAJOR_VERSION
#define CDC_STANDARDCORE_MINOR_VERSION                STANDARDCORE_MINOR_VERSION
#define CDC_STANDARDCORE_PATCH_VERSION                STANDARDCORE_PATCH_VERSION

/*
 * Mapping of the functionality of the file Crypto.h
 */
#ifdef CRYPTO_AUTH_SYM
   #define CDC_CRYPTO_AUTH_SYM                              CRYPTO_AUTH_SYM
#else
   #define CDC_CRYPTO_AUTH_ASYM                             CRYPTO_AUTH_ASYM
#endif

#define CDC_CR_FP_UINT8                                     CR_fp_uint8
#define CDC_CR_FPC_UINT8                                    CR_fpc_uint8
#define CDC_CR_FPC_UINT32                                   CR_fpc_uint32
#define CDC_CR_C_RC_T                                       CR_C_RC_t
#define CDC_CR_C_RC_OK                                      CR_C_RC_OK

#define CDC_CRYPTO_MAKECHALLKEY(length, challKey)           Crypto_MakeChallKey(length, challKey)
#define CDC_CRYPTO_CHECKAUTHUSTGSYMM(ch, uID, cID, l, r)    Crypto_CheckAuthUStgSymm(ch, uID, cID, l, r)
#define CDC_CRYPTO_CHECKAUTHUSTG(ch, uID, cID, cC, l, r, s) Crypto_CheckAuthUStg(ch, uID, cID, cC, l, r, s)


/*
 * Mapping of data assemble/deassemble macros
 */
#define CDC_MAKE16BIT(hiByte,loByte)                        Make16Bit(hiByte,loByte)
#define CDC_MAKE32BIT(hiHiByte,hiLoByte,loHiByte,loLoByte)  Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)
#define CDC_GETHIBYTE(data)                                 GetHiByte(data)
#define CDC_GETLOBYTE(data)                                 GetLoByte(data)
#define CDC_GETHIHIBYTE(data)                               GetHiHiByte(data)
#define CDC_GETHILOBYTE(data)                               GetHiLoByte(data)
#define CDC_GETLOHIBYTE(data)                               GetLoHiByte(data)
#define CDC_GETLOLOBYTE(data)                               GetLoLoByte(data)

#endif /* CDC_CFG_H                                                           */

/*** End of file **************************************************************/
