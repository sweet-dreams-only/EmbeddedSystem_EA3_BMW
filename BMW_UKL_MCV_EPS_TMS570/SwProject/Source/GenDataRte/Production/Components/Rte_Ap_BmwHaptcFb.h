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
 *          File:  Components/Rte_Ap_BmwHaptcFb.h
 *     Workspace:  C:/Build/BMW/F40_Latest/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Mon Aug  8 21:20:14 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_BMWHAPTCFB_H
# define _RTE_AP_BMWHAPTCFB_H

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

#  define Rte_InitValue_HaptcFbEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaptcFbIntenNr_Cnt_u16 (0U)
#  define Rte_InitValue_HaptcFbIntenSigVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaptcFbPatNr_Cnt_u16 (0U)
#  define Rte_InitValue_HaptcFbPatSigVld_Cnt_lgc (FALSE)
#  define Rte_InitValue_HaptcFbSt_Cnt_u08 (1U)
#  define Rte_InitValue_PostLimitTrq_MtrNm_f32 (0.0F)
#  define Rte_InitValue_PreLimitTrq_MtrNm_f32 (0.0F)
#  define Rte_InitValue_TrqOscActv_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqOscAmp_MtrNm_f32 (0.0F)
#  define Rte_InitValue_TrqOscDCExceeded_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqOscEnable_Cnt_lgc (FALSE)
#  define Rte_InitValue_TrqOscFallingRampRate_MtrNmpS_f32 (-4400.0F)
#  define Rte_InitValue_TrqOscFreq_Hz_f32 (50.0F)
#  define Rte_InitValue_TrqOscRisngRampRate_MtrNmpS_f32 (4400.0F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
#  define Rte_InitValue_VehicleSpeedValid_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd9_SystemState9_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



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

#  define Rte_IRead_BmwHaptcFb_Per1_HaptcFbEnable_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbEnable_Cnt_lgc.value)

#  define Rte_IRead_BmwHaptcFb_Per1_HaptcFbIntenNr_Cnt_u16() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbIntenNr_Cnt_u16.value)

#  define Rte_IRead_BmwHaptcFb_Per1_HaptcFbIntenSigVld_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbIntenSigVld_Cnt_lgc.value)

#  define Rte_IRead_BmwHaptcFb_Per1_HaptcFbPatNr_Cnt_u16() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbPatNr_Cnt_u16.value)

#  define Rte_IRead_BmwHaptcFb_Per1_HaptcFbPatSigVld_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbPatSigVld_Cnt_lgc.value)

#  define Rte_IRead_BmwHaptcFb_Per1_PostLimitTrq_MtrNm_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_PostLimitTrq_MtrNm_f32.value)

#  define Rte_IRead_BmwHaptcFb_Per1_PreLimitTrq_MtrNm_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_PreLimitTrq_MtrNm_f32.value)

#  define Rte_IRead_BmwHaptcFb_Per1_TrqOscActv_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscActv_Cnt_lgc.value)

#  define Rte_IRead_BmwHaptcFb_Per1_TrqOscDCExceeded_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscDCExceeded_Cnt_lgc.value)

#  define Rte_IRead_BmwHaptcFb_Per1_VehicleSpeedValid_Cnt_lgc() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_VehicleSpeedValid_Cnt_lgc.value)

#  define Rte_IRead_BmwHaptcFb_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_BmwHaptcFb_Per1_HaptcFbSt_Cnt_u08(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbSt_Cnt_u08.value = (data) \
  )

#  define Rte_IWriteRef_BmwHaptcFb_Per1_HaptcFbSt_Cnt_u08() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_HaptcFbSt_Cnt_u08.value)

#  define Rte_IWrite_BmwHaptcFb_Per1_TrqOscAmp_MtrNm_f32(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscAmp_MtrNm_f32.value = (data) \
  )

#  define Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscAmp_MtrNm_f32() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscAmp_MtrNm_f32.value)

#  define Rte_IWrite_BmwHaptcFb_Per1_TrqOscEnable_Cnt_lgc(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscEnable_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscEnable_Cnt_lgc() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscEnable_Cnt_lgc.value)

#  define Rte_IWrite_BmwHaptcFb_Per1_TrqOscFallingRampRate_MtrNmpS_f32(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscFallingRampRate_MtrNmpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscFallingRampRate_MtrNmpS_f32() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscFallingRampRate_MtrNmpS_f32.value)

#  define Rte_IWrite_BmwHaptcFb_Per1_TrqOscFreq_Hz_f32(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscFreq_Hz_f32.value = (data) \
  )

#  define Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscFreq_Hz_f32() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscFreq_Hz_f32.value)

#  define Rte_IWrite_BmwHaptcFb_Per1_TrqOscRisngRampRate_MtrNmpS_f32(data) \
  ( \
    Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscRisngRampRate_MtrNmpS_f32.value = (data) \
  )

#  define Rte_IWriteRef_BmwHaptcFb_Per1_TrqOscRisngRampRate_MtrNmpS_f32() \
  (&Rte_Task_2msA_9.Rte_RB.Rte_Ap_BmwHaptcFb_BmwHaptcFb_Per1.Rte_TrqOscRisngRampRate_MtrNmpS_f32.value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd9_SystemState9_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_BMWHAPTCFB_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWHAPTCFB_APPL_CODE) BmwHaptcFb_Init1(void);

FUNC(void, RTE_AP_BMWHAPTCFB_APPL_CODE) BmwHaptcFb_Per1(void);

# define RTE_STOP_SEC_AP_BMWHAPTCFB_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_BmwHaptcFb.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_BMWHAPTCFB_H */
