

/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Dcm_cfg.h                                                     **
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
 *          2010.01.18, anam: CR 70496 - Bug-fixing changes
 * v 2.4.0, 2010.02.23, gema: CR 70411: DCM: Module extension to 3.0  
 * v 2.4.1, 2010.03.05, anam: CR 23278: Changed configuration of PduRef
 * v 2.4.2, 2010.03.23, anam: CR 70602: DcmDslProtocolRxPduIdValue is missing in Dcm.bmd
 * v 2.4.3, 2010.04.07, anam: CR 70583: Changed reading of BMWAutosarCoreVersion
 * v 2.4.5, 2010.07.05, anam: CR 70695: Dcm.xdm DcmDslProtocolRxPduId in Autosar 3.x  
 * v 2.5.0, 2010.10.26, anam: CR 70846: DCM: Completion of the OBD Sevices Implementation in DCM 
 *                                      according to the Autosar DCM V.3.1
 *                            CR 70824: Mandatory parameter DcmObdDemSupport is ignored in config generation
 * v 2.5.1, 2011.03.02, anam: CR 70957: DCM: inconsistent declaration and use of parameters
 *                            CR 70964: Create Sybmbolic Names according to Shortnames 
 *                                      of Containers of Type DcmDslProtocolRx 
 *                            CR 71011: All Timings in DCM should be in seconds and of type float 
 * v 2.5.2, 2011.09.26, anam: CR 71007: DCM: TRUE and FALSE (in capital letters) are not specified in AUTOSAR as xsd:boolean
 *                      anam: CR 71076: Dcm: config parameter DcmAccessTimingParameterEnabled is not used
 *                      anam: CR 71118: DCM: GetPIDValue-functions not declared
 */

#ifndef __DCM_CFG_H__
#define __DCM_CFG_H__


/* callback header file includes                                              */


/* Definitions for BAC Versions                                               */
#define DCM_BAC21 (0u)
#define DCM_BAC3X (1u)


/* Null Pointer                                                               */
#define DCM_NULL_PTR              ( ( void * ) 0 )

/* Define used to set the configuration type to PRE_COMPILE                   */
#define DCM_PRE_COMPILE 0

/* Define used to set the configuration type to LINK_TIME                     */
#define DCM_LINK_TIME 1

/* Configuration type of the DCM Module                                       */
#define DCM_CONFIGURATION_TYPE DCM_PRE_COMPILE

/* Enable/disable indication forwarding to Application                        */
#define DCM_REQUEST_INDICATION_ENABLED   ( STD_ON )

/* Activation of Development Error Detection                                  */
#define DCM_DEV_ERROR_DETECT  ( STD_OFF )

/* Used to enable/disable version information retrieval by other modules.     */
#define DCM_VERSION_INFO_API  ( STD_OFF )

/* Used to enable/disable the PagedBuffer functionality inside DCM Dcm_Module */
#define DCM_PAGEDBUFFER_ENABLED  ( STD_OFF )

/* used to enable/disable the DEM usage inside DCM Dcm_Module                 */
#define DCM_USE_DEM  ( STD_ON )

/*
    BAC Version
    Specification, in which BAC Version, Dcm is integrated
*/
#define DCM_BAC_VERSION   ( DCM_BAC3X )


/* 
    used to enable/disable the DEM usage for OBD/emission related protocol. 
    Range STD_ON/STD_OFF
*/
#define DCM_OBD_DEM_SUPPORT  ( STD_OFF )

/* Used for configuring the type of DTC for OBD requests                      */
#define DCM_DTC_TYPE_FOR_OBD  ( STD_ON )
/*
   Used to select the DTC type for OBD services
   Value STD_ON means the following usage of the uint32 that holds the value of
   the DTC:
   byte 0= LowByte, byte 1= HighByte, byte 2 and byte 3 are 0.
   Value STD_OFF means the following usage of the uint32 that holds the value of
   the DTC:
   byte 0=0, byte 1=LowByte, byte 2=HighByte, byte 3 = 0
   These two possibilities were taken from ISO 15031-6.
*/

/* used to enable/disable the OBD service 0x01. 
   Range STD_ON/STD_OFF */
#define DCM_OBD_SERVICE_0x01_SUPPORTED ( STD_OFF )

/* used to enable/disable the OBD service 0x06. 
   Range STD_ON/STD_OFF */
#define DCM_OBD_SERVICE_0x06_SUPPORTED ( STD_OFF )

/* used to enable/disable the OBD service 0x08. 
   Range STD_ON/STD_OFF */
#define DCM_OBD_SERVICE_0x08_SUPPORTED ( STD_OFF )

/* used to enable/disable the OBD service 0x09. 
   Range STD_ON/STD_OFF */
#define DCM_OBD_SERVICE_0x09_SUPPORTED ( STD_OFF )

/* When DCM_OBD_SERVICE04_KIND is set to DEM_DTC_KIND_EMISSION_REL_DTCS only the OBD-relevabt DTCs are cleared by OBD service 0x04.
   When DCM_OBD_SERVICE04_KIND is set to DEM_DTC_KIND_ALL_DTCS all DTCs are cleared by OBD service 0x04. */
#define DCM_OBD_SERVICE04_KIND DEM_DTC_KIND_ALL_DTCS

/* Define the number of PIDs supported by the OBD service 0x01*/
#define DCM_OBD_NUMBER_OF_PIDS_SERVICE_0x01 0

/* Configuration table for the Supported PIDs of OBD service 0x01.
   The number of lines is configured with parameter DCM_OBD_NUMBER_OF_PIDS_SERVICE_0x01 */
#define DCM_OBD_PID_CFG_TABLE \
{ \
}
/*  For each PID the following parameters have
    to be defined:
    uint8 PID - Identifier of the PID
    uint8 PidSize - Length of data associated to the PID
    Dcm_ObdPidServiceType GetPidFuncPtr - Function pointer for reading value by PID
*/

/* Define the number of availability IDs supported by the OBD service 0x01*/
#define DCM_OBD_NUMBER_OF_AVAILABILITY_PIDS 1

/* Table to store the availability ID Data for OBD service 0x01*/
#define DCM_OBD_AVAILABILITY_PID_CFG_TABLE \
{ \
}


/* Define the number of OBDMIDs supported by the OBD service 0x06*/
#define DCM_OBD_NUMBER_OF_OBDMIDS 0

/* Configuration table for the Supported OBDMID/TID combination of OBD service 0x06.
   The number of lines is configured with parameter DCM_OBD_NUMBER_OF_OBDMIDS */
#define DCM_OBD_OBDMID_CFG_TABLE \
{ \
}
/*  For each OBDMID/TID combination the following parameters have
    to be defined:
    uint8 OBDMID - The identifier of the OBDMID
    uint8 TestId - The reported TestId assigned to the OBDMID
    uint8 UaSId - Unit And Scaling ID
    Dcm_ObdDtrServiceType GetDTRValueFuncPtr - Function pointer to obtain the DTR of an OBDMID
*/

/* Define the number of availability IDs supported by the OBD service 0x06*/
#define DCM_OBD_NUMBER_OF_AVAILABILITY_OBDMIDS 1

/* Table to store the availability ID Data for OBD service 0x06*/
#define DCM_OBD_AVAILABILITY_OBDMID_CFG_TABLE \
{ \
}

/* Define the number of TIDs supported by the OBD service 0x08*/
#define DCM_OBD_NUMBER_OF_REQ_CONTROL_TIDS 0

/* Configuration table for the Supported TestIds of OBD service 0x08.
   The number of lines is configured with parameter DCM_OBD_NUMBER_OF_REQ_CONTROL_TIDS */
#define DCM_OBD_REQ_CONTROL_CFG_TABLE \
{ \
}
/*  For each TestId the following parameters have
    to be defined:
    uint8 TID - The identifier of the TestId
    uint8 InBufferSize - Buffer Size for the RequestControl service
    uint8 OutBufferSize - Buffer Size for the RequestControl service
    Dcm_ObdReqControlServiceType ReqControlFuncPtr - Function pointer for executing the RequestControl service of the TestId
*/

/* Define the number of availability IDs supported by the OBD service 0x08*/
#define DCM_OBD_NUMBER_OF_AVAILABILITY_TIDS 1

/* Table to store the availability ID Data for OBD service 0x08*/
#define DCM_OBD_AVAILABILITY_TID_CFG_TABLE \
{ \
}

/* Define the number of InfoTypes supported by the OBD service 0x09*/
#define DCM_OBD_NUMBER_OF_INFO_TYPES 0

/* Configuration table for the Supported InfoTypes of OBD service 0x09.
   The number of lines is configured with parameter DCM_OBD_NUMBER_OF_INFO_TYPES */
#define DCM_OBD_VEHICLE_INFO_CFG_TABLE \
{ \
}
/*  For each InfoType the following parameters have
    to be defined:
    uint8 InfoType - Identifier of the InfoType
    uint8 VehInfoSize - Length of data associated to the InfoType
    Dcm_ObdInfoTypeServiceType GetInfoTypeFuncPtr - Function pointer for reading the associated INFOTYPE.
*/

/* Define the number of availability IDs supported by the OBD service 0x09*/
#define DCM_OBD_NUMBER_OF_AVAILABILITY_INFO_TYPES 1

/* Table to store the availability ID Data for OBD service 0x09*/
#define DCM_OBD_AVAILABILITY_INFO_TYPE_CFG_TABLE \
{ \
}


/* Number of defined protocols. Range: uint8                                  */
#define DCM_NUMBER_OF_PROTOCOLS  14


#include "Dcm_types.h"

/*
    Used for the busy response processing (negative responses with NRC0x78 sent
    to lower layer in case \n DCM must stop the currently active protocol.
    Value always 1. Not configurable
*/
#define DCM_BUSYREPEATREQUEST  1

/*
    Used for acknowledging that the response is ready to send.
    This shall be processed in the main cycle.
    Value always 1.Not configurable
*/
#define DCM_READY_TO_SEND 1

/* Defines the period in ms between two consecutive calls of the function
   Dcm_MainFunction(). Range: uint16                                          */
#define DCM_TASK_TIME  10

/* Length of the buffer used for normal processing. Range: uint16             */
#define DCM_BUFFER_LENGTH          500

/* Length for ROE buffer. Range: uint16                                       */
#define DCM_ROE_BUFFER_LENGTH      500

/* Length of the PERIODIC buffer. Range: uint16                               */
#define DCM_PERIODIC_BUFFER_LENGTH 500

/* Length of the buffer used for functional processing. Range: uint16         */
#define DCM_FUNC_BUFFER_LENGTH     500

/* Length of the buffer used for OBD request processing. Range: uint16        */
#define DCM_OBD_BUFFER_LENGTH      500

/*
    Length of the negative response buffer.
    Value is 3. Not configurable
*/
#define DCM_NEG_RESPONSE_BUFFER_LENGTH 3

/*******************************************************************************
**                         Global Data                                        **
*******************************************************************************/
#define DCM_CFG_EXTERN extern
#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
/* External link to the normal request buffer                                 */
DCM_CFG_EXTERN VAR(uint8,DCM_VAR) Dcm_RxTxBuffer[DCM_BUFFER_LENGTH];

/* External link to the ROE buffer                                            */
DCM_CFG_EXTERN VAR(uint8,DCM_VAR) Dcm_RoeBuffer[DCM_ROE_BUFFER_LENGTH];


/* External link to the negative response buffer                              */
DCM_CFG_EXTERN VAR(uint8,DCM_VAR) Dcm_NegResponseBuffer[DCM_NEG_RESPONSE_BUFFER_LENGTH];

/* External link to the normal request buffer                                 */
DCM_CFG_EXTERN VAR(uint8,DCM_VAR) Dcm_FuncRxTxBuffer[DCM_FUNC_BUFFER_LENGTH];

/* External link to the normal request buffer                                 */
DCM_CFG_EXTERN VAR(uint8,DCM_VAR) Dcm_OBDRxBuffer[DCM_OBD_BUFFER_LENGTH];
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/*******************************************************************************
**                         Global Macros                                      **
*******************************************************************************/
/* Number of used buffers.                                                    */
#define DCM_NUMBER_OF_BUFFER_ID 5

/* Number of services that shall be processed by DSP or RTE. Range: uint8     */
#define DCM_NUMBER_OF_SERVICE_ID 13

/*
    Enables/disables the ResponseOnOneEvent functionality in DCM.
    Range: STD_ON/STD_OFF */
#define DCM_ROE_ENABLED  ( STD_ON )

/*
    Enables/disables the ResponseOnOneDataByPeriodicId functionality in DCM.
    Range: STD_ON/STD_OFF
*/
#define DCM_PERIODIC_TRANS_ENABLED  ( STD_OFF )

/* Number of DcmRxPduIds. Range: uint8                                        */
#define DCM_NUMBER_OF_DCMRXPDUID 28

/* Number of DcmTxPduIds. Range: uint8                                        */
#define DCM_NUMBER_OF_DCMTXPDUID 14

/* Symbolic Names for PDUs Rx                                                 */
#define DcmDslProtocolRx0 0
#define DcmDslProtocolRx1 1
#define DcmDslProtocolRx2 2
#define DcmDslProtocolRx3 3
#define DcmDslProtocolRx4 4
#define DcmDslProtocolRx5 5
#define DcmDslProtocolRx6 6
#define DcmDslProtocolRx7 7
#define DcmDslProtocolRx8 8
#define DcmDslProtocolRx9 9
#define DcmDslProtocolRx10 10
#define DcmDslProtocolRx11 11
#define DcmDslProtocolRx12 12
#define DcmDslProtocolRx13 13
#define DcmDslProtocolRx14 14
#define DcmDslProtocolRx15 15
#define DcmDslProtocolRx16 16
#define DcmDslProtocolRx17 17
#define DcmDslProtocolRx18 18
#define DcmDslProtocolRx19 19
#define DcmDslProtocolRx20 20
#define DcmDslProtocolRx21 21
#define DcmDslProtocolRx22 22
#define DcmDslProtocolRx23 23
#define DcmDslProtocolRx24 24
#define DcmDslProtocolRx25 25
#define DcmDslProtocolRx26 26
#define DcmDslProtocolRx27 27

/* Number of security levels. Value is 8. Not configurable.                   */
#define DCM_NUMBER_OF_SECURITY_LEVELS 8

/* Number of session levels. Value is 8. Not configurable                     */
#define DCM_NUMBER_OF_SESSION_LEVELS  8

/* 
   Symbol Names for Security Levels 
   Range:0x00,0x01,0x03...0x7F (ISO specific)
   only odd values (and 0) are allowed
*/
#define FIRST_SECURITY 0
#define SECOND_SECURITY 1
#define FOURTH_SECURITY 19

/* Symbol Names for Session Levels                                            */
#define DEFAULT_SESSION 1
#define PROGRAMMING_SESSION 2
#define EXTENDED_DIAGNOSTIC_SESSION 3
#define CODING_SESSION 65
#define MANUFACTURING_SESSION 126
#define GARAGE_SESSION 97
#define SWT_SESSION 66

/*
    Number of subfunction for service 0x19.
    Value is 21 (ISO specific). Not configurable
*/
#define DCM_NUMBER_OF_SUBFUNCTIONS_0x19  21

/* enable/disable the access timing parameter uds service */
#define DCM_ACCESS_TIMING_PARAMETER_ENABLED STD_OFF


/* Configuration table for buffer used by the DCM Dcm_Module                  */
#define DIAGNOSTIC_BUFFER_CFG \
{ \
   {0, DCM_BUFFER_LENGTH,              &Dcm_RxTxBuffer[0]}, \
   {1, DCM_ROE_BUFFER_LENGTH,          &Dcm_RoeBuffer[0]}, \
   {2, DCM_NEG_RESPONSE_BUFFER_LENGTH, &Dcm_NegResponseBuffer[0]}, \
   {3, DCM_FUNC_BUFFER_LENGTH,         &Dcm_FuncRxTxBuffer[0]}, \
   {4, DCM_OBD_BUFFER_LENGTH,          &Dcm_OBDRxBuffer[0]} \
} \
/*
   The table shall contain in each line information about one buffer
   Each line shall have the following columns:
   - a buffer Id - unique uint8 value throughout this table
   - a buffer length - uint16 value according to the already defined parameter
     (e.g. @see DCM_BUFFER_SIZE)
   - a buffer address - this is the address of the buffer in memory.
     the buffers are defined in Dcm.c
*/
#define DCM_READDTC_SUBFUNCTION01_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION02_ENABLED  ( STD_ON  )
#define DCM_READDTC_SUBFUNCTION03_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION04_ENABLED  ( STD_ON  )
#define DCM_READDTC_SUBFUNCTION05_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION06_ENABLED  ( STD_ON  )
#define DCM_READDTC_SUBFUNCTION07_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION08_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION09_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION0A_ENABLED  ( STD_ON  )
#define DCM_READDTC_SUBFUNCTION0B_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION0C_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION0D_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION0E_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION0F_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION10_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION11_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION12_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION13_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION14_ENABLED  ( STD_OFF )
#define DCM_READDTC_SUBFUNCTION15_ENABLED  ( STD_OFF )

#if (DCM_CONFIGURATION_TYPE==DCM_PRE_COMPILE)
/* Type of the ROE processing. Used for correct processing. Range: TYPE1/TYPE2 */
#define DCM_ROE_TRANS_TYPE TYPE1

/* TxPduId that must be used for TYPE2 ROE. Range: uint8 (a valid TxPduId)    */
#define DCM_ROE_DCMTXPDUID 0

/* Buffer used for the ROE processing. Range: 0..max number of buffer - 1     */
#define DCM_ROE_TX_BUFFER_ID 1

/*
   Type of the PERIODICID processing. Used for correct processing.
   Range: TYPE1/TYPE2
*/
#define DCM_PERIODIC_TRANS_TYPE TYPE1

/*
   TxPduId that must be used for TYPE2 PERIODIC transmission.
   Range: uint8 (a valid TxPduId)
*/
#define DCM_PERIODIC_TRANS_DCMTXPDUID 0

/* Buffer used for the PERIODIC processing. Range: 0..max number of buffer - 1*/
#define DCM_PERIODIC_TRANS_TX_BUFFER_ID 2

/* Number of maximum allowed response pending messages that can be sent       */
#define DCM_NUM_MAX_RESPPEND 20

/* The length of the security access record parameter                         */
#define DCM_SECURITYACCESSRECORDLENGTH 4

/* Function pointer to Confirmation Response pending                          */
#define DCM_CONFRESPPEND_FUNCTIONPTR Rte_DcmResponsePendingConfirmation

/*
    Configuration table for each RxPduId.
    The number of lines is given by parameter DCM_NUMBER_OF DCMRXPDUID
*/
#define DIAGNOSTIC_PROTOCOL_RX_TABLE \
{ \
 {DcmDslProtocolRx0, DCM_PHYSICAL, 0, 0, 0} \
,{DcmDslProtocolRx1, DCM_FUNCTIONAL, 4, 0, 0} \
,{DcmDslProtocolRx2, DCM_PHYSICAL, 0, 1, 1} \
,{DcmDslProtocolRx3, DCM_FUNCTIONAL, 4, 1, 1} \
,{DcmDslProtocolRx4, DCM_PHYSICAL, 0, 2, 2} \
,{DcmDslProtocolRx5, DCM_FUNCTIONAL, 4, 2, 2} \
,{DcmDslProtocolRx6, DCM_PHYSICAL, 0, 3, 3} \
,{DcmDslProtocolRx7, DCM_FUNCTIONAL, 4, 3, 3} \
,{DcmDslProtocolRx8, DCM_PHYSICAL, 0, 4, 4} \
,{DcmDslProtocolRx9, DCM_FUNCTIONAL, 4, 4, 4} \
,{DcmDslProtocolRx10, DCM_PHYSICAL, 0, 5, 5} \
,{DcmDslProtocolRx11, DCM_FUNCTIONAL, 4, 5, 5} \
,{DcmDslProtocolRx12, DCM_PHYSICAL, 0, 6, 6} \
,{DcmDslProtocolRx13, DCM_FUNCTIONAL, 4, 6, 6} \
,{DcmDslProtocolRx14, DCM_PHYSICAL, 0, 7, 7} \
,{DcmDslProtocolRx15, DCM_FUNCTIONAL, 4, 7, 7} \
,{DcmDslProtocolRx16, DCM_PHYSICAL, 0, 8, 8} \
,{DcmDslProtocolRx17, DCM_FUNCTIONAL, 4, 8, 8} \
,{DcmDslProtocolRx18, DCM_PHYSICAL, 0, 9, 9} \
,{DcmDslProtocolRx19, DCM_FUNCTIONAL, 4, 9, 9} \
,{DcmDslProtocolRx20, DCM_PHYSICAL, 0, 10, 10} \
,{DcmDslProtocolRx21, DCM_FUNCTIONAL, 4, 10, 10} \
,{DcmDslProtocolRx22, DCM_PHYSICAL, 0, 11, 11} \
,{DcmDslProtocolRx23, DCM_FUNCTIONAL, 4, 11, 11} \
,{DcmDslProtocolRx24, DCM_PHYSICAL, 0, 12, 12} \
,{DcmDslProtocolRx25, DCM_FUNCTIONAL, 4, 12, 12} \
,{DcmDslProtocolRx26, DCM_PHYSICAL, 0, 13, 13} \
,{DcmDslProtocolRx27, DCM_FUNCTIONAL, 4, 13, 13} \
}
/* Each line shall provide information about one RxPduId
    - DcmRxPduId. This is the same with the number of the line.
      If one RxPdu is not processed, that line should be completed with some
      irrelevant values and never used
    - Addressing Type. Type: Dcm_AddrType Range: DCM_FUNCTIONAL/DCM_PHYSICAL
    - Buffer Id. Buffer used for this processing.
    Range: 0..max number of buffers - 1
    - The index in the protocol table for the protocol used by this RxPduId.
      Range: 0 .. max number of protocols - 1
    - The index of the TxTable where the first TxPduId associated with the
      RxPduId is located Range: 0 - maximum number of TxPduIds -1
*/

/*
    Configuration table for protocols.
    The number of lines is configured with parameter DCM_NUMBER_OF_PROTOCOLS
*/
#define DIAGNOSTIC_PROTOCOL_TABLE \
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
/*
    For each protocol configured with this table, the following parameters have
    to be defined:
    - Protocol Id. Type: Dcm_ProtocolType.
      Range: DCM_OBD_CAN/DCM_UDS_CAN/DCM_UDS_FLEXRAY
    - Timeout (in ms) of preempting protocol until protocol needs to be started.
      Range: uint16
    - Service identifier table used by the protocol.
      Range: 0..max number of service tables - 1
    - Protocol priority. Lowest value means highest priority.Each protocol shall
      have a priority defined. Range: uint8
*/

/* Configuration table for adjustment parameters for timers                   */
#define DCM_P2SERVER_ADJUST 15

/* Configuration table for adjustment parameters for timers                   */
#define DCM_P2STARSERVER_ADJUST 10

/*
    TxPduId information table.
    Number of lines given by parameter DCM_NUMBER_OF_DCMTXPDUID
*/
#define DIAGNOSTIC_PROTOCOL_TX_TABLE \
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
/*
    Following information must be configured for each TxPduId:
    - TxPduId used by the procotol for transmission. Range: uint8
    - Buffer id used for transmission. Range: 0..max number of buffers -1
      (this can be the same as the buffer used for reception)
    - Index of the RxTable where the associated RxPduId is located.
      Used for multiple diagnostic testers.
*/

/*
    Default timing parameter table.
    The number of lines is given by the value of DCM_NUMBER_OF_TIMING_PARAMETERS
*/
#define PROTOCOL_DEFAULTTIMING_STRUCTURE \
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
/*
    Each table shall have the following information for each line:\
    - The type of the timing structure. Type: Dcm_TimerModeType
    Range: DCM_DEFAULT (because is the default timing parameter table)
    - The P2ServerMin timer. Range: uint16
    - The P2ServerMax timer. Range: uint16
    - The P2StarServerMin timer. Range: uint16
    - The P2StarServerMax timer. Range: uint16
    - The S3Server timer. Range: uint16
*/

/*
    Limits timing parameter table.
    The number of lines is given by the value of DCM_NUMBER_OF_TIMING_PARAMETERS
*/
  #define PROTOCOL_LIMITSTIMING_STRUCTURE \
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
/*
    Each table shall have the following information for each line:
    - The type of the timing structure. Type: Dcm_TimerModeType
      Range: DCM_LIMITS (because is the limits timing parameter table)
    - The P2ServerMin timer. Range: uint16
    - The P2ServerMax timer. Range: uint16
    - The P2StarServerMin timer. Range: uint16
    - The P2StarServerMax timer. Range: uint16
    - The S3Server timer. Range: uint16
*/
#endif

#if (DCM_CONFIGURATION_TYPE!=DCM_LINK_TIME)
/* Timer for the PagedBuffer functionality. Expressed in ms. Represents the
   period the DCM shall wait\n for a request for new page. Range: uint16.
*/
#define DCM_PAGEDBUFFER_TIMEOUT 50

/* Initial time delay while SecurityAccess is locked                          */
#define DCM_SEC_ACCESS_DELAY 0

/*
    All service identifier tables are included in this define.
*/
#define SERVICE_IDENTIFIER_TABLE \
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
/*
   The following parameters have to be configured for each service in the
   service tables:
   - Servicetable ID - The ID of the servicetable to which this entry belongs
   - SID - this is the ISO specific service Id for each service
   - Pointer to function - points to the function that shall process this service
   - Security level - the security level needed for the processing of the service.
     Can be more that one.
   - Session level - the session level needed for the processing of the service.
     Can be more that one.
   - Subfunction - TRUE or FALSE if a sub-function is supported for the service.
   - Data processor - that data processor that shall process this service (DSP or RTE).
*/

/*Information about session levels. Number of lines given by parameter DCM_NUMBER_OF_SESSION_LEVELS*/
#define DCM_SESSION_LEVEL_TABLE \
{ \
 {DEFAULT_SESSION, 5000, 50} \
,{PROGRAMMING_SESSION, 15000, 300} \
,{EXTENDED_DIAGNOSTIC_SESSION, 5000, 300} \
,{CODING_SESSION, 5000, 300} \
,{MANUFACTURING_SESSION, 5000, 300} \
,{GARAGE_SESSION, 5000, 300} \
,{SWT_SESSION, 5000, 300} \
,{0, 0, 0} \
}
/*
    For each line the following parameters must be configured:
    - Session level. Type: Dcm_SesCtrlType Range: uint8 (ISO specific)
    - Session name. Type: string
    - P2StarServerMax timer. Range: uint16
    - P2ServerMax timer. Range: uint16
*/
/* ----- NXTR PATCH START -----
 * Added By: K. Smith (Nxtr)
 * Date Added: 28Sep16
 *
 * Reason: Due to the increase in key size, the Dcm needed to be patched to support the new key length. However, that value is
 * 260, which is larger than a uint8 and what the Dcm in Configurator will support. As a result, the data type needed to be patched
 * and the generated file hand needed to be hand modified.
 */
#if 0
/* ----- Original Code Start ----- */
/*Information about security levels. Number of lines given by parameter DCM_NUMBER_OF_SECURITY_LEVELS*/
  #define	 DCM_SEC_LEVEL_TABLE \
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
/* For each line the following parameters have to be defined:
   - Security level. Type Dcm_SecLevelType Range:  
     Range: 0x00,0x01,0x03...0x7F (ISO specific)
     only odd values (and 0) are allowed
   - This value represents the number of failed accesses for this security level 
    until a time delay must be elapsed. Range: uint8
   - Delay. Value in ms of the delay that must be elapsed so that the 
     SecurityAccess is permitted. Range: uint16
   - This value represents the number of failed attemps for the security access 
     until the security access is set to value 0x00 ("locked"). Range: uint8
   - The size in bytes of the seed. Range: uint8
   - The size in bytes of the key. Range: uitn8
*/
/* ----- Original Code End ----- */
#endif
/* ----- Patch Code Start ----- */
#define	 DCM_SEC_LEVEL_TABLE \
{ \
{FIRST_SECURITY, 0, 0, 0, 2, 2} \
,{SECOND_SECURITY, 255, 0, 255, 8, 260} \
,{FOURTH_SECURITY, 255, 0, 255, 8, 260} \
,{0, 0, 0, 0, 0, 0} \
,{0, 0, 0, 0, 0, 0} \
,{0, 0, 0, 0, 0, 0} \
,{0, 0, 0, 0, 0, 0} \
,{0, 0, 0, 0, 0, 0} \
}
/* For each line the following parameters have to be defined:
 - Security level. Type Dcm_SecLevelType Range:
   Range: 0x00,0x01,0x03...0x7F (ISO specific)
   only odd values (and 0) are allowed
 - This value represents the number of failed accesses for this security level
  until a time delay must be elapsed. Range: uint8
 - Delay. Value in ms of the delay that must be elapsed so that the
   SecurityAccess is permitted. Range: uint16
 - This value represents the number of failed attemps for the security access
   until the security access is set to value 0x00 ("locked"). Range: uint8
 - The size in bytes of the seed. Range: uint8
 - The size in bytes of the key. Range: uitn16 <---- Nxtr patch to make this a 16 bit value
*/
/* The following define will be looked at in a static source file. If the file is re-generated, it will remove
 * this patch, which will cause a build error. */
#define NXTR_DCM_CFG_H_PATCH_PRESENT
/* ----- Patch Code End ----- */
/* ----- NXTR PATCH END ----- */


 #if DCM_USE_DEM == STD_ON
/*Information about the sub-functions of the service 0x19. The numbers of line is constant and given by parameter DCM_NUMBER_OF_SUBFUNCTIONS_0x19*/
#define DCM_READDTC_SUB_FUNCTION_TABLE \
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
/*
   For each entry in this table the following parameters must be configured:
   - Sub-function value. Range: uint8 (Sub-functions must be always ordered)
   - Sub-function is supported or not. Range: TRUE/FALSE
   - Security level for the sub-function. Range: uint8. See section Service Table 
     Parameters for more info on security level configuration.
*/
#endif  /* DCM_USE_DEM == STD_ON                                              */

#endif  /* DCM_CONFIGURATION_TYPE != DCM_LINK_TIME                            */

/* Value used to expresss the fact that the service is not supported          */
#define SNSID 0xFF

#undef DCM_CFG_EXTERN

#endif /* DCM_CFG_H */
/*** End of file **************************************************************/
