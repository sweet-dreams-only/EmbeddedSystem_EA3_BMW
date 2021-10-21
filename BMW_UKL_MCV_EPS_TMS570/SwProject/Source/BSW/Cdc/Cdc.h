/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Cdc.h                                                         **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Header file of the CDC module                                 **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** dabu         Daniel Buder               EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.2: 08.10.2009, hauf: CR70292: Corrected storage class of
 *                                    Cdc_NvDataDefault to CDC_VAR_NVCONST
 * V1.0.1: 25.06.2009, dabu: CR70223: Implementation of Cdc review results
 * V1.0.0: 08.08.2008, dabu: BSCCDC-25: changed Application Extended Session
 *                                      handling according LH FP part 5 v09
 *         26.11.2007, dabu: ported from SC6.7.2 DiagServices package
 *                           version V4.0.1 from 2007-11-06
 */

#ifndef CDC_H
#define CDC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include <Dcm.h>                    /* DCM API                                */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * File version information
 */
#define CDC_H_MAJOR_VERSION        1u
#define CDC_H_MINOR_VERSION        1u
#define CDC_H_PATCH_VERSION        3u

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

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

#define CDC_TESTSTAMPINDEX                                                     3

/*
 * Init value for 'lastProgrammedSegment'. It represents that a restart of
 * transmission is not possible at the moment.
 */
#define REPROGRAMMINGNOTVALIDADDRESS                                       0x00u


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef struct
{
  uint8 testStamp[CDC_TESTSTAMPINDEX];
} Cdc_NvDataType;

/* The members of following enumeration represent the programming state       */
typedef enum
{
   /* states in the default session                                           */
   DEFAULT_BOOT                                    = 0x00u,
   DEFAULT_APPL_FLASH_MODE_DEACTIVATED             = 0x81u,
   DEFAULT_APPL_FLASH_MODE_ACTIVATED               = 0x82u,

   /* statuses in the extended session                                        */
   EXTENDED_BOOT                                   = 0x00u,
   EXTENDED_APPL_STARTED                           = 0x81u,
   EXTENDED_APPL_DTC_OFF                           = 0x82u,
   EXTENDED_APPL_NDC_DISABLED                      = 0x83u,
   EXTENDED_APPL_FLASH_MODE_ACTIVATED              = 0x84u,
   EXTENDED_APPL_FLASH_EXIT                        = 0x85u,

   /* statuses in the programming session                                     */
   PROG_BOOT_LOCKED                                = 0x01u,
   PROG_BOOT_UNLOCKED                              = 0x02u,
   PROG_BOOT_FINGERPRINT_WRITTEN                   = 0x03u,
   PROG_BOOT_MEMORY_ERASED                         = 0x04u,
   PROG_BOOT_DOWNLOAD_STARTED                      = 0x05u,
   PROG_BOOT_TRANSFER_DATA                         = 0x06u,
   PROG_BOOT_DOWNLOAD_FINISHED                     = 0x07u,
   PROG_BOOT_MEMORY_CHECKED                        = 0x08u,
   PROG_BOOT_PROGRAM_DEPEND_CHECKED                = 0x09u,

   PROG_BOOT_MEMORY_ERASE_FAILED                   = 0x44u,
   PROG_BOOT_TRANSFER_DATA_FAILED                  = 0x46u,
   PROG_BOOT_MEMORY_CHECK_FAILED                   = 0x48u,
   PROG_BOOT_PROGRAM_DEPEND_CHECK_FAILED           = 0x49u,
   /* else session status                                                     */
   ELSE_SUB_SESSION_STATE                          = 0xFFu
} SubSessionType;

/* The following enum type contains the dependenciescheck possible values     */
typedef enum
{
   DEPCHECKRESERVEDVALUE00 = 0x00u,   /* this is a reserved value             */
   DEPCHECKCORRECTRESULT   = 0x01u,   /* Programming dependencies ok          */
   DEPCHECKINCORRECTRESULT = 0x02u,   /* At least one the SWE does not        */
                                      /* have a programming status of         */
                                      /* 'check-signature-ok' or programming  */
                                      /* dependencies check hasn't passed     */
   DEPCHECKHWESWE_ERROR    = 0x03u,   /* SWE and HWE clashed                  */
   DEPCHECKSWESWE_ERROR    = 0x04u,   /* two SWEs clashed                     */
   DEPCHECKRESERVEDVALUEFF = 0xFFu    /* this is a reserved value             */
} depCheckValueType;

/* the following enum type contains the process classes                       */
typedef enum
{
   PROCESSCLASS_INVALID2                           = 0x00u,
   PROCESSCLASS_HWEL                               = 0x01u,
   PROCESSCLASS_HWAP                               = 0x02u,
   PROCESSCLASS_HWFR                               = 0x03u,
   PROCESSCLASS_CAFD                               = 0x05u,
   PROCESSCLASS_BTLD                               = 0x06u,
   PROCESSCLASS_FLSL                               = 0x07u,
   PROCESSCLASS_SWFL                               = 0x08u,
   PROCESSCLASS_SWFF                               = 0x09u,
   PROCESSCLASS_SWPF                               = 0x0Au,
   PROCESSCLASS_ONPS                               = 0x0Bu,
   PROCESSCLASS_IBAD                               = 0x0Cu,
   PROCESSCLASS_FAFP                               = 0x0Fu,
   PROCESSCLASS_FCFA                               = 0x10u,
   PROCESSCLASS_TLRT                               = 0x1Au,
   PROCESSCLASS_TPRG                               = 0x1Bu,
   PROCESSCLASS_ENTD                               = 0xA0u,
   PROCESSCLASS_NAVD                               = 0xA1u,
   PROCESSCLASS_FCFN                               = 0xA2u,
   PROCESSCLASS_INVALID                            = 0xFFu
} ProcessClassType;

/* The following enum type describes the status of each SWE                   */
typedef enum
{
   PROGSTAT_SWENOTFOUND                            = 0x01u,
   PROGSTAT_ERASEMEMORYSTARTED                     = 0x02u,
   PROGSTAT_MEMORYSUCCESSFULLYERASED               = 0x07u,
   PROGSTAT_DATATRANSFERSTARTED                    = 0x03u,
   PROGSTAT_CHECKSIGNATURESTARTED                  = 0x04u,
   PROGSTAT_CHECKSIGNATUREOK                       = 0x05u,
   PROGSTAT_CHECKSIGNATURENOK                      = 0x06u
} SWEProgrammingStatusType;

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
   VEHICLE_ELECTRICAL_SYSTEMVOLTAGE_TOOL_OW        = 0x0Au,
   TEMPERATURE_TOO_HIGH                            = 0x0Bu,
   TEMPERATURE_TOO_LOW                             = 0x0Cu
   /* 14 ... 127 HIS reserved, 128 ... 255 system supplier reserved           */
} ProgrammingPreConditionType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CDC_START_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

   extern VAR(Cdc_NvDataType, CDC_VAR_PUBLIC) Cdc_NvData;

#define CDC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include <MemMap.h>

#define CDC_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

   extern CONST(Cdc_NvDataType, CDC_VAR_NVCONST) Cdc_NvDataDefault;

#define CDC_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define CDC_START_SEC_CODE
#include <MemMap.h>

   extern FUNC(void, CDC_CODE) Cdc_Init(void);

#define CDC_STOP_SEC_CODE
#include <MemMap.h>


#endif  /* CDC_H                                                              */

/*** End of file **************************************************************/
