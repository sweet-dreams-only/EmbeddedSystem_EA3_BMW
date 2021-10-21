/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : EcuStartup.c
* Module Description: AUTOSAR Startup Sequence
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/* Version Control:
 * Date Created:      Thu Nov 11 16:33:22 2010
 * %version:          55 %
 * %date_modified:    Sat Jan 18 14:19:31 2014 % 
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 11/11/10   1.0      JJW      Initial file creation
 * 12/06/10   2.0      JJW      Added SystemTime_Init()
 * 12/07/10   3.0      JJW      Added Nhet_Init()
 * 12/08/10   4.0      JJW      Added Adc2_Init1() and Dma_Init1()
 * 12/08/10   5.0      JJW      Renamed Nhet_Init() to Nhet_Init1()
 * 12/14/10   6.0      LWW      Removed redundant IOHwAb_Init with 
 *                              developer defined init list
 * 12/16/10   7.0      BDO      Added SrlComSrvc_Init1()				CR3639
 * 12/19/10   8.0      JJW      Removed Dma Init
 * 12/21/10   9.0      LWW      Added PWM Init
 * 12/22/10   10.0     JJW      Added  XCP Cal RAM Init
 * 02/24/10   11.0     LWW      Added wait for NVM ReadAll to finish uploading
 * 12/16/10   11.1.1   BDO      Removed SrlComSrvc_Init1()
 * 12/16/10   11.1.2   BDO      Remove - include "SrlComSrvc.h"
 * 04/12/11   12.0     JJW      Added Metrics trace points for start-up metrics
 * 04/13/11   13       JJW      Added CrossChk_Init1
 * 04/19/11   14	   SMW      Removed Coding_Init function - will be called from
 *                              task_init through via RTE
 * 08/01/11   15	   JJW      BAC3.0 Initial integration
 * 08/16/11   16       YY       Enable interrupts for Turns Counter SPI
 * 08/17/11   17       JJW      Updated Eep Header file for new Eep BSW
 * 08/19/11   18       JJW      BAC3.0 integration removal of WdgM_Init function.
 * 08/20/11   19       JJW      Removed include for WdgM.h because the WdgM is being 
 *                              deactivated/remvoed from the project until integration
 *                              requirements are known.  This change uncovered that
 *                              Wdg.h was omitted from the includes, but is required for
 *                              the Wdg_Init function, so it was added.
 * 08/28/11   20       SMW      Added call to FreeTimer_Init for Seed request during coding
 *                              steps.  Used for Random number generation
 * 09/01/11   21       JJW      Removed Wdg.h and Wdg_Init calls because the safe watch dog is not
 *                              yet configured.	
 * 09/19/11   22       SMW      Added watchdog init and wdgM Init calls to init1 function
 * 10/19/11   22.1.2   LWW      Added Fee_Init and removed WdgM Init functions from Init1
 * 10/19/11   22.1.3   LWW      Added call to RestoreEaBlocks for FEE transition
 * 10/11/11   22.1.4   BDO      Add TcFlshPrg_Init() and mibspiInit() for Turns Counter programming
 * 10/14/11   22.1.5   LWW      Added calls for parity initialization
 * 09/21/11   23       JJW      Removed FreeTimer_Init() it is no longer necessary based on
 *                              the FreeTimer design changes to map to the SystemTick time source
 * 01/04/12   24.1.1   JJW      Added Init_TorqueScale to support EE data migration
 * 01/24/12   24.1.2   JJW      Added EccInit and associated changes to support enabling ECC
 * 03/14/12   24.1.2.1.1  JJW   Added SpiNxt_Init
 * 03/28/12   24.1.4   JJW      Metrics_Init() function name change for new metrics module integration
 * 04/17/12   24.1.5   JJW      Updates for multiple deprecated Ea block support
 * 05/02/12   27       JJW      Metrics v3 Integration
 * 05/30/12   28       JJW      Ea to Fee Block migration funciton call removed
 * 05/30/12   29       JJW      EccPrg removed
 * 06/16/12   30       NRAR     CrossChk_Init1() is removed/commented out
 * 06/29/12   31	   KJS		Added function call for DfltConfigData_Init1 in Init2.
 * 06/29/12   32	   BDO		Added DrvDynCtrl_Init()
 * 08/06/12   33	   KJS		Updated and removed init calls for microdiagnostics. 
 * 09/11/12   34	   KJS		Removed DrvDynCtrl_Init() for SF-33 DDC integration
 * 10/01/12   35  	   JJW		Re-order startup for Os v5.04 integration.  Any function using the
 *  							priv reg write API's must be run after Os Start(i.e. Init2).
 *  							Adc_Init does not require execution in Init1 as stated in previous
 *  							change entry.
 *								Remove CrossCheck include
 * 10/19/12   36  	   JJW		Trusted function call to PwmCdd to allow proper data access rights.
 * 11/14/12   37  	   JJW		Moved Tick enable to immediatley after Rte_Start
 * 11/14/12   38  	   JJW		
 * 11/15/12   39  	   KJS		Added Coding_Init() into the end of Init2. 
 * 11/21/12   42  	   JJW		Merged Wait state patch into file.
 * 12/04/12   43  	   KJS		Moved DfltConfigData in front of the NvMProxy Init call.
 * 12/07/12   44  	   JJW		Changed NvM Block Read order and processing to upload MEC and 
 *								associated blocks in order to perform initialization of ECU state
 *								prior to uploading other blocks which have conditional default init
 *								based on the ECU state.
 * 01/02/13   45  	   JJW		Replaced Xcp_CalRamInit with Xcp_Init for new Ap_Xcp Integration 
 * 04/02/13   46       JJW      Init_DeprecatedNvmBlock removal for implementation of CallBack strategy
 *								to improve start-up timing by eliminating need to always read deprecated blocks.
 * 04/03/13   47       JJW      NvMProxy_Init invocation order with respect to deprecated block reads queued
 *								read all corrected.
 * 04/11/13   49       KJS		Removed Coding_Init from EcuStartup_Init2, anomaly 4492
 * 05/22/13   50       JJW       Added Os Version API and display variable
 * 11/05/14	  52	   KJS		Added support for new suspend/resume erase and Fee
 * 12/09/14	  53	   KJS		Anomaly 7675 correction
 * 12/09/14	  54	   AS		GliwaT1 component integration
 * 05/05/15	  55	   ABS		EA3#1159 Duty cycle filters no reinitialized at startup
 * 08/25/16   56       RMV      With new uDiag integration(v18 to v30) the init function from Task_InitB_10 to EcuStartup_Init1()
                            
******************************************************************************/



/**************************************************************************************************
* Include files
**************************************************************************************************/

/*
 * Description: The V_Cfg header is generated by the generation tool. Important 
 *              information like CPU and compiler type, manufacturer information
 *              and a list of currently used CANbedded modules is defined here.
 */
#include "Std_Types.h"
#include "V_Cfg.h"
#include "SchM_Cfg.h"
#include "AddressTable.h"
#include "sc_ee_data.h"
#include "sc_target.h"
#include "DataLogistic.h"
#include "EcuStartup.h"
#include "Rte_Dcm.h"
#include "XcpProf.h"
#include "NvM_Cfg.h"
#include "ApplCallbacks.h"
#include "SystemTime.h"
#include "Nhet.h"
#include "Adc2.h"
#include "PwmCdd.h"
#include "T1_AppInterface.h"
#include "IpduM.h"
#include "Wdg_TMS570LS3x.h"
#include "Wdg_TMS570LS3x_Lcfg.h"
#include "WdgM.h"
#include "WdgM_PBcfg.h"
#include "Interrupts.h"
#include "SpiNxt.h"
#include "ti_fee.h" /* Required for suspend/resume erase API */
#include "trustfct.h"
#include "FlsTst.h"
#include "Cd_TcFlshPrg.h"
#include "Ap_ApXcp.h"
#include "NtWrap.h"
#include "Ap_DfltConfigData.h"
#include "Vsm_Client.h"
#include "EPS_DiagSrvcs_ISO.h"

/*Temporary edit to allow the change of the number of flash wait states in EcuStartup_Init1.*/
#include "system.h"




/*****************************************************************************
 * Include the CANbedded files 
 *****************************************************************************/
#if defined( VGEN_ENABLE_SYSSERVICE_ASRDET )
# include "Det.h"
#endif /* VGEN_ENABLE_SYSSERVICE_ASRDET */


# include "NvM.h"
# include "EcuM.h"
# include "SchM.h"
# include "Dem.h"
# include "MemIf_Types.h"
# include "Adc.h"
# include "Gpt.h"
# include "Mcu.h"
# include "Port.h"
# include "Spi.h"
# include "FrTrcv_30_Tja1080.h"
# include "FrIf.h"
# include "FrSm.h"
# include "FrTp.h"
# include "PduR.h"
# include "Com.h"
# include "ComM.h"
# include "Dcm.h"
# include "IoHwAb.h"
# include "Fr.h" 
# include "FrXcp.h"
# include "XcpProf.h"
# include "Coding.h"
# include "CDD_Func.h"
# include "FreeTimer.h"

#define ECUSTARTUP_START_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */

STATIC volatile VAR(uint16, ECUSTARTUP_VAR) EcuStartup_OsConfigBlockVersion_Cnt_D_u16;

#define ECUSTARTUP_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"/* PRQA S 5087 */


/*****************************************************************************
  * Name:        main
  * Description: 
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
int main(void) 
{
	T1_AppInit();

	osInitialize();

	EcuM_Init();
}

/*****************************************************************************
  * Name:        EcuStartup_Init1
  * Description: Initialization executed prior to OS start  
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
void EcuStartup_Init1(void) 
{

#if defined( VGEN_ENABLE_SYSSERVICE_ASRDET )
  Det_Init();
  Det_Start();  /* must be initialized before other components */
#endif

  /*Temporary edit to change number of flash wait states to 2dws/0aws. Should be replaced by a bootloader change.*/
  flashWREG->FRDCNTL = 0x00000201;

  VStdInitPowerOn();
  Dem_PreInit();
  FrTrcv_30_Tja1080_InitMemory();
  Fr_InitMemory();
  FrIf_InitMemory();
  FrXcp_InitMemory();
  XcpInitMemory();
  FrSM_InitMemory();
  ComM_InitMemory();
  Com_InitMemory();
  PduR_InitMemory();
  SchM_InitMemory();

  ApXcp_Init();
  Dma_Init1();
  FlsTst_Init(&FlsTst_Runtime);
  uDiagCCRM_Init();
  uDiagClockMonitor_Init();
  uDiagECC_Init();
  uDiagESM_Init();
  uDiagIOMM_Init();
	uDiagParity_Init();
	uDiagStaticRegs_Init();
	uDiagVIM_Init();
	uDiagPeriphMPU_Init();

  /* The design of Nhet_Init1() function requires execution in privileged mode because it initializes the
   * privileged HTU Data Packet Memory  without use of the Os Privileged register write API.
   */
  Nhet_Init1();

  Gpt_Init(&Gpt_Runtime);
  SpiNxt_Init();

}

/*****************************************************************************
  * Name:        EcuStartup_Init2
  * Description: Initialization executed after OS start  
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
void EcuStartup_Init2(void)
{


  /* Call the Os API for reporting the Os configuration version number as required by the Os Safety checks 
   * and provide the value in a Display variable for viewing via XCP.
   */
  EcuStartup_OsConfigBlockVersion_Cnt_D_u16 = osGetConfigBlockVersion();

  SystemTime_Init();
  /* Cold Init functions which require use of the uS System Time library must be scheduled after this point */
  NtWrapC_Adc_Init();
  Call_Adc2_Init1();
  /* Perform trusted function call to PwmCdd init to grant proper data access writes */
  Call_PwmCdd_Init();

  EnableCRCInterrupt();
  Spi_Init(&SpiRuntime);
  Port_Init(&Port_Runtime);
  SchM_Init();


  NvM_Init();
  TWrapC_FeeIf_Init();

  /* Read the MEC block first to determine the state of the ECU.  This must be done prior to reading other blocks
   * because the block default values for invalid blocks are conditional on the MEC state.
   * The EPS_DiagSrvcs_Init() function requires data from 2 other blocks as well, so those are also uploaded first.
   */

  /* Added the suspend/resume calls around the readall. Further analsis will need to be done to see if the resume 
   * call should be applied later in start up */
  TWrapC_TI_Fee_SuspendResumeErase(Suspend_Erase);

  NvM_ReadBlock(NVM_BLOCK_CMS_NXTRMEC, NULL_PTR);
  NvM_ReadBlock(NVM_BLOCK_CMS_IGNCNTR, NULL_PTR);
  NvM_ReadBlock(NVM_BLOCK_EPSDEFEATS, NULL_PTR);
  
  EnableTcSpiInterrupt();
  Appl_WaitNvMReady(NVM_BLOCK_CMS_NXTRMEC, TRUE);
  Appl_WaitNvMReady(NVM_BLOCK_CMS_IGNCNTR, TRUE);
  Appl_WaitNvMReady(NVM_BLOCK_EPSDEFEATS, TRUE);

  EPS_DiagSrvcs_Init();

  /* Perform Read All now that the criteria required for conditional initialization is read and initialized */
  NvM_ReadAll();
  /* TODO:  See if startup can be optimized to minimize NVM waiting */
  
  Appl_WaitNvMReady(0, TRUE);
  TWrapC_StaMd_Init0();


  TcFlshPrg_Init(); /* TcFlshPrg must be performed after NvMReadAll completes */

/* Moved DfltConfigData in front of the NvMProxy_init. This is because some of the values need to be copied
 * from unsecured memory locations to secured memory locations.
 *
 * TODO: Define proper trusted function calls to update the secured blocks so we meet the application
 * safety requirements.
 */
DfltConfigData_Init1();



  Dem_Init();

  TWrapC_TI_Fee_SuspendResumeErase(Resume_Erase);

  /* After the NvM driver has completed initializing the unsecured memory, execute the NvMProxy_Init to
  * transfer the data to secured memory and validate the contents of the memory.
  * Execution of the NvMProxy_Init function requires a trusted function call to place the system into a
  * privileged state that allows writing to the secured memory regions.
  *
  * NOTE: The NvMProxy_Init is scheduled after the Dem_Init to ensure that all deprecated block reads queued
  * during the ReadAll process are completed prior to executing the NvM Proxy to move the data to the
  * secured memory locations.  The Dem DataSet reads and waits ensure that the previously queued deprecated
  * block reads are completed by this point.
  */
  Call_NvMProxy_Init();


  FrTrcv_30_Tja1080_TrcvInit(0);
  Fr_Init(&Fr_Config);
  FrIf_Init(&FrIf_Config);
  FrSm_Init(&FrSMConfig);
  FrTp_Init();
  PduR_Init(&PduR_PBConfigStruct);
  Ipdum_Init(&IPduMConfig);
  Com_Init(&Com_ConfigStruct);
  ComM_Init();
  Dcm_Init();
  FrXcp_Init();
  XcpInit();
  Vsm_Init();
  EnableESMLInterrupt();

}

