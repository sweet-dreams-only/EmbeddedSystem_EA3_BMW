/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  IoHwAb10.c
 *     Workspace:  C:/ccm_wa/EPS/570/I410/BMW_UKL_MCV_EPS_TMS570/SwProject/IoHwAbstractionUsr/autosar
 *     SW-C Type:  IoHwAb10
 *  Generated at:  Wed Jan 23 10:15:33 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <IoHwAb10>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Sun Nov 14 12:00:00 2010
 * %version:          13 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Tue May 28 15:52:21 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author    Change Description                                                               SCR #
 * -------   -------  --------  -------------------------------------------------------------------------------  ------
 * 01/24/13   1	    JJW		 Initial creation
 * 05/28/13   13	KJS		 QAC corrections
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_IoHwAb10.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Nhet.h"

/* FDD47 sec 5.1.2.4 required defines for PDControlStat */
#define D_PDCONTROLSTATOPEN_CNT_U08		(uint8)0u
#define D_PDCONTROLSTATCLOSED_CNT_U08	(uint8)6u

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Float: D_ZERO_ULS_F32 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_IOHWAB10_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NHETSigCtrl_GetPhaseDisconnectSignal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetPhaseDisconnectSignal> of PortPrototype <NHETSigCtrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NHETSigCtrl_GetPhaseDisconnectSignal(UInt8 *Signal_Cnt_T_u08)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB10_APPL_CODE) NHETSigCtrl_GetPhaseDisconnectSignal(P2VAR(UInt8, AUTOMATIC, RTE_IOHWAB10_APPL_VAR) Signal_Cnt_T_u08)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NHETSigCtrl_GetPhaseDisconnectSignal
 *********************************************************************************************************************/
	/* FDD47 v007 sec. 5.1.2.4 implies that the desired return value is PWM period value.  It explicitly states 0
	 * for phase disconnect Open (STDF_OFF), and 6 for phase disconnect Closed (STD_ON).
	 * The Nhet Get command API merely returns STD_ON or STD_OFF
	 */
	if( STD_OFF == GetPhaseDscntCmd_m())
	{
		*Signal_Cnt_T_u08 = D_PDCONTROLSTATOPEN_CNT_U08;
	}
	else
	{
		*Signal_Cnt_T_u08 = D_PDCONTROLSTATCLOSED_CNT_U08;
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NHETSigCtrl_SetPhaseDisconnectSignal
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetPhaseDisconnectSignal> of PortPrototype <NHETSigCtrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void NHETSigCtrl_SetPhaseDisconnectSignal(Boolean Signal_Cnt_T_lgc)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_IOHWAB10_APPL_CODE) NHETSigCtrl_SetPhaseDisconnectSignal(Boolean Signal_Cnt_T_lgc)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: NHETSigCtrl_SetPhaseDisconnectSignal
 *********************************************************************************************************************/
  if(STD_ON == Signal_Cnt_T_lgc)
  {
  	SetPhaseDscntOn_m();
  }
  else
  {
  	SetPhaseDscntOff_m();
  }	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_IOHWAB10_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
