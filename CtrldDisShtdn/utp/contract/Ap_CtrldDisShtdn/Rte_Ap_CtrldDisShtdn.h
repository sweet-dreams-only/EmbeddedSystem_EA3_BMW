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
 *          File:  Rte_Ap_CtrldDisShtdn.h
 *     Workspace:  C:/SynergyProjects/CBD/CtrldDisShtdn/autosar/Ap_CtrldDisShtdn.dcf
 *     SW-C Type:  Ap_CtrldDisShtdn
 *  Generated at:  Thu Jan 24 16:22:00 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_CtrldDisShtdn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_CTRLDDISSHTDN_H
# define _RTE_AP_CTRLDDISSHTDN_H

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

typedef P2CONST(struct Rte_CDS_Ap_CtrldDisShtdn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistAssyPolarity_Cnt_s08 (0)
# define Rte_InitValue_CRFMtrVel_MtrRadpS_f32 (0.0F)
# define Rte_InitValue_CntDisMtrTrqCmdCRF_MtrNm_f32 (0.0F)
# define Rte_InitValue_CntDisMtrTrqCmdMRF_MtrNm_f32 (0.0F)
# define Rte_InitValue_CtrldDmpStsCmp_Cnt_lgc (FALSE)
# define Rte_InitValue_DiagStsF2Active_Cnt_lgc (FALSE)
# define Rte_InitValue_SumLimTrqCmd_MtrNm_f32 (0.0F)
# define Rte_InitValue_SysC_CRFMtrTrqCmd_MtrNm_f32 (0.0F)
# define Rte_InitValue_SysC_MRFMtrTrqCmd_MtrNm_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_CtrldDisShtdn_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, P2VAR(UInt16, AUTOMATIC, RTE_AP_CTRLDDISSHTDN_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CtrldDisShtdn_Per1_AssistAssyPolarity_Cnt_s08() \
  (Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_AssistAssyPolarity_Cnt_s08->value)

# define Rte_IRead_CtrldDisShtdn_Per1_CRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_CRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_CtrldDisShtdn_Per1_DiagStsF2Active_Cnt_lgc() \
  (Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_DiagStsF2Active_Cnt_lgc->value)

# define Rte_IRead_CtrldDisShtdn_Per1_SumLimTrqCmd_MtrNm_f32() \
  (Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_SumLimTrqCmd_MtrNm_f32->value)

# define Rte_IWrite_CtrldDisShtdn_Per1_CntDisMtrTrqCmdCRF_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_CntDisMtrTrqCmdCRF_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_CtrldDisShtdn_Per1_CntDisMtrTrqCmdCRF_MtrNm_f32() \
  (&Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_CntDisMtrTrqCmdCRF_MtrNm_f32->value)

# define Rte_IWrite_CtrldDisShtdn_Per1_CntDisMtrTrqCmdMRF_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_CntDisMtrTrqCmdMRF_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_CtrldDisShtdn_Per1_CntDisMtrTrqCmdMRF_MtrNm_f32() \
  (&Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_CntDisMtrTrqCmdMRF_MtrNm_f32->value)

# define Rte_IWrite_CtrldDisShtdn_Per1_CtrldDmpStsCmp_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_CtrldDmpStsCmp_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_CtrldDisShtdn_Per1_CtrldDmpStsCmp_Cnt_lgc() \
  (&Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_CtrldDmpStsCmp_Cnt_lgc->value)

# define Rte_IWrite_CtrldDisShtdn_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_CtrldDisShtdn_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32->value)

# define Rte_IWrite_CtrldDisShtdn_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_CtrldDisShtdn_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_CtrldDisShtdn->CtrldDisShtdn_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_CtrldDisShtdn_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16 Rte_Call_Ap_CtrldDisShtdn_SystemTime_DtrmnElapsedTime_mS_u16
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_CtrldDisShtdn_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_CTRLDDISSHTDN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrldDisShtdn_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_CtrldDisShtdn_Per1_AssistAssyPolarity_Cnt_s08(void)
 *   Float Rte_IRead_CtrldDisShtdn_Per1_CRFMtrVel_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_CtrldDisShtdn_Per1_DiagStsF2Active_Cnt_lgc(void)
 *   Float Rte_IRead_CtrldDisShtdn_Per1_SumLimTrqCmd_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CtrldDisShtdn_Per1_CntDisMtrTrqCmdCRF_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_CtrldDisShtdn_Per1_CntDisMtrTrqCmdCRF_MtrNm_f32(void)
 *   void Rte_IWrite_CtrldDisShtdn_Per1_CntDisMtrTrqCmdMRF_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_CtrldDisShtdn_Per1_CntDisMtrTrqCmdMRF_MtrNm_f32(void)
 *   void Rte_IWrite_CtrldDisShtdn_Per1_CtrldDmpStsCmp_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_CtrldDisShtdn_Per1_CtrldDmpStsCmp_Cnt_lgc(void)
 *   void Rte_IWrite_CtrldDisShtdn_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_CtrldDisShtdn_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32(void)
 *   void Rte_IWrite_CtrldDisShtdn_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_CtrldDisShtdn_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32(void)
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
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u16(UInt32 InitialTime, UInt16 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_CTRLDDISSHTDN_APPL_CODE) CtrldDisShtdn_Per1(void);

# define RTE_STOP_SEC_AP_CTRLDDISSHTDN_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1359066606
#    error "The magic number of the generated file <C:/Documents and Settings/nzx5jd/Desktop/DVOutput/Ap_CtrldDisShtdn/Rte_Ap_CtrldDisShtdn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1359066606
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_CTRLDDISSHTDN_H */
