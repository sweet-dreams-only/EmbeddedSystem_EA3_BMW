#ifndef T1_APPINTERFACE_CFG_H
#define T1_APPINTERFACE_CFG_H

/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/
#include "T1_AppInterface.h"

#ifdef T1_CANINTERFACE
	#include "com.h"
	#include "Can.h"
	#include "Appl_Cbk.h"
#endif /* T1_CANINTERFACE */

#ifdef T1_DGNINTERFACE
	#if defined(VGEN_ENABLE_IL_VECTOR)
	#include "il_inc.h"
	#endif

	#include "GCP_driverInterface.h"
	#include "Cdc_User.h"
#endif /* T1_DGNINTERFACE */

/*----------------------------------------------------------------------------------*/
/*--- external declarations for global variables -----------------------------------*/
/*----------------------------------------------------------------------------------*/
#ifdef T1_DGNINTERFACE
	#define T1_START_SEC_NO_INIT_16
	#include "T1_MemMap.h"
	T1_EXTERN T1_uint16_t txFrameLength;
	#define T1_STOP_SEC_NO_INIT_16
	#include "T1_MemMap.h"

	#define T1_START_SEC_NO_INIT_8
	#include "T1_MemMap.h"
	T1_EXTERN GCP_txFrame_t txFrameBuffer;
	#define T1_STOP_SEC_NO_INIT_8
	#include "T1_MemMap.h"
#endif /* T1_DGNINTERFACE */


/*----------------------------------------------------------------------------------*/
/*--- macros and inline functions --------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#ifdef T1_CANINTERFACE
	#define D_I2CNXT_CNT_U08 			T1_Isr_I2c_ID
	#define D_OVERVOLTTHRESH_CNT_U08	T1_Isr_OvervoltThresh_ID
	#define D_FLSTST_CNT_U08			T1_FlsTst_CrcIrq_ID
	#define D_ESMH_CNT_U08				T1_Isr_ESMH_ID
	#define D_ESML_CNT_U08				T1_Isr_ESML_ID
	#define D_SPINXT1_CNT_U08 			T1_SpiNxt_IrqUnit2TxRx_ID
	#define D_SPINXT2_CNT_U08 			T1_SpiNxt_IrqUnit2TxRxERR_ID
	#define PollT1HostToTarget() (void)Com_ReceiveSignalGroup(T1_HostToTarget_Group)
#endif /* T1_CANINTERFACE */

#ifdef T1_DGNINTERFACE
	#define DCM_T1_ENABLE	STD_ON
	#define GCP_MAX_RX_FRAME_BYTES		32
	#define GCP_MAX_TX_FRAME_BYTES		32

	#define INC_T1_ERROR_COUNT() ( T1_errorCount < 255 ? ++T1_errorCount : T1_errorCount )
	#define PollT1HostToTarget()	{}
#endif /* T1_DGNINTERFACE */


#define D_GLIWAT1_SWITCHTOPRIVMODE_CNT_LGC	STD_ON
#define D_GLIWAT1_SLOWWAITSTATES_CNT_LGC	STD_ON /* slow here means 3dws 1aws. */

#endif
