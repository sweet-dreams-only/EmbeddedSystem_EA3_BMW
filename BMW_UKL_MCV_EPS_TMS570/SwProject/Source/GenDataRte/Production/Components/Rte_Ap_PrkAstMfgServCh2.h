/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Components/Rte_Ap_PrkAstMfgServCh2.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:21 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_PRKASTMFGSERVCH2_H
# define _RTE_AP_PRKASTMFGSERVCH2_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_LrnPnCntrCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_LrnPnCntrEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PASpdHigh_Cnt_u08 (15U)
#  define Rte_InitValue_PosServEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_PosSrvoSmoothEnable_Uls_f32 (0.0F)
#  define Rte_InitValue_PrkAssistCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_SysCLnPnCtrCCDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_SysCPosServCCDisable_Cnt_lgc (FALSE)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_4ms_8, RTE_VAR_NOINIT) Rte_Task_4ms_8;

#  define RTE_STOP_SEC_VAR_Ap_8_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_STOP_SEC_CODE
# include "MemMap.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_PrkAstMfgServCh2_Per1_LrnPnCntrCmd_MtrNm_f32() \
  (Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_LrnPnCntrCmd_MtrNm_f32.value)

#  define Rte_IRead_PrkAstMfgServCh2_Per1_LrnPnCntrEnable_Cnt_lgc() \
  (Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_LrnPnCntrEnable_Cnt_lgc.value)

#  define Rte_IRead_PrkAstMfgServCh2_Per1_PASpdHigh_Cnt_u08() \
  (Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_PASpdHigh_Cnt_u08.value)

#  define Rte_IRead_PrkAstMfgServCh2_Per1_PosServEnable_Cnt_lgc() \
  (Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_PosServEnable_Cnt_lgc.value)

#  define Rte_IRead_PrkAstMfgServCh2_Per1_PosSrvoSmoothEnable_Uls_f32() \
  (Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_PosSrvoSmoothEnable_Uls_f32.value)

#  define Rte_IRead_PrkAstMfgServCh2_Per1_PrkAssistCmd_MtrNm_f32() \
  (Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_PrkAssistCmd_MtrNm_f32.value)

#  define Rte_IRead_PrkAstMfgServCh2_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_PrkAstMfgServCh2_Per1_SysCLnPnCtrCCDisable_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_SysCLnPnCtrCCDisable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PrkAstMfgServCh2_Per1_SysCLnPnCtrCCDisable_Cnt_lgc() \
  (&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_SysCLnPnCtrCCDisable_Cnt_lgc.value)

#  define Rte_IWrite_PrkAstMfgServCh2_Per1_SysCPosServCCDisable_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_SysCPosServCCDisable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_PrkAstMfgServCh2_Per1_SysCPosServCCDisable_Cnt_lgc() \
  (&Rte_Task_4ms_8.Rte_RB.Rte_Ap_PrkAstMfgServCh2_PrkAstMfgServCh2_Per1.Rte_SysCPosServCCDisable_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_FLTINJECTION_APPL_CODE) FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_FLTINJECTION_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
#  define RTE_STOP_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_FaultInjection_SCom_FltInjection(arg1, arg2) (FltInjection_SCom_FltInjection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_AP_DIAGMGR8_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR8_APPL_CODE) NxtrDiagMgr8_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR8_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr8_SetNTCStatus


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_PRKASTMFGSERVCH2_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PRKASTMFGSERVCH2_APPL_CODE) PrkAstMfgServCh2_Init(void);

FUNC(void, RTE_AP_PRKASTMFGSERVCH2_APPL_CODE) PrkAstMfgServCh2_Per1(void);

# define RTE_STOP_SEC_AP_PRKASTMFGSERVCH2_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_PrkAstMfgServCh2.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PRKASTMFGSERVCH2_H */
