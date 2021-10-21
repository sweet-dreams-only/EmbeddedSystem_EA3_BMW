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
 *          File:  Rte_Ap_DrvDynEnbl.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/DrvDynEnbl-nzt9hv/DrvDynEnbl/autosar
 *     SW-C Type:  Ap_DrvDynEnbl
 *  Generated at:  Tue Feb 19 14:58:06 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_DrvDynEnbl> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_DRVDYNENBL_H
# define _RTE_AP_DRVDYNENBL_H

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

typedef P2CONST(struct Rte_CDS_Ap_DrvDynEnbl, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DDEnableRqst_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DDErrInterfaceActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DiagStatus_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DrvDynActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DrvDynInterfaceState_Cnt_u08 ((QU_SER_STMOM_STMOM_DV_ACT)128u)
# define Rte_InitValue_OpTrqOvRmpInEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_PrkAssistState_Cnt_u08 ((QU_SER_WSTA_EST_FTAX)128u)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Rte_ModeType_StaMd_Mode, RTE_CODE) Rte_Mode_Ap_DrvDynEnbl_SystemState_Mode(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc() \
  (Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc->value)

# define Rte_IRead_DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc() \
  (Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc->value)

# define Rte_IRead_DrvDynEnbl_Per1_DiagStatus_Cnt_lgc() \
  (Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_DiagStatus_Cnt_lgc->value)

# define Rte_IRead_DrvDynEnbl_Per1_PrkAssistState_Cnt_u08() \
  (Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_PrkAssistState_Cnt_u08->value)

# define Rte_IWrite_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc() \
  (&Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc->value)

# define Rte_IWrite_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08(data) \
  ( \
  Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08->value = (data) \
  )

# define Rte_IWriteRef_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08() \
  (&Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08->value)

# define Rte_IWrite_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc() \
  (&Rte_Inst_Ap_DrvDynEnbl->DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc->value)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
# define Rte_Mode_SystemState_Mode Rte_Mode_Ap_DrvDynEnbl_SystemState_Mode




# define RTE_START_SEC_AP_DRVDYNENBL_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: DrvDynEnbl_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc(void)
 *   Boolean Rte_IRead_DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_DrvDynEnbl_Per1_DiagStatus_Cnt_lgc(void)
 *   QU_SER_WSTA_EST_FTAX Rte_IRead_DrvDynEnbl_Per1_PrkAssistState_Cnt_u08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc(void)
 *   void Rte_IWrite_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08(QU_SER_STMOM_STMOM_DV_ACT data)
 *   QU_SER_STMOM_STMOM_DV_ACT *Rte_IWriteRef_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08(void)
 *   void Rte_IWrite_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc(void)
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

FUNC(void, RTE_AP_DRVDYNENBL_APPL_CODE) DrvDynEnbl_Per1(void);

# define RTE_STOP_SEC_AP_DRVDYNENBL_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1361300706
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/DrvDynEnbl-nzt9hv/DrvDynEnbl/utp/contract/Ap_DrvDynEnbl/Rte_Ap_DrvDynEnbl.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1361300706
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_DRVDYNENBL_H */
