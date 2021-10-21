@Echo Off
setlocal



set SWC=TrqOsc

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_TRQOSC=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_TRQOSC=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_TRQOSC%
mkdir %GENDEFDIR_TRQOSC%



copy ..\generate\Ap_TrqOsc_*.arxml	%BSWMDDIR_TRQOSC%
copy ..\generate\Ap_TrqOsc_*.tt	%GENDEFDIR_TRQOSC%
copy ..\generate\Ap_TrqOsc_*.bat	%GENDEFDIR_TRQOSC%


pause
:end

endlocal

