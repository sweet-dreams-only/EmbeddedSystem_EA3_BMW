
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Sa_MtrPos2_Cfg.h
* Module Description: Configuration file of DiagMgr module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 29.01.2013 15:01:36
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Wed Feb 20 15:55:12 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/20/12   1       ssk       Initial template creation
 * 	 	
 */

#ifndef SA_MTRPOS_CFG_H
#define SA_MTRPOS_CFG_H

/*******************************************************************************
**                      Define Section                                       **
*******************************************************************************/

/* Generic definition for UTP access */
VAR(uint8, AUTOMATIC) MtrPos_ActvDblBuf_Cnt_u08;

#define CDD_Read_MtrPos_ActvDblBuf_Cnt_u08( ptr )		*(ptr) = MtrPos_ActvDblBuf_Cnt_u08
   
#endif /* MTRPOS_CFG_H */

/*** End of file **************************************************************/
