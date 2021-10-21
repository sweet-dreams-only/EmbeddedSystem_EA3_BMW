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
 *          File:  Components/Rte_Ap_CustPL.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Wed Jun 15 12:31:38 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CUSTPL_H
# define _RTE_AP_CUSTPL_H

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

#  define RTE_START_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CASSISTMSA_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_VehCfg_CBATCURLIMITCURRENT_Amp_f32;

#  define RTE_STOP_SEC_VAR_Ap_7_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CASSISTMSA_Cnt_lgc (FALSE)
#  define Rte_InitValue_CBATCURLIMITCUR_Amp_f32 (0.0F)
#  define Rte_InitValue_CCLMSAActive_Cnt_lgc (FALSE)
#  define Rte_InitValue_CCLTrqRamp_Uls_f32 (1.0F)
#  define Rte_InitValue_CVEHSPDCURLIMITCURRENT_Amp_f32 (0.0F)
#  define Rte_InitValue_CVEHSPDCURLIMITER_Cnt_lgc (FALSE)
#  define Rte_InitValue_CVEHSPDCURLIMITSPEED_Kph_f32 (0.0F)
#  define Rte_InitValue_CustCurrLmt_Amp_f32 (0.0F)
#  define Rte_InitValue_MSACommand_MSACmd_enum (3U)
#  define Rte_InitValue_SupplyCurrLmt_Amp_f32 (166.67F)
#  define Rte_InitValue_VehicleSpeed_Kph_f32 (0.0F)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for Mode Management
 *********************************************************************************************************************/
extern VAR(Rte_ModeType_StaMd_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_StaMd7_SystemState7_Mode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif /* !defined(RTE_CORE) */



# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitB_7, RTE_VAR_NOINIT) Rte_Task_InitB_7;

extern VAR(Rte_tsTask_10ms_7, RTE_VAR_NOINIT) Rte_Task_10ms_7;

#  define RTE_STOP_SEC_VAR_Ap_7_NOINIT_UNSPECIFIED
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

#  define Rte_IWrite_CustPL_Init1_CCLMSAActive_Cnt_lgc(data) \
  ( \
    Rte_Task_InitB_7.Rte_RB.Rte_Ap_CustPL_CustPL_Init1.Rte_CCLMSAActive_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CustPL_Init1_CCLMSAActive_Cnt_lgc() \
  (&Rte_Task_InitB_7.Rte_RB.Rte_Ap_CustPL_CustPL_Init1.Rte_CCLMSAActive_Cnt_lgc.value)

#  define Rte_IWrite_CustPL_Init1_CCLTrqRamp_Uls_f32(data) \
  ( \
    Rte_Task_InitB_7.Rte_RB.Rte_Ap_CustPL_CustPL_Init1.Rte_CCLTrqRamp_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CustPL_Init1_CCLTrqRamp_Uls_f32() \
  (&Rte_Task_InitB_7.Rte_RB.Rte_Ap_CustPL_CustPL_Init1.Rte_CCLTrqRamp_Uls_f32.value)

#  define Rte_IRead_CustPL_Per1_CASSISTMSA_Cnt_lgc() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CASSISTMSA_Cnt_lgc.value)

#  define Rte_IRead_CustPL_Per1_CBATCURLIMITCUR_Amp_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CBATCURLIMITCUR_Amp_f32.value)

#  define Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITCURRENT_Amp_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CVEHSPDCURLIMITCURRENT_Amp_f32.value)

#  define Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITER_Cnt_lgc() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CVEHSPDCURLIMITER_Cnt_lgc.value)

#  define Rte_IRead_CustPL_Per1_CVEHSPDCURLIMITSPEED_Kph_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CVEHSPDCURLIMITSPEED_Kph_f32.value)

#  define Rte_IRead_CustPL_Per1_MSACommand_MSACmd_enum() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_MSACommand_MSACmd_enum.value)

#  define Rte_IRead_CustPL_Per1_SupplyCurrLmt_Amp_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_SupplyCurrLmt_Amp_f32.value)

#  define Rte_IRead_CustPL_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_VehicleSpeed_Kph_f32.value)

#  define Rte_IWrite_CustPL_Per1_CCLMSAActive_Cnt_lgc(data) \
  ( \
    Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CCLMSAActive_Cnt_lgc.value = (data) \
  )

#  define Rte_IWriteRef_CustPL_Per1_CCLMSAActive_Cnt_lgc() \
  (&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CCLMSAActive_Cnt_lgc.value)

#  define Rte_IWrite_CustPL_Per1_CCLTrqRamp_Uls_f32(data) \
  ( \
    Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CCLTrqRamp_Uls_f32.value = (data) \
  )

#  define Rte_IWriteRef_CustPL_Per1_CCLTrqRamp_Uls_f32() \
  (&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CCLTrqRamp_Uls_f32.value)

#  define Rte_IWrite_CustPL_Per1_CustCurrLmt_Amp_f32(data) \
  ( \
    Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CustCurrLmt_Amp_f32.value = (data) \
  )

#  define Rte_IWriteRef_CustPL_Per1_CustCurrLmt_Amp_f32() \
  (&Rte_Task_10ms_7.Rte_RB.Rte_Ap_CustPL_CustPL_Per1.Rte_CustCurrLmt_Amp_f32.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CASSISTMSA_Cnt_lgc Rte_Read_Ap_CustPL_CASSISTMSA_Cnt_lgc
#  define Rte_Read_Ap_CustPL_CASSISTMSA_Cnt_lgc(data) (*(data) = Rte_VehCfg_CASSISTMSA_Cnt_lgc, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_CBATCURLIMITCUR_Amp_f32 Rte_Read_Ap_CustPL_CBATCURLIMITCUR_Amp_f32
#  define Rte_Read_Ap_CustPL_CBATCURLIMITCUR_Amp_f32(data) (*(data) = Rte_VehCfg_CBATCURLIMITCURRENT_Amp_f32, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_SystemState_Mode() Rte_ModeMachine_StaMd7_SystemState7_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_AP_FLTINJECTION_APPL_CODE) FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_FLTINJECTION_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
#  define RTE_STOP_SEC_AP_FLTINJECTION_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_FaultInjection_SCom_FltInjection(arg1, arg2) (FltInjection_SCom_FltInjection(arg1, arg2), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_CUSTPL_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CUSTPL_APPL_CODE) CustPL_Init1(void);

FUNC(void, RTE_AP_CUSTPL_APPL_CODE) CustPL_Per1(void);

# define RTE_STOP_SEC_AP_CUSTPL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_CustPL.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CUSTPL_H */
