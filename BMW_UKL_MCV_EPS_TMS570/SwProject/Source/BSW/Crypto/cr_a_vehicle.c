/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_a_vehicle.c                                                **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : asymmetrical authentication and signature check               **
**                                                                            **
**  REMARKS   :                                                               **
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
 *         11.08.2006, mg : added cancelation functionality, modified macro
 *                          syntax, made functions return immediately
 *                          after an error, improved formatting, removed
 *                          mem_util
 * V4.1.0: 22.06.2006, mg : no changes
 * V4.0.0: 03.04.2006, mg : moved configuration options to Crypto_Cfg.h, key
 *                          length configurable independently for authentication
 *                          and signature, cleaned up cr_c_hash.c,
 *                          removed compiler warnings
 *         22.02.2006, fs : added coding functions
 * V3.3.1: 11.11.2005, jd : added support for TriCore, ST30, MAC7100 and MB91
 * V3.3.0: 28.10.2005, jd : adapted to programming guidelines 1.6.1,
 *                          incorporated memory mappings of SC6.5,
 *                          added jumptable for access from application space
 * V3.2.1: 22.07.2005, mg : adapted header files for SC6
 * V3.2.0: 22.07.2005, am : changed type infrastructure from a mixed near/far
 *                          environment to a pure far API
 * V3.1.0: 03.05.2005, mg : adapted file header
 * V3.0.0: 17.02.2005, am : adopted to SC4, MISRA cleanups
 * V2.0.0: 08.10.2004, sc : Adoption from Acryl 2.1. Adapted to 16 bit CPUs.
 */

/**************************************************************************************************************************/
/* Nxtr Version Control:
 *---------------------------------------------------------------------------------------------------------------------
 *   Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 10/05/16   EA3#3     ABS        Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
 * 10/05/16   EA3#4     ABS        Authentication and Signature changes - review comments update			 EA3#7986
**************************************************************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */
#include "cr_a_mexp.h"             /* long number arithmetic                  */
#include "cr_a_vehicle.h"          /* asymmetric vehicle base routine decls   */
#include "cr_a_data.h"             /* container for asymmetric keys           */
#include "cr_c_random.h"           /* random generation routine declarations  */
#include "cr_c_hash.h"             /* hash routines                           */
#include "cr_c_cancel.h"           /* cancelation of computation              */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/* Local data type for state buffer in interruptible mode for subroutine      */
/* CR_A_CheckAuth()                                                           */
typedef union
{
   /* all local variables which have to be saved on interruption must be      */
   /* allocated in this structure                                             */
   struct
   {
      uint8 nResume;      /* finishing flag; must be first byte in structure  */
      uint8 h;            /* return code in interruption mode                 */
   } s;
   uint8 state[CR_DEF_AA_MEXP_STATESIZE];        /* guarantees minimum length */
} CR_LCL_AuthIntrBuffer_t;


/* Local data type for state buffer in interruptible mode for subroutine      */
/* CR_A_CheckSig()                                                            */
typedef union
{
   /* all local variables which have to be saved on interruption must be      */
   /* allocated in this structure                                             */
   struct
   {
      uint8 nResume;      /* finishing flag; must be first byte in structure  */
      uint8 h;            /* return code in interruption mode                 */
   } s;
   uint8 state[CR_DEF_CHECK_SIG_STATESIZE];      /* guarantees minimum length */
} CR_LCL_SigIntrBuffer_t;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Local Data                                            **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Prototypes                             **
*******************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "MemMap.h"

TS_STATIC_FUNCTION CR_C_RC_t CR_A_CompareResult
(
   CR_fpc_uint32 comp32,
   CR_cfpc_uint8 comp8
);

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CR_A_CompareResult                                         **
**                                                                            **
** DESCRIPTION   : this routine performs a byte-wise compare of the           **
**                 16 8-bit values pointed to by 'comp8' with the 4           **
**                 4-byte words pointed to by 'comp32'                        **
**                                                                            **
** PRECONDITIONS : pointer must be valid, and reference to accessible memory. **
**                                                                            **
** PARAMETERS    : comp32 - pointer to a 32-bit array of length 4             **
**                 comp8  - pointer to a 8-bit array of length 16             **
**                                                                            **
** RETURN        : CR_C_RC_OK  - on success                                   **
**                 CR_C_RC_ERR - on mismatch on result comparison             **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_A_CompareResult
(
   CR_fpc_uint32  comp32,
   CR_cfpc_uint8  comp8
)
{
   uint8_least i;                        /* loop counter                      */
   uint8_least j;                        /* loop counter                      */
   uint8_least k;                        /* storage for loop invariant (i*4)  */
   uint32 TempWord;                      /* temporary 32-bit storage          */

   i = 0;                                /* start with first 4-byte word      */
   do                                    /* loop over four words              */
   {
      TempWord = comp32[i + 1];          /* save word into local storage      */
      k        = i << 2U;                /* loop invariant: i * 4             */
      j        = 0;                      /* start with first byte of the word */
      do
      {
         if (comp8[k + j]  !=            /* do a byte-wise comparison         */
             (uint8)(TempWord & (uint32)0xff))
         {
            return CR_C_RC_ERR;          /* comparison failed: return error   */
         }
         TempWord >>= 8U;                /* compare next byte of the word     */
         ++j;                            /* go to next byte                   */
      } while (j != 4);
      ++i;                               /* go to next word                   */
   } while (i != 4);

   return CR_C_RC_OK;
}

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CR_A_CheckAuth                                             **
**                                                                            **
** DESCRIPTION   : this routine checks if the result of the response          **
**                 'response' encrypted with the given key elements is        **
**                 identical to the given challenge 'challenge'.              **
**                                                                            **
** PRECONDITIONS : pointer must be valid, and reference to accessible memory. **
**                                                                            **
** PARAMETERS    : cycleCount   - cycle counter, if using interupted mode.    **
**                                In non-interupted mode, the value must be 0 **
**                 challenge    - challenge, valid and allocated data array   **
**                 response     - response which has to be checked            **
**                 keyModulus   - modulus of RSA public key                   **
**                 keyPublicExp - exponent of RSA public key                  **
**                 keyBarrett   - barrett element of RSA public key           **
**                 state        - state buffer for interruption mode. will be **
**                                used on interrupted mode to save the        **
**                                internal state to complete the calculation  **
**                                on the next call, which must be called with **
**                                the same state-buffer content.              **
**                                If used in non-interrupted mode, the routine**
**                                must be called with state value 0 (NULL).   **
**                                                                            **
** RETURN        : CR_C_RC_OK       - on success                              **
**                 CR_C_RC_NF       - if not finished on return               **
**                 CR_C_RC_ERR      - on mismatch on result comparison        **
**                 CR_C_RC_CANCELED - if the computation has been canceled    **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
CR_C_RC_t CR_A_CheckAuth
(
   uint16        cycleCount,
   CR_fpc_uint8  challenge,
   CR_fpc_uint32 response,
   CR_fpc_uint32 keyModulus,
   CR_fpc_uint32 keyPublicExp,
#if (CR_DEF_USE_BARRETT == STD_ON)  /* activate if based on barrett               */
   CR_fpc_uint32 keyBarrett,
#endif                          /* if (CR_DEF_USE_BARRETT == STD_ON)              */
   CR_fp_uint8   state
)
{
   CR_C_RC_t RetVal;            /* return value                               */
#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )
    CR_LCL_AuthIntrBuffer_t u;  /* interruption buffer                        */
#endif                          /* CR_DEF_USE_INTERRUPTION                    */

   /* initialise variables */
   RetVal = CR_C_RC_OK;

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )

   if (state != CR_NULL)        /* check if we really want to use interr.     */
   {
      if (state[0] != 0)        /* check if this routine has been re-entered  */
      {
                                /* restore saved state to proceed calculation */
         (void)CR_C_memcpy
               (
                  (CR_fp_void)&u,
                  (CR_fp_void)state,
                  (uint16)CR_DEF_CHECK_AUTH_STATESIZE
               );
      }
      else                      /* not re-entered, first time here            */
      {
                                /* reset the current state                    */
         state[CR_DEF_CHECK_AUTH_STATESIZE] = 0;
      }

                                /* do the exponentiation                      */
#if (CR_DEF_USE_BARRETT == STD_ON)
      RetVal = CR_A_NewAaMExp
               (
                  cycleCount,
                  response,
                  keyPublicExp,
                  (CR_fp_uint32)CR_A_s2.resp_e,
                  keyModulus,
                  keyBarrett,
                  (CR_fp_uint32)CR_A_s2.tmp,
                  (CR_fp_uint8)&state[CR_DEF_CHECK_AUTH_STATESIZE]
               );
#else                           /* if (CR_DEF_USE_BARRETT == STD_ON)              */
      RetVal = CR_A_NewAaMExp
               (
                  cycleCount,
                  response,
                  keyPublicExp,
                  (CR_fp_uint32)CR_A_s2.resp_e,
                  keyModulus,
                  (CR_fp_uint32)CR_A_s2.tmp,
                  (CR_fp_uint8)&state[CR_DEF_CHECK_AUTH_STATESIZE]
               );
#endif                          /* if (CR_DEF_USE_BARRETT == STD_ON)              */

      /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED.  */
      CR_C_RETURN_IF_CANCELED(RetVal);

                                /* check if we are finished                   */
      if (RetVal == CR_C_RC_NF)
      {                         /* not finished                               */
         u.s.nResume = 1;
                                /* save the current state                     */
         (void)CR_C_memcpy
               (
                  (CR_fp_void)state,
                  (CR_fp_void)&u,
                  (uint16)CR_DEF_CHECK_AUTH_STATESIZE
               );
         RetVal = CR_C_RC_NF;   /* return "not finished"                      */
      }
      else                      /* we are finished, check the result          */
      {
         if (CR_A_s2.resp_e[0] != 4)     /* response length must be 4         */
         {
            RetVal = CR_C_RC_ERR;        /* return an error                   */
         }
         else                            /* response length ok                */
         {
                                         /* compare the result                */
            RetVal = CR_A_CompareResult((CR_fp_uint32)CR_A_s2.resp_e,challenge);
         }
         state[0] = 0;                   /* stop the interruption; we're done */
      }
   } else
   {
#endif  /* (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) */

                                         /* calculate the exponentiation      */
#if (CR_DEF_USE_BARRETT == STD_ON)
      RetVal = CR_A_NewAaMExp
               (
                  cycleCount,
                  response,
                  keyPublicExp,
                  (CR_fp_uint32)CR_A_s2.resp_e,
                  keyModulus,
                  keyBarrett,
                  (CR_fp_uint32)CR_A_s2.tmp,
                  (CR_fp_uint8)CR_NULL
               );
#else                                    /* if (CR_DEF_USE_BARRETT == STD_ON)     */
      RetVal = CR_A_NewAaMExp
               (
                  cycleCount,
                  response,
                  keyPublicExp,
                  (CR_fp_uint32)CR_A_s2.resp_e,
                  keyModulus,
                  (CR_fp_uint32)CR_A_s2.tmp,
                  (CR_fp_uint8)CR_NULL
               );
#endif                                   /* if (CR_DEF_USE_BARRETT == STD_ON)     */

      /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED.  */
      CR_C_RETURN_IF_CANCELED(RetVal);

      /* ----- NXTR PATCH START -----
       * Added by: K. Smith (Nxtr)
       * Date Added: 30Sep16
       *
       * Reason: The hash method change from MD5 to SHA256. This has a hash length of 8 uint32
       * byte values, so the 4 needed to change to an 8.
       */
	  #if 0
      /* ----- Original Code Start ----- */
                  /* compare resp_e with challenge, length must be equal to 4 */
      if (CR_A_s2.resp_e[0] != 4)
      {
         return CR_C_RC_ERR;             /* length wrong: return an error     */
      }
      /* ----- Original Code End ----- */
      #endif
      /* ----- Patch Code Start ----- */
      if (CR_A_s2.resp_e[0] != 8)
	  {
    	return CR_C_RC_ERR;             /* length wrong: return an error     */
	  }
      /* ----- Patch Code End ----- */
      /* ----- NXTR PATCH END ----- */

                                         /* compare the result                */
      RetVal = CR_A_CompareResult((CR_fp_uint32)CR_A_s2.resp_e,challenge);
#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )
   }
#endif  /* (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) */
   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CR_A_CheckSig                                              **
**                                                                            **
** DESCRIPTION   : this routine verifies the signature on an multi-element    **
**                 data-array. the whole text will be hashed. the signature   **
**                 will be exponentiated with the given key, and then both    **
**                 results compared for being equal.                          **
**                                                                            **
** PRECONDITIONS : pointer must be valid, and reference to accessible memory. **
**                                                                            **
** PARAMETERS    : numBlocks    - number of data blocks in textPtr            **
**                 textPtr      - field of data blocks                        **
**                 length       - field of length information for each        **
**                                element in textPtr                          **
**                 signature    - signature for checking                      **
**                 keyModulus   - modulus of RSA public key                   **
**                 keyPublicExp - exponent of RSA public key                  **
**                 keyBarrett   - barrett element of RSA public key           **
**                 cycleCount   - cycle counter, if using interupted mode.    **
**                                In non-interupted mode, the value must be 0 **
**                 state        - state buffer for interruption mode. will be **
**                                used on interrupted mode to save the        **
**                                internal state to complete the calculation  **
**                                on the next call, which must be called with **
**                                the same state-buffer content.              **
**                                If used in Non-Interrupted mode, the routine**
**                                must be called with state value 0 (NULL).   **
**                                                                            **
** RETURN        : CR_C_RC_OK       - on success                              **
**                 CR_C_RC_NF       - if not finished on return               **
**                 CR_C_RC_ERR      - invalid signature                       **
**                 CR_C_RC_CANCELED - if the computation has been canceled    **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
CR_C_RC_t CR_A_CheckSig
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint32   signature,
   CR_fpc_uint32   keyModulus,
   CR_fpc_uint32   keyPublicExp,
#if (CR_DEF_USE_BARRETT == STD_ON)              /* activate if based on barrett   */
   CR_fpc_uint32   keyBarrett,
#endif                                      /* if (CR_DEF_USE_BARRETT == STD_ON)  */
   uint16          cycleCount,
   CR_fp_uint8     state
)
{
   CR_C_RC_t RetVal;                        /* return value                   */
#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )
   CR_LCL_SigIntrBuffer_t u;                /* interruption buffer            */
#endif

   RetVal = CR_C_RC_OK;                     /* initialise the return value    */

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )

   if (state != CR_NULL)                          /* state buffer valid?            */
   {
      if (state[0] != 0)                    /* check if we are re-entered now */
      {
                  /* restore local state from previous calculation            */
         (void)CR_C_memcpy
               (
                  (CR_fp_void)&u,
                  (CR_fp_void)state,
                  (uint16)CR_DEF_CHECK_SIG_STATESIZE
               );
                  /* did the calculation finish last time?                    */
         if (state[CR_DEF_CHECK_SIG_STATESIZE] != 0)
         {
                  /* no, still work to do. continue the calculation           */
            RetVal = CR_C_hash
                     (
                        (CR_fp_uint16)&cycleCount,
                        numBlocks,
                        textPtr,
                        length,
                        (CR_fp_uint8)CR_A_s2.hashres,
                        (CR_fp_uint8)&state[CR_DEF_CHECK_SIG_STATESIZE]
                     );

            /* Has the sub-function been canceled? Then return.               */
            CR_C_RETURN_IF_CANCELED(RetVal);
         }
      }
      else        /* we are not reentered, first call                         */
      {
                  /* reset local state                                        */
         state[CR_DEF_CHECK_SIG_STATESIZE] = 0;
                  /* start calculation                                        */
         RetVal = CR_C_hash
                  (
                     (CR_fp_uint16)&cycleCount,
                     numBlocks,
                     textPtr,
                     length,
                     (CR_fp_uint8)CR_A_s2.hashres,
                     (CR_fp_uint8)&state[CR_DEF_CHECK_SIG_STATESIZE]
                  );

         /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED*/
         CR_C_RETURN_IF_CANCELED(RetVal);

      }
                  /* check if hash routine was interupted and did not finish  */
      if (RetVal == CR_C_RC_NF)
      {
                  /* function not finished, only interrupted. set resume flag */
         u.s.nResume = 1;
                  /* save local state for next call                           */
         (void)CR_C_memcpy
               (
                  (CR_fp_void)state,
                  (CR_fp_void)&u,
                  (uint16)CR_DEF_CHECK_SIG_STATESIZE
               );
      }
      else        /* hash routine finished without interruption               */
      {
                  /* calculate the exponentiation                             */
#if (CR_DEF_USE_BARRETT == STD_ON)
         RetVal = CR_A_NewAaMExp
                  (
                     cycleCount,
                     signature,
                     keyPublicExp,
                     (CR_fp_uint32)CR_A_s2.sig_e,
                     keyModulus,
                     keyBarrett,
                     (CR_fp_uint32)CR_A_s2.tmp,
                     (CR_fp_uint8)&state[CR_DEF_CHECK_SIG_STATESIZE +
                                         CR_DEF_HASH_STATESIZE]
                  );
#else             /* if (CR_DEF_USE_BARRETT == STD_ON)                            */
         RetVal = CR_A_NewAaMExp
                  (
                     cycleCount,
                     signature,
                     keyPublicExp,
                     (CR_fp_uint32)CR_A_s2.sig_e,
                     keyModulus,
                     (CR_fp_uint32)CR_A_s2.tmp,
                     (CR_fp_uint8)&state[CR_DEF_CHECK_SIG_STATESIZE +
                                         CR_DEF_HASH_STATESIZE]
                  );
#endif            /* if (CR_DEF_USE_BARRETT == STD_ON)                            */

         /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED*/
         CR_C_RETURN_IF_CANCELED(RetVal);

                  /* check if subroutine was interrupted and not finished     */
         if (RetVal == CR_C_RC_NF)
         {
                  /* mark local state also as not finished                    */
            u.s.nResume = 1;
                  /* save local state for next call                           */
            (void)CR_C_memcpy
                  (
                     (CR_fp_void)state,
                     (CR_fp_void)&u,
                     (uint16)CR_DEF_CHECK_SIG_STATESIZE
                  );

            return CR_C_RC_NF;
         }
         else     /* exponentiation was not interrupted                       */
         {
                  /* check if length of result is correct                     */
        	/* ----- NXTR PATCH START -----
        	 * Added By: K. Smith (Nxtr)
        	 * Date Added: 27Sep16
        	 *
        	 * Reason: The hash method change from MD5 to SHA256. This has a hash length of 8 uint32
             * byte values, so the 4 needed to change to an 8.
        	 */
            #if 0
         	/* ----- Original Code Start ----- */
            if (CR_A_s2.sig_e[0] != 4)
            {
                  /* wrong length of sig_e                                    */
               return CR_C_RC_ERR;
            }
        	/* ----- Original Code End ----- */
            #endif
         	/* ----- Patch Code Start ----- */
        	if (CR_A_s2.sig_e[0] != 8)
            {
                  /* wrong length of sig_e                                    */
               return CR_C_RC_ERR;
            }
        	/* ----- Patch Code End ----- */
        	/* ----- NXTR PATCH END ----- */

                  /* return value of comparison                               */
            RetVal = CR_A_CompareResult
                     (
                        (CR_fp_uint32)CR_A_s2.sig_e,
                        (CR_fp_uint8)CR_A_s2.hashres
                     );
         }
                  /* finish interruption: we are finished                     */
         state[0] = 0;
      }
   }
   else           /* if (state != CR_NULL)                                    */
   {

#endif  /* (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) */

                 /* calculate the hash over the given parameters              */
      RetVal = CR_C_hash
               (
                  (CR_fp_uint16)&cycleCount,
                  numBlocks,
                  textPtr,
                  length,
                  (CR_fp_uint8)CR_A_s2.hashres,
                  (CR_fp_uint8)CR_NULL
               );

      /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED.  */
      CR_C_RETURN_IF_CANCELED(RetVal);
                 /* calculate the exponentiation                              */
#if (CR_DEF_USE_BARRETT == STD_ON)
      RetVal = CR_A_NewAaMExp
               (
                  (uint16)0,
                  signature,
                  keyPublicExp,
                  (CR_fp_uint32)CR_A_s2.sig_e,
                  keyModulus,
                  keyBarrett,
                  (CR_fp_uint32)CR_A_s2.tmp,
                  (CR_fp_uint8)CR_NULL
               );
#else            /* if (CR_DEF_USE_BARRETT == STD_ON)                             */
      RetVal = CR_A_NewAaMExp
               (
                  (uint16)0,
                  signature,
                  keyPublicExp,
                  (CR_fp_uint32)CR_A_s2.sig_e,
                  keyModulus,
                  (CR_fp_uint32)CR_A_s2.tmp,
                  (CR_fp_uint8)CR_NULL
               );
#endif           /* if (CR_DEF_USE_BARRETT == STD_ON)                             */

      /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED.  */
      CR_C_RETURN_IF_CANCELED(RetVal);

      /* ----- NXTR PATCH START -----
       * Added by: Archana Shivarudrappa (Nxtr)
       * Date Added: 7Oct16
       *
       * Reason: The hash method change from MD5 to SHA256. This has a hash length of 8 uint32
       * byte values, so the 4 needed to change to an 8.
       */

	#if 0
      /* Original code - START */
      if (CR_A_s2.sig_e[0] != 4)
      {
         return CR_C_RC_ERR;
      }
      /* Original code - END */
	#endif

      /* Patch code  - START */
      if (CR_A_s2.sig_e[0] != 8)
      {
         return CR_C_RC_ERR;
      }
      /* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/
      RetVal = CR_A_CompareResult
               (
                  (CR_fp_uint32)CR_A_s2.sig_e,
                  (CR_fp_uint8)CR_A_s2.hashres
               );

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )
   }
#endif

   return RetVal;
}
#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/

