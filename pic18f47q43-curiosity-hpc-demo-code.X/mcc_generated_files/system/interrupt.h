/**
 * Interrupt Manager Generated Driver API Header File.
 * 
 * @file interrupt.h
 * 
 * @defgroup interrupt INTERRUPT
 * 
 * @brief This file contains the API prototypes and other data types for the Interrupt Manager driver.
 *
 * @version Interrupt Manager Driver Version 2.0.4
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

#ifndef INTERRUPT_H
#define INTERRUPT_H


/**
 * @ingroup interrupt
 * @def INTERRUPT_GlobalInterruptEnable()
 * @brief Enables the global interrupts.
 */
#define INTERRUPT_GlobalInterruptEnable() (INTCON0bits.GIE = 1)

/**
 * @ingroup interrupt
 * @def INTERRUPT_GlobalInterruptDisable()
 * @brief Disables the global interrupts.
 */
#define INTERRUPT_GlobalInterruptDisable() (INTCON0bits.GIE = 0)

/**
 * @ingroup interrupt
 * @def INTERRUPT_GlobalInterruptStatus()
 * @brief Returns the Global Interrupt Enable bit status.
 * @param None.
 * @retval True - Global Interrupt enabled.
 * @retval False - Global Interrupt disabled.
 */
#define INTERRUPT_GlobalInterruptStatus() (INTCON0bits.GIE)


/**
 * @ingroup interrupt
 * @brief Initializes the interrupt controller.
 * @param None.
 * @return None.
 */
void INTERRUPT_Initialize (void);


/**
 * @ingroup interrupt
 * @def EXT_INT0_InterruptFlagClear()
 * @brief Clears the Interrupt flag for the INT0 external interrupt.
 * @param None.
 * @return None.
 */
#define EXT_INT0_InterruptFlagClear()       (PIR1bits.INT0IF = 0)

/**
 * @ingroup interrupt
 * @def EXT_INT0_InterruptDisable()
 * @brief Disables the external interrupt on the INT0 pin.
 * @param None.
 * @return None.
 */
#define EXT_INT0_InterruptDisable()     (PIE1bits.INT0IE = 0)

/**
 * @ingroup interrupt
 * @def EXT_INT0_InterruptEnable()
 * @brief Enables the external interrupt on the INT0 pin.
 * @param None.
 * @return None.
 */
#define EXT_INT0_InterruptEnable()       (PIE1bits.INT0IE = 1)

/**
 * @ingroup interrupt
 * @def EXT_INT0_risingEdgeSet()
 * @brief Sets the external interrupt to trigger when the pin's level transitions from low to high (positive edge trigger).
 * @param None.
 * @return None.
 */
#define EXT_INT0_risingEdgeSet()          (INTCON0bits.INT0EDG = 1)

/**
 * @ingroup interrupt
 * @def EXT_INT0_fallingEdgeSet() 
 * @brief Sets the external interrupt to trigger when the pin's level transitions from high to low (negative edge trigger).
 * @param None.
 * @return None.
 */
#define EXT_INT0_fallingEdgeSet()          (INTCON0bits.INT0EDG = 0)

/**
 * @ingroup interrupt
 * @def EXT_INT1_InterruptFlagClear()
 * @brief Clears the Interrupt flag for the INT1 external interrupt.
 * @param None.
 * @return None.
 */
#define EXT_INT1_InterruptFlagClear()       (PIR6bits.INT1IF = 0)

/**
 * @ingroup interrupt
 * @def EXT_INT1_InterruptDisable()
 * @brief Disables the external interrupt on the INT1 pin.
 * @param None.
 * @return None.
 */
#define EXT_INT1_InterruptDisable()     (PIE6bits.INT1IE = 0)

/**
 * @ingroup interrupt
 * @def EXT_INT1_InterruptEnable()
 * @brief Enables the external interrupt on the INT1 pin.
 * @param None.
 * @return None.
 */
#define EXT_INT1_InterruptEnable()       (PIE6bits.INT1IE = 1)

/**
 * @ingroup interrupt
 * @def EXT_INT1_risingEdgeSet()
 * @brief Sets the external interrupt to trigger when the pin's level transitions from low to high (positive edge trigger).
 * @param None.
 * @return None.
 */
#define EXT_INT1_risingEdgeSet()          (INTCON0bits.INT1EDG = 1)

/**
 * @ingroup interrupt
 * @def EXT_INT1_fallingEdgeSet() 
 * @brief Sets the external interrupt to trigger when the pin's level transitions from high to low (negative edge trigger).
 * @param None.
 * @return None.
 */
#define EXT_INT1_fallingEdgeSet()          (INTCON0bits.INT1EDG = 0)

/**
 * @ingroup interrupt
 * @def EXT_INT2_InterruptFlagClear()
 * @brief Clears the Interrupt flag for the INT2 external interrupt.
 * @param None.
 * @return None.
 */
#define EXT_INT2_InterruptFlagClear()       (PIR10bits.INT2IF = 0)

/**
 * @ingroup interrupt
 * @def EXT_INT2_InterruptDisable()
 * @brief Disables the external interrupt on the INT2 pin.
 * @param None.
 * @return None.
 */
#define EXT_INT2_InterruptDisable()     (PIE10bits.INT2IE = 0)

/**
 * @ingroup interrupt
 * @def EXT_INT2_InterruptEnable()
 * @brief Enables the external interrupt on the INT2 pin.
 * @param None.
 * @return None.
 */
#define EXT_INT2_InterruptEnable()       (PIE10bits.INT2IE = 1)

/**
 * @ingroup interrupt
 * @def EXT_INT2_risingEdgeSet()
 * @brief Sets the external interrupt to trigger when the pin's level transitions from low to high (positive edge trigger).
 * @param None.
 * @return None.
 */
#define EXT_INT2_risingEdgeSet()          (INTCON0bits.INT2EDG = 1)

/**
 * @ingroup interrupt
 * @def EXT_INT2_fallingEdgeSet() 
 * @brief Sets the external interrupt to trigger when the pin's level transitions from high to low (negative edge trigger).
 * @param None.
 * @return None.
 */
#define EXT_INT2_fallingEdgeSet()          (INTCON0bits.INT2EDG = 0)

/**
   Section: External Interrupt Handlers
 */

/**
 * @ingroup interrupt
 * @brief Implements the Interrupt Service Routine (ISR) whenever the signal on the INT0 pin transitions on the selected edge.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT0_ISR(void);

/**
 * @ingroup interrupt
 * @brief Function to be called in the INT0 ISR containing the interrupt handler function for the INT0 pin interrupt event.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT0_CallBack(void);

/**
 * @ingroup interrupt
 * @brief Assigns an interrupt handler for the EXT_INT0 - INT0 interrupt event.
 * @pre INTERRUPT_Initialize() is already called.
 * @param (*InterruptHandler)(void) - Pointer to the InterruptHandler function.
 * @return None.
 */
void INT0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup interrupt
 * @brief Function pointer to the interrupt handler for the INT0 pin interrupt event.
 *        This can be reassigned using the INT0_SetInterruptHandler function.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
extern void (*INT0_InterruptHandler)(void);

/**
 * @ingroup interrupt
 * @brief Default interrupt handler assigned to handle INT0 interrupt events.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT0_DefaultInterruptHandler(void);

/**
 * @ingroup interrupt
 * @brief Implements the Interrupt Service Routine (ISR) whenever the signal on the INT1 pin transitions on the selected edge.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT1_ISR(void);

/**
 * @ingroup interrupt
 * @brief Function to be called in the INT1 ISR containing the interrupt handler function for the INT1 pin interrupt event.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT1_CallBack(void);

/**
 * @ingroup interrupt
 * @brief Assigns an interrupt handler for the EXT_INT1 - INT1 interrupt event.
 * @pre INTERRUPT_Initialize() is already called.
 * @param (*InterruptHandler)(void) - Pointer to the InterruptHandler function.
 * @return None.
 */
void INT1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup interrupt
 * @brief Function pointer to the interrupt handler for the INT1 pin interrupt event.
 *        This can be reassigned using the INT1_SetInterruptHandler function.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
extern void (*INT1_InterruptHandler)(void);

/**
 * @ingroup interrupt
 * @brief Default interrupt handler assigned to handle INT1 interrupt events.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT1_DefaultInterruptHandler(void);

/**
 * @ingroup interrupt
 * @brief Implements the Interrupt Service Routine (ISR) whenever the signal on the INT2 pin transitions on the selected edge.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT2_ISR(void);

/**
 * @ingroup interrupt
 * @brief Function to be called in the INT2 ISR containing the interrupt handler function for the INT2 pin interrupt event.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT2_CallBack(void);

/**
 * @ingroup interrupt
 * @brief Assigns an interrupt handler for the EXT_INT2 - INT2 interrupt event.
 * @pre INTERRUPT_Initialize() is already called.
 * @param (*InterruptHandler)(void) - Pointer to the InterruptHandler function.
 * @return None.
 */
void INT2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup interrupt
 * @brief Function pointer to the interrupt handler for the INT2 pin interrupt event.
 *        This can be reassigned using the INT2_SetInterruptHandler function.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
extern void (*INT2_InterruptHandler)(void);

/**
 * @ingroup interrupt
 * @brief Default interrupt handler assigned to handle INT2 interrupt events.
 * @pre INTERRUPT_Initialize() is already called.
 * @param None.
 * @return None.
 */
void INT2_DefaultInterruptHandler(void);

#endif  // INTERRUPT_H
/**
 End of File
*/