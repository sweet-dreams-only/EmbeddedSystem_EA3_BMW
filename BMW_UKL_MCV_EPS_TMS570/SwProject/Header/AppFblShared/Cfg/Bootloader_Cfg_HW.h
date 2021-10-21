/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Bootloader_Cfg_HW.h                                           **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : s12x                                                       **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Modular make environment. Contains configuration parameters   **
**              which are exclusively dedicated to the bootloader.            **
**              Therefore they are not defined in file 'StandardCore_Cfg.h'.  **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
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
** anht         Andreas Hartmann           EB Automotive                      **
** masc         Marko Schneider            EB Automotive                      **
** guab         Günter Abelen              MB Technology                      **
** tr           Thomas Rösch               Richard Bader GmbH                 **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.3: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.1.2: 14.04.2011, tr: CR70826 Vector Release 10 Update for all Tools
 * V1.1.1: 02.03.2011, guab: CR70866: CRC test not activatable in bootmanager
 * V1.1.0: 15.08.2008, masc: CR61432: added RAM ECC-error handling
 *                           + added CRC-check for SWEs
 *         05.06.2008, anht: CR61336: moved Flash timing parameters from
 *                                    bootloader_cfg.h to the derivative
 *                                    specific bootloader_cfg_xxx.h
 * V1.0.1: 27.09.2007, miwe: CR61261: reworked FreeTimer integration
 * V1.0.0: 24.09.2007, miwe: ported from SC6.7.2 file version V1.2.0
 */


/**************************************************************************************************************************
 * Nxtr Version Control:
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev          Author         Change Description                                                        SCR #
 * -------   -------     --------  ---------------------------------------------------------------------------  ----------
10/05/16     EA3#6.1.4     ABS        Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
**************************************************************************************************************************/

#ifndef BOOTLOADER_CFG_HW_H
#define BOOTLOADER_CFG_HW_H
/*
#ifndef I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION
#error "the program must not be used in connection with series production"
#endif
*/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types */
#include "Crypto_Cfg.h"           /* include crypto method                    */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* In general the flash EEPROM space of a MCU can consist of incoherent       */
/* memory areas. This means that the address space is nonlinear, it has some  */
/* gaps in between. These coherent memory areas mustn't be confused with the  */
/* flash memory blocks. One coherent memory area can consist of several flash */
/* blocks.                                                                    */

/* The two dimensial array 'MemSegTable' defined in 'AddressTable.c/h' shall  */
/* contain the start and end address of each coherent memory area dedicated   */
/* the application. The first index determines the number of the area (start  */
/* counting by zero) and the second index can be zero or one. If the second   */
/* index is zero then the start address of the corresponding memory area must */
/* be provided. If the second index is one then the end address of the        */
/* corresponding memory area must be provided.                                */
/* E.g. MemSegTable[2][0] = start address of third application ROM area,      */
/* MemSegTable[2][1] = end address of third application ROM area.             */

/* The singnature check function requires the start address and the length    */
/* of each coherent memory area that shall be checked. In general the         */
/* complete application shall be signature checked so the coherent memory     */
/* areas of the application and defined by 'MemSegTable' should be same but   */
/* it isn't so because some data of the application e.g. the singature itself */
/* mustn't be checked by the signature. Therefore two separate arrays         */
/* 'sw_ptr' and 'sw_length' must be provided that define each coherent memory */
/* area of the application that must be signature checked. 'sw_ptr' defines   */
/* the start address and 'sw_length' the length of such a memroy block.       */


/*******************************************************************************
**                      MCS12X                                                **
*******************************************************************************/

   /* ----------------------------------------------------------------------- */
   /*                     Flash timing parameters                             */
   /* ----------------------------------------------------------------------- */
   /* in seconds, according to FP_4371 et seqq.                               */
   #define ERASEMEMORYTIMEFORMAT               0x01u     /* see FP_5553       */
   #define ERASEMEMORYTIME                   0x0077u     /* maximum 0x0078    */
   #define CHECKMEMORYTIMEFORMAT               0x01u     /* see FP_5555       */
   #define CHECKMEMORYTIME                   0x000Fu     /* maximum 0x003C    */
   #define AUTHENTIFICATIONTIMEFORMAT          0x01u     /* see FP_5556       */
   #define AUTHENTIFICATIONTIME              0x0002u     /* maximum 0x000A    */
   /*
    * Reset time format 0x01 is not supported by the SC.
    * If the value of reset time is configured to big and no TesterPresent
    * messages are send, a session timeout will occur and the ECU will fall
    * back from the Bootloader to the Application.
    */
   #define RESETTIMEFORMAT                     0x02u     /* see FP_5582       */
   #define RESETTIME                         0x000Au     /* maximum 0x000A    */
   #define BOOTLOADERINSTALLATIONTIMEFORMAT    0x02u     /* see FP_5557       */
   #define BOOTLOADERINSTALLATIONTIME        0x001Eu     /* maximum 0x0078    */

   /*
    * The worst case time that is needed to flash ('FlasWrite()')
    * 'MY_NRV2B_TEMP_BUFFER_SIZE' Bytes of data. The time can be meassured in
    * the function 'FlashWriteUpdatingFlashSegmentStatusAndMaskingFlashStat()'
    * during NRV compressed data download using 'LED_FLASH_WRITE'.
    *
    * FlashWrite time (~16ms) + reserve
    */
   #define APPROXWORSTCASEFLASHWRITETIME    0x1Eu     /* 30 ms                */

   /* *******************  SWE configuration  ******************************* */

   /* number of bootloader and application SWEs                               */
   #define SWENUMBEROFBOOTSWE                      0x01u
   #define SWENUMBEROFAPPLSWE                      0x03u 
   #define SWENUMBEROFALLSWE                       (SWENUMBEROFBOOTSWE +       \
                                                    SWENUMBEROFAPPLSWE)

   /* *************************  boot  ************************************** */
   /* Defines the total number of memory areas dedicated for the bootloader   */
   #define FLASH_SEGMENT_NUMBER_BM   0x01u
   #define FLASH_SEGMENT_NUMBER_BOOT 0x06u

   /* Start and end address of the flash memory areas dedicated to the        */
   /* bootloader program(s)                                                   */
   #define FLASH_SEGMENT_TABLE_BM                                              \
      {0x00000000uL, 0x00007FFFuL}

   #define FLASH_SEGMENT_TABLE_BOOT                                            \
      {0x00008000uL, 0x0000BFFFuL},                                            \
      {0x0000C000uL, 0x0000FFFFuL},                                            \
      {0x00010000uL, 0x00013FFFuL},                                            \
      {0x00014000uL, 0x00017FFFuL},                                            \
      {0x00018000uL, 0x0001FFFFuL},                                            \
      {0x00020000uL, 0x0003FFFFuL}
      
   /* ************************  appl  *************************************** */

   /* Defines the total number of memory areas for each application SWE and   */
   /* the total number of memory segments for the application                 */
   #define SWE1_SEGMENT_NUMBER_APPL   4
   #define SWE2_SEGMENT_NUMBER_APPL   1
   #define SWE3_SEGMENT_NUMBER_APPL   1

   #define SWE_SEGMENT_NUMBER_APPL                                             \
      SWE1_SEGMENT_NUMBER_APPL,  \
      SWE2_SEGMENT_NUMBER_APPL,  \
      SWE3_SEGMENT_NUMBER_APPL

   /* Calculates the index of the the first memory segment of each SWE in     */
   /* 'FLASH_SEGMENT_TABLE_APPL' and prepares them for storing in an array    */

   #define SWE3_SEGMENT_INDEX_APPL  0x00u
   #define SWE2_SEGMENT_INDEX_APPL  (SWE3_SEGMENT_INDEX_APPL +				\
										SWE3_SEGMENT_NUMBER_APPL)
   #define SWE1_SEGMENT_INDEX_APPL  (SWE2_SEGMENT_INDEX_APPL +				\
										SWE2_SEGMENT_NUMBER_APPL)

   #define SWE_SEGMENT_INDEX_APPL                                              \
      SWE1_SEGMENT_INDEX_APPL, \
	  SWE2_SEGMENT_INDEX_APPL, \
	  SWE3_SEGMENT_INDEX_APPL

   /* calculates the number of memory segments of all application SWEs        */
   #define FLASH_SEGMENT_NUMBER_APPL (( SWE1_SEGMENT_NUMBER_APPL +			\
										SWE2_SEGMENT_NUMBER_APPL +			\
										SWE3_SEGMENT_NUMBER_APPL  ) )

   /* calculates the number of memory segments of all SWEs                    */
   #define FLASH_SEGMENT_NUMBER_ALL  (FLASH_SEGMENT_NUMBER_BOOT +              \
                                      FLASH_SEGMENT_NUMBER_APPL)

   /*
    * Start- and EndAddress of the flash memory area dedicated for the SWEs.
    *
    * --!!-- Constraints --!!--!!--!!--!!--!!--!!--!!--!!--!!--!!--!!--!!--!!--
    * + FP_5857:
    *   The start StartAddresses of the memory areas within a SWE have to be in
    *   increasing order.
    * + The memory areas shall not overlap.
    */
    #define FLASH_SEGMENT_TABLE_SWE1                                           \
      {0x00040000uL, 0x0005FFFFuL},                                            \
      {0x00060000uL, 0x0007FFFFuL},                                            \
      {0x00080000uL, 0x0009FFFFuL},                                            \
      {0x000A0000uL, 0x000BFFDFuL}
   #define FLASH_SEGMENT_TABLE_SWE2                                           \
   	 {0x00010000uL, 0x0001FFDFuL}
/*
	Note: 
	Due to the EEPROM size for BOOT_PROG_STATUS, SWE2 was combined into one 
	block. Increasing the number of sectors, would make BOOT_PROG_STATUS grow and
	cause changes to the EA/NvM layout.
	
	On the Champion part, the above SWE is actually three sectors with the following sizes:
	 {0x00010000uL, 0x00013FFFuL},											  \
     {0x00014000uL, 0x00017FFFuL},											  \
	 {0x00018000uL, 0x0001FFDFuL}
	On the Gladiator part, the above SWE is actually two sectors with the following sizes:
	 {0x00010000uL, 0x00017FFFuL},											  \
	 {0x00018000uL, 0x0001FFDFuL}
	
*/
     
   #define FLASH_SEGMENT_TABLE_SWE3                                           \
   	 {0x00008000uL, 0x0000FFDFuL}
/*
	Note: 
	Due to the EEPROM size for BOOT_PROG_STATUS, SWE2 was combined into one 
	block. Increasing the number of sectors, would make BOOT_PROG_STATUS grow and
	cause changes to the EA/NvM layout.
	
	On the Champion part, the above SWE is actually two sectors with the following sizes:
	 {0x00008000uL, 0x0000BFFFuL},											  \
     {0x0000C000uL, 0x0000FFFFuL},											  \
	On the Gladiator part, the above SWE is actually one sector as defined above.
*/

   /* This parameter is used to initialize an array with all the memory       */
   /* segment sizes defined above                                             */
   #define FLASH_SEGMENT_TABLE_APPL                                            \
      FLASH_SEGMENT_TABLE_SWE3,													\
      FLASH_SEGMENT_TABLE_SWE2,													\
      FLASH_SEGMENT_TABLE_SWE1

   #define FLASH_SEGMENT_TABLE                                                 \
      FLASH_SEGMENT_TABLE_BOOT,                                                \
      FLASH_SEGMENT_TABLE_APPL

   /*
    * define the number of areas that have to be signature checked for each
    * SWE:
    * normally there are two areas to be signature checked: the one before and
    * the one after the signature. When there are no holes between the flash
    * segments the signature can be checked across flash segment borders
    */
   #define SWE1_SIGNATUR_NUMBER_APPL 0x02u
   #define SWE2_SIGNATUR_NUMBER_APPL 0x02u
   #define SWE3_SIGNATUR_NUMBER_APPL 0x02u

   #define SWE_SIGNATUR_NUMBER_APPL                                            \
      SWE1_SIGNATUR_NUMBER_APPL,												\
      SWE2_SIGNATUR_NUMBER_APPL,												\
	  SWE3_SIGNATUR_NUMBER_APPL

   /* calculates the number of signature segments of all application SWEs     */
   #define FLASH_SIGNATUR_NUMBER_APPL ((SWE1_SIGNATUR_NUMBER_APPL +			\
										SWE2_SIGNATUR_NUMBER_APPL +			\
										SWE3_SIGNATUR_NUMBER_APPL ) )

   /*
    * Calculates the index of the the first signature segment of each SWE in
    * 'SIG_ADR_TABLE' and 'SIG_LEN_TABLE' and prepares them for storing in an
    * array
    */
   #define SWE1_SIGNATUR_INDEX_APPL  0x00u
   #define SWE2_SIGNATUR_INDEX_APPL  (SWE1_SIGNATUR_INDEX_APPL +			\
										SWE1_SIGNATUR_NUMBER_APPL)
   #define SWE3_SIGNATUR_INDEX_APPL  (SWE2_SIGNATUR_INDEX_APPL +			\
										SWE2_SIGNATUR_NUMBER_APPL)
 
   #define SWE_SIGNATUR_INDEX_APPL                                             \
      SWE1_SIGNATUR_INDEX_APPL,													\
	  SWE2_SIGNATUR_INDEX_APPL,													\
	  SWE3_SIGNATUR_INDEX_APPL

   /*
    * Start address of the flash memory areas dedicated for the
    * application program that shall be signature checked.
    *
    * On S12X this pointers have to be provided in the global address model:
    * Therefore the logical addresses have to be converted from logical to
    * global addresses.
    */
   #define SIG_ADR_TABLE_SWE1                                                  \
      (CR_cfpc_uint8)0x00040000uL,                                             \
      (CR_cfpc_uint8)0x000BFED0uL

   #define SIG_ADR_TABLE_SWE2                                                  \
      (CR_cfpc_uint8)0x00010000uL,                                             \
      (CR_cfpc_uint8)0x0001FED0uL
      
   #define SIG_ADR_TABLE_SWE3                                                  \
      (CR_cfpc_uint8)0x00008000uL,                                             \
      (CR_cfpc_uint8)0x0000FED0uL

   #define SIG_ADR_TABLE                                                       \
      SIG_ADR_TABLE_SWE1, \
      SIG_ADR_TABLE_SWE2, \
      SIG_ADR_TABLE_SWE3

   /*
    * Length of the flash memory areas dedicated for the
    * application program that shall be signature checked.
    *
    * Asymmetric signatures are longer than symmetric signatures. When symmetric
    * signatures are used, the thereby released memory is used by the SWE and
    * therefore signature checked. The difference betwenn the two signatures is
    * configured in 'SIG_LEN_OFFSET'.
    */
   #if defined (CRYPTO_AUTH_ASYM)
         #define SIG_LEN_OFFSET 0x00000000uL
   #elif defined (CRYPTO_AUTH_SYM)
         #define SIG_LEN_OFFSET 0x00000074uL
   #else
     #error "Bootloader_Cfg_HW.h: No crypto method defined. Define 'CRYPTO_AUTH_ASYM' or 'CRYPTO_AUTH_SYM'"
   #endif

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: SWE table modified because of the increase in signature length from 1024-bit to
 * 				2048-bit
 */
 #if 0
/* Original code - START */
   #define SIG_LEN_TABLE_SWE1                                                \
      (CR_fc_uint32)0x0007FE4CuL,                                            \
      (CR_fc_uint32)0x00000100uL

   #define SIG_LEN_TABLE_SWE2                                                \
      (CR_fc_uint32)0x0000FE4CuL,                                            \
      (CR_fc_uint32)0x00000100uL

   #define SIG_LEN_TABLE_SWE3                                                \
      (CR_fc_uint32)0x00007E4CuL,                                            \
      (CR_fc_uint32)0x00000100uL

   #define SIG_LEN_TABLE                                                       \
      SIG_LEN_TABLE_SWE1, \
      SIG_LEN_TABLE_SWE2, \
      SIG_LEN_TABLE_SWE3
/* Original code - END */
#endif
/* Patch code  - START */
   #define SIG_LEN_TABLE_SWE1                                                \
      (CR_fc_uint32)0x0007FDCCuL,                                            \
      (CR_fc_uint32)0x00000100uL

   #define SIG_LEN_TABLE_SWE2                                                \
      (CR_fc_uint32)0x0000FDCCuL,                                            \
      (CR_fc_uint32)0x00000100uL
      
   #define SIG_LEN_TABLE_SWE3                                                \
      (CR_fc_uint32)0x00007DCCuL,                                            \
      (CR_fc_uint32)0x00000100uL

   #define SIG_LEN_TABLE                                                       \
      SIG_LEN_TABLE_SWE1, \
      SIG_LEN_TABLE_SWE2, \
      SIG_LEN_TABLE_SWE3

/* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/
#endif /* BOOTLOADER_CFG_HW_H                                            */

/*** End of file **************************************************************/
