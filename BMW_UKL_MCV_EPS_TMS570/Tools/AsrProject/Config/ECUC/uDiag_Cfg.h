
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : uDiag_Cfg.h
* Module Description: Configuration file of uDiag module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 27.01.2013 14:54:15
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Mon Jan 28 12:39:56 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/17/12   1       JJW       Initial template creation
 * 09/25/12   2       JJW       Added VIM Table name configuration
 * 10/04/12   4       JJW       Added support for link-time register value determination
 * 11/29/12   7       JJW       Added support for Wdg configuration
 */

#ifndef UDIAG_CFG_H
#define UDIAG_CFG_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*** Public Part (used by uDiag API) *****************************************/
#include "Std_Types.h"                   /* Standard type definitions      */


/* uDiagLossOfExec_Per3_CP0 Checkpoint is enabled */
/* uDiagECC_Per_CP0 Checkpoint is enabled */

/* Disable all checkpoints that are not enabled */
#define Rte_Call_uDiagLossOfExec_Per2_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_uDiagLossOfExec_Per2_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_uDiagLossOfExec_Per3_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_uDiagStaticRegs_Per_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_uDiagStaticRegs_Per_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_uDiagVIM_Per_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_uDiagVIM_Per_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_uDiagECC_Per_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 

/*** Private Part (used by internal uDiag files only) *************************************/
#ifdef UDIAG_C

#define BC_WDGM_TTTECH_V2_0_3				STD_ON
#define BC_WDGM_NONE						STD_OFF
#define D_NUMOFSUPERVISEDENTITIES_CNT_U08	14u

#define D_NUMOFTESTEDREGS_CNT_U16	205u

/* Frequency of the VCLK in kHz. */
#define D_VCLKFREQ_KHZ_U32			75000U

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

   
#endif /* UDIAG_CFG_H */

/*** End of file **************************************************************/
