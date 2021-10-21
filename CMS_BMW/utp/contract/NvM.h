/* The following is only part of the header that was required at the 
 * time this component was made. 
 */


 #include "NvM_Cfg.h" /* KS - Added for QAC to include all files */
 #include "NvM_Types.h" /* KS - Added for QAC to include all files */
 
 extern FUNC(void, NVM_PUBLIC_CODE) NvM_GetErrorStatus
    (
        NvM_BlockIdType BlockId,
        P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
    );
 
 
 extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_ReadBlock
    (
        NvM_BlockIdType BlockId,
        P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
    );
 
FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WriteBlock (NvM_BlockIdType BlockId, P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr);
extern boolean Appl_WaitNvMReady(const uint16 blockNumber, const boolean fastMode);