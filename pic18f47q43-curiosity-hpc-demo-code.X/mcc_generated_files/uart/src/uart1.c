/**
  UART1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    uart1.c

  @Summary
    This is the generated driver implementation file for the UART1 driver using CCL

  @Description
    This source file provides APIs for UART1.
    Generation Information :
        Driver Version    :  2.4.0
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

/**
  Section: Included Files
*/
#include <xc.h>
#include "../uart1.h"

const struct UART_INTERFACE UART1_Interface = {
  .Initialize = UART1_Initialize,
  .Write = UART1_Write,
  .Read = UART1_Read,
  .RxCompleteCallbackRegister = NULL,
  .TxCompleteCallbackRegister = NULL,
  .ErrorCallbackRegister = UART1_SetErrorHandler,
  .FramingErrorCallbackRegister = UART1_SetFramingErrorHandler,
  .OverrunErrorCallbackRegister = UART1_SetOverrunErrorHandler,
  .ParityErrorCallbackRegister = NULL,
  .ChecksumErrorCallbackRegister = NULL,
  .IsRxReady = UART1_IsRxReady,
  .IsTxReady = UART1_IsTxReady,
  .IsTxDone = UART1_IsTxDone
};

/**
  Section: Macro Declarations
*/
#define UART1_TX_BUFFER_SIZE 8
#define UART1_RX_BUFFER_SIZE 8

/**
  Section: Global Variables
*/

static volatile uint8_t uart1TxHead = 0;
static volatile uint8_t uart1TxTail = 0;
static volatile uint8_t uart1TxBuffer[UART1_TX_BUFFER_SIZE];
volatile uint8_t uart1TxBufferRemaining;

static volatile uint8_t uart1RxHead = 0;
static volatile uint8_t uart1RxTail = 0;
static volatile uint8_t uart1RxBuffer[UART1_RX_BUFFER_SIZE];
static volatile uart1_status_t uart1RxStatusBuffer[UART1_RX_BUFFER_SIZE];
volatile uint8_t uart1RxCount;
static volatile uart1_status_t uart1RxLastError;

/**
  Section: UART1 APIs
*/
void (*UART1_FramingErrorHandler)(void);
void (*UART1_OverrunErrorHandler)(void);
void (*UART1_ErrorHandler)(void);

void UART1_DefaultFramingErrorHandler(void);
void UART1_DefaultOverrunErrorHandler(void);
void UART1_DefaultErrorHandler(void);

void UART1_Initialize(void)
{
    // Disable interrupts before changing states
    PIE4bits.U1RXIE = 0;
    UART1_SetRxInterruptHandler(UART1_Receive_ISR);
    PIE4bits.U1TXIE = 0;
    UART1_SetTxInterruptHandler(UART1_Transmit_ISR);
    PIE4bits.U1EIE = 0;
    UART1_SetFramingErrorInterruptHandler(UART1_FramingError_ISR);
    PIE4bits.U1IE = 0;
    UART1_SetUartInterruptHandler(UART1_UartInterrupt_ISR);

    // Set the UART1 module to the options selected in the user interface.
    // RXB disabled; 
    U1RXB = 0x0;
    // RXCHK disabled; 
    U1RXCHK = 0x0;
    // TXB disabled; 
    U1TXB = 0x0;
    // TXCHK disabled; 
    U1TXCHK = 0x0;
    // P1L 0x0; 
    U1P1L = 0x0;
    // P1H 0x0; 
    U1P1H = 0x0;
    // P2L 0x0; 
    U1P2L = 0x0;
    // P2H 0x0; 
    U1P2H = 0x0;
    // P3L 0x0; 
    U1P3L = 0x0;
    // P3H 0x0; 
    U1P3H = 0x0;
    // MODE Asynchronous 8-bit mode; RXEN disabled; TXEN enabled; ABDEN disabled; BRGS normal speed; 
    U1CON0 = 0x20;
    // SENDB disabled; BRKOVR disabled; RXBIMD Set RXBKIF on rising RX input; WUE disabled; ON enabled; 
    U1CON1 = 0x80;
    // FLO off; TXPOL not inverted; C0EN Add all TX and RX characters; STP Transmit 1Stop bit, receiver verifies first Stop bit; RXPOL not inverted; RUNOVF RX input shifter stops all activity; 
    U1CON2 = 0x0;
    // BRGL 2; 
    U1BRGL = 0x2;
    // BRGH 0; 
    U1BRGH = 0x0;
    // STPMD in middle of first Stop bit; TXWRE No error; 
    U1FIFO = 0x0;
    // ABDIE disabled; ABDIF Auto-baud not enabled or not complete; WUIF WUE not enabled by software; 
    U1UIR = 0x0;
    // TXCIF 0x0; RXFOIF not overflowed; RXBKIF No Break detected; CERIF No Checksum error; ABDOVF Not overflowed; 
    U1ERRIR = 0x0;
    // TXCIE disabled; RXFOIE disabled; RXBKIE disabled; FERIE disabled; CERIE disabled; ABDOVE disabled; PERIE disabled; TXMTIE disabled; 
    U1ERRIE = 0x0;

    UART1_SetFramingErrorHandler(UART1_DefaultFramingErrorHandler);
    UART1_SetOverrunErrorHandler(UART1_DefaultOverrunErrorHandler);
    UART1_SetErrorHandler(UART1_DefaultErrorHandler);

    uart1RxLastError.status = 0;

}

bool UART1_IsRxReady(void)
{
    return (bool)(PIR4bits.U1RXIF);
}

bool UART1_is_rx_ready(void)
{    
    return UART1_IsRxReady();
}

bool UART1_IsTxReady(void)
{
    return (bool)(PIR4bits.U1TXIF && U1CON0bits.TXEN);
}

bool UART1_is_tx_ready(void)
{
    return UART1_IsTxReady();
}

bool UART1_IsTxDone(void)
{
    return U1ERRIRbits.TXMTIF;
}

bool UART1_is_tx_done(void)
{
    return UART1_IsTxDone();
}

uart1_status_t UART1_GetLastStatus(void){
    return uart1RxLastError;
}

uart1_status_t UART1_get_last_status(void){
    return UART1_GetLastStatus();
}


uint8_t UART1_Read(void)
{
    while(!PIR4bits.U1RXIF)
    {
    }

    uart1RxLastError.status = 0;

    if(U1ERRIRbits.FERIF){
        uart1RxLastError.ferr = 1;
        UART1_FramingErrorHandler();
    }

    if(U1ERRIRbits.RXFOIF){
        uart1RxLastError.oerr = 1;
        UART1_OverrunErrorHandler();
    }

    if(uart1RxLastError.status){
        UART1_ErrorHandler();
    }

    return U1RXB;
}

void UART1_Write(uint8_t txData)
{
    while(0 == PIR4bits.U1TXIF)
    {
    }

    U1TXB = txData;    // Write the data byte to the USART.
}

char getch(void)
{
    return UART1_Read();
}

void putch(char txData)
{
    UART1_Write(txData);
}

void UART1_Transmit_ISR(void)
{
    // use this default transmit interrupt handler code
    if(sizeof(uart1TxBuffer) > uart1TxBufferRemaining)
    {
        U1TXB = uart1TxBuffer[uart1TxTail++];
       if(sizeof(uart1TxBuffer) <= uart1TxTail)
        {
            uart1TxTail = 0;
        }
        uart1TxBufferRemaining++;
    }
    else
    {
        PIE4bits.U1TXIE = 0;
    }
    
    // or set custom function using UART1_SetTxInterruptHandler()
}

void UART1_Receive_ISR(void)
{
    // use this default receive interrupt handler code
    uart1RxStatusBuffer[uart1RxHead].status = 0;

    if(U1ERRIRbits.FERIF){
        uart1RxStatusBuffer[uart1RxHead].ferr = 1;
        UART1_FramingErrorHandler();
    }
    
    if(U1ERRIRbits.RXFOIF){
        uart1RxStatusBuffer[uart1RxHead].oerr = 1;
        UART1_OverrunErrorHandler();
    }
    
    if(uart1RxStatusBuffer[uart1RxHead].status){
        UART1_ErrorHandler();
    } else {
        UART1_RxDataHandler();
    }

    // or set custom function using UART1_SetRxInterruptHandler()
}

void UART1_RxDataHandler(void){
    // use this default receive interrupt handler code
    uart1RxBuffer[uart1RxHead++] = U1RXB;
    if(sizeof(uart1RxBuffer) <= uart1RxHead)
    {
        uart1RxHead = 0;
    }
    uart1RxCount++;
}

void UART1_DefaultFramingErrorHandler(void){}

void UART1_DefaultOverrunErrorHandler(void){}

void UART1_DefaultErrorHandler(void){
}

void UART1_SetFramingErrorHandler(void (* interruptHandler)(void)){
    UART1_FramingErrorHandler = interruptHandler;
}

void UART1_SetOverrunErrorHandler(void (* interruptHandler)(void)){
    UART1_OverrunErrorHandler = interruptHandler;
}

void UART1_SetErrorHandler(void (* interruptHandler)(void)){
    UART1_ErrorHandler = interruptHandler;
}

void UART1_FramingError_ISR(void)
{
    // To clear the interrupt condition, all bits in the UxERRIR register must be cleared
    U1ERRIR = 0;
    
    // add your UART1 error interrupt custom code

}

void UART1_UartInterrupt_ISR(void)
{
    // WUIF must be cleared by software to clear UxIF
    U1UIRbits.WUIF = 0;
    
    // add your UART1 interrupt custom code
}

void UART1_SetRxInterruptHandler(void (* InterruptHandler)(void)){
    UART1_RxInterruptHandler = InterruptHandler;
}

void UART1_SetTxInterruptHandler(void (* InterruptHandler)(void)){
    UART1_TxInterruptHandler = InterruptHandler;
}

void UART1_SetFramingErrorInterruptHandler(void (* InterruptHandler)(void)){
    UART1_FramingErrorInterruptHandler = InterruptHandler;
}

void UART1_SetUartInterruptHandler(void (* InterruptHandler)(void)){
    UART1_UARTInterruptHandler = InterruptHandler;
}
/**
  End of File
*/