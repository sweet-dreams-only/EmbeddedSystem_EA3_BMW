/**********************************************************************************************************************
* Copyright 2016 Nxtr 
* Nxtr Confidential
*
* Module File Name  : Test_SinCos.c
* Module Description: This file contains stub source code for UTP and QAC
* Project           : CBD
* Author            : Rijvi Ahmed
***********************************************************************************************************************
* Version Control:
* %version:          1 %
* %derived_by:       jzk9cc %
*----------------------------------------------------------------------------------------------------------------------
* Date      Rev      Author         Change Description                                                           SCR #
* -------   -------  --------  ---------------------------------------------------------------------------     --------	
* 02/15/16   1       Rijvi          Initial version                                                            EA3#4485																
**********************************************************************************************************************/

#include "Std_Types.h"
#include "SinCos.h"
#include "Test_SinCos.h"



FUNC(void, TEST_SINCOS_CODE) Call_SinCos(void)
{
	float32 Inp = 1.5F;
	float32 SinVal;
	float32 CosVal;
	
	SinCos_Uls_f32(Inp, &SinVal, &CosVal);
	
}
