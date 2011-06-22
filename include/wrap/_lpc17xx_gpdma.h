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

#ifndef ___LPC17XX_GPDMA_H__
#define ___LPC17XX_GPDMA_H__

#include "lpc_types.h"

int _GPDMA_Init(uint8_t * args);
int _GPDMA_ChannelCmd(uint8_t * args);
int _GPDMA_Setup(uint8_t * args);
int _GPDMA_IntGetStatus(uint8_t * args);
int _GPDMA_ClearIntPending(uint8_t * args);
int _GPDMA_StateClear_Type_malloc(uint8_t * args);
int _GPDMA_LLI_Type_malloc(uint8_t * args);
int _GPDMA_LLI_Type_SrcAddr(uint8_t * args);
int _GPDMA_LLI_Type_DstAddr(uint8_t * args);
int _GPDMA_LLI_Type_NextLLI(uint8_t * args);
int _GPDMA_LLI_Type_Control(uint8_t * args);
int _GPDMA_Channel_CFG_Type_malloc(uint8_t * args);
int _GPDMA_Channel_CFG_Type_ChannelNum(uint8_t * args);
int _GPDMA_Channel_CFG_Type_TransferSize(uint8_t * args);
int _GPDMA_Channel_CFG_Type_TransferWidth(uint8_t * args);
int _GPDMA_Channel_CFG_Type_SrcMemAddr(uint8_t * args);
int _GPDMA_Channel_CFG_Type_DstMemAddr(uint8_t * args);
int _GPDMA_Channel_CFG_Type_TransferType(uint8_t * args);
int _GPDMA_Channel_CFG_Type_SrcConn(uint8_t * args);
int _GPDMA_Channel_CFG_Type_DstConn(uint8_t * args);
int _GPDMA_Channel_CFG_Type_DMALLI(uint8_t * args);
int _GPDMA_Status_Type_malloc(uint8_t * args);

#endif
