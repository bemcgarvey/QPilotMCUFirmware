/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: led.h                                     //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: LED macros                         //
/////////////////////////////////////////////////////

#ifndef LED_H
#define	LED_H

#define LED1On()        (LATCbits.LATC13 = 1)
#define LED1Off()       (LATCbits.LATC13 = 0)
#define LED1Toggle()    (LATCbits.LATC13 ^= 1)
#define LED2On()        (LATBbits.LATB8 = 1)
#define LED2Off()       (LATBbits.LATB8 = 0)
#define LED2Toggle()    (LATBbits.LATB8 ^= 1)
#define ExtLEDOn()      (LATEbits.LATE13 = 1)
#define ExtLEDOff()     (LATEbits.LATE13 = 0)
#define ExtLEDToggle()  (LATEbits.LATE13 ^= 1)

#endif	/* LED_H */

