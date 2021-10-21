/*************************************************************************************
*   FILE:           T1_AppInterface_Cfg.c
*
*   DESCRIPTION:    application specific interface functions for T1
*
*   $Author: nick $
*
*   $Revision: 15537 $
*
*   COPYRIGHT:      Gliwa GmbH | know- how in embedded software
*                   Weilheim i.OB.
*                   All rights reserved
*************************************************************************************/

/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/
#include "T1_AppInterface_Cfg.h"
#include "T1_AppInterface.h"
#include "ComStack_Types.h"


#ifdef T1_DGNINTERFACE
	#ifdef __TASKING__
	#pragma noclear
	#endif /* defined __TASKING__ */
	#include "T1_config.h"
	#include "GCP_driverInterface.h"
	#include "Cdc_Cfg.h"
	#include "Rte_dcm.h"
	#include <osek.h>
#endif /* T1_DGNINTERFACE */


/*----------------------------------------------------------------------------------*/
/*--- definitions of static variables ----------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#ifdef T1_ENABLE
	#ifdef T1_CANINTERFACE
		#define T1_START_SEC_NO_INIT_8
		#include "T1_MemMap.h"
			static uint8 Buffer_Cnt_T_u08[8u];
		#define T1_STOP_SEC_NO_INIT_8
		#include "T1_MemMap.h"
	#endif /* T1_CANINTERFACE */
#endif /* T1_ENABLE */

/*----------------------------------------------------------------------------------*/
/*--- external declarations for global variables -----------------------------------*/
/*----------------------------------------------------------------------------------*/

#ifdef T1_ENABLE
	#ifdef T1_DGNINTERFACE
		#define T1_START_SEC_NO_INIT_8
		#include "T1_MemMap.h"
			T1_uint8_t  T1_SEC_NO_INIT_8 T1_errorCount = 0u;
		#define T1_STOP_SEC_NO_INIT_8
		#include "T1_MemMap.h"

		/*
		 * To avoid an unnecessary reliance on dynamic memory allocation,
	     * our template allocates one global transmit buffer, large enough for
		 * the maximum transmit frame bytes. Also, a variable contains the length in bytes of the
		 * actual data content. When this length variable is set to 0, it denotes an empty buffer
		 * available for (re-)allocation.
		*/
		#define T1_START_SEC_NO_INIT_8
		#include "T1_MemMap.h"
			GCP_txFrame_t txFrameBuffer;
		#define T1_STOP_SEC_NO_INIT_8
		#include "T1_MemMap.h"

		/*
	     * ++++++
         * Ideally, do not define an additional copy of the transmit buffer here but rather
		 * directly use the transmit buffer already allocated by the diagnostic layer.
		 * However, to make this example more self-contained, and because some projects have
		 * required this approach, we define an additional copy of the transmit buffer.
		*/

		#define T1_START_SEC_NO_INIT_16
		#include "T1_MemMap.h"
			T1_uint16_t txFrameLength;
		#define T1_STOP_SEC_NO_INIT_16
		#include "T1_MemMap.h"

		#define T1_START_SEC_CONST_16
		#include "T1_MemMap.h"
			/* TODO: insert maximum frame sizes for Target->Host (Tx) and Host->Target (Rx) */
			const T1_uint16_t T1_maxTxFrameBytes T1_SEC_CONST_16 = 32u;
			const T1_uint16_t T1_maxRxFrameBytes T1_SEC_CONST_16 = 32u;
		#define T1_STOP_SEC_CONST_16
		#include "T1_MemMap.h"
	#endif /* T1_DGNINTERFACE */
#endif /* defined T1_ENABLE */


/*----------------------------------------------------------------------------------*/
/*--- definitions of global functions ----------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#ifdef T1_ENABLE
	#ifdef T1_DGNINTERFACE

		#define T1_START_SEC_CODE
		#include "T1_MemMap.h"

		GCP_txFrame_t * GCP_CODE GCP_TxBufferRequest( void )
		{
			if( 0u != txFrameLength )
			{
				/* Wait until buffer is free */
				return GCP_NULL;
			}
			else
			{
				return &txFrameBuffer;
			}
		}

		/*-------------------------------------------------------------------*/
		/*
		 * This function needs only be modified if a different buffering system is required.
		 * In this example, we ensure that the data is in our copy of the transmit buffer,
		 * txFrameBuffer, see comment ++++++ above.
		 */
		GCP_error_t GCP_CODE GCP_TransmitFrame( GCP_txFrame_t const *pData, GCP_uint16Least_t len )
		{
			GCP_uint16Least_t i; /* loop index */
			if( 0u != txFrameLength )
			{
				return GCP_TX_IN_PROGRESS;
			}
			else
			{
				if( pData != &txFrameBuffer )
				{
					/* Data not yet copied to txFrameBuffer, do it now */
					for( i = 0u; i < len; ++i )
					{
						txFrameBuffer.u8[i] = pData->u8[i];
					}
				}
			__asm( "" ); /* Prevent instruction re-ordering by optimizer */
			txFrameLength = (GCP_uint16_t)len; /* Transmit buffer is full */
			return GCP_OK;
			}
		}

		void T1_CODE T1_ContOHCallback( T1_uint8Least_t errMask )
		{

		}

		void T1_CODE T1_SuspendAllInterrupts(void )
		{
			SuspendAllInterrupts();
		}

		void T1_CODE T1_ResumeAllInterrupts(void )
		{
			ResumeAllInterrupts();
		}

		void T1_CODE T1_AppDisableT1Handler(void )
		{
			/* Do  Nothing */
		}

		void T1_CODE T1_AppEnableT1Handler(void )
		{
			/* Do  Nothing */
		}

		#define T1_STOP_SEC_CODE
		#include "T1_MemMap.h"
	#endif /* T1_DGNINTERFACE */
#endif /* T1_ENABLE */

#ifdef T1_ENABLE
	#ifdef T1_CANINTERFACE
		#define T1_START_SEC_CODE
		#include "T1_MemMap.h"

		/* Message reception handler. Pass all data back to T1.*/
		FUNC(void, COM_APPL_CODE) Appl_COMCbk_T1_HostToTarget_Group(void)
		{

			VAR(uint32, AUTOMATIC) CallerIsTrusted_Cnt_T_u32;

			CallerIsTrusted_Cnt_T_u32 = osSwitchToPrivMode();

			Com_ReceiveShadowSignal(T1_HostToTargetSig, &Buffer_Cnt_T_u08[0]);

			/* Parameter must be at module scope. */
			(void)T1_RxCallback((T1_rawData_t*)Buffer_Cnt_T_u08);

			if(0u == CallerIsTrusted_Cnt_T_u32)
			{
				osSwitchToUserMode();
			}

		}

		/* Called by T1 when it has data it wants to put on the bus. */
		T1_status_t T1_Transmit(T1_rawData_t const * pRawData)
		{
			T1_status_t RetVal_Cnt_T_Enum;
			PduInfoType Message_Cnt_T_Str;
			Std_ReturnType TransmitResult_Cnt_T_u08;
			uint8 RawData[8];

			RawData[0] = pRawData->d.u8[0];
			RawData[1] = pRawData->d.u8[1];
			RawData[2] = pRawData->d.u8[2];
			RawData[3] = pRawData->d.u8[3];
			RawData[4] = pRawData->d.u8[4];
			RawData[5] = pRawData->d.u8[5];
			RawData[6] = pRawData->d.u8[6];
			RawData[7] = pRawData->d.u8[7];


			Message_Cnt_T_Str.SduDataPtr = RawData;

			Message_Cnt_T_Str.SduLength = 8u;

			/* Send a raw message using exactly the data passed from T1. */
			TransmitResult_Cnt_T_u08 = CanIf_Transmit(0, &Message_Cnt_T_Str);

			/* Transmit the message on bus zero (HS). */
			if(E_OK == TransmitResult_Cnt_T_u08)
			{
				RetVal_Cnt_T_Enum = T1_OK;
			}
			else
			{
				RetVal_Cnt_T_Enum = T1_FAILED;
			}

			return RetVal_Cnt_T_Enum;
		}

		void T1_CODE T1_ContOHCallback( T1_uint8Least_t errMask )
		{

		}

		#define T1_STOP_SEC_CODE
		#include "T1_MemMap.h"
	#endif /* T1_CANINTERFACE */

	#else /* if T1_ENABLE is not defined */

	FUNC(void, COM_APPL_CODE) Appl_COMCbk_T1_HostToTarget_Group(void)
	{
		/* Do nothing. */
	}
#endif /* T1_ENABLE */




