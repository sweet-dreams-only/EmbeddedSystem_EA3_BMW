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
 *     Workspace:  C:/Synergy_EA3/working/BmwTqOvrlCdng/autosar
 *     SW-C Type:  Ap_BmwTqOvrlCdng
 *  Generated at:  Fri Jun  2 16:24:25 2017
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

# define Rte_TypeDef_FltInjectionLocType
typedef uint8 FltInjectionLocType;
# define FltInjectionLocType_LowerLimit ((FltInjectionLocType)0u)
# define FltInjectionLocType_UpperLimit ((FltInjectionLocType)255u)
# if (defined RTE_CONST_FLTINJ_ASSIST) || (defined FLTINJ_ASSIST)
#  if (!defined RTE_CONST_FLTINJ_ASSIST) || (RTE_CONST_FLTINJ_ASSIST != 1u)
#   error "Enumeration constant <FLTINJ_ASSIST> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSIST (1u)
#  define FLTINJ_ASSIST ((FltInjectionLocType)1u)
# endif
# if (defined RTE_CONST_FLTINJ_RETURN) || (defined FLTINJ_RETURN)
#  if (!defined RTE_CONST_FLTINJ_RETURN) || (RTE_CONST_FLTINJ_RETURN != 2u)
#   error "Enumeration constant <FLTINJ_RETURN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_RETURN (2u)
#  define FLTINJ_RETURN ((FltInjectionLocType)2u)
# endif
# if (defined RTE_CONST_FLTINJ_DAMPING) || (defined FLTINJ_DAMPING)
#  if (!defined RTE_CONST_FLTINJ_DAMPING) || (RTE_CONST_FLTINJ_DAMPING != 3u)
#   error "Enumeration constant <FLTINJ_DAMPING> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DAMPING (3u)
#  define FLTINJ_DAMPING ((FltInjectionLocType)3u)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTSUMNLMT) || (defined FLTINJ_ASSTSUMNLMT)
#  if (!defined RTE_CONST_FLTINJ_ASSTSUMNLMT) || (RTE_CONST_FLTINJ_ASSTSUMNLMT != 4u)
#   error "Enumeration constant <FLTINJ_ASSTSUMNLMT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTSUMNLMT (4u)
#  define FLTINJ_ASSTSUMNLMT ((FltInjectionLocType)4u)
# endif
# if (defined RTE_CONST_FLTINJ_AVGFRICLRN) || (defined FLTINJ_AVGFRICLRN)
#  if (!defined RTE_CONST_FLTINJ_AVGFRICLRN) || (RTE_CONST_FLTINJ_AVGFRICLRN != 7u)
#   error "Enumeration constant <FLTINJ_AVGFRICLRN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_AVGFRICLRN (7u)
#  define FLTINJ_AVGFRICLRN ((FltInjectionLocType)7u)
# endif
# if (defined RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE) || (defined FLTINJ_VECU_BATTERYVOLTAGE)
#  if (!defined RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE) || (RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE != 8u)
#   error "Enumeration constant <FLTINJ_VECU_BATTERYVOLTAGE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_VECU_BATTERYVOLTAGE (8u)
#  define FLTINJ_VECU_BATTERYVOLTAGE ((FltInjectionLocType)8u)
# endif
# if (defined RTE_CONST_FLTINJ_HYSTCOMP) || (defined FLTINJ_HYSTCOMP)
#  if (!defined RTE_CONST_FLTINJ_HYSTCOMP) || (RTE_CONST_FLTINJ_HYSTCOMP != 12u)
#   error "Enumeration constant <FLTINJ_HYSTCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_HYSTCOMP (12u)
#  define FLTINJ_HYSTCOMP ((FltInjectionLocType)12u)
# endif
# if (defined RTE_CONST_FLTINJ_INERTIACOMP) || (defined FLTINJ_INERTIACOMP)
#  if (!defined RTE_CONST_FLTINJ_INERTIACOMP) || (RTE_CONST_FLTINJ_INERTIACOMP != 14u)
#   error "Enumeration constant <FLTINJ_INERTIACOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_INERTIACOMP (14u)
#  define FLTINJ_INERTIACOMP ((FltInjectionLocType)14u)
# endif
# if (defined RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL) || (defined FLTINJ_SUPPPWRLMT_CUSTPL)
#  if (!defined RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL) || (RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL != 25u)
#   error "Enumeration constant <FLTINJ_SUPPPWRLMT_CUSTPL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SUPPPWRLMT_CUSTPL (25u)
#  define FLTINJ_SUPPPWRLMT_CUSTPL ((FltInjectionLocType)25u)
# endif
# if (defined RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW) || (defined FLTINJ_EOTDAMPING_ETDMPFW)
#  if (!defined RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW) || (RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW != 27u)
#   error "Enumeration constant <FLTINJ_EOTDAMPING_ETDMPFW> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EOTDAMPING_ETDMPFW (27u)
#  define FLTINJ_EOTDAMPING_ETDMPFW ((FltInjectionLocType)27u)
# endif
# if (defined RTE_CONST_FLTINJ_STABILITYCOMP) || (defined FLTINJ_STABILITYCOMP)
#  if (!defined RTE_CONST_FLTINJ_STABILITYCOMP) || (RTE_CONST_FLTINJ_STABILITYCOMP != 29u)
#   error "Enumeration constant <FLTINJ_STABILITYCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_STABILITYCOMP (29u)
#  define FLTINJ_STABILITYCOMP ((FltInjectionLocType)29u)
# endif
# if (defined RTE_CONST_FLTINJ_TRQBASEDINRTCOMP) || (defined FLTINJ_TRQBASEDINRTCOMP)
#  if (!defined RTE_CONST_FLTINJ_TRQBASEDINRTCOMP) || (RTE_CONST_FLTINJ_TRQBASEDINRTCOMP != 30u)
#   error "Enumeration constant <FLTINJ_TRQBASEDINRTCOMP> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQBASEDINRTCOMP (30u)
#  define FLTINJ_TRQBASEDINRTCOMP ((FltInjectionLocType)30u)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND) || (defined FLTINJ_SRLCOMVEHSPD_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND != 33u)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHSPD_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHSPD_SGNLCOND (33u)
#  define FLTINJ_SRLCOMVEHSPD_SGNLCOND ((FltInjectionLocType)33u)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTFIREWALL) || (defined FLTINJ_ASSTFIREWALL)
#  if (!defined RTE_CONST_FLTINJ_ASSTFIREWALL) || (RTE_CONST_FLTINJ_ASSTFIREWALL != 34u)
#   error "Enumeration constant <FLTINJ_ASSTFIREWALL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTFIREWALL (34u)
#  define FLTINJ_ASSTFIREWALL ((FltInjectionLocType)34u)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD) || (defined FLTINJ_ASSTEOTGAIN_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD) || (RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD != 38u)
#   error "Enumeration constant <FLTINJ_ASSTEOTGAIN_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTEOTGAIN_LMTCOD (38u)
#  define FLTINJ_ASSTEOTGAIN_LMTCOD ((FltInjectionLocType)38u)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTRQT1) || (defined FLTINJ_ANAHWTRQT1)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTRQT1) || (RTE_CONST_FLTINJ_ANAHWTRQT1 != 39u)
#   error "Enumeration constant <FLTINJ_ANAHWTRQT1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTRQT1 (39u)
#  define FLTINJ_ANAHWTRQT1 ((FltInjectionLocType)39u)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTRQT2) || (defined FLTINJ_ANAHWTRQT2)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTRQT2) || (RTE_CONST_FLTINJ_ANAHWTRQT2 != 40u)
#   error "Enumeration constant <FLTINJ_ANAHWTRQT2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTRQT2 (40u)
#  define FLTINJ_ANAHWTRQT2 ((FltInjectionLocType)40u)
# endif
# if (defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT) || (defined FLTINJ_DIGHWTRQSENT_T1FAULT)
#  if (!defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT) || (RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT != 41u)
#   error "Enumeration constant <FLTINJ_DIGHWTRQSENT_T1FAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DIGHWTRQSENT_T1FAULT (41u)
#  define FLTINJ_DIGHWTRQSENT_T1FAULT ((FltInjectionLocType)41u)
# endif
# if (defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT) || (defined FLTINJ_DIGHWTRQSENT_T2FAULT)
#  if (!defined RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT) || (RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT != 42u)
#   error "Enumeration constant <FLTINJ_DIGHWTRQSENT_T2FAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DIGHWTRQSENT_T2FAULT (42u)
#  define FLTINJ_DIGHWTRQSENT_T2FAULT ((FltInjectionLocType)42u)
# endif
# if (defined RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND) || (defined FLTINJ_TRQOSC_PREFINALCOMMAND)
#  if (!defined RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND) || (RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND != 43u)
#   error "Enumeration constant <FLTINJ_TRQOSC_PREFINALCOMMAND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQOSC_PREFINALCOMMAND (43u)
#  define FLTINJ_TRQOSC_PREFINALCOMMAND ((FltInjectionLocType)43u)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBCROLLGCNTR) || (defined FLTINJ_IMCARBCROLLGCNTR)
#  if (!defined RTE_CONST_FLTINJ_IMCARBCROLLGCNTR) || (RTE_CONST_FLTINJ_IMCARBCROLLGCNTR != 44u)
#   error "Enumeration constant <FLTINJ_IMCARBCROLLGCNTR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBCROLLGCNTR (44u)
#  define FLTINJ_IMCARBCROLLGCNTR ((FltInjectionLocType)44u)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRCRC) || (defined FLTINJ_IMCARBRCRC)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRCRC) || (RTE_CONST_FLTINJ_IMCARBRCRC != 45u)
#   error "Enumeration constant <FLTINJ_IMCARBRCRC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRCRC (45u)
#  define FLTINJ_IMCARBRCRC ((FltInjectionLocType)45u)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRDATA) || (defined FLTINJ_IMCARBRDATA)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRDATA) || (RTE_CONST_FLTINJ_IMCARBRDATA != 46u)
#   error "Enumeration constant <FLTINJ_IMCARBRDATA> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRDATA (46u)
#  define FLTINJ_IMCARBRDATA ((FltInjectionLocType)46u)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_HWTRQ) || (defined FLTINJ_GCCDIAG_HWTRQ)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_HWTRQ) || (RTE_CONST_FLTINJ_GCCDIAG_HWTRQ != 46u)
#   error "Enumeration constant <FLTINJ_GCCDIAG_HWTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_HWTRQ (46u)
#  define FLTINJ_GCCDIAG_HWTRQ ((FltInjectionLocType)46u)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBRPATIDN) || (defined FLTINJ_IMCARBRPATIDN)
#  if (!defined RTE_CONST_FLTINJ_IMCARBRPATIDN) || (RTE_CONST_FLTINJ_IMCARBRPATIDN != 47u)
#   error "Enumeration constant <FLTINJ_IMCARBRPATIDN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBRPATIDN (47u)
#  define FLTINJ_IMCARBRPATIDN ((FltInjectionLocType)47u)
# endif
# if (defined RTE_CONST_FLTINJ_CMMTRCURR1) || (defined FLTINJ_CMMTRCURR1)
#  if (!defined RTE_CONST_FLTINJ_CMMTRCURR1) || (RTE_CONST_FLTINJ_CMMTRCURR1 != 48u)
#   error "Enumeration constant <FLTINJ_CMMTRCURR1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_CMMTRCURR1 (48u)
#  define FLTINJ_CMMTRCURR1 ((FltInjectionLocType)48u)
# endif
# if (defined RTE_CONST_FLTINJ_CMMTRCURR2) || (defined FLTINJ_CMMTRCURR2)
#  if (!defined RTE_CONST_FLTINJ_CMMTRCURR2) || (RTE_CONST_FLTINJ_CMMTRCURR2 != 49u)
#   error "Enumeration constant <FLTINJ_CMMTRCURR2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_CMMTRCURR2 (49u)
#  define FLTINJ_CMMTRCURR2 ((FltInjectionLocType)49u)
# endif
# if (defined RTE_CONST_FLTINJ_NHET1CFGANDUSE1) || (defined FLTINJ_NHET1CFGANDUSE1)
#  if (!defined RTE_CONST_FLTINJ_NHET1CFGANDUSE1) || (RTE_CONST_FLTINJ_NHET1CFGANDUSE1 != 50u)
#   error "Enumeration constant <FLTINJ_NHET1CFGANDUSE1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_NHET1CFGANDUSE1 (50u)
#  define FLTINJ_NHET1CFGANDUSE1 ((FltInjectionLocType)50u)
# endif
# if (defined RTE_CONST_FLTINJ_NHET1CFGANDUSE2) || (defined FLTINJ_NHET1CFGANDUSE2)
#  if (!defined RTE_CONST_FLTINJ_NHET1CFGANDUSE2) || (RTE_CONST_FLTINJ_NHET1CFGANDUSE2 != 51u)
#   error "Enumeration constant <FLTINJ_NHET1CFGANDUSE2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_NHET1CFGANDUSE2 (51u)
#  define FLTINJ_NHET1CFGANDUSE2 ((FltInjectionLocType)51u)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP1) || (defined FLTINJ_EPWM_UP1)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP1) || (RTE_CONST_FLTINJ_EPWM_UP1 != 52u)
#   error "Enumeration constant <FLTINJ_EPWM_UP1> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP1 (52u)
#  define FLTINJ_EPWM_UP1 ((FltInjectionLocType)52u)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP2) || (defined FLTINJ_EPWM_UP2)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP2) || (RTE_CONST_FLTINJ_EPWM_UP2 != 53u)
#   error "Enumeration constant <FLTINJ_EPWM_UP2> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP2 (53u)
#  define FLTINJ_EPWM_UP2 ((FltInjectionLocType)53u)
# endif
# if (defined RTE_CONST_FLTINJ_EPWM_UP3) || (defined FLTINJ_EPWM_UP3)
#  if (!defined RTE_CONST_FLTINJ_EPWM_UP3) || (RTE_CONST_FLTINJ_EPWM_UP3 != 54u)
#   error "Enumeration constant <FLTINJ_EPWM_UP3> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_EPWM_UP3 (54u)
#  define FLTINJ_EPWM_UP3 ((FltInjectionLocType)54u)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENCAN) || (defined FLTINJ_IMCARBROPENCAN)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENCAN) || (RTE_CONST_FLTINJ_IMCARBROPENCAN != 65u)
#   error "Enumeration constant <FLTINJ_IMCARBROPENCAN> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENCAN (65u)
#  define FLTINJ_IMCARBROPENCAN ((FltInjectionLocType)65u)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENCANSCI) || (defined FLTINJ_IMCARBROPENCANSCI)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENCANSCI) || (RTE_CONST_FLTINJ_IMCARBROPENCANSCI != 66u)
#   error "Enumeration constant <FLTINJ_IMCARBROPENCANSCI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENCANSCI (66u)
#  define FLTINJ_IMCARBROPENCANSCI ((FltInjectionLocType)66u)
# endif
# if (defined RTE_CONST_FLTINJ_IMCARBROPENSCI) || (defined FLTINJ_IMCARBROPENSCI)
#  if (!defined RTE_CONST_FLTINJ_IMCARBROPENSCI) || (RTE_CONST_FLTINJ_IMCARBROPENSCI != 67u)
#   error "Enumeration constant <FLTINJ_IMCARBROPENSCI> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_IMCARBROPENSCI (67u)
#  define FLTINJ_IMCARBROPENSCI ((FltInjectionLocType)67u)
# endif
# if (defined RTE_CONST_FLTINJ_BMWTOC) || (defined FLTINJ_BMWTOC)
#  if (!defined RTE_CONST_FLTINJ_BMWTOC) || (RTE_CONST_FLTINJ_BMWTOC != 68u)
#   error "Enumeration constant <FLTINJ_BMWTOC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_BMWTOC (68u)
#  define FLTINJ_BMWTOC ((FltInjectionLocType)68u)
# endif
# if (defined RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT) || (defined FLTINJ_TRQOVLSTA_LKAFAULT)
#  if (!defined RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT) || (RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT != 91u)
#   error "Enumeration constant <FLTINJ_TRQOVLSTA_LKAFAULT> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQOVLSTA_LKAFAULT (91u)
#  define FLTINJ_TRQOVLSTA_LKAFAULT ((FltInjectionLocType)91u)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND) || (defined FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND != 100u)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND (100u)
#  define FLTINJ_SRLCOMVEHYAWRATE_SGNLCOND ((FltInjectionLocType)100u)
# endif
# if (defined RTE_CONST_FLTINJ_TRQARBLIM_LKACMD) || (defined FLTINJ_TRQARBLIM_LKACMD)
#  if (!defined RTE_CONST_FLTINJ_TRQARBLIM_LKACMD) || (RTE_CONST_FLTINJ_TRQARBLIM_LKACMD != 101u)
#   error "Enumeration constant <FLTINJ_TRQARBLIM_LKACMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_TRQARBLIM_LKACMD (101u)
#  define FLTINJ_TRQARBLIM_LKACMD ((FltInjectionLocType)101u)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_VEHSPD) || (defined FLTINJ_GCCDIAG_VEHSPD)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_VEHSPD) || (RTE_CONST_FLTINJ_GCCDIAG_VEHSPD != 146u)
#   error "Enumeration constant <FLTINJ_GCCDIAG_VEHSPD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_VEHSPD (146u)
#  define FLTINJ_GCCDIAG_VEHSPD ((FltInjectionLocType)146u)
# endif
# if (defined RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDASTFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL != 150u)
#   error "Enumeration constant <FLTINJ_DDASTFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDASTFACTRQST_DRVDYNCTRL (150u)
#  define FLTINJ_DDASTFACTRQST_DRVDYNCTRL ((FltInjectionLocType)150u)
# endif
# if (defined RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDDMPFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL != 151u)
#   error "Enumeration constant <FLTINJ_DDDMPFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDDMPFACTRQST_DRVDYNCTRL (151u)
#  define FLTINJ_DDDMPFACTRQST_DRVDYNCTRL ((FltInjectionLocType)151u)
# endif
# if (defined RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL) || (defined FLTINJ_DDRTNFACTRQST_DRVDYNCTRL)
#  if (!defined RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL) || (RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL != 152u)
#   error "Enumeration constant <FLTINJ_DDRTNFACTRQST_DRVDYNCTRL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_DDRTNFACTRQST_DRVDYNCTRL (152u)
#  define FLTINJ_DDRTNFACTRQST_DRVDYNCTRL ((FltInjectionLocType)152u)
# endif
# if (defined RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD) || (defined FLTINJ_OUTPUTRAMPMULT_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD) || (RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD != 153u)
#   error "Enumeration constant <FLTINJ_OUTPUTRAMPMULT_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_OUTPUTRAMPMULT_LMTCOD (153u)
#  define FLTINJ_OUTPUTRAMPMULT_LMTCOD ((FltInjectionLocType)153u)
# endif
# if (defined RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD) || (defined FLTINJ_ASSTEOTLIMIT_LMTCOD)
#  if (!defined RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD) || (RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD != 154u)
#   error "Enumeration constant <FLTINJ_ASSTEOTLIMIT_LMTCOD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ASSTEOTLIMIT_LMTCOD (154u)
#  define FLTINJ_ASSTEOTLIMIT_LMTCOD ((FltInjectionLocType)154u)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND) || (defined FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND != 155u)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND (155u)
#  define FLTINJ_SRLCOMVEHLONACCEL_SGNLCOND ((FltInjectionLocType)155u)
# endif
# if (defined RTE_CONST_FLTINJ_ANAHWTORQUE) || (defined FLTINJ_ANAHWTORQUE)
#  if (!defined RTE_CONST_FLTINJ_ANAHWTORQUE) || (RTE_CONST_FLTINJ_ANAHWTORQUE != 156u)
#   error "Enumeration constant <FLTINJ_ANAHWTORQUE> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_ANAHWTORQUE (156u)
#  define FLTINJ_ANAHWTORQUE ((FltInjectionLocType)156u)
# endif
# if (defined RTE_CONST_FLTINJ_MTRVEL) || (defined FLTINJ_MTRVEL)
#  if (!defined RTE_CONST_FLTINJ_MTRVEL) || (RTE_CONST_FLTINJ_MTRVEL != 160u)
#   error "Enumeration constant <FLTINJ_MTRVEL> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_MTRVEL (160u)
#  define FLTINJ_MTRVEL ((FltInjectionLocType)160u)
# endif
# if (defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD) || (defined FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD)
#  if (!defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD) || (RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD != 200u)
#   error "Enumeration constant <FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD (200u)
#  define FLTINJ_PRKASTMFGSERVCH2_PRKASSISTCMD ((FltInjectionLocType)200u)
# endif
# if (defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR) || (defined FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR)
#  if (!defined RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR) || (RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR != 201u)
#   error "Enumeration constant <FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR (201u)
#  define FLTINJ_PRKASTMFGSERVCH2_LRNPNCNTR ((FltInjectionLocType)201u)
# endif
# if (defined RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ) || (defined FLTINJ_GCCDIAG_MTRTRQ)
#  if (!defined RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ) || (RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ != 246u)
#   error "Enumeration constant <FLTINJ_GCCDIAG_MTRTRQ> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_GCCDIAG_MTRTRQ (246u)
#  define FLTINJ_GCCDIAG_MTRTRQ ((FltInjectionLocType)246u)
# endif
# if (defined RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND) || (defined FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND)
#  if (!defined RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND) || (RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND != 255u)
#   error "Enumeration constant <FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND (255u)
#  define FLTINJ_SRLCOMVEHLATACCEL_SGNLCOND ((FltInjectionLocType)255u)
# endif

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

# if (defined RTE_CONST_D_FALSE_CNT_LGC) || (defined D_FALSE_CNT_LGC)
#  if (!defined RTE_CONST_D_FALSE_CNT_LGC) || (RTE_CONST_D_FALSE_CNT_LGC != FALSE)
#   error "Constant value <D_FALSE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_FALSE_CNT_LGC (FALSE)
#  define D_FALSE_CNT_LGC ((Boolean)FALSE)
# endif

# if (defined RTE_CONST_D_TRUE_CNT_LGC) || (defined D_TRUE_CNT_LGC)
#  if (!defined RTE_CONST_D_TRUE_CNT_LGC) || (RTE_CONST_D_TRUE_CNT_LGC != TRUE)
#   error "Constant value <D_TRUE_CNT_LGC> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_TRUE_CNT_LGC (TRUE)
#  define D_TRUE_CNT_LGC ((Boolean)TRUE)
# endif

# if (defined RTE_CONST_D_2MS_SEC_F32) || (defined D_2MS_SEC_F32)
#  if (!defined RTE_CONST_D_2MS_SEC_F32) || (RTE_CONST_D_2MS_SEC_F32 != 0.002)
#   error "Constant value <D_2MS_SEC_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_2MS_SEC_F32 (0.002)
#  define D_2MS_SEC_F32 ((Float)0.002)
# endif

# if (defined RTE_CONST_D_ZERO_ULS_F32) || (defined D_ZERO_ULS_F32)
#  if (!defined RTE_CONST_D_ZERO_ULS_F32) || (RTE_CONST_D_ZERO_ULS_F32 != 0)
#   error "Constant value <D_ZERO_ULS_F32> conflicts with another constant."
#  endif
# else
#  define RTE_CONST_D_ZERO_ULS_F32 (0)
#  define D_ZERO_ULS_F32 ((Float)0)
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
  QU_SER_STMOM_STMOM_DV_ACT value;
} Rte_DE_QU_SER_STMOM_STMOM_DV_ACT;

typedef struct
{
  Float value;
} Rte_DE_Float;


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_Ap_BmwTqOvrlCdng
{
  /* Data Handles section */
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWTQOVRLCDNG_APPL_VAR) BmwTqOvrlCdng_Per1_DrvDynActive_Cnt_lgc;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWTQOVRLCDNG_APPL_VAR) BmwTqOvrlCdng_Per1_DrvgDynErrIfActv_Cnt_lgc;
  P2VAR(Rte_DE_QU_SER_STMOM_STMOM_DV_ACT, TYPEDEF, RTE_AP_BMWTQOVRLCDNG_APPL_VAR) BmwTqOvrlCdng_Per1_DrvgDynIfSt_Cnt_u08;
  P2VAR(Rte_DE_Boolean, TYPEDEF, RTE_AP_BMWTQOVRLCDNG_APPL_VAR) BmwTqOvrlCdng_Per1_OpTrqOvRmpInEnable_Cnt_lgc;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWTQOVRLCDNG_APPL_VAR) BmwTqOvrlCdng_Per1_OutpTqOvrl_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWTQOVRLCDNG_APPL_VAR) BmwTqOvrlCdng_Per1_SerlComTarSteerTqDrvrActr_MtrNm_f32;
  P2VAR(Rte_DE_Float, TYPEDEF, RTE_AP_BMWTQOVRLCDNG_APPL_VAR) BmwTqOvrlCdng_Per1_VehicleSpeed_Kph_f32;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

extern CONSTP2CONST(struct Rte_CDS_Ap_BmwTqOvrlCdng, RTE_CONST, RTE_CONST) Rte_Inst_Ap_BmwTqOvrlCdng;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1496443881
#    error "The magic number of the generated file <C:/Synergy_EA3/working/BmwTqOvrlCdng/tools/contract/Ap_BmwTqOvrlCdng/Rte_Type.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1496443881
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_TYPE_H */
