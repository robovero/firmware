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

#include "lpc17xx_rtc.h"

#include "return.h"

int _RTC_CntIncrIntConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t CntIncrIntType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	CntIncrIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	RTC_CntIncrIntConfig(RTCx, CntIncrIntType, NewState);
	return 0;
}

int _RTC_ClearIntPending(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t IntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	RTC_ClearIntPending(RTCx, IntType);
	return 0;
}

int _RTC_SetFullTime(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	RTC_TIME_Type* pFullTime;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pFullTime = (RTC_TIME_Type*) strtoul((char *) arg_ptr, NULL, 16);

	RTC_SetFullTime(RTCx, pFullTime);
	return 0;
}

int _RTC_SetAlarmTime(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t Timetype;
	uint32_t ALValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Timetype = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ALValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	RTC_SetAlarmTime(RTCx, Timetype, ALValue);
	return 0;
}

int _RTC_GetIntPending(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t IntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	IntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) RTC_GetIntPending(RTCx, IntType));
	writeUSBOutString(str);
	return 0;
}

int _RTC_SetTime(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t Timetype;
	uint32_t TimeValue;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Timetype = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TimeValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	RTC_SetTime(RTCx, Timetype, TimeValue);
	return 0;
}

int _RTC_GetFullAlarmTime(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	RTC_TIME_Type* pFullTime;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pFullTime = (RTC_TIME_Type*) strtoul((char *) arg_ptr, NULL, 16);

	RTC_GetFullAlarmTime(RTCx, pFullTime);
	return 0;
}

int _RTC_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	RTC_DeInit(RTCx);
	return 0;
}

int _RTC_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	RTC_Init(RTCx);
	return 0;
}

int _RTC_ReadGPREG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint8_t Channel;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Channel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) RTC_ReadGPREG(RTCx, Channel));
	writeUSBOutString(str);
	return 0;
}

int _RTC_GetAlarmTime(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t Timetype;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Timetype = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) RTC_GetAlarmTime(RTCx, Timetype));
	writeUSBOutString(str);
	return 0;
}

int _RTC_AlarmIntConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t AlarmTimeType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	AlarmTimeType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	RTC_AlarmIntConfig(RTCx, AlarmTimeType, NewState);
	return 0;
}

int _RTC_GetTime(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t Timetype;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Timetype = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) RTC_GetTime(RTCx, Timetype));
	writeUSBOutString(str);
	return 0;
}

int _RTC_CalibCounterCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	FunctionalState NewState;


	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	RTC_CalibCounterCmd(RTCx, NewState);
	return 0;
}

int _RTC_GetFullTime(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	RTC_TIME_Type* pFullTime;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pFullTime = (RTC_TIME_Type*) strtoul((char *) arg_ptr, NULL, 16);

	RTC_GetFullTime(RTCx, pFullTime);
	return 0;
}

int _RTC_CalibConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint32_t CalibValue;
	uint8_t CalibDir;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	CalibValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	CalibDir = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	RTC_CalibConfig(RTCx, CalibValue, CalibDir);
	return 0;
}

int _RTC_Cmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	RTC_Cmd(RTCx, NewState);
	return 0;
}

int _RTC_SetFullAlarmTime(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	RTC_TIME_Type* pFullTime;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pFullTime = (RTC_TIME_Type*) strtoul((char *) arg_ptr, NULL, 16);

	RTC_SetFullAlarmTime(RTCx, pFullTime);
	return 0;
}

int _RTC_WriteGPREG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;
	uint8_t Channel;
	uint32_t Value;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Channel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Value = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	RTC_WriteGPREG(RTCx, Channel, Value);
	return 0;
}

int _RTC_ResetClockTickCounter(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* RTCx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTCx = (LPC_RTC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	RTC_ResetClockTickCounter(RTCx);
	return 0;
}

int _RTC_INT_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(RTC_INT_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _RTC_TIME_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(RTC_TIME_Type)));
	writeUSBOutString(str);
	return 0;
}

int _RTC_TIME_Type_SEC(uint8_t * args)
{
	uint8_t * arg_ptr;
	RTC_TIME_Type* RTC_TIME_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTC_TIME_Type_ptr = (RTC_TIME_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RTC_TIME_Type_ptr->SEC);
		writeUSBOutString(str);
		return 0;
	}

	RTC_TIME_Type_ptr->SEC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RTC_TIME_Type_MIN(uint8_t * args)
{
	uint8_t * arg_ptr;
	RTC_TIME_Type* RTC_TIME_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTC_TIME_Type_ptr = (RTC_TIME_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RTC_TIME_Type_ptr->MIN);
		writeUSBOutString(str);
		return 0;
	}

	RTC_TIME_Type_ptr->MIN = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RTC_TIME_Type_HOUR(uint8_t * args)
{
	uint8_t * arg_ptr;
	RTC_TIME_Type* RTC_TIME_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTC_TIME_Type_ptr = (RTC_TIME_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RTC_TIME_Type_ptr->HOUR);
		writeUSBOutString(str);
		return 0;
	}

	RTC_TIME_Type_ptr->HOUR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RTC_TIME_Type_DOM(uint8_t * args)
{
	uint8_t * arg_ptr;
	RTC_TIME_Type* RTC_TIME_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTC_TIME_Type_ptr = (RTC_TIME_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RTC_TIME_Type_ptr->DOM);
		writeUSBOutString(str);
		return 0;
	}

	RTC_TIME_Type_ptr->DOM = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RTC_TIME_Type_DOW(uint8_t * args)
{
	uint8_t * arg_ptr;
	RTC_TIME_Type* RTC_TIME_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTC_TIME_Type_ptr = (RTC_TIME_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RTC_TIME_Type_ptr->DOW);
		writeUSBOutString(str);
		return 0;
	}

	RTC_TIME_Type_ptr->DOW = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RTC_TIME_Type_DOY(uint8_t * args)
{
	uint8_t * arg_ptr;
	RTC_TIME_Type* RTC_TIME_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTC_TIME_Type_ptr = (RTC_TIME_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RTC_TIME_Type_ptr->DOY);
		writeUSBOutString(str);
		return 0;
	}

	RTC_TIME_Type_ptr->DOY = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RTC_TIME_Type_MONTH(uint8_t * args)
{
	uint8_t * arg_ptr;
	RTC_TIME_Type* RTC_TIME_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTC_TIME_Type_ptr = (RTC_TIME_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RTC_TIME_Type_ptr->MONTH);
		writeUSBOutString(str);
		return 0;
	}

	RTC_TIME_Type_ptr->MONTH = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RTC_TIME_Type_YEAR(uint8_t * args)
{
	uint8_t * arg_ptr;
	RTC_TIME_Type* RTC_TIME_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RTC_TIME_Type_ptr = (RTC_TIME_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RTC_TIME_Type_ptr->YEAR);
		writeUSBOutString(str);
		return 0;
	}

	RTC_TIME_Type_ptr->YEAR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RTC_TIMETYPE_Num_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(RTC_TIMETYPE_Num)));
	writeUSBOutString(str);
	return 0;
}

