/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: initialization.c                          //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: config bits and initialization     //
/////////////////////////////////////////////////////
#include "definitions.h"
#include "device.h"

/*** DEVCFG0 ***/
#pragma config DEBUG =      OFF
#pragma config JTAGEN =     OFF
#pragma config ICESEL =     ICS_PGx2
#pragma config TRCEN =      OFF
#pragma config BOOTISA =    MIPS32
#pragma config FSLEEP =     OFF
#pragma config DBGPER =     PG_ALL
#pragma config SMCLR =      MCLR_NORM
#pragma config SOSCGAIN =   GAIN_2X
#pragma config SOSCBOOST =  OFF
#pragma config POSCGAIN =   GAIN_LEVEL_0
#pragma config POSCBOOST =  OFF
#pragma config EJTAGBEN =   NORMAL

/*** DEVCFG1 ***/
#pragma config FNOSC =      SPLL
#pragma config DMTINTV =    WIN_127_128
#pragma config FSOSCEN =    OFF
#pragma config IESO =       ON
#pragma config POSCMOD =    EC
#pragma config OSCIOFNC =   OFF
#pragma config FCKSM =      CSECME
#pragma config WDTPS =      PS64
#pragma config WDTSPGM =    STOP
#pragma config FWDTEN =     OFF
#pragma config WINDIS =     NORMAL
#pragma config FWDTWINSZ =  WINSZ_25
#pragma config DMTCNT =     DMT31
#pragma config FDMTEN =     OFF

/*** DEVCFG2 ***/
#pragma config FPLLIDIV =   DIV_3
#pragma config FPLLRNG =    RANGE_8_16_MHZ
#pragma config FPLLICLK =   PLL_POSC
#pragma config FPLLMULT =   MUL_60
#pragma config FPLLODIV =   DIV_4
#pragma config VBATBOREN =  OFF
#pragma config DSBOREN =    OFF
#pragma config DSWDTPS =    DSPS32
#pragma config DSWDTOSC =   LPRC
#pragma config DSWDTEN =    OFF
#pragma config FDSEN =      OFF
#pragma config BORSEL =     LOW
#pragma config UPLLEN =     OFF

/*** DEVCFG3 ***/
#pragma config USERID =     0xffff
#pragma config FUSBIDIO2 =   OFF
#pragma config FVBUSIO2 =  OFF
#pragma config PGL1WAY =    ON
#pragma config PMDL1WAY =   ON
#pragma config IOL1WAY =    ON
#pragma config FUSBIDIO1 =   OFF
#pragma config FVBUSIO1 =  OFF

/*** BF1SEQ ***/
#pragma config TSEQ =       0x0
#pragma config CSEQ =       0xffff

void SYS_Initialize(void* data) {
    __builtin_disable_interrupts();
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    OSCCONbits.FRCDIV = 0;
    PB6DIVbits.PBDIV = 0b11; //See errata

    //TODO Disable unused modules
    PMD1SET = 0;
    PMD2SET = 0;
    PMD3SET = 0;
    PMD4SET = 0;
    PMD5SET = 0;
    PMD6SET = 0;
    PMD7SET = 0;

    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    CFGCONbits.PMDLOCK = 1;
    SYSKEY = 0x33333333;

    //Configure CP0.K0 for cache policy
    //Write back, write allocate cache policy.
    __builtin_mtc0(16, 0, ((__builtin_mfc0(16, 0) & ~0x03) | 0x03));
    /* Configure Wait States and Prefetch */
    CHECONbits.PFMWS = 3;
    //TODO Check chip revision to see if this can be enabled - currently disabled per errata
    CHECONbits.PREFEN = 0;
    INTCONbits.MVEC = 1;
}
