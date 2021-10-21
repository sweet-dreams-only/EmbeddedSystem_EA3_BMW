@echo off
REM ****************************************************************************
REM * This script runs the CCT after the post build merge occurs. 
REM *
REM ****************************************************************************
REM /*---------------------------------------------------------------------------
REM * Version Control:
REM * Date Created:      Mon Apr 01 16:33:22 2013
REM * %version:          1 %
REM * %derived_by:       cz7lt6 %
REM * %date_modified:    Mon Apr  1 16:43:13 2013 %
REM *---------------------------------------------------------------------------*/

:start
CLS

SET RELEASE_PATH=%cd%\..\..\SwProject\Release
SET FAULT_INJ_PATH=%cd%\..\..\SwProject\z_FaultInjection


REM Ask use for the file name
set /p filename=What is the filename:

REM Ask user for build option
ECHO.
ECHO 1) Release Build
ECHO 2) Fault Injection Build

SET buildType=
SET /p buildType=Select Build Type: 

IF /I '%buildType%'=='1' GOTO :releaseBuild
IF /I '%buildType%'=='2' GOTO :faultInjBuild
GOTO start


:releaseBuild
CD %RELEASE_PATH%
GOTO cct

:faultInjBuild
CD %FAULT_INJ_PATH%
GOTO cct

:cct
cct -v2 -NoSort %filename%

PAUSE
 