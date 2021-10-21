/*****************************************************************************
* Copyright 2009 Nxtr Automotive, Inc., All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Metrics_Cfg.h
* Module Description: Prototypes for Metrics Functions and Macros
* Product           : EPS EA3
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri May  4 15:33:54 2012
* %version:          3 %
* %derived_by:       zz4r1x %
* %date_modified:    Fri Mar 22 11:33:59 2013 %
*---------------------------------------------------------------------------*/
#ifndef METRICS_CFG_H
#define METRICS_CFG_H

#include "Os.h" /* Required for choice of exclusive area protection */

/************ Metric Module Exclusive Area Protection *****************/
/* Task Start */
#define METRICS_ENTER_EXCLUSIVEAREA0	DisableAllInterrupts()
#define METRICS_EXIT_EXCLUSIVEAREA0		EnableAllInterrupts()
/* Task End */
#define METRICS_ENTER_EXCLUSIVEAREA1	DisableAllInterrupts()
#define METRICS_EXIT_EXCLUSIVEAREA1		EnableAllInterrupts()
/* MainFunction Metrics Calculations */
#define METRICS_ENTER_EXCLUSIVEAREA2	DisableAllInterrupts()
#define METRICS_EXIT_EXCLUSIVEAREA2		EnableAllInterrupts()
/* Runnable Start */
#define METRICS_ENTER_EXCLUSIVEAREA3	DisableAllInterrupts()
#define METRICS_EXIT_EXCLUSIVEAREA3		EnableAllInterrupts()
/* Runnable End */
#define METRICS_ENTER_EXCLUSIVEAREA4	DisableAllInterrupts()
#define METRICS_EXIT_EXCLUSIVEAREA4		EnableAllInterrupts()

/******************* Metric Module Feature Enable *********************/
#define BC_METRICS_DET			STD_ON
#define BC_METRICS_STACKUSE 	STD_ON
#define BC_METRICS_CPUUSEDIO	STD_OFF
#define BC_METRICS_CPUUSETMR	STD_ON
#define BC_METRICS_RUNBLCPUUSE	STD_OFF
#define BC_METRICS_PREEMPTCOUNT STD_OFF
#define BC_METRICS_BYPASSMPU    STD_ON

/**************** Metric Module Measurement Constants *****************/
#define D_OSCONTEXTSWITCH_US_U32  	0U		/* Os context switching constant to be used to compensate runtime measurements */
#define D_HWSTARTUP_US_U16          55000U; /* Constant measured in CTP.  This is the time from Wakeup High to uP Reset High */
#define D_OSCILATORFREQ_MHZ_U16		20		/* Used to configure the rti during the initial startup phase to measure init timing */

/************************** Task IDs **************************/
#define D_MTRCTRLID_CNT_U08                 osdNumberOfAllTasks
#define D_COMIRQ1_CNT_U08                   (D_MTRCTRLID_CNT_U08 + 1)
#define D_COMIRQ2_CNT_U08                 (D_COMIRQ1_CNT_U08 + 1)
#define D_COMIRQ3_CNT_U08                 (D_COMIRQ2_CNT_U08 + 1)
#define D_SPIIRQ1_CNT_U08                 (D_COMIRQ3_CNT_U08 + 1)
#define D_SPIIRQ2_CNT_U08                 (D_SPIIRQ1_CNT_U08 + 1)
#define D_SPIIRQ3_CNT_U08                 (D_SPIIRQ2_CNT_U08 + 1)
#define D_SPIIRQ4_CNT_U08                 (D_SPIIRQ3_CNT_U08 + 1)
#define D_SPIIRQ5_CNT_U08                 (D_SPIIRQ4_CNT_U08 + 1)
#define D_SPIIRQ6_CNT_U08                 (D_SPIIRQ5_CNT_U08 + 1)
#define D_SPIIRQ7_CNT_U08                 (D_SPIIRQ6_CNT_U08 + 1)
#define D_SPIIRQ8_CNT_U08                 (D_SPIIRQ7_CNT_U08 + 1)
#define D_SPIIRQ9_CNT_U08                 (D_SPIIRQ8_CNT_U08 + 1)
#define D_SPIIRQ10_CNT_U08                (D_SPIIRQ9_CNT_U08 + 1)
#define D_SPIIRQ11_CNT_U08                (D_SPIIRQ10_CNT_U08 + 1)
#define D_CROSSCHKID_CNT_U08              (D_SPIIRQ11_CNT_U08 + 1)
#define D_SPINXT1_CNT_U08					(D_CROSSCHKID_CNT_U08 + 1)
#define D_SPINXT2_CNT_U08					(D_SPINXT1_CNT_U08 + 1)
#define D_METRICS_CNT_U08					(D_SPINXT2_CNT_U08 + 1)
#define D_RTSID_CNT_U08                     (D_METRICS_CNT_U08 + 1)
#define d_NumberofTasks_Cnt_u16		    (D_RTSID_CNT_U08 + 1)

/* Number of Monitored Runnables */
#define d_NumberofRunnables_Cnt_u16		    1U

/************************** Trace Config IDs **************************/
#define D_MAXTRACEEVT_CNT_U16	      150U /* Define the Maximum number of init trace points allowed to be captured */
#define D_TRACE_OSINIT_CNT_U16          1U
#define D_TRACE_ECUMINIT_CNT_U16        2U
#define D_TRACE_ECUSTARTUP1_CNT_U16     3U
#define D_TRACE_GPTINIT_CNT_U16         4U
#define D_TRACE_ECUSTARTUP1END_CNT_U16  5U
#define D_TRACE_ECUSTARTUP2_CNT_U16     6U
#define D_TRACE_NVMINIT_CNT_U16         7U
#define D_TRACE_NVMEND_CNT_U16          8U
#define D_TRACE_ECUSTARTUP2END_CNT_U16  9U
#define D_TRACE_FULLCOMM_CNT_U16       10U
#define D_TRACE_TXAVLPO_CNT_U16        11U
#define D_TRACE_FRINIT_CNT_U16         12U
#define D_TRACE_CODINGINIT_CNT_U16     13U
#define D_TRACE_XCPINIT_CNT_U16        14U

#define D_TRACE_ECUMMAINFCN_CNT_U16           15U
#define D_TRACE_CODINGMAINFCN_CNT_U16         16U
#define D_TRACE_COMRXMAINFCN_CNT_U16          17U
#define D_TRACE_COMTXMAINFCN_CNT_U16          18U
#define D_TRACE_COMROUTEMAINFCN_CNT_U16       19U
#define D_TRACE_COMMMAINFCN_CNT_U16           20U
#define D_TRACE_DARHMAINFCN_CNT_U16           21U
#define D_TRACE_DEMMAINFCN_CNT_U16            22U
#define D_TRACE_SPIHMAINFCN_CNT_U16           23U
#define D_TRACE_SPIDMAINFCN_CNT_U16           24U
#define D_TRACE_EEPMAINFCN_CNT_U16            25U
#define D_TRACE_EAMAINFCN_CNT_U16             26U
#define D_TRACE_NVMMAINFCN_CNT_U16            27U
#define D_TRACE_WDGM_MAINFCN_CNT_U16          28U

#define D_TRACE_FRIFMAINFCN_CNT_U16           30U
#define D_TRACE_FRTPMAINFCN_CNT_U16           31U
#define D_TRACE_FRTRCVMAINFCN_CNT_U16         32U
#define D_TRACE_FRSMMAINFCN_CNT_U16           33U
#define D_TRACE_SYSTIMECLIENTMAINFCN_CNT_U16  34U
#define D_TRACE_VSM_CLIENTMAINFCN_CNT_U16     35U
#define D_TRACE_FRXCPTXMAINFCN_CNT_U16        36U
#define D_TRACE_FRXCPRXMAINFCN_CNT_U16        37U
#define D_TRACE_DCMMAINFCN_CNT_U16            38U

#define D_TRACE_SYSTEMTICK_CNT_U16            39U

#define D_NUMTRACEPOINTS_CNT_U16		      40U



#endif /* METRICS_CFG_H */
