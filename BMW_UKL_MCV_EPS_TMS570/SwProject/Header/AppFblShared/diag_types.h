/*******************************************************************************
**                                                                            **
**  SRC-MODULE: diag_types.h                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Declaration of independent Subparameter macros of diagnostic  **
**              services                                                      **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** masc         Marko Schneider            EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.0.1: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V3.0.0: 03.06.2009, hauf: CR61622: added SweProgDepStateType
 *                                    removed unused depCheckValueType
 *                                    removed unused CheckSweResultType
 *         04.06.2009, olho: CR61702: changed misspelled enum item
 * V2.0.0: 05.11.2008, miwe: CR61489: extended BootMode flag to 64 bit
 * V1.0.0: 20.08.2008, masc: CR61431: separated independent diag types for BM
 */

#ifndef DIAG_TYPES_H
#define DIAG_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* -------------------------------------------------------------------------- */
#include "sc_types.h"          /* Contains architecture independent           */
                               /* typedefinitions that shall be unique for    */
                               /* all modules.                                */
/* -------------------------------------------------------------------------- */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/


/*
 * The following symbols are used for BootMode
 */
#define BOOT_MODE_LENGTH            0x08u
#define BOOT_MODE_APPLICATION       0x00u
#define BOOT_MODE_BOOTLOADER        (uint8)0x00u, (uint8)0xFFu,                \
                                    (uint8)0xA5u, (uint8)0x5Au,                \
                                    (uint8)0x23u, (uint8)0x42u,                \
                                    (uint8)0xEBu, (uint8)0x6Cu

#if ( defined BAC && defined APPLICATION )
#else
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
#define DIAG_UDS28_00_ENABLE_RX_AND_TX                                     0x00u
#define DIAG_UDS28_01_ENABLE_RX_AND_DISABLE_TX                             0x01u
#define DIAG_UDS28_02_DISABLE_RX_AND_ENABLE_TX                             0x02u
#define DIAG_UDS28_03_DISABLE_RX_AND_TX                                    0x03u

#define DIAG_UDS28_01_NORMAL_COMM_MSG                                      0x01u
#define DIAG_UDS28_02_NM_COMM_MSG                                          0x02u
#define DIAG_UDS28_03_NORMAL_AND_NM_COMM_MSG                               0x03u

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
 * Used to access the programming dependencies in stream of 'GetCurrentSvk'
 */
#define DIAG_SVK_POS_PROGDEP                                               0x01u

/*
 * fingerprint bit mask and length format identifier:
 */
#define DIAG_FINGERPRINT_LENGTH_MASK                                       0xF0u
#define DIAG_FINGERPRINT_TESTER_SERVICE_ID_MASK                            0x0Fu
#define DIAG_FINGERPRINT_SHORT                                             0x00u
#define DIAG_FINGERPRINT_LONG                                              0x80u
#define DIAG_FINGERPRINT_PRGDATE_INITIAL                                   0x99u
#define DIAG_FINGERPRINT_PRGDATE_YEAR_POS                                  0x00u
#define DIAG_FINGERPRINT_PRGDATE_MONTH_POS                                 0x01u
#define DIAG_FINGERPRINT_PRGDATE_DAY_POS                                   0x02u
#define DIAG_FINGERPRINT_FORMAT_POS                                        0x03u
#define DIAG_FINGERPRINT_TESTER_SERVICE_ID_INITIAL                         0x0Bu
#define DIAG_FINGERPRINT_BMWCODE_POS                                       0x04u
#define DIAG_FINGERPRINT_BMWCODE_INITIAL                                 0x0000u
#define DIAG_FINGERPRINT_PROGDEVTYPE_POS                                   0x06u
#define DIAG_FINGERPRINT_PROGDEVTYPE_INITIAL                               0x00u
#define DIAG_FINGERPRINT_PROGDEV_SERNUM_POS                                0x07u
#define DIAG_FINGERPRINT_PROGDEV_SERNUM_INITIAL                     0x00000000uL
#define DIAG_FINGERPRINT_MILEAGE_POS                                       0x0Bu
#define DIAG_FINGERPRINT_MILEAGE_INITIAL                                 0x0000u

/*
 * initial value of VIN
 */
#define DIAG_VIN_INITIAL                                                   0x30u

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


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

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

/* The members of following enumeration represent the programming state       */
typedef enum
{
   /* states in the default session                                           */
   DEFAULT_BOOT                           = 0x00u,
   DEFAULT_APPL_FLASH_MODE_DEACTIVATED    = 0x81u,
   DEFAULT_APPL_FLASH_MODE_ACTIVATED      = 0x82u,

   /* statuses in the extended session                                        */
   EXTENDED_BOOT                          = 0x00u,
   EXTENDED_APPL_STARTED                  = 0x81u,
   EXTENDED_APPL_DTC_OFF                  = 0x82u,
   EXTENDED_APPL_NDC_DISABLED             = 0x83u,
   EXTENDED_APPL_FLASH_MODE_ACTIVATED     = 0x84u,
   EXTENDED_APPL_FLASH_EXIT               = 0x85u,

   /* statuses in the programming session                                     */
   PROG_BOOT_LOCKED                       = 0x01u,
   PROG_BOOT_UNLOCKED                     = 0x02u,
   PROG_BOOT_FINGERPRINT_WRITTEN          = 0x03u,
   PROG_BOOT_MEMORY_ERASED                = 0x04u,
   PROG_BOOT_DOWNLOAD_STARTED             = 0x05u,
   PROG_BOOT_TRANSFER_DATA                = 0x06u,
   PROG_BOOT_DOWNLOAD_FINISHED            = 0x07u,
   PROG_BOOT_MEMORY_CHECKED               = 0x08u,
   PROG_BOOT_PROGRAM_DEPEND_CHECKED       = 0x09u,

   PROG_BOOT_MEMORY_ERASE_FAILED          = 0x44u,
   PROG_BOOT_TRANSFER_DATA_FAILED         = 0x46u,
   PROG_BOOT_MEMORY_CHECK_FAILED          = 0x48u,
   PROG_BOOT_PROGRAM_DEPEND_CHECK_FAILED  = 0x49u,
   /* else session status                                                     */
   ELSE_SUB_SESSION_STATE                 = 0xFFu
} SubSessionType;

/* The following enum type contains the dependenciescheck possible values     */
typedef enum
{
   SWE_PROGDEP_STATE_UNCHECKED_APPL    = 0x00u,
   SWE_PROGDEP_STATE_CONSISTENT_APPL   = 0x01u,
   SWE_PROGDEP_STATE_INVALID           = 0x02u,
   SWE_PROGDEP_STATE_INCONSISTENT_APPL = 0x03u,
   SWE_PROGDEP_STATE_WRONG_APPL        = 0x04u,
   SWE_PROGDEP_STATE_VALID_BLU         = 0x06u
} SweProgDepStateType;


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
   TESTERTYPFREEREPAIRSHOP    = 0x9u,
   TESTERTYPSERVICEBMWHO      = 0xAu,
   TESTERTYPSYSTEMSUPPLIER    = 0xBu,
   TESTERTYPCARFACTORY        = 0xDu,
   TESTERTYPSPAREPARTFACTORY  = 0xEu,
   TESTERTYPDEVELOPMENT       = 0xFu
} testerKennungType;

/* The following enum type contains the 'reprogrammingValueType' types        */
typedef enum
{
   REPROGRAMMINGNOTVALIDADDRESS = 0x00u
} reprogrammingValueType;

/* the following enum type contains the 'programmingCounterStatusType'        */
typedef enum
{
   SEVERALTIMES               = 0x00u,
   ATLEASTONETIME             = 0x01u,
   NEVERMORE                  = 0x02u
} programmingCounterStatusType;

/* the following enum type contains the process classes                       */
typedef enum
{
   PROCESSCLASS_INVALID2      = 0x00u,
   PROCESSCLASS_HWEL          = 0x01u,
   PROCESSCLASS_HWAP          = 0x02u,
   PROCESSCLASS_HWFR          = 0x03u,
   PROCESSCLASS_CAFD          = 0x05u,
   PROCESSCLASS_BTLD          = 0x06u,
   PROCESSCLASS_FLSL          = 0x07u,
   PROCESSCLASS_SWFL          = 0x08u,
   PROCESSCLASS_SWFF          = 0x09u,
   PROCESSCLASS_SWPF          = 0x0Au,
   PROCESSCLASS_ONPS          = 0x0Bu,
   PROCESSCLASS_IBAD          = 0x0Cu,
   PROCESSCLASS_FAFP          = 0x0Fu,
   PROCESSCLASS_FCFA          = 0x10u,
   PROCESSCLASS_TLRT          = 0x1Au,
   PROCESSCLASS_TPRG          = 0x1Bu,
   PROCESSCLASS_ENTD          = 0xA0u,
   PROCESSCLASS_NAVD          = 0xA1u,
   PROCESSCLASS_FCFN          = 0xA2u,
   PROCESSCLASS_INVALID       = 0xFFu
} ProcessClassType;

/* The following enum type describes the status of each SWE                   */
typedef enum
{
   PROGSTAT_SWENOTFOUND                = 0x01u,
   PROGSTAT_ERASEMEMORYSTARTED         = 0x02u,
   PROGSTAT_MEMORYSUCCESSFULLYERASED   = 0x07u,
   PROGSTAT_DATATRANSFERSTARTED        = 0x03u,
   PROGSTAT_CHECKSIGNATURESTARTED      = 0x04u,
   PROGSTAT_CHECKSIGNATUREOK           = 0x05u,
   PROGSTAT_CHECKSIGNATURENOK          = 0x06u
} SWEProgrammingStatusType;

/* The following enum describes the possible types of the svk history memory  */
typedef enum
{
   SVKHISTORY_SYSTEMSUPPLIER   = 0x01u,
   SVKHISTORY_PLANT            = 0x02u,
   SVKHISTORY_BACKUP           = 0x03u
} SvkHistoryType;

/* Possible values for the CheckProgrammingPreconditions-list                 */
typedef enum
{
   MOTOR_ROTATION_SPEED_NOT_NULL                   = 0x01u,
   IMMOBILISER_NOT_DEACTIVATED                     = 0x02u,
   GEAR_IMPULSE_ROTATION_SPEED_NOT_NULL            = 0x03u,
   GEAR_OUTPUT_ROTATION_SPEED_NOT_NULL             = 0x04u,
   VEHICLESPEED_NOT_NULL                           = 0x05u,
   REGULATION_IN_PROGRESS                          = 0x06u,
   IGNITION_OFF_ON_NEEDED                          = 0x07u,
   PROGRAMMING_VOLTAGE_TOO_LOW                     = 0x08u,
   IGNITION_NOT_ACTIVATED                          = 0x09u,
   VEHICLE_ELECTRICAL_SYSTEMVOLTAGE_TOOL_LOW       = 0x0Au,
   TEMPERATURE_TOO_HIGH                            = 0x0Bu,
   TEMPERATURE_TOO_LOW                             = 0x0Cu
   /* 14 ... 127 HIS reserved, 128 ... 255 system supplier reserved           */
} ProgrammingPreConditionType;
								
#endif  /* not defined APPLICATION */

#endif  /* DIAG_TYPES_H                                                       */

/*** End of file **************************************************************/
