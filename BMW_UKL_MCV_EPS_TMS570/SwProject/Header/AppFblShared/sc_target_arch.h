/*******************************************************************************
**                                                                            **
**  SRC-MODULE: sc_target_arch.h                                              **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : MPC55xx                                                       **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Header file dedicated to 'sc_target_arch.c'. Contains         **
**              architecture specific parameters and extern definitions which **
**              are used both by the bootloader and the application.          **
**                                                                            **
**  REMARKS   : ---                                                           **
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
** miwe     Michael Weger           EB Automotive                      **
** ke         Kai Esbold                 EB Automotive                      **
** gema		Gerngross Markus	 		MB-technology			    			**
** ep           Erik Pusch                 R. Bader GmbH                      **
** pego         Peter Golzem               R. Bader GmbH                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V3.0.2: 07.07.2011, pego: CR71054: Application/Common: Mark sample code in() 
 *                                    file header of every concerned file.  
 * V3.0.1: 14.04.2011,   ep: CR70998: Remove references to MPC55xx in BAC 3.0
 * V3.0.0: 13.07.2009, gema: CR70254: boardDataStorageException and 
 *                                    boardDataStorageUserException deleted 
 *							      (will be done actually in sc_Target.c)
 * V2.1.0: 08.09.2008, ke  : CR61431: boardDataStorageException added
 *                                    boardDataStorageUserException added
 * V2.0.0: 27.02.2008, miwe: moved ResetECU() to bootloader_arch, because it's
 *                           not used by the Application
 * V1.0.0: 24.09.2007, miwe: ported from SC6.7.2 file version V4.1.0
 */

#ifndef  SC_TARGET_ARCH_H
#define  SC_TARGET_ARCH_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <string.h>               /* memcpy, memcmp, ...                      */
#include <Std_Types.h>            /* AUTOSAR Standard Types                   */
#include "sc_types.h"             /* Standard Core types                      */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/******************** memcpy **************************************************/
/* void *memcpy(void *s1, const void *s2, size_t n);                          */
#define SC_MEMCPY_ROM memcpy     /* 'memcpy' function used copy from ROM to   */
                                 /* RAM. Some architectures need a special    */
                                 /* 'memcpy' to copy from 'far ROM' to        */
                                 /* 'near RAM' addresses.                     */

/* void *memcpy(void *s1, const void *s2, size_t n);                          */
#define SC_MEMCPY     memcpy     /* Default definition. Used to copy from     */
                                 /* 'near' to 'near' addresses.               */

/******************** memcmp **************************************************/
/* int memcmp(const void *s1, const void *s2, size_t n);                      */
#define SC_MEMCMP_ROM memcmp     /* 'memcmp' function used to compare data in */
                                 /* far memory                                */
                                 /* Some architectures need a special 'memcmp'*/
                                 /* to compare between 'far ROM' and 'near    */
                                 /* RAM' addresses.                           */

/* int memcmp(const void *s1, const void *s2, size_t n);                      */
#define SC_MEMCMP     memcmp     /* Default definition. Used to compare       */
                                 /* between 'near' and 'near' addresses.      */

/******************** memmove *************************************************/
/* void *memmove(void *s1, const void *s2, size_t n);                         */
#define SC_MEMMOVE    memmove    /* moves 'n' bytes from pointer 's2' to 's1'.*/
                                 /* overlapping of the areas is supported     */

/******************** memset **************************************************/
/* void *memset(void *s, int c, size_t n);                                    */
#define SC_MEMSET_ROM memset     /* sets 'n' bytes in far array with the      */
                                 /* 'value' of the parameter                  */
                                 /* void *memset(void *s, int c, size_t n);   */
/* void *memset(void *s, int c, size_t n);                                    */
#define SC_MEMSET     memset     /* sets 'n' bytes in array with the 'value'  */
                                 /* of the parameter                          */
                                 /* void *memset(void *s, int c, size_t n);   */

/******** ConvertExtAddress2IntPointer / ConvertIntPointer2ExtAddress *********/
/* uint32 ConvertExtAddress2IntPointer(uint32 extAddress);                    */
/* uint32 ConvertIntPointer2ExtAddress(uint32 intPointer);                    */
/* Converts a logical block number sent by the tester (e.g. a pointer to a    */
/* SWE table) to an internal (far) pointer and vice versa.                    */
/*                                                                            */
/* nothing to do on 32 bit platforms                                          */
/*                                                                            */
#define ConvertExtAddress2IntPointer(extAddress)   ((uint32)extAddress)
#define ConvertIntPointer2ExtAddress(intPointer)   ((uint32)intPointer)

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

#endif /* SC_TARGET_ARCH_H                                                    */

/*** End of file **************************************************************/
