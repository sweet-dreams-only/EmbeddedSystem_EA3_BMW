/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Dma.h
* Module Description: DMA Peripheral Header
* Product           : Gen II Plus - EA3.0
* Author            : Owen Tosh
*****************************************************************************/
/*******************************************************************************
* Version Control:
* Date Created:      Tue Mar 11 12:00:00 2014
* %version:          2 %
* %derived_by:       nz63rn %
* %date_modified:    Tue Mar 11 12:00:00 2014 %
*******************************************************************************/
/*******************************************************************************
* Change History:
* Date      Rev      Author    Change Description
* --------  -------  --------  ------------------------------------------------
* 04/08/14   1       OT        Initial version
* MODIFIED FOR USE IN utp\contract for FlsTst
*******************************************************************************/


#ifndef DMA_H
#define DMA_H

extern FUNC(void, DMA_CODE) Dma_SetupFlsTstBlock( VAR(uint32, AUTOMATIC) CRCAddr_Cnt_T_u32,
												  VAR(uint32, AUTOMATIC) FlsAddr_Cnt_T_u32,
												  VAR(uint16, AUTOMATIC) DmaFrameCount_Cnt_T_u16,
												  VAR(uint16, AUTOMATIC) DmaElementCount_Cnt_T_u16 );

extern FUNC(void, DMA_CODE) Dma_EnableFlsTstBlock(void);

extern FUNC(void, DMA_CODE) Dma_DisableFlsTstBlock(void);

extern VAR(boolean, DMA_VAR) Dma_DmaRstFail_Cnt_G_lgc;

#endif
