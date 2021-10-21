/* Fr_Cfg.h header for QAC */

#define FR_VEXTENDED_CC_STATUS STD_ON
typedef uint32 Fr_VErrorStatusType;
extern FUNC(void, FR_CODE) Fr_VCheckErrorState(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);

/* From Fr_Ext.h */
extern FUNC(void, FR_APPL_CODE) ApplFr_CBK_CcErrorEvent(P2VAR(Fr_VErrorStatusType, AUTOMATIC, FR_APPL_DATA) Fr_VErrorStatusPtr);