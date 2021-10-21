/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2011 by Vctr Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vctr Informatik GmbH.
 *                Vctr Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vctr Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Spi.c
 *      Project:  DrvSpi
 *       Module:  MICROSAR communication DrvSpi Module Spi.c
 *
 *  Description:  This file implements the Spi Api for the spi communication driver.
 *
 *********************************************************************************************************************/

#define SPI_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Spi.h"
#include "Spi_Hw.h"

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
  #include "v_ver.h"
  #include "EcuM_Cbk.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */

#if (  (DRVSPI__COREASR_VERSION         != (0x0502)) \
    || (DRVSPI__COREASR_RELEASE_VERSION != (0x00)  )  )
  #error "Spi: Source and Header file are inconsistent!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if (  (SPI_AR_MAJOR_VERSION != (0x02)) \
    || (SPI_AR_MINOR_VERSION != (0x03)) \
    || (SPI_AR_PATCH_VERSION != (0x00)) )
  #error "Spi: AUTOSAR Version Numbers of Spi are different"
#endif

/* versions of all included header files shall be checked */
#if (  (SPI_CFG_MAJOR_VERSION != (0x05)) \
    || (SPI_CFG_MINOR_VERSION != (0x02)) )
  #error "Spi: Source and Generated Header file are inconsistent!"
#endif

#if (  (SPI_HW_MAJOR_VERSION != (0x05)) \
    || (SPI_HW_MINOR_VERSION != (0x02)) )
  #error "Spi_Hw: Source and Header file are inconsistent!"
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"

P2CONST(Spi_ConfigType, SPI_VAR_ZERO_INIT, SPI_PBCFG) Spi_ConfigPtr_pt = NULL_PTR;
volatile VAR(Spi_StatusType, SPI_VAR_ZERO_INIT) Spi_DrvResult_t = SPI_UNINIT;

#define SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define SPI_START_SEC_CODE
#include "MemMap.h"

/***********************************************************************************************************************
 *  Spi_InitMemory()
 **********************************************************************************************************************/
/*! \brief      Service to initialize module global variables at power up. This function can be used to initialize the
 *              variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre        Module must not be initialized
 *  \context    Function shall be called from task level
 **********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_InitMemory(void)
{

    Spi_ConfigPtr_pt = NULL_PTR;
    Spi_DrvResult_t  = SPI_UNINIT;
    Spi_DlcInitMemory();
} /* Spi_InitMemory() */

/***********************************************************************************************************************
 *  Spi_Init
 **********************************************************************************************************************/
/*! \brief      This method is Spi_Init Api.
 *  \param[in]  Spi_ConfigType             ConfigPtr
 *  \param[out] none
 *  \return     none
 *  \pre        Input parameter must not be NULL.
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_Init
(
    P2CONST(Spi_ConfigType, AUTOMATIC, SPI_PBCFG) ConfigPtr
)
{
    uint32 Index_loc;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_ALREADY_INITIALIZED)
    if (Spi_DrvResult_t != SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_INIT, SPI_E_ALREADY_INITIALIZED);
        return;
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_CONFIG)
    if (NULL_PTR == ConfigPtr)
    {
        Spi_DetReportError(SPI_SID_INIT, SPI_E_PARAM_CONFIG);
        return;
    }
    #endif
#endif

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
    if (((ConfigPtr->Spi_GeneratorVersion & (uint32)0x00FFFF00u) !=
       (((uint32)SPI_CFG_MAJOR_VERSION << 16u) |
       ((uint32)SPI_CFG_MINOR_VERSION << 8u)))
        #if ( SPI_CFG_PATCH_VERSION != 0)
        || ((ConfigPtr->Spi_GeneratorVersion & (uint32)0x000000FFu) < SPI_CFG_PATCH_VERSION)
        #endif
        )
    {
        /* Call the Vector specific Spi Error callback and do NOT Call Det_ReportError. */
        EcuM_GeneratorCompatibilityError((uint16) SPI_MODULE_ID, (uint8) 0u);
        return;
    }
#endif

    /* assign passed runtime */
    Spi_ConfigPtr_pt = ConfigPtr;
    for (Index_loc = 0; Index_loc < Spi_ConfigPtr_pt->Spi_MaxDlcs; Index_loc++)
    {
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_DlcResult[Index_loc] = SPI_DLC_OK;
    }
    for (Index_loc = 0; Index_loc < Spi_ConfigPtr_pt->Spi_MaxJobs; Index_loc++)
    {
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[Index_loc] = SPI_JOB_OK;
    }
    for (Index_loc = 0; Index_loc < Spi_ConfigPtr_pt->Spi_MaxSequences; Index_loc++)
    {
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[Index_loc] = SPI_SEQ_OK;
    }
    Spi_HwInit();
    /* driver result is IDLE if the whole driver initialized successfully */
    Spi_DrvResult_t = SPI_IDLE;
    return;
}

/***********************************************************************************************************************
 *  Spi_DeInit
 **********************************************************************************************************************/
/*! \brief      This method is Spi_DeInit Api.
 *  \param[in]  none
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void)
{
    uint32 Index_loc;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_DEINIT, SPI_E_UNINIT);
        return (E_NOT_OK);
    }
    #endif
#endif
    if (Spi_DrvResult_t  == SPI_BUSY)
    {
        return (E_NOT_OK);
    }
    Spi_DrvResult_t  = SPI_UNINIT;
    for (Index_loc = 0; Index_loc < Spi_ConfigPtr_pt->Spi_MaxDlcs; Index_loc++)
    {
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_DlcResult[Index_loc] = SPI_DLC_OK;
    }
    for (Index_loc = 0; Index_loc < Spi_ConfigPtr_pt->Spi_MaxJobs; Index_loc++)
    {
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[Index_loc] = SPI_JOB_OK;
    }
    for (Index_loc = 0; Index_loc < Spi_ConfigPtr_pt->Spi_MaxSequences; Index_loc++)
    {
        Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[Index_loc] = SPI_SEQ_OK;
    }
    Spi_HwDeInit();
    return(E_OK);
}

/***********************************************************************************************************************
 *  Spi_GetStatus
 **********************************************************************************************************************/
/*! \brief      This method is Spi_GetStatus Api.
 *  \param[in]  none
 *  \param[out] none
 *  \return     SPI_UNINIT, SPI_BUSY, SPI_IDLE
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void)
{
    return(Spi_DrvResult_t);
}

/***********************************************************************************************************************
 *  Spi_GetJobResult
 **********************************************************************************************************************/
/*! \brief      This method is Spi_GetJobResult Api.
 *  \param[in]  Spi_JobType               Job
 *  \param[out] none
 *  \return     SPI_JOB_OK, SPI_JOB_PENDING, SPI_JOB_FAILED
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult
(
    Spi_JobType Job
)
{
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_GET_JOB_RESULT, SPI_E_UNINIT);
        return (SPI_JOB_FAILED);
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_JOB)
    if (Job >= Spi_ConfigPtr_pt->Spi_MaxJobs)
    {
        Spi_DetReportError(SPI_SID_GET_JOB_RESULT, SPI_E_PARAM_JOB);
        return (SPI_JOB_FAILED);
    }
    #endif
#endif
    return(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[Job]);
}

#if (SPI_HW_STATUS_API == STD_ON)
/***********************************************************************************************************************
 *  Spi_GetHWUnitStatus
 **********************************************************************************************************************/
/*! \brief      This method is Spi_GetJobResult Api.
 *  \param[in]  Spi_HWUnitType            HWUnit
 *  \param[out] none
 *  \return     SPI_UNINIT, SPI_IDLE, SPI_BUSY
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus
(
    Spi_HWUnitType HWUnit
)
{
    Spi_StatusType Res_loc;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError( SPI_SID_GET_UNIT_STATUS, SPI_E_UNINIT);
        return (SPI_UNINIT);
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_UNIT)
    {
        uint8 UnitIdx_u8;
        uint8 UnitCnt_u8;
        UnitCnt_u8 = 0;
        for(UnitIdx_u8 = 0; UnitIdx_u8 < Spi_ConfigPtr_pt->Spi_MaxDlcs; UnitIdx_u8++)
        {
            /* check unit id against all configured id´s */
            if (HWUnit == Spi_UnitProperty_at[UnitIdx_u8].Spi_UnitID)
            {
                /* id shall occur only once */
                UnitCnt_u8++;
            }
        }
        if(UnitCnt_u8 != 1)
        {
            Spi_DetReportError(SPI_SID_GET_UNIT_STATUS, SPI_E_PARAM_UNIT);
            return (SPI_UNINIT);
        }
    }
    #endif
#endif
    Res_loc = SPI_UNINIT;
    switch(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_DlcResult[HWUnit])
    {
        case SPI_DLC_PENDING:
            /* need to fall through here, both results are mapped to SPI_BUSY  */
        case SPI_DLC_FAILED:
            Res_loc = SPI_BUSY;
            break;

        case SPI_DLC_OK:
            Res_loc = SPI_IDLE;
            break;

        default:
            break;
    }
    return(Res_loc);
}
#endif

/***********************************************************************************************************************
 *  Spi_GetSequenceResult
 **********************************************************************************************************************/
/*! \brief      This method is Spi_GetSequenceResult Api.
 *  \param[in]  Spi_SeqResultType         Seq
 *  \param[out] none
 *  \return     SPI_SEQ_OK
 *  \return     SPI_SEQ_PENDING
 *  \return     SPI_SEQ_CANCELLED
 *  \return     SPI_SEQ_FAILED
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult
(
    Spi_SequenceType Seq
)
{
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_GET_SEQ_RESULT, SPI_E_UNINIT);
        return (SPI_SEQ_FAILED);
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_SEQ)
    if (Seq >= Spi_ConfigPtr_pt->Spi_MaxSequences)
    {
        Spi_DetReportError(SPI_SID_GET_SEQ_RESULT, SPI_E_PARAM_SEQ);
        return (SPI_SEQ_FAILED);
    }
    #endif
#endif
    return(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[Seq]);
}

#if (SPI_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  Spi_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief      This method is Spi_GetVersionInfo Api.
 *  \param[in]  Std_VersionInfoType       VersioninfoPtr
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) VersioninfoPtr
)
{
#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_PARAM_CHK_VERSION)
    if (VersioninfoPtr == NULL_PTR)
    {
        Spi_DetReportError(SPI_SID_GETVERSION_INFO, SPI_E_PARAM_VERSIONINFO);
        return;
    }
    #endif
#endif

    VersioninfoPtr->vendorID         = ( SPI_VENDOR_ID);
    VersioninfoPtr->moduleID         = ( SPI_MODULE_ID );
    VersioninfoPtr->instanceID       = ( SPI_INSTANCE_ID );
    VersioninfoPtr->sw_major_version = ( SPI_SW_MAJOR_VERSION);
    VersioninfoPtr->sw_minor_version = ( SPI_SW_MINOR_VERSION);
    VersioninfoPtr->sw_patch_version = ( SPI_SW_PATCH_VERSION);
    return;
}
#endif

#if ((SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
/***********************************************************************************************************************
 *  Spi_WriteIB
 **********************************************************************************************************************/
/*! \brief      This method is Spi_WriteIB Api.
 *  \param[in]  Spi_ChannelType           Channel
 *  \param[in]  Spi_DataType              DataBufferPtr
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB
(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr
)
{
    uint16_least Index_loc;
    uint16_least Len_loc;
    uint16_least TxDefData_loc;
    uint16_least DataMode_loc;
    P2VAR(Spi_DataType, AUTOMATIC, SPI_VAR_NOINIT) TxPtr_p;   /* pointer channel Tx data */


#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_WRITE_IB, SPI_E_UNINIT);
        return (E_NOT_OK);
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_CHANNEL)
    if (  (Channel >= Spi_ConfigPtr_pt->Spi_MaxChannels)
       || (Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_ChannelBuf != SPI_IB))
    {
        /* channel must be valid */
        Spi_DetReportError(SPI_SID_WRITE_IB, SPI_E_PARAM_CHANNEL);
        return (E_NOT_OK);
    }
    #endif
#endif
    DataMode_loc  = Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_DataWidth;
    Len_loc       = Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_BufLength;
    TxDefData_loc = Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_DefaultTxData;
    TxPtr_p       = Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_Descriptor->Spi_Tx_pt;

    /* setup Rx and Tx length, the DLC module uses the generated lengths */
    Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_Descriptor->Spi_TxRxLength =
        Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_BufLength;
    if(DataBufferPtr == NULL_PTR)
    {
        /* copy default value */
        for(Index_loc=0; Index_loc < Len_loc; Index_loc++)
        {
            if(DataMode_loc == 8)
            {
                TxPtr_p[Index_loc] = (uint8)TxDefData_loc;
            }
            else
            {
                ((Spi_DlcFrame16PtrType) TxPtr_p)[Index_loc] = (uint16)TxDefData_loc;
            }
        }
    }
    else
    {
        /* only 8bit data buffers are handled, so the length has to be adjusted */
        if(DataMode_loc == 16)
        {
            /* the length is automatically adjusted by the generation tool, adjust to 8bit length */
            Len_loc = Len_loc << 1;
        }
        else
        {
            /* no action */
        }
        /* copy data to internal buffer */
        for(Index_loc=0; Index_loc < Len_loc; Index_loc++)
        {
            Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_Descriptor->Spi_Tx_pt[Index_loc] = DataBufferPtr[Index_loc];
        }
    }
    return(E_OK);
}
#endif

#if ((SPI_CHANNELBUFFERS == SPI_IB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
/***********************************************************************************************************************
 *  Spi_ReadIB
 **********************************************************************************************************************/
/*! \brief      This method is Spi_ReadIB Api.
 *  \param[in]  Spi_ChannelType           Channel
 *  \param[in]  Spi_DataType              DataBufferPtr
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB
(
    Spi_ChannelType Channel,
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr
)
{
    uint16_least Index_loc;
    uint16_least Len_loc;
    P2VAR(Spi_DataType, AUTOMATIC, SPI_VAR_NOINIT) RxPtr_p;   /* pointer channel Rx data */

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_READ_IB, SPI_E_UNINIT);
        return (E_NOT_OK);
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_CHANNEL)
    if (  (Channel >= Spi_ConfigPtr_pt->Spi_MaxChannels)
       || (Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_ChannelBuf != SPI_IB))
    {
        Spi_DetReportError(SPI_SID_READ_IB, SPI_E_PARAM_CHANNEL);
        return (E_NOT_OK);
    }
    #endif
#endif
    if(Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_DataWidth == 8)
    {
        Len_loc = Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_BufLength;
    }
    else
    {
        /* the length is automatically adjusted by the generation tool, adjust to 8bit length */
        Len_loc = (Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_BufLength << 1);
    }
    RxPtr_p = Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_Descriptor->Spi_Rx_pt;
    /* setup Rx and Tx length, the DLC module uses the generated lengths */
    Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_Descriptor->Spi_TxRxLength =
        Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_BufLength;

    if(DataBufferPtr == NULL_PTR)
    {
        /* no data available */
    }
    else
    {
        for(Index_loc=0; Index_loc < Len_loc; Index_loc++)
        {
            DataBufferPtr[Index_loc] = RxPtr_p[Index_loc];
        }
    }
    return(E_OK);
}
#endif

#if ((SPI_CHANNELBUFFERS == SPI_EB) || (SPI_CHANNELBUFFERS == SPI_IB_EB))
/***********************************************************************************************************************
 *  Spi_SetupEB
 **********************************************************************************************************************/
/*! \brief      This method is Spi_SetupEB Api.
 *  \param[in]  Spi_ChannelType           Channel
 *  \param[in]  Spi_DataType              SrcDataBufferPtr
 *  \param[in]  Spi_DataType              DesDataBufferPtr
 *  \param[in]  Spi_DataType              Length
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB
(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
    Spi_NumberOfDataType Length
)
{
    Spi_NumberOfDataType LengthEB_t;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_SETUP_EB, SPI_E_UNINIT);
        return (E_NOT_OK);
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_CHANNEL)
    if (  (Channel >= Spi_ConfigPtr_pt->Spi_MaxChannels)
       || (Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_ChannelBuf != SPI_EB))
    {
        Spi_DetReportError(SPI_SID_SETUP_EB, SPI_E_PARAM_CHANNEL);
        return (E_NOT_OK);
    }
    #endif
#endif
    /* check for frame mode if the length is aligned */
    if(Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_DataWidth == 8)
    {
        LengthEB_t = Length;
    }
    else
    {
        /* length must be even aligned in 16 bit mode */
        #if (STD_ON == SPI_DEV_ERROR_DETECT)
            #if (STD_ON == SPI_PARAM_CHK_ALIGNMENT)
            if((Length & 1) == 1)
            {
                Spi_DetReportError(SPI_SID_SETUP_EB, SPI_E_PARAM_FRAME_LENGTH);
                return (E_NOT_OK);
            }
            #endif
        #endif
        LengthEB_t = (Length >> 1);
        /* buffers must be even aligned in 16 bit mode */
        #if (STD_ON == SPI_DEV_ERROR_DETECT)
            #if (STD_ON == SPI_PARAM_CHK_BUFFER)
            {
                uint32_least SrcBuf_u32;
                uint32_least DestBuf_u32;

                SrcBuf_u32  = (uint32_least)SrcDataBufferPtr;
                DestBuf_u32 = (uint32_least)DesDataBufferPtr;
                if(  ((SrcBuf_u32  & 1) == 1)
                  || ((DestBuf_u32 & 1) == 1)  )
                {
                    Spi_DetReportError(SPI_SID_SETUP_EB, SPI_E_PARAM_FRAME_BUFFER);
                    return (E_NOT_OK);
                }
            }
            #endif
        #endif
    }
    /* now check length */
    #if (STD_ON == SPI_DEV_ERROR_DETECT)
        #if (STD_ON == SPI_PARAM_CHK_LENGTH)
        if ((LengthEB_t == 0) || (LengthEB_t > Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_BufLength))
        {
            Spi_DetReportError(SPI_SID_SETUP_EB, SPI_E_PARAM_LENGTH);
            return (E_NOT_OK);
        }
        #endif
    #endif

    Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_Descriptor->Spi_Tx_pt =
        (P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA))SrcDataBufferPtr;
    Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_Descriptor->Spi_Rx_pt = DesDataBufferPtr;
    Spi_ConfigPtr_pt->Spi_ChannelCfg[Channel].Spi_Descriptor->Spi_TxRxLength = LengthEB_t;
    return(E_OK);
}
#endif

#if ((SPI_SCALEABILITY == SPI_ASYNCONLY) || (SPI_SCALEABILITY == SPI_SYNC_ASYNC))
/***********************************************************************************************************************
 *  Spi_AsyncTransmit
 **********************************************************************************************************************/
/*! \brief      This method is Spi_AsyncTransmit Api.
 *  \param[in]  Spi_SequenceType          Sequence
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit
(
    Spi_SequenceType Sequence
)
{
    Spi_HwEventType HwEv_loc;
    Std_ReturnType  Ret_loc;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_ASYNC_TRANSMIT, SPI_E_UNINIT);
        return (E_NOT_OK);
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_SEQ)
    if(Sequence >= Spi_ConfigPtr_pt->Spi_MaxSequences)
    {
        Spi_DetReportError(SPI_SID_ASYNC_TRANSMIT, SPI_E_PARAM_SEQ);
        return (E_NOT_OK);
    }
    #endif
    #if (STD_ON == SPI_CHK_SEQ_PENDING)
    if(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[Sequence] == SPI_SEQ_PENDING)
    {
        Spi_DetReportError(SPI_SID_ASYNC_TRANSMIT, SPI_E_SEQ_PENDING);
        return (E_NOT_OK);
    }
    #endif
#endif
    /* check jobs of this sequence, if they are in service */

    HwEv_loc.Event_u8   = SPI_HW_EV_SEQ_START;
    HwEv_loc.Guard_u8   = SPI_HW_ASYNC;
    HwEv_loc.TaskID_u8  = Sequence;
    Ret_loc = Spi_HwSetEvent(&HwEv_loc);

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if(Ret_loc == E_NOT_OK)
    {
        Spi_DetReportError(SPI_SID_ASYNC_TRANSMIT, SPI_E_SEQ_PENDING);
    }
#endif
    return(Ret_loc);
}
#endif

#if ((SPI_SCALEABILITY == SPI_SYNCONLY)  || (SPI_SCALEABILITY == SPI_SYNC_ASYNC))
/***********************************************************************************************************************
 *  Spi_SyncTransmit
 **********************************************************************************************************************/
/*! \brief      This method is Spi_SyncTransmit Api.
 *  \param[in]  Spi_SequenceType          Sequence
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit
(
    Spi_SequenceType Sequence
)
{
    Spi_HwEventType HwEv_loc;
    Std_ReturnType  Ret_loc;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_SYNC_TRANSMIT, SPI_E_UNINIT);
        return (E_NOT_OK);
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_SEQ)
    if(Sequence >= Spi_ConfigPtr_pt->Spi_MaxSequences)
    {
        Spi_DetReportError(SPI_SID_SYNC_TRANSMIT, SPI_E_PARAM_SEQ);
        return (E_NOT_OK);
    }
    #endif
    #if (STD_ON == SPI_CHK_SEQ_PENDING)
    if(Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_SeqResult[Sequence] == SPI_SEQ_PENDING)
    {
        Spi_DetReportError(SPI_SID_SYNC_TRANSMIT, SPI_E_SEQ_IN_PROGRESS);
        return (E_NOT_OK);
    }
    #endif
#endif
    /* check jobs of this sequence, if they are in service */

    HwEv_loc.Event_u8  = SPI_HW_EV_SEQ_START;
    HwEv_loc.Guard_u8  = SPI_HW_SYNC;
    HwEv_loc.TaskID_u8 = Sequence;
    Spi_GlobalSuspend();
    Ret_loc = Spi_HwSetEvent(&HwEv_loc);

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    if(Ret_loc == E_NOT_OK)
    {
        Spi_DetReportError(SPI_SID_SYNC_TRANSMIT, SPI_E_SEQ_IN_PROGRESS);
    }
#endif
    while(Spi_GetSequenceResult(Sequence) == SPI_SEQ_PENDING)
    {
        Spi_MainFunction_Driving();
    }
    Spi_GlobalRestore();
    return(Ret_loc);
}
#endif

#if (SPI_CANCEL_API == STD_ON)
/***********************************************************************************************************************
 *  Spi_Cancel
 **********************************************************************************************************************/
/*! \brief      This method is Spi_Cancel Api.
 *  \param[in]  Spi_SequenceType          Sequence
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_Cancel
(
    Spi_SequenceType Sequence
)
{
    Spi_HwEventType HwEv_loc;

#if (STD_ON == SPI_DEV_ERROR_DETECT)
    #if (STD_ON == SPI_CHK_MODULE_INIT)
    if (Spi_DrvResult_t  == SPI_UNINIT)
    {
        Spi_DetReportError(SPI_SID_CANCEL, SPI_E_UNINIT);
        return;
    }
    #endif
    #if (STD_ON == SPI_PARAM_CHK_SEQ)
    if(Sequence >= Spi_ConfigPtr_pt->Spi_MaxSequences)
    {
        Spi_DetReportError(SPI_SID_CANCEL, SPI_E_PARAM_SEQ);
        return;
    }
    #endif
#endif
    HwEv_loc.Event_u8 = SPI_HW_EV_CANCEL;
    HwEv_loc.TaskID_u8       = Sequence;
    (FUNC(void, SPI_CODE)) Spi_HwSetEvent(&HwEv_loc);
    return;
}
#endif

/***********************************************************************************************************************
 *  Spi_SetAsyncMode
 **********************************************************************************************************************/
/*! \brief      This method is Spi_SetAsyncMode Api.
 *  \param[in]  Spi_AsyncModeType         Mode
 *  \param[out] none
 *  \return     E_OK
 *  \return     E_NOT_OK
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
#if ((SPI_SCALEABILITY == SPI_ASYNCONLY) || (SPI_SCALEABILITY == SPI_SYNC_ASYNC))
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode
(
    Spi_AsyncModeType Mode
)
{
    if(Mode == SPI_INTERRUPT_MODE)
    {
       if(Spi_DrvResult_t  == SPI_IDLE)
       {
           Spi_HwSetMode(Mode);
       }
       else
       {
           return(E_NOT_OK);
       }
    }
    else
    {
        /* set new mode */
        Spi_HwSetMode(Mode);
    }
    return(E_OK);
}
#endif

/***********************************************************************************************************************
 *  Spi_MainFunction_Handling
 **********************************************************************************************************************/
/*! \brief      This method is Spi_MainFunction_Handling. This function is called cyclic from the Os or scheduler.
 *  \param[in]  none         
 *  \param[out] none
 *  \return     none
 *  \context    Function could be called from from task level. It has no functionality.
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void)
{
}

/***********************************************************************************************************************
 *  Spi_MainFunction_Driving
 **********************************************************************************************************************/
/*! \brief      This method is Spi_MainFunction_Driving. This function is called cyclic from the Os or scheduler.
 *  \param[in]  Spi_AsyncModeType         Mode
 *  \param[out] none
 *  \return     none
 *  \context    Function could be called from from task level
 *  \note       Spi AUTOSAR API.
 **********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_MainFunction_Driving(void)
{
    Spi_HwProcessState();
}

#define SPI_STOP_SEC_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 *  END OF FILE: Spi.c
 *********************************************************************************************************************/
