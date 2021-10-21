/* Com.h header for QAC */


typedef uint8 Com_PduGroupIdType;

/* From ComStack_Types.h */
typedef uint16       PduIdType;   

/* From Com_Cfg.h */
#define PduGrp_EPS__A_FlexRay_TxDebug        (Com_PduGroupIdType) 0
#define PduGrp_EPS__A_FlexRay_Rx             (Com_PduGroupIdType) 1
#define PduGrp_EPS__A_FlexRay_Tx             (Com_PduGroupIdType) 2

/* From Com_Cbk.h */
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_DT_PT_2(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_FZZSTD(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_KILOMETERSTAND(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_KLEMMEN(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr);
FUNC(boolean, COM_APPL_CODE) Ipdum_ProcessRequestPdu(PduIdType ComRxPduId, P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_AVL_FORC_GRD(PduIdType ComTxPduId, P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_AVL_PO_EPS(PduIdType ComTxPduId, P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_AVL_STMOM_DV_ACT(PduIdType ComTxPduId, P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SduPtr);
FUNC(boolean, COM_APPL_CODE) Appl_COMCout_Pdu_DISP_CC_DRDY_02(PduIdType ComTxPduId, P2VAR(uint8, AUTOMATIC, COM_VAR_NOINIT) SduPtr);

/* From Com.h */
extern FUNC(void, COM_CODE) Com_IpduGroupStart(Com_PduGroupIdType IpduGroupId, boolean Initialize);
extern FUNC(void, COM_CODE) Com_IpduGroupStop(Com_PduGroupIdType IpduGroupId);

/* From Appl_ComCbk.h */
extern VAR(boolean, AP_SRLCOMOUTPUT_VAR_NOINIT) ComTxPduCallout_lgc;