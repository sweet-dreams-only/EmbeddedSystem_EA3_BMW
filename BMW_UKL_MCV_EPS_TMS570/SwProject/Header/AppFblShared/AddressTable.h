/*******************************************************************************
**                                                                            **
**  SRC-MODULE: AddressTable.h                                                **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Header file dedicated to file 'AddressTable.c'.               **
**              Defines the data type of the data that are shared between     **
**              application and bootloader and the extern declaration.        **
**              In addition the data type includes all the necessary          **
**              parameters of the SWE configuration. This is needed by the    **
**              BLU to check if the SWE configuration has changed.            **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
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
** miwe         Michael Weger              EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.2.1: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V2.2.0: 22.09.2010,   ft: CR70839: Swe.c shall not include flash.h
 *                                    in Application mode   
 * V2.1.0: 30.10.2009, gema: CR70430 - pattern for BootMode added
 * V2.0.0: 17.11.2008, miwe: CR61431: added Flash ECC-error handling
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V4.0.0
 */

#ifndef  ADDRESSTABLE_H
#define  ADDRESSTABLE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>        /* AUTOSAR Standard Types                       */
#include "sc_types_arch.h"    /* Contains architecture dependent parameters   */
                              /* e.g. 'SC_FAR_POINTER' used below.            */
#include "DataLogistic.h"     /* Address table specific structure types       */
#include "Bootloader_Cfg.h"   /* for MemSegTable                              */
#include "cr_c_data.h"        /* Crypto types                                 */
#include "BootManager_Cfg.h"  /* for CRC check configuration                  */
#include "diag_types.h"       /* for 'BOOT_MODE_LENGTH'                       */

#ifdef BOOTMANAGER
	#define flashAddress_t uint32
#else
	#include "flash.h"        /* for 'flashAddress_t'                         */
#endif

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define TIMINGPARAMETERLENGTH 0x0Fu /* length of the 'TimingParameters' array */
#define MEMSEGTABLESIZE       0x02u /*
                                     * MemSegTable stores start and end address
                                     * of a memmory segment
                                     */


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*
 * Fee sector configuration
 */
typedef struct
{
   uint32 LowerSectorStartAddress;
   uint32 LowerSectorEndAddress;
   uint32 UpperSectorStartAddress;
   uint32 UpperSectorEndAddress;
} FeeSectorConfigType;


/*
 * 'sharedBootROMDataType' defines a data type that contains all the data which
 * must be shared between bootloader and application.
 * In addition the data type includes all the necessary parameters of the SWE
 * configuration. This is needed by the BLU to check if the SWE configuration
 * has changed (FP_4919).
 */

typedef struct
{
   /*
    * Sizeof this struct:
    * Used by the BLU to check, if the SWE configuration has changed
    */
   uint32                                  SizeOfStruct;
   /*
    * Store number of Bootloaders and Applications for the BootManager:
    */
   uint8                                   NumberOfBootSWEs;
   uint8                                   NumberOfAllSWEs;
   /*
    * 'PointerToSweFlashStatus' must be the first member in the struct (after
    * the NumberOf's) because it is direct accessed by the BootManager. This
    * means, that it's possition in ROM can not be dependent to the numer of
    * SWEs
    */
   const SweFlashStatusType SC_FAR_POINTER PointerToSweFlashStatus[SWENUMBEROFALLSWE];
   const SweTableType       SC_FAR_POINTER PointerToSweTable[SWENUMBEROFALLSWE];
   uint8                                   SvkVersion;
   uint16                                  ProgrammingCounterMaxValue;
   uint8                                   TimingParameters[TIMINGPARAMETERLENGTH];
   /*
    * Memory segmentation table
    * Used by bootloader and application
    */
   flashAddress_t                          MemSegTable[FLASH_SEGMENT_NUMBER_ALL][MEMSEGTABLESIZE];
   /*
    * Index of the first segment of each SWE
    */
   uint8                                   SweSegmentIndexAppl [SWENUMBEROFAPPLSWE];
   /*
    * Number of segments in each SWE
    */
   uint8                                   SweSegmentNumberAppl [SWENUMBEROFAPPLSWE];
   /*
    * Index of the first signature object of each SWE
    */
   uint8                                   SweSignaturIndexAppl [SWENUMBEROFAPPLSWE];
   /*
    * Number of signature objects in each SWE
    */
   uint8                                   SweSignaturNumberAppl [SWENUMBEROFAPPLSWE];

   CR_cfpc_uint8                           SignatureSweDataPtr[FLASH_SIGNATUR_NUMBER_APPL];

   const uint32                            SignatureSweDataLength[FLASH_SIGNATUR_NUMBER_APPL];
   /*
    * Initial seed for random number generator:
    * It must not be initialized by '0x00'
    */
   CR_C_s2_t                               RANDOM_INIT_VAL;

   /* initial fingerprint                                                     */
   uint8                                   FINGERPRINT_INIT_VAL[FINGERPRINTLENGTH];
   /*
    * CRC check configuration used by BootManager
    */
   uint8                                   CrcBlockStep[BM_CRC_CALC_BLOCK_STEP_TABLE_SIZE + 1];
   uint8                                   SignatureSize;
   uint8                                   FlashSegmentNumberBoot;
   uint8                                   FlashSegmentNumberAll;
   FeeSectorConfigType                     FeeSectorConfig;
   /* pattern of BootMode Bootloader                                          */
   uint8                                   BootModeBootloader[BOOT_MODE_LENGTH];
} sharedBootROMDataType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*
 * Extern declaration of the struct 'sharedBootROMData'. It is located to a
 * shared section via 'MemMap.h'.
 */

/* Define beginning of the shared ROM section                                 */
#define BL_START_SEC_CONST_SHARED_DATA
#include "MemMap.h"

extern CONST(sharedBootROMDataType, SHAREDBOOTROMDATA_CONST) sharedBootROMData;

/* Define end of the shared ROM section                                       */
#define BL_STOP_SEC_CONST_SHARED_DATA
#include "MemMap.h"

#endif /* ADDRESSTABLE_H                                                      */

/*** End of file **************************************************************/
