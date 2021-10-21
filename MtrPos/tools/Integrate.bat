@Echo Off
setlocal

REM *** Assume the component name is the name of the directory 1 level up from this directory ***
for %%* in (..) do set SWC=%%~n*
echo SWC name is: %SWC%

REM *** Assume the integration project follows the standard naming convention and has an "_EPS_" string in it ***
FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%


set SWC=MtrPos2
 

set BSWMDDIR_MTRPOS2=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_MTRPOS2=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_MTRPOS2%
mkdir %GENDEFDIR_MTRPOS2%



copy ..\generate\Sa_MtrPos2_*.arxml	%BSWMDDIR_MTRPOS2%
copy ..\generate\Sa_MtrPos2_*.tt	%GENDEFDIR_MTRPOS2%
copy ..\generate\Sa_MtrPos2_*.bat	%GENDEFDIR_MTRPOS2%



set SWC=MtrPos3
 

set BSWMDDIR_MTRPOS3=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_MTRPOS3=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_MTRPOS3%
mkdir %GENDEFDIR_MTRPOS3%



copy ..\generate\Sa_MtrPos3_*.arxml	%BSWMDDIR_MTRPOS3%
copy ..\generate\Sa_MtrPos3_*.tt	%GENDEFDIR_MTRPOS3%
copy ..\generate\Sa_MtrPos3_*.bat	%GENDEFDIR_MTRPOS3%


pause
:end

endlocal

