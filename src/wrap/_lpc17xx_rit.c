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

#include "lpc17xx_rit.h"

#include "return.h"

int _RIT_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* RITx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RITx = (LPC_RIT_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	RIT_DeInit(RITx);
	return 0;
}

int _RIT_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* RITx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RITx = (LPC_RIT_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	RIT_Init(RITx);
	return 0;
}

int _RIT_Cmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* RITx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RITx = (LPC_RIT_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	RIT_Cmd(RITx, NewState);
	return 0;
}

int _RIT_GetIntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* RITx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RITx = (LPC_RIT_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) RIT_GetIntStatus(RITx));
	writeUSBOutString(str);
	return 0;
}

int _RIT_TimerConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* RITx;
	uint32_t time_interval;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RITx = (LPC_RIT_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	time_interval = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	RIT_TimerConfig(RITx, time_interval);
	return 0;
}

int _RIT_TimerClearCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* RITx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RITx = (LPC_RIT_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	RIT_TimerClearCmd(RITx, NewState);
	return 0;
}

int _RIT_TimerDebugCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* RITx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RITx = (LPC_RIT_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	RIT_TimerDebugCmd(RITx, NewState);
	return 0;
}

