/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2015 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Cal_Types.h
 *      Project:  SysService_AsrCal
 *       Module:  MICROSAR Crypto Abstraction Library (Cal)
 *    Generator:  -
 *
 *  Description:  This module implements the Crypto Abstraction Layer to perform
 *                cryptographic routine. The CAL provides synchronous services
 *                to enable a unique access to basic cryptographic functionalities
 *                for all software modules and software components.
 *
 *  Limitation to the Autosar specification:
 *                This implementation provides only a sub-set of the functionality
 *                as specified in the CAL_SWS of Autosar.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file (Cal.h).
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#if !defined (CAL_TYPES_H)
# define CAL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Cal_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* CAL0073: Config Id Type */
typedef uint16 Cal_ConfigIdType;

/* CAL0743: Align type for the key buffer */
#if   ( CAL_MAX_ALIGN_SCALAR_TYPE == 8 )
typedef uint8  Cal_AlignType;
#elif ( CAL_MAX_ALIGN_SCALAR_TYPE == 16 )
typedef uint16 Cal_AlignType;
#else
typedef uint32 Cal_AlignType;
#endif

/* CAL0069: Enumeration of the return type of the CAL module */
typedef enum
{
  CAL_E_OK,
  CAL_E_NOT_OK,
  CAL_E_SMALL_BUFFER,
  CAL_E_ENTROPY_EXHAUSTION
} Cal_ReturnType;

/* CAL0075: Enumeration of the result type of verification operations. */
typedef enum
{
  CAL_E_VER_OK,
  CAL_E_VER_NOT_OK
} Cal_VerifyResultType;

/* Declaration of key structures */
typedef struct
{
  uint32        length;
  Cal_AlignType data[CAL_ASYM_PUB_KEY_MAX_SIZE];
} Cal_AsymPublicKeyType;

typedef struct
{
  uint32        length;
  Cal_AlignType data[CAL_ASYM_PRIV_KEY_MAX_SIZE];
} Cal_AsymPrivateKeyType;

typedef struct
{
  uint32        length;
  Cal_AlignType data[CAL_SYM_KEY_MAX_SIZE];
} Cal_SymKeyType;

typedef struct
{
  uint32        length;
  Cal_AlignType data[CAL_KEY_EX_BASE_MAX_SIZE];
} Cal_KeyExchangeBaseType;

typedef struct
{
  uint32        length;
  Cal_AlignType data[CAL_KEY_EX_PRIV_MAX_SIZE];
} Cal_KeyExchangePrivateType;

/* Internal status for context buffer */
#define CAL_ACT_IDLE   0U
#define CAL_ACT_ACTIVE 1U

/* Context Buffer */
#if ( ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_HashCtxBufType[CAL_HASH_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_MAC_GENERATE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_MacGenerateCtxBufType[CAL_MACGENERATE_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_MAC_VERIFY_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_MacVerifyCtxBufType[CAL_MACVERIFY_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_RANDOM_SEED_CONFIGS     != 0 ) || \
      ( CAL_NUMBER_OF_RANDOM_GENERATE_CONFIGS != 0 ) || \
      ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_RandomCtxBufType[CAL_RANDOM_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SymBlockEncryptCtxBufType[CAL_SYMBLOCKENCRYPT_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SymBlockDecryptCtxBufType[CAL_SYMBLOCKDECRYPT_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SYM_ENCRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SymEncryptCtxBufType[CAL_SYMENCRYPT_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SymDecryptCtxBufType[CAL_SYMDECRYPT_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_AsymEncryptCtxBufType[CAL_ASYMENCRYPT_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_ASYM_DECRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_AsymDecryptCtxBufType[CAL_ASYMDECRYPT_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SIGNATURE_GENERATE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SignatureGenerateCtxBufType[CAL_SIGNATUREGENERATE_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SignatureVerifyCtxBufType[CAL_SIGNATUREVERIFY_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_CHECKSUM_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_ChecksumCtxBufType[CAL_CHECKSUM_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_KEY_DERIVE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_KeyDeriveCtxBufType[CAL_KEYDERIVE_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_KeyExchangeCalcSecretCtxBufType[CAL_KEYEXCHANGECALCSECRET_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SymKeyExtractCtxBufType[CAL_SYMKEYEXTRACT_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SYM_KEY_WRAP_SYM_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SymKeyWrapSymCtxBufType[CAL_SYMKEYWRAPSYM_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_SYM_KEY_WRAP_ASYM_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_SymKeyWrapAsymCtxBufType[CAL_SYMKEYWRAPASYM_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_ASYM_PRIVATE_KEY_EXTRACT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_AsymPublicKeyExtractCtxBufType[CAL_ASYMPUBLICKEYEXTRACT_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_ASYM_PRIVATE_KEY_WRAP_SYM_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_AsymPrivateKeyWrapSymCtxBufType[CAL_ASYMPRIVATEKEYWRAPSYM_CONTEXT_BUFFER_SIZE];
#endif

#if ( ( CAL_NUMBER_OF_ASYM_PRIVATE_KEY_WRAP_ASYM_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef Cal_AlignType Cal_AsymPrivateKeyWrapAsymCtxBufType[CAL_ASYMPRIVATEKEYWRAPASYM_CONTEXT_BUFFER_SIZE];
#endif

/* CAL0074: Data structure which shall encompass all information needed to specify the */
/* cryptographic primitives needed for the <Service> cryptographic service. It shall */
/* furthermore contain information on the callback function. */

/* Configuration Type for Random Interface */
#if ( ( CAL_NUMBER_OF_RANDOM_SEED_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;
  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                           Cal_RandomCtxBufType contextBuffer);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_RandomCtxBufType contextBuffer,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) seedPtr,
                                                            uint32 seedLength
  );

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_RandomCtxBufType contextBuffer
  );

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_RandomSeedConfigType;
#endif /*( ( CAL_NUMBER_OF_RANDOM_SEED_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Random Generator Interface */
#if ( ( CAL_NUMBER_OF_RANDOM_GENERATE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                      Cal_RandomCtxBufType contextBuffer,
                                                      P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) resultPtr,
                                                      uint32 resultLength);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_RandomGenerateConfigType;
#endif /*( ( CAL_NUMBER_OF_RANDOM_GENERATE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Hash interface */
#if ( ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;
  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                           Cal_HashCtxBufType                      contextBuffer);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_HashCtxBufType                       contextBuffer,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                                            uint32                                   dataLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_HashCtxBufType                      contextBuffer,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA)  resultPtr,
                                                            P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) resultLengthPtr,
                                                            boolean         truncationAllowed);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_HashConfigType;
#endif

/* Configuration Type for Signature Verification Type */
#if ( ( CAL_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;
  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                           Cal_SignatureVerifyCtxBufType            contextBuffer,
                                                        P2CONST(Cal_AsymPublicKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)  cfgPtr,
                                                            Cal_SignatureVerifyCtxBufType            contextBuffer,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                                            uint32                                   dataLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_SignatureVerifyCtxBufType            contextBuffer,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) signaturePtr,
                                                            uint32 signatureLength,
                                                        P2VAR(Cal_VerifyResultType, AUTOMATIC, CAL_APPL_DATA) resultPtr);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_SignatureVerifyConfigType;
#endif /*( ( CAL_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Symmetrical Key Extract interface */
#if ( ( CAL_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                           Cal_SymKeyExtractCtxBufType             contextBuffer);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_SymKeyExtractCtxBufType             contextBuffer,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                                            uint32                                   dataLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_SymKeyExtractCtxBufType             contextBuffer,
                                                            P2VAR(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_SymKeyExtractConfigType;
#endif /*( ( CAL_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Symmetrical Block Encryption interface */
#if ( ( CAL_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                           VAR(Cal_SymBlockEncryptCtxBufType, AUTOMATIC) Ctx,
                                                           P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            VAR(Cal_SymBlockEncryptCtxBufType, AUTOMATIC) Ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) iputTextPtr,
                                                            VAR(uint32, AUTOMATIC) iputTextLength,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) oputTextPtr,
                                                            P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) oputTextLengthPtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_SymBlockEncryptCtxBufType Ctx);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_SymBlockEncryptConfigType;
#endif /*( ( CAL_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Symmetrical Block Decryption interface */
#if ( ( CAL_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                           VAR(Cal_SymBlockDecryptCtxBufType, AUTOMATIC) Ctx,
                                                           P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            VAR(Cal_SymBlockDecryptCtxBufType, AUTOMATIC) Ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) iputTextPtr,
                                                            VAR(uint32, AUTOMATIC) iputTextLength,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) oputTextPtr,
                                                            P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) oputTextLengthPtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_SymBlockDecryptCtxBufType Ctx);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_SymBlockDecryptConfigType;
#endif /*( ( CAL_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for MAC Generate interface */
#if ( ( CAL_NUMBER_OF_MAC_GENERATE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                           Cal_MacGenerateCtxBufType               ctx,
                                                           P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_MacGenerateCtxBufType                ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                                            uint32                                   dataLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                            Cal_MacGenerateCtxBufType                ctx,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA)   resultPtr,
                                                            P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA)  resultLengthPtr,
                                                            boolean                               TruncationIsAllowed);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_MacGenerateConfigType;
#endif /*( ( CAL_NUMBER_OF_MAC_GENERATE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for MAC Verify interface */
#if ( ( CAL_NUMBER_OF_MAC_VERIFY_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)           CfgPtr,
                                                           Cal_MacVerifyCtxBufType                           Ctx,
                                                           P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) Key);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)  CfgPtr,
                                                            Cal_MacVerifyCtxBufType                  Ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) DataPtr,
                                                            uint32                                   DataLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)              CfgPtr,
                                                            Cal_MacVerifyCtxBufType                               Ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA)              Mac,
                                                            uint32                                                MacLength,
                                                            P2VAR(Cal_VerifyResultType, AUTOMATIC, CAL_APPL_DATA) ReslutPtr);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_MacVerifyConfigType;
#endif /*( ( CAL_NUMBER_OF_MAC_VERIFY_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Symmetrical Decryption interface */
#if ( ( CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)           CfgPtr,
                                                           Cal_SymDecryptCtxBufType                          Ctx,
                                                           P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) Key,
                                                           P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA)          InitVector,
                                                           uint32                                            InitVectorLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)  CfgPtr,
                                                            Cal_SymDecryptCtxBufType                 Ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) CipherTxtPtr,
                                                            uint32                                   CipherTxtLength,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA)  PlainTxtPtr,
                                                           P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA)  PlainTxtLengthPtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) CfgPtr,
                                                            Cal_SymDecryptCtxBufType                Ctx,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA)  PlainTxtPtr,
                                                            P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) PlainTxtLengthPtr);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_SymDecryptConfigType;
#endif /*( ( CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Symmetrical Encryption interface */
#if ( ( CAL_NUMBER_OF_SYM_ENCRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)  CfgPtr,
                                                           Cal_SymEncryptCtxBufType                 Ctx,
                                                           P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) Key,
                                                           P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) InitVector,
                                                           uint32                                   InitVectorLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)  CfgPtr,
                                                            Cal_SymEncryptCtxBufType                 Ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) PlainTxtPtr,
                                                            uint32                                   PlainTxtLength,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA)   CipherTxtPtr,
                                                            P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA)  CipherTxtLengthPtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) CfgPtr,
                                                            Cal_SymEncryptCtxBufType                Ctx,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA)  CipherTxtPtr,
                                                            P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) CipherTxtLengthPtr);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_SymEncryptConfigType;
#endif /*( ( CAL_NUMBER_OF_SYM_ENCRYPT_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Key Derive interface */
#if ( ( CAL_NUMBER_OF_KEY_DERIVE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)  CfgPtr,
                                                           Cal_KeyDeriveCtxBufType                  Ctx,
                                                           uint32                                   keyLength,
                                                           uint32                                   iterations);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)  CfgPtr,
                                                            Cal_KeyDeriveCtxBufType                  Ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) passwordPtr,
                                                            uint32                                   passwordLength,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) saltPtr,
                                                            uint32                                   saltLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)         CfgPtr,
                                                            Cal_KeyDeriveCtxBufType                         Ctx,
                                                            P2VAR(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_KeyDeriveConfigType;
#endif /*( ( CAL_NUMBER_OF_KEY_DERIVE_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

/* Configuration Type for Key Exchange interface */
#if ( ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveStartFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)                       CfgPtr,
                                                           Cal_KeyExchangeCalcSecretCtxBufType                           Ctx,
                                                           P2CONST(Cal_KeyExchangeBaseType, AUTOMATIC, CAL_APPL_DATA)    basePtr,
                                                           P2CONST(Cal_KeyExchangePrivateType, AUTOMATIC, CAL_APPL_DATA) privateValuePtr);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveUpdateFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA)  CfgPtr,
                                                            Cal_KeyExchangeCalcSecretCtxBufType      Ctx,
                                                            P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) partnerPublicValuePtr,
                                                            uint32                                   partnerPublicValueLength);

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFinishFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) CfgPtr,
                                                            Cal_KeyExchangeCalcSecretCtxBufType     Ctx,
                                                            P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA)  sharedSecretPtr,
                                                            P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) sharedSecretLengthPtr,
                                                            boolean                                 TruncationIsAllowed);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_KeyExchangeCalcSecretConfigType;
#endif /*( ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

#if ( ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_PUB_VAL_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )
typedef struct
{
  Cal_ConfigIdType ConfigId;

  P2FUNC(Cal_ReturnType, CAL_APPL_CODE, PrimitiveFct)(P2CONST(void, AUTOMATIC, CAL_APPL_DATA) cfgPtr,
                                                      P2CONST(Cal_KeyExchangeBaseType, AUTOMATIC, CAL_APPL_DATA) basePtr,
                                                      P2CONST(Cal_KeyExchangePrivateType, AUTOMATIC, CAL_APPL_DATA) privateValuePtr,
                                                      P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) publicValuePtr,
                                                      P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) publicValueLengthPtr);

  P2CONST(void, AUTOMATIC, CAL_CONST) PrimitiveConfigPtr;
} Cal_KeyExchangeCalcPubValConfigType;
#endif /*( ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_PUB_VAL_CONFIGS != 0 ) || ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) )*/

# define CAL_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

#endif /* CAL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Cal_Types.h
 *********************************************************************************************************************/
