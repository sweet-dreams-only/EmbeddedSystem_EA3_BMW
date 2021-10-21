/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Cd_TcFlshPrg.c
* Module Description: Turns Counter PIC Programming
* Product           : Gen II Plus - EA3.0
* Author            : Abdullah Husain
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue Sep 20 16:33:22 2011
* %version:          4 %
* %derived_by:       nz63rn %
* %date_modified:    Thu Jan 23 14:47:09 2014 %
*---------------------------------------------------------------------------*/


/**************************************************************************************************
* Include files
**************************************************************************************************/

#include "TcFlshPrg_Cfg.h"

#include "Cd_TcFlshPrg.h"
#include "Std_Types.h"
#include "SystemTime.h"
#include "IoHwAb_Cfg.h"
#include "CalConstants.h"
#include "SpiNxt.h"
#include "CDD_Func.h"
#include "CDD_Data.h"
#include "NvM.h"

/*****************************************************************************
  * Name:        TcMake32Bit
  * Description: Merge two 16Bit variables into one 32 bit variable by shifting
  		 the HiBytes up by 16 bits
  * Inputs:      HiBytes, LoBytes 
  * Outputs:     32 bit variable
  *
*****************************************************************************/

#define TcMake32Bit(HiBytes,LoBytes) ((uint32)(((uint32)(HiBytes))<<16U)|((uint32)(LoBytes)))

/* == MACRO CONSTANT =========================================== */
#define D_TENTH_US_U16					400u
#define D_TPINTPM_US_U16				5700u
#define D_TPINTCW_US_U16				7500u
#define D_PrgModeDelay_US_U16			100u
#define D_TERAB_US_U16					7500u
#define D_TxDataLen_Cnt_u16			95u
#define D_PrgMemSizeMax_Cnt_u16		8192u
#define D_PrgBlkSize_Cnt_u16			32u
#define D_LdConfig_Cnt_U16				((uint16)0x0000U)
#define D_LdPrgMem_Cnt_U16				((uint16)0x0002U)
#define D_RdPrgMem_Cnt_U16				((uint16)0x0004U)
#define D_IncrAddr_Cnt_U16				((uint16)0x0006U)
#define D_IntTimedPrg_Cnt_U16			((uint16)0x0008U)
#define D_BkErsPrgMem_Cnt_U16			((uint16)0x0009U)
#define D_RstAddr_Cnt_U16				((uint16)0x0016U)
#define D_Prg32BitKey_Cnt_U32			((uint32)0x4D434850U)
#define D_TxBufCntrlCmd_Cnt_U16			((uint16)0x8CFFU)
#define D_TxBufCntrlData_Cnt_U16		((uint16)0x8DFFU)
#define D_TxBufCntrlKey_Cnt_U16			((uint16)0x8EFFU)
#define D_Zeros_Cnt_U16					((uint16)0x0000U)
#define TRANS_GRP_0      				0UL
#define TRANS_GRP_1      				1UL
#define TRANS_GRP_2      				2UL
#define TRANS_GRP_3      				3UL
#define TRANS_GRP_4      				4UL
#define TRANS_GRP_5      				5UL

#define D_PRGMEMLMT_CNT_U16           (D_PrgMemSizeMax_Cnt_u16 - D_PrgBlkSize_Cnt_u16)

#define D_KEY_CNT_U32                 (TcMake32Bit(D_TxBufCntrlKey_Cnt_U16, D_Zeros_Cnt_U16))

#define D_TXDATA_CNT_U32                  (TcMake32Bit(D_TxBufCntrlData_Cnt_U16,D_Zeros_Cnt_U16))

#define D_BLKERSPRGMEMCMD_CNT_U32     (TcMake32Bit(D_TxBufCntrlCmd_Cnt_U16,D_BkErsPrgMem_Cnt_U16))
#define D_LDCONFIGCMD_CNT_U32           (TcMake32Bit(D_TxBufCntrlCmd_Cnt_U16,D_LdConfig_Cnt_U16))
#define D_LDPRGMEMCMD_CNT_U32           (TcMake32Bit(D_TxBufCntrlCmd_Cnt_U16,D_LdPrgMem_Cnt_U16))
#define D_RDPRGMEMCMD_CNT_U32           (TcMake32Bit(D_TxBufCntrlCmd_Cnt_U16,D_RdPrgMem_Cnt_U16))
#define D_INCRADDRCMD_CNT_U32           (TcMake32Bit(D_TxBufCntrlCmd_Cnt_U16,D_IncrAddr_Cnt_U16))
#define D_RSTADDRCMD_CNT_U32            (TcMake32Bit(D_TxBufCntrlCmd_Cnt_U16,D_RstAddr_Cnt_U16))
#define D_BEGTIMEDPRGCMD_CNT_U32        (TcMake32Bit(D_TxBufCntrlCmd_Cnt_U16,D_IntTimedPrg_Cnt_U16))

#define D_TCVerPrgMem_US_U32			3000000u
#define D_TcFlashStatStartValue_CNT_U8	((uint8)0x50U)
#define D_TcFlashStatPassValue_CNT_U8	((uint8)0x00U)
#define D_TcFlashStatFailMSK_CNT_U8		((uint8)0x23U)
#define D_TCFlashStatNoFail_CNT_U8		((uint8)0x00U)

#define D_TCPNHWPNBITS_CNT_U32			((uint32)0x000000FFUL)
#define D_TCPRGMEMPNADDR0_CNT_U16		((uint16)0x0FE0U)

#define D_INVALIDTCIMAGE_CNT_U08		((uint8)0x80U)
#define D_TCIMAGEVSPICERR_CNT_U08		((uint8)0x40U)
#define D_TCFLASHFAIL_CNT_U08			((uint8)0x20U)

#define D_TCFLSHCOMPLETE_CNT_U16		((uint16)0xA5A5U)
#define D_TCFLASHCOUNTERMAX_CNT_U16		((uint16)65535U)

#define D_SCOMCONDITIONSNOTCORRECT_CNT_U08  ((uint8)0x22U)
#define D_SCOMOK_CNT_U08					((uint8)0x00U)



/* == DATA TYPES =============================================== */


#define TCFLSHPRG_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(TcFlshPrgMode_T, CD_TFLSHPRG_VAR_NOINIT) TcPrgState_Cnt_M_enum;
VAR(TcFlshNvmType, NVM_APPL_DATA) TcFlshDataNvm_Uls_str;

#define TCFLSHPRG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

#define TCFLSHPRG_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(uint32, CD_TFLSHPRG_VAR_NOINIT) TcPrgStartTime_uS_M_u32;
STATIC VAR(uint32, CD_TFLSHPRG_VAR_NOINIT) TcFlshPrg_ExpectedTcPn_Cnt_M_u32;

#define TCFLSHPRG_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */

#define TCFLSHPRG_START_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(uint16, CD_TFLSHPRG_VAR_NOINIT) TcDataCntr_Cnt_M_u16;

#define TCFLSHPRG_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h" /* PRQA S 5087 */

#define TCFLSHPRG_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(boolean, CD_TFLSHPRG_VAR_NOINIT) TcFlshPrg_AllowTcAutoflash_Cnt_M_lgc;

#define TCFLSHPRG_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define TCFLSHPRG_START_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */

STATIC VAR(uint8, CD_TFLSHPRG_VAR_NOINIT) TcFlshPrg_TcFlashErrors_Cnt_M_u08;

#define TCFLSHPRG_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */

/* == LOCAL FUNCTIONS =============================================== */

STATIC FUNC(uint8, CD_TFLSHPRG_APPL_CODE) TcFlshPrgStart(void);



/*****************************************************************************
  * Name:        TcFlshPrg_Init
  * Description: 
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Init(void)	
{
	VAR(uint32, AUTOMATIC) TcImagePN_Cnt_T_u32;
	
	CDD_TcFlashActive_Cnt_G_lgc = FALSE;
	CDD_TcFlashVerify_Cnt_G_lgc = FALSE;
	CDD_TcPrgStatus_Cnt_G_enum = TcPrgInit;   
	TcPrgState_Cnt_M_enum = NotActivated;
	TcFlshPrg_AllowTcAutoflash_Cnt_M_lgc = TRUE;
	TcFlshPrg_ExpectedTcPn_Cnt_M_u32 = k_ExpectedTcPn_Cnt_u32 & (~D_TCPNHWPNBITS_CNT_U32);
	
	/*** TC_AutoFlash NVM Checks ***/
	TcImagePN_Cnt_T_u32 = (uint32)(uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMPNADDR0_CNT_U16])>>1);
	TcImagePN_Cnt_T_u32 = (TcImagePN_Cnt_T_u32 << 8) | (uint32)(uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMPNADDR0_CNT_U16 + 1U])>>1);
	TcImagePN_Cnt_T_u32 = (TcImagePN_Cnt_T_u32 << 8) | (uint32)(uint8)((t_TcPrgMemory_Cnt_u16[D_TCPRGMEMPNADDR0_CNT_U16 + 2U])>>1);
	TcImagePN_Cnt_T_u32 = (TcImagePN_Cnt_T_u32 << 8);
	
	if (TcImagePN_Cnt_T_u32 != TcFlshPrg_ExpectedTcPn_Cnt_M_u32)
	{
		TcFlshPrg_TcFlashErrors_Cnt_M_u08 |= D_INVALIDTCIMAGE_CNT_U08;
		TcFlshPrg_AllowTcAutoflash_Cnt_M_lgc = FALSE;
	}
	else if (TcFlshDataNvm_Uls_str.TcFlashComplete_Cnt_u16 != D_TCFLSHCOMPLETE_CNT_U16)
	{
		(void)TcFlshPrgStart();
	}
	else if (TcFlshDataNvm_Uls_str.LastVldTcPnFlashed_Cnt_u32 != TcFlshPrg_ExpectedTcPn_Cnt_M_u32)
	{
		(void)TcFlshPrgStart();
	}
	else /* trailing else required for MISRA rule 14.10 */
	{
	}
	
	CDD_TcFlashErrors_Cnt_G_u08 = TcFlshPrg_TcFlashErrors_Cnt_M_u08;
}


/*****************************************************************************
  * Name:        TcFlshPrg_Per1
  * Description: 
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Per1(void)
{

uint32 TcTxRam3[3];
uint32 TcTxRam10[10];
uint32 TcTxRam4[4];
uint32 TcTxRam97[97];
uint16 ElapsedTime_uS_T_u16;
uint32 ElapsedTime_uS_T_u32;
uint16 RamBufCntr_Cnt_T_u16 = 0U;
uint8 TcFlashStatus_Cnt_T_u8;
uint8 TcPrtNumbers_Cnt_T_u8[D_TcPNArraySize_Cnt_U16];
boolean TCprocessing_Cnt_T_lgc;
VAR(uint32, AUTOMATIC) TcActivePNVldCnt_Cnt_T_u32;
VAR(uint32, AUTOMATIC) TcActivePN_Cnt_T_u32;

	TcFlashStatus_Cnt_T_u8 = CDD_TcFlashStatus_Cnt_G_u08;
	TCprocessing_Cnt_T_lgc = CDD_TCprocessing_Cnt_G_lgc;
	TcActivePNVldCnt_Cnt_T_u32 = CDD_TcActivePNVldCnt_Cnt_G_u32 & (~D_TCPNHWPNBITS_CNT_U32);
	TcActivePN_Cnt_T_u32 = CDD_TcActivePN_Cnt_G_u32 & (~D_TCPNHWPNBITS_CNT_U32);
	
	/*** TC_AutoFlash Periodic Sub-Function ***/
	if (TcFlshPrg_AllowTcAutoflash_Cnt_M_lgc == TRUE)
	{
		if (TcActivePNVldCnt_Cnt_T_u32 == 0UL)
		{
			if (TcFlshPrg_ExpectedTcPn_Cnt_M_u32 == TcActivePN_Cnt_T_u32)
			{
				TcFlshPrg_AllowTcAutoflash_Cnt_M_lgc = FALSE;
			}
			else
			{
				TcFlshPrg_TcFlashErrors_Cnt_M_u08 |= D_TCIMAGEVSPICERR_CNT_U08;
				(void)TcFlshPrgStart();
			}
		}
	}
	
	/*** TC_Flash Periodic Sub-Function ***/
	if(CDD_TcPrgStatus_Cnt_G_enum == TcPrgInPrcs)
	{
		switch(TcPrgState_Cnt_M_enum)
		{
			case EnterPrgMode:
				if (TCprocessing_Cnt_T_lgc == FALSE)
				{
				(void)IoHwAb_SetTcMCLR(STD_HIGH);

				GetSystemTime_uS_u32(&TcPrgStartTime_uS_M_u32);

				TcPrgState_Cnt_M_enum = SendKey;
				}
			break;
			
			case SendKey:
				DtrmnElapsedTime_uS_u16(TcPrgStartTime_uS_M_u32,&ElapsedTime_uS_T_u16);

				if(ElapsedTime_uS_T_u16 > D_TENTH_US_U16){

					TcTxRam3[0]=D_KEY_CNT_U32|(D_Prg32BitKey_Cnt_U32&0x000007FFUL);
					TcTxRam3[1]=D_KEY_CNT_U32|((D_Prg32BitKey_Cnt_U32>>11)&0x000007FFUL);
					TcTxRam3[2]=D_KEY_CNT_U32|((D_Prg32BitKey_Cnt_U32>>22)&0x000007FFUL);


					mibspiSetCtrlData( mibspiREG5, TRANS_GRP_0, TcTxRam3 ); /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */
        		    mibspiTransfer( mibspiREG5, TRANS_GRP_0 );  /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */             

					TcPrgState_Cnt_M_enum = BulkErase;
				
				GetSystemTime_uS_u32(&TcPrgStartTime_uS_M_u32);
				}
			break;

			case BulkErase:

				DtrmnElapsedTime_uS_u16(TcPrgStartTime_uS_M_u32,&ElapsedTime_uS_T_u16);

				if(ElapsedTime_uS_T_u16 > D_PrgModeDelay_US_U16){
					TcTxRam3[0]=D_LDCONFIGCMD_CNT_U32;
					TcTxRam3[1]=D_TXDATA_CNT_U32;
					TcTxRam3[2]=D_BLKERSPRGMEMCMD_CNT_U32; 

					mibspiSetCtrlData( mibspiREG5, TRANS_GRP_1, TcTxRam3 );  /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */       
					mibspiTransfer( mibspiREG5, TRANS_GRP_1 );   /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */             

					TcPrgState_Cnt_M_enum = ConfigWords1;
					GetSystemTime_uS_u32(&TcPrgStartTime_uS_M_u32);
				}
			break;

			case ConfigWords1:
				DtrmnElapsedTime_uS_u16(TcPrgStartTime_uS_M_u32,&ElapsedTime_uS_T_u16);
				if(ElapsedTime_uS_T_u16 > D_TERAB_US_U16){
					TcTxRam10[0]=D_INCRADDRCMD_CNT_U32;
					TcTxRam10[1]=D_INCRADDRCMD_CNT_U32;
					TcTxRam10[2]=D_INCRADDRCMD_CNT_U32;
					TcTxRam10[3]=D_INCRADDRCMD_CNT_U32;
					TcTxRam10[4]=D_INCRADDRCMD_CNT_U32;
					TcTxRam10[5]=D_INCRADDRCMD_CNT_U32;
					TcTxRam10[6]=D_INCRADDRCMD_CNT_U32;
					TcTxRam10[7]=D_LDPRGMEMCMD_CNT_U32;
					TcTxRam10[8]=D_TXDATA_CNT_U32|t_TcConfigWords_Cnt_u16[0];
					TcTxRam10[9]=D_BEGTIMEDPRGCMD_CNT_U32;

					mibspiSetCtrlData( mibspiREG5, TRANS_GRP_2, TcTxRam10 );   /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */     
					mibspiTransfer( mibspiREG5, TRANS_GRP_2 );   /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */             

					TcPrgState_Cnt_M_enum = ConfigWords2;
					GetSystemTime_uS_u32(&TcPrgStartTime_uS_M_u32);
				}
			break;

			case ConfigWords2:
				DtrmnElapsedTime_uS_u16(TcPrgStartTime_uS_M_u32,&ElapsedTime_uS_T_u16);
				if(ElapsedTime_uS_T_u16 > D_TPINTCW_US_U16){
					TcTxRam4[0U]=D_INCRADDRCMD_CNT_U32;
					TcTxRam4[1U]=D_LDPRGMEMCMD_CNT_U32;
					TcTxRam4[2U]=D_TXDATA_CNT_U32|t_TcConfigWords_Cnt_u16[1];
					TcTxRam4[3U]=D_BEGTIMEDPRGCMD_CNT_U32;

					mibspiSetCtrlData( mibspiREG5, TRANS_GRP_3, TcTxRam4 );   /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */     
					mibspiTransfer( mibspiREG5, TRANS_GRP_3 );    /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */            

					TcPrgState_Cnt_M_enum = PrgMemBlock1;
					GetSystemTime_uS_u32(&TcPrgStartTime_uS_M_u32);
				}
			break;

			case PrgMemBlock1:
				DtrmnElapsedTime_uS_u16(TcPrgStartTime_uS_M_u32,&ElapsedTime_uS_T_u16);
				if(ElapsedTime_uS_T_u16 > D_TPINTCW_US_U16){
					TcTxRam97[RamBufCntr_Cnt_T_u16]=D_RSTADDRCMD_CNT_U32;
					RamBufCntr_Cnt_T_u16++;
					TcTxRam97[RamBufCntr_Cnt_T_u16] = D_LDPRGMEMCMD_CNT_U32;
					RamBufCntr_Cnt_T_u16++;
					TcTxRam97[RamBufCntr_Cnt_T_u16] = D_TXDATA_CNT_U32|t_TcPrgMemory_Cnt_u16[TcDataCntr_Cnt_M_u16];
					RamBufCntr_Cnt_T_u16++;
					TcDataCntr_Cnt_M_u16++;
					do{
						TcTxRam97[RamBufCntr_Cnt_T_u16] = D_INCRADDRCMD_CNT_U32;
						RamBufCntr_Cnt_T_u16++;
						TcTxRam97[RamBufCntr_Cnt_T_u16] = D_LDPRGMEMCMD_CNT_U32;
						RamBufCntr_Cnt_T_u16++;
						TcTxRam97[RamBufCntr_Cnt_T_u16] = D_TXDATA_CNT_U32|t_TcPrgMemory_Cnt_u16[TcDataCntr_Cnt_M_u16];
						RamBufCntr_Cnt_T_u16++;
						TcDataCntr_Cnt_M_u16++;
					}
					while(RamBufCntr_Cnt_T_u16 < D_TxDataLen_Cnt_u16);
					TcTxRam97[RamBufCntr_Cnt_T_u16]=D_BEGTIMEDPRGCMD_CNT_U32;
					RamBufCntr_Cnt_T_u16++;
					mibspiSetCtrlData( mibspiREG5, TRANS_GRP_4, TcTxRam97 );  /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */
					mibspiTransfer( mibspiREG5, TRANS_GRP_4 );  /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */
					TcPrgState_Cnt_M_enum = PrgMemBlockSeq;
					GetSystemTime_uS_u32(&TcPrgStartTime_uS_M_u32);
				}
			break;

			case PrgMemBlockSeq:
				DtrmnElapsedTime_uS_u16(TcPrgStartTime_uS_M_u32,&ElapsedTime_uS_T_u16);
				if(ElapsedTime_uS_T_u16 > D_TPINTPM_US_U16){
					if((TcDataCntr_Cnt_M_u16<k_TcPrgMemSize_Cnt_u16)&&(TcDataCntr_Cnt_M_u16 <= D_PRGMEMLMT_CNT_U16)){
						do{
								TcTxRam97[RamBufCntr_Cnt_T_u16] = D_INCRADDRCMD_CNT_U32;
								RamBufCntr_Cnt_T_u16++;
								TcTxRam97[RamBufCntr_Cnt_T_u16] = D_LDPRGMEMCMD_CNT_U32;
								RamBufCntr_Cnt_T_u16++;
								TcTxRam97[RamBufCntr_Cnt_T_u16] = D_TXDATA_CNT_U32|t_TcPrgMemory_Cnt_u16[TcDataCntr_Cnt_M_u16];
								RamBufCntr_Cnt_T_u16++;
								TcDataCntr_Cnt_M_u16++;
						}
						while(RamBufCntr_Cnt_T_u16 < D_TxDataLen_Cnt_u16);
						TcTxRam97[RamBufCntr_Cnt_T_u16]=D_BEGTIMEDPRGCMD_CNT_U32;
						RamBufCntr_Cnt_T_u16++;
						mibspiSetCtrlData( mibspiREG5, TRANS_GRP_4, TcTxRam97 );  /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */
						mibspiTransfer( mibspiREG5, TRANS_GRP_4 );  /* PRQA S 303 */ /* MISRA Rule 11.3 violation. This deviation is required for register access. */
						TcPrgState_Cnt_M_enum = PrgMemBlockSeq;
					}
					else{
						(void)IoHwAb_SetTcMCLR(STD_LOW);
						if(TcFlashStatus_Cnt_T_u8 != D_TcFlashStatStartValue_CNT_U8){
							TcPrgState_Cnt_M_enum = PrgCompleteFail;
						}
						else{
							TcPrgState_Cnt_M_enum = VerifyPrgMem;
							CDD_TcFlashVerify_Cnt_G_lgc = TRUE;
						}
					}
					GetSystemTime_uS_u32(&TcPrgStartTime_uS_M_u32);
				}
			break;

			case VerifyPrgMem:
				if(D_TcFlashStatPassValue_CNT_U8 == TcFlashStatus_Cnt_T_u8){

					TurnsCounter_Scom_PartNumSvc(&TcPrtNumbers_Cnt_T_u8);

					if( (TcPrtNumbers_Cnt_T_u8[0U] == TcPrtNumbers_Cnt_T_u8[9U])
					   && (TcPrtNumbers_Cnt_T_u8[1U] == TcPrtNumbers_Cnt_T_u8[10U])
					   && (TcPrtNumbers_Cnt_T_u8[3U] == TcPrtNumbers_Cnt_T_u8[12U])
					   && (TcPrtNumbers_Cnt_T_u8[4U] == TcPrtNumbers_Cnt_T_u8[13U])
					   && (TcPrtNumbers_Cnt_T_u8[6U] == TcPrtNumbers_Cnt_T_u8[15U])
					   && (TcPrtNumbers_Cnt_T_u8[7U] == TcPrtNumbers_Cnt_T_u8[16U]) )
					{
						TcPrgState_Cnt_M_enum = PrgCompletePass;
						TcFlshDataNvm_Uls_str.LastVldTcPnFlashed_Cnt_u32 = TcActivePN_Cnt_T_u32;
						TcFlshDataNvm_Uls_str.TcFlashComplete_Cnt_u16 = D_TCFLSHCOMPLETE_CNT_U16;
						(void)NvM_WriteBlock(NVM_BLOCK_TCFLSHPRG_TCFLSHDATA, NULL_PTR);
						TcFlshPrg_TcFlashErrors_Cnt_M_u08 &= (uint8)(~D_TCFLASHFAIL_CNT_U08);
					}
					else
					{
						TcPrgState_Cnt_M_enum = PrgCompleteFail;
						TcFlshPrg_TcFlashErrors_Cnt_M_u08 |= D_TCFLASHFAIL_CNT_U08;
					}
				}
				else
				{
					if((TcFlashStatus_Cnt_T_u8 & D_TcFlashStatFailMSK_CNT_U8) != D_TCFlashStatNoFail_CNT_U8)
					{
						TcPrgState_Cnt_M_enum = PrgCompleteFail;
						TcFlshPrg_TcFlashErrors_Cnt_M_u08 |= D_TCFLASHFAIL_CNT_U08;
					}
					else
					{
						DtrmnElapsedTime_uS_u32(TcPrgStartTime_uS_M_u32, &ElapsedTime_uS_T_u32);
						if(ElapsedTime_uS_T_u32 > D_TCVerPrgMem_US_U32)
						{
							TcPrgState_Cnt_M_enum = PrgCompleteFail;
							TcFlshPrg_TcFlashErrors_Cnt_M_u08 |= D_TCFLASHFAIL_CNT_U08;
						}
					}
				}
			break;

			case PrgCompletePass:
			case PrgCompleteFail:
				CDD_TcPrgStatus_Cnt_G_enum = TcPrgCmpl;
				CDD_TcFlashActive_Cnt_G_lgc = FALSE;
				CDD_TcFlashVerify_Cnt_G_lgc = FALSE;
			break;

			default:
				TcPrgState_Cnt_M_enum = PrgCompleteFail;
			break;
		}
	}
	CDD_TcFlashErrors_Cnt_G_u08 = TcFlshPrg_TcFlashErrors_Cnt_M_u08;
}


/*****************************************************************************
  * Name:        TcFlshPrgStart
  * Description: 
  * Inputs:      None 
  * Outputs:     None
  *
*****************************************************************************/
STATIC FUNC(uint8, CD_TFLSHPRG_APPL_CODE) TcFlshPrgStart(void)
{
	VAR(uint8, AUTOMATIC) RetVal_Cnt_T_u08;
	
	if ((CDD_TcFlashActive_Cnt_G_lgc == TRUE) || (0U != (TcFlshPrg_TcFlashErrors_Cnt_M_u08 & D_INVALIDTCIMAGE_CNT_U08)))
	{
		RetVal_Cnt_T_u08 = D_SCOMCONDITIONSNOTCORRECT_CNT_U08;
	}
	else
	{
		RetVal_Cnt_T_u08 = D_SCOMOK_CNT_U08;
		TcPrgState_Cnt_M_enum = EnterPrgMode;
		TcDataCntr_Cnt_M_u16 = 0U;
		CDD_TcPrgStatus_Cnt_G_enum = TcPrgInPrcs;
		CDD_TcFlashActive_Cnt_G_lgc = TRUE;
		CDD_TcFlashVerify_Cnt_G_lgc = FALSE;
		TcFlshPrg_AllowTcAutoflash_Cnt_M_lgc = FALSE;
		
		TcFlshDataNvm_Uls_str.TcFlashComplete_Cnt_u16 = 0U;
		TcFlshDataNvm_Uls_str.TcFlashIgnCnt_Cnt_u16 = TcFlshPrg_NVMIgnCntr_Cnt_u16;
		if (TcFlshDataNvm_Uls_str.TcFlashCounter_Cnt_u16 < D_TCFLASHCOUNTERMAX_CNT_U16)
		{
			TcFlshDataNvm_Uls_str.TcFlashCounter_Cnt_u16 += 1U;
		}
		(void)NvM_WriteBlock(NVM_BLOCK_TCFLSHPRG_TCFLSHDATA, NULL_PTR);
	}
	return RetVal_Cnt_T_u08;
}


/*****************************************************************************
  * Name:        TcFlshPrg_Scom_StartPrg
  * Description: 
  * Inputs:      None 
  * Outputs:     response from TcFlshPrgStart() --
  *					OK (0x00)
  *					Conditions Not Correct (0x22)
  *
*****************************************************************************/

FUNC(uint8, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_StartPrg(void)
{
	return TcFlshPrgStart();
}


/*****************************************************************************
  * Name:        TcFlshPrg_Scom_TcFlashTraceability
  * Description: 
  * Inputs:      None 
  * Outputs:     TcFlshTraceabilityType* pTcFlashTraceabilityData
  *
*****************************************************************************/

FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_TcFlashTraceability(P2VAR(TcFlshTraceabilityType, AUTOMATIC, AUTOMATIC) pTcFlshTraceabilityData)
{
	pTcFlshTraceabilityData->ExpectedTcPn_Cnt_u32 = TcFlshPrg_ExpectedTcPn_Cnt_M_u32;
	pTcFlshTraceabilityData->TcFlashNvm_Uls_str = TcFlshDataNvm_Uls_str;
	pTcFlshTraceabilityData->TcFlashStatus_Cnt_u08 = CDD_TcFlashStatus_Cnt_G_u08;
}

/*****************************************************************************
  * Name:        TcFlshPrg_Scom_FlshPrgStatus
  * Description: Provide the status of the flash programming.
  * Inputs:      pTcFlashActive, ptrTcDataCntr, ptrTcPrgState
  * Outputs:     None
  *
*****************************************************************************/

FUNC(void, CD_TFLSHPRG_APPL_CODE) TcFlshPrg_Scom_FlshPrgStatus( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pTcFlashActive, P2VAR(uint16, AUTOMATIC, AUTOMATIC) ptrTcDataCntr,
																P2VAR(TcFlshPrgMode_T, AUTOMATIC, AUTOMATIC) ptrTcPrgState)
{
	*pTcFlashActive = CDD_TcFlashActive_Cnt_G_lgc;
	*ptrTcDataCntr = TcDataCntr_Cnt_M_u16;
	*ptrTcPrgState = TcPrgState_Cnt_M_enum;

	return;
}




/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description                                                SCR #
-------   -------  --------  -----------------------------------                                    ----------
09/20/10   1.0      AH        Initial file creation
10/11/11   2.0      BDO       Set CDD_TcFlashActive_Cnt_G_lgc to FALSE after Program complete
04/11/11   3.0      JJW       MDD review updates to remove unecessary module level variables.
03/13/12   4        JJW       Updated Spi API for integration with SpiNxt BSW
03/01/13   5.0      AH		  Update to add flash verify functionality and reduce wait states (ICR 3938)
					KJS		  QAC updates and made into a integration component in BMW project.
03/18/13   6.0      KJS		  Updates per FDD98, Anomaly 4655
07/25/13   1.0      KMC       Initial file creation for CBD TcFlshPrg/FDD98 Synergy component
08/01/13   2.0      KMC       Changes for anomaly 4713/CR8684.  Also correct misplaced brace and 
                              remove clearing of TcDataCtr_Cnt_M_u16 in PrgMemBlockSeq section per 
							  FDD. QAC cleanup.
01/14/14	3		KMC		  Updated for FDD98 ver 003 -- autoflashing and fixes for A6196				11183
01/23/14    4		KMC		  Updated for FDD98 ver 004 -- fix A6256									11290
******************************************************************************/

