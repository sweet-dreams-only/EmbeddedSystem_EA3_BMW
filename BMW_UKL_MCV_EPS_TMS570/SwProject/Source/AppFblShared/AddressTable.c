/*******************************************************************************
**                                                                            **
**  SRC-MODULE: AddressTable.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Defines and initializes the struct 'sharedBootROMData' that   **
**              is located in the bootloader and is used to share data        **
**              between the bootloader and application.                       **
**              In addition the structs includes all the necessary parameters **
**              of the SWE configuration. This is needed by the BLU to check  **
**              if the SWE configuration has changed.                         **
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
** gema         Markus Gerngross           MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.3.3: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.3.2: 15.10.2010,   ft: CR70841: BOOTLOADERINSTALLATIONTIME must not be 0
 * V1.3.1: 27.01.2010, gema: CR70537: Template_can_Common: Compiler switches 
 *                                    shall have defined values 
 * V1.3.0: 30.10.2009, gema: CR70430 - BootMode Bootloader added
 * V1.2.0: 17.11.2008, miwe: CR61431: added Flash ECC-error handling
 *         10.09.2008, miwe: BMWSCCRINT-246: fixed wrong BLU-time check
 * V1.1.0: 03.12.2007, miwe: integration of Application template
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V4.0.1
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>           /* AUTOSAR Standard Types */
#include "AddressTable.h"        /* Header file dedicated to 'AddressTable.c' */
#include "Bootloader_Cfg.h"      /* for MemSegTable initialisation            */
#include "sc_types.h"            /* Type definitions and GetxxByte()          */
#ifdef APPLICATION
   #ifdef BAC
   #include "Cdc.h"              /* fingerprint init values                   */
   #endif
#else
   #include "diag_types.h"       /* fingerprint init values                   */
#endif


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* check flash timing parameters according to FP_4371 et seqq.                */
#if ( (ERASEMEMORYTIMEFORMAT            !=   0x01u) ||                         \
      (ERASEMEMORYTIME                   > 0x0078u) ||                         \
      (CHECKMEMORYTIMEFORMAT            !=   0x01u) ||                         \
      (CHECKMEMORYTIME                   > 0x003Cu) ||                         \
      (AUTHENTIFICATIONTIMEFORMAT       !=   0x01u) ||                         \
      (AUTHENTIFICATIONTIME              > 0x000Au) ||                         \
      (RESETTIMEFORMAT                  !=   0x02u) || /* 0x01 not supported */\
      (RESETTIME                         > 0x000Au) ||                         \
      (BOOTLOADERINSTALLATIONTIME       == 0x0000u) ||                         \
      ( (BOOTLOADERINSTALLATIONTIMEFORMAT != 0x00u) && /* no BLU             */\
        (BOOTLOADERINSTALLATIONTIMEFORMAT != 0x02u)    /* BLU available      */\
      )                                             ||                         \
      ( (BOOTLOADERINSTALLATIONTIMEFORMAT ==   0x02u) &&                       \
        (BOOTLOADERINSTALLATIONTIME        > 0x0078u)                          \
      )                                             ||                         \
      ( (BOOTLOADERINSTALLATIONTIMEFORMAT ==   0x00u) &&		\
        (BOOTLOADERINSTALLATIONTIME        > 0x0078u)                          \
      )                                                                        \
    )
   #error "AddressTable.c: Check of flash timing parameters according to FP_4371 et seqq. failed"
#endif

/* check SWE configuration                                                    */
#if ( (((SWENUMBEROFBOOTSWE)+(SWENUMBEROFAPPLSWE)) != (SWENUMBEROFALLSWE)) ||  \
      ((SWENUMBEROFALLSWE)  > 0xFEu)                                           \
    )
   #error "AddressTable.c: 'SWENUMBEROFALLSWE' must not exceed 254"
#endif

#if (FINGERPRINTLENGTH != 13u)
   #error "AddressTable.c: adapt initialization of 'Fingerprint' data"
#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*
 * Definition of the struct 'sharedBootROMDataType'. It is located to a
 * shared section via 'MemMap.h'.
 */

/* Define beginning of the shared ROM section                                 */
#define BL_START_SEC_CONST_SHARED_DATA
#include "MemMap.h"

CONST(sharedBootROMDataType, SHAREDBOOTROMDATA_CONST) sharedBootROMData =
{
   /*
    * Sizeof this struct:
    * Used by the BLU to check, if the SWE configuration has changed
    */
   (uint32)sizeof(sharedBootROMDataType),

   /*
    * Store number of Bootloaders and Applications for the BootManager:
    */
   (uint8)SWENUMBEROFBOOTSWE,
   (uint8)SWENUMBEROFALLSWE,
   /*
    * 'PointerToSweFlashStatus' must be the first member in the struct (after
    * the NumberOf's) because it is direct accessed by the BootManager. This
    * means, that it's possition in ROM can not be dependent to the numer of
    * SWEs
    */
   {
      &BootFlashStatus,                    /* Pointer to flash status of Boot */
      &Swe1FlashStatus,
      &Swe2FlashStatus,
      &Swe3FlashStatus
   },
   {
      &SweBootTable,                       /* Pointer to the BootTable.       */
      &Swe1Table,
      &Swe2Table,
      &Swe3Table
   },
   (uint8)DIAG_SVK_VERSION,
   (uint16)PROGRAMMING_COUNTER_MAX_VALUE,
   {
      /* Erase Memory Time                                                    */
      (uint8)ERASEMEMORYTIMEFORMAT,
      GetHiByte(ERASEMEMORYTIME),
      GetLoByte(ERASEMEMORYTIME),
      /* Check Memory Time                                                    */
      (uint8)CHECKMEMORYTIMEFORMAT,
      GetHiByte(CHECKMEMORYTIME),
      GetLoByte(CHECKMEMORYTIME),
      /* Authentification Time                                                */
      (uint8)AUTHENTIFICATIONTIMEFORMAT,
      GetHiByte(AUTHENTIFICATIONTIME),
      GetLoByte(AUTHENTIFICATIONTIME),
      /* Reset Time                                                           */
      (uint8)RESETTIMEFORMAT,
      GetHiByte(RESETTIME),
      GetLoByte(RESETTIME),
      /* Bootloader Installation Time                                         */
      (uint8)BOOTLOADERINSTALLATIONTIMEFORMAT,
      GetHiByte(BOOTLOADERINSTALLATIONTIME),
      GetLoByte(BOOTLOADERINSTALLATIONTIME)
   },
   /*
    * Memory segmentation table:
    * Used by bootloader and application
    */
   {
      FLASH_SEGMENT_TABLE
   },
   /*
    * Index of the first segment of each SWE
    */
   {
      SWE_SEGMENT_INDEX_APPL
   },
   /*
    * Number of segments in each SWE
    */
   {
      SWE_SEGMENT_NUMBER_APPL
   },
   /*
    * Index of the first signature object of each SWE
    */
   {
      SWE_SIGNATUR_INDEX_APPL
   },
   /*
    * Number of signature objects in each SWE
    */
   {
      SWE_SIGNATUR_NUMBER_APPL
   },
   {
      SIG_ADR_TABLE
      /* ^ MISRA violation: Rule 45 cast from integer to pointer is necessary */
      /* to initialize 'SignatureSweDataPtr' with correct addresses           */
   },
   {
      SIG_LEN_TABLE
   },
   /*
    * Initial seed for random number generator:
    * It must not be initialized by '0x00'
    */
   {
     {
        (uint32)0x17091982uL,
        (uint32)0x24071980uL
     },
     {
        (uint32)0x06021980uL,
        (uint32)0x22011978uL
     }
   },
   /* initial fingerprint                                                     */
   {
      /* programming date                                                     */
      (uint8)DIAG_FINGERPRINT_PRGDATE_INITIAL,
      (uint8)DIAG_FINGERPRINT_PRGDATE_INITIAL,
      (uint8)DIAG_FINGERPRINT_PRGDATE_INITIAL,

      /* fingerprint format / tester sevice id                                */
      (
         ( (uint8)DIAG_FINGERPRINT_LONG        &
           (uint8)DIAG_FINGERPRINT_LENGTH_MASK
         )
         |
         ( (uint8)DIAG_FINGERPRINT_TESTER_SERVICE_ID_INITIAL &
           (uint8)DIAG_FINGERPRINT_TESTER_SERVICE_ID_MASK
         )
      ),

      /* programming device type code                                         */
      GetHiByte(DIAG_FINGERPRINT_BMWCODE_INITIAL),
      GetLoByte(DIAG_FINGERPRINT_BMWCODE_INITIAL),

      /* programming device type                                              */
      (uint8)DIAG_FINGERPRINT_PROGDEVTYPE_INITIAL,

      /* programming device serial number                                     */
      GetHiHiByte(DIAG_FINGERPRINT_PROGDEV_SERNUM_INITIAL),
      GetHiLoByte(DIAG_FINGERPRINT_PROGDEV_SERNUM_INITIAL),
      GetLoHiByte(DIAG_FINGERPRINT_PROGDEV_SERNUM_INITIAL),
      GetLoLoByte(DIAG_FINGERPRINT_PROGDEV_SERNUM_INITIAL),

      /* mileage                                                              */
      GetHiByte(DIAG_FINGERPRINT_MILEAGE_INITIAL),
      GetLoByte(DIAG_FINGERPRINT_MILEAGE_INITIAL)
   },
   {
      (uint8)BM_CRC_CALC_BLOCK_STEP_TABLE_SIZE,
      BM_CRC_CALC_BLOCK_STEP_TABLE
   },
   (uint8)SIGNATURE_SIZE,
   (uint8)FLASH_SEGMENT_NUMBER_BOOT,
   (uint8)FLASH_SEGMENT_NUMBER_ALL,
#if ( SC_FEE_ENABLE == STD_ON )
   {
      (uint32)MY_FEE_DFLASH1_START,
      (uint32)( (uint32)MY_FEE_DFLASH1_START +
                (uint32)MY_FEE_DFLASH1_SIZE  -
                (uint32)1
              ),
      (uint32)MY_FEE_DFLASH2_START,
      (uint32)( (uint32)MY_FEE_DFLASH2_START +
                (uint32)MY_FEE_DFLASH2_SIZE  -
                (uint32)1
              )
   },
#else
   {
      (uint32)0x00000000uL,   /* No Fee is available                          */
      (uint32)0x00000000uL,   /* No Fee is available                          */
      (uint32)0x00000000uL,   /* No Fee is available                          */
      (uint32)0x00000000uL    /* No Fee is available                          */
   },
#endif /* SC_FEE_ENABLE == ON                                                 */
   /* pattern of BootMode Bootloader                                          */
   {
      BOOT_MODE_BOOTLOADER
   }

}; /* sharedBootROMData                                                       */

/* Define end of the shared ROM section                                       */
#define BL_STOP_SEC_CONST_SHARED_DATA
#include "MemMap.h"

/*** End of file **************************************************************/
