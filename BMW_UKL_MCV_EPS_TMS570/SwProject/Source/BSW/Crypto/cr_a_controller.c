/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_a_controller.c                                             **
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
 *         11.08.2006, mg : added cancelation functionality, modified macro
 *                          syntax, using DET, made functions return immediately
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

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Crypto_Cfg.h"            /* a&s configuration                       */
#include "cr_c_comp_specific.h"    /* compiler and platform specific settings */
#include "cr_a_controller.h"       /* controller auth routines declarations   */
#include "cr_a_vehicle.h"          /* asymmetric vehicle base routines        */
#include "cr_c_hash.h"             /* hash routines                           */
#include "cr_c_random.h"           /* random generation routines              */
#include "cr_a_data.h"             /* container for asymmetric keys           */
#include "cr_c_cancel.h"           /* cancelation of computation              */

#if (CR_DEF_USE_LEVEL0 == STD_ON)
   #include "cr_oa_teleservice.h"  /* optional teleservice routines           */
#endif                             /* if (CR_DEF_USE_LEVEL0 == STD_ON)            */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/* There are three data blocks in the authentication process:                 */
/*   - the user ID                                                            */
/*   - the controller ID                                                      */
/*   - the challenge                                                          */
#define CR_DEF_NO_OF_AUTH_BLOCKS 3


/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

/* Local data type for state buffer in interruptable mode for subroutine      */
/* Crypto_CheckAuthUStg()                                                     */
typedef union
{
   /* all local variables which have to be saved on interruption must be      */
   /* allocated in this structure                                             */
   struct
   {
      uint8 resume;        /* finishing-flag. must be first byte in structure */
      uint8 dummy;         /* not used. only for bad compilers                */
   } s;
   uint8 state[CR_DEF_CHECK_AUTH_STATESIZE];     /* guarantees minimum length */
} CR_LCL_ControllerAuthIntrBuffer_t;

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

TS_STATIC_FUNCTION CR_C_RC_t CR_ST_CheckAuthLevel
(
   uint32 const  level,
   uint16        cycleCount,
   CR_fpc_uint32 response,
   CR_fp_uint8   subStateBuffer
);

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : CR_ST_CheckAuthLevel                                       **
**                                                                            **
** DESCRIPTION   : reformatter to call CR_A_CheckAuth()                       **
**                                                                            **
** PRECONDITIONS : pointer must be valid, and reference to accessible memory. **
**                                                                            **
** PARAMETERS    : level      - authentication level                          **
**                 cycleCount - cycle counter, if using interupted mode.      **
**                               In non-interupted mode, the value must be 0. **
**                 response   - response which has to be checked              **
**                 subStateBuffer - state buffer for interruption mode. will  **
**                               be used on interrupted mode to save the      **
**                               internal state to complete the calculation   **
**                               on the next call, which must be called with  **
**                               the same state-buffer content.               **
**                               If used in Non-Interrupted mode, the routine **
**                               must be called with state value 0 (NULL).    **
**                                                                            **
** RETURN        : CR_C_RC_LVL    if called level is not supported/defined    **
**                 return values of CR_A_CheckAuth()                          **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_ST_CheckAuthLevel
(
   uint32 const  level,
   uint16        cycleCount,
   CR_fpc_uint32 response,
   CR_fp_uint8   subStateBuffer
)
{
   CR_C_RC_t RetVal;                    /* return value                       */

   switch (level)                       /* determine the authentication level */
   {
#if (CR_DEF_USE_LEVEL0 == STD_ON)           /* authentication check for level 0   */
      case 0:
         RetVal = CR_A_CheckAuth (cycleCount,
                                  (CR_fp_uint8)CR_A_s2.chall_u_stg,
                                  response,
                                  (CR_fp_uint32)CR_A_sts0.AUTH_U_STG_L0_m,
                                  (CR_fp_uint32)CR_A_sts0.AUTH_U_STG_L0_pe,
   #if (CR_DEF_USE_BARRETT == STD_ON)
                                  (CR_fp_uint32)CR_A_sts0.AUTH_U_STG_L0_bv,
   #endif                               /* if (CR_DEF_USE_BARRETT == STD_ON)      */
                                  subStateBuffer);
         break;
#endif                                  /* if (CR_DEF_USE_LEVEL0 == STD_ON)       */

#if (CR_DEF_USE_LEVEL1 == STD_ON)           /* authentication check for level 1   */
      case 1:
         RetVal = CR_A_CheckAuth (cycleCount,
                                  (CR_fp_uint8)CR_A_s2.chall_u_stg,
                                  response,
                                  (CR_fp_uint32)CR_A_s1.AUTH_U_STG_L1_m,
                                  (CR_fp_uint32)CR_A_s1.AUTH_U_STG_L1_pe,
   #if (CR_DEF_USE_BARRETT == STD_ON)
                                  (CR_fp_uint32)CR_A_s1.AUTH_U_STG_L1_bv,
   #endif                               /* if (CR_DEF_USE_BARRETT == STD_ON)      */
                                  subStateBuffer);
         break;
#endif                                  /* if (CR_DEF_USE_LEVEL1 == STD_ON)       */

#if (CR_DEF_USE_LEVEL2 == STD_ON)           /* authentication check for level 2   */
      case 2:
         RetVal = CR_A_CheckAuth (cycleCount,
                                  (CR_fp_uint8)CR_A_s2.chall_u_stg,
                                  response,
                                  (CR_fp_uint32)CR_A_s1.AUTH_U_STG_L2_m,
                                  (CR_fp_uint32)CR_A_s1.AUTH_U_STG_L2_pe,
   #if (CR_DEF_USE_BARRETT == STD_ON)
                                  (CR_fp_uint32)CR_A_s1.AUTH_U_STG_L2_bv,
   #endif                               /* if (CR_DEF_USE_BARRETT == STD_ON)      */
                                  subStateBuffer);
         break;
#endif                                  /* if (CR_DEF_USE_LEVEL2 == STD_ON)       */

#if (CR_DEF_USE_LEVEL3 == STD_ON)           /* authentication check for level 3   */
      case 3:
         RetVal = CR_A_CheckAuth (cycleCount,
                                  (CR_fp_uint8)CR_A_s2.chall_u_stg,
                                  response,
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L3_m,
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L3_pe,
   #if (CR_DEF_USE_BARRETT == STD_ON)
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L3_bv,
   #endif                               /* if (CR_DEF_USE_BARRETT == STD_ON)      */
                                  subStateBuffer);
         break;
#endif                                  /* if (CR_DEF_USE_LEVEL3 == STD_ON)       */

#if (CR_DEF_USE_LEVEL4 == STD_ON)           /* authentication check for level 4   */
      case 4:
         RetVal = CR_A_CheckAuth (cycleCount,
                                  (CR_fp_uint8)CR_A_s2.chall_u_stg,
                                  response,
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L4_m,
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L4_pe,
   #if (CR_DEF_USE_BARRETT == STD_ON)
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L4_bv,
   #endif                               /* if (CR_DEF_USE_BARRETT == STD_ON)      */
                                  subStateBuffer);
         break;
#endif                                  /* if (CR_DEF_USE_LEVEL4 == STD_ON)       */

#if (CR_DEF_USE_LEVEL5 == STD_ON)           /* authentication check for level 5   */
      case 5:
         RetVal = CR_A_CheckAuth (cycleCount,
                                  (CR_fp_uint8)CR_A_s2.chall_u_stg,
                                  response,
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L5_m,
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L5_pe,
   #if (CR_DEF_USE_BARRETT == STD_ON)
                                  (CR_fp_uint32)CR_A_s3.AUTH_U_STG_L5_bv,
   #endif                               /* if (CR_DEF_USE_BARRETT == STD_ON)      */
                                  subStateBuffer);
         break;
#endif                                  /* if (CR_DEF_USE_LEVEL5 == STD_ON)       */

      default:                          /* bad level value                    */
         RetVal = CR_C_RC_LVL;
         break;
   }

   return RetVal;
}


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Crypto_CheckAuthUStg                                       **
**                                                                            **
** DESCRIPTION   : Autentification tester controller element.                 **
**                 This routine checks if the decrypted response is           **
**                 identical to the hash of the concatenation of challenge,   **
**                 user-id and controller id.                                 **
**                 The used key is level dependent.                           **
**                                                                            **
** PRECONDITIONS : Pointer must be valid, and reference to accessible memory. **
**                                                                            **
** PARAMETERS    : challenge  - challenge, valid and allocated data array     **
**                 userID     - user id                                       **
**                 controllerID - controller ID                               **
**                 cycleCount - cycle counter, if using interupted mode.      **
**                               In non-interupted mode, the value must be 0. **
**                 level      - authentication level                          **
**                 response   - response, which has to be checked             **
**                 state      - state buffer for interruption mode. will      **
**                               be used on interrupted mode to save the      **
**                               internal state to complete the calculation   **
**                               on the next call, which must be called with  **
**                               the same state-buffer content.               **
**                               If used in Non-Interrupted mode, the routine **
**                               must be called with state value 0 (NULL).    **
**                                                                            **
** RETURN        : CR_C_RC_ERR    on failure                                  **
**                 CR_C_RC_NF     if interruptible and not finished           **
**                 CR_C_RC_LVL    if called level is not supported/defined    **
**                 return values of CR_A_CheckAuth()                          **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
CR_C_RC_t Crypto_CheckAuthUStg
(
   CR_fpc_uint8  challenge,
   CR_fpc_uint8  userID,
   CR_fpc_uint8  controllerID,
   uint16        cycleCount,
   uint32 const  level,
   CR_fpc_uint32 response,
   CR_fp_uint8   state
)
{
   CR_C_RC_t     RetVal;                              /* return value         */
   CR_fpc_uint8  textPtr[CR_DEF_NO_OF_AUTH_BLOCKS];   /* data blocks          */
   uint32        length[CR_DEF_NO_OF_AUTH_BLOCKS];    /* sizes of data blocks */

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )
   CR_LCL_ControllerAuthIntrBuffer_t u;               /* interruption buffer  */
   CR_fp_uint8 subStateBuffer;                        /* pointer to substate  */
#endif               /* if (CR_DEF_USE_INTERRUPTION == STD_ON) && ...             */


#if (CR_DEV_ERROR_DETECT == STD_ON)
                                   /* check if the signature pointer is valid */
   if
   (
     (((challenge == CR_NULL)      ||
       (userID == CR_NULL))        ||
       (controllerID == CR_NULL))  ||
       (response == CR_NULL)
   )
   {
       Det_ReportError
       (
          CR_DET_MODULE_ID,
          (uint8)CR_CONTROLLER_CHECKAUTHUSTG_ID,
          (uint8)CR_C_RC_ERR
       );

       return CR_C_RC_ERR;
   }
#endif                                /* if (CR_DEV_ERROR_DETECT == STD_ON)       */

   RetVal = CR_C_RC_OK;               /* initialise the return value          */

   /* Concatenate user ID, controller ID, and challenge for hashing.          */

   /* Create the array containing the lengths of the data blocks              */
   length[0] = 4;                     /* initialise size of the user id       */
   length[1] = 4;                     /* initialise size of the controller id */
   length[2] = 8;                     /* initialise size of the challenge     */

   /* Create the array containing pointers to the starts of the data blocks.  */
   textPtr[0] = userID;
   textPtr[1] = controllerID;
   textPtr[2] = challenge;

#if (CR_DEF_USE_INTERRUPTION == STD_ON) && \
    (CR_DEF_USE_TRIGGER_COP == STD_OFF)

   if (state != CR_NULL)              /* do we have an interruption state?    */
   {
      subStateBuffer = &state[CR_DEF_CHECK_AUTH_U_STG_STATESIZE];
      if (state[0] != 0)              /* check if we are re-entered now       */
      {
                                      /* restore state from previous call     */
         (void)CR_C_memcpy
               (
                  (CR_fp_void)&u,
                  (CR_fp_void)state,
                  (uint16)CR_DEF_CHECK_AUTH_U_STG_STATESIZE
               );
      }
      else                            /* not re-entered, first call           */
      {
                                      /* check correct response length        */
         if (response[0] >= (uint32)CR_DEF_AUTH_KEY_LENGTH)
         {
            return CR_C_RC_ERR;       /* not correct, return an error         */
         }

         /* Hash the concatenated pUserId, pnControllerId, and challenge and  */
         /* store the result in CR_A_s2.chall_u_stg. Do not use interruption  */
         /* during the hash computation.                                      */
         RetVal = CR_C_hash
                  (
                     (CR_fp_uint16)CR_NULL,
                     (uint32)CR_DEF_NO_OF_AUTH_BLOCKS,
                     (CR_fpcfpc_uint8)textPtr,
                     (CR_fp_uint32)length,
                     (CR_fp_uint8)CR_A_s2.chall_u_stg,
                     (CR_fp_uint8)CR_NULL
                  );

         /* Has the sub-function been canceled? Then return.                  */
         CR_C_RETURN_IF_CANCELED(RetVal);

                                       /* reset CR_A_check_auth_u_stg() state */
         state[CR_DEF_CHECK_AUTH_U_STG_STATESIZE] = 0;

      }

                                       /* check authentication level          */
      RetVal = CR_ST_CheckAuthLevel
               (
                  level,
                  cycleCount,
                  response,
                  subStateBuffer
               );

      /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED.  */
      CR_C_RETURN_IF_CANCELED(RetVal);

                                 /* check if the subfunction was not finished */
      if (RetVal == CR_C_RC_NF)
      {
         u.s.resume = 1;         /* mark own state as not finished            */

                                 /* save state                                */
         (void)CR_C_memcpy
               (
                  (CR_fp_void)state,
                  (CR_fp_void)&u,
                  (uint16)CR_DEF_CHECK_AUTH_U_STG_STATESIZE
               );

         return CR_C_RC_NF;     /* return not finished                        */
      }
      else       /* finish the interruption mechanism                         */
      {
         state[0] = 0;                        /* mark own state as "finished" */
                 /* implicitely return the return value of CheckAuthLevel()   */
      }
   }
   else          /* no state given: check without interruption                */
   {

#endif  /* (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) */

                                 /* check authentication without interruption */

                                 /* length of response valid?                 */
      if (response[0] >= (uint32)CR_DEF_AUTH_KEY_LENGTH)
      {
         return CR_C_RC_ERR;     /* no, return an error                       */
      }

      /* Hash the concatenated pUserId, pnControllerId, and challenge and     */
      /* store the result in CR_A_s2.chall_u_stg.                             */
      RetVal = CR_C_hash
               (
                  (CR_fp_uint16)CR_NULL,
                  (uint32)CR_DEF_NO_OF_AUTH_BLOCKS,
                  (CR_fpcfpc_uint8)textPtr,
                  (CR_fp_uint32)length,
                  (CR_fp_uint8)CR_A_s2.chall_u_stg,
                  (CR_fp_uint8)CR_NULL
               );

      /* Has the sub-func. been canceled? Then return with CR_C_RC_CANCELED.  */
      CR_C_RETURN_IF_CANCELED(RetVal);

      RetVal = CR_ST_CheckAuthLevel
               (
                  level,
                  cycleCount,
                  response,
                  (CR_fp_uint8)CR_NULL
               );

#if ( (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) )
   }
#endif  /* (CR_DEF_USE_INTERRUPTION == STD_ON) && (CR_DEF_USE_TRIGGER_COP == STD_OFF) */

   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Crypto_CheckSigSW                                          **
**                                                                            **
** DESCRIPTION   : this subroutine checks the signature of a software,        **
**                 which can be split to different blocks in textPtr.         **
**                 the signature check uses the software signature key.       **
**                                                                            **
** PRECONDITIONS : pointer must be valid, and reference to accessible memory. **
**                                                                            **
** PARAMETERS    : numBlocks  - number of data blocks in textPtr              **
**                 textPtr    - field of data blocks                          **
**                 length     - field of length-information for each element  **
**                 signature  - signature for checking                        **
**                 cycleCount - cycle counter, if using interupted mode.      **
**                               In non-interupted mode, the value must be 0. **
**                 state      - state buffer for interruption mode. will be   **
**                               used on interrupted mode to save the         **
**                               internal state to complete the calculation   **
**                               on the next call, which must be called with  **
**                               the same state-buffer content.               **
**                               If used in Non-Interrupted mode, the routine **
**                               must be called with state value 0 (NULL).    **
**                                                                            **
** RETURN        : CR_C_RC_ERR       if invalid signature                     **
**                 return code of func CR_A_CheckSig() else                   **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
CR_C_RC_t Crypto_CheckSigSW
(
    uint32 const    numBlocks,
    CR_fpcfpc_uint8 textPtr,
    CR_fpc_uint32   length,
    CR_fpc_uint32   signature,
    uint16          cycleCount,
    CR_fp_uint8     state
)
{

#if (CR_DEV_ERROR_DETECT == STD_ON)
                        /* check if the signature pointer is valid            */
   if (signature == CR_NULL)
   {
       Det_ReportError
       (
          CR_DET_MODULE_ID,
          (uint8)CR_CONTROLLER_CHECKSIGSW_ID,
          (uint8)CR_C_RC_ERR
       );

       return CR_C_RC_ERR;
   }
#endif                    /* if (CR_DEV_ERROR_DETECT == STD_ON)                   */


                        /* check if the length of the signature is too big    */
   if (signature[0] >= (uint32)CR_DEF_SIG_KEY_LENGTH)
   {
      return CR_C_RC_ERR;
   }

                        /* check signature                                    */
   return CR_A_CheckSig
          (
             numBlocks,
             textPtr,
             length,
             signature,
             (CR_fp_uint32)CR_A_s4.SIG_SW_m,
             (CR_fp_uint32)CR_A_s4.SIG_SW_pe,
#if (CR_DEF_USE_BARRETT == STD_ON)
             (CR_fp_uint32)CR_A_s4.SIG_SW_bv,
#endif                  /* if (CR_DEF_USE_BARRETT == STD_ON)                      */
             cycleCount,
             state
          );
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     : Crypto_CheckSigNCD                                         **
**                                                                            **
** DESCRIPTION   : this subroutine checks the signature of coding data,       **
**                 which can be split to different blocks in textPtr.         **
**                 the signature check uses the coding signature key.         **
**                                                                            **
** PRECONDITIONS : pointer must be valid, and reference to accessible memory. **
**                                                                            **
** PARAMETERS    : numBlocks  - number of data blocks in textPtr              **
**                 textPtr    - field of data blocks                          **
**                 length     - field of length-information for each element  **
**                 signature  - signature for checking                        **
**                 cycleCount - cycle counter, if using interupted mode.      **
**                               In non-interupted mode, the value must be 0. **
**                 state      - state buffer for interruption mode. will be   **
**                               used on interrupted mode to save the         **
**                               internal state to complete the calculation   **
**                               on the next call, which must be called with  **
**                               the same state-buffer content.               **
**                               If used in Non-Interrupted mode, the routine **
**                               must be called with state value 0 (NULL).    **
**                                                                            **
** RETURN        : CR_C_RC_ERR       if invalid signature                     **
**                 return code of func CR_A_CheckSig() else                   **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
CR_C_RC_t Crypto_CheckSigNCD
(
    uint32 const    numBlocks,
    CR_fpcfpc_uint8 textPtr,
    CR_fpc_uint32   length,
    CR_fpc_uint32   signature,
    uint16          cycleCount,
    CR_fp_uint8     state
)
{

#if (CR_DEV_ERROR_DETECT == STD_ON)
                    /* check if the signature pointer is valid                */
   if (signature == CR_NULL)
   {
       Det_ReportError
       (
          CR_DET_MODULE_ID,
          (uint8)CR_CONTROLLER_CHECKSIGNCD_ID,
          (uint8)CR_C_RC_ERR
       );

       return CR_C_RC_ERR;
   }
#endif                /* if (CR_DEV_ERROR_DETECT == STD_ON)                       */


                    /* check if the length of the signature is too big        */
   if (signature[0] >= (uint32)CR_DEF_NCD_SIG_KEY_LENGTH)
   {
      return CR_C_RC_ERR;
   }

                    /* check signature                                        */
   return CR_A_CheckSig
          (
             numBlocks,
             textPtr,
             length,
             signature,
             (CR_fp_uint32)CR_A_s5.SIG_COD_m,
             (CR_fp_uint32)CR_A_s5.SIG_COD_pe,
#if (CR_DEF_USE_BARRETT == STD_ON)
             (CR_fp_uint32)CR_A_s5.SIG_COD_bv,
#endif              /* if (CR_DEF_USE_BARRETT == STD_ON)                          */
             cycleCount,
             state
         );
}

#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
