/**********************************************************************
*
*	Header %name:	Sa_MtrPos.h %
*	Instance:		sag_EPS_1
*	Description:	
*	%created_by:	xz0btk %
*	%date_created:	Wed Feb 20 16:39:26 2013 %
*
**********************************************************************/
#ifndef _SA_MTRPOS_H
#define _SA_MTRPOS_H

#include "Rte_Type.h"
#include "Sa_MtrPos_Cfg.h"

#define D_MTRPOSDBLBUFFSZ_CNT_U08     2U

/* Component private variables */
#ifdef MTRPOS_C
extern CONSTP2VAR(MtrPosCal_DataType,  SA_MTRPOS_VAR, AUTOMATIC) MtrPos_EOLDataPtr_Cnt_M_Str;
extern VAR(float, AUTOMATIC) MtrPos3_DiagCorrectedMtrPos_Rev_M_f32;
extern VAR(float32, AUTOMATIC) MtrPos3_DiagMechMtrPos_Rev_M_f32;


/* Dual buffer accessors must be defined as volatile to ensure every write and
 * read of the variable is performed in the order specified in the software design.
 */

/* The following signal group is double buffered.  The buffer control signal is internal to this module
 * because the group of signals has no synchronization requirements with externally produced signals.
 */
extern volatile VAR(uint8, AUTOMATIC) MtrPos2_LearnedParamBfr_Cnt_M_u08;
extern VAR(uint16, AUTOMATIC) MtrPos2_Cos1RTAmpRec_Uls_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
extern VAR(uint16, AUTOMATIC) MtrPos2_Cos1RTOffset_Volts_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
extern VAR(uint16, AUTOMATIC) MtrPos2_Sin1RTAmpRec_Uls_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
extern VAR(uint16, AUTOMATIC) MtrPos2_Sin1RTOffset_Volts_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];

/* The following signal group is double buffered.  The buffer control signal is external to this module
 * because at least one of the signals has a synchronization requirement with signals produced
 * external to this module.  Therefore the signals must use a Globally supplied sync signal.
 */
extern VAR(uint16, AUTOMATIC) MtrPos_CorrectedMtrPos_Rev_M_u0p16[D_MTRPOSDBLBUFFSZ_CNT_U08];
extern VAR(uint16, AUTOMATIC) MtrPos_Cos1Scaled_Volts_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
extern VAR(uint16, AUTOMATIC) MtrPos_Sin1Scaled_Volts_M_u3p13[D_MTRPOSDBLBUFFSZ_CNT_U08];
extern VAR(uint16, AUTOMATIC) MtrPos_MechMtrPos_Rev_M_u0p16[D_MTRPOSDBLBUFFSZ_CNT_U08];
/* MtrPos_MtrRevCntr_Cnt_M_s16[D_MTRPOSDBLBUFFSZ_CNT_U08] is also part of this signal group,
 * but is read and written in MtrPos.c, so it is defined within MtrPos.c at a file scope. */
#endif

/* Component global CDD sender port variables written by the runnables scheduled in the motor control ISR */
extern VAR(sint16, AUTOMATIC) MtrPos_SinTheta1_Volts_G_s2p13;
extern VAR(sint16, AUTOMATIC) MtrPos_CosTheta1_Volts_G_s2p13;
extern VAR(uint16, AUTOMATIC) MtrPos_MechMtrPos_Rev_G_u0p16;
extern VAR(uint32, AUTOMATIC) MtrPos_SampleTime_uS_G_u32;
extern VAR(uint16, AUTOMATIC) MtrPos_CorrectedMtrPos_Rev_G_u0p16;

#endif
