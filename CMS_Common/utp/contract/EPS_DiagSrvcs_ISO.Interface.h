/**********************************************************************************************************************\
* This file has been modified to enable all services and parameters in CMS Common.  Use this file as reference only    *
* as many definitions, functions and variables either do not exist or exist across many programs.  The content is      *
* an amalgamation of many programs into a single file.  Again,                                                         *
*                                                                                                                      *
*                                                                                                                      *
*                                                                                                                      *
*                                                                                                                      *
*                                                                                                                      *
*                               THIS FILE IS FOR QAC TESTING PURPOSES ONLY.                                            *
*                                DO NOT EVEN USE THIS FILE FOR REFERENCE.                                              *
*                                                                                                                      *
*                                                                                                                      *
*                                                                                                                      *
*                                                                                                                      *
*                                                                                                                      *
\**********************************************************************************************************************/
#include "EPS_DiagSrvcs_CommonData.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"
#include "desc.h"                   /* Required for interfacing with the CAN transport layer */
#include "Dem_Cfg.h"
#include "Dem_Types.h"
#include "Lnk_Symbols.h"
#include "Ap_DiagMgr.h"
#include "omc.h"
#include "Cd_TcFlshPrg.h"           /*provide Turns Counter Flash Traceability ID defs */

#ifndef EPS_DIAGSRVCS_ISO_INTERFACE_H
#define EPS_DIAGSRVCS_ISO_INTERFACE_H

/* --- Common Defines --- */
#define CM_DIAGBUFFLEN_CNT_U16                      kDescPrimBufferLen
#define NXTR_SESSION                             0x7Eu
#define CM_SetNegResp(a)                            DescSetNegResponse(0,a)
#define CM_NumHeaderBytes_Cnt_u16                   2u
#define CM_NumRIDHeaderBytes_Cnt_u16                3u
#define CM_NumLIDHeaderBytes_Cnt_u16                CDD_DiagSrvcsUnusedVar_Cnt_M_u16
#define CM_MsgBufferType                            DescMsg
#define CM_MsgLenType                               DescMsgLen
#define CM_Std_ReturnType                           Std_ReturnType
#define CM_RESP_OK                                  RTE_E_OK
#define CM_NULL                                     NULL

/* offsets for the data buffers for diag request/responses */
#define D_REQMSG_PID_OFFSET_CNT_U16         2U
#define D_REQMSG_RID_OFFSET_CNT_U16         3U
#define D_REQMSG_IOC_OFFSET_CNT_U16         2U
#define D_REQMSG_RESET_OFFSET_CNT_U16       0U
#define D_RESPMSG_OFFSET_CNT_U16            0U

#define D_RETURNDATA_OFFSET_CNT_U16         0U  /* This index to offset the data that is WRITTEN to the diagnostic buffer..typically done in read operations */
#define D_REQUESTDATA_OFFSET_CNT_U16            0U  /* This index to offset the data that is READ from the diagnostic buffer..typically done in write operations */


#define D_EPSNRCNOTNXTRPROD_CNT_U08 D_EPSNRCREQOUTOFRANGE_CNT_U08
#define D_EPSNRCSERVICEMISSING_CNT_U08 D_EPSNRCREQOUTOFRANGE_CNT_U08

#define CM_GetCurrentDiagnosticMode(m) (*(m)=NXTR_SESSION)

/* -----[ Type Definitions Typically Defined Elsewhere ]------------------------------------------------------------- */
typedef enum {
    NotActivated        =   0,
    EnterPrgMode        =   1,
    SendKey             =   2,
    BulkErase           =   3,
    ConfigWords1        =   4,
    ConfigWords2        =   5,
    PrgMemBlock1        =   6,
    PrgMemBlockSeq      =   7,
    VerifyPrgMem        =   8,
    PrgCompletePass     =   9,
    PrgCompleteFail     =   10
} CM_TcFlshPrgMode_T;

/* The follow structure was added for QAC purposes only and contains extra parameters.  For reference ONLY */
typedef struct {
    uint16 DcShiftTbl_Cnt_u6p10[2];
    uint16 SinHarMagTbl_Cnt_u6p10[3];
    uint16 CosHarMagTbl_Cnt_u6p10[3];
    sint16 SinHarAngTbl_Cnt_s0p15[3];
    sint16 CosHarAngTbl_Cnt_s0p15[3];
    sint16 SinDeltaRel_Uls_s0p15;
    sint16 InvCosDeltRel_Uls_s1p14;
    uint16 RelPeakAdj_Uls_u1p15;
    sint16 EOLRelAbsAlign_HwDeg_s11p4;
    uint16 EOLP1HarMag1_Volt_u6p10;
    uint16 EOLHwPosTrmPerf_Cnt_u16;
    sint16 HwPosRelTrim_HwDeg_s11p4;
} CM_HwPosRelCal_DataType;

/* The follow structure was added for QAC purposes only and contains extra parameters.  For reference ONLY */
typedef struct {
    uint16 BEMFCal_Rev_u0p16;
    uint16 Sin1Offset_Volts_u3p13;
    uint16 Sin1AmpRec_Uls_u3p13;
    uint16 Cos1Offset_Volts_u3p13;
    uint16 Cos1AmpRec_Uls_u3p13;
    sint16 SinDelta1_Uls_s2p13;
    uint16 CosDelta1Rec_Uls_u3p13;
    uint16 Sin2Offset_Volts_u3p13;
    uint16 Sin2AmpRec_Uls_u3p13;
    uint16 Cos2Offset_Volts_u3p13;
    uint16 Cos2AmpRec_Uls_u3p13;
    sint16 SinDelta2_Uls_s2p13;
    uint16 CosDelta2Rec_Uls_u3p13;
    sint16 Sin1OffCorr_Volts_s2p13;
    uint16 Sin1GainCorr_Uls_u1p15;
    sint16 Cos1OffCorr_Volts_s2p13;
    uint16 Cos1GainCorr_Uls_u1p15;
    sint16 SinHarTbl_Cnt_sm6p13[144];
    sint16 CosHarTbl_Cnt_sm6p13[144];
} CM_MtrPosCal_DataType;

/* The follow structure was added for QAC purposes only and contains extra parameters.  For reference ONLY */
typedef struct {
    float32 EOLMtrCurrVcalCmd_VoltCnts_f32;
    uint16 EOLMtrCurr1Gain_AmpspVolt_u7p9;
    float32 EOLPhscurr1Gain_AmpspVolt_f32;
    uint16 EOLMtrCurr2Gain_AmpspVolt_u7p9;
    float32 EOLPhscurr2Gain_AmpspVolt_f32;
    uint16 EOLMtrCurr1Offset_Volts_u3p13;
    float32 EOLMtrCurr1OffsetLo_Volts_f32;
    uint16 EOLMtrCurr2Offset_Volts_u3p13;
    float32 EOLMtrCurr2OffsetLo_Volts_f32;
    float32 EOLMtrCurr1OffsetDiff_Volts_f32;
    float32 EOLMtrCurr2OffsetDiff_Volts_f32;
} CM_PhaseCurrCal_DataType;

typedef uint16 CM_IPMCoggingCancTrq[256];

typedef struct
{
  Float HwTrqScale_VoltsPerDeg_f32;
  Boolean HwTrqScalePerf_Cnt_lgc;
} CM_HwTrqScale_Datatype;

typedef struct
{
    Float HwTrqTrim_Volts_f32;
    Float T1Trim_Volts_f32;
    Float T2Trim_Volts_f32;
    Boolean HwTrqTrimPerf_Cnt_lgc;
} CM_HwTrqTrim_Datatype;


/* -----[ External Variables ]--------------------------------------------------------------------------------------- */
extern VAR(Float, AUTOMATIC) CM_HwTrq_HwNm_f32;
extern VAR(Float, AUTOMATIC) CM_VehicleSpeed_Kph_f32;
extern VAR(Float, AUTOMATIC) CM_Rte_IoHwAbstractionUsr_T1ADC_Volt_f32;
extern VAR(Float, AUTOMATIC) CM_Rte_IoHwAbstractionUsr_T2ADC_Volt_f32;
extern VAR(EnergyModeStateType, AUTOMATIC) CM_Rte_VehCfg_EnergyModeState_Cnt_enum;
extern VAR(boolean, AUTOMATIC) CM_DiagStsDefVehSpd_Cnt_lgc;
extern VAR(float32, AUTOMATIC) CM_SrlComHwPos_HwDeg_f32;
extern VAR(float32, AUTOMATIC) CM_Rte_AbsHwPos_SrlComHwPos_HwDeg_f32;
extern VAR(float32, AUTOMATIC) CM_HandwheelAuthority_Uls_f32;
extern VAR(float32, AUTOMATIC) CM_AlignedHwPos_HwDeg_f32;
extern VAR(boolean, AUTOMATIC) CM_VehSpdValid_Cnt_lgc;
extern VAR(boolean, AUTOMATIC) CDD_GenPosTrajEnableFlag_Cnt_G_lgc;
extern volatile CONST(boolean, AUTOMATIC) CM_EnableTestMode_Cnt_lgc;
extern VAR(float32, AUTOMATIC) CM_Rte_Sa_DigHwTrqSENT_HwTorque_HwNm_f32;
extern VAR(float32, AUTOMATIC) CM_Rte_Cd_Nhet1_DigHwTrqT1_HwNm_f32;
extern VAR(float32, AUTOMATIC) CM_Rte_Cd_Nhet1_DigHwTrqT2_HwNm_f32;
extern VAR(uint16, AUTOMATIC) CM_WIRSel_Cnt_u16;
extern VAR(float32, AUTOMATIC) CM_MtrTrqCmd_MtrNm_f32;
extern VAR(float32, AUTOMATIC) CM_CumMtrPos_Deg_f32;
extern VAR(Rte_ModeType_StaMd_Mode, ATOMATIC) CM_SystemState_Cnt_enum;
extern VAR(boolean, AUTOMATIC) CM_MfgDiagInhibit_Cnt_lgc;



#define CM_k_TrimVehSpdLimit_Kph_f32    k_SrvcVehSpdLimit_Kph_f32
#define CM_k_TrimHwTrqLimit_HwNm_f32    k_SrvcHwTrqLimit_HwNm_f32


/* -----[ External Functions ]--------------------------------------------------------------------------------------- */
extern FUNC(void, AUTOMATIC) CM_MtrPos_SCom_ReadEOLMtrCals(P2VAR(CM_MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);
extern FUNC(void, AUTOMATIC) CM_MtrPos_SCom_SetEOLMtrCals(P2VAR(CM_MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_VAR) MtrCalDataPtr);
extern FUNC(void, AUTOMATIC) CM_Call_MtrPos_SCom_SetEOLMtrCals(P2CONST(CM_MtrPosCal_DataType, AUTOMATIC, RTE_SA_MTRPOS_APPL_DATA) MtrCalDataPtr);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_Call_HwTrq_SCom_ManualSetHwTrqTrim(P2CONST(CM_HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_DATA) HwTrqTrimDataPtr);
extern FUNC(void, AUTOMATIC) CM_HwTrq_SCom_ReadHwTrqTrim(P2VAR(CM_HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqTrimDatPtr);
extern FUNC(void, AUTOMATIC) CM_Polarity_SCom_ReadPolarity(P2VAR(UInt16, AUTOMATIC, RTE_AP_POLARITY_APPL_VAR) Polarity_Cnt_b16);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_Call_Polarity_SCom_SetPolarity(UInt16 Polarity_Cnt_b16);
extern FUNC(void, AUTOMATIC) CM_HwTrq_SCom_ReadHwTrqScale(P2VAR(CM_HwTrqScale_Datatype, AUTOMATIC, RTE_SA_HWTRQ_APPL_VAR) HwTrqScaleDataPtr);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_HwTrq_SCom_SetHwTrqScale(Float ScaleValue);
extern FUNC(void, AUTOMATIC) CM_SCom_EOLNomMtrParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomL_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32);
extern FUNC(void, AUTOMATIC) CM_SCom_EOLNomMtrParam_Set(Float NomKe_VpRadpS_f32, Float NomL_Henry_f32, Float NomRmtr_Ohm_f32);
extern FUNC(void, AUTOMATIC) CM_SCom_EOLNomMtrParam_Get_FDB4(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomKe_VpRadpS_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomL_Henry_f32, P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) NomRmtr_Ohm_f32, P2VAR(Float, AUTOMATIC, AUTOMATIC) NomLd_Henry_T_f32);
extern FUNC(void, AUTOMATIC) CM_SCom_EOLNomMtrParam_Set_FDB4(Float NomKe_VpRadpS_f32, Float NomL_Henry_f32, Float NomRmtr_Ohm_f32, Float NomLd_Henry_T_f32);
extern FUNC(void, AUTOMATIC) CM_DiagMgr_SCom_GetNTCInfo(VAR(NTCNumber, AUTOMATIC) NTC_Cnt_T_enum, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Param_Ptr_T_u08, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Status_Ptr_T_u08, P2VAR(uint8, AUTOMATIC, AUTOMATIC) AgingCounter_Ptr_T_u08);
extern FUNC(void, AUTOMATIC) CM_Reset_ClearNTCs_SComm(void);
extern FUNC(void, AUTOMATIC) CM_DiagMgr_SCom_ReadStrgArray(void);
extern FUNC(void, AUTOMATIC) CM_DiagMgr_SCom_ClearBlackBox(void);
extern FUNC(void, AUTOMATIC) CM_DigHwTrq_SCom_ReadHwTrqTrim(P2VAR(CM_HwTrqTrim_Datatype, RTE_SA_DIGHWTRQ_APPL_VAR, RTE_SA_DIGHWTRQ_APPL_VAR) HwTrqTrimDatPtr);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_DigHwTrq_SCom_SetHwTrqTrim(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_DigHwTrq_SCom_ManualSetHwTrqTrim(P2CONST(CM_HwTrqTrim_Datatype, AUTOMATIC, RTE_SA_DIGHWTRQ_APPL_DATA) HwTrqTrimDataPtr);
extern FUNC(void, AUTOMATIC) CM_DigHwTrq_SCom_ReadHwTrqScale(P2VAR(CM_HwTrqScale_Datatype, RTE_SA_DIGHWTRQ_APPL_VAR, RTE_SA_DIGHWTRQ_APPL_VAR) HwTrqScaleDataPtr);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_DigHwTrq_SCom_SetHwTrqScale(Float ScaleValue);
extern FUNC(void, AUTOMATIC) CM_ManualVehSpd_SCom(Float VehSpd_Kph_f32);
extern FUNC(void, AUTOMATIC) CM_SCom_KeIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) KeIntgSV_Amp_f32);
extern FUNC(void, AUTOMATIC) CM_SCom_KeIntgSVParam_Set(Float KeIntgSV_Amp_f32);
extern FUNC(void, AUTOMATIC) CM_SCom_RIntgSVParam_Get(P2VAR(Float, AUTOMATIC, RTE_AP_PARAMCOMP_APPL_VAR) RIntgSV_Amp_f32);
extern FUNC(void, AUTOMATIC) CM_SCom_RIntgSVParam_Set(Float RIntgSV_Amp_f32);
extern FUNC(void, AUTOMATIC) CM_TrqCmdScl_SCom_Get(P2VAR(Float, AUTOMATIC, RTE_AP_TRQCMDSCL_APPL_VAR) Par_f32);
extern FUNC(void, AUTOMATIC) CM_TrqCmdScl_SCom_Set(Float Par_f32);
extern FUNC(void, AUTOMATIC) CM_MtrCurr_SCom_ReadMtrCurrCals(P2VAR(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_VAR) ShCurrCalPtr);
extern FUNC(void, AUTOMATIC) CM_MtrCurr_SCom_SetMtrCurrCals(P2CONST(ShCurrCal_DataType, AUTOMATIC, RTE_SA_MTRCURR_APPL_DATA) ShCurrCalPtr);
extern FUNC(void, AUTOMATIC) CM_ActivePull_SCom_ReadParam(P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) PullCompCmd_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) STComp_HwNm_f32, P2VAR(Float, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) LTComp_HwNm_f32, P2VAR(Boolean, AUTOMATIC, RTE_AP_ACTIVEPULL_APPL_VAR) EnableLearn_Cnt_lgc);
extern FUNC(void, AUTOMATIC) CM_ActivePull_SCom_SetSTComp(Float STComp_HwNm_f32);
extern FUNC(void, AUTOMATIC) CM_Reset_ActivePull_SCom_SetLTComp(Float LTComp_HwNm_f32);
extern FUNC(void, AUTOMATIC) CM_AvgFricLrn_SCom_InitLearnedTables(void);
extern FUNC(void, AUTOMATIC) CM_AvgFricLrn_SCom_ResetToZero(void);
extern FUNC(void, AUTOMATIC) CM_LTLVehSpdCntr_Scom_ResetToZero(void);
extern FUNC(void, AUTOMATIC) CM_Reset_SLP_SCom_SetSLPToInvld(void);
extern FUNC(void, AUTOMATIC) CM_AvgFricLrn_SCom_SetEOLFric(Float EOLFric_HwNm_f32);
extern FUNC(void, AUTOMATIC) CM_AvgFricLrn_SCom_GetEOLFric(P2VAR(Float, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EOLFric_HwNm_f32);
extern FUNC(void, AUTOMATIC) CM_AvgFricLrn_SCom_SetOffsetOutputDefeat(Boolean DefeatOffsetOutput_Cnt_lgc);
extern FUNC(void, AUTOMATIC) CM_AvgFricLrn_SCom_GetOffsetOutputDefeat(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) DefeatOffsetOutput_Cnt_lgc);
extern FUNC(void, AUTOMATIC) CM_AvgFricLrn_SCom_SetSelect(Boolean EnableFricLearning_Cnt_lgc, Boolean EnableOffsetOutput_Cnt_lgc, UInt8 OpMode_Uls_u08);
extern FUNC(void, AUTOMATIC) CM_AvgFricLrn_SCom_GetSelect(P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableFricLearning_Cnt_lgc, P2VAR(Boolean, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) EnableOffsetOutput_Cnt_lgc, P2VAR(UInt8, AUTOMATIC, RTE_AP_AVGFRICLRN_APPL_VAR) OpMode_Uls_u08);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_WdgM_CheckpointReached( VAR (WdgM_SupervisedEntityIdType, AUTOMATIC) SEID, VAR (WdgM_CheckpointIdType, AUTOMATIC) CPID);
extern FUNC(void, AUTOMATIC) CM_EnableSysTickInterrupt(void);
extern FUNC(void, AUTOMATIC) CM_DisableSysTickInterrupt(void);
extern FUNC(void, AUTOMATIC) CM_GetAlarm(VAR(uint16, AUTOMATIC) AlarmID_Cnt_T_u08, P2VAR(uint32, AUTOMATIC, AUTOMATIC) TicksToExpire_Cnt_T_u32);
extern FUNC(void, AUTOMATIC) CM_SetRelAlarm(VAR(uint16, AUTOMATIC) AlarmID_Cnt_T_u08, VAR(uint32, AUTOMATIC) TicksToDelay_Cnt_T_u16, VAR(uint32, AUTOMATIC) CycleTime_Cnt_T_u16);
extern FUNC(void, AUTOMATIC) CM_CancelAlarm(VAR(uint16, AUTOMATIC) AlarmID_Cnt_T_u08);
extern FUNC(void, AUTOMATIC) CM_ProcessF0FF(P2VAR(uint8, AUTOMATIC, AUTOMATIC) t_SrvcData_Cnt_T_u08, VAR(uint16, AUTOMATIC) ReadDataIdx_Cnt_T_u16);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_Vsm_Scom_SetOperatingMode (Vsm_OperatingModeType mode);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_TcEOLCals_Scom_SetTcEOLCals(UInt8 TcEolSineOffset_Cnt_P_u8, UInt8 TcEolCosineOffset_Cnt_P_u8, UInt8 TcEolSin2CosGain_Cnt_P_u8, UInt8 TcEolSinVsCosMin_Cnt_P_u8, UInt8 TcEolSinVsCosMax_Cnt_P_u8, UInt8 TcEolCalChksm_Cnt_P_u8);
extern FUNC(void, AUTOMATIC) CM_TcEOLCals_Scom_ReadTcEOLCals(P2VAR(EOLTurnsCntrCals_Datatype, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcEOLCalsPtr);
extern FUNC(void, AUTOMATIC) CM_TurnsCounter_Scom_PartNumSvc(P2VAR(TcPartNumType, AUTOMATIC, RTE_CD_TURNSCOUNTER_APPL_VAR) TcPrgStatePtr);
extern FUNC(void, AUTOMATIC) CM_AbsHwPos_Scom_ClearCenterPosition(void);
extern FUNC(void, AUTOMATIC) CM_AbsHwPos_Scom_ClearRacktoVehCntrOffset(void);
extern FUNC(void, AUTOMATIC) CM_Reset_LrnEOT_Scom_ResetEOT(void);
extern FUNC(void, AUTOMATIC) CM_LrnEOT_Scom_ResetRckCntrPrf(void);
extern FUNC(void, AUTOMATIC) CM_TurnsCounter_SCom_ResetTC(void);
extern FUNC(void, AUTOMATIC) CM_AbsHwPos_Scom_SetCenterPosition(VAR(float32, AUTOMATIC) RelOff_Deg_T_f32);
extern FUNC(Dem_ReturnClearDTCType, AUTOMATIC) CM_Reset_ClearCustDTCs_SComm(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_HwTrq_SCom_SetHwTrqTrim(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_HwTrq_SCom_ClrHwTrqTrim(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_HwTrq_SCom_ClrHwTrqScale(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_DigHwTrq_SCom_ClrHwTrqScale(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_DigHwTrq_SCom_ClrHwTrqTrim(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_MtrCurr_SCom_CalGain(void);
extern FUNC(void, AUTOMATIC) CM_MtrCurr_SCom_CalOffset(void);
extern FUNC(void, AUTOMATIC) CM_TcEOLCals_Scom_ClearTcEOLCals(void);
extern FUNC(void, AUTOMATIC) CM_GenPosTraj_SCom_SetInputParam(Float PosServHwAngle_HwDeg_f32, Float TargetVelocity_HwDegpSec_f32, Float TargetAcceleration_HwDegpSecSqr_f32);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_HwPos_SCom_SetHwPosTrim(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_HwPos_SCom_ClrHwPosTrim(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_HwPos_SCom_LrnHwPosTrim(void);
extern FUNC(void, RTE_AP_ASSISTSUMNLMT_APPL_CODE) CM_MtrTrqLmt_SCom_ManualTrqCmd(Boolean EnableManualCtrl, Float MtrTrqCmd_MtrNm_f32);
extern FUNC(void, RTE_AP_STAMD_APPL_CODE) CM_StaMd_SCom_EcuReset(void);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_TcFlshPrg_Scom_StartPrg(void);
extern FUNC(void, AUTOMATIC) CM_TcFlshPrg_Scom_FlshPrgStatus(P2VAR(boolean, AUTOMATIC, AUTOMATIC) pTcFlashActive_Cnt_T_lgc, P2VAR(uint16, AUTOMATIC, AUTOMATIC) ptrTcDataCntr_Cnt_T_u16, P2VAR(CM_TcFlshPrgMode_T, AUTOMATIC, AUTOMATIC) ptrTcPrgState_Uls_T_enum);
extern FUNC(uint8, AUTOMATIC) CM_CmMtrCurr_SCom_CalGain(void);
extern FUNC(uint8, AUTOMATIC) CM_CmMtrCurr_SCom_CalOffset(void);
extern FUNC(void, AUTOMATIC) CM_CmMtrCurr_SCom_MtrCurrOffReadStatus(P2VAR(uint8, AUTOMATIC, AUTOMATIC) MtrcurrOffResult);
extern FUNC(void, AUTOMATIC) CM_HwPosRel_SCom_ReadHwPosCals(P2VAR(CM_HwPosRelCal_DataType, AUTOMATIC, AUTOMATIC) EOLHwPosPID);
extern FUNC(void, AUTOMATIC) CM_HwPosRel_SCom_SetHwPosCals(P2VAR(CM_HwPosRelCal_DataType, AUTOMATIC, AUTOMATIC) EOLHwPosPID);
extern FUNC(void, AUTOMATIC) CM_CmMtrCurr_SCom_SetMtrCurrCals(P2VAR(CM_PhaseCurrCal_DataType, AUTOMATIC, AUTOMATIC) EOLHwPosPID);
extern FUNC(void, AUTOMATIC) CM_CmMtrCurr_SCom_ReadMtrCurrCals(P2VAR(CM_PhaseCurrCal_DataType, AUTOMATIC, AUTOMATIC) EOLHwPosPID);
extern FUNC(void, AUTOMATIC) CM_AbsHwPos_SCom_VehicleSystemStatus(P2VAR(sint16, AUTOMATIC, AUTOMATIC) SrlComHwPos_HwDeg_T_s11p4);
extern FUNC(void, AUTOMATIC) CM_Return_SCom_GetEOLRtnRange(P2VAR(float32, AUTOMATIC, AUTOMATIC) Diagtemp_Uls_T_f32);
extern FUNC(void, AUTOMATIC) CM_Return_SCom_SetEOLRtnRange(VAR(float32, AUTOMATIC) Diagtemp_Uls_T_f32);
extern FUNC(void, AUTOMATIC) CM_IPMTrqCanc_Scom_SetCogTrqCal(P2CONST(CM_IPMCoggingCancTrq, AUTOMATIC, AUTOMATIC) IPMCoggingTrqValues, VAR(uint16, AUTOMATIC) Offset_Cnt_T_u16);
extern FUNC(void, AUTOMATIC) CM_IPMTrqCanc_Scom_ReadCogTrqCal(P2VAR(CM_IPMCoggingCancTrq, AUTOMATIC, AUTOMATIC) IPMCoggingTrqValues, VAR(uint16, AUTOMATIC) Offset_Cnt_T_u16);
extern FUNC(void, AUTOMATIC) CM_ClearNTCs_SComm(void);
extern FUNC(void, AUTOMATIC) CM_ClearCustDTCs_SComm(VAR(uint32, AUTOMATIC), VAR(uint8, AUTOMATIC), VAR(uint16, AUTOMATIC));
extern FUNC(void, AUTOMATIC) CM_LrnEOT_Scom_ResetEOT(void);
extern FUNC(void, AUTOMATIC) CM_HwTrq_SCom_ManualSetHwTrqTrim(P2VAR(CM_HwTrqTrim_Datatype, AUTOMATIC, AUTOMATIC) HwTrqTrimData);
extern FUNC(Std_ReturnType, AUTOMATIC) CM_Polarity_SCom_SetPolarity(VAR(uint16, AUTOMATIC) Polarity_Cnt_T_b16);
extern FUNC(void, AUTOMATIC) DigHwTrq_SCom_ReadHwTrqScale(P2VAR(CM_HwTrqScale_Datatype, AUTOMATIC, AUTOMATIC) HwTrqScale_T_str);
extern FUNC(void, AUTOMATIC) CM_AbsHwPosScom_Scom_HwPosSrvRead(P2VAR(boolean, AUTOMATIC, AUTOMATIC) HwPosDft_Cnt_T_lgc);
extern FUNC(void, AUTOMATIC) CM_BatteryVoltage_SCom_ReadTransOvData(P2VAR(uint16, AUTOMATIC, AUTOMATIC) OvervoltageCounter_Cnt_T_u16, P2VAR(float32, AUTOMATIC, AUTOMATIC) MaxBatteryVoltage_Volts_T_f32);
extern FUNC(void, AUTOMaTIC) CM_BatteryVoltage_SCom_ClearTransOvData(void);
extern FUNC(void, AUTOMATIC) CM_ActivePull_SCom_SetLTComp(VAR(float32, AUTOMATIC) FloatData_f32);
extern FUNC(void, AUTOMATIC) CM_AbsHwPosScom_Scom_HwPosSrvSetToZero(VAR(boolean, AUTOMATIC) HwPosDft_Cnt_T_lgc);
extern FUNC(void, AUTOMATIC) CM_DigHwTrqSENT_SCom_ReadTrim(P2VAR(float32, AUTOMATIC, AUTOMATIC) HwTrqTrim_HwNm_T_f32, P2VAR(boolean, AUTOMATIC, AUTOMATIC) HwTrqTrimPerformed_Cnt_T_lgc);
extern FUNC(void, AUTOMATIC) CM_DigHwTrqSENT_SCom_WriteTrim(VAR(float32, AUTOMATIC) HwTrqTrim_HwNm_T_f32);
extern FUNC(void, CD_TFLSHPRG_APPL_CODE) CM_TcFlshPrg_Scom_TcFlashTraceability(P2VAR(CM_TcFlshTraceabilityType, AUTOMATIC, AUTOMATIC) TcFlshTraceabilityData);

#define D_EPSDIAGSRVPID0000_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0001_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0002_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0003_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0004_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0005_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0006_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0007_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0008_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0009_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000A_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000B_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000C_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000D_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000E_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP000F_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0010_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0011_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0012_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0013_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0014_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0015_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0016_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0017_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0018_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0019_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001A_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001B_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001C_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001D_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001E_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP001F_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0020_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0021_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0022_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0023_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0024_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0025_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0026_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0027_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0028_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0029_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002A_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002B_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002C_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002D_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002E_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP002F_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0030_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0031_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0032_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0033_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0034_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0035_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0036_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0037_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0038_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0039_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003A_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003B_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP003C_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0100_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0101_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0102_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0103_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0104_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0105_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0106_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0107_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0108_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP0109_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP010A_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVXCP010B_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRESET1160_CNT_ENUM D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF000_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF001_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF002_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF003_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF004_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF005_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF006_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF007_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF008_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF009_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00A_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00B_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00C_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00D_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00E_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF00F_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVRIDF0FF_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD01_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD02_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD03_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD04_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD05_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD06_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD07_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD08_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD09_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0A_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0B_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0C_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVIOCFD0D_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0E_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD0F_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD10_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVIOCFD11_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD12_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD13_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD14_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD15_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD16_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD17_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD18_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD19_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1A_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1B_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1C_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1D_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1E_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD1F_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD20_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD21_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD22_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD23_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD24_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD25_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD26_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD27_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD28_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD29_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD30_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD31_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFD41_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA0_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA1_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA2_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA3_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA4_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA5_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA7_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA8_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDA9_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAC_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAD_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAE_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDAF_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB0_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB1_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB2_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB3_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB4_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB5_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB6_CNT_ENUM   D_DIAGSRVC_ENABLED
#define D_EPSDIAGSRVPIDFDB7_CNT_ENUM   D_DIAGSRVC_ENABLED


/* -----[ Defines For RESET: 1160 ]------------------------------------------------------------------------------------ */
#define D_EPSRESET_ECURESET                     0x60U

/* -----[ Defines For RID: F000 ]------------------------------------------------------------------------------------ */
#include "Dem_Cfg.h"
#include "Dem_Types.h"

#define CM_RTE_MODE_StaMd_Mode_OPERATE          RTE_MODE_StaMd_Mode_OPERATE

/* Number of used bits in the control bytes (used to limit loop processing) */
#define D_RIDF000_BITLIMIT_CNT_U8                   13u
#define D_F000NMEC_CNT_LGC                          TRUE
#define D_F000IGNCNTR_CNT_LGC                       TRUE
#define D_F000LTLVEHSPDCNTR_CNT_LGC                 TRUE
#define D_F000STOREDLASTPOSINVALD_CNT_LGC           TRUE
#define D_F000TACHGAIN_CNT_LGC                      TRUE
#define D_F000SNSRLESSSTOREDLASTPOSINVALID_CNT_LGC  TRUE
#define D_F000LEARNEDEOT_CNT_LGC                    TRUE
#define D_F000ACTIVEPULLCOMP_CNT_LGC                TRUE
#define D_F000NXTRDTCTBL_CNT_LGC                    TRUE
#define D_F000NXTRDTCBLACKBOX_CNT_LGC               TRUE
#define D_F000CUSTDTCTBL_CNT_LGC                    TRUE
#define D_F000FRICTIONDETECTPARAM_CNT_LGC           TRUE
#define D_F000WIRPARAM_CNT_LGC                      TRUE
#define D_F000INITLRNDTBLS_CNT_LGC                  TRUE
#define D_F000TRANSOVDATA_CNT_LGC                   TRUE

/* Functions used by the above resets */
#define D_RESET_ALLDTC_MASK_CNT_U32             0xFFFFFFU


/* -----[ Defines For RID: F001 ]------------------------------------------------------------------------------------ */
#define D_ALLDTC_MASK_CNT_U32                   0xFFFFFFU

/* -----[ Defines For RID: F002 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F003 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F004 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F005 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F006 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F007 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F008 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F009 ]------------------------------------------------------------------------------------ */
#define MtrCurrOffProcessFlag                  boolean
#define D_RIDF009SVCDFTBITSSET_CNT_U16         0x0301U
#define D_RIDF009SVCDFTBITSCLR_CNT_U16         (~D_RIDF009SVCDFTBITSSET_CNT_U16)

/* -----[ Defines For RID: F00A ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F00B ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F00C ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F00D ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: F00E ]------------------------------------------------------------------------------------ */
#define D_RIDF00ESVCDFTBITSSET_CNT_U16          0x0301u

/* -----[ Defines For RID: F00F ]------------------------------------------------------------------------------------ */
#define CM_k_SComTrqPosPol_Cnt_s08              k_SComTrqPosPol_Cnt_s08
#define CM_RTE_MODE_StaMd_Mode_OPERATE          RTE_MODE_StaMd_Mode_OPERATE

/* -----[ Defines For PID: FD01 ]------------------------------------------------------------------------------------ */
#define CM_DIAGBUFFLEN_CNT_U16                  kDescPrimBufferLen
#define CM_SwRelNum_Cnt_u08                     k_SWRelNum_Cnt_u8
#define CM_CalRelNum_Cnt_u08                    k_CalRelNum_Cnt_u8
#define CM_BootRelNum_Cnt_u08                   Lnk_BootRelNum_Addr

/* -----[ Defines For PID: FD02 ]------------------------------------------------------------------------------------ */
#define D_SVCDFTRXMSGS_CNT_B32                  0x08000000u
#define D_SVCDFTMULTIGNMASK_CNT_B32             0x50000000u
#define CM_SrlComSvcDft_Cnt_b32                 CDD_EOLSrlComSvcDft_Cnt_G_b32

/* -----[ Defines For PID: FD03 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD04 ]------------------------------------------------------------------------------------ */
#define D_HARTBLSIZE_CNT_U16                    144u

/* -----[ Defines For PID: FD05 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD06 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD07 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD08 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD09 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD0A ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD0B ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD0C ]------------------------------------------------------------------------------------ */

/* -----[ Defines For RID: FD0D ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD0E ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD0F ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD10 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For IOC: FD11 ]------------------------------------------------------------------------------------ */
#define CM_DFTASSTTBL_CNT_LGC                   CDD_DftAsstTbl_Cnt_G_lgc
#define CM_DWNLDASSTGAIN_ULS_F32                CDD_DwnldAsstGain_Uls_G_f32

/* -----[ Defines For PID: FD12 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD13 ]------------------------------------------------------------------------------------ */
#define CM_NTCStrgArray_Type                    NTCStrgArray
#define CM_DTCMaxStorage_Cnt_u16                D_MAXDTCSTORAGE_CNT_U16

/* -----[ Defines For PID: FD14 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD15 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD16 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD18 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD19 ]------------------------------------------------------------------------------------ */
#define CM_NxtrMEC_Cnt_G_u8                     Nvm_NMEC_Cnt_u8

/* -----[ Defines For PID: FD1A ]------------------------------------------------------------------------------------ */
#define CM_Rte_ModeType_StaMd_Mode              Rte_ModeType_StaMd_Mode

/* -----[ Defines For PID: FD1B ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD1C ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD1D ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD1E ]------------------------------------------------------------------------------------ */
#define D_DFTTRQSNSRDIAG_ENABLE                 0xA55Au
#define D_DFTTRQSNSRDIAG_DISABLE                0x0000u

/* -----[ Defines For PID: FD1F ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD20 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD22 ]------------------------------------------------------------------------------------ */
#define D_PIDFD22STRLEN_CNT_U08                 D_TcPNArraySize_Cnt_U16
#define CM_TcPartNumType                        TcPartNumType

/* -----[ Defines For PID: FD23 ]------------------------------------------------------------------------------------ */
#define CM_Vsm_OperatingModeType                Vsm_OperatingModeType

/* -----[ Defines For PID: FD24 ]------------------------------------------------------------------------------------ */
#define CM_EOLTurnsCntrCals_Datatype            EOLTurnsCntrCals_Datatype

/* -----[ Defines For PID: FD25 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD26 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD27 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD29 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FD41 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDA0 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDA1 ]------------------------------------------------------------------------------------ */
#define CM_ECUSerialNumber                      Nvm_EcuSrlNum_Cnt_u8

/* -----[ Defines For PID: FDA2 ]------------------------------------------------------------------------------------ */
#define CM_EPSSerialNumber                      Nvm_EpsSrlNum_Cnt_u8

/* -----[ Defines For PID: FDA3 ]------------------------------------------------------------------------------------ */
#define CM_ECUHardwarePN                        Nvm_EcuHwPn_Cnt_u8

/* -----[ Defines For PID: FDA4 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDA5 ]------------------------------------------------------------------------------------ */
#define CM_ShCurrCal_DataType                   ShCurrCal_DataType

/* -----[ Defines For PID: FDA7 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDA8 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDA9 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDAC ]------------------------------------------------------------------------------------ */
#define CM_MfgScratchPad_Cnt_G_u8               Nvm_NxtrManfScrpd_Cnt_u8

/* -----[ Defines For PID: FDAD ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDAE ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDAF ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDB0 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDB1 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDB2 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDB3 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDB4 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDB5 ]------------------------------------------------------------------------------------ */

/* -----[ Defines For PID: FDB6 ]------------------------------------------------------------------------------------ */


#endif /* EPS_DIAGSRVCS_ISO_INTERFACE_H */
