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
 *          File:  Rte_Ap_MtrCtrlOpConv.h
 *     Workspace:  C:/_swb/CBD/SVDrvr-cz7lt6/SVDrvr/autosar/SVDrvr.dcf
 *     SW-C Type:  Ap_MtrCtrlOpConv
 *  Generated at:  Thu Feb  7 15:34:24 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_MtrCtrlOpConv> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_MTRCTRLOPCONV_H
# define _RTE_AP_MTRCTRLOPCONV_H

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

typedef P2CONST(struct Rte_CDS_Ap_MtrCtrlOpConv, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_CommutationOffset_Cnt_u16 (0U)
# define Rte_InitValue_CurrentGainSvc_Cnt_b32 (0U)
# define Rte_InitValue_DeadTimeComp_Uls_f32 (0.0F)
# define Rte_InitValue_ModulationIndex_Uls_f32 (0.0F)
# define Rte_InitValue_ModulationIndexFinal_Uls_f32 (0.0F)
# define Rte_InitValue_MtrTrqCmdSign_Cnt_s16 (0)
# define Rte_InitValue_PhaseAdvance_Cnt_s16 (0)
# define Rte_InitValue_PhaseAdvanceFinal_Cnt_u16 (0U)
# define Rte_InitValue_TorqueCmdMRF_MtrNm_f32 (0.0F)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_MtrCtrlOpConv_Per1_CurrentGainSvc_Cnt_b32() \
  (Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_CurrentGainSvc_Cnt_b32->value)

# define Rte_IRead_MtrCtrlOpConv_Per1_ModulationIndex_Uls_f32() \
  (Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_ModulationIndex_Uls_f32->value)

# define Rte_IRead_MtrCtrlOpConv_Per1_PhaseAdvance_Cnt_s16() \
  (Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_PhaseAdvance_Cnt_s16->value)

# define Rte_IRead_MtrCtrlOpConv_Per1_TorqueCmdMRF_MtrNm_f32() \
  (Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_TorqueCmdMRF_MtrNm_f32->value)

# define Rte_IWrite_MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16() \
  (&Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16->value)

# define Rte_IWrite_MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32() \
  (&Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32->value)

# define Rte_IWrite_MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32() \
  (&Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32->value)

# define Rte_IWrite_MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16(data) \
  ( \
  Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16->value = (data) \
  )

# define Rte_IWriteRef_MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16() \
  (&Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16->value)

# define Rte_IWrite_MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16(data) \
  ( \
  Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16->value = (data) \
  )

# define Rte_IWriteRef_MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16() \
  (&Rte_Inst_Ap_MtrCtrlOpConv->MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16->value)




# define RTE_START_SEC_AP_MTRCTRLOPCONV_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrCtrlOpConv_Per1
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
 *   UInt32 Rte_IRead_MtrCtrlOpConv_Per1_CurrentGainSvc_Cnt_b32(void)
 *   Float Rte_IRead_MtrCtrlOpConv_Per1_ModulationIndex_Uls_f32(void)
 *   SInt16 Rte_IRead_MtrCtrlOpConv_Per1_PhaseAdvance_Cnt_s16(void)
 *   Float Rte_IRead_MtrCtrlOpConv_Per1_TorqueCmdMRF_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16(void)
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32(void)
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32(void)
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16(void)
 *   void Rte_IWrite_MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_MTRCTRLOPCONV_APPL_CODE) MtrCtrlOpConv_Per1(void);

# define RTE_STOP_SEC_AP_MTRCTRLOPCONV_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1351626202
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/SVDrvr-nzt9hv/SVDrvr/utp/contract/Ap_MtrCtrlOpConv/Rte_Ap_MtrCtrlOpConv.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1351626202
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_MTRCTRLOPCONV_H */
