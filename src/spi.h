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

    void initMCUtoFMUchannel(void);
    bool transferMCUtoFMU(uint8_t *txBuff, int txBytes, uint8_t *rxBuff, int rxBytes);


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

