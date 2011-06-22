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

#include "lpc17xx_clkpwr.h"

#include "return.h"

int _CLKPWR_SetPCLKDiv(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ClkType;
	uint32_t DivVal;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ClkType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	DivVal = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	CLKPWR_SetPCLKDiv(ClkType, DivVal);
	return 0;
}

int _CLKPWR_Sleep(uint8_t * args)
{
	CLKPWR_Sleep();
	return 0;
}

int _CLKPWR_DeepSleep(uint8_t * args)
{
	CLKPWR_DeepSleep();
	return 0;
}

int _CLKPWR_PowerDown(uint8_t * args)
{
	CLKPWR_PowerDown();
	return 0;
}

int _CLKPWR_GetPCLK(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ClkType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ClkType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) CLKPWR_GetPCLK(ClkType));
	writeUSBOutString(str);
	return 0;
}

int _CLKPWR_ConfigPPWR(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t PPType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PPType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	CLKPWR_ConfigPPWR(PPType, NewState);
	return 0;
}

int _CLKPWR_GetPCLKSEL(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ClkType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ClkType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) CLKPWR_GetPCLKSEL(ClkType));
	writeUSBOutString(str);
	return 0;
}

int _CLKPWR_DeepPowerDown(uint8_t * args)
{
	CLKPWR_DeepPowerDown();
	return 0;
}

