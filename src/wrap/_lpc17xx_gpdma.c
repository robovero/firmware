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

#include "lpc17xx_gpdma.h"

#include "return.h"

int _GPDMA_Init(uint8_t * args)
{
	GPDMA_Init();
	return 0;
}

int _GPDMA_ChannelCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t channelNum;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channelNum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	GPDMA_ChannelCmd(channelNum, NewState);
	return 0;
}

int _GPDMA_Setup(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMAChannelConfig;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMAChannelConfig = (GPDMA_Channel_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Setup(GPDMAChannelConfig));
	writeUSBOutString(str);
	return 0;
}

int _GPDMA_IntGetStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Status_Type type;
	uint8_t channel;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	type = (GPDMA_Status_Type) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_IntGetStatus(type, channel));
	writeUSBOutString(str);
	return 0;
}

int _GPDMA_ClearIntPending(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_StateClear_Type type;
	uint8_t channel;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	type = (GPDMA_StateClear_Type) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	GPDMA_ClearIntPending(type, channel);
	return 0;
}

int _GPDMA_StateClear_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(GPDMA_StateClear_Type)));
	writeUSBOutString(str);
	return 0;
}

int _GPDMA_LLI_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(GPDMA_LLI_Type)));
	writeUSBOutString(str);
	return 0;
}

int _GPDMA_LLI_Type_SrcAddr(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_LLI_Type* GPDMA_LLI_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_LLI_Type_ptr = (GPDMA_LLI_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_LLI_Type_ptr->SrcAddr);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_LLI_Type_ptr->SrcAddr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_LLI_Type_DstAddr(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_LLI_Type* GPDMA_LLI_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_LLI_Type_ptr = (GPDMA_LLI_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_LLI_Type_ptr->DstAddr);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_LLI_Type_ptr->DstAddr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_LLI_Type_NextLLI(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_LLI_Type* GPDMA_LLI_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_LLI_Type_ptr = (GPDMA_LLI_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_LLI_Type_ptr->NextLLI);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_LLI_Type_ptr->NextLLI = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_LLI_Type_Control(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_LLI_Type* GPDMA_LLI_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_LLI_Type_ptr = (GPDMA_LLI_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_LLI_Type_ptr->Control);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_LLI_Type_ptr->Control = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(GPDMA_Channel_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _GPDMA_Channel_CFG_Type_ChannelNum(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->ChannelNum);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->ChannelNum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_TransferSize(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->TransferSize);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->TransferSize = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_TransferWidth(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->TransferWidth);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->TransferWidth = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_SrcMemAddr(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->SrcMemAddr);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->SrcMemAddr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_DstMemAddr(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->DstMemAddr);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->DstMemAddr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_TransferType(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->TransferType);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->TransferType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_SrcConn(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->SrcConn);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->SrcConn = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_DstConn(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->DstConn);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->DstConn = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Channel_CFG_Type_DMALLI(uint8_t * args)
{
	uint8_t * arg_ptr;
	GPDMA_Channel_CFG_Type* GPDMA_Channel_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	GPDMA_Channel_CFG_Type_ptr = (GPDMA_Channel_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) GPDMA_Channel_CFG_Type_ptr->DMALLI);
		writeUSBOutString(str);
		return 0;
	}

	GPDMA_Channel_CFG_Type_ptr->DMALLI = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _GPDMA_Status_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(GPDMA_Status_Type)));
	writeUSBOutString(str);
	return 0;
}

