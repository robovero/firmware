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

#include "lpc17xx_i2s.h"

#include "return.h"

int _I2S_GetLevel(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2S_GetLevel(I2Sx, TRMode));
	writeUSBOutString(str);
	return 0;
}

int _I2S_GetIRQDepth(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2S_GetIRQDepth(I2Sx, TRMode));
	writeUSBOutString(str);
	return 0;
}

int _I2S_Mute(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	I2S_Mute(I2Sx, TRMode);
	return 0;
}

int _I2S_Start(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	I2S_Start(I2Sx);
	return 0;
}

int _I2S_Pause(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	I2S_Pause(I2Sx, TRMode);
	return 0;
}

int _I2S_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	I2S_Init(I2Sx);
	return 0;
}

int _I2S_SetBitRate(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t bitrate;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bitrate = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	I2S_SetBitRate(I2Sx, bitrate, TRMode);
	return 0;
}

int _I2S_FreqConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint32_t Freq;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Freq = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2S_FreqConfig(I2Sx, Freq, TRMode));
	writeUSBOutString(str);
	return 0;
}

int _I2S_DMACmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t DMAIndex;
	uint8_t TRMode;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DMAIndex = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	I2S_DMACmd(I2Sx, DMAIndex, TRMode, NewState);
	return 0;
}

int _I2S_Send(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint32_t BufferData;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	BufferData = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	I2S_Send(I2Sx, BufferData);
	return 0;
}

int _I2S_Receive(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2S_Receive(I2Sx));
	writeUSBOutString(str);
	return 0;
}

int _I2S_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	I2S_DeInit(I2Sx);
	return 0;
}

int _I2S_Config(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;
	I2S_CFG_Type* ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ConfigStruct = (I2S_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	I2S_Config(I2Sx, TRMode, ConfigStruct);
	return 0;
}

int _I2S_IRQCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	I2S_IRQCmd(I2Sx, TRMode, NewState);
	return 0;
}

int _I2S_IRQConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;
	uint8_t level;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	level = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	I2S_IRQConfig(I2Sx, TRMode, level);
	return 0;
}

int _I2S_Stop(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	I2S_Stop(I2Sx, TRMode);
	return 0;
}

int _I2S_DMAConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	I2S_DMAConf_Type* DMAConfig;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DMAConfig = (I2S_DMAConf_Type*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	I2S_DMAConfig(I2Sx, DMAConfig, TRMode);
	return 0;
}

int _I2S_ModeConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	I2S_MODEConf_Type* ModeConfig;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ModeConfig = (I2S_MODEConf_Type*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	I2S_ModeConfig(I2Sx, ModeConfig, TRMode);
	return 0;
}

int _I2S_GetIRQStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* I2Sx;
	uint8_t TRMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Sx = (LPC_I2S_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TRMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2S_GetIRQStatus(I2Sx, TRMode));
	writeUSBOutString(str);
	return 0;
}

int _I2S_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(I2S_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _I2S_CFG_Type_wordwidth(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_CFG_Type* I2S_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_CFG_Type_ptr = (I2S_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_CFG_Type_ptr->wordwidth);
		writeUSBOutString(str);
		return 0;
	}

	I2S_CFG_Type_ptr->wordwidth = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_CFG_Type_mono(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_CFG_Type* I2S_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_CFG_Type_ptr = (I2S_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_CFG_Type_ptr->mono);
		writeUSBOutString(str);
		return 0;
	}

	I2S_CFG_Type_ptr->mono = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_CFG_Type_stop(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_CFG_Type* I2S_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_CFG_Type_ptr = (I2S_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_CFG_Type_ptr->stop);
		writeUSBOutString(str);
		return 0;
	}

	I2S_CFG_Type_ptr->stop = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_CFG_Type_reset(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_CFG_Type* I2S_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_CFG_Type_ptr = (I2S_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_CFG_Type_ptr->reset);
		writeUSBOutString(str);
		return 0;
	}

	I2S_CFG_Type_ptr->reset = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_CFG_Type_ws_sel(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_CFG_Type* I2S_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_CFG_Type_ptr = (I2S_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_CFG_Type_ptr->ws_sel);
		writeUSBOutString(str);
		return 0;
	}

	I2S_CFG_Type_ptr->ws_sel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_CFG_Type_mute(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_CFG_Type* I2S_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_CFG_Type_ptr = (I2S_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_CFG_Type_ptr->mute);
		writeUSBOutString(str);
		return 0;
	}

	I2S_CFG_Type_ptr->mute = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_DMAConf_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(I2S_DMAConf_Type)));
	writeUSBOutString(str);
	return 0;
}

int _I2S_DMAConf_Type_DMAIndex(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_DMAConf_Type* I2S_DMAConf_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_DMAConf_Type_ptr = (I2S_DMAConf_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_DMAConf_Type_ptr->DMAIndex);
		writeUSBOutString(str);
		return 0;
	}

	I2S_DMAConf_Type_ptr->DMAIndex = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_DMAConf_Type_depth(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_DMAConf_Type* I2S_DMAConf_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_DMAConf_Type_ptr = (I2S_DMAConf_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_DMAConf_Type_ptr->depth);
		writeUSBOutString(str);
		return 0;
	}

	I2S_DMAConf_Type_ptr->depth = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_MODEConf_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(I2S_MODEConf_Type)));
	writeUSBOutString(str);
	return 0;
}

int _I2S_MODEConf_Type_clksel(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_MODEConf_Type* I2S_MODEConf_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_MODEConf_Type_ptr = (I2S_MODEConf_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_MODEConf_Type_ptr->clksel);
		writeUSBOutString(str);
		return 0;
	}

	I2S_MODEConf_Type_ptr->clksel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_MODEConf_Type_fpin(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_MODEConf_Type* I2S_MODEConf_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_MODEConf_Type_ptr = (I2S_MODEConf_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_MODEConf_Type_ptr->fpin);
		writeUSBOutString(str);
		return 0;
	}

	I2S_MODEConf_Type_ptr->fpin = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2S_MODEConf_Type_mcena(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2S_MODEConf_Type* I2S_MODEConf_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2S_MODEConf_Type_ptr = (I2S_MODEConf_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2S_MODEConf_Type_ptr->mcena);
		writeUSBOutString(str);
		return 0;
	}

	I2S_MODEConf_Type_ptr->mcena = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

