/*****************************************************************************
* Copyright 2012 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : uDiag.h
* Module Description: Micro Diagnostic Common Header File
* Product           : Gen II Plus - EA3.0
* Author            : Lonnie Newton
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Tue May 31 09:10:25 2011 %
* %version:          1 %
* %derived_by:       cz7lt6 %
* %date_modified:    Mon Feb 18 09:16:31 2013 %
*---------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                        SCR #
* -------   -------  --------  ---------------------------------------------------------------------------  ----------
* 07/13/12  2        LWW       Defined UDIAG_COMPILER_ISR for isr declaration
* 07/19/12  3        LN        Added Channel Definitions														5769
* 09/18/12  4        JJW       Added inclusion of uDiag_Cfg.h
* 11/29/12  5        LWW       Added WdgResetHandler
*/

#ifndef U_DIAG_H
#define U_DIAG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* #include "uDiag_Cfg.h" Not needed for QAC */
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define D_NTCPARMBIT0_CNT_U8		0x01U
#define D_NTCPARMBIT1_CNT_U8		0x02U
#define D_NTCPARMBIT2_CNT_U8		0x04U
#define D_NTCPARMBIT3_CNT_U8		0x08U
#define D_NTCPARMBIT4_CNT_U8		0x10U
#define D_NTCPARMBIT5_CNT_U8		0x20U
#define D_NTCPARMBIT6_CNT_U8		0x40U
#define D_NTCPARMBIT7_CNT_U8		0x80U

#define D_ADC1_CNT_U8				0U
#define D_ADC2_CNT_U8				1U
#define D_DCAN1_CNT_U8				0U
#define D_DCAN2_CNT_U8				1U
#define D_DCC1_CNT_U8				0U
#define D_DCC2_CNT_U8				1U
#define D_EVENBANK_CNT_U8			0U
#define D_ODDBANK_CNT_U8			1U

#define UDIAG_COMPILER_ISR    interrupt

#define D_ADC2PARESMCHANNEL_CNT_U32			0x00000002U		/* Group 1 - Channel 1 */
#define D_DMAMPUESMCHANNEL_CNT_U32			0x00000004U		/* Group 1 - Channel 2 */
#define D_FMCCORESMCHANNEL_CNT_U32			0x00000040U		/* Group 1 - Channel 6 */
#define D_NHETPARESMCHANNEL_CNT_U32			0x00000080U		/* Group 1 - Channel 7 */
#define D_HTUPARESMCHANNEL_CNT_U32			0x00000100U		/* Group 1 - Channel 8 */
#define D_HTUMPUESMCHANNEL_CNT_U32			(0x00000200U)		/* Group 1 - Channel 9 */
#define D_CLCKMONINTESMCHANNEL_CNT_U32		0x00000800U		/* Group 1 - Channel 11 */
#define D_ADC1PARESMCHANNEL_CNT_U32			0x00080000U		/* Group 1 - Channel 19 */
#define D_DCAN1PARESMCHANNEL_CNT_U32		0x00200000U		/* Group 1 - Channel 21 */
#define D_DCAN2PARESMCHANNEL_CNT_U32		0x00800000U		/* Group 1 - Channel 23 */
#define D_RAMEVENCORESMCHANNEL_CNT_U32		0x04000000U		/* Group 1 - Channel 26 */
#define D_RAMODDCORESMCHANNEL_CNT_U32		0x10000000U		/* Group 1 - Channel 28 */
#define D_DCC1ESMCHANNEL_CNT_U32			0x40000000U		/* Group 1 - Channel 30 */
#define D_IOMMESMCHANNEL_CNT_U32			0x00000020U		/* Group 1 - Channel 37 */
#define D_DCC2ESMCHANNEL_CNT_U32			0x40000000U		/* Group 1 - Channel 62 */

#define D_CCMR4COMPESMCHANNEL_CNT_U32		0x00000004U		/* Group 2 - Channel 2 */
#define D_FMCUNCESMCHANNEL_CNT_U32			0x00000010U		/* Group 2 - Channel 4 */
#define D_RAMEVENUNCESMCHANNEL_CNT_U32		0x00000040U		/* Group 2 - Channel 6 */
#define D_RAMODDUNCESMCHANNEL_CNT_U32		0x00000100U		/* Group 2 - Channel 8 */
#define D_RAMEVENADDPARESMCHANNEL_CNT_U32	0x00000400U		/* Group 2 - Channel 10 */
#define D_RAMODDADDPARESMCHANNEL_CNT_U32	0x00001000U		/* Group 2 - Channel 12 */
#define D_ECCLIVELOCKESMCHANNEL_CNT_U32		0x00010000U		/* Group 2 - Channel 16 */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
FUNC(void, CD_UDIAG_APPL_CODE) NHETParityErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) HTUParityErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) HTUMPUErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) ADCParityErr(uint8 module);
FUNC(void, CD_UDIAG_APPL_CODE) DCANParityErr(uint8 module);
FUNC(void, CD_UDIAG_APPL_CODE) RAMParityErr(uint8 module);
FUNC(void, CD_UDIAG_APPL_CODE) IOMMErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) FlashECCCorrErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) RAMECCCorrErr(uint8 BANK);
FUNC(void, CD_UDIAG_APPL_CODE) FlashECCUncorrErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) RAMECCUncorrErr(uint8 BANK);
FUNC(void, CD_UDIAG_APPL_CODE) FlashECCLiveLockErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) ClockMonitorErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) DCCErr(uint8 module);
FUNC(void, CD_UDIAG_APPL_CODE) CCRMErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) DMAMPUErr(void);
FUNC(void, CD_UDIAG_APPL_CODE) WdgResetHandler(void);
#endif  /* U_DIAG_H */

/**********************************************************************************************************************
 *  END OF FILE: u_Diag.h
 *********************************************************************************************************************/
