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

#include "lpc17xx_adc.h"

#include "return.h"

int _ADC_ChannelGetStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	uint8_t channel;
	uint32_t StatusType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	StatusType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) ADC_ChannelGetStatus(ADCx, channel, StatusType));
	writeUSBOutString(str);
	return 0;
}

int _ADC_GlobalGetData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) ADC_GlobalGetData(ADCx));
	writeUSBOutString(str);
	return 0;
}

int _ADC_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	uint32_t rate;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	rate = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	ADC_Init(ADCx, rate);
	return 0;
}

int _ADC_ChannelCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	uint8_t Channel;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Channel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	ADC_ChannelCmd(ADCx, Channel, NewState);
	return 0;
}

int _ADC_GlobalGetStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	uint32_t StatusType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	StatusType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) ADC_GlobalGetStatus(ADCx, StatusType));
	writeUSBOutString(str);
	return 0;
}

int _ADC_EdgeStartConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	uint8_t EdgeOption;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EdgeOption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	ADC_EdgeStartConfig(ADCx, EdgeOption);
	return 0;
}

int _ADC_ChannelGetData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	uint8_t channel;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	channel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) ADC_ChannelGetData(ADCx, channel));
	writeUSBOutString(str);
	return 0;
}

int _ADC_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	ADC_DeInit(ADCx);
	return 0;
}

int _ADC_BurstCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	ADC_BurstCmd(ADCx, NewState);
	return 0;
}

int _ADC_PowerdownCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	ADC_PowerdownCmd(ADCx, NewState);
	return 0;
}

int _ADC_StartCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	uint8_t start_mode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	start_mode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	ADC_StartCmd(ADCx, start_mode);
	return 0;
}

int _ADC_IntConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* ADCx;
	ADC_TYPE_INT_OPT IntType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ADCx = (LPC_ADC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntType = (ADC_TYPE_INT_OPT) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	ADC_IntConfig(ADCx, IntType, NewState);
	return 0;
}

int _ADC_CHANNEL_SELECTION_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(ADC_CHANNEL_SELECTION)));
	writeUSBOutString(str);
	return 0;
}

int _ADC_START_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(ADC_START_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _ADC_TYPE_INT_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(ADC_TYPE_INT_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _ADC_START_ON_EDGE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(ADC_START_ON_EDGE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _ADC_DATA_STATUS_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(ADC_DATA_STATUS)));
	writeUSBOutString(str);
	return 0;
}

