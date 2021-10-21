/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Appl_ComCbk.h
* Module Description: GENy defined Callback functions
* Product           : Gen II Plus - EA3.0
* Author            : Bobby O'Steen
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Dec 2 16:24:22 2010
* %version:          8 %
* %derived_by:       wz7x3j %
* %date_modified:    Thu Sep  8 17:16:38 2011 % 
*---------------------------------------------------------------------------*/
#ifndef APPL_COMCBK_H_
#define APPL_COMCBK_H_

#include "Std_Types.h"
#include "Compiler.h" 

extern FUNC(void, SYSTIMECLIENT_PUBLIC_CODE) Rte_COMCbk_Com_T_SEC_COU_REL__RELATIVZEIT(void);
                                             
extern FUNC(void, RTE_APPL_CODE) Vsm_ClampRxNotification(void); 		/* Signal Handle: 35, Com_ST_KL__KLEMMEN */
extern FUNC(void, RTE_APPL_CODE) Vsm_OpStateRxNotification(void);		/* Signal Handle: 37, Com_ST_VEH_CON__KLEMMEN */
extern FUNC(void, RTE_APPL_CODE) Vsm_EnergyStateRxNotification(void); 	/* Signal Handle: 42, Com_TEMP_EX__A_TEMP */ 
extern FUNC(void, RTE_APPL_CODE) Vsm_CelRxNotification(void);  			/* Signal Handle: 33, Com_ST_ILK_ERRM_FZM__FZZSTD */
extern FUNC(void, RTE_APPL_CODE) KILOMETERSTAND_Rx_MILE_KM_SignalIndication(void);

/* Vector ComTxPduCallout workaround */
extern VAR(boolean, AP_SRLCOMOUTPUT_VAR_NOINIT) ComTxPduCallout_lgc;

#endif /*APPL_COMCBK_H_*/


/******************************************************************************
CHANGE HISTORY:

 Date      Rev      Author 			Change Description								   SCR #
 				 					 (MDD Rev & Date)
-------   -------  --------  -----------------------------------					----------
12/03/10  1.0      B.OSteen  Initial version. Provides Workaround for Rx Signal
							 Indication callbacks in BAC 2.1. This file will be
							 generated by GENy in the BAC 3.0 SIP. 
1/21/11   2.0      B.OSteen  Updated Rte_COMCbk_Com_T_SEC_COU_REL__RELATIVZEIT,
                             with additional underscore added to updated Fibex.
2/01/11   3.0      B.OSteen  Added Rte_COMCbkTAck functions to process alive counters
2/10/11   4.0      B.OSteen  Added Vsm_xxx Rx notification functions
3/22/11   6.0      BDO       Anomaly 2097 corrections    
8/29/11   7.0      BDO       Remove ComTxPduCallout_lgc flag   
9/08/11   8.0      BDO       Add ComTxPduCallout_lgc flag back - see anomaly 2506 for details                       
******************************************************************************/
