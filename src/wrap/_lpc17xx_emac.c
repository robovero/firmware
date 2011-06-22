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

#include "lpc17xx_emac.h"

#include "return.h"

int _EMAC_GetWoLStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ulWoLMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulWoLMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_GetWoLStatus(ulWoLMode));
	writeUSBOutString(str);
	return 0;
}

int _EMAC_Init(uint8_t * args)
{
	uint8_t * arg_ptr;
	EMAC_CFG_Type* EMAC_ConfigStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EMAC_ConfigStruct = (EMAC_CFG_Type*) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_Init(EMAC_ConfigStruct));
	writeUSBOutString(str);
	return 0;
}

int _EMAC_CheckReceiveDataStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ulRxStatType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulRxStatType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_CheckReceiveDataStatus(ulRxStatType));
	writeUSBOutString(str);
	return 0;
}

int _EMAC_CheckTransmitIndex(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_CheckTransmitIndex());
	writeUSBOutString(str);
	return 0;
}

int _EMAC_IntCmd(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ulIntType;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	EMAC_IntCmd(ulIntType, NewState);
	return 0;
}

int _EMAC_SetPHYMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ulPHYMode;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulPHYMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_SetPHYMode(ulPHYMode));
	writeUSBOutString(str);
	return 0;
}

int _EMAC_IntGetStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ulIntType;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulIntType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_IntGetStatus(ulIntType));
	writeUSBOutString(str);
	return 0;
}

int _EMAC_WritePacketBuffer(uint8_t * args)
{
	uint8_t * arg_ptr;
	EMAC_PACKETBUF_Type* pDataStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pDataStruct = (EMAC_PACKETBUF_Type*) strtoul((char *) arg_ptr, NULL, 16);

	EMAC_WritePacketBuffer(pDataStruct);
	return 0;
}

int _EMAC_SetHashFilter(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint8_t* dstMAC_addr;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	dstMAC_addr = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	EMAC_SetHashFilter(dstMAC_addr, NewState);
	return 0;
}

int _EMAC_CheckReceiveIndex(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_CheckReceiveIndex());
	writeUSBOutString(str);
	return 0;
}

int _EMAC_UpdatePHYStatus(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_UpdatePHYStatus());
	writeUSBOutString(str);
	return 0;
}

int _EMAC_CheckPHYStatus(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ulPHYState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulPHYState = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_CheckPHYStatus(ulPHYState));
	writeUSBOutString(str);
	return 0;
}

int _EMAC_UpdateTxProduceIndex(uint8_t * args)
{
	EMAC_UpdateTxProduceIndex();
	return 0;
}

int _EMAC_DeInit(uint8_t * args)
{
	EMAC_DeInit();
	return 0;
}

int _EMAC_GetReceiveDataSize(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_GetReceiveDataSize());
	writeUSBOutString(str);
	return 0;
}

int _EMAC_UpdateRxConsumeIndex(uint8_t * args)
{
	EMAC_UpdateRxConsumeIndex();
	return 0;
}

int _EMAC_ReadPacketBuffer(uint8_t * args)
{
	uint8_t * arg_ptr;
	EMAC_PACKETBUF_Type* pDataStruct;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pDataStruct = (EMAC_PACKETBUF_Type*) strtoul((char *) arg_ptr, NULL, 16);

	EMAC_ReadPacketBuffer(pDataStruct);
	return 0;
}

int _EMAC_SetFilterMode(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint32_t ulFilterMode;
	FunctionalState NewState;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	ulFilterMode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

	EMAC_SetFilterMode(ulFilterMode, NewState);
	return 0;
}

int _RX_Stat_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(RX_Stat)));
	writeUSBOutString(str);
	return 0;
}

int _RX_Stat_Info(uint8_t * args)
{
	uint8_t * arg_ptr;
	RX_Stat* RX_Stat_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RX_Stat_ptr = (RX_Stat *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RX_Stat_ptr->Info);
		writeUSBOutString(str);
		return 0;
	}

	RX_Stat_ptr->Info = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RX_Stat_HashCRC(uint8_t * args)
{
	uint8_t * arg_ptr;
	RX_Stat* RX_Stat_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RX_Stat_ptr = (RX_Stat *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RX_Stat_ptr->HashCRC);
		writeUSBOutString(str);
		return 0;
	}

	RX_Stat_ptr->HashCRC = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _EMAC_CFG_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(EMAC_CFG_Type)));
	writeUSBOutString(str);
	return 0;
}

int _EMAC_CFG_Type_Mode(uint8_t * args)
{

	uint8_t * arg_ptr;
	EMAC_CFG_Type* EMAC_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EMAC_CFG_Type_ptr = (EMAC_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_CFG_Type_ptr->Mode);
		writeUSBOutString(str);
		return 0;
	}

	EMAC_CFG_Type_ptr->Mode = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _EMAC_CFG_Type_pbEMAC_Addr(uint8_t * args)
{
	uint8_t * arg_ptr;
	EMAC_CFG_Type* EMAC_CFG_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EMAC_CFG_Type_ptr = (EMAC_CFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_CFG_Type_ptr->pbEMAC_Addr);
		writeUSBOutString(str);
		return 0;
	}

	EMAC_CFG_Type_ptr->pbEMAC_Addr = (uint8_t*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _EMAC_PACKETBUF_Type_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(EMAC_PACKETBUF_Type)));
	writeUSBOutString(str);
	return 0;
}

int _EMAC_PACKETBUF_Type_ulDataLen(uint8_t * args)
{
	uint8_t * arg_ptr;
	EMAC_PACKETBUF_Type* EMAC_PACKETBUF_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EMAC_PACKETBUF_Type_ptr = (EMAC_PACKETBUF_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_PACKETBUF_Type_ptr->ulDataLen);
		writeUSBOutString(str);
		return 0;
	}

	EMAC_PACKETBUF_Type_ptr->ulDataLen = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _EMAC_PACKETBUF_Type_pbDataBuf(uint8_t * args)
{
	uint8_t * arg_ptr;
	EMAC_PACKETBUF_Type* EMAC_PACKETBUF_Type_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	EMAC_PACKETBUF_Type_ptr = (EMAC_PACKETBUF_Type *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) EMAC_PACKETBUF_Type_ptr->pbDataBuf);
		writeUSBOutString(str);
		return 0;
	}

	EMAC_PACKETBUF_Type_ptr->pbDataBuf = (uint32_t*) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RX_Desc_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(RX_Desc)));
	writeUSBOutString(str);
	return 0;
}

int _RX_Desc_Packet(uint8_t * args)
{
	uint8_t * arg_ptr;
	RX_Desc* RX_Desc_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RX_Desc_ptr = (RX_Desc *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RX_Desc_ptr->Packet);
		writeUSBOutString(str);
		return 0;
	}

	RX_Desc_ptr->Packet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _RX_Desc_Ctrl(uint8_t * args)
{
	uint8_t * arg_ptr;
	RX_Desc* RX_Desc_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	RX_Desc_ptr = (RX_Desc *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) RX_Desc_ptr->Ctrl);
		writeUSBOutString(str);
		return 0;
	}

	RX_Desc_ptr->Ctrl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TX_Desc_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TX_Desc)));
	writeUSBOutString(str);
	return 0;
}

int _TX_Desc_Packet(uint8_t * args)
{
	uint8_t * arg_ptr;
	TX_Desc* TX_Desc_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TX_Desc_ptr = (TX_Desc *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TX_Desc_ptr->Packet);
		writeUSBOutString(str);
		return 0;
	}

	TX_Desc_ptr->Packet = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TX_Desc_Ctrl(uint8_t * args)
{
	uint8_t * arg_ptr;
	TX_Desc* TX_Desc_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TX_Desc_ptr = (TX_Desc *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TX_Desc_ptr->Ctrl);
		writeUSBOutString(str);
		return 0;
	}

	TX_Desc_ptr->Ctrl = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

int _TX_Stat_malloc(uint8_t * args)
{
	sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(TX_Stat)));
	writeUSBOutString(str);
	return 0;
}

int _TX_Stat_Info(uint8_t * args)
{
	uint8_t * arg_ptr;
	TX_Stat* TX_Stat_ptr;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	TX_Stat_ptr = (TX_Stat *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
		sprintf((char *) str, "%x\r\n", (unsigned int) TX_Stat_ptr->Info);
		writeUSBOutString(str);
		return 0;
	}

	TX_Stat_ptr->Info = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
	return 0;
}

