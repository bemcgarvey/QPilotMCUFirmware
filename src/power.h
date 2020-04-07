/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: power.h                                   //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: Power management for SAT and AUX5V //
/////////////////////////////////////////////////////

#ifndef POWER_H
#define	POWER_H

#ifdef	__cplusplus
extern "C" {
#endif

void SATPowerOn(void);
void SATPowerOff(void);
void AUX5VPowerOn(void);
void AUX5VPowerOff(void);
bool AUX5VGood(void);


#ifdef	__cplusplus
}
#endif

#endif	/* POWER_H */

