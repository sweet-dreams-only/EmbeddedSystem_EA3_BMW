@Echo off
REM ****************************************************************************
REM * This bat-file performs the necessary pre build steps:
REM *  1) Rename the standard AUTOSAR files included in CGT folder with .bak to 
REM *      ensure they do not interfere with the build
REM * Written by Nxtr
REM ****************************************************************************


REM **************** RENAME CONFLICTING FILES **********************************

SET CG_TOOL_ROOT=%1

ren %CG_TOOL_ROOT%\include\Compiler.h Compiler.h.bak
ren %CG_TOOL_ROOT%\include\Compiler_Cfg.h Compiler_Cfg.h.bak
ren %CG_TOOL_ROOT%\include\Platform_Types.h Platform_Types.h.bak
ren %CG_TOOL_ROOT%\include\Std_Types.h Std_Types.h.bak

REM **************** END *******************************************************
