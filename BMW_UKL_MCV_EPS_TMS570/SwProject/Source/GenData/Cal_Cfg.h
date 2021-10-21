/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2012 - 2016 by Vctr Informatik GmbH.                                           All rights reserved.
 *
 *                 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Cal
 *           Program: MSR BAC 4.0 (MSR_Bmw_SLP4)
 *          Customer: Nxtr Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Renesas RH850 P1M
 *    License Scope : The usage is restricted to CBD1500658_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Cal_Cfg.h
 *   Generation Time: 2016-09-22 13:26:21
 *           Project: EPS - Version 1.0
 *          Delivery: CBD1500658_D00
 *      Tool Version: DaVinci Configurator (beta) 5.10.26 SP3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/



#if !defined (CAL_CFG_H)
#define CAL_CFG_H

/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/
#ifndef CAL_USE_DUMMY_FUNCTIONS
#define CAL_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef CAL_USE_DUMMY_STATEMENT
#define CAL_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CAL_DUMMY_STATEMENT
#define CAL_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CAL_DUMMY_STATEMENT_CONST
#define CAL_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef CAL_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CAL_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CAL_ATOMIC_VARIABLE_ACCESS
#define CAL_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CAL_PROCESSOR_RH850_1311
#define CAL_PROCESSOR_RH850_1311
#endif
#ifndef CAL_COMP_GREENHILLS
#define CAL_COMP_GREENHILLS
#endif
#ifndef CAL_GEN_GENERATOR_MSR
#define CAL_GEN_GENERATOR_MSR
#endif
#ifndef CAL_CPUTYPE_BITORDER_LSB2MSB
#define CAL_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef CAL_CONFIGURATION_VARIANT_PRECOMPILE
#define CAL_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CAL_CONFIGURATION_VARIANT_LINKTIME
#define CAL_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CAL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CAL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CAL_CONFIGURATION_VARIANT
#define CAL_CONFIGURATION_VARIANT CAL_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CAL_POSTBUILD_VARIANT_SUPPORT
#define CAL_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



/**********************************************************************************************************************
 *  GENERAL PROPERTIES
 *********************************************************************************************************************/

/* Enables or disables Cal_GetVersionInfo API*/ 
#define CAL_VERSION_INFO_API                                STD_ON

/* If enabled, APIs of not configured services are not available */
#define CAL_DISABLE_NOT_USED_APIS                           STD_ON

/* The scalar type which has the maximum alignment restrictions on the given platform
 * Valid values are 8, 16 or 32 */
#define CAL_MAX_ALIGN_SCALAR_TYPE                           32

/* CAL_ASYM_PUB_KEY_MAX_SIZE shall be chosen such that 
 * "CAL_ASYM_PUB_KEY_MAX_SIZE * sizeof(Cal_AlignType)" is greater or equal to the 
 * maximum of the configured values CalAsymEncryptMaxKeySize,
 * CalSignatureVerifyMaxKeySize, CalAsymPublicKeyExtractMaxKeySize, 
 * CalSymKeyWrapAsymMaxPubKeySize and CalAsymPrivateKeyWrapAsymMaxPubKeySize. */
#define CAL_ASYM_PUB_KEY_MAX_SIZE                           512U

/* CAL_ASYM_PRIV_KEY_MAX_SIZE shall be chosen such that 
 * "CAL_ASYM_PRIV_KEY_MAX_SIZE * sizeof(Cal_AlignType)" is greater or equal to the 
 * maximum of the configured values CalAsymDecryptMaxKeySize,
 * CalSignatureGenerateMaxKeySize, CalAsymPrivateKeyExtractMaxKeySize, 
 * CalAsymPrivateKeyWrapSymMaxPrivKeySize and CalAsymPrivateKeyWrapAsymMaxPrivKeySize. */
#define CAL_ASYM_PRIV_KEY_MAX_SIZE                          1U

/* CAL_SYM_KEY_MAX_SIZE shall be chosen such that 
 * "CAL_SYM_KEY_MAX_SIZE * sizeof(Cal_AlignType)" * is greater or equal to the maximum of the configured values 
 * CalSymBlockEncryptMaxKeySize, CalSymBlockDecryptMaxKeySize, 
 * CalSymEncryptMaxKeySize, CalSymDecryptMaxKeySize, CalKeyDeriveMaxKeySize,
 * CalSymKeyExtractMaxKeySize, CalMacGenerateMaxKeySize
 * CalMacVerifyMaxKeySize, CalSymKeyWrapSymMaxSymKeySize,
 * CalSymKeyWrapAsymMaxSymKeySize and CalAsymPrivateKeyWrapSymMaxSymKeySize. */
#define CAL_SYM_KEY_MAX_SIZE                                5U

/* CAL_KEY_EX_BASE_MAX_SIZE shall be chosen such that 
 * "CAL_KEY_EX_BASE_MAX_SIZE * sizeof(Cal_AlignType)" is greater or equal to the maximum of the configured values 
 * CalKeyExchangeCalcPubValMaxBaseTypeSize and CalKeyExchangeCalcSecretMaxBaseTypeSize */
#define CAL_KEY_EX_BASE_MAX_SIZE                            1U

/* CAL_KEY_EX_PRIV_MAX_SIZE shall be chosen such that 
* "CAL_KEY_EX_PRIV_MAX_SIZE * sizeof(Cal_AlignType)" is greater or equal to the maximum of the configured values 
* CalKeyExchangeCalcPubValMaxPrivateTypeSize and CalKeyExchangeCalcSecretMaxPrivateTypeSize. */
#define CAL_KEY_EX_PRIV_MAX_SIZE                            1U


/**********************************************************************************************************************
 *  SERVICE CONFIGURATIONS
 *********************************************************************************************************************/

/* CAL_NUMBER_OF_X_CONFIGS determines the amount of configured services of this type */
#define CAL_NUMBER_OF_ASYM_DECRYPT_CONFIGS               0U 
#define CAL_NUMBER_OF_ASYM_ENCRYPT_CONFIGS               0U 
#define CAL_NUMBER_OF_ASYM_PRIVATE_KEY_EXTRACT_CONFIGS   0U 
#define CAL_NUMBER_OF_ASYM_PRIVATE_KEY_WRAP_ASYM_CONFIGS 0U 
#define CAL_NUMBER_OF_ASYM_PRIVATE_KEY_WRAP_SYM_CONFIGS  0U 
#define CAL_NUMBER_OF_ASYM_PUBLIC_KEY_EXTRACT_CONFIGS    0U 
#define CAL_NUMBER_OF_CHECKSUM_CONFIGS                   0U 
#define CAL_NUMBER_OF_HASH_CONFIGS                       1U 
#define CAL_NUMBER_OF_KEY_DERIVE_CONFIGS                 0U 
#define CAL_NUMBER_OF_KEY_EXCHANGE_CALC_PUB_VAL_CONFIGS  0U 
#define CAL_NUMBER_OF_KEY_EXCHANGE_CALC_SECRET_CONFIGS   0U 
#define CAL_NUMBER_OF_MAC_GENERATE_CONFIGS               0U 
#define CAL_NUMBER_OF_MAC_VERIFY_CONFIGS                 0U 
#define CAL_NUMBER_OF_RANDOM_GENERATE_CONFIGS            0U 
#define CAL_NUMBER_OF_RANDOM_SEED_CONFIGS                0U 
#define CAL_NUMBER_OF_SIGNATURE_GENERATE_CONFIGS         0U 
#define CAL_NUMBER_OF_SIGNATURE_VERIFY_CONFIGS           0U 
#define CAL_NUMBER_OF_SYM_BLOCK_DECRYPT_CONFIGS          0U 
#define CAL_NUMBER_OF_SYM_BLOCK_ENCRYPT_CONFIGS          0U 
#define CAL_NUMBER_OF_SYM_DECRYPT_CONFIGS                0U 
#define CAL_NUMBER_OF_SYM_ENCRYPT_CONFIGS                0U 
#define CAL_NUMBER_OF_SYM_KEY_EXTRACT_CONFIGS            0U 
#define CAL_NUMBER_OF_SYM_KEY_WRAP_ASYM_CONFIGS          0U 
#define CAL_NUMBER_OF_SYM_KEY_WRAP_SYM_CONFIGS           0U 
#define CAL_NUMBER_OF_SERVICES                           1 



/* Service Context Buffer */
#define CAL_ASYMDECRYPT_CONTEXT_BUFFER_SIZE           1U 
#define CAL_ASYMENCRYPT_CONTEXT_BUFFER_SIZE           1U 
#define CAL_ASYMPRIVATEKEYEXTRACT_CONTEXT_BUFFER_SIZE 1U 
#define CAL_ASYMPRIVATEKEYWRAPASYM_CONTEXT_BUFFER_SIZE 1U 
#define CAL_ASYMPRIVATEKEYWRAPSYM_CONTEXT_BUFFER_SIZE 1U 
#define CAL_ASYMPUBLICKEYEXTRACT_CONTEXT_BUFFER_SIZE  1U 
#define CAL_CHECKSUM_CONTEXT_BUFFER_SIZE              1U 
#define CAL_HASH_CONTEXT_BUFFER_SIZE                  85U 
#define CAL_KEYDERIVE_CONTEXT_BUFFER_SIZE             1U 
#define CAL_KEYEXCHANGECALCPUBVAL_CONTEXT_BUFFER_SIZE 1U 
#define CAL_KEYEXCHANGECALCSECRET_CONTEXT_BUFFER_SIZE 1U 
#define CAL_MACGENERATE_CONTEXT_BUFFER_SIZE           1U 
#define CAL_MACVERIFY_CONTEXT_BUFFER_SIZE             1U 
#define CAL_RANDOMSEED_CONTEXT_BUFFER_SIZE            1U 
#define CAL_SIGNATUREGENERATE_CONTEXT_BUFFER_SIZE     1U 
#define CAL_SIGNATUREVERIFY_CONTEXT_BUFFER_SIZE       1U 
#define CAL_SYMBLOCKDECRYPT_CONTEXT_BUFFER_SIZE       1U 
#define CAL_SYMBLOCKENCRYPT_CONTEXT_BUFFER_SIZE       1U 
#define CAL_SYMDECRYPT_CONTEXT_BUFFER_SIZE            1U 
#define CAL_SYMENCRYPT_CONTEXT_BUFFER_SIZE            1U 
#define CAL_SYMKEYEXTRACT_CONTEXT_BUFFER_SIZE         1U 
#define CAL_SYMKEYWRAPASYM_CONTEXT_BUFFER_SIZE        1U 
#define CAL_SYMKEYWRAPSYM_CONTEXT_BUFFER_SIZE         1U 

#define CAL_RANDOM_CONTEXT_BUFFER_SIZE         CAL_RANDOMSEED_CONTEXT_BUFFER_SIZE

/* Configuration IDs */
#define CalHashConfig                       0U 
#define CalConf_CalHashConfig_CalHashConfig 0U 


#endif /* CAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Cal_Cfg.h
 *********************************************************************************************************************/

