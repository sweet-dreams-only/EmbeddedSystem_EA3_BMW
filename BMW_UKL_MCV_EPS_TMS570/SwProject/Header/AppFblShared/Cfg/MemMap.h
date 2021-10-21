/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 by Vctr Informatik GmbH.                                              All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. 
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, Vctr Informatik's
 *                liability shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defines for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vctr Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component spesific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component spesific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all oems
 *                                              rename internal variables and filtermethods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXSubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *********************************************************************************************************************
 * Nxtr Change Log
 *********************************************************************************************************************
 * Version Control:
 * Date Created:      Thu Jan 20 11:18:06 2011
 * %version:          EA3#143 %
 * %date_modified:    Fri Jan  6 18:51:36 2012 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 2011-10-17   7      JJW       add defines for ASIL BD2 application and MtrPosCh2 component
 * 2011-12-06   8      JJW       add defines for HwTrq FDD04_008.1 component
 * 2011-12-12   10     JJW       add defines for RackLoad SF10_002.0 component
 * 2012-01-10   11     JJW       Update define defs for Channel 2, add defines for AssistCh2 SF01_001.0 SWC
 * 2012-01-10   12     JJW       add defines for AssistSumnLmtCh2 SF04_001.0 SWC
 * 2012-01-11   13     JJW       add defines for DampingCh2 SF03_001.1 SWC
 * 2012-01-11   14     JJW       add defines for ReturnCh2 SF02_001.2 SWC
 * 2012-01-12   15     JJW       add defines for VehPwrMd SWC
 * 2012-01-12   16     JJW       add defines for StOpCtrl SWC
 * 2012-01-12   18     JJW       Moved ASSISTSUMNLMTCH2 data to BD1 Application data area (i.e. default allocation)
 * 2012-01-12   19     JJW       Added ASSISTSUMNLMTCH2 memory mapping for integration of SFD04.001.3
 * 2012-01-20   20     JJW       VEHPWRMD Map updates for new component integration
 * 2012-01-24   21     JJW       ECCPRG Map updates for new component integration
 * 2012-01-24   22     JJW       HYSTCOMP Map updates for new component integration
 * 2012-02-01   23     JJW       METRICS Map updates for new component integration
 * 2012-02-02   24     JJW       add defines for CDDInterface and DIGPHSREASDIAG
 * 2012-02-27   24.1.1 JJW       POSSERVO Map updates for new component integration
 * 2012-02-27   24.1.2 JJW       LKTOLKSTR Map updates for new component integration
 * 2012-02-27   24.1.3 JJW       GENPOSTRAJ Map updates for new component integration
 * 2012-03-12   25     JJW       TURNSCOUNTER Map updates for new component integration
 * 2012-03-19   26     JJW       NVMPROXY Map updates for new component integration
 * 2012-03-28   27     JJW       TMPRLMON Map updates for new component integration
 * 2012-03-29   28     JJW       PARKASTENBL Map updates for new component integration
 * 2012-03-30   29     JJW       STAMD Map updates for new component integration
 * 2012-04-01   30     JJW       PRKASTMFGSERVCH2 Map updates for new component integration
 * 2012-04-01   31     JJW       PRKASTMFGSERVCH2 Map update correction for allocatin to CH2 partition
 * 2012-03-28   32     JJW       TMPRLMON Map updates for FDD19B_002.2 integration
 * 2012-04-13   33     JJW       FRTRCVPHY Map updates for FDD48_001.0 integration
 * 2012-05-09   34     JJW       FLTINJECTION Map updates for DF01_001.0 integration
 * 2012-05-09   35     JJW       ASSISTFIREWALL Map updates for SF34_001.0 integration and ASSISTCH2 removal
 * 2012-05-10   36     JJW       ASSISTSUMNLMTCH2 removal, ASSISTSUMNLMT updates for SF04_004.1 integration
 * 2012-05-10   37     JJW       RETURNCH2 removal, RETURNFIREWALL SF36_001.0 integration
 * 2012-05-10   38     JJW       DAMPINGCH2 removal, DAMPINGFIREWALL SF35_001.1 integration
 * 2012-05-29   39     JJW       ECCPRG Removal
 * 2012-06-08   40     JJW       ASSISTFIREWALL Map updates for SF34_003.0 integration
 * 2012-10-01   56     JJW       UDIAG Map updates for 000.8 integration
 * 								 GPT Map updates for Gpt 2.2.0 integration
 * 2012-10-03   57     JJW       Wdg MemMap include updates for new Wdg Stack integration
 * 2012-10-07   58     JJW       DiagMgr MemMap include updates for FDD37B_001.16 integration
 * 2012-10-12   59     JJW       MtrDrvDiag MemMap include updates for FDD15C_003.3 integration
 *									HwPwUp MemMap include for integration of FDD13B_001.1
 * 2012-10-16   60     JJW        MemMap updates to move the folloowing to Ap_7: SPINXT. TMPRLOMN, IOHWAB7,
 *									LKTOLKSTR, FLTINJECTION, GENPOSTRAJ, OSCTRAJ, PARKASTENBL, DRVDYNENBL, 
 *									POSSERVO, HWTRQ, MTRPOS, BATTERYVOLTAGE, SIGNLCONDN, DRVDYNCTRL, CTRLTEMP,
 *									CUSTPL, PWRLMTFUNC, MTRCURR, TUNINGSELAUTH, MTRTEMPEST, TURNSCOUNTER
 *								  Integrated NvMProxy FDD22_001.1
 * 									Added DIAGMGR7 MemMap sections
 *								  MemMap for CDDDATA10
 *								  MemMap for CALCONSTANTS Tunning structur pointers
 * 2012-10-21   61     JJW        StaMd FDD10B_10.0 integration
 * 2012-10-24   62     JJW        CurrentEst SF99_002.8_CE integration
 * 2012-10-26   63     BDO        SrlComInput and SrlComOutput integration    CR6627
 * 2012-10-30   64     JJW        NtWrap mapping
 * 2012-11-01   65     JJW        TMPRLMON FDD19B_007.1, UDIAG Allocation correction from 9 to 10
 * 2012-10-26   66     BDO        Add UNSPECIFIED section to SrlComOutput for ST_EST structure    CR6627
 * 2012-11-12   67     JJW        ASSISTFIREWALL SF34_006.2 integration and correction of Ap Data allocation on all
 *									firewall components to be Ap 10 instead of 8
 * 2012-14-12   68     JJW        HWTRQ FDD04A_008.0 integration
 * 2012-11-20   70     JJW        MTRPOSDIAG and MTRPOSSNSRLEARNING MemMap added
 * 2012-11-21   71     JJW        CDDDATA7 8 bit added
 * 2012-11-30   72     JJW        MtrVel FDD02B_008.0 MemMap added for MTRVEL and MTRVEL2
 *								  FRQDEPDMPNINRTCMP MemMap added
 *								  RACKLOAD MemMap added
 * 2012-12-04   73     JJW        FDD32B_TMS570_uDiag_000.16 and FDD32B_TMS570_Startup_000.9 integration
 * 2012-12-07   74     JJW        ResetCause mapping correction
 * 2013-01-10   79     JJW        FRTRCVR component integration
 * 2013-01-11   80     JJW        Ap_ApXcp integration
 * 2013-01-15   81     JJW        CBD Adc integration
 * 2013-01-22   82     JJW        CBD ShtdnMech integration
 * 2013-01-23   83     JJW        CBD Gsod integration
 * 2013-01-24   84     JJW        CBD PhaseDscnt integration
 * 2013-01-24   85     JJW        CBD MtrCtrl_VM integration
 * 2013-02-06   90     JJW        CBD MtrPos FDD06B_004.1 integration
 * 2013-08-06   91     JJW        CBD BVDiag integration, DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN coorrection
 * 2013-02-14   93     JJW        MtrVel FDD02B_010.4 integration global shared memmap change
 * 2013-02-15   94     KJS        Added ATAN2 statements, corrected BVDiag stop define. 
 * 2013-02-16	95     Selva      Added MTRVEL_START_SEC_VAR_CLEARED_8_GLOBALSHARED and 	
 *                                MTRVEL_STOP_SEC_VAR_CLEARED_8_GLOBALSHARED  for MtrVel FDD02B_010.5 Integration 
 * 2013-02-16	96     Selva      Revision log update for v-95 added.  
 * 2013-02-18	97     KJS	      CBD SVDrvr and Nhet integration.
 * 2013-02-18	98     KJS	      CBD SVDiag integration.
 * 2013-03-02	99     KJS	      CBD Damping integration.
 * 2013-03-03	100    KJS	      CBD Assist Sum and Limit Integration.
 * 2013-03-03	101    KJS	      CBD Assist Thermal Duty Cycle (Type H added).
 * 2013-03-07	102    KJS	      Added statements for VehPwrMd and VehCfg
 * 2013-03-15	103    KJS	      Added statements for turns counter, CDD_Data, and turns counter flashing.
 * 2013-03-18	104    KJS	      Added statements for DigPhsReasDiag
 * 2013-04-12	107    KJS	      Added statements for boolean Voltage Control
 * 2013-04-14	108    KJS	      Added statements for stability comp.
 * 2013-04-27	109    KJS	      Added statements for EOTActuatorMng, Return, and uDiag
 * 2013-05-21	110    JJW	      NHET Code and Var mapping
 * 2013-05-21	111    JJW	      Ap 10 variable mapping corrections for E2E, ABSHWPOS, ASSISTSUMNLMT, ETDMPFW, FLSTST,
 *									LMTCOD, PARAMCOMP, STOPCTRL. Removal of unused E2E mapping types for clarity.
 * 2013-05-21	112    JJW	      ECUSTARTUP mapping for Os config version display variable
 * 2013-05-22	113    KJS	      Removed E2EL code section from being included in variable section until better solution
 *									is found. Otherwise CRC and Alive counters will not work
 * 2013-05-24	114    JJW	      Added E2EPW Function level data section mapping to initialized variable section to 
 *                                 support mapping the funciton level constants (requiring initilaized memory) and 
 *                                 static variables (requiring RAM).
 * 2013-06-06	115    KJS	      Added support for StdMd8 16-bit values.
 * 2013-06-18	116    KJS	      Added support for new EOT damping firewall variables
 * 2013-07-11	117    KJS	      Added support for ApXCP variables.
 * 2013-09-14	118    KJS	      Added support for SrlComInput TypeH variable
 * 2013-10-07	119    KJS	      Added support for TJA Damping
 * 2013-11-12	120    KJS	      Updated support for CMS variables. 
 * 2014-01-14	122    KJS	      Updated LearnEOT and EOTActuMng to Ap_10 from Ap_9
 * 2014-01-17	123    KJS	      Added support for BkCpPc
 * 2014-01-17	124    KJS	      Added updates for TcFlshPrg (new revision)
 * 2014-01-17	126    KJS	      Added updates for Edch Phase 1
 * 2014-06-04	127    KJS	      Added updates for Edch Phase 2
 * 2014-09-02	128    KJS	      Removed CAL2 CVN table definition from memmap. Anomaly 7119
 * 2014-09-29	129    KJS	      Cleanup to move sections in the *.data to the proper mappings for upcoming FEE integration.
 * 2014-11-05	130    KJS	      Fee integration and moved ApXcp tune on the fly to its own section.
 * 2014-11-07	131    KJS	      Added new memmap statement for anomaly correction 7594
 * 2014-12-09	132    AS	      GliwaT1 component integration (FEE path)
 * 2015-09-11   133    ABS        Added updates for AvgFrcLrn and Active Pull Comp components
 * 2016-01-26   134    ABS        Added updates for BMW Haptic Feedback and Trq Osc components
 * 2016-01-27   135    ABS        Added updates for BMW Return Arbitration component
 * 2016-02-09   136    ABS        Added updates for TrqOsc and SignalConditioning components
 * 2016-03-09   137    ABS        Added updates for BMW Return Arbitration component
 * 2016-06-29   139    ABS        Added updates for SrlComInput component
 * 2016-08-31   140    RMV        Added updates for Dma, Udiag and Startup Component
 * 2016-10-05	142	   ABS		  Authentication and Signature changes - 2048bit key and SHA256 hash		 EA3#7986
 * 2017-05-26   143    SWI        Updates for Bmw Torque Overlay component									 EA3#12890
   *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#undef MEM_VENDOR_ID
#undef MEM_AR_MAJOR_VERSION
#undef MEM_AR_MINOR_VERSION
#undef MEM_AR_PATCH_VERSION
#undef MEM_SW_MAJOR_VERSION
#undef MEM_SW_MINOR_VERSION
#undef MEM_SW_PATCH_VERSION

#define MEM_VENDOR_ID        (30u)
#define MEM_AR_MAJOR_VERSION (1u)                      /* part of Autosare release 3.0.1 */
#define MEM_AR_MINOR_VERSION (1u)
#define MEM_AR_PATCH_VERSION (0u)

#define MEM_SW_MAJOR_VERSION (1u)
#define MEM_SW_MINOR_VERSION (5u)
#define MEM_SW_PATCH_VERSION (7u)

#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */

/* Include these prior to Rte_MemMap, because that file includes Os_MemMap */

#include "Wdg_MemMap.h"
#include "WdgM_MemMap.h"

/* include Rte MemMap because the Rte sections are configuration dependent*/
#include "Rte_MemMap.h"
#include "Bac_MemMap.h"

  /*CALCONSTANTS START*/
/* Variables */
#if defined CALCONSTANTS_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef CALCONSTANTS_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_7

#elif defined CALCONSTANTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef CALCONSTANTS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR	


/**************************************
 * ATan2 -- used for _atan2_asm_ functions
 ***********************************************/

#elif defined ATAN2_START_SEC_VAR_INIT_32
    #undef ATAN2_START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32_10

#elif defined ATAN2_STOP_SEC_VAR_INIT_32
    #undef ATAN2_STOP_SEC_VAR_INIT_32
    #define STOP_SEC_VAR


/**************************************
 * Application Net Interface
 ***********************************************/

#elif defined APPLNETINTERFACE_START_SEC_VAR_32
    #undef APPLNETINTERFACE_START_SEC_VAR_32
    #define START_SEC_VAR_INIT_32_9

#elif defined APPLNETINTERFACE_STOP_SEC_VAR_32
    #undef APPLNETINTERFACE_STOP_SEC_VAR_32
    #define STOP_SEC_VAR

/**************************************
 * Application Task
 ***********************************************/

#elif defined APPLTASKS_START_SEC_VAR_UNSPECIFIED
    #undef APPLTASKS_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined APPLTASKS_STOP_SEC_VAR_UNSPECIFIED
    #undef APPLTASKS_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined APPLTASKS_START_SEC_VAR_BOOLEAN
    #undef APPLTASKS_START_SEC_VAR_BOOLEAN
    #define START_SEC_VAR_INIT_BOOLEAN_9

#elif defined APPLTASKS_STOP_SEC_VAR_BOOLEAN
    #undef APPLTASKS_STOP_SEC_VAR_BOOLEAN
    #define STOP_SEC_VAR

#elif defined APPLTASKS_START_SEC_CONST_UNSPECIFIED
    #undef APPLTASKS_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined APPLTASKS_STOP_SEC_CONST_UNSPECIFIED
    #undef APPLTASKS_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST_UNSPECIFIED

/**************************************
 * BkCpPc
 ***********************************************/

#elif defined BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BKCPPC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined BKCPPC_START_SEC_VAR_CLEARED_32
    #undef BKCPPC_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined BKCPPC_STOP_SEC_VAR_CLEARED_32
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined BKCPPC_START_SEC_VAR_CLEARED_16
    #undef BKCPPC_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_7

#elif defined BKCPPC_STOP_SEC_VAR_CLEARED_16
    #undef BKCPPC_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR


/**************************************
 * BVDiag
 ***********************************************/

#elif defined BVDIAG_START_SEC_VAR_CLEARED_32
    #undef BVDIAG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined BVDIAG_STOP_SEC_VAR_CLEARED_32
    #undef BVDIAG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/**************************************
 * AP_SWEEP
 ***********************************************/

#elif defined SWEEP_START_SEC_VAR_CLEARED_32
    #undef SWEEP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_GLOBALSHARED

#elif defined SWEEP_STOP_SEC_VAR_CLEARED_32
    #undef SWEEP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined SWEEP_START_SEC_VAR_CLEARED_16
    #undef SWEEP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_GLOBALSHARED

#elif defined SWEEP_STOP_SEC_VAR_CLEARED_16
    #undef SWEEP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined SWEEP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef SWEEP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_GLOBALSHARED

#elif defined SWEEP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef SWEEP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
  /*CDDDATA7 START*/
/* Variables */
#elif defined CDDDATA7_START_SEC_VAR_NOINIT_32
    #undef CDDDATA7_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_7

#elif defined CDDDATA7_STOP_SEC_VAR_NOINIT_32
    #undef CDDDATA7_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR	

#elif defined CDDDATA7_START_SEC_VAR_NOINIT_16
    #undef CDDDATA7_START_SEC_VAR_NOINIT_16
    #define START_SEC_VAR_NOINIT_16_7

#elif defined CDDDATA7_STOP_SEC_VAR_NOINIT_16
    #undef CDDDATA7_STOP_SEC_VAR_NOINIT_16
    #define STOP_SEC_VAR	

#elif defined CDDDATA7_START_SEC_VAR_NOINIT_8
    #undef CDDDATA7_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8_7

#elif defined CDDDATA7_STOP_SEC_VAR_NOINIT_8
    #undef CDDDATA7_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR	

#elif defined CDDDATA7_START_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA7_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_NOINIT_BOOLEAN_7

#elif defined CDDDATA7_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA7_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR	

  /*CDDDATA9 START*/
/* Variables */
#elif defined CDDDATA9_START_SEC_VAR_NOINIT_32
    #undef CDDDATA9_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_9

#elif defined CDDDATA9_STOP_SEC_VAR_NOINIT_32
    #undef CDDDATA9_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR	

#elif defined CDDDATA9_START_SEC_VAR_NOINIT_16
    #undef CDDDATA9_START_SEC_VAR_NOINIT_16
    #define START_SEC_VAR_NOINIT_16_9

#elif defined CDDDATA9_STOP_SEC_VAR_NOINIT_16
    #undef CDDDATA9_STOP_SEC_VAR_NOINIT_16
    #define STOP_SEC_VAR	

#elif defined CDDDATA9_START_SEC_VAR_NOINIT_8
    #undef CDDDATA9_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8_9

#elif defined CDDDATA9_STOP_SEC_VAR_NOINIT_8
    #undef CDDDATA9_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR

#elif defined CDDDATA9_START_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA9_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_NOINIT_BOOLEAN_9

#elif defined CDDDATA9_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA9_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR	

  /*CDDDATA10 START*/
/* Variables */
#elif defined CDDDATA10_START_SEC_VAR_NOINIT_32
    #undef CDDDATA10_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined CDDDATA10_STOP_SEC_VAR_NOINIT_32
    #undef CDDDATA10_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR	

#elif defined CDDDATA10_START_SEC_VAR_NOINIT_16
    #undef CDDDATA10_START_SEC_VAR_NOINIT_16
    #define START_SEC_VAR_NOINIT_16_10

#elif defined CDDDATA10_STOP_SEC_VAR_NOINIT_16
    #undef CDDDATA10_STOP_SEC_VAR_NOINIT_16
    #define STOP_SEC_VAR	

#elif defined CDDDATA10_START_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA10_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_NOINIT_BOOLEAN_10

#elif defined CDDDATA10_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDDATA10_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR	
  /*CDDINTERFACE START*/

/* Variables */
/* To be used for all global or static variables that are never initialized */


#elif defined CDDINTERFACE10_START_SEC_VAR_NOINIT_8
    #undef CDDINTERFACE10_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined CDDINTERFACE10_STOP_SEC_VAR_NOINIT_8
    #undef CDDINTERFACE10_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR

#elif defined CDDINTERFACE10_START_SEC_VAR_NOINIT_32
    #undef CDDINTERFACE10_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined CDDINTERFACE10_STOP_SEC_VAR_NOINIT_32
    #undef CDDINTERFACE10_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

/* CDD Interface 9 */
#elif defined CDDINTERFACE9_START_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDINTERFACE9_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_NOINIT_BOOLEAN_9

#elif defined CDDINTERFACE9_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef CDDINTERFACE9_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR

/*CDDUSER START*/

#elif defined CDCUSER_START_SEC_VAR_CLEARED_8
    #undef CDCUSER_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined CDCUSER_STOP_SEC_VAR_CLEARED_8
    #undef CDCUSER_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined CDCUSER_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CDCUSER_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined CDCUSER_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CDCUSER_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined CDCUSER_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CDCUSER_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined CDCUSER_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CDCUSER_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined CDCUSER_START_SEC_VAR_CLEARED_32
    #undef CDCUSER_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined CDCUSER_STOP_SEC_VAR_CLEARED_32
    #undef CDCUSER_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CDCUSER_START_SEC_VAR_CLEARED_16
    #undef CDCUSER_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined CDCUSER_START_SEC_VAR_INIT_16
    #undef CDCUSER_START_SEC_VAR_INIT_16
    #define START_SEC_VAR_INIT_16_9

#elif defined CDCUSER_STOP_SEC_VAR_INIT_16
    #undef CDCUSER_STOP_SEC_VAR_INIT_16
    #define STOP_SEC_VAR

#elif defined CDCUSER_STOP_SEC_VAR_CLEARED_16
    #undef CDCUSER_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined CDCUSER_START_SEC_CONST_UNSPECIFIED
    #undef CDCUSER_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined CDCUSER_STOP_SEC_CONST_UNSPECIFIED
    #undef CDCUSER_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/*CDDUSER END*/




/*CURRENTEST START*/
/* Variables */
#elif defined CURRENTEST_START_SEC_VAR_CLEARED_32
    #undef CURRENTEST_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CURRENTEST_STOP_SEC_VAR_CLEARED_32
    #undef CURRENTEST_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR	
	
  /*DIGPHSREASDIAG START*/
/* Variables */
/* To be used for all global or static variables that are never initialized */
#elif defined DIGPHSREASDIAG_START_SEC_VAR_32
    #undef DIGPHSREASDIAG_START_SEC_VAR_32
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_11

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_32
    #undef DIGPHSREASDIAG_STOP_SEC_VAR_32
    #define STOP_SEC_VAR
	
/* AbsHwPos */
#elif defined ABSHWPOS_START_SEC_CONST_8
    #undef ABSHWPOS_START_SEC_CONST_8
    #define START_SEC_CONST_8BIT

#elif defined ABSHWPOS_STOP_SEC_CONST_8
    #undef ABSHWPOS_STOP_SEC_CONST_8
    #define STOP_SEC_CONST

#elif defined ABSHWPOS_START_SEC_VAR_8
    #undef ABSHWPOS_START_SEC_VAR_8
    #define START_SEC_VAR_NOINIT_8_10


#elif defined ABSHWPOS_STOP_SEC_VAR_8
    #undef ABSHWPOS_STOP_SEC_VAR_8
    #define STOP_SEC_VAR

#elif defined ABSHWPOS_START_SEC_VAR_16
    #undef ABSHWPOS_START_SEC_VAR_16
    #define START_SEC_VAR_NOINIT_16_10

#elif defined ABSHWPOS_STOP_SEC_VAR_16
    #undef ABSHWPOS_STOP_SEC_VAR_16
    #define STOP_SEC_VAR

#elif defined ABSHWPOS_START_SEC_VAR_32
    #undef ABSHWPOS_START_SEC_VAR_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined ABSHWPOS_STOP_SEC_VAR_32
    #undef ABSHWPOS_STOP_SEC_VAR_32
    #define STOP_SEC_VAR

#elif defined ABSHWPOS_START_SEC_VAR_UNSPECIFIED
    #undef ABSHWPOS_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined ABSHWPOS_STOP_SEC_VAR_UNSPECIFIED
    #undef ABSHWPOS_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR

/* Assist Start */
#elif defined ASSIST_START_SEC_VAR_CLEARED_16
    #undef ASSIST_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined ASSIST_STOP_SEC_VAR_CLEARED_16
    #undef ASSIST_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
/* Assist End */



  /*ASSISTFIREWALL START*/
/* Variables */
#elif defined ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
		
#elif defined ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
		
#elif defined ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ASSISTFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ASSISTFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

  /*ASSISTSUMNLMT START*/
/* Variables */
#elif defined ASSISTSUMNLMT_START_SEC_VAR_CLEARED_32
    #undef ASSISTSUMNLMT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined ASSISTSUMNLMT_STOP_SEC_VAR_CLEARED_32
    #undef ASSISTSUMNLMT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined ASSISTSUMNLMT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ASSISTSUMNLMT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined ASSISTSUMNLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ASSISTSUMNLMT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined ASSISTSUMNLMT_START_SEC_VAR_CLEAREDGS_32
    #undef ASSISTSUMNLMT_START_SEC_VAR_CLEAREDGS_32
    #define START_SEC_VAR_CLEARED_32_GLOBALSHARED

#elif defined ASSISTSUMNLMT_STOP_SEC_VAR_CLEAREDGS_32
    #undef ASSISTSUMNLMT_STOP_SEC_VAR_CLEAREDGS_32
    #define STOP_SEC_VAR

/* AVERAGE FRICTION LEARNING START */
/* Variables */

#elif defined AVGFRICLRN_START_SEC_VAR_CLEARED_32
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef AVGFRICLRN_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef AVGFRICLRN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR


/* ACTIVE PULL COMPENSATION START */
/* Variables */

#elif defined ACTIVEPULL_START_SEC_VAR_CLEARED_32
    #undef ACTIVEPULL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined ACTIVEPULL_STOP_SEC_VAR_CLEARED_32
    #undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined ACTIVEPULL_START_SEC_VAR_CLEARED_16
    #undef ACTIVEPULL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined ACTIVEPULL_STOP_SEC_VAR_CLEARED_16
    #undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined ACTIVEPULL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef ACTIVEPULL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined ACTIVEPULL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined ACTIVEPULL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ACTIVEPULL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined ACTIVEPULL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef ACTIVEPULL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/* Type H Variables */
#elif defined ACTIVEPULL_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:ActivePull")

    #undef ACTIVEPULL_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR

#elif defined ACTIVEPULL_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef ACTIVEPULL_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR
	
  /*BATTERYVOLTAGE START*/
/* Variables */
#elif defined BATTERYVOLTAGE_START_SEC_VAR_CLEARED_32
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_32
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined BATTERYVOLTAGE_START_SEC_VAR_CLEARED_16
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_7

#elif defined BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_16
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined BATTERYVOLTAGE_START_SEC_VAR_CLEARED_BOOLEAN
    #undef BATTERYVOLTAGE_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef BATTERYVOLTAGE_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  BmwHaptcFb START
 *********************************************************************************************************************/
#elif defined BMWHAPTCFB_START_SEC_VAR_CLEARED_8
    #undef BMWHAPTCFB_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined BMWHAPTCFB_STOP_SEC_VAR_CLEARED_8
    #undef BMWHAPTCFB_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined BMWHAPTCFB_START_SEC_VAR_CLEARED_16
    #undef BMWHAPTCFB_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined BMWHAPTCFB_STOP_SEC_VAR_CLEARED_16
    #undef BMWHAPTCFB_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined BMWHAPTCFB_START_SEC_VAR_CLEARED_32
    #undef BMWHAPTCFB_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined BMWHAPTCFB_STOP_SEC_VAR_CLEARED_32
    #undef BMWHAPTCFB_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined BMWHAPTCFB_START_SEC_VAR_CLEARED_BOOLEAN
    #undef BMWHAPTCFB_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined BMWHAPTCFB_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef BMWHAPTCFB_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
    
#elif defined BMWHAPTCFB_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BMWHAPTCFB_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined BMWHAPTCFB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BMWHAPTCFB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
    
/**********************************************************************************************************************
 *  Bmw Torque Overlay Conditioning START
 *********************************************************************************************************************/

#elif defined BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_10

#elif defined BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_32
    #undef BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_32
    #undef BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_8
    #undef BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_8
    #undef BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef BMWTQOVRLCDNG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_32_10

#elif defined BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef BMWTQOVRLCDNG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
    

/**********************************************************************************************************************
 *  Bmw Return Arbitration START
 *********************************************************************************************************************/
#elif defined BmwRtnArbn_START_SEC_VAR_CLEARED_32
    #undef BmwRtnArbn_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined BmwRtnArbn_STOP_SEC_VAR_CLEARED_32
    #undef BmwRtnArbn_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined BmwRtnArbn_START_SEC_VAR_CLEARED_BOOLEAN
    #undef BmwRtnArbn_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_32_9

#elif defined BmwRtnArbn_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef BmwRtnArbn_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined BmwRtnArbn_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BmwRtnArbn_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined BmwRtnArbn_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef BmwRtnArbn_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR



  /*CTRLTEMP START*/
/* Variables */
#elif defined CTRLTEMP_START_SEC_VAR_CLEARED_16
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_7

#elif defined CTRLTEMP_STOP_SEC_VAR_CLEARED_16
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
	
#elif defined CTRLTEMP_START_SEC_VAR_CLEARED_32
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined CTRLTEMP_STOP_SEC_VAR_CLEARED_32
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
	
#elif defined CTRLTEMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CTRLTEMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined CTRLTEMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CTRLTEMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

  /*CTRLDISSHTDN START*/
#elif defined CTRLDDISSHTDN_START_SEC_VAR_CLEARED_32
    #undef CTRLDDISSHTDN_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_32
    #undef CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
	
#elif defined CTRLDDISSHTDN_START_SEC_VAR_CLEARED_16
    #undef CTRLDDISSHTDN_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_16
    #undef CTRLDDISSHTDN_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
/* Variables */


  /*CUSTPL START*/
/* Variables */
#elif defined CUSTPL_START_SEC_VAR_CLEARED_32
    #undef CUSTPL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined CUSTPL_STOP_SEC_VAR_CLEARED_32
    #undef CUSTPL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined CUSTPL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef CUSTPL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined CUSTPL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef CUSTPL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR


#elif defined CUSTPL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CUSTPL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined CUSTPL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef CUSTPL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
		
  /*DAMPINGFIREWALL START*/
/* Variables */
#elif defined DAMPINGFIREWALL_START_SEC_VAR_CLEARED_32
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DAMPINGFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DAMPINGFIREWALL_START_SEC_VAR_CLEARED_16
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_16
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DAMPINGFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DAMPINGFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR


/* DemIf Start */

#elif defined DEMIF_START_SEC_CONST_8
    #undef DEMIF_START_SEC_CONST_8
    #define START_SEC_CONST_8BIT

#elif defined DEMIF_STOP_SEC_CONST_8
    #undef DEMIF_STOP_SEC_CONST_8
    #define STOP_SEC_CONST

/* DemIf End */


/* SRLCOMINPUT START */
/* Variables */
#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_32
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_16
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_8
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SRLCOMINPUT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined SRLCOMINPUT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SRLCOMINPUT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_32
	#define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_9:noinit:typeH:SrlComInput")

	#undef SRLCOMINPUT_START_SEC_VAR_SAVED_ZONEH_32
	#undef MEMMAP_ERROR

#elif defined SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef SRLCOMINPUT_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR

/* SRLCOMINPUT2 START */
/* Variables */
#elif defined SRLCOMINPUT2_START_SEC_VAR_CLEARED_32
    #undef SRLCOMINPUT2_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_32
    #undef SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT2_START_SEC_VAR_CLEARED_16
    #undef SRLCOMINPUT2_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_16
    #undef SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT2_START_SEC_VAR_CLEARED_8
    #undef SRLCOMINPUT2_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_8
    #undef SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT2_START_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMINPUT2_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined SRLCOMINPUT2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SRLCOMINPUT2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SRLCOMINPUT2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
/* SRLCOMOUTPUT START */
/* Variables */
#elif defined SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
    #undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
    #undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT_START_SEC_VAR_CLEARED_16
    #undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_16
    #undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT_START_SEC_VAR_CLEARED_8
    #undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_8
    #undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMOUTPUT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMOUTPUT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/* SRLCOMOUTPUT2 START */
/* Variables */
#elif defined SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_32
    #undef SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_32
    #undef SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_16
    #undef SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_16
    #undef SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_8
    #undef SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_8
    #undef SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMOUTPUT2_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef SRLCOMOUTPUT2_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined SRLCOMOUTPUT2_START_SEC_VAR_UNSPECIFIED
    #undef SRLCOMOUTPUT2_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined SRLCOMOUTPUT2_STOP_SEC_VAR_UNSPECIFIED
    #undef SRLCOMOUTPUT2_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  Damping START
 *********************************************************************************************************************/

#elif defined DAMPING_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPING_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined DAMPING_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DAMPING_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DAMPING_START_SEC_VAR_CLEARED_32
    #undef DAMPING_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined DAMPING_STOP_SEC_VAR_CLEARED_32
    #undef DAMPING_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DAMPING_START_SEC_VAR_CLEARED_16
    #undef DAMPING_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined DAMPING_STOP_SEC_VAR_CLEARED_16
    #undef DAMPING_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  Damping END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DiagMgr START
 *********************************************************************************************************************/
/* NvM */

/* Allocate DiagMgr NvM Blocks to Global Shared Memory */
#elif defined DIAGMGR_START_SEC_VAR_SAVED_ZONEH_UNSPECIFIED        
    #define VAR_SEC_OPEN
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef DIAGMGR_START_SEC_VAR_SAVED_ZONEH_UNSPECIFIED        
    #undef MEMMAP_ERROR

#elif defined DIAGMGR_STOP_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #undef DIAGMGR_STOP_SEC_VAR_SAVED_ZONEH_UNSPECIFIED
    #define STOP_SEC_VAR


/* Variables */
#elif defined DIAGMGR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef DIAGMGR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED

#elif defined DIAGMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef DIAGMGR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

	/*DiagMgr7*/
#elif defined DIAGMGR7_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR7_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_7

#elif defined DIAGMGR7_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR7_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIAGMGR7_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR7_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_7

#elif defined DIAGMGR7_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR7_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIAGMGR7_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR7_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined DIAGMGR7_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR7_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIAGMGR7_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR7_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined DIAGMGR7_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR7_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

	/*DiagMgr8*/
#elif defined DIAGMGR8_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_8

#elif defined DIAGMGR8_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIAGMGR8_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_8

#elif defined DIAGMGR8_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIAGMGR8_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_8

#elif defined DIAGMGR8_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIAGMGR8_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR8_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_8

#elif defined DIAGMGR8_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR8_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

	/*DiagMgr9*/
#elif defined DIAGMGR9_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined DIAGMGR9_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIAGMGR9_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined DIAGMGR9_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIAGMGR9_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined DIAGMGR9_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIAGMGR9_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR9_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined DIAGMGR9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

	/*DiagMgr10*/
#elif defined DIAGMGR10_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined DIAGMGR10_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIAGMGR10_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined DIAGMGR10_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIAGMGR10_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined DIAGMGR10_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIAGMGR10_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR10_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined DIAGMGR10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DIAGMGR_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef DIAGMGR_START_SEC_CONST_UNSPECIFIED

#elif defined DIAGMGR_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef DIAGMGR_STOP_SEC_CONST_UNSPECIFIED

	/*DiagMgr11*/
#elif defined DIAGMGR11_START_SEC_VAR_CLEARED_8
    #undef DIAGMGR11_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_11

#elif defined DIAGMGR11_STOP_SEC_VAR_CLEARED_8
    #undef DIAGMGR11_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIAGMGR11_START_SEC_VAR_CLEARED_16
    #undef DIAGMGR11_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_11

#elif defined DIAGMGR11_STOP_SEC_VAR_CLEARED_16
    #undef DIAGMGR11_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIAGMGR11_START_SEC_VAR_CLEARED_32
    #undef DIAGMGR11_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_11

#elif defined DIAGMGR11_STOP_SEC_VAR_CLEARED_32
    #undef DIAGMGR11_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIAGMGR11_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR11_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_11

#elif defined DIAGMGR11_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef DIAGMGR11_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined DIAGMGR_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef DIAGMGR_START_SEC_CONST_UNSPECIFIED

#elif defined DIAGMGR_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef DIAGMGR_STOP_SEC_CONST_UNSPECIFIED

/**********************************************************************************************************************
 *  DiagMgr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  digPhsReasDiag START
 *********************************************************************************************************************/

#elif defined DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
	#undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_11

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
	#undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined DIGPHSREASDIAG_START_SEC_VAR_CLEARED_16
	#undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_11

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_16
	#undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
	#undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_11

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
	#undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined DIGPHSREASDIAG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGPHSREASDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_11

#elif defined DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DIGPHSREASDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  digPhsReasDiag END
 *********************************************************************************************************************/

/* DrvDynCntrl */
#elif defined DRVDYNCTRL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DRVDYNCTRL_START_SEC_VAR_CLEARED_BOOLEAN
 	 #define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined DRVDYNCTRL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DRVDYNCTRL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined DRVDYNCTRL_START_SEC_VAR_CLEARED_32
	#undef DRVDYNCTRL_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_7


#elif defined DRVDYNCTRL_STOP_SEC_VAR_CLEARED_32
	#undef DRVDYNCTRL_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* DrvDynEnbl START
*********************************************************************************************************************/

#elif defined DRVDYNENBL_START_SEC_VAR_CLEARED_BOOLEAN
	#undef DRVDYNENBL_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined DRVDYNENBL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef DRVDYNENBL_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined DRVDYNENBL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DRVDYNENBL_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined DRVDYNENBL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef DRVDYNENBL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* DrvDynEnbl END
*********************************************************************************************************************/

/**********************************************************************************************************************
* EcuStartup START
*********************************************************************************************************************/

#elif defined ECUSTARTUP_START_SEC_VAR_CLEARED_16
	#undef ECUSTARTUP_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_9

#elif defined ECUSTARTUP_STOP_SEC_VAR_CLEARED_16
	#undef ECUSTARTUP_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* EcuStartup END
*********************************************************************************************************************/

/**********************************************************************************************************************
* Edch START
*********************************************************************************************************************/

/* Constants from the Edch source file */
#elif defined EDCH_START_SEC_CONST_UNSPECIFIED
	#undef EDCH_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED

#elif defined EDCH_STOP_SEC_CONST_UNSPECIFIED
	#undef EDCH_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST

#elif defined EDCH_START_SEC_CONST_BOOLEAN
	#undef EDCH_START_SEC_CONST_BOOLEAN
	#define START_SEC_CONST_8BIT

#elif defined EDCH_STOP_SEC_CONST_BOOLEAN
	#undef EDCH_STOP_SEC_CONST_BOOLEAN
	#define STOP_SEC_CONST

#elif defined EDCH_START_SEC_CONST_8BIT
	#undef EDCH_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT

#elif defined EDCH_STOP_SEC_CONST_8BIT
	#undef EDCH_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST

#elif defined EDCH_START_SEC_CONST_CVNBLOCK_0
	#pragma SET_DATA_SECTION(".BootCvnDefTbl")
    #undef MEMMAP_ERROR
	#undef EDCH_START_SEC_CONST_CVNBLOCK_0

/* Constants from the Edch configuration for CVN block references */
#elif defined EDCH_STOP_SEC_CONST_CVNBLOCK_0
	#undef EDCH_STOP_SEC_CONST_CVNBLOCK_0
	#define STOP_SEC_VAR

#elif defined EDCH_START_SEC_CONST_CVNBLOCK_1
	#pragma SET_DATA_SECTION(".AppCvnDefTbl")
    #undef MEMMAP_ERROR
	#undef EDCH_START_SEC_CONST_CVNBLOCK_1

#elif defined EDCH_STOP_SEC_CONST_CVNBLOCK_1
	#undef EDCH_STOP_SEC_CONST_CVNBLOCK_1
	#define STOP_SEC_VAR

#elif defined EDCH_START_SEC_CONST_CVNBLOCK_2
	#pragma SET_DATA_SECTION(".Cal1CvnDefTbl")
    #undef MEMMAP_ERROR
	#undef EDCH_START_SEC_CONST_CVNBLOCK_2

#elif defined EDCH_STOP_SEC_CONST_CVNBLOCK_2
	#undef EDCH_STOP_SEC_CONST_CVNBLOCK_2
	#define STOP_SEC_VAR

/* Variable section */
#elif defined EDCH_START_SEC_VAR_NOINIT_UNSPECIFIED
	#undef EDCH_START_SEC_VAR_NOINIT_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_9

#elif defined EDCH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#undef EDCH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
	#define STOP_SEC_VAR

#elif defined EDCH_START_SEC_VAR_BOOLEAN
	#undef EDCH_START_SEC_VAR_BOOLEAN
	#define START_SEC_VAR_NOINIT_BOOLEAN_9

#elif defined EDCH_STOP_SEC_VAR_BOOLEAN
	#undef EDCH_STOP_SEC_VAR_BOOLEAN
	#define STOP_SEC_VAR

#elif defined EDCH_START_SEC_VAR_NOINIT_8BIT
	#undef EDCH_START_SEC_VAR_NOINIT_8BIT
	#define START_SEC_VAR_NOINIT_8_9

#elif defined EDCH_STOP_SEC_VAR_NOINIT_8BIT
	#undef EDCH_STOP_SEC_VAR_NOINIT_8BIT
	#define STOP_SEC_VAR

#elif defined EDCH_START_SEC_VAR_NOINIT_16BIT
	#undef EDCH_START_SEC_VAR_NOINIT_16BIT
	#define START_SEC_VAR_NOINIT_16_9

#elif defined EDCH_STOP_SEC_VAR_NOINIT_16BIT
	#undef EDCH_STOP_SEC_VAR_NOINIT_16BIT
	#define STOP_SEC_VAR

/* Application Code */
#elif defined EDCH_START_SEC_APPL_CODE
	#undef EDCH_START_SEC_APPL_CODE
	#define START_SEC_CODE

#elif defined EDCH_STOP_SEC_APPL_CODE
	#undef EDCH_STOP_SEC_APPL_CODE
	#define STOP_SEC_CODE

#elif defined EDCH_START_SEC_CODE
	#undef EDCH_START_SEC_CODE
	#define START_SEC_CODE

#elif defined EDCH_STOP_SEC_CODE
	#undef EDCH_STOP_SEC_CODE
	#define STOP_SEC_CODE


/**********************************************************************************************************************
* Edch END
*********************************************************************************************************************/


/**********************************************************************************************************************
* ElecPwr START
*********************************************************************************************************************/

#elif defined ELECPWR_START_SEC_VAR_CLEARED_32
	#undef ELECPWR_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_9

#elif defined ELECPWR_STOP_SEC_VAR_CLEARED_32
	#undef ELECPWR_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* ElecPwr END
*********************************************************************************************************************/


/* EOTActuatorMng START */
#elif defined EOTACTUATORMNG_START_SEC_VAR_CLEARED_32
	#undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_32
	#undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined EOTACTUATORMNG_START_SEC_VAR_CLEARED_BOOLEAN
	#undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined EOTACTUATORMNG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef EOTACTUATORMNG_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef EOTACTUATORMNG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/* EOTActuatorMng STOP */


/* ETDMPFW Start */
#elif defined ETDMPFW_START_SEC_VAR_CLEARED_32
	#undef ETDMPFW_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined ETDMPFW_STOP_SEC_VAR_CLEARED_32
	#undef ETDMPFW_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined ETDMPFW_START_SEC_VAR_CLEARED_08
	#undef ETDMPFW_START_SEC_VAR_CLEARED_08
	#define START_SEC_VAR_CLEARED_8_10

#elif defined ETDMPFW_STOP_SEC_VAR_CLEARED_08
	#undef ETDMPFW_STOP_SEC_VAR_CLEARED_08
	#define STOP_SEC_VAR

#elif defined ETDMPFW_START_SEC_VAR_CLEARED_BOOLEAN
	#undef ETDMPFW_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined ETDMPFW_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef ETDMPFW_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/* ETDMPFW Stop */

/**********************************************************************************************************************
* EPSDiagSrvcs START
*********************************************************************************************************************/

#elif defined EPSDIAGSRVC_START_SEC_CONST_8
	#undef EPSDIAGSRVC_START_SEC_CONST_8
	#define START_SEC_CONST_8BIT

#elif defined EPSDIAGSRVC_STOP_SEC_CONST_8
	#undef EPSDIAGSRVC_STOP_SEC_CONST_8
	#define STOP_SEC_CONST
	
#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR	

#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_32
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_32
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR
	
#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_16
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_16
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_8
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_8
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR
	
#elif defined EPSDIAGSRVC_START_SEC_VAR_CLEARED_BOOLEAN
	#undef EPSDIAGSRVC_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef EPSDIAGSRVC_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* EPSDiagSrvcs END
*********************************************************************************************************************/

/**********************************************************************************************************************
* EPSDiagSrvcsXCP Start
*********************************************************************************************************************/

#elif defined EPSXCPSRVC_START_SEC_VAR_CLEARED_16
	#undef EPSXCPSRVC_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_9

#elif defined EPSXCPSRVC_STOP_SEC_VAR_CLEARED_16
	#undef EPSXCPSRVC_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* EPSDiagSrvcsXCP END
*********************************************************************************************************************/

/**********************************************************************************************************************
* FlsTst START
*********************************************************************************************************************/

#elif defined FLSTST_START_SEC_VAR_UNSPECIFIED
	#undef FLSTST_START_SEC_VAR_UNSPECIFIED
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_10


#elif defined FLSTST_STOP_SEC_VAR_UNSPECIFIED
#undef FLSTST_STOP_SEC_VAR_UNSPECIFIED
#define STOP_SEC_VAR


#elif defined FLSTST_START_SEC_VAR_16
#undef FLSTST_START_SEC_VAR_16
#define START_SEC_VAR_NOINIT_16_10


#elif defined FLSTST_STOP_SEC_VAR_16
#undef FLSTST_STOP_SEC_VAR_16
#define STOP_SEC_VAR


#elif defined FLSTST_START_SEC_VAR_CLEARED_8
#undef FLSTST_START_SEC_VAR_CLEARED_8
#define START_SEC_VAR_NOINIT_8_10


#elif defined FLSTST_STOP_SEC_VAR_CLEARED_8
#undef FLSTST_STOP_SEC_VAR_CLEARED_8
#define STOP_SEC_VAR


#elif defined FLSTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef FLSTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#define START_SEC_VAR_NOINIT_UNSPECIFIED_10


#elif defined FLSTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#undef FLSTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#define STOP_SEC_VAR



#elif defined FLSTST_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#undef FLSTST_START_SEC_CONST_UNSPECIFIED

#elif defined FLSTST_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR
#undef FLSTST_STOP_SEC_CONST_UNSPECIFIED


#elif defined FLSTST_START_SEC_CODE
#undef MEMMAP_ERROR
#undef FLSTST_START_SEC_CODE

#elif defined FLSTST_STOP_SEC_CODE
#undef MEMMAP_ERROR
#undef FLSTST_STOP_SEC_CODE


/**********************************************************************************************************************
* FlsTst END
*********************************************************************************************************************/

/*FLTINJECTION START*/
/* Code is mapped with the FRTRCVPHY BSW */
/* Variables */
#elif defined FLTINJECTION_START_SEC_VAR_CLEARED_32
    #undef FLTINJECTION_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED /* Temp move from App7 to globalshare to perform fault injections */

#elif defined FLTINJECTION_STOP_SEC_VAR_CLEARED_32
    #undef FLTINJECTION_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR


#elif defined FLTINJECTION_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef FLTINJECTION_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED /* Temp move from App7 to globalshare to perform fault injections */

#elif defined FLTINJECTION_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef FLTINJECTION_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
	
/**********************************************************************************************************************
* FRQDEPDMPNINRTCMP START
*********************************************************************************************************************/

#elif defined FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_32
	#undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_9

#elif defined FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_32
	#undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_BOOLEAN
	#undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FRQDEPDMPNINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef FRQDEPDMPNINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* FRQDEPDMPNINRTCMP END
*********************************************************************************************************************/
	
/*FRTRCVPHY START*/
/* Code is mapped with the FRTRCVPHY BSW */
/* Variables */
#elif defined FRTRCV_START_SEC_VAR_CLEARED_BOOLEAN
    #undef FRTRCV_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_8_9

#elif defined FRTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef FRTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined FRTRCV_START_SEC_VAR_CLEARED_8
    #undef FRTRCV_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined FRTRCV_STOP_SEC_VAR_CLEARED_8
    #undef FRTRCV_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined FRTRCV_START_SEC_VAR_CLEARED_16
    #undef FRTRCV_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined FRTRCV_STOP_SEC_VAR_CLEARED_16
    #undef FRTRCV_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
	
#elif defined FRTRCV_START_SEC_VAR_CLEARED_32
    #undef FRTRCV_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined FRTRCV_STOP_SEC_VAR_CLEARED_32
    #undef FRTRCV_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
	
	
/*GENPOSTRAJ START*/
/* Variables */
#elif defined GENPOSTRAJ_START_SEC_VAR_CLEARED_32
    #undef GENPOSTRAJ_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined GENPOSTRAJ_STOP_SEC_VAR_CLEARED_32
    #undef GENPOSTRAJ_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined GENPOSTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef GENPOSTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined GENPOSTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef GENPOSTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/*GSOD START*/
/* Variables */
#elif defined GSOD_START_SEC_VAR_CLEARED_BOOLEAN
    #undef GSOD_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_8

#elif defined GSOD_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef GSOD_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/* HiLoadStall */
/* Variables */
#elif defined HILOADSTALL_START_SEC_VAR_CLEARED_32
    #undef HILOADSTALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined HILOADSTALL_STOP_SEC_VAR_CLEARED_32
    #undef HILOADSTALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined HILOADSTALL_START_SEC_VAR_CLEARED_16
    #undef HILOADSTALL_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined HILOADSTALL_STOP_SEC_VAR_CLEARED_16
    #undef HILOADSTALL_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  HwPwUp START
 *********************************************************************************************************************/


/*******  VAR sections  **********************************************************************************************/

/* VAR sections */

#elif defined HWPWUP_START_SEC_VAR_CLEARED_UNSPECIFIED
	# undef HWPWUP_START_SEC_VAR_CLEARED_UNSPECIFIED
	# define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined HWPWUP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# undef HWPWUP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# define STOP_SEC_VAR
/**********************************************************************************************************************
 *  HwPwUp END
 *********************************************************************************************************************/

	
/* HwTrq */
#elif defined HWTRQ_START_SEC_VAR_CLEARED_32
	#undef HWTRQ_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_7

#elif defined HWTRQ_STOP_SEC_VAR_CLEARED_32
	#undef HWTRQ_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined HWTRQ_START_SEC_VAR_CLEARED_16
	#undef HWTRQ_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_7

#elif defined HWTRQ_STOP_SEC_VAR_CLEARED_16
	#undef HWTRQ_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined HWTRQ_START_SEC_VAR_CLEARED_8
	#undef HWTRQ_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_7

#elif defined HWTRQ_STOP_SEC_VAR_CLEARED_8
	#undef HWTRQ_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

	/* Type H Variables */
#elif defined HWTRQ_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit:typeH:HwTrq")

    #undef HWTRQ_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR

#elif defined HWTRQ_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef HWTRQ_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR

	
/* HwTrq2 */
#elif defined HWTRQ2_START_SEC_VAR_CLEARED_32
	#undef HWTRQ2_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_8

#elif defined HWTRQ2_STOP_SEC_VAR_CLEARED_32
	#undef HWTRQ2_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined HWTRQ2_START_SEC_VAR_CLEARED_16
	#undef HWTRQ2_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_8

#elif defined HWTRQ2_STOP_SEC_VAR_CLEARED_16
	#undef HWTRQ2_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined HWTRQ2_START_SEC_VAR_CLEARED_8
	#undef HWTRQ2_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_8

#elif defined HWTRQ2_STOP_SEC_VAR_CLEARED_8
	#undef HWTRQ2_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

	/* Type H Variables */
#elif defined HWTRQ2_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit:typeH:HwTrq2")

    #undef HWTRQ2_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR

#elif defined HWTRQ2_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef HWTRQ2_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR

/*HYSTCOMP START*/
/* Variables */
#elif defined HYSTCOMP_START_SEC_VAR_CLEARED_16
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined HYSTCOMP_STOP_SEC_VAR_CLEARED_16
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined HYSTCOMP_START_SEC_VAR_CLEARED_32
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined HYSTCOMP_STOP_SEC_VAR_CLEARED_32
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined HYSTCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef HYSTCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined HYSTCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef HYSTCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  IoHwAb7 START
 *********************************************************************************************************************/

#elif defined IOHWAB7_START_SEC_VAR_CLEARED_UNSPECIFIED
	# undef IOHWAB7_START_SEC_VAR_CLEARED_UNSPECIFIED
	# define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined IOHWAB7_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# undef IOHWAB7_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	# define STOP_SEC_VAR

#elif defined IOHWAB7_START_SEC_VAR_CLEARED_16
	# undef IOHWAB7_START_SEC_VAR_CLEARED_16
	# define START_SEC_VAR_CLEARED_16_7

#elif defined IOHWAB7_STOP_SEC_VAR_CLEARED_16
	# undef IOHWAB7_STOP_SEC_VAR_CLEARED_16
	# define STOP_SEC_VAR

#elif defined IOHWAB7_START_SEC_VAR_CLEARED_32
	# undef IOHWAB7_START_SEC_VAR_CLEARED_32
	# define START_SEC_VAR_CLEARED_32_7

#elif defined IOHWAB7_STOP_SEC_VAR_CLEARED_32
	# undef IOHWAB7_STOP_SEC_VAR_CLEARED_32
	# define STOP_SEC_VAR
#elif defined IOHWAB7_START_SEC_VAR_CLEARED_BOOLEAN
	# undef IOHWAB7_START_SEC_VAR_CLEARED_BOOLEAN
	# define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined IOHWAB7_STOP_SEC_VAR_CLEARED_BOOLEAN
	# undef IOHWAB7_STOP_SEC_VAR_CLEARED_BOOLEAN
	# define STOP_SEC_VAR
/**********************************************************************************************************************
 *  IoHwAb7 END
 *********************************************************************************************************************/

/*LKTOLKSTR START*/
/* Variables */
#elif defined LKTOLKSTR_START_SEC_VAR_CLEARED_32
    #undef LKTOLKSTR_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined LKTOLKSTR_STOP_SEC_VAR_CLEARED_32
    #undef LKTOLKSTR_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined LKTOLKSTR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef LKTOLKSTR_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined LKTOLKSTR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef LKTOLKSTR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined LKTOLKSTR_START_SEC_VAR_CLEARED_BOOLEAN
    #undef LKTOLKSTR_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined LKTOLKSTR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef LKTOLKSTR_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/* LMTCOD Start */
#elif defined LMTCOD_START_SEC_VAR_CLEARED_32
    #undef LMTCOD_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined LMTCOD_STOP_SEC_VAR_CLEARED_32
    #undef LMTCOD_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
/* LMTCOD End */

/**********************************************************************************************************************
 *  LnRkCr START
 *********************************************************************************************************************/
#elif defined LNRKCR_START_SEC_VAR_CLEARED_32
	# undef LNRKCR_START_SEC_VAR_CLEARED_32
	# define START_SEC_VAR_CLEARED_32_9

#elif defined LNRKCR_STOP_SEC_VAR_CLEARED_32
	# undef LNRKCR_STOP_SEC_VAR_CLEARED_32
	# define STOP_SEC_VAR
	
#elif defined LNRKCR_START_SEC_VAR_CLEARED_BOOLEAN
	# undef LNRKCR_START_SEC_VAR_CLEARED_BOOLEAN
	# define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined LNRKCR_STOP_SEC_VAR_CLEARED_BOOLEAN
	# undef LNRKCR_STOP_SEC_VAR_CLEARED_BOOLEAN
	# define STOP_SEC_VAR
/**********************************************************************************************************************
 *  LnRkCr END
 *********************************************************************************************************************/

/* LrnEOT */
#elif defined LRNEOT_START_SEC_VAR_CLEARED_32
    #undef LRNEOT_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined LRNEOT_STOP_SEC_VAR_CLEARED_32
    #undef LRNEOT_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined LRNEOT_START_SEC_VAR_CLEARED_BOOLEAN
    #undef LRNEOT_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined LRNEOT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef LRNEOT_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  MtrCurr START
 *********************************************************************************************************************/

/*******  VAR sections  **********************************************************************************************/

/* VAR sections */

#elif defined MTRCURR_START_SEC_VAR_CLEARED_32
# undef MTRCURR_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_7

#elif defined MTRCURR_STOP_SEC_VAR_CLEARED_32
# undef MTRCURR_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined MTRCURR_START_SEC_VAR_CLEARED_16
# undef MTRCURR_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_7

#elif defined MTRCURR_STOP_SEC_VAR_CLEARED_16
# undef MTRCURR_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined MTRCURR_START_SEC_VAR_CLEARED_BOOLEAN
# undef MTRCURR_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined MTRCURR_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef MTRCURR_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR

#elif defined MTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRCURR_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined MTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRCURR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MtrCurr END
 *********************************************************************************************************************/
	
	
/**********************************************************************************************************************
 *  MtrDrvDiag START
 *********************************************************************************************************************/


/*******  VAR sections  **********************************************************************************************/

/* VAR sections */

#elif defined MTRDRVDIAG_START_SEC_VAR_CLEARED_32
# undef MTRDRVDIAG_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_NOINIT_32_11

#elif defined MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
# undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined MTRDRVDIAG_START_SEC_VAR_CLEARED_16
# undef MTRDRVDIAG_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_NOINIT_16_11

#elif defined MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
# undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
# undef MTRDRVDIAG_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_NOINIT_BOOLEAN_11

#elif defined MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR

#elif defined MTRDRVDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRDRVDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_11

#elif defined MTRDRVDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRDRVDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MtrDrvDiag END
 *********************************************************************************************************************/
	
/**********************************************************************************************************************
 *  MtrTempEst START
 *********************************************************************************************************************/


/*******  VAR sections  **********************************************************************************************/

/* VAR sections */

#elif defined MTRTEMPEST_START_SEC_VAR_CLEARED_32
# undef MTRTEMPEST_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_7

#elif defined MTRTEMPEST_STOP_SEC_VAR_CLEARED_32
# undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined MTRTEMPEST_START_SEC_VAR_CLEARED_16
# undef MTRTEMPEST_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_7

#elif defined MTRTEMPEST_STOP_SEC_VAR_CLEARED_16
# undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined MTRTEMPEST_START_SEC_VAR_CLEARED_BOOLEAN
# undef MTRTEMPEST_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined MTRTEMPEST_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR

#elif defined MTRTEMPEST_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRTEMPEST_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined MTRTEMPEST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRTEMPEST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MtrTempEst END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  MtrVel START
 *********************************************************************************************************************/


/*******  VAR sections  **********************************************************************************************/

/* VAR sections */

#elif defined MTRVEL_START_SEC_VAR_CLEARED_32
# undef MTRVEL_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_10

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_32
# undef MTRVEL_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_CLEARED_16
# undef MTRVEL_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_10

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_16
# undef MTRVEL_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_CLEARED_BOOLEAN
# undef MTRVEL_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef MTRVEL_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRVEL_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRVEL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_NOINIT_BOOLEAN
# undef MTRVEL_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_BOOLEAN_10

#elif defined MTRVEL_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef MTRVEL_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_CLEARED_8
# undef MTRVEL_START_SEC_VAR_CLEARED_8
# define START_SEC_VAR_CLEARED_8_10

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_8
# undef MTRVEL_STOP_SEC_VAR_CLEARED_8
# define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_INIT_8_GLOBALSHARED
# undef MTRVEL_START_SEC_VAR_INIT_8_GLOBALSHARED
# define START_SEC_VAR_INIT_8_GLOBALSHARED

#elif defined MTRVEL_STOP_SEC_VAR_INIT_8_GLOBALSHARED
# undef MTRVEL_STOP_SEC_VAR_INIT_8_GLOBALSHARED
# define STOP_SEC_VAR

#elif defined MTRVEL_START_SEC_VAR_CLEARED_8_GLOBALSHARED
# undef MTRVEL_START_SEC_VAR_CLEARED_8_GLOBALSHARED
# define START_SEC_VAR_CLEARED_8_GLOBALSHARED

#elif defined MTRVEL_STOP_SEC_VAR_CLEARED_8_GLOBALSHARED
# undef MTRVEL_STOP_SEC_VAR_CLEARED_8_GLOBALSHARED
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  MtrVel END
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  MtrVel2 START
 *********************************************************************************************************************/


/*******  VAR sections  **********************************************************************************************/

/* VAR sections */

#elif defined MTRVEL2_START_SEC_VAR_CLEARED_32
# undef MTRVEL2_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_8

#elif defined MTRVEL2_STOP_SEC_VAR_CLEARED_32
# undef MTRVEL2_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined MTRVEL2_START_SEC_VAR_CLEARED_16
# undef MTRVEL2_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_8

#elif defined MTRVEL2_STOP_SEC_VAR_CLEARED_16
# undef MTRVEL2_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined MTRVEL2_START_SEC_VAR_CLEARED_BOOLEAN
# undef MTRVEL2_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_8

#elif defined MTRVEL2_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef MTRVEL2_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR

#elif defined MTRVEL2_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRVEL2_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_8

#elif defined MTRVEL2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef MTRVEL2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR
/**********************************************************************************************************************
 *  MtrVel2 END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  MtrVel3 START
 *********************************************************************************************************************/

/*******  VAR sections  **********************************************************************************************/

/* VAR sections */

#elif defined MTRVEL3_START_SEC_VAR_CLEARED_8
# undef MTRVEL3_START_SEC_VAR_CLEARED_8
# define START_SEC_VAR_CLEARED_8_10

#elif defined MTRVEL3_STOP_SEC_VAR_CLEARED_8
# undef MTRVEL3_STOP_SEC_VAR_CLEARED_8
# define STOP_SEC_VAR

#elif defined MTRVEL3_START_SEC_VAR_CLEARED_16
# undef MTRVEL3_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_10

#elif defined MTRVEL3_STOP_SEC_VAR_CLEARED_16
# undef MTRVEL3_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  MtrVel3 END
 *********************************************************************************************************************/
 
/*NVMPROXY START*/
/* Code */
#elif defined NVMPROXY_START_SEC_CODE
    #undef NVMPROXY_START_SEC_CODE
    #define START_SEC_CODE

#elif defined NVMPROXY_STOP_SEC_CODE
    #undef NVMPROXY_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined NVMPROXY_START_SEC_CONST_UNSPECIFIED
    #undef NVMPROXY_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
    #undef NVMPROXY_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/* Variables */
#elif defined NVMPROXY_START_SEC_VAR_CLEARED_16
    #undef NVMPROXY_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_GLOBALSHARED

#elif defined NVMPROXY_STOP_SEC_VAR_CLEARED_16
    #undef NVMPROXY_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
	
#elif defined NVMPROXY_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NVMPROXY_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED

#elif defined NVMPROXY_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef NVMPROXY_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined NVMPROXY_START_SEC_VAR_NOINIT_8
    #undef NVMPROXY_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8_9

#elif defined NVMPROXY_STOP_SEC_VAR_NOINIT_8
    #undef NVMPROXY_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR


/**********************************************************************************************************************
 *  NHET START
 *********************************************************************************************************************/
/* CODE sections */
#elif defined NHET_START_SEC_CODE
# undef NHET_START_SEC_CODE
# define START_SEC_CODE
# define START_SEC_VAR_CLEARED_UNSPECIFIED_10 /* Function Scope Static Var Allocation start */

#elif defined NHET_STOP_SEC_CODE
# undef NHET_STOP_SEC_CODE
# define STOP_SEC_CODE
# define STOP_SEC_VAR /* Function Scope Static Var Allocation stop */

 /* VAR sections */
#elif defined NHET_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef NHET_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined NHET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef NHET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR


#elif defined NHET_START_SEC_VAR_CLEARED_BOOLEAN
# undef NHET_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined NHET_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef NHET_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR


/**********************************************************************************************************************
 *  NtWrap START
 *********************************************************************************************************************/
/* VAR sections */

#elif defined NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef NTWRAP_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED

#elif defined NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef NTWRAP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  OscTraj START
 *********************************************************************************************************************/
/* VAR sections */

#elif defined OSCTRAJ_START_SEC_VAR_CLEARED_32
# undef OSCTRAJ_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_7

#elif defined OSCTRAJ_STOP_SEC_VAR_CLEARED_32
# undef OSCTRAJ_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined OSCTRAJ_START_SEC_VAR_CLEARED_16
# undef OSCTRAJ_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_7

#elif defined OSCTRAJ_STOP_SEC_VAR_CLEARED_16
# undef OSCTRAJ_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined OSCTRAJ_START_SEC_VAR_CLEARED_8
# undef OSCTRAJ_START_SEC_VAR_CLEARED_8
# define START_SEC_VAR_CLEARED_8_7

#elif defined OSCTRAJ_STOP_SEC_VAR_CLEARED_8
# undef OSCTRAJ_STOP_SEC_VAR_CLEARED_8
# define STOP_SEC_VAR

#elif defined OSCTRAJ_START_SEC_VAR_CLEARED_BOOLEAN
# undef OSCTRAJ_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined OSCTRAJ_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef OSCTRAJ_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR

#elif defined OSCTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef OSCTRAJ_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined OSCTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef OSCTRAJ_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  OscTraj END
 *********************************************************************************************************************/

/*PARKASTENBL START*/
/* Variables */
#elif defined PARKASTENBL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef PARKASTENBL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined PARKASTENBL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef PARKASTENBL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
	
#elif defined PARKASTENBL_START_SEC_VAR_CLEARED_32
    #undef PARKASTENBL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined PARKASTENBL_STOP_SEC_VAR_CLEARED_32
    #undef PARKASTENBL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
	
#elif defined PARKASTENBL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef PARKASTENBL_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined PARKASTENBL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef PARKASTENBL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/*PRKASTMFGSERVCH2 START*/
/* Variables */
#elif defined PRKASTANDMFGSERVCH2_START_SEC_VAR_CLEARED_16
    #undef PRKASTANDMFGSERVCH2_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_8

#elif defined PRKASTANDMFGSERVCH2_STOP_SEC_VAR_CLEARED_16
    #undef PRKASTANDMFGSERVCH2_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PHASECTRL START
 *********************************************************************************************************************/
 /* VAR sections */
#elif defined PHASECTRL_START_SEC_VAR_CLEARED_32
# undef PHASECTRL_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_10

#elif defined PHASECTRL_STOP_SEC_VAR_CLEARED_32
# undef PHASECTRL_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined PHASECTRL_START_SEC_VAR_CLEARED_16
# undef PHASECTRL_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_10

#elif defined PHASECTRL_STOP_SEC_VAR_CLEARED_16
# undef PHASECTRL_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PHASECTRL END
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  PHASEDSCNT START
 *********************************************************************************************************************/
/* Type H Variables */
#elif defined PHASEDSCNT_START_SEC_VAR_SAVED_ZONEH_8
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:PhaseDscnt")

    #undef PHASEDSCNT_START_SEC_VAR_SAVED_ZONEH_8
    #undef MEMMAP_ERROR

#elif defined PHASEDSCNT_STOP_SEC_VAR_SAVED_ZONEH_8
    #undef PHASEDSCNT_STOP_SEC_VAR_SAVED_ZONEH_8
    #define STOP_SEC_VAR

 /* VAR sections */
#elif defined PHASEDSCNT_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef PHASEDSCNT_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined PHASEDSCNT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef PHASEDSCNT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR

#elif defined PHASEDSCNT_START_SEC_VAR_CLEARED_32
# undef PHASEDSCNT_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_10

#elif defined PHASEDSCNT_STOP_SEC_VAR_CLEARED_32
# undef PHASEDSCNT_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined PHASEDSCNT_START_SEC_VAR_CLEARED_16
# undef PHASEDSCNT_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_10

#elif defined PHASEDSCNT_STOP_SEC_VAR_CLEARED_16
# undef PHASEDSCNT_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined PHASEDSCNT_START_SEC_VAR_CLEARED_8
# undef PHASEDSCNT_START_SEC_VAR_CLEARED_8
# define START_SEC_VAR_CLEARED_8_10

#elif defined PHASEDSCNT_STOP_SEC_VAR_CLEARED_8
# undef PHASEDSCNT_STOP_SEC_VAR_CLEARED_8
# define STOP_SEC_VAR

/* CONST sections */
#elif defined PHASEDSCNT_START_SEC_CONST_16
	#undef PHASEDSCNT_START_SEC_CONST_16
	#define START_SEC_CONST_UNSPECIFIED_10

#elif defined PHASEDSCNT_STOP_SEC_CONST_16
	#undef PHASEDSCNT_STOP_SEC_CONST_16
	#define STOP_SEC_CONST

/**********************************************************************************************************************
 *  PHASEDSCNT END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PRKASTMFGSERVCH2 START
 *********************************************************************************************************************/

#elif defined PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_32
	#undef PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_8

#elif defined PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_32
	#undef PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_16
	#undef PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_8

#elif defined PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_16
	#undef PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR

#elif defined PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_8
	#undef PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_8

#elif defined PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_8
	#undef PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_BOOLEAN
	#undef PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_BOOLEAN_8

#elif defined PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PRKASTMFGSERVCH2_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_8

#elif defined PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef PRKASTMFGSERVCH2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PRKASTMFGSERVCH2 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PWRLMTFUNC START
 *********************************************************************************************************************/
/* VAR sections */

#elif defined PWRLMTFUNC_START_SEC_VAR_CLEARED_32
# undef PWRLMTFUNC_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_7

#elif defined PWRLMTFUNC_STOP_SEC_VAR_CLEARED_32
# undef PWRLMTFUNC_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined PWRLMTFUNC_START_SEC_VAR_CLEARED_16
# undef PWRLMTFUNC_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_7

#elif defined PWRLMTFUNC_STOP_SEC_VAR_CLEARED_16
# undef PWRLMTFUNC_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined PWRLMTFUNC_START_SEC_VAR_CLEARED_8
# undef PWRLMTFUNC_START_SEC_VAR_CLEARED_8
# define START_SEC_VAR_CLEARED_8_7

#elif defined PWRLMTFUNC_STOP_SEC_VAR_CLEARED_8
# undef PWRLMTFUNC_STOP_SEC_VAR_CLEARED_8
# define STOP_SEC_VAR

#elif defined PWRLMTFUNC_START_SEC_VAR_CLEARED_BOOLEAN
# undef PWRLMTFUNC_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined PWRLMTFUNC_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef PWRLMTFUNC_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR


#elif defined PWRLMTFUNC_START_SEC_VAR_NOINIT_32
# undef PWRLMTFUNC_START_SEC_VAR_NOINIT_32
# define START_SEC_VAR_NOINIT_32_7

#elif defined PWRLMTFUNC_STOP_SEC_VAR_NOINIT_32
# undef PWRLMTFUNC_STOP_SEC_VAR_NOINIT_32
# define STOP_SEC_VAR

#elif defined PWRLMTFUNC_START_SEC_VAR_NOINIT_16
# undef PWRLMTFUNC_START_SEC_VAR_NOINIT_16
# define START_SEC_VAR_NOINIT_16_7

#elif defined PWRLMTFUNC_STOP_SEC_VAR_NOINIT_16
# undef PWRLMTFUNC_STOP_SEC_VAR_NOINIT_16
# define STOP_SEC_VAR

#elif defined PWRLMTFUNC_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef PWRLMTFUNC_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_7

#elif defined PWRLMTFUNC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef PWRLMTFUNC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PWRLMTFUNC END
 *********************************************************************************************************************/
	
  /*RETURNFIREWALL START*/
/* Variables */
#elif defined RETURNFIREWALL_START_SEC_VAR_CLEARED_32
    #undef RETURNFIREWALL_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined RETURNFIREWALL_STOP_SEC_VAR_CLEARED_32
    #undef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined RETURNFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #undef RETURNFIREWALL_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined RETURNFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef RETURNFIREWALL_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
/**********************************************************************************************************************
 *  QUADDET START
 *********************************************************************************************************************/
 /* VAR sections */
#elif defined QUADDET_START_SEC_VAR_INIT_32
# undef QUADDET_START_SEC_VAR_INIT_32
# define START_SEC_VAR_INIT_32_10

#elif defined QUADDET_STOP_SEC_VAR_INIT_32
# undef QUADDET_STOP_SEC_VAR_INIT_32
# define STOP_SEC_VAR

#elif defined QUADDET_START_SEC_VAR_INIT_8
# undef QUADDET_START_SEC_VAR_INIT_8
# define START_SEC_VAR_CLEARED_8_10

#elif defined QUADDET_STOP_SEC_VAR_INIT_8
# undef QUADDET_STOP_SEC_VAR_INIT_8
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  PHASECTRL END
 *********************************************************************************************************************/

/**********************************************************************************************************************
* RACKLOAD START
*********************************************************************************************************************/

#elif defined RACKLOAD_START_SEC_VAR_NOINIT_32
	#undef RACKLOAD_START_SEC_VAR_NOINIT_32
	#define START_SEC_VAR_NOINIT_32_9

#elif defined RACKLOAD_STOP_SEC_VAR_NOINIT_32
	#undef RACKLOAD_STOP_SEC_VAR_NOINIT_32
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* RACKLOAD END
*********************************************************************************************************************/
	
/**********************************************************************************************************************
* SHTDNMECH START
*********************************************************************************************************************/

#elif defined SHTDNMECH_START_SEC_VAR_CLEARED_8
	#undef SHTDNMECH_START_SEC_VAR_CLEARED_8
	#define START_SEC_VAR_CLEARED_8_10

#elif defined SHTDNMECH_STOP_SEC_VAR_CLEARED_8
	#undef SHTDNMECH_STOP_SEC_VAR_CLEARED_8
	#define STOP_SEC_VAR

#elif defined SHTDNMECH_START_SEC_VAR_CLEARED_32
	#undef SHTDNMECH_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_10

#elif defined SHTDNMECH_STOP_SEC_VAR_CLEARED_32
	#undef SHTDNMECH_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

/**********************************************************************************************************************
* SHTDNMECH END
*********************************************************************************************************************/
	
/**********************************************************************************************************************
 *  STAMD START
 *********************************************************************************************************************/
/* Variables */
#elif defined STAMD_START_SEC_VAR_SAVED_ZONEHGS_8
    #undef STAMD_START_SEC_VAR_SAVED_ZONEHGS_8
    #define START_SEC_VAR_NOINIT_8_GLOBALSHARED

#elif defined STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_8
    #undef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_8
    #define STOP_SEC_VAR
	
#elif defined STAMD_START_SEC_VAR_SAVED_ZONEHGS_32
    #undef STAMD_START_SEC_VAR_SAVED_ZONEHGS_32
    #define START_SEC_VAR_NOINIT_32_GLOBALSHARED

#elif defined STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_32
    #undef STAMD_STOP_SEC_VAR_SAVED_ZONEHGS_32
    #define STOP_SEC_VAR
	
/* CONST sections */
#elif defined STAMD_START_SEC_CONST_UNSPECIFIED
	#undef STAMD_START_SEC_CONST_UNSPECIFIED
	#define START_SEC_CONST_UNSPECIFIED_10

#elif defined STAMD_STOP_SEC_CONST_UNSPECIFIED
	#undef STAMD_STOP_SEC_CONST_UNSPECIFIED
	#define STOP_SEC_CONST

	
  /* STAMD4 */ 
#elif defined STAMD4_START_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD4_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_4

#elif defined STAMD4_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD4_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
  
#elif defined STAMD4_START_SEC_VAR_CLEARED_8
    #undef STAMD4_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_4

#elif defined STAMD4_STOP_SEC_VAR_CLEARED_8
    #undef STAMD4_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
	
#elif defined STAMD4_START_SEC_VAR_CLEARED_32
    #undef STAMD4_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_4

#elif defined STAMD4_STOP_SEC_VAR_CLEARED_32
    #undef STAMD4_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STAMD4_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD4_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_4

#elif defined STAMD4_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD4_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined STAMD4_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD4_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_4

#elif defined STAMD4_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD4_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

  /* STAMD7 */ 
#elif defined STAMD7_START_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD7_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_7

#elif defined STAMD7_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD7_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
  
#elif defined STAMD7_START_SEC_VAR_CLEARED_8
    #undef STAMD7_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_7

#elif defined STAMD7_STOP_SEC_VAR_CLEARED_8
    #undef STAMD7_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
	
#elif defined STAMD7_START_SEC_VAR_CLEARED_32
    #undef STAMD7_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined STAMD7_STOP_SEC_VAR_CLEARED_32
    #undef STAMD7_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STAMD7_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD7_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined STAMD7_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD7_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined STAMD7_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD7_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined STAMD7_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD7_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

  /* STAMD8 */ 
#elif defined STAMD8_START_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD8_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_8

#elif defined STAMD8_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD8_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
  
#elif defined STAMD8_START_SEC_VAR_CLEARED_8
    #undef STAMD8_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_8

#elif defined STAMD8_STOP_SEC_VAR_CLEARED_8
    #undef STAMD8_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
	
#elif defined STAMD8_START_SEC_VAR_CLEARED_16
    #undef STAMD8_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_8

#elif defined STAMD8_STOP_SEC_VAR_CLEARED_16
    #undef STAMD8_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR	
	
	
#elif defined STAMD8_START_SEC_VAR_CLEARED_32
    #undef STAMD8_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_8

#elif defined STAMD8_STOP_SEC_VAR_CLEARED_32
    #undef STAMD8_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STAMD8_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD8_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_8

#elif defined STAMD8_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD8_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined STAMD8_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD8_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_8

#elif defined STAMD8_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD8_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

  /* STAMD9 */ 
#elif defined STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD9_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9

#elif defined STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD9_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
  
#elif defined STAMD9_START_SEC_VAR_CLEARED_8
    #undef STAMD9_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined STAMD9_STOP_SEC_VAR_CLEARED_8
    #undef STAMD9_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
	
#elif defined STAMD9_START_SEC_VAR_CLEARED_32
    #undef STAMD9_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined STAMD9_STOP_SEC_VAR_CLEARED_32
    #undef STAMD9_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD9_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD9_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined STAMD9_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD9_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined STAMD9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD9_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

  /* STAMD10 */ 
#elif defined STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD10_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_10

#elif defined STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD10_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
  
#elif defined STAMD10_START_SEC_VAR_CLEARED_8
    #undef STAMD10_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined STAMD10_STOP_SEC_VAR_CLEARED_8
    #undef STAMD10_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
	
#elif defined STAMD10_START_SEC_VAR_CLEARED_32
    #undef STAMD10_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined STAMD10_STOP_SEC_VAR_CLEARED_32
    #undef STAMD10_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD10_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD10_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined STAMD10_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD10_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined STAMD10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD10_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

  /* STAMD11 */ 
#elif defined STAMD11_START_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD11_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_11

#elif defined STAMD11_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef STAMD11_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
  
#elif defined STAMD11_START_SEC_VAR_CLEARED_8
    #undef STAMD11_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_11

#elif defined STAMD11_STOP_SEC_VAR_CLEARED_8
    #undef STAMD11_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
	
#elif defined STAMD11_START_SEC_VAR_CLEARED_32
    #undef STAMD11_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_11

#elif defined STAMD11_STOP_SEC_VAR_CLEARED_32
    #undef STAMD11_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined STAMD11_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD11_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_11

#elif defined STAMD11_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STAMD11_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined STAMD11_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD11_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_11

#elif defined STAMD11_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STAMD11_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  STAMD END
 *********************************************************************************************************************/

  /*MTRPOS START*/
/* Variables */
#elif defined MTRPOS_START_SEC_VAR_NOINIT_32
    #undef MTRPOS_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined MTRPOS_STOP_SEC_VAR_NOINIT_32
    #undef MTRPOS_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR
	
#elif defined MTRPOS_START_SEC_VAR_CLEARED_16
    #undef MTRPOS_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined MTRPOS_STOP_SEC_VAR_CLEARED_16
    #undef MTRPOS_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR
#elif defined MTRPOS_START_SEC_VAR_CLEARED_8
    #undef MTRPOS_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_10

#elif defined MTRPOS_STOP_SEC_VAR_CLEARED_8
    #undef MTRPOS_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR
	
#elif defined MTRPOS_START_SEC_VAR_CLEARED_BOOLEAN
    #undef MTRPOS_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined MTRPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef MTRPOS_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR
	
#elif defined MTRPOS_START_SEC_CONST_UNSPECIFIED
    #undef MTRPOS_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined MTRPOS_STOP_SEC_CONST_UNSPECIFIED
    #undef MTRPOS_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
	
  /*MTRPOS2 START*/
/* Type H Variables */
#elif defined MTRPOS2_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit:typeH:MtrPos2")

    #undef MTRPOS2_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR

#elif defined MTRPOS2_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef MTRPOS2_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR  
  
/* Variables */
#elif defined MTRPOS2_START_SEC_VAR_CLEARED_8
    #undef MTRPOS2_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_7

#elif defined MTRPOS2_STOP_SEC_VAR_CLEARED_8
    #undef MTRPOS2_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined MTRPOS2_START_SEC_VAR_CLEARED_16
    #undef MTRPOS2_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_7

#elif defined MTRPOS2_STOP_SEC_VAR_CLEARED_16
    #undef MTRPOS2_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined MTRPOS2_START_SEC_VAR_CLEARED_32
    #undef MTRPOS2_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined MTRPOS2_STOP_SEC_VAR_CLEARED_32
    #undef MTRPOS2_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined MTRPOS2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MTRPOS2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined MTRPOS2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef MTRPOS2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined MTRPOS2_START_SEC_VAR_NOINIT_32
    #undef MTRPOS2_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_7

#elif defined MTRPOS2_STOP_SEC_VAR_NOINIT_32
    #undef MTRPOS2_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

  /*MTRPOS3 START*/
/* Variables */
#elif defined MTRPOS3_START_SEC_VAR_CLEARED_16
    #undef MTRPOS3_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_8

#elif defined MTRPOS3_STOP_SEC_VAR_CLEARED_16
    #undef MTRPOS3_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined MTRPOS3_START_SEC_VAR_CLEARED_32
    #undef MTRPOS3_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_8

#elif defined MTRPOS3_STOP_SEC_VAR_CLEARED_32
    #undef MTRPOS3_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined MTRPOS3_START_SEC_CONST_UNSPECIFIED
    #undef MTRPOS3_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined MTRPOS3_STOP_SEC_CONST_UNSPECIFIED
    #undef MTRPOS3_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/**********************************************************************************************************************
 *  ParamComp START
 *********************************************************************************************************************/

/* Type H Variables */
#elif defined PARAMCOMP_START_SEC_VAR_SAVED_ZONEH_32
    #define VAR_SEC_OPEN
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit:typeH:ParamComp")

    #undef PARAMCOMP_START_SEC_VAR_SAVED_ZONEH_32
    #undef MEMMAP_ERROR

#elif defined PARAMCOMP_STOP_SEC_VAR_SAVED_ZONEH_32
    #undef PARAMCOMP_STOP_SEC_VAR_SAVED_ZONEH_32
    #define STOP_SEC_VAR

/* Variables */
#elif defined PARAMCOMP_START_SEC_VAR_CLEARED_32
    #undef PARAMCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_32_10

#elif defined PARAMCOMP_STOP_SEC_VAR_CLEARED_32
    #undef PARAMCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined PARAMCOMP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef PARAMCOMP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined PARAMCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef PARAMCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  ParamComp END
 *********************************************************************************************************************/

  /*POSSERVO START*/
/* Variables */

#elif defined POSSERVO_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef POSSERVO_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined POSSERVO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef POSSERVO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined POSSERVO_START_SEC_VAR_CLEARED_16
    #undef POSSERVO_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_7

#elif defined POSSERVO_STOP_SEC_VAR_CLEARED_16
    #undef POSSERVO_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined POSSERVO_START_SEC_VAR_CLEARED_32
    #undef POSSERVO_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined POSSERVO_STOP_SEC_VAR_CLEARED_32
    #undef POSSERVO_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined POSSERVO_START_SEC_VAR_CLEARED_BOOLEAN
    #undef POSSERVO_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined POSSERVO_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef POSSERVO_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/* PwmCdd Start */
/* Variables */
#elif defined PWMCDD_START_SEC_VAR_CLEARED_16
    #undef PWMCDD_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined PWMCDD_STOP_SEC_VAR_CLEARED_16
    #undef PWMCDD_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR



		
  /*RACKLOAD START*/
/* Variables */
#elif defined RACKLOAD_START_SEC_VAR_NOINIT_32BIT
    #undef RACKLOAD_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_CLEARED_32_9

#elif defined RACKLOAD_STOP_SEC_VAR_NOINIT_32BIT
    #undef RACKLOAD_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

  /*RESETCAUSE START*/
/* Variables */
#elif defined RESETCAUSE_START_SEC_VAR_POWER_ON_CLEARED_8
    #undef RESETCAUSE_START_SEC_VAR_POWER_ON_CLEARED_8
	#pragma SET_DATA_SECTION(".resetcause")
    #undef MEMMAP_ERROR


#elif defined RESETCAUSE_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #undef RESETCAUSE_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #define STOP_SEC_VAR

/* Return START */
#elif defined RETURN_START_SEC_VAR_CLEARED_32
	#undef RETURN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_NOINIT_32_9

#elif defined RETURN_STOP_SEC_VAR_CLEARED_32
	#undef RETURN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined RETURN_START_SEC_VAR_CLEARED_16
	#undef RETURN_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_NOINIT_16_9

#elif defined RETURN_STOP_SEC_VAR_CLEARED_16
	#undef RETURN_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR


/* Return END */

  /*SignlCondn START*/
/* Variables */
#elif defined SIGNLCONDN_START_SEC_VAR_CLEARED_32
	#undef SIGNLCONDN_START_SEC_VAR_CLEARED_32
	#define START_SEC_VAR_CLEARED_32_7

#elif defined SIGNLCONDN_STOP_SEC_VAR_CLEARED_32
	#undef SIGNLCONDN_STOP_SEC_VAR_CLEARED_32
	#define STOP_SEC_VAR

#elif defined SIGNLCONDN_START_SEC_VAR_CLEARED_BOOLEAN
	#undef SIGNLCONDN_START_SEC_VAR_CLEARED_BOOLEAN
	#define START_SEC_VAR_CLEARED_32_7

#elif defined SIGNLCONDN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#undef SIGNLCONDN_STOP_SEC_VAR_CLEARED_BOOLEAN
	#define STOP_SEC_VAR

#elif defined SIGNLCONDN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SIGNLCONDN_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined SIGNLCONDN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef SIGNLCONDN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR


  /*SPINXT START*/
/* Code */
#elif defined SPINXT_START_SEC_CODE
    #undef SPINXT_START_SEC_CODE
    #define START_SEC_CODE

#elif defined SPINXT_STOP_SEC_CODE
    #undef SPINXT_STOP_SEC_CODE
    #define STOP_SEC_VAR

 /* Variables */
#elif defined SPINXT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SPINXT_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined SPINXT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef SPINXT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  StabilityComp START
 *********************************************************************************************************************/

/* StabilityComp.c */
#elif defined  STABILITYCOMP_START_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined  STABILITYCOMP_STOP_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined  STABILITYCOMP_START_SEC_VAR_CLEARED_16
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_10

#elif defined  STABILITYCOMP_STOP_SEC_VAR_CLEARED_16
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined  STABILITYCOMP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined  STABILITYCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined  STABILITYCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined  STABILITYCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/* StabilityComp2.c */
#elif defined  STABILITYCOMP2_START_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP2_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined  STABILITYCOMP2_STOP_SEC_VAR_CLEARED_32
    #undef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined  STABILITYCOMP2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP2_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined  STABILITYCOMP2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef STABILITYCOMP2_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  StabilityComp END
 *********************************************************************************************************************/


  /*STOPCTRL START*/
/* Variables */
#elif defined STOPCTRL_START_SEC_VAR_NOINIT_32BIT
    #undef STOPCTRL_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_CLEARED_32_10

#elif defined STOPCTRL_STOP_SEC_VAR_NOINIT_32BIT
    #undef STOPCTRL_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

#elif defined STOPCTRL_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STOPCTRL_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined STOPCTRL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STOPCTRL_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

/* Sweeping Technologies (SWT) - Start */
#elif defined (SWT_START_SEC_CONST_8BIT)
    #undef SWT_START_SEC_CONST_8BIT
	#define START_SEC_CONST_8BIT
#elif defined (SWT_STOP_SEC_CONST_8BIT)
    #undef SWT_STOP_SEC_CONST_8BIT
	#define STOP_SEC_CONST

#elif defined (SWT_START_SEC_CONST_16BIT)
    #undef SWT_START_SEC_CONST_16BIT
	#define START_SEC_CONST_16BIT
#elif defined (SWT_STOP_SEC_CONST_16BIT)
    #undef SWT_STOP_SEC_CONST_16BIT
	#define STOP_SEC_CONST

#elif defined (SWT_START_SEC_CONST_32BIT)
    #undef SWT_START_SEC_CONST_32BIT
	#define START_SEC_CONST_32BIT
#elif defined (SWT_STOP_SEC_CONST_32BIT)
    #undef SWT_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST

#elif defined (SWT_START_SEC_CODE)
    #undef SWT_START_SEC_CODE
	#define START_SEC_CODE
#elif defined (SWT_STOP_SEC_CODE)
    #undef SWT_STOP_SEC_CODE
	#define STOP_SEC_CODE

#elif defined (SWT_START_SEC_VAR_NO_INIT)
    #undef SWT_START_SEC_VAR_NO_INIT
	#define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#elif defined (SWT_STOP_SEC_VAR_NO_INIT)
    #undef SWT_STOP_SEC_VAR_NO_INIT
	#define STOP_SEC_VAR

#elif defined (SWT_START_SEC_CONST_UNSPEC)
   #undef SWT_START_SEC_CONST_UNSPEC
   #define START_SEC_CONST_UNSPECIFIED
#elif defined (SWT_STOP_SEC_CONST_UNSPEC)
   #undef SWT_STOP_SEC_CONST_UNSPEC
   #define STOP_SEC_CONST

/* Sweeping Technologies (SWT) - End */



/* TcFlshPrg Start */

#elif defined TCFLSHPRG_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef TCFLSHPRG_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined TCFLSHPRG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef TCFLSHPRG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined TCFLSHPRG_START_SEC_VAR_NOINIT_32
    #undef TCFLSHPRG_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined TCFLSHPRG_STOP_SEC_VAR_NOINIT_32
    #undef TCFLSHPRG_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

#elif defined TCFLSHPRG_START_SEC_VAR_NOINIT_16
    #undef TCFLSHPRG_START_SEC_VAR_NOINIT_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined TCFLSHPRG_STOP_SEC_VAR_NOINIT_16
    #undef TCFLSHPRG_STOP_SEC_VAR_NOINIT_16
    #define STOP_SEC_VAR

#elif defined TCFLSHPRG_START_SEC_VAR_NOINIT_8
    #undef TCFLSHPRG_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined TCFLSHPRG_STOP_SEC_VAR_NOINIT_8
    #undef TCFLSHPRG_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR

#elif defined TCFLSHPRG_START_SEC_VAR_NOINIT_BOOLEAN
    #undef TCFLSHPRG_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined TCFLSHPRG_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef TCFLSHPRG_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR


/* TcFlshPrg End */

/* TJADamp Start */

#elif defined TJADAMP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef TJADAMP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined TJADAMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef TJADAMP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined TJADAMP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef TJADAMP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined TJADAMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef TJADAMP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined TJADAMP_START_SEC_VAR_CLEARED_16
    #undef TJADAMP_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined TJADAMP_STOP_SEC_VAR_CLEARED_16
    #undef TJADAMP_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined TJADAMP_START_SEC_VAR_CLEARED_32
    #undef TJADAMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined TJADAMP_STOP_SEC_VAR_CLEARED_32
    #undef TJADAMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

/* TJADamp End */


/* Thermal Duty Cycle (THRMLDUTYCYCLE) */
/* Varialbes */
#elif defined THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_8
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_8
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef THRMLDUTYCYCLE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined THRMLDUTYCYCLE_STARTP_SEC_VAR_CLEARED_BOOLEAN
    #undef THRMLDUTYCYCLE_STARTP_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef THRMLDUTYCYCLE_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

  /*TMPRLMON START*/
/* Constants */
#elif defined  TMPRLMON_START_SEC_CONST_UNSPECIFIED
    #undef TMPRLMON_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined  TMPRLMON_STOP_SEC_CONST_UNSPECIFIED
    #undef TMPRLMON_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/* Variables */
#elif defined  TMPRLMON_START_SEC_VAR_CLEARED_8
    #undef TMPRLMON_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_7

#elif defined  TMPRLMON_STOP_SEC_VAR_CLEARED_8
    #undef TMPRLMON_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined  TMPRLMON_START_SEC_VAR_CLEARED_32
    #undef TMPRLMON_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined  TMPRLMON_STOP_SEC_VAR_CLEARED_32
    #undef TMPRLMON_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined  TMPRLMON_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TMPRLMON_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined  TMPRLMON_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TMPRLMON_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR
	
#elif defined  TMPRLMON_START_SEC_VAR_CLEARED_BOOLEAN
    #undef TMPRLMON_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_7

#elif defined  TMPRLMON_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef TMPRLMON_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  TrqBasedInrtCmp START
 *********************************************************************************************************************/
#elif defined  TRQBASEDINRTCMP_START_SEC_VAR_CLEARED_32
    #undef TRQBASEDINRTCMP_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_9

#elif defined  TRQBASEDINRTCMP_STOP_SEC_VAR_CLEARED_32
    #undef TRQBASEDINRTCMP_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR
	
#elif defined  TRQBASEDINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TRQBASEDINRTCMP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined  TRQBASEDINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TRQBASEDINRTCMP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  TrqOsc START
 *********************************************************************************************************************/
#elif defined  TRQOSC_START_SEC_VAR_CLEARED_BOOLEAN
    #undef TRQOSC_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined  TRQOSC_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef TRQOSC_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined TRQOSC_START_SEC_VAR_CLEARED_32
    #undef TRQOSC_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_10

#elif defined TRQOSC_STOP_SEC_VAR_CLEARED_32
    #undef TRQOSC_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined TRQOSC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TRQOSC_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_10

#elif defined TRQOSC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TRQOSC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined TRQOSC_START_SEC_VAR_INIT_32
    #undef TRQOSC_START_SEC_VAR_INIT_32
    #define START_SEC_VAR_INIT_32_10

#elif defined TRQOSC_STOP_SEC_VAR_INIT_32
    #undef TRQOSC_STOP_SEC_VAR_INIT_32
    #define STOP_SEC_VAR

/**********************************************************************************************************************
 *  uDiag START
 *********************************************************************************************************************/

/* Variables */
#elif defined UDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef UDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined UDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef UDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined UDIAG_START_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef UDIAG_START_SEC_CONST_UNSPECIFIED

#elif defined UDIAG_STOP_SEC_CONST_UNSPECIFIED
	#undef MEMMAP_ERROR
    #undef UDIAG_STOP_SEC_CONST_UNSPECIFIED

#elif defined  UDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef UDIAG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined UDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef UDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined UDIAG_START_SEC_VAR_CLEARED_16
    #undef UDIAG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_NOINIT_16_10

#elif defined UDIAG_STOP_SEC_VAR_CLEARED_16
    #undef UDIAG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined UDIAG_START_SEC_VAR_CLEARED_32
    #undef UDIAG_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_NOINIT_16_10

#elif defined UDIAG_STOP_SEC_VAR_CLEARED_32
    #undef UDIAG_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined UDIAG_START_SEC_VAR_SAVED_UNSPECIFIED
    #undef UDIAG_START_SEC_VAR_SAVED_UNSPECIFIED
    #define START_SEC_VAR_POWER_ON_CLEARED_8_10

#elif defined UDIAG_STOP_SEC_VAR_SAVED_UNSPECIFIED
    #undef UDIAG_STOP_SEC_VAR_SAVED_UNSPECIFIED
    #define STOP_SEC_VAR
    
/**********************************************************************************************************************
 *  uDiag END
 *********************************************************************************************************************/

/* TUNING SELECT START */
/* Variables */

#elif defined TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
	#undef TUNINGSELAUTH_START_SEC_VAR_CLEARED_16
	#define START_SEC_VAR_CLEARED_16_7

#elif defined TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
	#undef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_16
	#define STOP_SEC_VAR


#elif defined TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TUNINGSELAUTH_START_SEC_VAR_CLEARED_UNSPECIFIED
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#undef TUNINGSELAUTH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
	#define STOP_SEC_VAR
/* TUNING SELECT End */


/*TURNSCOUNTER START*/
/* Variables */
#elif defined  TURNSCOUNTER_START_SEC_VAR_CLEARED_8
    #undef TURNSCOUNTER_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_7

#elif defined  TURNSCOUNTER_STOP_SEC_VAR_CLEARED_8
    #undef TURNSCOUNTER_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined  TURNSCOUNTER_START_SEC_VAR_CLEARED_16
    #undef TURNSCOUNTER_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_7

#elif defined  TURNSCOUNTER_STOP_SEC_VAR_CLEARED_16
    #undef TURNSCOUNTER_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined  TURNSCOUNTER_START_SEC_VAR_CLEARED_32
    #undef TURNSCOUNTER_START_SEC_VAR_CLEARED_32
    #define START_SEC_VAR_CLEARED_32_7

#elif defined  TURNSCOUNTER_STOP_SEC_VAR_CLEARED_32
    #undef TURNSCOUNTER_STOP_SEC_VAR_CLEARED_32
    #define STOP_SEC_VAR

#elif defined  TURNSCOUNTER_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TURNSCOUNTER_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_7

#elif defined  TURNSCOUNTER_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef TURNSCOUNTER_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

  /*VEHCFG START*/
#elif defined VEHCFG_START_SEC_VAR_CLEARED_16
    #undef VEHCFG_START_SEC_VAR_CLEARED_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined VEHCFG_STOP_SEC_VAR_CLEARED_16
    #undef VEHCFG_STOP_SEC_VAR_CLEARED_16
    #define STOP_SEC_VAR

#elif defined VEHCFG_START_SEC_VAR_CLEARED_8
    #undef VEHCFG_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined VEHCFG_STOP_SEC_VAR_CLEARED_8
    #undef VEHCFG_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined VEHCFG_START_SEC_VAR_CLEARED_BOOLEAN
    #undef VEHCFG_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined VEHCFG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef VEHCFG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

  /*VEHCFG END */


  /*VEHPWRMD START*/
/* Variables */
#elif defined VEHPWRMD_START_SEC_VAR_NOINIT_32BIT
    #undef VEHPWRMD_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_CLEARED_32_9

#elif defined VEHPWRMD_STOP_SEC_VAR_NOINIT_32BIT
    #undef VEHPWRMD_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

#elif defined VEHPWRMD_START_SEC_VAR_NOINIT_16
    #undef VEHPWRMD_START_SEC_VAR_NOINIT_16
    #define START_SEC_VAR_CLEARED_16_9

#elif defined VEHPWRMD_STOP_SEC_VAR_NOINIT_16
    #undef VEHPWRMD_STOP_SEC_VAR_NOINIT_16
    #define STOP_SEC_VAR

#elif defined VEHPWRMD_START_SEC_VAR_NOINIT_8
    #undef VEHPWRMD_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined VEHPWRMD_STOP_SEC_VAR_NOINIT_8
    #undef VEHPWRMD_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR

#elif defined VEHPWRMD_START_SEC_VAR_NOINIT_BOOLEAN
    #undef VEHPWRMD_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined VEHPWRMD_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef VEHPWRMD_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR
	
/**********************************************************************************************************************
 *  VLTGCTRL START
 *********************************************************************************************************************/
 /* VAR sections */
#elif defined VLTGCTRL_START_SEC_VAR_CLEARED_16
# undef VLTGCTRL_START_SEC_VAR_CLEARED_16
# define START_SEC_VAR_CLEARED_16_10

#elif defined VLTGCTRL_STOP_SEC_VAR_CLEARED_16
# undef VLTGCTRL_STOP_SEC_VAR_CLEARED_16
# define STOP_SEC_VAR

#elif defined VLTGCTRL_START_SEC_VAR_CLEARED_32
# undef VLTGCTRL_START_SEC_VAR_CLEARED_32
# define START_SEC_VAR_CLEARED_32_10

#elif defined VLTGCTRL_STOP_SEC_VAR_CLEARED_32
# undef VLTGCTRL_STOP_SEC_VAR_CLEARED_32
# define STOP_SEC_VAR

#elif defined VLTGCTRL_START_SEC_VAR_CLEARED_BOOLEAN
# undef VLTGCTRL_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_10

#elif defined VLTGCTRL_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef VLTGCTRL_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR

/**********************************************************************************************************************
 *  VLTGCTRL END
 *********************************************************************************************************************/

  /* WDGRESETHANDLER */
/* Variables */
#elif defined WDGRESETHANDLER_START_SEC_VAR_POWER_ON_CLEARED_8
    #undef WDGRESETHANDLER_START_SEC_VAR_POWER_ON_CLEARED_8
    #define START_SEC_VAR_POWER_ON_CLEARED_8_10

#elif defined WDGRESETHANDLER_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #undef WDGRESETHANDLER_STOP_SEC_VAR_POWER_ON_CLEARED_8
    #define STOP_SEC_VAR

  /* AP_XCP */
/* Variables */
#elif defined APXCP_START_SEC_VAR_CLEARED_8
    #undef APXCP_START_SEC_VAR_CLEARED_8
    #define START_SEC_VAR_CLEARED_8_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_8
    #undef APXCP_STOP_SEC_VAR_CLEARED_8
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #undef APXCP_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #undef APXCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_CLEARED_BOOLEAN
    #undef APXCP_START_SEC_VAR_CLEARED_BOOLEAN
    #define START_SEC_VAR_CLEARED_BOOLEAN_9

#elif defined APXCP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #undef APXCP_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_NOINIT_8
    #undef APXCP_START_SEC_VAR_NOINIT_8
    #define START_SEC_VAR_NOINIT_8_9

#elif defined APXCP_STOP_SEC_VAR_NOINIT_8
    #undef APXCP_STOP_SEC_VAR_NOINIT_8
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_NOINIT_32
    #undef APXCP_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_9

#elif defined APXCP_STOP_SEC_VAR_NOINIT_32
    #undef APXCP_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR

#elif defined APXCP_START_SEC_VAR_INIT_UNSPECIFIED
    #undef APXCP_START_SEC_VAR_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
	#pragma SET_DATA_SECTION(".TOTFCals")	/* Added to pin the TOTF cals into the CAL_RAM section of RAM */
	#undef MEMMAP_ERROR

#elif defined APXCP_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef APXCP_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR



	/*E2EPW START*/

/* Code */
/* To be used for mapping code to application block, boot block, external flash etc. */
#elif defined E2EPW_START_SEC_CODE
    #undef E2EPW_START_SEC_CODE
    #define START_SEC_CODE
    #define START_SEC_VAR_INIT_UNSPECIFIED_10 /* initialized data section is used to accomodate function level constant definitions, must be in RAM for funtion level static variables */

#elif defined E2EPW_STOP_SEC_CODE
    #undef E2EPW_STOP_SEC_CODE
    #define STOP_SEC_CODE
    #define STOP_SEC_VAR


/* Variables */
/* To be used for all global or static variables that are never initialized */
#elif defined E2EPW_START_SEC_VAR_NOINIT_BOOLEAN
    #undef E2EPW_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_NOINIT_8_10

#elif defined E2EPW_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef E2EPW_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_NOINIT_8BIT
    #undef E2EPW_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_10

#elif defined E2EPW_STOP_SEC_VAR_NOINIT_8BIT
    #undef E2EPW_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_NOINIT_16BIT
    #undef E2EPW_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16_10

#elif defined E2EPW_STOP_SEC_VAR_NOINIT_16BIT
    #undef E2EPW_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_NOINIT_32BIT
    #undef E2EPW_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32_10

#elif defined E2EPW_STOP_SEC_VAR_NOINIT_32BIT
    #undef E2EPW_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef E2EPW_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined E2EPW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef E2EPW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR


/* Variables */
/* To be used for all global or static variables that are initialized only after power on reset */
#elif defined E2EPW_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
    #undef E2EPW_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
    #define START_SEC_VAR_INIT_8_10

#elif defined E2EPW_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
    #undef E2EPW_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_POWER_ON_INIT_8BIT
    #undef E2EPW_START_SEC_VAR_POWER_ON_INIT_8BIT
    #define START_SEC_VAR_INIT_8_10

#elif defined E2EPW_STOP_SEC_VAR_POWER_ON_INIT_8BIT
    #undef E2EPW_STOP_SEC_VAR_POWER_ON_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_POWER_ON_INIT_16BIT
    #undef E2EPW_START_SEC_VAR_POWER_ON_INIT_16BIT
    #define START_SEC_VAR_INIT_16_10

#elif defined E2EPW_STOP_SEC_VAR_POWER_ON_INIT_16BIT
    #undef E2EPW_STOP_SEC_VAR_POWER_ON_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_POWER_ON_INIT_32BIT
    #undef E2EPW_START_SEC_VAR_POWER_ON_INIT_32BIT
    #define START_SEC_VAR_INIT_32_10

#elif defined E2EPW_STOP_SEC_VAR_POWER_ON_INIT_32BIT
    #undef E2EPW_STOP_SEC_VAR_POWER_ON_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef E2EPW_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_10

#elif defined E2EPW_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef E2EPW_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define STOP_SEC_VAR


/* Variables */
/* To be used for all global or static variables that have at least one of the
 * following properties:
 * -     accessed bitwise
 * -     frequently used
 * -     high number of accesses in source code
 * Some platforms allow the use of bit instructions for variables located in
 * this specific RAM area as well as shorter addressing instructions.
 * This saves code and runtime. */
#elif defined E2EPW_START_SEC_VAR_FAST_BOOLEAN
    #undef E2EPW_START_SEC_VAR_FAST_BOOLEAN
    #define START_SEC_VAR_INIT_8_10

#elif defined E2EPW_STOP_SEC_VAR_FAST_BOOLEAN
    #undef E2EPW_STOP_SEC_VAR_FAST_BOOLEAN
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_FAST_8BIT
    #undef E2EPW_START_SEC_VAR_FAST_8BIT
    #define START_SEC_VAR_INIT_8_10

#elif defined E2EPW_STOP_SEC_VAR_FAST_8BIT
    #undef E2EPW_STOP_SEC_VAR_FAST_8BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_FAST_16BIT
    #undef E2EPW_START_SEC_VAR_FAST_16BIT
    #define START_SEC_VAR_INIT_16_10

#elif defined E2EPW_STOP_SEC_VAR_FAST_16BIT
    #undef E2EPW_STOP_SEC_VAR_FAST_16BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_FAST_32BIT
    #undef E2EPW_START_SEC_VAR_FAST_32BIT
    #define START_SEC_VAR_INIT_32_10

#elif defined E2EPW_STOP_SEC_VAR_FAST_32BIT
    #undef E2EPW_STOP_SEC_VAR_FAST_32BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_FAST_UNSPECIFIED
    #undef E2EPW_START_SEC_VAR_FAST_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_10

#elif defined E2EPW_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef E2EPW_STOP_SEC_VAR_FAST_UNSPECIFIED
    #define STOP_SEC_VAR


/* Variables */
/* To be used for global or static variables accessible from a calibration tool. */
#elif defined E2EPW_START_SEC_INTERNAL_VAR_BOOLEAN
    #undef E2EPW_START_SEC_INTERNAL_VAR_BOOLEAN
    #define START_SEC_VAR_INIT_8_10

#elif defined E2EPW_STOP_SEC_INTERNAL_VAR_BOOLEAN
    #undef E2EPW_STOP_SEC_INTERNAL_VAR_BOOLEAN
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_INTERNAL_VAR_8BIT
    #undef E2EPW_START_SEC_INTERNAL_VAR_8BIT
    #define START_SEC_VAR_INIT_8_10

#elif defined E2EPW_STOP_SEC_INTERNAL_VAR_8BIT
    #undef E2EPW_STOP_SEC_INTERNAL_VAR_8BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_INTERNAL_VAR_16BIT
    #undef E2EPW_START_SEC_INTERNAL_VAR_16BIT
    #define START_SEC_VAR_INIT_16_10

#elif defined E2EPW_STOP_SEC_INTERNAL_VAR_16BIT
    #undef E2EPW_STOP_SEC_INTERNAL_VAR_16BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_INTERNAL_VAR_32BIT
    #undef E2EPW_START_SEC_INTERNAL_VAR_32BIT
    #define START_SEC_VAR_INIT_32_10

#elif defined E2EPW_STOP_SEC_INTERNAL_VAR_32BIT
    #undef E2EPW_STOP_SEC_INTERNAL_VAR_32BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_INTERNAL_VAR_UNSPECIFIED
    #undef E2EPW_START_SEC_INTERNAL_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_10

#elif defined E2EPW_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
    #undef E2EPW_STOP_SEC_INTERNAL_VAR_UNSPECIFIED
    #define STOP_SEC_VAR


/* Variables */
/* To be used for global or static variables that are initialized after every
 * reset (the normal case).
 */
#elif defined E2EPW_START_SEC_VAR_BOOLEAN
    #undef E2EPW_START_SEC_VAR_BOOLEAN
    #define START_SEC_VAR_INIT_8_10

#elif defined E2EPW_STOP_SEC_VAR_BOOLEAN
    #undef E2EPW_STOP_SEC_VAR_BOOLEAN
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_8BIT
    #undef E2EPW_START_SEC_VAR_8BIT
    #define START_SEC_VAR_INIT_8_10

#elif defined E2EPW_STOP_SEC_VAR_8BIT
    #undef E2EPW_STOP_SEC_VAR_8BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_16BIT
    #undef E2EPW_START_SEC_VAR_16BIT
    #define START_SEC_VAR_INIT_16_10

#elif defined E2EPW_STOP_SEC_VAR_16BIT
    #undef E2EPW_STOP_SEC_VAR_16BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_32BIT
    #undef E2EPW_START_SEC_VAR_32BIT
    #define START_SEC_VAR_INIT_32_10

#elif defined E2EPW_STOP_SEC_VAR_32BIT
    #undef E2EPW_STOP_SEC_VAR_32BIT
    #define STOP_SEC_VAR

#elif defined E2EPW_START_SEC_VAR_UNSPECIFIED
    #undef E2EPW_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_10

#elif defined E2EPW_STOP_SEC_VAR_UNSPECIFIED
    #undef E2EPW_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR


/* Constants */
/* To be used for global or static constants.  */
#elif defined E2EPW_START_SEC_CONST_BOOLEAN
    #undef E2EPW_START_SEC_CONST_BOOLEAN
    #define START_SEC_CONST_8BIT

#elif defined E2EPW_STOP_SEC_CONST_BOOLEAN
    #undef E2EPW_STOP_SEC_CONST_BOOLEAN
    #define STOP_SEC_CONST

#elif defined E2EPW_START_SEC_CONST_8BIT
    #undef E2EPW_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT

#elif defined E2EPW_STOP_SEC_CONST_8BIT
    #undef E2EPW_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined E2EPW_START_SEC_CONST_16BIT
    #undef E2EPW_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT

#elif defined E2EPW_STOP_SEC_CONST_16BIT
    #undef E2EPW_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined E2EPW_START_SEC_CONST_32BIT
    #undef E2EPW_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT

#elif defined E2EPW_STOP_SEC_CONST_32BIT
    #undef E2EPW_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined E2EPW_START_SEC_CONST_UNSPECIFIED
    #undef E2EPW_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_CONST_UNSPECIFIED
    #undef E2EPW_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST


/* Library code     */
/* To be used for code that shall go into library segments for <MSN> module. */
#elif defined E2EPW_START_SEC_CODE_LIB
    #undef E2EPW_START_SEC_CODE_LIB
    #define START_SEC_CODE

#elif defined E2EPW_STOP_SEC_CODE_LIB
    #undef E2EPW_STOP_SEC_CODE_LIB
    #define STOP_SEC_CODE

#endif

/*E2EPW END*/

/*E2E START*/

/* Code */
/* To be used for mapping code to application block, boot block, external flash etc. */
#if defined E2E_START_SEC_CODE
    #undef E2E_START_SEC_CODE
    #define START_SEC_CODE
	#define START_SEC_VAR_CLEARED_UNSPECIFIED_10 /* Function Scope Static Var Allocation start */

#elif defined E2E_STOP_SEC_CODE
    #undef E2E_STOP_SEC_CODE
    #define STOP_SEC_CODE
    #define STOP_SEC_VAR /* Function Scope Static Var Allocation end */

/* Variables */
/* To be used for all global or static variables that are never initialized */
#elif defined E2E_START_SEC_VAR_NOINIT_BOOLEAN
    #undef E2E_START_SEC_VAR_NOINIT_BOOLEAN
    #define START_SEC_VAR_NOINIT_8_10

#elif defined E2E_STOP_SEC_VAR_NOINIT_BOOLEAN
    #undef E2E_STOP_SEC_VAR_NOINIT_BOOLEAN
    #define STOP_SEC_VAR

#elif defined E2E_START_SEC_VAR_NOINIT_8BIT
    #undef E2E_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_10

#elif defined E2E_STOP_SEC_VAR_NOINIT_8BIT
    #undef E2E_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR

#elif defined E2E_START_SEC_VAR_NOINIT_16BIT
    #undef E2E_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16_10

#elif defined E2E_STOP_SEC_VAR_NOINIT_16BIT
    #undef E2E_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR

#elif defined E2E_START_SEC_VAR_NOINIT_32BIT
    #undef E2E_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32_10

#elif defined E2E_STOP_SEC_VAR_NOINIT_32BIT
    #undef E2E_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

#elif defined E2E_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef E2E_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10

#elif defined E2E_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef E2E_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR


/* Variables */
/* To be used for global or static variables that are initialized after every
 * reset (the normal case).
 */
#elif defined E2E_START_SEC_VAR_BOOLEAN
    #undef E2E_START_SEC_VAR_BOOLEAN
    #define START_SEC_VAR_INIT_8_10

#elif defined E2E_STOP_SEC_VAR_BOOLEAN
    #undef E2E_STOP_SEC_VAR_BOOLEAN
    #define STOP_SEC_VAR

#elif defined E2E_START_SEC_VAR_8BIT
    #undef E2E_START_SEC_VAR_8BIT
    #define START_SEC_VAR_INIT_8_10

#elif defined E2E_STOP_SEC_VAR_8BIT
    #undef E2E_STOP_SEC_VAR_8BIT
    #define STOP_SEC_VAR

#elif defined E2E_START_SEC_VAR_16BIT
    #undef E2E_START_SEC_VAR_16BIT
    #define START_SEC_VAR_INIT_16_10

#elif defined E2E_STOP_SEC_VAR_16BIT
    #undef E2E_STOP_SEC_VAR_16BIT
    #define STOP_SEC_VAR

#elif defined E2E_START_SEC_VAR_32BIT
    #undef E2E_START_SEC_VAR_32BIT
    #define START_SEC_VAR_INIT_32_10

#elif defined E2E_STOP_SEC_VAR_32BIT
    #undef E2E_STOP_SEC_VAR_32BIT
    #define STOP_SEC_VAR

#elif defined E2E_START_SEC_VAR_UNSPECIFIED
    #undef E2E_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_10

#elif defined E2E_STOP_SEC_VAR_UNSPECIFIED
    #undef E2E_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR


/* Constants */
/* To be used for global or static constants.  */
#elif defined E2E_START_SEC_CONST_BOOLEAN
    #undef E2E_START_SEC_CONST_BOOLEAN
    #define START_SEC_CONST_8BIT

#elif defined E2E_STOP_SEC_CONST_BOOLEAN
    #undef E2E_STOP_SEC_CONST_BOOLEAN
    #define STOP_SEC_CONST

#elif defined E2E_START_SEC_CONST_8BIT
    #undef E2E_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT

#elif defined E2E_STOP_SEC_CONST_8BIT
    #undef E2E_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined E2E_START_SEC_CONST_16BIT
    #undef E2E_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT

#elif defined E2E_STOP_SEC_CONST_16BIT
    #undef E2E_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined E2E_START_SEC_CONST_32BIT
    #undef E2E_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT

#elif defined E2E_STOP_SEC_CONST_32BIT
    #undef E2E_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined E2E_START_SEC_CONST_UNSPECIFIED
    #undef E2E_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED

#elif defined E2E_STOP_SEC_CONST_UNSPECIFIED
    #undef E2E_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST

/* Library code     */
/* To be used for code that shall go into library segments for <MSN> module. */
#elif defined E2E_START_SEC_CODE_LIB
    #undef E2E_START_SEC_CODE_LIB
    #define START_SEC_CODE

#elif defined E2E_STOP_SEC_CODE_LIB
    #undef E2E_STOP_SEC_CODE_LIB
    #define STOP_SEC_CODE

#endif


 
 /**********************************************************************************************************************
 *  APPLMAIN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef APPLMAIN_START_SEC_CODE
  #undef APPLMAIN_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPLMAIN_STOP_SEC_CODE
  #undef APPLMAIN_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif
#ifdef APPLMAIN_START_SEC_VAR_UNSPECIFIED
  #undef APPLMAIN_START_SEC_VAR_UNSPECIFIED
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPLMAIN_STOP_SEC_VAR_UNSPECIFIED
  #undef APPLMAIN_STOP_SEC_VAR_UNSPECIFIED
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

 
/* The following sections are mapped in the Bac_MeMap.h included file
 * BL_START_SEC_CONST_SHARED_DATA is mapped
 *  BM_START_SEC_CONST_HW_DESCRIPTION_TABLE
 *  BL_START_SEC_CONST_BOOTSWE_DESCRIPTION_TABLE
 *  BM_START_SEC_VAR_NOINIT_BOOT_STATUS
 *  BM_START_SEC_CODE
 *  DATA_LOGISTIC_START_SEC_CODE
 *  BL_START_SEC_CONST_BOOTSWE_FLASH_STATUS
 *  DATA_LOGISTIC_START_SEC_VAR_NO_INIT_NVM_DATA
 */

#ifdef APPL_START_SEC_CONST_SWE4_FLASH_STATUS
  #undef APPL_START_SEC_CONST_SWE4_FLASH_STATUS
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPL_STOP_SEC_CONST_SWE4_FLASH_STATUS
  #undef APPL_STOP_SEC_CONST_SWE4_FLASH_STATUS
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef APPL_START_SEC_CONST_SWE3_FLASH_STATUS
  #undef APPL_START_SEC_CONST_SWE3_FLASH_STATUS
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
  #undef APPL_STOP_SEC_CONST_SWE3_FLASH_STATUS
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef APPL_START_SEC_CONST_SWE2_FLASH_STATUS
  #undef APPL_START_SEC_CONST_SWE2_FLASH_STATUS
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
  #undef APPL_STOP_SEC_CONST_SWE2_FLASH_STATUS
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef APPL_START_SEC_CONST_SWE1_FLASH_STATUS
  #undef APPL_START_SEC_CONST_SWE1_FLASH_STATUS
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
  #undef APPL_STOP_SEC_CONST_SWE1_FLASH_STATUS
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef APPL_START_SEC_CONST_SWE4_DESCRIPTION_TABLE
  #undef APPL_START_SEC_CONST_SWE4_DESCRIPTION_TABLE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPL_STOP_SEC_CONST_SWE4_DESCRIPTION_TABLE
  #undef APPL_STOP_SEC_CONST_SWE4_DESCRIPTION_TABLE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
  #undef APPL_START_SEC_CONST_SWE3_DESCRIPTION_TABLE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
  #undef APPL_STOP_SEC_CONST_SWE3_DESCRIPTION_TABLE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
  #undef APPL_START_SEC_CONST_SWE2_DESCRIPTION_TABLE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
  #undef APPL_STOP_SEC_CONST_SWE2_DESCRIPTION_TABLE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
  #undef APPL_START_SEC_CONST_SWE1_DESCRIPTION_TABLE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
  #undef APPL_STOP_SEC_CONST_SWE1_DESCRIPTION_TABLE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif
 
#ifdef BLU_START_SEC_CODE_CORE
   #undef      BLU_START_SEC_CODE_CORE
   #define     START_SEC_CODE
#endif

#ifdef BLU_STOP_SEC_CODE_CORE
   #undef      BLU_STOP_SEC_CODE_CORE
   #define     STOP_SEC_CODE
#endif

#ifdef BLU_START_SEC_VAR_UNSPECIFIED
   #undef      BLU_START_SEC_VAR_UNSPECIFIED
   #define     START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef BLU_STOP_SEC_VAR_UNSPECIFIED
   #undef      BLU_STOP_SEC_VAR_UNSPECIFIED
   #define     STOP_SEC_VAR
#endif

#ifdef BLU_START_SEC_CONST_UNSPECIFIED
   #undef      BLU_START_SEC_CONST_UNSPECIFIED
   #define     START_SEC_CONST_UNSPECIFIED
#endif

#ifdef BLU_STOP_SEC_CONST_UNSPECIFIED
   #undef      BLU_STOP_SEC_CONST_UNSPECIFIED
   #define     STOP_SEC_CONST
#endif

#ifdef BLU_START_SEC_VAR_FLASHBUFFER
   #undef      BLU_START_SEC_VAR_FLASHBUFFER
   /* no explicit memory mapping necessary */
   #define     START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef BLU_STOP_SEC_VAR_FLASHBUFFER
   #undef      BLU_STOP_SEC_VAR_FLASHBUFFER
   /* no explicit memory mapping necessary */
   #define     STOP_SEC_VAR
#endif

#ifdef BLU_START_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
   #undef      BLU_START_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
   #define     START_SEC_CONST_UNSPECIFIED
   #pragma DATA_SECTION (BluSweValidFlag, ".BLUValidFlag")
#endif

#ifdef BLU_STOP_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
   #undef      BLU_STOP_SEC_CONST_SWEFLASHSTATUSVALIDFLAG
   #define     STOP_SEC_CONST
#endif

#ifdef BLU_START_SEC_CONST_SWEFLASHSTATUSCHECKSUM
   #undef      BLU_START_SEC_CONST_SWEFLASHSTATUSCHECKSUM
   #define     START_SEC_CONST_UNSPECIFIED
   #pragma DATA_SECTION (BluSweCheckSum, ".BLUCrc")
#endif

#ifdef BLU_STOP_SEC_CONST_SWEFLASHSTATUSCHECKSUM
   #undef      BLU_STOP_SEC_CONST_SWEFLASHSTATUSCHECKSUM
   #define     STOP_SEC_CONST
#endif

#ifdef BLU_START_SEC_CONST_SWETABLE
   #undef      BLU_START_SEC_CONST_SWETABLE
   #define     START_SEC_CONST_UNSPECIFIED
#endif

#ifdef BLU_STOP_SEC_CONST_SWETABLE
   #undef      BLU_STOP_SEC_CONST_SWETABLE
   #define     STOP_SEC_CONST
#endif

#ifdef BLU_START_SEC_CONST_NVBACKUP_TABLEPOINTER
   #undef      BLU_START_SEC_CONST_NVBACKUP_TABLEPOINTER
   #define     START_SEC_CONST_UNSPECIFIED
   #pragma DATA_SECTION (Blu_NvBackupTablePointer, ".BLUNVBckupPtr")
#endif

#ifdef BLU_STOP_SEC_CONST_NVBACKUP_TABLEPOINTER
   #undef      BLU_STOP_SEC_CONST_NVBACKUP_TABLEPOINTER
   #define     STOP_SEC_CONST
#endif

#ifdef BLU_START_SEC_CODE_WD
   #undef      BLU_START_SEC_CODE_WD
   #define     START_SEC_CODE
#endif

#ifdef BLU_STOP_SEC_CODE_WD
   #undef      BLU_STOP_SEC_CODE_WD
   #define     STOP_SEC_CODE
#endif
/**********************************************************************************************************************
 *  COMM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COMM_START_SEC_CODE
  #undef COMM_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef COMM_STOP_SEC_CODE
  #undef COMM_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef COMM_START_SEC_APPL_CODE
  #undef COMM_START_SEC_APPL_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef COMM_STOP_SEC_APPL_CODE
  #undef COMM_STOP_SEC_APPL_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COMM_START_SEC_CONST_8BIT
# undef COMM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef COMM_STOP_SEC_CONST_8BIT
# undef COMM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef COMM_START_SEC_CONST_16BIT
# undef COMM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef COMM_STOP_SEC_CONST_16BIT
# undef COMM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef COMM_START_SEC_CONST_32BIT
# undef COMM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef COMM_STOP_SEC_CONST_32BIT
# undef COMM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef COMM_START_SEC_CONST_UNSPECIFIED
# undef COMM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_CONST_UNSPECIFIED
# undef COMM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef COMM_START_SEC_VAR_NOINIT_8BIT
# undef COMM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_8BIT
# undef COMM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_16BIT
# undef COMM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_16BIT
# undef COMM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NVRAM sections */

#ifdef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/









/**********************************************************************************************************************
 *  FrSM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRSM_START_SEC_CODE
  #undef FRSM_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FRSM_STOP_SEC_CODE
  #undef FRSM_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRSM_START_SEC_CONST_8BIT
# undef FRSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef FRSM_STOP_SEC_CONST_8BIT
# undef FRSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef FRSM_START_SEC_CONST_32BIT
# undef FRSM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FRSM_STOP_SEC_CONST_32BIT
# undef FRSM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef FRSM_START_SEC_CONST_UNSPECIFIED
# undef FRSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_CONST_UNSPECIFIED
# undef FRSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root pointer to postbuild data */
#ifdef FRSM_START_SEC_PBCFG_ROOT
# undef FRSM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRSM_STOP_SEC_PBCFG_ROOT
# undef FRSM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/* Tables for postbuild data */
#ifdef FRSM_START_SEC_PBCFG
# undef FRSM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRSM_STOP_SEC_PBCFG
# undef FRSM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


/* VAR NOINIT sections */

#ifdef FRSM_START_SEC_VAR_NOINIT_8BIT
# undef FRSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_CLEARED_8_9
#endif
#ifdef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  FrSM END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  Vsm START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef VSM_START_SEC_CODE
# undef VSM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef VSM_STOP_SEC_CODE
# undef VSM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef VSM_START_SEC_CONST_UNSPECIFIED
# undef VSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VSM_STOP_SEC_CONST_UNSPECIFIED
# undef VSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef VSM_START_SEC_CONST_8BIT
# undef VSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef VSM_STOP_SEC_CONST_8BIT
# undef VSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef VSM_START_SEC_CONST_16BIT
# undef VSM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef VSM_STOP_SEC_CONST_16BIT
# undef VSM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef VSM_START_SEC_VAR_NVDATA
# undef VSM_START_SEC_VAR_NVDATA
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef VSM_STOP_SEC_VAR_NVDATA
# undef VSM_STOP_SEC_VAR_NVDATA
# define STOP_SEC_VAR
#endif

#ifdef VSM_START_SEC_VAR_UNSPECIFIED
# undef VSM_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef VSM_STOP_SEC_VAR_UNSPECIFIED
# undef VSM_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef VSM_START_SEC_VAR_8BIT
# undef VSM_START_SEC_VAR_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef VSM_STOP_SEC_VAR_8BIT
# undef VSM_STOP_SEC_VAR_8BIT
# define STOP_SEC_VAR
#endif

#ifdef VSM_START_SEC_VAR_16BIT
# undef VSM_START_SEC_VAR_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef VSM_STOP_SEC_VAR_16BIT
# undef VSM_STOP_SEC_VAR_16BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  Vsm END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef XCP_START_SEC_CODE 
    #undef XCP_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef XCP_STOP_SEC_CODE 
    #undef XCP_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef XCP_START_SEC_CONST_UNSPECIFIED
    #undef XCP_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef XCP_STOP_SEC_CONST_UNSPECIFIED
    #undef XCP_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_CONST_16BIT 
    #undef XCP_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef XCP_STOP_SEC_CONST_16BIT 
    #undef XCP_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef XCP_START_SEC_CONST_8BIT 
    #undef XCP_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef XCP_STOP_SEC_CONST_8BIT 
    #undef XCP_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef XCP_START_SEC_VAR_NOINIT_8BIT 
    #undef XCP_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef XCP_STOP_SEC_VAR_NOINIT_8BIT 
    #undef XCP_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  FRXCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRXCP_START_SEC_CODE 
    #undef FRXCP_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRXCP_STOP_SEC_CODE 
    #undef FRXCP_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRXCP_START_SEC_CONST_UNSPECIFIED 
    #undef FRXCP_START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRXCP_STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_CONST_16BIT 
    #undef FRXCP_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef FRXCP_STOP_SEC_CONST_16BIT 
    #undef FRXCP_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_CONST_8BIT 
    #undef FRXCP_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRXCP_STOP_SEC_CONST_8BIT 
    #undef FRXCP_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_NOINIT_8BIT 
    #undef FRXCP_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef FRXCP_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRXCP_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRXCP END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  Dcm START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef DCM_START_SEC_CODE
# undef DCM_START_SEC_CODE
# define START_SEC_CODE
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef DCM_STOP_SEC_CODE
# undef DCM_STOP_SEC_CODE
# define STOP_SEC_CODE
# define STOP_SEC_VAR
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef DCM_START_SEC_CONST_UNSPECIFIED
# undef DCM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DCM_STOP_SEC_CONST_UNSPECIFIED
# undef DCM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef DCM_START_SEC_CONST_8BIT
# undef DCM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef DCM_STOP_SEC_CONST_8BIT
# undef DCM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Updated the BL SGBMID according to pdx template PT01_template.003_000_191.pdx
 *              with 2048-bit key and SHA-256 hash algorithm
 */
/* Patch code  - START */
#ifdef CAL_START_SEC_CONST_UNSPECIFIED
# undef CAL_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CAL_STOP_SEC_CONST_UNSPECIFIED
# undef CAL_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef CAL_START_SEC_CODE
# undef CAL_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef CAL_STOP_SEC_CODE
# undef CAL_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

#ifdef Cpl_START_SEC_CONST_8
# undef Cpl_START_SEC_CONST_8
# define START_SEC_CONST_8BIT
#endif
#ifdef Cpl_STOP_SEC_CONST_8
# undef Cpl_STOP_SEC_CONST_8
# define STOP_SEC_CONST
#endif

#ifdef Cpl_START_SEC_CONST_32
# undef Cpl_START_SEC_CONST_32
# define START_SEC_CONST_32BIT
#endif
#ifdef Cpl_STOP_SEC_CONST_32
# undef Cpl_STOP_SEC_CONST_32
# define STOP_SEC_CONST
#endif

#ifdef Cpl_START_SEC_CONST_UNSPECIFIED
# undef Cpl_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef Cpl_STOP_SEC_CONST_UNSPECIFIED
# undef Cpl_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef Cpl_START_SEC_CODE
# undef Cpl_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef Cpl_STOP_SEC_CODE
# undef Cpl_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
/* Patch code  - END */
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

/*******  VAR sections  **********************************************************************************************/

#ifdef DCM_START_SEC_VAR_UNSPECIFIED
# undef DCM_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef DCM_STOP_SEC_VAR_UNSPECIFIED
# undef DCM_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DCM_START_SEC_VAR_8BIT
# undef DCM_START_SEC_VAR_8BIT
# define START_SEC_VAR_INIT_8_9
#endif
#ifdef DCM_STOP_SEC_VAR_8BIT
# undef DCM_STOP_SEC_VAR_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DCM_START_SEC_VAR_FAST_8BIT
# undef DCM_START_SEC_VAR_FAST_8BIT
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef DCM_STOP_SEC_VAR_FAST_8BIT
# undef DCM_STOP_SEC_VAR_FAST_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DCM_START_SEC_VAR_16BIT
# undef DCM_START_SEC_VAR_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef DCM_STOP_SEC_VAR_16BIT
# undef DCM_STOP_SEC_VAR_16BIT
# define STOP_SEC_VAR
#endif

#ifdef DCM_START_SEC_VAR_FAST_16BIT
# undef DCM_START_SEC_VAR_FAST_16BIT
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef DCM_STOP_SEC_VAR_FAST_16BIT
# undef DCM_STOP_SEC_VAR_FAST_16BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  Dcm END
 *********************************************************************************************************************/












/**********************************************************************************************************************
 *  Dem START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef DEM_START_SEC_CODE
# undef DEM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DEM_STOP_SEC_CODE
# undef DEM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef DEM_START_SEC_CONST_UNSPECIFIED
# undef DEM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DEM_STOP_SEC_CONST_UNSPECIFIED
# undef DEM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef DEM_START_SEC_CONST_8BIT
# undef DEM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef DEM_STOP_SEC_CONST_8BIT
# undef DEM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef DEM_START_SEC_CONST_32BIT
# undef DEM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef DEM_STOP_SEC_CONST_32BIT
# undef DEM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef DEM_START_SEC_VAR_UNSPECIFIED
# undef DEM_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef DEM_STOP_SEC_VAR_UNSPECIFIED
# undef DEM_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_NOINIT_8BIT
# undef DEM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef DEM_STOP_SEC_VAR_NOINIT_8BIT
# undef DEM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DEM_START_SEC_VAR_NOINIT_16BIT
# undef DEM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef DEM_STOP_SEC_VAR_NOINIT_16BIT
# undef DEM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  Dem END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  Cdc START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef CDC_START_SEC_CODE
# undef CDC_START_SEC_CODE
# define START_SEC_CODE
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef CDC_STOP_SEC_CODE
# undef CDC_STOP_SEC_CODE
# define STOP_SEC_CODE
# define STOP_SEC_VAR
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef CDC_START_SEC_CONST_UNSPECIFIED
# undef CDC_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CDC_STOP_SEC_CONST_UNSPECIFIED
# undef CDC_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef CDC_START_SEC_VAR_NO_INIT_NVDATA
# undef CDC_START_SEC_VAR_NO_INIT_NVDATA
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef CDC_STOP_SEC_VAR_NO_INIT_NVDATA
# undef CDC_STOP_SEC_VAR_NO_INIT_NVDATA
# define STOP_SEC_VAR
#endif

#ifdef CDC_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CDC_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef CDC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CDC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef CDC_START_SEC_VAR_UNSPECIFIED
# undef CDC_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef CDC_STOP_SEC_VAR_UNSPECIFIED
# undef CDC_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef CDC_START_SEC_VAR_8BIT
# undef CDC_START_SEC_VAR_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef CDC_STOP_SEC_VAR_8BIT
# undef CDC_STOP_SEC_VAR_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CDC_START_SEC_VAR_NOINIT_16BIT
# undef CDC_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef CDC_STOP_SEC_VAR_NOINIT_16BIT
# undef CDC_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  Cdc END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Darh START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef DARH_START_SEC_CODE
# undef DARH_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DARH_STOP_SEC_CODE
# undef DARH_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef DARH_START_SEC_CONST_UNSPECIFIED
# undef DARH_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DARH_STOP_SEC_CONST_UNSPECIFIED
# undef DARH_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef DARH_START_SEC_CONST_8BIT
# undef DARH_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef DARH_STOP_SEC_CONST_8BIT
# undef DARH_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef DARH_START_SEC_VAR_UNSPECIFIED
# undef DARH_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef DARH_STOP_SEC_VAR_UNSPECIFIED
# undef DARH_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef DARH_START_SEC_VAR_8BIT
# undef DARH_START_SEC_VAR_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef DARH_STOP_SEC_VAR_8BIT
# undef DARH_STOP_SEC_VAR_8BIT
# define STOP_SEC_VAR
#endif

#ifdef DARH_START_SEC_VAR_16BIT
# undef DARH_START_SEC_VAR_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef DARH_STOP_SEC_VAR_16BIT
# undef DARH_STOP_SEC_VAR_16BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  Darh END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Adc START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ADC_START_SEC_CODE
    #undef ADC_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef ADC_STOP_SEC_CODE
    #undef ADC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ADC_START_SEC_CONST_32
    #undef ADC_START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
#endif

#ifdef ADC_STOP_SEC_CONST_32
    #undef ADC_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
#ifdef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED /* Temporarily allocated to Global Shared to allow access across applications until Nxtr Adc driver is developed */
#endif

#ifdef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Adc END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Adc2 START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ADC2_START_SEC_CODE
    #undef ADC2_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef ADC2_STOP_SEC_CODE
    #undef ADC2_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ADC2_START_SEC_CONST_32
    #undef ADC2_START_SEC_CONST_32
    #define START_SEC_CONST_32BIT
#endif

#ifdef ADC2_STOP_SEC_CONST_32
    #undef ADC2_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
#ifdef ADC2_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef ADC2_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED /* Temporarily allocated to Global Shared to allow access across applications until Nxtr Adc driver is developed */
#endif

#ifdef ADC2_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef ADC2_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Adc2 END
 *********************************************************************************************************************/



#ifdef DIO_START_SEC_CODE
  #undef DIO_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef DIO_STOP_SEC_CODE
  #undef DIO_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef DIO_START_SEC_CONST_UNSPECIFIED
  #undef DIO_START_SEC_CONST_UNSPECIFIED
  #define START_SEC_CONST_32BIT
#endif

#ifdef DIO_STOP_SEC_CONST_UNSPECIFIED
  #undef DIO_STOP_SEC_CONST_UNSPECIFIED
  #define STOP_SEC_CONST
#endif





















/**********************************************************************************************************************
 *  FR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FR_START_SEC_CODE
  #undef FR_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FR_STOP_SEC_CODE
  #undef FR_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


#ifdef FR_START_SEC_CODE_ISR
  #undef FR_START_SEC_CODE_ISR
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#ifdef FR_STOP_SEC_CODE_ISR
  #undef FR_STOP_SEC_CODE_ISR
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef FR_APPL_START_SEC_CODE
    #undef FR_APPL_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef FR_APPL_STOP_SEC_CODE
    #undef FR_APPL_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FR_START_SEC_CONST_32BIT
# undef FR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FR_STOP_SEC_CONST_32BIT
# undef FR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_CONST_16BIT
# undef FR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef FR_STOP_SEC_CONST_16BIT
# undef FR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_CONST_8BIT
# undef FR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef FR_STOP_SEC_CONST_8BIT
# undef FR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif


#ifdef FR_START_SEC_CONST_UNSPECIFIED
# undef FR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_CONST_UNSPECIFIED
# undef FR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef FR_START_SEC_PBCFG_ROOT
# undef FR_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef FR_STOP_SEC_PBCFG_ROOT
# undef FR_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_PBCFG
# undef FR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FR_STOP_SEC_PBCFG
# undef FR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */

#ifdef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FR END
 *********************************************************************************************************************/


#ifdef GPT_START_SEC_CODE
 #undef GPT_START_SEC_CODE
 #define START_SEC_CODE
#endif

#ifdef GPT_STOP_SEC_CODE
 #undef GPT_STOP_SEC_CODE
 #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_CODE_ISR
 #undef GPT_START_SEC_CODE_ISR
 #define START_SEC_CODE_ISR
#endif

#ifdef GPT_STOP_SEC_CODE_ISR
 #undef GPT_STOP_SEC_CODE_ISR
 #define STOP_SEC_CODE
#endif

#ifdef GPT_START_SEC_PBCFG_ROOT
 #undef GPT_START_SEC_PBCFG_ROOT
 #define START_SEC_CONST_PBCFG
#endif

#ifdef GPT_STOP_SEC_PBCFG_ROOT
 #undef GPT_STOP_SEC_PBCFG_ROOT
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_PBCFG
 #undef GPT_START_SEC_PBCFG
 #define START_SEC_CONST_PBCFG
#endif

#ifdef GPT_STOP_SEC_PBCFG
 #undef GPT_STOP_SEC_PBCFG
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_CONST_32BIT
 #undef GPT_START_SEC_CONST_32BIT
 #define START_SEC_CONST_32BIT
#endif

#ifdef GPT_STOP_SEC_CONST_32BIT
 #undef GPT_STOP_SEC_CONST_32BIT
 #define STOP_SEC_CONST
#endif

#ifdef GPT_START_SEC_VAR_32BIT
 #undef GPT_START_SEC_VAR_32BIT
 #define START_SEC_VAR_NOINIT_32_9
#endif

#ifdef GPT_STOP_SEC_VAR_32BIT
 #undef GPT_STOP_SEC_VAR_32BIT
 #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
 #undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
 #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
 #undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
 #define STOP_SEC_VAR
#endif

#ifdef GPT_START_SEC_VAR_UNSPECIFIED
 #undef GPT_START_SEC_VAR_UNSPECIFIED
 #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef GPT_STOP_SEC_VAR_UNSPECIFIED
 #undef GPT_STOP_SEC_VAR_UNSPECIFIED
 #define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01Asr START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ICU_START_SEC_CODE
    #undef ICU_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef ICU_STOP_SEC_CODE
    #undef ICU_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef ICU_START_SEC_CODE_ISR
    #undef ICU_START_SEC_CODE_ISR
    #define START_SEC_CODE_ISR
#endif
#ifdef ICU_STOP_SEC_CODE_ISR
    #undef ICU_STOP_SEC_CODE_ISR
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ICU_START_SEC_CONST_8BIT
    #undef ICU_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef ICU_STOP_SEC_CONST_8BIT
    #undef ICU_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_CONST_32BIT
    #undef ICU_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef ICU_STOP_SEC_CONST_32BIT
    #undef ICU_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_CONST_UNSPECIFIED
    #undef ICU_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ICU_STOP_SEC_CONST_UNSPECIFIED
    #undef ICU_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef ICU_START_SEC_CONST_PBCFG_ROOT
    #undef ICU_START_SEC_CONST_PBCFG_ROOT
    #define START_SEC_CONST_PBCFG
#endif
#ifdef ICU_STOP_SEC_CONST_PBCFG_ROOT
    #undef ICU_STOP_SEC_CONST_PBCFG_ROOT
    #define STOP_SEC_CONST
#endif

#ifdef ICU_START_SEC_CONST_PBCFG
    #undef ICU_START_SEC_CONST_PBCFG
    #define START_SEC_CONST_PBCFG
#endif
#ifdef ICU_STOP_SEC_CONST_PBCFG
    #undef ICU_STOP_SEC_CONST_PBCFG
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef ICU_START_SEC_VAR_NOINIT_8BIT
    #undef ICU_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef ICU_STOP_SEC_VAR_NOINIT_8BIT
    #undef ICU_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_NOINIT_32BIT
    #undef ICU_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32_9
#endif
#ifdef ICU_STOP_SEC_VAR_NOINIT_32BIT
    #undef ICU_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef ICU_START_SEC_VAR_ZERO_INIT_8BIT
    #undef ICU_START_SEC_VAR_ZERO_INIT_8BIT
    #define START_SEC_VAR_CLEARED_8_9
#endif
#ifdef ICU_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef ICU_STOP_SEC_VAR_ZERO_INIT_8BIT
    #define STOP_SEC_VAR
#endif

#ifdef ICU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef ICU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef ICU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef ICU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01Asr END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef HET_START_SEC_CODE
    #undef HET_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef HET_STOP_SEC_CODE
    #undef HET_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#ifdef HET_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef HET_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif

#ifdef HET_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef HET_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  MCU START
 **********************************************************************************************************************/

/****************************************  CODE sections **************************************************************/
#ifdef MCU_START_SEC_CODE
    #undef MCU_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef MCU_STOP_SEC_CODE
    #undef MCU_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

#ifdef MCU_START_SEC_PBCFG
    #undef MCU_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif
#ifdef MCU_STOP_SEC_PBCFG
    #undef MCU_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef MCU_START_SEC_PBCFG_ROOT
  #undef MCU_START_SEC_PBCFG_ROOT
  #define START_SEC_CONST_PBCFG
#endif
#ifdef MCU_STOP_SEC_PBCFG_ROOT
  #undef MCU_STOP_SEC_PBCFG_ROOT
  #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef MCU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef MCU_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef MCU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef MCU_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  MCU END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  PORT START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef PORT_START_SEC_CODE
    #undef PORT_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_CODE
    #undef PORT_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef PORT_START_SEC_PBCODE
    #undef PORT_START_SEC_PBCODE
    #define START_SEC_CODE
#endif

#ifdef PORT_STOP_SEC_PBCODE
    #undef PORT_STOP_SEC_PBCODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef PORT_START_SEC_PBCFG
    #undef PORT_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PORT_STOP_SEC_PBCFG
    #undef PORT_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef PORT_START_SEC_PBCFG_ROOT
    #undef PORT_START_SEC_PBCFG_ROOT
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PORT_STOP_SEC_PBCFG_ROOT
    #undef PORT_STOP_SEC_PBCFG_ROOT
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef PORT_START_SEC_VAR_UNSPECIFIED
    #undef PORT_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif

#ifdef PORT_STOP_SEC_VAR_UNSPECIFIED
    #undef PORT_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PORT END 
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  PWM START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef PWM_START_SEC_CODE
    #undef PWM_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef PWM_STOP_SEC_CODE
    #undef PWM_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

#ifdef PWM_START_SEC_CODE_ISR
    #undef PWM_START_SEC_CODE_ISR
    #define START_SEC_CODE_ISR
#endif

#ifdef PWM_STOP_SEC_CODE_ISR
    #undef PWM_STOP_SEC_CODE_ISR
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef PWM_START_SEC_CONST_PBCFG
    #undef PWM_START_SEC_CONST_PBCFG
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PWM_STOP_SEC_CONST_PBCFG
    #undef PWM_STOP_SEC_CONST_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef PWM_START_SEC_CONST_PBCFG_ROOT
    #undef PWM_START_SEC_CONST_PBCFG_ROOT
    #define START_SEC_CONST_PBCFG
#endif

#ifdef PWM_STOP_SEC_CONST_PBCFG_ROOT
    #undef PWM_STOP_SEC_CONST_PBCFG_ROOT
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef PWM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef PWM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef PWM_START_SEC_VAR_INIT_8BIT
    #undef PWM_START_SEC_VAR_INIT_8BIT
    #define START_SEC_VAR_INIT_8_9
#endif

#ifdef PWM_STOP_SEC_VAR_INIT_8BIT
    #undef PWM_STOP_SEC_VAR_INIT_8BIT
    #define STOP_SEC_VAR
#endif


#ifdef PWM_START_SEC_VAR_NOINIT_8BIT
    #undef PWM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef PWM_STOP_SEC_VAR_NOINIT_8BIT
    #undef PWM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  PWM END 
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Spi START 
 **********************************************************************************************************************/

/*******  CODE sections  **********************************************************************************************/

#ifdef SPI_START_SEC_CODE
    #undef SPI_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
    #undef SPI_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  ISR sections  ***********************************************************************************************/

#ifdef SPI_START_SEC_CODE_ISR
    #undef SPI_START_SEC_CODE_ISR
    #define START_SEC_CODE_ISR
#endif

#ifdef SPI_STOP_SEC_CODE_ISR
    #undef SPI_STOP_SEC_CODE_ISR
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

#ifdef SPI_START_SEC_PBCFG_ROOT
    #undef SPI_START_SEC_PBCFG_ROOT
    #define START_SEC_CONST_PBCFG
#endif

#ifdef SPI_STOP_SEC_PBCFG_ROOT
    #undef SPI_STOP_SEC_PBCFG_ROOT
    #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_PBCFG
    #undef SPI_START_SEC_PBCFG
    #define START_SEC_CONST_PBCFG
#endif

#ifdef SPI_STOP_SEC_PBCFG
    #undef SPI_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_32BIT
    #undef SPI_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef SPI_STOP_SEC_CONST_32BIT
    #undef SPI_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef SPI_START_SEC_CONST_UNSPECIFIED
    #undef SPI_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef SPI_STOP_SEC_CONST_UNSPECIFIED
    #undef SPI_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  ***********************************************************************************************/
#ifdef SPI_START_SEC_VAR_INIT_UNSPECIFIED
    #undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif

#ifdef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif

#ifdef SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  Spi END
 **********************************************************************************************************************/

























/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRTRCV_START_SEC_CODE 
    #undef FRTRCV_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_STOP_SEC_CODE 
    #undef FRTRCV_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRTRCV_START_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRTRCV_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_START_SEC_CONST_32BIT 
    #undef FRTRCV_START_SEC_CONST_32BIT 
    #define START_SEC_CONST_32BIT
#endif

#ifdef FRTRCV_STOP_SEC_CONST_32BIT 
    #undef FRTRCV_STOP_SEC_CONST_32BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_START_SEC_CONST_16BIT 
    #undef FRTRCV_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef FRTRCV_STOP_SEC_CONST_16BIT 
    #undef FRTRCV_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_START_SEC_CONST_8BIT 
    #undef FRTRCV_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRTRCV_STOP_SEC_CONST_8BIT 
    #undef FRTRCV_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif

#ifdef FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_START_SEC_VAR_INIT_8BIT 
    #undef FRTRCV_START_SEC_VAR_INIT_8BIT 
    #define START_SEC_VAR_INIT_8_9
#endif

#ifdef FRTRCV_STOP_SEC_VAR_INIT_8BIT 
    #undef FRTRCV_STOP_SEC_VAR_INIT_8BIT 
    #define STOP_SEC_VAR
#endif


 #ifdef FRTRCV_START_SEC_VAR_NOINIT_8BIT 
    #undef FRTRCV_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_INIT_8_9
#endif

#ifdef FRTRCV_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRTRCV_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  WDG START
 *********************************************************************************************************************/

/* Code section - START */
#if defined WDG_START_SEC_CODE                      /* Code */
    #undef WDG_START_SEC_CODE
    #define START_SEC_CODE
#elif defined WDG_STOP_SEC_CODE
    #undef WDG_STOP_SEC_CODE
    #define STOP_SEC_CODE

#elif defined WDG_START_SEC_CONST_8BIT         /* Global or static constants */
    #undef WDG_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#elif defined WDG_STOP_SEC_CONST_8BIT
    #undef WDG_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_16BIT
    #undef WDG_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#elif defined WDG_STOP_SEC_CONST_16BIT
    #undef WDG_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_32BIT
    #undef WDG_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#elif defined WDG_STOP_SEC_CONST_32BIT
    #undef WDG_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined WDG_START_SEC_CONST_UNSPECIFIED
    #undef WDG_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined WDG_STOP_SEC_CONST_UNSPECIFIED
    #undef WDG_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  WDG END
 *********************************************************************************************************************/








/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IOHWAB_START_SEC_CODE
    #undef IOHWAB_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef IOHWAB_STOP_SEC_CODE
    #undef IOHWAB_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef IOHWAB_START_SEC_CONST_32BIT
    #undef IOHWAB_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef IOHWAB_STOP_SEC_CONST_32BIT
    #undef IOHWAB_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef IOHWAB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef IOHWAB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef PDUR_START_SEC_CODE
# undef PDUR_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef PDUR_STOP_SEC_CODE
# undef PDUR_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef PDUR_START_SEC_CONST_8BIT
# undef PDUR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_8BIT
# undef PDUR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_16BIT
# undef PDUR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_16BIT
# undef PDUR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_32BIT
# undef PDUR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef PDUR_STOP_SEC_CONST_32BIT
# undef PDUR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_CONST_UNSPECIFIED
# undef PDUR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef PDUR_STOP_SEC_CONST_UNSPECIFIED
# undef PDUR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef PDUR_START_SEC_PBCFG
# undef PDUR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG
# undef PDUR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef PDUR_START_SEC_PBCFG_ROOT
# undef PDUR_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef PDUR_STOP_SEC_PBCFG_ROOT
# undef PDUR_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED           
# define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED           
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef PDUR_START_SEC_VAR_NOINIT_BOOLEAN
# undef PDUR_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef PDUR_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif



#ifdef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/









/**********************************************************************************************************************
 *  FRIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRIF_START_SEC_CODE
  #undef FRIF_START_SEC_CODE                        /* PRQA S 0841 */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FRIF_STOP_SEC_CODE
  #undef FRIF_STOP_SEC_CODE                         /* PRQA S 0841 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef FRIF_START_SEC_APPL_CODE
  #undef FRIF_START_SEC_APPL_CODE                   /* PRQA S 0841 */
  #define START_SEC_CODE                            /* mapped to default appl code section */
#endif
#ifdef FRIF_STOP_SEC_APPL_CODE
  #undef FRIF_STOP_SEC_APPL_CODE                    /* PRQA S 0841 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRIF_START_SEC_CONST_32BIT
# undef FRIF_START_SEC_CONST_32BIT                  /* PRQA S 0841 */
# define START_SEC_CONST_32BIT
#endif
#ifdef FRIF_STOP_SEC_CONST_32BIT
# undef FRIF_STOP_SEC_CONST_32BIT                   /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef FRIF_START_SEC_CONST_UNSPECIFIED
# undef FRIF_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_CONST_UNSPECIFIED  
# undef FRIF_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef FRIF_START_SEC_PBCFG
# undef FRIF_START_SEC_PBCFG                        /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRIF_STOP_SEC_PBCFG
# undef FRIF_STOP_SEC_PBCFG                         /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif

#ifdef FRIF_START_SEC_PBCFG_ROOT
# undef FRIF_START_SEC_PBCFG_ROOT                   /* PRQA S 0841 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRIF_STOP_SEC_PBCFG_ROOT
# undef FRIF_STOP_SEC_PBCFG_ROOT                    /* PRQA S 0841 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif

#ifdef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */
# define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRIF END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FEE START
 *********************************************************************************************************************/
/*******  CODE sections **********************************************************************************************/

#ifdef FEE_START_SEC_CODE
    #undef FEE_START_SEC_CODE
    #define START_SEC_CODE
 	#define START_SEC_VAR_INIT_UNSPECIFIED_10
#endif
#ifdef FEE_STOP_SEC_CODE
    #undef FEE_STOP_SEC_CODE
    #define STOP_SEC_CODE
	#define STOP_SEC_VAR
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_START_SEC_CONST_UNSPECIFIED
    #undef FEE_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_CONST_UNSPECIFIED
    #undef FEE_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR INIT sections */

#ifdef FEE_START_SEC_VAR_INIT_UNSPECIFIED
    #undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
	#define START_SEC_VAR_INIT_UNSPECIFIED_10
#endif
#ifdef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  FEE END
 *********************************************************************************************************************/



#ifdef MEMIF_START_SEC_CONST_8BIT 
    #undef MEMIF_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef MEMIF_STOP_SEC_CONST_8BIT 
    #undef MEMIF_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


#ifdef MEMIF_START_SEC_CONST_32BIT
    #undef MEMIF_START_SEC_CONST_32BIT
	#include "Cd_FeeIf.h"
    #define START_SEC_CONST_32BIT
	#define Fee_Read					TWrapC_Fee_Read
	#define Fee_Write 					TWrapC_Fee_Write
	#define Fee_EraseImmediateBlock 	TWrapC_Fee_EraseImmediateBlock
	#define Fee_InvalidateBlock 		TWrapC_Fee_InvalidateBlock
	#define Fee_Cancel 					TWrapC_Fee_Cancel
	#define Fee_GetStatus 		 		(MemIf_ApiGetJobResultType)TWrapC_Fee_GetStatus
	#define Fee_GetJobResult 		 	(MemIf_ApiGetJobResultType)TWrapC_Fee_GetJobResult
#endif

#ifdef MEMIF_STOP_SEC_CONST_32BIT
	#undef MEMIF_STOP_SEC_CONST_32BIT
	#define STOP_SEC_CONST
	#undef Fee_Read
	#undef Fee_Write
	#undef Fee_EraseImmediateBlock
	#undef Fee_InvalidateBlock
	#undef Fee_Cancel
	#undef Fee_GetStatus
	#undef Fee_GetJobResult
#endif



#ifdef MEMIF_START_SEC_CODE
    #undef MEMIF_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef MEMIF_STOP_SEC_CODE
    #undef MEMIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif





/**********************************************************************************************************************
 *  If_AsrIfWd START
 *********************************************************************************************************************/

/* Code section - START */
#if defined WDGIF_START_SEC_CODE                      /* Code */
    #undef WDGIF_START_SEC_CODE
    #define START_SEC_CODE
#elif defined WDGIF_STOP_SEC_CODE
    #undef WDGIF_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/* Variables - START */
#if defined WDGIF_START_SEC_VAR_INIT_8BIT           /* Init variables */
    #undef WDGIF_START_SEC_VAR_INIT_8BIT
    #define START_SEC_VAR_INIT_8_9
#elif defined WDGIF_STOP_SEC_VAR_INIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_16BIT
    #undef WDGIF_START_SEC_VAR_INIT_16BIT
    #define START_SEC_VAR_INIT_16_9
#elif defined WDGIF_STOP_SEC_VAR_INIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_32BIT
    #undef WDGIF_START_SEC_VAR_INIT_32BIT
    #define START_SEC_VAR_INIT_32_9
#elif defined WDGIF_STOP_SEC_VAR_INIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_INIT_UNSPECIFIED
    #define START_SEC_VAR_INIT_UNSPECIFIED_9
#elif defined WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_INIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_8BIT           /* No init variables */
    #undef WDGIF_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_16BIT
    #undef WDGIF_START_SEC_VAR_NOINIT_16BIT
    #define START_SEC_VAR_NOINIT_16_9
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_32BIT
    #undef WDGIF_START_SEC_VAR_NOINIT_32BIT
    #define START_SEC_VAR_NOINIT_32_9
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_NOINIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#elif defined WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_8BIT           /* Zero init variables */
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_8BIT
    #define START_SEC_VAR_CLEARED_8_9
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_8BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_16BIT
    #define START_SEC_VAR_CLEARED_16_9
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_16BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_32BIT
    #define START_SEC_VAR_CLEARED_32_9
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_32BIT
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDGIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#elif defined WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDGIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR

#elif defined WDGIF_START_SEC_CONST_8BIT         /* Global or static constants */
    #undef WDGIF_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#elif defined WDGIF_STOP_SEC_CONST_8BIT
    #undef WDGIF_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_16BIT
    #undef WDGIF_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#elif defined WDGIF_STOP_SEC_CONST_16BIT
    #undef WDGIF_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_32BIT
    #undef WDGIF_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#elif defined WDGIF_STOP_SEC_CONST_32BIT
    #undef WDGIF_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST

#elif defined WDGIF_START_SEC_CONST_UNSPECIFIED
    #undef WDGIF_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#elif defined WDGIF_STOP_SEC_CONST_UNSPECIFIED
    #undef WDGIF_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  If_AsrIfWd END
 *********************************************************************************************************************/









/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COM_START_SEC_CODE
# undef COM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_CODE
# undef COM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
/* COM application callback code section (Rte_Cbk.h)*/
#ifdef COM_START_SEC_APPL_CODE
# undef COM_START_SEC_APPL_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_APPL_CODE
# undef COM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COM_START_SEC_CONST_32BIT
# undef COM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef COM_STOP_SEC_CONST_32BIT
# undef COM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_UNSPECIFIED
# undef COM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_CONST_UNSPECIFIED
# undef COM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef COM_START_SEC_PBCFG_ROOT
# undef COM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG_ROOT
# undef COM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_PBCFG
# undef COM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG
# undef COM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef COM_START_SEC_VAR_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef COM_START_SEC_VAR_NOINIT_BOOLEAN
# undef COM_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef COM_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_8BIT
# undef COM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_8BIT
# undef COM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_16BIT
# undef COM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_16BIT
# undef COM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/






/**********************************************************************************************************************
 *  IpduM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IPDUM_START_SEC_CODE
# undef IPDUM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef IPDUM_STOP_SEC_CODE
# undef IPDUM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef IPDUM_START_SEC_CONST_8BIT
# undef IPDUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef IPDUM_STOP_SEC_CONST_8BIT
# undef IPDUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef IPDUM_START_SEC_CONST_UNSPECIFIED
# undef IPDUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_CONST_UNSPECIFIED
# undef IPDUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
#ifdef IPDUM_START_SEC_VAR_FAST_8BIT
# undef IPDUM_START_SEC_VAR_FAST_8BIT
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef IPDUM_STOP_SEC_VAR_FAST_8BIT
# undef IPDUM_STOP_SEC_VAR_FAST_8BIT
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_FAST_UNSPECIFIED
# undef IPDUM_START_SEC_VAR_FAST_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef IPDUM_STOP_SEC_VAR_FAST_UNSPECIFIED
# undef IPDUM_STOP_SEC_VAR_FAST_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef IPDUM_START_SEC_VAR_NOINIT_32BIT
# undef IPDUM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32_9
#endif
#ifdef IPDUM_STOP_SEC_VAR_NOINIT_32BIT
# undef IPDUM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

/* Postbuild CFG struct sections */
#ifdef IPDUM_START_CONFIG_DATA_UNSPECIFIED
# undef IPDUM_START_CONFIG_DATA_UNSPECIFIED
# define START_SEC_CONST_PBCFG
#endif
#ifdef IPDUM_STOP_CONFIG_DATA_UNSPECIFIED
# undef IPDUM_STOP_CONFIG_DATA_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  IpduM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef NVM_START_SEC_CODE
    #undef NVM_START_SEC_CODE
    #define START_SEC_CODE                /* mapped to default code section */
#endif
#ifdef NVM_STOP_SEC_CODE
    #undef NVM_STOP_SEC_CODE
    #define STOP_SEC_CODE                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef NVM_START_SEC_CONST_8BIT
    #undef NVM_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef NVM_STOP_SEC_CONST_8BIT
    #undef NVM_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_16BIT
    #undef NVM_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef NVM_STOP_SEC_CONST_16BIT
    #undef NVM_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_UNSPECIFIED
    #undef NVM_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_UNSPECIFIED
    #undef NVM_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_START_SEC_CONST_DESCRIPTOR_TABLE
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #undef NVM_STOP_SEC_CONST_DESCRIPTOR_TABLE
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef NVM_START_SEC_VAR_NOINIT_8BIT
    #undef NVM_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_8BIT
    #undef NVM_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef NVM_START_SEC_VAR_UNSPECIFIED
    #undef NVM_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */

#ifdef NVM_START_SEC_VAR_FAST_8BIT
    #undef NVM_START_SEC_VAR_FAST_8BIT
    #define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef NVM_STOP_SEC_VAR_FAST_8BIT
    #undef NVM_STOP_SEC_VAR_FAST_8BIT
    #define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define START_SEC_VAR_CLEARED_UNSPECIFIED_9
#endif
#ifdef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #undef NVM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/














#ifdef CRC_START_SEC_CODE
    #undef CRC_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef CRC_START_SEC_CONST_8BIT
    #undef CRC_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef CRC_START_SEC_CONST_16BIT
    #undef CRC_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef CRC_START_SEC_CONST_32BIT
    #undef CRC_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif

#ifdef CRC_STOP_SEC_CODE
    #undef CRC_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif
#ifdef CRC_STOP_SEC_CONST_8BIT
    #undef CRC_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef CRC_STOP_SEC_CONST_16BIT
    #undef CRC_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef CRC_STOP_SEC_CONST_32BIT
    #undef CRC_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif



#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_UNSPECIFIED
# undef DET_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef DET_STOP_SEC_VAR_UNSPECIFIED
# undef DET_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef ECUM_START_SEC_CODE
# undef ECUM_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ECUM_STOP_SEC_CODE
# undef ECUM_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ECUM_START_SEC_CODE_SET_BOOT_TARGET
# undef ECUM_START_SEC_CODE_SET_BOOT_TARGET
# define START_SEC_CODE                            /* mapped to default fast code section */
#endif
#ifdef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# undef ECUM_STOP_SEC_CODE_SET_BOOT_TARGET
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ECUM_START_SEC_CODE_GET_BOOT_TARGET
# undef ECUM_START_SEC_CODE_GET_BOOT_TARGET
# define START_SEC_CODE                            /* mapped to default ISR code section */
#endif
#ifdef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# undef ECUM_STOP_SEC_CODE_GET_BOOT_TARGET
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ECUM_START_SEC_CONST_8BIT
# undef ECUM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef ECUM_STOP_SEC_CONST_8BIT
# undef ECUM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef ECUM_START_SEC_CONST_UNSPECIFIED
# undef ECUM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ECUM_STOP_SEC_CONST_UNSPECIFIED
# undef ECUM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data */
#ifdef ECUM_START_SEC_CONST_PBCFG_ROOT
# undef ECUM_START_SEC_CONST_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG_ROOT
# undef ECUM_STOP_SEC_CONST_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef ECUM_START_SEC_CONST_PBCFG
# undef ECUM_START_SEC_CONST_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ECUM_STOP_SEC_CONST_PBCFG
# undef ECUM_STOP_SEC_CONST_PBCFG
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef ECUM_START_SEC_VAR_NOINIT_8BIT
# undef ECUM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_16BIT
# undef ECUM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# undef ECUM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */


/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  If_AsrIfEa START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef EA_START_SEC_CODE
    #undef EA_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef EA_STOP_SEC_CODE
    #undef EA_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef EA_START_SEC_CONST_8BIT
    #undef EA_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef EA_STOP_SEC_CONST_8BIT
    #undef EA_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef EA_START_SEC_CONST_16BIT
    #undef EA_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef EA_STOP_SEC_CONST_16BIT
    #undef EA_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef EA_START_SEC_CONST_32BIT
    #undef EA_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef EA_STOP_SEC_CONST_32BIT
    #undef EA_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef EA_START_SEC_CONST_UNSPECIFIED
    #undef EA_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_CONST_UNSPECIFIED
    #undef EA_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR NOINIT sections */

#ifdef EA_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef EA_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST sections */

#ifdef EA_START_SEC_VAR_FAST_UNSPECIFIED
    #undef EA_START_SEC_VAR_FAST_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef EA_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_FAST_UNSPECIFIED
    #define STOP_SEC_VAR
#endif


#ifdef EA_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef EA_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef EA_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  If_AsrIfEa END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  EEP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef EEP_30_AT25128_START_SEC_CODE
    #undef EEP_30_AT25128_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef EEP_30_AT25128_STOP_SEC_CODE
    #undef EEP_30_AT25128_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef EEP_30_AT25128_START_SEC_PBCFG
    #undef EEP_30_AT25128_START_SEC_PBCFG
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef EEP_30_AT25128_STOP_SEC_PBCFG
    #undef EEP_30_AT25128_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif


#ifdef EEP_30_AT25128_INST2_START_SEC_PBCFG
    #undef EEP_30_AT25128_INST2_START_SEC_PBCFG
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef EEP_30_AT25128_INST2_STOP_SEC_PBCFG
    #undef EEP_30_AT25128_INST2_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif


#ifdef EEP_30_AT25128_START_SEC_CONST_UNSPECIFIED
    #undef EEP_30_AT25128_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef EEP_30_AT25128_STOP_SEC_CONST_UNSPECIFIED
    #undef EEP_30_AT25128_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


#ifdef EEP_30_AT25128_INST2_START_SEC_CONST_UNSPECIFIED
    #undef EEP_30_AT25128_INST2_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef EEP_30_AT25128_INST2_STOP_SEC_CONST_UNSPECIFIED
    #undef EEP_30_AT25128_INST2_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef EEP_30_AT25128_START_SEC_VAR_NOINIT_8BIT
    #undef EEP_30_AT25128_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef EEP_30_AT25128_STOP_SEC_VAR_NOINIT_8BIT
    #undef EEP_30_AT25128_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif


#ifdef EEP_30_AT25128_INST2_START_SEC_VAR_NOINIT_8BIT
    #undef EEP_30_AT25128_INST2_START_SEC_VAR_NOINIT_8BIT
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef EEP_30_AT25128_INST2_STOP_SEC_VAR_NOINIT_8BIT
    #undef EEP_30_AT25128_INST2_STOP_SEC_VAR_NOINIT_8BIT
    #define STOP_SEC_VAR
#endif


#ifdef EEP_30_AT25128_START_SEC_VAR_UNSPECIFIED
    #undef EEP_30_AT25128_START_SEC_VAR_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_8_9
#endif

#ifdef EEP_30_AT25128_STOP_SEC_VAR_UNSPECIFIED
    #undef EEP_30_AT25128_STOP_SEC_VAR_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EEP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Coding START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef CODING_START_SEC_CODE
# undef CODING_START_SEC_CODE
# define START_SEC_CODE
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef CODING_STOP_SEC_CODE
# undef CODING_STOP_SEC_CODE
# define STOP_SEC_CODE
# define STOP_SEC_VAR
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef CODING_START_SEC_CONST_UNSPECIFIED
# undef CODING_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CODING_STOP_SEC_CONST_UNSPECIFIED
# undef CODING_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef CODING_START_SEC_CONST_UNSPECIFIED_DESCRIPTOR_TABLE
# undef CODING_START_SEC_CONST_UNSPECIFIED_DESCRIPTOR_TABLE
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CODING_STOP_SEC_CONST_UNSPECIFIED_DESCRIPTOR_TABLE
# undef CODING_STOP_SEC_CONST_UNSPECIFIED_DESCRIPTOR_TABLE
# define STOP_SEC_CONST
#endif

#ifdef CODING_START_SEC_CONST_8BIT
# undef CODING_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef CODING_STOP_SEC_CONST_8BIT
# undef CODING_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef CODING_START_SEC_VAR_NO_INIT_NVDATA
# undef CODING_START_SEC_VAR_NO_INIT_NVDATA
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef CODING_STOP_SEC_VAR_NO_INIT_NVDATA
# undef CODING_STOP_SEC_VAR_NO_INIT_NVDATA
# define STOP_SEC_VAR
#endif

#ifdef CODING_START_SEC_VAR_UNSPECIFIED
# undef CODING_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef CODING_STOP_SEC_VAR_UNSPECIFIED
# undef CODING_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif


#ifdef CODINGSAMPLE_START_SEC_CODE
# undef CODINGSAMPLE_START_SEC_CODE
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef CODINGSAMPLE_STOP_SEC_CODE
# undef CODINGSAMPLE_STOP_SEC_CODE
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  Coding END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  Crypto START 
 *********************************************************************************************************************/
 /*
  * Attention: Some memory section need to be defined identical among bootloader and application. These sections
  *            are handled in a separate file, e.g. Bac21_MemMap.h
  */
 
/*******  CODE sections **********************************************************************************************/

#ifdef CRYPTO_START_SEC_CODE
# undef CRYPTO_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef CRYPTO_STOP_SEC_CODE
# undef CRYPTO_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_START_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_STOP_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_STOP_SEC_ASYM2_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_COMM_RNG_VAR_NOINIT_32BIT
# undef CRYPTO_START_SEC_COMM_RNG_VAR_NOINIT_32BIT
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_STOP_SEC_COMM_RNG_VAR_NOINIT_32BIT
# undef CRYPTO_STOP_SEC_COMM_RNG_VAR_NOINIT_32BIT
# define STOP_SEC_CONST
#endif
   

#ifdef CRYPTO_START_SEC_SYMM_VAR_NOINIT_8BIT
# undef CRYPTO_START_SEC_SYMM_VAR_NOINIT_8BIT
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_STOP_SEC_SYMM_VAR_NOINIT_8BIT
# undef CRYPTO_STOP_SEC_SYMM_VAR_NOINIT_8BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_COMM_VAR_NOINIT_8BIT
# undef CRYPTO_START_SEC_COMM_VAR_NOINIT_8BIT
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_STOP_SEC_COMM_VAR_NOINIT_8BIT
# undef CRYPTO_STOP_SEC_COMM_VAR_NOINIT_8BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_RAND_SEED_VAR_NOINIT_32BIT
# undef CRYPTO_START_SEC_RAND_SEED_VAR_NOINIT_32BIT
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_STOP_SEC_RAND_SEED_VAR_NOINIT_32BIT
# undef CRYPTO_STOP_SEC_RAND_SEED_VAR_NOINIT_32BIT
# define STOP_SEC_CONST
#endif

/* ----------------------------------- NXTR PATCH START -------------------------------------
 * Added by: Archana Shivarudrappa
 * Date: 10/03/2016
 * Description: Removed since MD5 is no longer used
 */
 #if 0
/* Original code - START */
#ifdef CRYPTO_START_SEC_MD5_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_START_SEC_MD5_VAR_NOINIT_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_STOP_SEC_MD5_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_STOP_SEC_MD5_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_CONST
#endif
/* Original code - END */
#endif
/* ----------------------------------- NXTR PATCH END -------------------------------------*/

#ifdef CRYPTO_START_SEC_COMM_HASH_CONST_UNSPECIFIED
# undef CRYPTO_START_SEC_COMM_HASH_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_STOP_SEC_COMM_HASH_CONST_UNSPECIFIED
# undef CRYPTO_STOP_SEC_COMM_HASH_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_KEK_KEY_CONST_8BIT
# undef CRYPTO_START_SEC_KEK_KEY_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef CRYPTO_STOP_SEC_KEK_KEY_CONST_8BIT
# undef CRYPTO_STOP_SEC_KEK_KEY_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_SYMM_KEY_CONST_8BIT
# undef CRYPTO_START_SEC_SYMM_KEY_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef CRYPTO_STOP_SEC_SYMM_KEY_CONST_8BIT
# undef CRYPTO_STOP_SEC_SYMM_KEY_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_SYMM_SIG_CONST_8BIT
# undef CRYPTO_START_SEC_SYMM_SIG_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef CRYPTO_STOP_SEC_SYMM_SIG_CONST_8BIT
# undef CRYPTO_STOP_SEC_SYMM_SIG_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_SYMM_COD_SIG_CONST_8BIT
# undef CRYPTO_START_SEC_SYMM_COD_SIG_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef CRYPTO_STOP_SEC_SYMM_COD_SIG_CONST_8BIT
# undef CRYPTO_STOP_SEC_SYMM_COD_SIG_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_PUBKEY_AUTH_S1_CONST_32BIT
# undef CRYPTO_START_SEC_PUBKEY_AUTH_S1_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef CRYPTO_STOP_SEC_PUBKEY_AUTH_S1_CONST_32BIT
# undef CRYPTO_STOP_SEC_PUBKEY_AUTH_S1_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_PUBKEY_AUTH_S3_CONST_32BIT
# undef CRYPTO_START_SEC_PUBKEY_AUTH_S3_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef CRYPTO_STOP_SEC_PUBKEY_AUTH_S3_CONST_32BIT
# undef CRYPTO_STOP_SEC_PUBKEY_AUTH_S3_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_PUBKEY_SIG_CONST_32BIT
# undef CRYPTO_START_SEC_PUBKEY_SIG_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef CRYPTO_STOP_SEC_PUBKEY_SIG_CONST_32BIT
# undef CRYPTO_STOP_SEC_PUBKEY_SIG_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_START_SEC_PUBKEY_NCD_SIG_CONST_32BIT
# undef CRYPTO_START_SEC_PUBKEY_NCD_SIG_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef CRYPTO_STOP_SEC_PUBKEY_NCD_SIG_CONST_32BIT
# undef CRYPTO_STOP_SEC_PUBKEY_NCD_SIG_CONST_32BIT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/


/**********************************************************************************************************************
 *  Crypto END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Csm START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef CSM_START_SEC_CODE
# undef CSM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef CSM_STOP_SEC_CODE
# undef CSM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef CSM_START_SEC_CONST_UNSPECIFIED
# undef CSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_CONST_UNSPECIFIED
# undef CSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef CSM_START_SEC_CONST_8BIT
# undef CSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef CSM_STOP_SEC_CONST_8BIT
# undef CSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef CSM_START_SEC_CONST_32BIT
# undef CSM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef CSM_STOP_SEC_CONST_32BIT
# undef CSM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NO_INIT_8BIT
# undef CSM_START_SEC_VAR_NO_INIT_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef CSM_STOP_SEC_VAR_NO_INIT_8BIT
# undef CSM_STOP_SEC_VAR_NO_INIT_8BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  Csm END
 *********************************************************************************************************************/


















/**********************************************************************************************************************
 *  SchM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SCHM_START_SEC_CODE
# undef SCHM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef SCHM_STOP_SEC_CODE
# undef SCHM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SCHM_START_SEC_CONST_8BIT
# undef SCHM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef SCHM_STOP_SEC_CONST_8BIT
# undef SCHM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef SCHM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SCHM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef SCHM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SCHM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO_INIT sections */

#ifdef SCHM_START_SEC_VAR_ZERO_INIT_8BIT
# undef SCHM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_CLEARED_8_9
#endif
#ifdef SCHM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SCHM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SchM END
 *********************************************************************************************************************/






/**********************************************************************************************************************
 *  SysTimeClient START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef SYSTIMECLIENT_START_SEC_CODE
# undef SYSTIMECLIENT_START_SEC_CODE
# define START_SEC_CODE
#define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef SYSTIMECLIENT_STOP_SEC_CODE
# undef SYSTIMECLIENT_STOP_SEC_CODE
# define STOP_SEC_CODE
# define STOP_SEC_VAR
#endif


/*******  CONST sections  ********************************************************************************************/


/*******  VAR sections  **********************************************************************************************/

#ifdef SYSTIMECLIENT_START_SEC_VAR_8BIT
# undef SYSTIMECLIENT_START_SEC_VAR_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef SYSTIMECLIENT_STOP_SEC_VAR_8BIT
# undef SYSTIMECLIENT_STOP_SEC_VAR_8BIT
# define STOP_SEC_VAR
#endif

#ifdef SYSTIMECLIENT_START_SEC_VAR_16BIT
# undef SYSTIMECLIENT_START_SEC_VAR_16BIT
# define START_SEC_VAR_NOINIT_16_9
#endif
#ifdef SYSTIMECLIENT_STOP_SEC_VAR_16BIT
# undef SYSTIMECLIENT_STOP_SEC_VAR_16BIT
# define STOP_SEC_VAR
#endif

#ifdef SYSTIMECLIENT_START_SEC_VAR_32BIT
# undef SYSTIMECLIENT_START_SEC_VAR_32BIT
# define START_SEC_VAR_INIT_32_9
#endif
#ifdef SYSTIMECLIENT_STOP_SEC_VAR_32BIT
# undef SYSTIMECLIENT_STOP_SEC_VAR_32BIT
# define STOP_SEC_VAR
#endif

#ifdef SYSTIMECLIENT_START_SEC_VAR_UNSPECIFIED
# undef SYSTIMECLIENT_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED_9
#endif
#ifdef SYSTIMECLIENT_STOP_SEC_VAR_UNSPECIFIED
# undef SYSTIMECLIENT_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  SysTimeClient END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  Dma START 
 *********************************************************************************************************************/
 
 #ifdef DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef DMA_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED_10
#endif
#ifdef DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef DMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR
#endif

 #ifdef DMA_START_SEC_VAR_CLEARED_BOOLEAN
# undef DMA_START_SEC_VAR_CLEARED_BOOLEAN
# define START_SEC_VAR_CLEARED_BOOLEAN_10
#endif
#ifdef DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
# undef DMA_STOP_SEC_VAR_CLEARED_BOOLEAN
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FrTp START 
 *********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/

#ifdef FRTP_START_SEC_CODE
# undef FRTP_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef FRTP_STOP_SEC_CODE
# undef FRTP_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef FRTP_START_CONFIG_DATA_UNSPECIFIED
# undef FRTP_START_CONFIG_DATA_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRTP_STOP_CONFIG_DATA_UNSPECIFIED
# undef FRTP_STOP_CONFIG_DATA_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef FRTP_START_SEC_CONST_UNSPECIFIED
# undef FRTP_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRTP_STOP_SEC_CONST_UNSPECIFIED
# undef FRTP_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef FRTP_START_SEC_VAR_8BIT
# undef FRTP_START_SEC_VAR_8BIT
# define START_SEC_VAR_NOINIT_8_9
#endif
#ifdef FRTP_STOP_SEC_VAR_8BIT
# undef FRTP_STOP_SEC_VAR_8BIT
# define STOP_SEC_VAR
#endif

#ifdef FRTP_START_SEC_VAR_UNSPECIFIED
# undef FRTP_START_SEC_VAR_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED_9
#endif
#ifdef FRTP_STOP_SEC_VAR_UNSPECIFIED
# undef FRTP_STOP_SEC_VAR_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FrTp END
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  TMS START UP 
*********************************************************************************************************************/

#ifdef STARTUP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STARTUP_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED_10
#endif
#ifdef STARTUP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef STARTUP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

#ifdef STARTUP_START_SEC_VAR_NOINIT_32
    #undef STARTUP_START_SEC_VAR_NOINIT_32
    #define START_SEC_VAR_NOINIT_32_10
#endif
#ifdef STARTUP_STOP_SEC_VAR_NOINIT_32
    #undef STARTUP_STOP_SEC_VAR_NOINIT_32
    #define STOP_SEC_VAR
#endif
	

/* Package Merger: Stop Section MemMapModuleList */ 

/*------------------------------GLOBAL-SECTIONS-----------------------------*/
/* Check code sections */
#if ( (defined CODE_SEC_OPEN)                            && \
     ((defined START_SEC_CODE                          ) || \
      (defined START_SEC_CODE_FAST                     ) || \
      (defined START_SEC_CODE_ISR                      )    \
      ))
    #error "MemMap.h: Close the former code segment before opening a new one."
#endif

/* Check const sections */
#if ( (defined CONST_SEC_OPEN)                           && \
     ((defined START_SEC_CONST_8BIT                    ) || \
      (defined START_SEC_CONST_16BIT                   ) || \
      (defined START_SEC_CONST_32BIT                   ) || \
      (defined START_SEC_CONST_UNSPECIFIED             ) || \
      (defined START_SEC_CONST_FAST_8BIT               ) || \
      (defined START_SEC_CONST_FAST_16BIT              ) || \
      (defined START_SEC_CONST_FAST_32BIT              ) || \
      (defined START_SEC_CONST_FAST_UNSPECIFIED        ) || \
      (defined START_SEC_CONST_PBCFG                   )    \
      ))
    #error "MemMap.h: Close the former const segment before opening a new one."
#endif

/* Check data sections */
#if ( (defined VAR_SEC_OPEN)                             && \
     ((defined START_SEC_VAR_INIT_8_9                 ) || \
      (defined START_SEC_VAR_INIT_16_9                ) || \
      (defined START_SEC_VAR_INIT_32_9                ) || \
      (defined START_SEC_VAR_INIT_UNSPECIFIED_9       ) || \
      (defined START_SEC_VAR_INIT_BOOLEAN_9			  )	|| \
      (defined START_SEC_VAR_NOINIT_8_9               ) || \
      (defined START_SEC_VAR_NOINIT_16_9              ) || \
      (defined START_SEC_VAR_NOINIT_32_9              ) || \
      (defined START_SEC_VAR_NOINIT_UNSPECIFIED_9     ) || \
      (defined START_SEC_VAR_CLEARED_8_9              ) || \
      (defined START_SEC_VAR_CLEARED_16_9             ) || \
      (defined START_SEC_VAR_CLEARED_32_9             ) || \
      (defined START_SEC_VAR_CLEARED_UNSPECIFIED_9     ) || \
      (defined START_SEC_VAR_FAST_INIT_8BIT            ) || \
      (defined START_SEC_VAR_FAST_INIT_16BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_32BIT           ) || \
      (defined START_SEC_VAR_FAST_INIT_UNSPECIFIED     ) || \
      (defined START_SEC_VAR_FAST_NOINIT_8BIT          ) || \
      (defined START_SEC_VAR_FAST_NOINIT_16BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_32BIT         ) || \
      (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED   ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_8BIT       ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_16BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_32BIT      ) || \
      (defined START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)    \
      ))
    #error "MemMap.h: Close the former variable segment before opening a new one."
#endif



/*------------------------------GLOBAL-START-SECTIONS------------------------------*/

/* Code section */
#ifdef START_SEC_CODE                          
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE                          
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_FAST                     
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_FAST                     
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CODE_ISR                      
    #define CODE_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CODE_ISR                      
    #undef MEMMAP_ERROR
#endif




/* Const section */
#ifdef START_SEC_CONST_8BIT                    
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_8BIT                    
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_16BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_16BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_32BIT                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_32BIT                   
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_UNSPECIFIED             
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_UNSPECIFIED             
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_8BIT               
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_8BIT               
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_16BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_16BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_32BIT              
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_32BIT              
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_FAST_UNSPECIFIED        
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_FAST_UNSPECIFIED        
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_CONST_PBCFG                   
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
/*    #pragma */
    #undef START_SEC_CONST_PBCFG                   
    #undef MEMMAP_ERROR
#endif




/* Var section */
#ifdef START_SEC_VAR_FAST_INIT_8BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_INIT_8BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_16BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_INIT_16BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_32BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_INIT_32BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_8BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_FAST_NOINIT_8BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_16BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_FAST_NOINIT_16BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_32BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_FAST_NOINIT_32BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_16BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_ZERO_INIT_16BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_32BIT
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_ZERO_INIT_32BIT
    #undef MEMMAP_ERROR
#endif


#ifdef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif

/************************************** Global Shared Variable Sections (AUTOSAR 4.0) *******************************/

#ifdef START_SEC_VAR_INIT_8_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_8_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_16_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_32_GLOBALSHARED        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_8_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_16_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_32_GLOBALSHARED        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_8_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_8_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_16_GLOBALSHARED      
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_GLOBALSHARED        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_32_GLOBALSHARED        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_32_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossGlobalShared")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_GLOBALSHARED
    #undef MEMMAP_ERROR
#endif


/************************************** Application #4 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:init")

    #undef START_SEC_VAR_INIT_8_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:init")

    #undef START_SEC_VAR_INIT_16_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:init")

    #undef START_SEC_VAR_INIT_32_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_4
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_CLEARED_8_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_CLEARED_16_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_CLEARED_32_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_NOINIT_8_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_NOINIT_16_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_NOINIT_32_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_4
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_4
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_4:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_4
    #undef MEMMAP_ERROR
#endif

/************************************** Application #7 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_7
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:init")

    #undef START_SEC_VAR_INIT_8_7
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_7
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:init")

    #undef START_SEC_VAR_INIT_16_7
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_7
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:init")

    #undef START_SEC_VAR_INIT_32_7
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_7
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_7
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_7
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_7
    #undef MEMMAP_ERROR
#endif

/* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_CLEARED_8_7       
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_CLEARED_16_7        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_CLEARED_32_7        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_7        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_7        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_NOINIT_8_7       
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_NOINIT_16_7        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_NOINIT_32_7        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_7        
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_7        
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_7:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_7        
    #undef MEMMAP_ERROR
#endif
/************************************** Application #8 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_8_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_16_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_32_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_8
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_8
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_8:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_8
    #undef MEMMAP_ERROR
#endif
/************************************** Application #9 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_8_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_16_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_32_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_9
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_9
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_9:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_9
    #undef MEMMAP_ERROR
#endif

/************************************** Application #10 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
#ifdef START_SEC_VAR_POWER_ON_CLEARED_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".noclear")

    #undef START_SEC_VAR_POWER_ON_CLEARED_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_10
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_10:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

/************************************** Application #10 Constant Sections ***************************************/
/* Const section */
#ifdef START_SEC_CONST_8_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_8_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_16_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_16_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_32_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_32_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_UNSPECIFIED_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_FAST_UNSPECIFIED_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_FAST_UNSPECIFIED_10
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_CONST_PBCFG_10
    #define CONST_SEC_OPEN
/* Enter here a #pragma command for opening the specified section, otherwise default allocation is used */
    #undef START_SEC_CONST_PBCFG_10
    #undef MEMMAP_ERROR
#endif

/************************************** Application #11 Variable Sections ***************************************/
 /* Initialized Memory */
#ifdef START_SEC_VAR_INIT_8_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:init")

    #undef START_SEC_VAR_INIT_8_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_16_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:init")

    #undef START_SEC_VAR_INIT_16_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_32_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:init")

    #undef START_SEC_VAR_INIT_32_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_BOOLEAN_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:init")

    #undef START_SEC_VAR_INIT_BOOLEAN_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_INIT_UNSPECIFIED_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:init")

    #undef START_SEC_VAR_INIT_UNSPECIFIED_11
    #undef MEMMAP_ERROR
#endif

 /* Uninitialized Memory */
 #ifdef START_SEC_VAR_CLEARED_8_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_CLEARED_8_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_16_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_CLEARED_16_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_32_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_CLEARED_32_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_BOOLEAN_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_CLEARED_BOOLEAN_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_CLEARED_UNSPECIFIED_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_CLEARED_UNSPECIFIED_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_8_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_NOINIT_8_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_16_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_NOINIT_16_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_32_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_NOINIT_32_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_BOOLEAN_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_NOINIT_BOOLEAN_11
    #undef MEMMAP_ERROR
#endif

#ifdef START_SEC_VAR_NOINIT_UNSPECIFIED_11
    #define VAR_SEC_OPEN
/* Enter here a #pragma command for opening the specified section */
#pragma SET_DATA_SECTION(".ossDataAp_11:noinit")

    #undef START_SEC_VAR_NOINIT_UNSPECIFIED_11
    #undef MEMMAP_ERROR
#endif


/*------------------------------GENERAL-STOP-SECTIONS-------------------------------*/

/*default segment for Code*/
#ifdef STOP_SEC_CODE
    #undef CODE_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
#pragma SET_CODE_SECTION()

    #undef STOP_SEC_CODE
    #undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST_UNSPECIFIED
    #undef CONST_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
#pragma SET_DATA_SECTION()
    #undef STOP_SEC_CONST_UNSPECIFIED
    #undef MEMMAP_ERROR
#endif

/*default segment for Constants*/
#ifdef STOP_SEC_CONST
    #undef CONST_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
#pragma SET_DATA_SECTION()

    #undef STOP_SEC_CONST
    #undef MEMMAP_ERROR
#endif

/*default segment for Datas*/
#ifdef STOP_SEC_VAR
    #undef VAR_SEC_OPEN
/* Enter here a #pragma command for closing the specified section */
/* This should switch back to the default section */
#pragma SET_DATA_SECTION()

    #undef STOP_SEC_VAR
    #undef MEMMAP_ERROR
#endif


#ifdef MEMMAP_ERROR
    #error "MemMap.h, wrong pragma command"
#endif

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


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
