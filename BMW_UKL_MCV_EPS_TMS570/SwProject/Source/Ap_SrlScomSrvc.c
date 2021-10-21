/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_SrlScomSrvc.c
 *     Workspace:  C:/BMW_SynergyMerge/Merge5_ComTimingSrlComSvc/BMW_UKL_MCV_EPS_TMS570/Tools/AsrConfig/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *     SW-C Type:  Ap_SrlScomSrvc
 *  Generated at:  Fri Apr  1 18:19:15 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1000133 valid until 2011-12-09 for CBD1000133 Nxtr  BMW BAC2.1 Prototype Bundle TMS570 / TMS570LS101SPGEQ  / TMS470 Compiler CGT 4.6.2
 *
 *   Description:  C-Code implementation template for SW-C <Ap_SrlScomSrvc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Date      Rev      Author         Change Description                                      SCR #
 * -------   -------  --------  ----------------------------------------------------------  ----------
 * 04/01/11   1       BDO        Initial version template
 * 04/03/11   2       BDO		 Add EPSDiagSrvcs_Init(), EPSDiagSrvcs_Task(),  
 *								 CDCUser_Init() and CDCUser_Task() function calls.
 * 04/13/11   3       BDO		 Update SrlScomSrvc_Init() to call CDCUser_Init()
 * 06/06/12	  4 	  KJS		 Updatd SrlScomSrvc_Init() and Per1() for new CMS components. 
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Constants:
 ==========
  D_SFINVMILLI_ULS_F32
    Scale factor multiplier to convert a stanrd SI quantity into the SI milli unit (e.g. m to mm)

  D_SFMILLI_ULS_F32
    Scale factor multiplier to convert a SI milli quantity into the standard SI unit (e.g. mm to m)


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_SrlScomSrvc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "EPS_DiagSrvcs_SrvcLUTbl.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Float: D_MTRCTRLHIGHLMT_VOLTS_F32 = 18
 * Float: D_MTRCTRLLOWLMT_VOLTS_F32 = 9
 * Float: D_PI_ULS_F32 = 3.1415926535898
 * Float: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_SFMILLI_ULS_F32 = 0.001
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * UInt16: D_MAXCONF_ULS_U8P8 = 256u
 * UInt16: D_MTRPOLESDIV2_CNT_U16 = 3u
 * UInt16: D_QUADRANT1_CNT_U16 = 1u
 * UInt16: D_QUADRANT2_CNT_U16 = 2u
 * UInt16: D_QUADRANT3_CNT_U16 = 3u
 * UInt16: D_QUADRANT4_CNT_U16 = 4u
 * UInt32: D_SVCDFTDAMPING_CNT_B32 = 131072u
 * UInt32: D_SVCDFTENGON_CNT_B32 = 1u
 * UInt32: D_SVCDFTEOTIMPACT_CNT_B32 = 16u
 * UInt32: D_SVCDFTEOTTHERMAL_CNT_B32 = 32u
 * UInt32: D_SVCDFTFREQDEPDMP_CNT_B32 = 2u
 * UInt32: D_SVCDFTHYSTCOMP_CNT_B32 = 16384u
 * UInt32: D_SVCDFTKININTDIAG_CNT_B32 = 4u
 * UInt32: D_SVCDFTMODIDX_CNT_B32 = 512u
 * UInt32: D_SVCDFTMTRPARMNRMLRN_CNT_B32 = 128u
 * UInt32: D_SVCDFTMTRVELNRMLRN_CNT_B32 = 64u
 * UInt32: D_SVCDFTMULTIGNMASK_CNT_B32 = 1342177280u
 * UInt32: D_SVCDFTPULLCOMP_CNT_B32 = 1024u
 * UInt32: D_SVCDFTRETURN_CNT_B32 = 65536u
 * UInt32: D_SVCDFTRXMSGS_CNT_B32 = 134217728u
 * UInt32: D_SVCDFTTHERMALDC_CNT_B32 = 8u
 * UInt32: D_SVCDFTTRQRMP_CNT_B32 = 256u
 * UInt32: D_SVCDFTWHLIMBREJ_CNT_B32 = 2048u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_SRLSCOMSRVC_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlComSrvc_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 8ms
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLSCOMSRVC_APPL_CODE) SrlComSrvc_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlComSrvc_Per1
 *********************************************************************************************************************/
	
	CDCUser_Task();

	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SrlScomSrvc_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_SRLSCOMSRVC_APPL_CODE) SrlScomSrvc_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SrlScomSrvc_Init
 *********************************************************************************************************************/

	CDCUser_Init();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_SRLSCOMSRVC_APPL_CODE
#include "MemMap.h"


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
