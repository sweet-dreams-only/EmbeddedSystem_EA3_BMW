/*************************************************************************************
*   FILE:           GCP_sharedInterface.h
*
*   DESCRIPTION:    Included by the communications driver layer.
*                   It contains common types.
*                   This version is provided for external use with a GCP library.
*
*   $Author: nick $
*
*   $Revision: 11981 $
*
*   $URL: https://gliwa.com/svn/repos/T1target/trunk/src/GCP/N/src/hdr/GCP_sharedInterface.h $
*
*   Copyright:      Gliwa GmbH | know- how in embedded software
*                   Weilheim i.OB.
*                   All rights reserved
*************************************************************************************/

#ifndef GCP_SHAREDINTERFACE_H_
#define GCP_SHAREDINTERFACE_H_ (1)

#include "T1_AppInterface.h"

#ifdef T1_DGNINTERFACE

/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#include "GCP_config.h"

/*----------------------------------------------------------------------------------*/
/*--- macros -----------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#ifndef GCP_EXTERN
#   if defined __cplusplus
#       define GCP_EXTERN       extern "C"
#   else
#       define GCP_EXTERN       extern
#   endif
#endif

#ifndef GCP_NULL
#   define GCP_NULL             ((void GCP_FARPTR)0)
#endif

/* Status return codes */
#define GCP_OK                  (0x00u)
#define GCP_TX_IN_PROGRESS      (0x01u)
#define GCP_TX_WAIT_RESPONSE    (0x02u)
#define GCP_TX_RETRY_FRAME      (0x03u)
#define GCP_RX_REPEAT_FRAME     (0x04u)
/* Values greater than this are errors that will call ErrorCallback */
#define GCP_TX_TIMEOUT          (0xE0u)
#define GCP_RX_TIMEOUT          (0xE1u)
#define GCP_RX_CHKSUM_ERR       (0xE2u)

/*----------------------------------------------------------------------------------*/
/*--- type definitions -------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

/* Platform independent */
typedef unsigned char           GCP_uint8_t;
typedef unsigned short          GCP_uint16_t;
typedef unsigned long           GCP_uint32_t;

#if defined GCP_CPU8BIT
typedef GCP_uint8_t             GCP_uint8Least_t;
typedef GCP_uint16_t            GCP_uint16Least_t;
#elif defined GCP_CPU16BIT
typedef GCP_uint16_t            GCP_uint8Least_t;
typedef GCP_uint16_t            GCP_uint16Least_t;
#elif defined GCP_CPU32BIT
typedef GCP_uint32_t            GCP_uint8Least_t;
typedef GCP_uint32_t            GCP_uint16Least_t;
#endif

typedef GCP_uint16_t            GCP_timeoutCtr_t;

typedef GCP_uint8_t             GCP_msgId_t;
typedef GCP_uint16_t            GCP_dataLength_t;

typedef GCP_uint8Least_t        GCP_error_t;

#endif /* T1_DGNINTERFACE */

#endif /* GCP_SHAREDINTERFACE_H_ */
