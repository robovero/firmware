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

#include "lpc17xx_uart.h"

#include "return.h"

int _UART_RS485SendSlvAddr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* UARTx;
	uint8_t SlvAddr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART1_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	SlvAddr = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	UART_RS485SendSlvAddr(UARTx, SlvAddr);
	return 0;
}

int _UART_ABClearIntPending(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	UART_ABEO_Type ABIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ABIntType = (UART_ABEO_Type) strtoul((char *) arg_ptr, NULL, 16);

	UART_ABClearIntPending(UARTx, ABIntType);
	return 0;
}

int _UART_IrDAPulseDivConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	UART_IrDA_PULSE_Type PulseDiv;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	PulseDiv = (UART_IrDA_PULSE_Type) strtoul((char *) arg_ptr, NULL, 16);

	UART_IrDAPulseDivConfig(UARTx, PulseDiv);
	return 0;
}

int _UART_RS485Config(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* UARTx;
	UART1_RS485_CTRLCFG_Type* RS485ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART1_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RS485ConfigStruct = (UART1_RS485_CTRLCFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	UART_RS485Config(UARTx, RS485ConfigStruct);
	return 0;
}

int _UART_Receive(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint8_t* rxbuf;
	uint32_t buflen;
	TRANSFER_BLOCK_Type flag;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	rxbuf = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	buflen = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	flag = (TRANSFER_BLOCK_Type) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UART_Receive(UARTx, rxbuf, buflen, flag));
	writeUSBOutString(str);
	return 0;
}

int _UART_ReceiveByte(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UART_ReceiveByte(UARTx));
	writeUSBOutString(str);
	return 0;
}

int _UART_GetIntId(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UART_GetIntId(UARTx));
	writeUSBOutString(str);
	return 0;
}

int _UART_ForceBreak(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	UART_ForceBreak(UARTx);
	return 0;
}

int _UART_FIFOConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	UART_FIFO_CFG_Type* FIFOCfg;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	FIFOCfg = (UART_FIFO_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	UART_FIFOConfig(UARTx, FIFOCfg);
	return 0;
}

int _UART_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	UART_DeInit(UARTx);
	return 0;
}

int _UART_Send(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint8_t* txbuf;
	uint32_t buflen;
	TRANSFER_BLOCK_Type flag;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	txbuf = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	buflen = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	flag = (TRANSFER_BLOCK_Type) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UART_Send(UARTx, txbuf, buflen, flag));
	writeUSBOutString(str);
	return 0;
}

int _UART_FIFOConfigStructInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_FIFO_CFG_Type* UART_FIFOInitStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_FIFOInitStruct = (UART_FIFO_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	UART_FIFOConfigStructInit(UART_FIFOInitStruct);
	return 0;
}

int _UART_FullModemForcePinState(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* UARTx;
	UART_MODEM_PIN_Type Pin;
	UART1_SignalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART1_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Pin = (UART_MODEM_PIN_Type) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (UART1_SignalState) strtoul((char *) arg_ptr, NULL, 16);

	UART_FullModemForcePinState(UARTx, Pin, NewState);
	return 0;
}

int _UART_RS485ReceiverCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* UARTx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART1_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	UART_RS485ReceiverCmd(UARTx, NewState);
	return 0;
}

int _UART_CheckBusy(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UART_CheckBusy(UARTx));
	writeUSBOutString(str);
	return 0;
}

int _UART_SendByte(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	uint8_t Data;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Data = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

	UART_SendByte(UARTx, Data);
	return 0;
}

int _UART_ABCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	UART_AB_CFG_Type* ABConfigStruct;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ABConfigStruct = (UART_AB_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	UART_ABCmd(UARTx, ABConfigStruct, NewState);
	return 0;
}

int _UART_GetLineStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UART_GetLineStatus(UARTx));
	writeUSBOutString(str);
	return 0;
}

int _UART_FullModemConfigMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* UARTx;
	UART_MODEM_MODE_Type Mode;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART1_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Mode = (UART_MODEM_MODE_Type) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	UART_FullModemConfigMode(UARTx, Mode, NewState);
	return 0;
}

int _UART_FullModemGetStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* UARTx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART1_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UART_FullModemGetStatus(UARTx));
	writeUSBOutString(str);
	return 0;
}

int _UART_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	UART_CFG_Type* UART_ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_ConfigStruct = (UART_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	UART_Init(UARTx, UART_ConfigStruct);
	return 0;
}

int _UART_IrDACmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	UART_IrDACmd(UARTx, NewState);
	return 0;
}

int _UART_TxCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	UART_TxCmd(UARTx, NewState);
	return 0;
}

int _UART_ConfigStructInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_CFG_Type* UART_InitStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_InitStruct = (UART_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	UART_ConfigStructInit(UART_InitStruct);
	return 0;
}

int _UART_IntConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	UART_INT_Type UARTIntCfg;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTIntCfg = (UART_INT_Type) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	UART_IntConfig(UARTx, UARTIntCfg, NewState);
	return 0;
}

int _UART_IrDAInvtInputCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART_TypeDef* UARTx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	UART_IrDAInvtInputCmd(UARTx, NewState);
	return 0;
}

int _UART_RS485SendData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_UART1_TypeDef* UARTx;
	uint8_t* pData;
	uint32_t size;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UARTx = (LPC_UART1_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pData = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	size = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) UART_RS485SendData(UARTx, pData, size));
	writeUSBOutString(str);
	return 0;
}

int _UART_AB_MODE_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_AB_MODE_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART1_RS485_CTRLCFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_NormalMultiDropMode_State(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART1_RS485_CTRLCFG_Type* UART1_RS485_CTRLCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART1_RS485_CTRLCFG_Type_ptr = (UART1_RS485_CTRLCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART1_RS485_CTRLCFG_Type_ptr->NormalMultiDropMode_State);
		writeUSBOutString(str);
		return 0;
	}

	UART1_RS485_CTRLCFG_Type_ptr->NormalMultiDropMode_State = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_Rx_State(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART1_RS485_CTRLCFG_Type* UART1_RS485_CTRLCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART1_RS485_CTRLCFG_Type_ptr = (UART1_RS485_CTRLCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART1_RS485_CTRLCFG_Type_ptr->Rx_State);
		writeUSBOutString(str);
		return 0;
	}

	UART1_RS485_CTRLCFG_Type_ptr->Rx_State = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_AutoAddrDetect_State(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART1_RS485_CTRLCFG_Type* UART1_RS485_CTRLCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART1_RS485_CTRLCFG_Type_ptr = (UART1_RS485_CTRLCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART1_RS485_CTRLCFG_Type_ptr->AutoAddrDetect_State);
		writeUSBOutString(str);
		return 0;
	}

	UART1_RS485_CTRLCFG_Type_ptr->AutoAddrDetect_State = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_AutoDirCtrl_State(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART1_RS485_CTRLCFG_Type* UART1_RS485_CTRLCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART1_RS485_CTRLCFG_Type_ptr = (UART1_RS485_CTRLCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART1_RS485_CTRLCFG_Type_ptr->AutoDirCtrl_State);
		writeUSBOutString(str);
		return 0;
	}

	UART1_RS485_CTRLCFG_Type_ptr->AutoDirCtrl_State = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_DirCtrlPin(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART1_RS485_CTRLCFG_Type* UART1_RS485_CTRLCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART1_RS485_CTRLCFG_Type_ptr = (UART1_RS485_CTRLCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART1_RS485_CTRLCFG_Type_ptr->DirCtrlPin);
		writeUSBOutString(str);
		return 0;
	}

	UART1_RS485_CTRLCFG_Type_ptr->DirCtrlPin = (UART_RS485_DIRCTRL_PIN_Type) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_DirCtrlPol_Level(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART1_RS485_CTRLCFG_Type* UART1_RS485_CTRLCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART1_RS485_CTRLCFG_Type_ptr = (UART1_RS485_CTRLCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART1_RS485_CTRLCFG_Type_ptr->DirCtrlPol_Level);
		writeUSBOutString(str);
		return 0;
	}

	UART1_RS485_CTRLCFG_Type_ptr->DirCtrlPol_Level = (SetState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_MatchAddrValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART1_RS485_CTRLCFG_Type* UART1_RS485_CTRLCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART1_RS485_CTRLCFG_Type_ptr = (UART1_RS485_CTRLCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART1_RS485_CTRLCFG_Type_ptr->MatchAddrValue);
		writeUSBOutString(str);
		return 0;
	}

	UART1_RS485_CTRLCFG_Type_ptr->MatchAddrValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART1_RS485_CTRLCFG_Type_DelayValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART1_RS485_CTRLCFG_Type* UART1_RS485_CTRLCFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART1_RS485_CTRLCFG_Type_ptr = (UART1_RS485_CTRLCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART1_RS485_CTRLCFG_Type_ptr->DelayValue);
		writeUSBOutString(str);
		return 0;
	}

	UART1_RS485_CTRLCFG_Type_ptr->DelayValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_IrDA_PULSE_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_IrDA_PULSE_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_MODEM_PIN_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_MODEM_PIN_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_FIFO_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_FIFO_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_FIFO_CFG_Type_FIFO_ResetRxBuf(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_FIFO_CFG_Type* UART_FIFO_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_FIFO_CFG_Type_ptr = (UART_FIFO_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_FIFO_CFG_Type_ptr->FIFO_ResetRxBuf);
		writeUSBOutString(str);
		return 0;
	}

	UART_FIFO_CFG_Type_ptr->FIFO_ResetRxBuf = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_FIFO_CFG_Type_FIFO_ResetTxBuf(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_FIFO_CFG_Type* UART_FIFO_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_FIFO_CFG_Type_ptr = (UART_FIFO_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_FIFO_CFG_Type_ptr->FIFO_ResetTxBuf);
		writeUSBOutString(str);
		return 0;
	}

	UART_FIFO_CFG_Type_ptr->FIFO_ResetTxBuf = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_FIFO_CFG_Type_FIFO_DMAMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_FIFO_CFG_Type* UART_FIFO_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_FIFO_CFG_Type_ptr = (UART_FIFO_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_FIFO_CFG_Type_ptr->FIFO_DMAMode);
		writeUSBOutString(str);
		return 0;
	}

	UART_FIFO_CFG_Type_ptr->FIFO_DMAMode = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_FIFO_CFG_Type_FIFO_Level(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_FIFO_CFG_Type* UART_FIFO_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_FIFO_CFG_Type_ptr = (UART_FIFO_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_FIFO_CFG_Type_ptr->FIFO_Level);
		writeUSBOutString(str);
		return 0;
	}

	UART_FIFO_CFG_Type_ptr->FIFO_Level = (UART_FITO_LEVEL_Type) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_STOPBIT_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_STOPBIT_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_ABEO_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_ABEO_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_RS485_DIRCTRL_PIN_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_RS485_DIRCTRL_PIN_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART1_SignalState_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART1_SignalState)));
	writeUSBOutString(str);
	return 0;
}

int _UART_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_CFG_Type_Baud_rate(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_CFG_Type* UART_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_CFG_Type_ptr = (UART_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_CFG_Type_ptr->Baud_rate);
		writeUSBOutString(str);
		return 0;
	}

	UART_CFG_Type_ptr->Baud_rate = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_CFG_Type_Parity(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_CFG_Type* UART_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_CFG_Type_ptr = (UART_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_CFG_Type_ptr->Parity);
		writeUSBOutString(str);
		return 0;
	}

	UART_CFG_Type_ptr->Parity = (UART_PARITY_Type) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_CFG_Type_Databits(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_CFG_Type* UART_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_CFG_Type_ptr = (UART_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_CFG_Type_ptr->Databits);
		writeUSBOutString(str);
		return 0;
	}

	UART_CFG_Type_ptr->Databits = (UART_DATABIT_Type) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_CFG_Type_Stopbits(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_CFG_Type* UART_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_CFG_Type_ptr = (UART_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_CFG_Type_ptr->Stopbits);
		writeUSBOutString(str);
		return 0;
	}

	UART_CFG_Type_ptr->Stopbits = (UART_STOPBIT_Type) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_AB_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_AB_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_AB_CFG_Type_ABMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_AB_CFG_Type* UART_AB_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_AB_CFG_Type_ptr = (UART_AB_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_AB_CFG_Type_ptr->ABMode);
		writeUSBOutString(str);
		return 0;
	}

	UART_AB_CFG_Type_ptr->ABMode = (UART_AB_MODE_Type) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_AB_CFG_Type_AutoRestart(uint8_t * args)
{
	uint8_t * arg_ptr;
	UART_AB_CFG_Type* UART_AB_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	UART_AB_CFG_Type_ptr = (UART_AB_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) UART_AB_CFG_Type_ptr->AutoRestart);
		writeUSBOutString(str);
		return 0;
	}

	UART_AB_CFG_Type_ptr->AutoRestart = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _UART_MODEM_MODE_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_MODEM_MODE_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_FITO_LEVEL_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_FITO_LEVEL_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_INT_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_INT_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_LS_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_LS_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_DATABIT_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_DATABIT_Type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_MODEM_STAT_type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_MODEM_STAT_type)));
	writeUSBOutString(str);
	return 0;
}

int _UART_PARITY_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(UART_PARITY_Type)));
	writeUSBOutString(str);
	return 0;
}

