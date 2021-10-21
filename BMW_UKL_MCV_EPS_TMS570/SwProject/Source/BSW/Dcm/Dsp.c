/*

  SRC-MODULE: Dsp.c

  Copyright (C) BMW Group 2007

  TARGET    : All

  PROJECT   : BMW Standard Core 7

  AUTHOR    : Norbert Gaier

  PURPOSE   : Dcm module - DSP Part C source file

  REMARKS   :

  PLATFORM DEPENDANT [yes/no]: no

  TO BE CHANGED BY USER [yes/no]: no

*/

/*
                      Author Identity                                       


 Initials     Name                       Company
 --------     -------------------------  -------------------------------------
 gan          Norbert Gaier              Softing AG
 vm           Volker Matthes             BMW
 scma         Scheitterer Martin         MB Technology
 wab          Wolfgang Aberle            MB Technology
 anam         Andreas Amann              MB Technology
 gema         Markus Gerngross           MB Technology
*/

/*
                      Revision Control History                              
*/

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
 *          2009.02.26, vm  : CR 70094 reworked 
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
 *          2010.01.18, anam: CR 70453, CR 70493, CR 70496 - Bug-fixing changes 
 * v 2.4.5, 2010.06.30, anam: CR 70685: Argument mismatch in call to Rte_DcmGetSeed()
 * v 2.5.0, 2010.10.26, anam: CR 70846: DCM: Completion of the OBD Sevices Implementation in DCM 
 *                                      according to the Autosar DCM V.3.1
 *          2010.10.26, anam: CR 70809: Dcm: Missing or incomplete compiler abstraction   
 */


/**************************************************************************************************************************
 * Nxtr Version Control:
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
10/05/16     EA3#3     ABS        Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
**************************************************************************************************************************/


#define __DSP_C__

/*
                      Include Section
*/

#include "Dcm.h"
#include "Std_types.h"
#if (DCM_CONFIGURATION_TYPE==DCM_LINK_TIME)
 #include "Dcm_Lcfg.h"
#endif
#if (DCM_DEV_ERROR_DETECT==STD_ON)
 #include "Det.h"
#endif
#if DCM_USE_DEM==STD_ON
  #include "Dem.h"
#endif
#include "Rte_dcm.h"

/*
                      Local Macros
*/

#define DCM_AR_EXTERN extern

/*
                      Global Data
*/


#if DCM_USE_DEM==STD_ON
#define DCM_START_SEC_CONST_8BIT
#include "MemMap.h"
/* lengths of the subfunctions for UDS service 0x19 Read DTC Info */
static CONST(uint8,DCM_CONST) DtcInfoSubFunctionLengths[0x14] =
{
    READDTCINFORMATIONSUBFUNCTION1LENGTH ,   /*! Read DTC information sub-function 0x01*/
    READDTCINFORMATIONSUBFUNCTION2LENGTH ,   /*! Read DTC information sub-function 0x02*/
    READDTCINFORMATIONSUBFUNCTION3LENGTH ,   /*! Read DTC information sub-function 0x03*/
    READDTCINFORMATIONSUBFUNCTION4LENGTH  ,  /*! Read DTC information sub-function 0x04*/
    READDTCINFORMATIONSUBFUNCTION5LENGTH  ,  /*! Read DTC information sub-function 0x05*/
    READDTCINFORMATIONSUBFUNCTION6LENGTH  ,  /*! Read DTC information sub-function 0x06*/
    READDTCINFORMATIONSUBFUNCTION7LENGTH  ,  /*! Read DTC information sub-function 0x07*/
    READDTCINFORMATIONSUBFUNCTION8LENGTH  ,  /*! Read DTC information sub-function 0x08*/
    READDTCINFORMATIONSUBFUNCTION9LENGTH  ,  /*! Read DTC information sub-function 0x09*/
    READDTCINFORMATIONSUBFUNCTIONALENGTH ,   /*! Read DTC information sub-function 0x0A*/
    READDTCINFORMATIONSUBFUNCTIONBLENGTH ,   /*! Read DTC information sub-function 0x0B*/
    READDTCINFORMATIONSUBFUNCTIONCLENGTH ,   /*! Read DTC information sub-function 0x0C*/
    READDTCINFORMATIONSUBFUNCTIONDLENGTH ,   /*! Read DTC information sub-function 0x0D*/
    READDTCINFORMATIONSUBFUNCTIONELENGTH ,   /*! Read DTC information sub-function 0x0E*/
    READDTCINFORMATIONSUBFUNCTIONFLENGTH ,   /*! Read DTC information sub-function 0x0F*/
    READDTCINFORMATIONSUBFUNCTION10LENGTH,   /*! Read DTC information sub-function 0x10*/
    READDTCINFORMATIONSUBFUNCTION11LENGTH,   /*! Read DTC information sub-function 0x11*/
    READDTCINFORMATIONSUBFUNCTION12LENGTH,   /*! Read DTC information sub-function 0x12*/
    READDTCINFORMATIONSUBFUNCTION13LENGTH,   /*! Read DTC information sub-function 0x13*/
    READDTCINFORMATIONSUBFUNCTION14LENGTH,   /*! Read DTC information sub-function 0x14*/
};
#define DCM_STOP_SEC_CONST_8BIT
#include "MemMap.h"
#endif


#if DCM_CONFIGURATION_TYPE==DCM_PRE_COMPILE

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*default protocol timings taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_TimerServerType,DCM_CONST) Dcm_ProtocolDefaultTiming[DCM_NUMBER_OF_PROTOCOLS];

/*limit timing parameters taken from Dcm.c*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
DCM_AR_EXTERN CONST(Dcm_TimerServerType,DCM_CONST) Dcm_ProtocolLimitsTiming[DCM_NUMBER_OF_PROTOCOLS];
#endif

/*RxPdu information taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolRxTableType,DCM_CONST) Dcm_ProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID];

/*TxPdu configuration taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolTxTableType,DCM_CONST) Dcm_ProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID];

/*Session level information taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_SessionLevelTableType,DCM_CONST) Dcm_SessionLevel[DCM_NUMBER_OF_SESSION_LEVELS];

/*Service identifier table taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_ServiceIdentifierTableType,DCM_CONST) Dcm_ServiceIdTable[DCM_NUMBER_OF_SERVICE_ID];

/*Protocol information taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_DiagnosticProtocolTableType,DCM_CONST) Dcm_ProtocolTable[DCM_NUMBER_OF_PROTOCOLS];

DCM_AR_EXTERN CONST(Dcm_ReadDTCSubFunctionTableType,DCM_CONST) Dcm_SubFunctions0x19[DCM_NUMBER_OF_SUBFUNCTIONS_0x19];

DCM_AR_EXTERN CONST(Dcm_SecLevelTableType,DCM_CONST) Dcm_SecLevel[DCM_NUMBER_OF_SECURITY_LEVELS];

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#else

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*default protocol timings taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_TimerServerType,DCM_VAR) Dcm_ProtocolDefaultTiming[DCM_NUMBER_OF_PROTOCOLS];

/*limit timing parameters taken from Dcm.c*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
DCM_AR_EXTERN VAR(Dcm_TimerServerType,DCM_VAR) Dcm_ProtocolLimitsTiming[DCM_NUMBER_OF_PROTOCOLS];
#endif

/*RxPdu information taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolRxTableType,DCM_VAR) Dcm_ProtocolRxTable[DCM_NUMBER_OF_DCMRXPDUID];

/*TxPdu configuration taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolTxTableType,DCM_VAR) Dcm_ProtocolTxTable[DCM_NUMBER_OF_DCMTXPDUID];

/*Session level information taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_SessionLevelTableType,DCM_VAR) Dcm_SessionLevel[DCM_NUMBER_OF_SESSION_LEVELS];

/*Service identifier table taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_ServiceIdentifierTableType,DCM_VAR) Dcm_ServiceIdTable[DCM_NUMBER_OF_SERVICE_ID];

/*Protocol information taken from Dcm.c*/
DCM_AR_EXTERN VAR(Dcm_DiagnosticProtocolTableType,DCM_VAR) Dcm_ProtocolTable[DCM_NUMBER_OF_PROTOCOLS];

DCM_AR_EXTERN VAR(Dcm_ReadDTCSubFunctionTableType,DCM_VAR) Dcm_SubFunctions0x19[DCM_NUMBER_OF_SUBFUNCTIONS_0x19];

DCM_AR_EXTERN VAR(Dcm_SecLevelTableType,DCM_VAR) Dcm_SecLevel[DCM_NUMBER_OF_SECURITY_LEVELS];

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif



#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
VAR(uint8,DCM_VAR) Dcm_PagedBufferFlag;
#endif
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_16BIT
#include "MemMap.h"
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
/*! this is used to store the number of bytes that have been sent with the PagedBuffer*/
VAR(uint16,DCM_VAR) Dcm_LengthSoFar;

/*! this is the total length of the buffer used in PagedBuffer processing (this will be filled for each Dsp_DcmUpdatePage)*/
VAR(PduLengthType,DCM_VAR) Dcm_PagedBufferLength;

/*! this is the length of the request. It has to be stored so that the request can be simulated in the PagedBuffer processing*/
VAR(Dcm_MsgLenType,DCM_VAR) Dcm_RequestLength;
#endif
#define DCM_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#if DCM_PAGEDBUFFER_ENABLED==STD_ON
/*! used for pagedbuffer processing to signal which function must still process*/
VAR(Dcm_DiagnosticServiceType, DCM_VAR) Dcm_PagedBufferService;
#endif
#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*Buffer configuration taken from Dcm.c*/
DCM_AR_EXTERN CONST(Dcm_DiagnosticBufferCgfType,DCM_CONST) Dcm_DiagnosticBufferCfg[DCM_NUMBER_OF_BUFFER_ID];
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
DCM_AR_EXTERN P2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) Dcm_pMsgContext2;

DCM_AR_EXTERN VAR(Dcm_Current_Message_Status_Type,DCM_VAR) Dcm_Current_Message_Status;

DCM_AR_EXTERN VAR(Dcm_TimerServerType,DCM_VAR) Dcm_CurrentTimingParameter;

#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
DCM_AR_EXTERN P2VAR(Dcm_TimerServerType,AUTOMATIC,DCM_APPL_DATA) Dcm_NewTimingValues;
DCM_AR_EXTERN VAR(Dcm_TimerServerType,DCM_VAR) Dcm_NewTimings;
#endif

#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
DCM_AR_EXTERN VAR(uint8,DCM_VAR) Dcm_SecurityTimeOutNr;
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/*
                      Local Data
*/

#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#define DCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if ((defined DCM_OBD_SERVICE_0x01_SUPPORTED)&&(DCM_OBD_SERVICE_0x01_SUPPORTED == STD_ON))
static CONST(Dcm_ObdAvailabilityDataType,DCM_CONST) Dcm_AvailabilityPids_0x01[DCM_OBD_NUMBER_OF_AVAILABILITY_PIDS] = DCM_OBD_AVAILABILITY_PID_CFG_TABLE;
static CONST(Dcm_ObdPidConfigType,DCM_CONST) Dcm_ObdPidCfg[DCM_OBD_NUMBER_OF_PIDS_SERVICE_0x01] = DCM_OBD_PID_CFG_TABLE;
#endif /*((defined DCM_OBD_SERVICE_0x01_SUPPORTED)&&(DCM_OBD_SERVICE_0x01_SUPPORTED == STD_ON))*/

#if ((defined DCM_OBD_SERVICE_0x06_SUPPORTED)&&(DCM_OBD_SERVICE_0x06_SUPPORTED == STD_ON))
static CONST(Dcm_ObdAvailabilityDataType,DCM_CONST) Dcm_AvailabilityOBDMIDs[DCM_OBD_NUMBER_OF_AVAILABILITY_OBDMIDS] = DCM_OBD_AVAILABILITY_OBDMID_CFG_TABLE;
static CONST(Dcm_ObdObdmidConfigType,DCM_CONST) Dcm_ObdObdmidCfg[DCM_OBD_NUMBER_OF_OBDMID_TIDS] = DCM_OBD_OBDMID_CFG_TABLE;
#endif /*((defined DCM_OBD_SERVICE_0x06_SUPPORTED)&&(DCM_OBD_SERVICE_0x06_SUPPORTED == STD_ON))*/

#if ((defined DCM_OBD_SERVICE_0x08_SUPPORTED)&&(DCM_OBD_SERVICE_0x08_SUPPORTED == STD_ON))
static CONST(Dcm_ObdAvailabilityDataType,DCM_CONST) Dcm_AvailabilityTIDs[DCM_OBD_NUMBER_OF_AVAILABILITY_TIDS] = DCM_OBD_AVAILABILITY_TID_CFG_TABLE;
static CONST(Dcm_ObdReqControlConfigType,DCM_CONST) Dcm_ObdReqControlCfg[DCM_OBD_NUMBER_OF_REQ_CONTROL_TIDS] = DCM_OBD_REQ_CONTROL_CFG_TABLE;
#endif /*((defined DCM_OBD_SERVICE_0x08_SUPPORTED)&&(DCM_OBD_SERVICE_0x08_SUPPORTED == STD_ON))*/

#if ((defined DCM_OBD_SERVICE_0x09_SUPPORTED)&&(DCM_OBD_SERVICE_0x09_SUPPORTED == STD_ON))
static CONST(Dcm_ObdAvailabilityDataType,DCM_CONST) Dcm_AvailabilityInfoTypes[DCM_OBD_NUMBER_OF_AVAILABILITY_INFO_TYPES] = DCM_OBD_AVAILABILITY_INFO_TYPE_CFG_TABLE;
static CONST(Dcm_ObdVehInfoConfigType,DCM_CONST) Dcm_ObdVehicleInfoCfg[DCM_OBD_NUMBER_OF_INFO_TYPES] = DCM_OBD_VEHICLE_INFO_CFG_TABLE;
#endif /*((defined DCM_OBD_SERVICE_0x09_SUPPORTED)&&(DCM_OBD_SERVICE_0x09_SUPPORTED == STD_ON))*/

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

#define DCM_START_SEC_VAR_8BIT
#include "MemMap.h"
/*! used for SecurityAccess service*/
VAR(uint8,DCM_VAR) Dcm_CalcSeed;

/*! temporary buffer used for retrieving DEM information*/
VAR(uint8,DCM_VAR) Dcm_Buffer[255];

/*! length of the Dcm_Buffer*/
VAR(uint8,DCM_VAR) Dcm_BufferLength=255;

/*! Stores the number of failed attempts at security level*/
VAR(uint8,DCM_VAR) Dcm_NumberOfAttempts[DCM_NUMBER_OF_SECURITY_LEVELS];

/*! used for service RequestFreezeFrameData*/
VAR(uint8,DCM_VAR) Dcm_StopOBDProcessing;

#if DCM_PAGEDBUFFER_ENABLED==STD_ON
/*! this is the actual request data, needed for the PagedBuffer processing. No request is larger that 10 bytes (request processed in DSP)*/
VAR(uint8,DCM_VAR) Dcm_RequestBuffer[10];

VAR(Dcm_MsgType,DCM_VAR) Dcm_RequestData=&Dcm_RequestBuffer[0];
#endif
#define DCM_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define DCM_START_SEC_VAR_FAST_16BIT
#include "MemMap.h"
#if DCM_DEV_ERROR_DETECT==STD_ON
VAR(uint16,DCM_VAR) Dcm_DspReentrancy;
#endif
#define DCM_STOP_SEC_VAR_FAST_16BIT
#include "MemMap.h"

/*
                      Local Function Prototypes
*/
#if DCM_USE_DEM==STD_ON

#define DCM_START_SEC_CODE
#include "MemMap.h"

/* ReadDTCInformation subfunctions implemented by DSP - 21 functions*/
#if (DCM_READDTC_SUBFUNCTION01_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportNumberOfDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);  /* 01*/
#endif

#if (DCM_READDTC_SUBFUNCTION02_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);        /*02*/
#endif

#if (DCM_READDTC_SUBFUNCTION03_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportDTCSnapshotIdentification(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*03*/
#endif

#if (DCM_READDTC_SUBFUNCTION04_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportDTCSnapshotByDTCNumber(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*04*/
#endif

#if (DCM_READDTC_SUBFUNCTION05_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportDTCSnapshotRecordByRecordNumber(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*05*/
#endif

#if (DCM_READDTC_SUBFUNCTION06_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportDTCExtendedDataRecordByDTCNumber(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);/*06*/
#endif

#if (DCM_READDTC_SUBFUNCTION07_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportNumberOfDTCBySeverityMaskRecord(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);/*07*/
#endif

#if (DCM_READDTC_SUBFUNCTION08_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportDTCBySeverityMaskRecord(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*08*/
#endif

#if (DCM_READDTC_SUBFUNCTION09_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportSeverityInformationOfDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*09*/
#endif

#if (DCM_READDTC_SUBFUNCTION0A_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportSupportedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*0A*/
#endif

#if (DCM_READDTC_SUBFUNCTION0B_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportFirstTestFailedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*0B*/
#endif

#if (DCM_READDTC_SUBFUNCTION0C_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportFirstConfirmedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*0C*/
#endif

#if (DCM_READDTC_SUBFUNCTION0D_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportMostRecentTestFailedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*0D*/
#endif

#if (DCM_READDTC_SUBFUNCTION0E_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportMostRecentConfirmedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*0E*/
#endif

#if (DCM_READDTC_SUBFUNCTION0F_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportMirrorMemoryDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*0F*/
#endif

#if (DCM_READDTC_SUBFUNCTION10_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportMirrorMemoryDTCExtendedRecordByDTCNumber(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*10*/
#endif

#if (DCM_READDTC_SUBFUNCTION11_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportNumberOfMirrorMemoryDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*11*/
#endif

#if (DCM_READDTC_SUBFUNCTION12_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportNumberOfEmissionsRelatedOBDDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*12*/
#endif

#if (DCM_READDTC_SUBFUNCTION13_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportEmissionsRelatedOBDDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*13*/
#endif

#if (DCM_READDTC_SUBFUNCTION14_ENABLED==STD_ON)
FUNC(void,DCM_CODE) Dcm_ReportDTCFaultDetectionCounter(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext); /*14*/
#endif
/*auxiliary function used - 9 functions*/
#if ((DCM_READDTC_SUBFUNCTION0B_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0C_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0D_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0E_ENABLED==STD_ON))
FUNC(void,DCM_CODE) Dcm_ReportFailedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,Dem_DTCRequestType requestDTC);
#endif

#if ((DCM_READDTC_SUBFUNCTION02_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0A_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0F_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION13_ENABLED==STD_ON))
FUNC(void,DCM_CODE) Dcm_ReportFilteredDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext, Dem_DTCStatusMaskType DTCStatusMask);
#endif

#if ((DCM_READDTC_SUBFUNCTION06_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION10_ENABLED==STD_ON))
FUNC(void,DCM_CODE) Dcm_ReportDTCExtendedData(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);
#endif

#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
FUNC(uint8,DCM_CODE) Dcm_RequestSupportedPID(uint8 pid,uint8 fzf,CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) len);
FUNC(uint8,DCM_CODE) Dcm_RequestDTCOfFreezeFrame(uint8 pid, 
                                                 uint8 fzf, 
                                                 CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
                                                 P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) len,
                                                 CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ResponseCode);
FUNC(uint8,DCM_CODE) Dcm_RequestDataRecords(uint8 pid, uint8 fzf, 
                                            CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
                                            P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) len,
                                            P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ResponseCode);
static FUNC(uint8,DCM_CODE) Dcm_ObdHandleDataPid(uint8 PID, 
                                                 CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
                                                 P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength,
                                                 P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ResponseCode);
static FUNC(void,DCM_CODE) Dcm_ObdReportFilteredDtcs(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext);

static FUNC(Std_ReturnType,DCM_CODE) Dcm_ObdHandleDataObdmid(uint8 OBDMID, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength);

static FUNC(void,DCM_CODE) Dcm_ObdHandleAvailabilityId(
    uint8 AvailabilityID, 
    const uint8 NumberOfAvailabilityIDs,
    CONSTP2CONST(Dcm_ObdAvailabilityDataType,AUTOMATIC,DCM_APPL_DATA) AvailabilityIdDataTable,
    CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength
    );

static FUNC(Std_ReturnType,DCM_CODE) Dcm_ObdHandleDataVehicleInfo(uint8 InfoType, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength);

static FUNC(Std_ReturnType,DCM_CODE) Dcm_ObdHandleDataTid(uint8 TID, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength);

static FUNC(void,DCM_CODE) Dcm_ObdGetIdType(uint8 PID,P2VAR(Dcm_ObdIdType, AUTOMATIC, DCM_APPL_DATA) IdType);
static FUNC(void,DCM_CODE) Dcm_ObdHandleResponse(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
                                                 Dcm_NegativeResponseCodeType ResponseCode,
                                                 uint16 MessageLength);

#endif


#if (DCM_USE_DEM==STD_ON)
FUNC(uint8,DCM_CODE) Dcm_VerifyPagedBuffer(uint16 CurrentLength, Dcm_MsgType buffer, uint8 data);

static FUNC(void, DCM_CODE) Dcm_Write3BytesInU8Array(uint32 bytesToWrite, CONSTP2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) u8Array);

static FUNC(uint32, DCM_CODE) Dcm_Read3BytesFromU8Array(CONSTP2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) u8Array);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif

/*
                      Local Data
*/

#if DCM_USE_DEM==STD_ON

#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/*! All function pointers to sub-functions of service 0x19*/
P2FUNC(void, AUTOMATIC, Dcm_ptrReadDTCInformation[DCM_NUMBER_OF_SUBFUNCTIONS_0x19])(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)= \
{
#if (DCM_READDTC_SUBFUNCTION01_ENABLED==STD_ON)
Dcm_ReportNumberOfDTCByStatusMask
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION02_ENABLED==STD_ON)
Dcm_ReportDTCByStatusMask
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION03_ENABLED==STD_ON)
Dcm_ReportDTCSnapshotIdentification
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION04_ENABLED==STD_ON)
Dcm_ReportDTCSnapshotByDTCNumber
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION05_ENABLED==STD_ON)
Dcm_ReportDTCSnapshotRecordByRecordNumber
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION06_ENABLED==STD_ON)
Dcm_ReportDTCExtendedDataRecordByDTCNumber
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION07_ENABLED==STD_ON)
Dcm_ReportNumberOfDTCBySeverityMaskRecord
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION08_ENABLED==STD_ON)
Dcm_ReportDTCBySeverityMaskRecord
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION09_ENABLED==STD_ON)
Dcm_ReportSeverityInformationOfDTC
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION0A_ENABLED==STD_ON)
Dcm_ReportSupportedDTC
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION0B_ENABLED==STD_ON)
Dcm_ReportFirstTestFailedDTC
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION0C_ENABLED==STD_ON)
Dcm_ReportFirstConfirmedDTC
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION0D_ENABLED==STD_ON)
Dcm_ReportMostRecentTestFailedDTC
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION0E_ENABLED==STD_ON)
Dcm_ReportMostRecentConfirmedDTC
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION0F_ENABLED==STD_ON)
Dcm_ReportMirrorMemoryDTCByStatusMask
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION10_ENABLED==STD_ON)
Dcm_ReportMirrorMemoryDTCExtendedRecordByDTCNumber
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION11_ENABLED==STD_ON)
Dcm_ReportNumberOfMirrorMemoryDTCByStatusMask
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION12_ENABLED==STD_ON)
Dcm_ReportNumberOfEmissionsRelatedOBDDTCByStatusMask
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION13_ENABLED==STD_ON)
Dcm_ReportEmissionsRelatedOBDDTCByStatusMask
#else
0
#endif
,
#if (DCM_READDTC_SUBFUNCTION14_ENABLED==STD_ON)
Dcm_ReportDTCFaultDetectionCounter
#else
0
#endif
,0
};
#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#endif

/*
                      Global Functions
*/

/*
*! Function for confirmation of messages that were processed in DSP
*
* \name Dsp_DcmConfirmation
*
* \b Service-Id:   0x15
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   Dcm_IdContextType idContext - IdContext of the message that is confirmed
*                  PduIdType DcmRxPduId - RxPduId of the confirmed message
*                  Dcm_ConfirmationStatusType status - the status of the confirmation
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function is called by the DSL layer whenever a confirmation arrives and the data processor
*  that handled service was DSP.
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dsp_DcmConfirmation  (Dcm_IdContextType idContext,
                           PduIdType DcmRxPduId,
                           Dcm_ConfirmationStatusType status
                          )
{
  /*nothing to be done here.....all processing is done in Dcm_TxConfirmation
    the processing from TxConfirmation refers to timers and other issues that have no effect on DSP
    so no variable reset, flag reset or other processing needs to be done in DSP at the call of this function*/
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"


/*
*! Function for updating the next page during the PagedBuffer processing
*
* \name Dsp_DcmUpdatePage
*
* \b Service-Id:   0x29
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   Dcm_MsgType PageBufPtr - address of page to be filled
*                  Dcm_MsgLenType PageLen - the size of the page
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function is used during the DSP PagedBuffer processing. By calling this function, the new page from
*  the PagedBuffer processing has to given. This call shall be triggered by DSL when the lower layer asks
*  for the next buffer using Dcm_ProvideTxBuffer(). The parameter PageBufPtr is the page address and parameter
*  PageLen is the size of the page (maximum number of bytes that can be written in the page). This function shall
*  call Dcm_ProcessPage when the page has been filled. The function shall be present only if the PagedBuffer
*  mechanism is enabled (flag DCM_PAGEDBUFFER_ENABLED is set to STD_ON).
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"

FUNC(void,DCM_CODE) Dsp_DcmUpdatePage(Dcm_MsgType PageBufPtr,Dcm_MsgLenType PageLen)
{
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
  #if DCM_DEV_ERROR_DETECT==STD_ON
   if ((Dcm_DspReentrancy&0x0001)==0x0000)
   {
     Dcm_DspReentrancy|=0x0001;/*set*/
  #endif
     Dcm_pMsgContext2->reqData=Dcm_RequestData;

     if (Dcm_PagedBufferService)
     {
       Dcm_pMsgContext2->resData=PageBufPtr;
       Dcm_pMsgContext2->resMaxDataLen=PageLen;
     }
   #if DCM_DEV_ERROR_DETECT==STD_ON
     Dcm_DspReentrancy&=0xFFFE;/*clear*/
   }
   #endif
   #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function for updating the next page during the PagedBuffer processing
*
* \name Dsp_DcmCancelPagedBufferProcessing
*
* \b Service-Id:   0x30
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          none
*
* \b Description:  This function is called whenever the PagedBuffer processing must be interrupted because of errors.
*  These errors are due to timing issues (e.g. the page was not processed in due time). This function
*  shall stop the PagedBuffer processing. It shall be implemented only if the PagedBuffer mechanism is enabled
*  (flag DCM_PAGEDBUFFER_ENABLED is set to STD_ON).
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dsp_DcmCancelPagedBufferProcessing(void)
{
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
  #if DCM_DEV_ERROR_DETECT==STD_ON
  if ((Dcm_DspReentrancy&0x0002)==0x0000)
  {
    Dcm_DspReentrancy|=0x0002;/*set         */
  #endif  
    Dcm_PagedBufferFlag=2;/*exit by cancellation*/
  #if DCM_DEV_ERROR_DETECT==STD_ON  
    Dcm_DspReentrancy&=0xFFFD;/*clear*/
    return;
  }
  #endif
  #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used for processing the OBD service 0x02
*
* \name Dcm_RequestSupportedPID
*
* \b Service-Id:   0x31
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 pid - the PID for which the processing is done
*                  uint8 fzf - FreezeFrame
*
* \param (Output)  Dcm_MsgContextType *pMsgContext - structure that contains information about the service
*
* \return          uint8 - result of the operation (relevant for PagedBuffer processing)
*
* \b Description:  This function is used to retrieve the supported PID data identifiers OBD service 0x02 with sub-function 0x00 or multiple of 0x20).
*  Functions from DEM Dcm_Module shall be called to obtain the required information. In case of errors, corresponding
*  negative responses shall be sent. For more information about the processing this function has to do please
*  refer to ISO 15031-5.4. This function can be reentrant.
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(Dcm_NegativeResponseCodeType,DCM_CODE) Dcm_RequestSupportedPID(uint8 pid,uint8 fzf,CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) len)
{
    Dcm_NegativeResponseCodeType RetVal = DCM_E_OK;
    uint8 i;
    uint8 BufSize = 4; /*fixed length for supported pids*/
    
    if( E_OK != Dem_GetOBDFreezeFrameData(pid,&Dcm_Buffer[0],&BufSize))
    {
        RetVal = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        if( 0x00 != BufSize)
        {
            pMsgContext->resData[(*len)++] = pid;
            pMsgContext->resData[(*len)++] = fzf;
            for(i = 0 ; i < BufSize ; i++)
            {
                pMsgContext->resData[(*len)++] = Dcm_Buffer[i];
            }
        }
    }
    return RetVal;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif
/*
*! Function used for processing the OBD service 0x02
*
* \name Dcm_RequestDTCOfFreezeFrame
*
* \b Service-Id:   0x32
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 pid - the PID for which the processing is done
*                  uint8 fzf - FreezeFrame
*
* \param (Output)  Dcm_MsgContextType *pMsgContext - structure that contains information about the service
*
* \return          uint8 - result of the operation (relevant for PagedBuffer processing)
*
* \b Description:  This function is used by the service 0x02 (OBD) and sub-function 0x02. For more information about the
*  processing of this function please refer to ISO 15031-5.4
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8,DCM_CODE) Dcm_RequestDTCOfFreezeFrame(uint8 pid, 
                        uint8 fzf, 
                        CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
                        P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) len,
                        CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ResponseCode)
{
   uint8 temp;
   uint32 DTC;

   temp=(uint8)Dem_GetDTCOfFreezeFrameRecord(fzf,DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_DTC_KIND_EMISSION_REL_DTCS,&DTC);
   /*the DTC shall be correct when return valule is DEM_GET_DTCOFFF_OK
     if return value is something else, the DTC variable shall not be used
     0 will be filled if there is no DTC for record*/

   if (temp==(uint8)DEM_GET_DTCOFFF_OK)
   {
      if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,pid))
        return 1;
      if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,fzf))
        return 1;
      #if (DCM_DTC_TYPE_FOR_OBD==STD_ON)
        /*DTC 2Byte-> |0000|0000    |HighByte  |LowByte|*/
        if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,(uint8)((DTC & 0x0000FF00) >>8)))
           return 1;
        if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,(uint8)(DTC & 0x000000FF)))
           return 1;
      #else /*(DCM_DTC_TYPE_FOR_OBD==STD_OFF)*/
        /*DTC 2Byte-> |0000|HighByte|LowByte|0000|*/
        if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,(uint8)((DTC & 0x00FF0000) >>16)))
           return 1;
        if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,(uint8)((DTC & 0x0000FF00) >>8)))
           return 1;
      #endif
   }
   else
   {
     if (temp == (uint8)DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD)
     {
       if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,pid))
         return 1;
       if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,fzf))
         return 1;
       /*if there is no DTC just place 0*/
       if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,0x00))
          return 1;
       if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,0x00))
          return 1;
     }
     else
     {
       *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
     }
   }
   return 0;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
*! Function used for processing the OBD service 0x02
*
* \name Dcm_RequestDataRecords
*
* \b Service-Id:   0x33
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 pid - the PID for which the processing is done
*                  uint8 fzf - FreezeFrame
*
* \param (Output)  Dcm_MsgContextType *pMsgContext - structure that contains information about the service
*
* \return          uint8 - result of the operation (relevant for PagedBuffer processing)
*
* \b Description:  This function is used by the service 0x02 (OBD) and sub-function different from 0x00, 0x02 and no multiple
*  of 0x20. For more information about the processing of this function please refer to ISO 15031-5.4
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8,DCM_CODE) Dcm_RequestDataRecords(uint8 pid, uint8 fzf, 
                        CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
                        P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) len,
                        P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ResponseCode)
{
    uint8 i;

    Dcm_BufferLength = 255;
    if( E_OK != Dem_GetOBDFreezeFrameData(pid,&Dcm_Buffer[0],&Dcm_BufferLength))
    {
        *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    else
    {
        if( 0x00 != Dcm_BufferLength)
        {
            if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,pid))
               return 1;
            if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,fzf))
               return 1;
            for(i = 0 ; i < Dcm_BufferLength ; i++)
            {
                if (1==Dcm_VerifyPagedBuffer((*len)++,pMsgContext->resData,Dcm_Buffer[i]))
                   return 1;
            }
        }
    }
    return 0;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
*! Function used for processing the OBD service 0x02
*
* \name Dcm_DcmRequestFreezeFrameData
*
* \b Service-Id:   0x34
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the OBD service 0x02. For more information please refer to ISO 15031-5.4
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmRequestFreezeFrameData(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*different processing for PID:
    1 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0 (availability PIDs)
    2 0x02 - for the DTC associated to a FreezeFrame
    3 all the rest in other way (data PIDs)
    three different processings - three different functions for each processing */
    uint8 PID[3]={0,0,0};
    uint8 FreezeFrame[3]={0,0,0};
    uint8 NRPID;
    uint8 i;
    uint16 MessageLength;
    Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
    Dcm_ObdIdType IdType = DCM_OBD_NO_ID;

    if (    (DCM_REQUESTFREEZEFRAMEDATALENGTH > pMsgContext->reqDataLen)
         || (DCM_OBD_REQUEST_MAX_LEN < pMsgContext->reqDataLen)
         || ((pMsgContext->reqDataLen % 2) != 0) )
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
        return;
    }

    /*can be at most 3 PID...each must be analysed*/
    NRPID=(uint8)((pMsgContext->reqDataLen) / 2); /*(pMsgContext->reqDataLen - 1)*/
    for (i=0;i<NRPID;i++)
    {
      PID[i]=pMsgContext->reqData[i*2];
      FreezeFrame[i]=pMsgContext->reqData[(i*2)+1];
    }

    #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (!Dcm_PagedBufferService)
    {
        Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=0;/*no information at beginning */
        for (i=0;i<NRPID;i++)
        {
            if( 0x00 == FreezeFrame[i] )
            {
                Dcm_ObdGetIdType(PID[i],&IdType);
                switch(IdType)
                {
                    case DCM_OBD_DATA_ID:
                        if (0x02 == PID[i])
                        {
                            /* special processing - point 3 */
                            Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen += 4; /*pid, fzf, DTC HB, DTC LB*/
                        }
                        else
                        {
                            Dcm_BufferLength = 255; /*this is the size that can be filled in the Dcm_Buffer*/
                            if( E_OK != Dem_GetOBDFreezeFrameData(PID[i],&Dcm_Buffer[0],&Dcm_BufferLength))
                            {
                                Dcm_HandleNegResponse(pMsgContext,DCM_E_CONDITIONSNOTCORRECT);
                                return;
                            }
                            else
                            {
                                Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen += (Dcm_BufferLength + 2); /* Buffer + PID + FreezeFrame*/
                            }
                        }
                        break;
                    case DCM_OBD_AVAILABILITY_ID:
                        /*no paged buffering for availability pids*/
                    default:
                        break;
                }
            }
            else
            {
                /* request with record number != 0 are ignored */
            }
        } /*end of for*/
        Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
        if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)
        {
            Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;/*service Id is counted but will be added later        */
            Dcm_PagedBufferService=Dcm_DcmRequestFreezeFrameData;
            pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length        */
            for (i=0;i<pMsgContext->reqDataLen;i++)
            {
                Dcm_RequestData[i]=pMsgContext->reqData[i];
            }
            Dcm_LengthSoFar=0;
            Dcm_StartPagedProcessing(pMsgContext);
            return; /*end here the processing     */
        }
        else
        {
            Dcm_LengthSoFar=0;
            Dcm_PagedBufferService=0;
        }
    }
    #endif


    MessageLength=0x00; /*because the SID is missing from the response*/
    #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (Dcm_PagedBufferService)
      MessageLength++;
    #endif

    
    for (i=0;i<NRPID;i++)
    {
        if( 0x00 == FreezeFrame[i] )
        {
            Dcm_ObdGetIdType(PID[i],&IdType);
            switch(IdType)
            {
                case DCM_OBD_AVAILABILITY_ID:
                    /* handling of availability pid */
                    ResponseCode = Dcm_RequestSupportedPID(PID[i],FreezeFrame[i],pMsgContext,&MessageLength);
                    break;
                case DCM_OBD_DATA_ID:
                    if (PID[i]==0x02)
                    {
                        /*special processing for PID 0x02           */
                        if (1==Dcm_RequestDTCOfFreezeFrame(PID[i],FreezeFrame[i],pMsgContext,&MessageLength,&ResponseCode))
                        {
                            return;
                        }
                    }
                    else
                    {
                        /*this is for all the others - point 2*/
                        if (1==Dcm_RequestDataRecords(PID[i],FreezeFrame[i],pMsgContext,&MessageLength,&ResponseCode))
                        {
                            return;
                        }
                    }
                    break;
                default:
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
            }
        }
        else
        {
            /* request with record number != 0 are ignored */
        }
        if(DCM_E_OK != ResponseCode)
        {
            /* cancel the loop*/
            break;
        }
    }
    Dcm_ObdHandleResponse(pMsgContext,ResponseCode,MessageLength);
    return;
}

#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
*! Function used for processing the OBD service 0x03
*
* \name Dcm_DcmRequestEmissionRelatedDTC
*
* \b Service-Id:   0x35
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x03 (RequestEmissionRelatedDTC)
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmRequestEmissionRelatedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{

    if (!(REQUESTEMISSIONRELATEDDTCLENGTH == pMsgContext->reqDataLen))
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    }
    /*filter the DTCs*/
    else if(Dem_SetDTCFilter(0x08,DEM_DTC_KIND_EMISSION_REL_DTCS,\
       DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
         DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
      /*all confirmed DTCs*/
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_CONDITIONSNOTCORRECT);
    }
    else
    {
        /*report the filtered DTCs*/
        Dcm_ObdReportFilteredDtcs(pMsgContext);
    }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))) */

/*
*! Function used for processing the OBD service 0x0A
*
* \name Dcm_DcmObdRequestPermanentEmissionRelatedDTC
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x0A (RequestPermanentEmissionRelatedDTC)
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmObdRequestPermanentEmissionRelatedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{

    if (!(REQUESTEMISSIONRELATEDDTCLENGTH == pMsgContext->reqDataLen))
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    }
    /*filter the DTCs*/
    else if(Dem_SetDTCFilter(0x00,DEM_DTC_KIND_EMISSION_REL_DTCS,\
       DEM_DTC_ORIGIN_PERMANENT_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
         DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
      /*all confirmed DTCs*/
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
    }
    else
    {
        /*report the filtered DTCs*/
        Dcm_ObdReportFilteredDtcs(pMsgContext);
    }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))) */

/*
*! Function used for reporting the filtered DTCs
*
* \name Dcm_ReportFilteredDTC
*
* \b Service-Id:   0x67
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
* 
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dem_DTCStatusMaskType DTCStatusMask - indicates the supported DTC status bits from the DEM
*
* \return          none
*
* \b Description:  This function shall insert in the response all the filtered DTCs. The filter was previously set.
* this function will only get the next filtered DTC until there are no more to report.
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_ObdReportFilteredDtcs(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
    uint8 temp;
    uint32 FilteredDTC;
    uint8 FilteredDTCStatus;
    uint16 MessageLength;
    uint8 DTCcount;
    
    /*read DTCs*/
    DTCcount = 0;/*count DTCs to knwo if the message has to be filled with 0x00*/
    MessageLength = 0x01; /* the number of filtered dtcs is added to the buffer afterwards*/
    temp=(uint8)DEM_FILTERED_OK;
    while ((uint8)DEM_FILTERED_OK == temp)
    {
        /* check if buffer size suffices                                     */
        if (   (( pMsgContext->resDataLen + MessageLength + (Dcm_MsgLenType)2U) > pMsgContext->resMaxDataLen )
            && ( DTCcount >= 0xFF ) )
        {
            /* data cannot be transmitted - DCM buffer too small              */

            Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
            return;
        }
        /*read each DTC at a time*/
        temp=(uint8)Dem_GetNextFilteredDTC(&FilteredDTC,&FilteredDTCStatus);
        if (temp==(uint8)DEM_FILTERED_OK)
        {
            DTCcount++;
            #if (DCM_DTC_TYPE_FOR_OBD==STD_ON)
            pMsgContext->resData[MessageLength++]=(uint8)((FilteredDTC & 0x0000FF00) >>8);
            pMsgContext->resData[MessageLength++]=(uint8)((FilteredDTC & 0x000000FF) );    /*DTC 2Byte-> |0000|0000    |HighByte  |LowByte|*/
            #else /*(DCM_DTC_TYPE_FOR_OBD==STD_OFF) */
            pMsgContext->resData[MessageLength++]=(uint8)((FilteredDTC & 0x00FF0000) >>16);
            pMsgContext->resData[MessageLength++]=(uint8)((FilteredDTC & 0x0000FF00) >>8);    /*DTC 2Byte-> |0000|HighByte|LowByte|0000|*/
            #endif
        }
    }
    
    pMsgContext->resData[0]=DTCcount;
    pMsgContext->resDataLen=MessageLength;
    Dcm_ProcessingDone(pMsgContext);
    return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))) */

/*
*! Function used for processing the OBD service 0x04
*
* \name Dcm_DcmClearEmissionRelatedInformation
*
* \b Service-Id:   0x36
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x04 (ClearEmissionRelatedInformation)
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmClearEmissionRelatedInformation(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   Dem_ReturnClearDTCType rez;

   /*for this function no values shall be inserted in the response buffer
     only the SID shall be included when processing reaches DSD         */
   #if DCM_DEV_ERROR_DETECT==STD_ON
   if ((Dcm_DspReentrancy&0x0010)==0x0000)
   {
     Dcm_DspReentrancy|=0x0010;/*set*/
   #endif  
     if (!(CLEAREMISSIONRELATEDINFORMATIONLENGTH == pMsgContext->reqDataLen))
     {
       Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
       #if DCM_DEV_ERROR_DETECT==STD_ON
       Dcm_DspReentrancy&=0xFFEF;/*clear*/
       #endif
       return;
     }
        rez=Dem_ClearDTC(0xFFFFFFFF,DCM_OBD_SERVICE04_KIND,DEM_DTC_ORIGIN_PRIMARY_MEMORY);
     if( DEM_CLEAR_OK == rez )
     {
        pMsgContext->resDataLen=0;
        Dcm_ProcessingDone(pMsgContext);
     }
     else
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_CONDITIONSNOTCORRECT);
     }
   #if DCM_DEV_ERROR_DETECT==STD_ON  
     Dcm_DspReentrancy&=0xFFEF;/*clear*/
     return;
   }
   #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
*! Function used for processing the OBD service 0x07
*
* \name Dcm_DcmReqEmissionRelDTCDrivCyc
*
* \b Service-Id:   0x37
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x07 (RequestEmissionRelatedDTCDrivingCycle)
*/
#if ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON)))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmReqEmissionRelDTCDrivCyc(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
    if (!(REQUESTEMISSIONRELATEDDTCDURINGLASTDRIVINGCYCLELENGTH == pMsgContext->reqDataLen))
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
    }
    /*filter the DTCs*/
    else if(Dem_SetDTCFilter(0x04,DEM_DTC_KIND_EMISSION_REL_DTCS,\
         DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
           DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
        /*all pending DTCs*/
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_CONDITIONSNOTCORRECT);
    }
    else
    {
        /*report the filtered DTCs*/
        Dcm_ObdReportFilteredDtcs(pMsgContext);
    }
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* ((DCM_USE_DEM==STD_ON)&&((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))) 
*/
/*
*! Function used for processing the UDS service 0x83
*
* \name Dcm_DcmAccessTimingParameter
*
* \b Service-Id:   0x38
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x83 (AccessTimingParameter)
*/
#if ((defined DCM_ACCESS_TIMING_PARAMETER_ENABLED) && (DCM_ACCESS_TIMING_PARAMETER_ENABLED==STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmAccessTimingParameter(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint8  Subfunction;
   uint16 TimingValue;
   uint8 temp;

   #if DCM_DEV_ERROR_DETECT==STD_ON
   if ((Dcm_DspReentrancy&=0x0040)==0x0000)
   {
     Dcm_DspReentrancy|=0x0040;/*set            */
   #endif  
     /*if the length is too short*/
     if (pMsgContext->reqDataLen < 1)
     {
       Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
       #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xFFBF;/*clear*/
       #endif 
        return;
     }

    Subfunction=pMsgContext->reqData[0];

    if ((Subfunction>=0x01)&&(Subfunction<=0x03))
    {
      if(!( ACCESSTIMINGPARAMETERLENGTH == (pMsgContext->reqDataLen)))
       {

          Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
          #if DCM_DEV_ERROR_DETECT==STD_ON
          Dcm_DspReentrancy&=0xFFBF;/*clear*/
          #endif
          return;
       }
    }
    else
    {
      if (Subfunction==0x04)
      {
        /*this means along with the message, timing parameters have to come
          so 10 extra bytes should contain the timing parameter information*/
        if (!((ACCESSTIMINGPARAMETERLENGTH + 10)== (pMsgContext->reqDataLen)))
        {
          Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
          #if DCM_DEV_ERROR_DETECT==STD_ON
          Dcm_DspReentrancy&=0xFFBF;/*clear*/
          #endif
          return;
        }
      }
      else
      {
        /*subfunction is not supported         */
        Dcm_HandleNegResponse(pMsgContext,DCM_E_SUBFUNCTIONNOTSUPPORTED);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xFFBF;/*clear*/
        #endif
        return;
      }
    }

    /*if processing reaches here, it means length and sub-function is correct*/
      if (Subfunction == 0x01)
      {        
          /*report extended timing parameters*/
          TimingValue = Dcm_ProtocolLimitsTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_TIMSTR_P2SERVER_MAX;
        pMsgContext->resData[1]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[2]=(uint8)(TimingValue & 0x00FF);
        TimingValue = Dcm_ProtocolLimitsTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_TIMSTR_P2SERVER_MIN;
        pMsgContext->resData[3]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[4]=(uint8)(TimingValue & 0x00FF);
        TimingValue = Dcm_ProtocolLimitsTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_TIMSTR_P2STARSERVER_MAX;
        pMsgContext->resData[5]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[6]=(uint8)(TimingValue & 0x00FF);
        TimingValue = Dcm_ProtocolLimitsTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_TIMSTR_P2STARSERVER_MIN;
        pMsgContext->resData[7]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[8]=(uint8)(TimingValue & 0x00FF);
        TimingValue = Dcm_ProtocolLimitsTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex].DCM_TIMSTR_S3SERVER;
        pMsgContext->resData[9]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[10]=(uint8)(TimingValue & 0x00FF);
        pMsgContext->resDataLen=11;      
        }
      
      if (Subfunction == 0x02)
        {            
          /*set timing parameters to default*/
          Dcm_NewTimingValues=&Dcm_NewTimings;
           *Dcm_NewTimingValues=Dcm_ProtocolDefaultTiming[Dcm_Current_Message_Status.Dcm_ProtocolTableIndex];
         
           temp=(uint8)Dcm_PrepareSesTimingValues(Dcm_NewTimingValues);
         
         if (temp == DCM_E_OK)
           pMsgContext->resDataLen = 0x01;
         if ((temp == DCM_E_TI_PREPARE_INCONSISTENT)||(temp == DCM_E_TI_PREPARE_LIMITS))
         {
               Dcm_NewTimingValues=0;
                
               Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
           #if DCM_DEV_ERROR_DETECT==STD_ON
               Dcm_DspReentrancy&=0xFFBF;/*clear*/
           #endif
               return;
         }                                                                        
      }
      if (Subfunction == 0x03)            
        {
          /*report current timing parameters*/
           TimingValue = Dcm_CurrentTimingParameter.DCM_TIMSTR_P2SERVER_MAX;
        pMsgContext->resData[1]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[2]=(uint8)(TimingValue & 0x00FF);
        TimingValue = Dcm_CurrentTimingParameter.DCM_TIMSTR_P2SERVER_MIN;
        pMsgContext->resData[3]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[4]=(uint8)(TimingValue & 0x00FF);
        TimingValue = Dcm_CurrentTimingParameter.DCM_TIMSTR_P2STARSERVER_MAX;
        pMsgContext->resData[5]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[6]=(uint8)(TimingValue & 0x00FF);
        TimingValue = Dcm_CurrentTimingParameter.DCM_TIMSTR_P2STARSERVER_MIN;
        pMsgContext->resData[7]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[8]=(uint8)(TimingValue & 0x00FF);
        TimingValue = Dcm_CurrentTimingParameter.DCM_TIMSTR_S3SERVER;
        pMsgContext->resData[9]=(uint8)((TimingValue & 0xFF00)>>8);                       
        pMsgContext->resData[10]=(uint8)(TimingValue & 0x00FF);
        pMsgContext->resDataLen=11;      
      }      
      if (Subfunction == 0x04)
        {
          /*set timing parameters to given parameters*/
           Dcm_NewTimingValues=&Dcm_NewTimings;
           Dcm_NewTimingValues->DCM_TIMSTR_TYPE=DCM_LIMITS;
           Dcm_NewTimingValues->DCM_TIMSTR_P2SERVER_MAX=(pMsgContext->reqData[1]<<8) + pMsgContext->reqData[2];
           Dcm_NewTimingValues->DCM_TIMSTR_P2SERVER_MIN=(pMsgContext->reqData[3]<<8) + pMsgContext->reqData[4];
           Dcm_NewTimingValues->DCM_TIMSTR_P2STARSERVER_MAX=(pMsgContext->reqData[5]<<8) + pMsgContext->reqData[6];
           Dcm_NewTimingValues->DCM_TIMSTR_P2STARSERVER_MIN=(pMsgContext->reqData[7]<<8) + pMsgContext->reqData[8];
           Dcm_NewTimingValues->DCM_TIMSTR_S3SERVER=(pMsgContext->reqData[9]<<8) + pMsgContext->reqData[10];
         
           /*verify timing parameters*/
           temp=(uint8)Dcm_PrepareSesTimingValues(Dcm_NewTimingValues);
         
        if (temp == DCM_E_OK)
          pMsgContext->resDataLen = 0x01;
        if ((temp == DCM_E_TI_PREPARE_INCONSISTENT)||(temp == DCM_E_TI_PREPARE_LIMITS))
        {
               Dcm_NewTimingValues=0;
                
               Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
          #if DCM_DEV_ERROR_DETECT==STD_ON
               Dcm_DspReentrancy&=0xFFBF;/*clear*/
          #endif
               return;
        }                    
    }
  
  pMsgContext->resData[0]=pMsgContext->reqData[0];
   Dcm_ProcessingDone(pMsgContext);
#if DCM_DEV_ERROR_DETECT==STD_ON
   Dcm_DspReentrancy&=0xFFBF;/*clear*/
   return;
   }
#endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*
*! Function used for processing the UDS service 0x27
*
* \name Dcm_DcmSecurityAccess
*
* \b Service-Id:   0x39
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x27 (SecurityAccess)
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmSecurityAccess(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{

   uint8  temp;
   uint8  temp2;
   uint8  counter=0xFF;
   /*>><< GAN:2009-09-22 storage class fixed for pointer variable*/
   P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ptrKeyLen; 
   static uint8  reqseedlevel=0;
   /* ----- NXTR PATCH START -----
    * Added By: K. Smith (Nxtr)
    * Date Added: 28Sep16
    *
    * Reason: Size adjust for the signature increase from 132 to 260.
    */
   #if 0
   /* ----- Original Code Start ----- */
   static uint8  reqseclevel=0;
   /* ----- Original Code End ----- */
   #endif
   /* ----- Patch Code Start ----- */
   static uint16  reqseclevel=0;
   /* ----- Patch Code End ----- */
   /* ----- NXTR PATCH END ----- */

  #if DCM_DEV_ERROR_DETECT==STD_ON 
  if ((Dcm_DspReentrancy&0x0080)==0x0000)
  {
    Dcm_DspReentrancy|=0x0080;/*set*/
  #endif
    if (pMsgContext->reqDataLen < 1)
    {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
      #if DCM_DEV_ERROR_DETECT==STD_ON  
      Dcm_DspReentrancy&=0xFF7F;/*clear*/
      #endif
        return;
    }

    /*check the subfunction*/
    if ((pMsgContext->reqData[0] % 2 == 0)&&(Dcm_CalcSeed == 0))
     {
       /* >> GAN:2008-03-12 Fixed sendKey message without corresponding requestSeed
         first check if the corresponding security level is supported*/
       for (temp=0;temp<DCM_NUMBER_OF_SECURITY_LEVELS;temp++)
       {
         if ((pMsgContext->reqData[0] - 1) == Dcm_SecLevel[temp].DCM_SEC_LEVEL)
           counter=temp;
       }
       if (counter==0xFF)
       {
         Dcm_HandleNegResponse(pMsgContext,DCM_E_SUBFUNCTIONNOTSUPPORTED);
       }
       else
       {
         Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTSEQUENCEERROR);
       }
       /* << GAN:2008-03-12 Fixed sendKey message without corresponding requestSeed */
       #if DCM_DEV_ERROR_DETECT==STD_ON
       Dcm_DspReentrancy&=0xFF7F;/*clear*/
       #endif
       return;
     }
     /* >> GAN:2007-11-05 check here if the subfunction is correct to respect the order of NRC */
   if (pMsgContext->reqData[0] % 2 == 1)
     {
       /*find the security level*/
       for (temp=0;temp<DCM_NUMBER_OF_SECURITY_LEVELS;temp++)
       {
         if (pMsgContext->reqData[0] == Dcm_SecLevel[temp].DCM_SEC_LEVEL)
           counter=temp;
       }
       if (counter==0xFF)
       {
         Dcm_HandleNegResponse(pMsgContext,DCM_E_SUBFUNCTIONNOTSUPPORTED);
         #if DCM_DEV_ERROR_DETECT==STD_ON 
         Dcm_DspReentrancy&=0xFF7F;/*clear*/
         #endif
          return;
       }
     }
     /* >> GAN:2007-11-05 check here if the subfunction is correct to respect the order of NRC */


    if (pMsgContext->reqData[0] % 2 == 1)
    {
      /* >> GAN:2007-10-16 New check of the request length (including the additional parameters)*/
      if (((SECURITYACCESSLENGTH + DCM_SECURITYACCESSRECORDLENGTH) != pMsgContext->reqDataLen) )
      {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
        #if DCM_DEV_ERROR_DETECT==STD_ON  
        Dcm_DspReentrancy&=0xFF7F;/*clear*/
        #endif
          return;
      }
      /* << GAN:2007-10-16 New check of the request length (including the additional parameters)*/
    }
    else
    {
      if (!(SECURITYACCESSLENGTH + reqseclevel == pMsgContext->reqDataLen))
      {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
        #if DCM_DEV_ERROR_DETECT==STD_ON  
        Dcm_DspReentrancy&=0xFF7F;/*clear*/
        #endif
          return;
      }
    }

   if (Dcm_Current_Message_Status.Dcm_SecurityAccessIncrement)
     {

        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUIREDTIMEDELAYNOTEXPIRED);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xFF7F;/*clear*/
        #endif
        return;
     }

     /* >> GAN:2007-09-13 BMW specific addition to DCM specs*/
   if (Dcm_Current_Message_Status.Dcm_InitialSecurityAccessIncrement)
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_CONDITIONSNOTCORRECT);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xFF7F;/*clear*/
        #endif
        return;
     }
     /* << GAN:2007-09-13 BMW specific addition to DCM specs*/

    /*get the securityAccessType*/
   temp = pMsgContext->reqData[0];

     if(pMsgContext->reqData[0] % 2 == 1)
     {
         /* check of valid entry */
         temp  = (uint8)((Dcm_SecLevel[counter].DCM_SEC_LEVEL)>>1);
         temp  = (uint8)(Dcm_SecLevel[counter].DCM_SEC_LEVEL - temp);
         temp2 = (uint8)((Dcm_SecLevel[counter].DCM_SEC_LEVEL + 0x01)>>1);
         temp2 = (uint8)((Dcm_SecLevel[counter].DCM_SEC_LEVEL + 0x01) - temp2);
         /* no valid request*/
         if(temp!=temp2)
         {
           Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
           #if DCM_DEV_ERROR_DETECT==STD_ON
           Dcm_DspReentrancy&=0xFF7F;/*clear*/
           #endif
           return;
         }
         /*request to application for seed */
         reqseedlevel = counter;
         reqseclevel  = Dcm_SecLevel[counter].DCM_SEC_NUM_KEY;/*key length must be stored for the next call*/
         /* >> GAN:2008-02-06 Changed processing of the Seed calling mechanism*/
         if (Dcm_SecLevel[counter].DCM_SEC_LEVEL!=Dcm_Current_Message_Status.Dcm_ActiveSecurityLevel)
         {
           /* >> GAN:2007-10-16 additional parameters of the request must be in the buffer before requesting the seed*/
           for(Dcm_CalcSeed=0;Dcm_CalcSeed<DCM_SECURITYACCESSRECORDLENGTH;Dcm_CalcSeed++)
           {
             Dcm_Buffer[Dcm_CalcSeed] = pMsgContext->reqData[1+Dcm_CalcSeed];
           }
           /* >> GAN:2007-10-16 additional parameters of the request must be in the buffer before requesting the seed*/
           Rte_DcmGetSeed(Dcm_SecLevel[counter].DCM_SEC_LEVEL,Dcm_SecLevel[counter].DCM_SEC_NUM_SEED,&Dcm_Buffer[0]);
           for(Dcm_CalcSeed=0;Dcm_CalcSeed< Dcm_SecLevel[counter].DCM_SEC_NUM_SEED;Dcm_CalcSeed++)
           {
             pMsgContext->resData[1+Dcm_CalcSeed] = Dcm_Buffer[Dcm_CalcSeed];
           }
           Dcm_CalcSeed = 0x01;
         }
         else
         {
           for(Dcm_CalcSeed=0;Dcm_CalcSeed< Dcm_SecLevel[counter].DCM_SEC_NUM_SEED;Dcm_CalcSeed++)
           {
             pMsgContext->resData[1+Dcm_CalcSeed] = 0;
           }
           Dcm_CalcSeed = 0x00;
         }
         /* << GAN:2008-02-06 Changed processing of the Seed calling mechanism*/
         /*positive response */
         pMsgContext->resData[0]=pMsgContext->reqData[0];
         pMsgContext->resDataLen = Dcm_SecLevel[counter].DCM_SEC_NUM_SEED + 0x01; /*SID is not present in response                        */
         Dcm_ProcessingDone(pMsgContext);
         #if DCM_DEV_ERROR_DETECT==STD_ON
         Dcm_DspReentrancy&=0xFF7F;/*clear*/
         #endif
         return;
     }  /* end of if(!subfunction is odd number)*/
     else
     {
       /*see if sequence of call is correct*/
        if((temp - Dcm_SecLevel[reqseedlevel].DCM_SEC_LEVEL)== 0x01)
        {
           ptrKeyLen = &pMsgContext->reqData[1];

           if(Rte_DcmCompareKey(Dcm_SecLevel[reqseedlevel].DCM_SEC_LEVEL,Dcm_SecLevel[reqseedlevel].DCM_SEC_NUM_KEY,ptrKeyLen)==DCM_E_OK)
           {
              Dcm_CalcSeed = 0;
              /*reset all attempts for this security level...all the rest should hld their values*/
             Dcm_NumberOfAttempts[reqseedlevel]=0;
              /* set sec. level           */
              Dcm_SetSecurityLevel(Dcm_SecLevel[reqseedlevel].DCM_SEC_LEVEL);
              pMsgContext->resData[0]=pMsgContext->reqData[0];
              pMsgContext->resDataLen=0x01;
              Dcm_ProcessingDone(pMsgContext);
              #if DCM_DEV_ERROR_DETECT==STD_ON
              Dcm_DspReentrancy&=0xFF7F;/*clear*/
              #endif
              return;
           }
           Dcm_CalcSeed = 0;

           /*increase the number of failed accesses */
           Dcm_NumberOfAttempts[reqseedlevel]++;

           if (Dcm_NumberOfAttempts[reqseedlevel] == Dcm_SecLevel[reqseedlevel].DCM_SEC_NUM_MAX_ATT_DELAY)
           {
             Dcm_SecurityTimeOutNr=reqseedlevel;
             Dcm_Current_Message_Status.Dcm_SecurityAccessIncrement=DCM_TASK_TIME;
           }
           if (Dcm_NumberOfAttempts[reqseedlevel] >= Dcm_SecLevel[reqseedlevel].DCM_SEC_NUM_MAX_ATT_LOCK)
           {
             Dcm_Current_Message_Status.Dcm_ActiveSecurityLevel=0x00;
             Dcm_NumberOfAttempts[reqseedlevel]=0;

             Dcm_HandleNegResponse(pMsgContext,DCM_E_EXCEEDNUMBEROFATTEMPTS);
             #if DCM_DEV_ERROR_DETECT==STD_ON
             Dcm_DspReentrancy&=0xFF7F;/*clear*/
             #endif
             return;
           }

           Dcm_HandleNegResponse(pMsgContext,DCM_E_INVALIDKEY);
           #if DCM_DEV_ERROR_DETECT==STD_ON
           Dcm_DspReentrancy&=0xFF7F;/*clear*/
           #endif
           return;
        }

        Dcm_CalcSeed = 0;

        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTSEQUENCEERROR);
     #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xFF7F;/*clear*/
     #endif   
        return;
     } /* end of else*/
#if DCM_DEV_ERROR_DETECT==STD_ON     
  }
#endif  
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/*
*! Function used for processing the UDS service 0x10
*
* \name Dcm_DcmDiagnosticSessionControl
*
* \b Service-Id:   0x40
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x10 (DiagnosticSecurityAccess)
*/
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmDiagnosticSessionControl(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint8 SessionMode;
   uint8 Counter;
   uint8 Result;
   uint8 i;

  #if DCM_DEV_ERROR_DETECT==STD_ON 
  if ((Dcm_DspReentrancy&0x0100)==0x0000)
  {
    Dcm_DspReentrancy|=0x0100;/*set */
  #endif  
    /* >><< GAN:2008-08-12 Fixed length check for diagnostic session control*/
    if(!( DIAGNOSTICSESSIONCONTROLLENGTH == (pMsgContext->reqDataLen) ))
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xFEFF;/*clear*/
        #endif
        return;
     }

    SessionMode  = pMsgContext->reqData[0]; /*suppression bit already cleared and SID byte removed from the pMsgContext    */

    Counter=0xFF;
    for (i=0;i<DCM_NUMBER_OF_SESSION_LEVELS;i++)
    {
      if ((Dcm_SessionLevel[i].DCM_SESSION_LEVEL==SessionMode)&&(Dcm_SessionLevel[i].DCM_SESSION_LEVEL!=0))
      {
        Counter=i;
      }
    }

    if (Counter==0xFF)
    {
       Dcm_HandleNegResponse(pMsgContext,DCM_E_SUBFUNCTIONNOTSUPPORTED);
       #if DCM_DEV_ERROR_DETECT==STD_ON
       Dcm_DspReentrancy&=0xFEFF;/*clear*/
       #endif
       return;
     }

  /*see if the session is valid*/
  if( (Dcm_SessionLevel[Counter].DCM_SESSION_LEVEL== SessionMode) && (Dcm_SessionLevel[Counter].DCM_SESSION_LEVEL!=0))
        {
        /*get permission to change
          >> GAN:2008-02-04 Changed processing of the return type from the Permission function*/
        Result = (uint8)Rte_DcmGetSesChgPermission(Dcm_Current_Message_Status.Dcm_ActiveSession,SessionMode);
           if((Result == (uint8)DCM_E_OK)||(Result == (uint8)DCM_E_WAIT_PROCESSING_DONE))
           {
           /* << GAN:2008-02-04 Changed processing of the return type from the Permission function
             the actual change of the session shall be done when confirmation is received*/
              pMsgContext->resData[0]=pMsgContext->reqData[0];
              /*>> GAN:2007-10-18 Also place timing values in the message (max P2 and max P2* /10)*/
              pMsgContext->resData[1]=(uint8)(Dcm_SessionLevel[Counter].DCM_SESSION_P2SERVER_MAX >> 8);
              pMsgContext->resData[2]=(uint8)(Dcm_SessionLevel[Counter].DCM_SESSION_P2SERVER_MAX);
              pMsgContext->resData[3]=(uint8)((Dcm_SessionLevel[Counter].DCM_SESSION_P2STRSERVER_MAX / 10) >> 8);
              pMsgContext->resData[4]=(uint8)((Dcm_SessionLevel[Counter].DCM_SESSION_P2STRSERVER_MAX / 10));
              /* << GAN:2007-10-18 Also place timing values in the message (max P2 and max P2 * /10)*/
              pMsgContext->resDataLen=0x05;
              Dcm_ProcessingDone(pMsgContext);
              #if DCM_DEV_ERROR_DETECT==STD_ON
              Dcm_DspReentrancy&=0xFEFF;/*clear*/
              #endif
              return;
           }
           else
           {
             Dcm_HandleNegResponse(pMsgContext,DCM_E_CONDITIONSNOTCORRECT);
             #if DCM_DEV_ERROR_DETECT==STD_ON
             Dcm_DspReentrancy&=0xFEFF;/*clear*/
             #endif
              return;
          }
        }

  #if DCM_DEV_ERROR_DETECT==STD_ON      
   Dcm_DspReentrancy&=0xFEFF;/*clear*/
  }
  #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used for processing the UDS service 0x3E
*
* \name Dcm_DcmTesterPresent
*
* \b Service-Id:   0x41
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x3E (TesterPresent)
*/

#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmTesterPresent(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  #if DCM_DEV_ERROR_DETECT==STD_ON
  if ((Dcm_DspReentrancy&0x0200)==0x0000)
  {
  #endif   
    if (pMsgContext->reqDataLen < 1)
    {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
      #if DCM_DEV_ERROR_DETECT==STD_ON  
      Dcm_DspReentrancy&=0xFDFF;/*clear*/
      #endif
        return;
    }

    if (pMsgContext->reqData[0] != 0)
    {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_SUBFUNCTIONNOTSUPPORTED);
      #if DCM_DEV_ERROR_DETECT==STD_ON
      Dcm_DspReentrancy&=0xFDFF;/*clear*/
      #endif
       return;
    }

   if(!( TESTERPRESENTLENGTH == pMsgContext->reqDataLen))
     {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
      #if DCM_DEV_ERROR_DETECT==STD_ON  
      Dcm_DspReentrancy&=0xFDFF;/*clear*/
      #endif
        return;
     }

    /*at this moment only the value 0x00 can be found in pMsgcontext->ReqData[1]
      suppression bit should have been cleared*/
    if (pMsgContext->reqData[0] == 0x00)
    {
      pMsgContext->resData[0]=0x00;
      pMsgContext->resDataLen=0x01;
      Dcm_ProcessingDone(pMsgContext);
      #if DCM_DEV_ERROR_DETECT==STD_ON
      Dcm_DspReentrancy&=0xFDFF;/*clear*/
      #endif
      return;
    }
#if DCM_DEV_ERROR_DETECT==STD_ON    
  }
#endif  
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*
*! Function used for processing the UDS service 0x85
*
* \name Dcm_DcmControlDTCSetting
*
* \b Service-Id:   0x42
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x85 (ControlDTCSetting)
*/
#if DCM_USE_DEM==STD_ON
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmControlDTCSetting(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint8 temp;
   /* >> GAN:2008-02-04 Changed initial value for variable DTCGroup*/
   Dem_DTCGroupType DTCGroup=(Dem_DTCGroupType)DEM_DTC_GROUP_ALL_DTCS;
   /* << GAN:2008-02-04 Changed initial value for variable DTCGroup*/

  #if DCM_DEV_ERROR_DETECT==STD_ON
  if ((Dcm_DspReentrancy&0x0400)==0x0000)
  {
    Dcm_DspReentrancy|=0x0400;/*set      */
  #endif  
    if (pMsgContext->reqDataLen < 1)
    {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
      #if DCM_DEV_ERROR_DETECT==STD_ON
       Dcm_DspReentrancy&=0xFBFF;/*clear*/
      #endif
        return;
    }

    temp = (uint8)pMsgContext->reqData[0];

    if ((temp != 0x01) &&( temp != 0x02))
    {
      /*if reaches this point, subfunction is not correct*/
       Dcm_HandleNegResponse(pMsgContext,DCM_E_SUBFUNCTIONNOTSUPPORTED);
       #if DCM_DEV_ERROR_DETECT==STD_ON
       Dcm_DspReentrancy&=0xFBFF;/*clear*/
       #endif
       return;
    }

   if(CONTROLDTCSETTINGLENGTH != pMsgContext->reqDataLen)
     {
       Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
       #if DCM_DEV_ERROR_DETECT==STD_ON
       Dcm_DspReentrancy&=0xFBFF;/*clear*/
       #endif
        return;
     }

    /*if sub-function is 0x01 then enable the DTC storage*/
    if (temp==0x01)
    {
        temp=Dem_EnableDTCStorage(DTCGroup,DEM_DTC_KIND_ALL_DTCS);
    }
    /*if sub-function is 0x02 then disable the DTC storage*/
    else
    {
        temp=Dem_DisableDTCStorage(DTCGroup,DEM_DTC_KIND_ALL_DTCS);
    }
    if (temp==DEM_CONTROL_DTC_STORAGE_OK)
    {
        pMsgContext->resData[0]=pMsgContext->reqData[0];
        pMsgContext->resDataLen=0x01;
        Dcm_ProcessingDone(pMsgContext);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xFBFF;/*clear*/
        #endif
        return;
    }
    else
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_CONDITIONSNOTCORRECT);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xFBFF;/*clear*/
        #endif
        return;
    }
#if DCM_DEV_ERROR_DETECT==STD_ON    
  }
#endif  
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
*! Function used for processing the UDS service 0x14
*
* \name Dcm_DcmClearDiagnosticInformation
*
* \b Service-Id:   0x43
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process diagnostic service 0x14 (ClearDiagnosticInformation)
*/
#if DCM_USE_DEM==STD_ON
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmClearDiagnosticInformation(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint32 ClearedDTC;
   uint8 temp;

   #if DCM_DEV_ERROR_DETECT==STD_ON
   if ((Dcm_DspReentrancy&0x0800)==0x0000)
   {
     Dcm_DspReentrancy|=0x0800;/*set   */
   #endif  
     if(!( CLEARDIAGNOSTICINFORMATIONLENGTH ==( pMsgContext->reqDataLen)))
     {

        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
       #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xF7FF;/*clear*/
       #endif 
        return;
     }

     ClearedDTC=Dcm_Read3BytesFromU8Array(&pMsgContext->reqData[0]);

    /*this could be a DTC or a group of DTCs......take action according to this
      in both cases, use Dem_ClearDTC to clear the information*/

    temp=(uint8) Dem_ClearDTC(ClearedDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY );

     switch (temp)
     {
        case DEM_CLEAR_OK:
        {
          pMsgContext->resDataLen=0;
         Dcm_ProcessingDone(pMsgContext);
        }
        break;
        default:
          Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
        break;
     }
#if DCM_DEV_ERROR_DETECT==STD_ON     
    Dcm_DspReentrancy&=0xF7FF;/*clear*/
   }
#endif   
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
*! Function used for obtaining the failed DTCs based on the time of the occurrence
*
* \name Dcm_DcmReportFailedDTC
*
* \b Service-Id:   0x44
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   Dem_DTCRequestType requestDTC - this is the DTC type requested (e.g. first failed)
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall insert in the response message the DTC based on the DTCrequest parameter
*/
#if DCM_USE_DEM==STD_ON
#define DCM_START_SEC_CODE
#include "MemMap.h"
#if ((DCM_READDTC_SUBFUNCTION0B_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0C_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0D_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0E_ENABLED==STD_ON))
FUNC(void,DCM_CODE) Dcm_ReportFailedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,Dem_DTCRequestType requestDTC)
{

   uint8   temp;
   uint8   StatusMask;
   uint32  RecDTC;
   Dem_DTCStatusMaskType DTCStatusMask;

  pMsgContext->resData[0]=pMsgContext->reqData[0];

  /*get the DTC by time of the occurence*/
   temp = (uint8)Dem_GetDTCByOccurrenceTime(requestDTC,DEM_DTC_KIND_ALL_DTCS, &RecDTC);

   if(temp == (uint8)DEM_OCCURR_OK)
   {
     /*if reporting was successful fill the bytes in the response*/
     if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
     {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
         return;
     }
      pMsgContext->resData[1]  = (uint8)DTCStatusMask;
      Dcm_Write3BytesInU8Array(RecDTC, &pMsgContext->resData[2]);
      /*get the status of the DTC*/
      if(Dem_GetStatusOfDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,&StatusMask)  != DEM_STATUS_OK)
      {
         Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
         return;
      }
      pMsgContext->resData[5]  = StatusMask;
      pMsgContext->resDataLen=0x06;
   }
   else
   {
     /*if error occured while reporting*/
     if(temp == (uint8)DEM_OCCURR_FAILED)
     {
       if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
       {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
           return;
       }
         pMsgContext->resData[1]  = (uint8)DTCStatusMask;
        pMsgContext->resDataLen = 0x03;
     }
     else
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
        return;
     }
   }
   Dcm_ProcessingDone(pMsgContext);
}
#endif
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
*! Function used for processing UDS service 0x19
*
* \name Dcm_DcmReadDTCInformation
*
* \b Service-Id:   0x45
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmReadDTCInformation(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint8 Subfunction;
   uint8 i=0;
   uint8 security_mask=0;

   #if DCM_DEV_ERROR_DETECT==STD_ON
   if ((Dcm_DspReentrancy&0x1000)==0x0000)
   {
     Dcm_DspReentrancy|=0x1000;
   #endif  

     Subfunction  =  pMsgContext->reqData[0];

    if (pMsgContext->reqDataLen < 1)
    {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
      #if DCM_DEV_ERROR_DETECT==STD_ON 
      Dcm_DspReentrancy&=0xEFFF;/*clear*/
      #endif
        return;
    }

    /*sub-function is supported
      >> GAN:2007-09-12 removed 0x15 because it is not supported by DEM/DCM*/
   if((Subfunction<0x01)||(Subfunction >0x14))
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_SUBFUNCTIONNOTSUPPORTED);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xEFFF;/*clear*/
        #endif
        return;
     }
     /* << GAN:2007-09-12 removed 0x15 because it is not supported by DEM/DCM*/
    /* >> GAN:2008-03-12 first check if sub-function is supported or not*/
    if (Dcm_SubFunctions0x19[Subfunction-1].DCM_DTC_INFO_SUB_FUNCTION_SUPPORT==STD_OFF)
    {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_SUBFUNCTIONNOTSUPPORTED);
      #if DCM_DEV_ERROR_DETECT==STD_ON 
      Dcm_DspReentrancy&=0xEFFF;/*clear*/
      #endif
       return;
    }
    /* << GAN:2008-03-12 first check if sub-function is supported or not*/


    /*check length a different way - using the defines in the Dcm_BmwData.h
      >> GAN:2007-09-12 changed service length check */

    /*check length*/
    if(DtcInfoSubFunctionLengths[Subfunction-1] != pMsgContext->reqDataLen) 
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xEFFF;/*clear*/
        #endif
        return;
    }
    /* << GAN:2007-09-12 changed service length check*/

    security_mask=Dcm_GetSecurityMask();

    /*check if security level allows processing*/
     if(!(Dcm_SubFunctions0x19[Subfunction-1].DCM_SEC_LEVEL & security_mask ))
     {

        Dcm_HandleNegResponse(pMsgContext,DCM_E_SECURITYACCESSDENIED);
        #if DCM_DEV_ERROR_DETECT==STD_ON
        Dcm_DspReentrancy&=0xEFFF;/*clear*/
        #endif
        return;
     }

    /*dispatch the sub-function*/
      Dcm_ptrReadDTCInformation[Subfunction-1](pMsgContext);
#if DCM_DEV_ERROR_DETECT==STD_ON
      Dcm_DspReentrancy&=0xEFFF;/*clear*/
      
      return;
   }
#endif   
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x01
*
* \name Dcm_ReportNumberOfDTCByStatusMask
*
* \b Service-Id:   0x46
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x01 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION01_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportNumberOfDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint16 temp;
   Dem_DTCStatusMaskType DTCStatusMask;

   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   
   /*filter the DTC*/
   if( Dem_SetDTCFilter(pMsgContext->reqData[1],DEM_DTC_KIND_ALL_DTCS,\
                        DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
                        DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

   if (Dem_GetNumberOfFilteredDTC(&temp)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   /*no SID in response*/
   pMsgContext->resData[0] = pMsgContext->reqData[0]; /*sub-function*/
   pMsgContext->resData[1] = (uint8)DTCStatusMask;/*status of DTC*/
   pMsgContext->resData[2] = (uint8)DEM_DTC_TRANSLATION_ISO14229_1;/*DTC format ISO14229*/
   pMsgContext->resData[3] = (uint8)(temp>>8);/*DTC count HighByte*/
   pMsgContext->resData[4] = (uint8)temp;     /*DTC count LowByte*/
   pMsgContext->resDataLen=0x05; /*Response Length*/
   Dcm_ProcessingDone(pMsgContext);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x02
*
* \name Dcm_ReportDTCByStatusMask
*
* \b Service-Id:   0x47
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x02 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION02_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   
   Dem_DTCStatusMaskType DTCStatusMask;
   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   /*filter the DTC*/
   /* >> GAN:2008-03-13 Check is the StatusMask is different from 0x00*/
   if (pMsgContext->reqData[1] != 0)
   {
      if( Dem_SetDTCFilter(pMsgContext->reqData[1],\
                           DEM_DTC_KIND_ALL_DTCS,\
                           DEM_DTC_ORIGIN_PRIMARY_MEMORY,\
                           DEM_FILTER_WITH_SEVERITY_NO,\
                           DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
      {

         Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
         return;
      }
   }

  /*function used to report all filtered DTCs*/
   Dcm_ReportFilteredDTC(pMsgContext,DTCStatusMask);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x03
*
* \name Dcm_ReportDTCSnapshotIdentification
*
* \b Service-Id:   0x48
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x03 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION03_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportDTCSnapshotIdentification(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint32 FreezeFrameDTC;
   uint16  MessageLength;
   uint8 EventCounter;
   uint8 MaxEventNumber;
   uint8 temp;
   uint8 SubFunction;
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   uint8 i;
   uint16 records;
   #endif

   SubFunction=pMsgContext->reqData[0];

  /*disable DTC record update*/
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
  if (!Dcm_PagedBufferService)
  {
  #endif
     if (Dem_DisableDTCRecordUpdate() != E_OK)
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
        return;
     }
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
  }
  #endif

  /*here calculate the length*/
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
  if (!Dcm_PagedBufferService)
    {
      Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=1;/*subfunction */
       /*calculate length somehow*/
       if (Dem_SetDTCFilterForRecords(&records)==DEM_FILTER_ACCEPTED)
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=records*4;/*each DTC has 3 bytes plus the status*/
       }
       /*here verify if the length if PagedBuffer is required      */
       Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
       if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;/*service Id is counted but will be added later       */
         Dcm_PagedBufferService=Dcm_ReportDTCSnapshotIdentification;
         pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length       */
         for (i=0;i<pMsgContext->reqDataLen;i++)
           Dcm_RequestData[i]=pMsgContext->reqData[i];
         Dcm_LengthSoFar=0;
         Dcm_StartPagedProcessing(pMsgContext);
         return; /*end here the processing       */
       }
       else
       {
         Dcm_LengthSoFar=0;
         Dcm_PagedBufferService=0;
       }
    }
  #endif

    MessageLength=0;

#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (Dcm_PagedBufferService)
    {
        MessageLength++;
    }
    if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(SubFunction)))
        return;
#else
    pMsgContext->resData[MessageLength++]=(uint8)(SubFunction);
#endif

   EventCounter  = 0;
   MaxEventNumber = 0xFF;
   while (EventCounter < MaxEventNumber)
   {
     /*report all DTC of FreezeFrame*/
      temp = (uint8)Dem_GetDTCOfFreezeFrameRecord(EventCounter,DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_DTC_KIND_ALL_DTCS,\
              &FreezeFrameDTC);
      if (temp == (uint8)DEM_GET_DTCOFFF_OK)
      {
        /*fill the bytes in the response
          fill the response with the DTC and DTCStatus*/
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FreezeFrameDTC >> 16)))
            return;
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FreezeFrameDTC >> 8)))
            return;
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FreezeFrameDTC)))
            return;
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(EventCounter)))
            return;
#else
        if (Dcm_pMsgContext2->resMaxDataLen < MessageLength+3)
        {
            Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_RESPONSE_TOO_LONG);
            return;
        }
        Dcm_Write3BytesInU8Array(FreezeFrameDTC, &pMsgContext->resData[MessageLength]);
        MessageLength+=3;
        pMsgContext->resData[MessageLength++]=EventCounter;
#endif
         
      }
      else
      {
        /*if an error message is received*/
        if (temp!=(uint8)DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD)
        {
          Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
          return;
        }
      }
      EventCounter++;
   }

  /*enable the DTC record update*/
   if(Dem_EnableDTCRecordUpdate() != E_OK)
   {
     Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
     return;
   }

   #if DCM_PAGEDBUFFER_ENABLED==STD_ON
   if (!Dcm_PagedBufferService)
   {
   #endif
     pMsgContext->resDataLen=MessageLength;
    Dcm_ProcessingDone(pMsgContext);
  #if DCM_PAGEDBUFFER_ENABLED==STD_ON
   }
   else
   {
     Dcm_PagedBufferService=0; /*end PagedBuffer processing*/
   }
   #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x04
*
* \name Dcm_ReportDTCSnapshotByDTCNumber
*
* \b Service-Id:   0x49
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x04 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION04_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportDTCSnapshotByDTCNumber(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint32 RecDTC;
   uint32 temp;
   uint8  RecordNr;
   uint8  AllSnapshotRec;
   uint8 DTCStatusMask;
   uint16 MSGLength;
   uint8  SubFunction;
   uint8 ret;
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
     uint16 Size;
     uint8 i;
     uint8 RecordNrTemp;
   #endif

   RecDTC=Dcm_Read3BytesFromU8Array(&pMsgContext->reqData[1]);
   /* Snapshot record Nr*/
   RecordNr = pMsgContext->reqData[4];
   /*subfunction*/
   SubFunction = pMsgContext->reqData[0];

   /*Get status mask for DTC*/
   temp = (uint8)Dem_GetStatusOfDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,&DTCStatusMask);
   if (temp != (uint8)DEM_STATUS_OK)
   {
     /*errors...status of DTC was not obtained     */
     Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
     return;
   }

   /*disable DTC record update*/
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {
   #endif
     if( Dem_DisableDTCRecordUpdate() != E_OK)
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
        return;
     }
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   #endif

   /*here calculate the length of the message*/
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
     if (!Dcm_PagedBufferService)
     {
       Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=5;/*sub function, DTC and status mask       */
       /*length calculation is difficult here
         Dem_GetSizeOfFreezeFrameData will return the size of the entire freeze frame data????*/
       RecordNrTemp=RecordNr;
       if (RecordNrTemp!=0xFF)
       {
         /*only one record                */
         ret=(uint8)Dem_GetSizeOfFreezeFrame(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,RecordNrTemp,&Size);
         if (ret == (uint8)DEM_GET_SIZEOFFREEZEFRAMETYPE_OK)
         {
           Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=Size;
           if (Size!=0)
             Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=2;/*if there is a length, it means the record number will be placed in message along with RecNr and number of ids*/
         }
        else
        {
          /*in case of error, send an error message*/
          Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=2;
        }
       }
       else
       {
         /*calculate size for all record numbers
           >> GAN:2008-02-25 recordNr starts from 1*/
         RecordNrTemp=1;
         /* << GAN:2008-02-25 recordNr starts from 1*/
         ret=0;
         Size=1;

         while ((Size) && (!ret))
         {
           ret=(uint8)Dem_GetSizeOfFreezeFrame(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,RecordNrTemp,&Size);
           if (ret == (uint8)DEM_GET_SIZEOFFREEZEFRAMETYPE_OK)
           {
             Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=Size;
             if (Size!=0)
               Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=2;/*if there is a length, it means the record number will be placed in message along with RecNr and number of ids*/
           }
           RecordNrTemp++;
         }
       }
       /*here size should be calculated already */
       Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
       if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;
         Dcm_PagedBufferService=Dcm_ReportDTCSnapshotByDTCNumber;
         pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length       */
         for (i=0;i<pMsgContext->reqDataLen;i++)
           Dcm_RequestData[i]=pMsgContext->reqData[i];
         Dcm_LengthSoFar=0;
         Dcm_StartPagedProcessing(pMsgContext);
         return; /*end here the processing       */
       }
       else
       {
         Dcm_LengthSoFar=0;
         Dcm_PagedBufferService=0;
       }
     }
   #endif

   /*fill in the response some parts of the request    */
   MSGLength =0;

#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (Dcm_PagedBufferService)
    {
        MSGLength++;/*this is because te service ID has to be added in the */
    }

    if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,SubFunction))
        return;
    if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,pMsgContext->reqData[1]))
        return;
    if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,pMsgContext->reqData[2]))
        return;
    if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,pMsgContext->reqData[3]))
        return;
    /*insert status mask in response */
    if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,DTCStatusMask))
        return;
#else
    if (Dcm_pMsgContext2->resMaxDataLen < MSGLength+4)
    {
        Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_RESPONSE_TOO_LONG);
        return;
    }
    pMsgContext->resData[MSGLength++]=SubFunction;
    pMsgContext->resData[MSGLength++]=pMsgContext->reqData[1];
    pMsgContext->resData[MSGLength++]=pMsgContext->reqData[2];
    pMsgContext->resData[MSGLength++]=pMsgContext->reqData[3];
    pMsgContext->resData[MSGLength++]=DTCStatusMask;
#endif
     
   if(RecordNr == 0xFF)
   {
     /*all records to be reported*/
      AllSnapshotRec = 0;
      /* >> GAN:2008-02-25 RecordNr starts from 1*/
      RecordNr =0x01;
      /* << GAN:2008-02-25 RecordNr starts from 1*/
   }
   else
   {
     /*only one record to be reported*/
      AllSnapshotRec = 1;
   }

   ret=(uint8) DEM_GET_FFDATABYDTC_OK;

  /*loop for all records*/
   while (!ret)
   {
    Dcm_BufferLength=255; /*this is the size that can be filled in the Dcm_Buffer*/
    /*get freezeframe data*/
      ret = (uint8)Dem_GetFreezeFrameDataByDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,RecordNr,0xFFFF, \
        &Dcm_Buffer[0],&Dcm_BufferLength);
    if (ret == (uint8)DEM_GET_FFDATABYDTC_OK)
    {
         /* copy bytes in the response buffer
         >> GAN:2008-05-30 check if the record number reported any freezeframe*/
      if (Dcm_BufferLength>2)
      {
        if (Dcm_Buffer[1]>0)
        {
      /* >> GAN:2008-05-30 check if the record number reported any freezeframe*/
             for(temp=0;temp < Dcm_BufferLength;temp++)
             {
               if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,Dcm_Buffer[temp]))
               return;
             }
        }
      }
    }
    else
    {
      /*enable the DTC record update and send negative response  */
      if (AllSnapshotRec)
      {
        ret=Dem_EnableDTCRecordUpdate();
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
          return;
      }
    }

      if (AllSnapshotRec)/*force exit from while in case only one record is needed*/
        ret=1;
      RecordNr++;
   } /*end of while( AllSnapshotRec...)*/


   if(Dem_EnableDTCRecordUpdate() != E_OK)
   {

      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {
   #endif
     pMsgContext->resDataLen=MSGLength;
    Dcm_ProcessingDone(pMsgContext);
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   else
   {
     Dcm_PagedBufferService=0; /*end PagedBuffer processing*/
   }
   #endif

   return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x05
*
* \name Dcm_ReportDTCSnapshotRecordByRecordNumber
*
* \b Service-Id:   0x50
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x05 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION05_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportDTCSnapshotRecordByRecordNumber(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint32 RecDTC;
   uint8 temp;
   uint8 RecordNr;
   uint16 MSGLength;
   uint8 AllSnapshotRec;
   uint8 DTCStatus;
  uint8 ret;
  uint8 ret2;
  uint8 ret3;
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)

   uint8 i;
   uint16 Size;
   uint8 RecordNrTemp;
   #endif
   uint8 SubFunction;      
   
   RecordNr = pMsgContext->reqData[1];      
   SubFunction = pMsgContext->reqData[0];
   
   /*disable the updating of the records*/
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {        
   #endif
     if( Dem_DisableDTCRecordUpdate() != E_OK)
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
        return;
     }
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   #endif
 
   #if DCM_PAGEDBUFFER_ENABLED==STD_ON
     if (!Dcm_PagedBufferService)
     {
       Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=1;/*subfunction*/
       RecordNrTemp=RecordNr;
       if(RecordNrTemp == 0xFF)
       {
         /*all snapshot shall be reported*/
          AllSnapshotRec = 0;
          /* >> GAN:2008-02-25 RecordNr starts from 1*/
          RecordNrTemp =0x01; 
          /* << GAN:2008-02-25 RecordNr starts from 1*/
       }
       else
       {
         /*only one snapshot to be reported*/
          AllSnapshotRec = 1;
       }
       temp=0;
       ret=0;
       while ((!temp) && (!ret))
       {
         temp =  (uint8)Dem_GetDTCOfFreezeFrameRecord(RecordNrTemp, DEM_DTC_ORIGIN_PRIMARY_MEMORY,\
          DEM_DTC_KIND_ALL_DTCS, &RecDTC );
          if(temp == (uint8)DEM_GET_DTCOFFF_OK)
          {                      
            /*here call the size function for the */
            ret=(uint8)Dem_GetSizeOfFreezeFrame(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,RecordNrTemp,&Size);
           Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=Size;
           if (Size!=0)
             Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=6;/*recordNr, DTC, DTCStatus, number of identifiers */
          }
        else
        {
          if (AllSnapshotRec)
            Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=2;
        }
         if (AllSnapshotRec)
           temp=1; /*force the end of the while because only on RecordNr is requested*/
         RecordNrTemp++;
       }
       Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
       if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)  
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;              
         Dcm_PagedBufferService=Dcm_ReportDTCSnapshotRecordByRecordNumber;              
         pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length         */
         for (i=0;i<pMsgContext->reqDataLen;i++)
           Dcm_RequestData[i]=pMsgContext->reqData[i];
         Dcm_LengthSoFar=0;
         Dcm_StartPagedProcessing(pMsgContext);       
         return; /*end here the processing       */
       }
       else
       {
         Dcm_LengthSoFar=0;
         Dcm_PagedBufferService=0;         
       }     
     }
   #endif
  
  MSGLength=0;

#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (Dcm_PagedBufferService)
    {
        MSGLength++;
    }
    if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,SubFunction))
      return;
#else
    pMsgContext->resData[MSGLength++]=SubFunction;
#endif
  
  if(RecordNr == 0xFF)
   {
     /*all snapshot shall be reported*/
      AllSnapshotRec = 0;
      /* >> GAN:2008-02-25 RecordNr starts from 1*/
      RecordNr =0x01; 
      /* << GAN:2008-02-25 RecordNr starts from 1*/
   }
   else
   {
     /*only one snapshot to be reported*/
      AllSnapshotRec = 1;
   }
    
  ret=0;
  ret2=0;
  ret3=0;
   /*loop for all snapshot records*/
   while((!ret) && (!ret2) && (!ret3))
   {   
           
      /*get the freeze frame record*/
      ret =  (uint8)Dem_GetDTCOfFreezeFrameRecord(RecordNr, DEM_DTC_ORIGIN_PRIMARY_MEMORY,\
      DEM_DTC_KIND_ALL_DTCS, &RecDTC );
      if ((ret != (uint8)DEM_GET_FFDATABYDTC_OK)&&(ret != (uint8)DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD))
      {
      if (AllSnapshotRec)
      {
          temp=(uint8)Dem_EnableDTCRecordUpdate();

           Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
           return;
      }
      }
      /*>><<GAN:2009-09-10 Only if there is a DTC available for this recordNo, only then move forward*/
      else 
      {              
      if (ret != (uint8)DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD) 
      {             
    /*get the status for the DTC*/
        ret2 = (uint8)Dem_GetStatusOfDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,&DTCStatus);
      
         /*get freezeframe data*/
         ret3 = (uint8)Dem_GetFreezeFrameDataByDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,
         RecordNr, 0xFFFF,&Dcm_Buffer[0],&Dcm_BufferLength) ;
      /*>><<GAN:2009-09-11 optimized this bit of code (merged the negative response sending*/
         if ((ret3 != (uint8)DEM_GET_FFDATABYDTC_OK) || (ret2 != (uint8)DEM_STATUS_OK))
         {
        if (AllSnapshotRec)
        { 
             temp=(uint8)Dem_EnableDTCRecordUpdate();
            
              Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
              return;
           }
        }
      }
      /*>>GAN:2009-09-11 Add the record number in this case*/
      else
      {
      if (AllSnapshotRec)
          if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,RecordNr))
          return;
      }
      /*<<GAN:2009-09-11 Add the record number in this case*/
      }
           
      if ((!ret) && (!ret2) &&(!ret3)) 
    {
      if (Dcm_BufferLength > 2)
      {
        if (Dcm_Buffer[1] > 0)
        {
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
            if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,RecordNr))
             return; 
            /* copy DTC in response buffer*/
            if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,(uint8)(RecDTC >> 16)))
             return; 
            if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,(uint8)(RecDTC >> 8)))
             return; 
            if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,(uint8)(RecDTC )))
             return;
            if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,DTCStatus))
             return;
#else
            if (Dcm_pMsgContext2->resMaxDataLen < MSGLength+4)
            {
                Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_RESPONSE_TOO_LONG);
                return;
            }
            pMsgContext->resData[MSGLength++]=RecordNr;
            /* copy DTC in response buffer*/
            Dcm_Write3BytesInU8Array(RecDTC, &pMsgContext->resData[MSGLength]);
            MSGLength+=3;
            pMsgContext->resData[MSGLength++]=DTCStatus;
#endif
             
            /* copy bytes in the response
               copy only from the second byte as the first one contains the record nr which is already added*/
            for(temp=1;temp < Dcm_BufferLength;temp++)
            { 
              if (1==Dcm_VerifyPagedBuffer(MSGLength++,pMsgContext->resData,Dcm_Buffer[temp]))
               return;               
            }
        }
      }
      }
   
      if (AllSnapshotRec) 
        ret=1; /*force exit from while in case only one record number is requested*/
      RecordNr++;            
   }/* end of while(AllSnapshotRec...)*/
   
   if(Dem_EnableDTCRecordUpdate() != E_OK)
   {
     Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
     return;
   }
   
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {
   #endif
     pMsgContext->resDataLen=MSGLength;
    Dcm_ProcessingDone(pMsgContext);   
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   else
   {
     Dcm_PagedBufferService=0; /*end PagedBuffer processing*/
   }
   #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x06
*
* \name Dcm_ReportDTCExtendedDataRecordByDTCNumber
*
* \b Service-Id:   0x51
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x06 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION06_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportDTCExtendedDataRecordByDTCNumber(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*function used to report extended data*/
   Dcm_ReportDTCExtendedData(pMsgContext);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x07
*
* \name Dcm_ReportNumberOfDTCBySeverityMaskRecord
*
* \b Service-Id:   0x52
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x07 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION07_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportNumberOfDTCBySeverityMaskRecord(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   /*SID=0x19
    sub-func=0x07*/
   uint16 temp;
   Dem_DTCStatusMaskType DTCStatusMask;   
   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   /*filter DTCs*/
   if( Dem_SetDTCFilter(pMsgContext->reqData[2],DEM_DTC_KIND_ALL_DTCS,\
         DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_YES,\
         (Dem_DTCSeverityType)pMsgContext->reqData[1], DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

   if (Dem_GetNumberOfFilteredDTC(&temp)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   /*assemble response*/
   pMsgContext->resData[0] = pMsgContext->reqData[0];/*sub-function 0x07*/

   pMsgContext->resData[1] = (uint8)DTCStatusMask;
   pMsgContext->resData[2] = (uint8)DEM_DTC_TRANSLATION_ISO14229_1;
   pMsgContext->resData[3] = (uint8)(temp>>8);
   pMsgContext->resData[4] = (uint8)temp;
   pMsgContext->resDataLen=0x05; /*Message Length*/
   Dcm_ProcessingDone(pMsgContext);
   return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x08
*
* \name Dcm_ReportDTCBySeverityMaskRecord
*
* \b Service-Id:   0x53
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x08 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION08_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportDTCBySeverityMaskRecord(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint16 temp;
   uint32 FilteredDTC;
   uint8  FilteredDTCStatus;
   uint16  MessageLength;
   uint8  DTCSeverity;
   Dem_ViewIdType viewId;
   Dem_DTCStatusMaskType DTCStatusMask;
   uint8 SubFunction;
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
     uint16 Size;
     uint8 ret;
     uint8 i;
   #endif

  SubFunction=pMsgContext->reqData[0];

   /*Save severity mask*/
   DTCSeverity=pMsgContext->reqData[1];

   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
     Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
     return;
   }
   
  /*filter the DTCs*/
   if( Dem_SetDTCFilter(pMsgContext->reqData[2],DEM_DTC_KIND_ALL_DTCS,\
       DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_YES,\
      (Dem_DTCSeverityType)pMsgContext->reqData[1], DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
   {

      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }


   /*calculate total length*/
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
     if (!Dcm_PagedBufferService)
     {
       Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=2; /*subfunction*/
       ret=Dem_GetNumberOfFilteredDTC(&Size);
       if (ret == E_OK)
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=6*Size;
       /*here decide if pagedbuffer is needed*/
       Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
       if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;
         Dcm_PagedBufferService=Dcm_ReportDTCBySeverityMaskRecord;
         pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length       */
         for (i=0;i<pMsgContext->reqDataLen;i++)
           Dcm_RequestData[i]=pMsgContext->reqData[i];
         Dcm_LengthSoFar=0;
         Dcm_StartPagedProcessing(pMsgContext);
         return; /*end here the processing       */
       }
       else
       {
         Dcm_LengthSoFar=0;
         Dcm_PagedBufferService=0;
       }
     }
   #endif

    MessageLength=0;
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (Dcm_PagedBufferService)
    {
        MessageLength++;
    }
    if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, SubFunction))
      return;
    if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)DTCStatusMask))
      return;
#else
    pMsgContext->resData[MessageLength++]=SubFunction;
    pMsgContext->resData[MessageLength++]=(uint8)DTCStatusMask;
#endif

   temp = (uint8)DEM_FILTERED_OK;
  /*loop for all filteres DTCs   */
   while(temp == (uint8)DEM_FILTERED_OK)
   {
     /*get one DTC at a time*/
      temp =  (uint8)Dem_GetNextFilteredDTC(&FilteredDTC,&FilteredDTCStatus);
      if(temp == (uint8)DEM_FILTERED_OK)
      {
        /*assemble response with the data provided by DEM function*/
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)DTCSeverity))
         return;
#else
        if (Dcm_pMsgContext2->resMaxDataLen < MessageLength+5)
        {
            Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_RESPONSE_TOO_LONG);
            return;
        }
        /*fill in the response data*/
        pMsgContext->resData[MessageLength++]=(uint8)DTCSeverity;
#endif
        if (Dem_GetViewIDOfDTC(FilteredDTC,DEM_DTC_KIND_ALL_DTCS,&viewId)!=DEM_VIEWID_OK)
        {
            Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
            return;
        }
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)viewId))
          return;
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC >> 16)))
          return;
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC >> 8)))
          return;
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC)))
          return;
        if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, FilteredDTCStatus))
          return;
#else
        pMsgContext->resData[MessageLength++]=(uint8)viewId;
        Dcm_Write3BytesInU8Array(FilteredDTC, &pMsgContext->resData[MessageLength]);
        MessageLength+=3;
        pMsgContext->resData[MessageLength++]=FilteredDTCStatus;
#endif
      }
      
      

      if (temp == (uint8)DEM_FILTERED_WRONG_DTCKIND)
      {

        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
        return;
      }
   }  /* end of while      */

   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {
   #endif
     pMsgContext->resDataLen=MessageLength;
    Dcm_ProcessingDone(pMsgContext);
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   else
   {
     Dcm_PagedBufferService=0; /*end PagedBuffer processing*/
   }
   #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x09
*
* \name Dcm_ReportSeverityInformationOfDTC
*
* \b Service-Id:   0x54
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x09 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION09_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportSeverityInformationOfDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint32 RecDTC;
   uint8  DTCStatusMask;
   Dem_DTCSeverityType severity;
   Dem_ReturnGetSeverityOfDTCType severitystatus;
   Dem_ViewIdType viewId;
   Dem_DTCStatusMaskType StatusMask;

   /*calculate the DTC received in the request*/
   RecDTC=Dcm_Read3BytesFromU8Array(&pMsgContext->reqData[1]);

   pMsgContext->resData[0] = pMsgContext->reqData[0];
   pMsgContext->resData[4] = pMsgContext->reqData[1];
  pMsgContext->resData[5] = pMsgContext->reqData[2];
   pMsgContext->resData[6] = pMsgContext->reqData[3];

  /*get the status of the DTC*/
   if(Dem_GetStatusOfDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,&DTCStatusMask) != DEM_STATUS_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

  /*assemble the reponse  */
  if (Dem_GetDTCStatusAvailabilityMask(&StatusMask)!=E_OK)
  {
   Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
     return;
   }
   pMsgContext->resData[1] =  (uint8)StatusMask;
  if (Dem_GetSeverityOfDTC(RecDTC,DEM_DTC_ORIGIN_PRIMARY_MEMORY,&severity,&severitystatus)!=E_OK)
  {
    Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
  }
   pMsgContext->resData[2] =  (uint8)severity; /*no function in DEM can return the severity so dummy value used*/
   if (Dem_GetViewIDOfDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,&viewId)!=DEM_VIEWID_OK)
   {
     Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   pMsgContext->resData[3] =  viewId;  /*no function in DEM can return the functional unit so dummy value used*/
   pMsgContext->resData[7] =  DTCStatusMask;
   pMsgContext->resDataLen=0x08;
   Dcm_ProcessingDone(pMsgContext);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x0A
*
* \name Dcm_ReportSupportedDTC
*
* \b Service-Id:   0x55
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x0A of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION0A_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportSupportedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   Dem_DTCStatusMaskType DTCStatusMask;
   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   
   /*filter the DTC*/
   if(Dem_SetDTCFilter(0,DEM_DTC_KIND_ALL_DTCS,\
      DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
      DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
   {

      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

  /*use this function to report all the filtered DTCs*/
   Dcm_ReportFilteredDTC(pMsgContext,DTCStatusMask);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x0B
*
* \name Dcm_ReportFirstTestFailedDTC
*
* \b Service-Id:   0x56
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x0B of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION0B_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportFirstTestFailedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*this function is used to return the first failed DTC
    Dcm_ReportFailedDTC shall be used to report this first failed DTC*/
   Dcm_ReportFailedDTC(pMsgContext,DEM_FIRST_FAILED_DTC);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x0C
*
* \name Dcm_ReportFirstConfirmedDTC
*
* \b Service-Id:   0x57
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x0C of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION0C_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportFirstConfirmedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*this function is used to return the first confirmed DTC
    Dcm_ReportFailedDTC shall be used to report this first confirmed DTC*/
   Dcm_ReportFailedDTC(pMsgContext,DEM_FIRST_DET_CONFIRMED_DTC);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x0D
*
* \name Dcm_ReportMostRecentTestFailedDTC
*
* \b Service-Id:   0x58
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x0D of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION0D_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportMostRecentTestFailedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*this function is used to return the most recent failed DTC
    Dcm_ReportFailedDTC shall be used to report this most recent failed DTC*/
   Dcm_ReportFailedDTC(pMsgContext,DEM_MOST_RECENT_FAILED_DTC);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x0E
*
* \name Dcm_ReportMostRecentConfirmedDTC
*
* \b Service-Id:   0x59
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x0E of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION0E_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportMostRecentConfirmedDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*this function is used to return the most recent confirmed DTC
    Dcm_ReportFailedDTC shall be used to report this most recent confirmed DTC*/
   Dcm_ReportFailedDTC(pMsgContext,DEM_MOST_REC_DET_CONFIRMED_DTC);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x0F
*
* \name Dcm_ReportMirrorMemoryDTCByStatusMask
*
* \b Service-Id:   0x60
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x0F of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION0F_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportMirrorMemoryDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   Dem_DTCStatusMaskType DTCStatusMask;
   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   /*set the filter...DTC from the mirror memory with a status mask*/
   if (pMsgContext->reqData[1] != 0)
   {
      if( Dem_SetDTCFilter(pMsgContext->reqData[1],DEM_DTC_KIND_ALL_DTCS,\
           DEM_DTC_ORIGIN_MIRROR_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
           DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
      {
         Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
         return;
      }
   }

   /*call this function to report all filtered DTCs*/
   Dcm_ReportFilteredDTC(pMsgContext,DTCStatusMask);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x10
*
* \name Dcm_ReportMirrorMemoryDTCExtendedRecordByDTCNumber
*
* \b Service-Id:   0x61
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x10 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION10_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportMirrorMemoryDTCExtendedRecordByDTCNumber(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*extended data shall be reported from the mirror memory*/
   Dcm_ReportDTCExtendedData(pMsgContext);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x11
*
* \name Dcm_ReportNumberOfMirrorMemoryDTCByStatusMask
*
* \b Service-Id:   0x62
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x11 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION11_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportNumberOfMirrorMemoryDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint16 temp;
   Dem_DTCStatusMaskType DTCStatusMask;

   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   /*set the filter*/
   if( Dem_SetDTCFilter(pMsgContext->reqData[1],DEM_DTC_KIND_ALL_DTCS,\
      DEM_DTC_ORIGIN_MIRROR_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
      DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

   /*get the number of DTC matching the filter*/
   if (Dem_GetNumberOfFilteredDTC(&temp)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   pMsgContext->resData[0] = pMsgContext->reqData[0];/*Sub-Function = 0x11*/
   pMsgContext->resData[1] = (uint8)DTCStatusMask;
   pMsgContext->resData[2] = (uint8)DEM_DTC_TRANSLATION_ISO14229_1;/*DTC format ISO14229*/
   pMsgContext->resData[3] = (uint8)(temp>>8);/*DTC count HighByte*/
   pMsgContext->resData[4] = (uint8)temp;     /*DTC count LowByte*/
   pMsgContext->resDataLen=0x05;  /*Response Length*/
   Dcm_ProcessingDone(pMsgContext);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x12
*
* \name Dcm_ReportNumberOfEmissionsRelatedOBDDTCByStatusMask
*
* \b Service-Id:   0x63
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x12 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION12_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportNumberOfEmissionsRelatedOBDDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   uint16 temp;
   Dem_DTCStatusMaskType DTCStatusMask;

   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   
   /*filter the DTCs*/
   if( Dem_SetDTCFilter(pMsgContext->reqData[1],DEM_DTC_KIND_EMISSION_REL_DTCS,\
      DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
      DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

   /*get the number of the filtered DTCs      */
   if (Dem_GetNumberOfFilteredDTC(&temp)==E_NOT_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   pMsgContext->resData[0] = pMsgContext->reqData[0];/*Sub-Function = 0x12 */
   pMsgContext->resData[1] = (uint8)DTCStatusMask;
   pMsgContext->resData[2] = (uint8)DEM_DTC_TRANSLATION_ISO15031_6;
   pMsgContext->resData[3] = (uint8)(temp>>8); /*DTC count HighByte*/
   pMsgContext->resData[4] = (uint8)temp;    /*DTC count LowByte*/
   pMsgContext->resDataLen=0x05;  /*Response Length   */
  Dcm_ProcessingDone(pMsgContext);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x13
*
* \name Dcm_ReportEmissionsRelatedOBDDTCByStatusMask
*
* \b Service-Id:   0x64
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x13 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION13_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportEmissionsRelatedOBDDTCByStatusMask(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
   Dem_DTCStatusMaskType DTCStatusMask;
   if (Dem_GetDTCStatusAvailabilityMask(&DTCStatusMask)!=E_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }
   
   /*set the filter*/
   if (pMsgContext->reqData[1] != 0)
   {
      if( Dem_SetDTCFilter(pMsgContext->reqData[1],DEM_DTC_KIND_EMISSION_REL_DTCS,\
         DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
         DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
      {

         Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
         return;
      }
   }
   /*report the filtered DTCs*/
   Dcm_ReportFilteredDTC(pMsgContext,DTCStatusMask);
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing UDS service 0x19 subfunction 0x14
*
* \name Dcm_ReportDTCFaultDetectionCounter
*
* \b Service-Id:   0x65
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the subfunction 0x14 of service 0x19 of UDS (ReadDTCInformation)
*/
#if DCM_USE_DEM==STD_ON
#if (DCM_READDTC_SUBFUNCTION14_ENABLED==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportDTCFaultDetectionCounter(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  uint8 temp;
  uint32 FilteredDTC;
  uint8 FilteredDTCStatus;
  uint16 MessageLength;
  uint8 SubFunction;
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
  uint8 ret;
  uint8 i;
  uint16 Size;
  #endif

  SubFunction=pMsgContext->reqData[0];

  /*set the filter for all DTC with preFailed status - the status mask type is not final*/
  if( Dem_SetDTCFilter(0x01,DEM_DTC_KIND_ALL_DTCS,\
      DEM_DTC_ORIGIN_PRIMARY_MEMORY,DEM_FILTER_WITH_SEVERITY_NO,\
      DEM_SEVERITY_NO_SEVERITY, DEM_FILTER_FOR_FAULTDETECTIONCOUNTER_NO) != DEM_FILTER_ACCEPTED)
   {

      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
     {
       Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=1;/*sub function*/
       ret=Dem_GetNumberOfFilteredDTC(&Size);/*this cannot fail because the filter has already been accepted*/
       /*if this fails, the filter setting also fails so the function will not reach this point*/
       if (ret == E_OK)
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=4*Size;
       /*here decide if pagedbuffer is needed*/
       Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
       if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;
         Dcm_PagedBufferService=Dcm_ReportDTCFaultDetectionCounter;
         pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length       */
         for (i=0;i<pMsgContext->reqDataLen;i++)
           Dcm_RequestData[i]=pMsgContext->reqData[i];
         Dcm_LengthSoFar=0;
         Dcm_StartPagedProcessing(pMsgContext);
         return; /*end here the processing       */
       }
       else
       {
         Dcm_LengthSoFar=0;
         Dcm_PagedBufferService=0;
       }
     }
   #endif

  MessageLength=0;
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
  if (Dcm_PagedBufferService)
  {
    MessageLength++;
  }
  #endif

  if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, SubFunction))
     return;

  temp=(uint8)DEM_FILTERED_OK;
  /*loop for all filtered DTCs*/
  while (temp == (uint8)DEM_FILTERED_OK)
  {
    /*get one DTC at a time*/
    temp =  (uint8)Dem_GetNextFilteredDTC(&FilteredDTC,&FilteredDTCStatus);

    if (temp == (uint8)DEM_FILTERED_OK)
    {
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
      /*fill in the response data*/
      if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC >> 16)))
         return;
      if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC >> 8)))
         return;
      if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC)))
         return;
      /*placed 0 as fault detection counter*/
      if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(0x00)))
         return;
#else
        if (Dcm_pMsgContext2->resMaxDataLen < MessageLength+3)
        {
            Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_RESPONSE_TOO_LONG);
            return;
        }
        /*fill in the response data*/
        Dcm_Write3BytesInU8Array(FilteredDTC, &pMsgContext->resData[MessageLength]);
        MessageLength+=3;
        /*placed 0 as fault detection counter*/
        pMsgContext->resData[MessageLength++]=(uint8)(0x00);
#endif
    }
    if (temp==(uint8)DEM_FILTERED_WRONG_DTCKIND)
    {

    }

  }

  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
  if (!Dcm_PagedBufferService)
   {
   #endif
     pMsgContext->resDataLen=MessageLength;
    Dcm_ProcessingDone(pMsgContext);
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   else
   {
     Dcm_PagedBufferService=0; /*end PagedBuffer processing*/
   }
   #endif
  return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for reporting the filtered DTCs
*
* \name Dcm_ReportFilteredDTC
*
* \b Service-Id:   0x67
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dem_DTCStatusMaskType DTCStatusMask - indicates the supported DTC status bits from the DEM
*
* \return          none
*
* \b Description:  This function shall insert in the response all the filtered DTCs. The filter was previously set.
* this function will only get the next filtered DTC until there are no more to report.
*/
#if DCM_USE_DEM==STD_ON
#if ((DCM_READDTC_SUBFUNCTION02_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0A_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION0F_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION13_ENABLED==STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportFilteredDTC(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext, Dem_DTCStatusMaskType DTCStatusMask)
{
   uint8 temp;
   uint32 FilteredDTC;
   uint8  FilteredDTCStatus;
   uint16  MessageLength;
   uint8 SubFunction;
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   uint8 i;
   uint16 filtered;
   #endif

   SubFunction=pMsgContext->reqData[0];

   /* >> GAN:2008-03-13 For subfunctions 0x02, 0x13 and 0x0F, if StatusMask is 0x00 return only availability mask*/
   if ((pMsgContext->reqData[1] == 0)&&(SubFunction != 0x0A))
   {
      /*place availability mask and finish the request*/
      pMsgContext->resData[0]=SubFunction;
      pMsgContext->resData[1]=DTCStatusMask;
      MessageLength = 2;
      pMsgContext->resDataLen=MessageLength;
      Dcm_ProcessingDone(pMsgContext);
      return;
   }
   /* << GAN:2008-03-13 For subfunctions 0x02, 0x13 and 0x0F, if StatusMask is 0x00 return only availability mask*/

   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {
   #endif
     if( Dem_DisableDTCRecordUpdate() != E_OK)
     {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
        return;
     }
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   #endif

   /*calculate length */
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
     {
       Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=2;/*subfunction and availability*/
       /*calculate length somehow*/
       if (Dem_GetNumberOfFilteredDTC(&filtered)==E_OK)
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=filtered*4;/*each DTC has 3 bytes plus the status*/
       }
       /*here verify if the length if PagedBuffer is required      */
       Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
       if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;/*service Id is counted but will be added later*/
         Dcm_PagedBufferService=Dcm_ptrReadDTCInformation[SubFunction -1];
         pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length       */
         for (i=0;i<pMsgContext->reqDataLen;i++)
           Dcm_RequestData[i]=pMsgContext->reqData[i];
         Dcm_LengthSoFar=0;
         Dcm_StartPagedProcessing(pMsgContext);
         return; /*end here the processing       */
       }
       else
       {
         Dcm_LengthSoFar=0;
         Dcm_PagedBufferService=0;
       }
     }
   #endif

   /*some bytes from the request must be set in the response as well  */
   MessageLength=0;

   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (Dcm_PagedBufferService)
   {
       MessageLength++;/*just make space for the service Id, place actual data in Dcm_ProcessPage*/
   }
   #endif

   if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, SubFunction))
     return;

   if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(DTCStatusMask)))
     return;

   do
   {
     /*one DTC at a time is processed*/
      temp =  (uint8)Dem_GetNextFilteredDTC(&FilteredDTC,&FilteredDTCStatus) ;

      if(temp == (uint8)DEM_FILTERED_OK)
      {
         
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
        /*fill the response with the DTC and DTCStatus*/
       if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC >> 16)))
         return;
       if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC >> 8)))
         return;
       if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTC)))
         return;
       if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(FilteredDTCStatus)))
         return;
#else
        if (Dcm_pMsgContext2->resMaxDataLen < MessageLength+3)
        {
            Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_RESPONSE_TOO_LONG);
            return;
        }
        /*fill the response with the DTC and DTCStatus*/
        
        Dcm_Write3BytesInU8Array(FilteredDTC, &pMsgContext->resData[MessageLength]);
        MessageLength+=3;
        pMsgContext->resData[MessageLength++]=FilteredDTCStatus;
#endif
         
      }
      if (temp == (uint8)DEM_FILTERED_WRONG_DTCKIND)
      {
        temp=(uint8)Dem_EnableDTCRecordUpdate();

        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
        return;
      }

   }  while(temp != (uint8)DEM_FILTERED_NO_MATCHING_DTC);

   if(Dem_EnableDTCRecordUpdate() != E_OK)
   {

      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {
   #endif
     pMsgContext->resDataLen=MessageLength;
    Dcm_ProcessingDone(pMsgContext);
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   else
   {
     Dcm_PagedBufferService=0; /*end PagedBuffer processing*/
   }
   #endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for reporting the extended data
*
* \name Dcm_ReportDTCExtendedData
*
* \b Service-Id:   0x68
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall insert in the response all the extended data for a DTC. This function
* is used by service 0x19 subfunctions 0x06 and 0x10.
*/
#if DCM_USE_DEM==STD_ON
#if ((DCM_READDTC_SUBFUNCTION06_ENABLED==STD_ON)||(DCM_READDTC_SUBFUNCTION10_ENABLED==STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_ReportDTCExtendedData(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{

   uint32 RecDTC;
   uint32 temp;
   uint16  ExtDataRecNr;
   #if DCM_PAGEDBUFFER_ENABLED==STD_ON
   uint16 ExtendedSize;
   #endif
   uint8  i;
   uint16  MessageLength;
   uint8  Status;
   uint8  SubFunction;
   Dem_DTCOriginType Origin=DEM_DTC_ORIGIN_PRIMARY_MEMORY;

   /* >> GAN:2007-09-13 this can be done always (PagedBuffer or not)
      establish the origin of the extended data*/
   SubFunction=pMsgContext->reqData[0];
   if (SubFunction==0x06)
   {
      Origin=DEM_DTC_ORIGIN_PRIMARY_MEMORY;
   }
   if (SubFunction==0x10)
   {
      Origin=DEM_DTC_ORIGIN_MIRROR_MEMORY;
   }

   ExtDataRecNr  = pMsgContext->reqData[4];

   /*get the DTC according with the received bytes*/
   RecDTC=Dcm_Read3BytesFromU8Array(&pMsgContext->reqData[1]);
   /* << GAN:2007-09-13 this can be done always (PagedBuffer or not)    */

   /* Status of DTC to byte #5*/
   temp = (uint8)Dem_GetStatusOfDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,DEM_DTC_ORIGIN_PRIMARY_MEMORY,&Status);
   if(temp != (uint8)DEM_STATUS_OK)
   {
      Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
      return;
   }

   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {
   #endif
     if (Dem_DisableDTCRecordUpdate()==E_NOT_OK)
     {
       Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
       return;
     }
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   #endif

   #if DCM_PAGEDBUFFER_ENABLED==STD_ON
     /*calculate length*/
   if (!Dcm_PagedBufferService) /*calculate length only if a PagedBuffer processing is not started*/
     {
       Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=5; /*first four bytes shall be taken from the request  and the fifth byte is the status of DTC*/
       if (ExtDataRecNr!=0xFF)
       {
         /* >> GAN:2009-01-30 Changed calculation of the length*/
         if (DEM_GET_SIZEOFEDRBYDTCTYPE_OK==Dem_GetSizeOfExtendedDataRecordByDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,Origin,ExtDataRecNr,&ExtendedSize))
          {
           Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=ExtendedSize;
            if (ExtendedSize!=0x00)
              Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++; /*the ExtDataRecNr will be added to the response         */
          }
          /* << GAN:2009-01-30 Changed calculation of the length*/
       }
       else
       {
         ExtDataRecNr  = 0x00;
          /* >> vm:2009-02-26 changed while statement to check all extended datatrecords (up to 0xFE)*/
          /*Reason is that extended data record number might be non linear so that ExtendedSize could be 0x00
          even if there are extended data records left that are not already read*/
          /*loop for all extended data*/
          while(ExtDataRecNr<0xFF)
          {
            if (DEM_GET_SIZEOFEDRBYDTCTYPE_OK==Dem_GetSizeOfExtendedDataRecordByDTC(RecDTC,DEM_DTC_KIND_ALL_DTCS,Origin,ExtDataRecNr,&ExtendedSize))
            {
              Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen+=ExtendedSize;
               if (ExtendedSize!=0x00)
                  Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++; /*this is the ExtDataRecNr*/
            }
            ExtDataRecNr++;
          }
          /* << vm:2009-02-26 */
       }
       Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
       if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)
       {
         Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;
         Dcm_PagedBufferService=Dcm_ReportDTCExtendedData;
         pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length       */
         for (i=0;i<pMsgContext->reqDataLen;i++)
           Dcm_RequestData[i]=pMsgContext->reqData[i];
         Dcm_LengthSoFar=0;
         Dcm_StartPagedProcessing(pMsgContext);
         return; /*end here the processing       */
       }
       else
       {
         Dcm_LengthSoFar=0;
         Dcm_PagedBufferService=0;
       }
     }
   #endif

   /*take again the extended data record number as it might have been altered by the calculation of the length*/
   ExtDataRecNr  = pMsgContext->reqData[4];

   MessageLength=0;

   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (Dcm_PagedBufferService)
   {
       MessageLength++;/*just make space for the service Id, place actual data in Dcm_ProcessPage*/
   }
   #endif
   
 #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, SubFunction))
     return;
   if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(RecDTC>>16)))
     return;
   if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)(RecDTC>>8)))
     return;
   if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, (uint8)RecDTC))
     return;
   if (1==Dcm_VerifyPagedBuffer(MessageLength++, pMsgContext->resData, Status))
     return;
#else
    if (Dcm_pMsgContext2->resMaxDataLen < MessageLength+4)
    {
       Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_RESPONSE_TOO_LONG);
       return;
    }
     pMsgContext->resData[MessageLength++]=SubFunction;
     
     Dcm_Write3BytesInU8Array(RecDTC, &pMsgContext->resData[MessageLength]);
     MessageLength+=3;
     pMsgContext->resData[MessageLength++]=Status;
#endif

   if(ExtDataRecNr!=0xFF)
   {
      /*extended data records are filled directly in the response buffer from the correct position       */
      Dcm_BufferLength=255;/*this is the maximum number of data to be placed in the buffer*/
      temp =  (uint8)Dem_GetExtendedDataRecordByDTC( RecDTC,DEM_DTC_KIND_ALL_DTCS,
           Origin,ExtDataRecNr,&Dcm_Buffer[0],&Dcm_BufferLength);

      if (temp == (uint8)DEM_RECORD_OK)/*if extended data is ok, fill response, otherwise leave empty*/
      {
      for (i=0;i<Dcm_BufferLength;i++)
        pMsgContext->resData[MessageLength+i]=Dcm_Buffer[i];

      MessageLength+=Dcm_BufferLength;
      }
   }
   else
   {
     /*only here the pagedbuffer might be needed
       read all extended data*/
      temp = 0;
      ExtDataRecNr  = 0x00;
      /*loop for all extended data*/

      /* >> vm:2009-02-26 changed while statement to check all extended datatrecords (up to 0xFE)*/
      /*Reason is that extended data record number might be non linear so that ExtendedSize could be 0x00
      even if there are extended data records left that are not already read*/
      /*loop for all extended data*/

      while(ExtDataRecNr<0xFF)
      {
        /*get extended data and fill it in the response buffer*/
        Dcm_BufferLength=255;/*number of byte that can be filled*/
         temp =  (uint8)Dem_GetExtendedDataRecordByDTC( RecDTC,DEM_DTC_KIND_ALL_DTCS,
               Origin,ExtDataRecNr,&Dcm_Buffer[0],&Dcm_BufferLength);

         /*if data exist, place in response, if not go to next extended data     */
         if(temp==(uint8)DEM_RECORD_OK)
         {
           /*all bytes from the Dcm_Buffer should be placed in the buffer for response*/
           for(i=0;i<Dcm_BufferLength;i++)
           {
             /*check PagedBuffer*/
             if (1==Dcm_VerifyPagedBuffer(MessageLength++,pMsgContext->resData,Dcm_Buffer[i]))
               return; /*this means that Dcm_ProcessPage was called            */
           }
         }
         ExtDataRecNr++;
      }
   }
   /* >> vm:2009-02-26 */
   
   if (Dem_EnableDTCRecordUpdate()==E_NOT_OK)
   {
     Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
     return;
   }
   #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   if (!Dcm_PagedBufferService)
   {
   #endif
     pMsgContext->resDataLen=MessageLength;
    Dcm_ProcessingDone(pMsgContext);
  #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
   }
   else
   {
     Dcm_PagedBufferService=0; /*end PagedBuffer processing*/
   }
   #endif

}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*
*! Function used for processing the PagedBuffer mechanism
*
* \name Dcm_VerifyPagedBuffer
*
* \b Service-Id:   0x69
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  none
*
* \return          uint8 - status of the operation
*
* \b Description:  This function is used to decide whether the data can be placed in the response buffer or,
* because of the PagedBuffer mechanism, it must call the ProcessPage because the page was filled and needs
* to be transmitted.
*/
#if DCM_USE_DEM==STD_ON
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8,DCM_CODE) Dcm_VerifyPagedBuffer(uint16 CurrentLength, Dcm_MsgType buffer, uint8 data)
{
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    /*this is the actual paged buffer processing*/
    if (Dcm_PagedBufferService)
    {
        if (Dcm_LengthSoFar)
            if (CurrentLength < Dcm_LengthSoFar)
                return 3; /*don't place data in buffer*/
        if (CurrentLength - Dcm_LengthSoFar + 1 < Dcm_PagedBufferLength)
        {
            /*data can be still placed in buffer      */
            buffer[CurrentLength-Dcm_LengthSoFar]=data;
            if (CurrentLength + 1 >= (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + Dcm_LengthSoFar))
            {
                Dcm_ProcessPage(CurrentLength - Dcm_LengthSoFar + 1);
                Dcm_LengthSoFar=CurrentLength+1;
                return 2;/*place in buffer and ProcessPage and finish normally the processing*/
            }
            return 0;/*place in buffer     */
        }
        else
        {
            buffer[CurrentLength-Dcm_LengthSoFar]=data;
            Dcm_ProcessPage(Dcm_PagedBufferLength);
            Dcm_LengthSoFar+=Dcm_PagedBufferLength;
            return 1; /*place in buffer and ProcessPage and exit function*/
        }
    }
    else
    {
        buffer[CurrentLength-Dcm_LengthSoFar]=data;
        return 0;
    }
#else
    if (Dcm_pMsgContext2->resMaxDataLen < CurrentLength)
    {
        Dcm_HandleNegResponse(Dcm_pMsgContext2,DCM_E_RESPONSE_TOO_LONG);
        return 1;
    }
    buffer[CurrentLength]=data;
    return 0;
#endif
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (DCM_USE_DEM==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, DCM_CODE) Dcm_Write3BytesInU8Array(uint32 bytesToWrite, CONSTP2VAR(uint8,AUTOMATIC,DCM_APPL_DATA) u8Array)
{
   u8Array[0]=(uint8)(bytesToWrite>>16);
   u8Array[1]=(uint8)(bytesToWrite>>8);
   u8Array[2]=(uint8)bytesToWrite;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif


#if (DCM_USE_DEM==STD_ON)
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(uint32, DCM_CODE) Dcm_Read3BytesFromU8Array(CONSTP2CONST(uint8,AUTOMATIC,DCM_APPL_DATA) u8Array)
{
    uint32 retVal;
    retVal  = (uint32)u8Array[0] << 16;
    retVal += (uint32)u8Array[1] << 8;
    retVal += (uint32)u8Array[2];
    return retVal;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif


/*
*! Function used for processing the OBD service 0x01
*
* \name Dcm_DcmObdRequestCurrentPowerTrainDiagnosticData
*
* \b Service-Id:   0x34
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
*
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the OBD service 0x01. For more information please refer to ISO 15031-5.4
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#if ((defined DCM_OBD_SERVICE_0x01_SUPPORTED)&&(DCM_OBD_SERVICE_0x01_SUPPORTED == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmObdRequestCurrentPowerTrainDiagnosticData(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*different processing for PID:
    1 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0 (availability PIDs)
    2 all the rest in other way (data PIDs)*/
    uint8 PID;
    uint8 NumberOfPids;
    uint8 i,j;
    uint16 MessageLength;
    Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
    Dcm_ObdIdType IdType = DCM_OBD_NO_ID;

    /*can be at most 6 PID...each must be analysed */
    NumberOfPids = (uint8)(pMsgContext->reqDataLen); 
    
    if (    (DCM_OBD_REQUEST_MIN_LEN > pMsgContext->reqDataLen)
         || (DCM_OBD_REQUEST_MAX_LEN < pMsgContext->reqDataLen))
    {
       Dcm_HandleNegResponse(pMsgContext,DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT);
       return;
    }

    #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (!Dcm_PagedBufferService)
    {
        Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen=0;/*no information at beginning */
        for (i=0;i<NumberOfPids;i++)
        {
            PID = pMsgContext->reqData[i];
            Dcm_ObdGetIdType(PID,&IdType);
            switch(IdType)
            {
                case DCM_OBD_DATA_ID:
                    /* Data PID */
                    for ( j = 0 ; j < DCM_OBD_NUMBER_OF_PIDS_SERVICE_0x01 ; j++ )
                    {
                        if( PID == Dcm_ObdPidCfg[j].PID)
                        {
                            Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen += (Dcm_ObdPidCfg[j].PidSize + 1); /* Buffer + PID */
                        }
                    }
                    break;
                case DCM_OBD_AVAILABILITY_ID:
                    /*no paged buffering for availability pids*/
                default:
                    break;
            }
        } /*end of for*/
        Dcm_PagedBufferLength=Dcm_DiagnosticBufferCfg[Dcm_Current_Message_Status.Dcm_Message_Status_Busy - 1].DCM_BUFFER_SIZE;
        if (Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen + 1 > Dcm_PagedBufferLength)
        {
            Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen++;/*service Id is counted but will be added later        */
            Dcm_PagedBufferService=Dcm_DcmObdRequestCurrentPowerTrainDiagnosticData;
            pMsgContext->resDataLen=Dcm_Current_Message_Status.Dcm_PagedProcessing_DataLen; /*this will be the total data length        */
            for (i=0;i<pMsgContext->reqDataLen;i++)
            {
                Dcm_RequestData[i]=pMsgContext->reqData[i];
            }
            Dcm_LengthSoFar=0;
            Dcm_StartPagedProcessing(pMsgContext);
            return; /*end here the processing     */
        }
        else
        {
            Dcm_LengthSoFar=0;
            Dcm_PagedBufferService=0;
        }
    }
    #endif

    MessageLength=0x00; /*because the SID is missing from the response*/
    #if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
    if (Dcm_PagedBufferService)
      MessageLength++;
    #endif
    
    for (i=0;i<NumberOfPids;i++)
    {
        PID = pMsgContext->reqData[i];
        Dcm_ObdGetIdType(PID,&IdType);
        switch(IdType)
        {
            case DCM_OBD_AVAILABILITY_ID:
                /* handling of availability pids */
                /* 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0  */
                Dcm_ObdHandleAvailabilityId(PID,
                                            DCM_OBD_NUMBER_OF_AVAILABILITY_PIDS,
                                            Dcm_AvailabilityPids_0x01,
                                            pMsgContext,
                                            &MessageLength);
                break;
            case DCM_OBD_DATA_ID:
                /* Data PID */
                if (1==Dcm_ObdHandleDataPid(PID,pMsgContext,&MessageLength,&ResponseCode))
                    return;
                break;
            default:
                ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                break;
        }
        if(ResponseCode != DCM_E_OK)
        {
            /* cancel the loop*/
            break;
        }
    }
    Dcm_ObdHandleResponse(pMsgContext,ResponseCode,MessageLength);
    return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_SERVICE_0x01_SUPPORTED)&&(DCM_OBD_SERVICE_0x01_SUPPORTED == STD_ON))*/
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

/*
*! Function used for handling Data Pids for OBD service 0x02
*
* \name Dcm_ObdHandleDataPid
*
* 
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 pid - the PID for which the processing is done
*                  uint8 fzf - FreezeFrame
*
* \param (Output)  Dcm_MsgContextType *pMsgContext - structure that contains information about the service
*                  pMessageLength - Length of the buffer
*                  ResponseCode - Result of the operation
*
* \return          uint8 - result of the operation (relevant for PagedBuffer processing)
*
* \b Description:  This function is used by the service 0x02 (OBD) and sub-function different from 0x00, 0x02 and no multiple
*  of 0x20. For more information about the processing of this function please refer to ISO 15031-5.4
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#if ((defined DCM_OBD_SERVICE_0x01_SUPPORTED)&&(DCM_OBD_SERVICE_0x01_SUPPORTED == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(uint8,DCM_CODE) Dcm_ObdHandleDataPid(uint8 PID, 
                                          CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
                                          P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength,
                                          P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ResponseCode)
{
    uint8 i,j;

    for ( i = 0 ; i < DCM_OBD_NUMBER_OF_PIDS_SERVICE_0x01 ; i++ )
    {
        if( PID == Dcm_ObdPidCfg[i].PID)
        {
            if(E_OK == Dcm_ObdPidCfg[i].GetPidFuncPtr(&Dcm_Buffer[0]))
            {
                if (1==Dcm_VerifyPagedBuffer((*pMessageLength)++,pMsgContext->resData,PID))
                      return 1;
                for(j=0;j < Dcm_ObdPidCfg[i].PidSize ;j++)
                {
                    if (1==Dcm_VerifyPagedBuffer((*pMessageLength)++,pMsgContext->resData,Dcm_Buffer[j]))
                        return 1;
                }
            }
            else
            {
                *ResponseCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            /* stop loop */
            break;
        }
        else
        {
            /* no response for unsupported pids */
        }
    }
    return 0;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_SERVICE_0x01_SUPPORTED)&&(DCM_OBD_SERVICE_0x01_SUPPORTED == STD_ON))*/
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/


/*
*! Function used for processing the OBD service 0x06
*
* \name Dcm_DcmObdRequestOnBoardMonitorTestResult
*
* \b Service-Id:   0x34
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the OBD service 0x06. For more information please refer to ISO 15031-5.4
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#if ((defined DCM_OBD_SERVICE_0x06_SUPPORTED)&&(DCM_OBD_SERVICE_0x06_SUPPORTED == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmObdRequestOnBoardMonitorTestResult(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
  /*different processing for OBDMID:
    1 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0 (availability OBDMIDs)
    2 all the rest in other way (data OBDMIDs)*/
  uint8 OBDMID;
  uint8 NumberOfObdmids;
  uint8 i;
  uint16 MessageLength;
  Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
  Dcm_ObdIdType IdType = DCM_OBD_NO_ID;
  
    MessageLength = 0x00; 
    if (    (DCM_OBD_REQUEST_MIN_LEN > pMsgContext->reqDataLen)
         || (DCM_OBD_REQUEST_MAX_LEN < pMsgContext->reqDataLen))
    {
       ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else
    {
        /*can be at most 6 OBDMIDs...each must be analysed*/
        NumberOfObdmids = (uint8)(pMsgContext->reqDataLen); 
        for (i=0;i<NumberOfObdmids;i++)
        {
            OBDMID = pMsgContext->reqData[i];
            
            Dcm_ObdGetIdType(OBDMID,&IdType);
            switch(IdType)
            {
                case DCM_OBD_AVAILABILITY_ID:
                    /* handling of availability Obdmids */
                    /* 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0  */
                    Dcm_ObdHandleAvailabilityId(OBDMID,
                                                DCM_OBD_NUMBER_OF_AVAILABILITY_OBDMIDS,
                                                Dcm_AvailabilityOBDMIDs,
                                                pMsgContext,
                                                &MessageLength);
                    break;
                case DCM_OBD_DATA_ID:
                    /* Data OBDMID */
                    if( 1 != pMsgContext->reqDataLen)
                    {
                        /* only one data ID allowed*/
                        ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    }
                    else
                    {
                        ResponseCode = Dcm_ObdHandleDataObdmid(OBDMID,pMsgContext,&MessageLength);
                    }
                    break;
                default:
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
            }
            if(ResponseCode != DCM_E_OK)
            {
                /* cancel the loop*/
                break;
            }
        }
    }
    Dcm_ObdHandleResponse(pMsgContext,ResponseCode,MessageLength);
    return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_SERVICE_0x06_SUPPORTED)&&(DCM_OBD_SERVICE_0x06_SUPPORTED == STD_ON))*/
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

/*
*! Function used for processing the OBD services
*
* \name Dcm_ObdHandleAvailabilityId
*
* 
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 pid - the PID for which the processing is done
*                  uint8 fzf - FreezeFrame
*
* \param (Output)  Dcm_MsgContextType *pMsgContext - structure that contains information about the service
*
* \return          uint8 - result of the operation (relevant for PagedBuffer processing)
*
* \b Description:  This function is used to write the availability PIDs/TIDs/InfoTypes 
* for the OBD services $01, $06, $08, $09 */
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_ObdHandleAvailabilityId(
    uint8 AvailabilityID, 
    const uint8 NumberOfAvailabilityIDs,
    CONSTP2CONST(Dcm_ObdAvailabilityDataType,AUTOMATIC,DCM_APPL_DATA) AvailabilityIdDataTable,
    CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength)
{
    boolean PidRangeSupported;
    uint8 PidIndex;
    
    PidRangeSupported = TRUE;
    PidIndex = (uint8)(AvailabilityID / 32);
    
    if(NumberOfAvailabilityIDs <= PidIndex)
    {
        PidRangeSupported = FALSE;
    }
    else if( 0x00 != AvailabilityID )
    {
        if( 0x01 != (0x01 & AvailabilityIdDataTable[PidIndex-1].DataD) )
        {
            /* The last bit of previous availability pid data indicates
               if the next availability pid is supported*/
            PidRangeSupported = FALSE;
        }
    }
    else
    {
        /* PID 0x00 is always supported */
    }
    if( TRUE == PidRangeSupported )
    {
        pMsgContext->resData[(*pMessageLength)++] = AvailabilityID;
        /* assemble Data A - Data D */
        pMsgContext->resData[(*pMessageLength)++] = AvailabilityIdDataTable[PidIndex].DataA;
        pMsgContext->resData[(*pMessageLength)++] = AvailabilityIdDataTable[PidIndex].DataB;
        pMsgContext->resData[(*pMessageLength)++] = AvailabilityIdDataTable[PidIndex].DataC;
        pMsgContext->resData[(*pMessageLength)++] = AvailabilityIdDataTable[PidIndex].DataD;
    }
    return ;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

/*
*! Function used for handling Data Pids for OBD service 0x06
*
* \name Dcm_ObdHandleDataPid
*
* 
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 OBDMID - the OBDMID for which the processing is done
*
*
* \param (Output)  Dcm_MsgContextType *pMsgContext - structure that contains information about the service
*
* \return          Dcm_NegativeResponseCodeType - result of the operation
*
* \b Description:  This function is used by the service 0x06 (OBD) and sub-function different from 0x00, and no multiple
*  of 0x20. For more information about the processing of this function please refer to ISO 15031-5.4
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#if ((defined DCM_OBD_SERVICE_0x06_SUPPORTED)&&(DCM_OBD_SERVICE_0x06_SUPPORTED == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(Dcm_NegativeResponseCodeType,DCM_CODE) Dcm_ObdHandleDataObdmid(uint8 OBDMID, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength)
{
    uint8 i;
    uint16 TestVal;
    uint16 MinLimit;
    uint16 MaxLimit;
    uint8 Status;
    Dcm_NegativeResponseCodeType RetVal = DCM_E_OK;
    
    for ( i = 0 ; i < DCM_OBD_NUMBER_OF_OBDMID_TIDS ; i++ )
    {
        if( OBDMID == Dcm_ObdObdmidCfg[i].OBDMID)
        {
            if(E_OK == Dcm_ObdObdmidCfg[i].GetDTRValueFuncPtr(&TestVal,&MinLimit,&MaxLimit,&Status))
            {
                if( DCM_DTRSTATUS_VISIBLE != Status)
                {
                    /* invisible DTRs are ignored*/
                }
                /* check if buffer size suffices                                     */
                else if(   ( pMsgContext->resDataLen 
                             + (*pMessageLength)
                             + 9 /* ODBMID + TestId + UaSid + TestVal + MinLimit + MaxLimit*/)
                         > pMsgContext->resMaxDataLen )
                {
                    RetVal = DCM_E_REQUESTOUTOFRANGE;
                }
                else 
                {
                    pMsgContext->resData[(*pMessageLength)++] = OBDMID;
                    pMsgContext->resData[(*pMessageLength)++] = Dcm_ObdObdmidCfg[i].TestId;
                    pMsgContext->resData[(*pMessageLength)++] = Dcm_ObdObdmidCfg[i].UaSId;
                    pMsgContext->resData[(*pMessageLength)++] = (uint8)((TestVal & 0xFF00)>>8);
                    pMsgContext->resData[(*pMessageLength)++] = (uint8)(TestVal & 0x00FF);
                    pMsgContext->resData[(*pMessageLength)++] = (uint8)((MinLimit & 0xFF00)>>8);
                    pMsgContext->resData[(*pMessageLength)++] = (uint8)(MinLimit & 0x00FF);
                    pMsgContext->resData[(*pMessageLength)++] = (uint8)((MaxLimit & 0xFF00)>>8);
                    pMsgContext->resData[(*pMessageLength)++] = (uint8)(MaxLimit & 0x00FF);
                }
            }
            else
            {
                RetVal = DCM_E_CONDITIONSNOTCORRECT;
            }
        }
        else
        {
            /* no response for unsupported pids */
        }
    }
    return RetVal;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_SERVICE_0x06_SUPPORTED)&&(DCM_OBD_SERVICE_0x06_SUPPORTED == STD_ON))*/
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

/*
*! Function used for processing the OBD service 0x08
*
* \name Dcm_DcmObdRequestControl
*
* \b Service-Id:   0x34
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
* 
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the OBD service 0x08. For more information please refer to ISO 15031-5.4
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#if ((defined DCM_OBD_SERVICE_0x08_SUPPORTED)&&(DCM_OBD_SERVICE_0x08_SUPPORTED == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmObdRequestControl(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
    /* different processing for TIDs:
       1 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0 (availability TIDs)
       2 all the rest in other way (data TIDs)*/
    uint8 TID;
    uint8 NumberOfTids;
    uint8 i;
    uint16 MessageLength;
    Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
    Dcm_ObdIdType IdType = DCM_OBD_NO_ID;
    
    MessageLength = 0x00; 
    if (    (DCM_OBD_REQUEST_MIN_LEN > pMsgContext->reqDataLen)
         || (DCM_OBD_REQUEST_MAX_LEN < pMsgContext->reqDataLen))
    {
        ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else
    {
        /*can be at most 6 TIDs...each must be analysed*/
        NumberOfTids = (uint8)(pMsgContext->reqDataLen); 
        for (i=0;i<NumberOfTids;i++)
        {
            TID = pMsgContext->reqData[i];
            Dcm_ObdGetIdType(TID,&IdType);
            switch(IdType)
            {
                case DCM_OBD_AVAILABILITY_ID:
                    /* handling of availability Tids */
                    /* 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0  */
                    Dcm_ObdHandleAvailabilityId(TID,
                                                DCM_OBD_NUMBER_OF_AVAILABILITY_TIDS,
                                                Dcm_AvailabilityTIDs,
                                                pMsgContext,
                                                &MessageLength);
                    break;
                case DCM_OBD_DATA_ID:
                    /* Data Tid */
                    ResponseCode = Dcm_ObdHandleDataTid(TID,pMsgContext,&MessageLength);
                    /*cancel the loop so the following request data is not mistaken as a TestID*/
                    i = NumberOfTids;
                    break;
                default:
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
            }
            if(DCM_E_OK != ResponseCode)
            {
                /* cancel the loop*/
                break;
            }
        }
    }
    Dcm_ObdHandleResponse(pMsgContext,ResponseCode,MessageLength);
    return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_SERVICE_0x08_SUPPORTED)&&(DCM_OBD_SERVICE_0x08_SUPPORTED == STD_ON))*/
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

/*
*! Function used for processing the OBD service 0x08
*
* \name Dcm_ObdHandleDataTid
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 TID - the TID for which the processing is done
*                  
*
* \param (Output)  Dcm_MsgContextType *pMsgContext - structure that contains information about the service
*                  pMessageLength - Length of the buffer
*
* \return          Dcm_NegativeResponseCodeType - Result of the operation
*
* \b Description:  This function is used by the service 0x08 (OBD) and sub-function different from 0x00, and no multiple
*  of 0x20. For more information about the processing of this function please refer to ISO 15031-5.4
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#if ((defined DCM_OBD_SERVICE_0x08_SUPPORTED)&&(DCM_OBD_SERVICE_0x08_SUPPORTED == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(Dcm_NegativeResponseCodeType,DCM_CODE) Dcm_ObdHandleDataTid(uint8 TID, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength)
{
    Dcm_NegativeResponseCodeType RetVal = DCM_E_OK;
    uint8 i,j;

    for ( i = 0 ; i < DCM_OBD_NUMBER_OF_REQ_CONTROL_TIDS ; i++ )
    {
        if( TID == Dcm_ObdReqControlCfg[i].TID)
        {
            if(pMsgContext->reqDataLen - 1 <= Dcm_ObdReqControlCfg[i].InBufferSize)
            {
                if(E_OK == Dcm_ObdReqControlCfg[i].ReqControlFuncPtr(&Dcm_Buffer[0],&pMsgContext->reqData[1]))
                {
                    pMsgContext->resData[(*pMessageLength)++] = TID;
                    for(j=0;j < Dcm_ObdReqControlCfg[i].OutBufferSize ;j++)
                    {
                        pMsgContext->resData[(*pMessageLength)++] = Dcm_Buffer[j];
                    }
                }
                else
                {
                    RetVal = DCM_E_CONDITIONSNOTCORRECT;
                }
            }
            else
            {
                RetVal = DCM_E_REQUESTOUTOFRANGE;
            }
        }
        else
        {
            /* no response for unsupported tids */
        }
    }
    return RetVal;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_SERVICE_0x08_SUPPORTED)&&(DCM_OBD_SERVICE_0x08_SUPPORTED == STD_ON))*/
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

/*
*! Function used for processing the OBD service 0x09
*
* \name Dcm_DcmObdRequestVehicleInformation
*
* \b Service-Id:   0x34
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Non reentrant
*
* \param (Input)   none
* 
* \param (Output)  Dcm_MsgContextType pMsgContextType - structure containing message information
*
*                  Dcm_MsgType reqData - this is the request data buffer
*
*                  Dcm_MsgType respData - this is the response data buffer
*
* \return          none
*
* \b Description:  This function shall process the OBD service 0x09. For more information please refer to ISO 15031-5.4
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#if ((defined DCM_OBD_SERVICE_0x09_SUPPORTED)&&(DCM_OBD_SERVICE_0x09_SUPPORTED == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
FUNC(void,DCM_CODE) Dcm_DcmObdRequestVehicleInformation(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext)
{
    /* different processing for InfoTypes:
       1 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0 (availability InfoTypes)
       2 all the rest in other way (data InfoTypes)*/
    uint8 InfoType;
    uint8 NumberOfInfoTypes;
    uint8 i;
    uint16 MessageLength;
    Dcm_NegativeResponseCodeType ResponseCode = DCM_E_OK;
    Dcm_ObdIdType IdType = DCM_OBD_NO_ID;
    
    MessageLength = 0x00;
    if (    (DCM_OBD_REQUEST_MIN_LEN > pMsgContext->reqDataLen)
         || (DCM_OBD_REQUEST_MAX_LEN < pMsgContext->reqDataLen))
    {
        ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else
    {
        /*can be at most 6 InfoTypes...each must be analysed*/
        NumberOfInfoTypes = (uint8)(pMsgContext->reqDataLen); 
        for (i=0;i<NumberOfInfoTypes;i++)
        {
            InfoType = pMsgContext->reqData[i];
            Dcm_ObdGetIdType(InfoType,&IdType);
            switch(IdType)
            {
                case DCM_OBD_AVAILABILITY_ID:
                    /* handling of availability InfoTypes */
                    /* 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0  */
                    Dcm_ObdHandleAvailabilityId(InfoType,
                                                DCM_OBD_NUMBER_OF_AVAILABILITY_INFO_TYPES,
                                                Dcm_AvailabilityInfoTypes,
                                                pMsgContext,
                                                &MessageLength);
                    break;
                case DCM_OBD_DATA_ID:
                    /* Data InfoType */
                    if( 1 != pMsgContext->reqDataLen)
                    {
                        /* only one data ID allowed*/
                        ResponseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    }
                    else
                    {
                        ResponseCode = Dcm_ObdHandleDataVehicleInfo(InfoType,pMsgContext,&MessageLength);
                    }
                    break;
                default:
                    ResponseCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
            }
            if(DCM_E_OK != ResponseCode)
            {
                /* cancel the loop*/
                break;
            }
        }
    }
    Dcm_ObdHandleResponse(pMsgContext,ResponseCode,MessageLength);
    return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_SERVICE_0x09_SUPPORTED)&&(DCM_OBD_SERVICE_0x09_SUPPORTED == STD_ON))*/
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

/*
*! Function used for processing the OBD service 0x09
*
* \name Dcm_ObdHandleDataVehicleInfo
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 TID - the TID for which the processing is done
*                  
*
* \param (Output)  Dcm_MsgContextType *pMsgContext - structure that contains information about the service
*                  pMessageLength - Length of the buffer
*
* \return          Dcm_NegativeResponseCodeType - Result of the operation
*
* \b Description:  This function is used by the service 0x09 (OBD) and sub-function different from 0x00, and no multiple
*  of 0x20. For more information about the processing of this function please refer to ISO 15031-5.4
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#if ((defined DCM_OBD_SERVICE_0x09_SUPPORTED)&&(DCM_OBD_SERVICE_0x09_SUPPORTED == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(Dcm_NegativeResponseCodeType,DCM_CODE) Dcm_ObdHandleDataVehicleInfo(uint8 InfoType, CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) pMessageLength)
{
    Dcm_NegativeResponseCodeType RetVal = DCM_E_OK;
    uint8 i,j;

    for ( i = 0 ; i < DCM_OBD_NUMBER_OF_INFO_TYPES ; i++ )
    {
        if( InfoType == Dcm_ObdVehicleInfoCfg[i].InfoType)
        {
            if(E_OK == Dcm_ObdVehicleInfoCfg[i].GetInfoTypeFuncPtr(&Dcm_Buffer[0]))
            {
                pMsgContext->resData[(*pMessageLength)++] = InfoType;
                for(j=0;j < Dcm_ObdVehicleInfoCfg[i].VehInfoSize ;j++)
                {
                    pMsgContext->resData[(*pMessageLength)++] = Dcm_Buffer[j];
                }
            }
            else
            {
                RetVal = DCM_E_CONDITIONSNOTCORRECT;
            }
        }
        else
        {
            /* no response for unsupported InfoTypes */
        }
    }
    return RetVal;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_SERVICE_0x09_SUPPORTED)&&(DCM_OBD_SERVICE_0x09_SUPPORTED == STD_ON))*/
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/


/*
*! Function used for processing OBD services
*
* \name Dcm_ObdHandleDataPid
* 
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   uint8 PID - the ID for which the processing is done
*                  
*
* \param (Output)  IdType - The Type of the ID
* \return          Dcm_NegativeResponseCodeType - Result of the operation
*
* \b Description:  This function is used to retreive the type of PIDs/OBD Monitor IDs/TIDs/InfoTypes 
                    used by the OBD Services $01, $02, $06, $08, $09.
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_ObdGetIdType(uint8 PID,P2VAR(Dcm_ObdIdType, AUTOMATIC, DCM_APPL_DATA) IdType)
{
    if ((0x00 == PID)|| (0x00 == (PID % 32)))
    {
        if(   (DCM_OBD_NO_ID == *IdType)
            ||(DCM_OBD_AVAILABILITY_ID == *IdType))
        {
            *IdType = DCM_OBD_AVAILABILITY_ID;
        }
        else
        {
            /* combination of data and availability ids is not allowed*/
            *IdType = DCM_OBD_INVALID_ID;
        }
    }
    else
    {
        if(  (DCM_OBD_NO_ID == *IdType)
           ||(DCM_OBD_DATA_ID == *IdType))
        {
            *IdType = DCM_OBD_DATA_ID;
        }
        else
        {
            /* combination of data and availability ids is not allowed*/
            *IdType = DCM_OBD_INVALID_ID;
        }
    }
    return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

/*
*! Helper funciton to assemble obd response
*
* \name Dcm_ObdHandleResponse
*
* \b Sync/Async:   Synchronous
*
* \b Reentrancy:   Reentrant
*
* \param (Input)   CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext
*                  Dcm_NegativeResponseCodeType ResponseCode
*                  uint16 MessageLength 
*
* \b Description:  Helper funciton to assemble obd response
*/
#if ((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))
#define DCM_START_SEC_CODE
#include "MemMap.h"
static FUNC(void,DCM_CODE) Dcm_ObdHandleResponse(CONSTP2VAR(Dcm_MsgContextType,AUTOMATIC,DCM_APPL_DATA) pMsgContext,
                                                 Dcm_NegativeResponseCodeType ResponseCode,
                                                 uint16 MessageLength)
{
    
    
    if (DCM_E_OK != ResponseCode)
    {
        Dcm_HandleNegResponse(pMsgContext,ResponseCode);
    }
    else if( 0x00 == MessageLength )
    {
        Dcm_HandleNegResponse(pMsgContext,DCM_E_REQUESTOUTOFRANGE);
    }
    else 
    {
#if (DCM_PAGEDBUFFER_ENABLED==STD_ON)
        if (!Dcm_PagedBufferService)
        {
            pMsgContext->resDataLen=MessageLength;
            Dcm_ProcessingDone(pMsgContext);
        }
        else
        {
            Dcm_PagedBufferService=0; /*end PagedBuffer processing*/
        }
#else
        pMsgContext->resDataLen=MessageLength;
        Dcm_ProcessingDone(pMsgContext);
#endif
    }
    return;
}
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*((defined DCM_OBD_DEM_SUPPORT)&&(DCM_OBD_DEM_SUPPORT == STD_ON))*/

#undef DCM_AR_EXTERN

#undef __DSP_C__


