/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: power.c                                    //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: Power management for SAT and AUX5V //
/////////////////////////////////////////////////////

#include "device.h"
#include "power.h"

void SATPowerOn(void) {
    LATGbits.LATG6 = 1;
}

void SATPowerOff(void) {
    LATGbits.LATG6 = 0;
}

void AUX5VPowerOn(void) {
    LATGbits.LATG7 = 1;
}

void AUX5VPowerOff(void) {
    LATGbits.LATG7 = 0;
}

bool AUX5VGood(void) {
    return PORTGbits.RG8 == 1;
}
