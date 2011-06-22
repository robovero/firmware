/*******************************************************************************
 * @file
 * @purpose		
 * @version		0.1
 *------------------------------------------------------------------------------
 * Copyright (C) 2011 Gumstix Inc.
 * All rights reserved.
 *
 * Contributer(s):
 *   Neil MacMunn   <neil@gumstix.com>
 *------------------------------------------------------------------------------
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * Redistributions of source code must retain the above copyright notice, this
 * 	list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#include "lpc17xx_gpio.h"

#include "return.h"

int _FIO_IntCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;
	uint8_t edgeState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	edgeState = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_IntCmd(portNum, bitValue, edgeState);
	return 0;
}

int _GPIO_ClearInt(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	GPIO_ClearInt(portNum, bitValue);
	return 0;
}

int _GPIO_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t pinNum;
	uint8_t edgeState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pinNum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	edgeState = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_GetIntStatus(portNum, pinNum, edgeState));
	writeUSBOutString(str);
	return 0;
}

int _FIO_HalfWordClearValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t halfwordNum;
	uint16_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	halfwordNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_HalfWordClearValue(portNum, halfwordNum, bitValue);
	return 0;
}

int _GPIO_IntCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;
	uint8_t edgeState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	edgeState = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	GPIO_IntCmd(portNum, bitValue, edgeState);
	return 0;
}

int _FIO_ClearInt(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t pinNum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pinNum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_ClearInt(portNum, pinNum);
	return 0;
}

int _FIO_ByteSetValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t byteNum;
	uint8_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	byteNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_ByteSetValue(portNum, byteNum, bitValue);
	return 0;
}

int _GPIO_ReadValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_ReadValue(portNum));
	writeUSBOutString(str);
	return 0;
}

int _FIO_ByteSetDir(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t byteNum;
	uint8_t bitValue;
	uint8_t dir;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	byteNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dir = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_ByteSetDir(portNum, byteNum, bitValue, dir);
	return 0;
}

int _FIO_HalfWordSetDir(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t halfwordNum;
	uint16_t bitValue;
	uint8_t dir;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	halfwordNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dir = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_HalfWordSetDir(portNum, halfwordNum, bitValue, dir);
	return 0;
}

int _FIO_SetValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_SetValue(portNum, bitValue);
	return 0;
}

int _FIO_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t pinNum;
	uint8_t edgeState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pinNum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	edgeState = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) FIO_GetIntStatus(portNum, pinNum, edgeState));
	writeUSBOutString(str);
	return 0;
}

int _FIO_HalfWordSetValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t halfwordNum;
	uint16_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	halfwordNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_HalfWordSetValue(portNum, halfwordNum, bitValue);
	return 0;
}

int _FIO_ByteClearValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t byteNum;
	uint8_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	byteNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_ByteClearValue(portNum, byteNum, bitValue);
	return 0;
}

int _FIO_ByteReadValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t byteNum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	byteNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) FIO_ByteReadValue(portNum, byteNum));
	writeUSBOutString(str);
	return 0;
}

int _GPIO_ClearValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	GPIO_ClearValue(portNum, bitValue);
	return 0;
}

int _FIO_ClearValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_ClearValue(portNum, bitValue);
	return 0;
}

int _FIO_SetDir(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;
	uint8_t dir;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dir = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_SetDir(portNum, bitValue, dir);
	return 0;
}

int _FIO_SetMask(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;
	uint8_t maskValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	maskValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_SetMask(portNum, bitValue, maskValue);
	return 0;
}

int _FIO_HalfWordReadValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t halfwordNum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	halfwordNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) FIO_HalfWordReadValue(portNum, halfwordNum));
	writeUSBOutString(str);
	return 0;
}

int _FIO_ByteSetMask(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t byteNum;
	uint8_t bitValue;
	uint8_t maskValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	byteNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	maskValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_ByteSetMask(portNum, byteNum, bitValue, maskValue);
	return 0;
}

int _FIO_ReadValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) FIO_ReadValue(portNum));
	writeUSBOutString(str);
	return 0;
}

int _GPIO_SetValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	GPIO_SetValue(portNum, bitValue);
	return 0;
}

int _FIO_HalfWordSetMask(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint8_t halfwordNum;
	uint16_t bitValue;
	uint8_t maskValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	halfwordNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	maskValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	FIO_HalfWordSetMask(portNum, halfwordNum, bitValue, maskValue);
	return 0;
}

int _GPIO_SetDir(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t portNum;
	uint32_t bitValue;
	uint8_t dir;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	portNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dir = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	GPIO_SetDir(portNum, bitValue, dir);
	return 0;
}

int _GPIO_Byte_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(GPIO_Byte_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

/*int _GPIO_Byte_TypeDef_FIODIR[4](uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_Byte_TypeDef* GPIO_Byte_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_Byte_TypeDef_ptr = (GPIO_Byte_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_Byte_TypeDef_ptr->FIODIR[4]);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_Byte_TypeDef_ptr->FIODIR[4] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_Byte_TypeDef_FIOMASK[4](uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_Byte_TypeDef* GPIO_Byte_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_Byte_TypeDef_ptr = (GPIO_Byte_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_Byte_TypeDef_ptr->FIOMASK[4]);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_Byte_TypeDef_ptr->FIOMASK[4] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_Byte_TypeDef_FIOPIN[4](uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_Byte_TypeDef* GPIO_Byte_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_Byte_TypeDef_ptr = (GPIO_Byte_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_Byte_TypeDef_ptr->FIOPIN[4]);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_Byte_TypeDef_ptr->FIOPIN[4] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_Byte_TypeDef_FIOSET[4](uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_Byte_TypeDef* GPIO_Byte_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_Byte_TypeDef_ptr = (GPIO_Byte_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_Byte_TypeDef_ptr->FIOSET[4]);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_Byte_TypeDef_ptr->FIOSET[4] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_Byte_TypeDef_FIOCLR[4](uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_Byte_TypeDef* GPIO_Byte_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_Byte_TypeDef_ptr = (GPIO_Byte_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	GPIO_Byte_TypeDef_ptr->FIOCLR[4] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _GPIO_HalfWord_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(GPIO_HalfWord_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIODIRL(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_HalfWord_TypeDef_ptr->FIODIRL);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_HalfWord_TypeDef_ptr->FIODIRL = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIODIRU(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_HalfWord_TypeDef_ptr->FIODIRU);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_HalfWord_TypeDef_ptr->FIODIRU = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIOMASKL(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_HalfWord_TypeDef_ptr->FIOMASKL);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_HalfWord_TypeDef_ptr->FIOMASKL = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIOMASKU(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_HalfWord_TypeDef_ptr->FIOMASKU);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_HalfWord_TypeDef_ptr->FIOMASKU = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIOPINL(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_HalfWord_TypeDef_ptr->FIOPINL);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_HalfWord_TypeDef_ptr->FIOPINL = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIOPINU(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_HalfWord_TypeDef_ptr->FIOPINU);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_HalfWord_TypeDef_ptr->FIOPINU = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIOSETL(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_HalfWord_TypeDef_ptr->FIOSETL);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_HalfWord_TypeDef_ptr->FIOSETL = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIOSETU(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPIO_HalfWord_TypeDef_ptr->FIOSETU);
		writeUSBOutString(str);
		return 0;
	}

	GPIO_HalfWord_TypeDef_ptr->FIOSETU = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIOCLRL(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	GPIO_HalfWord_TypeDef_ptr->FIOCLRL = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPIO_HalfWord_TypeDef_FIOCLRU(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPIO_HalfWord_TypeDef* GPIO_HalfWord_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPIO_HalfWord_TypeDef_ptr = (GPIO_HalfWord_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	GPIO_HalfWord_TypeDef_ptr->FIOCLRU = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

