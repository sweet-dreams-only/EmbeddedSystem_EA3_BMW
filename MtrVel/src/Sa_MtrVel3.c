/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_MtrVel3.c
 *     Workspace:  C:/ccm_wa/EPS/570/I410/MtrVel/autosar
 *     SW-C Type:  Sa_MtrVel3
 *  Generated at:  Fri Feb  1 10:30:20 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Sa_MtrVel3>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Thu Jun 16 14:56:11 2011
 * %version:          2 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Thu Jun 13 10:22:21 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 01/29/13   1      JJW      Initial component  
 * 06/13/13	  2		 KJS	  Applied corrective action as defined in anomaly 4993 
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Sa_MtrVel3.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define MTRVEL_C
#include "Sa_MtrVel.h"	/* Include own header for internal definitions */
#include "Sa_MtrPos.h" /* Include MtrPos header for CDD S/R interface definitions */

#define D_BUFFERMASK_CNT_U08					(D_MTRVELOSBUFSZ_CNT_U08 - 1U)
#define D_MTRVELNUMBUFINIT_CNT_U08	2u /* init only required for the first 2 active buffers, leave snap shot set at 0 */	
#define D_SAMPLETNOM_US_U16    		62u
#define D_MTRVELTNOM_US_U16    		1000u


#define MTRVEL3_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */
	VAR(uint8,  AUTOMATIC) MtrVel3_OsBufPos_Cnt_M_u08[D_MTRVELOSBUFNUM_CNT_U08];
#define MTRVEL3_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */

#define MTRVEL3_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
	VAR(sint16, AUTOMATIC) MtrVel3_SinBuffer_Uls_M_s2p13[D_MTRVELOSBUFNUM_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];
	VAR(sint16, AUTOMATIC) MtrVel3_CosBuffer_Uls_M_s2p13[D_MTRVELOSBUFNUM_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];
	VAR(uint16, AUTOMATIC) MtrVel3_PosBuffer_Rev_M_u0p16[D_MTRVELOSBUFNUM_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];
	VAR(uint16, AUTOMATIC) MtrVel3_TimeBuffer_uS_M_u16p0[D_MTRVELOSBUFNUM_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];
#define MTRVEL3_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Double: Real in interval ]-DBL_MAX...DBL_MAX[ with double precision including NaN (standard type)
 * Float: Real in interval ]-FLT_MAX...FLT_MAX[ with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082
 * Float: D_2MS_SEC_F32 = 0.002
 * Float: D_2PI_ULS_F32 = 6.2831853071796
 * Float: D_MSECPERSEC_ULS_F32 = 1000
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8
 * Float: D_ONE_ULS_F32 = 1
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199
 * Float: D_PI_ULS_F32 = 3.1415926535898
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718
 * Float: D_VECUMIN_VOLTS_F32 = 5
 * Float: D_ZERO_ULS_F32 = 0
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ONE_CNT_U16 = 1u
 * UInt16: D_ZERO_CNT_U16 = 0u
 * UInt32: D_ONE_CNT_U32 = 1u
 * UInt32: D_ZERO_CNT_U32 = 0u
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3u
 * UInt8: D_ONE_CNT_U8 = 1u
 * UInt8: D_QUADRANT1_CNT_U8 = 1u
 * UInt8: D_QUADRANT2_CNT_U8 = 2u
 * UInt8: D_QUADRANT3_CNT_U8 = 3u
 * UInt8: D_QUADRANT4_CNT_U8 = 4u
 * UInt8: D_ZERO_CNT_U8 = 0u
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_MTRVEL3_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MtrVel3_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_MTRVEL3_APPL_CODE) MtrVel3_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MtrVel3_Init
 *********************************************************************************************************************/
	VAR(sint8, AUTOMATIC) pos;
	VAR(uint8, AUTOMATIC) buf;
	VAR(uint32, AUTOMATIC) sampTime_uS_T_u32;	

	sampTime_uS_T_u32 = MtrPos_SampleTime_uS_G_u32;
	
	/* Initialize only the active buffer set, the other 2 snapshot buffers remain initilaized at 0 */
	for (buf = 0u; buf < D_MTRVELNUMBUFINIT_CNT_U08; buf++)
	{
		/* Newest sample of each buffer is arbitrarily selected as the largest index in the buffer */
		MtrVel3_OsBufPos_Cnt_M_u08[buf] = D_MTRVELOSBUFSZ_CNT_U08 - 1u;
	
		for (pos = (D_MTRVELOSBUFSZ_CNT_U08 - 1u); pos >= 0; pos--)
		{
			MtrVel3_SinBuffer_Uls_M_s2p13[buf][pos] = MtrPos_SinTheta1_Volts_G_s2p13;
			MtrVel3_CosBuffer_Uls_M_s2p13[buf][pos] = MtrPos_CosTheta1_Volts_G_s2p13;
			MtrVel3_PosBuffer_Rev_M_u0p16[buf][pos] = MtrPos_MechMtrPos_Rev_G_u0p16;
			MtrVel3_TimeBuffer_uS_M_u16p0[buf][pos] = sampTime_uS_T_u32;
			
			/* Decrement timestamp by nominal sampling period to simulate previous timestamp value for next sample init */
			sampTime_uS_T_u32 = (sampTime_uS_T_u32 - D_SAMPLETNOM_US_U16) & 0xFFFFu;
		}		

		/* Decrement timestamp by nominal MtrVel computation period to simulate previous buffer timestamp start value for next buffer init */
		sampTime_uS_T_u32 = (MtrVel3_TimeBuffer_uS_M_u16p0[buf][D_MTRVELOSBUFSZ_CNT_U08 - 1u] - D_MTRVELTNOM_US_U16) & 0xFFFFu;
	}
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_MTRVEL3_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, SA_MTRVEL_CODE) MtrVel3_Per1(void)
{
	/* In order to ensure minimal run-time, capture local consistent copy of the volatile declared variable to ensure 
	 * the compiler doesn't read the variable on every use throughout this function.
     * Since this function is running in a higher priority context than the process modifying MtrVel_OsBufSelect_Cnt_M_u08,
	 * we don't need to be concerned with the value of MtrVel_OsBufSelect_Cnt_M_u08 changing during this process and this 
	 * function is designed to only funciton properly when MtrVel_OsBufSelect_Cnt_M_u08 is a constant value for the duration
	 * of this function execution.
	 */
	VAR(uint8, AUTOMATIC) BufSelect_Cnt_T_u08 = MtrVel_OsBufSelect_Cnt_M_u08;

	if (BufSelect_Cnt_T_u08 < D_MTRVELOSBUFNUM_CNT_U08)
	{
		MtrVel3_OsBufPos_Cnt_M_u08[BufSelect_Cnt_T_u08] = (MtrVel3_OsBufPos_Cnt_M_u08[BufSelect_Cnt_T_u08] + 1U) & D_BUFFERMASK_CNT_U08;
		
		MtrVel3_SinBuffer_Uls_M_s2p13[BufSelect_Cnt_T_u08][MtrVel3_OsBufPos_Cnt_M_u08[BufSelect_Cnt_T_u08]] = MtrPos_SinTheta1_Volts_G_s2p13;
		MtrVel3_CosBuffer_Uls_M_s2p13[BufSelect_Cnt_T_u08][MtrVel3_OsBufPos_Cnt_M_u08[BufSelect_Cnt_T_u08]] = MtrPos_CosTheta1_Volts_G_s2p13;
		MtrVel3_PosBuffer_Rev_M_u0p16[BufSelect_Cnt_T_u08][MtrVel3_OsBufPos_Cnt_M_u08[BufSelect_Cnt_T_u08]] = MtrPos_MechMtrPos_Rev_G_u0p16;
		MtrVel3_TimeBuffer_uS_M_u16p0[BufSelect_Cnt_T_u08][MtrVel3_OsBufPos_Cnt_M_u08[BufSelect_Cnt_T_u08]] = (uint16)(MtrPos_SampleTime_uS_G_u32 & 0xFFFFU);
	}	
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
