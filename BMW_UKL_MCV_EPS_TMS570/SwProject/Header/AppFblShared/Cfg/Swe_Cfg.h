/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swe_Cfg.h                                                     **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Swe Configuration File                                        **
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
 * V1.0.3: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V1.0.2: 21.02.2011,   ft: CR70956: DataFlash exception handling can
 *                                    not be extended platform specific  
 * V1.0.1: 27.01.2010, gema: CR70537: Template_can_Common: Compiler switches 
 *                                    shall have defined values 
 * V1.0.0: 08.07.2009, dabu: CR61622: initial version
 */


#ifndef  SWE_CFG_H
#define  SWE_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"          /* AUTOSAR standard includes                  */
#include "sc_types.h"           /* contains StandardCore types and macros     */
#include "sc_target.h"          /* contains RomAccessExceptionHandler         */
#include "AddressTable.h"       /* contains sharedBootROMData                 */

#ifdef BOOTMANAGER
   #include "Crc.h"             /* contains function to calculate CRC         */
   #include "wdg.h"             /* contains watchdog trigger function         */
   /*#include "wdgif.h"*/             /* contains watchdog trigger function         */
   #include "BootManager_Cfg.h" /* contains CRC check settings                */

   #ifdef BOOTMANAGER_TEST_ENABLE
      #if ( BOOTMANAGER_TEST_ENABLE == STD_ON )
         #include "Bootmanager_Test.h"
      #endif
   #endif
#endif

#if ( defined BOOTMANAGER ) || ( defined BOOTLOADER )
   #include "Bootloader_Cfg.h"  /* needed for SWENUMBEROFBOOTSWE              */
#endif /* ( defined BOOTMANAGER ) || (defined BOOTLOADER )                    */

#ifndef BOOTMANAGER
	#define ECC_FEE_NOTIFICATION()	
#endif /* BOOTMANAGER */

/*******************************************************************************
**                      Mapping of external API                               **
*******************************************************************************/

#ifdef BOOTMANAGER
	#define flashAddress_t uint32
#else
	#define flashAddress_t flashAddress_t
#endif /* BOOTMANAGER */

/* WDT functions                                                              */
#define SWE_WatchdogTrigger()                         (void)WdgIf_Trigger(WDG_INDEX)

/* CRC functions                                                              */
#define SWE_Crc_CalculateCRC32 ( p1,p2,p3 )           Crc_CalculateCRC32 ( p1,p2,p3 )

/* sc_target functions                                                        */
#define SWE_MAP_RomAccessExceptionHandler( p1, p2 )   RomAccessExceptionHandler( p1, p2 )


#endif /* SWE_CFG_H                                                           */

/*** End of file **************************************************************/


