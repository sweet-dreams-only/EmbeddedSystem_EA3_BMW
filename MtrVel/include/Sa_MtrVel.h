/**********************************************************************
*
*	Header %name:	Sa_MtrVel.h %
*	Instance:		sag_EPS_1
*	Description:	
*   %version:          3 %
*   %derived_by:       bz1q07 %
*   %date_modified:    Fri Feb 14 16:07:36 2014 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
* 06/12/13  2		 KJS		Added limit values for motorvel and hwvel cross checks so they can be 
*								shared between source modules. 
*
**********************************************************************/
#ifndef SA_MTRVEL_H
#define SA_MTRVEL_H

#include "Std_Types.h"

/* Component private variables */
#ifdef MTRVEL_C
	#define D_MTRVELOSBUFNUM_CNT_U08    4U /* 2 buffers required for algorithm, copies of buffers required for snapshot data results in 4 total buffers */
	#define D_MTRVELOSBUFSZ_CNT_U08     8U

	extern VAR(uint8, AUTOMATIC) MtrVel3_OsBufPos_Cnt_M_u08[D_MTRVELOSBUFNUM_CNT_U08];
	extern VAR(sint16, AUTOMATIC) MtrVel3_SinBuffer_Uls_M_s2p13[D_MTRVELOSBUFNUM_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];
	extern VAR(sint16, AUTOMATIC) MtrVel3_CosBuffer_Uls_M_s2p13[D_MTRVELOSBUFNUM_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];
	extern VAR(uint16, AUTOMATIC) MtrVel3_PosBuffer_Rev_M_u0p16[D_MTRVELOSBUFNUM_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];
	extern VAR(uint16, AUTOMATIC) MtrVel3_TimeBuffer_uS_M_u16p0[D_MTRVELOSBUFNUM_CNT_U08][D_MTRVELOSBUFSZ_CNT_U08];

	extern volatile VAR(uint8, AUTOMATIC) MtrVel_OsBufSelect_Cnt_M_u08;
#endif

/* Defines that are shared between the MtrVel source files */
#define D_MTRVELLOLMT_MTRRADPS_F32		(-1350.0F)
#define D_MTRVELHILMT_MTRRADPS_F32		1350.0F
#define D_HWVELLOLMT_HWRADPS_F32		(-42.0F)
#define D_HWVELHILMT_HWRADPS_F32		42.0F
#define D_4MS_SEC_F32					0.004F
#define D_ZERO_ULS_F32					0.0F

#endif
