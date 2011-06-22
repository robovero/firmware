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

#include "lpc17xx_timer.h"

#include "return.h"

int _TIM_GetIntCaptureStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_INT_TYPE IntFlag;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntFlag = (TIM_INT_TYPE) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) TIM_GetIntCaptureStatus(TIMx, IntFlag));
	writeUSBOutString(str);
	return 0;
}

int _TIM_ConfigMatch(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_MATCHCFG_Type* TIM_MatchConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_MatchConfigStruct = (TIM_MATCHCFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	TIM_ConfigMatch(TIMx, TIM_MatchConfigStruct);
	return 0;
}

int _TIM_ClearIntCapturePending(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_INT_TYPE IntFlag;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntFlag = (TIM_INT_TYPE) strtoul((char *) arg_ptr, NULL, 16);

	TIM_ClearIntCapturePending(TIMx, IntFlag);
	return 0;
}

int _TIM_SetMatchExt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_EXTMATCH_OPT ext_match;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ext_match = (TIM_EXTMATCH_OPT) strtoul((char *) arg_ptr, NULL, 16);

	TIM_SetMatchExt(TIMx, ext_match);
	return 0;
}

int _TIM_ConfigStructInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_MODE_OPT TimerCounterMode;
	void* TIM_ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TimerCounterMode = (TIM_MODE_OPT) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_ConfigStruct = (void*) strtoul((char *) arg_ptr, NULL, 16);

	TIM_ConfigStructInit(TimerCounterMode, TIM_ConfigStruct);
	return 0;
}

int _TIM_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_INT_TYPE IntFlag;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntFlag = (TIM_INT_TYPE) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) TIM_GetIntStatus(TIMx, IntFlag));
	writeUSBOutString(str);
	return 0;
}

int _TIM_Cmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	TIM_Cmd(TIMx, NewState);
	return 0;
}

int _TIM_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	TIM_DeInit(TIMx);
	return 0;
}

int _TIM_ResetCounter(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	TIM_ResetCounter(TIMx);
	return 0;
}

int _TIM_ConfigCapture(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_CAPTURECFG_Type* TIM_CaptureConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_CaptureConfigStruct = (TIM_CAPTURECFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	TIM_ConfigCapture(TIMx, TIM_CaptureConfigStruct);
	return 0;
}

int _TIM_GetCaptureValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_COUNTER_INPUT_OPT CaptureChannel;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	CaptureChannel = (TIM_COUNTER_INPUT_OPT) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) TIM_GetCaptureValue(TIMx, CaptureChannel));
	writeUSBOutString(str);
	return 0;
}

int _TIM_ClearIntPending(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_INT_TYPE IntFlag;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntFlag = (TIM_INT_TYPE) strtoul((char *) arg_ptr, NULL, 16);

	TIM_ClearIntPending(TIMx, IntFlag);
	return 0;
}

int _TIM_UpdateMatchValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	uint8_t MatchChannel;
	uint32_t MatchValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MatchChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MatchValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	TIM_UpdateMatchValue(TIMx, MatchChannel, MatchValue);
	return 0;
}

int _TIM_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* TIMx;
	TIM_MODE_OPT TimerCounterMode;
	void* TIM_ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIMx = (LPC_TIM_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TimerCounterMode = (TIM_MODE_OPT) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_ConfigStruct = (void*) strtoul((char *) arg_ptr, NULL, 16);

	TIM_Init(TIMx, TimerCounterMode, TIM_ConfigStruct);
	return 0;
}

int _TIM_EXTMATCH_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_EXTMATCH_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_MODE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_MODE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_CAP_MODE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_CAP_MODE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_CAPTURECFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_CAPTURECFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_CAPTURECFG_Type_CaptureChannel(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_CAPTURECFG_Type* TIM_CAPTURECFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_CAPTURECFG_Type_ptr = (TIM_CAPTURECFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_CAPTURECFG_Type_ptr->CaptureChannel);
		writeUSBOutString(str);
		return 0;
	}

	TIM_CAPTURECFG_Type_ptr->CaptureChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_CAPTURECFG_Type_RisingEdge(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_CAPTURECFG_Type* TIM_CAPTURECFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_CAPTURECFG_Type_ptr = (TIM_CAPTURECFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_CAPTURECFG_Type_ptr->RisingEdge);
		writeUSBOutString(str);
		return 0;
	}

	TIM_CAPTURECFG_Type_ptr->RisingEdge = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_CAPTURECFG_Type_FallingEdge(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_CAPTURECFG_Type* TIM_CAPTURECFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_CAPTURECFG_Type_ptr = (TIM_CAPTURECFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_CAPTURECFG_Type_ptr->FallingEdge);
		writeUSBOutString(str);
		return 0;
	}

	TIM_CAPTURECFG_Type_ptr->FallingEdge = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_CAPTURECFG_Type_IntOnCaption(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_CAPTURECFG_Type* TIM_CAPTURECFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_CAPTURECFG_Type_ptr = (TIM_CAPTURECFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_CAPTURECFG_Type_ptr->IntOnCaption);
		writeUSBOutString(str);
		return 0;
	}

	TIM_CAPTURECFG_Type_ptr->IntOnCaption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_INT_TYPE_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_INT_TYPE)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_COUNTER_INPUT_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_COUNTER_INPUT_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_MATCHCFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_MATCHCFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_MATCHCFG_Type_MatchChannel(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_MATCHCFG_Type* TIM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_MATCHCFG_Type_ptr = (TIM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_MATCHCFG_Type_ptr->MatchChannel);
		writeUSBOutString(str);
		return 0;
	}

	TIM_MATCHCFG_Type_ptr->MatchChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_MATCHCFG_Type_IntOnMatch(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_MATCHCFG_Type* TIM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_MATCHCFG_Type_ptr = (TIM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_MATCHCFG_Type_ptr->IntOnMatch);
		writeUSBOutString(str);
		return 0;
	}

	TIM_MATCHCFG_Type_ptr->IntOnMatch = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_MATCHCFG_Type_StopOnMatch(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_MATCHCFG_Type* TIM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_MATCHCFG_Type_ptr = (TIM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_MATCHCFG_Type_ptr->StopOnMatch);
		writeUSBOutString(str);
		return 0;
	}

	TIM_MATCHCFG_Type_ptr->StopOnMatch = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_MATCHCFG_Type_ResetOnMatch(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_MATCHCFG_Type* TIM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_MATCHCFG_Type_ptr = (TIM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_MATCHCFG_Type_ptr->ResetOnMatch);
		writeUSBOutString(str);
		return 0;
	}

	TIM_MATCHCFG_Type_ptr->ResetOnMatch = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_MATCHCFG_Type_ExtMatchOutputType(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_MATCHCFG_Type* TIM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_MATCHCFG_Type_ptr = (TIM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_MATCHCFG_Type_ptr->ExtMatchOutputType);
		writeUSBOutString(str);
		return 0;
	}

	TIM_MATCHCFG_Type_ptr->ExtMatchOutputType = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_MATCHCFG_Type_MatchValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_MATCHCFG_Type* TIM_MATCHCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_MATCHCFG_Type_ptr = (TIM_MATCHCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_MATCHCFG_Type_ptr->MatchValue);
		writeUSBOutString(str);
		return 0;
	}

	TIM_MATCHCFG_Type_ptr->MatchValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_COUNTERCFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_COUNTERCFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_COUNTERCFG_Type_CounterOption(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_COUNTERCFG_Type* TIM_COUNTERCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_COUNTERCFG_Type_ptr = (TIM_COUNTERCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_COUNTERCFG_Type_ptr->CounterOption);
		writeUSBOutString(str);
		return 0;
	}

	TIM_COUNTERCFG_Type_ptr->CounterOption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_COUNTERCFG_Type_CountInputSelect(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_COUNTERCFG_Type* TIM_COUNTERCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_COUNTERCFG_Type_ptr = (TIM_COUNTERCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_COUNTERCFG_Type_ptr->CountInputSelect);
		writeUSBOutString(str);
		return 0;
	}

	TIM_COUNTERCFG_Type_ptr->CountInputSelect = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_TIMERCFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_TIMERCFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _TIM_TIMERCFG_Type_PrescaleOption(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_TIMERCFG_Type* TIM_TIMERCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_TIMERCFG_Type_ptr = (TIM_TIMERCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_TIMERCFG_Type_ptr->PrescaleOption);
		writeUSBOutString(str);
		return 0;
	}

	TIM_TIMERCFG_Type_ptr->PrescaleOption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_TIMERCFG_Type_PrescaleValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	TIM_TIMERCFG_Type* TIM_TIMERCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TIM_TIMERCFG_Type_ptr = (TIM_TIMERCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TIM_TIMERCFG_Type_ptr->PrescaleValue);
		writeUSBOutString(str);
		return 0;
	}

	TIM_TIMERCFG_Type_ptr->PrescaleValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TIM_PRESCALE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TIM_PRESCALE_OPT)));
	writeUSBOutString(str);
	return 0;
}

