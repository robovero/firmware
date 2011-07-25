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

//#include "core_cm3.h"
#include "LPC17xx.h"

#include "return.h"


int _NVIC_EnableIRQ(uint8_t * args)
{
    uint8_t * arg_ptr;
    IRQn_Type IRQn;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    IRQn = (IRQn_Type) strtoul((char *) arg_ptr, NULL, 16);

    NVIC_EnableIRQ(IRQn);
    return 0;
}

int _NVIC_ClearPendingIRQ(uint8_t * args)
{
    uint8_t * arg_ptr;
    IRQn_Type IRQn;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    IRQn = (IRQn_Type) strtoul((char *) arg_ptr, NULL, 16);

    NVIC_ClearPendingIRQ(IRQn);
    return 0;
}

