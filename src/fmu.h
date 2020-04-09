/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: fmu.h                                     //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: FMU control                        //
/////////////////////////////////////////////////////

#ifndef FMU_H
#define	FMU_H

#ifdef	__cplusplus
extern "C" {
#endif

    void resetFMU(void);
    void releaseFMU(void);


#ifdef	__cplusplus
}
#endif

#endif	/* FMU_H */

