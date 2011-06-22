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

#include "debug_frmwrk.h"

#include "return.h"

int _UARTPutDec32(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint32_t decnum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	decnum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	UARTPutDec32(UARTx, decnum);
	return 0;
}

int _debug_frmwrk_init(uint8_t * args)
{
	debug_frmwrk_init();
	return 0;
}

int _UARTPutChar(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint8_t ch;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ch = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	UARTPutChar(UARTx, ch);
	return 0;
}

int _UARTPutHex(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint8_t hexnum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	hexnum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	UARTPutHex(UARTx, hexnum);
	return 0;
}

int _UARTGetChar(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UARTGetChar(UARTx));
	writeUSBOutString(str);
	return 0;
}

int _UARTPuts_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	void* str;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	str = (void*) strtoul((char *) arg_ptr, NULL, 16);

	UARTPuts_(UARTx, str);
	return 0;
}

int _UARTPutDec(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint8_t decnum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	decnum = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	UARTPutDec(UARTx, decnum);
	return 0;
}

int _UARTPutDec16(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint16_t decnum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	decnum = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

	UARTPutDec16(UARTx, decnum);
	return 0;
}

int _UARTPuts(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	void* str;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	str = (void*) strtoul((char *) arg_ptr, NULL, 16);

	UARTPuts(UARTx, str);
	return 0;
}

int _UARTPutHex16(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint16_t hexnum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	hexnum = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

	UARTPutHex16(UARTx, hexnum);
	return 0;
}

int _UARTPutHex32(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint32_t hexnum;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	hexnum = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	UARTPutHex32(UARTx, hexnum);
	return 0;
}

