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

#ifndef ___LPC_TYPES_H__
#define ___LPC_TYPES_H__

#include "lpc_types.h"

int _Status_malloc(uint8_t * args);
int _UNS_8_malloc(uint8_t * args);
int _BOOL_16_malloc(uint8_t * args);
//int _(*PFV)()_malloc(uint8_t * args);
int _INT_8_malloc(uint8_t * args);
int _SetState_malloc(uint8_t * args);
int _UNS_64_malloc(uint8_t * args);
int _FunctionalState_malloc(uint8_t * args);
int _BOOL_32_malloc(uint8_t * args);
int _CHAR_malloc(uint8_t * args);
int _TRANSFER_BLOCK_Type_malloc(uint8_t * args);
int _BOOL_8_malloc(uint8_t * args);
int _Bool_malloc(uint8_t * args);
int _FlagStatus_malloc(uint8_t * args);
int _INT_64_malloc(uint8_t * args);
int _INT_16_malloc(uint8_t * args);
int _IntStatus_malloc(uint8_t * args);
int _UNS_16_malloc(uint8_t * args);
int _INT_32_malloc(uint8_t * args);
int _UNS_32_malloc(uint8_t * args);
//int _(*PFI)()_malloc(uint8_t * args);

#endif
