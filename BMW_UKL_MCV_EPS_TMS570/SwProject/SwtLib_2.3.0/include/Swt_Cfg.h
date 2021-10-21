/**************************************************************************//**
 * \file
 * Module configuration file for SWT library.
 *
 * \target All
 * \project SWT
 * \author BMW AG
 * \userchange Yes
 *
 * This file contains various parameters that must be reviewed and possibly
 * modified by the integrator.
 *****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Aug 18 20:09:21 2012
* %version:          2 %
* %derived_by:       wz7x3j %
* %date_modified:    Sat Sep 29 12:34:35 2012 %
*---------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 09/29/12   2        BDO         SWT updates - anomaly 3782
 */

#if (!defined SWT_CFG_H)               /* preprocessor exclusion definition */
#define SWT_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

                              /* list of guards to prevent double definitions */
#if (defined SWT_CFG_ON)
   #error SWT_CFG_ON already defined
#endif                                           /* if (defined SWT_CFG_ON) */

#if (defined SWT_CFG_OFF)
   #error SWT_CFG_OFF already defined
#endif                                          /* if (defined SWT_CFG_OFF) */

/** Configuration value = true. */
#define SWT_CFG_ON 1U
/** Configuration value = false. */
#define SWT_CFG_OFF 0U



/* --------------------------- Os configuration ----------------------------- */

#if (defined SWT_USE_OS)
#error SWT_USE_OS already defined
#endif                                           /* if (defined SWT_USE_OS) */

/** Flag whether to include os.h for definition of architecture constants. */
#define SWT_USE_OS SWT_CFG_ON

#if (SWT_USE_OS == SWT_CFG_ON)
#include "os.h"
#else
#define __ARCH_Win32x86__
#endif                                   /* if (SWT_USE_OS == SWT_CFG_ON) */

/* ------------------- Persistent Storage configuration --------------------- */

/** Internal ID for NVRAM block for software data. */
#define SWT_SW_DATA            0U
/** Internal ID for NVRAM block for certificate data. */
#define SWT_CERT_DATA          1U
/** Internal ID for NVRAM block for software signature data. */
#define SWT_SWSIG_DATA         2U
/** Internal ID for NVRAM block for SWT SHORT data. */
#define SWT_SHORT_DATA         3U

/* --------------------------- RSA configuration ---------------------------- */

#if (defined SWT_FSC_SIG_LEN_BYTES)
   #error SWT_FSC_SIG_LEN_BYTES already defined
#endif                                /* if (defined SWT_FSC_SIG_LEN_BYTES) */

#if (defined SWT_RSA_KEY_LEN_BYTES)
   #error SWT_RSA_KEY_LEN_BYTES already defined
#endif                                /* if (defined SWT_RSA_KEY_LEN_BYTES) */

#if (defined SWT_RSA_USE_BARRETT)
   #error SWT_RSA_USE_BARRETT already defined
#endif                                  /* if (defined SWT_RSA_USE_BARRETT) */

/** Use barrett reduction? */
#define SWT_RSA_USE_BARRETT SWT_CFG_OFF


/* ------------------------ debugging configuration ------------------------- */

                               /* list of guards to prevent double definition */
#if (defined SWT_STATIC_VAR)
   #error SWT_STATIC_VAR already defined
#endif                                       /* if (defined SWT_STATIC_VAR) */

#if (defined SWT_STATIC_FUNC)
   #error SWT_STATIC_FUNC already defined
#endif                                      /* if (defined SWT_STATIC_FUNC) */

#if (defined SWT_DEV_ERROR_DETECT)
   #error SWT_DEV_ERROR_DETECT already defined
#endif                                 /* if (defined SWT_DEV_ERROR_DETECT) */

#if (defined SWT_DET_MODULE_ID)
   #error SWT_DET_MODULE_ID already defined
#endif                                    /* if (defined SWT_DET_MODULE_ID) */

#if (defined SWT_COMPUTE_HASH_INIT_API_ID)
   #error SWT_COMPUTE_HASH_INIT_API_ID already defined
#endif                         /* if (defined SWT_COMPUTE_HASH_INIT_API_ID) */

#if (defined SWT_COMPUTE_HASH_UPDATE_API_ID)
   #error SWT_COMPUTE_HASH_UPDATE_API_ID already defined
#endif                       /* if (defined SWT_COMPUTE_HASH_UPDATE_API_ID) */

#if (defined SWT_COMPUTE_HASH_FIN_API_ID)
   #error SWT_COMPUTE_HASH_FIN_API_ID already defined
#endif                          /* if (defined SWT_COMPUTE_HASH_FIN_API_ID) */

#if (defined SWT_VERIFY_ASYM_INIT_API_ID)
   #error SWT_VERIFY_ASYM_INIT_API_ID already defined
#endif                          /* if (defined SWT_VERIFY_ASYM_INIT_API_ID) */

#if (defined SWT_VERIFY_ASYM_UPDATE_API_ID)
   #error SWT_VERIFY_ASYM_UPDATE_API_ID already defined
#endif                        /* if (defined SWT_VERIFY_ASYM_UPDATE_API_ID) */

#if (defined SWT_VERIFY_ASYM_FINALIZE_API_ID)
   #error SWT_VERIFY_ASYM_FINALIZE_API_ID already defined
#endif                      /* if (defined SWT_VERIFY_ASYM_FINALIZE_API_ID) */

#if (defined SWT_HANDLER_STOREFSC_API_ID)
   #error SWT_HANDLER_STOREFSC_API_ID already defined
#endif                          /* if (defined SWT_HANDLER_STOREFSC_API_ID) */

#if (defined SWT_HANDLER_GETELEMENT_API_ID)
   #error SWT_HANDLER_GETELEMENT_API_ID already defined
#endif                        /* if (defined SWT_HANDLER_GETELEMENT_API_ID) */

#if (defined SWT_COMMON_COMPARE_API_ID)
   #error SWT_COMMON_COMPARE_API_ID already defined
#endif                            /* if (defined SWT_COMMON_COMPARE_API_ID) */

#if (defined SWT_COMMON_COPY_API_ID)
   #error SWT_COMMON_COPY_API_ID already defined
#endif                               /* if (defined SWT_COMMON_COPY_API_ID) */

#if (defined SWT_COMMON_SET_API_ID)
   #error SWT_COMMON_SET_API_ID already defined
#endif                                /* if (defined SWT_COMMON_SET_API_ID) */

                /* debugging configuration to enable/disable static variables */
#define SWT_STATIC_VAR static

                /* debugging configuration to enable/disable static functions */
#define SWT_STATIC_FUNC static

             /* if this macro is defined, more elaborate checks are performed */
#define SWT_DEV_ERROR_DETECT SWT_CFG_OFF

#if (SWT_DEV_ERROR_DETECT == SWT_CFG_ON)
#include "Det.h"                                         /* DET for debugging */
#endif

                          /*  The module ID of the SWT for usage in the DET */
#define SWT_DET_MODULE_ID 778U

#define SWT_COMPUTE_HASH_INIT_API_ID     1U
#define SWT_COMPUTE_HASH_UPDATE_API_ID   2U
#define SWT_COMPUTE_HASH_FIN_API_ID      3U
#define SWT_VERIFY_ASYM_INIT_API_ID      4U
#define SWT_VERIFY_ASYM_UPDATE_API_ID    5U
#define SWT_VERIFY_ASYM_FINALIZE_API_ID  6U
#define SWT_HANDLER_STOREFSC_API_ID      7U
#define SWT_HANDLER_GETFSC_API_ID        8U
#define SWT_HANDLER_PERIODICAL_API_ID    9U
#define SWT_HANDLER_DLPOST_API_ID        10U
#define SWT_HANDLER_GETSWID_API_ID       11U
#define SWT_HANDLER_GETSTATUS_API_ID     12U
#define SWT_HANDLER_CHECKFSC_API_ID      13U
#define SWT_HANDLER_DISABLEFSC_API_ID    14U
#define SWT_HANDLER_ACTIVATED_API_ID     15U
#define SWT_COMMON_COMPARE_API_ID        16U
#define SWT_COMMON_COPY_API_ID           17U
#define SWT_COMMON_SET_API_ID            18U
#define SWT_DCM_HANDLER_RC_SWT_API_ID    19U



/* ----------------- software signature check configuration ----------------- */


/* The header which contains the software signature check function.           */
#include "Appl_Crypto.h"

/* The return type of the signature check function                            */
#define Swt_SigRet_t CR_C_RC_t

/* The successful return value                                                */
#define Swt_SIG_OK   CR_C_RC_OK

/**************************************************************************//**
 * \def Swt_CryptoCheckSigSW
 * Macro mapping internal to platform function verifying the signature of an
 * SWE.
 *
 * \param nNumBlocks
 *      Number of blocks in SWE.
 * \param ppText
 *      Array of data blocks in SWE.
 * \param pnLength
 *      Array of block lengths.
 * \param pSignature
 *      Signature to verify.
 * \return
 *      #Swt_SIG_OK is signature was verified successfully.
 */

/* NXTR SWT */
/* The Swt_CryptoCheckSigSW needs to be mapped to Crypto_CheckSigSW - return Swt_SIG_OK when testing with unsigned SWE */
/* Since we have no SWE yet, just return OK for SW signature check. */
//#define Swt_CryptoCheckSigSW(nNumBlocks,ppText,pnLength,pSignature)   Swt_SIG_OK

/* NXTR SWT - SWE is signed. Signature is required for SWT. Use macro above when testing with unsigned SWE. */
#define Swt_CryptoCheckSigSW(nNumBlocks,ppText,pnLength,pSignature)   Crypto_CheckSigSW((nNumBlocks),(ppText),(pnLength),(pSignature),0,0)

/* -------------------- Diagnostic support configuration -------------------- */

/** Flag whether support for diagnostic protocol UDS is enabled. */
#define SWT_DIAG_USE_UDS			SWT_CFG_ON

/** Flag whether support for diagnostic protocol KWP 2000 is enabled, */
/** No SWT Short support */
#define SWT_DIAG_USE_KWP2000		SWT_CFG_OFF

/** Flag whether to use handling of SWT-enabled ECU list (typically only in VCM). */
#define SWT_DIAG_USE_ECU_SWTLIST	SWT_CFG_OFF

/* Santity check for diagnostic configuration. */
#if ((SWT_DIAG_USE_UDS == SWT_CFG_ON) && (SWT_DIAG_USE_KWP2000 == SWT_CFG_ON))
	#error Simultaneous usage of UDS and KWP2000 not supported.
#endif /* ((SWT_DIAG_USE_UDS == SWT_CFG_ON) && (SWT_DIAG_USE_KWP2000 == SWT_CFG_ON)) */

/* ------------------ FSC validity condition configuration ------------------ */

/** The maximal length of the validity condition field.                         */
#define SWT_VALIDITY_COND_MAX_LEN 30U

/* The user can configure which validity condition types (AllgGB) can be used */
/* in an FSC.                                                                 */

/** The type "unlimited" (0x01). */
#define SWT_USE_VAL_COND_UNLIMITED SWT_CFG_ON

/** The type "expiration date" (0x02). */
#define SWT_USE_VAL_COND_DATE      SWT_CFG_OFF

/** The type "time period" (0x03). */
#define SWT_USE_VAL_COND_PERIOD    SWT_CFG_OFF

/** The type "kilometers travelled" (0x04). */
#define SWT_USE_VAL_COND_KM        SWT_CFG_OFF

/** The type "operation time" (0x05). */
#define SWT_USE_VAL_COND_OP_TIME   SWT_CFG_OFF

/** The type "days" (0x06). */
#define SWT_USE_VAL_COND_DAYS      SWT_CFG_OFF




/* ------------------- FSC additional fields configuration ------------------ */

/** The maximal added length of all additional fields.                        */
#define SWT_ADD_FIELD_MAX_LEN 136U


/* ----------------------- FSC signature configuration ---------------------- */

/**The length of the FSC signature in bytes.                                  */
#define SWT_FSC_SIG_LEN_BYTES  128U


/* ------------------------ FSC type configuration -------------------------- */

/** Flag whether to use features of SWT Full (FSCs with certificates). */
#define SWT_USE_SWT_FULL SWT_CFG_OFF

/** Flag whether to use features of SWT Short (short FSC with symmetric encryption and enabler FSC). */
#define SWT_USE_SWT_SHORT SWT_CFG_OFF


/* ------------------ virtual controller configuration ---------------------- */

/** Number of virtual controllers that this module must support. */
#define SWT_NR_OF_SGIDS 1

/**************************************************************************//**
 * Array initializer containing a comma separated list of SGIDs.
 *
 * The length of the list must be #SWT_NR_OF_SGIDS.
 */
#define SWT_SGIDS 0x30



/** The number of SWIDs in the first virtual controller.                       */
#define SWT_NR_OF_SWIDS_IN_SGID_1 1

/**************************************************************************//**
 * The number of all SWIDs in all virtual controllers.
 *
 * It must be #SWT_NR_OF_SWIDS_IN_SGID_1 + SWT_NR_OF_SWIDS_IN_SGID_2 + ...
 */
#define SWT_NR_OF_SWIDS             \
        SWT_NR_OF_SWIDS_IN_SGID_1

/**************************************************************************//**
 * Array initializer containing the number of SWIDs in each virtual controller.
 *
 * This must be a comma separated list of the macros
 * "SWT_NR_OF_SWIDS_IN_SGID_<X>". The length of the list must be #SWT_NR_OF_SGIDS.
 */
#define SWT_NR_OF_SWIDS_ARRAY_INIT \
        SWT_NR_OF_SWIDS_IN_SGID_1

/**************************************************************************//**
 * Number of FSCS certificates which must be stored in the first virtual controller.
 *
 * This is identical to the number of SWIDs which have "full" FSCs.
 */
#define SWT_NR_OF_CERTS_IN_SGID_1 0  /* NXTR SWT */

/**************************************************************************//**
 * Number of all FSCS certificates in all virtual controllers.
 *
 * It must be #SWT_NR_OF_CERTS_IN_SGID_1 + SWT_NR_OF_CERTS_IN_SGID_2 + ...
 */
#define SWT_NR_OF_CERTS             \
        SWT_NR_OF_CERTS_IN_SGID_1

/**************************************************************************//**
 * Array initializer containing the number of FSCS certificates in each virtual controller.
 *
 * This must be a comma separated list of the macros "SWT_NR_OF_CERTS_IN_SGID_<X>". The
 * length of the list must be #SWT_NR_OF_SGIDS.
 */
#define SWT_NR_OF_CERTS_ARRAY_INIT \
        SWT_NR_OF_CERTS_IN_SGID_1




/* -------------------- initialization configuration ------------------------ */

/**************************************************************************//**
 * Flag whether function Swt_SwDownloadPostAction() is used.
 *
 * Swt_SwDownloadPostAction() is used to initialize the SW data values and the software signature
 * state after new software has been flashed. If the flag is set to #SWT_CFG_OFF
 * the values are initialized with the default values specified below.
 */
#define SWT_USE_SW_DL_POST_ACTION SWT_CFG_OFF



#if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_OFF)


/**************************************************************************//**
 * Array initializer containing default SW data values for the
 * first virtual controller.
 *
 * It includes the SWIDs and the FSC type. It must be a comma separated list of the macros
 * SWT_SW_DATA_DEFAULT_VALUES(), with the SWIDs and the FSC type as
 * inputs. The length of the list must be #SWT_NR_OF_SWIDS_IN_SGID_1.
 *
 * The amount of SWIDs with an FSC type of "full" must be the same as the
 * value of #SWT_NR_OF_CERTS_IN_SGID_1 and they must be the first elements
 * in the list.
 */
// TODO: Barrett

/*  NXTR SWT  - Nxtr commented out and reconfigured below
#define SWT_SW_DATA_DEFAULT_IN_SGID_1 \
SWT_SW_DATA_DEFAULT_VALUES ( 0x00, 0x1b, 0x00, 0x01, Swt_FSC_TYPE_FULL ), \
SWT_SW_DATA_DEFAULT_VALUES ( 0x00, 0x47, 0x00, 0x02, Swt_FSC_TYPE_SHORT )
*/

/*  /* NXTR SWT  - Nxtr modification for SWT Light and single SWID */
#define SWT_SW_DATA_DEFAULT_IN_SGID_1 \
SWT_SW_DATA_DEFAULT_VALUES ( 0x00, 0xBD, 0x00, 0x01, Swt_FSC_TYPE_LIGHT )


/**************************************************************************//**
 * Default values for the SW data for all virtual controllers.
 *
 * This must be a comma separated list of macros "SWT_SW_DATA_DEFAULT_IN_SGID_<X>".
 * The length of the list must be #SWT_NR_OF_SGIDS.
 */
#define SWT_SW_DATA_DEFAULT_INIT \
        SWT_SW_DATA_DEFAULT_IN_SGID_1


/**************************************************************************//**
 * Array initializer containing the default SW signature states for all virtual
 * controllers.
 *
 * This must be a comma separated list of the macro #SWT_SWSIG_DATA_DEFAULT_VALUES.
 * The length of the list must be #SWT_NR_OF_SGIDS.
 */
#define SWT_SW_SIG_DATA_DEFAULT_INIT \
        SWT_SWSIG_DATA_DEFAULT_VALUES




/**************************************************************************//**
 * Array initializer containing the default certificate values for all virtual
 * controllers.
 *
 * This must be a comma separated list of the macros #SWT_CERT_DATA_DEFAULT_VALUES.
 * The length of the list must be #SWT_NR_OF_CERTS.
 */
#define SWT_CERT_DATA_DEFAULT_INIT											\
        SWT_CERT_DATA_DEFAULT_VALUES	/* FSCS certificate for 1st SWID */




/**************************************************************************//**
 * Macro defining the format of the default value declaration.
 *
 * This macro gives the format of the SW data default information. It gets as
 * input the four bytes of an SWID and the type of the FSC which should be stored
 * for the given SWID (#Swt_FSC_TYPE_LIGHT, #Swt_FSC_TYPE_FULL, or
 * #Swt_FSC_TYPE_SHORT). This macro must be used in the definition of
 * "SWT_SW_DATA_DEFAULT_IN_SGID_<X>".
 */
#define SWT_SW_DATA_DEFAULT_VALUES( SWIDByte1,             \
                                      SWIDByte2,           \
                                      SWIDByte3,           \
                                      SWIDByte4,           \
                                      FSCType)             \
{                                                          \
   Swt_STATE_SW_DEACTIVATED,                               \
   Swt_STATE_FSC_NOT_EXISTENT,                             \
   { (SWIDByte1), (SWIDByte2), (SWIDByte3), (SWIDByte4) }, \
   {0},                                                    \
   0,                                                      \
   (FSCType)                                               \
}



#if (SWT_USE_SWT_FULL == SWT_CFG_ON)

/**
 * Macro defining format of the FSCS certificate default information.
 *
 * It must be used in the definition of "SWT_CERT_DATA_DEFAULT_IN_SGID_<X>".
 */
/* The FSCS certificate below is a production FSCS certificate. */
#define SWT_CERT_DATA_DEFAULT_VALUES { Swt_STATE_CERT_ACCEPTED,                                     \
{                                                                                                   \
    0x30, 0x82, 0x03, 0x08, 0x30, 0x82, 0x01, 0xf0, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x02, 0x04, \
    0x02, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x04, 0x05, 0x00, \
    0x30, 0x69, 0x31, 0x13, 0x30, 0x11, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64, \
    0x01, 0x19, 0x16, 0x03, 0x63, 0x6f, 0x6d, 0x31, 0x18, 0x30, 0x16, 0x06, 0x0a, 0x09, 0x92, 0x26, \
    0x89, 0x93, 0xf2, 0x2c, 0x64, 0x01, 0x19, 0x16, 0x08, 0x62, 0x6d, 0x77, 0x67, 0x72, 0x6f, 0x75, \
    0x70, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x70, 0x6b, 0x69, 0x31, \
    0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x0b, 0x62, 0x6d, 0x77, 0x2d, 0x66, 0x7a, \
    0x67, 0x2d, 0x70, 0x6b, 0x69, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0b, \
    0x66, 0x7a, 0x67, 0x2d, 0x72, 0x6f, 0x6f, 0x74, 0x2d, 0x63, 0x61, 0x30, 0x1e, 0x17, 0x0d, 0x30, \
    0x37, 0x30, 0x37, 0x33, 0x30, 0x31, 0x32, 0x34, 0x38, 0x32, 0x35, 0x5a, 0x17, 0x0d, 0x31, 0x32, \
    0x30, 0x37, 0x33, 0x30, 0x31, 0x32, 0x34, 0x38, 0x32, 0x35, 0x5a, 0x30, 0x81, 0x8c, 0x31, 0x13, \
    0x30, 0x11, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64, 0x01, 0x19, 0x13, 0x03, \
    0x63, 0x6f, 0x6d, 0x31, 0x18, 0x30, 0x16, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, \
    0x64, 0x01, 0x19, 0x13, 0x08, 0x62, 0x6d, 0x77, 0x67, 0x72, 0x6f, 0x75, 0x70, 0x31, 0x0c, 0x30, \
    0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x70, 0x6b, 0x69, 0x31, 0x14, 0x30, 0x12, 0x06, \
    0x03, 0x55, 0x04, 0x0b, 0x13, 0x0b, 0x62, 0x6d, 0x77, 0x2d, 0x66, 0x7a, 0x67, 0x2d, 0x70, 0x6b, \
    0x69, 0x31, 0x37, 0x30, 0x35, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x2e, 0x7a, 0x65, 0x6e, 0x74, \
    0x72, 0x61, 0x6c, 0x65, 0x20, 0x4d, 0x61, 0x73, 0x74, 0x65, 0x72, 0x20, 0x46, 0x72, 0x65, 0x69, \
    0x73, 0x63, 0x68, 0x61, 0x6c, 0x74, 0x63, 0x6f, 0x64, 0x65, 0x73, 0x74, 0x65, 0x6c, 0x6c, 0x65, \
    0x2d, 0x50, 0x72, 0x6f, 0x64, 0x75, 0x6b, 0x74, 0x69, 0x76, 0x30, 0x81, 0x9d, 0x30, 0x0d, 0x06, \
    0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8b, 0x00, \
    0x30, 0x81, 0x87, 0x02, 0x81, 0x81, 0x00, 0xf5, 0x70, 0x90, 0xd4, 0x8c, 0xef, 0x3b, 0x1f, 0xf7, \
    0x8c, 0xf9, 0x5c, 0x6d, 0x53, 0x10, 0x79, 0x80, 0x72, 0x07, 0x5b, 0x64, 0x35, 0xc2, 0x78, 0x92, \
    0xea, 0x4c, 0x57, 0x3f, 0x36, 0x84, 0x9c, 0xf3, 0xf3, 0x69, 0x07, 0xe5, 0xb0, 0x41, 0xce, 0x57, \
    0x69, 0xab, 0x0a, 0x75, 0xdd, 0xda, 0xab, 0x1a, 0xf5, 0x2a, 0x2a, 0xa6, 0x5e, 0x54, 0xd3, 0x1d, \
    0xce, 0x97, 0x38, 0xd7, 0x9d, 0xa6, 0x11, 0x7d, 0xc9, 0x3b, 0xd0, 0x1b, 0x29, 0xa4, 0x54, 0x67, \
    0x10, 0x57, 0xe1, 0x3c, 0x59, 0x97, 0x38, 0xac, 0x6f, 0xe2, 0x90, 0xb1, 0xdf, 0x43, 0xbd, 0x3b, \
    0xec, 0x80, 0x0f, 0xaf, 0x59, 0xf2, 0x1f, 0x8e, 0x18, 0x9b, 0x4b, 0xd8, 0x34, 0x1f, 0x3e, 0x97, \
    0x13, 0xb8, 0xec, 0x71, 0xc1, 0x84, 0xbb, 0xec, 0x17, 0xc6, 0xad, 0x2c, 0xa6, 0x3d, 0x21, 0x74, \
    0x80, 0xb1, 0x55, 0xd6, 0x69, 0xf8, 0x03, 0x02, 0x01, 0x03, 0xa3, 0x1c, 0x30, 0x1a, 0x30, 0x18, \
    0x06, 0x03, 0x55, 0x1d, 0x25, 0x01, 0x01, 0xff, 0x04, 0x0e, 0x30, 0x0c, 0x06, 0x0a, 0x2b, 0x06, \
    0x01, 0x04, 0x01, 0x84, 0x01, 0x0a, 0x01, 0x01, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, \
    0xf7, 0x0d, 0x01, 0x01, 0x04, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0x0c, 0x39, 0x17, 0xb4, \
    0x04, 0xff, 0x7e, 0x74, 0xb4, 0x3e, 0x49, 0xb2, 0x57, 0xbc, 0xa9, 0xd8, 0x7c, 0xd7, 0xe6, 0x5c, \
    0x27, 0x31, 0xc9, 0xf1, 0xb3, 0x12, 0x87, 0x07, 0xd0, 0xe1, 0xc0, 0xdc, 0x8c, 0x26, 0xe1, 0xec, \
    0x4b, 0xae, 0x21, 0x1d, 0x04, 0xd5, 0xf9, 0xf1, 0xe7, 0x87, 0x16, 0x67, 0xbb, 0xb4, 0xb7, 0xad, \
    0x3d, 0x1c, 0xb5, 0xb6, 0xde, 0x72, 0x22, 0x73, 0x6d, 0xf9, 0xca, 0xd1, 0x80, 0x15, 0xb2, 0x81, \
    0x33, 0xbf, 0x07, 0xf4, 0x7a, 0xd1, 0x7a, 0x2c, 0x17, 0x77, 0x3b, 0x2d, 0x91, 0x1c, 0xcf, 0x01, \
    0x25, 0x35, 0x64, 0x09, 0x7f, 0x4c, 0x7b, 0x95, 0xc3, 0x4b, 0x6a, 0x60, 0x38, 0xf7, 0x7b, 0x1b, \
    0xf8, 0x74, 0xc2, 0x57, 0x6c, 0xdd, 0x54, 0x92, 0x7b, 0xba, 0x54, 0x7a, 0x47, 0xfb, 0x45, 0x97, \
    0xcc, 0x0c, 0x91, 0x55, 0x45, 0x71, 0x8a, 0x62, 0xe6, 0x3d, 0x8c, 0xee, 0x67, 0x41, 0x5b, 0xf9, \
    0xf0, 0x4f, 0x88, 0xbc, 0xf5, 0x15, 0xa8, 0x1d, 0x88, 0x3d, 0xba, 0x17, 0xe1, 0x24, 0x30, 0x31, \
    0xe3, 0xf7, 0xdd, 0xe2, 0xbc, 0xb7, 0x3c, 0x3f, 0x23, 0xbe, 0x55, 0x77, 0x7f, 0x63, 0x4e, 0x85, \
    0x7d, 0x41, 0xbc, 0x21, 0xf4, 0x3d, 0xdf, 0x1a, 0x46, 0x53, 0xda, 0x91, 0x68, 0xfd, 0x55, 0xc1, \
    0xcb, 0xd8, 0xfa, 0xb6, 0x81, 0xb3, 0x89, 0xdf, 0x20, 0xb7, 0x4a, 0x46, 0x69, 0x19, 0x0b, 0x0d, \
    0xed, 0x58, 0xc6, 0xd2, 0x93, 0xd6, 0xf1, 0x09, 0x84, 0x68, 0x82, 0x76, 0xdc, 0xcd, 0x80, 0xd1, \
    0x98, 0x38, 0x1c, 0x38, 0x33, 0xa2, 0x3f, 0x40, 0x5f, 0xa7, 0x46, 0x20, 0x2f, 0x6d, 0x70, 0x8a, \
    0xb2, 0xb1, 0x3f, 0xbe, 0xae, 0x4f, 0x96, 0x66, 0xa6, 0x8c, 0xd2, 0xcf, 0xf1, 0xc8, 0x59, 0xb9, \
    0x1e, 0xf5, 0xa7, 0x69, 0xd8, 0x54, 0xc7, 0xed, 0xdb, 0x39, 0x9c, 0x2e } }


/**
 * Macro defining format of the SW signature default information.
 *
 * It must be used in the definition of "SWT_SW_SIG_DATA_DEFAULT_INIT".
 */
#define SWT_SWSIG_DATA_DEFAULT_VALUES																	\
{                                    																	\
	Swt_STATE_SWSIG_ACCEPTED,																			\
	Swt_STATE_CERT_ACCEPTED,	       																	\
	Swt_STATE_CERT_ACCEPTED,           																	\
	{																									\
		0x30, 0x82, 0x02, 0x9f, 0x30, 0x82, 0x01, 0x87, 0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x02, 0x03,	\
		0xf2, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x04, 0x05, 0x00,	\
		0x30, 0x69, 0x31, 0x13, 0x30, 0x11, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64,	\
		0x01, 0x19, 0x16, 0x03, 0x63, 0x6f, 0x6d, 0x31, 0x18, 0x30, 0x16, 0x06, 0x0a, 0x09, 0x92, 0x26,	\
		0x89, 0x93, 0xf2, 0x2c, 0x64, 0x01, 0x19, 0x16, 0x08, 0x62, 0x6d, 0x77, 0x67, 0x72, 0x6f, 0x75,	\
		0x70, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x70, 0x6b, 0x69, 0x31,	\
		0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x0b, 0x62, 0x6d, 0x77, 0x2d, 0x66, 0x7a,	\
		0x67, 0x2d, 0x70, 0x6b, 0x69, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0b,	\
		0x66, 0x7a, 0x67, 0x2d, 0x72, 0x6f, 0x6f, 0x74, 0x2d, 0x63, 0x61, 0x30, 0x1e, 0x17, 0x0d, 0x30,	\
		0x36, 0x30, 0x37, 0x31, 0x39, 0x31, 0x31, 0x33, 0x31, 0x32, 0x30, 0x5a, 0x17, 0x0d, 0x31, 0x31,	\
		0x30, 0x37, 0x32, 0x30, 0x31, 0x31, 0x33, 0x31, 0x32, 0x30, 0x5a, 0x30, 0x6a, 0x31, 0x13, 0x30,	\
		0x11, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64, 0x01, 0x19, 0x16, 0x03, 0x63,	\
		0x6f, 0x6d, 0x31, 0x18, 0x30, 0x16, 0x06, 0x0a, 0x09, 0x92, 0x26, 0x89, 0x93, 0xf2, 0x2c, 0x64,	\
		0x01, 0x19, 0x16, 0x08, 0x62, 0x6d, 0x77, 0x67, 0x72, 0x6f, 0x75, 0x70, 0x31, 0x0c, 0x30, 0x0a,	\
		0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 0x03, 0x70, 0x6b, 0x69, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03,	\
		0x55, 0x04, 0x0b, 0x13, 0x0b, 0x62, 0x6d, 0x77, 0x2d, 0x66, 0x7a, 0x67, 0x2d, 0x70, 0x6b, 0x69,	\
		0x31, 0x15, 0x30, 0x13, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0c, 0x43, 0x43, 0x43, 0x2d, 0x53,	\
		0x69, 0x67, 0x53, 0x2d, 0x4b, 0x65, 0x79, 0x30, 0x5a, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48,	\
		0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x49, 0x00, 0x30, 0x46, 0x02, 0x41, 0x00,	\
		0x9f, 0x1d, 0xc9, 0xb8, 0x3d, 0x10, 0xc9, 0x13, 0xd3, 0x05, 0x3a, 0xe0, 0xe7, 0x0c, 0xaa, 0x0d,	\
		0xed, 0x4f, 0x13, 0x4e, 0x5a, 0xc1, 0x5b, 0x79, 0x47, 0x6b, 0x5c, 0xec, 0x4d, 0xe0, 0x86, 0xc7,	\
		0xa5, 0x3f, 0x71, 0x19, 0x75, 0x2a, 0xca, 0xda, 0xd5, 0xcb, 0x88, 0xa1, 0xfe, 0x0f, 0x3c, 0xf7,	\
		0xa6, 0xcc, 0x6d, 0xe0, 0xda, 0xc7, 0xb4, 0x88, 0x63, 0xe6, 0x3a, 0x55, 0x6f, 0x82, 0x16, 0x6b,	\
		0x02, 0x01, 0x07, 0xa3, 0x1a, 0x30, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x1d, 0x25, 0x01, 0x01,	\
		0xff, 0x04, 0x0c, 0x30, 0x0a, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x03, 0x30,	\
		0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x04, 0x05, 0x00, 0x03, 0x82,	\
		0x01, 0x01, 0x00, 0x4d, 0x39, 0xea, 0x14, 0xef, 0x79, 0xe8, 0xaa, 0xbb, 0x68, 0xc0, 0x28, 0xa2,	\
		0x4e, 0x73, 0xce, 0xa6, 0x11, 0x31, 0x03, 0x1b, 0x01, 0xf4, 0x96, 0xb6, 0x0d, 0x0d, 0xbc, 0x0e,	\
		0x63, 0x47, 0x94, 0xa0, 0x35, 0x97, 0x62, 0x3d, 0x36, 0x0d, 0x6d, 0x36, 0xd0, 0x79, 0x2d, 0x60,	\
		0x73, 0x58, 0x98, 0x66, 0x94, 0xcb, 0x3b, 0xd1, 0x57, 0x46, 0xb6, 0xb8, 0x06, 0x6b, 0xa1, 0x34,	\
		0x24, 0x20, 0x4d, 0xdb, 0x3a, 0xd4, 0x84, 0xb7, 0x1c, 0x0b, 0x21, 0x34, 0x3d, 0xfc, 0xcf, 0x0b,	\
		0xa0, 0x14, 0xc9, 0x5c, 0x34, 0xbe, 0x2c, 0x1a, 0x04, 0xa1, 0x74, 0x81, 0x61, 0x3b, 0x49, 0x97,	\
		0x05, 0x93, 0xd8, 0x47, 0xd9, 0xce, 0x3b, 0x77, 0x96, 0x36, 0x41, 0xec, 0x9f, 0xf9, 0x98, 0xd9,	\
		0x88, 0x7c, 0x78, 0xf4, 0xa7, 0xc8, 0x3f, 0x2e, 0x56, 0xa9, 0xb4, 0x13, 0xb0, 0x58, 0x74, 0xba,	\
		0x66, 0x8f, 0x6c, 0x57, 0xe9, 0x9e, 0xc3, 0xe4, 0xa2, 0xd4, 0x87, 0xfb, 0xb1, 0x4b, 0xe8, 0x9f,	\
		0x13, 0x8f, 0x0b, 0x51, 0xcd, 0x8d, 0x6b, 0x48, 0x29, 0xc1, 0x52, 0xa5, 0xbe, 0xa0, 0x57, 0xd5,	\
		0xeb, 0x0f, 0x49, 0x83, 0x98, 0x09, 0x6b, 0x62, 0xc7, 0xa2, 0x7d, 0xcf, 0x5f, 0xf7, 0x51, 0x22,	\
		0x16, 0xe0, 0x1d, 0x4c, 0xc1, 0x77, 0x34, 0xca, 0x67, 0x9e, 0xd8, 0xc3, 0xf5, 0x62, 0xda, 0xc7,	\
		0x34, 0x4f, 0x95, 0x5c, 0x54, 0x89, 0x94, 0xf9, 0x38, 0x42, 0xc7, 0x5b, 0x24, 0x61, 0x14, 0xa8,	\
		0xf9, 0xcd, 0xb0, 0x08, 0xef, 0xa1, 0xe9, 0x07, 0x17, 0x07, 0x3a, 0x87, 0x92, 0xd4, 0xe6, 0xd0,	\
		0x31, 0xce, 0x8a, 0x3a, 0xa8, 0xc5, 0xa9, 0x63, 0x67, 0x60, 0x39, 0x38, 0xad, 0xaf, 0x0e, 0x96,	\
		0x67, 0x78, 0x8a, 0x8c, 0x69, 0xbe, 0x3b, 0x1f, 0xda, 0xfe, 0x0e, 0xdc, 0x74, 0x65, 0x41, 0x8a,	\
		0xc6, 0x3a, 0x20																				\
	}																									\
}

#else                             /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) */

/**
 * Macro defining format of the SW signature default information.
 *
 * It must be used in the definition of "SWT_SW_SIG_DATA_DEFAULT_INIT".
 */
#define SWT_SWSIG_DATA_DEFAULT_VALUES	\
{                                       \
   Swt_STATE_SWSIG_ACCEPTED				\
}

#endif                      /* #if (SWT_USE_SWT_FULL == SWT_CFG_ON) #else */


#endif                  /* #if (SWT_USE_SW_DL_POST_ACTION == SWT_CFG_OFF) */


/* ------------------------- certificate configuration ---------------------- */

#if (defined SWT_CERT_MIN_LEN)
   #error SWT_CERT_MIN_LEN already defined
#endif                                     /* if (defined SWT_CERT_MIN_LEN) */

#if (defined SWT_CERT_MAX_LEN)
   #error SWT_CERT_MAX_LEN already defined
#endif                                     /* if (defined SWT_CERT_MAX_LEN) */


/** Minimum size of a certificate in bytes. */
#define SWT_CERT_MIN_LEN 600
/** Maximum size of a certificate in bytes. */
#define SWT_CERT_MAX_LEN 1000

/** Length of the certificate signature in bytes. */
#define SWT_CERT_SIG_LEN_BYTES  256U

/**
 * \def SWT_SIG_LEN_BYTES
 * Maximal signature length in bytes.
 */
#if (SWT_CERT_SIG_LEN_BYTES > SWT_FSC_SIG_LEN_BYTES)
   #define SWT_SIG_LEN_BYTES SWT_CERT_SIG_LEN_BYTES
#else
   #define SWT_SIG_LEN_BYTES SWT_FSC_SIG_LEN_BYTES
#endif


/* ------------------------- SWT short configuration ------------------------ */

/** The SWID of the FSC_Enabler.                                                */
#define SWT_FSC_ENABLER_SWID_INIT            0x00, 0x1b, 0x00, 0x01

/** The length of the Diffie-Hellman key in bytes.                              */
#define SWT_DIFFIE_KEY_LEN_BYTES             128U

#define SWT_USE_VAL_COND_SHORT_KM            SWT_CFG_OFF
#define SWT_USE_VAL_COND_SHORT_CURRENT_DATE  SWT_CFG_OFF
#define SWT_USE_VAL_COND_SHORT_APPLICATION   SWT_CFG_OFF

/***********************************************************************************/
/* If SWT_SHORT_STORE is set, the out for the FSCEnabler derived key is stored in  */
/* in NVM-memory. Using this option is only valid for ECUs with weak CPUs, where   */
/* decrypting the key while a diagnostic command takes to much time.               */
/* ************ USING THIS OPTION HAS TO BE AGREED BY THE COC SECURITY *********** */
/***********************************************************************************/
#define SWT_SHORT_STORE                      SWT_CFG_OFF

/* Number of FSC-Short in the ECU, currently only one is possible */
#define SWT_NR_OF_SHORT                      0

#if (SWT_NR_OF_SHORT > 1)
#error ("More than one FSC Short makes no sense currently.")
#endif

#define SWT_SHORT_DATA_DEFAULT_INIT		\
        SWT_SHORT_DATA_DEFAULT_VALUES

/* SWT_SHORT_DATA_DEFAULT_VALUES have to be configured                       */
/* if SWT_SHORT_STORE is set to SWT_CFG_ON.                                 */
/* For each SWID with FSC-SHORT configured in SWT_SW_DATA_DEFAULT_IN_SGID_1 */
/* one entry has to be there in the following array.                        */
#define SWT_SHORT_DATA_DEFAULT_VALUES                             \
{                                                                 \
  {0x00, 0x47, 0x00, 0x02}, Swt_STATE_SHORT_NOTCHECKED, {0}, {0}  \
}

/***********************************************************************************/
/* Some checks for valid configuration                                             */
/***********************************************************************************/
#if((SWT_SHORT_STORE == SWT_CFG_ON) && (SWT_USE_SWT_SHORT != SWT_CFG_ON))
   #error("SWT_SHORT_STORE only usable with SWT_USE_SWT_SHORT")
#endif

#if((SWT_SHORT_STORE == SWT_CFG_ON) && (SWT_NR_OF_SHORT < 1))
   #error("SWT_SHORT_STORE only usable with SWT_NR_OF_SHORT >= 1")
#endif

#if (!defined SWT_FSC_ENABLER_SWID_INIT)
   #if (SWT_USE_SWT_SHORT == SWT_CFG_ON)
      #error("SWT_FSC_ENABLER_SWID_INIT missing for SWT Short")
   #endif
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


#endif                                           /* if (!defined SWT_CFG_H) */
/*** End of file **************************************************************/
