@Echo Off
setlocal

REM *** Assume the integration project follows the standard naming convention and has an "_EPS_" string in it ***
FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%



set SWC=HwTrq
 

set BSWMDDIR_HWTRQ=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_HWTRQ=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_HWTRQ%
mkdir %GENDEFDIR_HWTRQ%



copy ..\generate\Sa_HwTrq_*.arxml	%BSWMDDIR_HWTRQ%
copy ..\generate\Sa_HwTrq_*.tt	%GENDEFDIR_HWTRQ%
copy ..\generate\Sa_HwTrq_*.bat	%GENDEFDIR_HWTRQ%



set SWC=HwTrq2
 

set BSWMDDIR_HWTRQ2=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_HWTRQ2=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_HWTRQ2%
mkdir %GENDEFDIR_HWTRQ2%



copy ..\generate\Sa_HwTrq2_*.arxml	%BSWMDDIR_HWTRQ2%
copy ..\generate\Sa_HwTrq2_*.tt	%GENDEFDIR_HWTRQ2%
copy ..\generate\Sa_HwTrq2_*.bat	%GENDEFDIR_HWTRQ2%


pause
:end

endlocal

