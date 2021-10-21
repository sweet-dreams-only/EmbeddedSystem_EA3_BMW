

/* DiagMgr Proxy Define */




/* KS- defined NxtrDiagMgr without an application to make it universal to all  programs. */

typedef uint16 NTCNumber;
typedef uint8 UInt8;
typedef uint8 NxtrDiagMgrStatus;

#define NHET_REPORTERRORSTATUS(event, param, status)		NxtrDiagMgr_ReportNTCStatus(event, param, status)
extern FUNC(Std_ReturnType, RTE_AP_DIAGMGR_APPL_CODE) NxtrDiagMgr_ReportNTCStatus( VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum );
