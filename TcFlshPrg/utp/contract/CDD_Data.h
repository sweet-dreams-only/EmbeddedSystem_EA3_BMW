

typedef enum {
	TcPrgInit	= 				0,
	TcPrgInPrcs =				1,
	TcPrgCmpl	=	 			2
} TcFlshPrgStatus_T;

extern VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashActive_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TCprocessing_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TCprocessing_Cnt_G_lgc;
extern VAR(boolean, CDD_VAR_NOINIT) CDD_TcFlashVerify_Cnt_G_lgc;
extern VAR(TcFlshPrgStatus_T, CDD_VAR_NOINIT) CDD_TcPrgStatus_Cnt_G_enum;
extern VAR(uint8, CDD_VAR_NOINIT) CDD_TcFlashStatus_Cnt_G_u08;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_TcActivePN_Cnt_G_u32;
extern VAR(uint32, CDD_VAR_NOINIT) CDD_TcActivePNVldCnt_Cnt_G_u32;
extern VAR(uint8, CDD_VAR_NOINIT) CDD_TcFlashErrors_Cnt_G_u08;

#define D_TcPNArraySize_Cnt_U16				20u