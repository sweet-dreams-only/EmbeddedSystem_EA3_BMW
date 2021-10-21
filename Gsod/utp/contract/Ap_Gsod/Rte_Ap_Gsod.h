


/*
   !! B E T A   V E R S I O N !!

  These programs are fully operative programs.
  However, they are not thoroughly tested yet (beta-version).
  With regard to the fact that the programs are a beta-version only,
  Vctr Informatik's liability shall be expressly excluded in cases of ordinary negligence,
  to the extent admissible by law or statute.
*/



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
 *          File:  Rte_Ap_Gsod.h
 *     Workspace:  C:/cmsynergy/CBD_GSOD_SF37/Gsod-wz7x3j/Gsod/autosar/Ap_Gsod.dcf
 *     SW-C Type:  Ap_Gsod
 *  Generated at:  Wed May 22 10:29:33 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1 (Beta)
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_Gsod> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_GSOD_H
# define _RTE_AP_GSOD_H

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

typedef P2CONST(struct Rte_CDS_Ap_Gsod, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_Ana_Hw_Torque_HwNm_f32 (0.0F)
# define Rte_InitValue_Corrected_MtrPos_Rev_f32 (0.0F)
# define Rte_InitValue_Cum_Mtr_Pos_CRF_Deg_f32 (0.0F)
# define Rte_InitValue_MtrElecMech_Polarity_Cnt_s08 (0)
# define Rte_InitValue_SysC_Ana_Hw_Torque_HwNm_f32 (0.0F)
# define Rte_InitValue_SysC_Corrected_MtrPos_Rev_f32 (0.0F)
# define Rte_InitValue_SysC_Cum_Mtr_Pos_CRF_Deg_f32 (0.0F)
# define Rte_InitValue_SysC_MtrElecMech_Polarity_Cnt_s32 (0)
# define Rte_InitValue_SysC_Torque_Cmd_CRF_MtrNm_f32 (0.0F)
# define Rte_InitValue_SysC_Torque_Cmd_MRF_MtrNm_f32 (0.0F)
# define Rte_InitValue_SysC_Vecu_Volt_f32 (5.0F)
# define Rte_InitValue_Torque_Cmd_CRF_MtrNm_f32 (0.0F)
# define Rte_InitValue_Torque_Cmd_MRF_MtrNm_f32 (0.0F)
# define Rte_InitValue_Vecu_Volt_f32 (5.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_Ana_Hw_Torque_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_Corrected_MtrPos_Rev_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08(P2VAR(SInt8, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32(P2VAR(SInt32, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_SysC_Vecu_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ap_Gsod_Vecu_Volt_f32(P2VAR(Float, AUTOMATIC, RTE_AP_GSOD_APPL_VAR) data);
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_Gsod_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_Gsod_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_Ana_Hw_Torque_HwNm_f32 Rte_Read_Ap_Gsod_Ana_Hw_Torque_HwNm_f32
# define Rte_Read_Corrected_MtrPos_Rev_f32 Rte_Read_Ap_Gsod_Corrected_MtrPos_Rev_f32
# define Rte_Read_Cum_Mtr_Pos_CRF_Deg_f32 Rte_Read_Ap_Gsod_Cum_Mtr_Pos_CRF_Deg_f32
# define Rte_Read_MtrElecMech_Polarity_Cnt_s08 Rte_Read_Ap_Gsod_MtrElecMech_Polarity_Cnt_s08
# define Rte_Read_SysC_Ana_Hw_Torque_HwNm_f32 Rte_Read_Ap_Gsod_SysC_Ana_Hw_Torque_HwNm_f32
# define Rte_Read_SysC_Corrected_MtrPos_Rev_f32 Rte_Read_Ap_Gsod_SysC_Corrected_MtrPos_Rev_f32
# define Rte_Read_SysC_Cum_Mtr_Pos_CRF_Deg_f32 Rte_Read_Ap_Gsod_SysC_Cum_Mtr_Pos_CRF_Deg_f32
# define Rte_Read_SysC_MtrElecMech_Polarity_Cnt_s32 Rte_Read_Ap_Gsod_SysC_MtrElecMech_Polarity_Cnt_s32
# define Rte_Read_SysC_Torque_Cmd_CRF_MtrNm_f32 Rte_Read_Ap_Gsod_SysC_Torque_Cmd_CRF_MtrNm_f32
# define Rte_Read_SysC_Torque_Cmd_MRF_MtrNm_f32 Rte_Read_Ap_Gsod_SysC_Torque_Cmd_MRF_MtrNm_f32
# define Rte_Read_SysC_Vecu_Volt_f32 Rte_Read_Ap_Gsod_SysC_Vecu_Volt_f32
# define Rte_Read_Torque_Cmd_CRF_MtrNm_f32 Rte_Read_Ap_Gsod_Torque_Cmd_CRF_MtrNm_f32
# define Rte_Read_Torque_Cmd_MRF_MtrNm_f32 Rte_Read_Ap_Gsod_Torque_Cmd_MRF_MtrNm_f32
# define Rte_Read_Vecu_Volt_f32 Rte_Read_Ap_Gsod_Vecu_Volt_f32


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_Gsod_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Ap_Gsod_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_AP_GSOD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Gsod_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Ana_Hw_Torque_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_Corrected_MtrPos_Rev_f32(Float *data)
 *   Std_ReturnType Rte_Read_Cum_Mtr_Pos_CRF_Deg_f32(Float *data)
 *   Std_ReturnType Rte_Read_MtrElecMech_Polarity_Cnt_s08(SInt8 *data)
 *   Std_ReturnType Rte_Read_SysC_Ana_Hw_Torque_HwNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_SysC_Corrected_MtrPos_Rev_f32(Float *data)
 *   Std_ReturnType Rte_Read_SysC_Cum_Mtr_Pos_CRF_Deg_f32(Float *data)
 *   Std_ReturnType Rte_Read_SysC_MtrElecMech_Polarity_Cnt_s32(SInt32 *data)
 *   Std_ReturnType Rte_Read_SysC_Torque_Cmd_CRF_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_SysC_Torque_Cmd_MRF_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_SysC_Vecu_Volt_f32(Float *data)
 *   Std_ReturnType Rte_Read_Torque_Cmd_CRF_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_Torque_Cmd_MRF_MtrNm_f32(Float *data)
 *   Std_ReturnType Rte_Read_Vecu_Volt_f32(Float *data)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_GSOD_APPL_CODE) Gsod_Per1(void);

# define RTE_STOP_SEC_AP_GSOD_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1369228776
#    error "The magic number of the generated file <C:/cmsynergy/CBD_GSOD_SF37/Gsod-wz7x3j/Gsod/utp/contract/Ap_Gsod/Rte_Ap_Gsod.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1369228776
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_GSOD_H */
