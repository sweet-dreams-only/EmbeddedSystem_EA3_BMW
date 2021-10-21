/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Hash.c                                                  **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Definitions for hash services.                                **
**                                                                            **
**  REMARKS   : Implementation of a hash algorithm as a high-level service    **
**              using the low-level cryptographic primitive of the Swt      **
**              in Swt_MD5.h.                                               **
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
#include "Swt_MD5.h"                        /* declarations of MD5 services */
#include "Swt_Hash.h"                      /* declarations of hash services */

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
**                       External Constants                                   **
*******************************************************************************/



/*******************************************************************************
**                       External Data                                        **
*******************************************************************************/


/*******************************************************************************
**                       Local Constants                                      **
*******************************************************************************/


/*******************************************************************************
**                       Local Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define SWT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ComputeHashInit                                     **
**                                                                            **
** DESCRIPTION    : Initialize the provided hash context.                     **
**                                                                            **
** PRECONDITIONS  : 'HashCtx' is a valid HashContextType pointer              **
**                            (not checked)                                   **
**                                                                            **
** POSTCONDITIONS : After return the context is initialized correctly for     **
**                  the first call of Swt_HashUpdate.                       **
**                                                                            **
** PARAMETER      : HashCtx : pointer to the context to initialise            **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if an invalid context-pointer was     **
**                                        given (debugcheck)                  **
**                  Swt_RC_OK, if the provided context is initialised       **
**                                                                            **
** TIMING         : Constant timing for all inputs.                           **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_ComputeHashInit
(
   CONSTP2VAR(Swt_HashContextType,AUTOMATIC,SC_FAR) HashCtx
)
{

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   if( 0 == HashCtx )                      /* Check if we got a valid context */
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_COMPUTE_HASH_INIT_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

                                                      /* Init the MD5 context */
   Swt_MD5Init( &(HashCtx->MD5Ctx) );

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
                                  /* Show that the context is initialized now */
   HashCtx->State = SWT_HASH_STATE_INITIALIZED;
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

   return Swt_RC_OK;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ComputeHashUpdate                                   **
**                                                                            **
** DESCRIPTION    : Updates the context HashCtx with the provided datablock.  **
**                                                                            **
** PRECONDITIONS  : 'HashCtx' shall be a valid pointer (not checked)          **
**                  'HashCtx' shall point to a valid HashContext that has     **
**                    been initialised by a successful call to the function   **
**                    Swt_ComputeHashInit() (not checked)                   **
**                  'Block' shall be a valid pointer (not checked)            **
**                  'Block' shall point to a readable region of memory of     **
**                    byte length at least 'BlockLength' bytes (not checked)  **
**                  'HashCtx->Count + BlockLength' shall not exceed the       **
**                    maximal amount of bytes that can be hashed using this   **
**                    MD5 algorithm (not checked)                             **
**                                                                            **
** POSTCONDITIONS : An updated hash context according to the provided data.   **
**                                                                            **
** PARAMETER      : HashCtx : Pointer to the Swt_HashContext to be updated  **
**                : Block : Pointer to the data to be hashed                  **
**                : BlockLength : Number of bytes to be hashed                **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if an invalid context-pointer or an   **
**                                        invalid data block were given       **
**                                        (debugcheck)                        **
**                  Swt_RC_INVALID_HASH_CONTEXT, if the context was not     **
**                                               initialized by a call of     **
**                                               Swt_HashInit (debugcheck)  **
**                  Swt_RC_OK, if the provided context was updated with     **
**                             BlockLength data bytes at address Block        **
**                                                                            **
** TIMING         : The timing is proportional to the number of bytes divided **
**                : by the Hash blocksize.                                    **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_ComputeHashUpdate
(
   CONSTP2VAR(Swt_HashContextType,AUTOMATIC,SC_FAR) HashCtx,
   CONSTP2CONST(uint8,AUTOMATIC,SC_FAR)     Block,
   const uint32            BlockLength
)
{
#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
                    /* Check if we got a valid context and a valid data block */
   if( (0 == HashCtx) || (0 == Block) )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_COMPUTE_HASH_UPDATE_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
   else
   {
                        /* Check whether the context is initialized correctly */
      if( HashCtx->State != SWT_HASH_STATE_INITIALIZED )
      {
                                               /* report the error to the DET */
         Det_ReportError
         (
            SWT_DET_MODULE_ID,
            (uint8)SWT_COMPUTE_HASH_UPDATE_API_ID,
            (uint8)Swt_RC_INVALID_HASH_CONTEXT
         );

         return Swt_RC_INVALID_HASH_CONTEXT;
      }
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

                                 /* Update MD5 context with the provided data */
   Swt_MD5Update( &(HashCtx->MD5Ctx), Block, BlockLength );

                                                          /* Return to caller */
   return Swt_RC_OK;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME      : Swt_ComputeHashFinalize                                 **
**                                                                            **
** DESCRIPTION    : Finalize the hash computation and determine the hash      **
**                  value represented by the provided context.                **
**                                                                            **
** PRECONDITIONS  : 'HashCtx' is a valid pointer (not checked)                **
**                  'HashCtx' shall point to a valid context that has been    **
**                    initialised by a successful call to the function        **
**                    Swt_ComputeHashInit() (not checked)                   **
**                  'Digest' shall be a valid pointer (not checked)           **
**                  'Digest' shall point to a writeable region of memory of   **
**                    length at least 16 bytes (not checked)                  **
**                                                                            **
** POSTCONDITIONS : The hashvalue of the processed data is given in 'Digest'. **
**                                                                            **
** PARAMETER      : HashCtx : Valid pointer to a context which was updated    **
**                   with the data of which the hashvalue should be           **
**                   computed.                                                **
**                  Digest : Valid pointer to 16 Bytes which will hold        **
**                           the hashvalue after the call.                    **
**                                                                            **
** RETURN         : Swt_RC_BAD_PARAM, if an invalid context-pointer or an   **
**                                        pointer for the digest were given   **
**                                        (debugcheck)                        **
**                  Swt_RC_INVALID_HASH_CONTEXT, if the context was not     **
**                                               initialized by a call of     **
**                                               Swt_HashInit (debugcheck)  **
**                  Swt_RC_OK, if the hash was written to the memory block  **
**                             'Digest'                                       **
**                                                                            **
** TIMING         : Constant time for all inputs.                             **
**                                                                            **
*******************************************************************************/
SwtRC_t Swt_ComputeHashFinalize
(
   CONSTP2VAR(Swt_HashContextType,AUTOMATIC,SC_FAR) HashCtx,
   CONSTP2VAR(uint8,AUTOMATIC,SC_FAR)           Digest
)
{
#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
   /* Check if we got a valid context and a valid memory block for the digest */
   if( (0 == HashCtx) || (0 == Digest) )
   {
                                               /* report the error to the DET */
      Det_ReportError
      (
         SWT_DET_MODULE_ID,
         (uint8)SWT_COMPUTE_HASH_FIN_API_ID,
         (uint8)Swt_RC_BAD_PARAM
      );

      return Swt_RC_BAD_PARAM;
   }
   else
   {
                        /* Check whether the context is initialized correctly */
      if( HashCtx->State != SWT_HASH_STATE_INITIALIZED )
      {
                                               /* report the error to the DET */
        Det_ReportError
         (
            SWT_DET_MODULE_ID,
            (uint8)SWT_COMPUTE_HASH_FIN_API_ID,
            (uint8)Swt_RC_INVALID_HASH_CONTEXT
         );

         return Swt_RC_INVALID_HASH_CONTEXT;
      }
   }
#endif                         /* if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON) */

                                                  /* Compute the final digest */
   Swt_MD5Finish( &(HashCtx->MD5Ctx), Digest );
                                                    /* Everything is/was fine */

   return Swt_RC_OK;
}
#define SWT_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                       Local Function Definitions                           **
*******************************************************************************/




/*** End of file **************************************************************/
