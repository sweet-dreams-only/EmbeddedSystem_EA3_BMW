/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_CDDInterface10.c
 *     Workspace:  C:/_swb/BMW/BMW_UKL_MCV_EPS_TMS570-_410PR/BMW_UKL_MCV_EPS_TMS570/SwProject/CDDInterface/autosar/Sa_CDDInterface.dcf
 *     SW-C Type:  Sa_CDDInterface10
 *  Generated at:  Tue Feb 12 13:52:56 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nxtr  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Sa_CDDInterface10>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Mon Aug 15 20:53:00 2011
 * %version:          10 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Fri Mar 15 11:00:41 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 10/19/11  1       JJW       	Initial creation
 * 10/22/11  2       JJW       	Extended scope of application 10 signal buffering, per implied requirements
 * 11/21/11  3       JJW       	Changed MtrPos Buffer to use CDD_CDDMtrPosAccessBfr_Cnt_G_u16, which is managed by
 * 								IoHwAb7 to provide better synchronization between the ADC1 and ADC2 MtrPos samples
 * 01/28/13	 6		 KJS		Updated init and per1 to support polarity.  
 * 02/14/13  9		 KJS		QAC corrections.
 * 03/15/13  10		 KJS		QAC corrections.
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Constants:
 ==========
  D_RACKTOVEHCNTRUNLEARNED_CNT_U16
    This constant has been added until anomaly 3744 can be corrected. Once the anomaly is corrected, this can be removed from StdDef. This should only be used by BMW as of 12Sep12.

  D_SFMILLI_ULS_F32
    Scale factor multiplier to convert a SI milli quantity into the standard SI unit (e.g. mm to m)

  D_SVCDFTDRIVINGDYN_CNT_B32
    Torque Overlay defeat is bit 13 per PID 0xFD02 in teh EA 3.0_Nxtr Common Mfg Serv Spec
     
     Bit 13 =  2^13=8192

  D_SVCDFTHYSTADD_CNT_B32
    Hysteresis Add defeat is bit 15 per PID 0xFD02 in the EA 3.0_Nxtr Common Mfg Serv Spec
     
     Bit 15 =  2^15=32768

  D_SVCDFTPARKAST_CNT_B32
    Parking Assist defeay is bit 12 per PID 0xFD02 in teh EA 3.0_Nxtr Common Mfg Serv Spec
     
     Bit 12 =  2^12=4096

 *********************************************************************************************************************/

#include "Rte_Sa_CDDInterface10.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "fixmath.h"
#include "GlobalMacro.h"
#include "CDD_Data.h"
#include "Nhet.h"

#define D_ADCVOLTSPERCNT_ULS_F32		(5.0F / 4095.0F)
#define D_PXACCUMMAX_CNT_U32			536870911UL

#define D_PHASEA_CNT_U16  0U
#define D_PHASEB_CNT_U16  1U
#define D_PHASEC_CNT_U16  2U

#define CDDINTERFACE10_START_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(sint8, CDDInterface9_VAR_NOINIT) PrevMtrElecMechPolarity_Cnt_M_s08;
#define CDDINTERFACE10_STOP_SEC_VAR_NOINIT_8
#include "MemMap.h" /* PRQA S 5087 */


#define CDDINTERFACE10_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, CDDInterface9_VAR_NOINIT) PXAccumPrev_Cnt_M_u32[(D_PHASEC_CNT_U16 + 1U)];
#define CDDINTERFACE10_STOP_SEC_VAR_NOINIT_32
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
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 *
 * Enumeration Types:
 * ==================
 * FETFAULTTYPE_ENUM: Enumeration of integer in interval [0...255] with enumerators
 *   NOFAULT (0U)
 *   LOWER (1U)
 *   UPPER (2U)
 * FETPHASETYPE_ENUM: Enumeration of integer in interval [0...255] with enumerators
 *   NOPHASE (0U)
 *   PHASEA (1U)
 *   PHASEB (2U)
 *   PHASEC (3U)
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
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt8: D_ZERO_CNT_S8 = 0
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_CDDINTERFACE10_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_CDDInterface10_Init1_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface10_Init1
 *********************************************************************************************************************/
	VAR(sint8, AUTOMATIC) MtrElecMechPolarity_Cnt_T_s08;

	MtrElecMechPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface10_Init1_MtrElecMechPolarity_Cnt_s08();
	
	CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 = 0U;
	CDD_AppDataFbkPthAccessBfr_Cnt_G_u16 = 0U;
	CDD_CDDDataAccessBfr_Cnt_G_u16 = 0U;

	/* Update polarity for the PWM driver */
	(void)Rte_Call_CDDPorts_ApplyMtrElecMechPol(MtrElecMechPolarity_Cnt_T_s08);
	PrevMtrElecMechPolarity_Cnt_M_s08 = MtrElecMechPolarity_Cnt_T_s08;
	
	PXAccumPrev_Cnt_M_u32[D_PHASEA_CNT_U16] = HET_P1ACC_1.memory.data_word >> 3u;
	PXAccumPrev_Cnt_M_u32[D_PHASEB_CNT_U16] = HET_P2ACC_1.memory.data_word >> 3u;
	PXAccumPrev_Cnt_M_u32[D_PHASEC_CNT_U16] = HET_P3ACC_1.memory.data_word >> 3u;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   SInt8 Rte_IRead_CDDInterface10_Per1_MtrElecMechPolarity_Cnt_s08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_SWDutyCycleA_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleA_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_SWDutyCycleB_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleB_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface10_Per1_SWDutyCycleC_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface10_Per1_SWDutyCycleC_Uls_f32(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ApplyMtrElecMechPol(SInt8 MtrElecMechPol_Cnt_s8)
 *     Synchronous Service Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface10_Per1
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) ReadBuffer_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) WriteBuffer_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) DutyCycleSmall_Cnt_T_u16;
	VAR(float32, AUTOMATIC) InvPeriodSum_Uls_T_f32;
	VAR(float32, AUTOMATIC) SWDutyCycleA_Uls_T_f32;
	VAR(float32, AUTOMATIC) SWDutyCycleB_Uls_T_f32;
	VAR(float32, AUTOMATIC) SWDutyCycleC_Uls_T_f32;
	VAR(uint32, AUTOMATIC) ExpectedOnTimeA_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ExpectedOnTimeB_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) ExpectedOnTimeC_Cnt_T_u32;
	VAR(uint32, AUTOMATIC) MeasuredOnTime_Cnt_T_u32[(D_PHASEC_CNT_U16 + 1U)];
	VAR(uint32, AUTOMATIC) PXAccum_Cnt_T_u32[(D_PHASEC_CNT_U16 + 1U)];
	VAR(uint16, AUTOMATIC) i;
	VAR(sint8, AUTOMATIC) MtrElecMechPolarity_Cnt_T_s08;

	/* Read in inputs */
	MtrElecMechPolarity_Cnt_T_s08 = Rte_IRead_CDDInterface10_Per1_MtrElecMechPolarity_Cnt_s08();

	if(PrevMtrElecMechPolarity_Cnt_M_s08 != MtrElecMechPolarity_Cnt_T_s08)
	{
		PrevMtrElecMechPolarity_Cnt_M_s08 = MtrElecMechPolarity_Cnt_T_s08;
		(void)Rte_Call_CDDPorts_ApplyMtrElecMechPol(MtrElecMechPolarity_Cnt_T_s08);
	}

	ReadBuffer_Cnt_T_u16 = CDD_CDDDataAccessBfr_Cnt_G_u16;
	WriteBuffer_Cnt_T_u16 = (ReadBuffer_Cnt_T_u16 & 1U)^1U;
	CDDPorts_ClearPhsReasSum(WriteBuffer_Cnt_T_u16);
	CDD_CDDDataAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;
	
	/* These NHET2 memory reads are performed immediately after the buffer swap for greatest possible synchronization */
	PXAccum_Cnt_T_u32[D_PHASEA_CNT_U16] = HET_P1ACC_1.memory.data_word >> 3u;
	PXAccum_Cnt_T_u32[D_PHASEB_CNT_U16] = HET_P2ACC_1.memory.data_word >> 3u;
	PXAccum_Cnt_T_u32[D_PHASEC_CNT_U16] = HET_P3ACC_1.memory.data_word >> 3u;

	InvPeriodSum_Uls_T_f32 = 1.0F / (float32)CDD_PWMPeriodSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	
	SWDutyCycleA_Uls_T_f32 = (float32)CDD_PWMDutyCycleASum_Cnt_G_u32[ReadBuffer_Cnt_T_u16] * InvPeriodSum_Uls_T_f32;
	SWDutyCycleB_Uls_T_f32 = (float32)CDD_PWMDutyCycleBSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16] * InvPeriodSum_Uls_T_f32;
	SWDutyCycleC_Uls_T_f32 = (float32)CDD_PWMDutyCycleCSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16] * InvPeriodSum_Uls_T_f32;

	ExpectedOnTimeA_Cnt_T_u32 = CDD_PWMDutyCycleASum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeB_Cnt_T_u32 = CDD_PWMDutyCycleBSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeC_Cnt_T_u32 = CDD_PWMDutyCycleCSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	
	DutyCycleSmall_Cnt_T_u16 = CDD_DutyCycleSmall_Cnt_G_u16[ReadBuffer_Cnt_T_u16];

	for(i = D_PHASEA_CNT_U16; i <= D_PHASEC_CNT_U16; i++)
	{
		if(PXAccum_Cnt_T_u32[i] < PXAccumPrev_Cnt_M_u32[i])
		{
			MeasuredOnTime_Cnt_T_u32[i] = (D_PXACCUMMAX_CNT_U32 - PXAccumPrev_Cnt_M_u32[i]) + PXAccum_Cnt_T_u32[i] + 1U;
		}
		else
		{
			MeasuredOnTime_Cnt_T_u32[i] = PXAccum_Cnt_T_u32[i] - PXAccumPrev_Cnt_M_u32[i];
		}
		
		PXAccumPrev_Cnt_M_u32[i] = PXAccum_Cnt_T_u32[i];
	}
	
	Rte_IWrite_CDDInterface10_Per1_SWDutyCycleA_Uls_f32(SWDutyCycleA_Uls_T_f32);
	Rte_IWrite_CDDInterface10_Per1_SWDutyCycleB_Uls_f32(SWDutyCycleB_Uls_T_f32);
	Rte_IWrite_CDDInterface10_Per1_SWDutyCycleC_Uls_f32(SWDutyCycleC_Uls_T_f32);
	Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeA_Cnt_u32(ExpectedOnTimeA_Cnt_T_u32);
	Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeB_Cnt_u32(ExpectedOnTimeB_Cnt_T_u32);
	Rte_IWrite_CDDInterface10_Per1_ExpectedOnTimeC_Cnt_u32(ExpectedOnTimeC_Cnt_T_u32);
	Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeA_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEA_CNT_U16]);
	Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeB_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEB_CNT_U16]);
	Rte_IWrite_CDDInterface10_Per1_MeasuredOnTimeC_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEC_CNT_U16]);
	Rte_IWrite_CDDInterface10_Per1_DutyCycleSmall_Cnt_u16(DutyCycleSmall_Cnt_T_u16);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Per2
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   UInt16 Rte_IRead_CDDInterface10_Per2_CommOffset_Cnt_u16(void)
 *   Float Rte_IRead_CDDInterface10_Per2_DeadTimeComp_Uls_f32(void)
 *   Float Rte_IRead_CDDInterface10_Per2_ModIdxFinal_Uls_f32(void)
 *   SInt16 Rte_IRead_CDDInterface10_Per2_MtrTrqCmdSign_Cnt_s16(void)
 *   UInt16 Rte_IRead_CDDInterface10_Per2_PhaseAdvFinal_Cnt_u16(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per2(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface10_Per2
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) WriteBuffer_Cnt_T_u16;
	VAR(uint16, AUTOMATIC) CommOffset_Cnt_T_u16;
	VAR(float32, AUTOMATIC) DeadTimeComp_Uls_T_f32;
	VAR(float32, AUTOMATIC) ModIdxFinal_Uls_T_f32;
	VAR(sint16, AUTOMATIC) MtrTrqCmdSign_Cnt_T_s16;
	VAR(uint16, AUTOMATIC) PhaseAdvFinal_Cnt_T_u16;
	
	WriteBuffer_Cnt_T_u16 = (CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 & 1U)^1U;
	
	CommOffset_Cnt_T_u16 = Rte_IRead_CDDInterface10_Per2_CommOffset_Cnt_u16();
	DeadTimeComp_Uls_T_f32 = Rte_IRead_CDDInterface10_Per2_DeadTimeComp_Uls_f32();
	ModIdxFinal_Uls_T_f32 = Rte_IRead_CDDInterface10_Per2_ModIdxFinal_Uls_f32();
	MtrTrqCmdSign_Cnt_T_s16 = Rte_IRead_CDDInterface10_Per2_MtrTrqCmdSign_Cnt_s16();
	PhaseAdvFinal_Cnt_T_u16 = Rte_IRead_CDDInterface10_Per2_PhaseAdvFinal_Cnt_u16();
	
	CDD_CommOffset_Cnt_G_u16[WriteBuffer_Cnt_T_u16] = CommOffset_Cnt_T_u16;
	CDD_DeadTimeComp_Uls_G_u8p8[WriteBuffer_Cnt_T_u16] = FPM_FloatToFixed_m(DeadTimeComp_Uls_T_f32, u8p8_T);
	CDD_ModIdxFinal_Uls_G_u16p16[WriteBuffer_Cnt_T_u16] = FPM_FloatToFixed_m(ModIdxFinal_Uls_T_f32, u16p16_T);
	CDD_MtrTrqCmdSign_Cnt_G_s16[WriteBuffer_Cnt_T_u16] = MtrTrqCmdSign_Cnt_T_s16;
	CDD_PhaseAdvFinal_Cnt_G_u16[WriteBuffer_Cnt_T_u16] = PhaseAdvFinal_Cnt_T_u16;
	
	CDD_AppDataFwdPthAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface10_Per3
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   FETPHASETYPE_ENUM Rte_IRead_CDDInterface10_Per3_FETFaultPhase_Cnt_enum(void)
 *   FETFAULTTYPE_ENUM Rte_IRead_CDDInterface10_Per3_FETFaultType_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE10_APPL_CODE) CDDInterface10_Per3(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface10_Per3
 *********************************************************************************************************************/
	VAR(uint16, AUTOMATIC) WriteBuffer_Cnt_T_u16;
	VAR(FETPHASETYPE_ENUM, AUTOMATIC) FETFaultPhase_Cnt_T_enum;
	VAR(FETFAULTTYPE_ENUM, AUTOMATIC) FETFaultType_Cnt_T_enum;
	
	WriteBuffer_Cnt_T_u16 = (CDD_AppDataFbkPthAccessBfr_Cnt_G_u16 & 1U)^1U;

	FETFaultPhase_Cnt_T_enum = Rte_IRead_CDDInterface10_Per3_FETFaultPhase_Cnt_enum();
	FETFaultType_Cnt_T_enum = Rte_IRead_CDDInterface10_Per3_FETFaultType_Cnt_enum();
	
	CDD_FETFaultType_Cnt_G_enum[WriteBuffer_Cnt_T_u16] = FETFaultType_Cnt_T_enum;
	CDD_FETFaultPhase_Cnt_G_enum[WriteBuffer_Cnt_T_u16] = FETFaultPhase_Cnt_T_enum;
	
	CDD_AppDataFbkPthAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_CDDINTERFACE10_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
