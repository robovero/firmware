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

#include "LPC17xx.h"

#include "return.h"

int _LPC_UART0_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_UART0_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART0_TypeDef_RBR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->RBR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART0_TypeDef_THR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_UART0_TypeDef_ptr->THR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_DLL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->DLL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->DLL = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_DLM(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->DLM);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->DLM = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_IER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->IER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->IER = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_IIR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->IIR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART0_TypeDef_FCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_UART0_TypeDef_ptr->FCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_LCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->LCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->LCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_LSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->LSR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART0_TypeDef_SCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->SCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->SCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_ACR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->ACR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->ACR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_ICR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->ICR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->ICR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_FDR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->FDR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->FDR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_TER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->TER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART0_TypeDef_ptr->TER = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART0_TypeDef_FIFOLVL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART0_TypeDef* LPC_UART0_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART0_TypeDef_ptr = (LPC_UART0_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART0_TypeDef_ptr->FIFOLVL);
	writeUSBOutString(str);
	return 0;
}

int _LPC_CANCR_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_CANCR_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_CANCR_TypeDef_CANTxSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANCR_TypeDef* LPC_CANCR_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANCR_TypeDef_ptr = (LPC_CANCR_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANCR_TypeDef_ptr->CANTxSR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_CANCR_TypeDef_CANRxSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANCR_TypeDef* LPC_CANCR_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANCR_TypeDef_ptr = (LPC_CANCR_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANCR_TypeDef_ptr->CANRxSR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_CANCR_TypeDef_CANMSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANCR_TypeDef* LPC_CANCR_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANCR_TypeDef_ptr = (LPC_CANCR_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANCR_TypeDef_ptr->CANMSR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPIO_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_GPIO_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPIO_TypeDef_FIODIR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->FIODIR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr->FIODIR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

/*int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _LPC_GPIO_TypeDef_FIOMASK(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->FIOMASK);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr->FIOMASK = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

/*int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _LPC_GPIO_TypeDef_FIOPIN(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->FIOPIN);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr->FIOPIN = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

/*int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _LPC_GPIO_TypeDef_FIOSET(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->FIOSET);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr->FIOSET = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

/*int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _LPC_GPIO_TypeDef_FIOCLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_GPIO_TypeDef_ptr->FIOCLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

/*int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIO_TypeDef_(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIO_TypeDef* LPC_GPIO_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIO_TypeDef_ptr = (LPC_GPIO_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIO_TypeDef_ptr->);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIO_TypeDef_ptr-> = (struct) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _LPC_PINCON_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_PINCON_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL4(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL4);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL4 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL5(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL5);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL5 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL6(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL6);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL6 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL7(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL7);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL7 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL8(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL8);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL8 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL9(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL9);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL9 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINSEL10(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINSEL10);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINSEL10 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE4(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE4);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE4 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE5(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE5);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE5 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE6(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE6);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE6 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE7(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE7);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE7 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE8(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE8);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE8 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE9(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE9);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE9 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE_OD0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE_OD0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE_OD0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE_OD1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE_OD1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE_OD1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE_OD2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE_OD2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE_OD2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE_OD3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE_OD3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE_OD3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_PINMODE_OD4(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->PINMODE_OD4);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->PINMODE_OD4 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PINCON_TypeDef_I2CPADCFG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PINCON_TypeDef* LPC_PINCON_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PINCON_TypeDef_ptr = (LPC_PINCON_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PINCON_TypeDef_ptr->I2CPADCFG);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PINCON_TypeDef_ptr->I2CPADCFG = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_I2C_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_I2C_TypeDef_I2CONSET(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2CONSET);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2CONSET = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2STAT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2STAT);
	writeUSBOutString(str);
	return 0;
}

int _LPC_I2C_TypeDef_I2DAT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2DAT);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2DAT = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2ADR0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2ADR0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2ADR0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2SCLH(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2SCLH);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2SCLH = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2SCLL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2SCLL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2SCLL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2CONCLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_I2C_TypeDef_ptr->I2CONCLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_MMCTRL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->MMCTRL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->MMCTRL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2ADR1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2ADR1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2ADR1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2ADR2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2ADR2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2ADR2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2ADR3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2ADR3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2ADR3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2DATA_BUFFER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2DATA_BUFFER);
	writeUSBOutString(str);
	return 0;
}

int _LPC_I2C_TypeDef_I2MASK0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2MASK0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2MASK0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2MASK1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2MASK1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2MASK1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2MASK2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2MASK2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2MASK2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2C_TypeDef_I2MASK3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* LPC_I2C_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2C_TypeDef_ptr = (LPC_I2C_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2C_TypeDef_ptr->I2MASK3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2C_TypeDef_ptr->I2MASK3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_WDT_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_WDT_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_WDT_TypeDef_WDMOD(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_WDT_TypeDef* LPC_WDT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_WDT_TypeDef_ptr = (LPC_WDT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_WDT_TypeDef_ptr->WDMOD);
		writeUSBOutString(str);
		return 0;
	}

	LPC_WDT_TypeDef_ptr->WDMOD = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_WDT_TypeDef_WDTC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_WDT_TypeDef* LPC_WDT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_WDT_TypeDef_ptr = (LPC_WDT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_WDT_TypeDef_ptr->WDTC);
		writeUSBOutString(str);
		return 0;
	}

	LPC_WDT_TypeDef_ptr->WDTC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_WDT_TypeDef_WDFEED(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_WDT_TypeDef* LPC_WDT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_WDT_TypeDef_ptr = (LPC_WDT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_WDT_TypeDef_ptr->WDFEED = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_WDT_TypeDef_WDTV(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_WDT_TypeDef* LPC_WDT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_WDT_TypeDef_ptr = (LPC_WDT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_WDT_TypeDef_ptr->WDTV);
	writeUSBOutString(str);
	return 0;
}

int _LPC_WDT_TypeDef_WDCLKSEL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_WDT_TypeDef* LPC_WDT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_WDT_TypeDef_ptr = (LPC_WDT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_WDT_TypeDef_ptr->WDCLKSEL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_WDT_TypeDef_ptr->WDCLKSEL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_UART_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART_TypeDef_RBR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->RBR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART_TypeDef_THR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_UART_TypeDef_ptr->THR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_DLL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->DLL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->DLL = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_DLM(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->DLM);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->DLM = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_IER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->IER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->IER = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_IIR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->IIR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART_TypeDef_FCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_UART_TypeDef_ptr->FCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_LCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->LCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->LCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_LSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->LSR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART_TypeDef_SCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->SCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->SCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_ACR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->ACR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->ACR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_ICR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->ICR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->ICR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_FDR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->FDR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->FDR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_TER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->TER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART_TypeDef_ptr->TER = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART_TypeDef_FIFOLVL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* LPC_UART_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART_TypeDef_ptr = (LPC_UART_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART_TypeDef_ptr->FIFOLVL);
	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_QEI_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_QEICON(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_QEI_TypeDef_ptr->QEICON = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_QEISTAT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEISTAT);
	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_QEICONF(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEICONF);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->QEICONF = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_QEIPOS(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEIPOS);
	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_QEIMAXPOS(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEIMAXPOS);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->QEIMAXPOS = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_CMPOS0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->CMPOS0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->CMPOS0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_CMPOS1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->CMPOS1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->CMPOS1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_CMPOS2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->CMPOS2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->CMPOS2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_INXCNT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->INXCNT);
	writeUSBOutString(str);
	return 0;

}

int _LPC_QEI_TypeDef_INXCMP(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->INXCMP);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->INXCMP = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_QEILOAD(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEILOAD);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->QEILOAD = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_QEITIME(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEITIME);
	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_QEIVEL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEIVEL);

	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_QEICAP(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEICAP);
	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_VELCOMP(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->VELCOMP);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->VELCOMP = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_FILTER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->FILTER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_QEI_TypeDef_ptr->FILTER = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_QEIIEC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_QEI_TypeDef_ptr->QEIIEC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_QEIIES(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_QEI_TypeDef_ptr->QEIIES = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_QEIINTSTAT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEIINTSTAT);
	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_QEIIE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_QEI_TypeDef_ptr->QEIIE);
	writeUSBOutString(str);
	return 0;
}

int _LPC_QEI_TypeDef_QEICLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_QEI_TypeDef_ptr->QEICLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_QEI_TypeDef_QEISET(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_QEI_TypeDef* LPC_QEI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_QEI_TypeDef_ptr = (LPC_QEI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_QEI_TypeDef_ptr->QEISET = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SPI_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_SPI_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_SPI_TypeDef_SPCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* LPC_SPI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SPI_TypeDef_ptr = (LPC_SPI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SPI_TypeDef_ptr->SPCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SPI_TypeDef_ptr->SPCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SPI_TypeDef_SPSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* LPC_SPI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SPI_TypeDef_ptr = (LPC_SPI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SPI_TypeDef_ptr->SPSR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_SPI_TypeDef_SPDR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* LPC_SPI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SPI_TypeDef_ptr = (LPC_SPI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SPI_TypeDef_ptr->SPDR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SPI_TypeDef_ptr->SPDR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SPI_TypeDef_SPCCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* LPC_SPI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SPI_TypeDef_ptr = (LPC_SPI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SPI_TypeDef_ptr->SPCCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SPI_TypeDef_ptr->SPCCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SPI_TypeDef_SPINT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SPI_TypeDef* LPC_SPI_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SPI_TypeDef_ptr = (LPC_SPI_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SPI_TypeDef_ptr->SPINT);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SPI_TypeDef_ptr->SPINT = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_SC_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_SC_TypeDef_FLASHCFG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->FLASHCFG);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->FLASHCFG = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PLL0CON(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PLL0CON);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->PLL0CON = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PLL0CFG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PLL0CFG);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->PLL0CFG = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PLL0STAT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PLL0STAT);
	writeUSBOutString(str);
	return 0;
}

int _LPC_SC_TypeDef_PLL0FEED(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_SC_TypeDef_ptr->PLL0FEED = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PLL1CON(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PLL1CON);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->PLL1CON = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PLL1CFG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PLL1CFG);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->PLL1CFG = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PLL1STAT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PLL1STAT);
	writeUSBOutString(str);
	return 0;
}

int _LPC_SC_TypeDef_PLL1FEED(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_SC_TypeDef_ptr->PLL1FEED = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PCON(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PCON);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->PCON = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PCONP(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PCONP);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->PCONP = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_CCLKCFG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->CCLKCFG);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->CCLKCFG = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_USBCLKCFG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->USBCLKCFG);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->USBCLKCFG = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_CLKSRCSEL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->CLKSRCSEL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->CLKSRCSEL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_CANSLEEPCLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->CANSLEEPCLR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->CANSLEEPCLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_CANWAKEFLAGS(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->CANWAKEFLAGS);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->CANWAKEFLAGS = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_EXTINT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->EXTINT);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->EXTINT = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_EXTMODE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->EXTMODE);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->EXTMODE = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_EXTPOLAR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->EXTPOLAR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->EXTPOLAR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_RSID(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->RSID);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->RSID = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_SCS(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->SCS);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->SCS = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_IRCTRIM(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->IRCTRIM);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->IRCTRIM = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PCLKSEL0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PCLKSEL0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->PCLKSEL0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_PCLKSEL1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->PCLKSEL1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->PCLKSEL1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SC_TypeDef_USBIntSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->USBIntSt);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->USBIntSt = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

/*int _LPC_SC_TypeDef_DMAREQSEL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->DMAREQSEL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->DMAREQSEL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _LPC_SC_TypeDef_CLKOUTCFG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SC_TypeDef* LPC_SC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SC_TypeDef_ptr = (LPC_SC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SC_TypeDef_ptr->CLKOUTCFG);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SC_TypeDef_ptr->CLKOUTCFG = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_USB_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_HcRevision(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcRevision);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_HcControl(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcControl);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcControl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcCommandStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcCommandStatus);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcCommandStatus = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcInterruptStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcInterruptStatus);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcInterruptStatus = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcInterruptEnable(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcInterruptEnable);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcInterruptEnable = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcInterruptDisable(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcInterruptDisable);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcInterruptDisable = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcHCCA(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcHCCA);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcHCCA = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcPeriodCurrentED(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcPeriodCurrentED);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_HcControlHeadED(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcControlHeadED);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcControlHeadED = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcControlCurrentED(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcControlCurrentED);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcControlCurrentED = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcBulkHeadED(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcBulkHeadED);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcBulkHeadED = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcBulkCurrentED(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcBulkCurrentED);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcBulkCurrentED = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcDoneHead(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcDoneHead);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_HcFmInterval(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcFmInterval);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcFmInterval = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcFmRemaining(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcFmRemaining);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_HcFmNumber(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcFmNumber);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_HcPeriodicStart(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcPeriodicStart);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcPeriodicStart = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcLSTreshold(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcLSTreshold);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcLSTreshold = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcRhDescriptorA(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcRhDescriptorA);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcRhDescriptorA = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;

}

int _LPC_USB_TypeDef_HcRhDescriptorB(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcRhDescriptorB);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcRhDescriptorB = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcRhStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcRhStatus);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcRhStatus = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcRhPortStatus1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcRhPortStatus1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcRhPortStatus1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_HcRhPortStatus2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->HcRhPortStatus2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->HcRhPortStatus2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_Module_ID(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->Module_ID);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_OTGIntSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->OTGIntSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_OTGIntEn(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->OTGIntEn);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->OTGIntEn = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_OTGIntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->OTGIntSet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_OTGIntClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->OTGIntClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_OTGStCtrl(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->OTGStCtrl);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->OTGStCtrl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_OTGTmr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->OTGTmr);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->OTGTmr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBDevIntSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBDevIntSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBDevIntEn(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBDevIntEn);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->USBDevIntEn = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBDevIntClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBDevIntClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBDevIntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBDevIntSet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBCmdCode(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBCmdCode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBCmdData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBCmdData);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBRxData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBRxData);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBTxData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBTxData = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBRxPLen(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBRxPLen);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBTxPLen(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBTxPLen = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBCtrl(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBCtrl);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->USBCtrl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBDevIntPri(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBDevIntPri = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEpIntSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBEpIntSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBEpIntEn(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBEpIntEn);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->USBEpIntEn = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEpIntClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBEpIntClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEpIntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBEpIntSet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEpIntPri(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBEpIntPri = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBReEp(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBReEp);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->USBReEp = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEpInd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBEpInd = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBMaxPSize(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBMaxPSize);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->USBMaxPSize = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBDMARSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBDMARSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBDMARClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBDMARClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBDMARSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBDMARSet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBUDCAH(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBUDCAH);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->USBUDCAH = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEpDMASt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBEpDMASt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBEpDMAEn(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBEpDMAEn = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEpDMADis(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBEpDMADis = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBDMAIntSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBDMAIntSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBDMAIntEn(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBDMAIntEn);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->USBDMAIntEn = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEoTIntSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBEoTIntSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBEoTIntClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBEoTIntClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBEoTIntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBEoTIntSet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBNDDRIntSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBNDDRIntSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBNDDRIntClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBNDDRIntClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBNDDRIntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBNDDRIntSet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBSysErrIntSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBSysErrIntSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_USBSysErrIntClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBSysErrIntClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBSysErrIntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->USBSysErrIntSet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_I2C_RX(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->I2C_RX);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_I2C_TX(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->I2C_TX = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_I2C_STS(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->I2C_STS);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_I2C_CTL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->I2C_CTL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->I2C_CTL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_I2C_CLKHI(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->I2C_CLKHI);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->I2C_CLKHI = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_I2C_CLKLO(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_USB_TypeDef_ptr->I2C_CLKLO = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBClkCtrl(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBClkCtrl);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->USBClkCtrl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_OTGClkCtrl(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->OTGClkCtrl);
		writeUSBOutString(str);
		return 0;
	}

	LPC_USB_TypeDef_ptr->OTGClkCtrl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_USB_TypeDef_USBClkSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->USBClkSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_USB_TypeDef_OTGClkSt(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_USB_TypeDef* LPC_USB_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_USB_TypeDef_ptr = (LPC_USB_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_USB_TypeDef_ptr->OTGClkSt);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMACH_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_GPDMACH_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMACH_TypeDef_DMACCSrcAddr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMACH_TypeDef* LPC_GPDMACH_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMACH_TypeDef_ptr = (LPC_GPDMACH_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMACH_TypeDef_ptr->DMACCSrcAddr);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMACH_TypeDef_ptr->DMACCSrcAddr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMACH_TypeDef_DMACCDestAddr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMACH_TypeDef* LPC_GPDMACH_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMACH_TypeDef_ptr = (LPC_GPDMACH_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMACH_TypeDef_ptr->DMACCDestAddr);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMACH_TypeDef_ptr->DMACCDestAddr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMACH_TypeDef_DMACCLLI(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMACH_TypeDef* LPC_GPDMACH_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMACH_TypeDef_ptr = (LPC_GPDMACH_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMACH_TypeDef_ptr->DMACCLLI);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMACH_TypeDef_ptr->DMACCLLI = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMACH_TypeDef_DMACCControl(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMACH_TypeDef* LPC_GPDMACH_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMACH_TypeDef_ptr = (LPC_GPDMACH_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMACH_TypeDef_ptr->DMACCControl);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMACH_TypeDef_ptr->DMACCControl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMACH_TypeDef_DMACCConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMACH_TypeDef* LPC_GPDMACH_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMACH_TypeDef_ptr = (LPC_GPDMACH_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMACH_TypeDef_ptr->DMACCConfig);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMACH_TypeDef_ptr->DMACCConfig = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_ADC_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_ADC_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_ADC_TypeDef_ptr->ADCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_ADC_TypeDef_ADGDR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADGDR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_ADC_TypeDef_ptr->ADGDR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_ADC_TypeDef_ADINTEN(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADINTEN);
		writeUSBOutString(str);
		return 0;
	}

	LPC_ADC_TypeDef_ptr->ADINTEN = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_ADC_TypeDef_ADDR0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADDR0);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADDR1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);


	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADDR1);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADDR2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADDR2);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADDR3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADDR3);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADDR4(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADDR4);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADDR5(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADDR5);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADDR6(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADDR6);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADDR7(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADDR7);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADSTAT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADSTAT);
	writeUSBOutString(str);
	return 0;
}

int _LPC_ADC_TypeDef_ADTRM(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_ADC_TypeDef* LPC_ADC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_ADC_TypeDef_ptr = (LPC_ADC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_ADC_TypeDef_ptr->ADTRM);
		writeUSBOutString(str);
		return 0;
	}

	LPC_ADC_TypeDef_ptr->ADTRM = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMA_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_GPDMA_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACIntStat(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACIntStat);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACIntTCStat(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACIntTCStat);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACIntTCClear(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_GPDMA_TypeDef_ptr->DMACIntTCClear = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACIntErrStat(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACIntErrStat);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACIntErrClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_GPDMA_TypeDef_ptr->DMACIntErrClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACRawIntTCStat(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACRawIntTCStat);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACRawIntErrStat(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACRawIntErrStat);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACEnbldChns(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACEnbldChns);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACSoftBReq(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACSoftBReq);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMA_TypeDef_ptr->DMACSoftBReq = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACSoftSReq(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACSoftSReq);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMA_TypeDef_ptr->DMACSoftSReq = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACSoftLBReq(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACSoftLBReq);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMA_TypeDef_ptr->DMACSoftLBReq = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACSoftLSReq(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACSoftLSReq);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMA_TypeDef_ptr->DMACSoftLSReq = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACConfig);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMA_TypeDef_ptr->DMACConfig = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPDMA_TypeDef_DMACSync(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPDMA_TypeDef* LPC_GPDMA_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPDMA_TypeDef_ptr = (LPC_GPDMA_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPDMA_TypeDef_ptr->DMACSync);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPDMA_TypeDef_ptr->DMACSync = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_RTC_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_RTC_TypeDef_ILR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ILR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ILR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_CCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->CCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->CCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_CIIR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->CIIR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->CIIR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_AMR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->AMR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->AMR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_CTIME0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->CTIME0);
	writeUSBOutString(str);
	return 0;
}

int _LPC_RTC_TypeDef_CTIME1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->CTIME1);
	writeUSBOutString(str);
	return 0;
}

int _LPC_RTC_TypeDef_CTIME2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->CTIME2);
	writeUSBOutString(str);
	return 0;
}

int _LPC_RTC_TypeDef_SEC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->SEC);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->SEC = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_MIN(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->MIN);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->MIN = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_HOUR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->HOUR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->HOUR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_DOM(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->DOM);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->DOM = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_DOW(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->DOW);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->DOW = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_DOY(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->DOY);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->DOY = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_MONTH(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->MONTH);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->MONTH = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_YEAR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->YEAR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->YEAR = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_CALIBRATION(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->CALIBRATION);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->CALIBRATION = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_GPREG0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->GPREG0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->GPREG0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_GPREG1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->GPREG1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->GPREG1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_GPREG2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->GPREG2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->GPREG2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_GPREG3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->GPREG3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->GPREG3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_GPREG4(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->GPREG4);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->GPREG4 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_RTC_AUXEN(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->RTC_AUXEN);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->RTC_AUXEN = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_RTC_AUX(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->RTC_AUX);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->RTC_AUX = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_ALSEC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ALSEC);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ALSEC = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_ALMIN(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ALMIN);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ALMIN = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_ALHOUR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ALHOUR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ALHOUR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_ALDOM(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ALDOM);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ALDOM = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_ALDOW(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ALDOW);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ALDOW = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_ALDOY(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ALDOY);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ALDOY = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_ALMON(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ALMON);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ALMON = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RTC_TypeDef_ALYEAR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RTC_TypeDef* LPC_RTC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RTC_TypeDef_ptr = (LPC_RTC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RTC_TypeDef_ptr->ALYEAR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RTC_TypeDef_ptr->ALYEAR = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_MCPWM_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCON(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCCON);
	writeUSBOutString(str);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCON_SET(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCCON_SET = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCON_CLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCCON_CLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCAPCON(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCCAPCON);
	writeUSBOutString(str);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCAPCON_SET(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCCAPCON_SET = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCAPCON_CLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCCAPCON_CLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCTIM0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCTIM0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCTIM0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCTIM1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCTIM1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCTIM1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCTIM2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCTIM2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCTIM2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCPER0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCPER0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCPER0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCPER1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCPER1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCPER1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCPER2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCPER2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCPER2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCPW0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCPW0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCPW0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCPW1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCPW1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCPW1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCPW2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCPW2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCPW2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCDEADTIME(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCDEADTIME);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCDEADTIME = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCCP(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCCCP);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCCCP = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCR0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCCR0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCCR0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCR1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCCR1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCCR1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCR2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCCR2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_MCPWM_TypeDef_ptr->MCCR2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCINTEN(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCINTEN);
	writeUSBOutString(str);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCINTEN_SET(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCINTEN_SET = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCINTEN_CLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCINTEN_CLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCNTCON(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCCNTCON);
	writeUSBOutString(str);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCNTCON_SET(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCCNTCON_SET = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCNTCON_CLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCCNTCON_CLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCINTFLAG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_MCPWM_TypeDef_ptr->MCINTFLAG);
	writeUSBOutString(str);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCINTFLAG_SET(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCINTFLAG_SET = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCINTFLAG_CLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCINTFLAG_CLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_MCPWM_TypeDef_MCCAP_CLR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_MCPWM_TypeDef* LPC_MCPWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_MCPWM_TypeDef_ptr = (LPC_MCPWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_MCPWM_TypeDef_ptr->MCCAP_CLR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_I2S_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_I2S_TypeDef_I2SDAO(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SDAO);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2SDAO = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2SDAI(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SDAI);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2SDAI = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2STXFIFO(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_I2S_TypeDef_ptr->I2STXFIFO = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2SRXFIFO(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SRXFIFO);
	writeUSBOutString(str);
	return 0;
}

int _LPC_I2S_TypeDef_I2SSTATE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SSTATE);
	writeUSBOutString(str);
	return 0;
}

int _LPC_I2S_TypeDef_I2SDMA1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SDMA1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2SDMA1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2SDMA2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SDMA2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2SDMA2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2SIRQ(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SIRQ);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2SIRQ = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2STXRATE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2STXRATE);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2STXRATE = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2SRXRATE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SRXRATE);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2SRXRATE = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2STXBITRATE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2STXBITRATE);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2STXBITRATE = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2SRXBITRATE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SRXBITRATE);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2SRXBITRATE = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2STXMODE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2STXMODE);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2STXMODE = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_I2S_TypeDef_I2SRXMODE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2S_TypeDef* LPC_I2S_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_I2S_TypeDef_ptr = (LPC_I2S_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_I2S_TypeDef_ptr->I2SRXMODE);
		writeUSBOutString(str);
		return 0;
	}

	LPC_I2S_TypeDef_ptr->I2SRXMODE = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_UART1_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART1_TypeDef_RBR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->RBR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART1_TypeDef_THR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_UART1_TypeDef_ptr->THR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_DLL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->DLL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->DLL = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_DLM(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->DLM);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->DLM = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_IER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->IER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->IER = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_IIR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->IIR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART1_TypeDef_FCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_UART1_TypeDef_ptr->FCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_LCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->LCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->LCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_MCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->MCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->MCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_LSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->LSR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART1_TypeDef_MSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->MSR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_UART1_TypeDef_SCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->SCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->SCR = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_ACR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->ACR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->ACR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_FDR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->FDR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->FDR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_TER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->TER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->TER = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_RS485CTRL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->RS485CTRL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->RS485CTRL = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_ADRMATCH(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->ADRMATCH);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->ADRMATCH = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_RS485DLY(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->RS485DLY);
		writeUSBOutString(str);
		return 0;
	}

	LPC_UART1_TypeDef_ptr->RS485DLY = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_UART1_TypeDef_FIFOLVL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* LPC_UART1_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_UART1_TypeDef_ptr = (LPC_UART1_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_UART1_TypeDef_ptr->FIFOLVL);
	writeUSBOutString(str);
	return 0;
}

int _LPC_RIT_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_RIT_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_RIT_TypeDef_RICOMPVAL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* LPC_RIT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RIT_TypeDef_ptr = (LPC_RIT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RIT_TypeDef_ptr->RICOMPVAL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RIT_TypeDef_ptr->RICOMPVAL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RIT_TypeDef_RIMASK(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* LPC_RIT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RIT_TypeDef_ptr = (LPC_RIT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RIT_TypeDef_ptr->RIMASK);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RIT_TypeDef_ptr->RIMASK = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RIT_TypeDef_RICTRL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* LPC_RIT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RIT_TypeDef_ptr = (LPC_RIT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RIT_TypeDef_ptr->RICTRL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RIT_TypeDef_ptr->RICTRL = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_RIT_TypeDef_RICOUNTER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_RIT_TypeDef* LPC_RIT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_RIT_TypeDef_ptr = (LPC_RIT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_RIT_TypeDef_ptr->RICOUNTER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_RIT_TypeDef_ptr->RICOUNTER = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIOINT_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_GPIOINT_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IntStatus);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO0IntStatR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IO0IntStatR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO0IntStatF(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IO0IntStatF);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO0IntClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_GPIOINT_TypeDef_ptr->IO0IntClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO0IntEnR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IO0IntEnR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIOINT_TypeDef_ptr->IO0IntEnR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO0IntEnF(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IO0IntEnF);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIOINT_TypeDef_ptr->IO0IntEnF = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO2IntStatR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IO2IntStatR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO2IntStatF(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IO2IntStatF);
	writeUSBOutString(str);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO2IntClr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_GPIOINT_TypeDef_ptr->IO2IntClr = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO2IntEnR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IO2IntEnR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIOINT_TypeDef_ptr->IO2IntEnR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_GPIOINT_TypeDef_IO2IntEnF(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_GPIOINT_TypeDef* LPC_GPIOINT_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_GPIOINT_TypeDef_ptr = (LPC_GPIOINT_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_GPIOINT_TypeDef_ptr->IO2IntEnF);
		writeUSBOutString(str);
		return 0;
	}

	LPC_GPIOINT_TypeDef_ptr->IO2IntEnF = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_SSP_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_SSP_TypeDef_CR0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->CR0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->CR0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_CR1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->CR1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->CR1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_DR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->DR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->DR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_SR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->SR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_SSP_TypeDef_CPSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->CPSR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->CPSR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_IMSC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->IMSC);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->IMSC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_RIS(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->RIS);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->RIS = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_MIS(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->MIS);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->MIS = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_ICR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->ICR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->ICR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_SSP_TypeDef_DMACR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_SSP_TypeDef* LPC_SSP_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_SSP_TypeDef_ptr = (LPC_SSP_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_SSP_TypeDef_ptr->DMACR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_SSP_TypeDef_ptr->DMACR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_DAC_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_DAC_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_DAC_TypeDef_DACR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_DAC_TypeDef* LPC_DAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_DAC_TypeDef_ptr = (LPC_DAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_DAC_TypeDef_ptr->DACR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_DAC_TypeDef_ptr->DACR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_DAC_TypeDef_DACCTRL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_DAC_TypeDef* LPC_DAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_DAC_TypeDef_ptr = (LPC_DAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_DAC_TypeDef_ptr->DACCTRL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_DAC_TypeDef_ptr->DACCTRL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_DAC_TypeDef_DACCNTVAL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_DAC_TypeDef* LPC_DAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_DAC_TypeDef_ptr = (LPC_DAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_DAC_TypeDef_ptr->DACCNTVAL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_DAC_TypeDef_ptr->DACCNTVAL = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_CAN_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_CAN_TypeDef_MOD(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->MOD);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->MOD = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_CMR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_CAN_TypeDef_ptr->CMR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_GSR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->GSR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->GSR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_ICR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->ICR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_CAN_TypeDef_IER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->IER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->IER = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_BTR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->BTR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->BTR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_EWL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->EWL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->EWL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_SR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->SR);
	writeUSBOutString(str);
	return 0;
}

int _LPC_CAN_TypeDef_RFS(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->RFS);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->RFS = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_RID(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->RID);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->RID = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_RDA(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->RDA);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->RDA = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_RDB(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->RDB);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->RDB = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TFI1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TFI1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TFI1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TID1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TID1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TID1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TDA1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TDA1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TDA1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TDB1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TDB1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TDB1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TFI2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TFI2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TFI2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TID2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TID2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TID2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TDA2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TDA2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TDA2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TDB2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TDB2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TDB2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TFI3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TFI3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TFI3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TID3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TID3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TID3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TDA3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TDA3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TDA3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CAN_TypeDef_TDB3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CAN_TypeDef* LPC_CAN_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CAN_TypeDef_ptr = (LPC_CAN_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CAN_TypeDef_ptr->TDB3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CAN_TypeDef_ptr->TDB3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_RAM_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_CANAF_RAM_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

/*int _LPC_CANAF_RAM_TypeDef_mask[512](uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_RAM_TypeDef* LPC_CANAF_RAM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_RAM_TypeDef_ptr = (LPC_CANAF_RAM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_RAM_TypeDef_ptr->mask[512]);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_RAM_TypeDef_ptr->mask[512] = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _LPC_CANAF_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_CANAF_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_CANAF_TypeDef_AFMR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->AFMR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->AFMR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_TypeDef_SFF_sa(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->SFF_sa);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->SFF_sa = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_TypeDef_SFF_GRP_sa(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->SFF_GRP_sa);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->SFF_GRP_sa = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_TypeDef_EFF_sa(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->EFF_sa);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->EFF_sa = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_TypeDef_EFF_GRP_sa(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->EFF_GRP_sa);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->EFF_GRP_sa = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_TypeDef_ENDofTable(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->ENDofTable);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->ENDofTable = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_TypeDef_LUTerrAd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->LUTerrAd);
	writeUSBOutString(str);
	return 0;
}

int _LPC_CANAF_TypeDef_LUTerr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->LUTerr);
	writeUSBOutString(str);
	return 0;
}

int _LPC_CANAF_TypeDef_FCANIE(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->FCANIE);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->FCANIE = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_TypeDef_FCANIC0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->FCANIC0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->FCANIC0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_CANAF_TypeDef_FCANIC1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_CANAF_TypeDef* LPC_CANAF_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_CANAF_TypeDef_ptr = (LPC_CANAF_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_CANAF_TypeDef_ptr->FCANIC1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_CANAF_TypeDef_ptr->FCANIC1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_EMAC_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_MAC1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->MAC1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->MAC1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_MAC2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->MAC2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->MAC2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_IPGT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->IPGT);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->IPGT = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_IPGR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->IPGR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->IPGR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_CLRT(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->CLRT);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->CLRT = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_MAXF(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->MAXF);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->MAXF = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_SUPP(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->SUPP);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->SUPP = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_TEST(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->TEST);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->TEST = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_MCFG(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->MCFG);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->MCFG = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_MCMD(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->MCMD);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->MCMD = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_MADR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->MADR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->MADR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_MWTD(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_EMAC_TypeDef_ptr->MWTD = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_MRDD(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->MRDD);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_MIND(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->MIND);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_SA0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->SA0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->SA0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_SA1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->SA1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->SA1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_SA2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->SA2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->SA2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_Command(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->Command);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->Command = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_Status(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->Status);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_RxDescriptor(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RxDescriptor);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->RxDescriptor = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_RxStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RxStatus);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->RxStatus = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_RxDescriptorNumber(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RxDescriptorNumber);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->RxDescriptorNumber = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_RxProduceIndex(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RxProduceIndex);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_RxConsumeIndex(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RxConsumeIndex);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->RxConsumeIndex = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_TxDescriptor(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->TxDescriptor);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->TxDescriptor = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_TxStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->TxStatus);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->TxStatus = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_TxDescriptorNumber(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->TxDescriptorNumber);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->TxDescriptorNumber = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_TxProduceIndex(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->TxProduceIndex);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->TxProduceIndex = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_TxConsumeIndex(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->TxConsumeIndex);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_TSV0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->TSV0);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_TSV1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->TSV1);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_RSV(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RSV);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_FlowControlCounter(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->FlowControlCounter);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->FlowControlCounter = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_FlowControlStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->FlowControlStatus);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_RxFilterCtrl(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RxFilterCtrl);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->RxFilterCtrl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_RxFilterWoLStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RxFilterWoLStatus);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->RxFilterWoLStatus = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_RxFilterWoLClear(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->RxFilterWoLClear);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->RxFilterWoLClear = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_HashFilterL(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->HashFilterL);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->HashFilterL = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_HashFilterH(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->HashFilterH);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->HashFilterH = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_IntStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->IntStatus);
	writeUSBOutString(str);
	return 0;
}

int _LPC_EMAC_TypeDef_IntEnable(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->IntEnable);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->IntEnable = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_IntClear(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_EMAC_TypeDef_ptr->IntClear = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_IntSet(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		return 1;
	}

	LPC_EMAC_TypeDef_ptr->IntSet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_PowerDown(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->PowerDown);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->PowerDown = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_EMAC_TypeDef_Module_ID(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_EMAC_TypeDef* LPC_EMAC_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_EMAC_TypeDef_ptr = (LPC_EMAC_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_EMAC_TypeDef_ptr->Module_ID);
		writeUSBOutString(str);
		return 0;
	}

	LPC_EMAC_TypeDef_ptr->Module_ID = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_PWM_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_PWM_TypeDef_IR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->IR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->IR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_TCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->TCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->TCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_TC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->TC);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->TC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_PR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->PR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->PR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_PC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->PC);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->PC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_MCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->MCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->MCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_MR0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->MR0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->MR0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_MR1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->MR1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->MR1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_MR2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->MR2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->MR2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_MR3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->MR3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->MR3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_CCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->CCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->CCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_CR0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->CR0);
	writeUSBOutString(str);
	return 0;
}

int _LPC_PWM_TypeDef_CR1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->CR1);
	writeUSBOutString(str);
	return 0;
}

int _LPC_PWM_TypeDef_CR2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->CR2);
	writeUSBOutString(str);
	return 0;
}

int _LPC_PWM_TypeDef_CR3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->CR3);
	writeUSBOutString(str);
	return 0;
}

int _LPC_PWM_TypeDef_MR4(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->MR4);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->MR4 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_MR5(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->MR5);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->MR5 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_MR6(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->MR6);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->MR6 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_PCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->PCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->PCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_LER(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->LER);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->LER = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_PWM_TypeDef_CTCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_PWM_TypeDef* LPC_PWM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_PWM_TypeDef_ptr = (LPC_PWM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_PWM_TypeDef_ptr->CTCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_PWM_TypeDef_ptr->CTCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(LPC_TIM_TypeDef)));
	writeUSBOutString(str);
	return 0;
}

int _LPC_TIM_TypeDef_IR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->IR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->IR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_TCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->TCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->TCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_TC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->TC);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->TC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_PR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->PR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->PR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_PC(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->PC);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->PC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_MCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->MCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->MCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_MR0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->MR0);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->MR0 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_MR1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->MR1);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->MR1 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_MR2(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->MR2);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->MR2 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_MR3(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->MR3);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->MR3 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_CCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->CCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->CCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_CR0(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->CR0);
	writeUSBOutString(str);
	return 0;
}

int _LPC_TIM_TypeDef_CR1(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->CR1);
	writeUSBOutString(str);
	return 0;
}

int _LPC_TIM_TypeDef_EMR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->EMR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->EMR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _LPC_TIM_TypeDef_CTCR(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_TIM_TypeDef* LPC_TIM_TypeDef_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	LPC_TIM_TypeDef_ptr = (LPC_TIM_TypeDef *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) LPC_TIM_TypeDef_ptr->CTCR);
		writeUSBOutString(str);
		return 0;
	}

	LPC_TIM_TypeDef_ptr->CTCR = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _IRQn_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(IRQn_Type)));
	writeUSBOutString(str);
	return 0;
}

