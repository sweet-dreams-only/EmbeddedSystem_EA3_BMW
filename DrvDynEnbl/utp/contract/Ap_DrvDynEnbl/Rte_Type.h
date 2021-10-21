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
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/DrvDynEnbl-nzt9hv/DrvDynEnbl/autosar
 *     SW-C Type:  Ap_DrvDynEnbl
 *  Generated at:  Tue Feb 19 14:58:06 2013
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

# define Rte_TypeDef_QU_SER_STMOM_STMOM_DV_ACT
typedef uint8 QU_SER_STMOM_STMOM_DV_ACT;
# define QU_SER_STMOM_STMOM_DV_ACT_LowerLimit ((QU_SER_STMOM_STMOM_DV_ACT)0u)
# define QU_SER_STMOM_STMOM_DV_ACT_UpperLimit ((QU_SER_STMOM_STMOM_DV_ACT)255u)
# define Rte_InvalidValue_QU_SER_STMOM_STMOM_DV_ACT ((QU_SER_STMOM_STMOM_DV_ACT)255u)
# if (defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit) || (defined Cx20_Schnittstelle_verfuegbar___funktionsbereit)
#  if (!defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit) || (RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit != 32u)
#   error "Enumeration constant <Cx20_Schnittstelle_verfuegbar___funktionsbereit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit (32u)
#  define Cx20_Schnittstelle_verfuegbar___funktionsbereit ((QU_SER_STMOM_STMOM_DV_ACT)32u)
# endif
# if (defined RTE_CONST_Cx21_Schnittstelle_aktiv) || (defined Cx21_Schnittstelle_aktiv)
#  if (!defined RTE_CONST_Cx21_Schnittstelle_aktiv) || (RTE_CONST_Cx21_Schnittstelle_aktiv != 33u)
#   error "Enumeration constant <Cx21_Schnittstelle_aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx21_Schnittstelle_aktiv (33u)
#  define Cx21_Schnittstelle_aktiv ((QU_SER_STMOM_STMOM_DV_ACT)33u)
# endif
# if (defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (defined Cx60_Service_nicht_verfuegbar___Fehler)
#  if (!defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler != 96u)
#   error "Enumeration constant <Cx60_Service_nicht_verfuegbar___Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler (96u)
#  define Cx60_Service_nicht_verfuegbar___Fehler ((QU_SER_STMOM_STMOM_DV_ACT)96u)
# endif
# if (defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (defined Cx80_Schnittstelle_wird_initialisiert)
#  if (!defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (RTE_CONST_Cx80_Schnittstelle_wird_initialisiert != 128u)
#   error "Enumeration constant <Cx80_Schnittstelle_wird_initialisiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx80_Schnittstelle_wird_initialisiert (128u)
#  define Cx80_Schnittstelle_wird_initialisiert ((QU_SER_STMOM_STMOM_DV_ACT)128u)
# endif
# if (defined RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA) || (defined CxE0_Service_nicht_verfuegbar___Standby___PMA)
#  if (!defined RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA) || (RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA != 224u)
#   error "Enumeration constant <CxE0_Service_nicht_verfuegbar___Standby___PMA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE0_Service_nicht_verfuegbar___Standby___PMA (224u)
#  define CxE0_Service_nicht_verfuegbar___Standby___PMA ((QU_SER_STMOM_STMOM_DV_ACT)224u)
# endif
# if (defined RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status) || (defined CxE1_Service_nicht_verfuegbar___Standby___EPS_Status)
#  if (!defined RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status) || (RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status != 225u)
#   error "Enumeration constant <CxE1_Service_nicht_verfuegbar___Standby___EPS_Status> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE1_Service_nicht_verfuegbar___Standby___EPS_Status (225u)
#  define CxE1_Service_nicht_verfuegbar___Standby___EPS_Status ((QU_SER_STMOM_STMOM_DV_ACT)225u)
# endif
# if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255u)
#   error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_ungueltig (255u)
#  define CxFF_Signal_ungueltig ((QU_SER_STMOM_STMOM_DV_ACT)255u)
# endif

# define Rte_TypeDef_QU_SER_WSTA_EST_FTAX
typedef uint8 QU_SER_WSTA_EST_FTAX;
# define QU_SER_WSTA_EST_FTAX_LowerLimit ((QU_SER_WSTA_EST_FTAX)0u)
# define QU_SER_WSTA_EST_FTAX_UpperLimit ((QU_SER_WSTA_EST_FTAX)255u)
# define Rte_InvalidValue_QU_SER_WSTA_EST_FTAX ((QU_SER_WSTA_EST_FTAX)255u)
# if (defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit) || (defined Cx20_Schnittstelle_verfuegbar___funktionsbereit)
#  if (!defined RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit) || (RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit != 32u)
#   error "Enumeration constant <Cx20_Schnittstelle_verfuegbar___funktionsbereit> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx20_Schnittstelle_verfuegbar___funktionsbereit (32u)
#  define Cx20_Schnittstelle_verfuegbar___funktionsbereit ((QU_SER_WSTA_EST_FTAX)32u)
# endif
# if (defined RTE_CONST_Cx21_Schnittstelle_aktiv) || (defined Cx21_Schnittstelle_aktiv)
#  if (!defined RTE_CONST_Cx21_Schnittstelle_aktiv) || (RTE_CONST_Cx21_Schnittstelle_aktiv != 33u)
#   error "Enumeration constant <Cx21_Schnittstelle_aktiv> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx21_Schnittstelle_aktiv (33u)
#  define Cx21_Schnittstelle_aktiv ((QU_SER_WSTA_EST_FTAX)33u)
# endif
# if (defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (defined Cx60_Service_nicht_verfuegbar___Fehler)
#  if (!defined RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler) || (RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler != 96u)
#   error "Enumeration constant <Cx60_Service_nicht_verfuegbar___Fehler> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx60_Service_nicht_verfuegbar___Fehler (96u)
#  define Cx60_Service_nicht_verfuegbar___Fehler ((QU_SER_WSTA_EST_FTAX)96u)
# endif
# if (defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (defined Cx80_Schnittstelle_wird_initialisiert)
#  if (!defined RTE_CONST_Cx80_Schnittstelle_wird_initialisiert) || (RTE_CONST_Cx80_Schnittstelle_wird_initialisiert != 128u)
#   error "Enumeration constant <Cx80_Schnittstelle_wird_initialisiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_Cx80_Schnittstelle_wird_initialisiert (128u)
#  define Cx80_Schnittstelle_wird_initialisiert ((QU_SER_WSTA_EST_FTAX)128u)
# endif
# if (defined RTE_CONST_CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0) || (defined CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0)
#  if (!defined RTE_CONST_CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0) || (RTE_CONST_CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 != 224u)
#   error "Enumeration constant <CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 (224u)
#  define CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 ((QU_SER_WSTA_EST_FTAX)224u)
# endif
# if (defined RTE_CONST_CxE2_Funktion_in_Rueckfallebene___Hands_On) || (defined CxE2_Funktion_in_Rueckfallebene___Hands_On)
#  if (!defined RTE_CONST_CxE2_Funktion_in_Rueckfallebene___Hands_On) || (RTE_CONST_CxE2_Funktion_in_Rueckfallebene___Hands_On != 226u)
#   error "Enumeration constant <CxE2_Funktion_in_Rueckfallebene___Hands_On> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE2_Funktion_in_Rueckfallebene___Hands_On (226u)
#  define CxE2_Funktion_in_Rueckfallebene___Hands_On ((QU_SER_WSTA_EST_FTAX)226u)
# endif
# if (defined RTE_CONST_CxE3_Funktion_in_Rueckfallebene___EPS_Status) || (defined CxE3_Funktion_in_Rueckfallebene___EPS_Status)
#  if (!defined RTE_CONST_CxE3_Funktion_in_Rueckfallebene___EPS_Status) || (RTE_CONST_CxE3_Funktion_in_Rueckfallebene___EPS_Status != 227u)
#   error "Enumeration constant <CxE3_Funktion_in_Rueckfallebene___EPS_Status> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE3_Funktion_in_Rueckfallebene___EPS_Status (227u)
#  define CxE3_Funktion_in_Rueckfallebene___EPS_Status ((QU_SER_WSTA_EST_FTAX)227u)
# endif
# if (defined RTE_CONST_CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen) || (defined CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen)
#  if (!defined RTE_CONST_CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen) || (RTE_CONST_CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen != 228u)
#   error "Enumeration constant <CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen (228u)
#  define CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen ((QU_SER_WSTA_EST_FTAX)228u)
# endif
# if (defined RTE_CONST_CxE7_Schnittstelle_aktiv_degradiert) || (defined CxE7_Schnittstelle_aktiv_degradiert)
#  if (!defined RTE_CONST_CxE7_Schnittstelle_aktiv_degradiert) || (RTE_CONST_CxE7_Schnittstelle_aktiv_degradiert != 231u)
#   error "Enumeration constant <CxE7_Schnittstelle_aktiv_degradiert> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxE7_Schnittstelle_aktiv_degradiert (231u)
#  define CxE7_Schnittstelle_aktiv_degradiert ((QU_SER_WSTA_EST_FTAX)231u)
# endif
# if (defined RTE_CONST_CxFF_Signal_ungueltig) || (defined CxFF_Signal_ungueltig)
#  if (!defined RTE_CONST_CxFF_Signal_ungueltig) || (RTE_CONST_CxFF_Signal_ungueltig != 255u)
#   error "Enumeration constant <CxFF_Signal_ungueltig> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_CxFF_Signal_ungueltig (255u)
#  define CxFF_Signal_ungueltig ((QU_SER_WSTA_EST_FTAX)255u)
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

typedef struct
{
  QU_SER_WSTA_EST_FTAX value;
} Rte_DE_QU_SER_WSTA_EST_FTAX;

typedef struct
{
  QU_SER_STMOM_STMOM_DV_ACT value;
} Rte_DE_QU_SER_STMOM_STMOM_DV_ACT;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_DrvDynEnbl
{
  /* Data Handles section */
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_DRVDYNENBL_APPL_VAR) DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_DRVDYNENBL_APPL_VAR) DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_DRVDYNENBL_APPL_VAR) DrvDynEnbl_Per1_DiagStatus_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_DRVDYNENBL_APPL_VAR) DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc;
  P2VAR(Rte_DE_QU_SER_STMOM_STMOM_DV_ACT, TYPEDEF, RTE_AP_DRVDYNENBL_APPL_VAR) DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_DRVDYNENBL_APPL_VAR) DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc;
  P2VAR(Rte_DE_QU_SER_WSTA_EST_FTAX, TYPEDEF, RTE_AP_DRVDYNENBL_APPL_VAR) DrvDynEnbl_Per1_PrkAssistState_Cnt_u08;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_DrvDynEnbl, RTE_CONST, RTE_CONST) Rte_Inst_Ap_DrvDynEnbl;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1361300706
#    error "The magic number of the generated file <C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/DrvDynEnbl-nzt9hv/DrvDynEnbl/utp/contract/Ap_DrvDynEnbl/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1361300706
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
