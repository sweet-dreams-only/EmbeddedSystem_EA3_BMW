/*************************************************************************************
*   FILE:           GCP_config.h
*
*   DESCRIPTION:    Configure GCP with variable maximum frame size for T1
*
*   $Author: nick $
*
*   $Revision: 14780 $
*
*   $URL: https://gliwa.com/svn/repos/T1target/trunk/src/GCP/N/src/hdr/GCP_config.h $
*
*   Copyright:      Gliwa GmbH | know- how in embedded software
*                   Weilheim i.OB.
*                   All rights reserved
*************************************************************************************/

#ifndef GCP_CONFIG_H_
#define GCP_CONFIG_H_

#include "T1_AppInterface.h"

#ifdef T1_DGNINTERFACE
/*----------------------------------------------------------------------------------*/
/*--- header includes --------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

#include "T1_baseInterface.h"


/*----------------------------------------------------------------------------------*/
/*----------------------- target specific macros -----------------------------------*/
/*----------------------------------------------------------------------------------*/

#if defined T1_CPU32BIT
#   define GCP_CPU32BIT
#elif defined T1_CPU16BIT
#   define GCP_CPU16BIT
#elif defined T1_CPU8BIT
#   define GCP_CPU8BIT
#else
#   error T1_CPU<n>BIT not defined
#endif

#if defined T1_LITTLE_ENDIAN
#   define GCP_LITTLE_ENDIAN                (1)
#endif

#define GCP_FAR                             T1_FAR
#define GCP_FARPTR                          T1_FARPTR
#define GCP_CODE                            T1_CODE
#define GCP_SEC_NO_INIT_32                  T1_SEC_NO_INIT_32
#define GCP_SEC_CONST_32                    T1_SEC_CONST_32

#endif /* T1_DGNINTERFACE */

#endif /* GCP_CONFIG_H_ */
