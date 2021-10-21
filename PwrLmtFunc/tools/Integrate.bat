@Echo Off
setlocal



set SWC=PwrLmtFunc

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_PWRLMTFUNC=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_PWRLMTFUNC=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_PWRLMTFUNC%
mkdir %GENDEFDIR_PWRLMTFUNC%



copy ..\generate\Ap_PwrLmtFunc_*.arxml	%BSWMDDIR_PWRLMTFUNC%
copy ..\generate\Ap_PwrLmtFunc_*.tt	%GENDEFDIR_PWRLMTFUNC%
copy ..\generate\Ap_PwrLmtFunc_*.bat	%GENDEFDIR_PWRLMTFUNC%


pause
:end

endlocal

