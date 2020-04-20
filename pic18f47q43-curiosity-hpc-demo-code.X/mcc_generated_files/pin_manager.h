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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F47Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.35	
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

// get/set POT_CHANNEL aliases
#define POT_CHANNEL_TRIS                 TRISAbits.TRISA0
#define POT_CHANNEL_LAT                  LATAbits.LATA0
#define POT_CHANNEL_PORT                 PORTAbits.RA0
#define POT_CHANNEL_WPU                  WPUAbits.WPUA0
#define POT_CHANNEL_OD                   ODCONAbits.ODCA0
#define POT_CHANNEL_ANS                  ANSELAbits.ANSELA0
#define POT_CHANNEL_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define POT_CHANNEL_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define POT_CHANNEL_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define POT_CHANNEL_GetValue()           PORTAbits.RA0
#define POT_CHANNEL_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define POT_CHANNEL_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define POT_CHANNEL_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define POT_CHANNEL_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define POT_CHANNEL_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define POT_CHANNEL_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define POT_CHANNEL_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define POT_CHANNEL_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set LED_D2 aliases
#define LED_D2_TRIS                 TRISAbits.TRISA4
#define LED_D2_LAT                  LATAbits.LATA4
#define LED_D2_PORT                 PORTAbits.RA4
#define LED_D2_WPU                  WPUAbits.WPUA4
#define LED_D2_OD                   ODCONAbits.ODCA4
#define LED_D2_ANS                  ANSELAbits.ANSELA4
#define LED_D2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_D2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_D2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_D2_GetValue()           PORTAbits.RA4
#define LED_D2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_D2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED_D2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED_D2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED_D2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED_D2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED_D2_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LED_D2_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set LED_D3 aliases
#define LED_D3_TRIS                 TRISAbits.TRISA5
#define LED_D3_LAT                  LATAbits.LATA5
#define LED_D3_PORT                 PORTAbits.RA5
#define LED_D3_WPU                  WPUAbits.WPUA5
#define LED_D3_OD                   ODCONAbits.ODCA5
#define LED_D3_ANS                  ANSELAbits.ANSELA5
#define LED_D3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_D3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_D3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_D3_GetValue()           PORTAbits.RA5
#define LED_D3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_D3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_D3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_D3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_D3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_D3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_D3_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED_D3_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set LED_D4 aliases
#define LED_D4_TRIS                 TRISAbits.TRISA6
#define LED_D4_LAT                  LATAbits.LATA6
#define LED_D4_PORT                 PORTAbits.RA6
#define LED_D4_WPU                  WPUAbits.WPUA6
#define LED_D4_OD                   ODCONAbits.ODCA6
#define LED_D4_ANS                  ANSELAbits.ANSELA6
#define LED_D4_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LED_D4_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LED_D4_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LED_D4_GetValue()           PORTAbits.RA6
#define LED_D4_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LED_D4_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define LED_D4_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define LED_D4_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define LED_D4_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define LED_D4_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define LED_D4_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define LED_D4_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set LED_D5 aliases
#define LED_D5_TRIS                 TRISAbits.TRISA7
#define LED_D5_LAT                  LATAbits.LATA7
#define LED_D5_PORT                 PORTAbits.RA7
#define LED_D5_WPU                  WPUAbits.WPUA7
#define LED_D5_OD                   ODCONAbits.ODCA7
#define LED_D5_ANS                  ANSELAbits.ANSELA7
#define LED_D5_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED_D5_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED_D5_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED_D5_GetValue()           PORTAbits.RA7
#define LED_D5_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED_D5_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LED_D5_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LED_D5_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LED_D5_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define LED_D5_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define LED_D5_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define LED_D5_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set SWITCH_S1 aliases
#define SWITCH_S1_TRIS                 TRISBbits.TRISB4
#define SWITCH_S1_LAT                  LATBbits.LATB4
#define SWITCH_S1_PORT                 PORTBbits.RB4
#define SWITCH_S1_WPU                  WPUBbits.WPUB4
#define SWITCH_S1_OD                   ODCONBbits.ODCB4
#define SWITCH_S1_ANS                  ANSELBbits.ANSELB4
#define SWITCH_S1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SWITCH_S1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SWITCH_S1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SWITCH_S1_GetValue()           PORTBbits.RB4
#define SWITCH_S1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SWITCH_S1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SWITCH_S1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SWITCH_S1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SWITCH_S1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SWITCH_S1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SWITCH_S1_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SWITCH_S1_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSELB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

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