/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Boot_Crypto.h                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
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
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0: 24.08.2007, miwe: ported from SC6.7.2 file version V5.0.0
 */

#if !defined( BOOT_CRYPTO_H )
#define BOOT_CRYPTO_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>           /* AUTOSAR Standard Types                    */
#include "Crypto_Cfg.h"          /* a&s configuration                         */
#include "cr_c_comp_specific.h"  /* compiler and platform specific settings   */
#include "cr_c_jumptable.h"      /* the jumptable                             */
#include "cr_s_auth.h"           /* symmetrical authentication and signature  */
#include "cr_a_controller.h"     /* asymmetrical authentication and signature */
#include "cr_c_random.h"         /* pseudo random number generator            */
#include "cr_a_data.h"           /* asymmetric external declarations          */
#include "cr_c_data.h"           /* common external declarations              */
#include "cr_s_data.h"           /* symmetric external declarations           */


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

extern void Crypto_Init (void);

#endif                                                       /* BOOT_CRYPTO_H */

/*** End of file **************************************************************/

