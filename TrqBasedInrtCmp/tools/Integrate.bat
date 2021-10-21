@Echo Off
setlocal



set SWC=TrqBasedInrtCmp

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_TRQBASEDINRTCMP=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_TRQBASEDINRTCMP=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_TRQBASEDINRTCMP%
mkdir %GENDEFDIR_TRQBASEDINRTCMP%



copy ..\generate\Ap_TrqBasedInrtCmp_*.arxml	%BSWMDDIR_TRQBASEDINRTCMP%
copy ..\generate\Ap_TrqBasedInrtCmp_*.tt	%GENDEFDIR_TRQBASEDINRTCMP%
copy ..\generate\Ap_TrqBasedInrtCmp_*.bat	%GENDEFDIR_TRQBASEDINRTCMP%


pause
:end

endlocal

