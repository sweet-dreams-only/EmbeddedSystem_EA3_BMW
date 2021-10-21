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
 *          File:  Rte_Ap_HystComp.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/HystComp-nzt9hv/HystComp/autosar
 *     SW-C Type:  Ap_HystComp
 *  Generated at:  Sun Nov  4 13:52:18 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_HystComp> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_HYSTCOMP_H
# define _RTE_AP_HYSTCOMP_H

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

typedef P2CONST(struct Rte_CDS_Ap_HystComp, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistMechTempEst_DegC_f32 ((Float)0)
# define Rte_InitValue_BaseAssistCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_DefeatHystService_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_FricOffset_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_HysteresisComp_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_WIRCmdAmpBlnd_MtrNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_HystComp_FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_HYSTCOMP_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_HystComp_Per1_AssistMechTempEst_DegC_f32() \
  (Rte_Inst_Ap_HystComp->HystComp_Per1_AssistMechTempEst_DegC_f32->value)

# define Rte_IRead_HystComp_Per1_BaseAssistCmd_MtrNm_f32() \
  (Rte_Inst_Ap_HystComp->HystComp_Per1_BaseAssistCmd_MtrNm_f32->value)

# define Rte_IRead_HystComp_Per1_DefeatHystService_Cnt_lgc() \
  (Rte_Inst_Ap_HystComp->HystComp_Per1_DefeatHystService_Cnt_lgc->value)

# define Rte_IRead_HystComp_Per1_FricOffset_HwNm_f32() \
  (Rte_Inst_Ap_HystComp->HystComp_Per1_FricOffset_HwNm_f32->value)

# define Rte_IRead_HystComp_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_HystComp->HystComp_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_HystComp_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_HystComp->HystComp_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IRead_HystComp_Per1_WIRCmdAmpBlnd_MtrNm_f32() \
  (Rte_Inst_Ap_HystComp->HystComp_Per1_WIRCmdAmpBlnd_MtrNm_f32->value)

# define Rte_IWrite_HystComp_Per1_HysteresisComp_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_HystComp->HystComp_Per1_HysteresisComp_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_HystComp_Per1_HysteresisComp_MtrNm_f32() \
  (&Rte_Inst_Ap_HystComp->HystComp_Per1_HysteresisComp_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FltInjection_SCom_FltInjection Rte_Call_Ap_HystComp_FltInjection_SCom_FltInjection




# define RTE_START_SEC_AP_HYSTCOMP_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: HystComp_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HYSTCOMP_APPL_CODE) HystComp_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: HystComp_Per1
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
 *   Float Rte_IRead_HystComp_Per1_AssistMechTempEst_DegC_f32(void)
 *   Float Rte_IRead_HystComp_Per1_BaseAssistCmd_MtrNm_f32(void)
 *   Boolean Rte_IRead_HystComp_Per1_DefeatHystService_Cnt_lgc(void)
 *   Float Rte_IRead_HystComp_Per1_FricOffset_HwNm_f32(void)
 *   Float Rte_IRead_HystComp_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_HystComp_Per1_VehicleSpeed_Kph_f32(void)
 *   Float Rte_IRead_HystComp_Per1_WIRCmdAmpBlnd_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_HystComp_Per1_HysteresisComp_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_HystComp_Per1_HysteresisComp_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_HYSTCOMP_APPL_CODE) HystComp_Per1(void);

# define RTE_STOP_SEC_AP_HYSTCOMP_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1352051805
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/HystComp-nzt9hv/HystComp/utp/contract/Ap_HystComp/Rte_Ap_HystComp.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1352051805
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_HYSTCOMP_H */
