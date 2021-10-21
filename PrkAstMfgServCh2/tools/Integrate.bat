@Echo Off
setlocal



set SWC=PrkAstMfgServCh2

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_PRKASTMFGSERVCH2=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_PRKASTMFGSERVCH2=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_PRKASTMFGSERVCH2%
mkdir %GENDEFDIR_PRKASTMFGSERVCH2%



copy ..\generate\Ap_PrkAstMfgServCh2_*.arxml	%BSWMDDIR_PRKASTMFGSERVCH2%
copy ..\generate\Ap_PrkAstMfgServCh2_*.tt	%GENDEFDIR_PRKASTMFGSERVCH2%
copy ..\generate\Ap_PrkAstMfgServCh2_*.bat	%GENDEFDIR_PRKASTMFGSERVCH2%


pause
:end

endlocal

