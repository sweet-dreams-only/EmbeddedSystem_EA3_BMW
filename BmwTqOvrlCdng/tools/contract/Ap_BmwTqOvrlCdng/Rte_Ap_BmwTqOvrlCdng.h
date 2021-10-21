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
 *          File:  Rte_Ap_BmwTqOvrlCdng.h
 *     Workspace:  C:/Synergy_EA3/working/BmwTqOvrlCdng/autosar
 *     SW-C Type:  Ap_BmwTqOvrlCdng
 *  Generated at:  Fri Jun  2 16:24:25 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_BmwTqOvrlCdng> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_BMWTQOVRLCDNG_H
# define _RTE_AP_BMWTQOVRLCDNG_H

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

typedef P2CONST(struct Rte_CDS_Ap_BmwTqOvrlCdng, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_DrvDynActive_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DrvgDynErrIfActv_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_DrvgDynIfSt_Cnt_u08 ((QU_SER_STMOM_STMOM_DV_ACT)128u)
# define Rte_InitValue_OpTrqOvRmpInEnable_Cnt_lgc ((Boolean)FALSE)
# define Rte_InitValue_OutpTqOvrl_MtrNm_f32 ((Float)0)
# define Rte_InitValue_SerlComTarSteerTqDrvrActr_MtrNm_f32 ((Float)0)
# define Rte_InitValue_VehicleSpeed_Kph_f32 ((Float)0)


# define RTE_START_SEC_CODE
# include "MemMap.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ap_BmwTqOvrlCdng_FaultInjection_SCom_FltInjection(P2VAR(Float, AUTOMATIC, RTE_AP_BMWTQOVRLCDNG_APPL_VAR) SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum);

# define RTE_STOP_SEC_CODE
# include "MemMap.h"



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_BmwTqOvrlCdng_Per1_DrvDynActive_Cnt_lgc() \
  (Rte_Inst_Ap_BmwTqOvrlCdng->BmwTqOvrlCdng_Per1_DrvDynActive_Cnt_lgc->value)

# define Rte_IRead_BmwTqOvrlCdng_Per1_DrvgDynErrIfActv_Cnt_lgc() \
  (Rte_Inst_Ap_BmwTqOvrlCdng->BmwTqOvrlCdng_Per1_DrvgDynErrIfActv_Cnt_lgc->value)

# define Rte_IRead_BmwTqOvrlCdng_Per1_DrvgDynIfSt_Cnt_u08() \
  (Rte_Inst_Ap_BmwTqOvrlCdng->BmwTqOvrlCdng_Per1_DrvgDynIfSt_Cnt_u08->value)

# define Rte_IRead_BmwTqOvrlCdng_Per1_OpTrqOvRmpInEnable_Cnt_lgc() \
  (Rte_Inst_Ap_BmwTqOvrlCdng->BmwTqOvrlCdng_Per1_OpTrqOvRmpInEnable_Cnt_lgc->value)

# define Rte_IRead_BmwTqOvrlCdng_Per1_SerlComTarSteerTqDrvrActr_MtrNm_f32() \
  (Rte_Inst_Ap_BmwTqOvrlCdng->BmwTqOvrlCdng_Per1_SerlComTarSteerTqDrvrActr_MtrNm_f32->value)

# define Rte_IRead_BmwTqOvrlCdng_Per1_VehicleSpeed_Kph_f32() \
  (Rte_Inst_Ap_BmwTqOvrlCdng->BmwTqOvrlCdng_Per1_VehicleSpeed_Kph_f32->value)

# define Rte_IWrite_BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32(data) \
  ( \
  Rte_Inst_Ap_BmwTqOvrlCdng->BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32->value = (data) \
  )

# define Rte_IWriteRef_BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32() \
  (&Rte_Inst_Ap_BmwTqOvrlCdng->BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32->value)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_FaultInjection_SCom_FltInjection Rte_Call_Ap_BmwTqOvrlCdng_FaultInjection_SCom_FltInjection




# define RTE_START_SEC_AP_BMWTQOVRLCDNG_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdng_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWTQOVRLCDNG_APPL_CODE) BmwTqOvrlCdng_Init1(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BmwTqOvrlCdng_Per1
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
 *   Boolean Rte_IRead_BmwTqOvrlCdng_Per1_DrvDynActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_BmwTqOvrlCdng_Per1_DrvgDynErrIfActv_Cnt_lgc(void)
 *   QU_SER_STMOM_STMOM_DV_ACT Rte_IRead_BmwTqOvrlCdng_Per1_DrvgDynIfSt_Cnt_u08(void)
 *   Boolean Rte_IRead_BmwTqOvrlCdng_Per1_OpTrqOvRmpInEnable_Cnt_lgc(void)
 *   Float Rte_IRead_BmwTqOvrlCdng_Per1_SerlComTarSteerTqDrvrActr_MtrNm_f32(void)
 *   Float Rte_IRead_BmwTqOvrlCdng_Per1_VehicleSpeed_Kph_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32(Float data)
 *   Float *Rte_IWriteRef_BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32(void)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FaultInjection_SCom_FltInjection(Float *SignalPath_Uls_f32, FltInjectionLocType LocationKey_Cnt_enum)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_BMWTQOVRLCDNG_APPL_CODE) BmwTqOvrlCdng_Per1(void);

# define RTE_STOP_SEC_AP_BMWTQOVRLCDNG_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1496443881
#    error "The magic number of the generated file <C:/Synergy_EA3/working/BmwTqOvrlCdng/tools/contract/Ap_BmwTqOvrlCdng/Rte_Ap_BmwTqOvrlCdng.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1496443881
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_BMWTQOVRLCDNG_H */
