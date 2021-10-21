/**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : SinCos.h
* Module Description: This file contains the SinCos function prototype and definition
* Project           : CBD
* Author            : Rijvi Ahmed
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       jzk9cc %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------	
* 02/15/16   1       Rijvi      Initial version for SinCos algorithm                                           EA3#4485																
**********************************************************************************************************************/



/******************************************* Multiple Include Protection *********************************************/
#ifndef SINCOS_H
#define SINCOS_H


/************************************************ Include Statements *************************************************/
#include "Std_Types.h"


/********************************************* Embedded Local Constants **********************************************/
#define D_SIN22PT5DEG_ULS_F32	0.3826834323650897717284599840304F   	/* SIn(22.5deg) */ 
#define D_SIN45PT0DEG_ULS_F32	0.70710678118654752440084436210485F  	/* Sin(45.0deg) */
#define D_SIN67PT5DEG_ULS_F32	0.92387953251128675612818318939679F 	/* Sin(67.5deg) */
#define D_EIGHTOVERPI_ULS_F32   2.5464790894703253723021402139602F      /* (8.0F / 3.1415926535897932384626433832795F) */
#define D_PIOVEREIGHT_ULS_F32   0.39269908169872415480783042290994F     /* (3.1415926535897932384626433832795F / 8.0F) */
#define D_ONEOVERSIX_ULS_F32    0.16666666666666666666666666666667F     /* (1.0F/6.0F) */
#define D_ONEOVERTWO_ULS_F32    0.5F                                    /* (1.0F/2.0F) */




/*********************************************** Exported Declarations ***********************************************/
INLINE FUNC(void, SINCOS_CODE) SinCos_Uls_f32(float32 Inp, float32* SinVal, float32* CosVal);




/*****************************************************************************
*  Name:           SinCos_Uls_f32()
*  Description:    Optimized SinCos Algorithm
*  Inputs:         Inp, *SinVal, *CosVal
*  Outputs:        *SinVal = Sin(Inp) and *CosVal = Cosine(Inp)
*  Usage Notes:    Inp must be in radians.
*                  Input Range [-10000 to 10000]
*****************************************************************************/
INLINE FUNC(void, SINCOS_CODE) SinCos_Uls_f32(float32 Inp, float32* SinVal, float32* CosVal)
{

	VAR(sint32,    AUTOMATIC)  n;
	VAR(uint8,     AUTOMATIC)  Normdn;
	VAR(float32,   AUTOMATIC)  InpSqd;
	VAR(float32,   AUTOMATIC)  SinA;
	VAR(float32,   AUTOMATIC)  CosA;
	VAR(float32,   AUTOMATIC)  Tmp; 
	
	
	Tmp = (Inp < 0.0F) ? ( (Inp * D_EIGHTOVERPI_ULS_F32) - 0.5F  ) : ( (Inp * D_EIGHTOVERPI_ULS_F32) + 0.5F ); 
	n = (sint32)Tmp;
	Inp = Inp - ((float32)n * D_PIOVEREIGHT_ULS_F32); 	/* Determine 'A' part of 'Inp' angle. 'Inp' = 'A' + 'n' * 'B' */
	Normdn = (uint8)( (uint32)n & 0x0000000FU ); 		/* Determine normalized 'n' */
	    
	InpSqd = Inp * Inp;

	SinA = Inp * ( 1.0F - (InpSqd * D_ONEOVERSIX_ULS_F32) );
	CosA = 1.0F - (InpSqd  * D_ONEOVERTWO_ULS_F32);
	
	
	switch ( Normdn )
	{
		case 0U:
			*SinVal = SinA;
			*CosVal = CosA;
			break;
			
		case 1U:
			*SinVal = (D_SIN67PT5DEG_ULS_F32 * SinA) + (D_SIN22PT5DEG_ULS_F32 * CosA);
			*CosVal = (-D_SIN22PT5DEG_ULS_F32 * SinA) + (D_SIN67PT5DEG_ULS_F32 * CosA);
			break;
			
		case 2U:
			*SinVal = (D_SIN45PT0DEG_ULS_F32 * SinA) + (D_SIN45PT0DEG_ULS_F32 * CosA);
			*CosVal = (-D_SIN45PT0DEG_ULS_F32 * SinA) + (D_SIN45PT0DEG_ULS_F32 * CosA);
			break;
			
		case 3U:
			*SinVal = (D_SIN22PT5DEG_ULS_F32 * SinA) + (D_SIN67PT5DEG_ULS_F32 * CosA);
			*CosVal = (-D_SIN67PT5DEG_ULS_F32 * SinA) + (D_SIN22PT5DEG_ULS_F32 * CosA);
			break;
			
		case 4U:
			*SinVal = CosA;
			*CosVal = -SinA;
			break;
			
		case 5U:
			*SinVal = (-D_SIN22PT5DEG_ULS_F32 * SinA) + (D_SIN67PT5DEG_ULS_F32 * CosA);
			*CosVal = (-D_SIN67PT5DEG_ULS_F32 * SinA) + (-D_SIN22PT5DEG_ULS_F32 * CosA);
			break;
			
		case 6U:
			*SinVal = (-D_SIN45PT0DEG_ULS_F32 * SinA) +  (D_SIN45PT0DEG_ULS_F32 * CosA);
			*CosVal = (-D_SIN45PT0DEG_ULS_F32 * SinA) + (-D_SIN45PT0DEG_ULS_F32 * CosA);
			break;
			
		case 7U:
			*SinVal = (-D_SIN67PT5DEG_ULS_F32 * SinA) + (D_SIN22PT5DEG_ULS_F32 * CosA);
			*CosVal = (-D_SIN22PT5DEG_ULS_F32 * SinA) + (-D_SIN67PT5DEG_ULS_F32 * CosA);
			break;
			
		case 8U:
			*SinVal = -SinA;
			*CosVal = -CosA;
			break;
			
		case 9U:
			*SinVal = (-D_SIN67PT5DEG_ULS_F32 * SinA) + (-D_SIN22PT5DEG_ULS_F32 * CosA);
			*CosVal =  (D_SIN22PT5DEG_ULS_F32 * SinA) + (-D_SIN67PT5DEG_ULS_F32 * CosA);
			break;
			
		case 10U:
			*SinVal = (-D_SIN45PT0DEG_ULS_F32 * SinA) + (-D_SIN45PT0DEG_ULS_F32 * CosA);
			*CosVal =  (D_SIN45PT0DEG_ULS_F32 * SinA) + (-D_SIN45PT0DEG_ULS_F32 * CosA);
			break;
			
		case 11U:
			*SinVal = (-D_SIN22PT5DEG_ULS_F32 * SinA) + (-D_SIN67PT5DEG_ULS_F32 * CosA);
			*CosVal =  (D_SIN67PT5DEG_ULS_F32 * SinA) + (-D_SIN22PT5DEG_ULS_F32 * CosA);
			break;
			
		case 12U:
			*SinVal = -CosA;
			*CosVal =  SinA;
			break;
			
		case 13U:
			*SinVal =  (D_SIN22PT5DEG_ULS_F32 * SinA) + (-D_SIN67PT5DEG_ULS_F32 * CosA);
			*CosVal =  (D_SIN67PT5DEG_ULS_F32 * SinA) +  (D_SIN22PT5DEG_ULS_F32 * CosA);
			break;
			
		case 14U:
			*SinVal =  (D_SIN45PT0DEG_ULS_F32 * SinA) + (-D_SIN45PT0DEG_ULS_F32 * CosA);
			*CosVal =  (D_SIN45PT0DEG_ULS_F32 * SinA) +  (D_SIN45PT0DEG_ULS_F32 * CosA);
			break;
			
		/* case 15U:   */
		default :
			*SinVal =  (D_SIN67PT5DEG_ULS_F32 * SinA) + (-D_SIN22PT5DEG_ULS_F32 * CosA);
			*CosVal =  (D_SIN22PT5DEG_ULS_F32 * SinA) +  (D_SIN67PT5DEG_ULS_F32 * CosA);
			break;
			
	}	
													
}




#endif /*SINCOS_H*/

