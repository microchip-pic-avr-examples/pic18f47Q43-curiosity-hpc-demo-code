/**
  uart_interface Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    uart_interface.h

  @Summary
    This is the generated driver interface header file for the uart_interface driver.

  @Description
    This file provides common enumerations for uart_interface driver.
    Generation Information :
        Product Revision  :  CCL - 1.8.2
        Device            :  PIC18F47Q43
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.2
        MPLAB             :  Standalone
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

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H
/**
  Section: Included Files
*/
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>
    
/**
  uart_interface

  @Description
    Structure containing the function pointers of uart_interface driver.
 */
struct UART_INTERFACE
{   
    void (*Initialize)(void);
    uint8_t (*Read)(void);
    void (*Write)(uint8_t);
    void (*RxCompleteCallbackRegister)(void (*CallbackHandler)(void));
    void (*TxCompleteCallbackRegister)(void (*CallbackHandler)(void));
    void (*ErrorCallbackRegister)(void (*CallbackHandler)(void));
    void (*FramingErrorCallbackRegister)(void (*CallbackHandler)(void));
    void (*OverrunErrorCallbackRegister)(void (*CallbackHandler)(void));
    void (*ParityErrorCallbackRegister)(void (*CallbackHandler));
    void (*ChecksumErrorCallbackRegister)(void (*CallbackHandler));
    bool (*IsRxReady)(void);
    bool (*IsTxReady)(void);
    bool (*IsTxDone)(void);
};

#endif // end of UART_INTERFACE_H