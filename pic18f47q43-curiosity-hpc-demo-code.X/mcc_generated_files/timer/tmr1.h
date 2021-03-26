/**
  TMR1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.h

  @Summary
    This is the generated header file for the TMR1 driver

  @Description
    This header file provides APIs for driver for TMR1.
    Generation Information :
        Driver Version    :  2.11
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

#ifndef TMR1_H
#define TMR1_H

#include <stdbool.h>
#include <stdint.h>
#include "timer_interface.h"


/**
 @ingroup timer0_driver
 @struct TMR_INTERFACE
 @brief This is an instance of TMR_INTERFACE for Timer module
 */
extern const struct TMR_INTERFACE Timer1;

/**
 * @brief This API initializes the Timer module.
 *        This routine must be called before any other Timer routines.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     while(1)
 *     {   
 *         Timer1_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer1_Initialize(void);


/**
 * @brief This function starts Timer
 *        Timer-0 should be initialized with Timer1_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *     
 *     while(1)
 *     {
 *         Timer1_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer1_Start(void);

/**
 * @brief This function stops Timer
 *        Timer-0 should be initialized with Timer1_Initialize() before calling this API.
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
 *         Timer1_Stop();
 *     }
 * }
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     while(1)
 *     {
 *         Timer1_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer1_Stop(void);

/**
 * @brief This function reads the 16-bits from TMR1 register.
 *        Timer should be initialized with Timer1_Initialize() before calling this API.
 * @param void.
 * @return 16-bit data from TMR1 register.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *     
 *     while(1)
 *     {
 *         if(Timer1_Read() == 0x8000)
 *         {
 *             //do something
 *         }
 *     }
 * }
 * @endcode
 */
uint16_t Timer1_Read(void);

/**
 * @brief This function writes 16-bit value to TMR1 register.
 *        Timer should be initialized with Timer1_Initialize() before calling this API.
 * @param 16-bit value to be written to TMR1 register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     while(1)
 *     {
 *         if(Timer1_Read() == 0x0)
 *         {
 *             Timer1_Write(0x8000)
 *         }
 *     }
 * }
 * @endcode
 */
void Timer1_Write(size_t timerVal);

/**
 * @brief This function loads 8 bit value to TMR1 register.
 *        Timer should be initialized with Timer1_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     while(1)
 *     {
 *         if(some_condition)
 *         {
 *             //Change the period value of TMR1
 *             Timer1_Reload();
 *         }
 *     }
 * }
 * @endcode
 */
void Timer1_Reload(void);


/**
 * @brief This function starts the single pulse acquisition in TMR1 gate operation.
 *        This function must be used when the TMR1 gate is enabled.
 * @param void.
 * @return void.
 *
 * @code
 * uint16_t xVal;
 *   uint16_t yVal;
 *
 *   // enable TMR1 singlepulse mode
 *   Timer1_StartSinglePulseAcquistion();
 *
 *   // check TMR1 gate status
 *   if(Timer1_CheckGateValueStatus()== 0)
 *       xVal = Timer1_Read();
 *
 *   // wait untill gate interrupt occured
 *   while(TMR1GIF == 0)
 *   {
 *   }
 *
 *   yVal = Timer1_Read();
 * @endcode
 */

void Timer1_StartSinglePulseAcquisition(void);

/**
  @Summary
    Check the current state of Timer1 gate.

  @Description
    This function reads the TMR1 gate value and return it.
    This function must be used when the TMR1 gate is enabled.

  @Preconditions
    Initialize  the TMR1 with gate enable before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    uint16_t xVal;
    uint16_t yVal;

    // enable TMR1 singlepulse mode
    Timer1_StartSinglePulseAcquistion();

    // check TMR1 gate status
    if(Timer1_CheckGateValueStatus()== 0)
        xVal = Timer1_Read();

    // wait untill gate interrupt occured
    while(TMR1IF == 0)
    {
    }

    yVal = Timer1_Read();
    </code>
*/
uint8_t Timer1_CheckGateValueStatus(void);


/**
 * @brief Setter function for Timer overflow Callback.
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
 *     Timer1_Initialize();
 *     Timer1_OverflowCallbackRegister(customOverflowCallback);
 *
 *     while(1)
 *     {
 *     }
 * }
 * @endcode
 */
 void Timer1_OverflowCallbackRegister(void (* CallbackHandler)(void));

/**
 * @brief This function performs tasks to be executed on timer overflow event
 * @param void
 * @return void
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *
 *     while(1)
 *     {
 *         Timer1_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer1_Tasks(void);

/**
  @Summary
    Boolean routine to poll or to check for the overflow flag on the fly.

  @Description
    This function is called to check for the timer overflow flag.
    This function is usd in timer polling method.

  @Preconditions
    Initialize  the TMR1 module before calling this routine.

  @Param
    None

  @Returns
    true - timer overflow has occured.
    false - timer overflow has not occured.

  @Example
    <code>
    while(1)
    {
        // check the overflow flag
        if(Timer1_HasOverflowOccured())
        {
            // Do something else...

            // clear the TMR1 interrupt flag
            TMR1IF = 0;

            // Reload the TMR1 value
            Timer1_Reload();
        }
    }
    </code>
*/
bool Timer1_HasOverflowOccured(void);


/**
  @Summary
    Timer Gate Interrupt Service Routine

  @Description
    Timer Gate Interrupt Service Routine is called by the Interrupt Manager.
    User can write the code in this function.

  @Preconditions
    Initialize  the TMR1 module with gate interrupt before calling this isr.

  @Param
    None

  @Returns
    None

  @Example
    None
*/
void Timer1_GATE_ISR(void);

#endif // TMR1_H