/* CalConstant header for QAC */

#define D_NUMOFTUNSETS_CNT_U16 20U
#define D_NUMOFPERS_CNT_U16	20U


typedef struct
{
	uint16	k_CalID_Cnt_u16;
	uint16	k_PMAPersonality_CalID_Cnt_u16;
	/* Removed the rest of the cals in the structure since this is the only the SW cares about */
} TUNING_P_Str;

typedef struct
{
	uint32	k_HWAPId_Cnt_u32;
	/* Removed the rest of the cals in the structure since this is the only the SW cares about */
} TUNING_Y_Str;

extern CONST(boolean, CAL_CONST) k_SWTPresentSwitch_Uls_lgc;
extern CONST(uint8, CAL_CONST) k_NxtrVariantCalSel_Cnt_u8;

CONST(TUNING_P_Str, CAL_CONST)k_TunPer0_Cnt_Str = { 0U };
CONST(TUNING_Y_Str, CAL_CONST)k_TunSet0_Cnt_Str = { 0U };

CONSTP2CONST(TUNING_P_Str, AUTOMATIC, AUTOMATIC) T_TunPersSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16][D_NUMOFPERS_CNT_U16] = {{&k_TunPer0_Cnt_Str}};

CONSTP2CONST(TUNING_Y_Str, AUTOMATIC, AUTOMATIC) T_TunSetSelectionTbl_Ptr_Str[D_NUMOFTUNSETS_CNT_U16] = {&k_TunSet0_Cnt_Str};


 /* Manually Added Start */
 #define NVM_BLOCK_HWDESCDATA (59)
 /* Manually Added End */
typedef uint16 NvM_BlockIdType;
extern FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WriteBlock
    (
        NvM_BlockIdType BlockId,
        P2CONST(uint8, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
    );