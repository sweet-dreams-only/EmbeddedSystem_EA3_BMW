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
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-UKL_F45/Xcp/autosar/Ap_ApXcp.dcf
 *     SW-C Type:  Ap_ApXcp
 *  Generated at:  Mon Oct 28 11:23:27 2013
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

#  define Rte_TypeDef_Float
typedef float32 Float;
#  define Float_LowerLimit ((Float)-FLT_MAX)
#  define Float_UpperLimit ((Float)FLT_MAX)

#  define Rte_TypeDef_SInt16
typedef sint16 SInt16;
#  define SInt16_LowerLimit ((SInt16)-32768)
#  define SInt16_UpperLimit ((SInt16)32767)

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
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit (0U)
# define UInt16_UpperLimit (65535U)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit (0U)
# define UInt32_UpperLimit (4294967295U)

# define Rte_TypeDef_TuningSessionAddrPtrEnum
typedef uint8 TuningSessionAddrPtrEnum;
# define TuningSessionAddrPtrEnum_LowerLimit (0U)
# define TuningSessionAddrPtrEnum_UpperLimit (255U)
# if (defined RTE_CONST_TUN_SESSION_PTR_PERS) || (defined TUN_SESSION_PTR_PERS)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_PERS) || (RTE_CONST_TUN_SESSION_PTR_PERS != 0U)
#   error "Enumeration constant <TUN_SESSION_PTR_PERS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_PERS (0U)
#  define TUN_SESSION_PTR_PERS (0U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETS) || (defined TUN_SESSION_PTR_SETS)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETS) || (RTE_CONST_TUN_SESSION_PTR_SETS != 1U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETS> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETS (1U)
#  define TUN_SESSION_PTR_SETS (1U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_COMMON) || (defined TUN_SESSION_PTR_COMMON)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_COMMON) || (RTE_CONST_TUN_SESSION_PTR_COMMON != 2U)
#   error "Enumeration constant <TUN_SESSION_PTR_COMMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_COMMON (2U)
#  define TUN_SESSION_PTR_COMMON (2U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETANDPER) || (defined TUN_SESSION_PTR_SETANDPER)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETANDPER) || (RTE_CONST_TUN_SESSION_PTR_SETANDPER != 3U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETANDPER> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETANDPER (3U)
#  define TUN_SESSION_PTR_SETANDPER (3U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON) || (defined TUN_SESSION_PTR_SETANDPERANDCOMMON)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON) || (RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON != 4U)
#   error "Enumeration constant <TUN_SESSION_PTR_SETANDPERANDCOMMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_SETANDPERANDCOMMON (4U)
#  define TUN_SESSION_PTR_SETANDPERANDCOMMON (4U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_CUSTSEG) || (defined TUN_SESSION_PTR_CUSTSEG)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_CUSTSEG) || (RTE_CONST_TUN_SESSION_PTR_CUSTSEG != 16U)
#   error "Enumeration constant <TUN_SESSION_PTR_CUSTSEG> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_CUSTSEG (16U)
#  define TUN_SESSION_PTR_CUSTSEG (16U)
# endif
# if (defined RTE_CONST_TUN_SESSION_PTR_DISABLED) || (defined TUN_SESSION_PTR_DISABLED)
#  if (!defined RTE_CONST_TUN_SESSION_PTR_DISABLED) || (RTE_CONST_TUN_SESSION_PTR_DISABLED != 255U)
#   error "Enumeration constant <TUN_SESSION_PTR_DISABLED> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TUN_SESSION_PTR_DISABLED (255U)
#  define TUN_SESSION_PTR_DISABLED (255U)
# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

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
  UInt16 value;
} Rte_DE_UInt16;

typedef struct
{
  UInt32 value;
} Rte_DE_UInt32;

typedef struct
{
  TuningSessionAddrPtrEnum value;
} Rte_DE_TuningSessionAddrPtrEnum;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_ApXcp
{
  /* Data Handles section */
  P2VAR(Rte_DE_UInt32, TYPEDEF, RTE_AP_APXCP_APPL_VAR) ApXcp_Per1_ActiveTunOvrPtrAddr_Cnt_u32;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_APXCP_APPL_VAR) ApXcp_Per1_ActiveTunPers_Cnt_u16;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_APXCP_APPL_VAR) ApXcp_Per1_ActiveTunSet_Cnt_u16;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_APXCP_APPL_VAR) ApXcp_Per1_DesiredTunPers_Cnt_u16;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_APXCP_APPL_VAR) ApXcp_Per1_DesiredTunSet_Cnt_u16;
  P2VAR(Rte_DE_TuningSessionAddrPtrEnum, TYPEDEF, RTE_AP_APXCP_APPL_VAR) ApXcp_Per1_TuningSessionActPtr_Cnt_u8;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_ApXcp, RTE_CONST, RTE_CONST) Rte_Inst_Ap_ApXcp;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1357927880
#    error "The magic number of the generated file <C:/ccm_wa/EPS/570/I410/Xcp/utp/contract/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1357927880
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
