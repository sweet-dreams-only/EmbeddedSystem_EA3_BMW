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
 *          File:  Rte_Sa_MtrCurr.h
 *     Workspace:  C:/ccm_wa/EPS/570/I410/MtrCurr_VM/autosar
 *     SW-C Type:  Sa_MtrCurr
 *  Generated at:  Mon Feb  4 10:19:07 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Sa_MtrCurr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_MTRCURR_H
# define _RTE_SA_MTRCURR_H

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

typedef P2CONST(struct Rte_CDS_Sa_MtrCurr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ADCMtrCurr1_Volt_f32 ((Float)0)
# define Rte_InitValue_CorrectedMtrPos_Rev_f32 ((Float)0)
# define Rte_InitValue_DutyCycleSmall_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_InstantaneousMotorDirection_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_MtrCurrDax_Amp_f32 ((Float)0)
# define Rte_InitValue_MtrCurrQax_Amp_f32 ((Float)0)
# define Rte_InitValue_PADelta1_Cnt_u16 ((UInt16)0u)
# define Rte_InitValue_RawCurrFiltered_Amp_f32 ((Float)0)
# define Rte_InitValue_ValidSampleFlag_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Sa_MtrCurr_SystemState_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_MtrCurr_EOLShCurrCal_SetRamBlockStatus(Boolean RamBlockStatus);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_MtrCurr_Per1_ADCMtrCurr1_Volt_f32() \
  (Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_ADCMtrCurr1_Volt_f32->value)

# define Rte_IRead_MtrCurr_Per1_CorrectedMtrPos_Rev_f32() \
  (Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_CorrectedMtrPos_Rev_f32->value)

# define Rte_IRead_MtrCurr_Per1_DutyCycleSmall_Cnt_u16() \
  (Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_DutyCycleSmall_Cnt_u16->value)

# define Rte_IRead_MtrCurr_Per1_InstantaneousMotorDirection_Cnt_s08() \
  (Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_InstantaneousMotorDirection_Cnt_s08->value)

# define Rte_IRead_MtrCurr_Per1_PADelta1_Cnt_u16() \
  (Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_PADelta1_Cnt_u16->value)

# define Rte_IWrite_MtrCurr_Per1_MtrCurrDax_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_MtrCurrDax_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrCurr_Per1_MtrCurrDax_Amp_f32() \
  (&Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_MtrCurrDax_Amp_f32->value)

# define Rte_IWrite_MtrCurr_Per1_MtrCurrQax_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_MtrCurrQax_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrCurr_Per1_MtrCurrQax_Amp_f32() \
  (&Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_MtrCurrQax_Amp_f32->value)

# define Rte_IWrite_MtrCurr_Per1_RawCurrFiltered_Amp_f32(data) \
  ( \
  Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_RawCurrFiltered_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrCurr_Per1_RawCurrFiltered_Amp_f32() \
  (&Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_RawCurrFiltered_Amp_f32->value)

# define Rte_IWrite_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc(data) \
  ( \
  Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_ValidSampleFlag_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc() \
  (&Rte_Inst_Sa_MtrCurr->MtrCurr_Per1_ValidSampleFlag_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Sa_MtrCurr_SystemState_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_EOLShCurrCal_SetRamBlockStatus Rte_Call_Sa_MtrCurr_EOLShCurrCal_SetRamBlockStatus


/**********************************************************************************************************************
 * Per-Instance Memory User Types
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

# define Rte_Pim_ShCurrCal() (Rte_Inst_Sa_MtrCurr->Pim_ShCurrCal)




/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   ShCurrCal_DataType *Rte_Pim_ShCurrCal(void)
 *
 *********************************************************************************************************************/


# define RTE_START_SEC_SA_MTRCURR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
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
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF, DISABLE>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Float Rte_IRead_MtrCurr_Per1_ADCMtrCurr1_Volt_f32(void)
 *   Float Rte_IRead_MtrCurr_Per1_CorrectedMtrPos_Rev_f32(void)
 *   UInt16 Rte_IRead_MtrCurr_Per1_DutyCycleSmall_Cnt_u16(void)
 *   SInt8 Rte_IRead_MtrCurr_Per1_InstantaneousMotorDirection_Cnt_s08(void)
 *   UInt16 Rte_IRead_MtrCurr_Per1_PADelta1_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrCurr_Per1_MtrCurrDax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCurr_Per1_MtrCurrDax_Amp_f32(void)
 *   void Rte_IWrite_MtrCurr_Per1_MtrCurrQax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCurr_Per1_MtrCurrQax_Amp_f32(void)
 *   void Rte_IWrite_MtrCurr_Per1_RawCurrFiltered_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCurr_Per1_RawCurrFiltered_Amp_f32(void)
 *   void Rte_IWrite_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_MtrCurr_Per1_ValidSampleFlag_Cnt_lgc(void)
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
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_CalGain
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalGain> of PortPrototype <MtrCurr_SCom>
 *
 **********************************************************************************************************************
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
 *   Std_ReturnType Rte_Call_EOLShCurrCal_SetRamBlockStatus(Boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType MtrCurr_SCom_CalGain(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_MtrCurr_SCom_CurrentOutOfRange
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalGain(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_CalOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CalOffset> of PortPrototype <MtrCurr_SCom>
 *
 **********************************************************************************************************************
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MtrCurr_SCom_CalOffset(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_CalOffset(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_ReadMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadMtrCurrCals> of PortPrototype <MtrCurr_SCom>
 *
 **********************************************************************************************************************
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MtrCurr_SCom_ReadMtrCurrCals(ShCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_ReadMtrCurrCals(P2VAR(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_VAR) ShCurrCalPtr);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCurr_SCom_SetMtrCurrCals
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMtrCurrCals> of PortPrototype <MtrCurr_SCom>
 *
 **********************************************************************************************************************
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
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void MtrCurr_SCom_SetMtrCurrCals(const ShCurrCal_DataType *ShCurrCalPtr)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRCURR_APPL_CODE) MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_DATA) ShCurrCalPtr);

# define RTE_STOP_SEC_SA_MTRCURR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_MtrCurr_SCom_CurrentOutOfRange (34u)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1359988227
#    error "The magic number of the generated file <C:/ccm_wa/EPS/570/I410/MtrCurr_VM/utp/contract/Sa_MtrCurr/Rte_Sa_MtrCurr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1359988227
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_MTRCURR_H */
