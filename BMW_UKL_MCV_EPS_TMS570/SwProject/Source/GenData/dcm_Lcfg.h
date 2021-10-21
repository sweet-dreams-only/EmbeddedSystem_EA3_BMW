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
 */


#ifndef __DCM_LCFG_H__
#define __DCM_LCFG_H__

/*******************************************************************************
**                    Include Section                                         **
*******************************************************************************/

#include "Dcm_cfg.h"

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/

#define AR_EXTERN extern

#if (DCM_CONFIGURATION_TYPE==DCM_LINK_TIME)
/*Type of the ROE processing. Used for correct processing. Range: TYPE1/TYPE2*/
#define DCM_ROE_TRANS_TYPE TYPE1

/*TxPduId that must be used for TYPE2 ROE. Range: uint8 (a valid TxPduId)*/
#define DCM_ROE_DCMTXPDUID 0

/*Buffer used for the ROE processing. Range: 0..max number of buffer - 1 */
#define DCM_ROE_TX_BUFFER_ID 1

/*Type of the PERIODICID processing. Used for correct processing. Range: TYPE1/TYPE2*/
#define DCM_PERIODIC_TRANS_TYPE TYPE1

/*TxPduId that must be used for TYPE2 PERIODIC transmission. Range: uint8 (a valid TxPduId)*/
#define DCM_PERIODIC_TRANS_DCMTXPDUID 0

/*Buffer used for the PERIODIC processing. Range: 0..max number of buffer - 1 */
#define DCM_PERIODIC_TRANS_TX_BUFFER_ID 2

/*Timer for the PagedBuffer functionality. Expressed in ms. Represents the period the DCM shall wait\n for a request for new page. Range: uint16.*/
#define DCM_PAGEDBUFFER_TIMEOUT 50

/*Initial time delay while SecurityAccess is locked*/
#define DCM_SEC_ACCESS_DELAY 0

/*Number of maximum allowed response pending messages that can be sent*/
#define DCM_NUM_MAX_RESPPEND 20

/*Function pointer to Confirmation Response pending*/
#define DCM_CONFRESPPEND_FUNCTIONPTR Rte_DcmResponsePendingConfirmation

/*Configuration table for adjustment parameters for timers. */
#define DCM_P2SERVER_ADJUST 15

/*Configuration table for adjustment parameters for timers. */
#define DCM_P2STARSERVER_ADJUST 10

/*Length of the record for the SecurityAccess requestSeed request*/
#define DCM_SECURITYACCESSRECORDLENGTH 4


/*
                      Global Data                                           
*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*Table containing information about each service processed by the DCM*/
AR_EXTERN CONST(Dcm_ServiceIdentifierTableType,DCM_LCFG_CONST) Dcm_LinkTimeServiceTable[DCM_NUMBER_OF_SERVICE_ID];
/*  Line is given by value in table ServiceMatrix
    Table shall contain information about fucntion pointer, security and session levels needed to execuet service, subfunction availability
    and the data processor 
*/

/*Table that contains information about the security levels*/
AR_EXTERN CONST(Dcm_SecLevelTableType,DCM_LCFG_CONST) Dcm_LinkTimeSecurityLevel[DCM_NUMBER_OF_SECURITY_LEVELS + 1];
/*  The +1 from the size is due to the fact that the 0x00 Locked State is not considered between the security levels.
    The following information shall be found for each line in the table:
    - security level. Range: uint8
    - security name. Type: string
    - number of failed attempts until timer must be elapsed. Range: uint8
    - time delay required.Activated when the number of failed attempts reaches the parameter above. Range: uint16
    - number of failed attempt until lock. After this number of failed attempts the security level shall be set to "Locked" 0x00. Range: uint8
    - seed size in bytes. Range: uint8
    - key size in bytes. Range: uint8
*/

/*Table containing information about the session levels*/
AR_EXTERN CONST(Dcm_SessionLevelTableType,DCM_LCFG_CONST) Dcm_LinkTimeSessionLevel[DCM_NUMBER_OF_SESSION_LEVELS];
/*  The following information shall be found in this table:
    - session level value. Range: uint8
    - session name. Type: string
    - P2StarServerMax. Range: uint16
    - P2ServerMax. Range: uint16
*/

/*Table containing all relevand information about the sub-functions of service 0x19*/
AR_EXTERN CONST(Dcm_ReadDTCSubFunctionTableType,DCM_LCFG_CONST) Dcm_LinkTimeSubFunctions0x19[DCM_NUMBER_OF_SUBFUNCTIONS_0x19];
/*  Information about sub-functions of service 0x19 shall be found in this table
    - sub-function. Range: uint8 (0x01 - 0x15) sub function shall be ordered (0x01 found in first line, 0x02 found in second line).Range: uint8
    - if the sub-function is available or not (if the sub-function if not available this info shall be FALSE, but the line will exist in the config table. Range: TRUE/FALSE
    - security level needed. Different sub-functions can have different security levels. Range: uint8
    - length of request. Range: uint8
*/

/*Table containing default timing parameters*/
AR_EXTERN CONST(Dcm_TimerServerType,DCM_LCFG_CONST) Dcm_LinkTimeDefaultTimingParameters[DCM_NUMBER_OF_PROTOCOLS];
/*  All information about timers must be present in this table:
    - the type of the parameters. Range: DCM_DEFAULT/DCM_CURRENT
    - P2ServerMin. Range: uint16
    - P2ServerMax. Range: uint16
    - P2StarServerMin. Range: uint16
    - P2StarServerMax. Range: uint16
    - S3Server. Range: uint16
*/

/*Table containing default timing parameters*/
AR_EXTERN CONST(Dcm_TimerServerType,DCM_LCFG_CONST) Dcm_LinkTimeLimitsTimingParameters[DCM_NUMBER_OF_PROTOCOLS];
/*  All information about timers must be present in this table:
    - the type of the parameters. Range: DCM_DEFAULT/DCM_CURRENT
    - P2ServerMin. Range: uint16
    - P2ServerMax. Range: uint16
    - P2StarServerMin. Range: uint16
    - P2StarServerMax. Range: uint16
    - S3Server. Range: uint16
*/

/*Table including all necessary information for RxPduIds*/
AR_EXTERN CONST(Dcm_DiagnosticProtocolRxTableType,DCM_LCFG_CONST) Dcm_LinkTimeProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID];
/*  All required information to process the RxPduId shall be found in this table:
    RxPduId, same with the line of the table. Range: uint8. unused lines shall be filled with irelevant data (never used, written to maintain each RxPdu in its line (0x00 in first line, 0x01 in second)
    Addressing type. Range: DCM_FUNCTIONAL/DCM_PHYSICAL
    Id of buffer used. Range: 0..max number of buffers -1
    Id of protocol. Range: 0..max number of protocol -1
*/

/*Table including all necessary information for TxPduIds*/
AR_EXTERN CONST(Dcm_DiagnosticProtocolTxTableType,DCM_LCFG_CONST) Dcm_LinkTimeProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID];
/*  All required information to process the TxPduId shall be found in this table:
    TxPduId. Range: uint8.
    Id of buffer used. Range: 0..max number of buffers -1
*/

/*Table used to store information about all protocols*/
AR_EXTERN CONST(Dcm_DiagnosticProtocolTableType,DCM_LCFG_CONST) Dcm_LinkTimeProtocolTable[DCM_NUMBER_OF_PROTOCOLS];
/*  For each protocol, the following parameters shall be configured:
    - Protocol Id. Range: DCM_OBD_CAN/DCM_UDS_CAN/DCM_UDS_FLEXRAY
    - Preempt timeout(time until the protocol needs to be started). Range: uint16
    - Service identifier table used by the protocol. Range: 0..max number of service tables - 1
    - Protocol priority. Lowest value means highest priority.Each protocol shall have a priority defined. Range: uint8
    - Index in the timing parameters tables. Gives a link to the timing parameters associated with this protocol. Range: 0..max number of timing parameters - 1
    - Index in the TxPdu table. Gives a link to the TxPduId used by this protocol. Range: uint8 (valid TxPduId)
    For each protocol, the following parameters for timing adjustment shall be configured:
    - P2server adjust: value in ms of the adjustment value for the P2servermax. Range: uint16
    - P2startserver adjust: value in ms of the adjustment for the timing the P2starservermax. Range: uint16
*/
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif

#undef AR_EXTERN

#endif