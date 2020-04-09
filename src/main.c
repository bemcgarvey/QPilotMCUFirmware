/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: main.c                                    //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: program entry point and nmi handler//
/////////////////////////////////////////////////////
#include "device.h"
#include <stdlib.h> 
#include "definitions.h"               
#include "led.h"
#include "pins.h"
#include "delays.h"
#include "power.h"
#include "debug.h"

int main(void) {
    SYS_Initialize(NULL);
    initPins();
    releaseFMU();
    setPPS();
    initDebug();
    LED1Off();
    LED2On();
    while (true) {
//        char c = _mon_getc(false);
//        if (c != EOF) {
//            printf("rx: %c\r\n", c);
//            if (c == '1') {
//                LED1Toggle();
//            }
//            if (c == '2') {
//                LED2Toggle();
//            }
//        }
        LED1Toggle();
        LED2Toggle();
        delay_ms(1000);
    };
    return ( EXIT_FAILURE);
}

void _nmi_handler(void) {



    //Clear BEV flag
    _CP0_BIC_STATUS(_CP0_STATUS_BEV_MASK);
    __asm__("ERET");
}

