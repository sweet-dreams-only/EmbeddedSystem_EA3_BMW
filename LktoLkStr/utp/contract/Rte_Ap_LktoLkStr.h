/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2010 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Ap_LktoLkStr.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LktoLkStr-nzt9hv/LktoLkStr/autosar
 *     SW-C Type:  Ap_LktoLkStr
 *  Generated at:  Sun Sep 23 09:51:49 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_LktoLkStr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_LKTOLKSTR_H
# define _RTE_AP_LKTOLKSTR_H

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

typedef P2CONST(struct Rte_CDS_Ap_LktoLkStr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AlignedHwPosition_HwDeg_f32 ((Float)0)
# define Rte_InitValue_LrnPnCenterEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_LrnPnCntrCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_LrnPnCntrHwCenter_HwDeg_f32 ((Float)0)
# define Rte_InitValue_LrnPnCntrHwTravel_HwDeg_f32 ((Float)0)
# define Rte_InitValue_LrnPnCntrState_Cnt_enum ((LktoLkStrStateType)0u)
# define Rte_InitValue_MotorVelCRF_MtrRadpS_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LktoLkStr_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, P2VAR(UInt32, AUTOMATIC, RTE_AP_LKTOLKSTR_APPL_VAR) ElapsedTime);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_LktoLkStr_SystemTime_GetSystemTime_mS_u32(P2VAR(UInt32, AUTOMATIC, RTE_AP_LKTOLKSTR_APPL_VAR) CurrentTime);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_LktoLkStr_Per1_AlignedHwPosition_HwDeg_f32() \
  (Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_AlignedHwPosition_HwDeg_f32->value)

# define Rte_IRead_LktoLkStr_Per1_LrnPnCenterEnable_Cnt_lgc() \
  (Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCenterEnable_Cnt_lgc->value)

# define Rte_IRead_LktoLkStr_Per1_MotorVelCRF_MtrRadpS_f32() \
  (Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_MotorVelCRF_MtrRadpS_f32->value)

# define Rte_IWrite_LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32->value)

# define Rte_IWrite_LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32() \
  (&Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32->value)

# define Rte_IWrite_LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32() \
  (&Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32->value)

# define Rte_IWrite_LktoLkStr_Per1_LrnPnCntrState_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCntrState_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrState_Cnt_enum() \
  (&Rte_Inst_Ap_LktoLkStr->LktoLkStr_Per1_LrnPnCntrState_Cnt_enum->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32 Rte_Call_Ap_LktoLkStr_SystemTime_DtrmnElapsedTime_mS_u32
# define Rte_Call_SystemTime_GetSystemTime_mS_u32 Rte_Call_Ap_LktoLkStr_SystemTime_GetSystemTime_mS_u32




# define RTE_START_SEC_AP_LKTOLKSTR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ap_LktoLkStr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LKTOLKSTR_APPL_CODE) Ap_LktoLkStr_Init(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LktoLkStr_Per1
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
 *   Float Rte_IRead_LktoLkStr_Per1_AlignedHwPosition_HwDeg_f32(void)
 *   Boolean Rte_IRead_LktoLkStr_Per1_LrnPnCenterEnable_Cnt_lgc(void)
 *   Float Rte_IRead_LktoLkStr_Per1_MotorVelCRF_MtrRadpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32(void)
 *   void Rte_IWrite_LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32(void)
 *   void Rte_IWrite_LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32(void)
 *   void Rte_IWrite_LktoLkStr_Per1_LrnPnCntrState_Cnt_enum(LktoLkStrStateType data)
 *   LktoLkStrStateType *Rte_IWriteRef_LktoLkStr_Per1_LrnPnCntrState_Cnt_enum(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SystemTime_DtrmnElapsedTime_mS_u32(UInt32 InitialTime, UInt32 *ElapsedTime)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_SystemTime_GetSystemTime_mS_u32(UInt32 *CurrentTime)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LKTOLKSTR_APPL_CODE) LktoLkStr_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: LktoLkStr_SCom_SetInputParam
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetInputParam> of PortPrototype <LktoLkStr_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_LKTOLKSTR_APPL_CODE) LktoLkStr_SCom_SetInputParam(Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);

# define RTE_STOP_SEC_AP_LKTOLKSTR_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1348403688
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LktoLkStr-nzt9hv/LktoLkStr/utp/contract/Rte_Ap_LktoLkStr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1348403688
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_LKTOLKSTR_H */
