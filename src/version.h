/////////////////////////////////////////////////////
// Project: QPilot MCU                             //
// File: version.h                                 //
// Target: PIC32MKxxxxGPD/E064                     // 
// Compiler: XC32                                  //
// Author: Brad McGarvey                           //
// License: GNU General Public License v3.0        //
// Description: firmware version data              //
/////////////////////////////////////////////////////

#ifndef VERSION_H
#define	VERSION_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MAJOR_VERSION   1
#define MINOR_VERSION   0
    
    extern const unsigned int firmwareVersion;


#ifdef	__cplusplus
}
#endif

#endif	/* VERSION_H */

