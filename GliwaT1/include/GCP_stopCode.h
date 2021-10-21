/*************************************************************************************
*   FILE:           GCP_stopCode.h
*
*   DESCRIPTION:    Restore code section or set default compiler code section.
*
*   $Author: nick $
*
*   $Revision: 14073 $
*
*   $URL: https://gliwa.com/svn/repos/T1target/trunk/src/GCP/common/src/GCP_stopCode.h $
*
*   Copyright:      Gliwa GmbH | know- how in embedded software
*                   Weilheim i.OB.
*                   All rights reserved
*************************************************************************************/
#include "T1_AppInterface.h"

#ifdef T1_DGNINTERFACE
/* No multiple include protection. */
#define T1_STOP_SEC_CODE
#include "T1_MemMap.h"

#endif /* T1_DGNINTERFACE */
