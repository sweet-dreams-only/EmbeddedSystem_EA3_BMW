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
 *         File:  Spi_Dlc.c
 *      Project:  DrvSpi_Tms570Tispi01Asr
 *       Module:  MICROSAR Communication DrvSpi_Tms570Tispi01Asr
 *    Generator:  -
 *
 *  Description:  This file implements the Spi_Dlc low level driver, handling of channels and transmission settings.
 *
 *********************************************************************************************************************/

#define SPI_DLC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Spi.h"
#include "Spi_Hw.h"
#include "Spi_Irq.h"
#include "Spi_DlcDma.h"

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
  #include "v_ver.h"
  #include "EcuM_Cbk.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* versions of all included header files shall be checked */
#if (  (SPI_SW_MAJOR_VERSION != (0x01u)) \
    || (SPI_SW_MINOR_VERSION != (0x05u)) )
#error "Spi :Software Version Numbers are inconsistent!"
#endif

#if (  (SPI_IRQ_MAJOR_VERSION != (0x01)) \
    || (SPI_IRQ_MINOR_VERSION != (0x05)) )
  #error "Spi_Irq: Source and Header file are inconsistent!"
#endif

#if (  (SPI_DLCDMA_SW_MAJOR_VERSION != (0x01)) \
    || (SPI_DLCDMA_SW_MINOR_VERSION != (0x05)) )
  #error "Vendor specific version numbers of Spi_Dlc.c and Spi_DlcDma.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/* DMA mode is bit 1 so the option extends for STD DMA mode */
#define SPI_DLC_MAXOPT       (3u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
#define Spi_Dlc(Type, Name)    Spi_Dlc##Type##Name
#define Spi_Irq(Type, Name)    Spi_Irq##Type##Name

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef P2VAR(Spi_BufferDescriptorType, AUTOMATIC, SPI_APPL_DATA) Spi_BufferDescriptorPtrType;
typedef P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_PBCFG) Spi_ChannelConfigPtrType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/* we have to schedule one transfer group */
static VAR(Spi_DlcEventType,    SPI_VAR_NOINIT) Spi_DlcEvent_t[SPI_DLC_MAXHWUNIT];
/* for hardwareunit mapping */
static VAR(Spi_HWUnitMapType, SPI_VAR_NOINIT) Spi_HWUnitMap_at[SPI_DLC_MAXHWUNIT];

#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
#define SPI_DLC_DMA_BUF_SIZE    (4u)

static VAR(uint8, SPI_VAR_NOINIT) Spi_DlcStdDmaUnit;
static VAR(Dma_ChannelSetupType, SPI_VAR_NOINIT) Spi_DlcDmaChSetup[2];
/* allocate a DMA mini buffer to keep minimal overhead with small DMA transfers */
static VAR(Spi_TxField, SPI_VAR_NOINIT) Spi_DlcDmaChData[SPI_DLC_DMA_BUF_SIZE];
#endif


#define SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#ifndef V_SUPPRESS_EXTENDED_VERSION_CHECK
    #if (defined DRVSPI_TMS570TISPI01ASR_LIB_SYMBOL)
        #define SPI_START_SEC_CONST_32BIT
        #include "MemMap.h"

        /* The name of this const variable is defined via v_ver.h and depends on
         * the version of the c file. The value of the const variable is also
         * defined externally and is used for consistency checks, too.
         */
        CONST(uint32, SPI_CONST) DRVSPI_TMS570TISPI01ASR_LIB_SYMBOL = (uint32)DRVSPI_TMS570TISPI01ASR_LIB_VERSION;

        #define SPI_STOP_SEC_CONST_32BIT
        #include "MemMap.h"
    #endif
#endif


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SPI_START_SEC_CODE
#include "MemMap.h"


/* interface functions  are part of the Spi_Dlc.h */

/* this function is used for an as dummy for an option with no function
 * In case of the driver is not working as expected, check this function with
 * a breakpoint
 */
static FUNC(void, SPI_CODE) Spi_Dlc(Handle, Idle)   (Spi_DlcEventPtrType DlcEv_pt);

/* derived functions with option Std */
#if (SPI_HARDWAREUNIT_USE_STD == STD_ON)
static FUNC(void, SPI_CODE) Spi_Dlc(Std, Init)          (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Std, Close)         (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Std, EnIsr)         (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Std, DeIsr)         (Spi_DlcEventPtrType DlcEv_pt);

static FUNC(void, SPI_CODE) Spi_Dlc(Std, FillData)      (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Std, DrainData)     (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Std, TriggerData)   (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Std, Transmit)      (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Std, Error)         (Spi_DlcEventPtrType DlcEv_pt);
#endif

/* derived functions with option Ram, the macro Spi_Dlc(Ram,Init) expands to Spi_DlcRamInit  */
#if (SPI_HARDWAREUNIT_USE_RAM == STD_ON)
static FUNC(void, SPI_CODE) Spi_Dlc(Ram, Init)          (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Ram, Close)         (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Ram, EnIsr)         (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Ram, DeIsr)         (Spi_DlcEventPtrType DlcEv_pt);

static FUNC(void, SPI_CODE) Spi_Dlc(Ram, FillData)      (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Ram, DrainData)     (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Ram, TriggerData)   (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Ram, Transmit)      (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(Ram, Error)         (Spi_DlcEventPtrType DlcEv_pt);
#endif

/* derived functions with option Dma */
#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Init)       (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Close)      (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, EnIsr)      (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, DeIsr)      (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Prepare)    (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, TriggerData)(Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Transmit)   (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Error)      (Spi_DlcEventPtrType DlcEv_pt);
#endif

/* functions of master class */
static FUNC(void, SPI_CODE) Spi_DlcConsumeEvent      (Spi_DlcEventPtrType DlcEv_pt);
static FUNC(void, SPI_CODE) Spi_DlcTransmit          (Spi_DlcEventPtrType DlcEv_pt);

static FUNC(void, SPI_CODE) Spi_DlcSwitchChannel
(
    Spi_DlcEventPtrType DlcEv_pt,
    Spi_DlcVU16PtrType Ctrl_pt,
    Spi_DlcTxRxDefType Dir_t
);
static FUNC(void, SPI_CODE) Spi_DlcError (Spi_DlcEventPtrType DlcEv_pt);

#define SPI_STOP_SEC_CODE
#include "MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/* function mapping is
 *    Init      initialize driver
 *    Close     de-initialize driver
 *    EnIsr     en-able interrups
 *    DeIsr     de-activate interrupts
 *    FillData  fill buffer, register with data
 *    DrainData drain data from buffer, register
 *    Trigger   start transmission
 *    Transmit  setup transmit properties
 *    Error     handle error
 *
 */
static VAR(Spi_DlcFunctionType, SPI_VAR_NOINIT) Spi_DlcOptionSelect[SPI_DLC_MAXOPT] =
{
    /* STD unit specialized functions */
    {
        #if (SPI_HARDWAREUNIT_USE_STD == STD_ON)
        Spi_Dlc(Std, Init),
        Spi_Dlc(Std, Close),
        Spi_Dlc(Std, EnIsr),
        Spi_Dlc(Std, DeIsr),
        Spi_Dlc(Std, FillData),
        Spi_Dlc(Std, DrainData),
        Spi_Dlc(Std, TriggerData),
        Spi_Dlc(Std, Transmit),
        Spi_Dlc(Std, Error)
        #else
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle)
        #endif
    },
    /* MIB RAM unit specialized functions */
    {
        #if (SPI_HARDWAREUNIT_USE_RAM == STD_ON)
        Spi_Dlc(Ram, Init),
        Spi_Dlc(Ram, Close),
        Spi_Dlc(Ram, EnIsr),
        Spi_Dlc(Ram, DeIsr),
        Spi_Dlc(Ram, FillData),
        Spi_Dlc(Ram, DrainData),
        Spi_Dlc(Ram, TriggerData),
        Spi_Dlc(Ram, Transmit),
        Spi_Dlc(Ram, Error)
        #else
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle)
        #endif
    },
    /* STD DMA specialized functions */
    {
        #if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
        Spi_Dlc(StdDma, Init),
        Spi_Dlc(StdDma, Close),
        Spi_Dlc(StdDma, EnIsr),
        Spi_Dlc(StdDma, DeIsr),
        Spi_Dlc(StdDma, Prepare),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(StdDma, TriggerData),
        Spi_Dlc(StdDma, Transmit),
        Spi_Dlc(StdDma, Error)
        #else
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle),
        Spi_Dlc(Handle, Idle)
        #endif
    },
};

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_CODE
#include "MemMap.h"
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
static FUNC(void, SPI_CODE) Spi_Dlc(Handle, Idle)(Spi_DlcEventPtrType DlcEv_pt)
{
    volatile uint8 UnitId_u8;
    volatile uint8 Option_u8;

    /* Option_u8 values are 0 -> UnitId was configured in post-build as STD unit
     *                      1 -> UnitId was configured in post-build as MIB unit
     *                      2 -> UnitId was configured in post-build as STDDMA unit
     * conditions for reaching this function:
     * a) If the pre-compile STD option was never activated, but configured in post-build
     * b) If the pre-compile MIB option was never activated, configured used in post-build
     * c) If the pre-compile DMA option was never activated, configured used in post-build
     */
    Option_u8 = DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed;
    UnitId_u8 = DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID;
    /* prevent a compiler warning */
    Option_u8++;
    UnitId_u8++;
}

#if (SPI_HARDWAREUNIT_USE_STD == STD_ON)
/***********************************************************************************************************************
 *  Start section of  STD  unit specialized functions
 **********************************************************************************************************************/

static FUNC(void, SPI_CODE) Spi_Dlc(Std, Init)(Spi_DlcEventPtrType DlcEv_pt)
{
    /* set Tx Rx int levels to int line 1, error interrupts are mapped to line 0 */
    SPI_REG(W_, USER_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_LVL,
                                   0x00000300,
                                   DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

static FUNC(void, SPI_CODE) Spi_Dlc(Std, Close)(Spi_DlcEventPtrType DlcEv_pt)
{
    volatile uint16 DataLoc_u32; /* dummy data for read */

    /* disable interrupts */
    Spi_Dlc(Std, DeIsr)(DlcEv_pt);
    SPI_REG(R_, USER_, 32BIT_INIT)(DataLoc_u32,
                                   DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.RxData_u32,
                                   DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* avoid a compiler warning */
    DataLoc_u32++;
    SPI_REG(W_, USER_, 16BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_INT0,
                              SPI_DLC_BITCLR,
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    SPI_REG(W_, USER_, 16BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_LVL,
                                   SPI_DLC_BITCLR,
                                   DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

static FUNC(void, SPI_CODE) Spi_Dlc(Std, EnIsr) (Spi_DlcEventPtrType DlcEv_pt)
{
    /* enable RxInt and error tracing */
    SPI_REG(S_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_INT0,
                                 (
                                     SPI_DLC_INT0_RXIENA  |
                                     SPI_DLC_INT0_RXOVR   |
                                     SPI_DLC_INT0_TOERR   |
                                     SPI_DLC_INT0_DLENERR |
                                     SPI_DLC_INT0_BITERR
                                 ),
                                 DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea
                             );
}

static FUNC(void, SPI_CODE) Spi_Dlc(Std, DeIsr) (Spi_DlcEventPtrType DlcEv_pt)
{
    /* disable all interrupts */
    SPI_REG(C_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_INT0,
                                 (
                                     SPI_DLC_INT0_RXIENA  |
                                     SPI_DLC_INT0_RXOVR   |
                                     SPI_DLC_INT0_TOERR   |
                                     SPI_DLC_INT0_DLENERR |
                                     SPI_DLC_INT0_BITERR
                                 ),
                                 DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea
                             );
}


static FUNC(void, SPI_CODE) Spi_Dlc(Std, FillData)(Spi_DlcEventPtrType DlcEv_pt)
{
    Spi_BufferDescriptorPtrType ChBufTx_pt; /* pointer to Tx channel buffer */
    Spi_ChannelConfigPtrType ChCfg_pt;      /* pointer to channel configuration */
    uint16 TxPos_u16;            /* TX buffer counter */
    uint8  ChIDTx_u8;            /* channel identifier, Rx used as index */

    switch(DlcEv_pt->Guard_u8)
    {
        case SPI_DLC_G_PENDING:
        DlcEv_pt->Guard_u8 = (uint8)SPI_DLC_G_ACTIVE;
        /* fall through */

        case SPI_DLC_G_ACTIVE:

        /* channel values were set by Spi_DlcSwitchChannel() , now update the register */
        SPI_REG(W_, PRIV_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_FMT[0],
                                  DlcEv_pt->ChProp_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* in this module we try to transmit one Data unit */
        /* in this module we try to transmit one or more channels, depending on the configuration */
        ChIDTx_u8 = DlcEv_pt->ID_u8[SPI_DLC_TX];
        /* handle buffers for Tx and Rx */
        ChBufTx_pt  = Spi_ConfigPtr_pt->Spi_ChannelCfg[ChIDTx_u8].Spi_Descriptor;
        ChCfg_pt    = &Spi_ConfigPtr_pt->Spi_ChannelCfg[ChIDTx_u8];
        TxPos_u16   = DlcEv_pt->Pos_u16[SPI_DLC_TX];
        /*
         * this loop transfers data from the channel(s) to RAM
         * and uses interrupts to transfer and reload the data
         */
        /* get status */
        SPI_REG(R_, USER_, 16BIT)(DlcEv_pt->RxStat_t.Rx.Stat_u16,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.Rx.Stat_u16,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* ready to fill ? */
        /* the buffer should only be filled if the flag is zero, otherwise the data was not transmitted */
        if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_TXFULL))
        {
            /* this should not happen! */
            Spi_IrqTxRxERR(DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID);
        }
        else
        {
            /* setup data */
            if(ChBufTx_pt->Spi_Tx_pt == NULL_PTR)
            {
                /* write default data */
                DlcEv_pt->TxProp_t.Tx.Data_u16 = DlcEv_pt->Default_u16[SPI_DLC_TX];
            }
            else
            {
                /* write bytes to the channel */
                if(ChCfg_pt->Spi_DataWidth <= 8)
                {
                    /* use uint8 buffer mode */
                    DlcEv_pt->TxProp_t.Tx.Data_u16 = ((Spi_DlcFrame8PtrType)ChBufTx_pt->Spi_Tx_pt)[TxPos_u16];
                }
                else
                {
                    /* use uint16 buffer mode */
                    DlcEv_pt->TxProp_t.Tx.Data_u16 = ((Spi_DlcFrame16PtrType)ChBufTx_pt->Spi_Tx_pt)[TxPos_u16];
                }
            }
            /* data filled, increase count */
            TxPos_u16++;
            if(TxPos_u16 < ChBufTx_pt->Spi_TxRxLength)
            {
                /* write data back for next transfer */
                DlcEv_pt->Pos_u16[SPI_DLC_TX] = TxPos_u16;
            }
            else
            {
                /* Spi_DlcSwitchChannel changes the Guard_u8 state if a channel end has been reached */
                Spi_DlcSwitchChannel(DlcEv_pt,
                                     &DlcEv_pt->TxProp_t.Tx.Ctrl_u16,
                                     SPI_DLC_TX);
            }
        }
        break;

        default:
        break;
    }
    return;
}

static FUNC(void, SPI_CODE) Spi_Dlc(Std, DrainData)(Spi_DlcEventPtrType DlcEv_pt)
{
    Spi_BufferDescriptorPtrType ChBufRx_pt; /* pointer to channel buffer internal or external */
    Spi_ChannelConfigPtrType ChCfg_pt;      /* pointer to channel configuration */
    uint16 RxPos_u16;    /* buffer filled counter, increases with each successful write/read to MIB Ram */
    uint16 DataLoc_u16;  /* local data value */
    uint8  ChIDRx_u8;    /* channel identifier, used as index */

    /* in this module we try to transmit one or more channels, depending on the configuration */
    switch(DlcEv_pt->Guard_u8)
    {
        case SPI_DLC_G_ACTIVE:
        case SPI_DLC_G_FINISHED:
        ChIDRx_u8  = DlcEv_pt->ID_u8[SPI_DLC_RX];
        RxPos_u16  = DlcEv_pt->Pos_u16[SPI_DLC_RX];
        ChBufRx_pt = Spi_ConfigPtr_pt->Spi_ChannelCfg[ChIDRx_u8].Spi_Descriptor;
        ChCfg_pt   = &Spi_ConfigPtr_pt->Spi_ChannelCfg[ChIDRx_u8];

        /* drains data from Spi register to channel(s)*/
        /* read of this register resets the RX flag to 1 */
        SPI_REG(R_, USER_, 16BIT)(DlcEv_pt->RxStat_t.Rx.Stat_u16,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.Rx.Stat_u16,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* ready to drain ? */
        if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_RXEMPTY))
        {
            /* this should not happen! */
            Spi_IrqTxRxERR(DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID);
        }
        else
        {
            SPI_REG(R_, USER_, 16BIT)(DataLoc_u16,
                                      DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.Rx.Data_u16,
                                      DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
            if(ChBufRx_pt->Spi_Rx_pt == NULL_PTR)
            {
                /* skip any data, but data must be read to clear the flag, see line above */
            }
            else
            {
                /* read bytes to the channel */
                if(ChCfg_pt->Spi_DataWidth <= 8)
                {
                    /* use uint8 buffer mode */
                    ((Spi_DlcFrame8PtrType)ChBufRx_pt->Spi_Rx_pt)[RxPos_u16] = (uint8)DataLoc_u16;
                }
                else
                {
                    /* use uint16 buffer mode */
                    ((Spi_DlcFrame16PtrType)ChBufRx_pt->Spi_Rx_pt)[RxPos_u16] = DataLoc_u16;
                }
            }
            /* data drained, increase count */
            RxPos_u16++;
            if(RxPos_u16 < ChBufRx_pt->Spi_TxRxLength)
            {
                /* write data back for next transfer */
                DlcEv_pt->Pos_u16[SPI_DLC_RX]++;
            }
            else
            {
                Spi_DlcSwitchChannel(DlcEv_pt,
                                     NULL_PTR,
                                     SPI_DLC_RX);
            }
        }
        break;

        default:
        break;
    }
}

static FUNC(void, SPI_CODE) Spi_Dlc(Std, TriggerData)(Spi_DlcEventPtrType DlcEv_pt)
{
    /* activate CS# line and write first data */
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DAT1.TxData_u32,
                              DlcEv_pt->TxProp_t.TxData_u32,
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

static FUNC(void, SPI_CODE) Spi_Dlc(Std, Transmit)(Spi_DlcEventPtrType DlcEv_pt)
{
    /* avoid a compiler warning */
    DlcEv_pt->RxStat_t.Rx.Stat_u16 = 0;
    return;
}


static FUNC(void, SPI_CODE) Spi_Dlc(Std, Error)(Spi_DlcEventPtrType DlcEv_pt)
{
    volatile uint32 RxBuf_u32;

    RxBuf_u32 = SPI_DLC_RXBUFCTRL_TXFULL;
    /* poll register as long TX is full */
    while((SPI_DLC_CHECK_HEX32(RxBuf_u32, SPI_DLC_RXBUFCTRL_TXFULL)))
    {
        /* dummy read on this register cell */
        SPI_REG(R_, USER_, 32BIT)(RxBuf_u32,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.RxData_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    /* poll register as long RX is not empty */
    while((SPI_DLC_CHECK_NOT_HEX32(RxBuf_u32, SPI_DLC_RXBUFCTRL_RXEMPTY)))
    {
        /* dummy read on this register cell */
        SPI_REG(R_, USER_, 32BIT)(RxBuf_u32,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.RxData_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    /* prepare dummy data, required to take the CS# back */
    DlcEv_pt->TxProp_t.Tx.Data_u16 = DlcEv_pt->Default_u16[SPI_DLC_TX];
    /* update the control field */
    SPI_DLC_CLRVAL16(DlcEv_pt->TxProp_t.Tx.Ctrl_u16, SPI_DLC_TXRAMCTRL_CSHOLD);

    /* de-activate the CS# by sending a dummy data byte */
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DAT1.TxData_u32,
                              DlcEv_pt->TxProp_t.Tx.Ctrl_u16,
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}
#endif

/***********************************************************************************************************************
 *  Start section of  MIBRAM specialized functions
 **********************************************************************************************************************/

#if (SPI_HARDWAREUNIT_USE_RAM == STD_ON)

static FUNC(void, SPI_CODE) Spi_Dlc(Ram, Init) (Spi_DlcEventPtrType DlcEv_pt)
{
    uint32 Status_u32 ;

    /* enable MIB SPI to get access to the MIB registers */
    SPI_REG(W_, PRIV_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_EN,
                                   SPI_DLC_MIBSPIE_EN(1),
                                   DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* verify that the MIB ram finished auto initialization */
    Status_u32 = SPI_DLC_BUFINIT;
    while(Status_u32 == SPI_DLC_BUFINIT)
    {
        SPI_REG(G_, USER_, 32BIT_INIT)(Status_u32,
                                       DlcEv_pt->MUnit_pt->Reg_pt->Spi_FLG,
                                       SPI_DLC_BUFINIT,
                                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    /* prepare TG(x) ctrl register */
    /* set PStart to 0, we use the whole MIB RAM as one TG */
    SPI_REG(W_, USER_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGCTRL[0],
                                   0,
                                   DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* store end address in LTGPEND register bit 14::8 */
    SPI_REG(W_, USER_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_LTGPEND,
                                   SPI_DLC_LTGPEND_LPEND(SPI_DLC_MIBTXSIZE - 1),
                                   DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    SPI_REG(W_, USER_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGITLVST,
                                   SPI_DLC_TGITLVST_SETINTLEVEL(1,16),
                                   DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

static FUNC(void, SPI_CODE) Spi_Dlc(Ram, Close)(Spi_DlcEventPtrType DlcEv_pt)
{
    uint32 MibIdx_u32;                 /* index in MIBRAM */
    volatile uint16 DataLoc_u32;       /* dummy data for read */

    /* disable interrupts */
    Spi_Dlc(Ram, DeIsr)(DlcEv_pt);
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGCTRL[0],
                       SPI_DLC_BITCLR,
                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TICKCNT,
                       SPI_DLC_BITCLR,
                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_LTGPEND,
                       SPI_DLC_BITCLR,
                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGITLVST,
                       SPI_DLC_BITCLR,
                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGITENCR,
                       SPI_DLC_BITCLR,
                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    for(MibIdx_u32 = 0; MibIdx_u32 < SPI_DLC_MIBRXSIZE; MibIdx_u32++)
    {
        /* read whole MIBRAM to reset all status flags */
        SPI_REG(R_, USER_, 32BIT)(DataLoc_u32,
                          DlcEv_pt->MUnit_pt->Ram_pt->Spi_RxBank[MibIdx_u32].RxData_u32,
                          DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamArea);
        /* avoid a compiler warning */
        DataLoc_u32++;
    }
    /* clear SPI_DLC_MIBSPI enable bit, this must be done at last */
    /* the bit works as switch to enable access to the SPI_DLC_MIBSPI registers */
    SPI_REG(C_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_EN,
                     SPI_DLC_MIBSPIE_EN(1),
                     DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

static FUNC(void, SPI_CODE) Spi_Dlc(Ram, EnIsr) (Spi_DlcEventPtrType DlcEv_pt)
{
    /* enable the TG[0] interrupt generation (Value, bit for TG enable Irq) */
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGITENST,
                              SPI_DLC_TGITENST_SETINTENRDY(1,16),
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

static FUNC(void, SPI_CODE) Spi_Dlc(Ram, DeIsr) (Spi_DlcEventPtrType DlcEv_pt)
{
    /* disable the TG[0] interrupt generation (Value, bit for TG enable Irq), caution (set, clear) register */
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGITENCR,
                              SPI_DLC_TGITENST_SETINTENRDY(1,16),
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}


static FUNC(void, SPI_CODE) Spi_Dlc(Ram, FillData)(Spi_DlcEventPtrType DlcEv_pt)
{
    Spi_BufferDescriptorPtrType ChBufTx_pt; /* pointer to Tx channel buffer */
    Spi_ChannelConfigPtrType ChCfg_pt;      /* pointer to channel configuration */
    uint16 TgLen_u16;    /* local transfer group length */
    uint16 TxPos_u16;    /* buffer filled counter, increases with each successful write/read to MIB Ram */
    uint8  ChIDTx_u8;    /* channel identifier, Rx used as index */

    switch(DlcEv_pt->Guard_u8)
    {
        case SPI_DLC_G_PENDING:
        DlcEv_pt->Guard_u8 = (uint8)SPI_DLC_G_ACTIVE;
        /* fall through */

        case SPI_DLC_G_ACTIVE:
        /* mark the transfer group */
        TgLen_u16  = 0;
        /* channel values were set by Spi_DlcSwitchChannel() , now update the register */
        SPI_REG(W_, PRIV_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_FMT[0],
                           DlcEv_pt->ChProp_u32,
                           DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* in this module we try to transmit one or more channels, depending on the configuration
         * max transfer amount per transfer group
         */
        while(TgLen_u16 < SPI_DLC_TG_LEN)
        {
            ChIDTx_u8 = DlcEv_pt->ID_u8[SPI_DLC_TX];
            TxPos_u16 = DlcEv_pt->Pos_u16[SPI_DLC_TX];
            /* handle buffers for Tx and Rx */
            ChCfg_pt    = &Spi_ConfigPtr_pt->Spi_ChannelCfg[ChIDTx_u8];
            ChBufTx_pt  = ChCfg_pt->Spi_Descriptor;
            /*
            * this loop transfers data from the channel(s) to RAM
            * and uses interrupts to transfer and reload the data
            */
            while(TxPos_u16 < ChBufTx_pt->Spi_TxRxLength)
            {
                /* check i transfer group is full */
                if(TgLen_u16 == SPI_DLC_TG_LEN)
                {
                    /* transfer group is full, write position back and leave */
                    DlcEv_pt->Pos_u16[SPI_DLC_TX] = TxPos_u16;
                    return;
                }
                else
                {
                    /* no action */
                }
                /* get Mib status */
                SPI_REG(R_, USER_, 16BIT)(DlcEv_pt->RxStat_t.Rx.Stat_u16,
                                  DlcEv_pt->MUnit_pt->Ram_pt->Spi_RxBank[TgLen_u16].Rx.Stat_u16,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamArea);
                /* ready to fill ? */
                /* the ram buffer should only be filled if the flag is zero, otherwise the data was not transmitted */
                if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_TXFULL))
                {
                    /* in an error case, mark the position and handle the error */
                    DlcEv_pt->Pos_u16[SPI_DLC_TX] = TxPos_u16;
                    /* this should not happen! */
                    Spi_IrqTxRxERR(DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID);
                    return;
                }
                else
                {
                    /* setup data */
                    if(ChBufTx_pt->Spi_Tx_pt == NULL_PTR)
                    {
                        /* write default data */
                        DlcEv_pt->TxProp_t.Tx.Data_u16 = DlcEv_pt->Default_u16[SPI_DLC_TX];
                    }
                    else
                    {
                        /* write bytes to the channel */
                        if(ChCfg_pt->Spi_DataWidth <= 8)
                        {
                            /* use uint8 buffer mode */
                            DlcEv_pt->TxProp_t.Tx.Data_u16 = ((Spi_DlcFrame8PtrType)ChBufTx_pt->Spi_Tx_pt)[TxPos_u16];
                        }
                        else
                        {
                            /* use uint16 buffer mode */
                            DlcEv_pt->TxProp_t.Tx.Data_u16 = ((Spi_DlcFrame16PtrType)ChBufTx_pt->Spi_Tx_pt)[TxPos_u16];
                        }
                    }
                    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Ram_pt->Spi_TxBank[TgLen_u16].TxData_u32,
                                              DlcEv_pt->TxProp_t.TxData_u32,
                                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamArea);
                    /* data filled, increase count */
                    TxPos_u16++;
                    TgLen_u16++;
                }
            }
            /* switch channel and update channel properties */
            Spi_DlcSwitchChannel(DlcEv_pt,
                                 &DlcEv_pt->MUnit_pt->Ram_pt->Spi_TxBank[(TgLen_u16-1)].Tx.Ctrl_u16 ,
                                 SPI_DLC_TX);
            break;
        }
        break;

        default:
        break;
    }
    return;
}


static FUNC(void, SPI_CODE) Spi_Dlc(Ram, DrainData)(Spi_DlcEventPtrType DlcEv_pt)
{
    Spi_BufferDescriptorPtrType ChBufRx_pt; /* pointer to channel buffer internal or external */
    Spi_ChannelConfigPtrType ChCfg_pt;      /* pointer to channel configuration */
    uint16 DataLoc_u16;   /* local data value from MIB Ram register */
    uint16 TgLen_u16;     /* local transfer group length */
    uint16 RxPos_u16;     /* buffer filled counter, increases with each successful write/read to MIB Ram */
    uint8  ChIDRx_u8;     /* channel identifier, used as index */

    /* in this module we try to transmit one or more channels, depending on the configuration */
    switch(DlcEv_pt->Guard_u8)
    {
        case SPI_DLC_G_ACTIVE:
        case SPI_DLC_G_FINISHED:
        /* mark the transfer group */
        TgLen_u16  = 0;

        /* copy data to mib Rx buffer */
        /* in this module we try to transmit one or more channels, depending on the configuration */
        /* max transfer amount per transfer group */
        while(TgLen_u16 < SPI_DLC_TG_LEN)
        {
            ChIDRx_u8  = DlcEv_pt->ID_u8[SPI_DLC_RX];
            RxPos_u16  = DlcEv_pt->Pos_u16[SPI_DLC_RX];
            /* handle buffers for Rx */
            ChCfg_pt   = &Spi_ConfigPtr_pt->Spi_ChannelCfg[ChIDRx_u8];
            ChBufRx_pt = ChCfg_pt->Spi_Descriptor;
            /* this loop drains data from MIB ram to the channel(s)*/
            while(RxPos_u16 < ChBufRx_pt->Spi_TxRxLength)
            {
                if(TgLen_u16 == SPI_DLC_TG_LEN)
                {
                    /* transfer group is full, write position back and leave */
                    DlcEv_pt->Pos_u16[SPI_DLC_RX] = RxPos_u16;
                    return;
                }
                /* access MIB ram */
                /* read of this register resets the RX flag to 1 */
                SPI_REG(R_, USER_, 16BIT)(DlcEv_pt->RxStat_t.Rx.Stat_u16,
                                  DlcEv_pt->MUnit_pt->Ram_pt->Spi_RxBank[TgLen_u16].Rx.Stat_u16,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamArea);
                /* ready to drain ? */
                if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_RXEMPTY))
                {
                    /* in an error case, mark the position and handle the error */
                    DlcEv_pt->Pos_u16[SPI_DLC_RX] = RxPos_u16;
                    /* this should not happen! */
                    Spi_IrqTxRxERR(DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID);
                    return;
                }
                else
                {
                    SPI_REG(R_, USER_, 16BIT)(DataLoc_u16,
                                      DlcEv_pt->MUnit_pt->Ram_pt->Spi_RxBank[TgLen_u16].Rx.Data_u16,
                                      DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamArea);
                    if(ChBufRx_pt->Spi_Rx_pt == NULL_PTR)
                    {
                        /* skip any data, but data must be read to clear the flag, see line above */
                    }
                    else
                    {
                        /* read bytes to the channel */
                        if(ChCfg_pt->Spi_DataWidth <= 8)
                        {
                            /* use uint8 buffer mode */
                            ((Spi_DlcFrame8PtrType)ChBufRx_pt->Spi_Rx_pt)[RxPos_u16] = (uint8)DataLoc_u16;
                        }
                        else
                        {
                            /* use uint16 buffer mode */
                            ((Spi_DlcFrame16PtrType)ChBufRx_pt->Spi_Rx_pt)[RxPos_u16] = DataLoc_u16;
                        }
                    }
                    /* data drained, increase count */
                    RxPos_u16++;
                    TgLen_u16++;
                }
            }
            /* all bytes in a channel have been treated, select next channel */
            Spi_DlcSwitchChannel(DlcEv_pt,
                                 NULL_PTR,
                                 SPI_DLC_RX);
            break;
        }
        break;

        default:
        break;
    }
}

static FUNC(void, SPI_CODE) Spi_Dlc(Ram, TriggerData)(Spi_DlcEventPtrType DlcEv_pt)
{
     /* transfer group is ready for transfer, trigger interrupt generation */
    SPI_REG(S_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGCTRL[0],
                     SPI_DLC_TGCTRL_TGENA(1),
                     DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

static FUNC(void, SPI_CODE) Spi_Dlc(Ram, Transmit)(Spi_DlcEventPtrType DlcEv_pt)
{
    /* set trigger event (both edges) and trigger source (internal trigger)
     * start transfer every time the TG_ENA is set
     */
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGCTRL[0],
                       SPI_DLC_TGCTRL_TRIGSRC(0x0) | SPI_DLC_TGCTRL_TRIGEVT(0x7),
                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* enable oneshot */
    SPI_REG(S_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGCTRL[0],
                     SPI_DLC_TGCTRL_TGONESHOT(1),
                     DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* buffer mode 3 */
    SPI_DLC_SETVAL16(DlcEv_pt->TxProp_t.Tx.Ctrl_u16, SPI_DLC_TXCTRL_BUFMOD(3));
    return;
}


static FUNC(void, SPI_CODE) Spi_Dlc(Ram, Error)(Spi_DlcEventPtrType DlcEv_pt)
{
    volatile uint16 RxData_u16;
    volatile uint32 Status_u32;
    uint16 RxPos_u16;

    /* check if a transfer is pending */
    SPI_REG(R_, USER_, 32BIT)(Status_u32,
                              DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGCTRL[0] ,
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    if(SPI_DLC_CHECK_NOT_HEX32(Status_u32, SPI_DLC_TGCTRL_TGENA(1)))
    {
        /* trigger TG if TG was not triuggered */
        Spi_DlcRamTriggerData(DlcEv_pt);
    }
    else
    {
        /* TG is enabled and has been triggered */
    }
    /* check TG interrupt flag */
    SPI_REG(R_, USER_, 32BIT)(Status_u32,
                              DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGINTFLAG ,
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    while(SPI_DLC_CHECK_NOT_HEX32(Status_u32, SPI_DLC_TG0_INTFLG))
    {
        SPI_REG(R_, USER_, 32BIT)(Status_u32,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGINTFLAG ,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    /* dummy read on this RAM cell(s) */
    for(RxPos_u16 = 0; RxPos_u16 < SPI_DLC_TG_LEN; RxPos_u16++)
    {
        SPI_REG(R_, USER_, 32BIT)(RxData_u16,
                          DlcEv_pt->MUnit_pt->Ram_pt->Spi_RxBank[RxPos_u16].RxData_u32,
                          DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamArea);
    }
    /* dummy read interrupt status register */
    SPI_REG(G_, USER_, 32BIT)(Status_u32,
                              DlcEv_pt->MUnit_pt->Reg_pt->Spi_TGINTVECT[1],
                              SPI_DLC_TGINTVECT_INTVEC(0x1F),
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* clear the TG interrupt flag, necessary to prevent upcomming interrupts for TGx */
    SPI_REG(S_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_RegTGCTL.Spi_TGINTFLAG,
                              SPI_DLC_TGCTRL_INTFLAG(0),
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

#endif

/***********************************************************************************************************************
 *  Start section of  STD DMA specialized functions
 **********************************************************************************************************************/
#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)

static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Init) (Spi_DlcEventPtrType DlcEv_pt)
{
    Dma_Init();
}

static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Close)(Spi_DlcEventPtrType DlcEv_pt)
{
    volatile uint16 DataLoc_u32; /* dummy data for read */

    /* disable interrupts */
    Spi_Dlc(StdDma, DeIsr)(DlcEv_pt);
    SPI_REG(R_, USER_, 32BIT)(DataLoc_u32,
                      DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.RxData_u32,
                      DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* avoid a compiler warning */
    DataLoc_u32++;
    Dma_DeInit();

}

static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, EnIsr) (Spi_DlcEventPtrType DlcEv_pt)
{
    /* only enable error tracing */
    SPI_REG(S_, PRIV_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_INT0,
                             (
                                 SPI_DLC_INT0_RXOVR   |
                                 SPI_DLC_INT0_TOERR   |
                                 SPI_DLC_INT0_DLENERR |
                                 SPI_DLC_INT0_BITERR
                             ),
                             DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* enable BTC interrupts only on channel RX (RX ready) */
    SPI_REG(W_, PRIV_, 32BIT)(DMA_GLOBAL_REGISTER_BASE_ADDRESS->DMA_BTCINTENAS,
                             (1 << SPI_DLC_RX),
                             OS_MEM_AREA_DMA_REG);
}

static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, DeIsr) (Spi_DlcEventPtrType DlcEv_pt)
{
    /* disable DMA request generation and
     * disable error tracing
     */
    SPI_REG(C_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_INT0,
                             (
                                 SPI_DLC_DMA_EN_MASK  |
                                 SPI_DLC_INT0_RXOVR   |
                                 SPI_DLC_INT0_TOERR   |
                                 SPI_DLC_INT0_DLENERR |
                                 SPI_DLC_INT0_BITERR
                             ),
                             DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* disable BTC interrupts only on channel 0 (Rx ready) and channel 1 (TX ready) */
    SPI_REG(W_, PRIV_, 32BIT)(DMA_GLOBAL_REGISTER_BASE_ADDRESS->DMA_BTCINTENAR,
                              (1 << SPI_DLC_RX) | (1 << SPI_DLC_TX),
                              OS_MEM_AREA_DMA_REG);
    /* clear BTC flags on TX and RX channels */
    SPI_REG(W_, PRIV_, 32BIT)(DMA_GLOBAL_REGISTER_BASE_ADDRESS->DMA_BTCFLAG,
                              (1 << SPI_DLC_RX) | (1 << SPI_DLC_TX),
                              OS_MEM_AREA_DMA_REG);
}

/* must be 16 bit aligned */
#define SPI_DLCDMA_MAXFCOUNT    (0x1FFE)
static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Prepare) (Spi_DlcEventPtrType DlcEv_pt)
{
    Spi_BufferDescriptorPtrType ChBuf_pt;   /* pointer to Tx channel buffer */
    Spi_ChannelConfigPtrType ChCfg_pt;      /* pointer to channel configuration */
    Dma_ChannelSetupPtrType ChSetup_pt;     /* pointer to DMA setup structure */
    uint16 Offset_u16; /* offset in application buffer */
    uint16 LgtCh_u16;  /* current channel length */
    uint16 LgtIdx_u16; /* channel index */
    uint8  ChID_u8;    /* id of a channel */
    uint8  ChNum_u8;   /* number of channels */

    /* to trigger a Dma transfer, the first data must be manually written to the register
     *  to handle this, the value OffsetTx_u8 is added to address and subtracted from length
     */
    /* channel values were set by Spi_DlcSwitchChannel() , now update the register */
    SPI_REG(W_, PRIV_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_FMT[0],
                              DlcEv_pt->ChProp_u32,
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    for (ChID_u8 = 0; ChID_u8 < 2; ChID_u8++)
    {
        /* address next element by incrementing the address is not used */
        Spi_DlcDmaChSetup[ChID_u8].EIDstInc = 0;
        Spi_DlcDmaChSetup[ChID_u8].EISrcInc = 0;
        Spi_DlcDmaChSetup[ChID_u8].FISrcInc = 0;
        Spi_DlcDmaChSetup[ChID_u8].FIDstInc = 0;
    }
    Spi_DlcStdDmaUnit = DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID;
    ChSetup_pt = &Spi_DlcDmaChSetup[SPI_DLC_TX];
    ChID_u8    = DlcEv_pt->ID_u8[SPI_DLC_TX];
    ChNum_u8   = Spi_ConfigPtr_pt->Spi_JobCfg[DlcEv_pt->JobID_u8].Spi_ChannelList[0];
    /* backup hardware unit for ISR */
    ChBuf_pt = Spi_ConfigPtr_pt->Spi_ChannelCfg[ChID_u8].Spi_Descriptor;
    ChCfg_pt = &Spi_ConfigPtr_pt->Spi_ChannelCfg[ChID_u8];
    /* DMA strategy:
     * 1st setup the Tx control field manually
     * 2nd prepare DMA channel[0] with destination [Spi Tx data register] and source [application buffer]
     * 3rd prepare DMA channel with destination [Spi Tx control and data] and source location where the control field
     * and the last byte/word are located if a job end is in sight - else the DMA channel [0, 1] are sufficient for Tx
     * and Rx
     * 4th The 1st Dma_setup configures the DMA direct, the last job settings are stored in RAM to be initialized by
     * Dma_Setup in the BTC Isr. The STD unit DMA is frame transfer driven(see manual)!
     * Proceed with Rx in the same way but with channel[1]
     */

    /* clear DMA BTC flags, required to prevent unwanted interrupts from i.e. TX BTC end, where the interrupt
     * is not needed but the flag is set!
     */
     SPI_REG(W_, USER_, 32BIT)(Dma_GlobalRegister->DMA_BTCFLAG,
                               0x0000FFFF,
                               OS_MEM_AREA_DMA_REG);

    Offset_u16 = DlcEv_pt->Pos_u16[SPI_DLC_TX];
    LgtCh_u16  = ChBuf_pt->Spi_TxRxLength - Offset_u16;
     /* check if the channel length exceeds valid DMA transfer count
     */
    if(LgtCh_u16 > SPI_DLCDMA_MAXFCOUNT)
    {
        LgtCh_u16 = SPI_DLCDMA_MAXFCOUNT;
        DlcEv_pt->ChState_u8 = SPI_DLC_ST_PENDING;
    }
    else
    {
        /* channel finishes with this transfer */
        DlcEv_pt->ChState_u8 = SPI_DLC_ST_FINISHED;
    }
    /* use a small internal buffer for a small number of data to keep the timings */
    ChSetup_pt->Unit   = DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID;
    ChSetup_pt->Channel = SPI_DLC_TX;
    ChSetup_pt->Dir     = SPI_DLC_TX;
    /* set element count */
    ChSetup_pt->ECount  = 1;
    ChSetup_pt->ChEn = 1;
    DlcEv_pt->Lgt_u16[SPI_DLC_TX] = LgtCh_u16;
    DlcEv_pt->Lgt_u16[SPI_DLC_RX] = LgtCh_u16;
    if(LgtCh_u16 < SPI_DLC_DMA_BUF_SIZE)
    {
        /* Setup transfer parameters */
        ChSetup_pt->FCount  = LgtCh_u16;
        ChSetup_pt->DstAddr = (uint32)&DlcEv_pt->MUnit_pt->Reg_pt->Spi_DAT1.TxData_u32;
        ChSetup_pt->SrcAddr = (uint32)&Spi_DlcDmaChData[0].TxData_u32;
        /* use 32bit transfers from src + post increment to dest + const
         * increase source only
         */
        ChSetup_pt->ChCtrl = DMA_TX32_INCSO;
        /* the entry value updates the CS# value */
        for(LgtIdx_u16 = 0; LgtIdx_u16 < (LgtCh_u16 - 1); LgtIdx_u16++)
        {
            SPI_DLC_WRITEVAL16(Spi_DlcDmaChData[LgtIdx_u16].Tx.Ctrl_u16 , DlcEv_pt->TxProp_t.Tx.Ctrl_u16);
        }
        /* update the ending CS# field */
        SPI_DLC_WRITEVAL16(Spi_DlcDmaChData[LgtIdx_u16].Tx.Ctrl_u16 , DlcEv_pt->TxEProp_t.Tx.Ctrl_u16);
        if(ChBuf_pt->Spi_Tx_pt == NULL_PTR)
        {
            for(LgtIdx_u16 = 0; LgtIdx_u16 < LgtCh_u16; LgtIdx_u16++)
            {
                SPI_DLC_WRITEVAL16(Spi_DlcDmaChData[LgtIdx_u16].Tx.Data_u16 , DlcEv_pt->Default_u16[SPI_DLC_TX]);
            }
        }
        else
        {
            if(ChCfg_pt->Spi_DataWidth <= 8)
             {
                for(LgtIdx_u16 = 0; LgtIdx_u16 < LgtCh_u16; LgtIdx_u16++)
                {
                    SPI_DLC_WRITEVAL16(Spi_DlcDmaChData[LgtIdx_u16].Tx.Data_u16,
                                       ((Spi_DlcFrame8PtrType)ChBuf_pt->Spi_Tx_pt)[Offset_u16 + LgtIdx_u16]);
                }
             }
             else
             {
                 for(LgtIdx_u16 = 0; LgtIdx_u16 < LgtCh_u16; LgtIdx_u16++)
                 {
                     SPI_DLC_WRITEVAL16(Spi_DlcDmaChData[LgtIdx_u16].Tx.Data_u16,
                                        ((Spi_DlcFrame16PtrType)ChBuf_pt->Spi_Tx_pt)[Offset_u16 + LgtIdx_u16]);
                 }
             }
        }
    }
    else
    {
        /* last channel in a job detected ? */
        if(  (DlcEv_pt->ChState_u8 == SPI_DLC_ST_FINISHED)
          && (DlcEv_pt->Event_u8   == SPI_DLC_EV_ASYNCTX ))
        {
            /* check for channel end */
            if(DlcEv_pt->Num_u8[SPI_DLC_TX] >= ChNum_u8)
            {
                LgtCh_u16--;
                /* enable BTC interrupts only on channel TX (TX ready) */
                SPI_REG(S_, PRIV_, 32BIT)(DMA_GLOBAL_REGISTER_BASE_ADDRESS->DMA_BTCINTENAS,
                                         (1 << SPI_DLC_TX),
                                         OS_MEM_AREA_DMA_REG);
            }
            else
            {
                /* no action */
            }
        }
        /* prepare first data transmission */
        if(ChBuf_pt->Spi_Tx_pt == NULL_PTR)
        {
            SPI_DLC_WRITEVAL16(DlcEv_pt->TxProp_t.Tx.Data_u16 , DlcEv_pt->Default_u16[SPI_DLC_TX]);
            SPI_DLC_WRITEVAL16(DlcEv_pt->TxEProp_t.Tx.Data_u16 , DlcEv_pt->Default_u16[SPI_DLC_TX]);
        }
        else
        {
            if(ChCfg_pt->Spi_DataWidth <= 8)
            {
                SPI_DLC_WRITEVAL16(DlcEv_pt->TxProp_t.Tx.Data_u16,
                                   ((Spi_DlcFrame8PtrType)ChBuf_pt->Spi_Tx_pt)[Offset_u16]);
                SPI_DLC_WRITEVAL16(DlcEv_pt->TxEProp_t.Tx.Data_u16,
                                   ((Spi_DlcFrame8PtrType)ChBuf_pt->Spi_Tx_pt)[ChBuf_pt->Spi_TxRxLength - 1]);
            }
            else
            {
                SPI_DLC_WRITEVAL16(DlcEv_pt->TxProp_t.Tx.Data_u16,
                                   ((Spi_DlcFrame16PtrType)ChBuf_pt->Spi_Tx_pt)[Offset_u16]);
                SPI_DLC_WRITEVAL16(DlcEv_pt->TxEProp_t.Tx.Data_u16,
                                   ((Spi_DlcFrame16PtrType)ChBuf_pt->Spi_Tx_pt)[ChBuf_pt->Spi_TxRxLength - 1]);
            }
        }
        Offset_u16++;
        /* set frame count, is LgtCh_u16 - 1 due to the first data is written direct to
         * register triggering the first transfer
         */
        ChSetup_pt->FCount  = LgtCh_u16 - 1;
        /* Setup transfer parameters */
        ChSetup_pt->DstAddr = (uint32)&DlcEv_pt->MUnit_pt->Reg_pt->Spi_DAT1.Tx.Data_u16;
        if(ChBuf_pt->Spi_Tx_pt == NULL_PTR)
        {
            ChSetup_pt->SrcAddr = (uint32)&DlcEv_pt->Default_u16[SPI_DLC_TX];
            /* 8 bit DMA: source and destination are 16bit aligned so to access the lower value in big endian
             * the address has to be increased [xxDD];   [xxDD]
             *                  starting here   ^  moving to ^
             *                  this applies to source address as well as the destination address
             */
            if(ChCfg_pt->Spi_DataWidth <= 8)
            {
                ChSetup_pt->ChCtrl = DMA_TX08_CONST;
                /* to transmit real 8bit via Dma, the source and destination must be increased by one */
                ChSetup_pt->DstAddr++;
                ChSetup_pt->SrcAddr++;
            }
            else
            {
                ChSetup_pt->ChCtrl = DMA_TX16_CONST;
            }
        }
        else
        {
            if(ChCfg_pt->Spi_DataWidth <= 8)
            {
                ChSetup_pt->ChCtrl = DMA_TX08_INCSO;
                /* to transmit real 8bit via Dma, the destination must be increased */
                ChSetup_pt->DstAddr++;
                ChSetup_pt->SrcAddr  = (uint32) &((Spi_DlcFrame8PtrType)ChBuf_pt->Spi_Tx_pt)[Offset_u16];
            }
            else
            {
                ChSetup_pt->ChCtrl = DMA_TX16_INCSO;
                /* set the address to a aligned 16 bit address */
                ChSetup_pt->SrcAddr  = (uint32) &((Spi_DlcFrame16PtrType)ChBuf_pt->Spi_Tx_pt)[Offset_u16];
            }
        }
    }
    /* finally setup TX DMA channel */
    Dma_Setup(ChSetup_pt);
    /* now the DMA is prepared for Tx, prepare next channel for Rx */
    /* setup channel 1 for std and read the data field.
     * incoming data to the Spi_BUF field register generates the DMA Rx requests
     */
    Offset_u16 = DlcEv_pt->Pos_u16[SPI_DLC_RX];
    ChSetup_pt = &Spi_DlcDmaChSetup[SPI_DLC_RX];
    ChSetup_pt->Unit    = DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID;
    ChSetup_pt->Channel = SPI_DLC_RX;
    ChSetup_pt->Dir     = SPI_DLC_RX;
    ChSetup_pt->SrcAddr = (uint32)&DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.Rx.Data_u16;
    /* set frame count   */
    ChSetup_pt->FCount = DlcEv_pt->Lgt_u16[SPI_DLC_RX];
    /* set element count */
    ChSetup_pt->ECount = 1;
    if(ChBuf_pt->Spi_Rx_pt == NULL_PTR)
    {
        ChSetup_pt->DstAddr = (uint32)&DlcEv_pt->Default_u16[SPI_DLC_RX];
        if(ChCfg_pt->Spi_DataWidth <= 8)
        {
            ChSetup_pt->ChCtrl = DMA_RX08_CONST;
            /* to receive real 8bit via Dma, the source and destination must be increased */
            ChSetup_pt->DstAddr++;
            ChSetup_pt->SrcAddr++;
        }
        else
        {
            ChSetup_pt->ChCtrl = DMA_RX16_CONST;
        }
    }
    else
    {
        if(ChCfg_pt->Spi_DataWidth <= 8)
        {
            ChSetup_pt->ChCtrl = DMA_RX08_INCDO;
            /* to receive real 8bit via Dma, the source must be increased */
            ChSetup_pt->SrcAddr++;
            /* write data to Rx channel */
            ChSetup_pt->DstAddr  = (uint32) &((Spi_DlcFrame8PtrType)ChBuf_pt->Spi_Rx_pt)[Offset_u16];
        }
        else
        {
            ChSetup_pt->ChCtrl = DMA_RX16_INCDO;
            /* write data to Rx channel */
            ChSetup_pt->DstAddr  = (uint32) &((Spi_DlcFrame16PtrType)ChBuf_pt->Spi_Rx_pt)[Offset_u16];
        }
    }
    /* finally setup RX DMA channel */
    ChSetup_pt->ChEn = 1;
    Dma_Setup(ChSetup_pt);
    /* write position back */
    DlcEv_pt->Pos_u16[SPI_DLC_TX] += LgtCh_u16;
    DlcEv_pt->Pos_u16[SPI_DLC_RX] += LgtCh_u16;
}

static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, TriggerData)(Spi_DlcEventPtrType DlcEv_pt)
{
    if(DlcEv_pt->Lgt_u16[SPI_DLC_TX] >= SPI_DLC_DMA_BUF_SIZE)
    {
        /* activate CS# line and write first data */
        SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DAT1.TxData_u32,
                                  DlcEv_pt->TxProp_t.TxData_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    else
    {
        /* no action */
    }
    /* trigger the DMA request generation */
     SPI_REG(S_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_INT0,
                               SPI_DLC_DMA_EN_MASK,
                               DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
}

static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Transmit)(Spi_DlcEventPtrType DlcEv_pt)
{
    /* avoid a compiler warning */
    DlcEv_pt->TxProp_t.Tx.Data_u16 = 0;
}

static FUNC(void, SPI_CODE) Spi_Dlc(StdDma, Error)(Spi_DlcEventPtrType DlcEv_pt)
{
    Dma_ChannelSetupPtrType ChSetup_pt;
    volatile uint32 RxBuf_u32;

    RxBuf_u32 = SPI_DLC_RXBUFCTRL_TXFULL;
    /* poll register as long TX is full */
    while((SPI_DLC_CHECK_HEX32(RxBuf_u32, SPI_DLC_RXBUFCTRL_TXFULL)))
    {
        /* dummy read on this register cell */
        SPI_REG(R_, USER_, 32BIT)(RxBuf_u32,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.RxData_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    /* poll register as long RX is not empty */
    while(SPI_DLC_CHECK_NOT_HEX32(RxBuf_u32, SPI_DLC_RXBUFCTRL_RXEMPTY))
    {
        /* dummy read on this register cell */
        SPI_REG(R_, USER_, 32BIT)(RxBuf_u32,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.RxData_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    /* prepare dummy data, required to take the CS# back */
    DlcEv_pt->TxProp_t.Tx.Data_u16 = DlcEv_pt->Default_u16[SPI_DLC_TX];
    /* de-activate the CS# by sending a dummy data byte */
    SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DAT1.TxData_u32,
                              DlcEv_pt->TxEProp_t.Tx.Ctrl_u16,
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* reset any used DMA flags */
    SPI_REG(W_, USER_, 32BIT)(Dma_GlobalRegister->DMA_BTCFLAG,
                              0x0000FFFF,
                              OS_MEM_AREA_DMA_REG);

    /* shut down the DMA control package for TX and RX */
    Spi_DlcStdDmaUnit = DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID;
    ChSetup_pt = &Spi_DlcDmaChSetup[SPI_DLC_RX];
    ChSetup_pt->ChEn = 0;
    ChSetup_pt->Unit    = DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID;
    ChSetup_pt->Channel = SPI_DLC_TX;
    ChSetup_pt->Dir     = SPI_DLC_TX;
    /* set frame count   */
    ChSetup_pt->FCount = 0;
    /* set element count */
    ChSetup_pt->ECount = 0;
    /* source and destination address do not matter */
    /* update the control field with any value to trigger a change
     * this will shut down a previous transfer on this channel and resets the status
     * Shutdown TX and RX channels
     */
    ChSetup_pt->ChCtrl = DMA_RX08_CONST;
    Dma_Setup(ChSetup_pt);
    ChSetup_pt->ChCtrl = DMA_TX08_CONST;
    Dma_Setup(ChSetup_pt);
}
#endif /* SPI_HARDWAREUNIT_USE_STDDMA == STD_ON */


static FUNC(void, SPI_CODE) Spi_DlcConsumeEvent(Spi_DlcEventPtrType DlcEv_pt)
{
    volatile uint32 Status_u32; /* interrupt status */
    uint8  Ram_u8;              /* temporary parameter for RamUsed ON/OFF */

    *DlcEv_pt->DlcResult_t = SPI_DLC_PENDING;
    Ram_u8 = DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed;
    Spi_DlcTransmit(DlcEv_pt);
    /* both  modes */
    Spi_DlcOptionSelect[Ram_u8].FillData(DlcEv_pt);
    if(DlcEv_pt->Event_u8 == (uint8)SPI_DLC_EV_ASYNCTX)
    {
        /* enable interrupt generation */
        Spi_DlcOptionSelect[Ram_u8].EnIsr(DlcEv_pt);
    }
    else
    {
        /* no interrupt generation in sync mode */
    }
    /* this triggers the data transfer */
    Spi_DlcOptionSelect[Ram_u8].Trigger(DlcEv_pt);
}


static FUNC(void, SPI_CODE) Spi_DlcSwitchChannel
(
    Spi_DlcEventPtrType DlcEv_pt,
    Spi_DlcVU16PtrType Ctrl_pt,
    Spi_DlcTxRxDefType Dir_t
)
{
    Spi_ChannelConfigPtrType ChCfg_pt;
    uint32 TGReg_u32;
    uint8  ChIDTxRx_u8;  /* channel identifier, used as index */
    uint8  ChIdx_u8;     /* channel index of a channel list */
    uint8  ExtDev_u8;    /* channel index of a channel list */

    /* one channel transferred, prepare next */
    ExtDev_u8 = DlcEv_pt->DFSel_u8[1];
    /* increment channel number */
    DlcEv_pt->Num_u8[Dir_t]++;
    /* all channels in a job transferred ? */
    if(DlcEv_pt->Num_u8[Dir_t] > Spi_ConfigPtr_pt->Spi_JobCfg[DlcEv_pt->JobID_u8].Spi_ChannelList[0])
    {
        /* execute this only if CS handling is selected as active and in TX mode */
        if(  (DlcEv_pt->DFSel_u8[0] != SPI_NO_CHIP_SELECT)
          && (Ctrl_pt != NULL_PTR))
        {
            /* use special acces only in case of MIB RAM */
            if(DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed == SPI_DLC_RAM)
            {
                /* finish job, and de-activate CS
                 * remember: a write to the TX control field instantly affects the CS# signal
                 */
                SPI_REG(C_, USER_, 16BIT)((*Ctrl_pt),
                                          SPI_DLC_TXRAMCTRL_CSHOLD,
                                          DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamArea);
            }
            else
            {
                /* use standard access */
                SPI_DLC_CLRVAL16(*Ctrl_pt, SPI_DLC_TXRAMCTRL_CSHOLD);
            }
        }
        else
        {
            /* no action */
        }
        /* all channels in a job transmitted */
        if(Dir_t == SPI_DLC_TX)
        {
            /* if tx direction detects a end of all channels, the state is finished */
            DlcEv_pt->Guard_u8 = SPI_DLC_G_FINISHED;
        }
        else
        {
            /* if rx direction detects a end of all channels, the state is idle, because
             * all data has been transmitted and received
             */
            DlcEv_pt->Guard_u8 = SPI_DLC_G_IDLE;
        }
    }
    else
    {
        /* get next channel to receive */
        DlcEv_pt->Pos_u16[Dir_t]     = 0;
        /* get index of channel */
        ChIdx_u8                     = DlcEv_pt->Num_u8[Dir_t];
        /* get channel ID from job configuration */
        ChIDTxRx_u8                  = Spi_ConfigPtr_pt->Spi_JobCfg[DlcEv_pt->JobID_u8].Spi_ChannelList[ChIdx_u8];
        ChCfg_pt                     = &Spi_ConfigPtr_pt->Spi_ChannelCfg[ChIDTxRx_u8];
        DlcEv_pt->ID_u8[Dir_t]       = ChIDTxRx_u8;
        /* assign default data for channel */
        DlcEv_pt->Default_u16[Dir_t] = ChCfg_pt->Spi_DefaultTxData;

        /* this parameters are only modified if direction is Tx */
        if(Dir_t == SPI_DLC_TX)
        {
            /* now get the format word an clear the channel related parameters */
            SPI_REG(R_, PRIV_, 32BIT)(TGReg_u32,
                                      DlcEv_pt->MUnit_pt->Reg_pt->Spi_FMT[0],
                                      DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
            /* set the new values */
            SPI_DLC_CLRVAL32(TGReg_u32,
                             SPI_DLC_SPIFMT_CHARLEN(SPI_DLC_SPIFMT_CHARLEN_MASK) |
                             SPI_DLC_SPIFMT_WDELAY(SPI_DLC_SPIFMT_WDELAY_MASK)   |
                             SPI_DLC_SPIFMT_SHIFTDIR(1)
                             );
            /* set new char length (here 8bit) */
            SPI_DLC_SETVAL32(TGReg_u32, SPI_DLC_SPIFMT_CHARLEN(ChCfg_pt->Spi_DataWidth));
             /* set shift dir (LSB or MSB) */
            SPI_DLC_SETVAL32(TGReg_u32, SPI_DLC_SPIFMT_SHIFTDIR(ChCfg_pt->Spi_TxStart));
            /* set WDELAY */
            SPI_DLC_SETVAL32(TGReg_u32, SPI_DLC_SPIFMT_WDELAY(Spi_ConfigPtr_pt->Spi_DevCfg[ExtDev_u8].Spi_CsIdleTime));
            /* store changed channel values */
            DlcEv_pt->ChProp_u32 = TGReg_u32;
        }
    }
    return;
}

/***********************************************************************************************************************
 *  Spi_DlcInitMemory()
 **********************************************************************************************************************/
/*! \brief      Service to initialize module global variables at power up. This function can be used to initialize the
 *              variables in *_INIT_* sections in case they are not initialized by the startup code.
 *  \pre        Module must not be initialized
 *  \context    Function shall be called from task level
 **********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_DlcInitMemory(void)
{
    Spi_HWUnitMapPtrType MUnit_pt; /* pointer to hardware unit */
    uint8 UnitIdx_u8;              /* hardware unit index of generated unit arrays */

    MUnit_pt = &Spi_HWUnitMap_at[0];
    /* initialize mapping structure to default */
    for(UnitIdx_u8 = 0; UnitIdx_u8 < SPI_DLC_MAXHWUNIT; UnitIdx_u8++)
    {
        MUnit_pt->Reg_pt  = NULL_PTR;
        MUnit_pt->Ram_pt  = NULL_PTR;
        MUnit_pt->Prop_pt = NULL_PTR;
        MUnit_pt++;
    }
    #if (SPI_HARDWAREUNIT_USE_STD == STD_ON)
    Spi_DlcOptionSelect[SPI_DLC_STD].Init        = Spi_Dlc(Std, Init);
    Spi_DlcOptionSelect[SPI_DLC_STD].Close       = Spi_Dlc(Std, Close);
    Spi_DlcOptionSelect[SPI_DLC_STD].EnIsr       = Spi_Dlc(Std, EnIsr);
    Spi_DlcOptionSelect[SPI_DLC_STD].DeIsr       = Spi_Dlc(Std, DeIsr);
    Spi_DlcOptionSelect[SPI_DLC_STD].FillData    = Spi_Dlc(Std, FillData);
    Spi_DlcOptionSelect[SPI_DLC_STD].DrainData   = Spi_Dlc(Std, DrainData);
    Spi_DlcOptionSelect[SPI_DLC_STD].Trigger     = Spi_Dlc(Std, TriggerData);
    Spi_DlcOptionSelect[SPI_DLC_STD].Transmit    = Spi_Dlc(Std, Transmit);
    Spi_DlcOptionSelect[SPI_DLC_STD].Error       = Spi_Dlc(Std, Error);
    #else
    Spi_DlcOptionSelect[SPI_DLC_STD].Init        = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD].Close       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD].EnIsr       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD].DeIsr       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD].FillData    = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD].DrainData   = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD].Trigger     = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD].Transmit    = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD].Error       = Spi_Dlc(Handle, Idle);
    #endif
    /* MIB RAM unit specialized functions */
    #if (SPI_HARDWAREUNIT_USE_RAM == STD_ON)
    Spi_DlcOptionSelect[SPI_DLC_RAM].Init        = Spi_Dlc(Ram, Init);
    Spi_DlcOptionSelect[SPI_DLC_RAM].Close       = Spi_Dlc(Ram, Close);
    Spi_DlcOptionSelect[SPI_DLC_RAM].EnIsr       = Spi_Dlc(Ram, EnIsr);
    Spi_DlcOptionSelect[SPI_DLC_RAM].DeIsr       = Spi_Dlc(Ram, DeIsr);
    Spi_DlcOptionSelect[SPI_DLC_RAM].FillData    = Spi_Dlc(Ram, FillData);
    Spi_DlcOptionSelect[SPI_DLC_RAM].DrainData   = Spi_Dlc(Ram, DrainData);
    Spi_DlcOptionSelect[SPI_DLC_RAM].Trigger     = Spi_Dlc(Ram, TriggerData);
    Spi_DlcOptionSelect[SPI_DLC_RAM].Transmit    = Spi_Dlc(Ram, Transmit);
    Spi_DlcOptionSelect[SPI_DLC_RAM].Error       = Spi_Dlc(Ram, Error);
    #else
    Spi_DlcOptionSelect[SPI_DLC_RAM].Init        = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_RAM].Close       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_RAM].EnIsr       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_RAM].DeIsr       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_RAM].FillData    = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_RAM].DrainData   = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_RAM].Trigger     = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_RAM].Transmit    = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_RAM].Error       = Spi_Dlc(Handle, Idle);
    #endif
    /* STD DMA specialized functions */
    #if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Init        = Spi_Dlc(StdDma, Init);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Close       = Spi_Dlc(StdDma, Close);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].EnIsr       = Spi_Dlc(StdDma, EnIsr);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].DeIsr       = Spi_Dlc(StdDma, DeIsr);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].FillData    = Spi_Dlc(StdDma, Prepare);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].DrainData   = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Trigger     = Spi_Dlc(StdDma, TriggerData);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Transmit    = Spi_Dlc(StdDma, Transmit);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Error       = Spi_Dlc(Handle, Idle);
    #else
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Init        = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Close       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].EnIsr       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].DeIsr       = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].FillData    = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].DrainData   = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Trigger     = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Transmit    = Spi_Dlc(Handle, Idle);
    Spi_DlcOptionSelect[SPI_DLC_STD_DMA].Error       = Spi_Dlc(Handle, Idle);
    #endif
} /* Spi_InitMemory() */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

FUNC(void, SPI_CODE)Spi_DlcInit(void)
{
    P2VAR(Spi_DlcEventType, AUTOMATIC, SPI_VAR) DlcEv_pt;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_VAR) JobCfg_pt;
    uint32 CSVal_u32;    /* local value for chip select */
    uint8 UnitIdx_u8;    /* hardware unit index of generated unit arrays */
    uint8 UnitId_u8;     /* hardware unit id */
    uint8 JobId_u8;      /* local value for job assigned to a hardware unit */
    uint8 ExtDevIdx_u8;  /* external device index to set the levels as configured */
    uint8 ExtDevMask_u8; /* this mask yields 0xF if 4 external devices are configured, 0x7 with 3 */

    /*
     * set HW unit parameters
     */
    for(UnitIdx_u8 = 0; UnitIdx_u8 < Spi_ConfigPtr_pt->Spi_MaxDlcs; UnitIdx_u8++)
    {
        UnitId_u8 = Spi_UnitProperty_at[UnitIdx_u8].Spi_UnitID;
        DlcEv_pt  = &Spi_DlcEvent_t[UnitId_u8];
        /* assign hardware object */
        DlcEv_pt->MUnit_pt = &Spi_HWUnitMap_at[UnitId_u8];
        DlcEv_pt->Event_u8 = SPI_DLC_EV_CONSUMED;
        DlcEv_pt->Guard_u8 = SPI_DLC_G_IDLE;
        DlcEv_pt->DlcResult_t = (Spi_DlcResPtrType) &Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_DlcResult[UnitId_u8];
        /* the hardware unit array will be sorted! */
        /* ID found, now assign values in sorted order */
        DlcEv_pt->MUnit_pt->Reg_pt  =  Spi_HWUnit_at[UnitIdx_u8];
        DlcEv_pt->MUnit_pt->Ram_pt  =  Spi_RamUnit_at[UnitIdx_u8];
        DlcEv_pt->MUnit_pt->Prop_pt =  &Spi_UnitProperty_at[UnitIdx_u8];

        /* set master, external clk, enable SPI  */
        SPI_REG(W_, PRIV_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_GCR1,
                                       (
                                            SPI_DLC_MIBSPIEGCR1_MASTER(1) |
                                            SPI_DLC_MIBSPIEGCR1_CLKMOD(1) |
                                            SPI_DLC_MIBSPIEGCR1_SPIEN(1)
                                       ),
                                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* start at first entry */
        JobCfg_pt     = &Spi_ConfigPtr_pt->Spi_JobCfg[0];
        ExtDevMask_u8 = 0;
        for (JobId_u8 = 0; JobId_u8 < Spi_ConfigPtr_pt->Spi_MaxJobs; JobId_u8++)
        {
            /* get the chip select */
            ExtDevIdx_u8  = JobCfg_pt->Spi_ExDev;
            /* check if external device has already been set */
            if((ExtDevMask_u8 & (1 << ExtDevIdx_u8)) == 0)
            {
                /* update the mask */
                ExtDevMask_u8 |= (1 << ExtDevIdx_u8);
                CSVal_u32 = Spi_ConfigPtr_pt->Spi_DevCfg[ExtDevIdx_u8].Spi_DioPin;
                /* execute this only if CS handling is selected as active */
                if(CSVal_u32 != SPI_NO_CHIP_SELECT)
                {
                    if(SPI_DLC_LOWBYTE_GET(Spi_ConfigPtr_pt->Spi_DevCfg[ExtDevIdx_u8].Spi_CsProperty) == SPI_HIGH)
                    {
                        /* set the CS idle levels - idle high */
                        SPI_REG(S_, USER_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DEF,
                                                       1 << CSVal_u32,
                                                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
                    }
                    else
                    {
                        /* set the CS idle levels - idle low */
                        SPI_REG(C_, USER_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DEF,
                                                       1 << CSVal_u32,
                                                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
                    }
                }
                else
                {
                    /* no action */
                }
            }
            else
            {
                /* no action */
            }
            /* point to next object */
            JobCfg_pt++;
        }
       /* if hardware unit has no RAM so it runs in standard mode, the MIB features will not be initialized */
        Spi_DlcOptionSelect[DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed].Init(DlcEv_pt);
    }
}

FUNC(void, SPI_CODE) Spi_DlcClose(void)
{
    Spi_DlcEventPtrType DlcEv_pt;
    uint8 UnitIdx_u8;    /* hardware unit index */
    uint8 UnitId_u8;     /* hardware unit ID    */

    /* clear registers */
    for(UnitIdx_u8 = 0; UnitIdx_u8 < Spi_ConfigPtr_pt->Spi_MaxDlcs; UnitIdx_u8++)
    {
        UnitId_u8 = Spi_UnitProperty_at[UnitIdx_u8].Spi_UnitID;
        DlcEv_pt  = &Spi_DlcEvent_t[UnitId_u8];
       /* if hardware unit has no RAM so it runs in standard mode, the MIB features will not be initialized */
        Spi_DlcOptionSelect[DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed].Close(DlcEv_pt);
        /* power on default is 1 for each CS line */
        SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DEF,
                                  0x0Fu,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        SPI_REG(W_, PRIV_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_FMT[0],
                                       SPI_DLC_BITCLR,
                                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        SPI_REG(W_, PRIV_, 32BIT_INIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_GCR1,
                                       SPI_DLC_BITCLR,
                                       DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
}

static FUNC(void, SPI_CODE) Spi_DlcTransmit(Spi_DlcEventPtrType DlcEv_pt)
{
    P2CONST(Spi_ExternalDeviceConfigType, AUTOMATIC, SPI_PBCFG) DevCfg_pt;
    uint32 TGReg_u32;        /* local register mirror */
    uint32 CSVal_u32;        /* local value for chip select */
    uint8  ExtDev_u8;        /* local external device, used as index  */
    uint8  TMS_SpiModeWA[4]; /* the modes of the TMS Spi do not match the Spi Mode Matrix, so they have to be converted */
    uint8  JobIDLoc_u8;      /* job identifier, used as index */
    uint8  ChIDTxRx_u8;      /* channel identifier, used as index */

    TMS_SpiModeWA[0] = 1; /* the index is the real Spi mode, the contents the TMS Spi mode */
    TMS_SpiModeWA[1] = 0;
    TMS_SpiModeWA[2] = 3;
    TMS_SpiModeWA[3] = 2;

    /* start with high prio job, IdxLev0_uloc is the TG index, equal to the job priority  */
    JobIDLoc_u8 = DlcEv_pt->JobID_u8;
    /* external device assigned to a job */
    ExtDev_u8   = Spi_ConfigPtr_pt->Spi_JobCfg[JobIDLoc_u8].Spi_ExDev;
    /* the guard signals the job to be transmitted */
    if(DlcEv_pt->Guard_u8 == SPI_DLC_G_PENDING)
    {
        /* start with first channel in a job */
        /* the assignment starts with index 1, index 0 is the number of channels
         * due to the call of Spi_DlcSwitchChannel, the number is incremented by one
         * every call, so start here with zero!
         */
        DlcEv_pt->Num_u8[SPI_DLC_TX] = 0;
        DlcEv_pt->Num_u8[SPI_DLC_RX] = 0;
        /* get first channel ID in a job */
        ChIDTxRx_u8 = Spi_ConfigPtr_pt->Spi_JobCfg[JobIDLoc_u8].Spi_ChannelList[1];
        /* save ChID for later transmit */
        DlcEv_pt->ID_u8[SPI_DLC_TX] = ChIDTxRx_u8;
        DlcEv_pt->ID_u8[SPI_DLC_RX] = ChIDTxRx_u8;
        /* reset channel pointer for Tx, Rx  */
        DlcEv_pt->Pos_u16[SPI_DLC_TX] = 0;
        DlcEv_pt->Pos_u16[SPI_DLC_RX] = 0;
        DlcEv_pt->Default_u16[SPI_DLC_TX] = Spi_ConfigPtr_pt->Spi_ChannelCfg[ChIDTxRx_u8].Spi_DefaultTxData;
        DlcEv_pt->Default_u16[SPI_DLC_RX] = 0; /* use a memory location to store and trash data */

        DevCfg_pt = &Spi_ConfigPtr_pt->Spi_DevCfg[ExtDev_u8];
        /* set other data related parameters                               */
        /* set baud rate */
        TGReg_u32 = SPI_DLC_SPIFMT_PRESCALE(DevCfg_pt->Spi_Baudrate);
        /* set clock polarity (clock idle level) and */
        /* set phase (data shift edge), apply the TMS WA */
        SPI_DLC_SETVAL32(TGReg_u32, SPI_DLC_SPIFMT_PHASE(TMS_SpiModeWA[DevCfg_pt->Spi_Mode]));
        /* this register holds the data format word, which is vital for transmission */
        SPI_REG(W_, PRIV_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_FMT[0],
                                  TGReg_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* set Tx control field with the default low value of Spi_Def register */
        SPI_REG(R_, USER_, 32BIT)(DlcEv_pt->TxProp_t.Tx.Ctrl_u16,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_DEF,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* build the TX control field, set buffer mode to 3 */
        Spi_DlcOptionSelect[DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed].Transmit(DlcEv_pt);

        if(DevCfg_pt->Spi_CsMode == (uint8) SPI_CONTINOUS)
        {
            /* set chip select mode */
            SPI_DLC_SETVAL16(DlcEv_pt->TxProp_t.Tx.Ctrl_u16, SPI_DLC_TXRAMCTRL_CSHOLD);
        }
        else
        {
            /* enable WDELAY in single mode */
            SPI_DLC_SETVAL16(DlcEv_pt->TxProp_t.Tx.Ctrl_u16, SPI_DLC_TXRAMCTRL_WDEL);
        }
        /* get the chip select */
        CSVal_u32 = DevCfg_pt->Spi_DioPin;
        /* execute this only if CS handling is selected as active */
        if(CSVal_u32 != (uint32)SPI_NO_CHIP_SELECT)
        {
            /* low byte holds the CS idle level */
            if(SPI_DLC_LOWBYTE_GET(DevCfg_pt->Spi_CsProperty) == SPI_HIGH)
            {
                SPI_REG(S_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DEF,
                                          1 << CSVal_u32,
                                          DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
                /* activate the corresponding CS for transmit --(IDLE)--\__(ACTIVE)__ */
                SPI_DLC_CLRVAL16(DlcEv_pt->TxProp_t.Tx.Ctrl_u16, (1 << CSVal_u32));
            }
            else
            {
                SPI_REG(C_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DEF,
                                          1 << CSVal_u32,
                                          DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);

                /* activate the corresponding CS for transmit __(IDLE)__/--(ACTIVE)-- */
                SPI_DLC_SETVAL16(DlcEv_pt->TxProp_t.Tx.Ctrl_u16, (1 << CSVal_u32));
            }
        }
        else
        {
            /* no action */
        }
        /* update the TxEnd control field */
        SPI_DLC_WRITEVAL16(DlcEv_pt->TxEProp_t.Tx.Ctrl_u16, DlcEv_pt->TxProp_t.Tx.Ctrl_u16);
        SPI_DLC_CLRVAL16(DlcEv_pt->TxEProp_t.Tx.Ctrl_u16, SPI_DLC_TXRAMCTRL_CSHOLD);

        /* save the CS ID */
        DlcEv_pt->DFSel_u8[0] = (uint8)CSVal_u32;
        /* save the external device */
        DlcEv_pt->DFSel_u8[1] = ExtDev_u8;

        /* setup timings CS2_CLK[31..24], CLK_2CS[23..16], CS2_ENA[15..8], ENA_2CS[7..0] */
        SPI_REG(W_, USER_, 16BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DELAY[0],
                                  DevCfg_pt->Spi_ClkDelays[0],
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        SPI_REG(W_, USER_, 16BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DELAY[1],
                                  DevCfg_pt->Spi_ClkDelays[1],
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* For every channel we need to update the data format word.
         * Configure Tx
         */
        (FUNC(void, SPI_CODE)) Spi_DlcSwitchChannel(DlcEv_pt,
                                                    &DlcEv_pt->TxProp_t.Tx.Ctrl_u16,
                                                    SPI_DLC_TX);
        /* configure Rx */
        (FUNC(void, SPI_CODE)) Spi_DlcSwitchChannel(DlcEv_pt,
                                                    NULL_PTR,
                                                    SPI_DLC_RX);
    }
    else
    {
        /* no action */
    }
}


static FUNC(void, SPI_CODE) Spi_DlcError (Spi_DlcEventPtrType DlcEv_pt)
{
#if (SPI_DEM_ERROR_REPORTING == STD_ON)
    if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_TXFULL))
    {
        /* the transmit function has been called, but the sequencer still has not processed the buffer */
        Spi_DemReportError(SPI_E_TXSTALL_ERROR, DEM_EVENT_STATUS_FAILED);
    }
    else if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_RXEMPTY))
    {
        /* the receive function has been called, but the sequencer still has not processed the buffer */
        Spi_DemReportError(SPI_E_RXSTALL_ERROR, DEM_EVENT_STATUS_FAILED);
    }
    else if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_BITERR))
    {
        /* bit error */
        Spi_DemReportError(SPI_E_BIT_ERROR, DEM_EVENT_STATUS_FAILED);
    }
    else if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_TIMEOUT))
    {
        /* timeout error */
        Spi_DemReportError(SPI_E_TO_ERROR, DEM_EVENT_STATUS_FAILED);
    }
    else if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_DLENERR))
    {
        /* data length error */
        Spi_DemReportError(SPI_E_DLEN_ERROR, DEM_EVENT_STATUS_FAILED);
    }
    else if(SPI_DLC_CHECK_HEX16(DlcEv_pt->RxStat_t.Rx.Stat_u16, SPI_DLC_RXRAMCTRL_RXOVR))
    {
        /* overwrite occurred, Rx */
        Spi_DemReportError(SPI_E_DOVR_ERROR, DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        /* no action */
    }
#endif

    /* disable interrupts */
    Spi_DlcOptionSelect[DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed].DeIsr(DlcEv_pt);
    Spi_DlcOptionSelect[DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed].Error(DlcEv_pt);
    /* clear error condition (RxInt, RxOvr, BitErr, TimeOut, DlenError */
    SPI_REG(S_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_FLG,
                              (
                                  SPI_DLC_FLG_RXIF    |
                                  SPI_DLC_FLG_RXOVR   |
                                  SPI_DLC_FLG_BITERR  |
                                  SPI_DLC_FLG_DLENERR |
                                  SPI_DLC_FLG_TOERR
                              ),
                              DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    /* release job */
    DlcEv_pt->RxStat_t.Rx.Stat_u16   = 0;
    DlcEv_pt->Guard_u8     = SPI_DLC_G_IDLE;
    DlcEv_pt->Event_u8     = SPI_DLC_EV_CONSUMED;
    *DlcEv_pt->DlcResult_t = SPI_DLC_FAILED;
}

FUNC(Std_ReturnType, SPI_CODE) Spi_DlcSetEvent
(
    P2CONST(Spi_DlcEventType, AUTOMATIC, SPI_VAR_NOINIT) Dlc_Event_pt
)
{
    Spi_DlcEventPtrType DlcEv_pt;
    uint8 HwUnit_u8; /* index of hardware unit */
    uint8 JobId_u8;

    Spi_GlobalSuspend();
    JobId_u8  = Dlc_Event_pt->JobID_u8;
    HwUnit_u8 = Spi_ConfigPtr_pt->Spi_JobCfg[JobId_u8].Spi_HWUnitID;
    /* hardware unit id set, now get index of hardware unit */
    DlcEv_pt = &Spi_DlcEvent_t[HwUnit_u8];
    /* check if a job starts transmission */
    /* check if a job is waiting for transmit, do not queue him again */
    if(DlcEv_pt->Event_u8 != (uint8)SPI_DLC_EV_CONSUMED)
    {
        Spi_GlobalRestore();
        return (E_NOT_OK);
    }
    else
    {
        /* used for transmission mode */
        DlcEv_pt->Event_u8 = Dlc_Event_pt->Event_u8;
        /* high prio jobs are queued at pos 0, low prio jobs at pos. 3*/
        DlcEv_pt->JobID_u8    = JobId_u8;
        DlcEv_pt->Guard_u8    = (uint8)SPI_DLC_G_PENDING;
        DlcEv_pt->JobResult_t = (Spi_JobResPtrType) &Spi_ConfigPtr_pt->Spi_GlobalStatus_pt->Spi_JobResult[JobId_u8];
    }
    /* stop critical section */
    Spi_GlobalRestore();
    Spi_DlcConsumeEvent(DlcEv_pt);
    return (E_OK);
}

#define SPI_STOP_SEC_CODE
#include "MemMap.h"

#define SPI_START_SEC_CODE_ISR
#include "MemMap.h"

FUNC(void, SPI_CODE_ISR) Spi_IrqTxRxERR(uint32 HwUnit_u32)
{
    Spi_DlcEventPtrType DlcEv_pt;
    volatile uint32 TGErr_u32; /* value for error check */
    uint8  Ram_u8;   /* temporary parameter for RamUsed ON/OFF */

    DlcEv_pt = &Spi_DlcEvent_t[HwUnit_u32];
    /* check if a error is pending, get value */
    if(DlcEv_pt->Guard_u8 != SPI_DLC_G_IDLE)
    {
        Ram_u8 = DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed;
        if(Ram_u8 == SPI_DLC_RAM)
        {
            SPI_REG(G_, USER_, 32BIT)(TGErr_u32,
                                      DlcEv_pt->MUnit_pt->Reg_pt->Spi_TGINTVECT[0],
                                      SPI_DLC_TGINTVECT_INTVEC(0x1F),
                                      DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        }
        else
        {
            SPI_REG(G_, USER_, 32BIT)(TGErr_u32,
                                      DlcEv_pt->MUnit_pt->Reg_pt->Spi_FLG,
                                      0x3FF,
                                      DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        }
        /* set value, used in DlcError function */
        DlcEv_pt->RxStat_t.Rx.Stat_u16 = (uint16)(TGErr_u32 >> 1) - 1;
        DlcEv_pt->Pos_u16[SPI_DLC_RX] = 0;
        /* we caught an error, handle it */
        Spi_DlcError(DlcEv_pt);
        /* only treat active jobs! */
        if(  (*DlcEv_pt->JobResult_t == SPI_JOB_PENDING)
          || (*DlcEv_pt->JobResult_t == SPI_JOB_ACTIVE)  )
        {
            /* report to job and sequence handler that a job has finished */
            Spi_HwJobComplete(DlcEv_pt->JobID_u8, DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID);
        }
    }
    else
    {
        /* if no job is pending, all requests must be ignored */
    }
}

FUNC(void, SPI_CODE_ISR) Spi_IrqTxRx(uint32 HwUnit_u32)
{
    Spi_DlcEventPtrType DlcEv_pt;
    volatile uint32 TGIdx_u32; /* index of transfer group*/
    uint8 Ram_u8;              /* temporary parameter for RamUsed ON/OFF */

    DlcEv_pt = &Spi_DlcEvent_t[HwUnit_u32];
    Ram_u8 = DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed;

    /* check the TG which caused the IRQ
     * and clear the interrupt flag by read
     */
    if(Ram_u8 == SPI_DLC_RAM)
    {
        SPI_REG(G_, USER_, 32BIT)(TGIdx_u32,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_TGINTVECT[1],
                                  SPI_DLC_TGINTVECT_INTVEC(0x1F),
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    else
    {
        SPI_REG(G_, USER_, 32BIT)(TGIdx_u32,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_FLG,
                                  0x3FF,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        /* just read the flag */
        TGIdx_u32 = 0;
    }
    /* avoid a compiler warning */
    TGIdx_u32++;
    Spi_GlobalReEnable();
    Spi_DlcOptionSelect[Ram_u8].DrainData(DlcEv_pt);
    /* check state if  finished or idle */
    if(DlcEv_pt->Guard_u8 == SPI_DLC_G_IDLE)
    {
        DlcEv_pt->Event_u8     = SPI_DLC_EV_CONSUMED;
        if(*DlcEv_pt->DlcResult_t != SPI_DLC_FAILED)
        {
            /* CS#  is automatically released by Tx control field cell contents */
            /* close DLC, report the job which has finished */
            *DlcEv_pt->DlcResult_t = SPI_DLC_OK;
            Spi_DlcOptionSelect[Ram_u8].DeIsr(DlcEv_pt);
            /* report to job and sequence handler that a job has finished */
            Spi_HwJobComplete(DlcEv_pt->JobID_u8, DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID);
        }
        else
        {
            /* no action, just leave */
        }
    }
    else
    {
        /* refill data and
         * trigger transfer  again
         */
        /* transfer group is ready for transfer, trigger interrupt generation */
        Spi_DlcOptionSelect[Ram_u8].FillData(DlcEv_pt);
        Spi_DlcOptionSelect[Ram_u8].Trigger(DlcEv_pt);
    }
}

FUNC(void, SPI_CODE_ISR) Spi_DlcBlockCbk(void)
{
#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
    Spi_DlcEventPtrType DlcEv_pt;
    volatile uint32 HWChannel_u32;
    volatile uint32 Status_u32;     /* hardware status */

    DlcEv_pt   = &Spi_DlcEvent_t[Spi_DlcStdDmaUnit];
    /* Temporary ID of a hardware channel,
    * initialized with the ID of the hardware channel which caused this interrupt
    * Note: Reading LFSAOFFSET clears the respective LFSFLAG
    * Note: Reading BTCAOFFSET clears the respective BTCFLAG
    */
     SPI_REG(R_, USER_, 32BIT)(HWChannel_u32,
                              Dma_GlobalRegister->DMA_BTCAOFFSET,
                              OS_MEM_AREA_DMA_REG);
     /* nesting interrupts may fire */
    Spi_GlobalReEnable();

    if(HWChannel_u32 == (1 << SPI_DLC_TX))
    {
        /* synchronize TX buffer */
        SPI_REG(R_, USER_, 32BIT)(Status_u32,
                                  DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.RxData_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        while(SPI_DLC_CHECK_HEX32(Status_u32, SPI_DLC_RXBUFCTRL_TXFULL))
        {
            SPI_REG(R_, USER_, 32BIT)(Status_u32,
                                      DlcEv_pt->MUnit_pt->Reg_pt->Spi_BUF.RxData_u32,
                                      DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        }
        /* de-activate CS# line and write data */
        SPI_REG(W_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_DAT1.TxData_u32,
                                  DlcEv_pt->TxEProp_t.TxData_u32,
                                  DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
    }
    else
    {
        /* disable DMA requests */
        SPI_REG(C_, USER_, 32BIT)(DlcEv_pt->MUnit_pt->Reg_pt->Spi_INT0,
                                 SPI_DLC_DMA_EN_MASK,
                                 DlcEv_pt->MUnit_pt->Prop_pt->Spi_RegArea);
        if(DlcEv_pt->ChState_u8 == SPI_DLC_ST_FINISHED)
        {
            /* check for next channel RX */
            (FUNC(void, SPI_CODE)) Spi_DlcSwitchChannel(DlcEv_pt,
                                                        NULL_PTR,
                                                        SPI_DLC_RX);
            /* are both, channel and job done ? */
            if(DlcEv_pt->Guard_u8 == SPI_DLC_G_IDLE)
            {
                /* mark task as done */
                DlcEv_pt->ChState_u8 = SPI_DLC_ST_OK;
                /* check if hardware unit has failed */
                if(*DlcEv_pt->DlcResult_t != SPI_DLC_FAILED)
                {
                    /* close DLC, report the job which has finished */
                    *DlcEv_pt->DlcResult_t = SPI_DLC_OK;
                    DlcEv_pt->Event_u8     = SPI_DLC_EV_CONSUMED;
                    /* disable interrupt generation */
                    Spi_DlcOptionSelect[DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed].DeIsr(DlcEv_pt);
                    /* report to job and sequence handler that a job has finished */
                    Spi_HwJobComplete(DlcEv_pt->JobID_u8, DlcEv_pt->MUnit_pt->Prop_pt->Spi_UnitID);
                }
                else
                {
                    /* no action, just leave */
                }
                return;
            }
            /* check for next channel TX */
            (FUNC(void, SPI_CODE)) Spi_DlcSwitchChannel(DlcEv_pt,
                                                        NULL_PTR,
                                                        SPI_DLC_TX);
        }
        else
        {
            /* no action */
        }
        /* prepare DMA for transmission */
        Spi_DlcStdDmaPrepare(DlcEv_pt);
        /* enable DMA requests to generate the first pulse */
        Spi_DlcOptionSelect[DlcEv_pt->MUnit_pt->Prop_pt->Spi_RamUsed].Trigger(DlcEv_pt);
    }
#endif
}

#define SPI_STOP_SEC_CODE_ISR
#include "MemMap.h"

/**********************************************************************************************************************
 *  END OF FILE: SPI_DLC.C
 **********************************************************************************************************************/

