/**
  PWM3_16BIT Generated Driver API Header File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    pwm3_16bit.h
 
  @Summary
    This is the generated header file for the PWM3_16BIT driver
 
  @Description
    This header file provides APIs for driver for PWM3_16BIT.
    Generation Information :
        Driver Version    :  <!--Use existing driver version-->
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLABX 5.30
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

#ifndef PWM3_16BIT_H
#define PWM3_16BIT_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initializes the PWM3_16BIT module
 *        This routine must be called before any other PWM3_16BIT routine
 * @return None.
 * @param None.
 */
void PWM3_16BIT_Initialize(void);

/**
 * @brief Enables the PWM3_16BIT module
 * @return None.
 * @param None.
 */
void PWM3_16BIT_Enable();

/**
 * @brief Disables the PWM3_16BIT module
 *        In case if one wants to re-initialize PWM3_16BIT, this function
 *        must be called before PWM3_16BIT_Initialize()
 * @return None.
 * @param None.
 */
void PWM3_16BIT_Disable();

/**
 * @brief This routine configures the total PWM3_16BIT period. 
 *        PWM3_16BIT_LoadBufferRegisters() must be called after this API
 * @return None.
 * @param [in] Desired 16-bit PWM3_16BIT period
 * @example void main(void)
 *          {
 *              SYSTEM_Initialize();
 *              
 *              // Change the PWM period
 *              PWM3_16BIT_WritePeriodRegister(0x00FF);
 *              PWM3_16BIT_LoadBufferRegisters();
 *
 *          }
 */
void PWM3_16BIT_WritePeriodRegister(uint16_t periodCount);

/**
 * @brief This routine configures the active period or duty cycle of
 *        slice-1, parameter 1 output. PWM3_16BIT_LoadBufferRegisters() must
 *        be called after this API
 * @return None.
 * @param [in] PWMPWM3_16BITS1P1 register value
 * @example void main(void)
 *          {
 *              SYSTEM_Initialize();
 *
 *              // Change the slice-1, parameter-1 output duty cycle
 *              PWM3_16BIT_SetSlice1Output1DutyCycleRegister(0x55);  //33% duty cycle
 *              PWM3_16BIT_LoadBufferRegisters();
 *
 *          }
 */
void PWM3_16BIT_SetSlice1Output1DutyCycleRegister(uint16_t value);

/**
 * @brief This routine configures the active period or duty cycle of
 *        slice-1, parameter 2 output. PWM3_16BIT_LoadBufferRegisters() must
 *        be called after this API
 * @param [in] PWMPWM3_16BITS1P2 register value
 * @example void main(void)
 *          {
 *              SYSTEM_Initialize();
 *
 *              // Change the slice-1, parameter-2 output duty cycle
 *              PWM3_16BIT_SetSlice1Output2DutyCycleRegister(0xAA);   //66% duty cycle
 *              PWM3_16BIT_LoadBufferRegisters();
 *
 *          }
 */
void PWM3_16BIT_SetSlice1Output2DutyCycleRegister(uint16_t value);

/**
 * @brief This routine is used to load period or duty cycle registers on the next period event
 *        This API must be called after changing PR/P1/P2 registers
 * @return None
 * @param None
 * @example void main(void)
 *          {
 *              SYSTEM_Initialize();
 *
 *              // Change the slice-1, parameter-2 output duty cycle
 *              PWM3_16BIT_SetSlice1Output2DutyCycleRegister(0xAA);   //66% duty cycle
 *              PWM3_16BIT_LoadBufferRegisters();
 *
 *          }
 */
void PWM3_16BIT_LoadBufferRegisters(void);

/**
 * @brief Interrupt handler for PWM3_16BIT outputs
 * @return None
 * @param None
 */
void PWM3_16BIT_PWMI_ISR(void);

/**
 * @brief Interrupt handler for PWM3_16BIT period
 * @return None
 * @param None
 */
void PWM3_16BIT_PWMPI_ISR(void);

/**
 * @brief Setter for slice 1, parameter 1 out interrupt handler
 * @return None
 * @param None
 * @example 
 *          void Slice1Output1_CustomInterruptHandler(void)
 *          {
 *              //Custom interrupt handler code
 *          }
 *
 *          void main(void)
 *          {
 *              SYSTEM_Initialize();
 *              
 *              //Use custom handler for Slice1Output1 interrupt
 *              PWM3_16BIT_Slice1Output1_SetInterruptHandler(Slice1Output1_CustomInterruptHandler);
 *          }
 */
void PWM3_16BIT_Slice1Output1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @brief Setter for slice 1, parameter 2 out interrupt handler
 * @return None
 * @param None
 * @example 
 *          void Slice1Output2_CustomInterruptHandler(void)
 *          {
 *              //Custom interrupt handler code
 *          }
 *
 *          void main(void)
 *          {
 *              SYSTEM_Initialize();
 *              
 *              //Use custom handler for Slice1Output2 interrupt
 *              PWM3_16BIT_Slice1Output2_SetInterruptHandler(Slice1Output2_CustomInterruptHandler);
 *          }
 */
void PWM3_16BIT_Slice1Output2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @brief Setter for PWM3_16BIT period interrupt handler
 * @return None
 * @param None
 * @example 
 *          void Period_CustomInterruptHandler(void)
 *          {
 *              //Custom interrupt handler code
 *          }
 *
 *          void main(void)
 *          {
 *              SYSTEM_Initialize();
 *              
 *              //Use custom handler for period interrupt
 *              PWM3_16BIT_Period_SetInterruptHandler(Period_CustomInterruptHandler);
 *          }
 */
void PWM3_16BIT_Period_SetInterruptHandler(void (* InterruptHandler)(void));

#endif //PWM3_16BIT_H