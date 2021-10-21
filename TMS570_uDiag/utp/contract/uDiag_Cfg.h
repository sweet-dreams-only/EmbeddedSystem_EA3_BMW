
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : uDiag_Cfg.h
* Module Description: Configuration file of uDiag module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 08.01.2014 14:52:46
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          5 %
 * %date_modified:    Thu Jan  9 10:58:18 2014 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/17/12   1       JJW       Initial template creation
 * 09/25/12   2       JJW       Added VIM Table name configuration
 * 10/04/12   4       JJW       Added support for link-time register value determination
 * 11/29/12   7       JJW       Added support for Wdg configuration
 * 06/26/13   8       KMC       Added D_ENABLEFPUDIAG_CNT_LGC for enable/disable of FPU exception handling      7139
 * 10/10/13   9       KMC       Added BC_UDIAG_GLADIATORCOMPATIBLE for ESM group 1 channel 7 vs group 1        10404
 *                              channel 34 NHET2 parity error  
 *                              Added BC_UDIAG_UDIAGVIMPERTRUSTED for trusted function from uDiagVIM_Per       10408
 * 01/08/14   10      KMC       Added BC_UDIAG_UDIAGECCPERTRUSTED for trusted function from uDiagECC_Per       11176
 */

#ifndef UDIAG_CFG_H
#define UDIAG_CFG_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*** Public Part (used by uDiag API) *****************************************/
#include "Std_Types.h"                   /* Standard type definitions      */



/* Disable all checkpoints that are not enabled */
extern void Rte_Call_uDiagLossOfExec_Per2_CP0_CheckpointReached(void);	 
extern void Rte_Call_uDiagLossOfExec_Per2_CP1_CheckpointReached(void);	
extern void Rte_Call_uDiagLossOfExec_Per3_CP1_CheckpointReached(void);	
extern void Rte_Call_uDiagLossOfExec_Per3_CP0_CheckpointReached(void);	
extern void Rte_Call_uDiagStaticRegs_Per_CP0_CheckpointReached(void);	
extern void Rte_Call_uDiagStaticRegs_Per_CP1_CheckpointReached(void);	
extern void Rte_Call_uDiagVIM_Per_CP0_CheckpointReached(void);	
extern void Rte_Call_uDiagVIM_Per_CP1_CheckpointReached(void);	
extern void Rte_Call_uDiagECC_Per_CP0_CheckpointReached(void);	
extern void Rte_Call_uDiagECC_Per_CP1_CheckpointReached(void); 

/*** Private Part (used by internal uDiag files only) *************************************/
#ifdef UDIAG_C

#define BC_WDGM_NONE						STD_ON
#define BC_WDGM_TTTECH_V2_0_3				STD_OFF

#define D_NUMOFTESTEDREGS_CNT_U16	202u

/* Enable Floating Point Exception Diagnostic. */
#define D_ENABLEFPUDIAG_CNT_LGC			STD_OFF

/* Select ESM Channel 7 vs Channel 34 for NHET2 RAM Parity error. */
#define BC_UDIAG_GLADIATORCOMPATIBLE		STD_OFF

/* Frequency of the VCLK in kHz. */
#define D_VCLKFREQ_KHZ_U32			80000U

/* Name of the VIM initialization table in Flash */
#define D_VIMTABLENAME_CNT_U32		osaIRQTable

/* uDiag Register Verification Configuration Definitions */
typedef struct {
	VAR(uint32, AUTOMATIC) 	Address;						/* The first element is the register pointer */
	VAR(uint32, AUTOMATIC) 	Value;							/* The second element is a 32-bit value */
}uDiag_RegChkType;

extern CONST(uDiag_RegChkType, AUTOMATIC) StaticRegTable_Cnt_M_str[ D_NUMOFTESTEDREGS_CNT_U16 ];


#endif /* UDIAG_C                                                            */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

/*** Public Part (uDiag API) *****************************************/

/*
 * File version information
 */
#define UDIAG_CFG_H_MAJOR_VERSION   1u
#define UDIAG_CFG_H_MINOR_VERSION   0u
#define UDIAG_CFG_H_PATCH_VERSION   0u

/*
 * API enable settings
 */

 /* uDiagVIM_Per is in a trusted task. */
#define BC_UDIAG_UDIAGVIMPERTRUSTED			STD_OFF

/* uDiagECC_Per is in a trusted task. */
#define BC_UDIAG_UDIAGECCPERTRUSTED			STD_OFF

#endif /* UDIAG_CFG_H */

/*** End of file **************************************************************/
