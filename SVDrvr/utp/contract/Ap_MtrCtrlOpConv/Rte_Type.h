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
 *          File:  Rte_Type.h
 *     Workspace:  C:/_swb/CBD/SVDrvr-cz7lt6/SVDrvr/autosar/SVDrvr.dcf
 *     SW-C Type:  Ap_MtrCtrlOpConv
 *  Generated at:  Thu Feb  7 15:34:24 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
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
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define SInt16_LowerLimit (-32768)
# define SInt16_UpperLimit (32767)

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit (0U)
# define UInt16_UpperLimit (65535U)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit (0U)
# define UInt32_UpperLimit (4294967295U)


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_FETFAULTTYPE_ENUM
typedef uint8 FETFAULTTYPE_ENUM;
#  define FETFAULTTYPE_ENUM_LowerLimit (0U)
#  define FETFAULTTYPE_ENUM_UpperLimit (255U)
#  if (defined RTE_CONST_NOFAULT) || (defined NOFAULT)
#   if (!defined RTE_CONST_NOFAULT) || (RTE_CONST_NOFAULT != 0U)
#    error "Enumeration constant <NOFAULT> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_NOFAULT (0U)
#   define NOFAULT (0U)
#  endif
#  if (defined RTE_CONST_LOWER) || (defined LOWER)
#   if (!defined RTE_CONST_LOWER) || (RTE_CONST_LOWER != 1U)
#    error "Enumeration constant <LOWER> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_LOWER (1U)
#   define LOWER (1U)
#  endif
#  if (defined RTE_CONST_UPPER) || (defined UPPER)
#   if (!defined RTE_CONST_UPPER) || (RTE_CONST_UPPER != 2U)
#    error "Enumeration constant <UPPER> conflicts with another constant."
#   endif
#  else
#   define RTE_CONST_UPPER (2U)
#   define UPPER (2U)
#  endif

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# if (defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (defined D_MTRTRQCMDHILMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 != 8.8F)
#   error "Constant value <D_MTRTRQCMDHILMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
#  define D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S16) || (defined D_ZERO_CNT_S16)
#  if (!defined RTE_CONST_D_ZERO_CNT_S16) || (RTE_CONST_D_ZERO_CNT_S16 != 0)
#   error "Constant value <D_ZERO_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S16 (0)
#  define D_ZERO_CNT_S16 (0)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U16) || (defined D_ZERO_CNT_U16)
#  if (!defined RTE_CONST_D_ZERO_CNT_U16) || (RTE_CONST_D_ZERO_CNT_U16 != 0U)
#   error "Constant value <D_ZERO_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U16 (0U)
#  define D_ZERO_CNT_U16 (0U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0U)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0U)
#  define D_ZERO_CNT_U32 (0U)
# endif



/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  UInt32 value;
} Rte_DE_UInt32;

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  SInt16 value;
} Rte_DE_SInt16;

typedef struct
{
  UInt16 value;
} Rte_DE_UInt16;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_MtrCtrlOpConv
{
  /* Data Handles section */
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_CommutationOffset_Cnt_u16;
  P2VAR(Rte_DE_UInt32, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_CurrentGainSvc_Cnt_b32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_DeadTimeComp_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_ModulationIndexFinal_Uls_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_ModulationIndex_Uls_f32;
  P2VAR(Rte_DE_SInt16, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_MtrTrqCmdSign_Cnt_s16;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_PhaseAdvanceFinal_Cnt_u16;
  P2VAR(Rte_DE_SInt16, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_PhaseAdvance_Cnt_s16;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_MTRCTRLOPCONV_APPL_VAR) MtrCtrlOpConv_Per1_TorqueCmdMRF_MtrNm_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_MtrCtrlOpConv, RTE_CONST, RTE_CONST) Rte_Inst_Ap_MtrCtrlOpConv;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1351626202
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/SVDrvr-nzt9hv/SVDrvr/utp/contract/Ap_MtrCtrlOpConv/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1351626202
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
