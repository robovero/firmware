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

#include "lpc17xx_dac.h"

#include "return.h"

int _DAC_SetBias(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_DAC_TypeDef* DACx;
	uint32_t bias;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DACx = (LPC_DAC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	bias = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	DAC_SetBias(DACx, bias);
	return 0;
}

int _DAC_ConfigDAConverterControl(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_DAC_TypeDef* DACx;
	DAC_CONVERTER_CFG_Type* DAC_ConverterConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DACx = (LPC_DAC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DAC_ConverterConfigStruct = (DAC_CONVERTER_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	DAC_ConfigDAConverterControl(DACx, DAC_ConverterConfigStruct);
	return 0;
}

int _DAC_UpdateValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_DAC_TypeDef* DACx;
	uint32_t dac_value;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DACx = (LPC_DAC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dac_value = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	DAC_UpdateValue(DACx, dac_value);
	return 0;
}

int _DAC_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_DAC_TypeDef* DACx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DACx = (LPC_DAC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	DAC_Init(DACx);
	return 0;
}

int _DAC_SetDMATimeOut(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_DAC_TypeDef* DACx;
	uint32_t time_out;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DACx = (LPC_DAC_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	time_out = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	DAC_SetDMATimeOut(DACx, time_out);
	return 0;
}

int _DAC_CONVERTER_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(DAC_CONVERTER_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _DAC_CONVERTER_CFG_Type_DBLBUF_ENA(uint8_t * args)
{
	uint8_t * arg_ptr;
	DAC_CONVERTER_CFG_Type* DAC_CONVERTER_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DAC_CONVERTER_CFG_Type_ptr = (DAC_CONVERTER_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) DAC_CONVERTER_CFG_Type_ptr->DBLBUF_ENA);
		writeUSBOutString(str);
		return 0;
	}

	DAC_CONVERTER_CFG_Type_ptr->DBLBUF_ENA = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _DAC_CONVERTER_CFG_Type_CNT_ENA(uint8_t * args)
{
	uint8_t * arg_ptr;
	DAC_CONVERTER_CFG_Type* DAC_CONVERTER_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DAC_CONVERTER_CFG_Type_ptr = (DAC_CONVERTER_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) DAC_CONVERTER_CFG_Type_ptr->CNT_ENA);
		writeUSBOutString(str);
		return 0;
	}

	DAC_CONVERTER_CFG_Type_ptr->CNT_ENA = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _DAC_CONVERTER_CFG_Type_DMA_ENA(uint8_t * args)
{
	uint8_t * arg_ptr;
	DAC_CONVERTER_CFG_Type* DAC_CONVERTER_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DAC_CONVERTER_CFG_Type_ptr = (DAC_CONVERTER_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) DAC_CONVERTER_CFG_Type_ptr->DMA_ENA);
		writeUSBOutString(str);
		return 0;
	}

	DAC_CONVERTER_CFG_Type_ptr->DMA_ENA = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _DAC_CURRENT_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(DAC_CURRENT_OPT)));
	writeUSBOutString(str);
	return 0;
}

