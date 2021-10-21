/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_target_arch.c                                              **
**                                                                            **
**  Copyright (C) BMW Group 2010                                              **
**                                                                            **
**  TARGET    : S12x                                                          **
**                                                                            **
**  PROJECT   : BMW AUTOSAR Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Implements architecture specific Standard Core template       **
**              functions that are used both by the bootloader and the        **
**              application.                                                  **
**                                                                            **
**  REMARKS   : Architecture specific functions that are used only by the     **
**              template-application are implemented in file                  **
**              'application_arch.c'.                                         **
**              Architecture specific functions that are used only by the     **
**              template-bootloader are implemented in file                   **
**              'bootloader_arch.c'.                                          **
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
** miwe         Michael Weger              EB Automotive                      **
** ke           Kai Esbold                 EB Automotive                      **
** olgo         Oliver Gorisch             EB Automotive                      **
** gema         Gerngross Markus           MB-technology                      **
** tr           Thomas Rösch               Richard Bader GmbH                 **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.0.2: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V3.0.1: 14.04.2011,   tr: CR70826 Vector Release 10 Update for all Tools
 * V3.0.0: 13.07.2009, gema: CR70254: boardDataStorageException and 
 *                                    boardDataStorageUserException deleted 
 *                                    moved SC_FlASH_tag to Board.h (Global)
 *                                   (will be done actually in sc_Target.c)
 * V2.1.0: 08.09.2008, ke  : CR61431: boardDataStorageException added
 *                                    boardDataStorageUserException added
 *         02.09.2008, olgo: CR61431: separated bootloader and bootmanager
 * V2.0.0: 27.02.2008, miwe: moved ResetECU() to bootloader_arch, because it's
 *                           not used by the Application
 *         20.11.2007, miwe: integration of MCU driver
 * V1.0.0: 24.09.2007, miwe: ported from SC6.7.2 file version V5.3.0
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "sc_target_arch.h"       /* own header file                          */
#include "sc_target.h"            /* variable BootStatus                      */
#include "Bootloader_Cfg.h"       /* Bootloader configuration                 */
#include "AddressTable.h"         /* Address Table                            */


/*******************************************************************************
**                      Local Register Definitions                            **
*******************************************************************************/




/*** End of file **************************************************************/
