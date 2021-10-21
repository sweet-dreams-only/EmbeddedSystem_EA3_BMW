@Echo off
REM ****************************************************************************
REM * This bat-file performs the necessary archival steps:
REM *  1) Create Output zip
REM *  2) Create Source zip
REM *  3) Create Doc zip
REM *  4) Create Utp zip
REM * Written by Nxtr
REM * This batch script requires the installtion of "WinZip® Command Line Support Add-On"
REM * Additonally, the PATH variable must contain the dirrectory in which the add on
REM * was installed.
REM * Help for the Add-on can be found at (default install dir):
REM * file:///c:/Program%20Files/WinZip/WZCLINE.CHM
REM ****************************************************************************

SET BUILDPATH=%1

REM *** SET Zip File Name to Directory in which this bat file resides **********
for %%A in ("%~dp0.") do set PJTDIR=%%~nA
set FILENAME=%PJTDIR%

cd ..

REM **************** DELETE OLD FILES ******************************************
del %FILENAME%_%BUILD%_OUT.zip


REM *************** Create Zip Files for Secure Library ************************
REM ** Output Files **
IF dummy==dummy%BUILDPATH% (
REM Skip output archival if the path to the output files is not specified 
) ELSE (
REM ** Collect Binary image and description files, a2l file, and communication DB (e.g. FIBEX/DBC ) file **
wzzip %FILENAME%_OUT.zip %BUILDPATH%\*.xml %BUILDPATH%\*.bsw %BUILDPATH%\*.hex %BUILDPATH%\*.out %BUILDPATH%\*.map %BUILDPATH%\*.s19 %BUILDPATH%\*.a2l
wzzip %FILENAME%_OUT.zip %PJTDIR%"\Tools\AsrProject\Config\System\*.xml"
)

REM *************** Create Zip of all Files for Secure Library for Release build ************************
REM **************** DELETE OLD FILES ******************************************
del %FILENAME%_SRC.zip
del %FILENAME%_GENTOOLS.zip
del %FILENAME%_UTP.zip
del %FILENAME%_HLDD.zip

REM ** Source Files and Build Tools **
wzzip -p -r -x*.bak %FILENAME%_SRC.zip %CD%\*.c *.h *.asm *.inc *.lib *.bat
wzzip -P -r -x*.bak %FILENAME%_SRC.zip %PJTDIR%\"NHET Project" %PJTDIR%\"Tools\Build Environment" %PJTDIR%\Tools\CCT %PJTDIR%\Tools\HexView %PJTDIR%\Tools\SWE_Generator %PJTDIR%\Tools\QAC %PJTDIR%\Tools\nowECC %PJTDIR%\Tools\hex470 %PJTDIR%\Tools\CANape
wzzip -P    -x*.bak %FILENAME%_SRC.zip %PJTDIR%\SwProject\*.* *.*

REM ** Generation Tools **
wzzip -P -r -x*.bak %FILENAME%_GENTOOLS.zip %PJTDIR%\Tools\AsrProject %PJTDIR%\Tools\HalcoGen %PJTDIR%\Tools\DataDictTool %PJTDIR%\Tools\Patch %PJTDIR%\Tools\GnuWin32 %PJTDIR%\Tools\PostBuild

REM ** Design Documents **
REM ** Place all documents at the root level of the archive with no paths to make it easier to find them **
wzzip  -rp -x*.bak %FILENAME%_HLDD.zip %PJTDIR%"\Design Docs\HLDD\*.xls *.xlsx *.doc *.docx *.pdf"
wzzip -p -r -x*.bak %FILENAME%_HLDD.zip %PJTDIR%\*.doc *.docx *.xls *.xls? *.pdf

REM ** Unit Test Results **
wzzip -P -r -x*.bak %FILENAME%_UTP.zip %PJTDIR%\Tessy


REM **************** END *******************************************************
