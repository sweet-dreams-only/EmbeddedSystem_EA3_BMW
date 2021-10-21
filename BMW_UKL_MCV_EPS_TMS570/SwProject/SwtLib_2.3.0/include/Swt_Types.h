/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Swt_Types.h                                                 **
**                                                                            **
**  Copyright (C) BMW Group 2007                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PROJECT   : SWT                                                           **
**                                                                            **
**  AUTHOR    : Elektrobit Automotive GmbH                                    **
**                                                                            **
**  PURPOSE   : Module Specific Types                                         **
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
 * V2.1.1    : 22.09.2007, djk  : changed SwtRC_t (Bugfix)
 *                                Swt_RC_CERT_REJECTED     = 0xF2 -> 0xF1
 *                                Swt_RC_CERT_NOT_EXISTENT = 0xF1 -> 0xF2                                 
 */

#if (!defined SWT_TYPES_H)             /* preprocessor exclusion definition */
#define SWT_TYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Std_Types.h"                              /* AUTOSAR specific types */

/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/** Return code for most operations used in the SWT library. */
typedef enum             /* definition of a return value type for this module */
{
	/** Operation successful. */
	Swt_RC_OK = 0x00,
	/** Entities are equal. */
	Swt_RC_EQUAL = 0x10,
	/** Entities are not equal. */
	Swt_RC_NOT_EQUAL = 0x11,
	/** First given entity is smaller than the second. */
	Swt_RC_SMALLER = 0x12,
	/** First given entity is larger than the second. */
	Swt_RC_LARGER = 0x13,
	/** The given hash context is invalid. */
	Swt_RC_INVALID_HASH_CONTEXT = 0x20,
	/** Given signature context is invalid. */
	Swt_RC_INVALID_SIG_CONTEXT = 0x21,
	/** Certificate issuer invalid. */
	Swt_RC_WRONG_CERT_CONTENT_ISSUER = 0x30,
	/** Extension field invalid. */
	Swt_RC_WRONG_CERT_CONTENT_CRIT_ELEM = 0x31,
	/** Invalid SigS certificate. */
	Swt_RC_SIGS_CERT_INVALID = 0x32,
	/** Invalid FSCS certificate. */
	Swt_RC_FSCS_CERT_INVALID = 0x33,
	/** Invalid certificate. */
	Swt_RC_CERT_INVALID = 0x34,                                               
	/** Derivation of Ksym disabled. */
	Swt_RC_KEY_DERIVATION_NOT_ACTIVATED = 0xCC,
	/** FSC is not imported. */
	Swt_RC_FSC_NOT_IMPORTED = 0xD0,
	/** The FSC has an invalid structure. */
	Swt_RC_INVALID_FSC = 0xD1,
	/** No access to the FGN. */
	Swt_RC_FGN_ACCESS_FAILURE = 0xD2,
	/** No memory to store data available. */
	Swt_RC_NO_FREE_SPACE = 0xD3,
	/** The content of the FSC is invalid. */
	Swt_RC_BAD_FSC_CONTENT = 0xD5,
	/** A parameter is either invalid or unsupported. */
	Swt_RC_BAD_PARAM = 0xD6,
	/** No information about given SG available. */
	Swt_RC_MISSING_SG_DATA = 0xD8,
	/** No authentication of level 3. */
	Swt_RC_NOT_AUTHENTICATED = 0xD9,
	/** The fingerprint is invalid. */
	Swt_RC_BAD_FINGERPRINT = 0xDA,
	/** Invalid validity check. */
	Swt_RC_VALIDITY_CHECK_FAILURE = 0xDC,
	/** The FGN is invalid. */
	Swt_RC_FGN_INVALID = 0xDD,
	/** Invalid FGN check. */
	Swt_RC_FGN_CHECK_FAILURE = 0xDE,
	/** Unable to read from flash. */
	Swt_RC_FLASH_READ_ERROR = 0xDF,
	/** Unable to write to flash. */
	Swt_RC_FLASH_WRITE_ERROR = 0xE0,
	/** FSC certificate invalid. */
	Swt_RC_FSCS_CERT_CHECK_FAILURE = 0xE4,
	/** FSC certificate not checked. */
	Swt_RC_FSCS_CERT_NOT_CHECKED = 0xE6,
	/** FSC certificate not stored. */
	Swt_RC_FSCS_CERT_NOT_EXISTENT = 0xE7,
	/** Certificate invalid. */
	Swt_RC_SIGS_CERT_CHECK_FAILURE = 0xE8,
	/** Certificate not checked. */
	Swt_RC_SIGS_CERT_NOT_CHECKED = 0xEA,
	/** SigS certificate not stored. */
	Swt_RC_SIGS_CERT_NOT_EXISTENT = 0xEB,
	/** Root certificate not valid. */
	Swt_RC_ROOT_CERT_INVALID = 0xEC,
	/** Data of root certificate corrupt. */
	Swt_RC_ROOT_CERT_CORRUPT = 0xEE,
	/** Root certificate not valid. */
	Swt_RC_ROOT_CERT_REJECTED = 0xED,
	/** Root certificate not stored. */
	Swt_RC_ROOT_CERT_NOT_READABLE = 0xEF,
	/** Root certificate not stored. */
	Swt_RC_ROOT_CERT_NOT_EXISTENT = 0xF0,
	/** Certificate not accepted. */
	Swt_RC_CERT_REJECTED = 0xF1,
	/** Certificate not stored. */
	Swt_RC_CERT_NOT_EXISTENT = 0xF2,
	/** Invalid FSC. */
	Swt_RC_FSC_CHECK_FAILURE = 0xF3,
	/** The FSC is cancelled. */
	Swt_RC_FSC_CANCELLED = 0xF4,
	/** The FSC status is rejected. */
	Swt_RC_FSC_REJECTED = 0xF5,
	/** No FSC available. */
	Swt_RC_FSC_NOT_EXISTENT = 0xF6,
	/** The FSC contains a wrong FSCS-ID. */
	Swt_RC_WRONG_FSCS_ID_IN_FSC = 0xF7,
	/** The FSC contains a wrong date. */
	Swt_RC_INVALID_FSC_CREATION_DATE = 0xF8,
	/** Invalid signature check. */
	Swt_RC_SIG_CHECK_FAILURE = 0xF9,
	/** Invalid SW signature check. */
	Swt_RC_SWSIG_CHECK_FAILURE = 0xFA,
	/** Invalid signature status. */
	Swt_RC_SWSIG_REJECTED = 0xFB,
	/** Invalid SWID. */
	Swt_RC_SWID_CHECK_FAILURE = 0xFC,
	/** The SW is not activated. */
	Swt_RC_SW_NOT_ACTIVATED = 0xFD,
	/** The software is not flashed. */
	Swt_RC_SW_NOT_EXISTENT = 0xFE,
	/** The source of the error is unknown. */
	Swt_RC_UNKNOWN_ERROR = 0xFF
}
SwtRC_t;

typedef enum
{
   Swt_STATE_FSC_NOT_EXISTENT = 0U,                        /* No FSC stored */
   Swt_STATE_FSC_IMPORTED,            /* FSC is imported but not yet stored */
   Swt_STATE_FSC_ACCEPTED,                              /* Valid FSC stored */
   Swt_STATE_FSC_REJECTED,                            /* Invalid FSC stored */
   Swt_STATE_FSC_DISABLED                          /* FSC has been disabled */
}
Swt_FSC_State;

                                                        /* The states of a SW */
typedef enum
{
   Swt_STATE_SW_NOT_EXISTENT = 0U,                          /* No SW stored */
   Swt_STATE_SW_ACTIVATED,                           /* The SW is activated */
   Swt_STATE_SW_DEACTIVATED                      /* The SW is not activated */
}
Swt_SW_State;

                            /* The different types of FSC: Light, Full, Short */
typedef enum
{
   Swt_FSC_TYPE_LIGHT = 0x01,
   Swt_FSC_TYPE_FULL  = 0x02,
   Swt_FSC_TYPE_SHORT = 0x05
}
Swt_FSCTypeType;

///* NXTR SWT */ - Nxtr added definition to correct SWT compile error
typedef uint32 Swt_LNWordType;  //typedef unsigned long       uint32;

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/


#endif                                         /* if (!defined SWT_TYPES_H) */
/*** End of file **************************************************************/
