/**
 *
 * @file nvm.c
 *
 * @ingroup nvm_driver
 *
 * @brief Contains the implementation file for the NVM driver.
 *
 * @version NVM Driver Version 3.0.0
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

#include "../nvm.h"

/*
 * AoU: These variables are placed in the Access RAM using the "__near" qualifier.
 *      Additionally, "Address Qualifiers" must be configured to the "Require" under
 *      "Project Properties -> XC8 Compiler -> Optimizations".
 */
__near volatile static uint8_t unlockKeyLow;
__near volatile static uint8_t unlockKeyHigh;

void NVM_Initialize(void)
{
    NVM_StatusClear();
}

bool NVM_IsBusy(void)
{
    return NVMCON0bits.GO;
}

nvm_status_t NVM_StatusGet(void)
{
    if (NVMCON1bits.WRERR == 1)
    {
        return NVM_ERROR;
    }
    else
    {
        return NVM_OK;
    }
}

void NVM_StatusClear(void)
{
    NVMCON1bits.WRERR = 0;
}

void NVM_UnlockKeySet(uint16_t unlockKey)
{
    unlockKeyHigh = (uint8_t) (unlockKey >> 8);
    unlockKeyLow = (uint8_t) unlockKey;
}

void NVM_UnlockKeyClear(void)
{
    unlockKeyHigh = 0x00;
    unlockKeyLow = 0x00;
}

flash_data_t FLASH_Read(flash_address_t address)
{
    //Save the table pointer
    uint32_t tablePointer = ((uint32_t) TBLPTRU << 16) | ((uint32_t) TBLPTRH << 8) | ((uint32_t) TBLPTRL);

    //Load table pointer with the target address of the byte  
    TBLPTRU = (uint8_t) (address >> 16);
    TBLPTRH = (uint8_t) (address >> 8);
    TBLPTRL = (uint8_t) address;
  
    //Execute table read 
    asm("TBLRD*");
    
    //Restore the table pointer
    TBLPTRU = (uint8_t) (tablePointer >> 16);
    TBLPTRH = (uint8_t) (tablePointer >> 8);
    TBLPTRL = (uint8_t) tablePointer;

    return TABLAT;
}

nvm_status_t FLASH_RowRead(flash_address_t address, flash_data_t *dataBuffer)
{
    flash_data_t *bufferRamPtr = (flash_data_t *) (BUFFER_RAM_START_ADDRESS);
    uint16_t flashDataCount = PROGMEM_PAGE_SIZE;

    //Load NVMADR with the starting address of the memory page
    NVMADRU = (uint8_t) (address >> 16);
    NVMADRH = (uint8_t) (address >> 8);
    NVMADRL = (uint8_t) address;

    //Set the page read command
    NVMCON1bits.NVMCMD = 0x02;

    //Start page read
    NVMCON0bits.GO = 1;
    
    if (dataBuffer != bufferRamPtr)
    {
        //Given data pointer belongs to application buffer
        //Copy Buffer RAM contents to application buffer
        while (flashDataCount-- > 0U) 
        {
            *dataBuffer++ = *bufferRamPtr++;
        }
    }
    
    //Clear the NVM Command
    NVMCON1bits.NVMCMD = 0x00;

    return NVM_OK;
}

nvm_status_t FLASH_Write(flash_address_t address, uint16_t data)
{
    //Save global interrupt enable bit value
    uint8_t globalInterruptBitValue = INTCON0bits.GIE;

    //Load NVMADR with the target address of the word
    NVMADRU = (uint8_t) (address >> 16);
    NVMADRH = (uint8_t) (address >> 8);
    NVMADRL = (uint8_t) address;
    
    //Load NVMDAT with the desired value
    NVMDATH = (uint8_t) (data >> 8);
    NVMDATL = (uint8_t) data;

    //Set the word write command
    NVMCON1bits.NVMCMD = 0x03;

    //Disable global interrupt
    INTCON0bits.GIE = 0;

    //Perform the unlock sequence
    asm("asmopt push"); //save the current selection of optimizations
    asm("asmopt off"); //turn off assembler optimizations
    asm("banksel(_NVMLOCK)"); //select the bank of the NVMLOCK register
    NVMLOCK = unlockKeyLow; //assign 'unlockKeyLow' to NVMLOCK.
    asm("MOVF (_unlockKeyHigh&0xFF),w,c"); //load 'unlockKeyHigh' into the W register
    asm("MOVWF (_NVMLOCK&0xFF),b"); //move the W register to NVMLOCK

    //Start word write
    asm("bsf (_NVMCON0bits&0xFF)," ___mkstr(_NVMCON0_GO_POSN) ",b"); //set GO bit
    asm("asmopt pop"); //restore assembler optimization settings

    //Restore global interrupt enable bit value
    INTCON0bits.GIE = globalInterruptBitValue;

    //Clear the NVM Command
    NVMCON1bits.NVMCMD = 0x00;
    
    if (NVMCON1bits.WRERR == 1)
    {
       return NVM_ERROR;
    }
    else
    {
        return NVM_OK;
    }
}

nvm_status_t FLASH_RowWrite(flash_address_t address, flash_data_t *dataBuffer)
{
    flash_data_t *bufferRamPtr = (flash_data_t *) (BUFFER_RAM_START_ADDRESS);
    uint16_t flashDataCount = PROGMEM_PAGE_SIZE;
    
    //Save global interrupt enable bit value
    uint8_t globalInterruptBitValue = INTCON0bits.GIE;
    
    if (dataBuffer != bufferRamPtr)
    {
        //Given data pointer belongs to application buffer
        //Copy application buffer contents to Buffer RAM
        while (flashDataCount-- > 0U) 
        {
            *bufferRamPtr++ = *dataBuffer++;
        }
    }

    //Load NVMADR with the start address of the memory page
    NVMADRU = (uint8_t) (address >> 16);
    NVMADRH = (uint8_t) (address >> 8);
    NVMADRL = (uint8_t) address;

    //Set the page write command
    NVMCON1bits.NVMCMD = 0x05;

    //Disable global interrupt
    INTCON0bits.GIE = 0;

    //Perform the unlock sequence   
    asm("asmopt push"); //save the current selection of optimizations
    asm("asmopt off"); //turn off assembler optimizations
    asm("banksel(_NVMLOCK)"); //select the bank of the NVMLOCK register
    NVMLOCK = unlockKeyLow; //assign 'unlockKeyLow' to NVMLOCK.
    asm("MOVF (_unlockKeyHigh&0xFF),w,c"); //load 'unlockKeyHigh' into the W register
    asm("MOVWF (_NVMLOCK&0xFF),b"); //move the W register to NVMLOCK

    //Start page write 
    asm("bsf (_NVMCON0bits&0xFF)," ___mkstr(_NVMCON0_GO_POSN) ",b"); //Set GO bit  
    asm("asmopt pop"); //restore assembler optimization settings

    //Restore global interrupt enable bit value
    INTCON0bits.GIE = globalInterruptBitValue;

    //Clear the NVM Command
    NVMCON1bits.NVMCMD = 0x00;
    
    if (NVMCON1bits.WRERR == 1)
    {
        return NVM_ERROR;
    }
    else
    {
        return NVM_OK;
    }
}

nvm_status_t FLASH_PageErase(flash_address_t address)
{
    //Save global interrupt enable bit value
    uint8_t globalInterruptBitValue = INTCON0bits.GIE;

    //Load NVMADR with the any address in the memory page. NVMADRL is ignored
    NVMADRU = (uint8_t) (address >> 16);
    NVMADRH = (uint8_t) (address >> 8);

    //Set the page erase command
    NVMCON1bits.NVMCMD = 0x06;

    //Disable global interrupt
    INTCON0bits.GIE = 0;

    //Perform the unlock sequence
    asm("asmopt push"); //save the current selection of optimizations
    asm("asmopt off"); //turn off assembler optimizations
    asm("banksel(_NVMLOCK)"); //select the bank of the NVMLOCK register
    NVMLOCK = unlockKeyLow; //assign 'unlockKeyLow' to NVMLOCK.
    asm("MOVF (_unlockKeyHigh&0xFF),w,c"); //load 'unlockKeyHigh' into the W register
    asm("MOVWF (_NVMLOCK&0xFF),b"); //move the W register to NVMLOCK

    //Start page erase
    asm("bsf (_NVMCON0bits&0xFF)," ___mkstr(_NVMCON0_GO_POSN) ",b"); //Set GO bit
    asm("asmopt pop"); //restore assembler optimization settings

    //Restore global interrupt enable bit value
    INTCON0bits.GIE = globalInterruptBitValue;

    //Clear the NVM Command
    NVMCON1bits.NVMCMD = 0x00;
    
    if (NVMCON1bits.WRERR == 1)
    {
       return NVM_ERROR;
    }
    else
    {
        return NVM_OK;
    }
}

flash_address_t FLASH_PageAddressGet(flash_address_t address)
{
    return (flash_address_t) (address & ((PROGMEM_SIZE - 1U) ^ (PROGMEM_PAGE_SIZE - 1U)));
}

uint16_t FLASH_PageOffsetGet(flash_address_t address)
{
    return (uint16_t) (address & (PROGMEM_PAGE_SIZE - 1U));
}

eeprom_data_t EEPROM_Read(eeprom_address_t address)
{
    //Load NVMADR with the desired byte address
    NVMADRU = (uint8_t) (address >> 16);
    NVMADRH = (uint8_t) (address >> 8);
    NVMADRL = (uint8_t) address;

    //Set the byte read command
    NVMCON1bits.NVMCMD = 0x00;
    
    //Start byte read
    NVMCON0bits.GO = 1;

    return NVMDATL;
}

void EEPROM_Write(eeprom_address_t address, eeprom_data_t data)
{
    //Save global interrupt enable bit value
    uint8_t globalInterruptBitValue = INTCON0bits.GIE;

    //Load NVMADR with the target address of the byte
    NVMADRU = (uint8_t) (address >> 16);
    NVMADRH = (uint8_t) (address >> 8);
    NVMADRL = (uint8_t) address;

    //Load NVMDAT with the desired value
    NVMDATL = data;

    //Set the byte write command
    NVMCON1bits.NVMCMD = 0x03;

    //Disable global interrupt
    INTCON0bits.GIE = 0;
    
    //Perform the unlock sequence 
    asm("asmopt push"); //save the current selection of optimizations
    asm("asmopt off"); //turn off assembler optimizations
    asm("banksel(_NVMLOCK)"); //select the bank of the NVMLOCK register
    NVMLOCK = unlockKeyLow; //assign 'unlockKeyLow' to NVMLOCK.
    asm("MOVF (_unlockKeyHigh&0xFF),w,c"); //load 'unlockKeyHigh' into the W register
    asm("MOVWF (_NVMLOCK&0xFF),b"); //move the W register to NVMLOCK

    //Start byte write
    asm("bsf (_NVMCON0bits&0xFF)," ___mkstr(_NVMCON0_GO_POSN) ",b"); //Set GO bit   
    asm("asmopt pop"); //restore assembler optimization settings

    //Restore global interrupt enable bit value
    INTCON0bits.GIE = globalInterruptBitValue;

    //Clear the NVM Command
    NVMCON1bits.NVMCMD = 0x00;
}
