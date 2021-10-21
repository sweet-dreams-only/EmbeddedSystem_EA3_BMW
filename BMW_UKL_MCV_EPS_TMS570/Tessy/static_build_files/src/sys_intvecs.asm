;-------------------------------------------------------------------------------
; sys_core.asm
;
; (c) Texas Instruments 2009, All rights reserved.
;


;-------------------------------------------------------------------------------
; import reference for interrupt routines

    .ref _c_int00
    .ref _undefined
    .ref _svc
    .ref _prefetchAbort
    .ref _dataAbort


;-------------------------------------------------------------------------------
; interrupt vectors

    .sect ".intvecs"

        b   _c_int00
        b   _undefined
        b   _svc
        b   _prefetchAbort
        b   _dataAbort
        b   #-8
        ldr pc,[pc,#-0x1b0]
       	ldr pc,[pc,#-0x1b0]


;-------------------------------------------------------------------------------
