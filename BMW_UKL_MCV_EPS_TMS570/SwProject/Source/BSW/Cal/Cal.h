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
 *         File:  Cal.h
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
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Wladimir Gerber               Wge           Vctr Informatik GmbH
 *  Markus Schneider              Mss           Vctr Informatik GmbH
 *  Joern Herwig                  JHg           Vctr Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-09-01  Wge     Derived from SysService_AsrCal
 *  01.01.00  2012-09-26  Wge     ESCAN00061655: Fix findings of code inspection
 *  01.01.01  2013-01-18  Wge     ESCAN00064264: Replacing of _STATIC_ with STATIC due to MSR4 R6
 *  02.00.00  2013-04-12  Mss     ESCAN00066036: Moved back to SysService_AsrCal
 *                        Mss     ESCAN00066248: Adaptions to fulfill ASR4 specification
 *  02.00.01  2013-06-07  Mss     ESCAN00067924: Config container Cal_SymDecryptConfig has a wrong size
 *  02.00.02  2013-07-02  JHg     ESCAN00068121: Correction of version information
 *  02.00.03  2013-07-02  JHg     ESCAN00068121: Correction of version information
 *  02.01.00  2014-08-05  Mss     ESCAN00076672: Creation of Cal_SymEncrypt service
 *                        Mss     ESCAN00077613: Creation of CalKeyExchangeCalcSecret, CalKeyDerive and
 *                                                CalKeyExchangeCalcPubVal
 *  02.01.01  2015-08-07  Mss     ESCAN00081510: Fixed missing abstractions
 *                                ESCAN00080879: Fixed compiler error with dummy statement
 *********************************************************************************************************************/

#ifndef CAL_H
# define CAL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Cal_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : SysService_AsrCal CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define SYSSERVICE_ASRCAL_VERSION          (0x0201u)
# define SYSSERVICE_ASRCAL_RELEASE_VERSION  (0x01u)

/* Vendor and Module Identification */
# define CAL_VENDOR_ID              (30u)
# define CAL_MODULE_ID              (206u)
# define CAL_INSTANCE_ID            (0u)

/* AUTOSAR Software Specification Version Information (Autosar_SWS_CAL) */
# define CAL_AR_MAJOR_VERSION       (0x04)
# define CAL_AR_MINOR_VERSION       (0x00)
# define CAL_AR_PATCH_VERSION       (0x03)

/* Component Version Information */
# define CAL_SW_MAJOR_VERSION       ((SYSSERVICE_ASRCAL_VERSION >> 8) & 0xFFu)
# define CAL_SW_MINOR_VERSION       ((SYSSERVICE_ASRCAL_VERSION     ) & 0xFFu)
# define CAL_SW_PATCH_VERSION       (SYSSERVICE_ASRCAL_RELEASE_VERSION)

/* Switch Default Settings */
#ifndef STATIC
# define STATIC static
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define CAL_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* Requirement Specification Template version */
extern CONST(uint8, CAL_CONST) Cal_MainVersion;
extern CONST(uint8, CAL_CONST) Cal_SubVersion;
extern CONST(uint8, CAL_CONST) Cal_ReleaseVersion;

/* Service Configurations */
#if ( CAL_NUMBER_OF_HASH_CONFIGS != 0 )
extern CONST(Cal_HashConfigType, CAL_CONST) Cal_HashConfig[CAL_NUMBER_OF_HASH_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_RANDOM_SEED_CONFIGS != 0 )
extern CONST(Cal_RandomSeedConfigType, CAL_CONST) Cal_RandomSeedConfig[CAL_NUMBER_OF_RANDOM_SEED_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_RANDOM_GENERATE_CONFIGS != 0 )
extern CONST(Cal_RandomGenerateConfigType, CAL_CONST) Cal_RandomGenerateConfig[CAL_NUMBER_OF_RANDOM_GENERATE_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS != 0 )
extern CONST(Cal_SignatureVerifyConfigType, CAL_CONST) Cal_SignatureVerifyConfig[CAL_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS != 0 )
extern CONST(Cal_SymKeyExtractConfigType, CAL_CONST) Cal_SymKeyExtractConfig[CAL_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS != 0 )
extern CONST(Cal_SymBlockEncryptConfigType, CAL_CONST) Cal_SymBlockEncryptConfig[CAL_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS != 0 )
extern CONST(Cal_SymBlockDecryptConfigType, CAL_CONST) Cal_SymBlockDecryptConfig[CAL_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_MAC_GENERATE_CONFIGS != 0 )
extern CONST(Cal_MacGenerateConfigType, CAL_CONST) Cal_MacGenerateConfig[CAL_NUMBER_OF_MAC_GENERATE_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_MAC_VERIFY_CONFIGS != 0 )
extern CONST(Cal_MacVerifyConfigType, CAL_CONST) Cal_MacVerifyConfig[CAL_NUMBER_OF_MAC_VERIFY_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS != 0 )
extern CONST(Cal_SymDecryptConfigType, CAL_CONST) Cal_SymDecryptConfig[CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_SYM_ENCRYPT_CONFIGS != 0 )
extern CONST(Cal_SymEncryptConfigType, CAL_CONST) Cal_SymEncryptConfig[CAL_NUMBER_OF_SYM_ENCRYPT_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_KEY_DERIVE_CONFIGS != 0 )
extern CONST(Cal_KeyDeriveConfigType, CAL_CONST) Cal_KeyDeriveConfig[CAL_NUMBER_OF_KEY_DERIVE_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS != 0 )
extern CONST(Cal_KeyExchangeCalcSecretConfigType, CAL_CONST) Cal_KeyExchangeCalcSecretConfig[CAL_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS];
#endif

#if ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_PUB_VAL_CONFIGS != 0 )
extern CONST(Cal_KeyExchangeCalcPubValConfigType, CAL_CONST) Cal_KeyExchangeCalcPubValConfig[CAL_NUMBER_OF_KEY_EXCHANGE_CALC_PUB_VAL_CONFIGS];
#endif

# define CAL_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define CAL_START_SEC_CODE
# include "MemMap.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Decryption Interface */
#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_SymDecryptStart(Cal_ConfigIdType cfgId,
                                                   Cal_SymDecryptCtxBufType contextBuffer,
                                                   P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr,
                                                   P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) InitVectorPtr,
                                                   uint32 InitVectorLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymDecryptUpdate(Cal_ConfigIdType cfgId,
                                                    Cal_SymDecryptCtxBufType contextBuffer,
                                                    P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) cipherTextPtr,
                                                    uint32 cipherTextLength,
                                                    P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) plainTextPtr,
                                                    P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) plainTextLengthPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymDecryptFinish(Cal_ConfigIdType cfgId,
                                                    Cal_SymDecryptCtxBufType contextBuffer,
                                                    P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) plainTextPtr,
                                                    P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) plainTextLengthPtr);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS != 0 ) )*/

/* Encryption Interface */
#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_ENCRYPT_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_SymEncryptStart(Cal_ConfigIdType cfgId,
                                                   Cal_SymEncryptCtxBufType contextBuffer,
                                                   P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr,
                                                   P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) InitVectorPtr,
                                                   uint32 InitVectorLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymEncryptUpdate(Cal_ConfigIdType cfgId,
                                                    Cal_SymEncryptCtxBufType contextBuffer,
                                                    P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) plainTextPtr,
                                                    uint32 plainTextLength,
                                                    P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) cipherTextPtr,
                                                    P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) cipherTextLengthPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymEncryptFinish(Cal_ConfigIdType cfgId,
                                                    Cal_SymEncryptCtxBufType contextBuffer,
                                                    P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) cipherTextPtr,
                                                    P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) cipherTextLengthPtr);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_ENCRYPT_CONFIGS != 0 ) )*/

/* Random Interface */
#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_RANDOM_SEED_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_RandomSeedStart(Cal_ConfigIdType cfgId,
                                                   Cal_RandomCtxBufType contextBuffer);

FUNC(Cal_ReturnType, CAL_CODE) Cal_RandomSeedUpdate(Cal_ConfigIdType cfgId,
                                                    Cal_RandomCtxBufType contextBuffer,
                                                    P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) seedPtr,
                                                    uint32 seedLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_RandomSeedFinish(Cal_ConfigIdType cfgId,
                                                    Cal_RandomCtxBufType contextBuffer);

#endif
#if ( CAL_NUMBER_OF_RANDOM_GENERATE_CONFIGS != 0U )
FUNC(Cal_ReturnType, CAL_CODE) Cal_RandomGenerate(Cal_ConfigIdType cfgId,
                                                  Cal_RandomCtxBufType contextBuffer,
                                                  P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) resultPtr,
                                                  uint32 resultLength);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_RANDOM_SEED_CONFIGS != 0 ) )*/

/* Signature Interface */
#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureVerifyStart(Cal_ConfigIdType cfgId,
                                                        Cal_SignatureVerifyCtxBufType contextBuffer,
                                                      P2CONST(Cal_AsymPublicKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureVerifyUpdate(Cal_ConfigIdType cfgId,
                                                         Cal_SignatureVerifyCtxBufType contextBuffer,
                                                         P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                                         uint32 dataLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SignatureVerifyFinish(Cal_ConfigIdType cfgId,
                                                         Cal_SignatureVerifyCtxBufType contextBuffer,
                                                         P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) signaturePtr,
                                                         uint32 signatureLength,
                                                      P2VAR(Cal_VerifyResultType, AUTOMATIC, CAL_APPL_DATA) resultPtr);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS != 0 ) )*/

/* Hash interface */
#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_HashStart(Cal_ConfigIdType cfgId,
                                              Cal_HashCtxBufType contextBuffer);

FUNC(Cal_ReturnType, CAL_CODE) Cal_HashUpdate(Cal_ConfigIdType cfgId,
                                              Cal_HashCtxBufType contextBuffer,
                                              P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                              uint32 dataLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_HashFinish(Cal_ConfigIdType cfgId,
                                              Cal_HashCtxBufType contextBuffer,
                                              P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) resultPtr,
                                              P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) resultLengthPtr,
                                              boolean TruncationIsAllowed);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_HASH_CONFIGS != 0 ) )*/

/* Symmetrical Key Extract Interface */
#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyExtractStart(Cal_ConfigIdType cfgId,
                                                      Cal_SymKeyExtractCtxBufType contextBuffer);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyExtractUpdate(Cal_ConfigIdType cfgId,
                                                       Cal_SymKeyExtractCtxBufType contextBuffer,
                                                       P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                                       uint32 dataLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymKeyExtractFinish(Cal_ConfigIdType cfgId,
                                                       Cal_SymKeyExtractCtxBufType contextBuffer,
                                                       P2VAR(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS != 0 ) )*/

/* Symmetrical Block Interface */
#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockEncryptStart(Cal_ConfigIdType cfgId,
                                                        Cal_SymBlockEncryptCtxBufType contextBuffer,
                                                        P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockEncryptUpdate(Cal_ConfigIdType cfgId,
                                                         Cal_SymBlockEncryptCtxBufType contextBuffer,
                                                         P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) plainTextPtr,
                                                         uint32 plainTextLength,
                                                         P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) cipherTextPtr,
                                                         P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) cipherTextLengthPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockEncryptFinish(Cal_ConfigIdType cfgId,
                                                         Cal_SymBlockEncryptCtxBufType contextBuffer);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS != 0 ) )*/

#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockDecryptStart(Cal_ConfigIdType cfgId,
                                                        Cal_SymBlockDecryptCtxBufType contextBuffer,
                                                        P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockDecryptUpdate(Cal_ConfigIdType cfgId,
                                                         Cal_SymBlockDecryptCtxBufType contextBuffer,
                                                         P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) cipherTextPtr,
                                                         uint32 cipherTextLength,
                                                         P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) plainTextPtr,
                                                         P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) plainTextLengthPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_SymBlockDecryptFinish(Cal_ConfigIdType cfgId,
                                                         Cal_SymBlockDecryptCtxBufType contextBuffer);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS != 0 ) )*/

/* MAC Interface */
#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_MAC_GENERATE_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_MacGenerateStart(Cal_ConfigIdType cfgId,
                                                    Cal_MacGenerateCtxBufType contextBuffer,
                                                    P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_MacGenerateUpdate(Cal_ConfigIdType cfgId,
                                                     Cal_MacGenerateCtxBufType contextBuffer,
                                                     P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                                     uint32 dataLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_MacGenerateFinish(Cal_ConfigIdType cfgId,
                                                     Cal_MacGenerateCtxBufType contextBuffer,
                                                     P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) resultPtr,
                                                     P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) resultLengthPtr,
                                                     boolean TruncationIsAllowed);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_MAC_GENERATE_CONFIGS != 0 ) )*/

#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_MAC_VERIFY_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_MacVerifyStart(Cal_ConfigIdType cfgId,
                                                  Cal_MacVerifyCtxBufType contextBuffer,
                                                  P2CONST(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_MacVerifyUpdate(Cal_ConfigIdType cfgId,
                                                   Cal_MacVerifyCtxBufType contextBuffer,
                                                   P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) dataPtr,
                                                   uint32 dataLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_MacVerifyFinish(Cal_ConfigIdType cfgId,
                                                   Cal_MacVerifyCtxBufType contextBuffer,
                                                   P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) MacPtr,
                                                   uint32 MacLength,
                                                   P2VAR(Cal_VerifyResultType, AUTOMATIC, CAL_APPL_DATA) resultPtr);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_MAC_VERIFY_CONFIGS != 0 ) )*/

#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_KEY_DERIVE_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyDeriveStart(Cal_ConfigIdType cfgId,
                                                  Cal_KeyDeriveCtxBufType contextBuffer,
                                                  uint32 keyLength,
                                                  uint32 iterations);

FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyDeriveUpdate(Cal_ConfigIdType cfgId,
                                                   Cal_KeyDeriveCtxBufType contextBuffer,
                                                   P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) passwordPtr,
                                                   uint32 passwordLength,
                                                   P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) saltPtr,
                                                   uint32 saltLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyDeriveFinish(Cal_ConfigIdType cfgId,
                                                   Cal_KeyDeriveCtxBufType contextBuffer,
                                                   P2VAR(Cal_SymKeyType, AUTOMATIC, CAL_APPL_DATA) keyPtr);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_KEY_DERIVE_CONFIGS != 0 ) )*/

#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyExchangeCalcSecretStart(Cal_ConfigIdType cfgId,
                                                              Cal_KeyExchangeCalcSecretCtxBufType contextBuffer,
                                                              P2CONST(Cal_KeyExchangeBaseType, AUTOMATIC, CAL_APPL_DATA) basePtr,
                                                              P2CONST(Cal_KeyExchangePrivateType, AUTOMATIC, CAL_APPL_DATA) privateValuePtr);

FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyExchangeCalcSecretUpdate(Cal_ConfigIdType cfgId,
                                                               Cal_KeyExchangeCalcSecretCtxBufType contextBuffer,
                                                               P2CONST(uint8, AUTOMATIC, CAL_APPL_DATA) partnerPublicValuePtr,
                                                               uint32 partnerPublicValueLength);

FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyExchangeCalcSecretFinish(Cal_ConfigIdType     cfgId,
                                                               Cal_KeyExchangeCalcSecretCtxBufType contextBuffer,
                                                               P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) sharedSecretPtr,
                                                               P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) sharedSecretLengthPtr,
                                                               boolean TruncationIsAllowed);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS != 0 ) )*/

#if ( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_PUB_VAL_CONFIGS != 0 ) )
FUNC(Cal_ReturnType, CAL_CODE) Cal_KeyExchangeCalcPubVal(Cal_ConfigIdType cfgId,
                                                         P2CONST(Cal_KeyExchangeBaseType, AUTOMATIC, CAL_APPL_DATA) basePtr,
                                                         P2CONST(Cal_KeyExchangePrivateType, AUTOMATIC, CAL_APPL_DATA) privateValuePtr,
                                                         P2VAR(uint8, AUTOMATIC, CAL_APPL_DATA) publicValuePtr,
                                                         P2VAR(uint32, AUTOMATIC, CAL_APPL_DATA) publicValueLengthPtr);
#endif /*( ( CAL_DISABLE_NOT_USED_APIS == STD_OFF ) || ( CAL_NUMBER_OF_KEY_EXCHANGE_CALC_PUB_VAL_CONFIGS != 0 ) )*/

#if (CAL_VERSION_INFO_API == STD_ON)
extern FUNC(void, CAL_CODE) Cal_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CAL_APPL_DATA) versioninfo);
#endif
#ifdef  __cplusplus
}
#endif

# define CAL_STOP_SEC_CODE
# include "MemMap.h"

#endif      /*  CAL_H  */

/**********************************************************************************************************************
 *  END OF FILE: CAL.H
 *********************************************************************************************************************/
