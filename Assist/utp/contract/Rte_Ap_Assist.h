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
 *          File:  Rte_Ap_Assist.h
 *     Workspace:  C:/CMSynergy_Projects/Assist/autosar
 *     SW-C Type:  Ap_Assist
 *  Generated at:  Mon Jul 23 11:33:27 2012
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_Assist> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ASSIST_H
# define _RTE_AP_ASSIST_H

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

typedef P2CONST(struct Rte_CDS_Ap_Assist, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistDDFactor_Uls_f32 ((Float)1)
# define Rte_InitValue_BaseAssistCmd_MtrNm_f32 ((Float)0)
# define Rte_InitValue_DftAsstTbl_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DutyCycleLevel_Uls_f32 ((Float)0)
# define Rte_InitValue_DwnldAsstGain_Uls_f32 ((Float)0)
# define Rte_InitValue_HwTrq_HwNm_f32 ((Float)0)
# define Rte_InitValue_HwTrqHysAdd_HwNm_f32 ((Float)0)
# define Rte_InitValue_IpTrqOvr_HwNm_f32 ((Float)0)
# define Rte_InitValue_VehSpd_Kph_f32 ((Float)0)
# define Rte_InitValue_WIRCmdAmpBlnd_MtrNm_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_Assist_FltInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_ASSIST_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_Assist_Per1_AssistDDFactor_Uls_f32() \
  (Rte_Inst_Ap_Assist->Assist_Per1_AssistDDFactor_Uls_f32->value)

# define Rte_IRead_Assist_Per1_DftAsstTbl_Cnt_lgc() \
  (Rte_Inst_Ap_Assist->Assist_Per1_DftAsstTbl_Cnt_lgc->value)

# define Rte_IRead_Assist_Per1_DutyCycleLevel_Uls_f32() \
  (Rte_Inst_Ap_Assist->Assist_Per1_DutyCycleLevel_Uls_f32->value)

# define Rte_IRead_Assist_Per1_DwnldAsstGain_Uls_f32() \
  (Rte_Inst_Ap_Assist->Assist_Per1_DwnldAsstGain_Uls_f32->value)

# define Rte_IRead_Assist_Per1_HwTrqHysAdd_HwNm_f32() \
  (Rte_Inst_Ap_Assist->Assist_Per1_HwTrqHysAdd_HwNm_f32->value)

# define Rte_IRead_Assist_Per1_HwTrq_HwNm_f32() \
  (Rte_Inst_Ap_Assist->Assist_Per1_HwTrq_HwNm_f32->value)

# define Rte_IRead_Assist_Per1_IpTrqOvr_HwNm_f32() \
  (Rte_Inst_Ap_Assist->Assist_Per1_IpTrqOvr_HwNm_f32->value)

# define Rte_IRead_Assist_Per1_VehSpd_Kph_f32() \
  (Rte_Inst_Ap_Assist->Assist_Per1_VehSpd_Kph_f32->value)

# define Rte_IRead_Assist_Per1_WIRCmdAmpBlnd_MtrNm_f32() \
  (Rte_Inst_Ap_Assist->Assist_Per1_WIRCmdAmpBlnd_MtrNm_f32->value)

# define Rte_IWrite_Assist_Per1_BaseAssistCmd_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_Assist->Assist_Per1_BaseAssistCmd_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_Assist_Per1_BaseAssistCmd_MtrNm_f32() \
  (&Rte_Inst_Ap_Assist->Assist_Per1_BaseAssistCmd_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FltInjection_SCom_FltInjection Rte_Call_Ap_Assist_FltInjection_SCom_FltInjection




# define RTE_START_SEC_AP_ASSIST_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: Assist_Per1
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
 *   Float Rte_IRead_Assist_Per1_AssistDDFactor_Uls_f32(void)
 *   Boolean Rte_IRead_Assist_Per1_DftAsstTbl_Cnt_lgc(void)
 *   Float Rte_IRead_Assist_Per1_DutyCycleLevel_Uls_f32(void)
 *   Float Rte_IRead_Assist_Per1_DwnldAsstGain_Uls_f32(void)
 *   Float Rte_IRead_Assist_Per1_HwTrqHysAdd_HwNm_f32(void)
 *   Float Rte_IRead_Assist_Per1_HwTrq_HwNm_f32(void)
 *   Float Rte_IRead_Assist_Per1_IpTrqOvr_HwNm_f32(void)
 *   Float Rte_IRead_Assist_Per1_VehSpd_Kph_f32(void)
 *   Float Rte_IRead_Assist_Per1_WIRCmdAmpBlnd_MtrNm_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_Assist_Per1_BaseAssistCmd_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_Assist_Per1_BaseAssistCmd_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FltInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ASSIST_APPL_CODE) Assist_Per1(void);

# define RTE_STOP_SEC_AP_ASSIST_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1343055366
#    error "The magic number of the generated file <C:/CMSynergy_Projects/Assist/utp/contract/Rte_Ap_Assist.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1343055366
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ASSIST_H */
