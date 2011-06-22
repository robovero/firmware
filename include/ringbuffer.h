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

#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__

#include "lpc_types.h"

#define BUFFER_SIZE		256

typedef struct {
  uint8_t data[BUFFER_SIZE];
  int wrIdx;
  int rdIdx;
} RingBuffer;

/*
 * initialize a ring buffer
 */
inline void ringBufferInit(RingBuffer * rb_ptr);

/*
 * check if a ring buffer is full
 */
inline int ringBufferIsFull(RingBuffer * rb_ptr);

/*
 * check if a ring buffer is empty
 */
inline int ringBufferIsEmpty(RingBuffer * rb_ptr);

/*
 * number of bytes stored in the ring buffer
 */
inline int ringBufferUsed(RingBuffer * rb_ptr);

/*
 * number of bytes stored in the ring buffer that don't straddle the buffer wrap
 */
inline int ringBufferContigUsed(RingBuffer * rb_ptr);

/*
 * copy one byte into a ring buffer
 */
inline int ringBufferEnque(RingBuffer * rb_ptr, uint8_t val);

/*
 * discard one byte from the ring buffer
 */
inline int ringBufferDeEnque(RingBuffer * rb_ptr);

/*
 * get one byte from a ring buffer
 */
inline int ringBufferDeque(RingBuffer * rb_ptr, uint8_t* val_ptr);

#endif /* RINGBUFFER_H_ */
