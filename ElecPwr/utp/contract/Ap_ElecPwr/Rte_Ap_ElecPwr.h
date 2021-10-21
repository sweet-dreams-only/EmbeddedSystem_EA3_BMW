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
 *          File:  Rte_Ap_ElecPwr.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/ElecPwr-nzt9hv/ElecPwr/autosar
 *     SW-C Type:  Ap_ElecPwr
 *  Generated at:  Wed Feb  6 13:14:13 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Application header file for SW-C <Ap_ElecPwr> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_AP_ELECPWR_H
# define _RTE_AP_ELECPWR_H

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

typedef P2CONST(struct Rte_CDS_Ap_ElecPwr, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_ElecPower_Watts_f32 ((Float)0)
# define Rte_InitValue_EstR_Ohm_f32 ((Float)0)
# define Rte_InitValue_ModIdx_Uls_f32 ((Float)0)
# define Rte_InitValue_SupplyCur_Amp_f32 ((Float)0)
# define Rte_InitValue_TermA_Volt_f32 ((Float)0)
# define Rte_InitValue_TermXq_Uls_f32 ((Float)0)
# define Rte_InitValue_TermZ_Uls_f32 ((Float)0)
# define Rte_InitValue_UncorrPhsAdv_Cnt_s16 ((SInt16)0)
# define Rte_InitValue_Vecu_Volt_f32 ((Float)5)



/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

# define Rte_IRead_ElecPwr_Per1_EstR_Ohm_f32() \
  (Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_EstR_Ohm_f32->value)

# define Rte_IRead_ElecPwr_Per1_ModIdx_Uls_f32() \
  (Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_ModIdx_Uls_f32->value)

# define Rte_IRead_ElecPwr_Per1_TermA_Volt_f32() \
  (Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_TermA_Volt_f32->value)

# define Rte_IRead_ElecPwr_Per1_TermXq_Uls_f32() \
  (Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_TermXq_Uls_f32->value)

# define Rte_IRead_ElecPwr_Per1_TermZ_Uls_f32() \
  (Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_TermZ_Uls_f32->value)

# define Rte_IRead_ElecPwr_Per1_UncorrPhsAdv_Cnt_s16() \
  (Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_UncorrPhsAdv_Cnt_s16->value)

# define Rte_IRead_ElecPwr_Per1_Vecu_Volt_f32() \
  (Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_Vecu_Volt_f32->value)

# define Rte_IWrite_ElecPwr_Per1_ElecPower_Watts_f32(data) \
  ( \
  Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_ElecPower_Watts_f32->value = (data) \
  )

# define Rte_IWriteRef_ElecPwr_Per1_ElecPower_Watts_f32() \
  (&Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_ElecPower_Watts_f32->value)

# define Rte_IWrite_ElecPwr_Per1_SupplyCur_Amp_f32(data) \
  ( \
  Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_SupplyCur_Amp_f32->value = (data) \
  )

# define Rte_IWriteRef_ElecPwr_Per1_SupplyCur_Amp_f32() \
  (&Rte_Inst_Ap_ElecPwr->ElecPwr_Per1_SupplyCur_Amp_f32->value)




# define RTE_START_SEC_AP_ELECPWR_APPL_CODE
# include "MemMap.h"


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ElecPwr_Per1
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
 *   Float Rte_IRead_ElecPwr_Per1_EstR_Ohm_f32(void)
 *   Float Rte_IRead_ElecPwr_Per1_ModIdx_Uls_f32(void)
 *   Float Rte_IRead_ElecPwr_Per1_TermA_Volt_f32(void)
 *   Float Rte_IRead_ElecPwr_Per1_TermXq_Uls_f32(void)
 *   Float Rte_IRead_ElecPwr_Per1_TermZ_Uls_f32(void)
 *   SInt16 Rte_IRead_ElecPwr_Per1_UncorrPhsAdv_Cnt_s16(void)
 *   Float Rte_IRead_ElecPwr_Per1_Vecu_Volt_f32(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_ElecPwr_Per1_ElecPower_Watts_f32(Float data)
 *   Float *Rte_IWriteRef_ElecPwr_Per1_ElecPower_Watts_f32(void)
 *   void Rte_IWrite_ElecPwr_Per1_SupplyCur_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_ElecPwr_Per1_SupplyCur_Amp_f32(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_ELECPWR_APPL_CODE) ElecPwr_Per1(void);

# define RTE_STOP_SEC_AP_ELECPWR_APPL_CODE
# include "MemMap.h"

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1360169204
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/ElecPwr-nzt9hv/ElecPwr/utp/contract/Ap_ElecPwr/Rte_Ap_ElecPwr.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1360169204
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_AP_ELECPWR_H */
