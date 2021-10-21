/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Bac_Compiler_Cfg.h                                            **
**                                                                            **
**  Copyright (C) BMW Group 2010                                              **
**                                                                            **
**  TARGET    : S12X                                                          **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : MB Technology                                                 **
**                                                                            **
**  PURPOSE   : Memory section mapping for BMW-Modules                        **
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
** fw           Frank Waehner              MB Technology                      **
** ft           Florian Tausch             MB Technology                      **
** ep			Erik Pusch                 Richard Bader GmbH                 **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V7.0.7: 25.11.2010, ep: CR70741  LED: Missing or incomplete compiler abstraction
 * V7.0.6: 25.11.2010, ep: CR70719: BAC 3.0 Bootmanager: BM_BasicInitialisation
 *                                  without functionality
 * V7.0.5: 12.09.2010, ft: CR70750: added symbols for compiler
                                    abstraction (APPLICATION, BOOTMANAGER)
 * V7.0.4: 09.09.2010, ft: CR70733: added symbols for compiler
                                    abstraction (BLU)
 * V7.0.3: 09.09.2010, ft: CR70754: added some more symbols for compiler
                                    abstraction (BOOTLOADER, TESTCLIENT)
 * V7.0.2: 03.09.2010, ft: CR70740: added symbol FREETIMER_CONST for compiler
                                    abstraction
 * V7.0.1: 03.09.2010, ft: CR70739: added FREETIMER defines for compiler
                                    abstraction
 * V7.0.0: 25.08.2010, fw: completely revised and unified according CR#70792
 */

#ifndef BAC_COMPILER_CFG_H
#define BAC_COMPILER_CFG_H

/****************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*==== DATALOGISTIC BMW Bac 2.1 =======================================================*/
#define DATALOGISTIC_CONST
#define DATALOGISTIC_SVK_HISTORY
#define SHAREDBOOTROMDATA_CONST

/* To be used for locating the flag indicating bootloader startup when shutting down the application => EcuM_Callout_Stubs.c */
#define APPLBOOT_SHARED_RAM

#define SC_TARGET_CODE

#define BOOT_STATUS_RAM

#define COMMON_VAR

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* BAC_COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler_Cfg.h
 *********************************************************************************************************************/

/************   Organi, Version 3.8.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.8.0 Vector-Informatik GmbH  ************/
