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

#include "lpc17xx_qei.h"

#include "return.h"

int _QEI_GetTimer(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) QEI_GetTimer(QEIx));
	writeUSBOutString(str);
	return 0;
}

int _QEI_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	QEI_DeInit(QEIx);
	return 0;
}

int _QEI_GetPosition(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) QEI_GetPosition(QEIx));
	writeUSBOutString(str);
	return 0;
}

int _QEI_GetStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulFlagType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulFlagType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) QEI_GetStatus(QEIx, ulFlagType));
	writeUSBOutString(str);
	return 0;
}

int _QEI_Reset(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulResetType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulResetType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	QEI_Reset(QEIx, ulResetType);
	return 0;
}

int _QEI_SetMaxPosition(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulMaxPos;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulMaxPos = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	QEI_SetMaxPosition(QEIx, ulMaxPos);
	return 0;
}

int _QEI_GetVelocity(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) QEI_GetVelocity(QEIx));
	writeUSBOutString(str);
	return 0;
}

int _QEI_GetVelocityCap(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) QEI_GetVelocityCap(QEIx));
	writeUSBOutString(str);
	return 0;
}

int _QEI_SetPositionComp(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint8_t bPosCompCh;
	uint32_t ulPosComp;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bPosCompCh = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulPosComp = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	QEI_SetPositionComp(QEIx, bPosCompCh, ulPosComp);
	return 0;
}

int _QEI_SetDigiFilter(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulSamplingPulse;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulSamplingPulse = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	QEI_SetDigiFilter(QEIx, ulSamplingPulse);
	return 0;
}

int _QEI_IntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	QEI_IntSet(QEIx, ulIntType);
	return 0;
}

int _QEI_GetIndex(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) QEI_GetIndex(QEIx));
	writeUSBOutString(str);
	return 0;
}

int _QEI_SetTimerReload(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	QEI_RELOADCFG_Type* QEIReloadStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIReloadStruct = (QEI_RELOADCFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	QEI_SetTimerReload(QEIx, QEIReloadStruct);
	return 0;
}

int _QEI_ConfigStructInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	QEI_CFG_Type* QIE_InitStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QIE_InitStruct = (QEI_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	QEI_ConfigStructInit(QIE_InitStruct);
	return 0;
}

int _QEI_SetVelocityComp(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulVelComp;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulVelComp = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	QEI_SetVelocityComp(QEIx, ulVelComp);
	return 0;
}

int _QEI_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	QEI_CFG_Type* QEI_ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEI_ConfigStruct = (QEI_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	QEI_Init(QEIx, QEI_ConfigStruct);
	return 0;
}

int _QEI_IntCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulIntType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	QEI_IntCmd(QEIx, ulIntType, NewState);
	return 0;
}

int _QEI_IntClear(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	QEI_IntClear(QEIx, ulIntType);
	return 0;
}

int _QEI_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) QEI_GetIntStatus(QEIx, ulIntType));
	writeUSBOutString(str);
	return 0;
}

int _QEI_CalculateRPM(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulVelCapValue;
	uint32_t ulPPR;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulVelCapValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulPPR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) QEI_CalculateRPM(QEIx, ulVelCapValue, ulPPR));
	writeUSBOutString(str);
	return 0;
}

int _QEI_SetIndexComp(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* QEIx;
	uint32_t ulIndexComp;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEIx = (LPC_QEI_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIndexComp = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	QEI_SetIndexComp(QEIx, ulIndexComp);
	return 0;
}

int _QEI_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(QEI_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _QEI_CFG_Type_DirectionInvert(uint8_t * args)
{
	uint8_t * arg_ptr;
	QEI_CFG_Type* QEI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEI_CFG_Type_ptr = (QEI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) QEI_CFG_Type_ptr->DirectionInvert);
		writeUSBOutString(str);
		return 0;
	}

	QEI_CFG_Type_ptr->DirectionInvert = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _QEI_CFG_Type_SignalMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	QEI_CFG_Type* QEI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEI_CFG_Type_ptr = (QEI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) QEI_CFG_Type_ptr->SignalMode);
		writeUSBOutString(str);
		return 0;
	}

	QEI_CFG_Type_ptr->SignalMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _QEI_CFG_Type_CaptureMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	QEI_CFG_Type* QEI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEI_CFG_Type_ptr = (QEI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) QEI_CFG_Type_ptr->CaptureMode);
		writeUSBOutString(str);
		return 0;
	}

	QEI_CFG_Type_ptr->CaptureMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _QEI_CFG_Type_InvertIndex(uint8_t * args)
{
	uint8_t * arg_ptr;
	QEI_CFG_Type* QEI_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEI_CFG_Type_ptr = (QEI_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) QEI_CFG_Type_ptr->InvertIndex);
		writeUSBOutString(str);
		return 0;
	}

	QEI_CFG_Type_ptr->InvertIndex = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _QEI_RELOADCFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(QEI_RELOADCFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _QEI_RELOADCFG_Type_ReloadOption(uint8_t * args)
{
	uint8_t * arg_ptr;
	QEI_RELOADCFG_Type* QEI_RELOADCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEI_RELOADCFG_Type_ptr = (QEI_RELOADCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) QEI_RELOADCFG_Type_ptr->ReloadOption);
		writeUSBOutString(str);
		return 0;
	}

	QEI_RELOADCFG_Type_ptr->ReloadOption = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _QEI_RELOADCFG_Type_ReloadValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	QEI_RELOADCFG_Type* QEI_RELOADCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	QEI_RELOADCFG_Type_ptr = (QEI_RELOADCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) QEI_RELOADCFG_Type_ptr->ReloadValue);
		writeUSBOutString(str);
		return 0;
	}

	QEI_RELOADCFG_Type_ptr->ReloadValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

