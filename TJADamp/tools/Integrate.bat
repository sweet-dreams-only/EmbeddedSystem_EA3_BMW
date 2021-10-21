@Echo Off
setlocal



set SWC=TJADamp

FOR /D %%G in ("..\..\*_EPS_*") DO set INTPJTDIR=%%G
echo Integration project relative path is: %INTPJTDIR%

 

set BSWMDDIR_TJADAMP=%INTPJTDIR%\Tools\AsrProject\Generators\Components\_Schemes\%SWC%\bswmd
set GENDEFDIR_TJADAMP=%INTPJTDIR%\Tools\AsrProject\Generators\Artt\%SWC%


mkdir %BSWMDDIR_TJADAMP%
mkdir %GENDEFDIR_TJADAMP%



copy ..\generate\Ap_TJADamp_*.arxml	%BSWMDDIR_TJADAMP%
copy ..\generate\Ap_TJADamp_*.tt	%GENDEFDIR_TJADAMP%
copy ..\generate\Ap_TJADamp_*.bat	%GENDEFDIR_TJADAMP%


pause
:end

endlocal

