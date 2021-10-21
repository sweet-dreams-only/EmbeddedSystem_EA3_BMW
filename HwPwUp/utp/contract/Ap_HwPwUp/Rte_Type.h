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
 *     Workspace:  C:/Synergy_projects/HwPwUp-lz4p8n/HwPwUp/autosar
 *     SW-C Type:  Ap_HwPwUp
 *  Generated at:  Thu Mar 14 13:19:12 2013
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

# define Rte_TypeDef_StaMd_Users
typedef uint8 StaMd_Users;
# define StaMd_Users_LowerLimit ((StaMd_Users)0u)
# define StaMd_Users_UpperLimit ((StaMd_Users)15u)
# if (defined RTE_CONST_STAMD_STOPCTRL) || (defined STAMD_STOPCTRL)
#  if (!defined RTE_CONST_STAMD_STOPCTRL) || (RTE_CONST_STAMD_STOPCTRL != 0u)
#   error "Enumeration constant <STAMD_STOPCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_STOPCTRL (0u)
#  define STAMD_STOPCTRL ((StaMd_Users)0u)
# endif
# if (defined RTE_CONST_STAMD_VEHPWRMD) || (defined STAMD_VEHPWRMD)
#  if (!defined RTE_CONST_STAMD_VEHPWRMD) || (RTE_CONST_STAMD_VEHPWRMD != 1u)
#   error "Enumeration constant <STAMD_VEHPWRMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_VEHPWRMD (1u)
#  define STAMD_VEHPWRMD ((StaMd_Users)1u)
# endif
# if (defined RTE_CONST_STAMD_DIAGMGR) || (defined STAMD_DIAGMGR)
#  if (!defined RTE_CONST_STAMD_DIAGMGR) || (RTE_CONST_STAMD_DIAGMGR != 2u)
#   error "Enumeration constant <STAMD_DIAGMGR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_DIAGMGR (2u)
#  define STAMD_DIAGMGR ((StaMd_Users)2u)
# endif
# if (defined RTE_CONST_STAMD_PHSDSCNCT) || (defined STAMD_PHSDSCNCT)
#  if (!defined RTE_CONST_STAMD_PHSDSCNCT) || (RTE_CONST_STAMD_PHSDSCNCT != 3u)
#   error "Enumeration constant <STAMD_PHSDSCNCT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_PHSDSCNCT (3u)
#  define STAMD_PHSDSCNCT ((StaMd_Users)3u)
# endif
# if (defined RTE_CONST_STAMD_MTRDRVR) || (defined STAMD_MTRDRVR)
#  if (!defined RTE_CONST_STAMD_MTRDRVR) || (RTE_CONST_STAMD_MTRDRVR != 4u)
#   error "Enumeration constant <STAMD_MTRDRVR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_MTRDRVR (4u)
#  define STAMD_MTRDRVR ((StaMd_Users)4u)
# endif
# if (defined RTE_CONST_STAMD_TMPRLMON) || (defined STAMD_TMPRLMON)
#  if (!defined RTE_CONST_STAMD_TMPRLMON) || (RTE_CONST_STAMD_TMPRLMON != 5u)
#   error "Enumeration constant <STAMD_TMPRLMON> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_TMPRLMON (5u)
#  define STAMD_TMPRLMON ((StaMd_Users)5u)
# endif
# if (defined RTE_CONST_STAMD_HWPWUP) || (defined STAMD_HWPWUP)
#  if (!defined RTE_CONST_STAMD_HWPWUP) || (RTE_CONST_STAMD_HWPWUP != 6u)
#   error "Enumeration constant <STAMD_HWPWUP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_STAMD_HWPWUP (6u)
#  define STAMD_HWPWUP ((StaMd_Users)6u)
# endif


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

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



/**********************************************************************************************************************
 * Type definitions for implicit access to S/R communication
 *********************************************************************************************************************/
/* Types for Data Handles section */

typedef struct
{
  Boolean value;
} Rte_DE_Boolean;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_HwPwUp
{
  /* Data Handles section */
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Per1_MtrDrvrInitComplete_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Per1_MtrDrvrInitStart_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Per1_PwrDiscATestComplete_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Per1_PwrDiscATestStart_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Per1_PwrDiscBTestComplete_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Per1_PwrDiscBTestStart_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Per1_TMFTestComplete_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Per1_TMFTestStart_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Trns1_MtrDrvrInitStart_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Trns1_PwrDiscATestStart_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Trns1_PwrDiscBTestStart_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_HWPWUP_APPL_VAR) HwPwUp_Trns1_TMFTestStart_Cnt_lgc;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_HwPwUp, RTE_CONST, RTE_CONST) Rte_Inst_Ap_HwPwUp;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1363290748
#    error "The magic number of the generated file <C:/Synergy_projects/HwPwUp-lz4p8n/HwPwUp/utp/contract/Ap_HwPwUp/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1363290748
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
