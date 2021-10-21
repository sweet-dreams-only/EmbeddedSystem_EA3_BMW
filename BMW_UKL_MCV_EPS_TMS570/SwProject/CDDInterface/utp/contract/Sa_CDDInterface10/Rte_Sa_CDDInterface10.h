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
 *          File:  Rte_Sa_CDDInterface10.h
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_410PR/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface10
 *  Generated at:  Thu Feb 14 10:37:40 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Sa_CDDInterface10> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SA_CDDINTERFACE10_H
# define _RTE_SA_CDDINTERFACE10_H

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

typedef P2CONST(struct Rte_CDS_Sa_CDDInterface10, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CommOffset_Cnt_u16 (0U)
# define Rte_InitValue_DeadTimeComp_Uls_f32 (0.0F)
# define Rte_InitValue_DutyCycleSmall_Cnt_u16 (0U)
# define Rte_InitValue_ExpectedOnTimeA_Cnt_u32 (0U)
# define Rte_InitValue_ExpectedOnTimeB_Cnt_u32 (0U)
# define Rte_InitValue_ExpectedOnTimeC_Cnt_u32 (0U)
# define Rte_InitValue_FETFaultPhase_Cnt_enum (0U)
# define Rte_InitValue_FETFaultType_Cnt_enum (0U)
# define Rte_InitValue_MeasuredOnTimeA_Cnt_u32 (0U)
# define Rte_InitValue_MeasuredOnTimeB_Cnt_u32 (0U)
# define Rte_InitValue_MeasuredOnTimeC_Cnt_u32 (0U)
# define Rte_InitValue_ModIdxFinal_Uls_f32 (0.0F)
# define Rte_InitValue_MtrElecMechPolarity_Cnt_s08 (0)
# define Rte_InitValue_MtrTrqCmdSign_Cnt_s16 (0)
# define Rte_InitValue_PhaseAdvFinal_Cnt_u16 (0U)
# define Rte_InitValue_SWDutyCycleA_Uls_f32 (0.0F)
# define Rte_InitValue_SWDutyCycleB_Uls_f32 (0.0F)
# define Rte_InitValue_SWDutyCycleC_Uls_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CDDInterface10_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Sa_CDDInterface10_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_CDDInterface10_Init1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Init1_MtrElecMechPolarity_Cnt_s08->value)

# define Rte_IRead_CDDInterface10_Per1_MtrElecMechPolarity_Cnt_s08() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MtrElecMechPolarity_Cnt_s08->value)

# define Rte_IWrite_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_DutyCycleSmall_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_DutyCycleSmall_Cnt_u16->value)

# define Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32->value)

# define Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32->value)

# define Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32->value)

# define Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32->value)

# define Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32->value)

# define Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32->value)

# define Rte_IWrite_CDDInterface10_Per1_SWDutyCycleA_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_SWDutyCycleA_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleA_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_SWDutyCycleA_Uls_f32->value)

# define Rte_IWrite_CDDInterface10_Per1_SWDutyCycleB_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_SWDutyCycleB_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleB_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_SWDutyCycleB_Uls_f32->value)

# define Rte_IWrite_CDDInterface10_Per1_SWDutyCycleC_Uls_f32(data) \
  ( \
  Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_SWDutyCycleC_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleC_Uls_f32() \
  (&Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per1_SWDutyCycleC_Uls_f32->value)

# define Rte_IRead_CDDInterface10_Per2_CommOffset_Cnt_u16() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per2_CommOffset_Cnt_u16->value)

# define Rte_IRead_CDDInterface10_Per2_DeadTimeComp_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per2_DeadTimeComp_Uls_f32->value)

# define Rte_IRead_CDDInterface10_Per2_ModIdxFinal_Uls_f32() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per2_ModIdxFinal_Uls_f32->value)

# define Rte_IRead_CDDInterface10_Per2_MtrTrqCmdSign_Cnt_s16() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per2_MtrTrqCmdSign_Cnt_s16->value)

# define Rte_IRead_CDDInterface10_Per2_PhaseAdvFinal_Cnt_u16() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per2_PhaseAdvFinal_Cnt_u16->value)

# define Rte_IRead_CDDInterface10_Per3_FETFaultPhase_Cnt_enum() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per3_FETFaultPhase_Cnt_enum->value)

# define Rte_IRead_CDDInterface10_Per3_FETFaultType_Cnt_enum() \
  (Rte_Inst_Sa_CDDInterface10->CDDInterface10_Per3_FETFaultType_Cnt_enum->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_CDDPorts_ApplyMtrElecMechPol Rte_Call_Sa_CDDInterface10_CDDPorts_ApplyMtrElecMechPol
# define Rte_Call_CDDPorts_ClearPhsReasSum Rte_Call_Sa_CDDInterface10_CDDPorts_ClearPhsReasSum




# define RTE_START_SEC_SA_CDDINTERFACE10_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Init1
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
 *   SInt8 Rte_IRead_CDDInterface10_Init1_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Per1
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
 *   SInt8 Rte_IRead_CDDInterface10_Per1_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_SWDutyCycleA_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleA_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_SWDutyCycleB_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleB_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_SWDutyCycleC_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleC_Uls_f32(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Per2
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
 *   UInt16 Rte_IRead_CDDInterface10_Per2_CommOffset_Cnt_u16(void)
 *   Float Rte_IRead_CDDInterface10_Per2_DeadTimeComp_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface10_Per2_ModIdxFinal_Uls_f32(void)
 *   SInt16 Rte_IRead_CDDInterface10_Per2_MtrTrqCmdSign_Cnt_s16(void)
 *   UInt16 Rte_IRead_CDDInterface10_Per2_PhaseAdvFinal_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per2(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Per3
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
 *   FETPHASETYPE_ENUM Rte_IRead_CDDInterface10_Per3_FETFaultPhase_Cnt_enum(void)
 *   FETFAULTTYPE_ENUM Rte_IRead_CDDInterface10_Per3_FETFaultType_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per3(void);

# define RTE_STOP_SEC_SA_CDDINTERFACE10_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1360860104
#    error "The magic number of the generated file <C:/Documents and Settings/cz7lt6/Desktop/New Folder/Sa_CDDInterface10/Rte_Sa_CDDInterface10.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1360860104
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_SA_CDDINTERFACE10_H */
