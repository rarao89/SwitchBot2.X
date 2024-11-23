/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1778
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TURN_ON aliases
#define TURN_ON_TRIS                 TRISAbits.TRISA0
#define TURN_ON_LAT                  LATAbits.LATA0
#define TURN_ON_PORT                 PORTAbits.RA0
#define TURN_ON_WPU                  WPUAbits.WPUA0
#define TURN_ON_OD                   ODCONAbits.ODA0
#define TURN_ON_ANS                  ANSELAbits.ANSA0
#define TURN_ON_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define TURN_ON_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define TURN_ON_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define TURN_ON_GetValue()           PORTAbits.RA0
#define TURN_ON_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define TURN_ON_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define TURN_ON_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define TURN_ON_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define TURN_ON_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define TURN_ON_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define TURN_ON_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define TURN_ON_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set TURN_OFF aliases
#define TURN_OFF_TRIS                 TRISAbits.TRISA1
#define TURN_OFF_LAT                  LATAbits.LATA1
#define TURN_OFF_PORT                 PORTAbits.RA1
#define TURN_OFF_WPU                  WPUAbits.WPUA1
#define TURN_OFF_OD                   ODCONAbits.ODA1
#define TURN_OFF_ANS                  ANSELAbits.ANSA1
#define TURN_OFF_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define TURN_OFF_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define TURN_OFF_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define TURN_OFF_GetValue()           PORTAbits.RA1
#define TURN_OFF_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define TURN_OFF_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define TURN_OFF_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define TURN_OFF_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define TURN_OFF_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define TURN_OFF_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define TURN_OFF_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define TURN_OFF_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set INTA aliases
#define INTA_TRIS                 TRISBbits.TRISB0
#define INTA_LAT                  LATBbits.LATB0
#define INTA_PORT                 PORTBbits.RB0
#define INTA_WPU                  WPUBbits.WPUB0
#define INTA_ANS                  ANSELBbits.ANSB0
#define INTA_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define INTA_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define INTA_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define INTA_GetValue()           PORTBbits.RB0
#define INTA_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define INTA_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define INTA_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define INTA_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define INTA_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define INTA_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set DOWN aliases
#define DOWN_TRIS                 TRISCbits.TRISC5
#define DOWN_LAT                  LATCbits.LATC5
#define DOWN_PORT                 PORTCbits.RC5
#define DOWN_WPU                  WPUCbits.WPUC5
#define DOWN_OD                   ODCONCbits.ODC5
#define DOWN_ANS                  ANSELCbits.ANSC5
#define DOWN_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define DOWN_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define DOWN_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define DOWN_GetValue()           PORTCbits.RC5
#define DOWN_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define DOWN_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define DOWN_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define DOWN_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define DOWN_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define DOWN_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)
#define DOWN_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define DOWN_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set UP aliases
#define UP_TRIS                 TRISCbits.TRISC6
#define UP_LAT                  LATCbits.LATC6
#define UP_PORT                 PORTCbits.RC6
#define UP_WPU                  WPUCbits.WPUC6
#define UP_OD                   ODCONCbits.ODC6
#define UP_ANS                  ANSELCbits.ANSC6
#define UP_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define UP_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define UP_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define UP_GetValue()           PORTCbits.RC6
#define UP_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define UP_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define UP_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define UP_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define UP_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define UP_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define UP_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define UP_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SELECT aliases
#define SELECT_TRIS                 TRISCbits.TRISC7
#define SELECT_LAT                  LATCbits.LATC7
#define SELECT_PORT                 PORTCbits.RC7
#define SELECT_WPU                  WPUCbits.WPUC7
#define SELECT_OD                   ODCONCbits.ODC7
#define SELECT_ANS                  ANSELCbits.ANSC7
#define SELECT_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SELECT_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SELECT_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SELECT_GetValue()           PORTCbits.RC7
#define SELECT_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SELECT_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SELECT_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SELECT_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SELECT_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define SELECT_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define SELECT_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SELECT_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/