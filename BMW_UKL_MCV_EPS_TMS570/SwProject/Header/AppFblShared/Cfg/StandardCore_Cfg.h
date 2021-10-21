/*******************************************************************************
**                                                                            **
**  SRC-MODULE: StandardCore_Cfg.h                                            **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Modular make environment. Contains configuration parameters   **
**              which are used both by the bootloader and the application.    **
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
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.1.0: 16.11.2007, miwe: changed SC version to v7.0.0
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V2.1.2
 */

#ifndef STANDARDCORE_CFG_H
#define STANDARDCORE_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include <Std_Types.h>            /* AUTOSAR Standard Types */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/* this standardcore version makros are accessible by diagnosis               */
#define STANDARDCORE_MAJOR_VERSION 7u
#define STANDARDCORE_MINOR_VERSION 0u
#define STANDARDCORE_PATCH_VERSION 0u

#endif /* STANDARDCORE_CFG_H                                                  */

/*** End of file **************************************************************/

