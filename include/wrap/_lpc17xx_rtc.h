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

#ifndef ___LPC17XX_RTC_H__
#define ___LPC17XX_RTC_H__

#include "lpc_types.h"

int _RTC_CntIncrIntConfig(uint8_t * args);
int _RTC_ClearIntPending(uint8_t * args);
int _RTC_SetFullTime(uint8_t * args);
int _RTC_SetAlarmTime(uint8_t * args);
int _RTC_GetIntPending(uint8_t * args);
int _RTC_SetTime(uint8_t * args);
int _RTC_GetFullAlarmTime(uint8_t * args);
int _RTC_DeInit(uint8_t * args);
int _RTC_Init(uint8_t * args);
int _RTC_ReadGPREG(uint8_t * args);
int _RTC_GetAlarmTime(uint8_t * args);
int _RTC_AlarmIntConfig(uint8_t * args);
int _RTC_GetTime(uint8_t * args);
int _RTC_CalibCounterCmd(uint8_t * args);
int _RTC_GetFullTime(uint8_t * args);
int _RTC_CalibConfig(uint8_t * args);
int _RTC_Cmd(uint8_t * args);
int _RTC_SetFullAlarmTime(uint8_t * args);
int _RTC_WriteGPREG(uint8_t * args);
int _RTC_ResetClockTickCounter(uint8_t * args);
int _RTC_INT_OPT_malloc(uint8_t * args);
int _RTC_TIME_Type_malloc(uint8_t * args);
int _RTC_TIME_Type_SEC(uint8_t * args);
int _RTC_TIME_Type_MIN(uint8_t * args);
int _RTC_TIME_Type_HOUR(uint8_t * args);
int _RTC_TIME_Type_DOM(uint8_t * args);
int _RTC_TIME_Type_DOW(uint8_t * args);
int _RTC_TIME_Type_DOY(uint8_t * args);
int _RTC_TIME_Type_MONTH(uint8_t * args);
int _RTC_TIME_Type_YEAR(uint8_t * args);
int _RTC_TIMETYPE_Num_malloc(uint8_t * args);

#endif
