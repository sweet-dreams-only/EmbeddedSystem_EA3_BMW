/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Nvm.c                                                     **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : BMW Group                                                     **
**                                                                            **
**  PURPOSE   : Declaration of SWT Nvm flags                                  **
**                                                                            **
**  REMARKS   : Nvm flags are global variables used in                        **
**              Swt_Appl.c, Swt_Handler.c and Swt_Full.c                      **
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
** cr           Christoph Raber            BMW AG                             **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0    : 19.01.2011, cr   : initial release
 */

#if (!defined SWT_NVM_H)           /* preprocessor exclusion definition */
#define SWT_NVM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Cfg.h"                        /* configuration of this module */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/
#define UpdateSwtNvm(valueNvm, valueStatus, memId)\
\
if (valueStatus != valueNvm)\
{\
   valueNvm = valueStatus;\
   memId = TRUE;\
}

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Constants                                      **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define SWT_START_SEC_VAR_NO_INIT
#include "MemMap.h"

extern boolean nvmSwtSwData;
extern boolean nvmSwtSwSigData;
#ifdef SWT_USE_SWT_FULL
extern boolean nvmSwtCertData;
#endif

#define SWT_STOP_SEC_VAR_NO_INIT
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif                                       /* if (!defined SWT_NVM_H) */
/*** End of file **************************************************************/
