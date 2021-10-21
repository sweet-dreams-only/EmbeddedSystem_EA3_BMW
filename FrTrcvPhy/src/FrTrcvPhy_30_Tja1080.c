/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2009 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  FrTrcv.c
 *    Component:  MICROSAR FR Transceiver Driver
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  FlexRay transceiver driver implementation, according to:
 *                AUTOSAR FlexRay Transceiver Driver, AUTOSAR Release 3.0
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Jun 14 09:14:52 2011
 * %version:          11 %
 * %derived_by:       cz7lt6 %
 * %date_modified:    Thu Jan 24 09:28:27 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 04/12/12   5       JJW       FDD 48 rev001 initial implementation
 * 04/25/12   6       BDO       Anomaly 3202 - always set *TrcvStatusWord = 0 (BUSTRCV_E_OK)
 * 05/10/12   7       BDO       Anomaly 3235 - correct FAILED not being called for NTC_Num_BusOffCh1
 * 10/08/12   8       JJW       Configurable Event Status Reporting to support Application mapping
 * 10/25/12   9       JWJ       Updated to FDD v004 - anom correction 3570/3336                                 6644
 * 10/27/12   10      SMW       Anomaly 3987 - Added N-step macro section 5.2.2 of FDD version 005
 * 01/23/13   11      KJS       Anomaly 4052,4089, and 4277 & Updated to FDD version 006
 */


/**************************************************************************************************
* Include files
**************************************************************************************************/
#include "FrTrcv_30_Tja1080.h"
#include "FrTrcvPhy_30_Tja1080.h"
#include "Spi.h"
#include "Rte_Type.h"
#include "CalConstants.h"
#include "GlobalMacro.h"
#include "SystemTime.h"
#include "fr_regs.h"

/**************************************************************************************************
* Defines / Constants
**************************************************************************************************/
#define D_FRSTATUSNUMBYTES_CNT_U16	2U
#define D_FRSTSVALIDMASK_CNT_U16    0x7800U
#define D_FRSTSVALIDVALUE_CNT_U16   0x5000U
#define D_FRSTSNTCSTSMASK_CNT_U16   0x7E00U
#define D_FRSTSNTCSTSSHIFT_CNT_U16  5U
#define D_POCS_ULS_U32              0x0000001FU
#define D_NORMALACTIVE_ULS_U08      0x02
#define D_BYTESHIFT_CNT_U16			8U

/* ERRn pin is active logic low, but software uses 1 as active error. Enum just
 * used to convert the pin logic to software logic */
enum PhyFrInvERRnLogic_enum {
	PhyFrERRn_NotActive	= FALSE,
	PhyFrERRn_Active 	= TRUE
};

#define FRTRCV_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ 

#if FRTRCV_TRCV_DIAGNOSIS == STD_ON
CONST(uint8, FRTRCV_CONST) FrTrcv_StatusMaskTableSize = sizeof(FrTrcv_StatusMaskTable) / sizeof(FrTrcv_StatusMaskTable[0]);

/* The following table contains the bit vectors for the respective failures */
CONST(FrTrcv_StatusWordType, FRTRCV_CONST) FrTrcv_StatusMaskTable[9] = 
{
  (FrTrcv_StatusWordType) FRTRCV_BUSERROR,
  (FrTrcv_StatusWordType) FRTRCV_TEMPHIGH,
  (FrTrcv_StatusWordType) FRTRCV_TEMPMEDIUM,
  (FrTrcv_StatusWordType) FRTRCV_TXEN_CLAMPED,
  (FrTrcv_StatusWordType) FRTRCV_UVVBAT,
  (FrTrcv_StatusWordType) FRTRCV_UVVCC,
  (FrTrcv_StatusWordType) FRTRCV_UVVIO,
  (FrTrcv_StatusWordType) FRTRCV_STARLOCKED,
  (FrTrcv_StatusWordType) FRTRCV_TRXDCOLLISION
};

/* This table contains the DEM error for each possible transceiver failure */
/*TODO: Initialize table based on the actual status word definition for the transceiver used by the ECU */
/*       The following definition is a workaround definition because it is not specified in the SER 03B */
/*       How to map the other fualt bits.     */                                                          

CONST(Dem_EventIdType, FRTRCV_CONST) FrTrcv_DEM_E_Table[9] = 
{
  (Dem_EventIdType)FR_PHYS_FAILURE,
  (Dem_EventIdType)FR_PHYS_FAILURE,
  (Dem_EventIdType)FR_PHYS_FAILURE,
  (Dem_EventIdType)FR_PHYS_FAILURE,
  (Dem_EventIdType)FR_PHYS_FAILURE,
  (Dem_EventIdType)FR_PHYS_FAILURE,
  (Dem_EventIdType)FR_PHYS_FAILURE,
  (Dem_EventIdType)FR_PHYS_FAILURE,
  (Dem_EventIdType)FR_PHYS_FAILURE
};

#endif

#define FRTRCV_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ 

#define FRTRCV_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */ 
STATIC VAR(boolean, FRTRCV_CODE) ErrPending_Cnt_M_lgc;
STATIC volatile VAR(boolean, FRTRCV_CODE) PhyFRERRn_Cnt_D_lgc;
#define FRTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h" /* PRQA S 5087 */

#define FRTRCV_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */ 
STATIC VAR(Spi_DataType, FRTRCV_CODE) FrSpiStatusBuf_Cnt_M_u08[D_FRSTATUSNUMBYTES_CNT_U16];
#define FRTRCV_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */


#define FRTRCV_START_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */
/* Spi API operates on an array of 8 bit elements, whereas the FDD requires a 16 bit dispaly variable for the ErrorInfo.
 * For portability reasons and MISRA compliance, a seperate buffer is used for the Spi driver use vs the display variable.  
 */
STATIC volatile VAR(uint16, FRTRCV_CODE) FrErrorInfo_Cnt_D_u16;
STATIC VAR(uint16, FRTRCV_CODE) FrTxcvrERRnAcc_Cnt_M_u16;
STATIC VAR(uint16, FRTRCV_CODE) FrTxcvrSPIAcc_Cnt_M_u16;
STATIC VAR(uint16, FRTRCV_CODE) FrErrorInfo_Cnt_M_u16;
#define FRTRCV_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h" /* PRQA S 5087 */


#define FRTRCV_START_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, FRTRCV_CODE) FrBusOffTmr_mS_M_u32;
#define FRTRCV_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h" /* PRQA S 5087 */

/**************************************************************************************************
* Macros
**************************************************************************************************/


/**************************************************************************************************
* Typedef and Struct definitions
**************************************************************************************************/
#if ( FRTRCV_WUPINT_CBK == STD_ON )
typedef P2FUNC( void, FRTRCV_CODE, trcvIcuFctPtrType )( Icu_ChannelType );
#endif


/**************************************************************************************************
* Data definitions
**************************************************************************************************/


/**************************************************************************************************
* Prototypes for local functions
**************************************************************************************************/
#define FRTRCV_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */

STATIC FUNC(void, FRTRCV_CODE) TrcvPhy_30_Tja1080_ERRnRead(P2VAR(boolean, AUTOMATIC, AUTOMATIC) ErrPending_Cnt_T_lgc);

/**************************************************************************************************
*  Implementation
**************************************************************************************************/

/**************************************************************************************************
   Function name    : TrcvPhy_30_Tja1080_TrcvInit
   ------------------------------------------------------------------------------------------------
   Description      : Initialize the FlexRay Transceiver
   ------------------------------------------------------------------------------------------------
   Called by        : FrTrcv
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The selected FlexRay bus transceiver
   ------------------------------------------------------------------------------------------------
   Returncode       : -
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(void, FRTRCV_CODE) TrcvPhy_30_Tja1080_TrcvInit( FRTRCV_CHANNEL_SYSTEMTYPE_ONLY )
{
	(void)Spi_SetupEB(SPI_FRSTATUS_CH, NULL_PTR, FrSpiStatusBuf_Cnt_M_u08, D_FRSTATUSNUMBYTES_CNT_U16);

	/* Blindly set the Transceiver Interface Fault as passed per discussions with M. Kushion.
	 * The FDD does not specifically address when to determine the fault test has passed.
	 * The sequence of events in the FDD does not contain an initializaiton SPI read so the
	 * test is only run when the ERRn pin is first asserted.  In order to avoid a situaiton where
	 * the Transceiver interface test is latchead as failed and also to avoid complicating
	 * the initializaiton sequence with an initial FRStatus read, this blind Test Pass call is 
	 * used.
	 */
	(void)FRTRCVPHY_REPORTERRORSTATUS( NTC_Num_TrcvrInterfaceFlt, D_ONE_CNT_U8, NTC_STATUS_PASSED );

	/* Added to put the initial value to a passing condition. On ERRn trigger, it will be updated
	 * by new SPI data.
	 */
	FrErrorInfo_Cnt_M_u16 = D_FRSTSVALIDVALUE_CNT_U16;
}


/**************************************************************************************************
   Function name    : TrcvPhy_30_Tja1080_SetMode
   ------------------------------------------------------------------------------------------------
   Description      : Service function to set the transceiver into a specific mode
   ------------------------------------------------------------------------------------------------
   Called by        : FrTrcv
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The transceiver to set into the requested mode
                      FrTrcv_TrcvMode: The operation mode
   ------------------------------------------------------------------------------------------------
   Returncode       : BusTrcvErrorType: BUSTRCV_E_OK: Initialization was successful
                                        BUSTRCV_E_ERROR: Transceiver could not be initialized
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) TrcvPhy_30_Tja1080_SetMode
(
  FRTRCV_CHANNEL_SYSTEMTYPE_ONLY,
  FrTrcv_TrcvModeType FrTrcv_TrcvMode
)
{
  /*Nxtr ECU does not support FlexRay mode Changes (i.e. STBN and wakeup pins are not connected to uP*/
  /* Always return E_OK to any request. */
  return((BusTrcvErrorType)BUSTRCV_E_OK);
}


/**************************************************************************************************
   Function name    : TrcvPhy_30_Tja1080_GetMode
   ------------------------------------------------------------------------------------------------
   Description      : Service function to set the transceiver into a specific mode
   ------------------------------------------------------------------------------------------------
   Called by        : FrTrcv
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The transceiver to set into the requested mode
                      FrTrcv_TrcvModePtr: The returned operation mode
   ------------------------------------------------------------------------------------------------
   Returncode       : BusTrcvErrorType: BUSTRCV_E_OK: Initialization was successful
                                        BUSTRCV_E_ERROR: Transceiver could not be initialized
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) TrcvPhy_30_Tja1080_GetMode
(
  FRTRCV_CHANNEL_SYSTEMTYPE_ONLY,
  P2VAR(FrTrcv_TrcvModeType, AUTOMATIC, FRTRCV_APPL_DATA) FrTrcv_TrcvModePtr
)
{ 
  /*Currently using the wrong drivers for the transceiver TJA1080 instead of TJA1082 */
  /* Always returning normal mode, since STBN is tied to VCC in EA3.0 CCA design     */
  *FrTrcv_TrcvModePtr = FRTRCV_TRCVMODE_NORMAL;

  return((BusTrcvErrorType)BUSTRCV_E_OK);
}



/**************************************************************************************************
   Function name    : TrcvPhy_30_Tja1080_ReadStatusWord
   ------------------------------------------------------------------------------------------------
   Description      : Service function to read the TJA1080 status word
   ------------------------------------------------------------------------------------------------
   Called by        : FrTrcv
   ------------------------------------------------------------------------------------------------
   Parameter        : FrTrcv_TrcvIdx: The transceiver to read the status word from
   ------------------------------------------------------------------------------------------------
   Returncode       : FrTrcv_StatusWordType: status word from the transceiver
   ------------------------------------------------------------------------------------------------
   Misc             : -
**************************************************************************************************/
FUNC(BusTrcvErrorType, FRTRCV_CODE) TrcvPhy_30_Tja1080_ReadStatusWord
(
  FRTRCV_CHANNEL_SYSTEMTYPE_ONLY,
  FrTrcv_StatusWordType *TrcvStatusWord
)
{
	VAR(uint8,  AUTOMATIC) NTCStatusByte_Cnt_T_u08;
	VAR(boolean, AUTOMATIC) PhyFRERRn_Cnt_T_lgc;
	VAR(uint32, AUTOMATIC) TimeElapsed_mS_T_u32;
	VAR(uint32, AUTOMATIC) CcsvReg_Cnt_T_u32;
	
	*TrcvStatusWord = BUSTRCV_E_OK;

	/* -- Read in ERRn pin -- */

	/* FlexRay error pin uses active low logic: Logic Low = TRUE (error active), Logic High = FALSE (error not active)
	 * For software use, FDD uses "true" to indicate an error, this block assigns the variable for software use */
	if( Dio_ReadChannel( FRTRCV_CHANNEL_ERRN_0) == ((Dio_LevelType)STD_LOW) )
	{
		PhyFRERRn_Cnt_T_lgc = PhyFrERRn_Active;
		FrTxcvrERRnAcc_Cnt_M_u16 = DiagPStep_m( FrTxcvrERRnAcc_Cnt_M_u16, k_FrTxcvrERRnDiag_Cnt_str );
	}
	else
	{
		PhyFRERRn_Cnt_T_lgc = PhyFrERRn_NotActive;
		FrTxcvrERRnAcc_Cnt_M_u16 = DiagNStep_m( FrTxcvrERRnAcc_Cnt_M_u16, k_FrTxcvrERRnDiag_Cnt_str );
	}

	/* Test point for Phy_FR_ERRn*/
	PhyFRERRn_Cnt_D_lgc = PhyFRERRn_Cnt_T_lgc;
	
	/* If the ERRn pin is active, read new SPI data, otherwise process the old data */
	if( (PhyFRERRn_Cnt_T_lgc == PhyFrERRn_Active) && (ErrPending_Cnt_M_lgc == FALSE) )
	{
		/* Start read of status register, analyze next run */
		(void)Spi_AsyncTransmit( SPI_FRSTATUS_SEQ );
		ErrPending_Cnt_M_lgc = TRUE;
	}
	else
	{
		TrcvPhy_30_Tja1080_ERRnRead(&ErrPending_Cnt_M_lgc);
	}

	/* Determine if the Bus Off fault needs to be set from ERRn pin */
	if( DiagFailed_m( FrTxcvrERRnAcc_Cnt_M_u16, k_FrTxcvrERRnDiag_Cnt_str ) == TRUE )
	{
		NTCStatusByte_Cnt_T_u08 = (uint8)((FrErrorInfo_Cnt_M_u16 & D_FRSTSNTCSTSMASK_CNT_U16) >> D_FRSTSNTCSTSSHIFT_CNT_U16);
		(void)FRTRCVPHY_REPORTERRORSTATUS( NTC_Num_BusOffCh1, NTCStatusByte_Cnt_T_u08, NTC_STATUS_FAILED );
	}

	/* -- Process CCSV -- */

	CcsvReg_Cnt_T_u32 = FRCCREGS->CCSV;

	if((CcsvReg_Cnt_T_u32 & D_POCS_ULS_U32) == D_NORMALACTIVE_ULS_U08)
	{
		/* Reset timing condition */
		GetSystemTime_mS_u32(&FrBusOffTmr_mS_M_u32);

		/* FDD requires this counter to be zero, and the CCSV to be valid to reset the bus off fault */
		if(FrTxcvrERRnAcc_Cnt_M_u16 == D_ZERO_CNT_U16)
		{
			(void)FRTRCVPHY_REPORTERRORSTATUS( NTC_Num_BusOffCh1, D_ONE_CNT_U8, NTC_STATUS_PASSED );
		}
	}
	else
	{
		DtrmnElapsedTime_mS_u32(FrBusOffTmr_mS_M_u32, &TimeElapsed_mS_T_u32);
		if(TimeElapsed_mS_T_u32 >= k_FrTxcvrBusOffTimer_ms_u16)
		{
			NTCStatusByte_Cnt_T_u08 = (uint8)((FrErrorInfo_Cnt_M_u16 & D_FRSTSNTCSTSMASK_CNT_U16) >> D_FRSTSNTCSTSSHIFT_CNT_U16);
			(void)FRTRCVPHY_REPORTERRORSTATUS( NTC_Num_BusOffCh1, NTCStatusByte_Cnt_T_u08, NTC_STATUS_FAILED );
		}
	}

	return((BusTrcvErrorType)BUSTRCV_E_OK);
}

/*****************************************************************
 * Function: TrcvPhy_30_Tja1080_ERRnRead
 *
 * Input: *ErrPending_Cnt_T_lgc
 *
 * Output: N/A
 *
 * This function handles the SPI data received from the ERRn pin
 *****************************************************************/
STATIC FUNC(void, FRTRCV_CODE) TrcvPhy_30_Tja1080_ERRnRead(P2VAR(boolean, AUTOMATIC, AUTOMATIC) ErrPending_Cnt_T_lgc)
{
	VAR(Spi_SeqResultType, AUTOMATIC) SpiReadStatus_Cnt_T_Enm;
	VAR(boolean, AUTOMATIC) ProcessData_Cnt_T_lgc = FALSE;

	SpiReadStatus_Cnt_T_Enm = Spi_GetSequenceResult(SPI_FRSTATUS_SEQ);

	if( (*ErrPending_Cnt_T_lgc == TRUE) && (SpiReadStatus_Cnt_T_Enm == SPI_SEQ_OK) ) /* Read Finished Successfully */
	{
		/* New SPI data was received, update module variables */
		*ErrPending_Cnt_T_lgc = FALSE;
		FrErrorInfo_Cnt_M_u16 = (uint16)((((uint16)(FrSpiStatusBuf_Cnt_M_u08[1])) << D_BYTESHIFT_CNT_U16) | ((uint16)(FrSpiStatusBuf_Cnt_M_u08[0])));
		ProcessData_Cnt_T_lgc = TRUE;
	}
	else if(*ErrPending_Cnt_T_lgc == FALSE)
	{
		/* No new SPI data, do not change module variables, but process old data again */
		ProcessData_Cnt_T_lgc = TRUE;
	}
	else
	{
		/* Do nothing */
	}

	if( ProcessData_Cnt_T_lgc == TRUE )
	{
		/* Update display variable */
		FrErrorInfo_Cnt_D_u16 = FrErrorInfo_Cnt_M_u16;

        /* FDD 48 v004 - SPI Logic and Diagnosis */
		if( (FrErrorInfo_Cnt_M_u16 & D_FRSTSVALIDMASK_CNT_U16) == D_FRSTSVALIDVALUE_CNT_U16 )
		{
			FrTxcvrSPIAcc_Cnt_M_u16 = DiagNStep_m( FrTxcvrSPIAcc_Cnt_M_u16, k_FrTxcvrSpiDiag_Cnt_str );

			if( FrTxcvrSPIAcc_Cnt_M_u16 == D_ZERO_CNT_U16 )
			{
				(void)FRTRCVPHY_REPORTERRORSTATUS( NTC_Num_TrcvrInterfaceFlt, D_ONE_CNT_U8, NTC_STATUS_PASSED );
			}
		}
		else
		{
			FrTxcvrSPIAcc_Cnt_M_u16 = DiagPStep_m( FrTxcvrSPIAcc_Cnt_M_u16, k_FrTxcvrSpiDiag_Cnt_str );
			
			if( DiagFailed_m(FrTxcvrSPIAcc_Cnt_M_u16, k_FrTxcvrSpiDiag_Cnt_str) == TRUE )
			{
				(void)FRTRCVPHY_REPORTERRORSTATUS( NTC_Num_TrcvrInterfaceFlt, D_ONE_CNT_U8, NTC_STATUS_FAILED );
			}
		}
	}
	else if( SpiReadStatus_Cnt_T_Enm != SPI_SEQ_PENDING ) /* Sequence is no longer pending and is not Ok */
	{
		(void)Spi_AsyncTransmit( SPI_FRSTATUS_SEQ );
	}
	else /* Read Pending */
	{
		/* Do Nothing, waiting for Spi driver to complete the read of the status word */
	}

	return;
}

#define FRTRCV_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */

