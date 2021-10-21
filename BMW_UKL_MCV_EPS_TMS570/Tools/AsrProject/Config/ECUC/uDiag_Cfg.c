
/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : uDiag_Cfg.c
* Module Description: Configuration file of uDiag module
* Product           : Gen II Plus - EA3.0
* Generator         : artt 2.0.2.0
* Generation Time   : 27.01.2013 14:54:17
*****************************************************************************/
/* Version Control:
 * Date Created:      Fri Jul 13 18:34:17 2012
 * %version:          1 %
 * %date_modified:    Mon Jan 28 12:39:55 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 09/17/12   1       JJW       Initial template creation
 * 10/04/12   2       JJW       Added support for link-time register value determination
 * 10/04/12   3       JJW       Corrected constant suffixes
 */
#define UDIAG_C
#include "uDiag.h"
#include "Nhet.h"
#include "Usr_RegCkDefs.h"

#define UDIAG_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */

/* uDiag Configuration Definitions */
CONST(uDiag_RegChkType, AUTOMATIC) StaticRegTable_Cnt_M_str[ D_NUMOFTESTEDREGS_CNT_U16 ] = {
/* Register value definitions determined Pre-compile */
	{0xFFFFFF48ul, 0x01010001ul},                                      /* GHVSRC */
	{0xFFFFFF50ul, 0x00000009ul},                                      /* RCLKSRC */
	{0xFFFFFFC4ul, 0x0000000Aul},                                      /* BMMCR1 */
	{0xFFFFFFD0ul, 0x01010100ul},                                      /* CLKCNTL */
	{0xFFFF00A0ul, 0x00000000ul},                                      /* GLOBALCTRL1 */
	{0xFFFFEB10ul, 0x01010000ul},                                      /* PINMMR00 */
	{0xFFFFEB14ul, 0x01010100ul},                                      /* PINMMR01 */
	{0xFFFFEB18ul, 0x01010101ul},                                      /* PINMMR02 */
	{0xFFFFEB1Cul, 0x01010001ul},                                      /* PINMMR03 */
	{0xFFFFEB20ul, 0x01010101ul},                                      /* PINMMR04 */
	{0xFFFFEB24ul, 0x01010101ul},                                      /* PINMMR05 */
	{0xFFFFEB28ul, 0x01010101ul},                                      /* PINMMR06 */
	{0xFFFFEB2Cul, 0x01010101ul},                                      /* PINMMR07 */
	{0xFFFFEB30ul, 0x01010101ul},                                      /* PINMMR08 */
	{0xFFFFEB34ul, 0x01010101ul},                                      /* PINMMR09 */
	{0xFFFFEB38ul, 0x01010101ul},                                      /* PINMMR10 */
	{0xFFFFEB3Cul, 0x01010101ul},                                      /* PINMMR11 */
	{0xFFFFEB40ul, 0x01010101ul},                                      /* PINMMR12 */
	{0xFFFFEB44ul, 0x01010101ul},                                      /* PINMMR13 */
	{0xFFFFEB48ul, 0x01010101ul},                                      /* PINMMR14 */
	{0xFFFFEB4Cul, 0x01010101ul},                                      /* PINMMR15 */
	{0xFFFFEB50ul, 0x01010101ul},                                      /* PINMMR16 */
	{0xFFFFEB54ul, 0x01010101ul},                                      /* PINMMR17 */
	{0xFFFFEB58ul, 0x00010001ul},                                      /* PINMMR18 */
	{0xFFFFEB5Cul, 0x01010101ul},                                      /* PINMMR19 */
	{0xFFFFEB60ul, 0x01010101ul},                                      /* PINMMR20 */
	{0xFFFFEB64ul, 0x01010001ul},                                      /* PINMMR21 */
	{0xFFFFEB68ul, 0x01010101ul},                                      /* PINMMR22 */
	{0xFFFFEB6Cul, 0x00000001ul},                                      /* PINMMR23 */
	{0xFFFFEB70ul, 0x00000000ul},                                      /* PINMMR24 */
	{0xFFFFEB74ul, 0x00000000ul},                                      /* PINMMR25 */
	{0xFFFFEB78ul, 0x01010000ul},                                      /* PINMMR26 */
	{0xFFFFEB7Cul, 0x01010101ul},                                      /* PINMMR27 */
	{0xFFFFEB80ul, 0x01010101ul},                                      /* PINMMR28 */
	{0xFFFFEB84ul, 0x00000101ul},                                      /* PINMMR29 */
	{0xFFFFEB88ul, 0x00000001ul},                                      /* PINMMR30 */
	{0xFFF87000ul, 0x00000201ul},                                      /* FRDCNTL */
	{0xFFF87008ul, 0x000A060Aul},                                      /* FEDACTRL1 */
	{0xFFFFF800ul, 0x0005000Aul},                                      /* RAMCTRL_EVEN */
	{0xFFFFF804ul, 0x00000001ul},                                      /* RAMTHRESHOLD_EVEN */
	{0xFFFFF80Cul, 0x00000001ul},                                      /* RAMINTCTRL_EVEN */
	{0xFFFFF830ul, 0x00000005ul},                                      /* RAMTEST_EVEN */
	{0xFFFFF900ul, 0x0005000Aul},                                      /* RAMCTRL_ODD */
	{0xFFFFF904ul, 0x00000001ul},                                      /* RAMTHRESHOLD_ODD */
	{0xFFFFF90Cul, 0x00000001ul},                                      /* RAMINTCTRL_ODD */
	{0xFFFFF930ul, 0x00000005ul},                                      /* RAMTEST_ODD */
	{0xFFFFE580ul, 0x00000000ul},                                      /* PACT */
	{0xFFFFE604ul, 0x00000005ul},                                      /* STCGCR1 */
	{0xFFFFF604ul, 0x00000000ul},                                      /* CCMKEYR */
	{0xFFFFFF70ul, 0x00066800ul},                                      /* PLLCTL1 */
	{0xFFFFFF74ul, 0x3FC0723Dul},                                      /* PLLCTL2 */
	{0xFFFFE100ul, 0x60055F00ul},                                      /* PLLCTL3 */
	{0xFFFFEC00ul, 0x0000000Aul},                                      /* DCCGCTRL_DCC1 */
	{0xFFFFEC08ul, 0x00003CF0ul},                                      /* DCCCNT0SEED_DCC1 */
	{0xFFFFEC0Cul, 0x00001F40ul},                                      /* DCCVALID0SEED_DCC1 */
	{0xFFFFEC10ul, 0x00002710ul},                                      /* DCCCNT1SEED_DCC1 */
	{0xFFFFEC24ul, 0x0000A003ul},                                      /* DCCCNT1CLKSRC_DCC1 */
	{0xFFFFEC28ul, 0x00000000ul},                                      /* DCCCNT0CLKSRC_DCC1 */
	{0xFFFFF400ul, 0x0000000Aul},                                      /* DCCGCTRL_DCC2 */
	{0xFFFFF408ul, 0x00004BC8ul},                                      /* DCCCNT0SEED_DCC2 */
	{0xFFFFF40Cul, 0x000004B0ul},                                      /* DCCVALID0SEED_DCC2 */
	{0xFFFFF410ul, 0x000124F8ul},                                      /* DCCCNT1SEED_DCC2 */
	{0xFFFFF424ul, 0x0000A008ul},                                      /* DCCCNT1CLKSRC_DCC2 */
	{0xFFFFF428ul, 0x00000000ul},                                      /* DCCCNT0CLKSRC_DCC2 */
	{0xFFFFF500ul, 0x00000000ul},                                      /* ESMEEPAPR1 */
	{0xFFFFF508ul, 0x54080BC6ul},                                      /* ESMIESR1 */
	{0xFFFFF510ul, 0x00000800ul},                                      /* ESMILSR1 */
	{0xFFFFF534ul, 0x00003FFFul},                                      /* ESMLTCPR */
	{0xFFFFF540ul, 0x00000000ul},                                      /* ESMIEPSR4 */
	{0xFFFFF548ul, 0x40000020ul},                                      /* ESMIESR4 */
	{0xFFFFF550ul, 0x00000000ul},                                      /* ESMILSR4 */
	{0xFFFFFC00ul, 0x00000003ul},                                      /* RTIGCTRL */
	{0xFFFFFC04ul, 0x00000000ul},                                      /* RTITBCTRL */
	{0xFFFFFC80ul, 0x00000001ul},                                      /* RTISETINTENA */
	{0xFFFFFC90ul, 0xA98559DAul},                                      /* RTIDWDCTRL */
	{0xFFFFFC94ul, 0x00000035ul},                                      /* RTIDWDPRLD */
	{0xFFFFFCA4ul, 0x00000005ul},                                      /* RTIWWDRXNCTRL */
	{0xFFFFFCA8ul, 0x00000005ul},                                      /* RTIWWDSIZECTRL */
	{0xFE000008ul, 0x00000000ul},                                      /* CRC_CTRL1 */
	{0xFFFFFDF0ul, 0x0000000Aul},                                      /* PARCTL */
	{0xFFFFFE10ul, 0x00000003ul},                                      /* FIRQPR0_FIQ_IRQ */
	{0xFFFFFE14ul, 0x00000000ul},                                      /* FIRQPR1_FIQ_IRQ */
	{0xFFFFFE18ul, 0x00000000ul},                                      /* FIRQPR2_FIQ_IRQ */
	{0xFFFFFE80ul, 0x00013220ul},                                      /* CHANCTRL0 */
	{0xFFFFFEDCul, 0x03030303ul},                                      /* CHANCTRL1 */
	{0xFFFFF054ul, 0x1A010203ul},                                      /* DREQASI0 */
	{0xFFFFF058ul, 0x04050607ul},                                      /* DREQASI1 */
	{0xFFFFF05Cul, 0x08090A0Bul},                                      /* DREQASI2 */
	{0xFFFFF060ul, 0x0C0D0E0Ful},                                      /* DREQASI3 */
	{0xFFFFF094ul, 0x44440000ul},                                      /* PAR0 */
	{0xFFFFF098ul, 0x00000000ul},                                      /* PAR1 */
	{0xFFFFF1A8ul, 0x00000005ul},                                      /* DMAPCR */
	{0xFFFFF1B0ul, 0x000B0F0Dul},                                      /* DMAMPCTRL */
	{0xFFFFF1B8ul, 0xFE000060ul},                                      /* DMAMPROS */
	{0xFFFFF1BCul, 0xFE00006Ful},                                      /* DMAMPROE */
	{0xFFFFF1C0ul, 0xF07FFFFFul},                                      /* DMAMPR1S */
	{0xFFFFF1C4ul, 0xFFFFFFFFul},                                      /* DMAMPR1E */
	{0xFFFFF1C8ul, 0x00000000ul},                                      /* DMAMPR2S */
	{0xFFFFF1CCul, 0xFFFFFFFFul},                                      /* DMAMPR2E */
	{0xFFFFF1D0ul, 0x00000000ul},                                      /* DMAMPR3S */
	{0xFFFFF1D4ul, 0x00000000ul},                                      /* DMAMPR3E */
	{0xFFF7C004ul, 0x80140001ul},                                      /* ADOPMODECR_ADC1 */
	{0xFFF7C008ul, 0x00000004ul},                                      /* ADCLOCKCR_ADC1 */
	{0xFFF7C00Cul, 0x00000000ul},                                      /* ADCALCR_ADC1 */
	{0xFFF7C010ul, 0x00010031ul},                                      /* ADEVMODECR_ADC1 */
	{0xFFF7C014ul, 0x00010030ul},                                      /* ADG1MODECR_ADC1 */
	{0xFFF7C018ul, 0x00010030ul},                                      /* ADG2MODECR_ADC1 */
	{0xFFF7C01Cul, 0x00000000ul},                                      /* ADEVSRC_ADC1 */
	{0xFFF7C020ul, 0x00000000ul},                                      /* ADG1SRC_ADC1 */
	{0xFFF7C024ul, 0x00000000ul},                                      /* ADG2SRC_ADC1 */
	{0xFFF7C028ul, 0x00000000ul},                                      /* ADEVINTENA_ADC1 */
	{0xFFF7C02Cul, 0x00000000ul},                                      /* ADG1INTENA_ADC1 */
	{0xFFF7C030ul, 0x00000000ul},                                      /* ADG2INTENA_ADC1 */
	{0xFFF7C058ul, 0x001A001Bul},                                      /* ADBNDCR_ADC1 */
	{0xFFF7C05Cul, 0x00000002ul},                                      /* ADBNDEND_ADC1 */
	{0xFFF7C060ul, 0x00000006ul},                                      /* ADEVSAMP_ADC1 */
	{0xFFF7C064ul, 0x00000006ul},                                      /* ADG1SAMP_ADC1 */
	{0xFFF7C068ul, 0x00000006ul},                                      /* ADG2SAMP_ADC1 */
	{0xFFF7C078ul, 0x00000000ul},                                      /* ADEVSEL_ADC1 */
	{0xFFF7C07Cul, 0x0000C000ul},                                      /* ADG1SEL_ADC1 */
	{0xFFF7C080ul, 0x00003F65ul},                                      /* ADG2SEL_ADC1 */
	{0xFFF7C180ul, 0x0000000Aul},                                      /* ADPARCR_ADC1 */
	{0xFFF7C204ul, 0x80140001ul},                                      /* ADOPMODECR_ADC2 */
	{0xFFF7C208ul, 0x00000004ul},                                      /* ADCLOCKCR_ADC2 */
	{0xFFF7C20Cul, 0x00000000ul},                                      /* ADCALCR_ADC2 */
	{0xFFF7C210ul, 0x00010030ul},                                      /* ADEVMODECR_ADC2 */
	{0xFFF7C214ul, 0x00010038ul},                                      /* ADG1MODECR_ADC2 */
	{0xFFF7C218ul, 0x00010030ul},                                      /* ADG2MODECR_ADC2 */
	{0xFFF7C21Cul, 0x00000001ul},                                      /* ADEVSRC_ADC2 */
	{0xFFF7C220ul, 0x00000002ul},                                      /* ADG1SRC_ADC2 */
	{0xFFF7C224ul, 0x00000000ul},                                      /* ADG2SRC_ADC2 */
	{0xFFF7C228ul, 0x00000008ul},                                      /* ADEVINTENA_ADC2 */
	{0xFFF7C22Cul, 0x00000000ul},                                      /* ADG1INTENA_ADC2 */
	{0xFFF7C230ul, 0x00000000ul},                                      /* ADG2INTENA_ADC2 */
	{0xFFF7C258ul, 0x00020004ul},                                      /* ADBNDCR_ADC2 */
	{0xFFF7C25Cul, 0x00000002ul},                                      /* ADBNDEND_ADC2 */
	{0xFFF7C260ul, 0x00000006ul},                                      /* ADEVSAMP_ADC2 */
	{0xFFF7C264ul, 0x00000006ul},                                      /* ADG1SAMP_ADC2 */
	{0xFFF7C268ul, 0x00000006ul},                                      /* ADG2SAMP_ADC2 */
	{0xFFF7C278ul, 0x00000603ul},                                      /* ADEVSEL_ADC2 */
	{0xFFF7C27Cul, 0x0000E100ul},                                      /* ADG1SEL_ADC2 */
	{0xFFF7C280ul, 0x00000603ul},                                      /* ADG2SEL_ADC2 */
	{0xFFF7C380ul, 0x0000000Aul},                                      /* ADPARCR_ADC2 */
	{0xFFF7B800ul, 0x00010001ul},                                      /* HETGCR_HET1 */
	{0xFFF7B804ul, 0x00000700ul},                                      /* HETPFR_HET1 */
	{0xFFF7B81Cul, 0x00000000ul},                                      /* HETEXC1_HET1 */
	{0xFFF7B824ul, 0x00000000ul},                                      /* HETPRY_HET1 */
	{0xFFF7B82Cul, 0x00000000ul},                                      /* HETAND_HET1 */
	{0xFFF7B834ul, 0x00000000ul},                                      /* HETHRSH_HET1 */
	{0xFFF7B838ul, 0x00005E0Aul},                                      /* HETXOR_HET1 */
	{0xFFF7B83Cul, 0x00000001ul},                                      /* HETREQENS_HET1 */
	{0xFFF7B844ul, 0x00000000ul},                                      /* HETREQDS_HET1 */
	{0xFFF7B874ul, 0x0000000Aul},                                      /* HETPCR_HET1 */
	{0xFFF7B87Cul, 0x00000000ul},                                      /* HETPPR_HET1 */
	{0xFFF7B88Cul, 0x00000000ul},                                      /* HETLBPSEL_HET1 */
	{0xFFF7B890ul, 0x00050000ul},                                      /* HETLBPDIR_HET1 */
	{0xFFF7B894ul, 0x00000000ul},                                      /* HETPINDIS_HET1 */
	{0xFFF7B900ul, 0x00030001ul},                                      /* HETGCR_HET2 */
	{0xFFF7B904ul, 0x00000400ul},                                      /* HETPFR_HET2 */
	{0xFFF7B91Cul, 0x00000000ul},                                      /* HETEXC1_HET2 */
	{0xFFF7B924ul, 0x00000000ul},                                      /* HETPRY_HET2 */
	{0xFFF7B92Cul, 0x00000000ul},                                      /* HETAND_HET2 */
	{0xFFF7B934ul, 0x000000F4ul},                                      /* HETHRSH_HET2 */
	{0xFFF7B938ul, 0x00000000ul},                                      /* HETXOR_HET2 */
	{0xFFF7B93Cul, 0x00000000ul},                                      /* HETREQENS_HET2 */
	{0xFFF7B944ul, 0x00000000ul},                                      /* HETREQDS_HET2 */
	{0xFFF7B94Cul, 0x10000000ul},                                      /* HETDIR_HET2 */
	{0xFFF7B974ul, 0x0000000Aul},                                      /* HETPCR_HET2 */
	{0xFFF7B97Cul, 0x00000000ul},                                      /* HETPPR_HET2 */
	{0xFFF7B98Cul, 0x00000000ul},                                      /* HETLBPSEL_HET2 */
	{0xFFF7B990ul, 0x00050000ul},                                      /* HETLBPDIR_HET2 */
	{0xFFF7B994ul, 0x00000000ul},                                      /* HETPINDIS_HET2 */
	{0xFFF7A400ul, 0x00010000ul},                                      /* HTU__GC_HTU1 */
	{0xFFF7A42Cul, 0x00000000ul},                                      /* HTU__INTMAP_HTU1 */
	{0xFFF7A43Cul, 0x00000000ul},                                      /* HTU__BIM_HTU1 */
	{0xFFF7A44Cul, 0xFF4600D8ul},                                      /* HTU__MP1S_HTU1 */
	{0xFFF7A450ul, 0xFF4601CCul},                                      /* HTU__MP1E_HTU1 */
	{0xFFF7A454ul, 0x00000000ul},                                      /* HTU__DCTRL_HTU1 */
	{0xFFF7A464ul, 0x0000000Aul},                                      /* HTU__PCR_HTU1 */
	{0xFFF7A500ul, 0x00000000ul},                                      /* HTU__GC_HTU2 */
	{0xFFF7A504ul, 0x00000000ul},                                      /* HTU__CPENA_HTU2 */
	{0xFFF7A52Cul, 0x00000000ul},                                      /* HTU__INTMAP_HTU2 */
	{0xFFF7A53Cul, 0x00000000ul},                                      /* HTU__BIM_HTU2 */
	{0xFFF7A54Cul, 0x00000000ul},                                      /* HTU__MP1S_HTU2 */
	{0xFFF7A550ul, 0x00000000ul},                                      /* HTU__MP1E_HTU2 */
	{0xFFF7A554ul, 0x00000000ul},                                      /* HTU__DCTRL_HTU2 */
	{0xFFF7A564ul, 0x0000000Aul},                                      /* HTU__PCR_HTU2 */
	{0xFFF7A574ul, 0x00000000ul},                                      /* HTU__MP0S_HTU2 */
	{0xFFF7A578ul, 0x00000000ul},                                      /* HTU__MP0E_HTU2 */
	{0xFF4E0004ul, 0x00000000ul},                                      /* HTU_IFADDRB_HTU1 */
	{0xFF4E0008ul, 0x008000D8ul},                                      /* HTU_IHADDRCT_HTU1 */
	{0xFF4E000Cul, 0x00100001ul},                                      /* HTU_ITCOUNT_HTU1 */
	{0xFF4C0000ul, 0x00000000ul},                                      /* HTU_IFADDRA_HTU2 */
	{0xFF4C0004ul, 0x00000000ul},                                      /* HTU_IFADDRB_HTU2 */
	{0xFF4C0008ul, 0x00000000ul},                                      /* HTU_IHADDRCT_HTU2 */
	{0xFF4C000Cul, 0x00000000ul},                                      /* HTU_ITCOUNT_HTU2 */
	{0xFFF7BC00ul, 0x00000001ul},                                      /* GIOGCR0 */
	{0xFFF7BC08ul, 0x00000000ul},                                      /* GIOINTDET */
	{0xFFF7BC0Cul, 0x00000000ul},                                      /* GIOPOL */
	{0xFFF7BC34ul, 0x0000002Dul},                                      /* GIODIR_A_ */
	{0xFFF7BC54ul, 0x00000018ul},                                      /* GIODIR_B_ */
/* Register value definitions determined at Link-time */
	{0xFFFFFDF8ul, ((uint32)&VIM_Fallback)},                           /* FBPARERR */
	{0xFFF7A474ul, ((uint32)&Nhet_PwmControl_Cnt_G_str)},              /* HTU__MP0S_HTU1 */
	{0xFFF7A478ul, ((uint32)&Nhet_PwmControl_Cnt_G_str + 64ul)},       /* HTU__MP0E_HTU1 */
	{0xFF4E0000ul, ((uint32)&Nhet_PwmControl_Cnt_G_str)},              /* HTU_IFADDRA_HTU1 */
};


#define UDIAG_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */
