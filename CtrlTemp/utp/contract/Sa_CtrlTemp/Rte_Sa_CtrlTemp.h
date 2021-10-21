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
 *          File:  Rte_Sa_CtrlTemp.h
 *     Workspace:  C:/_Synergy_Projects/Working/CtrlTemp-nz63rn/CtrlTemp/autosar
 *     SW-C Type:  Sa_CtrlTemp
 *  Generated at:  Mon Sep 16 15:33:21 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_CtrlTemp> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CTRLTEMP_H
# define _RTE_SA_CTRLTEMP_H

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

typedef P2CONST(struct Rte_CDS_Sa_CtrlTemp, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AmbTemp_DegC_f32 ((Float)0)
# define Rte_InitValue_DiagStsTempRdPrf_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_FiltMeasTemp_DegC_f32 ((Float)0)
# define Rte_InitValue_TemperatureADC_Volt_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus(NTCNumber NTC_Cnt_T_enum, UInt8 Param_Cnt_T_u08, NxtrDiagMgrStatus Status_Cnt_T_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CtrlTemp_Init1_TemperatureADC_Volt_f32() \
  (Rte_Inst_Sa_CtrlTemp->CtrlTemp_Init1_TemperatureADC_Volt_f32->value)

# define Rte_IWrite_CtrlTemp_Init1_FiltMeasTemp_DegC_f32(data) \
  ( \
  Rte_Inst_Sa_CtrlTemp->CtrlTemp_Init1_FiltMeasTemp_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_CtrlTemp_Init1_FiltMeasTemp_DegC_f32() \
  (&Rte_Inst_Sa_CtrlTemp->CtrlTemp_Init1_FiltMeasTemp_DegC_f32->value)

# define Rte_IRead_CtrlTemp_Per1_DiagStsTempRdPrf_Cnt_lgc() \
  (Rte_Inst_Sa_CtrlTemp->CtrlTemp_Per1_DiagStsTempRdPrf_Cnt_lgc->value)

# define Rte_IRead_CtrlTemp_Per1_TemperatureADC_Volt_f32() \
  (Rte_Inst_Sa_CtrlTemp->CtrlTemp_Per1_TemperatureADC_Volt_f32->value)

# define Rte_IWrite_CtrlTemp_Per1_FiltMeasTemp_DegC_f32(data) \
  ( \
  Rte_Inst_Sa_CtrlTemp->CtrlTemp_Per1_FiltMeasTemp_DegC_f32->value = (data) \
  )

# define Rte_IWriteRef_CtrlTemp_Per1_FiltMeasTemp_DegC_f32() \
  (&Rte_Inst_Sa_CtrlTemp->CtrlTemp_Per1_FiltMeasTemp_DegC_f32->value)

# define Rte_IRead_CtrlTemp_Per2_AmbTemp_DegC_f32() \
  (Rte_Inst_Sa_CtrlTemp->CtrlTemp_Per2_AmbTemp_DegC_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_NxtrDiagMgr_SetNTCStatus Rte_Call_Sa_CtrlTemp_NxtrDiagMgr_SetNTCStatus




# define RTE_START_SEC_SA_CTRLTEMP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrlTemp_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CtrlTemp_Init1_TemperatureADC_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CtrlTemp_Init1_FiltMeasTemp_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_CtrlTemp_Init1_FiltMeasTemp_DegC_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CTRLTEMP_APPL_CODE) CtrlTemp_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrlTemp_Per1
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
 *   Boolean Rte_IRead_CtrlTemp_Per1_DiagStsTempRdPrf_Cnt_lgc(void)
 *   Float Rte_IRead_CtrlTemp_Per1_TemperatureADC_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CtrlTemp_Per1_FiltMeasTemp_DegC_f32(Float data)
 *   Float *Rte_IWriteRef_CtrlTemp_Per1_FiltMeasTemp_DegC_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CTRLTEMP_APPL_CODE) CtrlTemp_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtrlTemp_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_CtrlTemp_Per2_AmbTemp_DegC_f32(void)
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

FUNC(void, RTE_SA_CTRLTEMP_APPL_CODE) CtrlTemp_Per2(void);

# define RTE_STOP_SEC_SA_CTRLTEMP_APPL_CODE
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
#   if RTE_MAGIC_NUMBER != 1379355108
#    error "The magic number of the generated file <C:/_Synergy_Projects/Working/CtrlTemp-nz63rn/CtrlTemp/utp/contract/Sa_CtrlTemp/Rte_Sa_CtrlTemp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1379355108
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CTRLTEMP_H */
