/**
  * TMR1 Generated Driver File
  *
  * @file tmr1.c
  *
  * @ingroup tmr1
  *
  * @brief Driver implementation for the TMR1 driver
  *
  * @version TMR1 Driver Version 3.1.1
*/
/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/**
 * Section: Included Files
*/

#include <xc.h>
#include "../tmr1.h"

/**
 * Section: Global Variables Definitions
*/
volatile uint16_t timer1ReloadVal;
void (*TMR1_InterruptHandler)(void);

const struct TMR_INTERFACE tmr1 = {
    .Initialize = TMR1_Initialize,
    .Start = TMR1_Start,
    .Stop = TMR1_Stop,
    .PeriodCountSet = TMR1_Write,
    .TimeoutCallbackRegister = TMR1_OverflowCallbackRegister,
    .Tasks = TMR1_Tasks
};
static void (*TMR1_OverflowCallback)(void);
static void TMR1_DefaultOverflowCallback(void);
static void (*TMR1_GateCallback)(void);
static void TMR1_DefaultGateCallback(void);

void TMR1_Initialize(void)
{
    //TGGO done; TGSPM disabled; TGTM disabled; TGPOL low; TMRGE disabled; 
    T1GCON = 0x0;
    //TGSS T1G_pin; 
    T1GATE = 0x0;
    //TMRCS FOSC/4; 
    T1CLK = 0x1;
    //TMRH 11; 
    TMR1H = 0xB;
    //TMRL 219; 
    TMR1L = 0xDB;

    // Load the TMR1 value to reload variable
    timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);

    //Set default callback for TMR1 overflow interrupt
    TMR1_OverflowCallbackRegister(TMR1_DefaultOverflowCallback);

    //Set default callback for TMR1 gate interrupt
    TMR1_GateCallbackRegister(TMR1_DefaultGateCallback);

    //Clear interrupt flags
    PIR3bits.TMR1IF = 0;
    PIR3bits.TMR1GIF = 0;
    
    //TMRON disabled; TRD16 disabled; nTSYNC synchronize; TCKPS 1:1; 
    T1CON = 0x0;
}

void TMR1_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void TMR1_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}

uint16_t TMR1_Read(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
    readValLow = TMR1L;
    readValHigh = TMR1H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void TMR1_Write(size_t timerVal)
{
    if (T1CONbits.NOT_SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON = 0;

        // Write to the Timer1 register
        TMR1H = (uint8_t)(timerVal >> 8);
        TMR1L = (uint8_t)timerVal;

        // Start the Timer after writing to the register
        T1CONbits.TMR1ON = 1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H = (uint8_t)(timerVal >> 8);
        TMR1L = (uint8_t)timerVal;
    }
}

void TMR1_Reload(void)
{
    TMR1_Write(timer1ReloadVal);
}

void TMR1_PeriodCountSet(size_t periodVal)
{
   timer1ReloadVal = (uint16_t) periodVal;
}

void TMR1_StartSinglePulseAcquisition(void)
{
    T1GCONbits.T1GGO = 1;
}

uint8_t TMR1_CheckGateValueStatus(void)
{
    return (T1GCONbits.T1GVAL);
}


void TMR1_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    TMR1_OverflowCallback = CallbackHandler;
}

static void TMR1_DefaultOverflowCallback(void)
{
    //Add your interrupt code here or
    //Use TMR1_OverflowCallbackRegister function to use Custom ISR
}

bool TMR1_HasOverflowOccured(void)
{
    return(PIR3bits.TMR1IF);
}

void TMR1_GateISR(void)
{
    // clear the TMR1 interrupt flag
    PIR3bits.TMR1GIF = 0;
    if(TMR1_GateCallback)
    {
        TMR1_GateCallback();
}
}

void TMR1_GateCallbackRegister(void (* CallbackHandler)(void))
{
    TMR1_GateCallback = CallbackHandler;
}

static void TMR1_DefaultGateCallback(void)
{
    //Add your interrupt code here or
    //Use TMR1_GateCallbackRegister function to use Custom ISR
}

void TMR1_Tasks(void)
{
    if(PIR3bits.TMR1IF)
    {
        PIR3bits.TMR1IF = 0;
        TMR1_OverflowCallback();
    }
}

/**
  End of File
*/