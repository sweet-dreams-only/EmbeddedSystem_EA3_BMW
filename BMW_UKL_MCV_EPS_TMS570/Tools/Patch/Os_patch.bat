@Echo off
REM ****************************************************************************
REM * This script applies patches to the generated Os files.
REM *	INPUTS - Original generated files:
REM *	osobjs.inc
REM *	osobjs_init.inc
REM *	intvect.asm
REM *	Os_MemMap.h
REM *
REM *	OUTPUTS - Patch files:
REM *	osobjs.inc
REM *	osobjs_init.inc
REM *	intvect.asm
REM *	Os_MemMap.h
REM *
REM ****************************************************************************
REM /*---------------------------------------------------------------------------
REM * Version Control:
REM * Date Created:      Wed Oct 20 16:33:22 2012
REM * %version:          3 %
REM * %derived_by:       xz0btk %
REM * %date_modified:    Sat Oct 27 09:18:24 2012 %
REM *---------------------------------------------------------------------------*/

SET GNU_PATH=%cd%\..\GnuWin32\bin
SET DIFF_PATH=%cd%\diff\Os

REM ** Change to Output Folder
CD ..\..\SwProject\Source\GenDataOS
 
%GNU_PATH%\patch < %DIFF_PATH%\osobjs.inc.diff
%GNU_PATH%\patch < %DIFF_PATH%\osobjs_init.inc.diff
%GNU_PATH%\patch < %DIFF_PATH%\intvect.asm.diff
 
REM ** Search and Replace the Os_MemMap to provide proper MEM_MAP error undef statements required by AUTOSAR Memmap standard **
ECHO patching file Os_MemMap.h
%GNU_PATH%\sed -i s/"#endif"/"#undef MEMMAP_ERROR \/* Nxtr Patch to Meet Autosar MEMMAP undef requirements *\/ \n#endif"/g Os_MemMap.h
 
REN ~cfg4_301_EPS.ecuc.arxml.HTM cfg4_301_EPS.ecuc.arxml.HTM
 
PAUSE
 