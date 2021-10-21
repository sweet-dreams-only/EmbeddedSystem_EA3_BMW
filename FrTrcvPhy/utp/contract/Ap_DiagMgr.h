/*****************************************************************************
* Copyright 2011 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_DiagMgr.h
* Module Description: This file contains a stub header for UTP and QAC 
*                     projects
* Product           : Gen II Plus EA3.0
* Author            : Jared Julien
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Oct 26 16:48:22 2003
* %version:          2 %
* %derived_by:       cz7lt6 %
* %date_modified:    Thu Jan 24 10:15:26 2013 %
*---------------------------------------------------------------------------*/
#ifndef AP_DIAGMGR_H
#define AP_DIAGMGR_H

/* KS - Added for QAC checks to pass */
#include "Rte_Type.h"
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr9_ReportNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum );

#endif  /* AP_DIAGMGR_H */
