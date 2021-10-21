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
 *         File:  _Compiler_Cfg.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the Compiler_Cfg.h
 *                This file has to be extended with the memory and pointer classes for all BSW modules
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
 *  01.01.01  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.02  2009-04-27  Ht                    support OEM specific _compiler_cfg.inc file, improve list of components 
 *                                              (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm, If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.03  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.04  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-09-02  Lo                    add external Flash driver support
 *  01.02.02  2009-09-21  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
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
 *  01.03.02  2010-02-15  Ht                   support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
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
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat,
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXSubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *********************************************************************************************************************/
 /*************************************************************************************************************************
 * Version Control:
 * Date Created:      Wed Oct 19 12:16:01 2011
 * %version:          3 %
 * %derived_by:       wz7x3j %
 * %date_modified:    Thu Oct 20 10:20:06 2011 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        	   SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  	----------
 * 10/20/11   4        BDO        Add CRYPTO_HOTKEY definition - integrate BMW Crypto_Cfg_hotkey.h file
*************************************************************************************************************************/
 
 
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* Package Merger: Start Section CompilerCfgIncludes */
/*for vector*/ 
#include "v_cfg.h"
#include "v_def.h"
  

/* Package Merger: Stop Section CompilerCfgIncludes */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define BAC

#define AUTOSAR_COMSTACKDATA

#define MSR_REGSPACE


/* due to compatibility to ASR 2.1 */
#define _STATIC_   STATIC
#define _INLINE_   INLINE

/* Package Merger: Start Section CompilerCfgModuleList */

#define V_SUPPRESS_EXTENDED_VERSION_CHECK
#define V_USE_DUMMY_STATEMENT STD_OFF

#if !defined( ON )
# define ON                                     STD_ON
#endif
#if !defined( OFF )
# define OFF                                    STD_OFF
#endif
#define __ARCH_TMS470__ /* Define in v_cfg.h is different */
/* include Rte Compiler_Cfg because the Rte sections are configuration dependent*/
 #include "Rte_Compiler_Cfg.h" 

/* Define BMW platform macros */

/* Needs to be defined to STD_ON when more than 256 DEM events are configured */
#define DEM_LIDS                                STD_OFF
#define DEM_DEV_ERROR_DETECT                    STD_OFF
#define CANIF_SUPPRESS_DEM_VERSION_CHECK        STD_OFF

//#error "Please uncomment the required Macro below and delete this error directive"
 #define APPLICATION 
/* #define BOOTLOADER */
/* #define BOOTMANAGER */

//#error "Please configure SC_FEE_ENABLE, SC_HANDLE_ECC and SC_VERIFY_SWE_CRC_CHKSUM according to your needs"
#define SC_FEE_ENABLE                           STD_OFF
#define SC_HANDLE_ECC                           STD_OFF    /* Does the HW support ECC error handling (relevant for Bootloader)? */
#define SC_VERIFY_SWE_CRC_CHKSUM                STD_OFF    /* Shall SWEs be checked with a CRC (relevant for Bootloader)? */
#define SC_SWT_ENABLE                           STD_ON 	   //NXTR SWT    /* Is the SWT security mechanism relevant for this ECU? */
#define SC_CODING_ENABLE                        STD_ON 
#define SC_CSM_ENABLE                           STD_OFF
#define SC_PIA_ENABLE                           STD_OFF
#define DM_TEST                                 STD_ON

/* NXTR SWT *///NXTR SWT - added was not defined */
#define SWT_USE_ECU_SWTLIST 					SWT_CFG_ON


/* Do not change the three definitions below unless you are sure what you are doing... */
#define SC_LED_DEMO_ON                          STD_OFF
#define USE_ITEST_CODE                          STD_OFF
#define SC_APPL_CRYPTO_ENABLE                   STD_ON

#if defined( BOOTLOADER )
# define SC_NRV2B_ENABLE                        STD_ON
#else
# define SC_NRV2B_ENABLE                        STD_OFF
#endif

#define DATALOGISTIC_CODE
#define DIAG_PUBLIC_DCMCODE

#define CRYPTO_HOTKEY							1

/* include Bac_Compiler_Cfg for shared mem and ptr classes among application and bootloader */
#include "Bac_Compiler_Cfg.h"


/* include Rte Compiler_Cfg because the Rte sections are configuration dependent*/
#include "Rte_Compiler_Cfg.h"

#define COMMON_VAR

/**********************************************************************************************************************
 *  Nxtr EPS Components
 *********************************************************************************************************************/
#define FILTERS_CODE
 
 
/**********************************************************************************************************************
 *  COMM START 
 *********************************************************************************************************************/

#define COMM_CODE

#define COMM_CONST

#define COMM_VAR_INIT
#define COMM_VAR_NOINIT
#define COMM_VAR_NOINIT_8BIT
#define COMM_VAR_NOINIT_16BIT
#define COMM_VAR_NOINIT_UNSPECIFIED
#define COMM_VAR_ZERO_INIT

#define COMM_APPL_CODE
#define COMM_APPL_VAR
#define COMM_APPL_VAR_NVRAM


/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/









/**********************************************************************************************************************
 *  FrSM START 
 *********************************************************************************************************************/

#define FRSM_CODE

#define FRSM_CONST
#define FRSM_PBCFG

#define FRSM_VAR_NOINIT
#define FRSM_VAR_ZERO_INIT

#define FRSM_APPL_DATA
#define FRSM_APPL_VAR


/**********************************************************************************************************************
 *  FrSM END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  Vsm START 
 *********************************************************************************************************************/

#define VSM_CONST
#define VSM_PUBLIC_CODE
#define VSM_PRIVATE_CODE
#define VSM_VAR
#define NM_APPL_CONST

/**********************************************************************************************************************
 *  Vsm END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

#define XCP_CONST
#define XCP_VAR
#define XCP_CODE
#define XCP_APPL_DATA
#define XCP_MTA_DATA
#define XCP_DAQ_DATA
#define XCP_VAR_NOINIT


/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  FRXCP START 
 *********************************************************************************************************************/

#define FRXCP_CONST
#define FRXCP_CODE
#define FRXCP_APPL_DATA
#define FRXCP_APPL_VAR
#define FRXCP_VAR_NOINIT

/**********************************************************************************************************************
 *  FRXCP END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  Dcm START 
 *********************************************************************************************************************/

#define DCM_APPL_CODE
#define DCM_APPL_DATA
#define DCM_CODE
#define DCM_CONST
#define DCM_LCFG_CONST
#define DCM_VAR

/**********************************************************************************************************************
 *  Dcm END
 *********************************************************************************************************************/

















/**********************************************************************************************************************
 *  Dem START 
 *********************************************************************************************************************/

#define DEM_APPL_CODE
#define DEM_APPL_CONST
#define DEM_APPL_DATA
#define DEM_CODE
#define DEM_CONST
#define DEM_VAR
#define DEM_VAR_NOINIT

/**********************************************************************************************************************
 *  Dem END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Cdc START 
 *********************************************************************************************************************/

#define CDC_CODE
#define CDC_CONST_DCMDATA
#define CDC_FAR_CONST
#define CDC_FAR_DATA
#define CDC_PUBLIC_DCMCODE
#define CDC_VAR_DCMDATA
#define CDC_VAR_NVCONST
#define CDC_VAR_PRIVATE
#define CDC_VAR_PUBLIC
#define DEM_PUBLIC_CODE

/**********************************************************************************************************************
 *  Cdc END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Darh START 
 *********************************************************************************************************************/

#define DARH_APPL_CONST
#define DARH_APPL_DATA
#define DARH_CODE
#define DARH_CONST
#define DARH_DATA
#define DARH_DCM_DATA

/**********************************************************************************************************************
 *  Darh END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Adc START
 *********************************************************************************************************************/
#define ADC_CODE
#define ADC_CONST
#define ADC_PBCFG
#define ADC_APPL_DATA
#define ADC_VAR
/**********************************************************************************************************************
 *  Adc END
 *********************************************************************************************************************/





#define DIO_CONST
#define DIO_CODE
#define DIO_APPL_DATA
#define DIO_VAR





















/**********************************************************************************************************************
 *  FR START 
 *********************************************************************************************************************/

#define FR_CODE                 /* FR modules code qualifier */
#define FR_CODE_ISR             /* module interrupt service routines */

#define FR_CONST                /* FR constant memory */
#define FR_APPL_CONST           /* Application constant memory, coming from outside of the module */
#define FR_PBCFG                /* postbuild generated constant/flash */
#define FR_APPL_DATA            /* memory class for pointers to application data (expected to be in RAM or ROM) passed via API */
#define FR_VAR_FRM_DATA         /* memory class for pointers to Flexray memory data in RAM */
#define FR_APPL_CODE            /* memory class for pointers to application functions (e.g. call back function pointers) */

#define FR_VAR_NOINIT           /* none initialized variables. To be used for all global or static variables that are never initialized */                                
#define FR_VAR_NOINIT_FAST      /* like FR_VAR_NOINIT, optimized access */                                




/**********************************************************************************************************************
 *  FR END
 *********************************************************************************************************************/





#define GPT_CODE
#define GPT_DATA
#define GPT_CONST
#define GPT_APPL_DATA
#define GPT_APPL_CODE
#define GPT_PBCFG



/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01Asr START
 *********************************************************************************************************************/

#define ICU_CODE
#define ICU_APPL_CODE
#define ICU_APPL_DATA
#define ICU_VAR
#define ICU_VAR_FAST
#define ICU_CONST
#define ICU_PBCFG

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01Asr END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx START
 *********************************************************************************************************************/

#define HET_CODE
#define HET_RAM
#define HET_VAR
#define HET_CONST

/**********************************************************************************************************************
 *  DrvIcu_Tms570Tinhet01ExtVx END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 * MCU START
 *********************************************************************************************************************/

#define MCU_APPL_DATA
#define MCU_CODE
#define MCU_DATA
#define MCU_PBCFG
#define MCU_RAM_COPY
#define MCU_ROM_COPY
#define MICROSAR_NEAR

/**********************************************************************************************************************
 *  MCU END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  PORT START 
 *********************************************************************************************************************/
 
#define PORT_CODE
#define PORT_PBCODE
#define PORT_VAR
#define PORT_APPL_DATA
#define PORT_PBCFG

/**********************************************************************************************************************
 *  PORT END 
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  PWM START 
 *********************************************************************************************************************/
 
#define PWM_CODE
#define PWM_VAR
#define PWM_APPL_DATA
#define PWM_PBCFG

/**********************************************************************************************************************
 *  PWM STOP 
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  Spi START 
 **********************************************************************************************************************/

#define SPI_CODE
#define SPI_VAR
#define SPI_VAR_NOINIT
#define SPI_VAR_INIT
#define SPI_VAR_ZERO_INIT
#define SPI_CONST
#define SPI_PBCFG
#define SPI_APPL_CODE
#define SPI_APPL_DATA

/**********************************************************************************************************************
 *  Spi END
 **********************************************************************************************************************/

























/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

#define FRTRCV_CONST
#define FRTRCV_VAR
#define FRTRCV_CODE
#define FRTRCV_APPL_DATA

/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/







  /**********************************************************************************************************************
  *  WDG START
  *********************************************************************************************************************/
  #define WDG_REGS
  #define WDG_VAR_INIT
  #define WDG_APPL_DATA
  #define WDG_CONST
  #define WDG_PBCFG
  #define WDG_CODE
  #define WDG_TRIGGER
    
  /**********************************************************************************************************************
  *  WDG END
  *********************************************************************************************************************/








/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

#define IOHWAB_CODE

#define IOHWAB_VAR

#define IOHWAB_APPL_DATA
#define IOHWAB_APPL_CODE

#define IOHWAB_CONST

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

# define PDUR_CODE
# define PDUR_VAR_NOINIT
# define PDUR_VAR_ZERO_INIT
# define PDUR_VAR
# define PDUR_CONST
# define PDUR_PBCFG
# define PDUR_APPL_DATA
# define PDUR_APPL_CODE
# define PDUR_IPDUM_DATA
# define PDUR_MOST_DATA
# define PDUR_PBCFG_ROOT		PDUR_PBCFG

/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/









/**********************************************************************************************************************
 *  FRIF START 
 *********************************************************************************************************************/

#define FRIF_CODE
#define FRIF_CODE_FAST
#define FRIF_CODE_ISR

#define FRIF_CONST
#define FRIF_CONST_FAST
#define FRIF_PBCFG
#define FRIF_PBCFG_ROOT

#define FRIF_VAR_INIT
#define FRIF_VAR_NOINIT
#define FRIF_VAR_ZERO_INIT
#define FRIF_VAR_INIT_FAST
#define FRIF_VAR_NOINIT_FAST
#define FRIF_VAR_ZERO_INIT_FAST

#define FRIF_APPL_DATA
#define FRIF_APPL_CODE

/**********************************************************************************************************************
 *  FRIF END
 *********************************************************************************************************************/














#define MEMIF_CODE
#define MEMIF_CONST
#define MEMIF_APPL_DATA





/**********************************************************************************************************************
 *  If_AsrIfWd START
 *********************************************************************************************************************/

#define WDGIF_CODE
#define WDGIF_VAR
#define WDGIF_CONST
#define WDGIF_APPL_DATA

/**********************************************************************************************************************
 *  If_AsrIfWd END
 *********************************************************************************************************************/










/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define COM_CONST
/* Module Constant Data of the Postbuild Configuration */
#define COM_PBCFG
/* Module Root Constant of the Postbuild Configuration */
#define COM_PBCFG_ROOT 		COM_PBCFG


/* Module Implementation */
#define COM_CODE

/* Module Variables which are initialized by the startup code or by the call of Com_InitMemory() */
#define COM_VAR_NOINIT
/* Module Variables which are initialized by call of Com_Init() */
#define COM_VAR_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define COM_APPL_CODE
/* Application Buffer which is located in RAM */
#define COM_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define COM_APPL_DATA

/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  IpduM START 
 *********************************************************************************************************************/

#define IPDUM_APPL_CONST
#define IPDUM_APPL_DATA
#define IPDUM_CODE
#define IPDUM_VAR
#define IPDUM_VAR_NOINIT
#define IPDUM_VAR_FAST
#define IPDUM_CONST

/**********************************************************************************************************************
 *  IpduM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  NvM START 
 *********************************************************************************************************************/

#define NVM_APPL_DATA
#define NVM_APPL_CODE
#define NVM_APPL_CONST

#define NVM_CRC_APPL_DATA

#define NVM_CONFIG_DATA
#define NVM_CONFIG_CONST

#define NVM_FAST_DATA

#define NVM_PRIVATE_CODE
#define NVM_PRIVATE_CONST
#define NVM_PRIVATE_DATA

#define NVM_PUBLIC_CODE
#define NVM_PUBLIC_CONST

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/














#define CRC_APPL_DATA
#define CRC_CODE
#define CRC_CONST



# define DET_CODE
# define DET_VAR
# define DET_APPL_DATA
# define DET_APPL_CODE



/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM START 
 *********************************************************************************************************************/
#define ECUM_API_CODE 
#define ECUM_APPL_CONFIG 
#define ECUM_APPL_DATA 
#define ECUM_VAR_BOOT
#define ECUM_CODE
#define ECUM_CODE_BOOT_TARGET 
#define ECUM_CONST 
#define ECUM_PBCFG
#define ECUM_VAR 
#define ECUM_VAR_NOINIT 

/**********************************************************************************************************************
 *  SYSSERVICE_ASRECUM END
 *********************************************************************************************************************/








/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM START 
 *********************************************************************************************************************/

#define WDGM_CODE

#define WDGM_VAR
#define WDGM_VAR_NOINIT
#define WDGM_DATA

#define WDGM_APPL_DATA
#define WDGM_APPL_CODE

#define WDGM_GPT_CODE
#define WDGM_CONST
#define WDGM_PBCFG

/**********************************************************************************************************************
 *  SYSSERVICE_ASRWDM END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  Coding START 
 *********************************************************************************************************************/

#define CODING_CONST
#define CODING_CONST_DESCRIPTOR_TABLE
#define CODING_PRIVATE_CODE
#define CODING_PUBLIC_CODE
#define CODING_VAR
#define CODING_VAR_DCMDATA
#define CODING_VAR_DIAGDATA
#define CODING_VAR_NVDATA
#define USER_PUBLIC_CODE

/**********************************************************************************************************************
 *  Coding END
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  Crypto START 
 *********************************************************************************************************************/

#define CRYPTO_CONST
#define CRYPTO_VAR

/**********************************************************************************************************************
 *  Crypto END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Csm START 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Csm END
 *********************************************************************************************************************/



















/**********************************************************************************************************************
 *  SchM START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define SCHM_CONST

/* Module Implementation */
#define SCHM_CODE

/* Module Variables which are not initialized by the startup code of the compiler */
#define SCHM_VAR_NOINIT

/* Module Global or static variables that are initialized with zero by the startup code of the compiler or in SchM_InitMemory */
#define SCHM_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  SchM END
 *********************************************************************************************************************/







/**********************************************************************************************************************
 *  SysTimeClient START 
 *********************************************************************************************************************/

#define SYSTIMECLIENT_PUBLIC_CODE
#define SYSTIMECLIENT_PRIVATE_CODE
#define SYSTIMECLIENT_VAR

/**********************************************************************************************************************
 *  SysTimeClient END
 *********************************************************************************************************************/











/**********************************************************************************************************************
 *  FrTp START 
 *********************************************************************************************************************/

#define FRTP_CODE
#define FRTP_APPL_CONST
#define FRTP_CONST
#define FRTP_APPL_DATA
#define FRTP_VAR

/**********************************************************************************************************************
 *  FrTp END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  E2E START 
 *********************************************************************************************************************/


#define E2E_CODE
#define E2E_VAR_NOINIT
#define E2E_VAR_POWER_ON_INIT
#define E2E_VAR_FAST
#define E2E_VAR
#define E2E_CONST
#define E2E_APPL_DATA
#define E2E_APPL_CONST
#define E2E_APPL_CODE

/**********************************************************************************************************************
 *  E2E END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  E2E START 
 *********************************************************************************************************************/


#define E2EPW_CODE
#define E2EPW_VAR_NOINIT
#define E2EPW_VAR_POWER_ON_INIT
#define E2EPW_VAR_FAST
#define E2EPW_VAR
#define E2EPW_CONST
#define E2EPW_APPL_DATA
#define E2EPW_APPL_CONST
#define E2EPW_APPL_CODE

/**********************************************************************************************************************
 *  E2E END
 *********************************************************************************************************************/












/* Package Merger: Stop Section CompilerCfgModuleList */

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


#endif  /* COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler_Cfg.h
 *********************************************************************************************************************/

/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
/************   Organi, Version 3.9.0 Vector-Informatik GmbH  ************/
