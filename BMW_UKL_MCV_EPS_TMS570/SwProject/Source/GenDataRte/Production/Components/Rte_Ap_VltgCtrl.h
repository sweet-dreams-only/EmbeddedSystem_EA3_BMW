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
 *          File:  Components/Rte_Ap_VltgCtrl.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Tue Feb  9 10:51:22 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_VLTGCTRL_H
# define _RTE_AP_VLTGCTRL_H

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

#  define Rte_InitValue_CCLMSAActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_CuTempEst_DegC_f32 (0.0F)
#  define Rte_InitValue_EstKe_VpRadpS_f32 (0.0F)
#  define Rte_InitValue_EstLd_Henry_f32 (0.0F)
#  define Rte_InitValue_EstLq_Henry_f32 (0.0F)
#  define Rte_InitValue_EstR_Ohm_f32 (0.0F)
#  define Rte_InitValue_MRFMtrTrqCmdScl_MtrNm_f32 (0.0F)
#  define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_ModIdx_Uls_f32 (0.0F)
#  define Rte_InitValue_MtrEnvSpd_MtrRadpS_f32 (0.0F)
#  define Rte_InitValue_MtrQuad_Cnt_u08 (1U)
#  define Rte_InitValue_PDActivateTest_Cnt_lgc (FALSE)
#  define Rte_InitValue_PDPhsAdvSel_Cnt_s16 (0)
#  define Rte_InitValue_PDTestModIdx_Uls_f32 (0.0F)
#  define Rte_InitValue_PhsAdv_Cnt_s16 (0)
#  define Rte_InitValue_TermA_Volt_f32 (0.0F)
#  define Rte_InitValue_TermBSS_Volt_f32 (0.0F)
#  define Rte_InitValue_TermBTOT_Volt_f32 (0.0F)
#  define Rte_InitValue_TermXd_Uls_f32 (0.0F)
#  define Rte_InitValue_TermXq_Uls_f32 (0.0F)
#  define Rte_InitValue_TermY_Uls_f32 (0.0F)
#  define Rte_InitValue_TermZ_Uls_f32 (1.0F)
#  define Rte_InitValue_UnCorrPhsAdv_Cnt_s16 (0)
#  define Rte_InitValue_VdTerm_Volt_f32 (0.0F)
#  define Rte_InitValue_Vecu_Volt_f32 (5.0F)
#  define Rte_InitValue_VqTerm_Volt_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_10_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2ms_10, RTE_VAR_NOINIT) Rte_Task_2ms_10;

extern VAR(Rte_tsTask_1ms_10, RTE_VAR_NOINIT) Rte_Task_1ms_10;

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

#  define Rte_IRead_VltgCtrl_Per1_EstKe_VpRadpS_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per1.Rte_EstKe_VpRadpS_f32.value)

#  define Rte_IRead_VltgCtrl_Per1_EstR_Ohm_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_ParamComp_EstR_Ohm_f32.value)

#  define Rte_IRead_VltgCtrl_Per1_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32.value)

#  define Rte_IWrite_VltgCtrl_Per1_TermBSS_Volt_f32(data) \
  ( \
    Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per1.Rte_TermBSS_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per1_TermBSS_Volt_f32() \
  (&Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per1.Rte_TermBSS_Volt_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_CuTempEst_DegC_f32() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_CuTempEst_DegC_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_EstKe_VpRadpS_f32() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_EstKe_VpRadpS_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_EstLd_Henry_f32() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_EstLd_Henry_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_EstLq_Henry_f32() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_EstLq_Henry_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_EstR_Ohm_f32() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_EstR_Ohm_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_TrqCmdScl_MRFMtrTrqCmdScl_MtrNm_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_MtrVel_MRFMotorVel_MtrRadpS_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_MtrEnvSpd_MtrRadpS_f32() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_MtrEnvSpd_MtrRadpS_f32.value)

#  define Rte_IRead_VltgCtrl_Per2_MtrQuad_Cnt_u08() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_QuadDet_MtrQuad_Cnt_u08.value)

#  define Rte_IRead_VltgCtrl_Per2_Vecu_Volt_f32() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value)

#  define Rte_IWrite_VltgCtrl_Per2_TermA_Volt_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermA_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per2_TermA_Volt_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermA_Volt_f32.value)

#  define Rte_IWrite_VltgCtrl_Per2_TermBTOT_Volt_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermBTOT_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per2_TermBTOT_Volt_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermBTOT_Volt_f32.value)

#  define Rte_IWrite_VltgCtrl_Per2_TermXd_Uls_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermXd_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per2_TermXd_Uls_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermXd_Uls_f32.value)

#  define Rte_IWrite_VltgCtrl_Per2_TermXq_Uls_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermXq_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per2_TermXq_Uls_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermXq_Uls_f32.value)

#  define Rte_IWrite_VltgCtrl_Per2_TermY_Uls_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermY_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per2_TermY_Uls_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_TermY_Uls_f32.value)

#  define Rte_IWrite_VltgCtrl_Per2_TermZ_Uls_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_TermZ_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per2_TermZ_Uls_f32() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per2.Rte_TermZ_Uls_f32.value)

#  define Rte_IWrite_VltgCtrl_Per2_VdTerm_Volt_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_VdTerm_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per2_VdTerm_Volt_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_VdTerm_Volt_f32.value)

#  define Rte_IWrite_VltgCtrl_Per2_VqTerm_Volt_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_VqTerm_Volt_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per2_VqTerm_Volt_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_VqTerm_Volt_f32.value)

#  define Rte_IRead_VltgCtrl_Per3_CCLMSAActive_Cnt_lgc() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per3.Rte_CCLMSAActive_Cnt_lgc.value)

#  define Rte_IRead_VltgCtrl_Per3_MtrEnvSpd_MtrRadpS_f32() \
  (Rte_Task_2ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per3.Rte_MtrEnvSpd_MtrRadpS_f32.value)

#  define Rte_IRead_VltgCtrl_Per3_Vecu_Volt_f32() \
  (Rte_Task_2ms_10.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value)

#  define Rte_IRead_VltgCtrl_Per4_MtrQuad_Cnt_u08() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_QuadDet_MtrQuad_Cnt_u08.value)

#  define Rte_IRead_VltgCtrl_Per4_PDActivateTest_Cnt_lgc() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_PDActivateTest_Cnt_lgc.value)

#  define Rte_IRead_VltgCtrl_Per4_PDPhsAdvSel_Cnt_s16() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_PDPhsAdvSel_Cnt_s16.value)

#  define Rte_IRead_VltgCtrl_Per4_PDTestModIdx_Uls_f32() \
  (Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_PDTestModIdx_Uls_f32.value)

#  define Rte_IRead_VltgCtrl_Per4_Vecu_Volt_f32() \
  (Rte_Task_1ms_10.Rte_TB.Rte_I_BatteryVoltage_Vecu_Volt_f32.value)

#  define Rte_IWrite_VltgCtrl_Per4_ModIdx_Uls_f32(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_ModIdx_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per4_ModIdx_Uls_f32() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_ModIdx_Uls_f32.value)

#  define Rte_IWrite_VltgCtrl_Per4_PhsAdv_Cnt_s16(data) \
  ( \
    Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_PhsAdv_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per4_PhsAdv_Cnt_s16() \
  (&Rte_Task_1ms_10.Rte_TB.Rte_I_VltgCtrl_PhsAdv_Cnt_s16.value)

#  define Rte_IWrite_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16(data) \
  ( \
    Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_UnCorrPhsAdv_Cnt_s16.value = (data) \
  )

#  define Rte_IWriteRef_VltgCtrl_Per4_UnCorrPhsAdv_Cnt_s16() \
  (&Rte_Task_1ms_10.Rte_RB.Rte_Ap_VltgCtrl_VltgCtrl_Per4.Rte_UnCorrPhsAdv_Cnt_s16.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd_SystemState_Mode


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_VLTGCTRL_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Init1(void);

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per1(void);

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per2(void);

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per3(void);

FUNC(void, RTE_AP_VLTGCTRL_APPL_CODE) VltgCtrl_Per4(void);

# define RTE_STOP_SEC_AP_VLTGCTRL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_VltgCtrl.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_VLTGCTRL_H */
