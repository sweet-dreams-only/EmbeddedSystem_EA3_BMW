/*****************************************************************************
* Copyright 2012 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Nhet_Cfg.h
* Module Description: Nhet Complex Driver configuration
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Sat Jul 28 18:03:04 2012
* %version:          2 %
* %derived_by:       xz0btk %
* %date_modified:    Mon Oct  8 14:35:59 2012 %
*---------------------------------------------------------------------------*/


#ifndef NHET_CFG_H
#define NHET_CFG_H

/* Include definitions for Diagnostic Event API */
#include "Ap_DiagMgr.h"

#define NHET_E_MPU_FAILURE			NTC_Num_RAMDiag_HETTU1RamFlt

#define NHET_E_MPU_INFO				0x80U

#define NHET_REPORTERRORSTATUS(event, param, status)		NxtrDiagMgr10_ReportNTCStatus(event, param, status)
#define NHET_EVENT_PASSED				NTC_STATUS_PASSED
#define NHET_EVENT_FAILED				NTC_STATUS_FAILED

#endif
