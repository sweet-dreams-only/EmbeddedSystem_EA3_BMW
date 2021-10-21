/* --------{ EB Automotive C Source File }-------- */

/*==================[inclusions]============================================*/

#include <Std_Types.h>           /* AUTOSAR standard types */
#include <IpduM_Lcfg.h>          /* Generated configuration */
#include <IpduM_Int.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

#define IPDUM_DATA_MEM_SIZE_32BIT_WORDS \
    ((IPDUM_DATA_MEM_SIZE + (uint32)sizeof(uint32) - 1) / (uint32)sizeof(uint32))

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

#define IPDUM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"

/**
 * Internal memory statically allocated upon link-time. - Size depends on
 * post build configuration => memory requirements of post build config
 * must be smaller than IPDUM_DATA_MEM_SIZE in order to avoide buffer
 * overflows. - Memory is 32-bit aligned in oder to enable 32 Bit accesses
 * to memory
 */
IPDUM_STATIC VAR(uint32, IPDUM_VAR_NOINIT) Ipdum_DataMem[IPDUM_DATA_MEM_SIZE_32BIT_WORDS];

#define IPDUM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h"


/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

CONSTP2VAR(uint8, IPDUM_CONST, IPDUM_VAR_NOINIT) Ipdum_gDataMemPtr = (CONSTP2VAR(uint8, IPDUM_CONST, IPDUM_VAR)) Ipdum_DataMem;

#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
