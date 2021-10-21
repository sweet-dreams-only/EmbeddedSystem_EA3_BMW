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
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LktoLkStr-nzt9hv/LktoLkStr/autosar
 *     SW-C Type:  Ap_LktoLkStr
 *  Generated at:  Sun Sep 23 09:51:49 2012
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

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit ((Float)-FLT_MAX)
# define Float_UpperLimit ((Float)FLT_MAX)

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit ((UInt16)0u)
# define UInt16_UpperLimit ((UInt16)65535u)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit ((UInt32)0u)
# define UInt32_UpperLimit ((UInt32)4294967295u)

# define Rte_TypeDef_LktoLkStrStateType
typedef uint8 LktoLkStrStateType;
# define LktoLkStrStateType_LowerLimit ((LktoLkStrStateType)0u)
# define LktoLkStrStateType_UpperLimit ((LktoLkStrStateType)7u)
# if (defined RTE_CONST_HOLD) || (defined HOLD)
#  if (!defined RTE_CONST_HOLD) || (RTE_CONST_HOLD != 0u)
#   error "Enumeration constant <HOLD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_HOLD (0u)
#  define HOLD ((LktoLkStrStateType)0u)
# endif
# if (defined RTE_CONST_POSANGVEL) || (defined POSANGVEL)
#  if (!defined RTE_CONST_POSANGVEL) || (RTE_CONST_POSANGVEL != 1u)
#   error "Enumeration constant <POSANGVEL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_POSANGVEL (1u)
#  define POSANGVEL ((LktoLkStrStateType)1u)
# endif
# if (defined RTE_CONST_POSMTRTRQ) || (defined POSMTRTRQ)
#  if (!defined RTE_CONST_POSMTRTRQ) || (RTE_CONST_POSMTRTRQ != 2u)
#   error "Enumeration constant <POSMTRTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_POSMTRTRQ (2u)
#  define POSMTRTRQ ((LktoLkStrStateType)2u)
# endif
# if (defined RTE_CONST_NEGANGVEL) || (defined NEGANGVEL)
#  if (!defined RTE_CONST_NEGANGVEL) || (RTE_CONST_NEGANGVEL != 3u)
#   error "Enumeration constant <NEGANGVEL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NEGANGVEL (3u)
#  define NEGANGVEL ((LktoLkStrStateType)3u)
# endif
# if (defined RTE_CONST_NEGMTRTRQ) || (defined NEGMTRTRQ)
#  if (!defined RTE_CONST_NEGMTRTRQ) || (RTE_CONST_NEGMTRTRQ != 4u)
#   error "Enumeration constant <NEGMTRTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_NEGMTRTRQ (4u)
#  define NEGMTRTRQ ((LktoLkStrStateType)4u)
# endif
# if (defined RTE_CONST_MOVETO) || (defined MOVETO)
#  if (!defined RTE_CONST_MOVETO) || (RTE_CONST_MOVETO != 5u)
#   error "Enumeration constant <MOVETO> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_MOVETO (5u)
#  define MOVETO ((LktoLkStrStateType)5u)
# endif
# if (defined RTE_CONST_DONE) || (defined DONE)
#  if (!defined RTE_CONST_DONE) || (RTE_CONST_DONE != 6u)
#   error "Enumeration constant <DONE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_DONE (6u)
#  define DONE ((LktoLkStrStateType)6u)
# endif
# if (defined RTE_CONST_TIMEOUT) || (defined TIMEOUT)
#  if (!defined RTE_CONST_TIMEOUT) || (RTE_CONST_TIMEOUT != 7u)
#   error "Enumeration constant <TIMEOUT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_TIMEOUT (7u)
#  define TIMEOUT ((LktoLkStrStateType)7u)
# endif


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_Double
typedef float64 Double;
#  define Double_LowerLimit ((Double)-DBL_MAX)
#  define Double_UpperLimit ((Double)DBL_MAX)

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

# if (defined RTE_CONST_D_FALSE_CNT_LGC) || (defined D_FALSE_CNT_LGC)
#  if (!defined RTE_CONST_D_FALSE_CNT_LGC) || (RTE_CONST_D_FALSE_CNT_LGC != FALSE)
#   error "Constant value <D_FALSE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FALSE_CNT_LGC (FALSE)
#  define D_FALSE_CNT_LGC ((Boolean)FALSE)
# endif

# if (defined RTE_CONST_D_2MS_SEC_F32) || (defined D_2MS_SEC_F32)
#  if (!defined RTE_CONST_D_2MS_SEC_F32) || (RTE_CONST_D_2MS_SEC_F32 != 0.002)
#   error "Constant value <D_2MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_SEC_F32 (0.002)
#  define D_2MS_SEC_F32 ((Float)0.002)
# endif

# if (defined RTE_CONST_D_2PI_ULS_F32) || (defined D_2PI_ULS_F32)
#  if (!defined RTE_CONST_D_2PI_ULS_F32) || (RTE_CONST_D_2PI_ULS_F32 != 6.2831853071796)
#   error "Constant value <D_2PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2PI_ULS_F32 (6.2831853071796)
#  define D_2PI_ULS_F32 ((Float)6.2831853071796)
# endif

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1)
#  define D_ONE_ULS_F32 ((Float)1)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0)
#  define D_ZERO_ULS_F32 ((Float)0)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0u)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0u)
#  define D_ZERO_CNT_U32 ((UInt32)0u)
# endif



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
  Boolean value;
} Rte_DE_Boolean;

typedef struct
{
  LktoLkStrStateType value;
} Rte_DE_LktoLkStrStateType;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_LktoLkStr
{
  /* Data Handles section */
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LKTOLKSTR_APPL_VAR) LktoLkStr_Per1_AlignedHwPosition_HwDeg_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_LKTOLKSTR_APPL_VAR) LktoLkStr_Per1_LrnPnCenterEnable_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LKTOLKSTR_APPL_VAR) LktoLkStr_Per1_LrnPnCntrCmd_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LKTOLKSTR_APPL_VAR) LktoLkStr_Per1_LrnPnCntrHwCenter_HwDeg_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LKTOLKSTR_APPL_VAR) LktoLkStr_Per1_LrnPnCntrHwTravel_HwDeg_f32;
  P2VAR(Rte_DE_LktoLkStrStateType, TYPEDEF, RTE_AP_LKTOLKSTR_APPL_VAR) LktoLkStr_Per1_LrnPnCntrState_Cnt_enum;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_LKTOLKSTR_APPL_VAR) LktoLkStr_Per1_MotorVelCRF_MtrRadpS_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_LktoLkStr, RTE_CONST, RTE_CONST) Rte_Inst_Ap_LktoLkStr;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1348403688
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/LktoLkStr-nzt9hv/LktoLkStr/utp/contract/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1348403688
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
