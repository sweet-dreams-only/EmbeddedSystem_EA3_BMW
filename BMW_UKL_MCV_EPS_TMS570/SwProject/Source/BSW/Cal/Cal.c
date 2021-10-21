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
 *         File:  Cal.c
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

#define CAL_SOURCE
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Cal.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (CAL_SW_MAJOR_VERSION != (0x02)) \
    || (CAL_SW_MINOR_VERSION != (0x01)) \
    || (CAL_SW_PATCH_VERSION != (0x01)) )
# error "Vendor specific version numbers of Cal.c and Cal.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define CAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Requirement Specification Template version */
CONST(uint8, CAL_CONST) Cal_MainVersion    = CAL_SW_MAJOR_VERSION;
CONST(uint8, CAL_CONST) Cal_SubVersion     = CAL_SW_MINOR_VERSION;
CONST(uint8, CAL_CONST) Cal_ReleaseVersion = CAL_SW_PATCH_VERSION;

#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define CAL_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Cal_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief      Writes the version information to the structure referenced by the
 *              parameter 'versioninfo'.
 *  \param[out] versioninfo             reference to the structure to which the
 *                                      version information data should be
 *                                      written to.
 **********************************************************************************************************************/
#if (CAL_VERSION_INFO_API == STD_ON)
FUNC(void, CAL_CODE) Cal_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CAL_APPL_DATA) versioninfo)
{ /* CAL0706 */
  if(versioninfo != NULL_PTR)
  {
    versioninfo->vendorID = CAL_VENDOR_ID;
    versioninfo->moduleID = CAL_MODULE_ID;
    versioninfo->sw_major_version = CAL_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = CAL_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = CAL_SW_PATCH_VERSION;
  }

  return;
}
#endif

#define CAL_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Module specific MISRA deviations
 *********************************************************************************************************************/
/* module specific MISRA deviations:
  MD_CAL_11.4:
    Reason:     This procedure is enforced by the platform design.
    Risk:       None. ContextBuffer is only used internally.
    Prevention: Covered by code review.

  MD_CAL_16.7:
    Reason:     The given pointer shall not be CONST due to AUTOSAR CAL SWS.
    Risk:       None
    Prevention: Covered by code review.

  MD_CAL_8.8:
    Reason:     The configuration of Services is done in the Cal_Cfg.c. For this reason it is necessary to link
                external.
    Risk:       None
    Prevention: Covered by code review.

   MD_CAL_3112:
     Reason:     Dummy statement to avoid compiler warnings.
     Risk:       There is no risk as such statements have no effect on the code.
     Prevention: Covered by code review.

   MD_CAL_3453:
     Reason:     Function-like macro to avoid compiler warnings.
     Risk:       There is no risk as such statements have no effect on the code.
     Prevention: Covered by code review.

*/
/**********************************************************************************************************************
 *  END OF FILE: CAL.C
 *********************************************************************************************************************/

