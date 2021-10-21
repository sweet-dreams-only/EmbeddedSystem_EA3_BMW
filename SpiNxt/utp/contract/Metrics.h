/*****************************************************************************
* Copyright 2013 Nxtr Automotive, All Rights Reserved.
* Nxtr Confidential
*
* Module File Name  : Metrics.h
* Module Description: Define metrics interfaces.
* Product           : Gen II Plus - EA3.0
* Author            : Blake Latchford
*****************************************************************************/
/**********************************************************************
 *	Header %name:	Metrics.h %
 *	Instance:		sag_EPS_10
 *	Description:	
 *	%created_by:	zz4r1x %
 *	%date_created:	Fri Mar 15 16:25:39 2013 %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 03/15/13  1        BWL            Inital creation.                                                          7619
**********************************************************************/
#ifndef METRICS_H
#define METRICS_H

#define D_SPINXT1_CNT_U08
#define D_SPINXT2_CNT_U08

/* All metrics calls are do-nothing in production build. */
#define Metrics_TaskStart( Id ) ((void)(0))
#define Metrics_TaskEnd( Id ) ((void)(0))

#endif
