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
 *          File:  Rte_Ap_PrkAstMfgServCh2.h
 *     Workspace:  C:/SynergyWorkArea/CBD_PrkAstMfgServCh2/PrkAstMfgServCh2/autosar
 *     SW-C Type:  Ap_PrkAstMfgServCh2
 *  Generated at:  Mon Feb 24 12:35:45 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_PrkAstMfgServCh2> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PRKASTMFGSERVCH2_H
# define _RTE_AP_PRKASTMFGSERVCH2_H

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

typedef P2CONST(struct Rte_CDS_Ap_PrkAstMfgServCh2, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_LrnPnCntrCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_LrnPnCntrEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PASpdHigh_Cnt_u08 ((ST_V_VEH_NSS)15u)
# define Rte_InitValue_PosServEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PosSrvoSmoothEnable_Uls_f32 ((Float)0)
# define Rte_InitValue_PrkAssistCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_SysCLnPnCtrCCDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SysCPosServCCDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PrkAstMfgServCh2_FaultInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_PRKASTMFGSERVCH2_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_PrkAstMfgServCh2_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_PrkAstMfgServCh2_Per1_LrnPnCntrCmd_MtrNm_f32() \
  (Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_LrnPnCntrCmd_MtrNm_f32->value)

# define Rte_IRead_PrkAstMfgServCh2_Per1_LrnPnCntrEnable_Cnt_lgc() \
  (Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_LrnPnCntrEnable_Cnt_lgc->value)

# define Rte_IRead_PrkAstMfgServCh2_Per1_PASpdHigh_Cnt_u08() \
  (Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_PASpdHigh_Cnt_u08->value)

# define Rte_IRead_PrkAstMfgServCh2_Per1_PosServEnable_Cnt_lgc() \
  (Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_PosServEnable_Cnt_lgc->value)

# define Rte_IRead_PrkAstMfgServCh2_Per1_PosSrvoSmoothEnable_Uls_f32() \
  (Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_PosSrvoSmoothEnable_Uls_f32->value)

# define Rte_IRead_PrkAstMfgServCh2_Per1_PrkAssistCmd_MtrNm_f32() \
  (Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_PrkAssistCmd_MtrNm_f32->value)

# define Rte_IRead_PrkAstMfgServCh2_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_PrkAstMfgServCh2_Per1_SysCLnPnCtrCCDisable_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_SysCLnPnCtrCCDisable_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PrkAstMfgServCh2_Per1_SysCLnPnCtrCCDisable_Cnt_lgc() \
  (&Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_SysCLnPnCtrCCDisable_Cnt_lgc->value)

# define Rte_IWrite_PrkAstMfgServCh2_Per1_SysCPosServCCDisable_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_SysCPosServCCDisable_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_PrkAstMfgServCh2_Per1_SysCPosServCCDisable_Cnt_lgc() \
  (&Rte_Inst_Ap_PrkAstMfgServCh2->PrkAstMfgServCh2_Per1_SysCPosServCCDisable_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FaultInjection_SCom_FltInjection Rte_Call_Ap_PrkAstMfgServCh2_FaultInjection_SCom_FltInjection
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_PrkAstMfgServCh2_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_PRKASTMFGSERVCH2_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: PrkAstMfgServCh2_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PRKASTMFGSERVCH2_APPL_CODE) PrkAstMfgServCh2_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PrkAstMfgServCh2_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_PrkAstMfgServCh2_Per1_LrnPnCntrCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_PrkAstMfgServCh2_Per1_LrnPnCntrEnable_Cnt_lgc(void)
 *   ST_V_VEH_NSS Rte_IRead_PrkAstMfgServCh2_Per1_PASpdHigh_Cnt_u08(void)
 *   Boolean Rte_IRead_PrkAstMfgServCh2_Per1_PosServEnable_Cnt_lgc(void)
 *   Float Rte_IRead_PrkAstMfgServCh2_Per1_PosSrvoSmoothEnable_Uls_f32(void)
 *   Float Rte_IRead_PrkAstMfgServCh2_Per1_PrkAssistCmd_MtrNm_f32(void)
 *   Float Rte_IRead_PrkAstMfgServCh2_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_PrkAstMfgServCh2_Per1_SysCLnPnCtrCCDisable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PrkAstMfgServCh2_Per1_SysCLnPnCtrCCDisable_Cnt_lgc(void)
 *   void Rte_IWrite_PrkAstMfgServCh2_Per1_SysCPosServCCDisable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_PrkAstMfgServCh2_Per1_SysCPosServCCDisable_Cnt_lgc(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PRKASTMFGSERVCH2_APPL_CODE) PrkAstMfgServCh2_Per1(void);

# define RTE_STOP_SEC_AP_PRKASTMFGSERVCH2_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1393270008
#    error "The magic number of the generated file <C:/SynergyWorkArea/CBD_PrkAstMfgServCh2/PrkAstMfgServCh2/utp/contract/Ap_PrkAstMfgServCh2/Rte_Ap_PrkAstMfgServCh2.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1393270008
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PRKASTMFGSERVCH2_H */
