@Echo Off
setlocal



set SWC=AssistSumnLmt

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_ASSISTSUMNLMT=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_ASSISTSUMNLMT=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_ASSISTSUMNLMT%
mkdir %GENDEFDIR_ASSISTSUMNLMT%



copy ..\generate\Ap_AssistSumnLmt_*.arxml	%BSWMDDIR_ASSISTSUMNLMT%
copy ..\generate\Ap_AssistSumnLmt_*.tt	%GENDEFDIR_ASSISTSUMNLMT%
copy ..\generate\Ap_AssistSumnLmt_*.bat	%GENDEFDIR_ASSISTSUMNLMT%


pause
:end

endlocal

