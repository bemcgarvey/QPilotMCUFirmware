/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: fmu.c                                     //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: FMU control                        //
/////////////////////////////////////////////////////

#include "device.h"
#include "fmu.h"

void resetFMU(void) {
    TRISBbits.TRISB15 = 0; //Make reset pin output
    LATBbits.LATB15 = 0; //Reset
}

void releaseFMU(void) {
    LATBbits.LATB15 = 1;
    TRISBbits.TRISB15 = 1;
}