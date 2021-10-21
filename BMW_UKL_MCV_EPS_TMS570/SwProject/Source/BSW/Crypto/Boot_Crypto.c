/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Boot_Crypto.c                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : types and data structures for accessing jumptable             **
**                                                                            **
**  REMARKS   : CRYPTO_JUMPTABLE_ADDR defines address for jump table, it      **
**              must point to the same address used by the bootloader         **
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
** miwe         Michael Weger              EB Automotive                      **
** anht         Andreas Hartmann           EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.1: 20.06.2008, anht: CR61399: Use TRUE/FALSE instead of 0/1 for
 *                                    assignments to cr_c_cancel
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version 5.1.0
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "Boot_Crypto.h"          /* Jumptable types                          */


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  Crypto_Init                                               **
**                                                                            **
** DESCRIPTION   :  initialies the crypto module                              **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :  void                                                      **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  This function is used to make sure the jumptable is not   **
**                  optimized away.                                           **
**                                                                            **
*******************************************************************************/
void Crypto_Init (void)
{

#if (SC_BOOT_CRYPTO_ENABLE == ON)
   /* A dummy variable. It is not used anywhere.                              */
   volatile struct Crypto_JumpTable_s Dummy_Crypto_JumpTable;

   /* The contents of the jumptable are assigned to the dummy variable. This  */
   /* is done so that the jumptable is not optimized away.                    */
   Dummy_Crypto_JumpTable = Crypto_JumpTable;

#if (CR_DEF_USE_CANCEL == ON)
   CR_C_cancel = FALSE;
#endif

#endif   /* SC_BOOT_CRYPTO_ENABLE == ON */

}

/*** End of file **************************************************************/
