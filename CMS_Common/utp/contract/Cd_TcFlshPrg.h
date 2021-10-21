/* The following is only part of the header that was required at the 
 * time this component was made. 
 */

#ifndef CD_TCFLSHPRG_H
#define CD_TCFLSHPRG_H


typedef struct  {
	uint32 LastVldTcPnFlashed_Cnt_u32;
	uint16 TcFlashComplete_Cnt_u16;
	uint16 TcFlashIgnCnt_Cnt_u16;
	uint16 TcFlashCounter_Cnt_u16;
}TcFlshNvmType;
	
typedef struct  {
	uint32 ExpectedTcPn_Cnt_u32;
	TcFlshNvmType TcFlashNvm_Uls_str;
	uint8 TcFlashStatus_Cnt_u08;
}CM_TcFlshTraceabilityType;

#endif /* CD_TCFLSHPRG_H */
