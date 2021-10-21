@ECHO OFF

REM    Data Dictionary Launcher Tool
REM    Rev 2.0
REM    
REM    CHANGELOG
REM    Rev       Date       By    Changes
REM    -------   --------   ---   ----------------------------------------------
REM    1.0       02/03/12   LW    Initial Version
REM    2.0       02/06/12   OT    Added robustness, generalized naming
REM    3.0       02/07/12   LW    Delete logic change
REM    4.0       02/07/12   OT    Fixed Launching (cmd window not closing)

REM ***************** SET PATHS ************************************************
SET DD_PATH="%cd%\..\..\Design Docs\HLDD"
SET DD_NAME="Integration Data Dictionary.xlsm"

REM **************** CHECK TO SEE IF NEW VERSION IS AVAILABLE ******************
IF EXIST "%cd%\DataDictTool.xla" GOTO checkold
ECHO.
ECHO            +--------------------------------------------------------+
ECHO            ^|                                                        ^|
ECHO            ^|      Latest Version of DataDictTool.xla Not Found      ^|
ECHO            ^|                                                        ^|
ECHO            ^|  YOU MAY NOT BE USING THE LATEST DATA DICTIONARY TOOL  ^|
ECHO            ^|                                                        ^|
ECHO            +--------------------------------------------------------+
ECHO.
PAUSE
ECHO.
GOTO launchdd

REM **************** CHECK TO SEE IF AN OLD VERSION IS INSTALLED ***************
:checkold
IF NOT EXIST "C:\Documents and Settings\%USERNAME%\Application Data\Microsoft\AddIns\DataDictTool.xla" GOTO copyddtool

REM **************** DELETE OLD FILES ******************************************
DEL /F "C:\Documents and Settings\%USERNAME%\Application Data\Microsoft\AddIns\DataDictTool.xla"
IF NOT EXIST "C:\Documents and Settings\%USERNAME%\Application Data\Microsoft\AddIns\DataDictTool.xla" GOTO copyddtool

ECHO.
ECHO           +----------------------------------------------------------+
ECHO           ^|                                                          ^|
ECHO           ^|  Could Not Delete DataDictTool.xla - Please Close Excel  ^|
ECHO           ^|                                                          ^|
ECHO           +----------------------------------------------------------+
ECHO.
PAUSE
ECHO.
GOTO checkold

REM **************** COPY DDTOOL ***********************************************
:copyddtool
copy "%cd%\DataDictTool.xla" "C:\Documents and Settings\%USERNAME%\Application Data\Microsoft\AddIns\"

:launchdd
REM **************** CHECK TO SEE IF DATA DICTIONARY EXISTS ********************
IF NOT EXIST %DD_PATH%\%DD_NAME% GOTO launchdderror

REM **************** LAUNCH EXCEL **********************************************
START "DD Launcher" /Min %DD_PATH%\%DD_NAME%
EXIT

:launchdderror
ECHO.
ECHO     +---------------------------------------------------------------------+
ECHO     ^|                                                                     ^|
ECHO     ^|  Couldn't Find Data Dictionary: %DD_NAME%  ^|
ECHO     ^|                                                                     ^|
ECHO     +---------------------------------------------------------------------+
ECHO.
PAUSE
ECHO.
EXIT