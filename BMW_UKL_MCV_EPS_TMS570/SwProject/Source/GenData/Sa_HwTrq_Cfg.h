
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Sa_HwTrq_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 12.08.2015 09:55:35
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          EA3#5 %
 * %date_modified:    Thu Sep 27 10:20:52 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 	 	
 */

#ifndef SA_HWTRQ_CFG_H
#define SA_HWTRQ_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/


#define BC_HWTRQ_SENSRANGCHK	STD_OFF


/* Disable all checkpoints that are not enabled */
#define Rte_Call_HwTrq_Per1_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_HwTrq_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_HwTrq_Per2_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_HwTrq_Per2_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_HwTrq_Per3_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_HwTrq_Per3_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 

#endif /* HWTRQ_CFG_H */

/*** End of file **************************************************************/
