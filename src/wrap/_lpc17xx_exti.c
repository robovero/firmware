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

#include "lpc17xx_exti.h"

#include "return.h"

int _EXTI_Init(uint8_t * args)
{
	EXTI_Init();
	return 0;
}

int _EXTI_ClearEXTIFlag(uint8_t * args)
{
	uint8_t * arg_ptr;
	EXTI_LINE_ENUM EXTILine;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EXTILine = (EXTI_LINE_ENUM) strtoul((char *) arg_ptr, NULL, 16);

	EXTI_ClearEXTIFlag(EXTILine);
	return 0;
}

int _EXTI_Config(uint8_t * args)
{
	uint8_t * arg_ptr;
	EXTI_InitTypeDef* EXTICfg;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EXTICfg = (EXTI_InitTypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	EXTI_Config(EXTICfg);
	return 0;
}

int _EXTI_SetMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	EXTI_LINE_ENUM EXTILine;
	EXTI_MODE_ENUM mode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EXTILine = (EXTI_LINE_ENUM) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	mode = (EXTI_MODE_ENUM) strtoul((char *) arg_ptr, NULL, 16);

	EXTI_SetMode(EXTILine, mode);
	return 0;
}

int _EXTI_DeInit(uint8_t * args)
{
	EXTI_DeInit();
	return 0;
}

int _EXTI_SetPolarity(uint8_t * args)
{
	uint8_t * arg_ptr;
	EXTI_LINE_ENUM EXTILine;
	EXTI_POLARITY_ENUM polarity;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EXTILine = (EXTI_LINE_ENUM) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	polarity = (EXTI_POLARITY_ENUM) strtoul((char *) arg_ptr, NULL, 16);

	EXTI_SetPolarity(EXTILine, polarity);
	return 0;
}

int _EXTI_MODE_ENUM_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(EXTI_MODE_ENUM)));
	writeUSBOutString(str);
	return 0;
}

int _EXTI_InitTypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(EXTI_InitTypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _EXTI_InitTypeDef_EXTI_Line(uint8_t * args)
{
	uint8_t * arg_ptr;
	EXTI_InitTypeDef* EXTI_InitTypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EXTI_InitTypeDef_ptr = (EXTI_InitTypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) EXTI_InitTypeDef_ptr->EXTI_Line);
		writeUSBOutString(str);
		return 0;
	}

	EXTI_InitTypeDef_ptr->EXTI_Line = (EXTI_LINE_ENUM) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _EXTI_InitTypeDef_EXTI_Mode(uint8_t * args)
{
	uint8_t * arg_ptr;
	EXTI_InitTypeDef* EXTI_InitTypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EXTI_InitTypeDef_ptr = (EXTI_InitTypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) EXTI_InitTypeDef_ptr->EXTI_Mode);
		writeUSBOutString(str);
		return 0;
	}

	EXTI_InitTypeDef_ptr->EXTI_Mode = (EXTI_MODE_ENUM) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _EXTI_InitTypeDef_EXTI_polarity(uint8_t * args)
{
	uint8_t * arg_ptr;
	EXTI_InitTypeDef* EXTI_InitTypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EXTI_InitTypeDef_ptr = (EXTI_InitTypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) EXTI_InitTypeDef_ptr->EXTI_polarity);
		writeUSBOutString(str);
		return 0;
	}

	EXTI_InitTypeDef_ptr->EXTI_polarity = (EXTI_POLARITY_ENUM) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _EXTI_POLARITY_ENUM_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(EXTI_POLARITY_ENUM)));
	writeUSBOutString(str);
	return 0;
}

int _EXTI_LINE_ENUM_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(EXTI_LINE_ENUM)));
	writeUSBOutString(str);
	return 0;
}

