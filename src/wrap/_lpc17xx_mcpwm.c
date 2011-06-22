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

#include "lpc17xx_mcpwm.h"

#include "return.h"

int _MCPWM_ConfigCapture(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t channelNum;
	MCPWM_CAPTURE_CFG_Type* captureConfig;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channelNum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	captureConfig = (MCPWM_CAPTURE_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_ConfigCapture(MCPWMx, channelNum, captureConfig);
	return 0;
}

int _MCPWM_IntConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t ulIntType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_IntConfig(MCPWMx, ulIntType, NewState);
	return 0;
}

int _MCPWM_ACMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t acMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	acMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_ACMode(MCPWMx, acMode);
	return 0;
}

int _MCPWM_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_Init(MCPWMx);
	return 0;
}

int _MCPWM_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t ulIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_GetIntStatus(MCPWMx, ulIntType));
	writeUSBOutString(str);
	return 0;
}

int _MCPWM_Stop(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t channel0;
	uint32_t channel1;
	uint32_t channel2;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_Stop(MCPWMx, channel0, channel1, channel2);
	return 0;
}

int _MCPWM_Start(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t channel0;
	uint32_t channel1;
	uint32_t channel2;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_Start(MCPWMx, channel0, channel1, channel2);
	return 0;
}

int _MCPWM_GetCapture(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t captureChannel;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	captureChannel = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_GetCapture(MCPWMx, captureChannel));
	writeUSBOutString(str);
	return 0;
}

int _MCPWM_IntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t ulIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_IntSet(MCPWMx, ulIntType);
	return 0;
}

int _MCPWM_ConfigChannel(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t channelNum;
	MCPWM_CHANNEL_CFG_Type* channelSetup;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channelNum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channelSetup = (MCPWM_CHANNEL_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_ConfigChannel(MCPWMx, channelNum, channelSetup);
	return 0;
}

int _MCPWM_ClearCapture(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t captureChannel;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	captureChannel = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_ClearCapture(MCPWMx, captureChannel);
	return 0;
}

int _MCPWM_DCMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t dcMode;
	uint32_t outputInvered;
	uint32_t outputPattern;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dcMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	outputInvered = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	outputPattern = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_DCMode(MCPWMx, dcMode, outputInvered, outputPattern);
	return 0;
}

int _MCPWM_CountConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t channelNum;
	uint32_t countMode;
	MCPWM_COUNT_CFG_Type* countConfig;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channelNum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	countMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	countConfig = (MCPWM_COUNT_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_CountConfig(MCPWMx, channelNum, countMode, countConfig);
	return 0;
}

int _MCPWM_WriteToShadow(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t channelNum;
	MCPWM_CHANNEL_CFG_Type* channelSetup;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channelNum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channelSetup = (MCPWM_CHANNEL_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_WriteToShadow(MCPWMx, channelNum, channelSetup);
	return 0;
}

int _MCPWM_IntClear(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* MCPWMx;
	uint32_t ulIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWMx = (LPC_MCPWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	MCPWM_IntClear(MCPWMx, ulIntType);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(MCPWM_CHANNEL_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_channelType(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CHANNEL_CFG_Type* MCPWM_CHANNEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CHANNEL_CFG_Type_ptr = (MCPWM_CHANNEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CHANNEL_CFG_Type_ptr->channelType);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CHANNEL_CFG_Type_ptr->channelType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_channelPolarity(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CHANNEL_CFG_Type* MCPWM_CHANNEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CHANNEL_CFG_Type_ptr = (MCPWM_CHANNEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CHANNEL_CFG_Type_ptr->channelPolarity);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CHANNEL_CFG_Type_ptr->channelPolarity = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_channelDeadtimeEnable(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CHANNEL_CFG_Type* MCPWM_CHANNEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CHANNEL_CFG_Type_ptr = (MCPWM_CHANNEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CHANNEL_CFG_Type_ptr->channelDeadtimeEnable);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CHANNEL_CFG_Type_ptr->channelDeadtimeEnable = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_channelDeadtimeValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CHANNEL_CFG_Type* MCPWM_CHANNEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CHANNEL_CFG_Type_ptr = (MCPWM_CHANNEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CHANNEL_CFG_Type_ptr->channelDeadtimeValue);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CHANNEL_CFG_Type_ptr->channelDeadtimeValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_channelUpdateEnable(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CHANNEL_CFG_Type* MCPWM_CHANNEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CHANNEL_CFG_Type_ptr = (MCPWM_CHANNEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CHANNEL_CFG_Type_ptr->channelUpdateEnable);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CHANNEL_CFG_Type_ptr->channelUpdateEnable = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_channelTimercounterValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CHANNEL_CFG_Type* MCPWM_CHANNEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CHANNEL_CFG_Type_ptr = (MCPWM_CHANNEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CHANNEL_CFG_Type_ptr->channelTimercounterValue);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CHANNEL_CFG_Type_ptr->channelTimercounterValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_channelPeriodValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CHANNEL_CFG_Type* MCPWM_CHANNEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CHANNEL_CFG_Type_ptr = (MCPWM_CHANNEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CHANNEL_CFG_Type_ptr->channelPeriodValue);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CHANNEL_CFG_Type_ptr->channelPeriodValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CHANNEL_CFG_Type_channelPulsewidthValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CHANNEL_CFG_Type* MCPWM_CHANNEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CHANNEL_CFG_Type_ptr = (MCPWM_CHANNEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CHANNEL_CFG_Type_ptr->channelPulsewidthValue);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CHANNEL_CFG_Type_ptr->channelPulsewidthValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_COUNT_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(MCPWM_COUNT_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _MCPWM_COUNT_CFG_Type_counterChannel(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_COUNT_CFG_Type* MCPWM_COUNT_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_COUNT_CFG_Type_ptr = (MCPWM_COUNT_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_COUNT_CFG_Type_ptr->counterChannel);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_COUNT_CFG_Type_ptr->counterChannel = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_COUNT_CFG_Type_countRising(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_COUNT_CFG_Type* MCPWM_COUNT_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_COUNT_CFG_Type_ptr = (MCPWM_COUNT_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_COUNT_CFG_Type_ptr->countRising);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_COUNT_CFG_Type_ptr->countRising = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_COUNT_CFG_Type_countFalling(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_COUNT_CFG_Type* MCPWM_COUNT_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_COUNT_CFG_Type_ptr = (MCPWM_COUNT_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_COUNT_CFG_Type_ptr->countFalling);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_COUNT_CFG_Type_ptr->countFalling = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CAPTURE_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(MCPWM_CAPTURE_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _MCPWM_CAPTURE_CFG_Type_captureChannel(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CAPTURE_CFG_Type* MCPWM_CAPTURE_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CAPTURE_CFG_Type_ptr = (MCPWM_CAPTURE_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CAPTURE_CFG_Type_ptr->captureChannel);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CAPTURE_CFG_Type_ptr->captureChannel = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CAPTURE_CFG_Type_captureRising(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CAPTURE_CFG_Type* MCPWM_CAPTURE_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CAPTURE_CFG_Type_ptr = (MCPWM_CAPTURE_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CAPTURE_CFG_Type_ptr->captureRising);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CAPTURE_CFG_Type_ptr->captureRising = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CAPTURE_CFG_Type_captureFalling(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CAPTURE_CFG_Type* MCPWM_CAPTURE_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CAPTURE_CFG_Type_ptr = (MCPWM_CAPTURE_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CAPTURE_CFG_Type_ptr->captureFalling);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CAPTURE_CFG_Type_ptr->captureFalling = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CAPTURE_CFG_Type_timerReset(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CAPTURE_CFG_Type* MCPWM_CAPTURE_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CAPTURE_CFG_Type_ptr = (MCPWM_CAPTURE_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CAPTURE_CFG_Type_ptr->timerReset);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CAPTURE_CFG_Type_ptr->timerReset = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _MCPWM_CAPTURE_CFG_Type_hnfEnable(uint8_t * args)
{
	uint8_t * arg_ptr;
	MCPWM_CAPTURE_CFG_Type* MCPWM_CAPTURE_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MCPWM_CAPTURE_CFG_Type_ptr = (MCPWM_CAPTURE_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) MCPWM_CAPTURE_CFG_Type_ptr->hnfEnable);
		writeUSBOutString(str);
		return 0;
	}

	MCPWM_CAPTURE_CFG_Type_ptr->hnfEnable = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

