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
 *          File:  Components/Rte_Ap_Polarity.h
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
#ifndef _RTE_AP_POLARITY_H
# define _RTE_AP_POLARITY_H

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

#  define RTE_START_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_AssistAssyPolarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_HwPosPolarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_HwTrqPolarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_MtrElecMechPolarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_MtrPosPolarity_Cnt_s08;
extern VAR(SInt8, RTE_VAR_INIT) Rte_Polarity_MtrVelPolarity_Cnt_s08;
extern VAR(SInt32, RTE_VAR_INIT) Rte_Polarity_SysC_MtrElecMechPolarity_Cnt_s32;

#  define RTE_STOP_SEC_VAR_Ap_10_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_AssistAssyPolarity_Cnt_s08 (0)
#  define Rte_InitValue_HwPosPolarity_Cnt_s08 (0)
#  define Rte_InitValue_HwTrqPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MtrPosPolarity_Cnt_s08 (0)
#  define Rte_InitValue_MtrVelPolarity_Cnt_s08 (0)
#  define Rte_InitValue_SysC_MtrElecMechPolarity_Cnt_s32 (0)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitA_10, RTE_VAR_NOINIT) Rte_Task_InitA_10;

#  define RTE_STOP_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
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

#  define Rte_IWrite_Polarity_Init1_AssistAssyPolarity_Cnt_s08(data) \
  ( \
    Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_AssistAssyPolarity_Cnt_s08.value = (data) \
  )

#  define Rte_IWriteRef_Polarity_Init1_AssistAssyPolarity_Cnt_s08() \
  (&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_AssistAssyPolarity_Cnt_s08.value)

#  define Rte_IWrite_Polarity_Init1_HwPosPolarity_Cnt_s08(data) \
  ( \
    Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_HwPosPolarity_Cnt_s08.value = (data) \
  )

#  define Rte_IWriteRef_Polarity_Init1_HwPosPolarity_Cnt_s08() \
  (&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_HwPosPolarity_Cnt_s08.value)

#  define Rte_IWrite_Polarity_Init1_HwTrqPolarity_Cnt_s08(data) \
  ( \
    Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_HwTrqPolarity_Cnt_s08.value = (data) \
  )

#  define Rte_IWriteRef_Polarity_Init1_HwTrqPolarity_Cnt_s08() \
  (&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_HwTrqPolarity_Cnt_s08.value)

#  define Rte_IWrite_Polarity_Init1_MtrElecMechPolarity_Cnt_s08(data) \
  ( \
    Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrElecMechPolarity_Cnt_s08.value = (data) \
  )

#  define Rte_IWriteRef_Polarity_Init1_MtrElecMechPolarity_Cnt_s08() \
  (&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrElecMechPolarity_Cnt_s08.value)

#  define Rte_IWrite_Polarity_Init1_MtrPosPolarity_Cnt_s08(data) \
  ( \
    Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrPosPolarity_Cnt_s08.value = (data) \
  )

#  define Rte_IWriteRef_Polarity_Init1_MtrPosPolarity_Cnt_s08() \
  (&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrPosPolarity_Cnt_s08.value)

#  define Rte_IWrite_Polarity_Init1_MtrVelPolarity_Cnt_s08(data) \
  ( \
    Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrVelPolarity_Cnt_s08.value = (data) \
  )

#  define Rte_IWriteRef_Polarity_Init1_MtrVelPolarity_Cnt_s08() \
  (&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_MtrVelPolarity_Cnt_s08.value)

#  define Rte_IWrite_Polarity_Init1_SysC_MtrElecMechPolarity_Cnt_s32(data) \
  ( \
    Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_SysC_MtrElecMechPolarity_Cnt_s32.value = (data) \
  )

#  define Rte_IWriteRef_Polarity_Init1_SysC_MtrElecMechPolarity_Cnt_s32() \
  (&Rte_Task_InitA_10.Rte_RB.Rte_Ap_Polarity_Polarity_Init1.Rte_SysC_MtrElecMechPolarity_Cnt_s32.value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_AssistAssyPolarity_Cnt_s08 Rte_Write_Ap_Polarity_AssistAssyPolarity_Cnt_s08
#  define Rte_Write_Ap_Polarity_AssistAssyPolarity_Cnt_s08(data) (Rte_Polarity_AssistAssyPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwPosPolarity_Cnt_s08 Rte_Write_Ap_Polarity_HwPosPolarity_Cnt_s08
#  define Rte_Write_Ap_Polarity_HwPosPolarity_Cnt_s08(data) (Rte_Polarity_HwPosPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_HwTrqPolarity_Cnt_s08 Rte_Write_Ap_Polarity_HwTrqPolarity_Cnt_s08
#  define Rte_Write_Ap_Polarity_HwTrqPolarity_Cnt_s08(data) (Rte_Polarity_HwTrqPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MtrElecMechPolarity_Cnt_s08 Rte_Write_Ap_Polarity_MtrElecMechPolarity_Cnt_s08
#  define Rte_Write_Ap_Polarity_MtrElecMechPolarity_Cnt_s08(data) (Rte_Polarity_MtrElecMechPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MtrPosPolarity_Cnt_s08 Rte_Write_Ap_Polarity_MtrPosPolarity_Cnt_s08
#  define Rte_Write_Ap_Polarity_MtrPosPolarity_Cnt_s08(data) (Rte_Polarity_MtrPosPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_MtrVelPolarity_Cnt_s08 Rte_Write_Ap_Polarity_MtrVelPolarity_Cnt_s08
#  define Rte_Write_Ap_Polarity_MtrVelPolarity_Cnt_s08(data) (Rte_Polarity_MtrVelPolarity_Cnt_s08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_SysC_MtrElecMechPolarity_Cnt_s32 Rte_Write_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32
#  define Rte_Write_Ap_Polarity_SysC_MtrElecMechPolarity_Cnt_s32(data) (Rte_Polarity_SysC_MtrElecMechPolarity_Cnt_s32 = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_NVMPROXY_APPL_CODE) NvMProxy_GetErrorStatus(UInt8 parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMPROXY_APPL_VAR) ErrorStatus);
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CtrlPolEOL_GetErrorStatus(arg1) (NvMProxy_GetErrorStatus((UInt8)9, arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_CtrlPolEOL_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)9, arg1))
#  define RTE_START_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR10_APPL_CODE) NxtrDiagMgr10_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR10_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr10_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(UInt16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Polarity_k_SystemPolarity_Cnt_b16;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_k_SystemPolarity_Cnt_b16() \
  (&Rte_Polarity_k_SystemPolarity_Cnt_b16)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_POLARITY_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_Init1(void);

FUNC(void, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_ReadPolarity(P2VAR(UInt16, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Cnt_b16);

FUNC(Std_ReturnType, RTE_AP_POLARITY_APPL_CODE) Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16);

# define RTE_STOP_SEC_AP_POLARITY_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

#  define RTE_E_Polarity_SCom_RequestOutOfRange (49U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_Polarity.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_POLARITY_H */
