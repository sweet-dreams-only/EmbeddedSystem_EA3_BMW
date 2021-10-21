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
 *          File:  Rte_Ap_EOTActuatorMng.h
 *     Workspace:  C:/_swb/CBD/EOTActuatorMng-cz7lt6/EOTActuatorMng/autosar
 *     SW-C Type:  Ap_EOTActuatorMng
 *  Generated at:  Thu May 28 12:53:56 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_EOTActuatorMng> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_EOTACTUATORMNG_H
# define _RTE_AP_EOTACTUATORMNG_H

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

typedef P2CONST(struct Rte_CDS_Ap_EOTActuatorMng, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_AssistEOTDamping_MtrNm_f32 ((Float)0)
# define Rte_InitValue_AssistEOTGain_Uls_f32 ((Float)1)
# define Rte_InitValue_AssistEOTLimit_MtrNm_f32 ((Float)8.8)
# define Rte_InitValue_CcwEOT_HwDeg_f32 ((Float)0)
# define Rte_InitValue_CcwFound_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_CwEOT_HwDeg_f32 ((Float)0)
# define Rte_InitValue_CwFound_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_EOTDisable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_HandWheelAuth_Uls_f32 ((Float)0)
# define Rte_InitValue_HandWheelPos_HwDeg_f32 ((Float)0)
# define Rte_InitValue_HwTorque_HwNm_f32 ((Float)0)
# define Rte_InitValue_MotorVel_MtrRadpS_f32 ((Float)0)
# define Rte_InitValue_OutputRampMultLtd_Uls_f32 ((Float)0)
# define Rte_InitValue_PreLimitTorque_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_EOTActuatorMng_Per1_CcwEOT_HwDeg_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_CcwEOT_HwDeg_f32->value)

# define Rte_IRead_EOTActuatorMng_Per1_CcwFound_Cnt_lgc() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_CcwFound_Cnt_lgc->value)

# define Rte_IRead_EOTActuatorMng_Per1_CwEOT_HwDeg_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_CwEOT_HwDeg_f32->value)

# define Rte_IRead_EOTActuatorMng_Per1_CwFound_Cnt_lgc() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_CwFound_Cnt_lgc->value)

# define Rte_IRead_EOTActuatorMng_Per1_EOTDisable_Cnt_lgc() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_EOTDisable_Cnt_lgc->value)

# define Rte_IRead_EOTActuatorMng_Per1_HandWheelAuth_Uls_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_HandWheelAuth_Uls_f32->value)

# define Rte_IRead_EOTActuatorMng_Per1_HandWheelPos_HwDeg_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_HandWheelPos_HwDeg_f32->value)

# define Rte_IRead_EOTActuatorMng_Per1_HwTorque_HwNm_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_HwTorque_HwNm_f32->value)

# define Rte_IRead_EOTActuatorMng_Per1_MotorVel_MtrRadpS_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_MotorVel_MtrRadpS_f32->value)

# define Rte_IRead_EOTActuatorMng_Per1_OutputRampMultLtd_Uls_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_OutputRampMultLtd_Uls_f32->value)

# define Rte_IRead_EOTActuatorMng_Per1_PreLimitTorque_MtrNm_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_PreLimitTorque_MtrNm_f32->value)

# define Rte_IRead_EOTActuatorMng_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_EOTActuatorMng_Per1_AssistEOTDamping_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_AssistEOTDamping_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_EOTActuatorMng_Per1_AssistEOTDamping_MtrNm_f32() \
  (&Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_AssistEOTDamping_MtrNm_f32->value)

# define Rte_IWrite_EOTActuatorMng_Per1_AssistEOTGain_Uls_f32(data) \
  ( \
  Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_AssistEOTGain_Uls_f32->value = (data) \
  )

# define Rte_IWriteRef_EOTActuatorMng_Per1_AssistEOTGain_Uls_f32() \
  (&Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_AssistEOTGain_Uls_f32->value)

# define Rte_IWrite_EOTActuatorMng_Per1_AssistEOTLimit_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_AssistEOTLimit_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_EOTActuatorMng_Per1_AssistEOTLimit_MtrNm_f32() \
  (&Rte_Inst_Ap_EOTActuatorMng->EOTActuatorMng_Per1_AssistEOTLimit_MtrNm_f32->value)




# define RTE_START_SEC_AP_EOTACTUATORMNG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: EOTActuatorMng_Per1
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
 *   Float Rte_IRead_EOTActuatorMng_Per1_CcwEOT_HwDeg_f32(void)
 *   Boolean Rte_IRead_EOTActuatorMng_Per1_CcwFound_Cnt_lgc(void)
 *   Float Rte_IRead_EOTActuatorMng_Per1_CwEOT_HwDeg_f32(void)
 *   Boolean Rte_IRead_EOTActuatorMng_Per1_CwFound_Cnt_lgc(void)
 *   Boolean Rte_IRead_EOTActuatorMng_Per1_EOTDisable_Cnt_lgc(void)
 *   Float Rte_IRead_EOTActuatorMng_Per1_HandWheelAuth_Uls_f32(void)
 *   Float Rte_IRead_EOTActuatorMng_Per1_HandWheelPos_HwDeg_f32(void)
 *   Float Rte_IRead_EOTActuatorMng_Per1_HwTorque_HwNm_f32(void)
 *   Float Rte_IRead_EOTActuatorMng_Per1_MotorVel_MtrRadpS_f32(void)
 *   Float Rte_IRead_EOTActuatorMng_Per1_OutputRampMultLtd_Uls_f32(void)
 *   Float Rte_IRead_EOTActuatorMng_Per1_PreLimitTorque_MtrNm_f32(void)
 *   Float Rte_IRead_EOTActuatorMng_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_EOTActuatorMng_Per1_AssistEOTDamping_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_EOTActuatorMng_Per1_AssistEOTDamping_MtrNm_f32(void)
 *   void Rte_IWrite_EOTActuatorMng_Per1_AssistEOTGain_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_EOTActuatorMng_Per1_AssistEOTGain_Uls_f32(void)
 *   void Rte_IWrite_EOTActuatorMng_Per1_AssistEOTLimit_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_EOTActuatorMng_Per1_AssistEOTLimit_MtrNm_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_EOTACTUATORMNG_APPL_CODE) EOTActuatorMng_Per1(void);

# define RTE_STOP_SEC_AP_EOTACTUATORMNG_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1390570683
#    error "The magic number of the generated file <C:/Users/nzt9hv/Documents/Synergy/ccm_wa/ESG_Dev_65/EOTActuatorMng-nzt9hv/EOTActuatorMng/utp/contract/Ap_EOTActuatorMng/Rte_Ap_EOTActuatorMng.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1390570683
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_EOTACTUATORMNG_H */
