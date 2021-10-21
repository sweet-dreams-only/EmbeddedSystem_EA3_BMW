/* -----------------------------------------------------------------------------
  Filename:    Com_Cbk.h
  Description: Toolversion: 11.00.11.01.01.01.24.00.00.00
               
               Serial Number: CBD1010124
               Customer Info: Nxtr
                              Package: BMW MSR SIP BAC3.0   
                              Micro: TI TMS570 TMS570LS30306
                              Compiler: Code Composer Studio 4.9.0
               
               
               Generator Fwk   : GENy 
               Generator Module: Com
               
               Configuration   : c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\Tools\AsrProject\Config\ECUC\EPS.ecuc.vdsxml
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570PSFC66
               
               Channel "A_FlexRay":
                       Databasefile: 
                       Bussystem:    FlexRay
                       Node:         EPS_A_FlexRay_1_FrIfConfig

  Generated by , 2016-02-09  08:25:11
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

#if !defined(COM_CBK_H)
#define COM_CBK_H

#define COM_START_SEC_CODE
/* PRQA S 5087 1 */ /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
#include "MemMap.h"

#define COM_RXIND_PARA    SduPtr
#define COM_RXIND_TYPE    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)
/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer after an I-PDU has been received.
    \param    ComRxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                              Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param    COM_RXIND_PARA
              SduPtr          Pointer to the received I-PDU data.\n
                              This Parameter is used, if COM_USE_PDUINFOTYPE is defined to STD_OFF.\n
              PduInfoPtr      Payload information of the received I-PDU (pointer to data and data length).\n
                              This Parameter is used, if COM_USE_PDUINFOTYPE is defined to STD_ON.    
    \return   none
    \context  The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used. 
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType ComRxPduId, COM_RXIND_TYPE COM_RXIND_PARA);

/**********************************************************************************************************************
  Com_TxConfirmation
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer after the PDU has been transmitted on the network.
              A confirmation that is received for an I-PDU that does not require a confirmation is silently discarded.
    \param    ComTxPduId    ID of AUTOSAR COM I-PDU that has been transmitted.
                            Range: 0..(maximum number of I-PDU IDs transmitted by AUTOSAR COM) - 1
    \return   none
    \context  The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used. 
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType ComTxPduId);

#define COM_TT_PARA      SduPtr
#define COM_TT_TYPE      P2VAR(uint8, AUTOMATIC, COM_APPL_VAR)
#define COM_TT_RETURN    void
/**********************************************************************************************************************
  Com_TriggerTransmit
**********************************************************************************************************************/
/** \brief    This function is called by the lower layer when an AUTOSAR COM I-PDU shall be transmitted.
              Within this function, AUTOSAR COM shall copy the contents of its I-PDU transmit buffer
              to the L-PDU buffer given by SduPtr.
              Use case:
              This function is used e.g. by the LIN Master for sending out a LIN frame. In this case, the trigger transmit
              can be initiated by the Master schedule table itself or a received LIN header.
              This function is also used by the FlexRay Interface for requesting PDUs to be sent in static part
              (synchronous to the FlexRay global time). Once the I-PDU has been successfully sent by the lower layer
              (PDU-Router), the lower layer must call Com_TxConfirmation().
    \param    ComTxPduId    ID of AUTOSAR COM I-PDU that is requested to be transmitted by AUTOSAR COM.
    \param    COM_TT_PARA
              SduPtr              Pointer to the received I-PDU data.\n
                                  This Parameter is used, if COM_USE_PDUINFOTYPE is defined to STD_OFF.\n
              PduInfoPtr          Payload information of the received I-PDU (pointer to data and data length).\n
                                  This Parameter is used, if COM_USE_PDUINFOTYPE is defined to STD_ON.
    \return   COM_TT_RETURN
              none                No return value.\n
                                  This return value is used, if COM_USE_PDUINFOTYPE is defined to STD_OFF.\n
              Std_ReturnType      This  return value is used, if COM_USE_PDUINFOTYPE is defined to STD_ON.
                                  E_OK:     The SDU has been copied and the SduLength indicates
                                            the number of copied bytes.\n
                                  E_NOT_OK: The SDU has not been copied and the SduLength has not been set.                                  
    \context  The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used. 
    \note     The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(COM_TT_RETURN, COM_CODE) Com_TriggerTransmit(PduIdType ComTxPduId, COM_TT_TYPE COM_TT_PARA);



#define COM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
#include "MemMap.h"


#define COM_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
#include "MemMap.h"

/**********************************************************************************************************************
  I-PDU Callout Prototypes
**********************************************************************************************************************/
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_FZZSTD(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_KILOMETERSTAND(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr);
FUNC(boolean, COM_APPL_CODE) Ipdum_ProcessRequestPdu(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_AVL_FORC_GRD(PduIdType ComTxPduId, P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_AVL_PO_EPS(PduIdType ComTxPduId, P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_AVL_STMOM_DV_ACT(PduIdType ComTxPduId, P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SduPtr);

#define COM_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /*RULE 19.1: The memory abstraction concept uses includes of MemMap.h at any place in the source code. This is required by AUTOSAR. */
#include "MemMap.h"



/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 214596022
      #error "The magic number of the generated file <c:\Build\BMW\ses_dev_ea3\BMW_MCV_UKL_EPS_TMS570_F40_Working\BMW_UKL_MCV_EPS_TMS570\SwProject\Source\GenData\Com_Cbk.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 214596022
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* COM_CBK_H */