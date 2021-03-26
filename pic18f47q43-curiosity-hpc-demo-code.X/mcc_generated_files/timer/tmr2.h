/**
  TMR2 Generated Driver API Header File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    tmr2.h
 
  @Summary
    This is the generated header file for the TMR2 driver
 
  @Description
    This header file provides APIs for driver for TMR2.
    Generation Information :
        Driver Version    :  3.0.0
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

#ifndef TMR2_H
#define TMR2_H

/**
 * @brief This file contains API prototypes and other datatypes for TMR2 module.
 * @defgroup TMR2_driver  TMR2
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include "timer_interface.h"

/**
 Section: Data Type Definitions
*/
/**
 @ingroup TMR2_driver
 @struct TMR_INTERFACE
 @brief This is an instance of TMR_INTERFACE for TMR2 module
 */
extern const struct TMR_INTERFACE Timer2;

/**
  HLT Mode Setting Enumeration

  @Summary
    Defines the different modes of the HLT.

  @Description
    This defines the several modes of operation of the Timer with
	HLT extension. The modes can be set in a control register associated
	with the timer
*/

typedef enum
{

	/* Roll-over Pulse mode clears the TMRx upon TMRx = PRx, then continue running.
	ON bit must be set and is not affected by Resets
	*/

   /* Roll-over Pulse mode indicates that Timer starts
   immediately upon ON = 1 (Software Control)
   */
   Timer2_ROP_STARTS_TMRON,

   /* Roll-over Pulse mode indicates that the Timer starts
       when ON = 1 and TMRx_ers = 1. Stops when TMRx_ers = 0
     */
   Timer2_ROP_STARTS_TMRON_ERSHIGH,

   /* Roll-over Pulse mode indicates that the Timer starts
      when ON = 1 and TMRx_ers = 0. Stops when TMRx_ers = 1
     */
   Timer2_ROP_STARTS_TMRON_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon rising or falling edge of TMRx_ers
     */
   Timer2_ROP_RESETS_ERSBOTHEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
    upon rising edge of TMRx_ers
     */
   Timer2_ROP_RESETS_ERSRISINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon falling edge of TMRx_ers
     */
   Timer2_ROP_RESETS_ERSFALLINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 0
     */
   Timer2_ROP_RESETS_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 1
     */
   Timer2_ROP_RESETS_ERSHIGH,

    /*In all One-Shot mode the timer resets and the ON bit is
	cleared when the timer value matches the PRx period
	value. The ON bit must be set by software to start
	another timer cycle.
	*/

   /* One shot mode indicates that the Timer starts
    immediately upon ON = 1 (Software Control)
     */
   Timer2_OS_STARTS_TMRON,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers
     */
   Timer2_OS_STARTS_ERSRISINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers
     */
   Timer2_OS_STARTS_ERSFALLINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when either a rising or falling edge is detected on TMRx_ers
     */
   Timer2_OS_STARTS_ERSBOTHEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers rising edge and resets on all
	subsequent TMRx_ers rising edges
     */
   Timer2_OS_STARTS_ERSFIRSTRISINGEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers falling edge and restarts on all
	subsequent TMRx_ers falling edges
     */
   Timer2_OS_STARTS_ERSFIRSTFALLINGEDGE,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 0
     */
   Timer2_OS_STARTS_ERSRISINGEDGEDETECT,
     /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 1
     */
   Timer2_OS_STARTS_ERSFALLINGEDGEDETECT,
   
   /* One shot mode indicates that the Timer starts
    when a TMRx_ers = 1,ON =1 and resets upon TMRx_ers =0
    */
   Timer2_OS_STARTS_TMRON_ERSHIGH = 0x16,
           
   /* One shot mode indicates that the Timer starts
     when a TMRx_ers = 0,ON = 1 and resets upon TMRx_ers =1 
    */
   Timer2_OS_STARTS_TMRON_ERSLOW = 0x17,
        
   /*In all Mono-Stable mode the ON bit must be initially set,but
     not cleared upon the TMRx = PRx, and the timer will start upon
     an TMRx_ers start event following TMRx = PRx.*/
               
   /* Mono Stable mode indicates that the Timer starts
      when a rising edge is detected on the TMRx_ers and ON = 1
    */
   Timer2_MS_STARTS_TMRON_ERSRISINGEDGEDETECT = 0x11,
           
   /* Mono Stable mode indicates that the Timer starts
      when a falling edge is detected on the TMRx_ers and ON = 1
    */
   Timer2_MS_STARTS_TMRON_ERSFALLINGEDGEDETECT = 0x12,
           
   /* Mono Stable mode indicates that the Timer starts
      when  either a rising or falling edge is detected on TMRx_ers 
      and ON = 1
    */
   Timer2_MS_STARTS_TMRON_ERSBOTHEDGE = 0x13
           
} Timer2_HLT_MODE;

/**
  HLT Reset Source Enumeration

  @Summary
    Defines the different reset source of the HLT.

  @Description
    This source can control starting and stopping of the
	timer, as well as resetting the timer, depending on
	which mode the timer is in. The mode of the timer is
	controlled by the HLT_MODE
*/

typedef enum
{
     /* T2INPPS is the Timer external reset source
     */
    Timer2_T2INPPS,

    /* Reserved enum cannot be used 
     */
    Timer2_RESERVED,
    
    /* Timer4 Postscale is the Timer external reset source 
     */
    Timer2_T4POSTSCALED,
    
    /* Timer6 Postscale is the Timer external reset source 
     */
    Timer2_T6POSTSCALED,

    /* CCP1_OUT is the Timer external reset source 
     */
    Timer2_CCP1_OUT,

    /* CCP2_OUT is the Timer external reset source 
     */
    Timer2_CCP2_OUT,

    /* CCP3_OUT is the Timer external reset source 
     */
    Timer2_CCP3_OUT,

    /* PWM1S1P1_out is the Timer external reset source 
     */
    Timer2_PWM1S1P1_OUT,

    /* PWM1S1P2_out is the Timer external reset source 
     */
    Timer2_PWM1S1P2_OUT,

    /* PWM2S1P1_out is the Timer external reset source 
     */
    Timer2_PWM2S1P1_OUT,

    /* PWM2S1P2_out is the Timer external reset source 
     */
    Timer2_PWM2S1P2_OUT,

    /* PWM3S1P1_out is the Timer external reset source 
     */
    Timer2_PWM3S1P1_OUT,

    /* PWM3S1P2_out is the Timer external reset source 
     */
    Timer2_PWM3S1P2_OUT,

    /* Reserved enum cannot be used 
    */
    Timer2_RESERVED_2,

    /* Reserved enum cannot be used 
    */
    Timer2_RESERVED_3,

    /* CMP1_OUT is the Timer external reset source 
     */
    Timer2_CMP1_OUT,

    /* CMP2_OUT is the Timer external reset source 
     */
    Timer2_CMP2_OUT,

    /* ZCD_Output is the Timer external reset source 
     */
    Timer2_ZCD_OUTPUT,

    /* CLC1_out is the Timer external reset source 
     */
    Timer2_CLC1_OUT,
         
    /* CLC2_out is the Timer external reset source 
     */
    Timer2_CLC2_OUT,
            
    /* CLC3_out is the Timer external reset source 
     */
    Timer2_CLC3_OUT,

    /* CLC4_out is the Timer external reset source 
     */
    Timer2_CLC4_OUT,  

    /* CLC5_out is the Timer external reset source 
     */
    Timer2_CLC5_OUT,
         
    /* CLC6_out is the Timer external reset source 
     */
    Timer2_CLC6_OUT,
            
    /* CLC7_out is the Timer external reset source 
     */
    Timer2_CLC7_OUT,
    
    /* CLC8_out is the Timer external reset source 
     */
    Timer2_CLC8_OUT,

    /* UART1_rx_edge is the Timer external reset source 
     */
    Timer2_UART1_RX_EDGE,

    /* UART1_tx_edge is the Timer external reset source 
     */
    Timer2_UART1_TX_EDGE,

    /* UART2_rx_edge is the Timer external reset source 
     */
    Timer2_UART2_RX_EDGE,

    /* UART2_tx_edge is the Timer external reset source 
     */
    Timer2_UART2_TX_EDGE,

    /* UART3_rx_edge is the Timer external reset source 
     */
    Timer2_UART3_RX_EDGE,

    /* UART3_tx_edge is the Timer external reset source 
     */
    Timer2_UART3_TX_EDGE,

    /* UART4_rx_edge is the Timer external reset source 
     */
    Timer2_UART4_RX_EDGE,

    /* UART4_tx_edge is the Timer external reset source 
     */
    Timer2_UART4_TX_EDGE,

    /* UART5_rx_edge is the Timer external reset source 
     */
    Timer2_UART5_RX_EDGE,

    /* UART5_tx_edge is the Timer external reset source 
     */
    Timer2_UART5_TX_EDGE,

    /* Reserved enum cannot be used 
    */
    Timer2_RESERVED_4

} Timer2_HLT_EXT_RESET_SOURCE;


/**
  Section: Macro Declarations
*/

/**
  Section: TMR2 APIs
*/

/**
 * @ingroup TMR2_driver
 * @brief This API initializes the TMR2 module.
 *        This routine must be called before any other TMR2 routines.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer2_Initialize();
 *     
 *     while(1)
 *     {   
 *         Timer2_Tasks();
 *     }
 * }
 * @endcode
 */
 void Timer2_Initialize(void);

/**
 * @ingroup TMR2_driver
 * @brief Configures the Hardware Limit Timer mode.
 *        Writes the T2HLTbits.MODE bits.
 *        TMR2 should be initialized with Timer2_Initialize after calling this API.
 * @param mode - Value to write into T2HLTbits.MODE bits.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer2_HLT_MODE hltmode;
 *     hltmode = Timer2_ROP_STARTS_TMRON_EN;
 *
 *     // Initialize TMR2 module
 *     Timer2_Initialize();
 *	   // Set the HLT mode
 *	   Timer2_ModeSet (hltmode);
 *
 *     // Do something else...
 * }
 * @endcode
 */
void Timer2_ModeSet(Timer2_HLT_MODE mode);

/**
 * @ingroup TMR2_driver
 * @brief Configures the HLT external reset source.
 *        Writes the T2RSTbits.RSEL bits.
 *        TMR2 should be initialized with Timer2_Initialize after calling this API.
 * @param reset - Value to write into T2RSTbits.RSEL bits.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer2_HLT_EXT_RESET_SOURCE hltresetsrc;
 *     hltresetsrc = T2IN;
 *
 *     // Initialize TMR2 module
 *     Timer2_Initialize();
 *
 *	   // Set the HLT mode
 *	   Timer2_ExtResetSourceSet(hltresetsrc);
 *
 *     // Do something else...
 * }
 * @endcode
 */
void Timer2_ExtResetSourceSet(Timer2_HLT_EXT_RESET_SOURCE reset);

/**
 * @ingroup TMR2_driver
 * @brief This function starts TMR2.
 *        TMR2 should be initialized with Timer2_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer2_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer2_Start();
 *     
 *     while(1)
 *     {
 *         Timer2_Start();
 *     }
 * }
 * @endcode
 */
void Timer2_Start(void);

/**
 * @ingroup TMR2_driver
 * @brief This function stops TMR2.
 *        TMR2 should be initialized with Timer2_Initialize() before calling this API.
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
 *         Timer2_Stop();
 *     }
 * }
 * void main(void)
 * {
 *     Timer2_Initialize();
 *     
 *     while(1)
 *     {
 *         Timer2_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer2_Stop(void);

/**
 * @ingroup TMR2_driver
 * @brief This function reads the 8 bits from TMR2 register.
 *        TMR2 should be initialized with Timer2_Initialize() before calling this API.
 * @param void.
 * @return 8-bit data from TMR2 register.
 *
 * @code
 * void main(void)
 * {
 *     Timer2_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer2_Start();
 *     
 *     while(1)
 *     {
 *         if(Timer2_Read(); == 0x80)
 *         {
 *             //do something
 *         }
 *     }
 * }
 * @endcode
 */
uint8_t Timer2_Read(void);

/**
 * @ingroup TMR2_driver
 * @brief This function writes 8-bit value to TMR2 register.
 *        TMR2 should be initialized with Timer2_Initialize() before calling this API.
 * @param 8-bit value to be written to TMR2 register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer2_Initialize();
 *     
 *     while(1)
 *     {
 *         if(Timer2_Read() == 0x0)
 *         {
 *             Timer2_Write();
 *         }
 *     }
 * }
 * @endcode
 */
void Timer2_Write(uint8_t timerVal);

/**
 * @ingroup TMR2_driver
 * @brief This function loads 8 bit value to PR2H register.
 *        TMR2 should be initialized with Timer2_Initialize() before calling this API.
 * @param 8-bit value to be written to PR2 register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer2_Initialize()
 *     
 *     while(1)
 *     {
 *         if(some_condition)
 *         {
 *             //Change the period value of TMR2
 *             Timer2_PeriodCountSet(0x80);
 *         }
 *     }
 * }
 * @endcode
 */
void Timer2_PeriodCountSet(size_t periodVal);

/**
 * @ingroup TMR2_driver
 * @brief Setter function for TMR2 overflow Callback.
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
 *     Timer2_Initialize();
 *     Timer2_OverflowCallbackRegister(customOverflowCallback)
 *
 *     while(1)
 *     {
 *     }
 * }
 * @endcode
 */
void Timer2_OverflowCallbackRegister(void (* InterruptHandler)(void));

/**
 * @ingroup TMR2_driver
 * @brief This function performs tasks to be executed on timer overflow event
 * @param void
 * @return void
 *
 * @code
 * void main(void)
 * {
 *     Timer2_Initialize();
 *
 *     while(1)
 *     {
 *         Timer2_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer2_Tasks(void);

#endif // TMR2_H
/**
 End of File
*/