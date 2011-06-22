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

#ifndef ___LPC17XX_I2S_H__
#define ___LPC17XX_I2S_H__

#include "lpc_types.h"

int _I2S_GetLevel(uint8_t * args);
int _I2S_GetIRQDepth(uint8_t * args);
int _I2S_Mute(uint8_t * args);
int _I2S_Start(uint8_t * args);
int _I2S_Pause(uint8_t * args);
int _I2S_Init(uint8_t * args);
int _I2S_SetBitRate(uint8_t * args);
int _I2S_FreqConfig(uint8_t * args);
int _I2S_DMACmd(uint8_t * args);
int _I2S_Send(uint8_t * args);
int _I2S_Receive(uint8_t * args);
int _I2S_DeInit(uint8_t * args);
int _I2S_Config(uint8_t * args);
int _I2S_IRQCmd(uint8_t * args);
int _I2S_IRQConfig(uint8_t * args);
int _I2S_Stop(uint8_t * args);
int _I2S_DMAConfig(uint8_t * args);
int _I2S_ModeConfig(uint8_t * args);
int _I2S_GetIRQStatus(uint8_t * args);
int _I2S_CFG_Type_malloc(uint8_t * args);
int _I2S_CFG_Type_wordwidth(uint8_t * args);
int _I2S_CFG_Type_mono(uint8_t * args);
int _I2S_CFG_Type_stop(uint8_t * args);
int _I2S_CFG_Type_reset(uint8_t * args);
int _I2S_CFG_Type_ws_sel(uint8_t * args);
int _I2S_CFG_Type_mute(uint8_t * args);
int _I2S_DMAConf_Type_malloc(uint8_t * args);
int _I2S_DMAConf_Type_DMAIndex(uint8_t * args);
int _I2S_DMAConf_Type_depth(uint8_t * args);
int _I2S_MODEConf_Type_malloc(uint8_t * args);
int _I2S_MODEConf_Type_clksel(uint8_t * args);
int _I2S_MODEConf_Type_fpin(uint8_t * args);
int _I2S_MODEConf_Type_mcena(uint8_t * args);

#endif
