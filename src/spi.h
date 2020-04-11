/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: spi.h                                     //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: Interprocessor SPI functions       //
/////////////////////////////////////////////////////

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

    void initMCUtoFMU(void);
    bool transferMCUtoFMUch1(uint8_t *txBuff, int txBytes, uint8_t *rxBuff, int rxBytes);
    void initFMUtoMCUch1(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

