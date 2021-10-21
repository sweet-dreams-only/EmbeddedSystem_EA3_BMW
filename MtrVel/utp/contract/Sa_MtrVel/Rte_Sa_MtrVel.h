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
 *          File:  Rte_Sa_MtrVel.h
 *     Workspace:  C:/Synergy/prep_projects/MtrVel/MtrVel/autosar
 *     SW-C Type:  Sa_MtrVel
 *  Generated at:  Fri Feb 14 14:37:47 2014
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_MtrVel> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_MTRVEL_H
# define _RTE_SA_MTRVEL_H

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

typedef P2CONST(struct Rte_CDS_Sa_MtrVel, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AsstAssemPol_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_CRFMotorVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_HandwheelVel_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_HwVelValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_MRFMotorVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MRFMotorVelUnfiltered_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_SysCDiagHandWheelVel_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_SysCDiagMtrVelMRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_SysCHandwheelVel_HwRadpS_f32 ((Float)0)
# define Rte_InitValue_SysCMotorVelMRF_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrVel_FaultInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_SA_MTRVEL_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, P2VAR(Boolean, AUTOMATIC, RTE_SA_MTRVEL_APPL_VAR) NTCFailed_Ptr_T_lgc);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_MtrVel_Per1_AsstAssemPol_Cnt_s08() \
  (Rte_Inst_Sa_MtrVel->MtrVel_Per1_AsstAssemPol_Cnt_s08->value)

# define Rte_IRead_MtrVel_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Sa_MtrVel->MtrVel_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32(data) \
  ( \
  Rte_Inst_Sa_MtrVel->MtrVel_Per1_CRFMotorVel_MtrRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32() \
  (&Rte_Inst_Sa_MtrVel->MtrVel_Per1_CRFMotorVel_MtrRadpS_f32->value)

# define Rte_IWrite_MtrVel_Per1_HandwheelVel_HwRadpS_f32(data) \
  ( \
  Rte_Inst_Sa_MtrVel->MtrVel_Per1_HandwheelVel_HwRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrVel_Per1_HandwheelVel_HwRadpS_f32() \
  (&Rte_Inst_Sa_MtrVel->MtrVel_Per1_HandwheelVel_HwRadpS_f32->value)

# define Rte_IWrite_MtrVel_Per1_HwVelValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_MtrVel->MtrVel_Per1_HwVelValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_MtrVel_Per1_HwVelValid_Cnt_lgc() \
  (&Rte_Inst_Sa_MtrVel->MtrVel_Per1_HwVelValid_Cnt_lgc->value)

# define Rte_IWrite_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32(data) \
  ( \
  Rte_Inst_Sa_MtrVel->MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32() \
  (&Rte_Inst_Sa_MtrVel->MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32->value)

# define Rte_IWrite_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32(data) \
  ( \
  Rte_Inst_Sa_MtrVel->MtrVel_Per1_MRFMotorVel_MtrRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32() \
  (&Rte_Inst_Sa_MtrVel->MtrVel_Per1_MRFMotorVel_MtrRadpS_f32->value)

# define Rte_IWrite_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32(data) \
  ( \
  Rte_Inst_Sa_MtrVel->MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32() \
  (&Rte_Inst_Sa_MtrVel->MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32->value)

# define Rte_IWrite_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32(data) \
  ( \
  Rte_Inst_Sa_MtrVel->MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32() \
  (&Rte_Inst_Sa_MtrVel->MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32->value)

# define Rte_IRead_MtrVel_Per2_SysCDiagHandWheelVel_HwRadpS_f32() \
  (Rte_Inst_Sa_MtrVel->MtrVel_Per2_SysCDiagHandWheelVel_HwRadpS_f32->value)

# define Rte_IRead_MtrVel_Per2_SysCDiagMtrVelMRF_MtrRadpS_f32() \
  (Rte_Inst_Sa_MtrVel->MtrVel_Per2_SysCDiagMtrVelMRF_MtrRadpS_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FaultInjection_SCom_FltInjection Rte_Call_Sa_MtrVel_FaultInjection_SCom_FltInjection
# define Rte_Call_NxtrDiagMgr_GetNTCFailed Rte_Call_Sa_MtrVel_NxtrDiagMgr_GetNTCFailed
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_MtrVel_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_SA_MTRVEL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrVel_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrVel_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_MtrVel_Per1_AsstAssemPol_Cnt_s08(void)
 *   Float Rte_IRead_MtrVel_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_CRFMotorVel_MtrRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_HandwheelVel_HwRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_HandwheelVel_HwRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_HwVelValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrVel_Per1_HwVelValid_Cnt_lgc(void)
 *   void Rte_IWrite_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_MRFMotorVelUnfiltered_MtrRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_MRFMotorVel_MtrRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_SysCHandwheelVel_HwRadpS_f32(void)
 *   void Rte_IWrite_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32(Float data)
 *   Float *Rte_IWriteRef_MtrVel_Per1_SysCMotorVelMRF_MtrRadpS_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_NxtrDiagMgr_GetNTCFailed(NTCNumber NTC_Cnt_T_enum, Boolean *NTCFailed_Ptr_T_lgc)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NxtrDiagMgr_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrVel_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_MtrVel_Per2_SysCDiagHandWheelVel_HwRadpS_f32(void)
 *   Float Rte_IRead_MtrVel_Per2_SysCDiagMtrVelMRF_MtrRadpS_f32(void)
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

FUNC(void, RTE_SA_MTRVEL_APPL_CODE) MtrVel_Per2(void);

# define RTE_STOP_SEC_SA_MTRVEL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_NxtrDiagMgr_E_NOT_OK (1u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1392404586
#    error "The magic number of the generated file <C:/Synergy/prep_projects/MtrVel/MtrVel/utp/contract/Sa_MtrVel/Rte_Sa_MtrVel.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1392404586
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRVEL_H */
