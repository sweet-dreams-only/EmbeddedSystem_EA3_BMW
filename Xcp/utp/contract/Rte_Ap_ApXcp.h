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
 *          File:  Rte_Ap_ApXcp.h
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_TOF/Xcp/autosar/Ap_ApXcp.dcf
 *     SW-C Type:  Ap_ApXcp
 *  Generated at:  Thu Jul 11 15:51:18 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_ApXcp> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_APXCP_H
# define _RTE_AP_APXCP_H

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

typedef P2CONST(struct Rte_CDS_Ap_ApXcp, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ActiveTunOvrPtrAddr_Cnt_u32 (0U)
# define Rte_InitValue_ActiveTunPers_Cnt_u16 (0U)
# define Rte_InitValue_ActiveTunSet_Cnt_u16 (0U)
# define Rte_InitValue_DesiredTunPers_Cnt_u16 (0U)
# define Rte_InitValue_DesiredTunSet_Cnt_u16 (0U)
# define Rte_InitValue_TuningSessionActPtr_Cnt_u8 (255U)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_ApXcp_Per1_ActiveTunPers_Cnt_u16() \
  (Rte_Inst_Ap_ApXcp->ApXcp_Per1_ActiveTunPers_Cnt_u16->value)

# define Rte_IRead_ApXcp_Per1_ActiveTunSet_Cnt_u16() \
  (Rte_Inst_Ap_ApXcp->ApXcp_Per1_ActiveTunSet_Cnt_u16->value)

# define Rte_IRead_ApXcp_Per1_DesiredTunPers_Cnt_u16() \
  (Rte_Inst_Ap_ApXcp->ApXcp_Per1_DesiredTunPers_Cnt_u16->value)

# define Rte_IRead_ApXcp_Per1_DesiredTunSet_Cnt_u16() \
  (Rte_Inst_Ap_ApXcp->ApXcp_Per1_DesiredTunSet_Cnt_u16->value)

# define Rte_IWrite_ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32(data) \
  ( \
  Rte_Inst_Ap_ApXcp->ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32->value = (data) \
  )

# define Rte_IWriteRef_ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32() \
  (&Rte_Inst_Ap_ApXcp->ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32->value)

# define Rte_IWrite_ApXcp_Per1_TuningSessionActPtr_Cnt_u8(data) \
  ( \
  Rte_Inst_Ap_ApXcp->ApXcp_Per1_TuningSessionActPtr_Cnt_u8->value = (data) \
  )

# define Rte_IWriteRef_ApXcp_Per1_TuningSessionActPtr_Cnt_u8() \
  (&Rte_Inst_Ap_ApXcp->ApXcp_Per1_TuningSessionActPtr_Cnt_u8->value)




# define RTE_START_SEC_AP_APXCP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ApXcp_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_ApXcp_Per1_ActiveTunPers_Cnt_u16(void)
 *   UInt16 Rte_IRead_ApXcp_Per1_ActiveTunSet_Cnt_u16(void)
 *   UInt16 Rte_IRead_ApXcp_Per1_DesiredTunPers_Cnt_u16(void)
 *   UInt16 Rte_IRead_ApXcp_Per1_DesiredTunSet_Cnt_u16(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32(void)
 *   void Rte_IWrite_ApXcp_Per1_TuningSessionActPtr_Cnt_u8(TuningSessionAddrPtrEnum data)
 *   TuningSessionAddrPtrEnum *Rte_IWriteRef_ApXcp_Per1_TuningSessionActPtr_Cnt_u8(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_APXCP_APPL_CODE) ApXcp_Per1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DAQ_1msTL
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_APXCP_APPL_CODE) DAQ_1msTL(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DAQ_2msTL
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_APXCP_APPL_CODE) DAQ_2msTL(void);

# define RTE_STOP_SEC_AP_APXCP_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1357927880
#    error "The magic number of the generated file <C:/ccm_wa/EPS/570/I410/Xcp/utp/contract/Rte_Ap_ApXcp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1357927880
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_APXCP_H */
