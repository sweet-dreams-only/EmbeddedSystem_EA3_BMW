/**********************************************************************
*
*	Header %name:	Sa_MtrPos.h %
*	Instance:		sag_EPS_1
*	Description:	
*	%created_by:	bz1q07 %
*	%date_created:	Fri Feb 14 13:06:06 2014 %
*
**********************************************************************/
#ifndef _SA_MTRPOS_H
#define _SA_MTRPOS_H

/* Component global CDD sender port variables read by the runnables scheduled in the motor control ISR */
extern VAR(sint16, AUTOMATIC) MtrPos_SinTheta1_Volts_G_s2p13;
extern VAR(sint16, AUTOMATIC) MtrPos_CosTheta1_Volts_G_s2p13;
extern VAR(uint16, AUTOMATIC) MtrPos_MechMtrPos_Rev_G_u0p16;
extern VAR(uint32, AUTOMATIC) MtrPos_SampleTime_uS_G_u32;

#endif
