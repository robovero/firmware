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

#include "lpc17xx_spi.h"

#include "return.h"

int _SPI_SetClock(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;
	uint32_t target_clock;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	target_clock = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	SPI_SetClock(SPIx, target_clock);
	return 0;
}

int _SPI_CheckStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t inputSPIStatus;
	uint8_t SPIStatus;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	inputSPIStatus = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIStatus = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SPI_CheckStatus(inputSPIStatus, SPIStatus));
	writeUSBOutString(str);
	return 0;
}

int _SPI_SendData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;
	uint16_t Data;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Data = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

	SPI_SendData(SPIx, Data);
	return 0;
}

int _SPI_GetStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SPI_GetStatus(SPIx));
	writeUSBOutString(str);
	return 0;
}

int _SPI_GetDataSize(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SPI_GetDataSize(SPIx));
	writeUSBOutString(str);
	return 0;
}

int _SPI_ReceiveData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SPI_ReceiveData(SPIx));
	writeUSBOutString(str);
	return 0;
}

int _SPI_ConfigStructInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_CFG_Type* SPI_InitStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_InitStruct = (SPI_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	SPI_ConfigStructInit(SPI_InitStruct);
	return 0;
}

int _SPI_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SPI_GetIntStatus(SPIx));
	writeUSBOutString(str);
	return 0;
}

int _SPI_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	SPI_DeInit(SPIx);
	return 0;
}

int _SPI_IntCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	SPI_IntCmd(SPIx, NewState);
	return 0;
}

int _SPI_ReadWrite(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;
	SPI_DATA_SETUP_Type* dataCfg;
	SPI_TRANSFER_Type xfType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dataCfg = (SPI_DATA_SETUP_Type*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	xfType = (SPI_TRANSFER_Type) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SPI_ReadWrite(SPIx, dataCfg, xfType));
	writeUSBOutString(str);
	return 0;
}

int _SPI_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;
	SPI_CFG_Type* SPI_ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_ConfigStruct = (SPI_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	SPI_Init(SPIx, SPI_ConfigStruct);
	return 0;
}

int _SPI_ClearIntPending(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* SPIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPIx = (LPC_SPI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	SPI_ClearIntPending(SPIx);
	return 0;
}

int _SPI_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(SPI_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _SPI_CFG_Type_Databit(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_CFG_Type* SPI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_CFG_Type_ptr = (SPI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_CFG_Type_ptr->Databit);
		writeUSBOutString(str);
		return 0;
	}

	SPI_CFG_Type_ptr->Databit = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_CFG_Type_CPHA(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_CFG_Type* SPI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_CFG_Type_ptr = (SPI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_CFG_Type_ptr->CPHA);
		writeUSBOutString(str);
		return 0;
	}

	SPI_CFG_Type_ptr->CPHA = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_CFG_Type_CPOL(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_CFG_Type* SPI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_CFG_Type_ptr = (SPI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_CFG_Type_ptr->CPOL);
		writeUSBOutString(str);
		return 0;
	}

	SPI_CFG_Type_ptr->CPOL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_CFG_Type_Mode(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_CFG_Type* SPI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_CFG_Type_ptr = (SPI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_CFG_Type_ptr->Mode);
		writeUSBOutString(str);
		return 0;
	}

	SPI_CFG_Type_ptr->Mode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_CFG_Type_DataOrder(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_CFG_Type* SPI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_CFG_Type_ptr = (SPI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_CFG_Type_ptr->DataOrder);
		writeUSBOutString(str);
		return 0;
	}

	SPI_CFG_Type_ptr->DataOrder = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_CFG_Type_ClockRate(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_CFG_Type* SPI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_CFG_Type_ptr = (SPI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_CFG_Type_ptr->ClockRate);
		writeUSBOutString(str);
		return 0;
	}

	SPI_CFG_Type_ptr->ClockRate = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_DATA_SETUP_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(SPI_DATA_SETUP_Type)));
	writeUSBOutString(str);
	return 0;
}

int _SPI_DATA_SETUP_Type_tx_data(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_DATA_SETUP_Type* SPI_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_DATA_SETUP_Type_ptr = (SPI_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_DATA_SETUP_Type_ptr->tx_data);
		writeUSBOutString(str);
		return 0;
	}

	SPI_DATA_SETUP_Type_ptr->tx_data = (void*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_DATA_SETUP_Type_rx_data(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_DATA_SETUP_Type* SPI_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_DATA_SETUP_Type_ptr = (SPI_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_DATA_SETUP_Type_ptr->rx_data);
		writeUSBOutString(str);
		return 0;
	}

	SPI_DATA_SETUP_Type_ptr->rx_data = (void*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_DATA_SETUP_Type_length(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_DATA_SETUP_Type* SPI_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_DATA_SETUP_Type_ptr = (SPI_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_DATA_SETUP_Type_ptr->length);
		writeUSBOutString(str);
		return 0;
	}

	SPI_DATA_SETUP_Type_ptr->length = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_DATA_SETUP_Type_counter(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_DATA_SETUP_Type* SPI_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_DATA_SETUP_Type_ptr = (SPI_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_DATA_SETUP_Type_ptr->counter);
		writeUSBOutString(str);
		return 0;
	}

	SPI_DATA_SETUP_Type_ptr->counter = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_DATA_SETUP_Type_status(uint8_t * args)
{
	uint8_t * arg_ptr;
	SPI_DATA_SETUP_Type* SPI_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SPI_DATA_SETUP_Type_ptr = (SPI_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SPI_DATA_SETUP_Type_ptr->status);
		writeUSBOutString(str);
		return 0;
	}

	SPI_DATA_SETUP_Type_ptr->status = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SPI_TRANSFER_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(SPI_TRANSFER_Type)));
	writeUSBOutString(str);
	return 0;
}

