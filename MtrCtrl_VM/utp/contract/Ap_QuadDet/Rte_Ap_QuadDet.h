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
 *          File:  Rte_Ap_QuadDet.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/autosar
 *     SW-C Type:  Ap_QuadDet
 *  Generated at:  Sat Apr 13 16:57:39 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_QuadDet> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_QUADDET_H
# define _RTE_AP_QUADDET_H

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

typedef P2CONST(struct Rte_CDS_Ap_QuadDet, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_InstMtrDir_Cnt_s08 ((SInt8)0)
# define Rte_InitValue_MRFCumMtrPos_Deg_f32 ((Float)0)
# define Rte_InitValue_MRFMtrTrqCmdScl_MtrNm_f32 ((Float)0)
# define Rte_InitValue_MRFMtrVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_MtrQuad_Cnt_u08 ((UInt8)1u)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_QuadDet_Per1_MRFCumMtrPos_Deg_f32() \
  (Rte_Inst_Ap_QuadDet->QuadDet_Per1_MRFCumMtrPos_Deg_f32->value)

# define Rte_IRead_QuadDet_Per1_MRFMtrTrqCmdScl_MtrNm_f32() \
  (Rte_Inst_Ap_QuadDet->QuadDet_Per1_MRFMtrTrqCmdScl_MtrNm_f32->value)

# define Rte_IRead_QuadDet_Per1_MRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_QuadDet->QuadDet_Per1_MRFMtrVel_MtrRadpS_f32->value)

# define Rte_IWrite_QuadDet_Per1_InstMtrDir_Cnt_s08(data) \
  ( \
  Rte_Inst_Ap_QuadDet->QuadDet_Per1_InstMtrDir_Cnt_s08->value = (data) \
  )

# define Rte_IWriteRef_QuadDet_Per1_InstMtrDir_Cnt_s08() \
  (&Rte_Inst_Ap_QuadDet->QuadDet_Per1_InstMtrDir_Cnt_s08->value)

# define Rte_IWrite_QuadDet_Per1_MtrQuad_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_QuadDet->QuadDet_Per1_MtrQuad_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_QuadDet_Per1_MtrQuad_Cnt_u08() \
  (&Rte_Inst_Ap_QuadDet->QuadDet_Per1_MtrQuad_Cnt_u08->value)




# define RTE_START_SEC_AP_QUADDET_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: QuadDet_Per1
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
 *   Float Rte_IRead_QuadDet_Per1_MRFCumMtrPos_Deg_f32(void)
 *   Float Rte_IRead_QuadDet_Per1_MRFMtrTrqCmdScl_MtrNm_f32(void)
 *   Float Rte_IRead_QuadDet_Per1_MRFMtrVel_MtrRadpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_QuadDet_Per1_InstMtrDir_Cnt_s08(SInt8 data)
 *   SInt8 *Rte_IWriteRef_QuadDet_Per1_InstMtrDir_Cnt_s08(void)
 *   void Rte_IWrite_QuadDet_Per1_MtrQuad_Cnt_u08(UInt8 data)
 *   UInt8 *Rte_IWriteRef_QuadDet_Per1_MtrQuad_Cnt_u08(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_QUADDET_APPL_CODE) QuadDet_Per1(void);

# define RTE_STOP_SEC_AP_QUADDET_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1365890906
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/MtrCtrl_VM-nzt9hv/MtrCtrl_VM/utp/contract/Ap_QuadDet/Rte_Ap_QuadDet.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1365890906
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_QUADDET_H */
