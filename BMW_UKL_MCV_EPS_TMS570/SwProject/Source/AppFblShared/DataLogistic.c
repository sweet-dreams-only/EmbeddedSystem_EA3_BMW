/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DataLogistic.c                                                **
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
** olgo         Oliver Gorisch             EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
** ke           Kai Esbold                 EB Automotive                      **
** hauf         Andreas Hauf               EB Automotive                      **
** dare         Daniel Reiss               EB Automotive                      **
** masc         Marko Schneider            EB Automotive                      **
** gema         Markus Gerngross           MB-Technologie                     **
** ft           Florian Tausch             MB Technology                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V4.1.4: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V4.1.3: 17.12.2010,   ft: removed comments and unnecessary lines of code
 * V4.1.2: 12.11.2010,   ft: CR70748: added missing compiler abstraction
 * V4.1.1: 03.09.2009, gema: CR61763: BAC Switch implemented
 * V4.1.0: 15.08.2008, masc: CR61431: added CRC-check for SWEs
 * V4.0.0: 23.10.2006, dare: added compiler abstraction
 *         29.08.2006, miwe: adaptions according to LH FP v07:
 *                           - ReadDataById(EcuManufacturingData) is now
 *                             mandatory: removed pre processor switches
 *         23.06.2006, miwe: 'HwDescData' is linked near to save ROM
 *                           during the frequent access in 'diag' and 'bootdiag'
 * V3.0.0: 05.05.2006, miwe: RT2989: changed comment
 *         05.04.2006, hauf: renamed section definitions
 *                           according to BMW programming guidelines
 *         27.02.2006, ke  : replace setpragma.h with MemMap.h
 *         07.02.2006, dabu: Bootloader adaptions according to LH FP v05:
 *                           + added sgbm-infos for additional process class
 *                           + changed process class definitions from sc_types.h
 *                     miwe: + handling of (SWE_DEV_INFO_LENGTH == 0u) adapted
 *                     olgo: + Swe(x)ProgDepData added
 *         02.02.2006, dabu: CR60419: added hardware description data with the
 *                                    ECU serial number
 *                           moved HWE Sgbm Id / HardwareLogisticData into the
 *                           hardware description data
 * V2.1.1: 01.12.2005, miwe: CR60215: removed compiler warnings
 * V2.01 : 29.09.2005, olog: SWE(x)ValidFlagData added
 * V2.00 : 05.07.2005, miwe: CR60047: HWE Sgbm Id(s) implemented
 * V1.00 : 15.06.2005, miwe: Merge of 'BootDataLogistic.c' and
 *                           'ApplDataLogistic.c'
 *
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "DataLogistic.h"                           /* module own header file */

/* --- Switch between BAC / SC6 dependent include files ----------------------*/
#ifdef BAC

#include <Std_Types.h>           /* AUTOSAR Standard Types                    */
#include "DataLogistic.h"        /* module own header file                    */
#include "Bootloader_Cfg.h"      /* swe address mapping initialisation data   */
#ifdef APPLICATION
   #include "Cdc.h"              /* defines types used by diagnostic          */
#else
   #include "diag_types.h"       /* defines types used by diagnostic          */
#endif

#endif /* defined BAC                                                         */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/* -------------------------------------------------------------------------- */
/*                      Boot.-SWE                                             */
/* -------------------------------------------------------------------------- */
#define BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
#include "MemMap.h"

#ifdef BAC
   CONST(SweTableType, COMMON_CONST) SweBootTable =
#else
   const SweTableType SweBootTable =
#endif /* Defined BAC */
{
   {  /* logistic data                                                        */
      BOOTSWECLASSIFICATIONDATA,
      BOOTLOGISTICIDENTIFIERDATA,
      BOOTSWESOFTWAREVERSIONDATA
   },
   {0}, /* signature                                                          */
#if (SWE_DEV_INFO_LENGTH > 0u)
   {BOOTSWEDEVINFO}
#else
   {0}
#endif
};

#define BL_STOP_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
#include "MemMap.h"

/* Boot flash status                                                          */
#define BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
#include "MemMap.h"
#ifdef BAC
   CONST(SweFlashStatusType, COMMON_CONST) BootFlashStatus = {
#else
   const SweFlashStatusType BootFlashStatus = {
#endif /* Defined BAC */
                                                     { SWE_CRC_CHECKSUM_DATA },
                                                     { SWE_VALID_FLAG_DATA },
                                                     { PROG_DEP_DATA }
                                              };
#define BL_STOP_SEC_CONST_BOOTSWE_FLASH_STATUS
#include "MemMap.h"


/* -------------------------------------------------------------------------- */
/*                      Appl.-SWE 1                                           */
/* -------------------------------------------------------------------------- */

/* SWE1 table                                                                 */
#define APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   CONST(SweTableType, COMMON_CONST) Swe1Table =
#else
   const SweTableType Swe1Table =
#endif /* Defined BAC */
{
   {  /* logistic data                                                        */
      SWE1SWECLASSIFICATIONDATA,
      SWE1LOGISTICIDENTIFIERDATA,
      SWE1SWESOFTWAREVERSIONDATA
   },
   {0}, /* signature                                                          */
#if (SWE_DEV_INFO_LENGTH > 0u)
   {SWE1SWEDEVINFO}
#else
   {0}
#endif
};

#define APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
#include "MemMap.h"

/* SWE1 flash status                                                          */
#define APPL_START_SEC_CONST_SWE1_FLASH_STATUS
#include "MemMap.h"
#ifdef BAC
   CONST(SweFlashStatusType, COMMON_CONST) Swe1FlashStatus =
#else
   const SweFlashStatusType Swe1FlashStatus =
#endif /* Defined BAC */
                                              {
                                                     { SWE_CRC_CHECKSUM_DATA },
                                                     { SWE_VALID_FLAG_DATA },
                                                     { PROG_DEP_DATA }
                                              };
#define APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
#include "MemMap.h"


/* -------------------------------------------------------------------------- */
/*                      Cal1.-SWE 2                                           */
/* -------------------------------------------------------------------------- */

/* SWE2 table                                                                 */
#define APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   CONST(SweTableType, COMMON_CONST) Swe2Table =
#else
   const SweTableType Swe2Table =
#endif /* Defined BAC */
{
   {  /* logistic data                                                        */
      SWE2SWECLASSIFICATIONDATA,
      SWE2LOGISTICIDENTIFIERDATA,
      SWE2SWESOFTWAREVERSIONDATA
   },
   {0}, /* signature                                                          */
#if (SWE_DEV_INFO_LENGTH > 0u)
   {SWE2SWEDEVINFO}
#else
   {0}
#endif
};

#define APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
#include "MemMap.h"

/* SWE1 flash status                                                          */
#define APPL_START_SEC_CONST_SWE2_FLASH_STATUS
#include "MemMap.h"
#ifdef BAC
   CONST(SweFlashStatusType, COMMON_CONST) Swe2FlashStatus =
#else
   const SweFlashStatusType Swe2FlashStatus =
#endif /* Defined BAC */
                                              {
                                                     { SWE_CRC_CHECKSUM_DATA },
                                                     { SWE_VALID_FLAG_DATA },
                                                     { PROG_DEP_DATA }
                                              };
#define APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
#include "MemMap.h"


/* -------------------------------------------------------------------------- */
/*                      Cal2.-SWE 3                                           */
/* -------------------------------------------------------------------------- */

/* SWE3 table                                                                 */
#define APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   CONST(SweTableType, COMMON_CONST) Swe3Table =
#else
   const SweTableType Swe3Table =
#endif /* Defined BAC */
{
   {  /* logistic data                                                        */
      SWE3SWECLASSIFICATIONDATA,
      SWE3LOGISTICIDENTIFIERDATA,
      SWE3SWESOFTWAREVERSIONDATA
   },
   {0}, /* signature                                                          */
#if (SWE_DEV_INFO_LENGTH > 0u)
   {SWE3SWEDEVINFO}
#else
   {0}
#endif
};

#define APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
#include "MemMap.h"

/* SWE1 flash status                                                          */
#define APPL_START_SEC_CONST_SWE3_FLASH_STATUS
#include "MemMap.h"
#ifdef BAC
   CONST(SweFlashStatusType, COMMON_CONST) Swe3FlashStatus =
#else
   const SweFlashStatusType Swe3FlashStatus =
#endif /* Defined BAC */
                                              {
                                                     { SWE_CRC_CHECKSUM_DATA },
                                                     { SWE_VALID_FLAG_DATA },
                                                     { PROG_DEP_DATA }
                                              };
#define APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
#include "MemMap.h"





/* -------------------------------------------------------------------------- */
/*                      Hardware Description Data                             */
/* -------------------------------------------------------------------------- */

#define BM_START_SEC_CONST_HW_DESCRIPTION_TABLE
#include "MemMap.h"
#ifdef BAC
   CONST(HwDescDataType, COMMON_CONST) HwDescData =
#else
   const HwDescDataType HwDescData =
#endif /* Defined BAC */
{
   /* HWE Sgbm Id = HardwareLogisticData                                      */
   {
      {
         {  /* logistic data - HWEL: Hardware Electronic                      */
            HWE1CLASSIFICATIONDATA,
            HWE1LOGISTICIDENTIFIERDATA,
            HWE1VERSIONDATA
         }
#if (HWEDEVELOPMENTINFOLENGTH > 0u)
         /* HWEDevelopmentInfo                                                */
         ,{HWE1DEVELOPMENTINFO}
#endif
      }

   },
   /* ECUSerialNumber                                                         */
   {ECUSERIALNUMBER},
   /* ECUManufacturingData                                                    */
   {ECUMANUFACTURINGDATA}
};

#define BM_STOP_SEC_CONST_HW_DESCRIPTION_TABLE
#include "MemMap.h"

/*** End of file **************************************************************/
