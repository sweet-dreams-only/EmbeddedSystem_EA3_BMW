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
 *          File:  Rte_Ap_OscTraj.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/OscTraj-nzt9hv/OscTraj/autosar
 *     SW-C Type:  Ap_OscTraj
 *  Generated at:  Fri Sep 21 17:28:15 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_OscTraj> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_OSCTRAJ_H
# define _RTE_AP_OSCTRAJ_H

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

typedef P2CONST(struct Rte_CDS_Ap_OscTraj, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CalculateFlag_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HwPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_OscTrajState_Cnt_enum ((OscTrajCmdStateType)0u)
# define Rte_InitValue_OscillateHwAngle_HwDeg_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_OscTraj_Per1_CalculateFlag_Cnt_lgc() \
  (Rte_Inst_Ap_OscTraj->OscTraj_Per1_CalculateFlag_Cnt_lgc->value)

# define Rte_IRead_OscTraj_Per1_HwPos_HwDeg_f32() \
  (Rte_Inst_Ap_OscTraj->OscTraj_Per1_HwPos_HwDeg_f32->value)

# define Rte_IWrite_OscTraj_Per1_OscTrajState_Cnt_enum(data) \
  ( \
  Rte_Inst_Ap_OscTraj->OscTraj_Per1_OscTrajState_Cnt_enum->value = (data) \
  )

# define Rte_IWriteRef_OscTraj_Per1_OscTrajState_Cnt_enum() \
  (&Rte_Inst_Ap_OscTraj->OscTraj_Per1_OscTrajState_Cnt_enum->value)

# define Rte_IWrite_OscTraj_Per1_OscillateHwAngle_HwDeg_f32(data) \
  ( \
  Rte_Inst_Ap_OscTraj->OscTraj_Per1_OscillateHwAngle_HwDeg_f32->value = (data) \
  )

# define Rte_IWriteRef_OscTraj_Per1_OscillateHwAngle_HwDeg_f32() \
  (&Rte_Inst_Ap_OscTraj->OscTraj_Per1_OscillateHwAngle_HwDeg_f32->value)




# define RTE_START_SEC_AP_OSCTRAJ_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: OscTraj_Per1
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
 *   Boolean Rte_IRead_OscTraj_Per1_CalculateFlag_Cnt_lgc(void)
 *   Float Rte_IRead_OscTraj_Per1_HwPos_HwDeg_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_OscTraj_Per1_OscTrajState_Cnt_enum(OscTrajCmdStateType data)
 *   OscTrajCmdStateType *Rte_IWriteRef_OscTraj_Per1_OscTrajState_Cnt_enum(void)
 *   void Rte_IWrite_OscTraj_Per1_OscillateHwAngle_HwDeg_f32(Float data)
 *   Float *Rte_IWriteRef_OscTraj_Per1_OscillateHwAngle_HwDeg_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_OSCTRAJ_APPL_CODE) OscTraj_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OscTraj_SCom_SetInputParams
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetInputParams> of PortPrototype <OscTraj_SCom>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_OSCTRAJ_APPL_CODE) OscTraj_SCom_SetInputParams(Float Amplitude_HwDeg_f32, UInt8 Cycles_Cnt_u08, Float Frequency_Hz_f32);

# define RTE_STOP_SEC_AP_OSCTRAJ_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1348260086
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/OscTraj-nzt9hv/OscTraj/utp/contract/Rte_Ap_OscTraj.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1348260086
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_OSCTRAJ_H */
