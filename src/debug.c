/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: debug.c                                   //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: debugging tools - USART logging    //
/////////////////////////////////////////////////////

#include "device.h"
#include "debug.h"
#include "led.h"

void initDebug(void) {
    U5BRG = 129; //115200 baud
    U5MODEbits.BRGH = 1;
    U5STAbits.URXEN = 1;
    U5STAbits.UTXEN = 1;
    U5STAbits.OERR = 0;
    U5MODEbits.ON = 1;
}

void _mon_putc(char c) {
    while (U5STAbits.UTXBF == 1);
    U5TXREG = c;
}

int _mon_getc(int canblock) {
    char c;
    if (canblock) {
        while (U5STAbits.URXDA == 0);
        c = U5RXREG;
        return c;
    } 
    else if (U5STAbits.URXDA == 1) {
        char c = U5RXREG;
        return c;
    } else {
        return -1;
    }
}