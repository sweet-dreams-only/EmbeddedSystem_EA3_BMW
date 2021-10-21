@Echo off
REM ****************************************************************************
REM * This bat-file performs the necessary post build steps:
REM *  1) Generate hex file from build output
REM *  2) Generate BMW Hash/SWE programmable file
REM *  3) Archive the project files into the required secure library zip files
REM * Written by Nxtr
REM * This batch script requires the installtion of "WinZip® Command Line Support Add-On"
REM * Additonally, the PATH variable must contain the dirrectory in which the add on
REM * was installed.
REM * Help for the Add-on can be found at (default install dir):
REM * file:///c:/Program%20Files/WinZip/WZCLINE.CHM
REM ****************************************************************************

REM ***************** SET PATHS ************************************************
REM ** Set current path **
SET PROJ_PATH=%cd%
SET TOOL_PATH=%PROJ_PATH%\..\..\Tools
SET CCT_PATH=%TOOL_PATH%\CCT
SET NOWECC_PATH=%TOOL_PATH%\nowECC
SET HEXVIEW_PATH=%TOOL_PATH%\HexView
SET HEX470_PATH=%TOOL_PATH%\hex470
SET SWEGEN_PATH=%TOOL_PATH%\SWE_Generator
SET A2LCFG_PATH=%TOOL_PATH%\CANape


REM **************** DISABLE ARCHIVE PROCESS ***********************************
REM 0 -> Off (skips archive step) 1 -> On (default setting)
SET ARCHIVE_ACTIVE=1

REM **************** DELETE OLD FILES ******************************************

SET DEFAULT_DBG_FILENAME="EPS_UKL_MCV_dbg"
SET DEFAULT_FLT_FILENAME="EPS_UKL_MCV_flt"
SET DEFAULT_MET_FILENAME="EPS_UKL_MCV_Metric_CpuUse"
SET FILENAME=%1
SET CONFIGNAME=%2
SET SWE1_SGBMID=00001892_000_000_000
SET SWE2_SGBMID=00001893_000_000_000
SET SWE3_SGBMID=00001894_000_000_000

del %FILENAME%.hex
del %FILENAME%.hex.map
del %FILENAME%.s19
del *.msr
del *.bsw
del *.a2l

REM **************** Run CCT over the out file *********************************
REM * CCT performs the checksum of the Safe Context Os config data, so the 
REM * Perl script provided with the SafeContext Os is not required in the process
"%CCT_PATH%"\CCT %FILENAME%.out

REM **************** Run NowECC over the out file and append the ECC region *****
REM * This command line assumes that the required applicaiotn range of memory is present in 
REM *  the out file and filled correctly by the linker command definitions
%NOWECC_PATH%\nowecc -i %FILENAME%.out -f021 16M_ADD -r4 -a


REM **************** CREATE Hex File******************************************** 
"%HEX470_PATH%"\hex470 -i -o %FILENAME%.hex -map %FILENAME%.hex.map -datawidth 8 -memwidth 8 -romwidth 8 -i %FILENAME%.out


REM **************** CREATE BSWs *********************************************** 

REM create s19 from hex
"%HEXVIEW_PATH%"\hexview -s -i %FILENAME%.hex -FR:0x40000-0xBFFFF -FP:FF -xs %FILENAME%.s19
"%HEXVIEW_PATH%"\hexview -s -i %FILENAME%.s19 -FR:0x08000-0x0FFFF -FP:FF -xs %FILENAME%.s19

copy %FILENAME%.s19 "%SWEGEN_PATH%"
cd "%SWEGEN_PATH%"

REM unzip the archived utlity (this step is here because the utility has characters that are illegal in synergy, so it is ziped then archived.)
wzunzip -n -d "%SWEGEN_PATH%"\utility.zip

REM SWE1 - EPS Application
REM Generate Hash file for production signature process
SWE-Generator -gui off -mode swegen -config SweGen_Appl_SWE1.cfg > outputfile.txt -par %FILENAME%.s19 -par SWFL_%SWE1_SGBMID%
REM Create msr from s19 and bsw from msr using test keys for developement
SWE-Generator -gui off -mode swegen -config SweGen_Appl_SWE1_TestKey.cfg > outputfile.txt -par %FILENAME%.s19 -par SWFL_%SWE1_SGBMID%
SET /P SWE_FILE=<outputfile.txt
SWE-Generator -gui off -mode compress -compressmode compressconvert -compressinput "%SWE_FILE%" -compressoutput swfl_%SWE1_SGBMID%.bsw -log logfileApp.log -efficiency 50

REM SWE2 - CAL 1 (Nxtr Cals)
REM Generate Hash file for production signature process
SWE-Generator -gui off -mode swegen -config SweGen_Cal1_SWE2.cfg > outputfile.txt -par %FILENAME%.s19 -par SWFL_%SWE2_SGBMID%
REM Create msr from s19 and bsw from msr using test keys for developement
SWE-Generator -gui off -mode swegen -config SweGen_Cal1_SWE2_TestKey.cfg > outputfile.txt -par %FILENAME%.s19 -par SWFL_%SWE2_SGBMID%
SET /P SWE_FILE=<outputfile.txt
SWE-Generator -gui off -mode compress -compressmode compressconvert -compressinput "%SWE_FILE%" -compressoutput swfl_%SWE2_SGBMID%.bsw -log logfileCal1.log -efficiency 50
 
REM SWE3 - CAL 2 (BMW Tuning)
REM Generate Hash file for production signature process
SWE-Generator -gui off -mode swegen -config SweGen_Cal2_SWE3.cfg > outputfile.txt -par %FILENAME%.s19 -par SWFL_%SWE3_SGBMID%
REM Create msr from s19 and bsw from msr using test keys for developement
SWE-Generator -gui off -mode swegen -config SweGen_Cal2_SWE3_TestKey.cfg > outputfile.txt -par %FILENAME%.s19 -par SWFL_%SWE3_SGBMID%
SET /P SWE_FILE=<outputfile.txt
SWE-Generator -gui off -mode compress -compressmode compressconvert -compressinput "%SWE_FILE%" -compressoutput swfl_%SWE3_SGBMID%.bsw -log logfileCal2.log -efficiency 50

REM *************** Clean Up *********************************************

copy *.bsw "%PROJ_PATH%"
copy *.xml "%PROJ_PATH%"


del *.txt
del *.s19
del *.msr
del *.bsw
del *.xml

REM ********************** Restore Original Directory ***********************
cd 	"%PROJ_PATH%"

REM ************************* Perform Extra Steps for Official Builds **************
IF %ARCHIVE_ACTIVE%==0 GOTO ELSE
IF (%FILENAME%)==(%DEFAULT_DBG_FILENAME%) GOTO ELSE
IF (%FILENAME%)==(%DEFAULT_FLT_FILENAME%) GOTO ELSE
IF (%FILENAME%)==(%DEFAULT_MET_FILENAME%) GOTO ELSE
	REM **************** Update A2L File********************************************
	cd "%A2LCFG_PATH%"
	CMD /C update_a2l %CONFIGNAME% %FILENAME%

	REM ********************** Restore Original Directory ***********************
	cd 	"%PROJ_PATH%"

	REM ********** Create Archives of the Project Per the Secure Lib Guidelines **********
	cd ../../
	archive.bat "%PROJ_PATH%"
	GOTO ENDIF
:ELSE
	ECHO postbuld.bat info: A2L update and archival zipping skipped.  If desired, change the output filenames in the linker settings to enable these operations.
:ENDIF

REM **************** END *******************************************************
