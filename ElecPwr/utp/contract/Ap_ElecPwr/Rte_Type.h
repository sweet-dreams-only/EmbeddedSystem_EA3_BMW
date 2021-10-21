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
 *          File:  Rte_Type.h
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/ElecPwr-nzt9hv/ElecPwr/autosar
 *     SW-C Type:  Ap_ElecPwr
 *  Generated at:  Wed Feb  6 13:14:13 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit ((Float)-FLT_MAX)
# define Float_UpperLimit ((Float)FLT_MAX)

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define SInt16_LowerLimit ((SInt16)-32768)
# define SInt16_UpperLimit ((SInt16)32767)

# define Rte_TypeDef_DT_SinTanLkpTbl_f32
typedef Float DT_SinTanLkpTbl_f32[193];


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_Boolean
typedef boolean Boolean;

#  define Rte_TypeDef_Double
typedef float64 Double;
#  define Double_LowerLimit ((Double)-DBL_MAX)
#  define Double_UpperLimit ((Double)DBL_MAX)

#  define Rte_TypeDef_SInt32
typedef sint32 SInt32;
#  define SInt32_LowerLimit ((SInt32)-2147483648)
#  define SInt32_UpperLimit ((SInt32)2147483647)

#  define Rte_TypeDef_SInt4
typedef sint8 SInt4;
#  define SInt4_LowerLimit ((SInt4)-8)
#  define SInt4_UpperLimit ((SInt4)7)

#  define Rte_TypeDef_SInt8
typedef sint8 SInt8;
#  define SInt8_LowerLimit ((SInt8)-128)
#  define SInt8_UpperLimit ((SInt8)127)

#  define Rte_TypeDef_UInt16
typedef uint16 UInt16;
#  define UInt16_LowerLimit ((UInt16)0u)
#  define UInt16_UpperLimit ((UInt16)65535u)

#  define Rte_TypeDef_UInt32
typedef uint32 UInt32;
#  define UInt32_LowerLimit ((UInt32)0u)
#  define UInt32_UpperLimit ((UInt32)4294967295u)

#  define Rte_TypeDef_UInt4
typedef uint8 UInt4;
#  define UInt4_LowerLimit ((UInt4)0u)
#  define UInt4_UpperLimit ((UInt4)15u)

#  define Rte_TypeDef_UInt8
typedef uint8 UInt8;
#  define UInt8_LowerLimit ((UInt8)0u)
#  define UInt8_UpperLimit ((UInt8)255u)

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1)
#  define D_ONE_ULS_F32 ((Float)1)
# endif

# if (defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (defined D_VECUMIN_VOLTS_F32)
#  if (!defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (RTE_CONST_D_VECUMIN_VOLTS_F32 != 5)
#   error "Constant value <D_VECUMIN_VOLTS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_VECUMIN_VOLTS_F32 (5)
#  define D_VECUMIN_VOLTS_F32 ((Float)5)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0)
#  define D_ZERO_ULS_F32 ((Float)0)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S16) || (defined D_ZERO_CNT_S16)
#  if (!defined RTE_CONST_D_ZERO_CNT_S16) || (RTE_CONST_D_ZERO_CNT_S16 != 0)
#   error "Constant value <D_ZERO_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S16 (0)
#  define D_ZERO_CNT_S16 ((SInt16)0)
# endif

# if defined T_SINELKPTBL_ULS_F32
#  error "Constant value <T_SINELKPTBL_ULS_F32> conflicts with an already defined symbol."
# else
#  define T_SINELKPTBL_ULS_F32 (Rte_T_SINELKPTBL_ULS_F32)
# endif
extern CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_SINELKPTBL_ULS_F32;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  SInt16 value;
} Rte_DE_SInt16;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_ElecPwr
{
  /* Data Handles section */
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_ElecPower_Watts_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_EstR_Ohm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_ModIdx_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_SupplyCur_Amp_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_TermA_Volt_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_TermXq_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_TermZ_Uls_f32;
  P2VAR(Rte_DE_SInt16, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_UncorrPhsAdv_Cnt_s16;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_ELECPWR_APPL_VAR) ElecPwr_Per1_Vecu_Volt_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_ElecPwr, RTE_CONST, RTE_CONST) Rte_Inst_Ap_ElecPwr;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1360169204
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/ElecPwr-nzt9hv/ElecPwr/utp/contract/Ap_ElecPwr/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1360169204
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
