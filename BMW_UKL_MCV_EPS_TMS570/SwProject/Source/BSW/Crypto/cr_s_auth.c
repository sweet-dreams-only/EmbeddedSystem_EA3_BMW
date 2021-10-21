/*******************************************************************************
**                                                                            **
**  SRC-MODULE: cr_s_auth.c                                                   **
**                                                                            **
**  Copyright (C) BMW Group 2006                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : 3SOFT                                                         **
**                                                                            **
**  PURPOSE   : symmetrical authentication                                    **
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
 *                          redundant casts
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
#include "cr_s_auth.h"             /* symmetric controller auth. decls.       */
#include "cr_s_data.h"             /* container for symmetric keys            */
#include "cr_c_random.h"           /* random generation routines              */
#include "cr_c_hash.h"             /* hash routines                           */
#include "cr_c_cancel.h"           /* cancelation of computation              */

/*******************************************************************************
**                      Local Macros                                          **
*******************************************************************************/

/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/

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

TS_STATIC_FUNCTION void CR_S_ExtendChall
(
   CR_fpc_uint8 challenge,
   CR_fpc_uint8 extensionA,
   CR_fpc_uint8 extensionB,
   CR_fp_uint8  extendedChallenge
);


TS_STATIC_FUNCTION CR_C_RC_t CR_S_CheckSigSymm
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint8    mac,
   CR_fpc_uint8    symmKey
);

TS_STATIC_FUNCTION CR_C_RC_t CR_S_Auth
(
   CR_fpc_uint8 challenge,
   CR_fpc_uint8 symmKey,
   CR_fp_uint8  response
);

#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Local Functions                                       **
*******************************************************************************/

#define CRYPTO_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_S_ExtendChall                                          **
**                                                                            **
** DESCRIPTION   :  Concatenates a challenge, a user id and a controller id.  **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  challenge         - 8 Byte challenge to extend            **
**                  extensionA        - 4 Byte value                          **
**                  extensionB        - 4 Byte value                          **
**                  extendedChallenge - returned value (extended challenge)   **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  pointer must be valid, and point to accessible memory     **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION void CR_S_ExtendChall
(
   CR_fpc_uint8 challenge,
   CR_fpc_uint8 extensionA,
   CR_fpc_uint8 extensionB,
   CR_fp_uint8  extendedChallenge
)
{
#if (CR_DEV_ERROR_DETECT == STD_ON)

   if
   (
      (((challenge == CR_NULL)   ||
        (extensionA == CR_NULL)) ||
        (extensionB == CR_NULL)) ||
        (extendedChallenge == CR_NULL)
   )
   {
       Det_ReportError
       (
          CR_DET_MODULE_ID,
          (uint8)CR_AUTH_EXTENDCHALL_ID,
          (uint8)CR_C_RC_ERR
       );

       return;
   }
#endif                                   /* if (CR_DEV_ERROR_DETECT == STD_ON)  */


                                         /* copy ID1 to the challenge         */
   extendedChallenge[0 ] = extensionA[0];
   extendedChallenge[1 ] = extensionA[1];
   extendedChallenge[2 ] = extensionA[2];
   extendedChallenge[3 ] = extensionA[3];

                                         /* copy ID2 to the challenge         */
   extendedChallenge[4 ] = extensionB[0];
   extendedChallenge[5 ] = extensionB[1];
   extendedChallenge[6 ] = extensionB[2];
   extendedChallenge[7 ] = extensionB[3];

                                         /* and append the original challenge */
   extendedChallenge[8 ] = challenge[0];
   extendedChallenge[9 ] = challenge[1];
   extendedChallenge[10] = challenge[2];
   extendedChallenge[11] = challenge[3];
   extendedChallenge[12] = challenge[4];
   extendedChallenge[13] = challenge[5];
   extendedChallenge[14] = challenge[6];
   extendedChallenge[15] = challenge[7];
}


/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_S_Auth                                                 **
**                                                                            **
** DESCRIPTION   :  Concatenates challenge and key, creates a signature and   **
**                  writes that into buffer provided.                         **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  challenge - challenge, 16 Bytes                           **
**                  symmKey   - symmetric key, 16 Bytes                       **
**                  response  - signature, 16 Bytes                           **
**                                                                            **
** RETURN        :  CR_C_RC_OK        if there was no cancellation            **
**                  CR_C_RC_CANCELED  if the computation has been cancelled   **
**                                                                            **
** REMARKS       :  calls CR_C_md5init, CR_C_md5hash, CR_C_md5end             **
**                  Pointer must be valid, and point to accessible memory     **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_S_Auth
(
   CR_fpc_uint8 challenge,
   CR_fpc_uint8 symmKey,
   CR_fp_uint8  response
)
{
   CR_C_RC_t RetVal;                             /* return value of md5hash() */

#if (CR_DEV_ERROR_DETECT == STD_ON)

   if
   (
      ((challenge == CR_NULL) ||
       (response == CR_NULL)) ||
       (symmKey == CR_NULL)
   )
   {
       Det_ReportError
       (
          CR_DET_MODULE_ID,
          (uint8)CR_AUTH_AUTH_ID,
          (uint8)CR_C_RC_ERR
       );

       return CR_C_RC_OK;
   }
#endif                                    /* if (CR_DEV_ERROR_DETECT == STD_ON) */

   CR_C_md5init ();                       /* initialize MD5 hash state        */

                                          /* hash the key                     */
   RetVal = CR_C_md5hash
            (
               (CR_fp_uint16)CR_NULL,
               symmKey,
               (uint32)16,
               (CR_fp_uint8)CR_NULL
            );

   /* Has the sub-function been canceled? Then return with CR_C_RC_CANCELED.  */
   CR_C_RETURN_IF_CANCELED(RetVal);

                                          /* hash the challenge               */
   RetVal = CR_C_md5hash
            (
               (CR_fp_uint16)CR_NULL,
               challenge,
               (uint32)16,
               (CR_fp_uint8)CR_NULL
            );

   CR_C_RETURN_IF_CANCELED(RetVal);

                                          /* hash the key                     */
   RetVal = CR_C_md5hash
            (
               (CR_fp_uint16)CR_NULL,
               symmKey,
               (uint32)16,
               (CR_fp_uint8)CR_NULL
            );

   CR_C_RETURN_IF_CANCELED(RetVal);

   return CR_C_md5end (response);        /* finalize hash operation           */
 }

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_S_CheckSigSymm                                         **
**                                                                            **
** DESCRIPTION   :  Verifies that a given mac belongs to given data and was   **
**                  computed using the given key.                             **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  numBlocks - block count, number of elements in textPtr    **
**                  textPtr   - array of pointers to the                      **
**                              sw-blocks. Must contain one or more fields.   **
**                              Must match numBlocks count.                   **
**                  length    - array of long values giving                   **
**                              the length of each appopriate block. Must     **
**                              match the numBlocks count.                    **
**                  mac       - mac to be verified                            **
**                  symmKey   - key to be used                                **
**                                                                            **
** RETURN        :  CR_C_RC_OK       on success                               **
**                  CR_C_RC_ERR      if mac does not match                    **
**                  CR_C_RC_CANCELED if the computation has been cancelled    **
**                                                                            **
** REMARKS       :  calls CR_C_md5init, CR_C_md5hash, CR_C_md5end             **
**                  Pointer must be valid, and point to accessible memory     **
**                                                                            **
*******************************************************************************/
TS_STATIC_FUNCTION CR_C_RC_t CR_S_CheckSigSymm
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint8    mac,
   CR_fpc_uint8    symmKey
)
{
   uint32 i;                       /* loop counter                            */
   CR_C_RC_t RetVal;               /* return value of this function           */

#if (CR_DEV_ERROR_DETECT == STD_ON)

   if ((((textPtr == CR_NULL) ||
         (length == CR_NULL)) ||
         (mac == CR_NULL)) ||
         (symmKey == CR_NULL))
   {
       Det_ReportError
       (
          CR_DET_MODULE_ID,
          (uint8)CR_AUTH_CHECKSIGSYMM_ID,
          (uint8)CR_C_RC_ERR
       );

       return CR_C_RC_ERR;
   }
#endif                             /* if (CR_DEV_ERROR_DETECT == STD_ON)          */

   CR_C_md5init ();                /* initialize the MD5 hash state           */

                                   /* hash the key                            */
   RetVal = CR_C_md5hash
            (
               (CR_fp_uint16)CR_NULL,
               symmKey,
               (uint32)16,
               (CR_fp_uint8)CR_NULL
            );

   /* Has the sub-function been canceled? Then return with CR_C_RC_CANCELED.  */
   CR_C_RETURN_IF_CANCELED(RetVal);

                                   /* hash all blocks                         */
   i = 0;                          /* start with first block                  */

   while (i != numBlocks)
   {
                                   /* hash this block                         */
      RetVal = CR_C_md5hash
               (
                  (CR_fp_uint16)CR_NULL,
                  textPtr[i],
                  length[i],
                  (CR_fp_uint8)CR_NULL
               );

      CR_C_RETURN_IF_CANCELED(RetVal);

      ++i;                         /* hash next block                         */
   }

                                   /* hash the key                            */
   RetVal = CR_C_md5hash
            (
               (CR_fp_uint16)CR_NULL,
               symmKey,
               (uint32)16,
               (CR_fp_uint8)CR_NULL
            );

   CR_C_RETURN_IF_CANCELED(RetVal);

   RetVal = CR_C_md5end (CR_S_s2.hashres);      /* finalize hashing           */

   CR_C_RETURN_IF_CANCELED(RetVal);

                                   /* compare the MAC with the expected value */
   i = 0;                          /* start with first byte                   */
   do
   {
      if (CR_S_s2.hashres[i] != mac[i])               /* do the bytes differ? */
      {
         return CR_C_RC_ERR;       /* yes, set error                          */
      }
      ++i;                         /* compare next byte                       */
   } while (i != 16);

   return RetVal;
}

#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define CRYPTO_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  Crypto_CheckAuthUStgSymm                                  **
**                                                                            **
** DESCRIPTION   :  Concatenates challenge, user id and controller id,        **
**                  computes the MAC with the authentication key and compares **
**                  that with the passed response.                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  challenge    - Challenge, 8 Bytes                         **
**                  userID       - user id, 4 Bytes                           **
**                  controllerID - controller id, 4 Bytes                     **
**                  level        - auth level to select key, 1-5              **
**                  response     - response to be checked                     **
**                                                                            **
** RETURN        :  CR_C_RC_OK        on success                              **
**                  CR_C_RC_ERR       if comparison failed                    **
**                  CR_C_RC_LVL       wrong level passed                      **
**                  CR_C_RC_CANCELED  if the computation has been cancelled   **
**                                                                            **
** REMARKS       :  calls CR_S_ExtendChall, CR_S_Auth                         **
**                  Pointer must be valid, and point to accessible memory     **
**                                                                            **
*******************************************************************************/
CR_C_RC_t Crypto_CheckAuthUStgSymm
(
   CR_fpc_uint8 challenge,
   CR_fpc_uint8 userID,
   CR_fpc_uint8 controllerID,
   uint32       level,
   CR_fpc_uint8 response
)
{
   uint8 i;               /* loop counter                                     */
   CR_C_RC_t RetVal;      /* return value                                     */

   RetVal = CR_C_RC_OK;   /* initialize return value                          */

                          /* concatenate challenge, user id and controller id */
   CR_S_ExtendChall
   (
      challenge,
      userID,
      controllerID,
      (CR_fp_uint8)CR_S_s2.chall_u_stg
   );

        /* if just LEVEL3 is defined, use LEVEL3 keys independent from level */
#if ( (CR_DEF_USE_LEVEL3 == STD_ON)  && \
      (CR_DEF_USE_LEVEL4 == STD_OFF) && \
      (CR_DEF_USE_LEVEL5 == STD_OFF) && \
      (CR_DEF_USE_LEVEL1 == STD_OFF) && \
      (CR_DEF_USE_LEVEL2 == STD_OFF) )

   RetVal = CR_S_Auth
            (
               (CR_fp_uint8)CR_S_s2.chall_u_stg,
               (CR_fp_uint8)CR_S_s3.AUTH_U_STG_L3_symm,
               (CR_fp_uint8)CR_S_s2.resp_ex
            );

   /* Has the sub-function been canceled? Then return with CR_C_RC_CANCELED.  */
   CR_C_RETURN_IF_CANCELED(RetVal);

#else                                    /* if ( (CR_DEF_USE_LEVEL3 == STD_ON)) && \
                                                 (CR_DEF_USE_LEVEL4 == STD_OFF) && \
                                                 (CR_DEF_USE_LEVEL5 == STD_OFF) && \
                                                 (CR_DEF_USE_LEVEL1 == STD_OFF) && \
                                                 (CR_DEF_USE_LEVEL2 == STD_OFF)   */

   switch (level)         /* select key by level                              */
   {
#if (CR_DEF_USE_LEVEL1 == STD_ON)
      case 1:             /* use LEVEL1 key                                   */
      {
         RetVal = CR_S_Auth
                  (
                     (CR_fp_uint8)CR_S_s2.chall_u_stg,
                     (CR_fp_uint8)CR_S_s1.AUTH_U_STG_L1_symm,
                     (CR_fp_uint8)CR_S_s2.resp_ex
                  );

         /* Has the sub-function been canceled? Then return.                  */
         CR_C_RETURN_IF_CANCELED(RetVal);

         break;
      }
#endif                    /* if (CR_DEF_USE_LEVEL1 == STD_ON)                     */
#if (CR_DEF_USE_LEVEL2 == STD_ON)
      case 2:             /* use LEVEL2 key                                   */
      {
         RetVal = CR_S_Auth
                  (
                     (CR_fp_uint8)CR_S_s2.chall_u_stg,
                     (CR_fp_uint8)CR_S_s1.AUTH_U_STG_L2_symm,
                     (CR_fp_uint8)CR_S_s2.resp_ex
                  );

         CR_C_RETURN_IF_CANCELED(RetVal);

         break;
      }
#endif                   /* if (CR_DEF_USE_LEVEL2 == STD_ON)                      */
#if (CR_DEF_USE_LEVEL3 == STD_ON)
      case 3:            /* use LEVEL3 key                                    */
      {
         RetVal = CR_S_Auth
                  (
                     (CR_fp_uint8)CR_S_s2.chall_u_stg,
                     (CR_fp_uint8)CR_S_s3.AUTH_U_STG_L3_symm,
                     (CR_fp_uint8)CR_S_s2.resp_ex
                  );

         CR_C_RETURN_IF_CANCELED(RetVal);

         break;
      }
#endif                   /* if (CR_DEF_USE_LEVEL3 == STD_ON)                      */
#if (CR_DEF_USE_LEVEL4 == STD_ON)
      case 4:            /* use LEVEL4 key                                    */
      {
         RetVal = CR_S_Auth
                  (
                     (CR_fp_uint8)CR_S_s2.chall_u_stg,
                     (CR_fp_uint8)CR_S_s3.AUTH_U_STG_L4_symm,
                     (CR_fp_uint8)CR_S_s2.resp_ex
                  );

         CR_C_RETURN_IF_CANCELED(RetVal);

         break;
      }
#endif                   /* if (CR_DEF_USE_LEVEL4 == STD_ON)                      */
#if (CR_DEF_USE_LEVEL5 == STD_ON)
      case 5:            /* use LEVEL5 key                                    */
      {
         RetVal = CR_S_Auth
                  (
                     (CR_fp_uint8)CR_S_s2.chall_u_stg,
                     (CR_fp_uint8)CR_S_s3.AUTH_U_STG_L5_symm,
                     (CR_fp_uint8)CR_S_s2.resp_ex
                  );

         CR_C_RETURN_IF_CANCELED(RetVal);

         break;
      }
#endif                   /* if (CR_DEF_USE_LEVEL5 == STD_ON)                      */

      default:           /* level invalid or deactivated: return LEVEL error  */
      {
         RetVal = CR_C_RC_LVL;
         break;
      }
   }

#endif                                   /* if ( (CR_DEF_USE_LEVEL3 == STD_ON)) && \
                                               (!(CR_DEF_USE_LEVEL4 == STD_ON)) && \
                                               (!(CR_DEF_USE_LEVEL5 == STD_ON)) && \
                                               (!(CR_DEF_USE_LEVEL1 == STD_ON)) && \
                                               (!(CR_DEF_USE_LEVEL2 == STD_ON))   */
                         /* compare expected response with the given one      */
   i = 0;
   while (i != 16)
   {
      if (response[i] != CR_S_s2.resp_ex[i])        /* if bytes differ        */
      {
         return CR_C_RC_ERR;                        /* return an error        */
      }
      ++i;                                          /* compare next byte      */
   }
   return RetVal;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  Crypto_CheckSigSwSymm                                     **
**                                                                            **
** DESCRIPTION   :  Checks if the mac matches the software in textPtr.        **
**                  The SW can be made up of multiple blocks.                 **
**                                                                            **
** PRECONDITIONS :  SIG_SW_symm must be set.                                  **
**                                                                            **
** PARAMETERS    :  numBlocks - block count, number of elements in textPtr    **
**                  textPtr   - pointer to an array of pointers to the        **
**                              sw-blocks. Must contain one or more fields.   **
**                              Must match numBlocks count.                   **
**                  length    - Pointer to an array of long values giving     **
**                              the length of each appopriate block. Must     **
**                              match the numBlocks count.                    **
**                  mac       - mac to be verified                            **
**                                                                            **
** RETURN        :  CR_C_RC_OK        on success                              **
**                  CR_C_RC_ERR       if mac does not match                   **
**                  CR_C_RC_CANCELED  if the computation has been cancelled   **
**                                                                            **
** REMARKS       :  calls CR_S_CheckSigSymm                                   **
**                  Pointer must be valid, and point to accessible memory     **
**                                                                            **
*******************************************************************************/
CR_C_RC_t Crypto_CheckSigSwSymm
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint8    mac
)
{
   return CR_S_CheckSigSymm (numBlocks, textPtr, length,
                             mac, (CR_fpc_uint8)SIG_SW_symm);
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  Crypto_CheckSigNCDSymm                                    **
**                                                                            **
** DESCRIPTION   :  Checks if the mac matches the coding data in textPtr.     **
**                  The NCD can be made up of multiple blocks.                **
**                                                                            **
** PRECONDITIONS :  SIG_COD_symm must be set.                                 **
**                                                                            **
** PARAMETERS    :  numBlocks - block count, number of elements in textPtr    **
**                  textPtr   - pointer to an array of pointers to the        **
**                              data-blocks. Must contain one or more fields. **
**                              Must match numBlocks count.                   **
**                  length    - Pointer to an array of long values giving     **
**                              the length of each appopriate block. Must     **
**                              match the numBlocks count.                    **
**                  mac       - mac to be verified                            **
**                                                                            **
** RETURN        :  CR_C_RC_OK        on success                              **
**                  CR_C_RC_ERR       if mac does not match                   **
**                  CR_C_RC_CANCELED  if the computation has been cancelled   **
**                                                                            **
** REMARKS       :  calls CR_S_CheckSigSymm                                   **
**                  Pointer must be valid, and point to accessible memory     **
**                                                                            **
*******************************************************************************/
CR_C_RC_t Crypto_CheckSigNCDSymm
(
   uint32 const    numBlocks,
   CR_fpcfpc_uint8 textPtr,
   CR_fpc_uint32   length,
   CR_fpc_uint8    mac
)
{
   return CR_S_CheckSigSymm (numBlocks, textPtr, length,
                             mac, (CR_fpc_uint8)SIG_COD_symm);
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_S_AuthenticateStgSamSymm                               **
**                                                                            **
** DESCRIPTION   :  Concatenatenates challenge, controller ID and SAM ID and  **
**                  creates a signature of that block.                        **
**                                                                            **
** PRECONDITIONS :  CR_S_AuthStgSamSymm must be set.                          **
**                                                                            **
** PARAMETERS    :  challenge    - Challenge, 8 Bytes                         **
**                  controllerID - controller ID, 4 Bytes                     **
**                  samID        - SAM ID                                     **
**                  response     - signature, 16 Bytes                        **
**                                                                            **
** RETURN        :  void                                                      **
**                                                                            **
** REMARKS       :  calls CR_S_ExtendChall, CR_S_Auth                         **
**                  Pointer must be valid, and point to accessible memory     **
**                                                                            **
*******************************************************************************/
#if (CR_DEF_STGAUTH == STD_ON)
void CR_S_AuthenticateStgSamSymm
(
   CR_fpc_uint8 challenge,
   CR_fpc_uint8 controllerID,
   CR_fpc_uint8 samID,
   CR_fp_uint8  response
)
{
   uint8 chall_stg_sam[16];               /* extended challenge               */

   CR_S_ExtendChall (challenge, controllerID,
                     samID, (CR_fp_uint8)chall_stg_sam);

   (void)CR_S_Auth ((CR_fp_uint8)chall_stg_sam,
                    (CR_fp_uint8)CR_S_AuthStgSamSymm, response);
}
#endif                                    /* if (CR_DEF_STGAUTH == STD_ON)        */

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :  CR_S_CheckAuthStgSamSymm                                  **
**                                                                            **
** DESCRIPTION   :  Checks if response value is valid by creating an authen-  **
**                  tication and comparing to a reference value.              **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETERS    :  challenge    - challenge buffer, 8 Bytes                  **
**                  controllerID - 4 Bytes controller ID                      **
**                  samID        - 4 Bytes SAm ID                             **
**                  response     - response buffer to be verified             **
**                                                                            **
** RETURN        :  CR_C_RC_OK        on success                              **
**                  CR_C_RC_ERR       if response is invalid                  **
**                  CR_C_RC_CANCELED  if the computation has been cancelled   **
**                                                                            **
** REMARKS       :  calls CR_S_ExtendChall, CR_S_Auth                         **
**                                                                            **
*******************************************************************************/
#if (CR_DEF_STGAUTH == STD_ON)
CR_C_RC_t CR_S_CheckAuthStgSamSymm
(
   CR_fpc_uint8  challenge,
   CR_fpc_uint8  controllerID,
   CR_fpc_uint8  samID,
   CR_fpc_uint8  response
)
{
   uint8 chall_stg_sam[16];        /* controller challenge                    */
   uint8 expected_response[16];    /* expected value                          */
   uint32 i;                       /* loop counter                            */
   CR_C_RC_t RetVal;               /* return value                            */

   RetVal = CR_C_RC_OK;            /* initialize return value                 */
                           /* concatenate challenge, controller ID and SAM id */
   CR_S_ExtendChall( challenge, controllerID,
                     samID, (CR_fp_uint8)chall_stg_sam );
                                   /* authenticate the concatenated challenge */
   RetVal = CR_S_Auth( (CR_fp_uint8)chall_stg_sam,
                       (CR_fp_uint8)CR_S_AuthStgSamSymm,
                       (CR_fp_uint8)expected_response );

   /* Has the sub-function been canceled? Then return with CR_C_RC_CANCELED.  */
   CR_C_RETURN_IF_CANCELED(RetVal);

                                   /* compare the challenge to the given data */
   i = 0;                          /* start with first byte                   */
   while (i != 16)
   {
      if (response[i] != expected_response[i])      /* do these bytes differ? */
      {
         return CR_C_RC_ERR;       /* yes, return error                       */
      }
      ++i;                         /* compare next byte                       */
   }
   return RetVal;
}

#endif                             /* if (CR_DEF_STGAUTH == STD_ON)               */

#define CRYPTO_STOP_SEC_CODE
#include "MemMap.h"

/*** End of file **************************************************************/
