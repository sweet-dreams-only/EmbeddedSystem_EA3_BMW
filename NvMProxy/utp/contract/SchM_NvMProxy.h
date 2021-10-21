#ifndef SCHM_NVMPROXY_H
#define SCHM_NVMPROXY_H

#define NVMPROXY_EXCLUSIVE_AREA_0 0U

/* Exclusive area stubs for unit testing hooks */
extern void SchM_Enter_NvMProxy( uint16 area );
extern void SchM_Exit_NvMProxy( uint16 area );

#endif/* double include preventer */

