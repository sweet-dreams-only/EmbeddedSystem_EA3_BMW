/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Common.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions of common services for the Swt                  **
**                                                                            **
**  REMARKS   : This file contains commonly used code for the module Swt.   **
**              Most of these functions are fallback functions for memory     **
**              handling using non-standard pointers, like far/huge pointers. **
**              It is used internally by the crypto routines, the parser and  **
**              the handler.                                                  **
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
** fs           Frank Stamm                Elektrobit Automotive GmbH         **
** mg           Matthias Galota            Elektrobit Automotive GmbH         **
** djk          Daniel Karl                Elektrobit Automotive GmbH         **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V0.9.0    : 28.11.2006, mg   : initial release
 * V1.0.0    : 16.03.2007, mg   : first release of SWT Light/Full/Short
 * V2.1.0    : 10.09.2007, djk  : nothing changed
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Swt_Cfg.h"                        /* configuration of this module */
#include "Swt_Types.h"                              /* types of this module */
#include "Swt_Common.h"                  /* declarations of common services */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constants                                      **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Local Constants                                       **
*******************************************************************************/

/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define SWT_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CommonCompare                                       **
**                                                                            **
** DESCRIPTION    : Compares two memory blocks byte-wise                      **
**                                                                            **
** PRECONDITIONS  : - BlockA is a valid pointer (debugcheck)                  **
**                  - BlockB is a valid pointer (debugcheck)                  **
**                  - BlockA points to a region of memory of                  **
**                    byte length 'ByteLength' (not checked)                  **
**                  - BlockB points to a region of memory of                  **
**                    byte length 'ByteLength' (not checked)                  **
**                                                                            **
** POSTCONDITIONS : none                                                      **
**                                                                            **
** PARAMETER      : BlockA     - pointer to the first block to compare        **
**                  BlockB     - pointer to the second block to compare       **
**                  ByteLength - byte length of both blocks                   **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM :                                      **
**                     parameter was invalid (debugcheck)                     **
**                  Swt_RC_EQUAL         : memory blocks are equal          **
**                  Swt_RC_NOT_EQUAL     : memory blocks are not equal      **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : depends on input data. This function uses an 'early exit' **
**                  on the first byte the blocks differ                       **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CommonCompare
(
   CONSTP2CONST(void,AUTOMATIC,SC_FAR)  BlockA,
   CONSTP2CONST(void,AUTOMATIC,SC_FAR)  BlockB,
   const uint32        ByteLength
)
{
   SwtRC_t RetVal;                                          /* return value */
   uint32_least Len;                                 /* internal length index */

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if ((0 == BlockA) || (0 == BlockB))                  /* null pointer check */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_COMMON_COMPARE_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }                                                    /* NULL pointer check */
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   RetVal = Swt_RC_EQUAL;                    /* initialize the return value */
   Len = (uint32_least)0;                          /* initialize local length */
                                                /* loop over the block length */
   while ((Len < ByteLength) && (RetVal == Swt_RC_EQUAL))
   {
                                                         /* compare byte-wise */
      if (((P2CONST(uint8,AUTOMATIC,SC_FAR))BlockA)[Len] !=
          ((P2CONST(uint8,AUTOMATIC,SC_FAR))BlockB)[Len])

      {
         RetVal = Swt_RC_NOT_EQUAL;
      }                                    /* if (BlockA[Len] != BlockB[Len]) */
      ++Len;                                               /* go to next byte */
   }               /* while ((Len > (uint16)0) && (RetVal == Swt_RC_EQUAL)) */

   return RetVal;
}                                            /* SwtRC_t Swt_CommonCompare */

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_CommonCopy                                          **
**                                                                            **
** DESCRIPTION    : Performs a byte-wise copy of memory blocks                **
**                                                                            **
** PRECONDITIONS  : - Src is a valid pointer (debugcheck)                     **
**                  - Dest is a valid pointer (debugcheck)                    **
**                  - Src points to a region of memory of                     **
**                    byte length 'ByteLength' (not checked)                  **
**                  - Src points to a region of memory of                     **
**                    byte length 'ByteLength' (not checked)                  **
**                                                                            **
** POSTCONDITIONS : the memory block pointed to by Sec has been copied        **
**                  to the location pointed at by Dest                        **
**                                                                            **
** PARAMETER      : Dest       - pointer to the destination memory block      **
**                  Src        - pointer to the source memory block           **
**                  ByteLength - byte-length of both blocks                   **
**                                                                            **
** RETURN         : Swt_RC_OK        : operation successful                 **
**                  Swt_RC_BAD_PARAM :                                      **
**                     a parameter was invalid (debugcheck)                   **
**                                                                            **
** REMARKS        :                                                           **
**                                                                            **
** TIMING         : constant for all input.                                   **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_CommonCopy
(
   CONSTP2VAR(void,AUTOMATIC,SC_FAR)        Dest,
   CONSTP2CONST(void,AUTOMATIC,SC_FAR)  Src,
   const uint32        ByteLength
)
{
   uint32_least Len;                                 /* internal length value */

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if ((0 == Dest) || (0 == Src))                       /* null pointer check */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_COMMON_COPY_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }                                                    /* null pointer check */
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   Len = (uint32_least)0;                       /* loop over the block length */
   while (Len < ByteLength)
   {
                                                            /* copy byte-wise */
      ((P2VAR(uint8,AUTOMATIC,SC_FAR))Dest)[Len] =
                                    ((P2CONST(uint8,AUTOMATIC,SC_FAR))Src)[Len];
      ++Len;                                               /* go to next byte */
   }                                              /* while (Len < ByteLength) */

   return Swt_RC_OK;
}                                               /* SwtRC_t Swt_CommonCopy */
#define SWT_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/

/*** End of file **************************************************************/
