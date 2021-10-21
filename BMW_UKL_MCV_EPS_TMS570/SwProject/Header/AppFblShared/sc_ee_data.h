/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_ee_data.h                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Header file dedicated to file 'sc_ee_data.c'.                 **
**              Implements the data type definition 'BootProgCounterType',    **
**              'BootProgDataType', 'BootProgStatusType' and                  **
**              'SvkHistoryMemory' and external definition of struct          **
**              'BootProgStatus', 'BootProgCounter', 'BootProgData',          **
**              'SvkHistoryMemory'                                            **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
**                                                                            ** 
**  DISCLAIMER:                                                               **
**  As the program is not fully tested and qualified for series production    **
**  use, the user shall not be entitled to use the program in connection      **
**  with any series production. BMW provides the user with the program only   **
**  as sample application (for testing purposes).                             **
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
** scma         Scheitterer Martin         MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
** anam         Andreas Amann              MB Technology                      **
** pego         Peter Golzem               R. Bader GmbH                      **
** mb           Martin Bader               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.2.2: 26.08.2011,   mb: CR70955: New global common for common files between templates
 * V1.2.1: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.2.1: 20.05.2011, anam: CR71056: SVK Read: Optimize RAM Usage 
 * V1.2.0: 07.09.2010,   ft: CR70748: added missing compiler abstraction
 * V1.2.0: 07.09.2010,   ft: CR70753: added missing compiler abstraction
 * V1.2.0: 07.09.2010,   ft: CR70747: added missing compiler abstraction
 * V1.1.1: 30.07.2009, scma: switch for SC6 diag added
 * V1.1.0: 02.09.2008, olgo: CR61431: separated bootloader and bootmanager
 * V1.1.0: 15.11.2007, miwe: NvM integration in Application:
 *                           + changed init block callback prototype
 *                           + added Vsm_NvData_Default block
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V9.0.0
 */
/*
#ifndef I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION
#error "the program must not be used in connection with series production"
#endif
*/
#ifndef SC_EE_DATA_H
#define SC_EE_DATA_H

#ifndef BOOTMANAGER
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>        /* AUTOSAR Standard Types                       */
#include "sc_types.h"         /* include StandardCore types                   */
#include "DataLogistic.h"     /* for FingerPrint length definition            */
#include "Bootloader_Cfg.h"   /* include Bootloader configuration             */
#ifdef BOOTLOADER
   #include "Vsm_Client.h"    /* VSM modul specific include                   */
   #include "Boot_Crypto.h"   /* Crypto routines                              */
#else
   #include "Appl_Crypto.h"   /* Crypto routines                              */
#endif


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * Macros needed to access the 'FlashSegmentStatus' bitfield
 */
#define FLASH_SEGMENT_STATUS_NOT_WRITABLE                                  0x00u
#define FLASH_SEGMENT_STATUS_WRITABLE                                      0x01u

#define REQUIRED_SIZE_FLASH_SEGMENT_STATUS                                     \
         CALC_REQUIRED_BYTES_FOR_MULTI_BYTE_BIT_ARRAY(FLASH_SEGMENT_NUMBER_APPL)


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* Types for ApplicStartedFirst flag                                          */
typedef enum
{
   ISFIRSTSTARTOFAPPLICATION     = 0x5Au,
   ISNOTFIRSTSTARTOFAPPLICATION  = 0x00u
} ApplicStartedFirstType;

/* Types for SvkLockedStatus flag                                             */
typedef enum
{
   SVKSTATUS_SYSSUPPANDPLANTUNLOCKED,
   SVKSTATUS_SYSSUPLOCKEDPLANTUNLOCKED,
   SVKSTATUS_SYSSUPPANDPLANTLOCKED
} SvkLockedStatusType;

typedef struct
{
   uint8 SvkLockedStatus;                          /* SysSupplier and Plant   */
                                                   /* entries can be locked   */
                                                   /* by this flag            */
   #if (NUMBEROFSVKBACKUPS > 0u)
      uint8 SvkBackupFIFOCounter;                  /* Svk Backup as FIFO      */
   #endif
   /* Nxtr Patch
    * Date: 3/19/15
    * Applied By: K. Smith
    * Reason: Removed #ifdef BOOTLOADER check and #endif. We are reading the SVKhistory
    * into RAM, and the size defined in NvM is larger then what is defined in RAM.
    */
   /* #ifdef BOOTLOADER */
   uint8 SvkSysSupp [SVK_BACKUP_SIZE];             /* system supplier SVK     */
   uint8 SvkPlant   [SVK_BACKUP_SIZE];             /* plant SVK               */
   #if (NUMBEROFSVKBACKUPS > 0u)                   /* Svk Backup as FIFO      */
      uint8 SvkBackup[NUMBEROFSVKBACKUPS][SVK_BACKUP_SIZE];
   #endif
   /* #endif */ /*BOOTLOADER*/
} SvkHistoryMemoryType;

/*
 * This type is used for organising bootloader information data in
 * non volatile memory
 * This type is used both by bootloader and application
 */

typedef struct
{
   uint16 ProgrammingCounter[SWENUMBEROFALLSWE];/* Current status of each SWE */
} BootProgCounterType;

typedef struct
{
#ifdef BOOTLOADER
   uint8     RANDOM      [RANDOMLENGTH];       /* Seed for the pseudo for SC6 */
#else
   CR_C_s2_t RANDOM;                           /* Seed for the pseudo         */
#endif
   uint8     ApplicStartedFirst;               /* Indication of first start   */
   uint8     FingerPrint [FINGERPRINTLENGTH];  /* FingerPrint                 */
   uint8     VIN         [VINLENGTH];          /* Vehicle Identification      */
} BootProgDataType;

typedef struct
{
   uint8 FlashSegmentStatus   [REQUIRED_SIZE_FLASH_SEGMENT_STATUS];
   uint8 SWEProgrammingStatus [SWENUMBEROFALLSWE];
   uint8 lastProgrammedSegment;
} BootProgStatusType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define DATA_LOGISTIC_START_SEC_VAR_NO_INIT_NVM_DATA
#include "MemMap.h"
/*
 * Extern definition of struct 'BootProgCounter'. It will be used as RAM
 * mirror in Appl (NvM) and Bootloader.
 */
extern VAR(BootProgCounterType, COMMON_VAR) BootProgCounter;

extern VAR(BootProgDataType, COMMON_VAR) BootProgData;

extern VAR(BootProgStatusType, COMMON_VAR) BootProgStatus;

extern VAR(SvkHistoryMemoryType, COMMON_VAR) SvkHistoryMemory;


#define DATA_LOGISTIC_STOP_SEC_VAR_NO_INIT_NVM_DATA
#include "MemMap.h"

#ifdef BOOTLOADER
   extern CONST(Vsm_NvDataType, COMMON_CONST) Vsm_NvData_Default;
#endif


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

extern FUNC(Std_ReturnType, COMMON_CODE) Init_BootProgStatus( void );
#ifdef BOOTLOADER
   extern FUNC(boolean, COMMON_CODE) Sync_SWEProgrammingStatus( void );
#endif /* #ifdef BOOTLOADER */
extern FUNC(Std_ReturnType, COMMON_CODE) Init_BootProgCounter( void );
extern FUNC(Std_ReturnType, COMMON_CODE) Init_BootProgData( void );
#ifdef BOOTLOADER
extern FUNC(Std_ReturnType, COMMON_CODE) Init_SvkHistoryMemory(VAR(uint16, COMMON_VAR) BlockNumber);
#else
extern FUNC(Std_ReturnType, COMMON_CODE) Init_SvkHistoryMemory( void );
#endif

#endif /* BOOTMANAGER */
#endif /* SC_EE_DATA_H                                                        */

/*** End of file **************************************************************/
