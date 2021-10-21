#ifndef AP_DEMIF_NXTRADDON_H
#define AP_DEMIF_NXTRADDON_H

/* Manually added Start */
#define OBD_CYCLE 3U
typedef uint8 Edch_EventIdxType;
typedef uint8 Dem_EventStatusType;
/* End */


extern FUNC(Std_ReturnType, RTE_EDCH_APPL_CODE) Edch_SetEventStatusIN(Edch_EventIdxType IdxIN, Dem_EventStatusType EventStatus);
typedef Std_ReturnType (*EdchSetMonitor_T)(Edch_EventIdxType IdxIN, Dem_EventStatusType EventStatus);

typedef struct EdchRelDiag_Str {
	uint8				DEMEventId;
	EdchSetMonitor_T	func;
}EdchRelDiag_Str;

/* Values are generated based on the Edch configuration. */

#define D_NUMOFEDCHDIAG_CNT_U8	2U /* Set to 2 for QAC not to flag a warning that the loop is only ran once */

STATIC CONST(EdchRelDiag_Str, AP_DEMIF_CODE) t_EdchRelDiagTbl_str[] = 
{
	{0U, &Edch_SetEventStatusIN},	/* Dummy value */
	{1U, &Edch_SetEventStatusIN},	/* Dummy value */
};


#endif /* AP_DEMIF_NXTRADDON_H */
/*** End of file **************************************************************/
