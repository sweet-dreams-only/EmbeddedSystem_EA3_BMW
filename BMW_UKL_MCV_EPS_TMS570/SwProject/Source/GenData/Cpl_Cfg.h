/*----------------------------------------------------------------------------*/
/**
*  \file
*
*  \brief       BMW SWC Cpl Configuration
*
*  This file contains the configuration of all BMW Cpl's for usage in the BMW AUTOSAR Core.
*
*  \project     BMW AUTOSAR Core
*
*  \par         To be changed by user:
*               [no]
*
*  \copyright   BMW Group 2015
*
*  \version     3.0.2
*
*  \remarks     --
*
*/
/*----------------------------------------------------------------------------*/

#ifndef CPL_CFG_H
#define CPL_CFG_H

/*------------------------------------------------------------------------------
                      Include Section
------------------------------------------------------------------------------*/

#include "Std_Types.h"
#include "Cal.h"
#include "Cpl_Version.h"


/*------------------------------------------------------------------------------
                      Macros
------------------------------------------------------------------------------*/

/* check version of the module */
#if (!Cpl_CHECK_VERSION(3,0,2))
   #error "Version of Cpl_AESDecrypt_Cfg.h.tt does not match the version of the module!"
#endif


/* --- AESDecrypt --- */
/**
 * \brief Indicates whether the AESDecrypt primitive API definition code shall be enabled
 *        or not.
 */
#define CPL_AES_DECRYPT_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the AESDecrypt primitive.
 */
#define CPL_AES_DECRYPT_ENABLED STD_OFF

/* --- AESEncrypt --- */
/**
 * \brief Indicates whether the AESEncrypt primitive API definition code shall be enabled
 *        or not.
 */
#define CPL_AES_ENCRYPT_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the AESEncrypt primitive.
 */
#define CPL_AES_ENCRYPT_ENABLED STD_OFF

/* --- CbcDecWithBlockEnc --- */
/**
 * \brief Indicates whether the CbcDecWithBlockEnc primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_CBCDEC_WITHBLOCKENC_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the CbcDecWithBlockEnc primitive.
 */
#define CPL_CBCDEC_WITHBLOCKENC_ENABLED STD_OFF

/* --- CbcMacGenerate --- */
/**
 * \brief Indicates whether the CbcMacGenerate primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_CBC_MAC_G_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the CbcMacGenerate primitive.
 */
#define CPL_CBC_MAC_G_ENABLED STD_OFF

/* --- CbcMacVerify --- */
/**
 * \brief Indicates whether the CbcMacVerify primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_CBC_MAC_V_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the CbcMacVerify primitive.
 */
#define CPL_CBC_MAC_V_ENABLED STD_OFF

/* --- CbcPkcs5Decrypt --- */
/**
 * \brief Indicates whether the CbcPkcs5Decrypt primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_CBC_PKCS5_DEC_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the CbcPkcs5Decrypt primitive.
 */
#define CPL_CBC_PKCS5_DEC_ENABLED STD_OFF

/* --- DESDecrypt --- */
/**
 * \brief Indicates whether the DESDecrypt primitive API definition code shall be enabled
 *        or not.
 */
#define CPL_DES_DECRYPT_CODE_ENABLED STD_OFF

/** \brief Macro indicating whether there is any configuration for the DESDecrypt primitive.
 */
#define CPL_DES_DECRYPT_ENABLED STD_OFF

/* --- DESEncrypt --- */
/**
 * \brief Indicates whether the DESEncrypt primitive API definition code shall be enabled
 *        or not.
 */
#define CPL_DES_ENCRYPT_CODE_ENABLED STD_OFF

/** \brief Macro indicating whether there is any configuration for the DESEncrypt primitive.
 */
#define CPL_DES_ENCRYPT_ENABLED STD_OFF

/* --- DifHellman --- */
/**
 * \brief Indicates whether the DifHellman primitive API definition code shall be enabled
 *        or not.
 */
#define CPL_DIFHELLMAN_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the DifHellman primitive
 */
#define CPL_DIFHELLMAN_ENABLED STD_OFF

/* --- HMacGenerate --- */
/**
 * \brief Indicates whether the HMacGenerate primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_H_MAC_G_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the HMacGenerate primitive.
 */
#define CPL_H_MAC_G_ENABLED STD_OFF

/* --- HMacVerify --- */
/**
 * \brief Indicates whether the HMacVerify primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_H_MAC_V_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the HMacVerify primitive.
 */
#define CPL_H_MAC_V_ENABLED STD_OFF

/* --- MD5 --- */
/**
 * \brief Indicates whether the MD5 primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_MD5_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the MD5 primitive.
 */
#define CPL_MD5_ENABLED STD_OFF

/* --- PBKDF1 --- */
/**
 * \brief Indicates whether the PBKDF1 primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_PBKDF1_CODE_ENABLED STD_OFF

/** This Macro indicates whether there is a configuration for a PBKDF1.
 */
#define CPL_PBKDF1_ENABLED STD_OFF

/* --- PKCS1Vrfy --- */
/**
 * \brief Indicates whether the SigBMWVrfy primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_PKCS1_VRFY_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the PKCS1Vrfy primitive
 */
#define CPL_PKCS1_VRFY_ENABLED STD_OFF

/* --- SHA --- */
/**
 * \brief Indicates whether the SHA primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_SHA_CODE_ENABLED STD_ON

/**
 * \brief Indicates whether there is any configuration for the SHA primitive.
 */
#define CPL_SHA_ENABLED STD_ON

/* --- SigBMWVrfy --- */
/**
 * \brief Indicates whether the SigBMWVrfy primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_SIG_BMW_VRFY_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the SigBMWVrfy primitive
 */
#define CPL_SIG_BMW_VRFY_ENABLED STD_OFF

/* --- SSG --- */
/**
 * \brief Indicates whether the SSG primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_SSG_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the SSG primitive.
 */
#define CPL_SSG_ENABLED STD_OFF

/* --- SymKeyExtract --- */
/**
 * \brief Indicates whether the SymKeyExtract primitive API definition code shall be
 *        enabled or not.
 */
#define CPL_SYM_KEY_EXTRACT_CODE_ENABLED STD_OFF

/**
 * \brief Indicates whether there is any configuration for the SymKeyExtract primitive.
 */
#define CPL_SYM_KEY_EXTRACT_ENABLED STD_OFF


/*------------------------------------------------------------------------------
                      Data Types
------------------------------------------------------------------------------*/



/* --- SHA --- */
/**
 * \brief Type for the configured SHA algorithm.
 */
typedef enum
{
   CPL_SHA_1   = 0U,
   CPL_SHA_256
}
Cpl_SHAConfigIdType;

/**
 * \brief Configuration type for SHA.
 */
typedef struct
{
   Cpl_SHAConfigIdType                  ConfigId;
}
Cpl_SHAConfigType;


/*------------------------------------------------------------------------------
                      Global Variables
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
                      Global Constants
------------------------------------------------------------------------------*/

#define Cpl_START_SEC_CONST_UNSPECIFIED
#include <Cpl_MemMap.h>


/* --- SHA --- */
extern CONST(Cpl_SHAConfigType, Cpl_CONST) CplSHAConfig;

#define Cpl_STOP_SEC_CONST_UNSPECIFIED
#include <Cpl_MemMap.h>


#endif /* CPL_CFG_H */

/*--- End of file ------------------------------------------------------------*/
