//* SpiNxt.h for QAC */
#ifndef SPINXT_H
#define SPINXT_H

#include "Std_Types.h"
#include "mibspi_regs.h"


/* MIBSPI Interface Functions 
 * These Halcogen driver functions are externed for use in CDD instances that either
 * require the additional flexibility offered by the API, or for legacy reasons were
 * implemented prior to the creation of the Autosar Api for this BSW.
 */

FUNC(void, SPI_CODE) mibspiSetData(const mibspictrlregs_t *mibspi, uint32 group, const uint16 data[]);
FUNC(void, SPI_CODE) mibspiSetCtrlData(const mibspictrlregs_t *mibspi, uint32 group, const uint32 data[]);
FUNC(uint32, SPI_CODE) mibspiGetData(const mibspictrlregs_t *mibspi, uint32 group, uint16 data[]);
FUNC(void, SPI_CODE) mibspiTransfer(mibspictrlregs_t *mibspi, uint32 group);


#endif

