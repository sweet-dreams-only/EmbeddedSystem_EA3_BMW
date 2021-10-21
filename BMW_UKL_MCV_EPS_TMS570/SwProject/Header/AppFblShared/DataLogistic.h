/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DataLogistic.h                                                **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Data structure table of bootloader and each SWE               **
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
** miwe         Michael Weger              EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** mm           Miroslaw Missalla          EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
** ke           Kai Esbold                 EB Automotive                      **
** dare         Daniel Reiss               EB Automotive                      **
** masc         Marko Schneider            EB Automotive                      **
** gema         Markus Gerngross           MB-technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V5.1.1: 03.09.2009, gema: CR61763: BAC Switch implemented
 * V5.1.0: 15.08.2008, masc: CR61431: added CRC-check for SWEs
 * V5.0.0: 23.10.2006, dare: added compiler abstraction
 *         21.09.2006, olgo: CR60738: SWEDevelopmentInfoField is 255 byte
 *         29.08.2006, miwe: adaptions according to LH FP v07:
 *                           - ReadDataById(EcuManufacturingData) is now
 *                             mandatory: removed pre processor switches
 *                           - renamed 'SWE_VALID' to 'VALID_FLAG_SWE_VALID'
 *         22.08.2006, olgo: formatted
 *         23.06.2006, miwe: 'HwDescData' is linked near to save ROM
 *                           during the frequent access in 'diag' and 'bootdiag'
 * V4.0.0: 05.04.2006, hauf: renamed section definitions
 *                           according to BMW programming guidelines
 *         17.03.2006, hauf: include diag.h
 *         10.03.2006, miwe: MISRA checked
 *         06.02.2006, miwe: Bootloader adaptions according to LH FP v05:
 *                           + handling of (SWE_DEV_INFO_LENGTH == 0u) adapted
 *                     olgo: + Swe(x)ProgDepData added
 *                     ke  : + replaced setpragma.h with MemMap.h
 *         02.02.2006, dabu: CR60419: added hardware description data with the
 *                                    ECU serial number
 *                           moved HWE Sgbm Id / HardwareLogisticData into the
 *                           hardware description data
 * V3.3.0: 20.12.2005, mm  : Fingerprint length adapted
 * V3.2.1: 31.10.2005, miwe: MISRA warnings removed
 * V3.2.0: 27.10.2005, miwe: type of 'SweSignature' altered,
 *                           'FINGERPRINTLENGTH' changed
 * V3.01 : 29.09.2005, olgo: prototypes for SWE(x)ValidFlagData added
 * V3.00 : 05.07.2005, miwe: CR60047: HWE Sgbm Id(s) implemented,
 *                           'SWECLASSIFICATIONLENGTH' adapted according to spec
 * V2.01 : 30.06.2005, miwe: 'SweDevInfo' added to SweTableType
 * V2.00 : 27.06.2005, hauf: renamed 'application_mcfg.h' to 'Application_Cfg.h'
 *                           renamed 'bootloader_mcfg.h' to 'Bootloader_Cfg.h'
 *                           renamed 'Tsvk' to 'SvkType'
 *                           renamed 'TSweTable' to 'SweTableType'
 *                           renamed 'TsgbmId' to 'SgbmIdType'
 * V1.01 : 23.06.2005, miwe: Changed 'SWECLASSIFICATIONLENGTH' from 2 to 1 byte
 * V1.00 : 15.06.2005, miwe: Merge of 'BootDataLogistic.h' and
 *                           'ApplDataLogistic.h'
 */

/**************************************************************************************************************************
 * Nxtr Version Control:
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
10/05/16     EA3#5     ABS        Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
**************************************************************************************************************************/



#ifndef DATALOGISTIC_H
#define DATALOGISTIC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Bootloader_Cfg.h"      /* swe address mapping initialisation data   */
#include "Crypto_Cfg.h"          /* include crypto method                     */

/* --- Switch between BAC / SC6 dependent include files ----------------------*/
#ifdef BAC
   #include <Std_Types.h>           /* AUTOSAR Standard Types                    */
#else
   #include "sc_types_arch.h"       /* Defines the data types                    */
   #include "sc_target_arch.h"      /* Defines some architecture specific        */
                                 /* parameters e.g. 'SC_MEMCPY'               */
   #include "Application_Cfg.h"     /* signature check specific defines          */
   #include "diag_types.h"          /* defines types used by diagnostic          */
#endif /* defined BAC                                                         */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* --- configuration of signature data -------------------------------------- */

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 09/30/2016
 * Description: Updated the SIGNATURE_LENGTH to (64 + 1 long length = 65) because of signature size
 *              update from 1024-bit to 2048-bit
 *              Updated the SIGNATURE_ITEM_SIZE because of 64/8 = 8byte
 */
 #if 0
/* Original code - START */
#if defined (CRYPTO_SIG_ASYM)
   #define SIGNATURE_LENGTH           33u                    /* ... in uint32 */
   #define SIGNATURE_ITEM_SIZE         4u
#elif defined (CRYPTO_SIG_SYM)
   #define SIGNATURE_LENGTH           16u                    /* ... in uint8  */
   #define SIGNATURE_ITEM_SIZE         1u
#else
   #error "DataLogistic.h: No crypto method defined. Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'"
#endif
/* Original code - END */
#endif

/* Patch code  - START */
#if defined (CRYPTO_SIG_ASYM)
   #define SIGNATURE_LENGTH           65u                    /* ... in uint32 */
   #define SIGNATURE_ITEM_SIZE         8u
#elif defined (CRYPTO_SIG_SYM)
   #define SIGNATURE_LENGTH           16u                    /* ... in uint8  */
   #define SIGNATURE_ITEM_SIZE         1u
#else
   #error "DataLogistic.h: No crypto method defined. Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'"
#endif
/* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/


#define SIGNATURE_SIZE                (SIGNATURE_LENGTH * SIGNATURE_ITEM_SIZE)

#define VALID_FLAG_SWE_VALID          0x5A5Au
#define VALID_FLAG_SWE_NOT_VALID      0x0000u   /*
                                                 * Values of valid 'SWEValidFlag'
                                                 */

#define FINGERPRINTLENGTH             13u       /* Len of Fingerprint         */
#define FINGERPRINTLENGTH_SHORT       4u        /* Len of short Fingerprint   */

#define DIAG_SVK_VERSION              0x01u     /*
                                                 * Svk version used during diag
                                                 * and stored in bootloader
                                                 * flash
                                                 */

#define ECUMANUFACTURINGDATALENGTH    0x03u     /*
                                                 * length of
                                                 * 'ECUManufacturingData'
                                                 */

#define RANDOMLENGTH             16u    /* Length of BootProgData component   */
                                        /* RANDOM: seed for calculating a     */
                                        /* random number for the              */
                                        /* authentication in byte.            */

#define VINLENGTH                17u    /* Length of the VIN number           */

#define MAX_XWE_DEV_INFO_LENGTH  256u   /* Length of the SWE development info */
                                        /* field by LH FP                     */

/* check user configurations                                                  */
#if (SWE_DEV_INFO_LENGTH >= MAX_XWE_DEV_INFO_LENGTH)
   #error "DataLogistic.h: 'SWE_DEV_INFO_LENGTH' to long. The maximum is 255 Byte"
#endif

#if (HWEDEVELOPMENTINFOLENGTH >= MAX_XWE_DEV_INFO_LENGTH)
   #error "DataLogistic.h: 'HWEDEVELOPMENTINFOLENGTH' to long. The maximum is 255 Byte"
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* ---------------------------------------------------------------------------*/
/*          SGBM-ID (Steuergeraete-Beschreibungsmodell-Identifier)            */
/* -------------------------------------------------------------------------- */
#define SWECLASSIFICATIONLENGTH           1u
#define SWELOGISTICIDENTIFIERLENGTH       4u
#define SWESOFTWAREVERSIONLENGTH          3u

#define SGBM_ID_LENGTH ( SWECLASSIFICATIONLENGTH +                             \
                         SWELOGISTICIDENTIFIERLENGTH +                         \
                         SWESOFTWAREVERSIONLENGTH                              \
                       )

#if (((SGBM_ID_LENGTH) % 4u) != 0u)
 #error "DataLogistic.h: ((SGBM_ID_LENGTH) % 4u) != 0u"
#endif

/* ---------------------------------------------------------------------------*/
/*                              HWE table                                     */
/* -------------------------------------------------------------------------- */
/* Define data type 'HweTableType' for HWE Table.                             */
typedef struct
{
   /* --- logistic data ----------------------------------------------------- */
   uint8 HWESgbmId[SGBM_ID_LENGTH];

   /* --- HWE development Information --------------------------------------- */
#if (HWEDEVELOPMENTINFOLENGTH > 0u)
   uint8 HWEDevelopmentInfo[HWEDEVELOPMENTINFOLENGTH + 0x01u];
                                             /* ... plus one Byte length info */
#endif
} HweTableType;


/* ---------------------------------------------------------------------------*/
/*          Hardware Description Data                                         */
/* -------------------------------------------------------------------------- */

/* Define data type 'HwDescDataType' for the Hardware Description Data        */
typedef struct
{
   /* HardwareLogisticData                                                    */
   HweTableType HweTable[NUMBEROFHWESGBMIDS];
   /* ECUSerialNumber                                                         */
   uint8 ECUSerialNumber[ECUSERIALNUMBERLENGTH];
   /* ECUManufacturingData                                                    */
   uint8 ECUManufacturingData[ECUMANUFACTURINGDATALENGTH];
} HwDescDataType;

#define SVK_BACKUP_SIZE ( 4u + FINGERPRINTLENGTH + (SGBM_ID_LENGTH *           \
                          (NUMBEROFHWESGBMIDS + SWENUMBEROFALLSWE))            \
                        )


/* ---------------------------------------------------------------------------*/
/*                              SWE table                                     */
/* -------------------------------------------------------------------------- */

/* Define data type 'SweTableType' for SWE Table.                             */
typedef struct
{
   /* --- logistic data ----------------------------------------------------- */
   uint8 SgbmId[SGBM_ID_LENGTH];

   /* --- signature of the SWE ---------------------------------------------- */
#if defined (CRYPTO_SIG_ASYM)
   uint32 SweSignature[SIGNATURE_LENGTH];
#elif defined (CRYPTO_SIG_SYM)
   uint8  SweSignature[SIGNATURE_LENGTH];
#else
 #error "DataLogistic.h: No crypto method defined. Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'."
#endif

   /* --- SWE development Information --------------------------------------- */
   uint8 SweDevInfo[MAX_XWE_DEV_INFO_LENGTH];
} SweTableType;


/* ---------------------------------------------------------------------------*/
/*                              SWE Flash Status                              */
/* -------------------------------------------------------------------------- */

typedef struct
{
   /* CRC of valid-flag flash segment                                         */
   uint8 SweCrcCheckSum[SWE_CRC_CHECKSUM_AREA_LENGTH];
   /* SWE valid-flag                                                          */
   uint8 SweValidFlag[SWE_VALID_FLAG_AREA_LENGTH];
   /* SWE programming dependencies flag                                       */
   uint8 ProgDepFlag[PROG_DEP_AREA_LENGTH];
} SweFlashStatusType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* -------------------------------------------------------------------------- */
/* extern declaration of Boot.-SWE table                                      */
#define BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   extern CONST(SweTableType, COMMON_CONST) SweBootTable;
#else
   extern const SweTableType SweBootTable;
#endif /* Defined BAC */
#define BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
#include "MemMap.h"
/* -------------------------------------------------------------------------- */
/* extern declaration of Appl.-SWE1 table                                     */
#define APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   extern CONST(SweTableType, COMMON_CONST) Swe1Table;
#else
   extern const SweTableType Swe1Table;
#endif /* Defined BAC */
#define APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
#include "MemMap.h"
/* -------------------------------------------------------------------------- */
/* extern declaration of Cal1.-SWE2 table                                     */
#define APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   extern CONST(SweTableType, COMMON_CONST) Swe2Table;
#else
   extern const SweTableType Swe2Table;
#endif /* Defined BAC */
#define APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
#include "MemMap.h"
/* -------------------------------------------------------------------------- */
/* extern declaration of Cal2.-SWE3 table                                     */
#define APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   extern CONST(SweTableType, COMMON_CONST) Swe3Table;
#else
   extern const SweTableType Swe3Table;
#endif /* Defined BAC */
#define APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
#include "MemMap.h"
/* -------------------------------------------------------------------------- */
/* extern declaration of Boot.-SWE flash status                               */
#define BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
#include "MemMap.h"
#ifdef BAC
   extern CONST(SweFlashStatusType, COMMON_CONST) BootFlashStatus;
#else
   extern const SweFlashStatusType BootFlashStatus;
#endif /* Defined BAC */
#define BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS
#include "MemMap.h"
/* -------------------------------------------------------------------------- */
/* extern declaration of Appl.-SWE1 flash status                              */
#define APPL_START_SEC_CONST_SWE1_FLASH_STATUS
#include "MemMap.h"
#ifdef BAC
   extern CONST(SweFlashStatusType, COMMON_CONST) Swe1FlashStatus;
#else
   extern const SweFlashStatusType Swe1FlashStatus;
#endif /* Defined BAC */
#define APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
#include "MemMap.h"
/* -------------------------------------------------------------------------- */
/* extern declaration of Cal.-SWE2 flash status                              */
#define APPL_START_SEC_CONST_SWE2_FLASH_STATUS
#include "MemMap.h"
#ifdef BAC
   extern CONST(SweFlashStatusType, COMMON_CONST) Swe2FlashStatus;
#else
   extern const SweFlashStatusType Swe2FlashStatus;
#endif /* Defined BAC */
#define APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
#include "MemMap.h"
/* -------------------------------------------------------------------------- */
/* extern declaration of Cal.-SWE3 flash status                              */
#define APPL_START_SEC_CONST_SWE3_FLASH_STATUS
#include "MemMap.h"
#ifdef BAC
   extern CONST(SweFlashStatusType, COMMON_CONST) Swe3FlashStatus;
#else
   extern const SweFlashStatusType Swe3FlashStatus;
#endif /* Defined BAC */
#define APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
#include "MemMap.h"
/* -------------------------------------------------------------------------- */
/* extern declaration of hardware description data                            */
#define BM_START_SEC_CONST_HW_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   extern CONST(HwDescDataType, COMMON_CONST) HwDescData;
#else
   extern const HwDescDataType HwDescData;
#endif /* Defined BAC */
#define BM_STOP_SEC_CONST_HW_DESCRIPTION_TABLE
#include "MemMap.h"
/* -------------------------------------------------------------------------- */

#endif  /* DATALOGISTIC_H                                                     */

/*** End of file **************************************************************/
