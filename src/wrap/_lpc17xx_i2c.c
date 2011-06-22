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

#include "lpc17xx_i2c.h"

#include "return.h"

int _I2C_MonitorModeCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	I2C_MonitorModeCmd(I2Cx, NewState);
	return 0;
}

int _I2C_IntCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	Bool NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (Bool) strtoul((char *) arg_ptr, NULL, 16);

	I2C_IntCmd(I2Cx, NewState);
	return 0;
}

int _I2C_DeInit(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	I2C_DeInit(I2Cx);
	return 0;
}

int _I2C_SlaveHandler(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	I2C_SlaveHandler(I2Cx);
	return 0;
}

int _I2C_MonitorModeConfig(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	uint32_t MonitorCfgType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	MonitorCfgType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	I2C_MonitorModeConfig(I2Cx, MonitorCfgType, NewState);
	return 0;
}

int _I2C_MasterTransferData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	I2C_M_SETUP_Type* TransferCfg;
	I2C_TRANSFER_OPT_Type Opt;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TransferCfg = (I2C_M_SETUP_Type*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Opt = (I2C_TRANSFER_OPT_Type) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2C_MasterTransferData(I2Cx, TransferCfg, Opt));
	writeUSBOutString(str);
	return 0;
}

int _I2C_SlaveTransferComplete(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2C_SlaveTransferComplete(I2Cx));
	writeUSBOutString(str);
	return 0;
}

int _I2C_SlaveTransferData(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	I2C_S_SETUP_Type* TransferCfg;
	I2C_TRANSFER_OPT_Type Opt;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TransferCfg = (I2C_S_SETUP_Type*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	Opt = (I2C_TRANSFER_OPT_Type) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2C_SlaveTransferData(I2Cx, TransferCfg, Opt));
	writeUSBOutString(str);
	return 0;
}

int _I2C_SetOwnSlaveAddr(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	I2C_OWNSLAVEADDR_CFG_Type* OwnSlaveAddrConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	OwnSlaveAddrConfigStruct = (I2C_OWNSLAVEADDR_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	I2C_SetOwnSlaveAddr(I2Cx, OwnSlaveAddrConfigStruct);
	return 0;
}

int _I2C_MasterTransferComplete(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2C_MasterTransferComplete(I2Cx));
	writeUSBOutString(str);
	return 0;
}

int _I2C_MasterHandler(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	I2C_MasterHandler(I2Cx);
	return 0;
}

int _I2C_MonitorHandler(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	uint8_t* buffer;
	uint32_t size;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	buffer = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	size = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2C_MonitorHandler(I2Cx, buffer, size));
	writeUSBOutString(str);
	return 0;
}

int _I2C_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	uint32_t clockrate;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	clockrate = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	I2C_Init(I2Cx, clockrate);
	return 0;
}

int _I2C_MonitorGetDatabuffer(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2C_MonitorGetDatabuffer(I2Cx));
	writeUSBOutString(str);
	return 0;
}

int _I2C_GetLastStatusCode(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) I2C_GetLastStatusCode(I2Cx));
	writeUSBOutString(str);
	return 0;
}

int _I2C_Cmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	LPC_I2C_TypeDef* I2Cx;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2Cx = (LPC_I2C_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	I2C_Cmd(I2Cx, NewState);
	return 0;
}

int _I2C_M_SETUP_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(I2C_M_SETUP_Type)));
	writeUSBOutString(str);
	return 0;
}

int _I2C_M_SETUP_Type_sl_addr7bit(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->sl_addr7bit);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->sl_addr7bit = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_tx_data(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->tx_data);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->tx_data = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_tx_length(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->tx_length);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->tx_length = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_tx_count(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->tx_count);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->tx_count = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_rx_data(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->rx_data);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->rx_data = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_rx_length(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->rx_length);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->rx_length = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_rx_count(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->rx_count);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->rx_count = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_retransmissions_max(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->retransmissions_max);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->retransmissions_max = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_retransmissions_count(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->retransmissions_count);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->retransmissions_count = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_M_SETUP_Type_status(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->status);
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->status = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

/*int _I2C_M_SETUP_Type_(*callback)(void)(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_M_SETUP_Type* I2C_M_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_M_SETUP_Type_ptr = (I2C_M_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_M_SETUP_Type_ptr->(*callback)(void));
		writeUSBOutString(str);
		return 0;
	}

	I2C_M_SETUP_Type_ptr->(*callback)(void) = (void*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

int _I2C_OWNSLAVEADDR_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(I2C_OWNSLAVEADDR_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _I2C_OWNSLAVEADDR_CFG_Type_SlaveAddrChannel(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_OWNSLAVEADDR_CFG_Type* I2C_OWNSLAVEADDR_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_OWNSLAVEADDR_CFG_Type_ptr = (I2C_OWNSLAVEADDR_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_OWNSLAVEADDR_CFG_Type_ptr->SlaveAddrChannel);
		writeUSBOutString(str);
		return 0;
	}

	I2C_OWNSLAVEADDR_CFG_Type_ptr->SlaveAddrChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_OWNSLAVEADDR_CFG_Type_SlaveAddr_7bit(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_OWNSLAVEADDR_CFG_Type* I2C_OWNSLAVEADDR_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_OWNSLAVEADDR_CFG_Type_ptr = (I2C_OWNSLAVEADDR_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_OWNSLAVEADDR_CFG_Type_ptr->SlaveAddr_7bit);
		writeUSBOutString(str);
		return 0;
	}

	I2C_OWNSLAVEADDR_CFG_Type_ptr->SlaveAddr_7bit = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_OWNSLAVEADDR_CFG_Type_GeneralCallState(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_OWNSLAVEADDR_CFG_Type* I2C_OWNSLAVEADDR_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_OWNSLAVEADDR_CFG_Type_ptr = (I2C_OWNSLAVEADDR_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_OWNSLAVEADDR_CFG_Type_ptr->GeneralCallState);
		writeUSBOutString(str);
		return 0;
	}

	I2C_OWNSLAVEADDR_CFG_Type_ptr->GeneralCallState = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_OWNSLAVEADDR_CFG_Type_SlaveAddrMaskValue(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_OWNSLAVEADDR_CFG_Type* I2C_OWNSLAVEADDR_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_OWNSLAVEADDR_CFG_Type_ptr = (I2C_OWNSLAVEADDR_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_OWNSLAVEADDR_CFG_Type_ptr->SlaveAddrMaskValue);
		writeUSBOutString(str);
		return 0;
	}

	I2C_OWNSLAVEADDR_CFG_Type_ptr->SlaveAddrMaskValue = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_TRANSFER_OPT_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(I2C_TRANSFER_OPT_Type)));
	writeUSBOutString(str);
	return 0;
}

int _I2C_S_SETUP_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(I2C_S_SETUP_Type)));
	writeUSBOutString(str);
	return 0;
}

int _I2C_S_SETUP_Type_tx_data(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_S_SETUP_Type* I2C_S_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_S_SETUP_Type_ptr = (I2C_S_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_S_SETUP_Type_ptr->tx_data);
		writeUSBOutString(str);
		return 0;
	}

	I2C_S_SETUP_Type_ptr->tx_data = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_S_SETUP_Type_tx_length(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_S_SETUP_Type* I2C_S_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_S_SETUP_Type_ptr = (I2C_S_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_S_SETUP_Type_ptr->tx_length);
		writeUSBOutString(str);
		return 0;
	}

	I2C_S_SETUP_Type_ptr->tx_length = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_S_SETUP_Type_tx_count(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_S_SETUP_Type* I2C_S_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_S_SETUP_Type_ptr = (I2C_S_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_S_SETUP_Type_ptr->tx_count);
		writeUSBOutString(str);
		return 0;
	}

	I2C_S_SETUP_Type_ptr->tx_count = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_S_SETUP_Type_rx_data(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_S_SETUP_Type* I2C_S_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_S_SETUP_Type_ptr = (I2C_S_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_S_SETUP_Type_ptr->rx_data);
		writeUSBOutString(str);
		return 0;
	}

	I2C_S_SETUP_Type_ptr->rx_data = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_S_SETUP_Type_rx_length(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_S_SETUP_Type* I2C_S_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_S_SETUP_Type_ptr = (I2C_S_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_S_SETUP_Type_ptr->rx_length);
		writeUSBOutString(str);
		return 0;
	}

	I2C_S_SETUP_Type_ptr->rx_length = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_S_SETUP_Type_rx_count(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_S_SETUP_Type* I2C_S_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_S_SETUP_Type_ptr = (I2C_S_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_S_SETUP_Type_ptr->rx_count);
		writeUSBOutString(str);
		return 0;
	}

	I2C_S_SETUP_Type_ptr->rx_count = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _I2C_S_SETUP_Type_status(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_S_SETUP_Type* I2C_S_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_S_SETUP_Type_ptr = (I2C_S_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_S_SETUP_Type_ptr->status);
		writeUSBOutString(str);
		return 0;
	}

	I2C_S_SETUP_Type_ptr->status = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

/*int _I2C_S_SETUP_Type_(*callback)(void)(uint8_t * args)
{
	uint8_t * arg_ptr;
	I2C_S_SETUP_Type* I2C_S_SETUP_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	I2C_S_SETUP_Type_ptr = (I2C_S_SETUP_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) I2C_S_SETUP_Type_ptr->(*callback)(void));
		writeUSBOutString(str);
		return 0;
	}

	I2C_S_SETUP_Type_ptr->(*callback)(void) = (void*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}*/

