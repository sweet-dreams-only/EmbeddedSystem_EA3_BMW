
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Ap_DigPhsReasDiag_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 18.02.2013 14:00:52
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          4 %
 * %date_modified:    Thu May 16 10:59:01 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 	 	
 */

#ifndef AP_DIGPHSREASDIAG_CFG_H
#define AP_DIGPHSREASDIAG_CFG_H


/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/



/* Disable all checkpoints that are not enabled */
extern void Rte_Call_DigPhsReasDiag_Per1_CP0_CheckpointReached(void);	 /* Checkpoint disabled */	 
extern void Rte_Call_DigPhsReasDiag_Per1_CP1_CheckpointReached(void);	 /* Checkpoint disabled */	 

#define D_NHETFREQUENCY_HZ_F32		80000000.0F
#define D_MAXPWMFREQ_HZ_U32 18000U
   
#endif /* DIGPHSREASDIAG_CFG_H */

/*** End of file **************************************************************/
