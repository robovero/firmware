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

#ifndef ___LPC17XX_MCPWM_H__
#define ___LPC17XX_MCPWM_H__

#include "lpc_types.h"

int _MCPWM_ConfigCapture(uint8_t * args);
int _MCPWM_IntConfig(uint8_t * args);
int _MCPWM_ACMode(uint8_t * args);
int _MCPWM_Init(uint8_t * args);
int _MCPWM_GetIntStatus(uint8_t * args);
int _MCPWM_Stop(uint8_t * args);
int _MCPWM_Start(uint8_t * args);
int _MCPWM_GetCapture(uint8_t * args);
int _MCPWM_IntSet(uint8_t * args);
int _MCPWM_ConfigChannel(uint8_t * args);
int _MCPWM_ClearCapture(uint8_t * args);
int _MCPWM_DCMode(uint8_t * args);
int _MCPWM_CountConfig(uint8_t * args);
int _MCPWM_WriteToShadow(uint8_t * args);
int _MCPWM_IntClear(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_malloc(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_channelType(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_channelPolarity(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_channelDeadtimeEnable(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_channelDeadtimeValue(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_channelUpdateEnable(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_channelTimercounterValue(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_channelPeriodValue(uint8_t * args);
int _MCPWM_CHANNEL_CFG_Type_channelPulsewidthValue(uint8_t * args);
int _MCPWM_COUNT_CFG_Type_malloc(uint8_t * args);
int _MCPWM_COUNT_CFG_Type_counterChannel(uint8_t * args);
int _MCPWM_COUNT_CFG_Type_countRising(uint8_t * args);
int _MCPWM_COUNT_CFG_Type_countFalling(uint8_t * args);
int _MCPWM_CAPTURE_CFG_Type_malloc(uint8_t * args);
int _MCPWM_CAPTURE_CFG_Type_captureChannel(uint8_t * args);
int _MCPWM_CAPTURE_CFG_Type_captureRising(uint8_t * args);
int _MCPWM_CAPTURE_CFG_Type_captureFalling(uint8_t * args);
int _MCPWM_CAPTURE_CFG_Type_timerReset(uint8_t * args);
int _MCPWM_CAPTURE_CFG_Type_hnfEnable(uint8_t * args);

#endif
