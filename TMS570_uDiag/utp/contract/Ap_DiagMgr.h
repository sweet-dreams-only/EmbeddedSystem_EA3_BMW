/**********************************************************************
*
*	Header %name:	Ap_DiagMgr.h %
*	Instance:		sag_EPS_20
*	Description:	
*	%created_by:	xz0btk %
*	%date_created:	Wed Jul  4 14:22:18 2012 %
*
**********************************************************************/
#ifndef AP_DIAGMGR_H
#define AP_DIAGMGR_H

#include "Std_Types.h" 
#include "Rte_Type.h"

FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr_ReportNTCStatus(NTCNumber NTC, UInt8 Param, NxtrDiagMgrStatus Status);

#endif

