/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_ee_data.c                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Implements the definition of struct 'BootProgStatus',         **
**              'BootProgCounter', 'BootProgData' and 'SvkHistoryMemory'.     **
**              These structs contains some data which is used by the         **
**              standard core and which must be located within non-volatile   **
**              memory.                                                       **
**              These structs will be used as RAM mirror in Appl (NvM) and    **
**              Bootloader                                                    **
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
** hauf         Andreas Hauf               EB Automotive                      **
** gema         Gerngross Markus           MB Technology                      **
** scma         Scheitterer Martin         MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
** tr           Thomas Rösch               Richard Bader GmbH                 **
** pego         Peter Golzem               R. Bader GmbH                      **
** anam         Andreas Amann              MB Technology                      **
** mb           Martin Bader               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.2.4: 26.08.2011,   mb: CR70955: New global common for common files between templates
 * V2.2.3: 20.05.2011, anam: CR71056: SVK Read: Optimize RAM Usage 
 * V2.2.2: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V2.2.1: 14.04.2011,   tr: CR70826 Vector Release 10 Update for all Tools
 * V2.2.0: 07.09.2010,   ft: CR70748: added missing compiler abstraction
 * V2.2.0: 07.09.2010,   ft: CR70753: added missing compiler abstraction
 * V2.2.0: 07.09.2010,   ft: CR70747: added missing compiler abstraction
 * V2.1.0: 30.07.2009, scma: switch for SC6 diag added
 * V2.0.0: 13.07.2009, gema: CR70254: added ECC/CRC error flags handling
 *                                    removed EccErrorOccurred handling
 * V1.2.1: 30.06.2009, hauf: CR70156: synchronize SWE programming status
 *                                    with valid flags during startup
 * V1.2.0: 02.09.2008, olgo: CR61431: separated bootloader and bootmanager
 *         30.07.2008, miwe: CR61388: added Blu Nv data conversion support
 * V1.1.0: 03.12.2007, miwe: integration of Application template
 *         15.11.2007, miwe: NvM integration in Application:
 *                           + changed init block callback prototype
 *                           + added Vsm_NvData_Default block
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V7.0.0
 */
/*
#ifndef I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION
#error "the program must not be used in connection with series production"
#endif
*/
#ifndef BOOTMANAGER
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>        /* AUTOSAR Standard Types */
#include "sc_ee_data.h"       /* Header file corresponding to 'sc_ee_data.c'  */
#include "AddressTable.h"     /* for 'sharedBootROMData' structure            */
#include "Bootloader_Cfg.h"   /* for 'SWENUMBEROFALLSWE' macro                */
#include "sc_types_arch.h"    /* for 'SC_FAR_POINTER' defines                 */
#include "Swe.h"              /* Contains SWE access functions                */
#ifdef APPLICATION
   #include "Cdc.h"           /* for fingerprint defines                      */
#else
   #include "diag.h"          /* for fingerprint defines                      */
#ifdef BOOTLOADER
   #include "bootmain.h"
   #include "Vsm_Client.h"    /* VSM modul specific include                   */
#endif
#endif
#include "sc_target.h"        /* for BootStatus structure                     */


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define DATA_LOGISTIC_START_SEC_VAR_NO_INIT_NVM_DATA
#include "MemMap.h"
/*
 * The struct 'BootProgCounter' will be used as RAM mirror in Appl (NvM) and
 * Bootloader
 */
VAR(BootProgCounterType, COMMON_VAR) BootProgCounter;

VAR(BootProgDataType, COMMON_VAR) BootProgData;

VAR(BootProgStatusType, COMMON_VAR) BootProgStatus;

VAR(SvkHistoryMemoryType, COMMON_VAR) SvkHistoryMemory;

#define DATA_LOGISTIC_STOP_SEC_VAR_NO_INIT_NVM_DATA
#include "MemMap.h"

#ifdef BOOTLOADER
CONST(Vsm_NvDataType, COMMON_CONST) Vsm_NvData_Default =
{
   VSM_MM_MODE_NORMAL,
   VSM_MM_MODE_EXTENSION_NORMAL
   /* TODO: Nxtr Patch Comment:  Additional initializer commented out per Vector's direction.
                               It has not been confirmed by Nxtr that BMW agrees with 
							   this patch.
   #if (SC_FEE_ENABLE != STD_ON)
   ,(uint8)0x00u
   #endif */
};
#endif


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#define DATA_LOGISTIC_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Init_BootProgStatus                                        **
**                                                                            **
** DESCRIPTION   : Initalize 'BootProgStatus' struct with default data        **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** GLOBAL DATA   : BootProgStatus                                             **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       : This function is called from bootloader and application    **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, COMMON_CODE) Init_BootProgStatus( void )
{
   uint8_least iLoop;

   /* clear FlashSegmentStatus                                                */
#if ( FLASH_SEGMENT_STATUS_NOT_WRITABLE != 0x00u )
   #error "sc_ee_data.c: adapt 'Init_BootProgStatus' - a loop must be used to set the status properly"
#endif

   (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&BootProgStatus.FlashSegmentStatus[0],
                        FLASH_SEGMENT_STATUS_NOT_WRITABLE,
                        sizeof(BootProgStatus.FlashSegmentStatus)
                      );

   for (iLoop = (uint8_least)0;
        iLoop < (uint8_least)SWENUMBEROFALLSWE;
        iLoop++
       )
   {
#ifdef BOOTLOADER
                                            /* get SWE valid state from ROM   */
      SweValidStateType validStateOfSwe = Swe_GetValidStateOfSwe( (uint8)iLoop );

                                  /* if SWE is valid                          */
      if ( ( validStateOfSwe == SWE_VALID_STATE_VALID_SWFL ) ||
           ( validStateOfSwe == SWE_VALID_STATE_VALID_BTLD  ) )
      {
#endif /* #ifdef BOOTLOADER */
         /* init SWEProgrammingStatus to CHECKSIGNATUREOK                     */
         BootProgStatus.SWEProgrammingStatus[iLoop] =
                                               (uint8)PROGSTAT_CHECKSIGNATUREOK;
#ifdef BOOTLOADER
      }
      else
      {
         /* init SWEProgrammingStatus to CHECKSIGNATURENOK                    */
         BootProgStatus.SWEProgrammingStatus[iLoop] =
                                              (uint8)PROGSTAT_CHECKSIGNATURENOK;
      }
#endif /* #ifdef BOOTLOADER */
   }

   BootProgStatus.lastProgrammedSegment = (uint8)REPROGRAMMINGNOTVALIDADDRESS;

   return E_OK;
} /* end of function 'Init_BootProgStatus'                                    */


#ifdef BOOTLOADER
/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Sync_SWEProgrammingStatus                                  **
**                                                                            **
** DESCRIPTION   : Synchronize SWE programming status in NV memory from SWE   **
**                 valid state in flash ROM                                   **
**                                                                            **
** PRECONDITIONS : ---                                                        **
**                                                                            **
** GLOBAL DATA   : BootProgStatus                                             **
**                                                                            **
** PARAMETER     : ---                                                        **
**                                                                            **
** RETURN        : TRUE:  Updated SWE programming status in RAM               **
**                 FALSE: SWE Programming status already synchron with ROM    **
**                                                                            **
** REMARKS       : This function is called from bootloader only               **
**                                                                            **
*******************************************************************************/
FUNC(boolean, COMMON_CODE) Sync_SWEProgrammingStatus( void )
{
   boolean statusChanged = FALSE;

                                  /* iterate all application SWEs             */
   uint8_least sweId;
   for (sweId = (uint8_least)SWE_ID_OF_APPL_SWE1;
        sweId < (uint8_least)SWENUMBEROFALLSWE;
        sweId++
       )
   {
                                            /* get SWE valid state from ROM   */
      SweValidStateType validStateOfSwe = Swe_GetValidStateOfSwe( (uint8)sweId );

                                  /* if SWE valid flag in SWE ROM is not ok   */
      if ( ( validStateOfSwe != SWE_VALID_STATE_VALID_SWFL ) &&
           ( validStateOfSwe != SWE_VALID_STATE_VALID_BTLD  ) )
      {
                                  /* if SWE programming status is ok          */
         if ( BootProgStatus.SWEProgrammingStatus[ sweId ] == (uint8)PROGSTAT_CHECKSIGNATUREOK )
         {
                                            /* correct SWE programing status  */
            BootProgStatus.SWEProgrammingStatus[ sweId ] = PROGSTAT_CHECKSIGNATURENOK;

                                            /* mark for writing back to NVRAM */
            statusChanged = TRUE;
         }
      }
                                  /* if SWE valid flag in SWE ROM is ok       */
      else
      {

                                  /* iterate all flash segments of SWE        */
         uint8_least flashSegmentId = (uint8_least)
            sharedBootROMData.SweSegmentIndexAppl[ sweId - SWE_ID_OF_APPL_SWE1 ];
         uint8_least flashSegmentIdOfNextSwe = flashSegmentId +
            sharedBootROMData.SweSegmentNumberAppl[ sweId - SWE_ID_OF_APPL_SWE1 ];
         do
         {
                                  /* if flash segment status of SWE is wrong  */
            if ( GET_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootProgStatus.FlashSegmentStatus,
                                                  (uint8)flashSegmentId )
                 != (uint8)FLASH_SEGMENT_STATUS_NOT_WRITABLE )
            {
                                            /* correct flash segment status   */
               CLEAR_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootProgStatus.FlashSegmentStatus,
                                                  flashSegmentId );

                                            /* mark for writing back to NVRAM */
               statusChanged = TRUE;
            }
            ++flashSegmentId;
         } while ( flashSegmentId < flashSegmentIdOfNextSwe );


                                  /* if SWE programming status is not ok      */
         if ( BootProgStatus.SWEProgrammingStatus[ sweId ] != (uint8)PROGSTAT_CHECKSIGNATUREOK )
         {
                                            /* correct SWE programing status  */
            BootProgStatus.SWEProgrammingStatus[ sweId ] = PROGSTAT_CHECKSIGNATUREOK;

                                            /* mark for writing back to NVRAM */
            statusChanged = TRUE;
         }
      }
   }

   return statusChanged;
} /* end of function 'Sync_SWEProgrammingStatus'                              */
#endif /* #ifdef BOOTLOADER */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Init_BootProgCounter                                       **
**                                                                            **
** DESCRIPTION   : Initalize 'BootProgCounter' struct with default data       **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** GLOBAL DATA   : BootProgCounter                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       : This function is called from bootloader and application    **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, COMMON_CODE) Init_BootProgCounter( void )
{
   /* set all data to 0x00                                                    */
   (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&BootProgCounter,
                        0x00u,
                        sizeof(BootProgCounter)
                      );

   return E_OK;
} /* end of function 'Init_BootProgCounter'                                   */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Init_BootProgData                                          **
**                                                                            **
** DESCRIPTION   : Initalize 'BootProgData' struct with default data          **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** GLOBAL DATA   : BootProgData                                               **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       : This function is called from bootloader and application    **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, COMMON_CODE) Init_BootProgData( void )
{
   /* Write initial seed for random number generator into BootProgData        */
#ifdef BOOTLOADER
   BootProgData.RANDOM[0] = sharedBootROMData.RANDOM_INIT_VAL.reg_a[0];
   BootProgData.RANDOM[1] = sharedBootROMData.RANDOM_INIT_VAL.reg_a[1];
   BootProgData.RANDOM[2] = sharedBootROMData.RANDOM_INIT_VAL.reg_b[0];
   BootProgData.RANDOM[3] = sharedBootROMData.RANDOM_INIT_VAL.reg_b[1];
#else
   BootProgData.RANDOM.reg_a[0] = sharedBootROMData.RANDOM_INIT_VAL.reg_a[0];
   BootProgData.RANDOM.reg_a[1] = sharedBootROMData.RANDOM_INIT_VAL.reg_a[1];
   BootProgData.RANDOM.reg_b[0] = sharedBootROMData.RANDOM_INIT_VAL.reg_b[0];
   BootProgData.RANDOM.reg_b[1] = sharedBootROMData.RANDOM_INIT_VAL.reg_b[1];
#endif /* BOOTLOADER */
   /*
    * ApplicStartedFirst set to ISNOTFIRSTSTARTOFAPPLICATION because an empty
    * Nv memory doesn't signify a first startup of the application
    */
   BootProgData.ApplicStartedFirst = (uint8)ISNOTFIRSTSTARTOFAPPLICATION;

   /* write initial fingerprint into BootProgData                             */
   (void)SC_MEMCPY_ROM( (void SC_FAR_POINTER)&BootProgData.FingerPrint[0],
                        (const void SC_FAR_POINTER)&sharedBootROMData.FINGERPRINT_INIT_VAL[0],
                        sizeof(BootProgData.FingerPrint)
                      );

   /* set VIN to init value                                                   */
   (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&BootProgData.VIN[0],
                        DIAG_VIN_INITIAL,
                        sizeof(BootProgData.VIN)
                      );

   return E_OK;
} /* end of function 'Init_BootProgData'                                      */


/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Init_SvkHistoryMemory                                      **
**                                                                            **
** DESCRIPTION   : Initalize 'SvkHistoryMemory' struct with default data      **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** GLOBAL DATA   : SvkHistoryMemory                                           **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       : This function is called from bootloader and application    **
**                                                                            **
*******************************************************************************/
#ifdef BOOTLOADER
FUNC(Std_ReturnType, COMMON_CODE) Init_SvkHistoryMemory(VAR(uint16, COMMON_VAR) BlockNumber)
{
   VAR(boolean, COMMON_VAR) retVal = TRUE;
   #if (NUMBEROFSVKBACKUPS > 0u)
   uint8 SvkBackupCounter;
   #endif
   P2VAR(uint8, AUTOMATIC, COMMON_VAR) DataBufferPtr = NULL_PTR;
   VAR(uint16, COMMON_VAR) len = 0;

   switch(BlockNumber)
   {
      case NVM_BLOCK_BOOT_SVK_HISTORY:
         DataBufferPtr = (P2VAR(uint8, AUTOMATIC, COMMON_VAR)) &SvkHistoryMemory;
         #if (NUMBEROFSVKBACKUPS > 0u)
         len = 2; /* SvkHistoryMemory.SvkLockedStatus + SvkHistoryMemory.SvkBackupFIFOCounter */
         #else
         len = 1;
         #endif
         break;
      case NVM_BLOCK_BOOT_SVK_SYS_SUPP:
         DataBufferPtr = &SvkHistoryMemory.SvkSysSupp[0];
         len = SVK_BACKUP_SIZE;
         break;
      case NVM_BLOCK_BOOT_SVK_PLANT:
         DataBufferPtr = &SvkHistoryMemory.SvkPlant[0];
         len = SVK_BACKUP_SIZE;
         break;
      default:
         #if (NUMBEROFSVKBACKUPS > 0u)
         for( SvkBackupCounter = 0; SvkBackupCounter < NUMBEROFSVKBACKUPS ; SvkBackupCounter++)
         {
            if(BlockNumber == Boot_SvkBackups[SvkBackupCounter])
            {
               DataBufferPtr = &SvkHistoryMemory.SvkBackup[SvkBackupCounter][0];
               len = SVK_BACKUP_SIZE;
            }
         }
         #endif
         break;
    }
   /* set all data to 0x00                                                    */
   (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)DataBufferPtr,
                        0x00u,
                        len
                      );
   
   if(NVM_BLOCK_BOOT_SVK_HISTORY == BlockNumber)
   {
     /* all SVK memories are unlocked                                           */
     SvkHistoryMemory.SvkLockedStatus = (uint8)SVKSTATUS_SYSSUPPANDPLANTUNLOCKED;
   }
   
   return E_OK;
   
} /* end of function 'Init_SvkHistoryMemory'                                  */
#else
FUNC(Std_ReturnType, COMMON_CODE) Init_SvkHistoryMemory( void )
{
   /* set all data to 0x00                                                    */
   (void)SC_MEMSET_ROM( (void SC_FAR_POINTER)&SvkHistoryMemory,
                        0x00u,
                        sizeof(SvkHistoryMemory)
                      );

   /* all SVK memories are unlocked                                           */
   SvkHistoryMemory.SvkLockedStatus = (uint8)SVKSTATUS_SYSSUPPANDPLANTUNLOCKED;

   return E_OK;
} /* end of function 'Init_SvkHistoryMemory'                                  */

#endif /*#ifdef BOOTLOADER*/

#define DATA_LOGISTIC_STOP_SEC_CODE
#include "MemMap.h"

#endif /* !defined(BOOTMANAGER)                                               */

/*** End of file **************************************************************/

