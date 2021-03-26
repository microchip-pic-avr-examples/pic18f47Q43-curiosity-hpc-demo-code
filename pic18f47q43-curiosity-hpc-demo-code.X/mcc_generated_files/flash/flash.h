/**
  MEMORY Generated Driver API Header File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    memory.h
 
  @Summary
    This is the generated header file for the MEMORY driver
 
  @Description
    This header file provides APIs for driver for MEMORY.
    Generation Information :
        Driver Version    :  1.1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLABX v5.40
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

#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

/**
  Section: Macro Declarations
 */

#define WRITE_FLASH_BLOCKSIZE    128
#define ERASE_FLASH_BLOCKSIZE    128
#define END_FLASH                0x020000
#define EEPROM_SIZE              1024

/**
  Section: MEMORY Interface APIs
 */

void FLASH_Initialize(void);

/**
 * @brief This routine reads one data byte from given address of FLASH
 * @return Data byte read from given FLASH address
 * @param [in] Address of FLASH location to be read
 * @example void main(void)
 *          {
 *              uint8_t readByte;
 *              SYSTEM_Initialize();
 *              readByte = FLASH_ReadByte(0x1FF00);
 *          }
 */
uint8_t FLASH_ReadByte(uint32_t flashAddr);

/**
 * @brief This routine reads one word from given address of FLASH
 * @return Data word read from given FLASH address
 * @param [in] Address of FLASH location to be read
 * @example void main(void)
 *          {
 *              uint16_t readWord;
 *              SYSTEM_Initialize();
 *              readWord = FLASH_ReadWord(0x1FF00);
 *          }
 */
uint16_t FLASH_ReadWord(uint32_t flashAddr);

/**
 * @brief This routine reads one block from given address of FLASH
 *        into device Buffer RAM
 * @return None
 * @param [in] Starting address of a FLASH block
 * @example Use case: Read one page from given FLASH location into device Buffer RAM using FLASH_ReadPage()
 *                    Transfer the contents of device Buffer RAM to U1TXB using DMA2
 *                    
 *          void main(void)
 *          {   
 *              SYSTEM_Initialize();
 *
 *              //Read one page from PFM into device Buffer RAM
 *              FLASH_ReadPage();
 *
 *              //Initialize DMA2 to copy data from device Buffer RAM to U1TXB register
 *              //Configure source size as 256 and destination size as 1
 *              DMA2_Initialize();
 *          }
 */
void FLASH_ReadPage(uint32_t flashAddr);

/**
 * @brief This routine writes one block of data from Buffer RAM to the given address of FLASH
 * @return None
 * @param [in] Starting address of a FLASH block
 * @example Use case: Data received in U1RXB is copied to device Buffer RAM using DMA1.
 *                    Once page-sized data is copied to device Buffer RAM, 
 *                    it will be transferred to PFM using FLASH_WritePage()
 *          void main(void)
 *          {   
 *              SYSTEM_Initialize();
 *
 *              //Initialize DMA1 to copy data from UART receive buffer to device Buffer RAM
 *              //Configure Source size as 1 and destination size as 256 (FLASH page size)
 *              DMA1_Initialize();
 *
 *              //Once 256 bytes are copied in device buffer RAM,
 *              //Write the data available in device Buffer RAM to given FLASH page
 *              FLASH_WritePage();
 *          }
 */
void FLASH_WritePage(uint32_t flashAddr);

/**
 * @brief This routine writes one word to given address of erased FLASH location
 * @return None
 * @param [in] Address of erased FLASH location to be written
 * @param [in] Data word to be written to given address
 * @example void main(void)
 *          {
 *              SYSTEM_Initialize();
 *              FLASH_WriteWord(0x1FF00,0x55AA);
 *          }
 */
void FLASH_WriteWord(uint32_t flashAddr, uint16_t word);

/**
 * @brief This routine writes 128 words from given block start address
 * @return Status of operation
 * @param [in] Starting address of a FLASH block
 * @param [in] Address of RAM buffer to be copied to FLASH block
 * @example uint16_t flashWrBufPtr[WRITE_FLASH_BLOCKSIZE] =
 *          {
 *              0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0x2, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0x3, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0x4, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0x5, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0x6, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0x7, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0x8, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0x9, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0xa, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0xb, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0xc, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0xd, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0xe, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0xf, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
 *              0xf, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8
 *          };
 *          void main(void)
 *          {
 *              SYSTEM_Initialize();
 *              FLASH_WriteBlock(0x1FF00,flashWrBufPtr);
 *          }
 */
int8_t FLASH_WriteBlock(uint32_t flashAddr, uint16_t *flashWrBufPtr);

/**
 * @brief This routine erases 128-words block from given address of FLASH
 * @return None
 * @param [in] Starting address of FLASH block to be erased
 * @example void main(void)
 *          {
 *              SYSTEM_Initialize();
 *              FLASH_EraseBlock(0x1FF00);
 *          }
 */
void FLASH_EraseBlock(uint32_t flashAddr);

/**
  Section: Data EEPROM Module APIs
 */

/**
 * @brief This routine writes one data byte to given EEPROM address
 * @return None
 * @param [in] Address of EEPROM location to be written
 * @param [in] Data byte to be written to given EEPROM location
 * @example void main(void)
 *          {
 *              SYSTEM_Initialize();
 *              DATAEE_WriteByte(0x2, 0xAB);  //Writes a byte to 0x380002
 *          }
 */
void DATAEE_WriteByte(uint16_t bAdd, uint8_t bData);

/**
 * @brief This routine reads one data byte from given EEPROM address
 * @return Data byte read from given EEPROM address
 * @param [in] Address of EEPROM location to be read
 * @example void main(void)
 *          {
 *              uint8_t eepromByte;
 *              SYSTEM_Initialize();
 *              eepromByte = DATAEE_ReadByte(0x2);    //Reads a byte from 0x380002
 *          }
 */
uint8_t DATAEE_ReadByte(uint16_t bAdd);

/**
 * @brief This routine is used to implement the ISR for the interrupt-driven implementations.
 * @return None
 * @param None
 */
void FLASH_ISR(void);

#endif /* MEMORY_H_INCLUDED */