/*******************************************************************************
 * @file
 * @purpose        
 * @version        0.1
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
 *     list of conditions and the following disclaimer.
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

#ifndef ___LPC17XX_EMAC_H__
#define ___LPC17XX_EMAC_H__

#include "lpc_types.h"

int _EMAC_GetWoLStatus(uint8_t * args);
int _EMAC_Init(uint8_t * args);
int _EMAC_CheckReceiveDataStatus(uint8_t * args);
int _EMAC_CheckTransmitIndex(uint8_t * args);
int _EMAC_IntCmd(uint8_t * args);
int _EMAC_SetPHYMode(uint8_t * args);
int _EMAC_IntGetStatus(uint8_t * args);
int _EMAC_WritePacketBuffer(uint8_t * args);
int _EMAC_SetHashFilter(uint8_t * args);
int _EMAC_CheckReceiveIndex(uint8_t * args);
int _EMAC_UpdatePHYStatus(uint8_t * args);
int _EMAC_CheckPHYStatus(uint8_t * args);
int _EMAC_UpdateTxProduceIndex(uint8_t * args);
int _EMAC_DeInit(uint8_t * args);
int _EMAC_GetReceiveDataSize(uint8_t * args);
int _EMAC_UpdateRxConsumeIndex(uint8_t * args);
int _EMAC_ReadPacketBuffer(uint8_t * args);
int _EMAC_SetFilterMode(uint8_t * args);
int _RX_Stat_malloc(uint8_t * args);
int _RX_Stat_Info(uint8_t * args);
int _RX_Stat_HashCRC(uint8_t * args);
int _EMAC_CFG_Type_malloc(uint8_t * args);
int _EMAC_CFG_Type_Mode(uint8_t * args);
int _EMAC_CFG_Type_pbEMAC_Addr(uint8_t * args);
int _EMAC_PACKETBUF_Type_malloc(uint8_t * args);
int _EMAC_PACKETBUF_Type_ulDataLen(uint8_t * args);
int _EMAC_PACKETBUF_Type_pbDataBuf(uint8_t * args);
int _RX_Desc_malloc(uint8_t * args);
int _RX_Desc_Packet(uint8_t * args);
int _RX_Desc_Ctrl(uint8_t * args);
int _TX_Desc_malloc(uint8_t * args);
int _TX_Desc_Packet(uint8_t * args);
int _TX_Desc_Ctrl(uint8_t * args);
int _TX_Stat_malloc(uint8_t * args);
int _TX_Stat_Info(uint8_t * args);

#endif
