
/* --------{ EB Automotive C Source File }-------- */
#ifndef IPDUM_LCFG_H
#define IPDUM_LCFG_H

/*==================[includes]==============================================*/

#include <IpduM.h>                  /* Module interface */
#include <IpduM_Types.h>            /* Module types */

/*==================[macros]================================================*/

/**
 * Size of internal Ipdum data in units of bytes (static memory
 * allocation) - Memory required by post-build config must be smaller
 * than this constant
 */

#define IPDUM_DATA_MEM_SIZE \
    (((uint32)sizeof(Ipdum_TxDataType) * 2U) + ((uint32)sizeof(Ipdum_QueueEntry) * 0U) + 66U)

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IPDUM_LCFG_H */
/*==================[end of file]===========================================*/
