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
 *          File:  Rte_Compiler_Cfg.h
 *     Workspace:  C:/Users/nz2378/Documents/work/EA3/Integration/BMW/F40_UKL_MCV/Application/Source/BMW_UKL_MCV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *  Generated at:  Thu May 25 16:44:08 2017
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  RTE Compiler Abstraction header file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMPILER_CFG_H
# define _RTE_COMPILER_CFG_H


/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CODE
 *********************************************************************************************************************/

/* used for code */
# define RTE_CODE

/* used for all global or static variables that are not initialized by the startup code of the compiler */
# define RTE_VAR_NOINIT

/* used for global or static variables that are initialized with zero by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_ZERO_INIT

/* used for global or static variables that are initialized by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_INIT

/* used for global or static constants */
# define RTE_CONST

/* used for references on application data (variables or constants */
# define RTE_APPL_DATA

/* used for references on application variables */
# define RTE_APPL_VAR

/* used for references on application functions */
# define RTE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ABSHWPOS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ABSHWPOS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ABSHWPOS_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ABSHWPOS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ACTIVEPULL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ACTIVEPULL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ACTIVEPULL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ACTIVEPULL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_APXCP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_APXCP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_APXCP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_APXCP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ASSIST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ASSIST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ASSIST_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ASSIST_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ASSISTFIREWALL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ASSISTFIREWALL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ASSISTFIREWALL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ASSISTFIREWALL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ASSISTSUMNLMT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ASSISTSUMNLMT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ASSISTSUMNLMT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ASSISTSUMNLMT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_AVGFRICLRN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_AVGFRICLRN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_AVGFRICLRN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_AVGFRICLRN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_BVDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_BVDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BVDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BVDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_BATTERYVOLTAGE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_BATTERYVOLTAGE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BATTERYVOLTAGE_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BATTERYVOLTAGE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_BMWHAPTCFB_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_BMWHAPTCFB_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BMWHAPTCFB_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BMWHAPTCFB_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_BMWRTNARBN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_BMWRTNARBN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BMWRTNARBN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BMWRTNARBN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_BMWTQOVRLCDNG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_BMWTQOVRLCDNG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_BMWTQOVRLCDNG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_BMWTQOVRLCDNG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CHKPTAP10_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CHKPTAP10_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CHKPTAP10_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CHKPTAP10_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CHKPTAP11_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CHKPTAP11_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CHKPTAP11_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CHKPTAP11_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CHKPTAP7_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CHKPTAP7_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CHKPTAP7_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CHKPTAP7_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CHKPTAP8_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CHKPTAP8_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CHKPTAP8_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CHKPTAP8_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CHKPTAP9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CHKPTAP9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CHKPTAP9_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CHKPTAP9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CTRLDDISSHTDN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CTRLDDISSHTDN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CTRLDDISSHTDN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CTRLDDISSHTDN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CURRENTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CURRENTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CURRENTEST_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CURRENTEST_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_CUSTPL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_CUSTPL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_CUSTPL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_CUSTPL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DAMPING_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DAMPING_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DAMPING_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DAMPING_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DAMPINGFIREWALL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DAMPINGFIREWALL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DAMPINGFIREWALL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DAMPINGFIREWALL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DEMIF_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DEMIF_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DEMIF_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DEMIF_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIAGMGR10_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIAGMGR10_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIAGMGR10_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIAGMGR10_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIAGMGR11_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIAGMGR11_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIAGMGR11_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIAGMGR11_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIAGMGR7_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIAGMGR7_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIAGMGR7_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIAGMGR7_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIAGMGR8_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIAGMGR8_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIAGMGR8_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIAGMGR8_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIAGMGR9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIAGMGR9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIAGMGR9_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIAGMGR9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DIGPHSREASDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DIGPHSREASDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DIGPHSREASDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DIGPHSREASDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DRVDYNCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DRVDYNCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DRVDYNCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DRVDYNCTRL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_DRVDYNENBL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_DRVDYNENBL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_DRVDYNENBL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_DRVDYNENBL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_EOTACTUATORMNG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_EOTACTUATORMNG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_EOTACTUATORMNG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_EOTACTUATORMNG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ELECPWR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ELECPWR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ELECPWR_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ELECPWR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_ETDMPFW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_ETDMPFW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_ETDMPFW_APPL_DATA

/* used for references on application functions */
# define RTE_AP_ETDMPFW_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_FLTINJECTION_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_FLTINJECTION_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_FLTINJECTION_APPL_DATA

/* used for references on application functions */
# define RTE_AP_FLTINJECTION_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_FRQDEPDMPNINRTCMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_FRQDEPDMPNINRTCMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_FRQDEPDMPNINRTCMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_FRQDEPDMPNINRTCMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_GENPOSTRAJ_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_GENPOSTRAJ_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_GENPOSTRAJ_APPL_DATA

/* used for references on application functions */
# define RTE_AP_GENPOSTRAJ_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_GSOD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_GSOD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_GSOD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_GSOD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HILOADSTALL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HILOADSTALL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HILOADSTALL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HILOADSTALL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HWPWUP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HWPWUP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HWPWUP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HWPWUP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HYSTADD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HYSTADD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HYSTADD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HYSTADD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_HYSTCOMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_HYSTCOMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_HYSTCOMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_HYSTCOMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_LKTOLKSTR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_LKTOLKSTR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_LKTOLKSTR_APPL_DATA

/* used for references on application functions */
# define RTE_AP_LKTOLKSTR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_LMTCOD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_LMTCOD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_LMTCOD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_LMTCOD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_LNRKCR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_LNRKCR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_LNRKCR_APPL_DATA

/* used for references on application functions */
# define RTE_AP_LNRKCR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_LRNEOT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_LRNEOT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_LRNEOT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_LRNEOT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_MTRCTRLOPCONV_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_MTRCTRLOPCONV_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_MTRCTRLOPCONV_APPL_DATA

/* used for references on application functions */
# define RTE_AP_MTRCTRLOPCONV_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_MTRTEMPEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_MTRTEMPEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_MTRTEMPEST_APPL_DATA

/* used for references on application functions */
# define RTE_AP_MTRTEMPEST_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_NHET2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_NHET2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_NHET2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_NHET2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_OSCTRAJ_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_OSCTRAJ_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_OSCTRAJ_APPL_DATA

/* used for references on application functions */
# define RTE_AP_OSCTRAJ_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PARAMCOMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PARAMCOMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PARAMCOMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PARAMCOMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PARKASTENBL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PARKASTENBL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PARKASTENBL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PARKASTENBL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PHASECTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PHASECTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PHASECTRL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PHASECTRL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_POLARITY_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_POLARITY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_POLARITY_APPL_DATA

/* used for references on application functions */
# define RTE_AP_POLARITY_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_POSSERVO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_POSSERVO_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_POSSERVO_APPL_DATA

/* used for references on application functions */
# define RTE_AP_POSSERVO_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PRKASTMFGSERVCH2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PRKASTMFGSERVCH2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PRKASTMFGSERVCH2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PRKASTMFGSERVCH2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_PWRLMTFUNC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_PWRLMTFUNC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_PWRLMTFUNC_APPL_DATA

/* used for references on application functions */
# define RTE_AP_PWRLMTFUNC_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_QUADDET_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_QUADDET_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_QUADDET_APPL_DATA

/* used for references on application functions */
# define RTE_AP_QUADDET_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_RACKLOAD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_RACKLOAD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_RACKLOAD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_RACKLOAD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_RETURN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_RETURN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_RETURN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_RETURN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_RETURNFIREWALL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_RETURNFIREWALL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_RETURNFIREWALL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_RETURNFIREWALL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SIGNLCONDN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SIGNLCONDN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SIGNLCONDN_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SIGNLCONDN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SRLCOMINPUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SRLCOMINPUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SRLCOMINPUT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SRLCOMINPUT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SRLCOMINPUT2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SRLCOMINPUT2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SRLCOMINPUT2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SRLCOMINPUT2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SRLCOMOUTPUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SRLCOMOUTPUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SRLCOMOUTPUT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SRLCOMOUTPUT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SRLCOMOUTPUT2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SRLCOMOUTPUT2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SRLCOMOUTPUT2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SRLCOMOUTPUT2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SRLSCOMSRVC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SRLSCOMSRVC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SRLSCOMSRVC_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SRLSCOMSRVC_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STOPCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STOPCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STOPCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STOPCTRL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STAMD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STAMD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STAMD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STAMD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STAMD11_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STAMD11_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STAMD11_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STAMD11_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STAMD7_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STAMD7_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STAMD7_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STAMD7_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STAMD8_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STAMD8_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STAMD8_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STAMD8_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STAMD9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STAMD9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STAMD9_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STAMD9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STABILITYCOMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STABILITYCOMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STABILITYCOMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STABILITYCOMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_STABILITYCOMP2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_STABILITYCOMP2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_STABILITYCOMP2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_STABILITYCOMP2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SWEEP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SWEEP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SWEEP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SWEEP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_SWEEP2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_SWEEP2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_SWEEP2_APPL_DATA

/* used for references on application functions */
# define RTE_AP_SWEEP2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TJADAMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TJADAMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TJADAMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TJADAMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_THRMLDUTYCYCLE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_THRMLDUTYCYCLE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_THRMLDUTYCYCLE_APPL_DATA

/* used for references on application functions */
# define RTE_AP_THRMLDUTYCYCLE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQBASEDINRTCMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQBASEDINRTCMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQBASEDINRTCMP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQBASEDINRTCMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQCMDSCL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQCMDSCL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQCMDSCL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQCMDSCL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TRQOSC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TRQOSC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TRQOSC_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TRQOSC_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_TUNINGSELAUTH_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_TUNINGSELAUTH_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_TUNINGSELAUTH_APPL_DATA

/* used for references on application functions */
# define RTE_AP_TUNINGSELAUTH_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_VEHCFG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_VEHCFG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_VEHCFG_APPL_DATA

/* used for references on application functions */
# define RTE_AP_VEHCFG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_VEHPWRMD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_VEHPWRMD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_VEHPWRMD_APPL_DATA

/* used for references on application functions */
# define RTE_AP_VEHPWRMD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_VEHSPDLMT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_VEHSPDLMT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_VEHSPDLMT_APPL_DATA

/* used for references on application functions */
# define RTE_AP_VEHSPDLMT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AP_VLTGCTRL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_AP_VLTGCTRL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_VLTGCTRL_APPL_DATA

/* used for references on application functions */
# define RTE_AP_VLTGCTRL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CDD_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CDD_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CDD_APPL_DATA

/* used for references on application functions */
# define RTE_CDD_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CD_TURNSCOUNTER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CD_TURNSCOUNTER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CD_TURNSCOUNTER_APPL_DATA

/* used for references on application functions */
# define RTE_CD_TURNSCOUNTER_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CD_UDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CD_UDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CD_UDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_CD_UDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CODING_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CODING_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CODING_APPL_DATA

/* used for references on application functions */
# define RTE_CODING_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_COMM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_COMM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_COMM_APPL_DATA

/* used for references on application functions */
# define RTE_COMM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEM_APPL_DATA

/* used for references on application functions */
# define RTE_DEM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ECUM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ECUM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ECUM_APPL_DATA

/* used for references on application functions */
# define RTE_ECUM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_EDCH_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_EDCH_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_EDCH_APPL_DATA

/* used for references on application functions */
# define RTE_EDCH_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IOHWAB10_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IOHWAB10_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWAB10_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWAB10_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IOHWAB7_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IOHWAB7_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWAB7_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWAB7_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IOHWABSTRACTION_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_IOHWABSTRACTION_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWABSTRACTION_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWABSTRACTION_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NXTRLIBS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NXTRLIBS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NXTRLIBS_APPL_DATA

/* used for references on application functions */
# define RTE_NXTRLIBS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NTWRAP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NTWRAP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NTWRAP_APPL_DATA

/* used for references on application functions */
# define RTE_NTWRAP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NVM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NVM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVM_APPL_DATA

/* used for references on application functions */
# define RTE_NVM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NVMPROXY_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NVMPROXY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVMPROXY_APPL_DATA

/* used for references on application functions */
# define RTE_NVMPROXY_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTEERRATA10_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTEERRATA10_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTEERRATA10_APPL_DATA

/* used for references on application functions */
# define RTE_RTEERRATA10_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTEERRATA11_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTEERRATA11_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTEERRATA11_APPL_DATA

/* used for references on application functions */
# define RTE_RTEERRATA11_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTEERRATA7_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTEERRATA7_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTEERRATA7_APPL_DATA

/* used for references on application functions */
# define RTE_RTEERRATA7_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTEERRATA8_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTEERRATA8_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTEERRATA8_APPL_DATA

/* used for references on application functions */
# define RTE_RTEERRATA8_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_RTEERRATA9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_RTEERRATA9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_RTEERRATA9_APPL_DATA

/* used for references on application functions */
# define RTE_RTEERRATA9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_BKCPPC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_BKCPPC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_BKCPPC_APPL_DATA

/* used for references on application functions */
# define RTE_SA_BKCPPC_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_CDDINTERFACE10_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_CDDINTERFACE10_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_CDDINTERFACE10_APPL_DATA

/* used for references on application functions */
# define RTE_SA_CDDINTERFACE10_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_CDDINTERFACE9_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_CDDINTERFACE9_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_CDDINTERFACE9_APPL_DATA

/* used for references on application functions */
# define RTE_SA_CDDINTERFACE9_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_CTRLTEMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_CTRLTEMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_CTRLTEMP_APPL_DATA

/* used for references on application functions */
# define RTE_SA_CTRLTEMP_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_HWTRQ_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_HWTRQ_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_HWTRQ_APPL_DATA

/* used for references on application functions */
# define RTE_SA_HWTRQ_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_HWTRQ2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_HWTRQ2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_HWTRQ2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_HWTRQ2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRCURR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRCURR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRCURR_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRCURR_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRDRVDIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRDRVDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRDRVDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRDRVDIAG_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRPOS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRPOS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRPOS_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRPOS_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRPOS2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRPOS2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRPOS2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRPOS2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRPOS3_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRPOS3_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRPOS3_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRPOS3_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRVEL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRVEL_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRVEL_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRVEL_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRVEL2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRVEL2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRVEL2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRVEL2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_MTRVEL3_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_MTRVEL3_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRVEL3_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRVEL3_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_PHASEDSCNT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_PHASEDSCNT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_PHASEDSCNT_APPL_DATA

/* used for references on application functions */
# define RTE_SA_PHASEDSCNT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_PRIMARYSHUTDOWN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_PRIMARYSHUTDOWN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_PRIMARYSHUTDOWN_APPL_DATA

/* used for references on application functions */
# define RTE_SA_PRIMARYSHUTDOWN_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_SHTDNMECH_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_SHTDNMECH_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_SHTDNMECH_APPL_DATA

/* used for references on application functions */
# define RTE_SA_SHTDNMECH_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_TMPRLMON_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_TMPRLMON_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_TMPRLMON_APPL_DATA

/* used for references on application functions */
# define RTE_SA_TMPRLMON_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SA_TMPRLMON2_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SA_TMPRLMON2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_TMPRLMON2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_TMPRLMON2_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_SPINXT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_SPINXT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SPINXT_APPL_DATA

/* used for references on application functions */
# define RTE_SPINXT_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WDGM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WDGM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WDGM_APPL_DATA

/* used for references on application functions */
# define RTE_WDGM_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Per-Instance Memory specific defines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_Ap_7_PIM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_Ap_9_PIM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_PIM_GROUP
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_PIM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_TMPRLMON2_TODO_APPL)  *********/

/* used for references on application variables */
# define RTE_SA_TMPRLMON2_TODO_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_TMPRLMON2_TODO_APPL_DATA

/* used for references on application functions */
# define RTE_SA_TMPRLMON2_TODO_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_AP_XCP_APPL)  ********************/

/* used for references on application variables */
# define RTE_AP_XCP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_AP_XCP_APPL_DATA

/* used for references on application functions */
# define RTE_AP_XCP_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_IOHWABSTRACTIONUSR_APPL)  ********/

/* used for references on application variables */
# define RTE_IOHWABSTRACTIONUSR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_IOHWABSTRACTIONUSR_APPL_DATA

/* used for references on application functions */
# define RTE_IOHWABSTRACTIONUSR_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_MTRPOSDIAG_APPL)  *************/

/* used for references on application variables */
# define RTE_SA_MTRPOSDIAG_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRPOSDIAG_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRPOSDIAG_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_MTRPOSCH2_APPL)  **************/

/* used for references on application variables */
# define RTE_SA_MTRPOSCH2_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRPOSCH2_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRPOSCH2_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_SA_MTRPOSSNSRLEARNING_APPL)  *****/

/* used for references on application variables */
# define RTE_SA_MTRPOSSNSRLEARNING_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_SA_MTRPOSSNSRLEARNING_APPL_DATA

/* used for references on application functions */
# define RTE_SA_MTRPOSSNSRLEARNING_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_EDCH_APPL)  **********************/

/* used for references on application variables */
# define RTE_EDCH_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_EDCH_APPL_DATA

/* used for references on application functions */
# define RTE_EDCH_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_TEST_APPL)  **********************/

/* used for references on application variables */
# define RTE_TEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_TEST_APPL_DATA

/* used for references on application functions */
# define RTE_TEST_APPL_CODE

/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 1455040902
#    error "The magic number of the generated file <c:/Build/BMW/ses_dev_ea3/BMW_MCV_UKL_EPS_TMS570_F40_Working/BMW_UKL_MCV_EPS_TMS570/SwProject/Source/GenDataRte/Production/Rte_Compiler_Cfg.h> is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 1455040902
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* _RTE_COMPILER_CFG_H */
