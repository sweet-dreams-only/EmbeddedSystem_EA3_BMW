/* CDD_Data for QAC */

extern VAR(boolean, CDD_VAR_NOINIT) CDD_SWTEnableFlag_Cnt_G_lgc;

typedef uint16 NvM_BlockIdType;
extern FUNC(void, NVM_PUBLIC_CODE) NvM_GetErrorStatus (NvM_BlockIdType BlockId, P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr);

#define D_ZERO_CNT_U32 0UL

#define Rte_NvmBlock_VehCfg_PrevVldTuningSel (0U)

