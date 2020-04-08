/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: pins.h                                    //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: I/O pin configuration              //
/////////////////////////////////////////////////////

////////////////////////////
// Pin map
//
// RA0 = V_SENSE = AN0
// RA1 = SDO4
// RA4 = Switch
// RA7 = OC5
// RA8 = U2RX = Sat1
// RA10 = LED1
// RA11 = SCK4in
// RA12 = SDI4
//
// RB0 = SCK3out
// RB1 = SDO3
// RB2 = AN4 = I_SENSE
// RB3 = SDI3
// RB4 = SDI5
// RB5 = U5CTS
// RB6 = U5RX
// RB7 = U5RTS
// RB9 = LED2
// RB10 = OC15
// RB11 = OC16
// RB12 = OC8
// RB14 = INT1 = MCU_INT
// RB15 = FMU_Reset
//
// RC0 = U3RX
// RC1 = U3TX
// RC2 = U4RX = Sat2
// RC6 = OC10
// RC7 = OC1
// RC8 = OC9
// RC9 = OC6
// RC10 = U5TX
// RC11 = FMU_INT
//
// RD5 = OC13
// RD6 = OC2
//
// RE13 = Ext_LED
// RE15 = SCK5in
//
// RF0 = OC14
// RF1 = OC7
//
// RG6 = SAT_3V3_EN
// RG7 = AUX_5V_EN
// RG8 = AUX_5V_OC
////////////////////////////

#ifndef PINS_H
#define	PINS_H

#ifdef	__cplusplus
extern "C" {
#endif

    void initPins(void);
    void setPPS(void);


#ifdef	__cplusplus
}
#endif

#endif	/* PINS_H */

