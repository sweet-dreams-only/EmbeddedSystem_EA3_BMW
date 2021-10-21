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
 *          File:  Components/Rte_Ap_BmwRtnArbn.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu Feb 25 17:38:10 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_BMWRTNARBN_H
# define _RTE_AP_BMWRTNARBN_H

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

#  define Rte_InitValue_BasicRtnCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_DefeatReturnSvc_Cnt_lgc (FALSE)
#  define Rte_InitValue_DiagStsHwPosDis_Cnt_lgc (FALSE)
#  define Rte_InitValue_EnableCVR_Cnt_lgc (FALSE)
#  define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
#  define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
#  define Rte_InitValue_HandwheelVelocity_HwRadpS_f32 (0.0F)
#  define Rte_InitValue_HwTorque_HwNm_f32 (0.0F)
#  define Rte_InitValue_MRFMtrTrqCmdScl_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PAReturnSclFct_Uls_f32 (1.0F)
#  define Rte_InitValue_ReturnCmd_MtrNm_f32 (0.0F)
#  define Rte_InitValue_ReturnDDFactor_Uls_f32 (1.0F)
#  define Rte_InitValue_ReturnOffset_HwDeg_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_2msA_9, RTE_VAR_NOINIT) Rte_Task_2msA_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#  define Rte_IRead_BmwRtnArbn_Per1_BasicRtnCmd_MtrNm_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_Return_ReturnCmd_MtrNm_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_DefeatReturnSvc_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_DefeatReturnSvc_Cnt_lgc.value)

#  define Rte_IRead_BmwRtnArbn_Per1_DiagStsHwPosDis_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_DiagMgr10_DiagStsHWASbSystmFltPres_Cnt_lgc.value)

#  define Rte_IRead_BmwRtnArbn_Per1_EnableCVR_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_EnableCVR_Cnt_lgc.value)

#  define Rte_IRead_BmwRtnArbn_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_AbsHwPos_HandwheelAuthority_Uls_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_AbsHwPos_HandwheelPosition_HwDeg_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_HandwheelVelocity_HwRadpS_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_MtrVel_HandwheelVel_HwRadpS_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_HwTorque_HwNm_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_Sweep_OutputHwTrq_HwNm_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_MRFMtrTrqCmdScl_MtrNm_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_PAReturnSclFct_Uls_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_PosServo_PosSrvoReturnSclFct_Uls_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_ReturnDDFactor_Uls_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_DrvDynCtrl_ReturnDDFactor_Uls_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_ReturnOffset_HwDeg_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_SrlComInput_ReturnOffset_HwDeg_f32.value)

#  define Rte_IRead_BmwRtnArbn_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2msA_9.Rte_TB.Rte_I_SignlCondn_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_ReturnCmd_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_BmwRtnArbn_Per1_ReturnCmd_MtrNm_f32() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwRtnArbn_BmwRtnArbn_Per1.Rte_ReturnCmd_MtrNm_f32.value)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_BMWRTNARBN_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWRTNARBN_APPL_CODE) BmwRtnArbn_Init1(void);

FUNC(void, RTE_AP_BMWRTNARBN_APPL_CODE) BmwRtnArbn_Per1(void);

# define RTE_STOP_SEC_AP_BMWRTNARBN_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_BmwRtnArbn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_BMWRTNARBN_H */
