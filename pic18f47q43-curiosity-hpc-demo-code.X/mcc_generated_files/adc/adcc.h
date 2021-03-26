/**
  ADCC Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    adcc.h

  @Summary
    This is the generated header file for the ADCC driver.

  @Description
    This header file provides APIs for the ADCC driver.
    Generation Information :
        Driver Version    :  2.1.4
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.30
        MPLAB             :  MPLABX v5.45
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

#ifndef ADCC_H
#define ADCC_H

/**
 * @brief This file contains API prototypes and other datatypes for ADC module.
 * @defgroup adc_with_computation  ADCC: Analog-to-Digital Converter with Computation
 * @{
 */

#include <stdint.h>
#include <stdbool.h>

/**
 @ingroup adc_with_computation
 @typedef adc_result_t
 @brief This typedef should be used for result of A/D conversion.
 */
typedef uint16_t adc_result_t;
#ifndef uint24_t
typedef __uint24 uint24_t;
#endif

/**
 @ingroup adc_with_computation
 @enum adcc_channel_t
 @brief This enumeration contains available ADC channels.
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
 * @ingroup adc_with_computation
 * @brief This API initializes the ADC module.
 *        This routine must be called before any other ADC routine.
 * @param void
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     adc_result_t convertedValue;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     while(!ADCC_IsConversionDone());
 *     convertedValue = ADCC_GetConversionResult();
 *
 *     while(1);
 * }
 * @endcode
 */
void ADCC_Initialize(void);

/**
 * @ingroup adc_with_computation
 * @brief This API starts A/D conversion on selected channel.
 * @param[in] channel - Analog channel number on which A/D conversion has to be applied.
 *                      Refer @ref adcc_channel_t for available list of channels
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     adc_result_t convertedValue;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     while(!ADCC_IsConversionDone());
 *     convertedValue = ADCC_GetConversionResult();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
void ADCC_StartConversion(adcc_channel_t channel);

/**
 * @ingroup adc_with_computation
 * @brief This API checks if ongoing A/D conversion is complete.
 * @param void
 * @return bool - Status of A/D conversion.
 *         true - if conversion is complete.
 *         false - if conversion is ongoing.
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     adc_result_t convertedValue;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     while(!ADCC_IsConversionDone());
 *     convertedValue = ADCC_GetConversionResult();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
bool ADCC_IsConversionDone(void);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to retrieve the result of latest A/D conversion.
 * @param void
 * @return The result of A/D conversion. Refer @ref adc_result_t
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     adc_result_t convertedValue;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     while(!ADCC_IsConversionDone());
 *     convertedValue = ADCC_GetConversionResult();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
adc_result_t ADCC_GetConversionResult(void);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to retrieve the result of single A/D conversion on given channel.
 * @param[in] channel - Analog channel number on which A/D conversion has to be applied.
 *                      Refer @ref adcc_channel_t  for available channels
 * @return The result of A/D conversion. Refer @ref adc_result_t
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     adc_result_t convertedValue;
 *     ADCC_Initialize();
 *     ADCC_DisableContinuousConversion();
 *
 *     convertedValue = ADCC_GetSingleConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to stop ongoing A/D conversion.
 * @param void
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1)
 *     {
 *         if(some_condition)
 *         {
 *             ADCC_StopConversion();
 *         }
 *     }
 * }
 * @endcode
 */
inline void ADCC_StopConversion(void);

/**
 * @ingroup adc_with_computation
 * @brief This API is used enable Stop On Interrupt bit.
 * @param void
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     ADCC_Initialize();
 *     ADCC_EnableContinuousConversion();
 *     ADCC_SetStopOnInterrupt();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
inline void ADCC_SetStopOnInterrupt(void);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to discharge input sample capacitor by setting the channel to AVss.
 * @param void
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     adc_result_t convertedValue;
 *     ADCC_Initialize();
 *     ADCC_DischargeSampleCapacitor();
 *     ADCC_StartConversion(channel_ANA0);
 *     while(!ADCC_IsConversionDone());
 *     convertedValue = ADCC_GetConversionResult();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
inline void ADCC_DischargeSampleCapacitor(void); 

/**
 * @ingroup adc_with_computation
 * @brief This API is used to load ADC Acquisition Time Control register with specified value.
 * @param[in] acquisitionValue - Value to be loaded in the acquisition time control register.
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     
 *     uint16_t acquisitionValue = 98;
 *     
 *     ADCC_Initialize();
 *     ADCC_LoadAcquisitionRegister(acquisitionValue);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
void ADCC_LoadAcquisitionRegister(uint16_t acquisitionValue);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to load ADC Precharge Time Control register with specified value.
 * @param[in] prechargeTime - Value to be loaded in the precharge time control register.
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     
 *     uint16_t prechargeTime = 98;
 *     
 *     ADCC_Initialize();
 *     ADCC_SetPrechargeTime(prechargeTime);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
void ADCC_SetPrechargeTime(uint16_t prechargeTime);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to load repeat counter with specified value.
 * @param[in] repeatCount - Value to be loaded to repeat counter.
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint8_t repeatCount = 32;
 *     ADCC_Initialize();
 *     ADCC_SetRepeatCount(repeatCount);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
void ADCC_SetRepeatCount(uint8_t repeatCount);

/**
 * @ingroup adc_with_computation
 * @brief This API retrieves the current value of ADC Repeat Count register.
 * @param void
 * @return Current value of ADC Repeat Count register
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint8_t conversionCount;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     conversionCount = ADCC_GetCurrentCountofConversions();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
uint8_t ADCC_GetCurrentCountofConversions(void);

/**
 * @ingroup adc_with_computation
 * @brief This API clears the accumulator.
 * @param void
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     ADCC_Initialize();
 *     ADCC_ClearAccumulator();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
inline void ADCC_ClearAccumulator(void);

/**
 * @ingroup adc_with_computation
 * @brief This API retrieves 18-bit value of ADC accumulator.
 * @param void
 * @return Value of ADC accumulator.
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     
 *     
 *     uint24_t accumulatorValue;
 *     
 *     ADCC_Initialize();
 *     accumulatorValue = ADCC_GetAccumulatorValue();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
uint24_t ADCC_GetAccumulatorValue(void);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to determine whether ADC accumulator has overflowed.
 * @param void
 * @return Status of accumulator.
 *         true - ADC accumulator has overflowed.
 *         false - ADC accumulator has not overflowed.
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     bool hasAccOvf;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     hasAccOvf = ADCC_HasAccumulatorOverflowed();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
bool ADCC_HasAccumulatorOverflowed(void);

/**
 * @ingroup adc_with_computation
 * @brief This API retrieves the value of ADC Filter register.
 * @param void
 * @return 16-bit value obtained from ADFLTRH and ADFLTRL registers.
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint16_t filterValue;
 *     ADCC_Initialize();
 *     filterValue = ADCC_GetFilterValue();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
uint16_t ADCC_GetFilterValue(void);

/**
 * @ingroup adc_with_computation
 * @brief This API retrieves the value of ADC Previous register.
 * @param void
 * @return 16-bit value obtained from ADPREVH and ADPREVL registers.
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint16_t previousResult, convertedValue;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1);
 *     {
 *         previousResult = ADCC_GetPreviousResult();
 *         convertedValue = ADCC_GetConversionResult();
 *     }
 * }
 * @endcode
 */
uint16_t ADCC_GetPreviousResult(void);

/**
 * @ingroup adc_with_computation
 * @brief This API used to set value of ADC Threshold Set-point.
 * @param[in] setPoint - 16-bit value for set point.
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint16_t setPoint = 90;
 *     ADCC_Initialize();
 *     ADCC_DefineSetPoint(setPoint);
 *     ADCC_StartConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
void ADCC_DefineSetPoint(uint16_t setPoint);

/**
 * @ingroup adc_with_computation
 * @brief This API used to set value of ADC Upper Threshold register.
 * @param[in] upperThreshold - 16-bit value for upper threshold.
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint16_t upperThreshold = 5000;
 *     ADCC_Initialize();
 *     ADCC_SetUpperThreshold(upperThreshold);
 *     ADCC_StartConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
void ADCC_SetUpperThreshold(uint16_t upperThreshold);

/**
 * @ingroup adc_with_computation
 * @brief This API used to set value of ADC Lower Threshold register.
 * @param[in] lowerThreshold - 16-bit value for lower threshold.
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint16_t lowerThreshold = 500;
 *     ADCC_Initialize();
 *     ADCC_SetLowerThreshold(lowerThreshold);
 *     ADCC_StartConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
void ADCC_SetLowerThreshold(uint16_t lowerThreshold);

/**
 * @ingroup adc_with_computation
 * @brief This API retrieves the value of ADC Set-point Error register.
 * @param void
 * @return 16-bit value obtained from ADERRH and ADERRL registers.
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint16_t errorCalc;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     errorCalc = ADCC_GetErrorCalculation(void);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
uint16_t ADCC_GetErrorCalculation(void);

/**
 * @ingroup adc_with_computation
 * @brief This API enables double-sampling bit.
 * @param void
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     ADCC_Initialize();
 *     ADCC_EnableDoubleSampling();
 *     ADCC_StartConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
inline void ADCC_EnableDoubleSampling(void);

/**
 * @ingroup adc_with_computation
 * @brief This API enables continuous conversion.
 * @param void
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     ADCC_Initialize();
 *     ADCC_EnableContinuousConversion();
 *     ADCC_StartConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
inline void ADCC_EnableContinuousConversion(void);

/**
 * @ingroup adc_with_computation
 * @brief This API disables continuous conversion.
 * @param void
 * @return void
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     ADCC_Initialize();
 *     ADCC_DisableContinuousConversion();
 *     ADCC_StartConversion(channel_ANA0);
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
inline void ADCC_DisableContinuousConversion(void);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to determine if ADC error has crossed the upper threshold.
 * @param void
 * @return Status of operation.
 *         true - if ERR > UTH
 *         false - if ERR <= UTH
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     bool uThr;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     uThr = ADCC_HasErrorCrossedUpperThreshold();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
bool ADCC_HasErrorCrossedUpperThreshold(void);

/**
 * @ingroup adc_with_computation
 * @brief This API is used to determine if ADC error is less than the lower threshold.
 * @param void
 * @return Status of operation.
 *         true - if ERR < LTH.
 *         false - if ERR >= LTH.
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     bool lThr;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     lThr = ADCC_HasErrorCrossedLowerThreshold();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
bool ADCC_HasErrorCrossedLowerThreshold(void);

/**
 * @ingroup adc_with_computation
 * @brief This API is used retrieve the multi-stage status.
 * @param void
 * @return Contents of ADC STATUS register.
 *
 * @details <b>API usage example</b>
 * @code
 * void main(void)
 * {
 *     uint8_t status;
 *     ADCC_Initialize();
 *     ADCC_StartConversion(channel_ANA0);
 *     status = ADCC_GetConversionStageStatus();
 *
 *     //Application code
 *
 *     while(1);
 * }
 * @endcode
 */
uint8_t ADCC_GetConversionStageStatus(void);



/**
 * @}
 */
#endif//ADCC_H