/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Sa_MtrDrvDiag.h
 *     Workspace:  C:/CMSynergy_Projects/CBD/SVDiag/autosar
 *     SW-C Type:  Sa_MtrDrvDiag
 *  Generated at:  Thu Apr 25 10:47:34 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_MtrDrvDiag> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_MTRDRVDIAG_H
# define _RTE_SA_MTRDRVDIAG_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"

typedef P2CONST(struct Rte_CDS_Sa_MtrDrvDiag, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_FETFaultPhase_Cnt_enum ((FETPHASETYPE_ENUM)0u)
# define Rte_InitValue_FETFaultType_Cnt_enum ((FETFAULTTYPE_ENUM)0u)
# define Rte_InitValue_MtrDrvrInitComplete_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MtrDrvrInitStart_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VswitchClosed_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Sa_MtrDrvDiag_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_FetDrvReset_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_FetFlt1Data_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET(P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput(IoHwAb_BoolType signal);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) CurrentTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32(P2VAR(UInt32, AUTOMATIC, RTE_SA_MTRDRVDIAG_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_MtrDrvDiag_Per1_MtrDrvrInitStart_Cnt_lgc() \
  (Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Per1_MtrDrvrInitStart_Cnt_lgc->value)

# define Rte_IRead_MtrDrvDiag_Per1_VswitchClosed_Cnt_lgc() \
  (Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Per1_VswitchClosed_Cnt_lgc->value)

# define Rte_IWrite_MtrDrvDiag_Per1_FETFaultPhase_Cnt_enum(data) \
  ( \
  Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Per1_FETFaultPhase_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_MtrDrvDiag_Per1_FETFaultPhase_Cnt_enum() \
  (&Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Per1_FETFaultPhase_Cnt_enum->value)

# define Rte_IWrite_MtrDrvDiag_Per1_FETFaultType_Cnt_enum(data) \
  ( \
  Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Per1_FETFaultType_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_MtrDrvDiag_Per1_FETFaultType_Cnt_enum() \
  (&Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Per1_FETFaultType_Cnt_enum->value)

# define Rte_IWrite_MtrDrvDiag_Per1_MtrDrvrInitComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Per1_MtrDrvrInitComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_MtrDrvDiag_Per1_MtrDrvrInitComplete_Cnt_lgc() \
  (&Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Per1_MtrDrvrInitComplete_Cnt_lgc->value)

# define Rte_IWrite_MtrDrvDiag_Trns1_MtrDrvrInitComplete_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Trns1_MtrDrvrInitComplete_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_MtrDrvDiag_Trns1_MtrDrvrInitComplete_Cnt_lgc() \
  (&Rte_Inst_Sa_MtrDrvDiag->MtrDrvDiag_Trns1_MtrDrvrInitComplete_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Sa_MtrDrvDiag_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FetDrvReset_OP_SET Rte_Call_Sa_MtrDrvDiag_FetDrvReset_OP_SET
# define Rte_Call_FetFlt1Data_OP_GET Rte_Call_Sa_MtrDrvDiag_FetFlt1Data_OP_GET
# define Rte_Call_FetFlt2Clk_OP_GET Rte_Call_Sa_MtrDrvDiag_FetFlt2Clk_OP_GET
# define Rte_Call_FetFlt2Clk_OP_SET Rte_Call_Sa_MtrDrvDiag_FetFlt2Clk_OP_SET
# define Rte_Call_IoHwAbPortConfig_SetFetFlt2ToOutput Rte_Call_Sa_MtrDrvDiag_IoHwAbPortConfig_SetFetFlt2ToOutput
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Sa_MtrDrvDiag_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_MtrDrvDiag_NxtrDiagMgr_SetNTCStatus
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16 Rte_Call_Sa_MtrDrvDiag_SystemTime_DtrmnElapsedTime_uS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Sa_MtrDrvDiag_SystemTime_GetSystemTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_uS_u32 Rte_Call_Sa_MtrDrvDiag_SystemTime_GetSystemTime_uS_u32




# define RTE_START_SEC_SA_MTRDRVDIAG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrDrvDiag_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <DISABLE, OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_MtrDrvDiag_Per1_MtrDrvrInitStart_Cnt_lgc(void)
 *   Boolean Rte_IRead_MtrDrvDiag_Per1_VswitchClosed_Cnt_lgc(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrDrvDiag_Per1_FETFaultPhase_Cnt_enum(FETPHASETYPE_ENUM data)
 *   FETPHASETYPE_ENUM *Rte_IWriteRef_MtrDrvDiag_Per1_FETFaultPhase_Cnt_enum(void)
 *   void Rte_IWrite_MtrDrvDiag_Per1_FETFaultType_Cnt_enum(FETFAULTTYPE_ENUM data)
 *   FETFAULTTYPE_ENUM *Rte_IWriteRef_MtrDrvDiag_Per1_FETFaultType_Cnt_enum(void)
 *   void Rte_IWrite_MtrDrvDiag_Per1_MtrDrvrInitComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrDrvDiag_Per1_MtrDrvrInitComplete_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FetDrvReset_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *   Std_ReturnType Rte_Call_FetFlt1Data_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt1Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_FetFlt2Clk_OP_GET(IoHwAb_BoolType *signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt2Clk_E_NOT_OK
 *   Std_ReturnType Rte_Call_FetFlt2Clk_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetFlt2Clk_E_NOT_OK
 *   Std_ReturnType Rte_Call_IoHwAbPortConfig_SetFetFlt2ToOutput(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IoHwAbPortConfig_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_uS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_uS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRDRVDIAG_APPL_CODE) MtrDrvDiag_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrDrvDiag_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OPERATE, WARMINIT>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FetDrvReset_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRDRVDIAG_APPL_CODE) MtrDrvDiag_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrDrvDiag_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <WARMINIT> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrDrvDiag_Trns1_MtrDrvrInitComplete_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrDrvDiag_Trns1_MtrDrvrInitComplete_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FetDrvReset_OP_SET(IoHwAb_BoolType signal)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FetDrvReset_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRDRVDIAG_APPL_CODE) MtrDrvDiag_Trns1(void);

# define RTE_STOP_SEC_SA_MTRDRVDIAG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_FetDrvReset_E_NOT_OK (1u)

# define RTE_E_FetFlt1Data_E_NOT_OK (1u)

# define RTE_E_FetFlt2Clk_E_NOT_OK (1u)

# define RTE_E_IoHwAbPortConfig_E_NOT_OK (1u)

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1366902976
#    error "The magic number of the generated file <C:/CMSynergy_Projects/CBD/SVDiag/utp/contract/Sa_MtrDrvDiag/Rte_Sa_MtrDrvDiag.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1366902976
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRDRVDIAG_H */
