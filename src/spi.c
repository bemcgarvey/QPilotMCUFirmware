/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: spi.c                                     //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: Interprocessor SPI functions       //
/////////////////////////////////////////////////////

#include "device.h"
#include "spi.h"
#include "debug.h"

void initMCUtoFMUchannel(void) {
    //SPI3
    TRISBbits.TRISB3 = 1;
    SPI3CON = 0;
    char c = SPI3BUF;
    SPI3CONbits.ENHBUF = 0;
    SPI3CONbits.MODE16 = 0;
    SPI3CONbits.MODE32 = 0;  //8 bit transfers for now
    SPI3CONbits.CKE = 1; 
    SPI3CONbits.CKP = 0;
    SPI3CONbits.SMP = 1;
    SPI3CONbits.MSTEN = 1;
    SPI3BRG = 0; //30 MHz
    SPI3STATbits.SPIROV = 0;
    SPI3CONbits.ON = 1;
    
}

bool transferMCUtoFMU(uint8_t *txBuff, int txBytes, uint8_t *rxBuff, int rxBytes) {
    uint8_t c;
    while (txBytes > 0) {
        SPI3BUF = *txBuff;
        while (SPI3STATbits.SPIRBF == 0);
        c = SPI3BUF;
        --txBytes;
        ++txBuff;
    }
    delay_us(1);
    while (rxBytes > 0) {
        SPI3BUF = 0;
        while (SPI3STATbits.SPIRBF == 0);
        c = SPI3BUF;
        *rxBuff = c;
        --rxBytes;
        ++rxBuff;
    }
    return true;
}