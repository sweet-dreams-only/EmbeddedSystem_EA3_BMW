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
 *          File:  Rte_Ap_EtDmpFw.h
 *     Workspace:  C:/Synergy_projects/EtDmpFw-lz4p8n/EtDmpFw/autosar/Ap_EtDmpFw.dcf
 *     SW-C Type:  Ap_EtDmpFw
 *  Generated at:  Thu May 16 14:24:14 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  Application header file for SW-C <Ap_EtDmpFw> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ETDMPFW_H
# define _RTE_AP_ETDMPFW_H

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

typedef P2CONST(struct Rte_CDS_Ap_EtDmpFw, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistEOTDamping_MtrNm_f32 (0.0F)
# define Rte_InitValue_CRFMtrVel_MtrRadpS_f32 (0.0F)
# define Rte_InitValue_EOTDampingLtd_MtrNm_f32 (0.0F)
# define Rte_InitValue_EOTDisable_Cnt_lgc (FALSE)
# define Rte_InitValue_HandwheelAuthority_Uls_f32 (0.0F)
# define Rte_InitValue_HandwheelPosition_HwDeg_f32 (0.0F)
# define Rte_InitValue_MEC_Counter_Cnt_enum (0U)
# define Rte_InitValue_Vehicle_Speed_Kph_f32 (0.0F)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_EtDmpFw_FaultInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_ETDMPFW_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_EtDmpFw_Per1_AssistEOTDamping_MtrNm_f32() \
  (Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_AssistEOTDamping_MtrNm_f32->value)

# define Rte_IRead_EtDmpFw_Per1_CRFMtrVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_CRFMtrVel_MtrRadpS_f32->value)

# define Rte_IRead_EtDmpFw_Per1_EOTDisable_Cnt_lgc() \
  (Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_EOTDisable_Cnt_lgc->value)

# define Rte_IRead_EtDmpFw_Per1_HandwheelAuthority_Uls_f32() \
  (Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_HandwheelAuthority_Uls_f32->value)

# define Rte_IRead_EtDmpFw_Per1_HandwheelPosition_HwDeg_f32() \
  (Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_HandwheelPosition_HwDeg_f32->value)

# define Rte_IRead_EtDmpFw_Per1_MEC_Counter_Cnt_enum() \
  (Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_MEC_Counter_Cnt_enum->value)

# define Rte_IRead_EtDmpFw_Per1_Vehicle_Speed_Kph_f32() \
  (Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_Vehicle_Speed_Kph_f32->value)

# define Rte_IWrite_EtDmpFw_Per1_EOTDampingLtd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_EOTDampingLtd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_EtDmpFw_Per1_EOTDampingLtd_MtrNm_f32() \
  (&Rte_Inst_Ap_EtDmpFw->EtDmpFw_Per1_EOTDampingLtd_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FaultInjection_SCom_FltInjection Rte_Call_Ap_EtDmpFw_FaultInjection_SCom_FltInjection




# define RTE_START_SEC_AP_ETDMPFW_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: EtDmpFw_Per1
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
 *   Float Rte_IRead_EtDmpFw_Per1_AssistEOTDamping_MtrNm_f32(void)
 *   Float Rte_IRead_EtDmpFw_Per1_CRFMtrVel_MtrRadpS_f32(void)
 *   Boolean Rte_IRead_EtDmpFw_Per1_EOTDisable_Cnt_lgc(void)
 *   Float Rte_IRead_EtDmpFw_Per1_HandwheelAuthority_Uls_f32(void)
 *   Float Rte_IRead_EtDmpFw_Per1_HandwheelPosition_HwDeg_f32(void)
 *   ManufModeType Rte_IRead_EtDmpFw_Per1_MEC_Counter_Cnt_enum(void)
 *   Float Rte_IRead_EtDmpFw_Per1_Vehicle_Speed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_EtDmpFw_Per1_EOTDampingLtd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_EtDmpFw_Per1_EOTDampingLtd_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ETDMPFW_APPL_CODE) EtDmpFw_Per1(void);

# define RTE_STOP_SEC_AP_ETDMPFW_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1368733517
#    error "The magic number of the generated file <C:/Synergy_projects/EtDmpFw-lz4p8n/EtDmpFw/utp/contract/Ap_EtDmpFw/Rte_Ap_EtDmpFw.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1368733517
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ETDMPFW_H */
