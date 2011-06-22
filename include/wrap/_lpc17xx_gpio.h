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

#ifndef ___LPC17XX_GPIO_H__
#define ___LPC17XX_GPIO_H__

#include "lpc_types.h"

int _FIO_IntCmd(uint8_t * args);
int _GPIO_ClearInt(uint8_t * args);
int _GPIO_GetIntStatus(uint8_t * args);
int _FIO_HalfWordClearValue(uint8_t * args);
int _GPIO_IntCmd(uint8_t * args);
int _FIO_ClearInt(uint8_t * args);
int _FIO_ByteSetValue(uint8_t * args);
int _GPIO_ReadValue(uint8_t * args);
int _FIO_ByteSetDir(uint8_t * args);
int _FIO_HalfWordSetDir(uint8_t * args);
int _FIO_SetValue(uint8_t * args);
int _FIO_GetIntStatus(uint8_t * args);
int _FIO_HalfWordSetValue(uint8_t * args);
int _FIO_ByteClearValue(uint8_t * args);
int _FIO_ByteReadValue(uint8_t * args);
int _GPIO_ClearValue(uint8_t * args);
int _FIO_ClearValue(uint8_t * args);
int _FIO_SetDir(uint8_t * args);
int _FIO_SetMask(uint8_t * args);
int _FIO_HalfWordReadValue(uint8_t * args);
int _FIO_ByteSetMask(uint8_t * args);
int _FIO_ReadValue(uint8_t * args);
int _GPIO_SetValue(uint8_t * args);
int _FIO_HalfWordSetMask(uint8_t * args);
int _GPIO_SetDir(uint8_t * args);
int _GPIO_Byte_TypeDef_malloc(uint8_t * args);
//int _GPIO_Byte_TypeDef_FIODIR[4](uint8_t * args);
//int _GPIO_Byte_TypeDef_FIOMASK[4](uint8_t * args);
//int _GPIO_Byte_TypeDef_FIOPIN[4](uint8_t * args);
//int _GPIO_Byte_TypeDef_FIOSET[4](uint8_t * args);
//int _GPIO_Byte_TypeDef_FIOCLR[4](uint8_t * args);
int _GPIO_HalfWord_TypeDef_malloc(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIODIRL(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIODIRU(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIOMASKL(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIOMASKU(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIOPINL(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIOPINU(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIOSETL(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIOSETU(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIOCLRL(uint8_t * args);
int _GPIO_HalfWord_TypeDef_FIOCLRU(uint8_t * args);

#endif
