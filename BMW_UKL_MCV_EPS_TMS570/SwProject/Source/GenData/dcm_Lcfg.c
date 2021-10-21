/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Dcm_Lcfg.h                                                     **
**                                                                            **
**  Copyright (C) BMW Group 2009                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PURPOSE   : Configuration file for Dcm                                    **
**                                                                            **
**  REMARKS   : File is generated with Artt                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
**  Initials     Name                       Company                           **
**  --------     -------------------------  --------------------------------- **
**  gan          Norbert Gaier              Softing AG                        **
**  scma         Scheitterer Martin         MB Technology                     **
**  wab          Wolfgang Aberle            MB Technology                     **
**  anam         Andreas Amann              MB Technology                     **
**  gema         Markus Gerngross           MB Technology                     **
*******************************************************************************/

/*******************************************************************************
**                    Revision Control History                                **
*******************************************************************************/


/*
 * v 1.1.26,2006.07.19, gan : DCM Module based on DCM specs v.2.0.0
 * v 2.0.0, 2007.09.28, gan : DCM Module + BMW Standard Core 7 additions
 * v 2.1.0, 2007.10.10, gan : Bug-fixing changes
 * v 2.1.1, 2007.10.17, gan : Bug-fixing changes
 * v 2.1.2, 2007.10.23, gan : Bug-fixing and enhancements
 * v 2.1.3, 2007.11.08, gan : Bug-fixing and enhancements
 * v 2.1.4, 2007.12.05, gan : Bug-fixing
 * v 2.1.5, 2008.02.07, gan : Bug-fixing
 * v 2.1.6, 2008.02.29, gan : Bug-fixing
 * v 2.1.7, 2008.06.06, gan : Bug-fixing
 * v 2.1.8, 2008.08.15, gan : Bug-fixing
 * v 2.1.9, 2008.10.31, gan : Bug-fixing
 * v 2.2.0, 2008.12.03, gan : DCM release 2.2.0 delivery
 * v 2.2.1, 2009.01.30, gan : Several changes requested by BMW
 * v 2.2.2, 2009.02.20, gan : Bug-fixing
 *   		2009.02.26, vm  : CR 70094 reworked 
 * v 2.2.3, 2009.03.27, gan : CR 70189: "Dcm_SuppressionOverride" flag is not reset.
 * v 2.2.4, 2009.04.22, vm  : CR 70194: Response behavior for functional adressed requests is not correct
 *          2009.04.22, vm  : CR 70200: S3 Timer handling not correct
 * v 2.3.0, 2009.08.04, scma: Initialize response data buffer with request
 *                            data buffer for Bootloader added
 * v 2.3.2, 2009.10.10, gan : CR 70286 Change storage classes in compiler abstraction for DCM
 *                            CR 70330 Dcm: wrong memory mapping
 *                            CR 70331 Dcm warnings
 *                            CR 70335 Dcm-Functionpointer corruption
 *                            CR 70351 Dcm source code has mismatching memory sections 
 *                            CR 70357 DCM: Behaviour when ResponsePending could not be sent
 *                            CR 70361 Dcm: compiler warning
 *          2010.11.02, gema: CR 70261 Dcm-Generator do not check validy of config
 *                            CR 70429 Relocation of wrapper between DCM and bootdiag 
 * v 2.3.3, 2009.11.02, anam: CR 70460: Code Size Optimization - Dcm - 
 *                                      BAC HIS implementation guidelines 
 *          2009.12.04, wab : CR 70338: DCM: Problems with DCMModuleGenerator.exe
 *                            CR 70339: Generator crashes when removing the 
 *                                      optional container DcmDspReadDTC
 *                            CR 70393: Arrays in dcm_cfg.h are badly formatted
 *                            CR 70344: DCM: PROTOCOL_LIMITSTIMING_STRUCTURE is
 *                                      generated with values of DCM_DEFAULT 
 *                            CR 70401: Errors in Dcm example configuration
 *                            CR 70384: Dcm generator should generate symbolic 
 *                                      names
 *                            CR 70452: Dcm: Special buffers are not used
 * v 2.4.1, 2010.03.05, anam: CR 23278: Changed configuration of PduRef
 * v 2.4.3, 2010.04.07, anam: CR 70583: Changed reading of BMWAutosarCoreVersion
 * v 2.4.5, 2010.07.05, anam: CR 70695: Dcm.xdm DcmDslProtocolRxPduId in Autosar 3.x  
 * v 2.5.1, 2011.03.02, anam: CR 70957: DCM: inconsistent declaration and use of parameters
 * v 2.5.2, 2011.09.26, anam: CR 71007: DCM: TRUE and FALSE (in capital letters) are not specified in AUTOSAR as xsd:boolean
 *                      anam: CR 71117: DCM: case sensitive filenames
 */

#ifndef __DCM_LCFG_C__
#define __DCM_LCFG_C__

/*******************************************************************************
**                    Include Section                                         **
*******************************************************************************/

#include "Dcm_Lcfg.h"

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

#if (DCM_CONFIGURATION_TYPE==DCM_LINK_TIME)

#include "Dsp.h"
#include "Rte_dcm.h"
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONST(Dcm_ServiceIdentifierTableType,DCM_LCFG_CONST) Dcm_LinkTimeServiceTable[DCM_NUMBER_OF_SERVICE_ID]=\
{ \
 { 0, 16, Dcm_DcmDiagnosticSessionControl, 7, 127, 1, DCM_DSP} \
,{ 0, 17, Rte_DcmECUReset, 7, 127, 1, DCM_DSP} \
,{ 0, 39, Dcm_DcmSecurityAccess, 7, 88, 1, DCM_DSP} \
,{ 0, 40, Rte_DcmCommunicationControl, 7, 124, 1, DCM_DSP} \
,{ 0, 62, Dcm_DcmTesterPresent, 7, 127, 1, DCM_DSP} \
,{ 0, 133, Dcm_DcmControlDTCSetting, 7, 92, 1, DCM_DSP} \
,{ 0, 134, Rte_DcmResponseOnEvent, 7, 95, 1, DCM_DSP} \
,{ 0, 34, Rte_DcmReadDataByIdentifier, 7, 127, 0, DCM_DSP} \
,{ 0, 46, Rte_DcmWriteDataByIdentifier, 7, 127, 0, DCM_DSP} \
,{ 0, 20, Dcm_DcmClearDiagnosticInformation, 7, 127, 0, DCM_DSP} \
,{ 0, 25, Dcm_DcmReadDTCInformation, 7, 127, 1, DCM_DSP} \
,{ 0, 49, Rte_DcmRoutineControl, 7, 127, 1, DCM_DSP} \
,{ 0, 47, Dcm_InputOutputControlByIdentifier, 7, 81, 0, DCM_DSP} \
}
;

CONST(Dcm_SecLevelTableType,DCM_LCFG_CONST) Dcm_LinkTimeSecurityLevel[DCM_NUMBER_OF_SECURITY_LEVELS + 1]=\
{ \
 {FIRST_SECURITY, 0, 0, 0, 2, 2} \
,{SECOND_SECURITY, 255, 0, 255, 8, 132} \
,{FOURTH_SECURITY, 255, 0, 255, 8, 132} \
,{0, 0, 0, 0, 0, 0} \
,{0, 0, 0, 0, 0, 0} \
,{0, 0, 0, 0, 0, 0} \
,{0, 0, 0, 0, 0, 0} \
,{0, 0, 0, 0, 0, 0} \
}
;

CONST(Dcm_SessionLevelTableType,DCM_LCFG_CONST) Dcm_LinkTimeSessionLevel[DCM_NUMBER_OF_SESSION_LEVELS]=\
{ \
 {DEFAULT, 5000, 50} \
,{PROGRAMMING, 15000, 300} \
,{EXTENDED_DIAGNOSTIC, 5000, 300} \
,{CODING, 5000, 300} \
,{MANUFACTURING, 5000, 300} \
,{GARAGE, 5000, 300} \
,{SWT, 5000, 300} \
,{0, 0, 0} \
}
;

#if DCM_USE_DEM==STD_ON
CONST(Dcm_ReadDTCSubFunctionTableType,DCM_LCFG_CONST) Dcm_LinkTimeSubFunctions0x19[DCM_NUMBER_OF_SUBFUNCTIONS_0x19]=\
{ \
 {1, DCM_READDTC_SUBFUNCTION01_ENABLED, 3} \
,{2, DCM_READDTC_SUBFUNCTION02_ENABLED, 3} \
,{3, DCM_READDTC_SUBFUNCTION03_ENABLED, 3} \
,{4, DCM_READDTC_SUBFUNCTION04_ENABLED, 3} \
,{5, DCM_READDTC_SUBFUNCTION05_ENABLED, 3} \
,{6, DCM_READDTC_SUBFUNCTION06_ENABLED, 3} \
,{7, DCM_READDTC_SUBFUNCTION07_ENABLED, 3} \
,{8, DCM_READDTC_SUBFUNCTION08_ENABLED, 3} \
,{9, DCM_READDTC_SUBFUNCTION09_ENABLED, 3} \
,{10, DCM_READDTC_SUBFUNCTION0A_ENABLED, 3} \
,{11, DCM_READDTC_SUBFUNCTION0B_ENABLED, 3} \
,{12, DCM_READDTC_SUBFUNCTION0C_ENABLED, 3} \
,{13, DCM_READDTC_SUBFUNCTION0D_ENABLED, 3} \
,{14, DCM_READDTC_SUBFUNCTION0E_ENABLED, 3} \
,{15, DCM_READDTC_SUBFUNCTION0F_ENABLED, 3} \
,{16, DCM_READDTC_SUBFUNCTION10_ENABLED, 3} \
,{17, DCM_READDTC_SUBFUNCTION11_ENABLED, 3} \
,{18, DCM_READDTC_SUBFUNCTION12_ENABLED, 3} \
,{19, DCM_READDTC_SUBFUNCTION13_ENABLED, 3} \
,{20, DCM_READDTC_SUBFUNCTION14_ENABLED, 3} \
,{21, DCM_READDTC_SUBFUNCTION15_ENABLED, 3} \
}
;
#endif

CONST(Dcm_TimerServerType,DCM_LCFG_CONST) Dcm_LinkTimeDefaultTimingParameters[DCM_NUMBER_OF_PROTOCOLS]=\
{ \
 {DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
,{DCM_DEFAULT, 0, 50, 0, 5000, 5000}\
}
;

CONST(Dcm_TimerServerType,DCM_LCFG_CONST) Dcm_LinkTimeLimitsTimingParameters[DCM_NUMBER_OF_PROTOCOLS]=\
{ \
 {DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
,{DCM_LIMITS, 0, 50, 0, 5000, 5000}\
}
;
CONST(Dcm_DiagnosticProtocolRxTableType,DCM_LCFG_CONST) Dcm_LinkTimeProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID]=\
{ \
,{DcmDslProtocolRxIpdu0, DCM_PHYSICAL, 0, 0, 0} \
,{DcmDslProtocolRxIpdu1, DCM_FUNCTIONAL, 4, 0, 0} \
,{DcmDslProtocolRxIpdu2, DCM_PHYSICAL, 0, 1, 1} \
,{DcmDslProtocolRxIpdu3, DCM_FUNCTIONAL, 4, 1, 1} \
,{DcmDslProtocolRxIpdu4, DCM_PHYSICAL, 0, 2, 2} \
,{DcmDslProtocolRxIpdu5, DCM_FUNCTIONAL, 4, 2, 2} \
,{DcmDslProtocolRxIpdu6, DCM_PHYSICAL, 0, 3, 3} \
,{DcmDslProtocolRxIpdu7, DCM_FUNCTIONAL, 4, 3, 3} \
,{DcmDslProtocolRxIpdu8, DCM_PHYSICAL, 0, 4, 4} \
,{DcmDslProtocolRxIpdu9, DCM_FUNCTIONAL, 4, 4, 4} \
,{DcmDslProtocolRxIpdu10, DCM_PHYSICAL, 0, 5, 5} \
,{DcmDslProtocolRxIpdu11, DCM_FUNCTIONAL, 4, 5, 5} \
,{DcmDslProtocolRxIpdu12, DCM_PHYSICAL, 0, 6, 6} \
,{DcmDslProtocolRxIpdu13, DCM_FUNCTIONAL, 4, 6, 6} \
,{DcmDslProtocolRxIpdu14, DCM_PHYSICAL, 0, 7, 7} \
,{DcmDslProtocolRxIpdu15, DCM_FUNCTIONAL, 4, 7, 7} \
,{DcmDslProtocolRxIpdu16, DCM_PHYSICAL, 0, 8, 8} \
,{DcmDslProtocolRxIpdu17, DCM_FUNCTIONAL, 4, 8, 8} \
,{DcmDslProtocolRxIpdu18, DCM_PHYSICAL, 0, 9, 9} \
,{DcmDslProtocolRxIpdu19, DCM_FUNCTIONAL, 4, 9, 9} \
,{DcmDslProtocolRxIpdu20, DCM_PHYSICAL, 0, 10, 10} \
,{DcmDslProtocolRxIpdu21, DCM_FUNCTIONAL, 4, 10, 10} \
,{DcmDslProtocolRxIpdu22, DCM_PHYSICAL, 0, 11, 11} \
,{DcmDslProtocolRxIpdu23, DCM_FUNCTIONAL, 4, 11, 11} \
,{DcmDslProtocolRxIpdu24, DCM_PHYSICAL, 0, 12, 12} \
,{DcmDslProtocolRxIpdu25, DCM_FUNCTIONAL, 4, 12, 12} \
,{DcmDslProtocolRxIpdu26, DCM_PHYSICAL, 0, 13, 13} \
,{DcmDslProtocolRxIpdu27, DCM_FUNCTIONAL, 4, 13, 13} \
}
;

CONST(Dcm_DiagnosticProtocolTxTableType,DCM_LCFG_CONST) Dcm_LinkTimeProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID]=\
{ \
 {0, 0, 0} \
,{1, 0, 2} \
,{2, 0, 4} \
,{3, 0, 6} \
,{4, 0, 8} \
,{5, 0, 10} \
,{6, 0, 12} \
,{7, 0, 14} \
,{8, 0, 16} \
,{9, 0, 18} \
,{10, 0, 20} \
,{11, 0, 22} \
,{12, 0, 24} \
,{13, 0, 26} \
}
;

CONST(Dcm_DiagnosticProtocolTableType,DCM_LCFG_CONST) Dcm_LinkTimeProtocolTable[DCM_NUMBER_OF_PROTOCOLS]=\
{ \
 {DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
,{DCM_UDS_FLEXRAY, 1, 0, 0} \
}
;

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#endif
