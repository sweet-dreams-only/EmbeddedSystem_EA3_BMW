/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_PrimaryShutdown.c
 *     Workspace:  C:/ccm_wa/EPS/570/BMW_UKL_MCV_EPS_TMS570/Tools/AsrConfig/DCF/EPS.dcf
 *   ECU-Project:  EPS
 *     SW-C Type:  Sa_PrimaryShutdown
 *  Generated at:  Fri Apr 15 17:28:23 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1000133 valid until 2011-12-09 for CBD1000133 Nxtr  BMW BAC2.1 Prototype Bundle TMS570 / TMS570LS101SPGEQ  / TMS470 Compiler CGT 4.6.2
 *
 *   Description:  C-Code implementation template for SW-C <Sa_PrimaryShutdown>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Thu Apr 15 19:27:06 2011
 * %version:          2 %
 * %derived_by:       czgng4 %
 * %date_modified:    Thu Apr 15 19:27:06 2011 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/15/11  2        LWW       Initial version
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

#include "Rte_Sa_PrimaryShutdown.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Nhet.h"

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


#define RTE_START_SEC_SA_PRIMARYSHUTDOWN_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PrimShtdn_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_PRIMARYSHUTDOWN_APPL_CODE) PrimShtdn_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PrimShtdn_Init
 *********************************************************************************************************************/
	
	NHET0->NHETDIR = NHET0->NHETDIR  & 0xFEABFFBB;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PrimShtdn_Trns1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_PRIMARYSHUTDOWN_APPL_CODE) PrimShtdn_Trns1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PrimShtdn_Trns1
 *********************************************************************************************************************/

	NHET0->NHETDIR = NHET0->NHETDIR  | 0x01540044;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PrimShtdn_Trns2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on exiting of Mode <OPERATE> of ModeDeclarationGroupPrototype <Mode> of PortPrototype <SystemState>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_PRIMARYSHUTDOWN_APPL_CODE) PrimShtdn_Trns2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PrimShtdn_Trns2
 *********************************************************************************************************************/
 	
 	NHET0->NHETDIR = NHET0->NHETDIR  & 0xFEABFFBB;
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_PRIMARYSHUTDOWN_APPL_CODE
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
