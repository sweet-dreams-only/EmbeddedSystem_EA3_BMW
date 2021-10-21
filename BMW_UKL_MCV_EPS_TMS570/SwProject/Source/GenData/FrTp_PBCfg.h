/** BMW FrTp {BMW FlexRay Transport Protocol}
 **
 ** Copyright 2002-2010 Elektrobit Austria GmbH, http://www.elektrobit.com/
 ** All rights reserved.
 ** This software is the confidential and proprietary information
 ** of Elektrobit ("Confidential Information").
 *
 ** You shall not disclose such Confidential Information
 ** and shall use it only in accordance with the terms and
 ** conditions of the License Agreement you entered into with
 ** Elektrobit.
 **
 */


/*
 * MCG-Version:       2.0.6
 */
#ifndef _FRTP_PBCFG_H_
#define _FRTP_PBCFG_H_


#include "FrTp_Cfg.h"               /* pre-compile time parameter */
#include <FrTp_Types.h>             /* Internal FrTp Types */

#if (!defined FRTP_BSW_MCG_IFVERSION_CHECK) || \
(!FRTP_BSW_MCG_IFVERSION_CHECK(1,3,2))
 #error Interface version number mismatch.
#endif

#define FRTP_CONFIG_NAME FrTpMultipleConfigLayout
#define FRTP_CONFIG_LAYOUT_TYPE FrTpMultipleConfigLayoutType
#define FrTpMultipleConfig (FrTpMultipleConfigLayout.RootConfig)

typedef struct
{
    #if FRTP_RELOCATABLE_CONFIG == STD_ON
    const FrTpRootConfigType RootConfig;
    #endif
    const FrTp_ChnConfigType Channels[1];
    const FrTp_ConConfigType Connections[28];
    const FrTp_PDUTxConfigType TxPdus[1];
    const FrTp_PDURxConfigType RxPdus[2];
} FrTpMultipleConfigLayoutType;
/*
 * MISRA RULE 87 VIOLATION:
 * memory abstraction defined by AUTOSAR requires inclusion of MemMap.h within code fragments.
 */
#define FRTP_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

extern const FrTpMultipleConfigLayoutType FRTP_CONFIG_NAME;
/*
 * MISRA RULE 87 VIOLATION:
 * memory abstraction defined by AUTOSAR requires inclusion of MemMap.h within code fragments.
 */
#define FRTP_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"


#endif /* _FRTP_PBCFG_H_ */


/*
 * = eof ======================================================================
 */
