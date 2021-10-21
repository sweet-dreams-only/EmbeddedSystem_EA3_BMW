/* -----------------------------------------------------------------------------
  Filename:    ComM_Lcfg.h
  Description: Toolversion: 11.00.11.01.01.01.24.00.00.00
               
               Serial Number: CBD1010124
               Customer Info: Nxtr
                              Package: BMW MSR SIP BAC3.0   
                              Micro: TI TMS570 TMS570LS30306
                              Compiler: Code Composer Studio 4.9.0
               
               
               Generator Fwk   : GENy 
               Generator Module: ComM
               
               Configuration   : c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\Tools\AsrProject\Config\ECUC\EPS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "A_FlexRay":
                       Databasefile: 
                       Bussystem:    FlexRay
                       Node:         EPS_A_FlexRay_1_FrIfConfig

  Generated by , 2016-02-09  08:25:10
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vctr Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vctr Informatik 
  GmbH.
  
  Vctr Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vctr Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(COMM_LCFG_H)
#define COMM_LCFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "ComM_Cfg.h"


/* -----------------------------------------------------------------------------
    &&&~ TYPES
 ----------------------------------------------------------------------------- */

typedef VAR(uint16, TYPEDEF) ComM_UserMaskType;
typedef struct ComM_InhibitionTypeTag
{
  ComM_InhibitionStatusType ComM_ECUGroupClassification;
  uint16 ComM_InhibitCnt;
  ComM_InhibitionStatusType ComM_InhibitionStatus[1];
} ComM_InhibitionType;


/* -----------------------------------------------------------------------------
    &&&~ USER HANDELS
 ----------------------------------------------------------------------------- */

#define ComMUser_A_FlexRay    0u


/* -----------------------------------------------------------------------------
    &&&~ DEFINES
 ----------------------------------------------------------------------------- */

/* ComM channel handles */
#define COMM_A_FlexRay      0u


/* -----------------------------------------------------------------------------
    &&&~ GLOBAL DATA
 ----------------------------------------------------------------------------- */

#define COMM_START_SEC_CONST_8BIT
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"
extern CONST(NetworkHandleType, COMM_CONST)          ComM_ChannelStopIndex[COMM_ACTIVE_CHANNEL];
extern CONST(NetworkHandleType, COMM_CONST)          ComM_Active_Channel;
extern CONST(uint8, COMM_CONST)                      ComM_User_ByteCount;
extern CONST(uint8, COMM_CONST)                      ComM_Nm_Type[COMM_ACTIVE_CHANNEL];
extern CONST(uint8, COMM_CONST)                      ComM_InhibitionStatusInitValue[COMM_ACTIVE_CHANNEL];
extern CONST(ComM_UserHandleType, COMM_CONST)        ComM_MaxNumberOfUsers;
extern CONST(boolean, COMM_CONST)                    ComM_SyncWakeUp;
extern CONST(uint8, COMM_CONST)                      ComM_UserByteMaskIndex[COMM_MAX_NUMBER_OF_USERS + 1];
#define COMM_STOP_SEC_CONST_8BIT
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"

#define COMM_START_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"
extern CONST(ComM_BusType, COMM_CONST)               ComM_ChannelBusType[COMM_ACTIVE_CHANNEL];
extern CONST(ComM_UserByteMaskType, COMM_CONST)      ComM_UserByteMask[COMM_MAX_BYTE_MASK];
extern CONST(ComM_InhibitionStatusType, COMM_CONST)  ComM_ECUGroupClassInit;
#define COMM_STOP_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_8BIT
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"
extern VAR(uint8, COMM_VAR_NOINIT_8BIT)                            ComM_UserReqFullComArray[COMM_USER_BYTE];
extern VAR(uint8, COMM_VAR_NOINIT_8BIT)                            ComM_BusSmState[COMM_ACTIVE_CHANNEL];
extern VAR(uint8, COMM_VAR_NOINIT_8BIT)                            ComM_LastBusSmState[COMM_ACTIVE_CHANNEL];
extern VAR(uint8, COMM_VAR_NOINIT_8BIT)                            ComM_FrShutdown[COMM_ACTIVE_CHANNEL];
extern VAR(uint8, COMM_VAR_NOINIT_8BIT)                            ComM_StateChange[COMM_ACTIVE_CHANNEL];
extern VAR(uint8, COMM_VAR_NOINIT_8BIT)                            ComM_LastStateChange[COMM_ACTIVE_CHANNEL];
extern VAR(uint8, COMM_VAR_NOINIT_8BIT)                            ComM_Dcm_FullReq[COMM_ACTIVE_CHANNEL];
extern VAR(uint8, COMM_VAR_NOINIT_8BIT)                            ComM_Dcm_SilentReq[COMM_ACTIVE_CHANNEL];
#define COMM_STOP_SEC_VAR_NOINIT_8BIT
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_16BIT
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"
extern VAR(uint16, COMM_VAR_NOINIT_16BIT)                           ComM_MinFullComModeTime[COMM_ACTIVE_CHANNEL];
extern VAR(uint16, COMM_VAR_NOINIT_16BIT)                           ComM_NmLightTimeout[COMM_ACTIVE_CHANNEL];
#define COMM_STOP_SEC_VAR_NOINIT_16BIT
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"
extern VAR(ComM_SubModeType, COMM_VAR_NOINIT_UNSPECIFIED)           ComM_ActiveComMode[COMM_ACTIVE_CHANNEL];
extern VAR(ComM_SubModeType, COMM_VAR_NOINIT_UNSPECIFIED)           ComM_BusComModeReq[COMM_ACTIVE_CHANNEL];
extern VAR(ComM_SubModeType, COMM_VAR_NOINIT_UNSPECIFIED)           ComM_BusComModeReqTmp[COMM_ACTIVE_CHANNEL];
#define COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"

#define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"
extern VAR(ComM_InhibitionType, COMM_APPL_VAR_NVRAM)                        ComM_Inhibition;
#define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */ 
#include "MemMap.h"
#define COMM_START_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(uint32, COMM_CONST) ComM_GeneratorVersion;
#define COMM_STOP_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"



#if (COMM_CRC_CHECK == STD_ON)
#define COMM_START_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

extern CONST(uint32, COMM_CONST) ComM_PrecompileCRC;
#define COMM_STOP_SEC_CONST_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


#endif

#define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ GLOBAL FUNCTION PROTOTYPES
 ----------------------------------------------------------------------------- */

extern FUNC(void, COMM_CODE) ComM_MainFunction_0(void); /* ComM Main function */
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ServiceLimitChannelToNoComMode(ComM_NetworkHandleType Channel, boolean Status);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ServicePreventWakeUp(ComM_NetworkHandleType Channel, boolean Status);


/* -----------------------------------------------------------------------------
    &&&~ INTERNAL GENERATED FUNCTION PROTOTYPES
 ----------------------------------------------------------------------------- */

extern FUNC(void, COMM_CODE) ComM_NOCOM_NETREQ(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_NOCOM_READYS(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_SICOM(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_READYS_NETREQ(NetworkHandleType  Channel);/* transition ready to sleep to network requested */
extern FUNC(void, COMM_CODE) ComM_SICOM_NOCOM(NetworkHandleType  Channel);/* transition silent communication to no cummunication*/
extern FUNC(void, COMM_CODE) ComM_SICOM_NETREQ(NetworkHandleType  Channel);/* transition silent communiction to network requested */
extern FUNC(void, COMM_CODE) ComM_SICOM_READYS(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_NETREQ_READYS(NetworkHandleType  Channel);/* transition network requested to ready to sleep */
extern FUNC(void, COMM_CODE) ComM_NO_TRANS(NetworkHandleType  Channel);
extern FUNC(void, COMM_CODE) ComM_EnterModeNoCommunication(NetworkHandleType  Channel);
extern FUNC(void, COMM_CODE) ComM_StateChangeNotification(NetworkHandleType Channel);
extern FUNC(void, COMM_CODE) ComM_DcmIndication(NetworkHandleType Channel, ComM_ModeType ComM_TargetMode);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LoadNonVolatileValues(void);
extern FUNC(void, COMM_CODE) ComM_StoreNonVolatileValues(void);
extern FUNC(void, COMM_CODE) ComM_GetCurrentBusSMMode(NetworkHandleType Channel, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode);


#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 214596022
      #error "The magic number of the generated file <c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\SwProject\Source\GenData\ComM_Lcfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 214596022
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* COMM_LCFG_H */