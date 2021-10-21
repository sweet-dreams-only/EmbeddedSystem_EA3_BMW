/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_target.h                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Header file dedicated to file 'sc_target.c'. Implements the   **
**              extern definition of the functions and data implemented in    **
**              'sc_target.c'.                                                **
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
** hauf         Andreas Hauf               EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** miwe         Michael Weger              EB Automotive                      **
** masc         Marko Schneider            EB Automotive                      **
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
 * V3.4.2: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V3.4.1: 22.09.2010,   ft: CR70807: removed unnecessary inclusions of 
 *                                    v_cfg.h and v_def.h  
 * V3.4.0: 07.09.2010,   ft: CR70754: added missing compiler abstraction
 * V3.3.1: 27.01.2010, gema: CR70537: Template_can_Common: Compiler switches 
 *                                    shall have defined values 
 * V3.3.0: 07.07.2009, dabu: CR61622: added functions to set & get the BootMode
 * V3.2.0: 03.06.2009, hauf: CR61622: added ECC/CRC error flags to BootStatus
 *                                    removed EccErrorOccurred from BootStatus
 *                                    added function RomAccessExceptionHandler
 * V3.0.0: 27.10.2008, miwe: CR61489: extended BootMode flag to 64 bit
 * V2.1.0: 15.08.2008, masc: CR61432: added RAM ECC-error handling
 *                           CR61431: added Flash ECC-error handling
 * V2.0.0: 26.09.2006, olgo: added IsApplicationActive to BootStatusType for
 *                           runtime decision what application (Appl or BL) is
 *                           active
 *         05.04.2006, hauf: renamed section definitions
 *                           according to BMW programming guidelines
 *         17.03.2006, hauf: include diag.h instead of sc_types.h
 *         10.03.2006, miwe: MISRA checked
 *         27.02.2006, ke  : replaced setpragma.h with MemMap.h
 *         27.02.2006, miwe: unused function 'ScUnexpectedFault' removed
 * V1.2.0. 16.11.2005, miwe: 'Std_Types.h' include added
 * V1.1.0: 31.10.2005, miwe: missing 'setpragma' inlcudes added
 * V1.01 : 21.09.2005, olgo: BootStatusType added
 * V1.00 : 30.06.2005, hauf: made common between SC trees, cleared history
 */

#ifndef  SC_TARGET_H
#define  SC_TARGET_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "v_cfg.h"
#include <Std_Types.h>                     /* AUTOSAR Standard Types          */
#include "sc_target_arch.h"                /* include the 'sc_target' defines */
                                           /* which are HW dependant          */
#include "Diag_Types.h"                    /* for 'BOOT_MODE_LENGTH'          */
#include "BootManager_Cfg.h"               /* defines BM_MAX_NUMBER_OF_SWES   */
#include "AddressTable.h"                  /* contains sharedBootROMData      */

#define ISRDISPATCH_FLAG_BOOTLOADER   0xA5A5u
#define ISRDISPATCH_FLAG_APPLICATION  0x7B7Bu

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef uint16 IsrDispatchType;

/*
 * BootMode switches between application and bootloader; after startup in
 * bootloader, the mode is reset to application mode immediately. This prevents
 * unintended bootloader activations after reset.
 *
 * IsApplicationActive is set to TRUE within application startup and set to
 * FALSE within bootloader startup. After beeing set, this information is NOT
 * changed until next startup. It is used by the FEE jumptable.
 */

typedef struct
{

   #if ( SC_HANDLE_ECC == STD_ON )
      uint8 EccError[ CALC_REQUIRED_BYTES_FOR_MULTI_BYTE_BIT_ARRAY( BM_MAX_NUMBER_OF_SWES ) ];
                                            /* 0 = ok, 1 = ECC error occured  */
                                            /* Bit 0: Bootloader SWE          */
                                            /* Bit 1: Application SWE 1       */
                                            /* ...                            */
                                            /* Bit n: Application SWE n       */
   #endif

   #if ( SC_VERIFY_SWE_CRC_CHKSUM == STD_ON )
      uint8 CrcError[ CALC_REQUIRED_BYTES_FOR_MULTI_BYTE_BIT_ARRAY( BM_MAX_NUMBER_OF_SWES ) ];
                                            /* 0 = ok, 1 = CRC error occured  */
                                            /* Bit 0: Bootloader SWE          */
                                            /* Bit 1: Application SWE 1       */
                                            /* ...                            */
                                            /* Bit n: Application SWE n       */
   #endif

   uint8 BootMode[BOOT_MODE_LENGTH];
                                            /* Switches between application   */
                                            /* and bootloader                 */

   #if ( SC_FEE_ENABLE == STD_ON )
      boolean IsApplicationActive;
                                            /* TRUE : application mode        */
                                            /* FALSE: boot mode               */
   #endif

} BootStatusType;


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define BM_START_SEC_VAR_NOINIT_ISR_DISPATCH
#include "MemMap.h"

                                 /* contains Flag to dispatch interrupt table */
extern IsrDispatchType IsrDispatch;

#define BM_STOP_SEC_VAR_NOINIT_ISR_DISPATCH

#define BM_START_SEC_VAR_NOINIT_BOOT_STATUS
#include "MemMap.h"

/* Note: This area shall only contain one variable, because the linking
 *       processes for BM, BL and Appl may link this on different addresses
 *       otherwise.
 */

#ifdef BAC
extern VAR(BootStatusType, COMMON_VAR) BootStatus;      /* contains boot status information    */
#else
extern BootStatusType BootStatus;
#endif /* Defined BAC */

#define BM_STOP_SEC_VAR_NOINIT_BOOT_STATUS
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define BM_START_SEC_CODE
#include "MemMap.h"

#if ( SC_HANDLE_ECC == STD_ON )
   #ifdef BAC
      extern FUNC(uint32, COMMON_CODE) RomAccessExceptionHandler
          (
		     VAR(uint32, COMMON_APPL_DATA) codeAddress,
			 VAR(uint32, COMMON_APPL_DATA) dataAddress
		  );
   #else
   extern uint32 RomAccessExceptionHandler( uint32 codeAddress, uint32 dataAddress );
   #endif /* Defined BAC */
#endif

#if defined ( BOOTMANAGER )
   #ifdef BAC
      extern FUNC(BmBootModeType, COMMON_CODE) GetBootMode( void );
   #else
      extern BmBootModeType GetBootMode( void );
   #endif /* Defined BAC */
   #ifdef BAC
      extern FUNC(void, COMMON_CODE) SetBootMode
       (
	      VAR(BmBootModeType, COMMON_APPL_DATA) newBootMode
	   );
   #else
      extern void SetBootMode( BmBootModeType newBootMode );
   #endif /* Defined BAC */
#endif /* BOOTMANAGER */

#define BM_STOP_SEC_CODE
#include "MemMap.h"

#endif /* SC_TARGET_H                                                         */

/*** End of file **************************************************************/
