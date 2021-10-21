/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2008-2011 by Vctr Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SchM_Cfg.h
 *        Config:  ECUC
 *  Generated at:  Sat Sep 13 15:09:32 2014
 *
 *     Generator:  MICROSAR SchM Generator Version 03.00.02
 *
 *   Description:  Configuration of BSW Scheduler
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Sun Aug 28 08:04:40 2011
 * %version:          14 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Wed Apr  3 15:21:01 2013 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/28/11   5       LWW       Added SPIDriver Resource handling
 * 10/09/11   7       LWW       Changed Ea to Fee MainFunction for MemStack resource
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#ifndef SCHM_CFG_H
# define SCHM_CFG_H

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define SchM_NvM_MainFunction_Start()		GetResource(OsRes_MemStackTask)
#define SchM_NvM_MainFunction_Return()		ReleaseResource(OsRes_MemStackTask)

#define SchM_Fee_MainFunction_Start()	GetResource(OsRes_MemStackTask);
#define SchM_Fee_MainFunction_Return()	ReleaseResource(OsRes_MemStackTask);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!        << End of include and declaration area >>             DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

# include "Os.h"

/**********************************************************************************************************************
 * Trigger Information:
 * Task SchM_100ms_Task10 Cycle Time 100 ms Alarm Offset 0 ms
 * Task SchM_Task Cycle Time 5 ms Alarm Offset 0 ms
 * Task SchM_Task2 Cycle Time 5 ms Alarm Offset 3 ms
 * Mainfunction EPSDiagSrvcs_Task() Cycle Time 10 ms Activation Offset 3 ms
 * Mainfunction Com_MainFunctionRx() Cycle Time 5 ms Activation Offset 0 ms
 * Mainfunction Com_MainFunctionTx() Cycle Time 5 ms Activation Offset 0 ms
 * Mainfunction ComM_MainFunction_0() Cycle Time 20 ms Activation Offset 3 ms
 * Mainfunction Darh_Main() Cycle Time 10 ms Activation Offset 0 ms
 * Mainfunction Dcm_MainFunction() Cycle Time 10 ms Activation Offset 0 ms
 * Mainfunction Dem_MainFunction() Cycle Time 5 ms Activation Offset 3 ms
 * Mainfunction EcuM_MainFunction() Cycle Time 10 ms Activation Offset 3 ms
 * Mainfunction Fee_MainFunction() Cycle Time 100 ms Activation Offset 0 ms
 * Mainfunction FrIf_MainFunction_0() Cycle Time 5 ms Activation Offset 0 ms
 * Mainfunction FrSm_MainFunction_0() Cycle Time 5 ms Activation Offset 0 ms
 * Mainfunction FrTp_MainFunction() Cycle Time 5 ms Activation Offset 0 ms
 * Mainfunction FrTrcv_30_Tja1080_MainFunction() Cycle Time 5 ms Activation Offset 3 ms
 * Mainfunction FrXcp_MainFunctionRx() Cycle Time 10 ms Activation Offset 0 ms
 * Mainfunction FrXcp_MainFunctionTx() Cycle Time 10 ms Activation Offset 0 ms
 * Mainfunction IpduM_MainFunction() Cycle Time 10 ms Activation Offset 0 ms
 * Mainfunction NvM_MainFunction() Cycle Time 100 ms Activation Offset 3 ms
 * Mainfunction NvMProxy_MainFunction() Cycle Time 100 ms Activation Offset 3 ms
 * Mainfunction SrlComOutput_MainFunction() Cycle Time 5 ms Activation Offset 0 ms
 * Mainfunction SysTimeClient_MainFunction() Cycle Time 10 ms Activation Offset 0 ms
 * Mainfunction TcFlshPrg_Per1() Cycle Time 10 ms Activation Offset 3 ms
 * Mainfunction Vsm_MainFunction() Cycle Time 10 ms Activation Offset 0 ms
 * Mainfunction XcpBackground() Cycle Time 5 ms Activation Offset 3 ms
 *********************************************************************************************************************/

# ifndef SchM_ComM_MainFunction_0_Start
#  define SchM_ComM_MainFunction_0_Start() ((void)(0))
# endif

# ifndef SchM_ComM_MainFunction_0_Return
#  define SchM_ComM_MainFunction_0_Return() ((void)(0))
# endif

# ifndef SchM_Com_MainFunctionRx_Start
#  define SchM_Com_MainFunctionRx_Start() ((void)(0))
# endif

# ifndef SchM_Com_MainFunctionRx_Return
#  define SchM_Com_MainFunctionRx_Return() ((void)(0))
# endif

# ifndef SchM_Com_MainFunctionTx_Start
#  define SchM_Com_MainFunctionTx_Start() ((void)(0))
# endif

# ifndef SchM_Com_MainFunctionTx_Return
#  define SchM_Com_MainFunctionTx_Return() ((void)(0))
# endif

# ifndef SchM_Darh_Main_Start
#  define SchM_Darh_Main_Start() ((void)(0))
# endif

# ifndef SchM_Darh_Main_Return
#  define SchM_Darh_Main_Return() ((void)(0))
# endif

# ifndef SchM_Dcm_MainFunction_Start
#  define SchM_Dcm_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_Dcm_MainFunction_Return
#  define SchM_Dcm_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_Dem_MainFunction_Start
#  define SchM_Dem_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_Dem_MainFunction_Return
#  define SchM_Dem_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_EPSDiagSrvcs_Task_Start
#  define SchM_EPSDiagSrvcs_Task_Start() ((void)(0))
# endif

# ifndef SchM_EPSDiagSrvcs_Task_Return
#  define SchM_EPSDiagSrvcs_Task_Return() ((void)(0))
# endif

# ifndef SchM_EcuM_MainFunction_Start
#  define SchM_EcuM_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_EcuM_MainFunction_Return
#  define SchM_EcuM_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_Fee_MainFunction_Start
#  define SchM_Fee_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_Fee_MainFunction_Return
#  define SchM_Fee_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_FrIf_MainFunction_0_Start
#  define SchM_FrIf_MainFunction_0_Start() ((void)(0))
# endif

# ifndef SchM_FrIf_MainFunction_0_Return
#  define SchM_FrIf_MainFunction_0_Return() ((void)(0))
# endif

# ifndef SchM_FrSm_MainFunction_0_Start
#  define SchM_FrSm_MainFunction_0_Start() ((void)(0))
# endif

# ifndef SchM_FrSm_MainFunction_0_Return
#  define SchM_FrSm_MainFunction_0_Return() ((void)(0))
# endif

# ifndef SchM_FrTp_MainFunction_Start
#  define SchM_FrTp_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_FrTp_MainFunction_Return
#  define SchM_FrTp_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_FrTrcv_30_Tja1080_MainFunction_Start
#  define SchM_FrTrcv_30_Tja1080_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_FrTrcv_30_Tja1080_MainFunction_Return
#  define SchM_FrTrcv_30_Tja1080_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_FrXcp_MainFunctionRx_Start
#  define SchM_FrXcp_MainFunctionRx_Start() ((void)(0))
# endif

# ifndef SchM_FrXcp_MainFunctionRx_Return
#  define SchM_FrXcp_MainFunctionRx_Return() ((void)(0))
# endif

# ifndef SchM_FrXcp_MainFunctionTx_Start
#  define SchM_FrXcp_MainFunctionTx_Start() ((void)(0))
# endif

# ifndef SchM_FrXcp_MainFunctionTx_Return
#  define SchM_FrXcp_MainFunctionTx_Return() ((void)(0))
# endif

# ifndef SchM_IpduM_MainFunction_Start
#  define SchM_IpduM_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_IpduM_MainFunction_Return
#  define SchM_IpduM_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_NvMProxy_MainFunction_Start
#  define SchM_NvMProxy_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_NvMProxy_MainFunction_Return
#  define SchM_NvMProxy_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_NvM_MainFunction_Start
#  define SchM_NvM_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_NvM_MainFunction_Return
#  define SchM_NvM_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_SrlComOutput_MainFunction_Start
#  define SchM_SrlComOutput_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_SrlComOutput_MainFunction_Return
#  define SchM_SrlComOutput_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_SysTimeClient_MainFunction_Start
#  define SchM_SysTimeClient_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_SysTimeClient_MainFunction_Return
#  define SchM_SysTimeClient_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_TcFlshPrg_Per1_Start
#  define SchM_TcFlshPrg_Per1_Start() ((void)(0))
# endif

# ifndef SchM_TcFlshPrg_Per1_Return
#  define SchM_TcFlshPrg_Per1_Return() ((void)(0))
# endif

# ifndef SchM_Vsm_MainFunction_Start
#  define SchM_Vsm_MainFunction_Start() ((void)(0))
# endif

# ifndef SchM_Vsm_MainFunction_Return
#  define SchM_Vsm_MainFunction_Return() ((void)(0))
# endif

# ifndef SchM_XcpBackground_Start
#  define SchM_XcpBackground_Start() ((void)(0))
# endif

# ifndef SchM_XcpBackground_Return
#  define SchM_XcpBackground_Return() ((void)(0))
# endif

# ifndef SchM_EnterHook_Adc_Start
#  define SchM_EnterHook_Adc_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Adc_Return
#  define SchM_EnterHook_Adc_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Adc_Start
#  define SchM_ExitHook_Adc_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Adc_Return
#  define SchM_ExitHook_Adc_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_CMS_Common_Start
#  define SchM_EnterHook_CMS_Common_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_CMS_Common_Return
#  define SchM_EnterHook_CMS_Common_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_CMS_Common_Start
#  define SchM_ExitHook_CMS_Common_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_CMS_Common_Return
#  define SchM_ExitHook_CMS_Common_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Coding_Start
#  define SchM_EnterHook_Coding_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Coding_Return
#  define SchM_EnterHook_Coding_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Coding_Start
#  define SchM_ExitHook_Coding_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Coding_Return
#  define SchM_ExitHook_Coding_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Com_Start
#  define SchM_EnterHook_Com_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Com_Return
#  define SchM_EnterHook_Com_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Com_Start
#  define SchM_ExitHook_Com_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Com_Return
#  define SchM_ExitHook_Com_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_ComM_Start
#  define SchM_EnterHook_ComM_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_ComM_Return
#  define SchM_EnterHook_ComM_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_ComM_Start
#  define SchM_ExitHook_ComM_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_ComM_Return
#  define SchM_ExitHook_ComM_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Darh_Start
#  define SchM_EnterHook_Darh_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Darh_Return
#  define SchM_EnterHook_Darh_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Darh_Start
#  define SchM_ExitHook_Darh_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Darh_Return
#  define SchM_ExitHook_Darh_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Dcm_Start
#  define SchM_EnterHook_Dcm_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Dcm_Return
#  define SchM_EnterHook_Dcm_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Dcm_Start
#  define SchM_ExitHook_Dcm_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Dcm_Return
#  define SchM_ExitHook_Dcm_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Dem_Start
#  define SchM_EnterHook_Dem_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Dem_Return
#  define SchM_EnterHook_Dem_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Dem_Start
#  define SchM_ExitHook_Dem_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Dem_Return
#  define SchM_ExitHook_Dem_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Det_Start
#  define SchM_EnterHook_Det_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Det_Return
#  define SchM_EnterHook_Det_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Det_Start
#  define SchM_ExitHook_Det_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Det_Return
#  define SchM_ExitHook_Det_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Dio_Start
#  define SchM_EnterHook_Dio_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Dio_Return
#  define SchM_EnterHook_Dio_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Dio_Start
#  define SchM_ExitHook_Dio_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Dio_Return
#  define SchM_ExitHook_Dio_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_EcuM_Start
#  define SchM_EnterHook_EcuM_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_EcuM_Return
#  define SchM_EnterHook_EcuM_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_EcuM_Start
#  define SchM_ExitHook_EcuM_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_EcuM_Return
#  define SchM_ExitHook_EcuM_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Fee_Start
#  define SchM_EnterHook_Fee_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Fee_Return
#  define SchM_EnterHook_Fee_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Fee_Start
#  define SchM_ExitHook_Fee_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Fee_Return
#  define SchM_ExitHook_Fee_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Fr_Start
#  define SchM_EnterHook_Fr_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Fr_Return
#  define SchM_EnterHook_Fr_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Fr_Start
#  define SchM_ExitHook_Fr_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Fr_Return
#  define SchM_ExitHook_Fr_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrIf_Start
#  define SchM_EnterHook_FrIf_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrIf_Return
#  define SchM_EnterHook_FrIf_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_FrIf_Start
#  define SchM_ExitHook_FrIf_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_FrIf_Return
#  define SchM_ExitHook_FrIf_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrSM_Start
#  define SchM_EnterHook_FrSM_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrSM_Return
#  define SchM_EnterHook_FrSM_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_FrSM_Start
#  define SchM_ExitHook_FrSM_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_FrSM_Return
#  define SchM_ExitHook_FrSM_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrTp_Start
#  define SchM_EnterHook_FrTp_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrTp_Return
#  define SchM_EnterHook_FrTp_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_FrTp_Start
#  define SchM_ExitHook_FrTp_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_FrTp_Return
#  define SchM_ExitHook_FrTp_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrTrcv_30_Tja1080_Start
#  define SchM_EnterHook_FrTrcv_30_Tja1080_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrTrcv_30_Tja1080_Return
#  define SchM_EnterHook_FrTrcv_30_Tja1080_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_FrTrcv_30_Tja1080_Start
#  define SchM_ExitHook_FrTrcv_30_Tja1080_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_FrTrcv_30_Tja1080_Return
#  define SchM_ExitHook_FrTrcv_30_Tja1080_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrXcp_Start
#  define SchM_EnterHook_FrXcp_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_FrXcp_Return
#  define SchM_EnterHook_FrXcp_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_FrXcp_Start
#  define SchM_ExitHook_FrXcp_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_FrXcp_Return
#  define SchM_ExitHook_FrXcp_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Gpt_Start
#  define SchM_EnterHook_Gpt_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Gpt_Return
#  define SchM_EnterHook_Gpt_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Gpt_Start
#  define SchM_ExitHook_Gpt_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Gpt_Return
#  define SchM_ExitHook_Gpt_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_IoHwAb_Start
#  define SchM_EnterHook_IoHwAb_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_IoHwAb_Return
#  define SchM_EnterHook_IoHwAb_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_IoHwAb_Start
#  define SchM_ExitHook_IoHwAb_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_IoHwAb_Return
#  define SchM_ExitHook_IoHwAb_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_IpduM_Start
#  define SchM_EnterHook_IpduM_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_IpduM_Return
#  define SchM_EnterHook_IpduM_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_IpduM_Start
#  define SchM_ExitHook_IpduM_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_IpduM_Return
#  define SchM_ExitHook_IpduM_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Mcu_Start
#  define SchM_EnterHook_Mcu_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Mcu_Return
#  define SchM_EnterHook_Mcu_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Mcu_Start
#  define SchM_ExitHook_Mcu_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Mcu_Return
#  define SchM_ExitHook_Mcu_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_NvM_Start
#  define SchM_EnterHook_NvM_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_NvM_Return
#  define SchM_EnterHook_NvM_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_NvM_Start
#  define SchM_ExitHook_NvM_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_NvM_Return
#  define SchM_ExitHook_NvM_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_NvMProxy_Start
#  define SchM_EnterHook_NvMProxy_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_NvMProxy_Return
#  define SchM_EnterHook_NvMProxy_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_NvMProxy_Start
#  define SchM_ExitHook_NvMProxy_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_NvMProxy_Return
#  define SchM_ExitHook_NvMProxy_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_PduR_Start
#  define SchM_EnterHook_PduR_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_PduR_Return
#  define SchM_EnterHook_PduR_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_PduR_Start
#  define SchM_ExitHook_PduR_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_PduR_Return
#  define SchM_ExitHook_PduR_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Port_Start
#  define SchM_EnterHook_Port_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Port_Return
#  define SchM_EnterHook_Port_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Port_Start
#  define SchM_ExitHook_Port_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Port_Return
#  define SchM_ExitHook_Port_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Spi_Start
#  define SchM_EnterHook_Spi_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Spi_Return
#  define SchM_EnterHook_Spi_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Spi_Start
#  define SchM_ExitHook_Spi_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Spi_Return
#  define SchM_ExitHook_Spi_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_SpiNxt_Start
#  define SchM_EnterHook_SpiNxt_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_SpiNxt_Return
#  define SchM_EnterHook_SpiNxt_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_SpiNxt_Start
#  define SchM_ExitHook_SpiNxt_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_SpiNxt_Return
#  define SchM_ExitHook_SpiNxt_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_SrlComOutput_Start
#  define SchM_EnterHook_SrlComOutput_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_SrlComOutput_Return
#  define SchM_EnterHook_SrlComOutput_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_SrlComOutput_Start
#  define SchM_ExitHook_SrlComOutput_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_SrlComOutput_Return
#  define SchM_ExitHook_SrlComOutput_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_SysTimeClient_Start
#  define SchM_EnterHook_SysTimeClient_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_SysTimeClient_Return
#  define SchM_EnterHook_SysTimeClient_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_SysTimeClient_Start
#  define SchM_ExitHook_SysTimeClient_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_SysTimeClient_Return
#  define SchM_ExitHook_SysTimeClient_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_TcFlshPrg_Start
#  define SchM_EnterHook_TcFlshPrg_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_TcFlshPrg_Return
#  define SchM_EnterHook_TcFlshPrg_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_TcFlshPrg_Start
#  define SchM_ExitHook_TcFlshPrg_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_TcFlshPrg_Return
#  define SchM_ExitHook_TcFlshPrg_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Vsm_Client_Start
#  define SchM_EnterHook_Vsm_Client_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Vsm_Client_Return
#  define SchM_EnterHook_Vsm_Client_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Vsm_Client_Start
#  define SchM_ExitHook_Vsm_Client_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Vsm_Client_Return
#  define SchM_ExitHook_Vsm_Client_Return(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Xcp_Start
#  define SchM_EnterHook_Xcp_Start(ExclusiveArea)  ((void)(0))
# endif

# ifndef SchM_EnterHook_Xcp_Return
#  define SchM_EnterHook_Xcp_Return(ExclusiveArea) ((void)(0))
# endif

# ifndef SchM_ExitHook_Xcp_Start
#  define SchM_ExitHook_Xcp_Start(ExclusiveArea)   ((void)(0))
# endif

# ifndef SchM_ExitHook_Xcp_Return
#  define SchM_ExitHook_Xcp_Return(ExclusiveArea)  ((void)(0))
# endif


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* SCHM_CFG_H */

