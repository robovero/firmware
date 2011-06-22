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

#include "lpc17xx_wdt.h"

#include "return.h"

int _WDT_Start(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t TimeOut;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TimeOut = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	WDT_Start(TimeOut);
	return 0;
}

int _WDT_ClrTimeOutFlag(uint8_t * args)
{
	WDT_ClrTimeOutFlag();
	return 0;
}

int _WDT_ReadTimeOutFlag(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) WDT_ReadTimeOutFlag());
	writeUSBOutString(str);
	return 0;
}

int _WDT_UpdateTimeOut(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t TimeOut;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TimeOut = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	WDT_UpdateTimeOut(TimeOut);
	return 0;
}

int _WDT_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	WDT_CLK_OPT ClkSrc;
	WDT_MODE_OPT WDTMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ClkSrc = (WDT_CLK_OPT) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	WDTMode = (WDT_MODE_OPT) strtoul((char *) arg_ptr, NULL, 16);

	WDT_Init(ClkSrc, WDTMode);
	return 0;
}

int _WDT_Feed(uint8_t * args)
{
	WDT_Feed();
	return 0;
}

int _WDT_GetCurrentCount(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) WDT_GetCurrentCount());
	writeUSBOutString(str);
	return 0;
}

int _WDT_MODE_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(WDT_MODE_OPT)));
	writeUSBOutString(str);
	return 0;
}

int _WDT_CLK_OPT_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(WDT_CLK_OPT)));
	writeUSBOutString(str);
	return 0;
}

