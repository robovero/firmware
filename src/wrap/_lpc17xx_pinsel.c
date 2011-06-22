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

#include "lpc17xx_pinsel.h"

#include "return.h"

int _PINSEL_SetI2C0Pins(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t i2cPinMode;
	FunctionalState filterSlewRateEnable;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i2cPinMode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	filterSlewRateEnable = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	PINSEL_SetI2C0Pins(i2cPinMode, filterSlewRateEnable);
	return 0;
}

int _PINSEL_ConfigPin(uint8_t * args)
{
	uint8_t * arg_ptr;
	PINSEL_CFG_Type* PinCfg;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PinCfg = (PINSEL_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	PINSEL_ConfigPin(PinCfg);
	return 0;
}

int _PINSEL_ConfigTraceFunc(uint8_t * args)
{
	uint8_t * arg_ptr;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	PINSEL_ConfigTraceFunc(NewState);
	return 0;
}

int _PINSEL_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(PINSEL_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _PINSEL_CFG_Type_Portnum(uint8_t * args)
{
	uint8_t * arg_ptr;
	PINSEL_CFG_Type* PINSEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PINSEL_CFG_Type_ptr = (PINSEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PINSEL_CFG_Type_ptr->Portnum);
		writeUSBOutString(str);
		return 0;
	}

	PINSEL_CFG_Type_ptr->Portnum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PINSEL_CFG_Type_Pinnum(uint8_t * args)
{
	uint8_t * arg_ptr;
	PINSEL_CFG_Type* PINSEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PINSEL_CFG_Type_ptr = (PINSEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PINSEL_CFG_Type_ptr->Pinnum);
		writeUSBOutString(str);
		return 0;
	}

	PINSEL_CFG_Type_ptr->Pinnum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PINSEL_CFG_Type_Funcnum(uint8_t * args)
{
	uint8_t * arg_ptr;
	PINSEL_CFG_Type* PINSEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PINSEL_CFG_Type_ptr = (PINSEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PINSEL_CFG_Type_ptr->Funcnum);
		writeUSBOutString(str);
		return 0;
	}

	PINSEL_CFG_Type_ptr->Funcnum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PINSEL_CFG_Type_Pinmode(uint8_t * args)
{
	uint8_t * arg_ptr;
	PINSEL_CFG_Type* PINSEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PINSEL_CFG_Type_ptr = (PINSEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PINSEL_CFG_Type_ptr->Pinmode);
		writeUSBOutString(str);
		return 0;
	}

	PINSEL_CFG_Type_ptr->Pinmode = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _PINSEL_CFG_Type_OpenDrain(uint8_t * args)
{
	uint8_t * arg_ptr;
	PINSEL_CFG_Type* PINSEL_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PINSEL_CFG_Type_ptr = (PINSEL_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) PINSEL_CFG_Type_ptr->OpenDrain);
		writeUSBOutString(str);
		return 0;
	}

	PINSEL_CFG_Type_ptr->OpenDrain = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

