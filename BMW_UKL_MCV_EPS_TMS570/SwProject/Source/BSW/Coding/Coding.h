/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Coding.h                                                      **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Header file of coding module                                  **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDENT [yes/no]: no                                           **
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
** thmi         Themistoklis Mirkos        EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.4: 15.02.2011, thmi: CR70905: updated MISRA comments to MISRA 2004
 * V1.1.3: 11.02.2011, thmi: make declaration of Coding_MainFunction() in
 *                           Coding.h depend on using RTE, to avoid rendundant
 *                           redeclaration in generated Rte_Coding.h
 * V1.1.2: 30.06.2009, hauf: changed module version
 * V1.1.0: 27.03.2009, hauf: CR70090: increased module minor version
 * V1.0.0: 30.11.2007, hauf: ported from SC6.7.2 file version V4.1.0
 */

#ifndef CODING_H
#define CODING_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR standard types                   */
#include <Coding_Cfg.h>           /* Configuration file of coding module      */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*
 * File version information
 */
#define CODING_H_MAJOR_VERSION        2u
#define CODING_H_MINOR_VERSION        2u
#define CODING_H_PATCH_VERSION        5u


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define CODING_START_SEC_CODE
#include "MemMap.h"

   extern FUNC(void, CODING_PUBLIC_CODE)
               Coding_Init( void );

#if ( (CODING_RTE_ENABLE != STD_ON) || !(defined CODING_C) )
   extern FUNC(void, CODING_PUBLIC_CODE)
               Coding_MainFunction( void );
#endif

   extern FUNC(void, CODING_PUBLIC_CODE)
               Coding_CheckSignatureOnShutdown( void );

#define CODING_STOP_SEC_CODE
#include "MemMap.h"


#endif /* CODING_H                                                            */

/*** End of file **************************************************************/
