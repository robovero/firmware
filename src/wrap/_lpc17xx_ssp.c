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

#include "lpc17xx_ssp.h"

#include "return.h"

int _SSP_LoopBackCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	SSP_LoopBackCmd(SSPx, NewState);
	return 0;
}

int _SSP_GetRawIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	uint32_t RawIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RawIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SSP_GetRawIntStatus(SSPx, RawIntType));
	writeUSBOutString(str);
	return 0;
}

int _SSP_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	SSP_CFG_Type* SSP_ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_ConfigStruct = (SSP_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	SSP_Init(SSPx, SSP_ConfigStruct);
	return 0;
}

int _SSP_DMACmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	uint32_t DMAMode;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DMAMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	SSP_DMACmd(SSPx, DMAMode, NewState);
	return 0;
}

int _SSP_GetDataSize(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SSP_GetDataSize(SSPx));
	writeUSBOutString(str);
	return 0;
}

int _SSP_Cmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	SSP_Cmd(SSPx, NewState);
	return 0;
}

int _SSP_IntConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	uint32_t IntType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	SSP_IntConfig(SSPx, IntType, NewState);
	return 0;
}

int _SSP_SlaveOutputCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	SSP_SlaveOutputCmd(SSPx, NewState);
	return 0;
}

int _SSP_ClearIntPending(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	uint32_t IntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	SSP_ClearIntPending(SSPx, IntType);
	return 0;
}

int _SSP_ReadWrite(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	SSP_DATA_SETUP_Type* dataCfg;
	SSP_TRANSFER_Type xfType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dataCfg = (SSP_DATA_SETUP_Type*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	xfType = (SSP_TRANSFER_Type) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SSP_ReadWrite(SSPx, dataCfg, xfType));
	writeUSBOutString(str);
	return 0;
}

int _SSP_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	SSP_DeInit(SSPx);
	return 0;
}

int _SSP_GetStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	uint32_t FlagType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	FlagType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SSP_GetStatus(SSPx, FlagType));
	writeUSBOutString(str);
	return 0;
}

int _SSP_GetRawIntStatusReg(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SSP_GetRawIntStatusReg(SSPx));
	writeUSBOutString(str);
	return 0;
}

int _SSP_ConfigStructInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_CFG_Type* SSP_InitStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_InitStruct = (SSP_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	SSP_ConfigStructInit(SSP_InitStruct);
	return 0;
}

int _SSP_ReceiveData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SSP_ReceiveData(SSPx));
	writeUSBOutString(str);
	return 0;
}

int _SSP_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	uint32_t IntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) SSP_GetIntStatus(SSPx, IntType));
	writeUSBOutString(str);
	return 0;
}

int _SSP_SendData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* SSPx;
	uint16_t Data;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSPx = (LPC_SSP_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Data = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

	SSP_SendData(SSPx, Data);
	return 0;
}

int _SSP_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(SSP_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _SSP_CFG_Type_Databit(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_CFG_Type* SSP_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_CFG_Type_ptr = (SSP_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_CFG_Type_ptr->Databit);
		writeUSBOutString(str);
		return 0;
	}

	SSP_CFG_Type_ptr->Databit = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_CFG_Type_CPHA(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_CFG_Type* SSP_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_CFG_Type_ptr = (SSP_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_CFG_Type_ptr->CPHA);
		writeUSBOutString(str);
		return 0;
	}

	SSP_CFG_Type_ptr->CPHA = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_CFG_Type_CPOL(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_CFG_Type* SSP_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_CFG_Type_ptr = (SSP_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_CFG_Type_ptr->CPOL);
		writeUSBOutString(str);
		return 0;
	}

	SSP_CFG_Type_ptr->CPOL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_CFG_Type_Mode(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_CFG_Type* SSP_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_CFG_Type_ptr = (SSP_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_CFG_Type_ptr->Mode);
		writeUSBOutString(str);
		return 0;
	}

	SSP_CFG_Type_ptr->Mode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_CFG_Type_FrameFormat(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_CFG_Type* SSP_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_CFG_Type_ptr = (SSP_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_CFG_Type_ptr->FrameFormat);
		writeUSBOutString(str);
		return 0;
	}

	SSP_CFG_Type_ptr->FrameFormat = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_CFG_Type_ClockRate(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_CFG_Type* SSP_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_CFG_Type_ptr = (SSP_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_CFG_Type_ptr->ClockRate);
		writeUSBOutString(str);
		return 0;
	}

	SSP_CFG_Type_ptr->ClockRate = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_DATA_SETUP_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(SSP_DATA_SETUP_Type)));
	writeUSBOutString(str);
	return 0;
}

int _SSP_DATA_SETUP_Type_tx_data(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_DATA_SETUP_Type* SSP_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_DATA_SETUP_Type_ptr = (SSP_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_DATA_SETUP_Type_ptr->tx_data);
		writeUSBOutString(str);
		return 0;
	}

	SSP_DATA_SETUP_Type_ptr->tx_data = (void*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_DATA_SETUP_Type_tx_cnt(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_DATA_SETUP_Type* SSP_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_DATA_SETUP_Type_ptr = (SSP_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_DATA_SETUP_Type_ptr->tx_cnt);
		writeUSBOutString(str);
		return 0;
	}

	SSP_DATA_SETUP_Type_ptr->tx_cnt = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_DATA_SETUP_Type_rx_data(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_DATA_SETUP_Type* SSP_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_DATA_SETUP_Type_ptr = (SSP_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_DATA_SETUP_Type_ptr->rx_data);
		writeUSBOutString(str);
		return 0;
	}

	SSP_DATA_SETUP_Type_ptr->rx_data = (void*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_DATA_SETUP_Type_rx_cnt(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_DATA_SETUP_Type* SSP_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_DATA_SETUP_Type_ptr = (SSP_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_DATA_SETUP_Type_ptr->rx_cnt);
		writeUSBOutString(str);
		return 0;
	}

	SSP_DATA_SETUP_Type_ptr->rx_cnt = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_DATA_SETUP_Type_length(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_DATA_SETUP_Type* SSP_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_DATA_SETUP_Type_ptr = (SSP_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_DATA_SETUP_Type_ptr->length);
		writeUSBOutString(str);
		return 0;
	}

	SSP_DATA_SETUP_Type_ptr->length = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_DATA_SETUP_Type_status(uint8_t * args)
{
	uint8_t * arg_ptr;
	SSP_DATA_SETUP_Type* SSP_DATA_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SSP_DATA_SETUP_Type_ptr = (SSP_DATA_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) SSP_DATA_SETUP_Type_ptr->status);
		writeUSBOutString(str);
		return 0;
	}

	SSP_DATA_SETUP_Type_ptr->status = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _SSP_TRANSFER_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(SSP_TRANSFER_Type)));
	writeUSBOutString(str);
	return 0;
}

