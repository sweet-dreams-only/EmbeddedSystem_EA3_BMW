@Echo Off
setlocal



set SWC=MtrCtrlOpConv

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_MTRCTRLOPCONV=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_MTRCTRLOPCONV=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_MTRCTRLOPCONV%
mkdir %GENDEFDIR_MTRCTRLOPCONV%



copy ..\generate\Ap_MtrCtrlOpConv_*.arxml	%BSWMDDIR_MTRCTRLOPCONV%
copy ..\generate\Ap_MtrCtrlOpConv_*.tt	%GENDEFDIR_MTRCTRLOPCONV%
copy ..\generate\Ap_MtrCtrlOpConv_*.bat	%GENDEFDIR_MTRCTRLOPCONV%


pause
:end

endlocal

