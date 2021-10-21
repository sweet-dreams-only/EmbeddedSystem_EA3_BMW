; Version Control:
; Date Created:      Mon Mar 19 13:59:02 2012 %
; %version:          1 %
; %derived_by:       cz7lt6 %
; %date_modified:    Mon Aug  6 15:26:06 2012 %
;---------------------------------------------------------------------------------------------------------------------
; Date      Rev      Author         Change Description                                                        SCR #
; -------   -------  --------  ---------------------------------------------------------------------------  ----------
; 03/19/12  1 		  LWW		Initial creation for anomaly correction
; 07/14/12  2 		  LWW		Chanded vector to point directly to ESMH ISR


   .ref Isr_ESMH


	.sect ".fiqarmvect"
fiqARMVectTable
	b Isr_ESMH    ; ESMH is only FIQ... branch there directly
