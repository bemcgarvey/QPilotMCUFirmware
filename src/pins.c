/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: pins.c                                    //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: I/O pin configuration              //
/////////////////////////////////////////////////////
#include "device.h"
#include "pins.h"

void initPins(void) {
    //Set all pins to digital output low level
    LATA = 0;
    LATB = 0;
    LATC = 0;
    LATD = 0;
    LATE = 0;
    LATF = 0;
    LATG = 0;
    ANSELA = 0;
    ANSELAbits.ANSA0 = 1;
    ANSELB = 0;
    ANSELBbits.ANSB2 = 1;
    ANSELC = 0;
    ANSELE = 0;
    ANSELG = 0;
    TRISA = 0;
    TRISAbits.TRISA0 = 1; //AN0 - V_SENSE
    TRISAbits.TRISA4 = 1; //Switch
    TRISB = 0;
    TRISBbits.TRISB2 = 1; //AN4 - I_SENSE
    TRISC = 0;
    TRISD = 0;
    TRISE = 0;
    TRISF = 0;
    TRISG = 0;
    TRISGbits.TRISG8 = 1; //AUX_5V_OC
}

void setPPS(void) {
    /* unlock system for PPS configuration */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    CFGCONbits.IOLOCK = 0;
    /* PPS Input Remapping */
    U2RXR = 0b0101;
    SCK4R = 0b1000;
    SDI4R = 0b1000;
    SDI3R = 0b0001;
    SDI5R = 0b0010;
    U5CTSR = 0b0001;
    U5RXR = 0b0000;
    INT1R = 0b0000;
    U3RXR = 0b0110;
    U4RXR = 0b0110;
    SCK5R = 0b1000;

    /* PPS Output Remapping */
    RPA1R = 0b01111;
    RPA7R = 0b00110;
    RPB0R = 0b01110;
    RPB1R = 0b01110;
    RPB7R = 0b01011;
    RPB10R = 0b01010;
    RPB11R = 0b01010;
    RPB12R = 0b00110;
    RPC1R = 0b00001;
    RPC6R = 0b01001;
    RPC7R = 0b00101;
    RPC8R = 0b01000;
    RPC9R = 0b00110;
    RPC10R = 0b01011;
    RPD5R = 0b01001;
    RPD6R = 0b00101;
    RPF0R = 0b01010;
    RPF1R = 0b00110;
    
    /* Lock the system after PPS configuration */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    CFGCONbits.IOLOCK = 1;
}
