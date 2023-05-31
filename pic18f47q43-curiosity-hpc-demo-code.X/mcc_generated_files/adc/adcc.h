/**
 * ADCC Generated Driver API Header File
 * 
 * @file adcc.h
 * 
 * @defgroup  adcc ADCC
 * 
 * @brief This file contains the API prototypes and data types for the ADCC driver.
 *
 * @version ADCC Driver Version 2.1.5
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

#ifndef ADCC_H
#define ADCC_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

/**
 @ingroup adcc
 @typedef adc_result_t
 @brief Used for the result of ADC conversion.
*/
typedef uint16_t adc_result_t;
#ifndef uint24_t
typedef __uint24 uint24_t;
#endif

/**
 * @ingroup adcc
 * @enum adcc_channel_t
 * @brief Contains the available ADC channels.
*/
typedef enum
{
    channel_VSS =  0x3b,
    channel_Temp =  0x3c,
    channel_DAC1 =  0x3d,
    channel_FVR_Buffer1 =  0x3e,
    channel_FVR_Buffer2 =  0x3f,
    POT_CHANNEL =  0x0
} adcc_channel_t;

/**
  Section: ADCC Module APIs
*/

/**
 * @ingroup adcc
 * @brief Initializes the ADC module. This routine is called before any other ADC routine.
 * @param None.
 * @return None.
*/
void ADCC_Initialize(void);

/**
 * @ingroup adcc
 * @brief Starts ADC conversion on the selected channel
 * @pre ADCC_Initialize() function is called before calling this function to enable ADC.
 * @param channel - Analog channel number on which the ADC conversion has to be applied.
 *                  Refer to adcc_channel_t for the available list of channels.
 * @return None.
*/
void ADCC_StartConversion(adcc_channel_t channel);

/**
 * @ingroup adcc
 * @brief Checks if ongoing ADC conversion is complete.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @retval True - ADC conversion is complete.
 * @retval False - ADC conversion is ongoing.
*/
bool ADCC_IsConversionDone(void);


/**
 * @ingroup adcc
 * @brief Retrieves the result of latest A/D conversion.
 * @pre ADCC_StartConversion() is called before calling this function and completion status is checked using the ADCC_IsConversionDone() routine.
 * @param None.
 * @return The result of ADC conversion. Refer to the adc_result_t.
*/
adc_result_t ADCC_GetConversionResult(void);

/**
 * @ingroup adcc
 * @brief Retrieves the result of a single ADC conversion on any given channel.
 * @pre Enable ADC using the ADCC_Initialize() function. Also ADCC_DisableContinuousConversion() function should have been called before calling this function
 * @param channel - Analog channel number on which ADC conversion will be applied.
 *                  Refer to adcc_channel_t  for available channels
 * @return The result of a single ADC conversion. Refer to the adc_result_t.
*/
adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel);

/**
 * @ingroup adcc
 * @brief Stops the ongoing ADC conversion.
 * @pre ADCC_StartConversion() function is called before calling this function.
 * @param None.
 * @return None.
*/
inline void ADCC_StopConversion(void);

/**
 * @ingroup adcc
 * @brief Enables Stop On Interrupt bit.
 * @pre ADCC_EnableContinuousConversion() function is called before calling this function.
 * @param None.
 * @return None.
*/
inline void ADCC_SetStopOnInterrupt(void);

/**
 * @ingroup adcc
 * @brief Discharges the input sample capacitor by setting the channel to AVss.
 * @param None.
 * @return None.
*/
inline void ADCC_DischargeSampleCapacitor(void); 

/**
 * @ingroup adcc
 * @brief Loads ADC Acquisition Time Control register with specified value.
 * @param acquisitionValue - Value to be loaded in the acquisition time control register.
 * @return None.
*/
void ADCC_LoadAcquisitionRegister(uint16_t acquisitionValue);

/**
 * @ingroup adcc
 * @brief Loads ADC Precharge Time Control register with specified value.
 * @param prechargeTime - Value to be loaded in the precharge time control register.
 * @return None.
*/
void ADCC_SetPrechargeTime(uint16_t prechargeTime);

/**
 * @ingroup adcc
 * @brief Loads repeat counter with specified value.
 * @param repeatCount - Value to be loaded to repeat counter.
 * @return none
*/
void ADCC_SetRepeatCount(uint8_t repeatCount);

/**
 * @ingroup adcc
 * @brief Retrieves the current value of ADC Repeat Count register.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @return Current value of the ADC Repeat Count register
*/
uint8_t ADCC_GetCurrentCountofConversions(void);

/**
 * @ingroup adcc
 * @brief Clears the accumulator.
 * @param None.
 * @return None.
*/
inline void ADCC_ClearAccumulator(void);

/**
 * @ingroup adcc
 * @brief Retrieves the value of ADC accumulator.
 * @param None.
 * @return Value of ADC accumulator.
*/
uint24_t ADCC_GetAccumulatorValue(void);

/**
 * @ingroup adcc
 * @brief Determines whether ADC accumulator has overflowed.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @retval True - ADC accumulator has overflowed.
 * @retval False - ADC accumulator has not overflowed.
*/
bool ADCC_HasAccumulatorOverflowed(void);

/**
 * @ingroup adcc
 * @brief Retrieves the value of the ADC Filter(ADFLTR) register.
 * @param None.
 * @return 16-bit value obtained from the high byte ADFLTR(ADFLTRH) and low byte ADFLTR(ADFLTRL) registers.
*/
uint16_t ADCC_GetFilterValue(void);

/**
 * @ingroup adcc
 * @brief Retrieves the value of the ADC Previous(ADPREV) register.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @return 16-bit value obtained from the high byte ADPREV(ADPREVH) and low byte ADPREV(ADPREVL) registers.
*/
uint16_t ADCC_GetPreviousResult(void);

/**
 * @ingroup adcc
 * @brief Sets the value of the ADC Threshold Setpoint(ADSTPT) register.
 * @param setPoint - 16-bit value for the ADC Threshold Setpoint register.
 * @return None.
*/
void ADCC_DefineSetPoint(uint16_t setPoint);

/**
 * @ingroup adcc
* @brief Sets the value of ADC Upper Threshold(ADUTH) register.
 * @param upperThreshold - 16-bit value for the ADC Upper Threshold register.
 * @return None.
*/
void ADCC_SetUpperThreshold(uint16_t upperThreshold);

/**
 * @ingroup adcc
 * @brief Sets the value of ADC Lower Threshold(ADLTH) register.
 * @param lowerThreshold - 16-bit value for the ADC Lower Threshold register.
 * @return None.
*/
void ADCC_SetLowerThreshold(uint16_t lowerThreshold);

/**
 * @ingroup adcc
 * @brief Retrieves the value of ADC Set-point Error register.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @return 16-bit value obtained from the high byte ADERR(ADERRH) and low byte ADERR(ADERRL) registers.
*/
uint16_t ADCC_GetErrorCalculation(void);

/**
 * @ingroup adcc
 * @brief Enables double-sampling bit.
 * @param None.
 * @return None.
*/
inline void ADCC_EnableDoubleSampling(void);

/**
 * @ingroup adcc
 * @brief Enables continuous conversion.
 * @param None.
 * @return None.
*/
inline void ADCC_EnableContinuousConversion(void);

/**
 * @ingroup adcc
 * @brief Disables continuous conversion.
 * @param None.
 * @return None.
*/
inline void ADCC_DisableContinuousConversion(void);

/**
 * @ingroup adcc
 * @brief Determines if ADC error has crossed the upper threshold.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @retval True - ADC error has crossed the upper threshold.
 * @retval False - ADC error has not crossed the upper threshold.
*/
bool ADCC_HasErrorCrossedUpperThreshold(void);

/**
 * @ingroup adcc
 * @brief Determines if ADC error is less than the lower threshold.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @retval True - ADC error has crossed the lower threshold.
 * @retval False - ADC error has not crossed the lower threshold.
*/
bool ADCC_HasErrorCrossedLowerThreshold(void);

/**
 * @ingroup adcc
 * @brief Retrieves the multi-stage status.
 * @pre ADCC_StartConversion() is called before calling this function.
 * @param None.
 * @return Contents of ADC STATUS register.
*/
uint8_t ADCC_GetConversionStageStatus(void);



#endif//ADCC_H
