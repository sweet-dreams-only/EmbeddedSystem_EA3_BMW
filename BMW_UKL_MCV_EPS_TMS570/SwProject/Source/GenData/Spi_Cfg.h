/*============================================================================
 Copyright (c) 2011 by Vctr Informatik GmbH.    All rights reserved.

 This software is copyright protected and proprietary to Vctr Informatik GmbH.
 Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 All other rights remain with Vctr Informatik GmbH.

 ------------------------------------------------------------------------------
 MICROSAR Module SPI - Submodule Cfg (configuration)

 Project:    EPS.ecuc
 Generated:  2014-11-04 05:06 pm
 License:   Nxtr Automotive Corporation (2502600608)
 
    This file is generated by DaVinci Configurator Pro - DAVINCICFG.EXE V4.0.67.0.
    Do not modify this file, otherwise the software may behave in unexpected way.
 ----------------------------------------------------------------------------

 Module Description:
 Configuration Header File.
 ============================================================================*/

/* Do not modify the following parts.                                       */

#ifndef SPI_CFG_H
#define SPI_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/*<T_SPI_CFG_INCLUDE_IRQ>*/
#include "SchM_Spi.h"
#include "Os.h"
/*</T_SPI_CFG_INCLUDE_IRQ>*/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define SPI_CFG_MAJOR_VERSION    (5)
#define SPI_CFG_MINOR_VERSION    (2)
#define SPI_CFG_PATCH_VERSION    (0)

/* Compile switch to enable /disable the Spi_GetVersionInfo function */
/*<T_SPI_VERSION_INFO_API/>*/ 
#define SPI_VERSION_INFO_API   (STD_OFF)
/* Compile switch to enable /disable the Spi_Cancel function */
/*<T_SPI_CANCEL_API/>*/ 
#define SPI_CANCEL_API         (STD_OFF)
/* Compile switch to enable /disable the Spi_GetJobResult function */
/*<T_SPI_HW_STATUS_API/>*/ 
#define SPI_HW_STATUS_API      (STD_OFF)

/* Pre-processor switch for enabling the development error detection and reporting */
/*<T_SPI_DEV_ERROR_DETECT/>*/ 
#define SPI_DEV_ERROR_DETECT   (STD_OFF)
#if (SPI_DEV_ERROR_DETECT == STD_ON)
/*<T_SPI_PARAM_CHK/>*/ 
    #define SPI_PARAM_CHK          (STD_ON)
    #if (SPI_PARAM_CHK == STD_ON)
        /*<T_SPI_PARAM_CHK_CONFIG/>*/ 
        #define SPI_PARAM_CHK_CONFIG   (STD_ON)
        /*<T_SPI_PARAM_CHK_CHANNEL/>*/ 
        #define SPI_PARAM_CHK_CHANNEL  (STD_ON)
        /*<T_SPI_PARAM_CHK_JOB/>*/ 
        #define SPI_PARAM_CHK_JOB      (STD_ON)
        /*<T_SPI_PARAM_CHK_SEQ/>*/ 
        #define SPI_PARAM_CHK_SEQ      (STD_ON)
        /*<T_SPI_PARAM_CHK_LENGTH/>*/ 
        #define SPI_PARAM_CHK_LENGTH   (STD_ON)
        /*<T_SPI_PARAM_CHK_BUFFER/>*/ 
        #define SPI_PARAM_CHK_BUFFER   (STD_ON)
        /*<T_SPI_PARAM_CHK_ALIGNMENT/>*/ 
        #define SPI_PARAM_CHK_ALIGNMENT   (STD_ON)
        /*<T_SPI_PARAM_CHK_VERSION/>*/ 
        #define SPI_PARAM_CHK_VERSION  (STD_ON)
        /*<T_SPI_PARAM_CHK_UNIT/>*/ 
        #define SPI_PARAM_CHK_UNIT     (STD_ON)
    #else
        #define SPI_PARAM_CHK_CONFIG   (STD_OFF)
        #define SPI_PARAM_CHK_CHANNEL  (STD_OFF)
        #define SPI_PARAM_CHK_JOB      (STD_OFF)
        #define SPI_PARAM_CHK_SEQ      (STD_OFF)
        #define SPI_PARAM_CHK_LENGTH   (STD_OFF)
        #define SPI_PARAM_CHK_VERSION  (STD_OFF)
        #define SPI_PARAM_CHK_UNIT     (STD_OFF)
    #endif
    /*<T_SPI_CHK_MODULE_INIT/>*/ 
        #define SPI_CHK_MODULE_INIT    (STD_ON)
    /*<T_SPI_CHK_SEQ_PENDING/>*/ 
        #define SPI_CHK_SEQ_PENDING    (STD_ON)
    /*<T_SPI_CHK_MODULE_ALREADY_INITIALIZED/>*/ 
        #define SPI_CHK_MODULE_ALREADY_INITIALIZED    (STD_ON)
    /*<T_SPI_CHK_SEQ_PROCESSING/>*/ 
        #define SPI_CHK_SEQ_PROCESSING (STD_ON)
    /* include DET as configured */
    /*<T_SPI_DET_ERROR_REPORTING/>*/ 
    #define SPI_DET_ERROR_REPORTING    (STD_ON)
    #if (SPI_DET_ERROR_REPORTING == STD_ON)
    /*<T_SPI_DET_INCLUDE_FILE/>*/ 
    #include "Det.h"
    /*<T_SPI_DET_ERRORHOOK/>*/ 
    #define Spi_DetReportError(SpiApiId, SpiErrorId)\
    (Det_ReportError(SPI_MODULE_ID, SPI_INSTANCE_ID, SpiApiId, SpiErrorId))
    #else
        #define Spi_DetReportError(SpiApiId, SpiErrorId)
    #endif
#endif


/* include DEM as configured or if available */
/*<T_SPI_DEM_ERROR_REPORTING/>*/ 
#define SPI_DEM_ERROR_REPORTING    (STD_OFF)
#if (SPI_DEM_ERROR_REPORTING == STD_ON)
/*<T_SPI_DEM_INCLUDE_FILE>*/
#include "Dem.h"
/*</T_SPI_DEM_INCLUDE_FILE>*/
/*<T_SPI_DEM_ERRORHOOK/>*/ 
#define Spi_DemReportError(SpiEventId, SpiEventStatus)\
    (Dem_ReportErrorStatus(SpiEventId, SpiEventStatus))
#else
    /* create a stub */
    #define Spi_DemReportError(SpiEventId, SpiEventStatus)
#endif

/* include upper layer module call backs as configured */
/*<T_SPI_CBK_INCLUDE_FILE>*/
/*</T_SPI_CBK_INCLUDE_FILE>*/

/*<T_SPI_IRQ_NOTIFICATION_DECL/>*/ 
#define SPI_CFG_ISR_TYPE    (SPI_ISR_CAT2)

/*---- defines for max allowed channels, jobs, sequences ------------------------------------------------------------*/
/*<T_SPI_MAX_CHANNEL/>*/  
#define SPI_MAX_CHANNEL    (1u)
/*<T_SPI_MAX_JOB/>*/ 
#define SPI_MAX_JOB    (1u)
/*<T_SPI_MAX_SEQUENCE/>*/ 
#define SPI_MAX_SEQUENCE    (1u)
/*<T_SPI_EXTERNALDEVICE_CONTAINER_NR/>*/ 
#define SPI_MAX_EXTDEVICE    (1u)

/*--------- scaleability levels --------------------------------------------------------------------------------------*/
/*<T_SPI_LEVEL_DELIVERED/>*/ 
#define SPI_SCALEABILITY    (1u)
/*<T_SPI_CHANNEL_BUFFERS_ALLOWED/>*/ 
#define SPI_CHANNELBUFFERS    (1u)

/*--------- define for runtime mapping -------------------------------------------------------------------------------*/
/*<T_SPI_CFG_EXTERN>*/
#define SPI_RUNTIME    (&SpiRuntime)
/*</T_SPI_CFG_EXTERN>*/

/*<T_SPI_MAX_H_W_UNIT/>*/ 
#define SPI_MAX_HWUNIT    (2u)

/* definitions of channel, device and job enums */
    /*<T_SPI_NR_OF_CHANNEL_DEF>*/
#define SPI_FRSTATUS_CH    (0u)
/*</T_SPI_NR_OF_CHANNEL_DEF>*/

    /*<T_SPI_NR_OF_DEVICE_DEF>*/
#define TJA1082    (0u)
/*</T_SPI_NR_OF_DEVICE_DEF>*/

    /*<T_SPI_NR_OF_JOB_DEF>*/
#define SPI_FRSTATUS_JOB    (0u)
/*</T_SPI_NR_OF_JOB_DEF>*/

    /*<T_SPI_NR_OF_SEQ_DEF>*/
#define SPI_FRSTATUS_SEQ    (0u)
/*</T_SPI_NR_OF_SEQ_DEF>*/

#define SPI_HARDWAREUNIT0_ACTIVE    (STD_OFF)
#define SPI_HARDWAREUNIT1_ACTIVE    (STD_OFF)
#define SPI_HARDWAREUNIT2_ACTIVE    (STD_OFF)
#define SPI_HARDWAREUNIT3_ACTIVE    (STD_OFF)
#define SPI_HARDWAREUNIT4_ACTIVE    (STD_OFF)

    /*<T_SPI_NR_OF_HW_UNIT_ACTIVE_DEF>*/
#undef SPI_HARDWAREUNIT0_ACTIVE
#define SPI_HARDWAREUNIT0_ACTIVE   (STD_ON)
/*</T_SPI_NR_OF_HW_UNIT_ACTIVE_DEF>*/

#if ( (defined SPI_IRQ_SOURCE) || \
      (defined SPI_SOURCE )    || \
      (defined SPI_HW_SOURCE ) || \
      (defined SPI_DLC_SOURCE) || \
      (defined SPI_DLCDMA_SOURCE) || \
      (defined SPI_PBCFG_SOURCE)  )

#define SPI_HARDWAREUNIT_USE_STD       (STD_OFF)
#define SPI_HARDWAREUNIT_USE_RAM       (STD_OFF)
#define SPI_HARDWAREUNIT_USE_STDDMA    (STD_OFF)

    /*<T_SPI_NR_OF_HW_UNIT_FEATURE_DEF>*/
#undef  SPI_HARDWAREUNIT_USE_RAM
#define SPI_HARDWAREUNIT_USE_RAM      (STD_ON)
/*</T_SPI_NR_OF_HW_UNIT_FEATURE_DEF>*/

/*<T_SPI_SRA_ENABLED/>*/ 
#define SPI_SPECIAL_REGISTER_ACCESS_ENABLED    (STD_ON)

/*<T_SPI_SRA_ONLY_FOR_WRITE/>*/ 
#define SPI_SPECIAL_REGISTER_ACCESS_ONLY_FOR_WRITE    (STD_ON)

/*<T_SPI_SRA_ONLY_FOR_PRIVILEGED_MODE/>*/ 
#define SPI_SPECIAL_REGISTER_ACCESS_ONLY_FOR_PRIVILEGED_MODE    ((STD_ON))

/*<T_SPI_SRA_NOT_IN_INIT/>*/ 
#define SPI_SPECIAL_REGISTER_ACCESS_NOT_IN_INIT    ((STD_OFF))


#ifndef OS_MEM_AREA_SPI_REG1
#define OS_MEM_AREA_SPI_REG1     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_REG2
#define OS_MEM_AREA_SPI_REG2     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_REG3
#define OS_MEM_AREA_SPI_REG3     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_REG4
#define OS_MEM_AREA_SPI_REG4     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_REG5
#define OS_MEM_AREA_SPI_REG5     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_RAM1
#define OS_MEM_AREA_SPI_RAM1     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_RAM2
#define OS_MEM_AREA_SPI_RAM2     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_RAM3
#define OS_MEM_AREA_SPI_RAM3     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_RAM4
#define OS_MEM_AREA_SPI_RAM4     (0x0u)
#endif
#ifndef OS_MEM_AREA_SPI_RAM5
#define OS_MEM_AREA_SPI_RAM5     (0x0u)
#endif
#ifndef OS_MEM_AREA_DMA_REG
#define OS_MEM_AREA_DMA_REG      (0x0u)
#endif
#ifndef OS_MEM_AREA_DMA_RAM
#define OS_MEM_AREA_DMA_RAM      (0x0u)
#endif
#ifndef OS_MEM_AREA_VIM_REG
#define OS_MEM_AREA_VIM_REG      (0x0u)
#endif

#if (SPI_SPECIAL_REGISTER_ACCESS_ENABLED == STD_ON)
/* OS safety accesses */
/* write accesses */
#define SPI_OS_W_32BIT(reg, val, area)   (osWritePeripheral32 ((area), (uint32)(&reg),  (uint32)(val)                ))
#define SPI_OS_S_32BIT(reg, val, area)   (osModifyPeripheral32((area), (uint32)(&reg), ~(uint32)0    , (uint32)(val) ))
#define SPI_OS_C_32BIT(reg, val, area)   (osModifyPeripheral32((area), (uint32)(&reg), ~(uint32)(val), (uint32)0     ))
#define SPI_OS_W_16BIT(reg, val, area)   (osWritePeripheral16 ((area), (uint32)(&reg),  (uint32)(val)                ))
#define SPI_OS_S_16BIT(reg, val, area)   (osModifyPeripheral16((area), (uint32)(&reg), ~(uint32)0,     (uint32)(val) ))
#define SPI_OS_C_16BIT(reg, val, area)   (osModifyPeripheral16((area), (uint32)(&reg), ~(uint32)(val), (uint32)0     ))
#define SPI_OS_W_8BIT(reg, val, area)    (osWritePeripheral8  ((area), (uint32)(&reg),  (uint32)(val)                ))
/* read accesses */
#define SPI_OS_R_32BIT(var, reg,area)        ((var) = (osReadPeripheral32((area), (uint32)(&reg))))
#define SPI_OS_G_32BIT(var, reg, mask, area)  (var) = (osReadPeripheral32((area), (uint32)(&reg)));\
                                              (var) = ((var) & (uint32)(mask))
#define SPI_OS_R_16BIT(var, reg, area)       ((var) = (osReadPeripheral16((area), (uint32)(&reg))))
#define SPI_OS_G_16BIT(var, reg, mask, area)  (var) = (osReadPeripheral16((area), (uint32)(&reg)));\
                                              (var) = ((var) & (uint32)(mask))
#define SPI_OS_R_8BIT(var, reg, area)        ((var) = (osReadPeripheral8( (area), (uint32)(&reg))))
#endif

/* Standard accesses */
/* write accesses */
#define SPI_W_32BIT(reg, val, area)       ((reg)  = ( (uint32)(val) | ((area) ^ (area))))
#define SPI_S_32BIT(reg, val, area)       ((reg) |= ( (uint32)(val) | ((area) ^ (area))))
#define SPI_C_32BIT(reg, val, area)       ((reg) &= (~(uint32)(val) | ((area) ^ (area))))
#define SPI_W_16BIT(reg, val, area)       ((reg)  = ( (uint16)(val) | ((area) ^ (area))))
#define SPI_S_16BIT(reg, val, area)       ((reg) |= ( (uint16)(val) | ((area) ^ (area))))
#define SPI_C_16BIT(reg, val, area)       ((reg) &= (~(uint16)(val) | ((area) ^ (area))))
#define SPI_W_8BIT(reg, val, area)        ((reg)  = ( (uint32)(val) | ((area) ^ (area))))
/* read accesses 32bit */
#define SPI_R_32BIT(var, reg, area)       ((var)  = (((uint32)(reg)                 ) | ((area) ^ (area))))
#define SPI_G_32BIT(var, reg, mask, area) ((var)  = (((uint32)(reg) & (uint32)(mask)) | ((area) ^ (area))))
#define SPI_R_16BIT(var, reg, area)       ((var)  = (((uint16)(reg)                 ) | ((area) ^ (area))))
#define SPI_G_16BIT(var, reg, mask, area) ((var)  = (((uint16)(reg) & (uint32)(mask)) | ((area) ^ (area))))
#define SPI_R_8BIT(var, reg, area)        ((var)  = (((uint8)(reg)                  ) | ((area) ^ (area))))

#if (SPI_SPECIAL_REGISTER_ACCESS_ENABLED == STD_ON)
    #if (SPI_SPECIAL_REGISTER_ACCESS_NOT_IN_INIT == STD_ON)
        #if (SPI_SPECIAL_REGISTER_ACCESS_ONLY_FOR_PRIVILEGED_MODE == STD_ON)
            /* write accesses user */
            #define SPI_REG_W_USER_32BIT(reg, val, area)                 SPI_W_32BIT(reg, val, area)
            #define SPI_REG_S_USER_32BIT(reg, val, area)                 SPI_S_32BIT(reg, val, area)
            #define SPI_REG_C_USER_32BIT(reg, val, area)                 SPI_C_32BIT(reg, val, area)
            #define SPI_REG_W_USER_16BIT(reg, val, area)                 SPI_W_16BIT(reg, val, area)
            #define SPI_REG_S_USER_16BIT(reg, val, area)                 SPI_S_16BIT(reg, val, area)
            #define SPI_REG_C_USER_16BIT(reg, val, area)                 SPI_C_16BIT(reg, val, area)
            #define SPI_REG_W_USER_8BIT(reg, val, area)                  SPI_W_8BIT(reg, val, area)
        #else
            /* write accesses user 32bit OS protected */
            #define SPI_REG_W_USER_32BIT(reg, val, area)                 SPI_OS_W_32BIT(reg, val, area)
            #define SPI_REG_S_USER_32BIT(reg, val, area)                 SPI_OS_S_32BIT(reg, val, area)
            #define SPI_REG_C_USER_32BIT(reg, val, area)                 SPI_OS_C_32BIT(reg, val, area)
            #define SPI_REG_W_USER_16BIT(reg, val, area)                 SPI_OS_W_16BIT(reg, val, area)
            #define SPI_REG_S_USER_16BIT(reg, val, area)                 SPI_OS_S_16BIT(reg, val, area)
            #define SPI_REG_C_USER_16BIT(reg, val, area)                 SPI_OS_C_16BIT(reg, val, area)
            #define SPI_REG_W_USER_8BIT(reg, val, area)                  SPI_W_8BIT(reg, val, area)
        #endif
        /* write accesses user INIT */
        #define SPI_REG_W_USER_32BIT_INIT(reg, val, area)                SPI_W_32BIT(reg, val, area)
        #define SPI_REG_S_USER_32BIT_INIT(reg, val, area)                SPI_S_32BIT(reg, val, area)
        #define SPI_REG_C_USER_32BIT_INIT(reg, val, area)                SPI_C_32BIT(reg, val, area)
        #define SPI_REG_W_USER_16BIT_INIT(reg, val, area)                SPI_W_16BIT(reg, val, area)
        #define SPI_REG_S_USER_16BIT_INIT(reg, val, area)                SPI_S_16BIT(reg, val, area)
        #define SPI_REG_C_USER_16BIT_INIT(reg, val, area)                SPI_C_16BIT(reg, val, area)
        #define SPI_REG_W_USER_8BIT_INIT(reg, val, area)                 SPI_W_8BIT(reg, val, area)

        /* write accesses supervisor INIT */
        #define SPI_REG_W_PRIV_32BIT_INIT(reg, val, area)                SPI_W_32BIT(reg, val, area)
        #define SPI_REG_S_PRIV_32BIT_INIT(reg, val, area)                SPI_S_32BIT(reg, val, area)
        #define SPI_REG_C_PRIV_32BIT_INIT(reg, val, area)                SPI_C_32BIT(reg, val, area)
        #define SPI_REG_W_PRIV_16BIT_INIT(reg, val, area)                SPI_W_16BIT(reg, val, area)
        #define SPI_REG_S_PRIV_16BIT_INIT(reg, val, area)                SPI_S_16BIT(reg, val, area)
        #define SPI_REG_C_PRIV_16BIT_INIT(reg, val, area)                SPI_C_16BIT(reg, val, area)
        #define SPI_REG_W_PRIV_8BIT_INIT(reg, val, area)                 SPI_W_8BIT(reg, val, area)
    #else
        #if (SPI_SPECIAL_REGISTER_ACCESS_ONLY_FOR_PRIVILEGED_MODE == STD_ON)
            /* write accesses user INIT */
            #define SPI_REG_W_USER_32BIT_INIT(reg, val, area)            SPI_W_32BIT(reg, val, area)
            #define SPI_REG_S_USER_32BIT_INIT(reg, val, area)            SPI_S_32BIT(reg, val, area)
            #define SPI_REG_C_USER_32BIT_INIT(reg, val, area)            SPI_C_32BIT(reg, val, area)
            #define SPI_REG_W_USER_16BIT_INIT(reg, val, area)            SPI_W_16BIT(reg, val, area)
            #define SPI_REG_S_USER_16BIT_INIT(reg, val, area)            SPI_S_16BIT(reg, val, area)
            #define SPI_REG_C_USER_16BIT_INIT(reg, val, area)            SPI_C_16BIT(reg, val, area)
            #define SPI_REG_W_USER_8BIT_INIT(reg, val, area)             SPI_W_8BIT(reg, val, area)

            /* write accesses user */
            #define SPI_REG_W_USER_32BIT(reg, val, area)                 SPI_W_32BIT(reg, val, area)
            #define SPI_REG_S_USER_32BIT(reg, val, area)                 SPI_S_32BIT(reg, val, area)
            #define SPI_REG_C_USER_32BIT(reg, val, area)                 SPI_C_32BIT(reg, val, area)
            #define SPI_REG_W_USER_16BIT(reg, val, area)                 SPI_W_16BIT(reg, val, area)
            #define SPI_REG_S_USER_16BIT(reg, val, area)                 SPI_S_16BIT(reg, val, area)
            #define SPI_REG_C_USER_16BIT(reg, val, area)                 SPI_C_16BIT(reg, val, area)
            #define SPI_REG_W_USER_8BIT(reg, val, area)                  SPI_W_8BIT(reg, val, area)
        #else
            /* write accesses user INIT, OS protected access */
            #define SPI_REG_W_USER_32BIT_INIT(reg, val, area)            SPI_OS_W_32BIT(reg, val, area)
            #define SPI_REG_S_USER_32BIT_INIT(reg, val, area)            SPI_OS_S_32BIT(reg, val, area)
            #define SPI_REG_C_USER_32BIT_INIT(reg, val, area)            SPI_OS_C_32BIT(reg, val, area)
            #define SPI_REG_W_USER_16BIT_INIT(reg, val, area)            SPI_OS_W_16BIT(reg, val, area)
            #define SPI_REG_S_USER_16BIT_INIT(reg, val, area)            SPI_OS_S_16BIT(reg, val, area)
            #define SPI_REG_C_USER_16BIT_INIT(reg, val, area)            SPI_OS_C_16BIT(reg, val, area)
            #define SPI_REG_W_USER_8BIT_INIT(reg, val, area)             SPI_OS_W_8BIT(reg, val, area)

            /* write accesses user OS protected access*/
            #define SPI_REG_W_USER_32BIT(reg, val, area)                 SPI_OS_W_32BIT(reg, val, area)
            #define SPI_REG_S_USER_32BIT(reg, val, area)                 SPI_OS_S_32BIT(reg, val, area)
            #define SPI_REG_C_USER_32BIT(reg, val, area)                 SPI_OS_C_32BIT(reg, val, area)
            #define SPI_REG_W_USER_16BIT(reg, val, area)                 SPI_OS_W_16BIT(reg, val, area)
            #define SPI_REG_S_USER_16BIT(reg, val, area)                 SPI_OS_S_16BIT(reg, val, area)
            #define SPI_REG_C_USER_16BIT(reg, val, area)                 SPI_OS_C_16BIT(reg, val, area)
            #define SPI_REG_W_USER_8BIT(reg, val, area)                  SPI_OS_W_8BIT(reg, val, area)
        #endif
        /* write accesses supervisor INIT, OS protected access */
        #define SPI_REG_W_PRIV_32BIT_INIT(reg, val, area)                SPI_OS_W_32BIT(reg, val, area)
        #define SPI_REG_S_PRIV_32BIT_INIT(reg, val, area)                SPI_OS_S_32BIT(reg, val, area)
        #define SPI_REG_C_PRIV_32BIT_INIT(reg, val, area)                SPI_OS_C_32BIT(reg, val, area)
        #define SPI_REG_W_PRIV_16BIT_INIT(reg, val, area)                SPI_OS_W_16BIT(reg, val, area)
        #define SPI_REG_S_PRIV_16BIT_INIT(reg, val, area)                SPI_OS_S_16BIT(reg, val, area)
        #define SPI_REG_C_PRIV_16BIT_INIT(reg, val, area)                SPI_OS_C_16BIT(reg, val, area)
        #define SPI_REG_W_PRIV_8BIT_INIT(reg, val, area)                 SPI_OS_W_8BIT(reg, val, area)
    #endif
    /* write accesses privileged, OS protected access */
    #define SPI_REG_W_PRIV_32BIT(reg, val, area)                         SPI_OS_W_32BIT(reg, val, area)
    #define SPI_REG_S_PRIV_32BIT(reg, val, area)                         SPI_OS_S_32BIT(reg, val, area)
    #define SPI_REG_C_PRIV_32BIT(reg, val, area)                         SPI_OS_C_32BIT(reg, val, area)
    #define SPI_REG_W_PRIV_16BIT(reg, val, area)                         SPI_OS_W_16BIT(reg, val, area)
    #define SPI_REG_S_PRIV_16BIT(reg, val, area)                         SPI_OS_S_16BIT(reg, val, area)
    #define SPI_REG_C_PRIV_16BIT(reg, val, area)                         SPI_OS_C_16BIT(reg, val, area)
    #define SPI_REG_W_PRIV_8BIT(reg, val, area)                          SPI_OS_W_8BIT(reg, val, area)
#else
    /* write accesses user INIT */
    #define SPI_REG_W_USER_32BIT_INIT(reg, val, area)                    SPI_W_32BIT(reg, val, area)
    #define SPI_REG_S_USER_32BIT_INIT(reg, val, area)                    SPI_S_32BIT(reg, val, area)
    #define SPI_REG_C_USER_32BIT_INIT(reg, val, area)                    SPI_C_32BIT(reg, val, area)
    #define SPI_REG_W_USER_16BIT_INIT(reg, val, area)                    SPI_W_16BIT(reg, val, area)
    #define SPI_REG_S_USER_16BIT_INIT(reg, val, area)                    SPI_S_16BIT(reg, val, area)
    #define SPI_REG_C_USER_16BIT_INIT(reg, val, area)                    SPI_C_16BIT(reg, val, area)
    #define SPI_REG_W_USER_8BIT_INIT(reg, val, area)                     SPI_W_8BIT(reg, val, area)

    /* write accesses supervisor INIT */
    #define SPI_REG_W_PRIV_32BIT_INIT(reg, val, area)                    SPI_W_32BIT(reg, val, area)
    #define SPI_REG_S_PRIV_32BIT_INIT(reg, val, area)                    SPI_S_32BIT(reg, val, area)
    #define SPI_REG_C_PRIV_32BIT_INIT(reg, val, area)                    SPI_C_32BIT(reg, val, area)
    #define SPI_REG_W_PRIV_16BIT_INIT(reg, val, area)                    SPI_W_16BIT(reg, val, area)
    #define SPI_REG_S_PRIV_16BIT_INIT(reg, val, area)                    SPI_S_16BIT(reg, val, area)
    #define SPI_REG_C_PRIV_16BIT_INIT(reg, val, area)                    SPI_C_16BIT(reg, val, area)
    #define SPI_REG_W_PRIV_8BIT_INIT(reg, val, area)                     SPI_W_8BIT(reg, val, area)

    /* write accesses user */
    #define SPI_REG_W_USER_32BIT(reg, val, area)                         SPI_W_32BIT(reg, val, area)
    #define SPI_REG_S_USER_32BIT(reg, val, area)                         SPI_S_32BIT(reg, val, area)
    #define SPI_REG_C_USER_32BIT(reg, val, area)                         SPI_C_32BIT(reg, val, area)
    #define SPI_REG_W_USER_16BIT(reg, val, area)                         SPI_W_16BIT(reg, val, area)
    #define SPI_REG_S_USER_16BIT(reg, val, area)                         SPI_S_16BIT(reg, val, area)
    #define SPI_REG_C_USER_16BIT(reg, val, area)                         SPI_C_16BIT(reg, val, area)
    #define SPI_REG_W_USER_8BIT(reg, val, area)                          SPI_W_8BIT(reg, val, area)

    /* write accesses supervisor */
    #define SPI_REG_W_PRIV_32BIT(reg, val, area)                         SPI_W_32BIT(reg, val, area)
    #define SPI_REG_S_PRIV_32BIT(reg, val, area)                         SPI_S_32BIT(reg, val, area)
    #define SPI_REG_C_PRIV_32BIT(reg, val, area)                         SPI_C_32BIT(reg, val, area)
    #define SPI_REG_W_PRIV_16BIT(reg, val, area)                         SPI_W_16BIT(reg, val, area)
    #define SPI_REG_S_PRIV_16BIT(reg, val, area)                         SPI_S_16BIT(reg, val, area)
    #define SPI_REG_C_PRIV_16BIT(reg, val, area)                         SPI_C_16BIT(reg, val, area)
    #define SPI_REG_W_PRIV_8BIT(reg, val, area)                          SPI_W_8BIT(reg, val, area)
#endif

#if (SPI_SPECIAL_REGISTER_ACCESS_ENABLED == STD_ON)
    #if (SPI_SPECIAL_REGISTER_ACCESS_ONLY_FOR_WRITE == STD_ON)
        #if (SPI_SPECIAL_REGISTER_ACCESS_NOT_IN_INIT == STD_ON)
            /* read accesses supervisor init */
            #define SPI_REG_R_PRIV_32BIT_INIT(var, reg, area)            SPI_R_32BIT(var, reg, area)
            #define SPI_REG_G_PRIV_32BIT_INIT(var, reg, mask, area)      SPI_G_32BIT(var, reg, mask, area)
            #define SPI_REG_R_PRIV_16BIT_INIT(var, reg, area)            SPI_R_16BIT(var, reg, area)
            #define SPI_REG_G_PRIV_16BIT_INIT(var, reg, mask, area)      SPI_G_16BIT(var, reg, mask, area)
            #define SPI_REG_R_PRIV_8BIT_INIT(var, reg, area)             SPI_R_8BIT(var, reg, area)
        #else
            /* read accesses supervisor init, OS protected */
            #define SPI_REG_R_PRIV_32BIT_INIT(var, reg, area)            SPI_OS_R_32BIT(var, reg, area)
            #define SPI_REG_G_PRIV_32BIT_INIT(var, reg, mask, area)      SPI_OS_G_32BIT(var, reg, mask, area)
            #define SPI_REG_R_PRIV_16BIT_INIT(var, reg, area)            SPI_OS_R_16BIT(var, reg, area)
            #define SPI_REG_G_PRIV_16BIT_INIT(var, reg, mask, area)      SPI_OS_G_16BIT(var, reg, mask, area)
            #define SPI_REG_R_PRIV_8BIT_INIT(var, reg, area)             SPI_OS_R_8BIT(var, reg, area)
        #endif
        /* read accesses user init */
        #define SPI_REG_R_USER_32BIT_INIT(var, reg, area)                SPI_R_32BIT(var, reg, area)
        #define SPI_REG_G_USER_32BIT_INIT(var, reg, mask, area)          SPI_G_32BIT(var, reg, mask, area)
        #define SPI_REG_R_USER_16BIT_INIT(var, reg, area)                SPI_R_16BIT(var, reg, area)
        #define SPI_REG_G_USER_16BIT_INIT(var, reg, mask, area)          SPI_G_16BIT(var, reg, mask, area)
        #define SPI_REG_R_USER_8BIT_INIT(var, reg, area)                 SPI_R_8BIT(var, reg, area)
        /* read accesses user */
        #define SPI_REG_R_USER_32BIT(var, reg, area)                     SPI_R_32BIT(var, reg, area)
        #define SPI_REG_G_USER_32BIT(var, reg, mask, area)               SPI_G_32BIT(var, reg, mask, area)
        #define SPI_REG_R_USER_16BIT(var, reg, area)                     SPI_R_16BIT(var, reg, area)
        #define SPI_REG_G_USER_16BIT(var, reg, mask, area)               SPI_G_16BIT(var, reg, mask, area)
        #define SPI_REG_R_USER_8BIT(var, reg, area)                      SPI_R_8BIT(var, reg, area)
    #else
        #if (SPI_SPECIAL_REGISTER_ACCESS_NOT_IN_INIT == STD_ON)
            #if (SPI_SPECIAL_REGISTER_ACCESS_ONLY_FOR_PRIVILEGED_MODE == STD_ON)
                /* read accesses user */
                #define SPI_REG_R_USER_32BIT(var, reg, area)             SPI_R_32BIT(var, reg, area)
                #define SPI_REG_G_USER_32BIT(var, reg, mask, area)       SPI_G_32BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_16BIT(var, reg, area)             SPI_R_16BIT(var, reg, area)
                #define SPI_REG_G_USER_16BIT(var, reg, mask, area)       SPI_G_16BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_8BIT(var, reg, area)              SPI_R_8BIT(var, reg, area)
            #else
                /* read accesses user, OS protected */
                #define SPI_REG_R_USER_32BIT(var, reg, area)             SPI_OS_R_32BIT(var, reg, area)
                #define SPI_REG_G_USER_32BIT(var, reg, mask, area)       SPI_OS_G_32BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_16BIT(var, reg, area)             SPI_OS_R_16BIT(var, reg, area)
                #define SPI_REG_G_USER_16BIT(var, reg, mask, area)       SPI_OS_G_16BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_8BIT(var, reg, area)              SPI_OS_R_8BIT(var, reg, area)
            #endif
            /* read accesses user init */
            #define SPI_REG_R_USER_32BIT_INIT(var, reg, area)            SPI_R_32BIT(var, reg, area)
            #define SPI_REG_G_USER_32BIT_INIT(var, reg, mask, area)      SPI_G_32BIT(var, reg, mask, area)
            #define SPI_REG_R_USER_16BIT_INIT(var, reg, area)            SPI_R_16BIT(var, reg, area)
            #define SPI_REG_G_USER_16BIT_INIT(var, reg, mask, area)      SPI_G_16BIT(var, reg, mask, area)
            #define SPI_REG_R_USER_8BIT_INIT(var, reg, area)             SPI_R_8BIT(var, reg, area)
            /* read accesses supervisor init */
            #define SPI_REG_R_PRIV_32BIT_INIT(var, reg, area)            SPI_R_32BIT(var, reg, area)
            #define SPI_REG_G_PRIV_32BIT_INIT(var, reg, mask, area)      SPI_G_32BIT(var, reg, mask, area)
            #define SPI_REG_R_PRIV_16BIT_INIT(var, reg, area)            SPI_R_16BIT(var, reg, area)
            #define SPI_REG_G_PRIV_16BIT_INIT(var, reg, mask, area)      SPI_G_16BIT(var, reg, mask, area)
            #define SPI_REG_R_PRIV_8BIT_INIT(var, reg, area)             SPI_R_8BIT(var, reg, area)
        #else
            #if (SPI_SPECIAL_REGISTER_ACCESS_ONLY_FOR_PRIVILEGED_MODE == STD_ON)
                /* read accesses user init */
                #define SPI_REG_R_USER_32BIT_INIT(var, reg, area)        SPI_R_32BIT(var, reg, area)
                #define SPI_REG_G_USER_32BIT_INIT(var, reg, mask, area)  SPI_G_32BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_16BIT_INIT(var, reg, area)        SPI_R_16BIT(var, reg, area)
                #define SPI_REG_G_USER_16BIT_INIT(var, reg, mask, area)  SPI_G_16BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_8BIT_INIT(var, reg, area)         SPI_R_8BIT(var, reg, area)
                /* read accesses supervisor init */
                #define SPI_REG_R_USER_32BITT(var, reg, area)            SPI_R_32BIT(var, reg, area)
                #define SPI_REG_G_USER_32BITT(var, reg, mask, area)      SPI_G_32BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_16BITT(var, reg, area)            SPI_R_16BIT(var, reg, area)
                #define SPI_REG_G_USER_16BITT(var, reg, mask, area)      SPI_G_16BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_8BIT(var, reg, area)              SPI_R_8BIT(var, reg, area)
            #else
                /* read accesses user, OS protected */
                #define SPI_REG_R_USER_32BIT_INIT(var, reg, area)        SPI_OS_R_32BIT(var, reg, area)
                #define SPI_REG_G_USER_32BIT_INIT(var, reg, mask, area)  SPI_OS_G_32BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_16BIT_INIT(var, reg, area)        SPI_OS_R_16BIT(var, reg, area)
                #define SPI_REG_G_USER_16BIT_INIT(var, reg, mask, area)  SPI_OS_G_16BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_8BIT_INIT(var, reg, area)         SPI_OS_R_8BIT(var, reg, area)
                /* read accesses supervisor init */
                #define SPI_REG_R_USER_32BIT(var, reg, area)             SPI_OS_R_32BIT(var, reg, area)
                #define SPI_REG_G_USER_32BIT(var, reg, mask, area)       SPI_OS_G_32BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_16BIT(var, reg, area)             SPI_OS_R_16BIT(var, reg, area)
                #define SPI_REG_G_USER_16BIT(var, reg, mask, area)       SPI_OS_G_16BIT(var, reg, mask, area)
                #define SPI_REG_R_USER_8BIT(var, reg, area)              SPI_OS_R_8BIT(var, reg, area)
            #endif
            /* read accesses supervisor init, OS protected */
            #define SPI_REG_R_PRIV_32BIT_INIT(var, reg, area)            SPI_OS_R_32BIT(var, reg, area)
            #define SPI_REG_G_PRIV_32BIT_INIT(var, reg, mask, area)      SPI_OS_G_32BIT(var, reg, mask, area)
            #define SPI_REG_R_PRIV_16BIT_INIT(var, reg, area)            SPI_OS_R_16BIT(var, reg, area)
            #define SPI_REG_G_PRIV_16BIT_INIT(var, reg, mask, area)      SPI_OS_G_16BIT(var, reg, mask, area)
            #define SPI_REG_R_PRIV_8BIT_INIT(var, reg, area)             SPI_OS_R_8BIT(var, reg, area)
        #endif
    #endif
    /* read accesses supervisor, OS protected */
    #define SPI_REG_R_PRIV_32BIT(var, reg, area)                         SPI_OS_R_32BIT(var, reg, area)
    #define SPI_REG_G_PRIV_32BIT(var, reg, mask, area)                   SPI_OS_G_32BIT(var, reg, mask, area)
    #define SPI_REG_R_PRIV_16BIT(var, reg, area)                         SPI_OS_R_16BIT(var, reg, area)
    #define SPI_REG_G_PRIV_16BIT(var, reg, mask, area)                   SPI_OS_G_16BIT(var, reg, mask, area)
    #define SPI_REG_R_PRIV_8BIT(var, reg, area)                          SPI_OS_R_8BIT(var, reg, area)
#else
    /* read accesses user init */
    #define SPI_REG_R_USER_32BIT_INIT(var, reg, area)                    SPI_R_32BIT(var, reg, area)
    #define SPI_REG_G_USER_32BIT_INIT(var, reg, mask, area)              SPI_G_32BIT(var, reg, mask, area)
    #define SPI_REG_R_USER_16BIT_INIT(var, reg, area)                    SPI_R_16BIT(var, reg, area)
    #define SPI_REG_G_USER_16BIT_INIT(var, reg, mask, area)              SPI_G_16BIT(var, reg, mask, area)
    #define SPI_REG_R_USER_8BIT_INIT(var, reg, area)                     SPI_R_8BIT(var, reg, area)
    /* read accesses supervisor init */
    #define SPI_REG_R_PRIV_32BIT_INIT(var, reg, area)                    SPI_R_32BIT(var, reg, area)
    #define SPI_REG_G_PRIV_32BIT_INIT(var, reg, mask, area)              SPI_G_32BIT(var, reg, mask, area)
    #define SPI_REG_R_PRIV_16BIT_INIT(var, reg, area)                    SPI_R_16BIT(var, reg, area)
    #define SPI_REG_G_PRIV_16BIT_INIT(var, reg, mask, area)              SPI_G_16BIT(var, reg, mask, area)
    #define SPI_REG_R_PRIV_8BIT_INIT(var, reg, area)                     SPI_R_8BIT(var, reg, area)
    /* read accesses user */
    #define SPI_REG_R_USER_32BIT(var, reg, area)                         SPI_R_32BIT(var, reg, area)
    #define SPI_REG_G_USER_32BIT(var, reg, mask, area)                   SPI_G_32BIT(var, reg, mask, area)
    #define SPI_REG_R_USER_16BIT(var, reg, area)                         SPI_R_16BIT(var, reg, area)
    #define SPI_REG_G_USER_16BIT(var, reg, mask, area)                   SPI_G_16BIT(var, reg, mask, area)
    #define SPI_REG_R_USER_8BIT(var, reg, area)                          SPI_R_8BIT(var, reg, area)
    /* read accesses supervisor */
    #define SPI_REG_R_PRIV_32BIT(var, reg, area)                         SPI_R_32BIT(var, reg, area)
    #define SPI_REG_G_PRIV_32BIT(var, reg, mask, area)                   SPI_G_32BIT(var, reg, mask, area)
    #define SPI_REG_R_PRIV_16BIT(var, reg, area)                         SPI_R_16BIT(var, reg, area)
    #define SPI_REG_G_PRIV_16BIT(var, reg, mask, area)                   SPI_G_16BIT(var, reg, mask, area)
    #define SPI_REG_R_PRIV_8BIT(var, reg, area)                          SPI_R_8BIT(var, reg, area)
#endif
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define SPI_START_SEC_PBCFG_ROOT
#include "MemMap.h"

/*<T_SPI_RUNTIME_DEF/>*/ 
extern CONST(Spi_ConfigType, SPI_PBCFG) SpiRuntime;


#define SPI_STOP_SEC_PBCFG_ROOT
#include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#if ( (defined SPI_IRQ_SOURCE) || \
      (defined SPI_SOURCE )    || \
      (defined SPI_HW_SOURCE ) || \
      (defined SPI_DLC_SOURCE)    \
    )
#define SPI_START_SEC_CODE
#include "MemMap.h"

/*<T_SPI_GLOBAL_SUSPEND/>*/ 
#define Spi_GlobalSuspend()    SchM_Enter_Spi(SPI_EXCLUSIVE_AREA_0)
/*<T_SPI_GLOBAL_RESTORE/>*/ 
#define Spi_GlobalRestore()    SchM_Exit_Spi(SPI_EXCLUSIVE_AREA_0)
/*<T_SPI_GLOBAL_RE_ENABLE/>*/ 
#define Spi_GlobalReEnable()    


#define SPI_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif  /* SPI_CFG */
/**********************************************************************************************************************
 *  END OF FILE: Spi_Cfg.h
 *********************************************************************************************************************/

