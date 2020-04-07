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

#define LED1On()        (LATAbits.LATA10 = 1)
#define LED1Off()       (LATAbits.LATA10 = 0)
#define LED1Toggle()    (LATAbits.LATA10 ^= 1)
#define LED2On()        (LATBbits.LATB9 = 1)
#define LED2Off()       (LATBbits.LATB9 = 0)
#define LED2Toggle()    (LATBbits.LATB9 ^= 1)
#define ExtLEDOn()      (LATEbits.LATE13 = 1)
#define ExtLEDOff()     (LATEbits.LATE13 = 0)
#define ExtLEDToggle()  (LATEbits.LATE13 ^= 1)

#endif	/* LED_H */

