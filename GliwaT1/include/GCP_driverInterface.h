/*************************************************************************************
*   FILE:           GCP_driverInterface.h
*
*   DESCRIPTION:    Included by the the communications driver layer only.
*
*   $Author: nick $
*
*   $Revision: 14073 $
*
*   $URL: https://gliwa.com/svn/repos/GliwaCommunicationProtocol/trunk/SW/target/src/GCP_driverInterface.h $
*
*   Copyright:      Gliwa GmbH | know- how in embedded software
*                   Weilheim i.OB.
*                   All rights reserved
*************************************************************************************/

#ifndef GCP_DRIVERINTERFACE_H_
#define GCP_DRIVERINTERFACE_H_ (1)

#include "T1_AppInterface.h"

#ifdef T1_DGNINTERFACE

/*----------------------------------------------------------------------------------*/
/*--- header includes I ------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#include "GCP_sharedInterface.h"
#include "T1_AppInterface_Cfg.h"

#define GCP_MAX_RX_FRAME_BYTES		32
#define GCP_MAX_TX_FRAME_BYTES		32
/*----------------------------------------------------------------------------------*/
/*--- consistency checks -----------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#if defined GCP_ALL_16BIT
#   if 0 != (GCP_MAX_TX_FRAME_BYTES & 1)
#       error GCP_ALL_16BIT incompatible with odd valued GCP_MAX_TX_FRAME_BYTES
#   endif
#   if 0 != (GCP_MAX_RX_FRAME_BYTES & 1)
#       error GCP_ALL_16BIT incompatible with odd valued GCP_MAX_RX_FRAME_BYTES
#   endif
#endif /* defined GCP_ALL_16BIT */

#if ! defined GCP_VAR_MAX_TX_FRAME_BYTES
#   if (1 != GCP_MAX_TX_FRAME_BYTES) && (2 != GCP_MAX_TX_FRAME_BYTES) && (4 != GCP_MAX_TX_FRAME_BYTES) && (8 != GCP_MAX_TX_FRAME_BYTES)
#       if defined GCP_TX_FRAME_PASS_BY_VALUE
#           error GCP_TX_FRAME_PASS_BY_VALUE incompatible with GCP_MAX_TX_FRAME_BYTES
#       endif
#   endif /* (1 != GCP_MAX_TX_FRAME_BYTES) && (2 != GCP_MAX_TX_FRAME_BYTES) && (4 != GCP_MAX_TX_FRAME_BYTES) && (8 != GCP_MAX_TX_FRAME_BYTES) */
#endif /* defined GCP_VAR_MAX_TX_FRAME_BYTES */

#if ! defined GCP_VAR_MAX_RX_FRAME_BYTES
#   if (1 != GCP_MAX_RX_FRAME_BYTES) && (2 != GCP_MAX_RX_FRAME_BYTES) && (4 != GCP_MAX_RX_FRAME_BYTES) && (8 != GCP_MAX_RX_FRAME_BYTES)
#       if defined GCP_RX_FRAME_PASS_BY_VALUE
#           error GCP_RX_FRAME_PASS_BY_VALUE incompatible with GCP_MAX_RX_FRAME_BYTES
#       endif
#   endif /* (1 != GCP_MAX_RX_FRAME_BYTES) && (2 != GCP_MAX_RX_FRAME_BYTES) && (4 != GCP_MAX_RX_FRAME_BYTES) && (8 != GCP_MAX_RX_FRAME_BYTES) */
#endif /* defined GCP_VAR_MAX_RX_FRAME_BYTES */

/*----------------------------------------------------------------------------------*/
/*--- type definitions -------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#if ! defined GCP_VAR_MAX_TX_FRAME_BYTES && ! defined GCP_VAR_MAX_RX_FRAME_BYTES
#   if     (defined GCP_TX_FRAME_PASS_BY_VALUE && (8 == GCP_MAX_TX_FRAME_BYTES)) \
        || (defined GCP_RX_FRAME_PASS_BY_VALUE && (8 == GCP_MAX_RX_FRAME_BYTES))
typedef unsigned long long      GCP_uint64_t;
#   endif
#endif /* ! defined GCP_VAR_MAX_TX_FRAME_BYTES && ! defined GCP_VAR_MAX_RX_FRAME_BYTES */

#if defined GCP_TX_FRAME_PASS_BY_VALUE
#   if 1 == GCP_MAX_TX_FRAME_BYTES
typedef GCP_uint8_t     GCP_txFrameInt_t;
#   elif 2 == GCP_MAX_TX_FRAME_BYTES
typedef GCP_uint16_t    GCP_txFrameInt_t;
#   elif 4 == GCP_MAX_TX_FRAME_BYTES
typedef GCP_uint32_t    GCP_txFrameInt_t;
#   elif 8 == GCP_MAX_TX_FRAME_BYTES
typedef GCP_uint64_t    GCP_txFrameInt_t;
#   endif
#endif /* defined GCP_TX_FRAME_PASS_BY_VALUE */

typedef union
{
#if defined GCP_VAR_MAX_TX_FRAME_BYTES && defined GCP_LIB_BUILD
    GCP_uint8_t                 u8[GCP_STD_MESSAGE_BYTES];
#else /* ! defined GCP_VAR_MAX_TX_FRAME_BYTES */
    GCP_uint8_t                 u8[GCP_MAX_TX_FRAME_BYTES];
#   if ! defined GCP_VAR_MAX_TX_FRAME_BYTES
#       if GCP_MAX_TX_FRAME_BYTES >= 2
    GCP_uint16_t                u16[GCP_MAX_TX_FRAME_BYTES/2];
#       endif /* GCP_MAX_TX_FRAME_BYTES >= 2 */
#       if GCP_MAX_TX_FRAME_BYTES >= 4
    GCP_uint32_t                u32[GCP_MAX_TX_FRAME_BYTES/4];
#       endif /* GCP_MAX_TX_FRAME_BYTES >= 4 */
#   endif /* defined GCP_VAR_MAX_TX_FRAME_BYTES */
#endif /* defined GCP_VAR_MAX_TX_FRAME_BYTES */
#if defined GCP_TX_FRAME_PASS_BY_VALUE
    GCP_txFrameInt_t            uInt;
#endif /* defined GCP_TX_FRAME_PASS_BY_VALUE */
}
GCP_txFrame_t;

#if defined GCP_RX_FRAME_PASS_BY_VALUE
#   if 1 == GCP_MAX_RX_FRAME_BYTES
typedef GCP_uint8_t     GCP_rxFrameInt_t;
#   elif 2 == GCP_MAX_RX_FRAME_BYTES
typedef GCP_uint16_t    GCP_rxFrameInt_t;
#   elif 4 == GCP_MAX_RX_FRAME_BYTES
typedef GCP_uint32_t    GCP_rxFrameInt_t;
#   elif 8 == GCP_MAX_RX_FRAME_BYTES
typedef GCP_uint64_t    GCP_rxFrameInt_t;
#   endif
#endif /* defined GCP_RX_FRAME_PASS_BY_VALUE */

typedef union
{
#if defined GCP_VAR_MAX_RX_FRAME_BYTES && defined GCP_LIB_BUILD
    GCP_uint8_t                 u8[GCP_STD_MESSAGE_BYTES];
#else /* ! defined GCP_VAR_MAX_RX_FRAME_BYTES */
    GCP_uint8_t                 u8[GCP_MAX_RX_FRAME_BYTES];
#   if ! defined GCP_VAR_MAX_RX_FRAME_BYTES
#       if GCP_MAX_RX_FRAME_BYTES >= 2
    GCP_uint16_t                u16[GCP_MAX_RX_FRAME_BYTES/2];
#       endif /* GCP_MAX_RX_FRAME_BYTES >= 2 */
#       if GCP_MAX_RX_FRAME_BYTES >= 4
    GCP_uint32_t                u32[GCP_MAX_RX_FRAME_BYTES/4];
#       endif /* GCP_MAX_RX_FRAME_BYTES >= 4 */
#   endif /* defined GCP_VAR_MAX_RX_FRAME_BYTES */
#endif /* defined GCP_VAR_MAX_RX_FRAME_BYTES */
#if defined GCP_RX_FRAME_PASS_BY_VALUE
    GCP_rxFrameInt_t            uInt;
#endif /* defined GCP_RX_FRAME_PASS_BY_VALUE */
}
GCP_rxFrame_t;

/*----------------------------------------------------------------------------------*/
/*--- forward declaration of low level communication layer transmit function -------*/
/*----------------------------------------------------------------------------------*/

#include "GCP_startCode.h"


/*----------------------------------------------------------------------------------*/
/*--- forward declaration of API functions -----------------------------------------*/
/*----------------------------------------------------------------------------------*/

GCP_EXTERN GCP_error_t GCP_CODE GCP_RxHandler(
#if defined GCP_RX_FRAME_PASS_BY_VALUE
                                        GCP_rxFrameInt_t frame
#else /* ! defined GCP_RX_FRAME_PASS_BY_VALUE */
                                        GCP_rxFrame_t const *pFrame
#endif /* defined GCP_RX_FRAME_PASS_BY_VALUE */
#if defined GCP_VAR_MAX_RX_FRAME_BYTES
                                        , GCP_dataLength_t len
#elif GCP_MAX_RX_FRAME_BYTES != GCP_MIN_RX_FRAME_BYTES
                                        , GCP_dataLength_t len
#endif
                                                                    );

/*----------------------------------------------------------------------------------*/
/*--- forward declaration of callouts ----------------------------------------------*/
/*----------------------------------------------------------------------------------*/

GCP_EXTERN GCP_txFrame_t * GCP_CODE GCP_TxBufferRequest( void );

#include "GCP_stopCode.h"

#endif /* T1_DGNINTERFACE */

#endif /* GCP_DRIVERINTERFACE_H_ */
