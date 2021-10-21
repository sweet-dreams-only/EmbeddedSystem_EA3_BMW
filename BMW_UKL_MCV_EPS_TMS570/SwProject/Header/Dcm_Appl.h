/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Dcm_Appl.h                                                    **
**                                                                            **
**  Copyright (C) BMW Group 2008                                              **
**                                                                            **
**  TARGET    : MPC55xx Autosar v2.1                                          **
**                                                                            **
**  PROJECT   : BMW Standard Core                                             **
**                                                                            **
**  AUTHOR    : EB Automotive                                                 **
**                                                                            **
**  PURPOSE   : Configuration file for DCM Module                             **
**                                                                            **
**  REMARKS   : ---                                                           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** miwe         Michael Weger              EB Automotive                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V1.1.0: 24.01.2008, miwe: RT10289: removed Dcm_NegativeResponseCodeTypes which
 *                                    shall be defined by the Dcm module
 * V1.0.0: 02.10.2007, miwe: initial version
 */

#ifndef DCM_APPL_H
#define DCM_APPL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include <Std_Types.h>            /* AUTOSAR Standard Types */
#include <Dcm.h>                  /* AUTOSAR DCM Module */
#include "Dcm_Cbk.h"              /* Dcm callback header */
#include "sc_types.h"             /* for data assemble/deassemble macros */


/*******************************************************************************
**                      Global Macros                                         **
*******************************************************************************/

#define DCM_CONFIG                                   /* unused init parameter */

#define CONFIG_TRUE                                   CFG_ON
#define CONFIG_FALSE                                  CFG_OFF

/* Read Dcm P2 and P2Star timeout to control compressed programming */
#define Dcm_GetCurrentSessionTimings(P2, P2Star)                               \
   do                                                                          \
   {                                                                           \
      Dcm_TimerServerType TimerServerCurrent;                                  \
      Dcm_GetSesTimingValues(DCM_CURRENT, &TimerServerCurrent);                \
      (*(P2))     = (uint16)TimerServerCurrent.DCM_TIMSTR_P2SERVER_MAX;        \
      (*(P2Star)) = (uint16)TimerServerCurrent.DCM_TIMSTR_P2STARSERVER_MAX;    \
   } while(0)

/* Mapping for force ResponsePending API */
#define Dcm_SendResponsePending(pMsgContext)           Rte_SendResponsePending()
#define Dcm_GetResponsePendingFinished(pMsgContext)                            \
                                                Rte_GetResponsePendingFinished()

/* Unused Dcm callbacks */
#define Rte_DcmStartProtocol(protocol)                                  DCM_E_OK
#define Rte_DcmStopProtocol(pMsgContext)

/* Mapping of data assemble/deassemble macros */
#define Dcm_Make16Bit(hiByte,loByte)                                           \
                                 Make16Bit(hiByte,loByte)
#define Dcm_Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)                     \
                                 Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)
#define Dcm_GetHiByte(data)      GetHiByte(data)
#define Dcm_GetLoByte(data)      GetLoByte(data)
#define Dcm_GetHiHiByte(data)    GetHiHiByte(data)
#define Dcm_GetHiLoByte(data)    GetHiLoByte(data)
#define Dcm_GetLoHiByte(data)    GetLoHiByte(data)
#define Dcm_GetLoLoByte(data)    GetLoLoByte(data)

/* Definition of security levels */
#define DCM_SEC_LEV_LOCKED                                                 0x00u
#define DCM_SEC_LEV_PROGRAMMINGACCESS                                      0x11u

/* NXTR SWT */
#define DCM_SES_LEV_SWT 			   0x42u
#define DCM_SEC_LEV_SWTACCESS          0x13u


/* Definition of securityAccessDataRecordLen */
#define DCM_SEC_SEED_RECORD_LENGTH              (DCM_SECURITYACCESSRECORDLENGTH)

/*
 * Rx Pdu Id for simulate DiagnosticSessionControl(ProgrammingSession) request
 * in StartupSequence()
 */
#define Diag_PhyRx_IPdu                                                    0x00u

/* Mapping of ResponseCodes */
#define DCM_NRC_OK                                                             \
   (Dcm_NegativeResponseCodesType)DCM_E_OK
#define DCM_NRC_GENERALREJECT                                                  \
   (Dcm_NegativeResponseCodesType)DCM_E_GENERALREJECT
#define DCM_NRC_SERVICENOTSUPPORTED                                            \
   (Dcm_NegativeResponseCodesType)DCM_E_SERVICENOTSUPPORTED
#define DCM_NRC_SUBFUNCTIONNOTSUPPORTED                                        \
   (Dcm_NegativeResponseCodesType)DCM_E_SUBFUNCTIONNOTSUPPORTED
#define DCM_NRC_INCORRECTMESSAGELENGTHORINVALIDFORMAT                          \
   (Dcm_NegativeResponseCodesType)DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#define DCM_NRC_RESPONSETOOLONG                                                \
   (Dcm_NegativeResponseCodesType)DCM_E_RESPONSE_TOO_LONG
#define DCM_NRC_BUSYREPEATREQUEST                                              \
   (Dcm_NegativeResponseCodesType)DCM_E_BUSYREPEATREQUEST
#define DCM_NRC_CONDITIONSNOTCORRECT                                           \
   (Dcm_NegativeResponseCodesType)DCM_E_CONDITIONSNOTCORRECT
#define DCM_NRC_REQUESTSEQUENCEERROR                                           \
   (Dcm_NegativeResponseCodesType)DCM_E_REQUESTSEQUENCEERROR
#define DCM_NRC_REQUESTOUTOFRANGE                                              \
   (Dcm_NegativeResponseCodesType)DCM_E_REQUESTOUTOFRANGE
#define DCM_NRC_SECURITYACCESSDENIED                                           \
   (Dcm_NegativeResponseCodesType)DCM_E_SECURITYACCESSDENIED
#define DCM_NRC_INVALIDKEY                                                     \
   (Dcm_NegativeResponseCodesType)DCM_E_INVALIDKEY
#define DCM_NRC_EXCEEDNUMBEROFATTEMPTS                                         \
   (Dcm_NegativeResponseCodesType)DCM_E_EXCEEDNUMBEROFATTEMPTS
#define DCM_NRC_REQUIREDTIMEDELAYNOTEXPIRED                                    \
   (Dcm_NegativeResponseCodesType)DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#define DCM_NRC_UPLOADDOWNLOADNOTACCEPTED                                      \
   (Dcm_NegativeResponseCodesType)DCM_E_UPLOADDOWNLOADNOTACCEPTED
#define DCM_NRC_TRANSFERDATASUSPENDED                                          \
   (Dcm_NegativeResponseCodesType)DCM_E_TRANSFERDATASUSPENDED
#define DCM_NRC_GENERALPROGRAMMINGFAILURE                                      \
   (Dcm_NegativeResponseCodesType)DCM_E_GENERALPROGRAMMINGFAILURE
#define DCM_NRC_WRONGBLOCKSEQUENCECOUNTER                                      \
   (Dcm_NegativeResponseCodesType)DCM_E_WRONGBLOCKSEQUENCECOUNTER
#define DCM_NRC_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING                        \
   (Dcm_NegativeResponseCodesType)DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING
#define DCM_NRC_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION                         \
   (Dcm_NegativeResponseCodesType)DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#define DCM_NRC_SERVICENOTSUPPORTEDINACTIVESESSION                             \
   (Dcm_NegativeResponseCodesType)DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#define DCM_NRC_RPMTOOHIGH                                                     \
   (Dcm_NegativeResponseCodesType)DCM_E_RPMTOOHIGH
#define DCM_NRC_RPMTOOLOW                                                      \
   (Dcm_NegativeResponseCodesType)DCM_E_RPMTOOLOW
#define DCM_NRC_ENGINEISRUNNING                                                \
   (Dcm_NegativeResponseCodesType)DCM_E_ENGINEISRUNNING
#define DCM_NRC_ENGINEISNOTRUNNING                                             \
   (Dcm_NegativeResponseCodesType)DCM_E_ENGINEISNOTRUNNING
#define DCM_NRC_ENGINERUNTIMETOOLOW                                            \
   (Dcm_NegativeResponseCodesType)DCM_E_ENGINERUNTIMETOOLOW
#define DCM_NRC_TEMPERATURETOOHIGH                                             \
   (Dcm_NegativeResponseCodesType)DCM_E_TEMPERATURETOOHIGH
#define DCM_NRC_TEMPERATURETOOLOW                                              \
   (Dcm_NegativeResponseCodesType)DCM_E_TEMPERATURETOOLOW
#define DCM_NRC_VEHICLESPEEDTOOHIGH                                            \
   (Dcm_NegativeResponseCodesType)DCM_E_VEHICLESPEEDTOOHIGH
#define DCM_NRC_VEHICLESPEEDTOOLOW                                             \
   (Dcm_NegativeResponseCodesType)DCM_E_VEHICLESPEEDTOOLOW
#define DCM_NRC_THROTTLE_PEDALTOOHIGH                                          \
   (Dcm_NegativeResponseCodesType)DCM_E_THROTTLE_PEDALTOOHIGH
#define DCM_NRC_THROTTLE_PEDALTOOLOW                                           \
   (Dcm_NegativeResponseCodesType)DCM_E_THROTTLE_PEDALTOOLOW
#define DCM_NRC_TRANSMISSIONRANGEINNEUTRAL                                     \
   (Dcm_NegativeResponseCodesType)DCM_E_TRANSMISSIONRANGEINNEUTRAL
#define DCM_NRC_TRANSMISSIONRANGEINGEAR                                        \
   (Dcm_NegativeResponseCodesType)DCM_E_TRANSMISSIONRANGEINGEAR
#define DCM_NRC_BRAKESWITCH_NOTCLOSED                                          \
   (Dcm_NegativeResponseCodesType)DCM_E_BRAKESWITCH_NOTCLOSED
#define DCM_NRC_SHIFTERLEVERNOTINPARK                                          \
   (Dcm_NegativeResponseCodesType)DCM_E_SHIFTERLEVERNOTINPARK
#define DCM_NRC_TORQUECONVERTERCLUTCHLOCKED                                    \
   (Dcm_NegativeResponseCodesType)DCM_E_TORQUECONVERTERCLUTCHLOCKED
#define DCM_NRC_VOLTAGETOOHIGH                                                 \
   (Dcm_NegativeResponseCodesType)DCM_E_VOLTAGETOOHIGH
#define DCM_NRC_VOLTAGETOOLOW                                                  \
   (Dcm_NegativeResponseCodesType)DCM_E_VOLTAGETOOLOW


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/* mapping of Dcm_NegativeResponseCodesType for SC6 compatibility */
typedef Dcm_NegativeResponseCodeType              Dcm_NegativeResponseCodesType;

typedef struct
{
  uint16 timeOutP2;
  uint16 timeOutP2Ex;
} Dcm_TimerP2xSettingType;

#endif /* DCM_APPL_H                                                          */

/*** End of file **************************************************************/
