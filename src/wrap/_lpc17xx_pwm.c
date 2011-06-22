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

#include "lpc17xx_pwm.h"

#include "return.h"

int _PWM_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	PWM_DeInit(PWMx);
	return 0;
}

int _PWM_PinConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	uint8_t PWM_Channel;
	uint8_t PinselOption;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_Channel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PinselOption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	PWM_PinConfig(PWMx, PWM_Channel, PinselOption);
	return 0;
}

int _PWM_GetCaptureValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	uint8_t CaptureChannel;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	CaptureChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) PWM_GetCaptureValue(PWMx, CaptureChannel));
	writeUSBOutString(str);
	return 0;
}

int _PWM_ConfigStructInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t PWMTimerCounterMode;
	void* PWM_InitStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMTimerCounterMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_InitStruct = (void*) strtoul((char *) arg_ptr, NULL, 16);

	PWM_ConfigStructInit(PWMTimerCounterMode, PWM_InitStruct);
	return 0;
}

int _PWM_ChannelCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	uint8_t PWMChannel;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	PWM_ChannelCmd(PWMx, PWMChannel, NewState);
	return 0;
}

int _PWM_ConfigCapture(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	PWM_CAPTURECFG_Type* PWM_CaptureConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_CaptureConfigStruct = (PWM_CAPTURECFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	PWM_ConfigCapture(PWMx, PWM_CaptureConfigStruct);
	return 0;
}

int _PWM_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	uint32_t IntFlag;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntFlag = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) PWM_GetIntStatus(PWMx, IntFlag));
	writeUSBOutString(str);
	return 0;
}

int _PWM_ChannelConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	uint8_t PWMChannel;
	uint8_t ModeOption;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ModeOption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	PWM_ChannelConfig(PWMx, PWMChannel, ModeOption);
	return 0;
}

int _PWM_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	uint32_t PWMTimerCounterMode;
	void* PWM_ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMTimerCounterMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_ConfigStruct = (void*) strtoul((char *) arg_ptr, NULL, 16);

	PWM_Init(PWMx, PWMTimerCounterMode, PWM_ConfigStruct);
	return 0;
}

int _PWM_MatchUpdate(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	uint8_t MatchChannel;
	uint32_t MatchValue;
	uint8_t UpdateType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MatchChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MatchValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UpdateType = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	PWM_MatchUpdate(PWMx, MatchChannel, MatchValue, UpdateType);
	return 0;
}

int _PWM_ConfigMatch(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	PWM_MATCHCFG_Type* PWM_MatchConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_MatchConfigStruct = (PWM_MATCHCFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	PWM_ConfigMatch(PWMx, PWM_MatchConfigStruct);
	return 0;
}

int _PWM_ResetCounter(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	PWM_ResetCounter(PWMx);
	return 0;
}

int _PWM_CounterCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	PWM_CounterCmd(PWMx, NewState);
	return 0;
}

int _PWM_Cmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	PWM_Cmd(PWMx, NewState);
	return 0;
}

int _PWM_ClearIntPending(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* PWMx;
	uint32_t IntFlag;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWMx = (LPC_PWM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntFlag = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	PWM_ClearIntPending(PWMx, IntFlag);
	return 0;
}

int _PWM_MATCHCFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_MATCHCFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_MATCHCFG_Type_MatchChannel(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_MATCHCFG_Type* PWM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_MATCHCFG_Type_ptr = (PWM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_MATCHCFG_Type_ptr->MatchChannel);
		writeUSBOutString(str);
		return 0;
	}

	PWM_MATCHCFG_Type_ptr->MatchChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_MATCHCFG_Type_IntOnMatch(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_MATCHCFG_Type* PWM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_MATCHCFG_Type_ptr = (PWM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_MATCHCFG_Type_ptr->IntOnMatch);
		writeUSBOutString(str);
		return 0;
	}

	PWM_MATCHCFG_Type_ptr->IntOnMatch = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_MATCHCFG_Type_StopOnMatch(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_MATCHCFG_Type* PWM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_MATCHCFG_Type_ptr = (PWM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_MATCHCFG_Type_ptr->StopOnMatch);
		writeUSBOutString(str);
		return 0;
	}

	PWM_MATCHCFG_Type_ptr->StopOnMatch = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_MATCHCFG_Type_ResetOnMatch(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_MATCHCFG_Type* PWM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_MATCHCFG_Type_ptr = (PWM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_MATCHCFG_Type_ptr->ResetOnMatch);
		writeUSBOutString(str);
		return 0;
	}

	PWM_MATCHCFG_Type_ptr->ResetOnMatch = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_TIMER_PRESCALE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_TIMER_PRESCALE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_TC_MODE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_TC_MODE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_TIMERCFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_TIMERCFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_TIMERCFG_Type_PrescaleOption(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_TIMERCFG_Type* PWM_TIMERCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_TIMERCFG_Type_ptr = (PWM_TIMERCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_TIMERCFG_Type_ptr->PrescaleOption);
		writeUSBOutString(str);
		return 0;
	}

	PWM_TIMERCFG_Type_ptr->PrescaleOption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_TIMERCFG_Type_PrescaleValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_TIMERCFG_Type* PWM_TIMERCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_TIMERCFG_Type_ptr = (PWM_TIMERCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_TIMERCFG_Type_ptr->PrescaleValue);
		writeUSBOutString(str);
		return 0;
	}

	PWM_TIMERCFG_Type_ptr->PrescaleValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_MATCH_UPDATE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_MATCH_UPDATE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_INTSTAT_TYPE_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_INTSTAT_TYPE)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_COUNTER_EDGE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_COUNTER_EDGE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_CAPTURECFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_CAPTURECFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_CAPTURECFG_Type_CaptureChannel(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_CAPTURECFG_Type* PWM_CAPTURECFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_CAPTURECFG_Type_ptr = (PWM_CAPTURECFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_CAPTURECFG_Type_ptr->CaptureChannel);
		writeUSBOutString(str);
		return 0;
	}

	PWM_CAPTURECFG_Type_ptr->CaptureChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_CAPTURECFG_Type_RisingEdge(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_CAPTURECFG_Type* PWM_CAPTURECFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_CAPTURECFG_Type_ptr = (PWM_CAPTURECFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_CAPTURECFG_Type_ptr->RisingEdge);
		writeUSBOutString(str);
		return 0;
	}

	PWM_CAPTURECFG_Type_ptr->RisingEdge = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_CAPTURECFG_Type_FallingEdge(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_CAPTURECFG_Type* PWM_CAPTURECFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_CAPTURECFG_Type_ptr = (PWM_CAPTURECFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_CAPTURECFG_Type_ptr->FallingEdge);
		writeUSBOutString(str);
		return 0;
	}

	PWM_CAPTURECFG_Type_ptr->FallingEdge = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_CAPTURECFG_Type_IntOnCaption(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_CAPTURECFG_Type* PWM_CAPTURECFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_CAPTURECFG_Type_ptr = (PWM_CAPTURECFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_CAPTURECFG_Type_ptr->IntOnCaption);
		writeUSBOutString(str);
		return 0;
	}

	PWM_CAPTURECFG_Type_ptr->IntOnCaption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_COUNTERCFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_COUNTERCFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_COUNTERCFG_Type_CounterOption(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_COUNTERCFG_Type* PWM_COUNTERCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_COUNTERCFG_Type_ptr = (PWM_COUNTERCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_COUNTERCFG_Type_ptr->CounterOption);
		writeUSBOutString(str);
		return 0;
	}

	PWM_COUNTERCFG_Type_ptr->CounterOption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_COUNTERCFG_Type_CountInputSelect(uint8_t * args)
{
	uint8_t * arg_ptr;
	PWM_COUNTERCFG_Type* PWM_COUNTERCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PWM_COUNTERCFG_Type_ptr = (PWM_COUNTERCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PWM_COUNTERCFG_Type_ptr->CountInputSelect);
		writeUSBOutString(str);
		return 0;
	}

	PWM_COUNTERCFG_Type_ptr->CountInputSelect = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PWM_CHANNEL_EDGE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_CHANNEL_EDGE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _PWM_COUNTER_INPUTSEL_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PWM_COUNTER_INPUTSEL_OPT)));
	writeUSBOutString(str);
	return 0;
}

