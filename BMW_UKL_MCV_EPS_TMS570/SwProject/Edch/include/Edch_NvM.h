/* --------{ BMW C Source File }-------- */

/* !LINKSTO EDCH_SDD_0310, 1
 */

 #ifndef EDCH_NVM_H
#define EDCH_NVM_H

/*==================[inclusions]==============================================*/

#include <Edch_NvM_Cfg.h>

/*==================[macros]==================================================*/

/*==================[type definitions]========================================*/

/*------------------[State of OBD operation cycle]----------------------------*/

/* !LINKSTO EDCH_257, 2
 */
/**
 * \brief Type for actual state of the OBD Cycle resp. the Driving Cycle
 */
typedef enum {
  EDCH_OC_NOT_ACTIVE,
  EDCH_OC_ACTIVE,
  EDCH_OC_QUALIFIED
}Edch_OperationCycleStateType;

/*------------------[CRC32 checksums]-----------------------------------------*/

/**
 * \brief Type for CRC32 Value
 */
typedef uint32 Edch_ChecksumValType;

/*==================[external function declarations]==========================*/

/*==================[external constants]======================================*/

#define EDCH_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* !LINKSTO EDCH_SDD_0305, 1
 */
extern CONST(Edch_ChecksumValType, EDCH_CONST) Edch_CalIdDefaultVal;

/* !LINKSTO EDCH_SDD_0306, 1
 */
extern CONST(Edch_ChecksumValType, EDCH_CONST) Edch_CvnDefaultVal;

#if (EDCH_CODINGSW_CNT != 0)
/* !LINKSTO EDCH_SDD_0307, 1
 */
extern CONST(Edch_ChecksumValType, EDCH_CONST) Edch_RefCodCvnDefaultVal;

/* !LINKSTO EDCH_SDD_0308, 1
 */
extern CONST(Edch_ChecksumValType, EDCH_CONST) Edch_SubCodCvnDefaultVal;
#endif

/* !LINKSTO EDCH_SDD_0309, 1
 */
extern CONST(Edch_ChecksumValType, EDCH_CONST) Edch_SubCvnDefaultVal[EDCH_CVNTABLE_CNT];

/* !LINKSTO EDCH_SDD_0318, 1
 */
extern CONST(Edch_OperationCycleStateType, EDCH_CONST) Edch_OperationCycleStateDefaultVal;

#define EDCH_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]======================================*/

/*==================[external data]===========================================*/

#define EDCH_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* !LINKSTO EDCH_SDD_0280, 1
 */
extern VAR(Edch_ChecksumValType, EDCH_VAR) Edch_CalId_val;

/* !LINKSTO EDCH_SDD_0281, 1
 */
extern VAR(Edch_ChecksumValType, EDCH_VAR) Edch_Cvn_val;

#if (EDCH_CODINGSW_CNT != 0)
/* !LINKSTO EDCH_SDD_0283, 1
 */
extern VAR(Edch_ChecksumValType, EDCH_VAR) Edch_RefCodCvn_val;

/* !LINKSTO EDCH_SDD_0284, 1
 */
extern VAR(Edch_ChecksumValType, EDCH_VAR) Edch_SubCodCvn_val;
#endif

/* !LINKSTO EDCH_SDD_0282, 1
 */
extern VAR(Edch_ChecksumValType, EDCH_VAR) Edch_SubCvn_val[EDCH_CVNTABLE_CNT];

/* !LINKSTO EDCH_211, 2
 */
extern VAR(Edch_OperationCycleStateType, EDCH_VAR) Edch_OperationCycleState;

#define EDCH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/*==================[internal data]===========================================*/

/*==================[external function definitions]===========================*/

/*==================[internal function definitions]===========================*/

#endif /* if (!defined EDCH_NVM_H) */
/*==================[end of file]=============================================*/

