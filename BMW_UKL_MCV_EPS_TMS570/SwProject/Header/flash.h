/*******************************************************************************
**                                                                            **
**  SRC-MODULE: flash.h                                                       **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : MPC55xx                                                       **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : - Loading of HIS flash driver to RAM memory                   **
**              - Platform independent flash API functions                    **
**              - Invalidation of HIS flash driver code in RAM after usage    **
**                                                                            **
**  REMARKS   : The API is hardware independent                               **
**              The module itself may be hardware dependent                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
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
** dare         Daniel Reiss               EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.0.0: 04.10.2007, dare: ported from SC6.7.2 file version V3.0.1
 */

#ifndef FLASH_H
#define FLASH_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>          /* standard core data types                   */
                                /* type definitions in 'his_flash.h'. E.G.    */
                                /* 'UINT32'.                                  */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define LOADER_VERSION_MAJOR     0x03        /* loader major version number   */
#define LOADER_VERSION_MINOR     0x00        /* loader minor version number   */
#define LOADER_VERSION_PATCH     0x00        /* loader patch level number     */

#define FLASH_NOK                0x00u       /* status: operation failed      */
#define FLASH_OK                 0x01u       /* status: operation succeeded   */

#define FLASH_SRC_ADDR_ALIGN     0x04u       /*
                                              * the flash driver requires that
                                              * the 'sourceDataPtr' is
                                              * 'FLASH_SRC_ADDR_ALIGN' aligned
                                              */
#define FLASH_DEST_ADDR_ALIGN    0x08u       /*
                                              * the flash driver requires that
                                              * the 'destDataPtr' is
                                              * 'FLASH_DEST_ADDR_ALIGN' aligned
                                              */
#define FLASH_PAGE_SIZE          0x08u       /*
                                              * minimum page size that can be
                                              * written in one 'FlashWrite'
                                              * call
                                              */


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

typedef uint8  flashStatus_t;               /* runtime return status type     */
typedef uint8  flashKey_t;                  /* flash driver encryption key    */
                                            /* type                           */
typedef uint32 flashAddress_t;              /* target address type            */
typedef uint32 flashMemoryLength_t;         /* memory length type             */

#endif
