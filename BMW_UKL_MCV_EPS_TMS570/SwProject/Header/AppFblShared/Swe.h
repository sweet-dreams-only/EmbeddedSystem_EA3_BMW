/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swe.h                                                         **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : SWE access functions                                          **
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
** hauf         Hauf Andreas               EB Automotive                      **
** dabu         Daniel Buder               EB Automotive                      **
** gema         Markus Gerngross           MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.1.1: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V2.1.0: 07.09.2010,   ft: CR70747: added missing compiler abstraction
 * V2.0.1: 27.01.2010, gema: CR70537: Template_can_Common: Compiler switches 
 *                                    shall have defined values 
 * V2.0.0: 07.07.2009, dabu: CR61622: mapping of external API
 * V1.0.0: 03.06.2009, hauf: CR61622: initial version
 */

#ifndef SWE_H
#define SWE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"          /* Autosar standard types                     */
#include "Swe_Cfg.h"            /* Swe configuration file                     */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#if ( defined BOOTMANAGER ) || ( defined BOOTLOADER )

#define SWE_ID_OF_BOOT_SWE    0u
#define SWE_ID_OF_APPL_SWE1   SWENUMBEROFBOOTSWE

#if ( SC_HANDLE_ECC == STD_ON )
   #define Swe_GetEccErrorFlagOfSwe( sweId )                                   \
      ( GET_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootStatus.EccError, sweId ) != 0u )
   #define Swe_SetEccErrorFlagOfSwe( sweId )                                   \
      SET_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootStatus.EccError, sweId )
   #define Swe_ClearEccErrorFlagOfSwe( sweId )                                 \
      CLEAR_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootStatus.EccError, sweId )
#endif
#if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
   #define Swe_GetCrcErrorFlagOfSwe( sweId )                                   \
      ( GET_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootStatus.CrcError, sweId ) != 0u )
   #define Swe_SetCrcErrorFlagOfSwe( sweId )                                   \
      SET_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootStatus.CrcError, sweId )
   #define Swe_ClearCrcErrorFlagOfSwe( sweId )                                 \
      CLEAR_BIT_IN_MULTI_BYTE_BIT_ARRAY( BootStatus.CrcError, sweId )
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef enum
{
   SWE_VALID_STATE_INVALID    = 0x00u,
   SWE_VALID_STATE_VALID_SWFL = 0x01u,
   SWE_VALID_STATE_VALID_BTLD = 0x02u,
   SWE_VALID_STATE_UNCHECKED  = 0x03u
} SweValidStateType;


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#ifdef BAC
   extern FUNC(SweValidStateType, COMMON_CODE) Swe_GetValidStateOfSwe
         (
	        VAR(uint8, COMMON_APPL_DATA) sweNumber
	     );
#else
extern SweValidStateType   Swe_GetValidStateOfSwe( uint8 sweNumber );
#endif /* Defined BAC */
#ifdef BAC
   extern FUNC(SweValidStateType, COMMON_CODE) Swe_GetValidStateOfApplSwes( void );
#else
extern SweValidStateType   Swe_GetValidStateOfApplSwes( void );
#endif /* Defined BAC */
#ifdef BAC
   extern FUNC(SweProgDepStateType, COMMON_CODE) Swe_GetProgDepStateOfApplSwes( void );
#else
extern SweProgDepStateType Swe_GetProgDepStateOfApplSwes( void );
#endif /* Defined BAC */

#endif /* ( defined BOOTMANAGER ) || (defined BOOTLOADER )                    */

#ifdef BOOTMANAGER
   #if ( SC_HANDLE_ECC == STD_ON ) || ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
      #ifdef BAC
         extern FUNC(void, COMMON_CODE) Swe_InitErrorFlagsOfAllSwes( void );
      #else
      extern void Swe_InitErrorFlagsOfAllSwes( void );
      #endif /* Defined BAC */
   #else
      #define Swe_InitErrorFlagsOfAllSwes()
   #endif
#endif

#if ( SC_HANDLE_ECC == STD_ON )
   #ifdef BAC
      extern FUNC(uint32, COMMON_CODE) Swe_RomAccessExceptionHandler
             ( 
		        VAR(uint32, COMMON_APPL_DATA) codeAddress, 
			    VAR(uint32, COMMON_APPL_DATA) dataAddress 
	         );
   #else
      extern uint32 Swe_RomAccessExceptionHandler
	         (
                uint32 codeAddress, 
				uint32 dataAddress 
			 );
   #endif /* Defined BAC */
#endif

#endif /* SWE_H                                                               */

/*** End of file **************************************************************/
