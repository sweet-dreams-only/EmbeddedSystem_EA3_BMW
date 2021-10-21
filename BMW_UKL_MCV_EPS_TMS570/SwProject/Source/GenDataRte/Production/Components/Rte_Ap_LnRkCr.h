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
 *          File:  Components/Rte_Ap_LnRkCr.h
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
#ifndef _RTE_AP_LNRKCR_H
# define _RTE_AP_LNRKCR_H

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

#  define Rte_InitValue_AlignedHwPos_HwDeg_f32 (0.0F)
#  define Rte_InitValue_CRFMtrTrqCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_LTRackCntrComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_LrnPnCntrEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_LrnPnCntrHwCenter_HwDeg_f32 (0.0F)
#  define Rte_InitValue_LrnPnCntrHwTravel_HwDeg_f32 (0.0F)
#  define Rte_InitValue_LrnPnCntrState_Cnt_enum (0U)
#  define Rte_InitValue_MtrVelCRF_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_RackCenter_HwDeg_f32 (0.0F)
#  define Rte_InitValue_RackCntrComplete_Cnt_lgc (FALSE)
#  define Rte_InitValue_RackCntrMtrAngleError_Cnt_lgc (FALSE)
#  define Rte_InitValue_RackCntrMtrAngleFound_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitB_9, RTE_VAR_NOINIT) Rte_Task_InitB_9;

extern VAR(Rte_tsTask_4ms_9, RTE_VAR_NOINIT) Rte_Task_4ms_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#  define Rte_IRead_LnRkCr_Init1_AlignedHwPos_HwDeg_f32() \
  (Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_AlignedHwPos_HwDeg_f32.value)

#  define Rte_IWrite_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_LTRackCntrComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Init1_LTRackCntrComplete_Cnt_lgc() \
  (&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_LTRackCntrComplete_Cnt_lgc.value)

#  define Rte_IWrite_LnRkCr_Init1_RackCenter_HwDeg_f32(data) \
  ( \
    Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCenter_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Init1_RackCenter_HwDeg_f32() \
  (&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCenter_HwDeg_f32.value)

#  define Rte_IWrite_LnRkCr_Init1_RackCntrComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Init1_RackCntrComplete_Cnt_lgc() \
  (&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrComplete_Cnt_lgc.value)

#  define Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc(data) \
  ( \
    Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrMtrAngleError_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Init1_RackCntrMtrAngleError_Cnt_lgc() \
  (&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrMtrAngleError_Cnt_lgc.value)

#  define Rte_IWrite_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc(data) \
  ( \
    Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrMtrAngleFound_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Init1_RackCntrMtrAngleFound_Cnt_lgc() \
  (&Rte_Task_InitB_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Init1.Rte_RackCntrMtrAngleFound_Cnt_lgc.value)

#  define Rte_IRead_LnRkCr_Per1_AlignedHwPos_HwDeg_f32() \
  (Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_AlignedHwPos_HwDeg_f32.value)

#  define Rte_IRead_LnRkCr_Per1_CRFMtrTrqCmd_MtrNm_f32() \
  (Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_CRFMtrTrqCmd_MtrNm_f32.value)

#  define Rte_IRead_LnRkCr_Per1_LrnPnCntrEnable_Cnt_lgc() \
  (Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LrnPnCntrEnable_Cnt_lgc.value)

#  define Rte_IRead_LnRkCr_Per1_LrnPnCntrHwCenter_HwDeg_f32() \
  (Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LrnPnCntrHwCenter_HwDeg_f32.value)

#  define Rte_IRead_LnRkCr_Per1_LrnPnCntrHwTravel_HwDeg_f32() \
  (Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LrnPnCntrHwTravel_HwDeg_f32.value)

#  define Rte_IRead_LnRkCr_Per1_LrnPnCntrState_Cnt_enum() \
  (Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LrnPnCntrState_Cnt_enum.value)

#  define Rte_IRead_LnRkCr_Per1_MtrVelCRF_MtrRadpS_f32() \
  (Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_MtrVelCRF_MtrRadpS_f32.value)

#  define Rte_IWrite_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LTRackCntrComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Per1_LTRackCntrComplete_Cnt_lgc() \
  (&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_LTRackCntrComplete_Cnt_lgc.value)

#  define Rte_IWrite_LnRkCr_Per1_RackCenter_HwDeg_f32(data) \
  ( \
    Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCenter_HwDeg_f32.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Per1_RackCenter_HwDeg_f32() \
  (&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCenter_HwDeg_f32.value)

#  define Rte_IWrite_LnRkCr_Per1_RackCntrComplete_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrComplete_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Per1_RackCntrComplete_Cnt_lgc() \
  (&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrComplete_Cnt_lgc.value)

#  define Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrMtrAngleError_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Per1_RackCntrMtrAngleError_Cnt_lgc() \
  (&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrMtrAngleError_Cnt_lgc.value)

#  define Rte_IWrite_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc(data) \
  ( \
    Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrMtrAngleFound_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_LnRkCr_Per1_RackCntrMtrAngleFound_Cnt_lgc() \
  (&Rte_Task_4ms_9.Rte_RB.Rte_Ap_LnRkCr_LnRkCr_Per1.Rte_RackCntrMtrAngleFound_Cnt_lgc.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NTWRAP_APPL_CODE) Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(Float RackCntr_HwDeg_P_f32, Boolean LTRckCntrComplete_Cnt_P_lgc);
#  define RTE_STOP_SEC_NTWRAP_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(arg1, arg2) (Call_AbsHwPos_SetData_SetRacktoVehCntrOffset(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, Boolean RamBlockStatus);
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_LearnedRackCntrData_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)33, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_LearnedRackCntrData_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)33, arg1))
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) NTCFailed_Ptr_T_lgc);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCFailed NxtrDiagMgr9_GetNTCFailed
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) ElapsedTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(arg1, arg2) (DtrmnElapsedTime_mS_u16(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NXTRLIBS_APPL_CODE) GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_NXTRLIBS_APPL_VAR) CurrentTime);
#  define RTE_STOP_SEC_NXTRLIBS_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_SystemTime_GetSystemTime_mS_u32(arg1) (GetSystemTime_mS_u32(arg1), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(RackCenterType, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_LnRkCr_LearnedRackCntr;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_LearnedRackCntr() \
  (&Rte_LnRkCr_LearnedRackCntr)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_LNRKCR_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Init1(void);

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Per1(void);

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrDeg(void);

FUNC(void, RTE_AP_LNRKCR_APPL_CODE) LnRkCr_Scom_ResetRckCntrMtrRev(void);

# define RTE_STOP_SEC_AP_LNRKCR_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_LnRkCr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_LNRKCR_H */
