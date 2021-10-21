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
 *         File:  Spi_Irq.h
 *      Project:  DrvSpi_Tms570Tispi01Asr
 *       Module:  MICROSAR Communication DrvSpi_Tms570Tispi01Asr Module
 *    Generator:  -
 *
 *  Description:  This file implements the interrupt handling for spi communication driver.
 *
 *********************************************************************************************************************/

#ifndef SPI_IRQ_H
#define SPI_IRQ_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SPI_COMPILER_ISR    interrupt

#define SPI_IRQ_MAJOR_VERSION    (0x01u)
#define SPI_IRQ_MINOR_VERSION    (0x05u)
#define SPI_IRQ_PATCH_VERSION    (0x00u)

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define SPI_ISR_VOID    (0x00u)
#define SPI_ISR_CAT1    (0x01u)
#define SPI_ISR_CAT2    (0x02u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

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
        SPI_COMPILER_ISR void Spi_IrqUnit0TxRxERR ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit0TxRxERR( void );
    #endif

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
        SPI_COMPILER_ISR void Spi_IrqUnit0TxRx ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit0TxRx( void );
    #endif
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
        SPI_COMPILER_ISR void Spi_IrqUnit1TxRxERR ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit1TxRxERR( void );
    #endif

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
            SPI_COMPILER_ISR void Spi_IrqUnit1TxRx ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
            void Spi_IrqUnit1TxRx( void );
    #endif
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
        SPI_COMPILER_ISR void Spi_IrqUnit2TxRxERR ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit2TxRxERR( void );
    #endif
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
        SPI_COMPILER_ISR void Spi_IrqUnit2TxRx ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit2TxRx( void );
    #endif
#endif

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
        SPI_COMPILER_ISR void Spi_IrqUnit3TxRxERR ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit3TxRxERR( void );
    #endif

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
        SPI_COMPILER_ISR void Spi_IrqUnit3TxRx ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit3TxRx( void );
    #endif
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
        SPI_COMPILER_ISR void Spi_IrqUnit4TxRxERR ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit4TxRxERR( void );
    #endif

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
        SPI_COMPILER_ISR void Spi_IrqUnit4TxRx ( void );
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
        /* Function prototype is declared by OS */
    #elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
        void Spi_IrqUnit4TxRx( void );
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
    SPI_COMPILER_ISR void Dma_IsrBTC ( void );
#elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
    /* Function prototype is declared by OS */
#elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
    void Dma_IsrBTC(void);
#endif

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
    SPI_COMPILER_ISR void Dma_IsrLFS ( void );
#elif (SPI_CFG_ISR_TYPE == SPI_ISR_CAT2)
    ISR( Dma_IsrLFS );
#elif (SPI_CFG_ISR_TYPE == SPI_ISR_VOID)
    void Dma_IsrLFS(void);
#endif

#define SPI_STOP_SEC_CODE_ISR
#include "MemMap.h"

#endif  /* SPI_IRQ_H */

/**********************************************************************************************************************
 *  END OF FILE: Spi_Irq.h
 *********************************************************************************************************************/
