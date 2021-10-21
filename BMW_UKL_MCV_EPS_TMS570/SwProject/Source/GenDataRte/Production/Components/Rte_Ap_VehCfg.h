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
 *          File:  Components/Rte_Ap_VehCfg.h
 *     Workspace:  c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Fri Apr 28 16:52:13 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_VEHCFG_H
# define _RTE_AP_VEHCFG_H

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

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

/************************************************************************/
/* extern declaration of RTE buffers for optimized macro implementation */
/************************************************************************/
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CADASIF_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CASSISTMSA_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_VehCfg_CBATCURLIMITCURRENT_Amp_f32;
extern VAR(UInt8, RTE_VAR_INIT) Rte_VehCfg_CDISPCCDRDY02_Cnt_u08;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CDRVDYNMSG_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CEFANMSG_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CEPSPWRMAX_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CEVIIF_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CFRCOMPIF_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CHWACORRECTION_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CPLCOMPIF_Cnt_lgc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CSELRETURN_Cnt_lgc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_VehCfg_CSELTUNINGBASE_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_VehCfg_CSELTUNINGSPORT_Cnt_u08;
extern VAR(UInt8, RTE_VAR_INIT) Rte_VehCfg_CSELTUNINGSVT_Cnt_u08;
extern VAR(Float, RTE_VAR_INIT) Rte_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc;
extern VAR(Float, RTE_VAR_INIT) Rte_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32;
extern VAR(Boolean, RTE_VAR_INIT) Rte_VehCfg_TxDebugMsgEn_Cnt_lgc;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h"

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CADASIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CASSISTMSA_Cnt_lgc (FALSE)
#  define Rte_InitValue_CBATCURLIMITCURRENT_Amp_f32 (0.0F)
#  define Rte_InitValue_CDISPCCDRDY02_Cnt_u08 (1U)
#  define Rte_InitValue_CDRVDYNMSG_Cnt_lgc (FALSE)
#  define Rte_InitValue_CEFANMSG_Cnt_lgc (FALSE)
#  define Rte_InitValue_CEPSPWRMAX_Cnt_lgc (TRUE)
#  define Rte_InitValue_CERRMVOLTFALLBACK_Cnt_lgc (FALSE)
#  define Rte_InitValue_CEVIIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CFACTORIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CFRCOMPIF_Cnt_lgc (TRUE)
#  define Rte_InitValue_CHWACORRECTION_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWANGLEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CHWTORQUEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CMTTORQUEIF_Cnt_lgc (FALSE)
#  define Rte_InitValue_CPLCOMPIF_Cnt_lgc (TRUE)
#  define Rte_InitValue_CSELRETURN_Cnt_lgc (FALSE)
#  define Rte_InitValue_CSELTUNINGBASE_Cnt_u08 (0U)
#  define Rte_InitValue_CSELTUNINGSPORT_Cnt_u08 (0U)
#  define Rte_InitValue_CSELTUNINGSVT_Cnt_u08 (0U)
#  define Rte_InitValue_CVEHSPDCURLIMITCURRENT_Amp_f32 (0.0F)
#  define Rte_InitValue_CVEHSPDCURLIMITER_Cnt_lgc (FALSE)
#  define Rte_InitValue_CVEHSPDCURLIMITSPEED_Kph_f32 (0.0F)
#  define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
#  define Rte_InitValue_DesiredTunSet_Cnt_u16 (0U)
#  define Rte_InitValue_EnergyModeState_Cnt_enum (0U)
#  define Rte_InitValue_NxtrMEC_Cnt_enum (0U)
#  define Rte_InitValue_PrkAssistState_Cnt_u08 (128U)
#  define Rte_InitValue_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP (3U)
#  define Rte_InitValue_TxDebugMsgEn_Cnt_lgc (FALSE)
#  define Rte_InitValue_VINValid_Cnt_lgc (FALSE)
# endif


# ifndef RTE_CORE
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

extern VAR(Rte_tsTask_InitA_9, RTE_VAR_NOINIT) Rte_Task_InitA_9;

extern VAR(Rte_tsTask_10msB_9, RTE_VAR_NOINIT) Rte_Task_10msB_9;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h"
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CFACTORIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CHWANGLEIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CHWTORQUEIF_Cnt_lgc(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ap_VehCfg_CMTTORQUEIF_Cnt_lgc(Boolean data);

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

#  define Rte_IWrite_VehCfg_Init1_DesiredTunPers_Cnt_u16(data) \
  ( \
    Rte_Task_InitA_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Init1.Rte_DesiredTunPers_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_VehCfg_Init1_DesiredTunPers_Cnt_u16() \
  (&Rte_Task_InitA_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Init1.Rte_DesiredTunPers_Cnt_u16.value)

#  define Rte_IWrite_VehCfg_Init1_DesiredTunSet_Cnt_u16(data) \
  ( \
    Rte_Task_InitA_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Init1.Rte_DesiredTunSet_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_VehCfg_Init1_DesiredTunSet_Cnt_u16() \
  (&Rte_Task_InitA_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Init1.Rte_DesiredTunSet_Cnt_u16.value)

#  define Rte_IRead_VehCfg_Per1_NxtrMEC_Cnt_enum() \
  (Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_NxtrMEC_Cnt_enum.value)

#  define Rte_IRead_VehCfg_Per1_PrkAssistState_Cnt_u08() \
  (Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_PrkAssistState_Cnt_u08.value)

#  define Rte_IRead_VehCfg_Per1_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP() \
  (Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_SrlComTuningSel_SU_CLU_STMOM_SFE_DXP.value)

#  define Rte_IRead_VehCfg_Per1_VINValid_Cnt_lgc() \
  (Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_VINValid_Cnt_lgc.value)

#  define Rte_IWrite_VehCfg_Per1_DesiredTunPers_Cnt_u16(data) \
  ( \
    Rte_Task_10msB_9.Rte_TB.Rte_I_VehCfg_DesiredTunPers_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_VehCfg_Per1_DesiredTunPers_Cnt_u16() \
  (&Rte_Task_10msB_9.Rte_TB.Rte_I_VehCfg_DesiredTunPers_Cnt_u16.value)

#  define Rte_IWrite_VehCfg_Per1_DesiredTunSet_Cnt_u16(data) \
  ( \
    Rte_Task_10msB_9.Rte_TB.Rte_I_VehCfg_DesiredTunSet_Cnt_u16.value = (data) \
  )

#  define Rte_IWriteRef_VehCfg_Per1_DesiredTunSet_Cnt_u16() \
  (&Rte_Task_10msB_9.Rte_TB.Rte_I_VehCfg_DesiredTunSet_Cnt_u16.value)

#  define Rte_IWrite_VehCfg_Per1_EnergyModeState_Cnt_enum(data) \
  ( \
    Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_EnergyModeState_Cnt_enum.value = (data) \
  )

#  define Rte_IWriteRef_VehCfg_Per1_EnergyModeState_Cnt_enum() \
  (&Rte_Task_10msB_9.Rte_RB.Rte_Ap_VehCfg_VehCfg_Per1.Rte_EnergyModeState_Cnt_enum.value)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_CADASIF_Cnt_lgc Rte_Write_Ap_VehCfg_CADASIF_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CADASIF_Cnt_lgc(data) (Rte_VehCfg_CADASIF_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CASSISTMSA_Cnt_lgc Rte_Write_Ap_VehCfg_CASSISTMSA_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CASSISTMSA_Cnt_lgc(data) (Rte_VehCfg_CASSISTMSA_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CBATCURLIMITCURRENT_Amp_f32 Rte_Write_Ap_VehCfg_CBATCURLIMITCURRENT_Amp_f32
#  define Rte_Write_Ap_VehCfg_CBATCURLIMITCURRENT_Amp_f32(data) (Rte_VehCfg_CBATCURLIMITCURRENT_Amp_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CDISPCCDRDY02_Cnt_u08 Rte_Write_Ap_VehCfg_CDISPCCDRDY02_Cnt_u08
#  define Rte_Write_Ap_VehCfg_CDISPCCDRDY02_Cnt_u08(data) (Rte_VehCfg_CDISPCCDRDY02_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CDRVDYNMSG_Cnt_lgc Rte_Write_Ap_VehCfg_CDRVDYNMSG_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CDRVDYNMSG_Cnt_lgc(data) (Rte_VehCfg_CDRVDYNMSG_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CEFANMSG_Cnt_lgc Rte_Write_Ap_VehCfg_CEFANMSG_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CEFANMSG_Cnt_lgc(data) (Rte_VehCfg_CEFANMSG_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CEPSPWRMAX_Cnt_lgc Rte_Write_Ap_VehCfg_CEPSPWRMAX_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CEPSPWRMAX_Cnt_lgc(data) (Rte_VehCfg_CEPSPWRMAX_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CERRMVOLTFALLBACK_Cnt_lgc Rte_Write_Ap_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc(data) (Rte_VehCfg_CERRMVOLTFALLBACK_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CEVIIF_Cnt_lgc Rte_Write_Ap_VehCfg_CEVIIF_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CEVIIF_Cnt_lgc(data) (Rte_VehCfg_CEVIIF_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CFACTORIF_Cnt_lgc Rte_Write_Ap_VehCfg_CFACTORIF_Cnt_lgc
#  define Rte_Write_CFRCOMPIF_Cnt_lgc Rte_Write_Ap_VehCfg_CFRCOMPIF_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CFRCOMPIF_Cnt_lgc(data) (Rte_VehCfg_CFRCOMPIF_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CHWACORRECTION_Cnt_lgc Rte_Write_Ap_VehCfg_CHWACORRECTION_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CHWACORRECTION_Cnt_lgc(data) (Rte_VehCfg_CHWACORRECTION_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CHWANGLEIF_Cnt_lgc Rte_Write_Ap_VehCfg_CHWANGLEIF_Cnt_lgc
#  define Rte_Write_CHWTORQUEIF_Cnt_lgc Rte_Write_Ap_VehCfg_CHWTORQUEIF_Cnt_lgc
#  define Rte_Write_CMTTORQUEIF_Cnt_lgc Rte_Write_Ap_VehCfg_CMTTORQUEIF_Cnt_lgc
#  define Rte_Write_CPLCOMPIF_Cnt_lgc Rte_Write_Ap_VehCfg_CPLCOMPIF_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CPLCOMPIF_Cnt_lgc(data) (Rte_VehCfg_CPLCOMPIF_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CSELRETURN_Cnt_lgc Rte_Write_Ap_VehCfg_CSELRETURN_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CSELRETURN_Cnt_lgc(data) (Rte_VehCfg_CSELRETURN_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CSELTUNINGBASE_Cnt_u08 Rte_Write_Ap_VehCfg_CSELTUNINGBASE_Cnt_u08
#  define Rte_Write_Ap_VehCfg_CSELTUNINGBASE_Cnt_u08(data) (Rte_VehCfg_CSELTUNINGBASE_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CSELTUNINGSPORT_Cnt_u08 Rte_Write_Ap_VehCfg_CSELTUNINGSPORT_Cnt_u08
#  define Rte_Write_Ap_VehCfg_CSELTUNINGSPORT_Cnt_u08(data) (Rte_VehCfg_CSELTUNINGSPORT_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CSELTUNINGSVT_Cnt_u08 Rte_Write_Ap_VehCfg_CSELTUNINGSVT_Cnt_u08
#  define Rte_Write_Ap_VehCfg_CSELTUNINGSVT_Cnt_u08(data) (Rte_VehCfg_CSELTUNINGSVT_Cnt_u08 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CVEHSPDCURLIMITCURRENT_Amp_f32 Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32
#  define Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32(data) (Rte_VehCfg_CVEHSPDCURLIMITCURRENT_Amp_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CVEHSPDCURLIMITER_Cnt_lgc Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc(data) (Rte_VehCfg_CVEHSPDCURLIMITER_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_CVEHSPDCURLIMITSPEED_Kph_f32 Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32
#  define Rte_Write_Ap_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32(data) (Rte_VehCfg_CVEHSPDCURLIMITSPEED_Kph_f32 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_TxDebugMsgEn_Cnt_lgc Rte_Write_Ap_VehCfg_TxDebugMsgEn_Cnt_lgc
#  define Rte_Write_Ap_VehCfg_TxDebugMsgEn_Cnt_lgc(data) (Rte_VehCfg_TxDebugMsgEn_Cnt_lgc = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CODING_APPL_CODE
#  include "MemMap.h"
FUNC(void, RTE_CODING_APPL_CODE) Coding_RequestBlock(Coding_BlockIdType blockId);
#  define RTE_STOP_SEC_CODING_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_Block_Request(arg1) (Coding_RequestBlock(arg1), ((Std_ReturnType)RTE_E_OK))
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, P2VAR(UInt8, AUTOMATIC, RTE_NVM_APPL_VAR) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, P2VAR(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_VAR) DstPtr);
# endif
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NvM_PrevTuningSel_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)37, arg1))
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "MemMap.h"
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(UInt8, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# else
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, P2CONST(NvM_DestPtr, AUTOMATIC, RTE_NVM_APPL_DATA) DstPtr);
# endif
#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NvM_PrevTuningSel_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)37, arg1))
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_GetNTCStatus(NTCNumber NTC_Cnt_T_enum, P2VAR(UInt8, AUTOMATIC, RTE_AP_DIAGMGR9_APPL_VAR) Status_Ptr_T_u08);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_GetNTCStatus NxtrDiagMgr9_GetNTCStatus
#  define RTE_START_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"
FUNC(Std_ReturnType, RTE_AP_DIAGMGR9_APPL_CODE) NxtrDiagMgr9_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);
#  define RTE_STOP_SEC_AP_DIAGMGR9_APPL_CODE
#  include "MemMap.h"

#  define Rte_Call_NxtrDiagMgr_SetNTCStatus NxtrDiagMgr9_SetNTCStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

extern VAR(TuningSelectParam, RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP) Rte_VehCfg_PrevVldTuningSel;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP_UNSPECIFIED
#   include "MemMap.h"

#  endif

#  define Rte_Pim_PrevVldTuningSel() \
  (&Rte_VehCfg_PrevVldTuningSel)


# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_AP_VEHCFG_APPL_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlockValid_Check(Coding_BlockIdType blockId, P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);
# else
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlockValid_Check(Coding_BlockIdType blockId, P2CONST(Coding_BlockDataType, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize, P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);
# endif

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlock_Receive(Coding_BlockIdType blockId, P2CONST(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize);
# else
FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkBlock_Receive(Coding_BlockIdType blockId, P2CONST(Coding_BlockDataType, AUTOMATIC, RTE_AP_VEHCFG_APPL_DATA) blockData, UInt8 blockSize);
# endif

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkDataChange_EndNotification(Coding_DataStatusType dataStatus);

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkDataChange_StartNotification(void);

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) CbkPreConditions_Check(P2VAR(Coding_ErrorType, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) error);

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Init1(void);

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Per1(void);

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_ClearRacktoVehCntrOffset(void);

FUNC(void, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_GetVariantSelect(P2VAR(UInt8, AUTOMATIC, RTE_AP_VEHCFG_APPL_VAR) VehicleVariant_Cnt_T_u8);

FUNC(Std_ReturnType, RTE_AP_VEHCFG_APPL_CODE) VehCfg_Scom_SetVariantSelect(UInt8 VehicleVariant_Cnt_T_u8);

# define RTE_STOP_SEC_AP_VEHCFG_APPL_CODE
# include "MemMap.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvM_AC3_SRBS_Srv_E_NOT_OK (1U)

#  define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

#  define RTE_E_VehCfg_Scom_E_VARIANT_OUTOFRANGE (34U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Components/Rte_Ap_VehCfg.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_VEHCFG_H */
