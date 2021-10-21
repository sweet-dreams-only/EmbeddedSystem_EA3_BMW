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
 *     Workspace:  C:/SynergyProjects/CBD/CtrldDisShtdn/autosar/Ap_CtrldDisShtdn.dcf
 *     SW-C Type:  Ap_CtrldDisShtdn
 *  Generated at:  Thu Jan 24 16:22:00 2013
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

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Double
typedef float64 Double;
# define Double_LowerLimit (-DBL_MAX)
# define Double_UpperLimit (DBL_MAX)

# define Rte_TypeDef_Float
typedef float32 Float;
# define Float_LowerLimit (-FLT_MAX)
# define Float_UpperLimit (FLT_MAX)

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define SInt16_LowerLimit (-32768)
# define SInt16_UpperLimit (32767)

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;
# define SInt32_LowerLimit (-2147483648)
# define SInt32_UpperLimit (2147483647)

# define Rte_TypeDef_SInt8
typedef sint8 SInt8;
# define SInt8_LowerLimit (-128)
# define SInt8_UpperLimit (127)

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define UInt16_LowerLimit (0U)
# define UInt16_UpperLimit (65535U)

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define UInt32_LowerLimit (0U)
# define UInt32_UpperLimit (4294967295U)

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;
# define UInt8_LowerLimit (0U)
# define UInt8_UpperLimit (255U)

# define Rte_TypeDef_DT_SinTanLkpTbl_f32
typedef Float DT_SinTanLkpTbl_f32[193];


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
typedef uint8 Rte_ModeType_StaMd_Mode;

# define RTE_MODE_StaMd_Mode_DISABLE (0U)
# define RTE_MODE_StaMd_Mode_OFF (1U)
# define RTE_MODE_StaMd_Mode_OPERATE (2U)
# define RTE_MODE_StaMd_Mode_WARMINIT (3U)
# define RTE_TRANSITION_StaMd_Mode (4U)


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

# if (defined RTE_CONST_D_FALSE_CNT_LGC) || (defined D_FALSE_CNT_LGC)
#  if (!defined RTE_CONST_D_FALSE_CNT_LGC) || (RTE_CONST_D_FALSE_CNT_LGC != FALSE)
#   error "Constant value <D_FALSE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FALSE_CNT_LGC (FALSE)
#  define D_FALSE_CNT_LGC (FALSE)
# endif

# if (defined RTE_CONST_D_TRUE_CNT_LGC) || (defined D_TRUE_CNT_LGC)
#  if (!defined RTE_CONST_D_TRUE_CNT_LGC) || (RTE_CONST_D_TRUE_CNT_LGC != TRUE)
#   error "Constant value <D_TRUE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRUE_CNT_LGC (TRUE)
#  define D_TRUE_CNT_LGC (TRUE)
# endif

# if (defined RTE_CONST_D_SFINVMILLI_ULS_F32) || (defined D_SFINVMILLI_ULS_F32)
#  if (!defined RTE_CONST_D_SFINVMILLI_ULS_F32) || (RTE_CONST_D_SFINVMILLI_ULS_F32 != 1000)
#   error "Constant value <D_SFINVMILLI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_SFINVMILLI_ULS_F32 (1000)
#  define D_SFINVMILLI_ULS_F32 (1000)
# endif

# if (defined RTE_CONST_D_180OVRPI_ULS_F32) || (defined D_180OVRPI_ULS_F32)
#  if (!defined RTE_CONST_D_180OVRPI_ULS_F32) || (RTE_CONST_D_180OVRPI_ULS_F32 != 57.295779513082F)
#   error "Constant value <D_180OVRPI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_180OVRPI_ULS_F32 (57.295779513082F)
#  define D_180OVRPI_ULS_F32 (57.295779513082F)
# endif

# if (defined RTE_CONST_D_2MS_SEC_F32) || (defined D_2MS_SEC_F32)
#  if (!defined RTE_CONST_D_2MS_SEC_F32) || (RTE_CONST_D_2MS_SEC_F32 != 0.002F)
#   error "Constant value <D_2MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_SEC_F32 (0.002F)
#  define D_2MS_SEC_F32 (0.002F)
# endif

# if (defined RTE_CONST_D_2PI_ULS_F32) || (defined D_2PI_ULS_F32)
#  if (!defined RTE_CONST_D_2PI_ULS_F32) || (RTE_CONST_D_2PI_ULS_F32 != 6.2831853071796F)
#   error "Constant value <D_2PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2PI_ULS_F32 (6.2831853071796F)
#  define D_2PI_ULS_F32 (6.2831853071796F)
# endif

# if (defined RTE_CONST_D_MSECPERSEC_ULS_F32) || (defined D_MSECPERSEC_ULS_F32)
#  if (!defined RTE_CONST_D_MSECPERSEC_ULS_F32) || (RTE_CONST_D_MSECPERSEC_ULS_F32 != 1000.0F)
#   error "Constant value <D_MSECPERSEC_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MSECPERSEC_ULS_F32 (1000.0F)
#  define D_MSECPERSEC_ULS_F32 (1000.0F)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (defined D_MTRTRQCMDHILMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 != 8.8F)
#   error "Constant value <D_MTRTRQCMDHILMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
#  define D_MTRTRQCMDHILMT_MTRNM_F32 (8.8F)
# endif

# if (defined RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32) || (defined D_MTRTRQCMDLOLMT_MTRNM_F32)
#  if (!defined RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32) || (RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32 != -8.8F)
#   error "Constant value <D_MTRTRQCMDLOLMT_MTRNM_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRTRQCMDLOLMT_MTRNM_F32 (-8.8F)
#  define D_MTRTRQCMDLOLMT_MTRNM_F32 (-8.8F)
# endif

# if (defined RTE_CONST_D_ONE_ULS_F32) || (defined D_ONE_ULS_F32)
#  if (!defined RTE_CONST_D_ONE_ULS_F32) || (RTE_CONST_D_ONE_ULS_F32 != 1.0F)
#   error "Constant value <D_ONE_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_ULS_F32 (1.0F)
#  define D_ONE_ULS_F32 (1.0F)
# endif

# if (defined RTE_CONST_D_PIOVR180_ULS_F32) || (defined D_PIOVR180_ULS_F32)
#  if (!defined RTE_CONST_D_PIOVR180_ULS_F32) || (RTE_CONST_D_PIOVR180_ULS_F32 != 0.0174532925199F)
#   error "Constant value <D_PIOVR180_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PIOVR180_ULS_F32 (0.0174532925199F)
#  define D_PIOVR180_ULS_F32 (0.0174532925199F)
# endif

# if (defined RTE_CONST_D_PI_ULS_F32) || (defined D_PI_ULS_F32)
#  if (!defined RTE_CONST_D_PI_ULS_F32) || (RTE_CONST_D_PI_ULS_F32 != 3.1415926535898F)
#   error "Constant value <D_PI_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_PI_ULS_F32 (3.1415926535898F)
#  define D_PI_ULS_F32 (3.1415926535898F)
# endif

# if (defined RTE_CONST_D_RADPERREV_ULS_F32) || (defined D_RADPERREV_ULS_F32)
#  if (!defined RTE_CONST_D_RADPERREV_ULS_F32) || (RTE_CONST_D_RADPERREV_ULS_F32 != 6.28318530718F)
#   error "Constant value <D_RADPERREV_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_RADPERREV_ULS_F32 (6.28318530718F)
#  define D_RADPERREV_ULS_F32 (6.28318530718F)
# endif

# if (defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (defined D_VECUMIN_VOLTS_F32)
#  if (!defined RTE_CONST_D_VECUMIN_VOLTS_F32) || (RTE_CONST_D_VECUMIN_VOLTS_F32 != 5.0F)
#   error "Constant value <D_VECUMIN_VOLTS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_VECUMIN_VOLTS_F32 (5.0F)
#  define D_VECUMIN_VOLTS_F32 (5.0F)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0.0F)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0.0F)
#  define D_ZERO_ULS_F32 (0.0F)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S16) || (defined D_NEGONE_CNT_S16)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S16) || (RTE_CONST_D_NEGONE_CNT_S16 != -1)
#   error "Constant value <D_NEGONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S16 (-1)
#  define D_NEGONE_CNT_S16 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S16) || (defined D_ONE_CNT_S16)
#  if (!defined RTE_CONST_D_ONE_CNT_S16) || (RTE_CONST_D_ONE_CNT_S16 != 1)
#   error "Constant value <D_ONE_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S16 (1)
#  define D_ONE_CNT_S16 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S16) || (defined D_ZERO_CNT_S16)
#  if (!defined RTE_CONST_D_ZERO_CNT_S16) || (RTE_CONST_D_ZERO_CNT_S16 != 0)
#   error "Constant value <D_ZERO_CNT_S16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S16 (0)
#  define D_ZERO_CNT_S16 (0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S32) || (defined D_NEGONE_CNT_S32)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S32) || (RTE_CONST_D_NEGONE_CNT_S32 != -1)
#   error "Constant value <D_NEGONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S32 (-1)
#  define D_NEGONE_CNT_S32 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S32) || (defined D_ONE_CNT_S32)
#  if (!defined RTE_CONST_D_ONE_CNT_S32) || (RTE_CONST_D_ONE_CNT_S32 != 1)
#   error "Constant value <D_ONE_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S32 (1)
#  define D_ONE_CNT_S32 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S32) || (defined D_ZERO_CNT_S32)
#  if (!defined RTE_CONST_D_ZERO_CNT_S32) || (RTE_CONST_D_ZERO_CNT_S32 != 0)
#   error "Constant value <D_ZERO_CNT_S32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S32 (0)
#  define D_ZERO_CNT_S32 (0)
# endif

# if (defined RTE_CONST_D_NEGONE_CNT_S8) || (defined D_NEGONE_CNT_S8)
#  if (!defined RTE_CONST_D_NEGONE_CNT_S8) || (RTE_CONST_D_NEGONE_CNT_S8 != -1)
#   error "Constant value <D_NEGONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_NEGONE_CNT_S8 (-1)
#  define D_NEGONE_CNT_S8 (-1)
# endif

# if (defined RTE_CONST_D_ONE_CNT_S8) || (defined D_ONE_CNT_S8)
#  if (!defined RTE_CONST_D_ONE_CNT_S8) || (RTE_CONST_D_ONE_CNT_S8 != 1)
#   error "Constant value <D_ONE_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_S8 (1)
#  define D_ONE_CNT_S8 (1)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_S8) || (defined D_ZERO_CNT_S8)
#  if (!defined RTE_CONST_D_ZERO_CNT_S8) || (RTE_CONST_D_ZERO_CNT_S8 != 0)
#   error "Constant value <D_ZERO_CNT_S8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_S8 (0)
#  define D_ZERO_CNT_S8 (0)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U16) || (defined D_ONE_CNT_U16)
#  if (!defined RTE_CONST_D_ONE_CNT_U16) || (RTE_CONST_D_ONE_CNT_U16 != 1U)
#   error "Constant value <D_ONE_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U16 (1U)
#  define D_ONE_CNT_U16 (1U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U16) || (defined D_ZERO_CNT_U16)
#  if (!defined RTE_CONST_D_ZERO_CNT_U16) || (RTE_CONST_D_ZERO_CNT_U16 != 0U)
#   error "Constant value <D_ZERO_CNT_U16> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U16 (0U)
#  define D_ZERO_CNT_U16 (0U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U32) || (defined D_ONE_CNT_U32)
#  if (!defined RTE_CONST_D_ONE_CNT_U32) || (RTE_CONST_D_ONE_CNT_U32 != 1U)
#   error "Constant value <D_ONE_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U32 (1U)
#  define D_ONE_CNT_U32 (1U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U32) || (defined D_ZERO_CNT_U32)
#  if (!defined RTE_CONST_D_ZERO_CNT_U32) || (RTE_CONST_D_ZERO_CNT_U32 != 0U)
#   error "Constant value <D_ZERO_CNT_U32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U32 (0U)
#  define D_ZERO_CNT_U32 (0U)
# endif

# if (defined RTE_CONST_D_MTRPOLESDIV2_CNT_U8) || (defined D_MTRPOLESDIV2_CNT_U8)
#  if (!defined RTE_CONST_D_MTRPOLESDIV2_CNT_U8) || (RTE_CONST_D_MTRPOLESDIV2_CNT_U8 != 3U)
#   error "Constant value <D_MTRPOLESDIV2_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_MTRPOLESDIV2_CNT_U8 (3U)
#  define D_MTRPOLESDIV2_CNT_U8 (3U)
# endif

# if (defined RTE_CONST_D_ONE_CNT_U8) || (defined D_ONE_CNT_U8)
#  if (!defined RTE_CONST_D_ONE_CNT_U8) || (RTE_CONST_D_ONE_CNT_U8 != 1U)
#   error "Constant value <D_ONE_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ONE_CNT_U8 (1U)
#  define D_ONE_CNT_U8 (1U)
# endif

# if (defined RTE_CONST_D_QUADRANT1_CNT_U8) || (defined D_QUADRANT1_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT1_CNT_U8) || (RTE_CONST_D_QUADRANT1_CNT_U8 != 1U)
#   error "Constant value <D_QUADRANT1_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT1_CNT_U8 (1U)
#  define D_QUADRANT1_CNT_U8 (1U)
# endif

# if (defined RTE_CONST_D_QUADRANT2_CNT_U8) || (defined D_QUADRANT2_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT2_CNT_U8) || (RTE_CONST_D_QUADRANT2_CNT_U8 != 2U)
#   error "Constant value <D_QUADRANT2_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT2_CNT_U8 (2U)
#  define D_QUADRANT2_CNT_U8 (2U)
# endif

# if (defined RTE_CONST_D_QUADRANT3_CNT_U8) || (defined D_QUADRANT3_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT3_CNT_U8) || (RTE_CONST_D_QUADRANT3_CNT_U8 != 3U)
#   error "Constant value <D_QUADRANT3_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT3_CNT_U8 (3U)
#  define D_QUADRANT3_CNT_U8 (3U)
# endif

# if (defined RTE_CONST_D_QUADRANT4_CNT_U8) || (defined D_QUADRANT4_CNT_U8)
#  if (!defined RTE_CONST_D_QUADRANT4_CNT_U8) || (RTE_CONST_D_QUADRANT4_CNT_U8 != 4U)
#   error "Constant value <D_QUADRANT4_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_QUADRANT4_CNT_U8 (4U)
#  define D_QUADRANT4_CNT_U8 (4U)
# endif

# if (defined RTE_CONST_D_ZERO_CNT_U8) || (defined D_ZERO_CNT_U8)
#  if (!defined RTE_CONST_D_ZERO_CNT_U8) || (RTE_CONST_D_ZERO_CNT_U8 != 0U)
#   error "Constant value <D_ZERO_CNT_U8> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_CNT_U8 (0U)
#  define D_ZERO_CNT_U8 (0U)
# endif

# if defined T_SINELKPTBL_ULS_F32
#  error "Constant value <T_SINELKPTBL_ULS_F32> conflicts with an already defined symbol."
# else
#  define T_SINELKPTBL_ULS_F32 (Rte_T_SINELKPTBL_ULS_F32)
# endif
extern CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_SINELKPTBL_ULS_F32;

# if defined T_TANLKPTBL_ULS_F32
#  error "Constant value <T_TANLKPTBL_ULS_F32> conflicts with an already defined symbol."
# else
#  define T_TANLKPTBL_ULS_F32 (Rte_T_TANLKPTBL_ULS_F32)
# endif
extern CONST(DT_SinTanLkpTbl_f32, RTE_CONST) Rte_T_TANLKPTBL_ULS_F32;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"


/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  SInt8 value;
} Rte_DE_SInt8;

typedef struct
{
  Float value;
} Rte_DE_Float;

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_CtrldDisShtdn
{
  /* Data Handles section */
  P2VAR(Rte_DE_SInt8, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_AssistAssyPolarity_Cnt_s08;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_CRFMtrVel_MtrRadpS_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_CntDisMtrTrqCmdCRF_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_CntDisMtrTrqCmdMRF_MtrNm_f32;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_CtrldDmpStsCmp_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_DiagStsF2Active_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_SumLimTrqCmd_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_SysC_CRFMtrTrqCmd_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_CTRLDDISSHTDN_APPL_VAR) CtrldDisShtdn_Per1_SysC_MRFMtrTrqCmd_MtrNm_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_CtrldDisShtdn, RTE_CONST, RTE_CONST) Rte_Inst_Ap_CtrldDisShtdn;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1359066606
#    error "The magic number of the generated file <C:/Documents and Settings/nzx5jd/Desktop/DVOutput/Ap_CtrldDisShtdn/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1359066606
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
