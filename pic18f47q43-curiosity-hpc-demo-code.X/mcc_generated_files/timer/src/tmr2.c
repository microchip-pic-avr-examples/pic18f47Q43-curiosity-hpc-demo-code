/**
  TMR2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr2.c
 
  @Summary
    This is the generated driver implementation file for the TMR2 driver
 
  @Description
    This source file provides APIs for driver for TMR2.
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../tmr2.h"

const struct TMR_INTERFACE Timer2 = {
    .Initialize = Timer2_Initialize,
    .Start = Timer2_Start,
    .Stop = Timer2_Stop,
    .PeriodCountSet = Timer2_PeriodCountSet,
    .TimeoutCallbackRegister = Timer2_OverflowCallbackRegister,
    .Tasks = Timer2_Tasks
};

static void (*Timer2_OverflowCallback)(void);
static void Timer2_DefaultOverflowCallback(void);

/**
  Section: TMR2 APIs
*/

void Timer2_Initialize(void){

    // Set TMR2 to the options selected in the User Interface
    // TCS FOSC/4; 
    T2CLKCON = 0x1;
    // TMODE Software control; TCKSYNC Not Synchronized; TCKPOL Rising Edge; TPSYNC Not Synchronized; 
    T2HLT = 0x0;
    // TRSEL T2CKIPPS pin; 
    T2RST = 0x0;
    // PR 255; 
    T2PR = 0xFF;
    // TMR 0x0; 
    T2TMR = 0x0;

    // Set Default Interrupt Handler
    Timer2_OverflowCallbackRegister(Timer2_DefaultOverflowCallback);

    // Clearing IF flag.
     PIR3bits.TMR2IF = 0;
    // TCKPS 1:1; TMRON on; TOUTPS 1:1; 
    T2CON = 0x80;
}

void Timer2_ModeSet(Timer2_HLT_MODE mode)
{
   // Configure different types HLT mode
    T2HLTbits.T2MODE = mode;
}

void Timer2_ExtResetSourceSet(Timer2_HLT_EXT_RESET_SOURCE reset)
{
    //Configure different types of HLT external reset source
    T2RSTbits.T2RSEL = reset;
}

void Timer2_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
}

void Timer2_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 0;
}

uint8_t Timer2_Read(void)
{
    uint8_t readVal;
    readVal = TMR2;
    return readVal;
}

void Timer2_Write(uint8_t timerVal)
{
    // Write to the Timer2 register
    TMR2 = timerVal;;
}

void Timer2_PeriodCountSet(size_t periodVal)
{
   PR2 = (uint8_t) periodVal;
}

void Timer2_OverflowCallbackRegister(void (* InterruptHandler)(void)){
    Timer2_OverflowCallback = InterruptHandler;
}

static void Timer2_DefaultOverflowCallback(void){
    // add your TMR2 interrupt custom code
    // or set custom function using Timer2_OverflowCallbackRegister()
}

void Timer2_Tasks(void)
{
    if(PIR3bits.TMR2IF)
    {
        // Clearing IF flag.
        PIR3bits.TMR2IF = 0;
        Timer2_OverflowCallback();
    }
}

/**
  End of File
*/