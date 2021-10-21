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
 *          File:  Rte_Ap_SignlCondn.h
 *     Workspace:  C:/SynergyEA3/Working/SgnlCond/autosar
 *     SW-C Type:  Ap_SignlCondn
 *  Generated at:  Wed Apr  6 13:32:18 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_SignlCondn> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_SIGNLCONDN_H
# define _RTE_AP_SIGNLCONDN_H

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

typedef P2CONST(struct Rte_CDS_Ap_SignlCondn, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_EstimdLatAcce_MpSecSq_f32 ((Float)0)
# define Rte_InitValue_EstimdLatAcceValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SrlComVehLatAccel_MpSecSq_f32 ((Float)0)
# define Rte_InitValue_SrlComVehLatAccelValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SrlComVehLonAccel_MpSecSq_f32 ((Float)0)
# define Rte_InitValue_SrlComVehLonAccelValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SrlComVehSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_SrlComVehSpeedValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_SrlComVehYawRate_DegpS_f32 ((Float)0)
# define Rte_InitValue_SrlComVehYawRateValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleLatAcceValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleLatAccel_MpSecSq_f32 ((Float)0)
# define Rte_InitValue_VehicleLonAccel_KphpS_f32 ((Float)0)
# define Rte_InitValue_VehicleLonAccelValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeedValid_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_VehicleYawRate_DegpS_f32 ((Float)0)
# define Rte_InitValue_VehicleYawRateValid_Cnt_lgc ((Boolean)FALSE)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_SignlCondn_FaultInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_SIGNLCONDN_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_SignlCondn_Per1_SrlComVehLatAccelValid_Cnt_lgc() \
  (Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_SrlComVehLatAccelValid_Cnt_lgc->value)

# define Rte_IRead_SignlCondn_Per1_SrlComVehLatAccel_MpSecSq_f32() \
  (Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_SrlComVehLatAccel_MpSecSq_f32->value)

# define Rte_IRead_SignlCondn_Per1_SrlComVehLonAccelValid_Cnt_lgc() \
  (Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_SrlComVehLonAccelValid_Cnt_lgc->value)

# define Rte_IRead_SignlCondn_Per1_SrlComVehLonAccel_MpSecSq_f32() \
  (Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_SrlComVehLonAccel_MpSecSq_f32->value)

# define Rte_IRead_SignlCondn_Per1_SrlComVehSpeedValid_Cnt_lgc() \
  (Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_SrlComVehSpeedValid_Cnt_lgc->value)

# define Rte_IRead_SignlCondn_Per1_SrlComVehSpeed_Kph_f32() \
  (Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_SrlComVehSpeed_Kph_f32->value)

# define Rte_IRead_SignlCondn_Per1_SrlComVehYawRateValid_Cnt_lgc() \
  (Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_SrlComVehYawRateValid_Cnt_lgc->value)

# define Rte_IRead_SignlCondn_Per1_SrlComVehYawRate_DegpS_f32() \
  (Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_SrlComVehYawRate_DegpS_f32->value)

# define Rte_IWrite_SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc->value)

# define Rte_IWrite_SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32->value)

# define Rte_IWrite_SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc->value)

# define Rte_IWrite_SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32->value)

# define Rte_IWrite_SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc->value)

# define Rte_IWrite_SignlCondn_Per1_VehicleLonAccel_KphpS_f32(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleLonAccel_KphpS_f32->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_VehicleLonAccel_KphpS_f32() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleLonAccel_KphpS_f32->value)

# define Rte_IWrite_SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc->value)

# define Rte_IWrite_SignlCondn_Per1_VehicleSpeed_Kph_f32(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleSpeed_Kph_f32->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_VehicleSpeed_Kph_f32() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc->value)

# define Rte_IWrite_SignlCondn_Per1_VehicleYawRate_DegpS_f32(data) \
  ( \
  Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleYawRate_DegpS_f32->value = (data) \
  )

# define Rte_IWriteRef_SignlCondn_Per1_VehicleYawRate_DegpS_f32() \
  (&Rte_Inst_Ap_SignlCondn->SignlCondn_Per1_VehicleYawRate_DegpS_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FaultInjection_SCom_FltInjection Rte_Call_Ap_SignlCondn_FaultInjection_SCom_FltInjection




# define RTE_START_SEC_AP_SIGNLCONDN_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: SignlCondn_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SIGNLCONDN_APPL_CODE) SignlCondn_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SignlCondn_Per1
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
 *   Boolean Rte_IRead_SignlCondn_Per1_SrlComVehLatAccelValid_Cnt_lgc(void)
 *   Float Rte_IRead_SignlCondn_Per1_SrlComVehLatAccel_MpSecSq_f32(void)
 *   Boolean Rte_IRead_SignlCondn_Per1_SrlComVehLonAccelValid_Cnt_lgc(void)
 *   Float Rte_IRead_SignlCondn_Per1_SrlComVehLonAccel_MpSecSq_f32(void)
 *   Boolean Rte_IRead_SignlCondn_Per1_SrlComVehSpeedValid_Cnt_lgc(void)
 *   Float Rte_IRead_SignlCondn_Per1_SrlComVehSpeed_Kph_f32(void)
 *   Boolean Rte_IRead_SignlCondn_Per1_SrlComVehYawRateValid_Cnt_lgc(void)
 *   Float Rte_IRead_SignlCondn_Per1_SrlComVehYawRate_DegpS_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_EstimdLatAcceValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_EstimdLatAcce_MpSecSq_f32(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_VehicleLatAcceValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_VehicleLatAccel_MpSecSq_f32(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_VehicleLonAccelValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleLonAccel_KphpS_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_VehicleLonAccel_KphpS_f32(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_VehicleSpeedValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleSpeed_Kph_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_VehicleSpeed_Kph_f32(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_SignlCondn_Per1_VehicleYawRateValid_Cnt_lgc(void)
 *   void Rte_IWrite_SignlCondn_Per1_VehicleYawRate_DegpS_f32(Float data)
 *   Float *Rte_IWriteRef_SignlCondn_Per1_VehicleYawRate_DegpS_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SIGNLCONDN_APPL_CODE) SignlCondn_Per1(void);

# define RTE_STOP_SEC_AP_SIGNLCONDN_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1459973385
#    error "The magic number of the generated file <C:/SynergyEA3/Working/SgnlCond/tools/contract/Ap_SignlCondn/Rte_Ap_SignlCondn.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1459973385
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_SIGNLCONDN_H */
