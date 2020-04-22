/**
  Lab Header File

  @Company
    Microchip Technology Inc.

  @File Name
    labs.h

  @Summary
    This is the header file for the variables declarations and function prototypes

  @Description
    This header file provides all the variables and function prototypes used in this project.
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#ifndef LABS_H
#define	LABS_H

#include <xc.h>
#include <stdint.h>
    

/**
  Section: Macro Declarations
 */
    #define _XTAL_FREQ          500000
    #define PRESSED             1
    #define NOT_PRESSED         0
    #define RUNNING             1
    #define NOT_RUNNING         0
    #define LAST                16
    #define LEDs                LATA
    #define LEDs_SetLow()       do { LATA = 0; } while(0)

    #define INTERRUPT_TMR0InterruptEnable()         do { TMR0IE = 1; } while(0)
    #define INTERRUPT_TMR0InterruptDisable()        do { TMR0IE = 0; } while(0)


/**
  Section: Variable Definitions
 */
    uint8_t labNumber = 0;
    uint8_t switchEvent = 0;
    uint8_t labState = NOT_RUNNING;
    uint8_t btnState = NOT_PRESSED;    

/**
  Section: Function Prototypes
 */
    
/**
  @Summary
    Performs the HelloWorld Lab.

  @Description
    This turns on LED_D2 on the Curiosity Board. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void HelloWorld(void);

/**
  @Summary
    Performs the Blink Lab.

  @Description
    LED_D2 blinks at a rate of approximately 1.5 seconds. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Blink(void);

/**
  @Summary
    Performs the Rotate Lab.

  @Description
    The LEDs rotate from right to left at a rate of 0.5s. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Rotate(void);

/**
  @Summary
    Performs the Analog to Digital Conversion Lab.

  @Description
    The top 4 MSbs of the ADC are displayed on the LEDs. Rotate the potentiometer 
    to change the display. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void ADC(void);

/**
  @Summary
    Performs the Variable Speed Rotate Lab.

  @Description
    The LEDs rotate from right to left similar to Rotate Lab with varying speed.
    Rotate the POT clockwise to see the LEDs shift faster.

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void VSR(void);

/**
  @Summary
    Performs the Pulse Width Modulation Lab.

  @Description
    Rotating the potentiometer will adjust the brightness of a single LED, LED_D5. 
    

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void PWM(void);

/**
  @Summary
    Performs the Timer1 Lab.

  @Description
    The LEDs rotate from right to left, similar to Rotate Lab, at a rate of ~0.5 seconds.

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Timer1(void);

/**
  @Summary
    Performs the Interrupt Lab.

  @Description
    The LEDs rotate at a constant speed of ~0.5s from left to right.

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void Interrupt(void);

/**
  @Summary
    Performs the Sleep-Wakeup Lab.

  @Description
    LED_D2 and LED_D4 are ON while the MCU is in sleep mode. After 4 seconds, the Watchdog 
    Timer will wake up the device from sleep then both LED_D3 and LED_D5 will turn ON, 
    while LED_D2 and LED_D4 will turn OFF. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void SleepWakeUp(void);

/**
  @Summary
    Performs the EEPROM Lab.

  @Description
   The top 4 MSBs of the ADC is written to EEPROM. These are read 
   afterwards and displayed on the LEDs. Rotating the potentiometer changes value of the 
   ADC to be stored/read to/from EEPROM. 

  @Preconditions
    SYSTEM_Initialize() functions should have been called before calling this function.

  @Returns
    None

  @Param
    none
*/
void EEPROM(void);

#endif	/* LABS_H */
/**
 End of File
 */