/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : ApplCallbacks.h
* Module Description: Application defined Callback functions
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          18 %
* %derived_by:       pzswj8 %
* %date_modified:    Wed Nov 20 13:43:36 2013 % 
*---------------------------------------------------------------------------*/
#ifndef APPLCALLBACKS_H
#define APPLCALLBACKS_H


typedef struct
{
  UInt16 R_BEMFCal_Rev_u0p16;
  UInt16 Sin1Offset_Volts_u3p13;
  UInt16 Sin1AmpRec_Uls_u3p13;
  UInt16 Cos1Offset_Volts_u3p13;
  UInt16 Cos1AmpRec_Uls_u3p13;
  SInt16 SinDelta1_Uls_s2p13;
  UInt16 CosDelta1Rec_Uls_u3p13;
  UInt16 Sin2Offset_Volts_u3p13;
  UInt16 Sin2AmpRec_Uls_u3p13;
  UInt16 Cos2Offset_Volts_u3p13;
  UInt16 Cos2AmpRec_Uls_u3p13;
  SInt16 SinDelta2_Uls_s2p13;
  UInt16 CosDelta2Rec_Uls_u3p13;
  SInt16 Sin1OffCorr_Volts_s2p13;
  UInt16 Sin1GainCorr_Uls_u1p15;
  SInt16 Cos1OffCorr_Volts_s2p13;
  UInt16 Cos1GainCorr_Uls_u1p15;
  DT_Array144_s8 SinHarTbl_Cnt_sm6p13;
  DT_Array144_s8 CosHarTbl_Cnt_sm6p13;
} MtrPosCalDeprecated_DataType;

/* START CHANGES FOR DEPRECATED TORQUE SCALE FACTOR FIXED TO FLOAT TRANSITION */
typedef struct
{
  float HwTrqScale_VoltsPerDeg_f32;
  uint16 HwTrqScaleStatus_Cnt_u16;
  uint16 padding;					/* This padding parameter accounts for an over allocated EA block, this padding might be unecessary, but is added as a precaution */
} HwTrqScaleDeprecated_Datatype;

typedef struct
{
  float HwTrqTrim_Volts_f32;
  float T1Trim_Volts_f32;
  float T2Trim_Volts_f32;
  uint16 HwTrqTrimStatus_Cnt_u16;
  uint16 padding;					/* This padding parameter accounts for an over allocated EA block, this padding might be unecessary, but is added as a precaution */
} HwTrqTrimDeprecated_Datatype;

typedef struct
{
  boolean LTVehCntrComplete;
  uint8 R_LTVehCntrComplete;
} LTVehCntrDeprecated_DataType;

typedef struct
{
  uint16 RacktoVehCntrOffset;
  uint16 R_RacktoVehCntrOffset;
} RacktoVehCntrDerecated_DataType;

typedef struct
{
  float32 VehCntrOffset;
  uint32 R_VehCntrOffset;
} VehCntrOffsetDeprecated_DataType;


typedef struct
{
   uint8 HWESgbmId[8u];
   uint8 HWEDevelopmentInfo[15u];
} HweTableDeprecated_Type;


typedef struct
{
   /* HardwareLogisticData                                                    */
	HweTableDeprecated_Type HweTable[1u];
   /* ECUSerialNumber                                                         */
   uint8 ECUSerialNumber[10u];
   /* ECUManufacturingData                                                    */
   uint8 ECUManufacturingData[3u];
} HwDescDataDeprecated_Type;

typedef struct
{
	uint8 Data[66u]; /* Size of the data is the size of the deprecated memory block. Note: that really the data is not in a struct, but just an array (unless you are looking at SVK_HISTORY) */
} SvkSysSuppDeprecated_Type;

typedef struct
{
	uint8 Data[66u]; /* Size of the data is the size of the deprecated memory block. Note: that really the data is not in a struct, but just an array (unless you are looking at SVK_HISTORY) */
} SvkPlantDeprecated_Type;

/* The NvM Generator produces Rte_Call style definitions for blocks which are configured to provide service ports
 * The correct use of these functions through the Rte is not understood at this time because the Rte is not 
 * initialized while the NvM Read All occurs.  For the time being the macros are being defined here to map the NvM
 * init call backs to the appropriate function provided by this module.
 */ 
#define  Rte_Call_Nvm_RpNotifyInit__Rte_NvmBlock_LrnEOT_LearnedEOT_InitBlock					Ap_CB_InitLearnedEOT
#define  Rte_Call_NvM_RpNotifyJobEnd_Rte_NvmBlock_LrnEOT_LearnedEOT_JobFinished					Ap_CB_NtfyJobEndLearnedEOT
#define  Rte_Call_NvM_RpNotifyJobEnd_Rte_NvmBlock_AbsHwPos_Trim_JobFinished                     Ap_CB_NtfyJobEndAbsHwPosTrim

/* Depecreated block RAM buffers */
extern VAR(MtrPosCalDeprecated_DataType, AUTOMATIC) Deprecated_MtrPos_MtrPosSnsr_EOLData;
extern VAR(uint16, AUTOMATIC) Deprecated_MtrTrqLmt_EOLTrqCmdSclFac_Uls_u7p9;
extern VAR(HwTrqScaleDeprecated_Datatype, AUTOMATIC) Deprecated_HwTrq_HwTrqScaleData;
extern VAR(HwTrqTrimDeprecated_Datatype, AUTOMATIC) Deprecated_HwTrq_HwTrqTrimData;
extern VAR(EOTLearned_DataType, AUTOMATIC) Deprecated_FinalHwPos_LearnedEOT;
extern VAR(boolean, AUTOMATIC) Deprecated_AbsHwPos_LTVehCntrComplete;
extern VAR(sint16, AUTOMATIC) Deprecated_AbsHwPos_RacktoVehCntrOffset;
extern VAR(float32, AUTOMATIC) Deprecated_AbsHwPos_VehCntrOffset;
extern VAR(LTVehCntrDeprecated_DataType, AUTOMATIC) Deprecated_AbsHwPos_LTVehCntrComplete_RC;
extern VAR(RacktoVehCntrDerecated_DataType, AUTOMATIC) Deprecated_AbsHwPos_RacktoVehCntrOffset_RC;
extern VAR(VehCntrOffsetDeprecated_DataType, AUTOMATIC) Deprecated_AbsHwPos_VehCntrOffset_RC;
extern VAR(HwDescDataDeprecated_Type, AUTOMATIC) Deprecated_HwDescData;
extern VAR(SvkSysSuppDeprecated_Type, AUTOMATIC) Deprecated_SVK_SYS_SUPP;
extern VAR(SvkPlantDeprecated_Type, AUTOMATIC) Deprecated_SVK_PLANT;

/* Invalid block initialization call back functions */
/* Initial Init Callback to queue the read fo the deprecated block data */
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitMtrPosSnsrEOLData(void);
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitTorqueCmdSF(void);
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitHwTrqScaleData(void);
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitHwTrqTrimData(void);
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitLearnedEOT(void);
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitAbsHwPosTrim(void);
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitHwDescData(void);
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitSvkSysSupp(void);
extern FUNC(void, APPLCALLBACKS_APPL_CODE) Ap_CB_InitSvkPlant(void);

/* Secondary JobEnd notification Callback to finish the required deprecated block data processing */
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndMtrPosSnsrEOLDataDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndTrqCmdSclDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndHwTrqScaleDataDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndHwTrqTrimDataDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndLearnedEOTDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndVehCntrOffsetRCDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndVehCntrOffsetDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndHwDescDataDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndSvkSysSuppDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndSvkPlantDeprc( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );

/* Block job end notifications */
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndLearnedEOT( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndMtrPosSnsrEOLData( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndTorqueCmdSF( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndHwTrqScaleData( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndHwTrqTrimData( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndAbsHwPosTrim( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );
extern FUNC(Std_ReturnType, APPLCALLBACKS_APPL_CODE) Ap_CB_NtfyJobEndHwDescData( NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult );

#define D_PERFORMEDDEPRECATED_CNT_U16 		0xAAAAU
#define D_NOTPERFORMEDDEPRECATED_CNT_U16 	0x5555U
#define D_PERFORMEDDEPRECATEDBOOL_CNT_U16	0x0001U
/* END CHANGES FOR DEPRECATED TORQUE SCALE FACTOR FIXED TO FLOAT TRANSITION */

extern boolean Appl_WaitNvMReady(const uint16 blockNumber, const boolean fastMode);
extern void SchM_SyncTasks(void);
extern void SystemTick(void);

extern FUNC(void, AUTOMATIC) StaMd_Init0(void);
extern FUNC(void, AUTOMATIC) TWrapC_StaMd_Init0(void);


#endif /*APPLCALLBACKS_H*/
