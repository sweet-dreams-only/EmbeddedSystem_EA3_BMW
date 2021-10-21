/******   STARTSINGLE_OF_MULTIPLE_COMMENT    ******/


/*****************************************************************************/
/**
 * \file  SIP_VERS.C
 * \brief Vector SIP (Software Integration Package) version check
 *
 *  \pre 
 *  The purpose of this file is to:
 *  1) Check that all currently compiled files in the system have the correct 
 *     versions according to the delivered software integration package (SIP).
 *  2) Provide the SIP version as ROM constants for e.g. diagnostic purposes.
 *
 *-----------------------------------------------------------------------------
 *
 *  Usage hints: What to do when a compiler error occurs within this file?
 *               If a compiler error occurs within this file, a wrong version
 *               for the notified module has been detected. 
 *               Please check, if
 *               a) The module is part of your project and the include path is 
 *                  set correct (if not, the compiler may assume 0 for the 
 *                  version number comparison)
 *               b) The used module may have an incorrect version for this
 *                  project. Proof carefully, if a newer (or older) version
 *                  of the notified component is already available on your site
 *                  and an erroneous version mixup had occurred. See the required
 *                  module's main and bugfix version above of the error message.
 *               c) This may be the wrong SIP version check file for the project.
 *                  Proof carefully, if the file has been exchanged together with
 *                  the latest change of a component (e.g. an bugfix delivery), 
 *                  too.
 *               In case none of the above mention points is true, please contact 
 *               your Vector's contact person for further help.
 *
 *****************************************************************************
 *
 *  Background information: Each Vector software component checks its own header
 *               and code files for version consistency. With this, a version  
 *               mixup within each component could be detected during compilation.
 *               To detect the mixup of different components in a project, too,
 *               this version check file has been introduced.
 *                                
 *****************************************************************************
 *               C O P Y R I G H T
 *****************************************************************************
 * Copyright (c) 2011 by Vctr Informatik GmbH.           All rights reserved.
 *
 *                    Alle Rechte an der Software verbleiben bei der
 *                    Vctr Informatik GmbH.
 *                    Vctr Informatik GmbH räumt dem Lizenznehmer das unwider-
 *                    rufliche, geographisch und zeitlich nicht beschränkte,
 *                    jedoch nicht ausschließliche Nutzungsrecht innerhalb des
 *                    Lizenznehmers ein. Die Weitergabe des Nutzungsrechts
 *                    durch den Lizenznehmers ist auf dessen Zulieferer
 *                    beschränkt. Die Zulieferer sind zu verpflichten, die
 *                    Software nur im Rahmen von Projekten für den Lizenznehmer
 *                    zu verwenden; weitere Rechte der Zulieferer sind
 *                    auszuschließen.
 *
 *     Use of this source code is subject to the License Agreement "license.txt"
 *     distributed with this file. You may not use this source code unless you
 *     agree to the terms of the License Agreement.
 *
 *     REMOVAL OF THESE COMMENTS IS A VIOLATION OF THE LICENSE AGREEMENT.
 *
 *****************************************************************************
 *               A U T H O R   I D E N T I T Y
 *****************************************************************************
 * Initials     Name                      Company
 * ********     *********************     ************************************
 * Ra           Andreas Raisch            Vctr Informatik GmbH
 * Hgo          Hua Guo                   Vctr Informatik GmbH
 * Abc/visabc   Alexander Becker          Vctr Informatik GmbH
 * Bwr          Bernhard Wissinger        Vctr Informatik GmbH
 * Fr           Markus Feninger           Vctr Informatik GmbH
 * visdbr       Daniela Brenner           Vctr Informatik GmbH
 * visagh       Alexander Gronbach        Vctr Informatik GmbH
 * Stu          Bernd Stumpf              Vctr Informatik GmbH
 * Ntr          Nam Trinh                 Vctr Informatik GmbH
 * visget       Matthias Gette            Vctr Informatik GmbH
 * visbwa       Benjamin Walter           Vctr Informatik GmbH
 * viskrt       Kerstin Thim              Vctr Informatik GmbH
 * visoh        Oliver Hornung            Vctr Informatik GmbH
 * visjy        Junwei Ye                 Vctr Informatik GmbH
 * vishkh       Hagen Keinath             Vctr Informatik GmbH
 * visbch       Christoph Breuer          Vctr Informatik GmbH
 *****************************************************************************
 *               R E V I S I O N   H I S T O R Y
 *****************************************************************************
 * Date         Version Author  Description
 * ********     ************** ***********************************************
 * 02-11-14     1.00.00 Ra      First template version, based on proposal by Hp
 * 07-11-07     2.00.00 Hgo     use v_ver.h to automatically check SIP Version
 * 07-11-16     2.01.00 Abc     sip_vers OEM independent
 * 07-11-19     2.01.01 Abc     different bugfixes
 * 08-01-31     2.01.02 Bwr     adaption for TMS470HeccScc
 * 08-03-10     2.01.03 Hgo     correct diag
 * 08-03-12     2.01.04 Hgo     correct Tp_ISO_SCS bugfix version check
 * 08-03-12     2.01.05 Fr      SipVersion declaration included
 * 08-03-13     2.01.06 Hgo     COMMENT rule for GW_AS_DC added
 * 08-03-13     2.01.07 Et      GenTool (release => bugfix version) + DIAG modifications
 *                              _GENTOOL_CANGEN_VERSION / _GENTOOL_CANGEN_RELEASE_VERSION
 * 08-03-14     2.01.08 Hgo     DBKomGEN version check added
 *                              both release and bugfix version names supported
 * 08-03-17     2.01.09 Et      corrected GenTool CANgen/DBKOMgen version support
 * 08-04-04     2.01.10 Hgo     ESCAN00025852
 *                              added the check for some components, if it is used
 * 08-04-17     2.01.11 Dbr     adaption for TMS470HeccScc ARM
 * 08-04-23     2.01.12 visagh  added Mpc55xx_Flexcan2 with GHS and corrected VWTP20
 *                              COMMENT rule for GENy, CANgen and DBKOMgen added
 * 08-04-28     2.01.13 Hgo     added H8S RCAN and HCAN1 support
 * 08-04-28     2.01.14 visbwr  fixed GMLAN and FJ16FX support
 * 08-05-07     2.01.15 visbwr  added TP_MCAN support
 * 08-05-07     2.01.16 Dbr     added LIN for MPC55XX GHS Flexcan2
 * 08-05-08     2.01.17 Dbr     added CanDrv R32C/Renesas
 * 08-05-08     2.01.18 Hgo     added gw_sig, gw_msg
 * 08-05_13     2.01.19 Stu     added CanDrv Stm8a/Cosmic
 * 08-05-19     3.00.00 Hgo     added Asr Componente
 *                              added Lib check
 *                              added Version Check for not-Vector Component
 *                              supported version check for mpc55xx from version 2.09.xx
 * 08-05-29     3.00.01 Hgo     filted the lib check for canbedded delivery
 * 08-05-29     3.00.02 Hgo     changed for _COMMON Key
 *                              added Issm and Vmm
 * 08-05-30     3.00.03 Hgo     canceled the version check of Comstacktypes and stdtypes
 * 08-05-30     3.00.04 Hgo     canceled the version check of CommonAsr
 * 08-05-30     3.00.05 Hgo     corrected the header relation
 * 08-06-02     3.00.06 visagh  changed include of NmDirOsek
 * 08-06-03     3.00.07 visagh  corrected include of NmDirOsek
 * 08-06-20     3.00.08 viset   support "old" and "new" NmDirOsek versions
 * 08-06-26     3.00.09 abc     added VGEN_ENABLE_DIAG_ASR_DCM for DCM v1.x.x
 * 08-06-27     3.00.10 visagh  support Ccl_Vector for non Vector OEMs
 * 08-06-30     3.00.11 abc     support for automatic scan of Ccl_CclCom version
 * 08-07-02     3.00.12 visagh  fixed XC2000 and BF5XX support
 *                              different bugfixes related to formatting
 * 08-07-29     3.00.13 Ntr     added Mpc55xx_Flexcan2 with Diabdata
 * 08-07-29     3.00.14 Rna     added DSPIC33FECANHLL added
 * 08-08-04     3.00.15 Tri     AUTOSAR naming convention applied
 * 08-08-06     3.00.16 visagh  corrected support of VWTP20
 * 08-08-08     3.00.17 visbwr  added support of C_COMP_QCC_TMS320ARM
 * 08-08-14     3.00.18 visget  corrected VStdLib lib check (SH2)
 * 08-08-22     3.00.19 viset   avoid compiler warnings for M16C with Mitsubishi
 * 08-08-25     3.00.20 Hgo     corrected include for the dependence of NmDirOsek
 * 08-08-26     3.00.21 viset   corrected V3.00.19 modification (M16C instead of  M32C)
 * 08-08-26     3.00.22 viset   corrected V3.00.19 modification (main/sub version name)
 * 08-08-28     3.00.23 Ntr     corrected DrvCAN check (C_COMP_IAR_78K0)
 * 08-08-29     3.00.24 Rna     LIN Drv TMS470 added
 * 08-09-04     3.00.25 Hgo     corrected the include filter for NM_DIROSEKEXT_DC
 * 08-09-11     3.00.26 Abc     CAN Drv TMS470DCAN added
 * 08-09-18     3.00.27 Rna     Version defines for V850 changed
 * 08-10-08     3.00.28 Abc     Added CANbedded support for C_COMP_MICROSOFT_TMS320ARM
 * 08-10-27     3.00.29 Abc     Version check for V850 corrected:
 *                              C_PROCESSOR_AVALON / DRVCAN_V85XDCANIDX added
 * 08-11-11     3.00.30 viset   avoid compiler warnings for M32R with Mitsubishi
 * 08-11-19     3.00.31 visagh  corrected check of TMS320ARM
 * 08-11-24     3.00.32 visagh  added include of Frfm header file
 * 08-12-18     3.00.33 viset   Nm_DirOsekUserdata_Dc supported by GenTool_Geny only
 * 08-12-22     3.00.34 vishgo  Cancelled the check, if all deliveried modules in one project are used.
 * 08-12-22     3.00.35 vishgo  extended version check from VolvoAb to all postbuild delivery
 *                              added the check, if all deliveried modules in a postbuild project are used.
 * 09-01-02     3.00.36 viset   added missing #endif for VGEN_ENABLE_IF_ASRIFMEM filter rule (postbuild)
 * 09-01-08             visfmi  changed library version check switch to SIPVERSIONCHECK_CHECKLIBVERSION
 * 09-01-14             visdbr  changed defines for FJ16FX, VGEN_ENABLE_DRVCANTRANS_TJA1041ASR, VGEN_ENABLE_CCL_ASRCOMM and VGEN_ENABLE_CCL_ASRSMCAN
 * 09-01-21     3.00.37 viset   support CANdrv SH2 HCAN2 (RI 1.5)
 * 09-01-27     3.01.00 vishgo  added Asr makefile
 * 09-01-28     3.01.01 vislo   Add VGEN_ENABLE for all MCAL components
 * 09-01-29     3.01.02 vislo   Adapt version in header
 * 09-02-18     3.01.03 visagh  added support of C_COMP_MTRWRKS_MPC5X00_MSCAN
 * 09-02-18     3.01.04 visagh  Version defines for MPC5X00 VStdLib changed
 * 09-03-13     3.01.05 vismfi  Remove DIAG_ASRDEM__CORE_LIB_SYMBOL, the dependence of the Dem to the Lib is obsolete
 * 09-03-18             visagh  Restructured CanDrv's and Nm's with different version defines to fix compiler warnings and wrong errors
 * 09-03-31     3.01.06 visagh  added support of C_COMP_RENESAS_M16C_RCAN2
 * 09-04-07     3.01.07 viset   support C_COMP_MATSUSHITA_MN101E_CCAN
 * 09-04-29     3.01.08 visagh  support C_COMP_ARM_TCC800X_CCAN
 * 09-05-06     3.01.09 visagh  support C_COMP_IAR_M16C_RCAN2
 * 09-05-13     3.01.10 vishgo  fixed AsrFrTp version check
 *                              checked the version between generated and static files
 * 09-05-14     3.01.11 visbwa  fixed SysService_AsrCrc version check (removed 'V_')
 * 09-05-29     3.01.12 vishgo  deleted the error for Lib, if the module in the license but not used by customer.
 * 09-06-02     3.01.13 viset   support C_COMP_GAIO_SH2_RCAN
 * 09-06-19     3.01.14 vihkh   changed include sequence of gdda.h and desc.h
 * 09-06-30     3.01.15 vishgo  changed DEM Name for Daimler from DC to DAIMLER
 * 09-07-23     3.01.16 visabc  added _CCL_DPM_DC_VERSION / _RELEASE_VERSION
 * 09-08-25     3.01.17 visagh  only check version of NmHighWrapper if NmHigh is enabled
 * 09-08-25     3.01.18 viskrt  Added VGEN_ENABLE switches
 * 09-08-26     3.01.19 viset   COMMON_SIPVERSIONCHECK_RELEASE_VERSION correction
 * 09-08-28     3.01.20 viskrt  Changed name of J1939 include files
 *                      visbwr  Added QCC_MPC5X00, QNX components
 * 09-09-07     3.01.21 visard  Fix Tmsx70 DCAN / HECCSCC defines
 * 09-09-18     3.01.22 visagh  Fixed an error
 * 09-09-30     3.01.23 visabc  Added support of C_COMP_IAR_AVR32_CANIF
 *                              added support of Il_Vector_Gm
 * 09-10-06     3.01.24 visagh  added C_COMP_RENESAS_SH4_RCAN and C_COMP_GHS_SH4_RCAN2
 * 09-10-13     3.01.25 visdbr  adapted SYSSERVICE_ISSM to SYSSERVICE_ISSM_VOLVO_AB
 * 09-10-14     3.01.26 visoh   Added XcpOnCan
 * 09-10-14     3.01.27 visntr  support C_COMP_GAIO_SH2_RCAN for Hll CAN-Driver
 * 09-10-30     3.01.28 visjy   support C_COMP_ARM_STM32_BXCAN for Hll CAN-Driver
 * 09-11-13     3.01.29 vishkh  support for C_COMP_GNU_TX49 CAN-Driver
 * 09-11-24     3.01.30 visjy   Add vstdlib check for STM32
 * 09-12-03     3.01.31 visagh  Add new V85X VStdLib version defines
 *                              removed LIB check HW dependency (VStdLib, Can, Lin)
 * 09-12-11     3.01.32 visbwr  Add C_COMP_GNU_IMX_FLEXCAN2
 * 09-12-14     3.01.33 vishkh  Add C_COMP_METROWERKS_MPC55XX_FLEXCAN2
 * 09-12-21     3.01.34 visjy   Add C_COMP_GHS_V85X_FCN
 * 10-01-11     3.01.35 visagh  corrected DRVCAN_BF5XXXHLL_VERSION
 * 10-01-25     3.01.36 visagh  avoid compiler warnings for DPM
 * 10-01-27     3.01.37 visjy   Add C_COMP_GHS_KEIL_SJA2020
 * 10-01-27     3.01.38 visjy   Add DRVLIN_MPC56xx for lin driver
 * 10-04-23     3.01.39 visntr  corrected DRVLIN_MPC5500SCICTRLASR_VERSION
 * 10-05-04     3.01.40 visdbr  CORRECTED DRVLIN_MPC5500SCICTRLASR_VERSION for DIAB
 * 10-05-26     3.01.41 visjy   support C_COMP_QCC_MB86R0X_CCAN
 * 10-06-07     3.01.42 vishgo  ESCAN00043187
 * 10-06-07     3.01.43 vishgo  deleted VGEN_ENABLE_VDEF macro for VDEF
 * 10-06-08     3.01.44 vishgo  fixed VGEN_ENABLE_IF_ASRIFFEE for Fee version check
 * 10-06-08     3.01.45 vishgo  added SchM_Cfg.h include
 * 10-06-09     3.01.46 vishgo  added C_COMP_IAR_SH2_RCAN
 * 10-06-09     3.01.47 vishkh  added C_COMP_GNU_MPC55XX
 * 10-06-14     3.01.48 visabc  added C_COMP_QCC_SH4_RCAN
 * 10-07-21     3.01.49 visabc  added C_COMP_IAR_78K0R
 * 10-07-26     3.01.50 visbch  corrected Lib-check for Gw PduR
 * 10-07-30     3.01.51 vishkh  added C_COMP_GNU_IMX_FLEXCAN2
 * 10-10-11     3.01.52 visagh  added C_COMP_RENESAS_V85X_FCN
 * 10-10-28     3.01.53 visstu  added C_COMP_KEIL_XC800
 * 10-12-16     3.01.54 visaar  added C_COMP_RENESAS_78K0R
 * 11-02-24     3.01.55 visagh  removed PAG specific Tp_Iso15765 errors
 * 11-03-28     3.01.56 vishgo  added AsrFrIf version check
 * 11-04-05     3.01.57 vishgo  ESCAN00049838 
 * 11-04-07     3.01.58 vadhda  added C_COMP_GNU_ST30_CCAN
 * 11-04-12     3.01.59 visagh  added C_COMP_RENESAS_V85X_AFCAN
 * 11-04-19     3.01.60 vidbr   support  ASR4 components
 * 11-04-21     3.01.61 vidbr   DCM not filtered correctly
 * 11-04-21     3.01.62 vidbr   NmDirOsek not filtered correctly
 * 11-04-26     3.01.63 viset   modified CCL filter rule to support AR4 components
 * 11-05-02     3.01.64 visabc  added C_COMP_ARM_TX03_TXCAN
 * 11-05-04     3.01.65 visstu  added C_COMP_IAR_V85X_FCN
 * 11-05-04     3.01.65 visjy   added C_COMP_GAIO_MPC55XX_FLEXCAN2 for Drv can HLL
 *****************************************************************************/


#include "v_cfg.h"
#include "v_ver.h"
#include "v_def.h"
#include "Std_Types.h"
#if defined( VGEN_GENY )
 #include "v_inc.h"
#endif
  #include "SchM_Cfg.h"

/* ---------------------------------------------------------------------------
 * Asr ComM
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_CCL_ASRCOMM )
  #include "ComM.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr FrSm
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_CCL_ASRSMFR )
  #include "FrSM.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr Gw PduR
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_GW_ASRPDUR )
  #include "PduR.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr Il Com
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_IL_ASRCOM )
  #include "Com.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr MenIf
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_IF_ASRIFMEM )
#include "MemIf.h"
#endif



/* ---------------------------------------------------------------------------
 * Asr Nvm
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_MEMSERVICE_ASRNVM )
#include "NvM.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr Sysserver EcuM
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_SYSSERVICE_ASRECUM )
  #include "EcuM.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr SysService_Crc
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_SYSSERVICE_ASRCRC )
#include "Crc.h"
#endif

/* ---------------------------------------------------------------------------
 * Description: VSTDLIB.H includes the Vector Standard Library header.
 *--------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_VSTDLIB )
  #include "vstdlib.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr WdgIf
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_IF_ASRIFWD )
#include "WdgIf.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr WdgM
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_SYSSERVICE_ASRWDM )
#include "WdgM.h"
#endif

/* ---------------------------------------------------------------------------
 * Station management header
 * --------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  Nicht-Vector-Komponenten
  ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------
 * Asr DRV ADC
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_ADC_DRV )
#include "Adc.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV DIO
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_DIO_DRV )
#include "Dio.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Gpt
 * --------------------------------------------------------------------------*/
#if defined (VGEN_ENABLE_GPT_DRV )
#include "Gpt.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV ICU
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_ICU_DRV )
#include "Icu.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV MCU
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_MCU_DRV )
#include "Mcu.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Port
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_PORT_DRV )
#include "Port.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Pwm
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_PWM_DRV )
#include "Pwm.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Spi
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_SPI_DRV )
#include "Spi.h"
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Wdg
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_WDG_DRV )
#include "Wdg.h"
#endif

#include "sip_vers.h"



/******************************************************************************
| version check
|*****************************************************************************/
/* Used to check source against header. This is NOT the SIP version! */
#if ( SIP_VERS_VERSION != _COMMON_SIPVERSIONCHECK_VERSION )
  #error "SipCheck: Different main/sub version in header and source!"
#endif
#if ( SIP_VERS_RELEASE_VERSION != _COMMON_SIPVERSIONCHECK_RELEASE_VERSION )
  #error "SipCheck: Different release versions header and source!"
#endif


/******************************************************************************
| check components (presence, versions, functionalities)
|*****************************************************************************/

/* ---------------------------------------------------------------------------
 * Asr ComM
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_CCL_ASRCOMM )
  #if ( CCL_ASRCOMM_VERSION         != _CCL_ASRCOMM_VERSION )
    #error "AsrComM: Wrong version detected for this SIP delivery!"
  #endif
  #if ( CCL_ASRCOMM_RELEASE_VERSION != _CCL_ASRCOMM_RELEASE_VERSION   )
    #error "AsrComM: Wrong release version detected for this SIP delivery!"
  #endif
#endif

/* ---------------------------------------------------------------------------
 * Asr FrSm
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_CCL_ASRSMFR )
  #if ( CCL_ASRSMFR_VERSION         != _CCL_ASRSMFR_VERSION )
    #error "AsrFrSm: Wrong version detected for this SIP delivery!"
  #endif
  #if ( CCL_ASRSMFR_RELEASE_VERSION != _CCL_ASRSMFR_RELEASE_VERSION   )
    #error "AsrFrSm: Wrong release version detected for this SIP delivery!"
  #endif
#endif


/* ---------------------------------------------------------------------------
 * Asr Gw PduR
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_GW_ASRPDUR )
  #if ( GW_ASRPDUR_VERSION         != _GW_ASRPDUR_VERSION )
    #error "AsrPduR: Wrong version detected for this SIP delivery!"
  #endif
  #if ( GW_ASRPDUR_RELEASE_VERSION != _GW_ASRPDUR_RELEASE_VERSION   )
    #error "AsrPduR: Wrong release version detected for this SIP delivery!"
  #endif
#endif

/* ---------------------------------------------------------------------------
 * Asr Il Com
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_IL_ASRCOM )
  #if ( IL_ASRCOM_VERSION         != _IL_ASRCOM_VERSION )
    #error "AsrCom: Wrong version detected for this SIP delivery!"
  #endif
  #if ( IL_ASRCOM_RELEASE_VERSION != _IL_ASRCOM_RELEASE_VERSION   )
    #error "AsrCom: Wrong release version detected for this SIP delivery!"
  #endif
#endif

/* ---------------------------------------------------------------------------
 * IL_ASRCOM
 * --------------------------------------------------------------------------*/
#ifdef VGEN_ENABLE_IL_ASRCOM
 #if ( IL_ASRCOM_VERSION != _IL_ASRCOM_VERSION )
  #error "IL_ASRCOM: Wrong version detected for this SIP delivery!"
 #endif
 #if ( IL_ASRCOM_RELEASE_VERSION != _IL_ASRCOM_RELEASE_VERSION   )
  #error "IL_ASRCOM: Wrong version detected for this SIP delivery!"
 #endif
#endif

/* ---------------------------------------------------------------------------
 * Asr MenIf
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_IF_ASRIFMEM )
#if ( IF_ASRIFMEM_VERSION         != _IF_ASRIFMEM_VERSION )
  #error "AsrMemIf: Wrong version detected for this SIP delivery!"
#endif
#if ( IF_ASRIFMEM_RELEASE_VERSION != _IF_ASRIFMEM_RELEASE_VERSION   )
  #error "AsrMemIf: Wrong release version detected for this SIP delivery!"
#endif
#endif




/* ---------------------------------------------------------------------------
 * Asr Nvm
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_MEMSERVICE_ASRNVM )
#if ( MEMSERVICE_ASRNVM_VERSION         != _MEMSERVICE_ASRNVM_VERSION )
  #error "AsrNvm: Wrong version detected for this SIP delivery!"
#endif
#if ( MEMSERVICE_ASRNVM_RELEASE_VERSION != _MEMSERVICE_ASRNVM_RELEASE_VERSION   )
  #error "AsrNvm: Wrong release version detected for this SIP delivery!"
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr SysService_Crc
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_SYSSERVICE_ASRCRC )
#if ( SYSSERVICE_ASRCRC_VERSION         != _SYSSERVICE_ASRCRC_VERSION )
  #error "AsrCrc: Wrong version detected for this SIP delivery!"
#endif
#if ( SYSSERVICE_ASRCRC_RELEASE_VERSION != _SYSSERVICE_ASRCRC_RELEASE_VERSION   )
  #error "AsrCrc: Wrong release version detected for this SIP delivery!"
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr Sysservice EcuM
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_SYSSERVICE_ASRECUM )
  #if ( SYSSERVICE_ASRECUM_VERSION         != _SYSSERVICE_ASRECUM_VERSION )
    #error "AsrEcuM: Wrong version detected for this SIP delivery!"
  #endif
  #if ( SYSSERVICE_ASRECUM_RELEASE_VERSION != _SYSSERVICE_ASRECUM_RELEASE_VERSION   )
    #error "AsrEcuM: Wrong release version detected for this SIP delivery!"
  #endif
#endif

/*----------------------------------------------------------------------------
  Common_VStdLib
  ---------------------------------------------------------------------------*/
#if defined( VGEN_ENABLE_VSTDLIB )
#if defined ( C_COMP_TI_TMS470_DCAN )
 #if( VSTDLIB_ARM7_VERSION != _VSTDLIB_HW_VERSION )
  #error "VStdLib: Wrong main/sub version detected for this SIP delivery!"
 #endif
 #if( VSTDLIB_ARM7_RELEASE_VERSION != _VSTDLIB_HW_RELEASE_VERSION )
  #error "VStdLib: Wrong release version detected for this SIP delivery!"
 #endif
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr WdgIf
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_IF_ASRIFWD )
#if ( IF_ASRIFWD_VERSION         != _IF_ASRIFWD_VERSION )
  #error "AsrWdgIf: Wrong version detected for this SIP delivery!"
#endif
#if ( IF_ASRIFWD_RELEASE_VERSION != _IF_ASRIFWD_RELEASE_VERSION   )
  #error "AsrWdgIf: Wrong release version detected for this SIP delivery!"
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr WdgM
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_SYSSERVICE_ASRWDM )
#if ( SYSSERVICE_ASRWDM_VERSION         != _SYSSERVICE_ASRWDM_VERSION )
  #error "AsrWdgM: Wrong version detected for this SIP delivery!"
#endif
#if ( SYSSERVICE_ASRWDM_RELEASE_VERSION != _SYSSERVICE_ASRWDM_RELEASE_VERSION   )
  #error "AsrWdgM: Wrong release version detected for this SIP delivery!"
#endif
#endif

/*----------------------------------------------------------------------------
  V_DEF
  ---------------------------------------------------------------------------*/
#if ( COMMON_VDEF_VERSION != _COMMON_VDEF_VERSION   )
  #error "V_Def: Wrong version detected for this SIP delivery!"
#endif
#if ( COMMON_VDEF_RELEASE_VERSION != _COMMON_VDEF_RELEASE_VERSION )
  #error "V_Def: Wrong version detected for this SIP delivery!"
#endif
/*----------------------------------------------------------------------------
  Nicht-Vector-Komponenten
  ---------------------------------------------------------------------------*/

/* ---------------------------------------------------------------------------
 * Asr DRV ADC
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_ADC_DRV )
#if ( ((ADC_SW_MAJOR_VERSION<<8) |(ADC_SW_MINOR_VERSION))  != _DRVADC_HW_VERSION )
  #error "Drv Adc: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( ADC_SW_PATCH_VERSION != _DRVADC_HW_RELEASE_VERSION )
  #error "Drv Adc: Wrong release version detected for this SIP delivery! "
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV DIO
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_DIO_DRV )
#if ( ((DIO_SW_MAJOR_VERSION<<8) |(DIO_SW_MINOR_VERSION))  != _DRVDIO_HW_VERSION )
  #error "Drv Dio: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( DIO_SW_PATCH_VERSION != _DRVDIO_HW_RELEASE_VERSION )
  #error "Drv Dio: Wrong release version detected for this SIP delivery! "
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Gpt
 * --------------------------------------------------------------------------*/
#if defined (VGEN_ENABLE_GPT_DRV )
#if ( ((GPT_SW_MAJOR_VERSION<<8) |(GPT_SW_MINOR_VERSION))  != _DRVGPT_HW_VERSION )
  #error "Drv GPT: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( GPT_SW_PATCH_VERSION != _DRVGPT_HW_RELEASE_VERSION )
  #error "Drv GPT: Wrong release version detected for this SIP delivery! "
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV ICU
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_ICU_DRV )
#if ( ((ICU_SW_MAJOR_VERSION<<8) |(ICU_SW_MINOR_VERSION))  != _DRVICU_HW_VERSION )
  #error "Drv ICU: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( ICU_SW_PATCH_VERSION != _DRVICU_HW_RELEASE_VERSION )
  #error "Drv ICU: Wrong release version detected for this SIP delivery! "
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV MCU
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_MCU_DRV )
#if ( ((MCU_SW_MAJOR_VERSION<<8) |(MCU_SW_MINOR_VERSION))  != _DRVMCU_HW_VERSION )
  #error "Drv MCU: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( MCU_SW_PATCH_VERSION != _DRVMCU_HW_RELEASE_VERSION )
  #error "Drv MCU: Wrong release version detected for this SIP delivery! "
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Port
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_PORT_DRV )
#if ( ((PORT_SW_MAJOR_VERSION<<8) |(PORT_SW_MINOR_VERSION))  != _DRVPORT_HW_VERSION )
  #error "Drv PORT: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( PORT_SW_PATCH_VERSION != _DRVPORT_HW_RELEASE_VERSION )
  #error "Drv PORT: Wrong release version detected for this SIP delivery! "
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Pwm
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_PWM_DRV )
#if ( ((PWM_SW_MAJOR_VERSION<<8) |(PWM_SW_MINOR_VERSION))  != _DRVPWM_HW_VERSION )
  #error "Drv PWM: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( PWM_SW_PATCH_VERSION != _DRVPWM_HW_RELEASE_VERSION )
  #error "Drv PWM: Wrong release version detected for this SIP delivery! "
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Spi
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_SPI_DRV )
#if ( ((SPI_SW_MAJOR_VERSION<<8) |(SPI_SW_MINOR_VERSION))  != _DRVSPI_HW_VERSION )
  #error "Drv SPI: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( SPI_SW_PATCH_VERSION != _DRVSPI_HW_RELEASE_VERSION )
  #error "Drv SPI: Wrong release version detected for this SIP delivery! "
#endif
#endif

/* ---------------------------------------------------------------------------
 * Asr DRV Wdg
 * --------------------------------------------------------------------------*/
#if defined ( VGEN_ENABLE_WDG_DRV )
#if ( ((WDG_SW_MAJOR_VERSION<<8) |(WDG_SW_MINOR_VERSION))  != _DRVWD_HW_VERSION )
  #error "Drv WDG: Wrong main/sub version detected for this SIP delivery! "
#endif
#if ( WDG_SW_PATCH_VERSION != _DRVWD_HW_RELEASE_VERSION )
  #error "Drv WDG: Wrong release version detected for this SIP delivery! "
#endif
#endif



/******************************************************************************
| check the version between generated and static files
|*****************************************************************************/
#if(VGEN_DELIVERY_VERSION_BYTE_0 != (_VECTOR_SIP_VERSION & 0xff00)>>8) 
 #error "Generated and static files are not from the same delivery SIP main version is different"
#endif
#if(VGEN_DELIVERY_VERSION_BYTE_1 != (_VECTOR_SIP_VERSION & 0x00ff)) 
 #error "Generated and static files are not from the same delivery SIP sub version is different"
#endif
#if(VGEN_DELIVERY_VERSION_BYTE_2 != _VECTOR_SIP_RELEASE_VERSION) 
 #error "Generated and static files are not from the same delivery SIP bug version is different"
#endif

/******************************************************************************
| Store additional SIP information in ROM constants
|*****************************************************************************/
/* ROM CATEGORY 4 START*/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipMainVersion   = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_0);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipSubVersion    = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_1);
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kSipBugFixVersion = (vuint8)(VGEN_DELIVERY_VERSION_BYTE_2);
/* ROM CATEGORY 4 END*/
