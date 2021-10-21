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
 *          File:  Components/Rte_Ap_ParamComp.h
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
#ifndef _RTE_AP_PARAMCOMP_H
# define _RTE_AP_PARAMCOMP_H

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

#  define Rte_InitValue_CuTempEst_DegC_f32 (0.0F)
#  define Rte_InitValue_EstKe_VpRadpS_f32 (0.0F)
#  define Rte_InitValue_EstLd_Henry_f32 (0.0F)
#  define Rte_InitValue_EstLq_Henry_f32 (0.0F)
#  define Rte_InitValue_EstR_Ohm_f32 (0.0F)
#  define Rte_InitValue_ExpIq_Amp_f32 (0.0F)
#  define Rte_InitValue_IdEst_Amp_f32 (0.0F)
#  define Rte_InitValue_MRFMtrTrqCmdScl_MtrNm_f32 (0.0F)
#  define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_MagTempEst_DegC_f32 (0.0F)
#  define Rte_InitValue_MtrCurrQax_Amp_f32 (0.0F)
#  define Rte_InitValue_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc (FALSE)
#  define Rte_InitValue_MtrQuad_Cnt_u08 (1U)
#  define Rte_InitValue_SiTempEst_DegC_f32 (0.0F)
#  define Rte_InitValue_ValidCurrSample_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitB_10, RTE_VAR_NOINIT) Rte_Task_InitB_10;

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

extern VAR(Rte_tsTask_100ms_10, RTE_VAR_NOINIT) Rte_Task_100ms_10;

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

#  define Rte_IWrite_ParamComp_Init1_EstKe_VpRadpS_f32(data) \
  ( \
    Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstKe_VpRadpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Init1_EstKe_VpRadpS_f32() \
  (&Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstKe_VpRadpS_f32.value)

#  define Rte_IWrite_ParamComp_Init1_EstLd_Henry_f32(data) \
  ( \
    Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstLd_Henry_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Init1_EstLd_Henry_f32() \
  (&Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstLd_Henry_f32.value)

#  define Rte_IWrite_ParamComp_Init1_EstLq_Henry_f32(data) \
  ( \
    Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstLq_Henry_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Init1_EstLq_Henry_f32() \
  (&Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstLq_Henry_f32.value)

#  define Rte_IWrite_ParamComp_Init1_EstR_Ohm_f32(data) \
  ( \
    Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstR_Ohm_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Init1_EstR_Ohm_f32() \
  (&Rte_Task_InitB_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Init1.Rte_EstR_Ohm_f32.value)

#  define Rte_IRead_ParamComp_Per1_IdEst_Amp_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_CurrentEst_IdEst_Amp_f32.value)

#  define Rte_IRead_ParamComp_Per1_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32.value)

#  define Rte_IRead_ParamComp_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value)

#  define Rte_IRead_ParamComp_Per1_MtrCurrQax_Amp_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_MtrCurrQax_Amp_f32.value)

#  define Rte_IRead_ParamComp_Per1_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_MtrParmNrmLrnSrlComSvcDft_Cnt_lgc.value)

#  define Rte_IRead_ParamComp_Per1_MtrQuad_Cnt_u08() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_QuadDet_MtrQuad_Cnt_u08.value)

#  define Rte_IRead_ParamComp_Per1_ValidCurrSample_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_ValidCurrSample_Cnt_lgc.value)

#  define Rte_IWrite_ParamComp_Per1_EstKe_VpRadpS_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstKe_VpRadpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Per1_EstKe_VpRadpS_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstKe_VpRadpS_f32.value)

#  define Rte_IWrite_ParamComp_Per1_EstLd_Henry_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstLd_Henry_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Per1_EstLd_Henry_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstLd_Henry_f32.value)

#  define Rte_IWrite_ParamComp_Per1_EstLq_Henry_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstLq_Henry_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Per1_EstLq_Henry_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstLq_Henry_f32.value)

#  define Rte_IWrite_ParamComp_Per1_EstR_Ohm_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstR_Ohm_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Per1_EstR_Ohm_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_EstR_Ohm_f32.value)

#  define Rte_IWrite_ParamComp_Per1_ExpIq_Amp_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_ExpIq_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_ParamComp_Per1_ExpIq_Amp_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per1.Rte_ExpIq_Amp_f32.value)

#  define Rte_IRead_ParamComp_Per2_CuTempEst_DegC_f32() \
  (Rte_Task_100ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per2.Rte_CuTempEst_DegC_f32.value)

#  define Rte_IRead_ParamComp_Per2_MagTempEst_DegC_f32() \
  (Rte_Task_100ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per2.Rte_MagTempEst_DegC_f32.value)

#  define Rte_IRead_ParamComp_Per2_SiTempEst_DegC_f32() \
  (Rte_Task_100ms_10.Rte_RB.Rte_Ap_ParamComp_ParamComp_Per2.Rte_SiTempEst_DegC_f32.value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVMPROXY_APPL_CODE) NvMProxy_WriteBlock(UInt8 parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVMPROXY_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVMPROXY_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_EOLNomMtrParamBlk_WriteBlock(arg1) (NvMProxy_WriteBlock((UInt8)6, arg1))


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(EOLNomMtrParamType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_ParamComp_EOLNomMtrParam;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_EOLNomMtrParam() \
  (&Rte_ParamComp_EOLNomMtrParam)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_PARAMCOMP_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Init1(void);

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Per1(void);

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) ParamComp_Per2(void);

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomLq_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomLq_Henry_f32, Float NomRmtr_Ohm_f32);

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) KeIntgSV_Amp_f32);

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32);

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) RIntgSV_Amp_f32);

FUNC(void, RTE_AP_PARAMCOMP_APPL_CODE) SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32);

# define RTE_STOP_SEC_AP_PARAMCOMP_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_ParamComp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_PARAMCOMP_H */
