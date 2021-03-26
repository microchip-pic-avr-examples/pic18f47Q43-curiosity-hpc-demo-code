/**
  TMR0 Generated Driver API Header File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    tmr0.h
 
  @Summary
    This is the generated header file for the TMR0 driver
 
  @Description
    This header file provides APIs for driver for TMR0.
    Generation Information :
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.31
        MPLAB             :  MPLAB X v5.45
*/

/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/

#ifndef TMR0_H
#define TMR0_H

/**
 * @brief This file contains API prototypes and other datatypes for Timer-0 module.
 * @defgroup timer0_driver  Timer 0
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include "timer_interface.h"


/**
 @ingroup timer0_driver
 @struct TMR_INTERFACE
 @brief This is an instance of TMR_INTERFACE for Timer-0 module
 */
extern const struct TMR_INTERFACE Timer0;

/**
 * @ingroup timer0_driver
 * @brief This API initializes the Timer-0 module.
 *        This routine must be called before any other Timer-0 routines.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     while(1)
 *     {   
 *         Timer0_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer0_Initialize(void);

/**
 * @ingroup timer0_driver
 * @brief This function starts Timer-0.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer0_Start();
 *     
 *     while(1)
 *     {
 *         Timer0_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer0_Start(void);

/**
 * @ingroup timer0_driver
 * @brief This function stops Timer-0.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void customAppCallback(void)
 * {
 *     static uint8_t counter;
 *     if(counter++ == 10)
 *     {
 *         counter = 0;
 *         //Stop timer after 10 timeouts
 *         Timer0_Stop();
 *     }
 * }
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     while(1)
 *     {
 *         Timer0_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer0_Stop(void);

/**
 * @ingroup timer0_driver
 * @brief This function reads the 8 bits from TMRTMR0 register.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param void.
 * @return 8-bit data from TMRTMR0 register.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer0_Start();
 *     
 *     while(1)
 *     {
 *         if(Timer0_Read() == 0x80)
 *         {
 *             //do something
 *         }
 *     }
 * }
 * @endcode
 */
uint8_t Timer0_Read(void);

/**
 * @ingroup timer0_driver
 * @brief This function writes 8-bit value to TMRTMR0 register.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param 8-bit value to be written to TMRTMR0 register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     while(1)
 *     {
 *         if(Timer0_Read() == 0x0)
 *         {
 *             Timer0_Write(0x80)
 *         }
 *     }
 * }
 * @endcode
 */
void Timer0_Write(size_t timerVal);

/**
 * @ingroup timer0_driver
 * @brief This function loads 8 bit value to TMRTMR0H register.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param 8-bit value to be written to TMRTMR0H register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     while(1)
 *     {
 *         if(some_condition)
 *         {
 *             //Change the period value of TMR0
 *             Timer0_Reload(0x80);
 *         }
 *     }
 * }
 * @endcode
 */
void Timer0_Reload(uint8_t periodVal);

/**
 * @ingroup timer0_driver
 * @brief Interrupt Service Routine for Timer-0 overflow interrupt.
 * @param void
 * @return void
 */
void Timer0_OverflowISR(void);

/**
 * @ingroup timer0_driver
 * @brief Setter function for Timer-0 overflow Callback.
 * @param CallbackHandler - Pointer to custom Callback.
 * @return void
 *
 * @code
 * void customOverflowCallback(void)
 * {
 *    //Custom ISR code
 * }
 *
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     Timer0_OverflowCallbackRegister(customOverflowCallback);
 *
 *     while(1)
 *     {
 *     }
 * }
 * @endcode
 */
 void Timer0_OverflowCallbackRegister(void (* CallbackHandler)(void));


/**
 * @}
 */
#endif //TMR0_H