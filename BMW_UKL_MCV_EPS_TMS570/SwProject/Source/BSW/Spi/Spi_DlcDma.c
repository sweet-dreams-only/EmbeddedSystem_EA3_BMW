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
 *         File:  Spi_DlcDma.c
 *      Project:  DrvSpi_Tms570Tispi01Asr
 *       Module:  MICROSAR Communication DrvSpi_Tms570Tispi01Asr Module Spi_DlcDma.c
 *    Generator:  -
 *
 *  Description:  This file implements the Spi Dma support, handling of channels and transmission settings.
 *
 *********************************************************************************************************************/

#define SPI_DLCDMA_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Spi_DlcDma.h"
#include "Spi.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (SPI_DLCDMA_SW_MAJOR_VERSION != (0x01)) \
    || (SPI_DLCDMA_SW_MINOR_VERSION != (0x05)) )
  #error "Vendor specific version numbers of Spi_DlcDma.c and Spi_DlcDma.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/* the Spi uses max five Channel_u16s for Tx/Rx with 10 requests */

#define DMA_HW_Channel_u16_NUMBER    (16u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
static VAR(Dma_StatusType, SPI_VAR) Dma_ModuleInitFlag = DMA_UNINIT;
/* DMA support for max 5 HWUnits */
Dma_GlobalRegisterPtrType Dma_GlobalRegister      = DMA_GLOBAL_REGISTER_BASE_ADDRESS;
#endif

#define SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define SPI_START_SEC_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

FUNC(void, SPI_CODE) Dma_Init( void )
{
#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
    /* dma has already been initilized */
    if(Dma_ModuleInitFlag == DMA_IDLE)
    {
        /* no action */
    }
    else
    {
        /* ====== Initialization 1 of Global Control Register ====== */
        /* Cause a self reset of the DMA hardware module to reach a defined state of all global registers of DMA module,
        * switch the debug mode off and set DMA to disabled */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_GCTRL, 0x00000001u, OS_MEM_AREA_DMA_REG);
        /* Reset the reset bit of the DMA hardware module
        * switch the debug mode to "finish current frame transfer" and set DMA to disabled */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_GCTRL, 0x00000200u, OS_MEM_AREA_DMA_REG);

        /* ====== Initialization of HW Channel_u16 Enable Register ====== */
        /* No initialization needed, all Channel_u16s are disabled after reset. */
        /* Initialization not needed but done because there is no statement in manual about reset state of this register */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_HWCHENAR, 0xFFFFFFFFu, OS_MEM_AREA_DMA_REG);

        /* ====== Initialization of SW Channel_u16 Enable Register ====== */
        /* No initialization needed, all Channel_u16s are disabled after reset. */
        /* Initialization not needed but done because there is no statement in manual about reset state of this register */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_SWCHENAR, 0xFFFFFFFFu, OS_MEM_AREA_DMA_REG);

        /* ====== Initialization of Interrupt Enable Register ====== */
        /* Enable all Dma interrupts globally, but disable all Dma interrupts themselves */

        /* Initialization not needed but done because there is no statement in manual about reset state of this register */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_FTCINTENAR, 0xFFFFFFFFu, OS_MEM_AREA_DMA_REG);  /* disable frame transfer complete interrupt */
        /* Initialization not needed but done because there is no statement in manual about reset state of this register */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_LFSINTENAR, 0xFFFFFFFFu, OS_MEM_AREA_DMA_REG);  /* disable last frame started interrupt */
        /* Initialization not needed but done because there is no statement in manual about reset state of this register */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_HBCINTENAR, 0xFFFFFFFFu, OS_MEM_AREA_DMA_REG);  /* disable half block complete interrupt */
        /* Initialization not needed but done because there is no statement in manual about reset state of this register */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_BTCINTENAR, 0xFFFFFFFFu, OS_MEM_AREA_DMA_REG);  /* disable block transfer complete interrupt */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_GCHIENAS, ((uint32) 0xFFFFFFFFu), OS_MEM_AREA_DMA_REG);    /* enable all Dma interrupts globally */

        /* ====== Initialization of Port Assignment Registers ====== */
        /* Set Port assignment of all Channel_u16s to Port B only. Port A seems to be not implemented in TMS570PSFC66 */
        SPI_REG(W_, PRIV_, 32BIT_INIT)( Dma_GlobalRegister->DMA_PAR[0], 0x77777777u, OS_MEM_AREA_DMA_REG);
        #if DMA_HW_Channel_u16_NUMBER > 8u
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_PAR[1], 0x77777777u, OS_MEM_AREA_DMA_REG);    /* only needed if more than 8 hardware Channel_u16s are available */
        #endif
        #if DMA_HW_Channel_u16_NUMBER > 16u
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_PAR[2], 0x77777777u, OS_MEM_AREA_DMA_REG);    /* only needed if more than 16 hardware Channel_u16s are available */
        #endif
        #if DMA_HW_Channel_u16_NUMBER > 24u
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_PAR[3], 0x7777777u, OS_MEM_AREA_DMA_REG);    /* only needed if more than 24 hardware Channel_u16s are available */
        #endif

        /* ====== Initialization of Channel_u16 Priority Register ====== */
        /* No initialization needed, all Channel_u16s are set to low priority after reset. */
        /* ====== Initialization of Interrupt Mapping Registers ====== */
        /* No initialization needed, all requests are routed to ARM core after reset. */
        /* ====== Initialization of Fall Back Register ====== */
        /* Currently unknown if initialization is needed. */
        /* ====== Initialization of Port Control Register ====== */
        /* Currently unknown if initialization is needed. */
        /* Note: Definition of priority scheme (fixed priority/round robin) can be made in this register. */
        /* Note: DMA module of TMS570 uses a FIFO buffer.
        * Bypassing of FIFO can be switched on in this register. */

        /* ====== Initialization of RAM Test Control Register ====== */
        /* Currently unknown if initialization is needed. */
        /* ====== Initialization of Debug Control Register ====== */
        /* Currently unknown if initialization is needed. */
        /* ====== Initialization of Watch Point Register ====== */
        /* Currently unknown if initialization is needed. */
        /* ====== Initialization of Watch Mask Register ====== */
        /* Currently unknown if initialization is needed. */
        /* ====== Initialization of Parity Control Register ====== */
        /* Currently unknown if initialization is needed. */
        /* ====== Initialization of Memory Protection Control Register ====== */
        /* Currently unknown if initialization is needed. */
        /* ====== Initialization of Memory Protection Region Registers ====== */
        /* Currently unknown if initialization is needed. */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_DMAPCR, 0x5u, OS_MEM_AREA_DMA_REG);
        /* ====== Initialization 2 of Global Control Register ====== */
        /* Set DMA to enabled */
        SPI_REG(S_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_GCTRL, 0x00010000u, OS_MEM_AREA_DMA_REG);

        /* Set initialization flag to not uninit */
        Dma_ModuleInitFlag = DMA_IDLE;
    }
#endif
} /* End of Dma_Init() */

FUNC(void, SPI_CODE) Dma_DeInit( void )
{
#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
    /* ====== disable and reset hardware ====== */
    /* Cause a self reset of the DMA hardware module to reach a defined state of all global registers of DMA module,
     * switch the debug mode off and set DMA to disabled */
    SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_GCTRL, (uint32)0x00000001u, OS_MEM_AREA_DMA_REG);
    /* Reset the reset bit of the DMA hardware module */
    SPI_REG(W_, PRIV_, 32BIT_INIT)(Dma_GlobalRegister->DMA_GCTRL, (uint32)0x00000000u, OS_MEM_AREA_DMA_REG);
    /* ====== set initialization flag to uninit ====== */
    Dma_ModuleInitFlag = DMA_UNINIT;
#endif
} /* End of Dma_DeInit() */

FUNC(void, SPI_CODE) Dma_Setup
(
    P2CONST(Dma_ChannelSetupType, AUTOMATIC, SPI_VAR) Setup
)
{
#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
    /* misra 8.7: move to local */
    /* for C61 or Ls3xx */
    CONST(Dma_RequestType, SPI_VAR) Dma_MapReqLine[SPI_DLC_MAXHWUNIT] =
    {
          { SPI_DLC_RXUNIT0, SPI_DLC_TXUNIT0 }
        , { SPI_DLC_RXUNIT1, SPI_DLC_TXUNIT1 }
        , { SPI_DLC_RXUNIT2, SPI_DLC_TXUNIT2 }
        , { SPI_DLC_RXUNIT3, SPI_DLC_TXUNIT3 }
        , { SPI_DLC_RXUNIT4, SPI_DLC_TXUNIT4 }
    };

    uint16 Channel_u16;
    uint16 Unit_u16;
    uint8 ReqL_u8;    /* DMA request line */

    Channel_u16 = Setup->Channel;
    Unit_u16    = Setup->Unit;

    SPI_REG(W_, USER_, 32BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].ISADDR,
                              Setup->SrcAddr,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 32BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].IDADDR,
                              Setup->DstAddr,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 16BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].IFTCOUNT,
                              Setup->FCount,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 16BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].IETCOUNT,
                              Setup->ECount,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 16BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].CHCTRL,
                              Setup->ChCtrl,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 16BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].CHCTRL_CHAIN,
                              0,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 16BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].EIDXS,
                              Setup->EISrcInc,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 16BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].EIDXD,
                              Setup->EIDstInc,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 16BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].FIDXS,
                              Setup->FISrcInc,
                              OS_MEM_AREA_DMA_RAM);
    SPI_REG(W_, USER_, 16BIT)(DMA_PRIMARY_CONTROL_PACKET_BASE_ADDRESS->DMA_CHCTRL[Channel_u16].FIDXD,
                              Setup->FIDstInc,
                              OS_MEM_AREA_DMA_RAM);

    /* configure the Channel_u16 for DMA transmission channels [1 = TX, 0 = RX]
     * DMA_REQ_SPIx for Tmsx70 TxData/RxData
     * SPI_DMA_TXDATA uses request line 1
     * SPI_DMA_RXDATA uses request line 0
     */
    ReqL_u8 = Setup->Dir;
    SPI_REG(W_, USER_, 8BIT)(Dma_GlobalRegister->DMA_DREQASI[Channel_u16],
                              Dma_MapReqLine[Unit_u16].DmaReq[ReqL_u8],
                              OS_MEM_AREA_DMA_REG);
    if(Setup->ChEn == 0)
    {
        /* disable channel for hardware requests */
        SPI_REG(S_, PRIV_, 32BIT)(Dma_GlobalRegister->DMA_HWCHENAR,
                                  ((uint32)1 << Channel_u16),
                                  OS_MEM_AREA_DMA_REG);
    }
    else
    {
        /* enable channel for hardware requests */
        SPI_REG(S_, PRIV_, 32BIT)(Dma_GlobalRegister->DMA_HWCHENAS,
                                  ((uint32)1 << Channel_u16),
                                  OS_MEM_AREA_DMA_REG);
    }
#endif
}

#define SPI_STOP_SEC_CODE
#include "MemMap.h"
