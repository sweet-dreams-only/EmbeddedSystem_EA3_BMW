/*****************************************************************************
* Copyright 2012 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Adc.c
* Module Description: ADC Unit 1 Complex Device Driver
* Product           : Gen II Plus - EA3.0
* Author            : Lonnie Newton
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 02 09:15:00 2012
* %version:          2 %
* %derived_by:       xz0btk %
* %date_modified:    Wed Jan 16 14:08:38 2013 %
*---------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Adc.h"
#include "Adc_Common.h"
#include "adc_regs.h"
#include "Ap_DiagMgr.h"
#include "CalConstants.h"
#include "SystemTime.h"
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define D_ADC1RSLTBASEADR_CNT_U32      (0xFF3E0000U) /* ADC1 result memory base address per TI spu499 */
#define D_ADC1NUMRSLTBUF_CNT_U08		64U	/* The number of result buffers is based on the value of BNDEND, which the
												FDD specifies to result in 64 buffers.  This number could become part of
												the configuration file if the use case arises */

/* Check that the ADC RAM allocation configuration is valid */
/* Is the sum of the buffers correct?, Is any buffer an odd number? */
#if (((D_ADC1EVTBUFSZ_CNT_U08 + D_ADC1G1BUFSZ_CNT_U08 + D_ADC1G2BUFSZ_CNT_U08) != D_ADC1NUMRSLTBUF_CNT_U08) || \
	(D_ADC1EVTBUFSZ_CNT_U08 & 1U) || (D_ADC1EVTBUFSZ_CNT_U08 & 1U) || (D_ADC1EVTBUFSZ_CNT_U08 & 1U))
	#error "Invalid Adc1 result RAM buffer allocation configuration: EVT, G1 and G2 allocation must sum to 64, and all must be even"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


#define ADC_START_SEC_CONST_32
#include "MemMap.h"
/* Module internal configuration data structure, post build configuration of this module not currently supported.
 * Thus the configuration structure is defined within the static source and initialized with values from the
 * configuration file.
 */

/* The T_Adc1GroupConfigData_Cnt_Str defines a group access structure of the configurable elements that need to be accessed
 *  for each group to perform Adc operations on the group or get the group status. This definition is convenient to allow
 *  the functions in this module to access the appropriate configuration using a group ID indexer.
 *  NOTE: register elements which are already defined with an equivalent index access in adc_regs.h are not included in this configuration
 *  structure because it is takes more FLASH memory resources to store the address of the register in this table and also
 *  requires more run-time to dereference the pointer in this table vs direct access.
 */
static CONST(Adc_GroupConfigDataType, ADC_PBCFG) T_Adc1GroupConfigData_Cnt_Str[3] =
{
	{	/* ADC1 Event Group */
		D_ADC1NUMEVTCH_CNT_U08,
		D_ADC1EVTCH_CNT_U32,
		&(((uint32*)D_ADC1RSLTBASEADR_CNT_U32)[0]),
	},
	{	/* ADC1 G1 Group */
		D_ADC1NUMG1CH_CNT_U08,
		D_ADC1G1CH_CNT_U32,
		&(((uint32*)D_ADC1RSLTBASEADR_CNT_U32)[D_ADC1EVTBUFSZ_CNT_U08]),
	},
	{	/* ADC1 G2 Group */
		D_ADC1NUMG2CH_CNT_U08,
		D_ADC1G2CH_CNT_U32,
		&(((uint32*)D_ADC1RSLTBASEADR_CNT_U32)[D_ADC1EVTBUFSZ_CNT_U08 + D_ADC1G1BUFSZ_CNT_U08]),
	}
};

#define ADC_STOP_SEC_CONST_32
#include "MemMap.h"

#define ADC_START_SEC_CODE
#include "MemMap.h"
/************************************************************************************************************************
  * Name:        Adc_Init_FixedCfg
  * Description: Non Autosar compliant API in that it has a fixed configuration. A remapping macro is provided in the
  * 			 Header which exposes the Api to allow mapping the Autosar Api to this function.
  * 			 Adc1 primary initialization and initial conversion trigger
  * Inputs:      ConfigPtr - Configuration structure for initializing the module
  * Outputs:     None
*************************************************************************************************************************/
FUNC(void, ADC_CODE) Adc_Init_FixedCfg()
{
	VAR(sint8, AUTOMATIC) i; /* use case of this indexer requires it to be signed */
	VAR(uint8, AUTOMATIC) Group_Cnt_T_u08;
	VAR(uint32, AUTOMATIC) convMask_Cnt_T_u32;

	/* ADC RAM Auto-Initialization is performed by Mcu_Init*/
	/* Parity Enabled by uDiag Component */

	/* Enable ADC for normal operation */
	adcREG1->OPMODECR = 0x80140001U;

	/* Configure the ADCLK Frequency (Vclk /(Prescale + 1))*/
	adcREG1->CLOCKCR = 4U;

	/* Assign the 64 words ADC FIFO RAM to three conversion Groups */
	adcREG1->BNDEND = 0x02U;
	/* Compute the result buffer boundaries based on the configured result RAM allocations */
	adcREG1->BNDCR  = ((D_ADC1EVTBUFSZ_CNT_U08 & 0xFEU) << 15) +
					  ((D_ADC1EVTBUFSZ_CNT_U08 + D_ADC1G1BUFSZ_CNT_U08) >> 1U);

	/* Configure the acquisition time (Value of 6 = 492nSec sample window)*/
	adcREG1->G0SAMP = 6U;
	adcREG1->G1SAMP = 6U;
	adcREG1->G2SAMP = 6U;

	/* Perform Offset Cancellation Configuration at Init */
	ADC1_REPORTERRORSTATUS(NTC_Num_PerDiag_ADC1Flt, D_NTCPARMBIT1_CNT_U8, (ADCOffsetCalibration(adcREG1)));

	/* Common Register Configuration */
	adcREG1->RSTCR = 0U;
	adcREG1->EVTDIR = 0U;
	adcREG1->EVTDIS = 0U;
	adcREG1->EVTPSEL = 0U;
	adcREG1->MAGINT1MASK = 0U;
	adcREG1->MAGINT2MASK = 0U;
	adcREG1->MAGINT3MASK = 0U;
	adcREG1->MAGINTCR1 = 0U;
	adcREG1->MAGINTCR2 = 0U;
	adcREG1->MAGINTCR3 = 0U;
	adcREG1->MAGTHRINTENASET = 0U;
	adcREG1->MAGTHRINTENACLR = 0x7U;

	/* Event Group Register Configuration (Currently Not Used) */
	adcREG1->G0SRC = 0U;
	adcREG1->GxINTENA[D_GROUPEV_CNT_U8] = 0U;
	adcREG1->GxINTCR[D_GROUPEV_CNT_U8] = 0U;
	adcREG1->G0SAMPDISEN = 0U;
	adcREG1->GxFIFORESETCR[D_GROUPEV_CNT_U8] = 0U;
	adcREG1->G0DMACR = 0U;
	adcREG1->GxMODECR[D_GROUPEV_CNT_U8] = 0x00010031U;

	/* Group 1 Register Configuration */
	adcREG1->G1SRC = 0U;
	adcREG1->GxINTENA[D_GROUP1_CNT_U8] = 0U;
	adcREG1->GxINTCR[D_GROUP1_CNT_U8] = 0U;
	adcREG1->G1SAMPDISEN = 0U;
	adcREG1->GxFIFORESETCR[D_GROUP1_CNT_U8] = 0U;
	adcREG1->G1DMACR = 0U;
	adcREG1->GxMODECR[D_GROUP1_CNT_U8] = 0x00010030U;

	/* Group 2 Register Configuration */
	adcREG1->G2SRC = 0U;
	adcREG1->GxINTENA[D_GROUP2_CNT_U8] = 0U;
	adcREG1->GxINTCR[D_GROUP2_CNT_U8] = 0U;
	adcREG1->G2SAMPDISEN = 0U;
	adcREG1->GxFIFORESETCR[D_GROUP2_CNT_U8] = 0U;
	adcREG1->G2DMACR = 0U;
	adcREG1->GxMODECR[D_GROUP2_CNT_U8] = 0x00010030U;

	/* Indirect initialization of Adc Ram buffer pointers.  There is no direct method to set the pointers
	 * and all pointers start at 0 after init.  This method is not mentioned in the FDD 34c rev007 and
	 * is included in this design as a patch until the FDD is updated to include the final design for
	 * buffer pointer initialization. */
	for(Group_Cnt_T_u08 = D_GROUP1_CNT_U8; Group_Cnt_T_u08 <= D_GROUP2_CNT_U8; Group_Cnt_T_u08++){
		i = D_ADC1EVTBUFSZ_CNT_U08 + (D_ADC1G1BUFSZ_CNT_U08 * (Group_Cnt_T_u08 - 1u) ); /* init to number of dummy conversions required, using a mathematical expression vs conditional to explicitly reduce branching */

		while(i > 0){
			convMask_Cnt_T_u32 = (1ul << (Min_m(i, 16u))) - 1ul; /* compute required conversion mask, up to 16 bits. */
			i -= 16; /* Decrement i by the max number of conversions, it is signed so a negative number will allow exiting the loop */
			adcREG1->GxSEL[Group_Cnt_T_u08] = convMask_Cnt_T_u32; /* Start the dummy conversion */
			while((adcREG1->GxSR[Group_Cnt_T_u08] & D_GROUPBUSY_CNT_U32) != 0U){
				/* wait */
			}
		}
	}

	/* Group Conversion at Init - Currently Performed by IoHwAb_Init */

}

/************************************************************************************************************************
  * Name:        Adc_StartGroupConversion
  * Description: This function starts a software triggered conversion of all channels of the requested Adc channel group
  * Inputs:      Group - Numeric Id of requested Adc channel group
  * Outputs:     None
*************************************************************************************************************************/
FUNC(void, ADC_CODE) Adc_StartGroupConversion(Adc_GroupType Group)
{
	/* Select Channels to Convert */
	adcREG1->GxSEL[Group] = T_Adc1GroupConfigData_Cnt_Str[Group].ChannelSelect;
}

/*************************************************************************************************************************
  * Name:        Adc_GetGroupStatus
  * Description: Returns the conversion status of the requested ADC1 channel group
  * Inputs:      Group - Numeric Id of requested Adc channel group
  * Outputs:     ReturnVal_Cnt_T_Enum - Conversion status for the requested group
*************************************************************************************************************************/
FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus(Adc_GroupType Group)
{
	VAR(uint32, AUTOMATIC) AdcStatusReg_Cnt_T_u32;
	VAR(Adc_StatusType, AUTOMATIC) ReturnVal_Cnt_T_Enum;


	AdcStatusReg_Cnt_T_u32 = adcREG1->GxSR[Group];

	if((AdcStatusReg_Cnt_T_u32 & D_GROUPBUSY_CNT_U32) != 0U)
	{
		ReturnVal_Cnt_T_Enum = ADC_BUSY;
	}
	else if((AdcStatusReg_Cnt_T_u32 & D_GROUPEND_CNT_U32) != 0U)
	{
		ReturnVal_Cnt_T_Enum = ADC_COMPLETED;
	}
	else
	{
		ReturnVal_Cnt_T_Enum = ADC_IDLE;
	}

	return (ReturnVal_Cnt_T_Enum);
}

/************************************************************************************************************************
  * Name:        Adc_ReadGroup
  * Description: Reads the group conversion result of the last completed conversion for the requested group and
  *               	stores the channel values starting at the DataBufferPtr address. The group channel values are stored in
  *               	ascending channel number order.
  * Inputs:      Group - Numeric Id of requested Adc channel group
  * 		     DataBufferPtr - ADC results of all channels of the selected group are stored in the data buffer
  *               	addressed with the pointer.
  * Outputs:     ReturnVal_Cnt_T_Enum - Conversion status for the requested group
*************************************************************************************************************************/
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupRefType DataBufferPtr)
{
	VAR(uint8, AUTOMATIC) ChCounter_Cnt_T_u08;
	VAR(Std_ReturnType, AUTOMATIC) ReturnVal_Cnt_T_u08;


	if((adcREG1->GxSR[Group] & D_GROUPEND_CNT_U32) != 0U)
	{
		/* Results are available. Group can be read. */
		for (ChCounter_Cnt_T_u08 = 0; ChCounter_Cnt_T_u08 < T_Adc1GroupConfigData_Cnt_Str[Group].NumOfChannels; ChCounter_Cnt_T_u08++)
		{
			/* Get Conversion Result and mask out the upper bits to remove the channel number if enabled */
			DataBufferPtr[ChCounter_Cnt_T_u08] = (Adc_ValueGroupType)( (T_Adc1GroupConfigData_Cnt_Str[Group].ResultBuf[ChCounter_Cnt_T_u08]) & D_MAXCONVERSIONVALUE_CNT_U16);
		}
		ReturnVal_Cnt_T_u08 = E_OK;
	}
	else
	{
		/* Group conversion incomplete, full group conversion results are not yet available */
		ReturnVal_Cnt_T_u08 = E_NOT_OK;
	}

	return(ReturnVal_Cnt_T_u08);
}

#define ADC_STOP_SEC_CODE
#include "MemMap.h" 

/*****************************************************************************

CHANGE HISTORY:

 Date      Rev      Author         Change Description              SCR #
-------   -------  --------  -----------------------------------  ----------
11/02/12   1.0      LN      	Initial Component Creation			CR6519
01/18/13   2      	JJW      	Updates per peer review
								Adc Ram pointer init workaround
******************************************************************************/
