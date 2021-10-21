/*******************************************************************************
**                                                                            **
**  SRC-MODULE: SysTimeClient.h                                               **
**                                                                            **
**  Copyright (C) BMW Group 2011                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Autosar Core                                              **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : header file of SysTimeClient module                           **
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
** mani         Markus Nirschl             EB Automotive                      **
** olho         Oliver Hoeft               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.2.1: 30.03.2011, olho: CR71019: Checked with MISRA 2004
 * V1.2.0: 05.02.2008, mani: reworked after review
 * V1.1.0: 21.12.2007, mani: adaptions for RTE usage
 * V1.0.0: 30.11.2007, mani: initial version based on SC6 Systime module 5.0.0
 */

/*******************************************************************************
**                      MISRA comments                                        **
*******************************************************************************/
/* Misra-C:2004 Deviation List:
  *
  * MISRA-1) Deviated Rule: 8.8 (required)
  *   An external object or function shall be declared in one and only one file.
  *
  *   Reason:
  *   In case of RTE a declaration of SysTimeClient_Init is needed for EcuM.
  */


#ifndef SYSTIMECLIENT_H
#define SYSTIMECLIENT_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"                               /* include AUTOSAR types */
#include "SysTimeClient_Cfg.h"            /* SysTimeClient configuration file */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/**** Version Macros ****/
#define SYSTIMECLIENT_MAJOR_VERSION   2u
#define SYSTIMECLIENT_MINOR_VERSION   1u
#define SYSTIMECLIENT_PATCH_VERSION   5u


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#define SYSTIMECLIENT_START_SEC_CODE
#include "MemMap.h"

/* Deviation MISRA-1 */
extern FUNC(void, SYSTIMECLIENT_PUBLIC_CODE) SysTimeClient_Init(void);

#if (SysTimeClientRte == STD_OFF)
   extern FUNC(void, SYSTIMECLIENT_PUBLIC_CODE) SysTimeClient_MainFunction(void);
   extern FUNC(Std_ReturnType, SYSTIMECLIENT_PUBLIC_CODE) SysTimeClient_GetTime(uint32 *currentTime);
#endif

#define SYSTIMECLIENT_STOP_SEC_CODE
#include "MemMap.h"


#endif /* SYSTIMECLIENT_H */

/*** End of file **************************************************************/
