/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_c_cancel.h                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : a cancel routine for code canceling                           **
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
** jd           Jochen Decker              3SOFT                              **
** mg           Matthias Galota            3SOFT                              **
** am           Alexander Much             3SOFT                              **
** sc           Juergen Scherg             3SOFT                              **
** fs           Frank Stamm                3SOFT                              **
** gema         Markus Gerngross           MB Technology                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V5.0.1: 27.01.2010, gema: CR70529: Crypto: Compiler switches shall have 
 *                                    defined values
 * V5.0.0: 21.09.2006, mg : code clean-ups
 *         11.08.2006, mg : added cancelation functionality
 */

#if !defined( CR_C_CANCEL_H )
#define CR_C_CANCEL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"                           /* a&s configuration        */
#include "cr_c_data.h"                            /* the variable CR_C_cancel */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#if (CR_DEF_USE_CANCEL == STD_ON)

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Crypto_Cancel                                              **
**                                                                            **
** DESCRIPTION   : Sets the global variable CR_C_cancel to TRUE. Other        **
**                 functions query this variable to see whether they should   **
**                 cancel their computations.                                 **
**                                                                            **
** PRECONDITIONS : none                                                       **
**                                                                            **
** PARAMETERS    : none                                                       **
**                                                                            **
** RETURN        : none                                                       **
**                                                                            **
** REMARKS       : none                                                       **
**                                                                            **
*******************************************************************************/
#define Crypto_Cancel() (CR_C_cancel = TRUE)



               /* Return from a cancelled function and reset the cancel flag. */
#define CR_C_CheckCancelRequest()                                              \
if (CR_C_cancel != FALSE)                                                      \
{                                                                              \
   CR_C_cancel = FALSE;                                                        \
   return CR_C_RC_CANCELED;                                                    \
}

              /* Return if the RetVal is "CR_C_RC_CANCELED".                  */
#define CR_C_RETURN_IF_CANCELED(RetVal)                                          \
if ((RetVal) == CR_C_RC_CANCELED)                                              \
{                                                                              \
   return CR_C_RC_CANCELED;                                                    \
}


#else         /* #if (CR_DEF_USE_CANCEL == STD_ON)                                */

              /* Do not use any of the cancel routines.                       */
#define Crypto_Cancel()
#define CR_C_CheckCancelRequest()
#define CR_C_RETURN_IF_CANCELED(RetVal)

#endif        /* #if (CR_DEF_USE_CANCEL == STD_ON) #else                          */


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif                                        /* if !defined( CR_C_CANCEL_H ) */
/*** End of file **************************************************************/
