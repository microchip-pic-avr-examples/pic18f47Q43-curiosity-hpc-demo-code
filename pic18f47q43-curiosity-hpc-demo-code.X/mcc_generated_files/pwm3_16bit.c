/**
  PWM3_16BIT Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm3_16bit.c

  @Summary
    This is the generated driver implementation file for the PWM3_16BIT driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for PWM3_16BIT.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F47Q43
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above or later
        MPLAB             :  MPLAB X 5.35
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "pwm3_16bit.h"

//Pointers to PWM3_16BIT interrupt handlers
//User can use them in application code to initialize with custom ISRs
static void (*PWM3_16BIT_Slice1Output1_InterruptHandler)(void);   //SaP1IF and hence PWMxIF is set
static void (*PWM3_16BIT_Slice1Output2_InterruptHandler)(void);   //SaP2IF and hence PWMxIF is set
static void (*PWM3_16BIT_Period_InterruptHandler)(void);          //PWMxPIF is set
static void PWM3_16BIT_Slice1Output1_DefaultInterruptHandler(void);
static void PWM3_16BIT_Slice1Output2_DefaultInterruptHandler(void);
static void PWM3_16BIT_Period_DefaultInterruptHandler(void);

void PWM3_16BIT_Initialize(void)
{
    //PWMERS External Reset Disabled; 
    PWM3ERS = 0x00;

    //PWMCLK HFINTOSC; 
    PWM3CLK = 0x03;

    //PWMLDS Autoload disabled; 
    PWM3LDS = 0x00;

    //PWMPRL 0; 
    PWM3PRL = 0x00;

    //PWMPRH 16; 
    PWM3PRH = 0x10;

    //PWMCPRE Prescale by 10; 
    PWM3CPRE = 0x09;

    //PWMPIPOS No postscale; 
    PWM3PIPOS = 0x00;

    //PWMS1P2IF PWM2 output match did not occur; PWMS1P1IF PWM1 output match did not occur; 
    PWM3GIR = 0x00;

    //PWMS1P2IE disabled; PWMS1P1IE disabled; 
    PWM3GIE = 0x00;

    //PWMPOL2 disabled; PWMPOL1 disabled; PWMPPEN disabled; PWMMODE Left aligned mode; 
    PWM3S1CFG = 0x00;

    //PWMS1P1L 205; 
    PWM3S1P1L = 0xCD;

    //PWMS1P1H 12; 
    PWM3S1P1H = 0x0C;

    //PWMS1P2L 0; 
    PWM3S1P2L = 0x00;

    //PWMS1P2H 8; 
    PWM3S1P2H = 0x08;
    
    //Clear PWM3_16BIT period interrupt flag
    PIR7bits.PWM3PIF = 0;
    
    //Clear PWM3_16BIT interrupt flag
    PIR7bits.PWM3IF = 0;
    
    //Clear PWM3_16BIT slice 1, output 1 interrupt flag
    PWM3GIRbits.S1P1IF = 0;
    
    //Clear PWM3_16BIT slice 1, output 2 interrupt flag
    PWM3GIRbits.S1P2IF = 0;
    
    //PWM3_16BIT interrupt enable bit
    PIE7bits.PWM3IE = 0;
    
    //PWM3_16BIT period interrupt enable bit
    PIE7bits.PWM3PIE = 0;
    
    //Set default interrupt handlers
    PWM3_16BIT_Slice1Output1_SetInterruptHandler(PWM3_16BIT_Slice1Output1_DefaultInterruptHandler);
    PWM3_16BIT_Slice1Output2_SetInterruptHandler(PWM3_16BIT_Slice1Output2_DefaultInterruptHandler);
    PWM3_16BIT_Period_SetInterruptHandler(PWM3_16BIT_Period_DefaultInterruptHandler);

    //PWMEN enabled; PWMLD disabled; PWMERSPOL disabled; PWMERSNOW disabled; 
    PWM3CON = 0x80;
}

void PWM3_16BIT_Enable()
{
    PWM3CON |= _PWM3CON_EN_MASK;
}

void PWM3_16BIT_Disable()
{
    PWM3CON &= (~_PWM3CON_EN_MASK);
}

void PWM3_16BIT_WritePeriodRegister(uint16_t periodCount)
{
    PWM3PRL = (uint8_t)periodCount;
    PWM3PRH = (uint8_t)(periodCount >> 8);
}

void PWM3_16BIT_SetSlice1Output1DutyCycleRegister(uint16_t registerValue)
{    
    PWM3S1P1L = (uint8_t)(registerValue);
    PWM3S1P1H = (uint8_t)(registerValue >> 8);
}

void PWM3_16BIT_SetSlice1Output2DutyCycleRegister(uint16_t registerValue)
{        
    PWM3S1P2L = (uint8_t)(registerValue);
    PWM3S1P2H = (uint8_t)(registerValue >> 8);
}

void PWM3_16BIT_LoadBufferRegisters(void)
{
    //Load the period and duty cycle registers on the next period event
    PWM3CONbits.LD = 1;
}

void PWM3_16BIT_PWMI_ISR(void)
{
    PIR7bits.PWM3IF = 0;
    if((PWM3GIEbits.S1P1IE == 1) && (PWM3GIRbits.S1P1IF == 1))
    {
        PWM3GIRbits.S1P1IF = 0;
        if(PWM3_16BIT_Slice1Output1_InterruptHandler != NULL)
            PWM3_16BIT_Slice1Output1_InterruptHandler();
    }
    else if((PWM3GIEbits.S1P2IE == 1) && (PWM3GIRbits.S1P2IF == 1))
    {
        PWM3GIRbits.S1P2IF = 0;
        if(PWM3_16BIT_Slice1Output2_InterruptHandler != NULL)
            PWM3_16BIT_Slice1Output2_InterruptHandler();
    }
}

void PWM3_16BIT_PWMPI_ISR(void)
{
    PIR7bits.PWM3PIF = 0;
    if(PWM3_16BIT_Period_InterruptHandler != NULL)
        PWM3_16BIT_Period_InterruptHandler();
}

void PWM3_16BIT_Slice1Output1_SetInterruptHandler(void (* InterruptHandler)(void))
{
    PWM3_16BIT_Slice1Output1_InterruptHandler = InterruptHandler;
}

void PWM3_16BIT_Slice1Output2_SetInterruptHandler(void (* InterruptHandler)(void))
{
    PWM3_16BIT_Slice1Output2_InterruptHandler = InterruptHandler;
}

void PWM3_16BIT_Period_SetInterruptHandler(void (* InterruptHandler)(void))
{
    PWM3_16BIT_Period_InterruptHandler = InterruptHandler;
}

static void PWM3_16BIT_Slice1Output1_DefaultInterruptHandler(void)
{
    //Add your interrupt code here or
    //Use PWM3_16BIT_Slice1Output1_SetInterruptHandler() function to use Custom ISR
}

static void PWM3_16BIT_Slice1Output2_DefaultInterruptHandler(void)
{
    //Add your interrupt code here or
    //Use PWM3_16BIT_Slice1Output2_SetInterruptHandler() function to use Custom ISR
}

static void PWM3_16BIT_Period_DefaultInterruptHandler(void)
{
    //Add your interrupt code here or
    //Use PWM3_16BIT_Period_SetInterruptHandler() function to use Custom ISR
}
