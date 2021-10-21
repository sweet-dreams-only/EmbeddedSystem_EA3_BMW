/*************************************************************************************
*   FILE:           GCP_startCode.h
*
*   DESCRIPTION:    Set T1 code section for GCP.
*
*   $Author: nick $
*
*   $Revision: 14073 $
*
*   $URL: https://gliwa.com/svn/repos/T1target/trunk/src/GCP/common/src/GCP_startCode.h $
*
*   Copyright:      Gliwa GmbH | know- how in embedded software
*                   Weilheim i.OB.
*                   All rights reserved
*************************************************************************************/
#include "T1_AppInterface.h"

#ifdef T1_DGNINTERFACE
/* No multiple include protection. */
#define T1_START_SEC_CODE
#include "T1_MemMap.h"

#endif /* T1_DGNINTERFACE */

