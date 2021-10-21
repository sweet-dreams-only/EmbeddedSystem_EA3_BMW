/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Bootloader_Cfg.h                                              **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : MPC55xx                                                       **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive, MB Technology                                  **
**                                                                            **
**  PURPOSE   : Modular make environment. Contains configuration parameters   **
**              which are dedicated to the bootloader.                        **
**              Therefore they are not defined in file 'StandardCore_Cfg.h'.  **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
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
** anht         Andreas Hartmann           EB Automotive                      **
** masc         Marko Schneider            EB Automotive                      **
** gusc         Guenter Schwarz            MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.1: 08.04.2009, gusc: CR70091: Reverted changes of ECU-ID and
 *                                    manufacturing data
 * V1.1.0: 15.08.2008, masc: CR61431: added CRC-check for SWEs
 *         05.06.2008, anht: CR61336: moved Flash timing parameters from
 *                                    bootloader_cfg.h to the derivative
 *                                    specific bootloader_cfg_xxx.h
 * V1.0.2: 14.11.2008, gusc: changed settings for ECU-ID and manufacturing data
 *                           ECU-ID: 9999999999, Date: 30.02.2001
 *                           for avoiding failures in flash test
 * V1.0.1: 14.12.2007, miwe: increased RESETTIME provisional to prevent timeouts
 *                           during NvM-Write all
 * V1.0.0: 24.09.2007, miwe: ported from SC6.7.2 file version V8.1.1
 */


/*************************************************************************************************************************
 * Version Control:
 * Date Created:      Wed Oct 19 12:16:01 2011
 * %version:          EA3#43 %
 * %derived_by:       pzswj8 %
 * %date_modified:    Thu Oct 20 10:20:06 2011 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 10/20/11   31        BDO        Update Bootloader Sgbm Id to $00001891 
 * 11/08/11   32        BG         Updated SGBMID to 0x1A6A for 1024 bit hotkeys
 * 10/05/16   EA3#43    ABS		   Authentication and Signature changes - 2048bit key and SHA256 hash		    EA3#7986

*************************************************************************************************************************/


#ifndef BOOTLOADER_CFG_H
#define BOOTLOADER_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types */

/* Include derivative specific bootloader config headers                      */
#include "Bootloader_Cfg_HW.h"


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* -------------------------------------------------------------------------- */
/*                     SWE status specific defines                            */
/* -------------------------------------------------------------------------- */


/*
 * Length of the SWE CRC checksum area. It must have a correct size for HIS
 * flash driver
 */
#define SWE_CRC_CHECKSUM_AREA_LENGTH      0x10u
/* SWE CRC checksum data. It must have size of 'SWE_CRC_CHECKSUM_AREA_LENGTH' */
#define SWE_CRC_CHECKSUM_DATA                                                  \
   (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,                     \
   (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,                     \
   (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,                     \
   (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u

/*
 * Length of the SWE valid flag area. It must have a correct size for HIS flash
 * driver
 */
#define SWE_VALID_FLAG_AREA_LENGTH 0x10u
/* SWE valid flag data. It must have size of 'SWE_VALID_FLAG_AREA_LENGTH'     */
#define SWE_VALID_FLAG_DATA                                                    \
       (uint8)0x5Au, (uint8)0x5Au, (uint8)0x00u, (uint8)0x00u,                 \
       (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,                 \
       (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,                 \
       (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u

/*
 * Length of the programming dependencies flag area. It must have a correct
 * size for his flash driver
 */
#define PROG_DEP_AREA_LENGTH 0x10u
/* Programming dependencies data. It must have size of 'PROG_DEP_AREA_LENGTH' */
#define PROG_DEP_DATA                                                          \
       (uint8)0x01u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,                 \
       (uint8)0x01u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,                 \
       (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u,                 \
       (uint8)0x00u, (uint8)0x00u, (uint8)0x00u, (uint8)0x00u

/*
 * Length of the whole SWE flash status area
 */
#define SWE_FLASH_STATUS_AREA_LENGTH                                           \
   ( SWE_CRC_CHECKSUM_AREA_LENGTH +                                            \
     SWE_VALID_FLAG_AREA_LENGTH   +                                            \
     PROG_DEP_AREA_LENGTH                                                      \
   )

/* -------------------------------------------------------------------------- */
/*                     ProgrammingCounter specific defines                    */
/* -------------------------------------------------------------------------- */

/*
 * Maximum number of ECU flash reprogramming attempts according to the system
 * supplier
 */
#define PROGRAMMING_COUNTER_MAX_VALUE     0x0400u

/*
 * This defines the value which indicates erased flash memory. This is usually
 * 0xFF, however on Tricore it is 0x00.
 */
#define FLASH_ERASED_BYTE                 0xFFu


/* -------------------------------------------------------------------------- */
/*                          Data Logistic                                     */
/* -------------------------------------------------------------------------- */

/*
 * Length of the SWE development info field:
 * This value must be the max. length of every xxxSWEDEVINFO constant defined
 * below. The xxxSWEDEVINFO constants can have different lengths - in this case
 * the first byte of xxxSWEDEVINFO should not be set to SWE_DEV_INFO_LENGTH -
 * the real length should used instead.
 * A length of '0u' can be used to disable this feature.
 * The SWEDevelopmentInfo initialized here can be overwritten by the SWE-
 * Generator tool with every length from 0u bis 255u independed from the
 * length that is configured with 'SWE_DEV_INFO_LENGTH'
 */
#define SWE_DEV_INFO_LENGTH               14u


/* -------------------------------------------------------------------------- */
/*                 initialisation data of Boot.-SWE1 Sgbm Id                  */
/* -------------------------------------------------------------------------- */
/* BTLD: Bootloader                                                           */
#define BOOTSWECLASSIFICATIONDATA   PROCESSCLASS_BTLD 
#define BOOTLOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x1Au, (uint8)0x6Au
#define BOOTSWESOFTWAREVERSIONDATA  (uint8)0x02u, (uint8)0x00u, (uint8)0x0Au
#if (SWE_DEV_INFO_LENGTH > 0u)
   #define BOOTSWEDEVINFO           ((uint8)(SWE_DEV_INFO_LENGTH)),            \
                                       'B','O','O','T','S','W','E','D','E','V','I','N','F','O'
#endif

/* -------------------------------------------------------------------------- */
/*                 initialisation data of Appl.-SWE1 Sgbm Id                  */
/* -------------------------------------------------------------------------- */
/* SWFL: Software ECU memory image                                            */
#define SWE1SWECLASSIFICATIONDATA   PROCESSCLASS_SWFL
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Description: Updated the SWE1 SGBMID according to pdx template PT01_template.003_000_191.pdx
 *              with 2048-bit key and SHA-256 hash algorithm
 */
#if 0
/* Original code - START */
#define SWE1LOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x18u, (uint8)0x92u
/* Original code - END */
#endif
/* Patch code  - START */
#define SWE1LOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x50u, (uint8)0x8Bu
/* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/
#define SWE1SWESOFTWAREVERSIONDATA  (uint8)0x02u, (uint8)0x01u, (uint8)0x0Fu
#if (SWE_DEV_INFO_LENGTH > 0u)
   #define SWE1SWEDEVINFO           ((uint8)(SWE_DEV_INFO_LENGTH)),            \
                                       'S','W','E','1','S','W','E','D','E','V','I','N','F','O'
#endif

/* -------------------------------------------------------------------------- */
/*                 initialisation data of Cal.-SWE2 Sgbm Id                  */
/* -------------------------------------------------------------------------- */
/* SWFL: Software ECU memory image                                            */
#define SWE2SWECLASSIFICATIONDATA   PROCESSCLASS_SWFL
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Description: Updated the SWE2 SGBMID according to pdx template PT01_template.003_000_191.pdx
 *              with 2048-bit key and SHA-256 hash algorithm
 */
#if 0
/* Original code - START */
#define SWE2LOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x18u, (uint8)0x93u
/* Original code - END */
#endif
/* Patch code  - START */
#define SWE2LOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x50u, (uint8)0x8Cu
/* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/
#define SWE2SWESOFTWAREVERSIONDATA  (uint8)0x02u, (uint8)0x01u, (uint8)0x0Fu
#if (SWE_DEV_INFO_LENGTH > 0u)
   #define SWE2SWEDEVINFO           ((uint8)(SWE_DEV_INFO_LENGTH)),            \
                                       'S','W','E','2','S','W','E','D','E','V','I','N','F','O'
#endif

/* -------------------------------------------------------------------------- */
/*                 initialisation data of Cal.-SWE3 Sgbm Id                  */
/* -------------------------------------------------------------------------- */
/* SWFL: Software ECU memory image                                            */
#define SWE3SWECLASSIFICATIONDATA   PROCESSCLASS_SWFL
/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Description: Updated the SWE3 SGBMID according to pdx template PT01_template.003_000_191.pdx
 *              with 2048-bit key and SHA-256 hash algorithm
 */
#if 0
/* Original code - START */
#define SWE3LOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x18u, (uint8)0x94u
/* Original code - END */
#endif
/* Patch code  - START */
#define SWE3LOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x50u, (uint8)0x8Du
/* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/
#define SWE3SWESOFTWAREVERSIONDATA  (uint8)0x02u, (uint8)0x01u, (uint8)0x0Fu
#if (SWE_DEV_INFO_LENGTH > 0u)
   #define SWE3SWEDEVINFO           ((uint8)(SWE_DEV_INFO_LENGTH)),            \
                                       'S','W','E','3','S','W','E','D','E','V','I','N','F','O'
#endif

/*
 * The number of Svk backups beside the system supplier and plan svk history.
 * Svk backups are not mandatory. Choose '0u' to disable this feature. Dont't
 * forget to update NvM configuration.
 * 0u <= NUMBEROFSVKBACKUPS <= 61u
 */
#define NUMBEROFSVKBACKUPS                0u

/* -------------------------------------------------------------------------- */
/*                    initialisation data of HWE Sgbm Id(s)                   */
/* -------------------------------------------------------------------------- */

/* number of HWE Sgbm Id(s)                                                   */
#define NUMBEROFHWESGBMIDS                2u
/*
 * Length of the HWE development info field:
 * The HardwareDevelopmentInfo CAN NOT be overwritten by the SWE-Generator tool.
 * The length that is configured here will be reserved in a protected ROM space
 * (in the BootManager). It is not designated that the size can be increased
 * during ECU livetime.
 */
#define HWEDEVELOPMENTINFOLENGTH          14u

/* structure of 8 byte Sgbm Id(s):
 *                         1 byte: process class
 *                         4 byte: id (BMW-wide unique)
 *                         3 byte: version number (1 byte per major,minor,patch)
 */
/* HWEL: Hardware Electronic                                                  */
#define HWE1CLASSIFICATIONDATA      PROCESSCLASS_HWEL
#define HWE1LOGISTICIDENTIFIERDATA  (uint8)0x00u, (uint8)0x00u, (uint8)0x12u, (uint8)0x39u
#define HWE1VERSIONDATA             (uint8)0x02u, (uint8)0x00u, (uint8)0x00u
/* HWEDevelopmentInfo */
#if (HWEDEVELOPMENTINFOLENGTH > 0u)
   #define HWE1DEVELOPMENTINFO      ((uint8)(HWEDEVELOPMENTINFOLENGTH)),       \
                                       'H','W','E','L','H','W','E','D','E','V','I','N','F','O'
#endif

#if 0 /* The following Sgbm-Ids are optional and commented out to save memory */
      /* Adaptions in 'DataLogistic.c' needed when enabled                    */
/* HWFR: Hardware Color (optional)                                            */
#define HWE2CLASSIFICATIONDATA      PROCESSCLASS_HWFR
#define HWE2LOGISTICIDENTIFIERDATA  (uint8)0xC0u, (uint8)0xFFu, (uint8)0xEEu, (uint8)0x00u
#define HWE2VERSIONDATA             (uint8)0xFFu, (uint8)0xFFu, (uint8)0xFFu           /* FP_4650 */
/* HWEDevelopmentInfo                                                         */
 #if (HWEDEVELOPMENTINFOLENGTH > 0u)
   #define HWE2DEVELOPMENTINFO      ((uint8)(HWEDEVELOPMENTINFOLENGTH)),       \
                                       'H','W','F','R','H','W','E','D','E','V','I','N','F','O'
 #endif
#endif
/* HWAP:Hardware Characteristic (optional)                                    */
#define HWE3CLASSIFICATIONDATA      PROCESSCLASS_HWAP
#define HWE3LOGISTICIDENTIFIERDATA  (uint8)0xCAu, (uint8)0xFEu, (uint8)0xC0u, (uint8)0xDEu
#define HWE3VERSIONDATA             (uint8)0xFFu, (uint8)0xFFu, (uint8)0xFFu           /* FP_4650 */
/* HWEDevelopmentInfo                                                         */
 #if (HWEDEVELOPMENTINFOLENGTH > 0u)
   #define HWE3DEVELOPMENTINFO      ((uint8)(HWEDEVELOPMENTINFOLENGTH)),       \
                                       'H','W','A','P','H','W','E','D','E','V','I','N','F','O'
 #endif



/* -------------------------------------------------------------------------- */
/*             initialisation data of hardware description data               */
/* -------------------------------------------------------------------------- */

/* length of the ECUSerialNumber                                              */
#define ECUSERIALNUMBERLENGTH       10u

/*
 * 10-bytes ECU-ID used by DIAG_DID_F18C_ECUID
 * used to read the system supplier ECU serial number.
 * If the ECU serial number requires less than 10-bytes:
 *    in case of hexadecimal serial number: fill up with leading 0x00
 *    in case of serial number with BCD-coding: fill up with leading 0x30
 */
#ifndef ECUSERIALNUMBER
#define ECUSERIALNUMBER             (uint8)0x39u, (uint8)0x39u, (uint8)0x39u,  \
                                    (uint8)0x39u, (uint8)0x39u, (uint8)0x39u,  \
                                    (uint8)0x39u, (uint8)0x39u, (uint8)0x39u,  \
                                    (uint8)0x39u
#endif /* ECUSERIALNUMBER */

/*
 * 3-bytes 'ECUManufacturingData' used by 'DIAG_DID_F18B_ECUMANUFACTURINGDATA'
 * used to read the system supplier ECU Manufacturing Data.
 * Value 1: Year  0x01 = 2001 ... 0x99 = 2099
 * Value 2: Month 0x01 = Jan. ... 0x12 = Dec.
 * Value 3: Day   0x01 = 01.  ... 0x31 = 31.
 * If ECU Manufacturing Data is not supported, set following default data:
 *    (uint8)0x00, (uint8)0x00, (uint8)0x00 or
 *    (uint8)0xFF, (uint8)0xFF, (uint8)0xFF
 */
#ifndef ECUMANUFACTURINGDATA
#define ECUMANUFACTURINGDATA        (uint8)0x09u, (uint8)0x12u, (uint8)0x17u
#endif  /* ECUMANUFACTURINGDATA */

#endif /* BOOTLOADER_CFG_H                                                    */

/*** End of file **************************************************************/
