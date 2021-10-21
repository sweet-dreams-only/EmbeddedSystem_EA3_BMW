/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Ap_DrvDynEnbl.c
 *     Workspace:  C:/Documents and Settings/nzt9hv/My Documents/Synergy/ccm_wa/ESG_Dev_65/DrvDynEnbl-nzt9hv/DrvDynEnbl/autosar
 *     SW-C Type:  Ap_DrvDynEnbl
 *  Generated at:  Tue Feb 19 14:58:02 2013
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.2
 *       License:  License CBD1010122 valid for CBD1010122 Nxtr  GM MSR_SLP3_BSW_RTE_wGMLAN TexasInstruments TMS570 Texas Instruments
 *
 *   Description:  C-Code implementation template for SW-C <Ap_DrvDynEnbl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * Date Created:      Wed Jun 06 17:52:44 2012
 * %version:          4 %
 * %derived_by:       nzt9hv %
 * %date_modified:    Mon Apr 29 16:00:55 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ---------- 
 * 10/06/12   2        Selva      Checkpoints added and mempmap macros corrected		                          6461
 * 02/19/13   3         Selva       Updated to FDDv10
 * 04/29/13   4         Selva       Fixed for Unit test finding's. Redundant test removed.
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Types:
 ===========
  QU_SER_WSTA_EST_FTAX
    Service-Qualifier zur Lenkradvibration


 Mode Declaration Groups:
 ========================
  StaMd_Mode
    EPS System State mode declaration

 *********************************************************************************************************************/

#include "Rte_Ap_DrvDynEnbl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ap_DrvDynEnbl_Cfg.h"

/* == INCLUDES ================================================= */

#include "GlobalMacro.h"



/* == DATA TYPES =============================================== */

typedef void(*DrvDynHandler_T)(boolean*pActive_T_lgc,boolean*OpTrqRmpEn_T_lgc);

typedef enum 
{
	DRVDYN_STATE_INITIALIZED = 0,
	DRVDYN_STATE_AVAILABLE = 1,
	DRVDYN_STATE_ACTIVE = 2,
	DRVDYN_STATE_ERROR = 3,
    DRVDYN_STATE_STANDBYPMA = 4,
    DRVDYN_STATE_STANDBYEPSSTATUS = 5,
   DRVDYN_STATE_INVALID = 6
} DriveDynamicsState_T;

/* == PROTOTYPES =============================================== */

STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_Default(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc);
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_Initialized(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc);
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_Available(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc);
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_Active(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc);
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_StandbyPMA(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc);
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_StandbyEpsStatus(P2VAR(boolean, AUTOMATIC, AUTOMATIC)pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc);


/* == CONSTANTS ================================================ */

STATIC CONST(uint8, AP_DRVDYNENBL_CODE) t_DrvDynStateCode_Cnt_u08[] = 
{
	Cx80_Schnittstelle_wird_initialisiert,
	Cx20_Schnittstelle_verfuegbar___funktionsbereit,
	Cx21_Schnittstelle_aktiv,
	Cx60_Service_nicht_verfuegbar___Fehler,
	CxE0_Service_nicht_verfuegbar___Standby___PMA, 
	CxE1_Service_nicht_verfuegbar___Standby___EPS_Status,
	CxFF_Signal_ungueltig
};

STATIC CONST(DrvDynHandler_T, AP_DRVDYNENBL_CODE) t_DrvDynStateHandler_Cnt_Fn[] = 
{
	&DrvDyn_HdlSt_Initialized,		/* DRVDYN_STATE_INITIALIZED */
	&DrvDyn_HdlSt_Available,			/* DRVDYN_STATE_AVAILABLE */
	&DrvDyn_HdlSt_Active,			/* DRVDYN_STATE_ACTIVE */
	&DrvDyn_HdlSt_Default,			/* DRVDYN_STATE_ERROR */
	&DrvDyn_HdlSt_StandbyPMA,		/* DRVDYN_STATE_STANDBYPMA */
	&DrvDyn_HdlSt_StandbyEpsStatus,	/* DRVDYN_STATE_STANDBYEPSSTATUS */
	&DrvDyn_HdlSt_Default			/* DRVDYN_STATE_INVALID */
};


#define DRVDYNENBL_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
STATIC VAR(Boolean,  DRVDYNENBL_VAR_NOINIT) DrvDynActive_Cnt_M_lgc;
STATIC VAR(Boolean,  DRVDYNENBL_VAR_NOINIT) OpTrqOvRmpInEnable_Cnt_M_lgc;
#define DRVDYNENBL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"

#define DRVDYNENBL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
STATIC VAR(DriveDynamicsState_T,  DRVDYNENBL_VAR_NOINIT) DrvDynInterfaceState_Cnt_M_enum;
#define DRVDYNENBL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 *
 * Enumeration Types:
 * ==================
 * QU_SER_STMOM_STMOM_DV_ACT: Enumeration of integer in interval [0...255] with enumerators
 *   Cx20_Schnittstelle_verfuegbar___funktionsbereit (32u)
 *   Cx21_Schnittstelle_aktiv (33u)
 *   Cx60_Service_nicht_verfuegbar___Fehler (96u)
 *   Cx80_Schnittstelle_wird_initialisiert (128u)
 *   CxE0_Service_nicht_verfuegbar___Standby___PMA (224u)
 *   CxE1_Service_nicht_verfuegbar___Standby___EPS_Status (225u)
 *   CxFF_Signal_ungueltig (255u)
 * QU_SER_WSTA_EST_FTAX: Enumeration of integer in interval [0...255] with enumerators
 *   Cx20_Schnittstelle_verfuegbar___funktionsbereit (32u)
 *   Cx21_Schnittstelle_aktiv (33u)
 *   Cx60_Service_nicht_verfuegbar___Fehler (96u)
 *   Cx80_Schnittstelle_wird_initialisiert (128u)
 *   CxE0_Funktion_in_Rueckfallebene___V_Fzg_____0 (224u)
 *   CxE2_Funktion_in_Rueckfallebene___Hands_On (226u)
 *   CxE3_Funktion_in_Rueckfallebene___EPS_Status (227u)
 *   CxE4_Schnittstelle_inaktiv___Stillstandsnaher_Bereich_verlassen (228u)
 *   CxE7_Schnittstelle_aktiv_degradiert (231u)
 *   CxFF_Signal_ungueltig (255u)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_AP_DRVDYNENBL_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DrvDynEnbl_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *     and not in Mode(s) <OFF>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Implicit S/R API:
 *   -----------------
 *   Boolean Rte_IRead_DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc(void)
 *   Boolean Rte_IRead_DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc(void)
 *   Boolean Rte_IRead_DrvDynEnbl_Per1_DiagStatus_Cnt_lgc(void)
 *   QU_SER_WSTA_EST_FTAX Rte_IRead_DrvDynEnbl_Per1_PrkAssistState_Cnt_u08(void)
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc(void)
 *   void Rte_IWrite_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08(QU_SER_STMOM_STMOM_DV_ACT data)
 *   QU_SER_STMOM_STMOM_DV_ACT *Rte_IWriteRef_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08(void)
 *   void Rte_IWrite_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc(Boolean data)
 *   Boolean *Rte_IWriteRef_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc(void)
 *
 * Mode Interfaces:
 * ================
 *   Rte_ModeType_StaMd_Mode Rte_Mode_SystemState_Mode(void)
 *   Modes of Rte_ModeType_StaMd_Mode:
 *   - RTE_MODE_StaMd_Mode_DISABLE
 *   - RTE_MODE_StaMd_Mode_OFF
 *   - RTE_MODE_StaMd_Mode_OPERATE
 *   - RTE_MODE_StaMd_Mode_WARMINIT
 *   - RTE_TRANSITION_StaMd_Mode
 *
 *********************************************************************************************************************/

FUNC(void, RTE_AP_DRVDYNENBL_APPL_CODE) DrvDynEnbl_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DrvDynEnbl_Per1
 *********************************************************************************************************************/

	VAR(boolean, AUTOMATIC) Active_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC) State_Cnt_T_u08;
	VAR(uint8, AUTOMATIC) DrvDynState_Cnt_T_enum;
	VAR(boolean, AUTOMATIC) OpTrqOvRmpInEnable_Cnt_T_lgc;
	
	/* capture current active status */
	/* Configurable Start of Runnable Checkpoint */
	Rte_Call_DrvDynEnbl_Per1_CP0_CheckpointReached();
	Active_Cnt_T_lgc = DrvDynActive_Cnt_M_lgc;
	OpTrqOvRmpInEnable_Cnt_T_lgc = OpTrqOvRmpInEnable_Cnt_M_lgc;
	DrvDynState_Cnt_T_enum = DrvDynInterfaceState_Cnt_M_enum;
	
	/* determine the next state and active flag */
	
	t_DrvDynStateHandler_Cnt_Fn[DrvDynState_Cnt_T_enum](&Active_Cnt_T_lgc, &OpTrqOvRmpInEnable_Cnt_T_lgc);
	
	
	DrvDynState_Cnt_T_enum = DrvDynInterfaceState_Cnt_M_enum;
	State_Cnt_T_u08 = t_DrvDynStateCode_Cnt_u08[DrvDynState_Cnt_T_enum];
	
	
	/* update outputs */
	DrvDynActive_Cnt_M_lgc = Active_Cnt_T_lgc;
	OpTrqOvRmpInEnable_Cnt_M_lgc = OpTrqOvRmpInEnable_Cnt_T_lgc;
	Rte_IWrite_DrvDynEnbl_Per1_DrvDynActive_Cnt_lgc(Active_Cnt_T_lgc);
	Rte_IWrite_DrvDynEnbl_Per1_DrvDynInterfaceState_Cnt_u08(State_Cnt_T_u08);
	Rte_IWrite_DrvDynEnbl_Per1_OpTrqOvRmpInEnable_Cnt_lgc(OpTrqOvRmpInEnable_Cnt_T_lgc);
	/* Configurable End of Runnable Checkpoint */
	Rte_Call_DrvDynEnbl_Per1_CP1_CheckpointReached();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_AP_DRVDYNENBL_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* == STATE HANDLERS =========================================== */

/*****************************************************************************
 * Handle State:	(generic)
 *****************************************************************************/
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_Default( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc )
{
	/* do nothing */
	pActive_T_lgc = pActive_T_lgc;
	OpTrqRmpEn_T_lgc = OpTrqRmpEn_T_lgc;
}

/*****************************************************************************
 * Handle State:	DRVDYN_STATE_INITIALIZED
 *****************************************************************************/
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_Initialized( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc )
{
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	
	/* capture inputs */	
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	
	/* determine which state transition to make if any */
	if(RTE_MODE_StaMd_Mode_OPERATE == SystemState_Cnt_T_enum)
	{
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_AVAILABLE;
		(*pActive_T_lgc) = FALSE;
		(*OpTrqRmpEn_T_lgc) = FALSE;
	}
}

/*****************************************************************************
 * Handle State:	DRVDYN_STATE_AVAILABLE
 *****************************************************************************/
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_Available( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc )
{
	VAR(boolean, AUTOMATIC)	DiagStatusError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	Invalid_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC)	PrkAstState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC)	Enable_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;
	
	/* capture inputs */
	DiagStatusError_Cnt_T_lgc	= Rte_IRead_DrvDynEnbl_Per1_DiagStatus_Cnt_lgc();
	Invalid_Cnt_T_lgc			= Rte_IRead_DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc();
	PrkAstState_Cnt_T_u08		= Rte_IRead_DrvDynEnbl_Per1_PrkAssistState_Cnt_u08();
	Enable_Cnt_T_lgc			= Rte_IRead_DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc();
	
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	/* determine which state transition to make if any */
	if(TRUE == DiagStatusError_Cnt_T_lgc)
	{
		(*pActive_T_lgc) = FALSE;
		(*OpTrqRmpEn_T_lgc) = FALSE;
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_ERROR;
	}
	else if((TRUE == Invalid_Cnt_T_lgc) || ((SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE)))
	{   
		
		(*pActive_T_lgc) = FALSE;
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_STANDBYEPSSTATUS;
	}
	else if(Cx21_Schnittstelle_aktiv == PrkAstState_Cnt_T_u08)
	{	
		
		(*pActive_T_lgc) = FALSE;
        DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_STANDBYPMA;
	}
	else if(TRUE == Enable_Cnt_T_lgc)
	{	
		
		(*pActive_T_lgc) = TRUE;
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_ACTIVE;
	}
	else { }
}

/*****************************************************************************
 * Handle State:	DRVDYN_STATE_ACTIVE
 *****************************************************************************/
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_Active( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc )
{
	VAR(boolean, AUTOMATIC)	DiagStatusError_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	Invalid_Cnt_T_lgc;
	VAR(uint8, AUTOMATIC)	PrkAstState_Cnt_T_u08;
	VAR(boolean, AUTOMATIC)	Enable_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;

	/* capture inputs */
	DiagStatusError_Cnt_T_lgc	= Rte_IRead_DrvDynEnbl_Per1_DiagStatus_Cnt_lgc();
	Invalid_Cnt_T_lgc			= Rte_IRead_DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc();
	PrkAstState_Cnt_T_u08		= Rte_IRead_DrvDynEnbl_Per1_PrkAssistState_Cnt_u08();
	Enable_Cnt_T_lgc			= Rte_IRead_DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc();
	
	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	/* determine which state transition to make if any */
	if(TRUE == DiagStatusError_Cnt_T_lgc)
	{
		(*pActive_T_lgc) = FALSE;
		(*OpTrqRmpEn_T_lgc) = FALSE;
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_ERROR;
	}
	else if((TRUE == Invalid_Cnt_T_lgc)|| ((SystemState_Cnt_T_enum == RTE_MODE_StaMd_Mode_DISABLE)))
	{	
		(*OpTrqRmpEn_T_lgc) = TRUE;
		(*pActive_T_lgc) = FALSE;
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_STANDBYEPSSTATUS;
	}
	else if(Cx21_Schnittstelle_aktiv == PrkAstState_Cnt_T_u08)
	{	
	    (*OpTrqRmpEn_T_lgc) = TRUE;
		(*pActive_T_lgc) = FALSE;
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_STANDBYPMA;
	}
	else if(FALSE == Enable_Cnt_T_lgc)
	{	
		(*OpTrqRmpEn_T_lgc) = FALSE;
		(*pActive_T_lgc) = FALSE;
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_AVAILABLE;
	}
	else { }
}

/*****************************************************************************
 * Handle State:	DRVDYN_STATE_STANDBYPMA
 *****************************************************************************/
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_StandbyPMA( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc ,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc)
{
	VAR(uint8, AUTOMATIC) PrkAstState_Cnt_T_u08;
	PrkAstState_Cnt_T_u08 = Rte_IRead_DrvDynEnbl_Per1_PrkAssistState_Cnt_u08();
	
	/* determine which state transition to make if any */
	if(Cx21_Schnittstelle_aktiv != PrkAstState_Cnt_T_u08)
	{
		(*OpTrqRmpEn_T_lgc) = (*OpTrqRmpEn_T_lgc) ;
		(*pActive_T_lgc) = FALSE;
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_AVAILABLE;
	}
}

/*****************************************************************************
 * Handle State:	DRVDYN_STATE_STANDBYEPSSTATUS
 *****************************************************************************/
STATIC FUNC(void, AP_DRVDYNENBL_CODE) DrvDyn_HdlSt_StandbyEpsStatus( P2VAR(boolean, AUTOMATIC, AUTOMATIC) pActive_T_lgc,P2VAR(boolean, AUTOMATIC, AUTOMATIC)OpTrqRmpEn_T_lgc)
{
	VAR(boolean, AUTOMATIC)	Invalid_Cnt_T_lgc;
	VAR(boolean, AUTOMATIC)	Enable_Cnt_T_lgc;
	VAR(Rte_ModeType_StaMd_Mode, AUTOMATIC) SystemState_Cnt_T_enum;

	SystemState_Cnt_T_enum = Rte_Mode_SystemState_Mode();
	/* capture inputs */
	Invalid_Cnt_T_lgc			= Rte_IRead_DrvDynEnbl_Per1_DDErrInterfaceActive_Cnt_lgc();
	Enable_Cnt_T_lgc			= Rte_IRead_DrvDynEnbl_Per1_DDEnableRqst_Cnt_lgc();
	
	/* determine which state transition to make if any */
	if( (FALSE == Invalid_Cnt_T_lgc) && (FALSE == Enable_Cnt_T_lgc) && (SystemState_Cnt_T_enum != RTE_MODE_StaMd_Mode_DISABLE))
	{
		DrvDynInterfaceState_Cnt_M_enum = DRVDYN_STATE_AVAILABLE;
		(*pActive_T_lgc) = FALSE;
		(*OpTrqRmpEn_T_lgc) = (*OpTrqRmpEn_T_lgc) ;
	}
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
