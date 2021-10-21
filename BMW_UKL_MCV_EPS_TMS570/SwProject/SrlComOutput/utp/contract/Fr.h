/* Fr.h for QAC */

 #define FR_VCTRL_SYSTEMTYPE_FIRST    uint8 Fr_CtrlIdx,
  
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime
(
  FR_VCTRL_SYSTEMTYPE_FIRST
  P2VAR(uint8,  AUTOMATIC, FR_APPL_DATA) Fr_CyclePtr,
  P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_MacroTickPtr
);