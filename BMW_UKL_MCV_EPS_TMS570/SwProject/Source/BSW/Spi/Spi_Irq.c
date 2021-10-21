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
 *         File:  Spi_Irq.c
 *      Project:  DrvSpi_Tms570Tispi01Asr
 *       Module:  MICROSAR Communication DrvSpi_Tms570Tispi01Asr Module
 *    Generator:  -
 *
 *  Description:  This file implements the interrupt handling for spi communication driver.
 *
 *********************************************************************************************************************/

#define SPI_IRQ_SOURCE

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Spi.h"
#include "Spi_Irq.h"
#include "Spi_DlcDma.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* AUTOSAR version information check has to match definition in header file */
#if (  (SPI_IRQ_MAJOR_VERSION != (0x01u)) \
    || (SPI_IRQ_MINOR_VERSION != (0x05u)) )
  #error "Software Version Numbers of Spi_Irq.c and Spi_Irq.h are different"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

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

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
#define SPI_START_SEC_CODE_ISR
#include "MemMap.h"

#if (SPI_HARDWAREUNIT0_ACTIVE == STD_ON)
/***********************************************************************************************************************
 *  SPI unit 0 error handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 0 error handler.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt error handler for SPI, active if feature is available
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit0TxRxERR ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit0TxRxERR )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit0TxRxERR( void )
    #endif
    {
        Spi_IrqTxRxERR(SPI_UNIT0);
    }

/***********************************************************************************************************************
 *  SPI unit 0 handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 0 handler.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt handler for SPI
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit0TxRx ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit0TxRx )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit0TxRx( void )
    #endif
    {
        Spi_IrqTxRx(SPI_UNIT0);
    }
#endif

#if (SPI_HARDWAREUNIT1_ACTIVE == STD_ON)
/***********************************************************************************************************************
 *  SPI unit 1 Error handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 1 Error handler.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt error handler for SPI, active if feature is available
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit1TxRxERR ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit1TxRxERR )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit1TxRxERR( void )
    #endif
    {
        Spi_IrqTxRxERR(SPI_UNIT1);
    }

/***********************************************************************************************************************
 *  SPI unit 1 handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 1 handler..
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt handler for SPI
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
            SPI_COMPILER_ISR void Spi_IrqUnit1TxRx ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
            ISR( Spi_IrqUnit1TxRx )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
            void Spi_IrqUnit1TxRx( void )
    #endif
    {
        Spi_IrqTxRx(SPI_UNIT1);
    }
#endif

#if (SPI_HARDWAREUNIT2_ACTIVE == STD_ON)
/***********************************************************************************************************************
 *  SPI unit 2 Error handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 2 Error handler.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt error handler for SPI, active if feature is available
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit2TxRxERR ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit2TxRxERR )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit2TxRxERR( void )
    #endif
    {
        Spi_IrqTxRxERR(SPI_UNIT2);
    }

/***********************************************************************************************************************
 *  SPI unit 2 handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 2 handler..
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt handler for SPI
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit2TxRx ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit2TxRx )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit2TxRx( void )
    #endif
    {
        Spi_IrqTxRx(SPI_UNIT2);
    }
#endif

#if (SPI_HARDWAREUNIT3_ACTIVE == STD_ON)
/***********************************************************************************************************************
 *  SPI unit 3 Error handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 2 Error handler.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt error handler for SPI, active if feature is available
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit3TxRxERR ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit3TxRxERR )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit3TxRxERR( void )
    #endif
    {
        Spi_IrqTxRxERR(SPI_UNIT3);
    }

/***********************************************************************************************************************
 *  SPI unit 3 handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 2 handler..
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt handler for SPI
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit3TxRx ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit3TxRx )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit3TxRx( void )
    #endif
    {
        Spi_IrqTxRx(SPI_UNIT3);
    }
#endif

#if (SPI_HARDWAREUNIT4_ACTIVE == STD_ON)
/***********************************************************************************************************************
 *  SPI unit 4 Error handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 2 Error handler.
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt error handler for SPI, active if feature is available
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit4TxRxERR ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit4TxRxERR )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit4TxRxERR( void )
    #endif
    {
        Spi_IrqTxRxERR(SPI_UNIT4);
    }

/***********************************************************************************************************************
 *  SPI unit 4 handler
 **********************************************************************************************************************/
/*! \brief      This method is the SPI unit 4 handler..
 *  \param[in]  none
 *  \param[out] none
 *  \return     none
 *  \context    Function is called from interrupt level
 *  \note       Interrupt handler for SPI
 **********************************************************************************************************************/
    #if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
        SPI_COMPILER_ISR void Spi_IrqUnit4TxRx ( void )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        ISR( Spi_IrqUnit4TxRx )
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit4TxRx( void )
    #endif
    {
        Spi_IrqTxRx(SPI_UNIT4);
    }
#endif

/***********************************************************************************************************************
*  Dma_IsrBTC
**********************************************************************************************************************/
/*! \brief      Interrupt service routine for block transfer complete interrupt of Dma module
*
*              This function will be called from block transfer complete interrupt of Dma module
*
*  \param[in]  void
*  \return     void
*
*  \context    Function is called on interrupt level.
**********************************************************************************************************************/
#if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
    SPI_COMPILER_ISR void Dma_IsrBTC ( void )
#elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
    ISR( Dma_IsrBTC )
#elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
    void Dma_IsrBTC(void)
#endif
{
#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
    /* Call the Notification */
    Spi_DlcBlockCbk();
#endif
}

/***********************************************************************************************************************
*  Dma_IsrLFS
**********************************************************************************************************************/
/*! \brief      Interrupt service routine for last frame transfer interrupt of Dma module
*
*              This function will be called prior to the last frame of a block
*
*  \param[in]  void
*  \return     void
*
*  \context    Function is called on interrupt level.
**********************************************************************************************************************/
#if (SPI_CFG_ISR_TYPE == SPI_ISR_CAT1)
    SPI_COMPILER_ISR void Dma_IsrLFS ( void )
#elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
    ISR( Dma_IsrLFS )
#elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
    void Dma_IsrLFS(void)
#endif
{
#if (SPI_HARDWAREUNIT_USE_STDDMA == STD_ON)
    /* Call the Notification */
#endif
}

#define SPI_STOP_SEC_CODE_ISR
#include "MemMap.h"
/**********************************************************************************************************************
 *  END OF FILE: Spi_Irq.c
 *********************************************************************************************************************/
