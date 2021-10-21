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
 *     Workspace:  C:/SynergyWorkArea/Working/BmwHaptcFb/autosar
 *     SW-C Type:  Ap_BmwHaptcFb
 *  Generated at:  Thu Jul 28 10:27:57 2016
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

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;
# define UInt8_LowerLimit ((UInt8)0u)
# define UInt8_UpperLimit ((UInt8)255u)


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

# endif


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
typedef uint8 Rte_ModeType_StaMd_Mode;

# define RTE_MODE_StaMd_Mode_DISABLE ((Rte_ModeType_StaMd_Mode)0)
# define RTE_MODE_StaMd_Mode_OFF ((Rte_ModeType_StaMd_Mode)1)
# define RTE_MODE_StaMd_Mode_OPERATE ((Rte_ModeType_StaMd_Mode)2)
# define RTE_MODE_StaMd_Mode_WARMINIT ((Rte_ModeType_StaMd_Mode)3)
# define RTE_TRANSITION_StaMd_Mode ((Rte_ModeType_StaMd_Mode)4)


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

# if (defined RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32) || (defined D_MTRRAMPRATEFALL_MTRNMPS_F32)
#  if (!defined RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32) || (RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32 != -4400)
#   error "Constant value <D_MTRRAMPRATEFALL_MTRNMPS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRRAMPRATEFALL_MTRNMPS_F32 (-4400)
#  define D_MTRRAMPRATEFALL_MTRNMPS_F32 ((Float)-4400)
# endif

# if (defined RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32) || (defined D_MTRRAMPRATERISE_MTRNMPS_F32)
#  if (!defined RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32) || (RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32 != 4400)
#   error "Constant value <D_MTRRAMPRATERISE_MTRNMPS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRRAMPRATERISE_MTRNMPS_F32 (4400)
#  define D_MTRRAMPRATERISE_MTRNMPS_F32 ((Float)4400)
# endif

# if (defined RTE_CONST_D_TRQOSCFREQINIT_HZ_F32) || (defined D_TRQOSCFREQINIT_HZ_F32)
#  if (!defined RTE_CONST_D_TRQOSCFREQINIT_HZ_F32) || (RTE_CONST_D_TRQOSCFREQINIT_HZ_F32 != 50)
#   error "Constant value <D_TRQOSCFREQINIT_HZ_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRQOSCFREQINIT_HZ_F32 (50)
#  define D_TRQOSCFREQINIT_HZ_F32 ((Float)50)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0)
#  define D_ZERO_ULS_F32 ((Float)0)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U16) || (defined D_ONE_CNT_U16)
#  if (!defined RTE_CONST_D_ONE_CNT_U16) || (RTE_CONST_D_ONE_CNT_U16 != 1u)
#   error "Constant value <D_ONE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U16 (1u)
#  define D_ONE_CNT_U16 ((UInt16)1u)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U16) || (defined D_ZERO_CNT_U16)
#  if (!defined RTE_CONST_D_ZERO_CNT_U16) || (RTE_CONST_D_ZERO_CNT_U16 != 0u)
#   error "Constant value <D_ZERO_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U16 (0u)
#  define D_ZERO_CNT_U16 ((UInt16)0u)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U8) || (defined D_ONE_CNT_U8)
#  if (!defined RTE_CONST_D_ONE_CNT_U8) || (RTE_CONST_D_ONE_CNT_U8 != 1u)
#   error "Constant value <D_ONE_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U8 (1u)
#  define D_ONE_CNT_U8 ((UInt8)1u)
# endif



/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;

typedef struct
{
  UInt16 value;
} Rte_DE_UInt16;

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  UInt8 value;
} Rte_DE_UInt8;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_BmwHaptcFb
{
  /* Data Handles section */
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_HaptcFbEnable_Cnt_lgc;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_HaptcFbIntenNr_Cnt_u16;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_HaptcFbIntenSigVld_Cnt_lgc;
  P2VAR(Rte_DE_UInt16, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_HaptcFbPatNr_Cnt_u16;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_HaptcFbPatSigVld_Cnt_lgc;
  P2VAR(Rte_DE_UInt8, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_HaptcFbSt_Cnt_u08;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_PostLimitTrq_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_PreLimitTrq_MtrNm_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_TrqOscActv_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_TrqOscAmp_MtrNm_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_TrqOscDCExceeded_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_TrqOscEnable_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_TrqOscFallingRampRate_MtrNmpS_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_TrqOscFreq_Hz_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_TrqOscRisngRampRate_MtrNmpS_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_VehicleSpeedValid_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWHAPTCFB_APPL_VAR) BmwHaptcFb_Per1_VehicleSpeed_Kph_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_BmwHaptcFb, RTE_CONST, RTE_CONST) Rte_Inst_Ap_BmwHaptcFb;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1469718012
#    error "The magic number of the generated file <C:/SynergyWorkArea/Working/BmwHaptcFb/tools/contract/Ap_BmwHaptcFb/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1469718012
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
