
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_SrlComOutput_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 25.10.2012 18:27:52
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Fri Oct 26 12:07:24 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 	 	
 */

#ifndef AP_SRLCOMOUTPUT_CFG_H
#define AP_SRLCOMOUTPUT_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/


/* Disable all checkpoints that are not enabled */
#define Rte_Call_SrlComOutput_Per1_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_SrlComOutput_Per1_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_SrlComOutput_Per2_CP0_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
#define Rte_Call_SrlComOutput_Per2_CP1_CheckpointReached()		(void)0 /* Checkpoint disabled */	 
   
#endif /* SRLCOMOUTPUT_CFG_H */

/*** End of file **************************************************************/