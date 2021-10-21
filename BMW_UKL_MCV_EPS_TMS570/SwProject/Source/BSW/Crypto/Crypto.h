/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Crypto.h                                                      **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
*******************************************************************************/

#ifndef CRYPTO_H
#define CRYPTO_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types                   */

#if defined( BOOTLOADER )
# include <Boot_Crypto.h>         /* include Crypto API                       */
#else
# include <Appl_Crypto.h>         /* include Crypto API                       */
#endif

#endif /* CRYPTO_H                                                            */

/*** End of file **************************************************************/
