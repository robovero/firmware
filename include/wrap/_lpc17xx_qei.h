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

#ifndef ___LPC17XX_QEI_H__
#define ___LPC17XX_QEI_H__

#include "lpc_types.h"

int _QEI_GetTimer(uint8_t * args);
int _QEI_DeInit(uint8_t * args);
int _QEI_GetPosition(uint8_t * args);
int _QEI_GetStatus(uint8_t * args);
int _QEI_Reset(uint8_t * args);
int _QEI_SetMaxPosition(uint8_t * args);
int _QEI_GetVelocity(uint8_t * args);
int _QEI_GetVelocityCap(uint8_t * args);
int _QEI_SetPositionComp(uint8_t * args);
int _QEI_SetDigiFilter(uint8_t * args);
int _QEI_IntSet(uint8_t * args);
int _QEI_GetIndex(uint8_t * args);
int _QEI_SetTimerReload(uint8_t * args);
int _QEI_ConfigStructInit(uint8_t * args);
int _QEI_SetVelocityComp(uint8_t * args);
int _QEI_Init(uint8_t * args);
int _QEI_IntCmd(uint8_t * args);
int _QEI_IntClear(uint8_t * args);
int _QEI_GetIntStatus(uint8_t * args);
int _QEI_CalculateRPM(uint8_t * args);
int _QEI_SetIndexComp(uint8_t * args);
int _QEI_CFG_Type_malloc(uint8_t * args);
int _QEI_CFG_Type_DirectionInvert(uint8_t * args);
int _QEI_CFG_Type_SignalMode(uint8_t * args);
int _QEI_CFG_Type_CaptureMode(uint8_t * args);
int _QEI_CFG_Type_InvertIndex(uint8_t * args);
int _QEI_RELOADCFG_Type_malloc(uint8_t * args);
int _QEI_RELOADCFG_Type_ReloadOption(uint8_t * args);
int _QEI_RELOADCFG_Type_ReloadValue(uint8_t * args);

#endif
