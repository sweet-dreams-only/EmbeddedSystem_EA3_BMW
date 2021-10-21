/** \brief BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** BMW-FrTp Version Information implementation.
 **
 ** \file    FrTp_VersionInfo.c
 ** \project BMW FrTp
 **
 ** \controller independent
 ** \compiler   independent
 ** \hardware   independent
 **
 ** \author  Wolfgang Huber
 ** Copyright 2002-2008 Elektrobit Austria GmbH, http://www.elektrobit.com/
 ** All rights reserved.
 ** This software is the confidential and proprietary information
 ** of Elektrobit ("Confidential Information").
 *
 ** You shall not disclose such Confidential Information
 ** and shall use it only in accordance with the terms and
 ** conditions of the License Agreement you entered into with
 ** Elektrobit.

 ** \addtogroup FrTp FlexRay Transport Protocol
 ** @{ */

/* ----------------------------------------------------------------------------
 Include Section
 ---------------------------------------------------------------------------- */

#include "FrTp_Priv.h"      /* get FrTp private data                         */

/* ----------------------------------------------------------------------------
 Local Macros
 ---------------------------------------------------------------------------- */
/**
 * software version check
 */
#if !FRTP_SW_VERSION_CHECK(1,2,6)
#error Software version number mismatch
#endif
/* ----------------------------------------------------------------------------
 Global Data
 ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
 Global Functions
 ---------------------------------------------------------------------------- */

/* start code section declaration */
#define FRTP_START_SEC_CODE
#include "MemMap.h"

#if (FRTP_VERSION_INFO_API == STD_ON)
FUNC(void,FRTP_CODE) FrTp_GetVersionInfo(
    P2VAR(Std_VersionInfoType,AUTOMATIC,FRTP_APPL_DATA) versioninfo
)
{
#if (FRTP_DEV_ERROR_DETECT == STD_ON)
  if (versioninfo == NULL_PTR)
  {
    FrTp_Det_ReportError(
        FRTP_DET_GENERIC_INSTANCE_ID,
        FRTP_GETVERSIONINFO_SERVICE_ID,
        FRTP_E_NULL_PTR
    );
  }
  else
#endif
  {
    /* return versio info values */
    versioninfo->vendorID = FRTP_VENDOR_ID;
    versioninfo->moduleID = FRTP_MODULE_ID;
    versioninfo->sw_major_version = FRTP_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = FRTP_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = FRTP_SW_PATCH_VERSION;
  }
}

#endif

/* stop code section declaration */
#define FRTP_STOP_SEC_CODE
#include "MemMap.h"

/** @} doxygen end group definition */
