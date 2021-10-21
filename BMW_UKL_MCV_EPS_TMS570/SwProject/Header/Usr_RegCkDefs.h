/*****************************************************************************
* Copyright 2010 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Usr_RegCkDefs.h
* Module Description: User defined external definitions for uDiag Reg Check
* Product           : Gen II Plus - EA3.0
* Author            : Jeremy Warmbier
*****************************************************************************/
/*---------------------------------------------------------------------------
* Version Control:
* Date Created:      Fri Nov 5 16:33:22 2010
* %version:          1 %
* %derived_by:       xz0btk %
* %date_modified:    Thu Oct  4 15:39:10 2012 % 
*---------------------------------------------------------------------------*/
#ifndef USR_REGCKDEFS_H
#define USR_REGCKDEFS_H

/* Function Definitions provided for functions that are referenced in the Register
 * Check configuration, but are not available as part of the external API for a 
 * component (i.e. the functions are not defined in a header file).
 */
extern FUNC(void, CD_UDIAG_APPL_CODE) VIM_Fallback(void);											 

#endif /*USR_REGCKDEFS_H*/
