/*******************************************************************************
 * @file
 * @purpose		
 * @version		0.1
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
 * 	list of conditions and the following disclaimer.
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

#include "ringbuffer.h"


inline void ringBufferInit(RingBuffer * rb_ptr)
{
	rb_ptr->rdIdx = 0;
	rb_ptr->wrIdx = 0;
}


inline int ringBufferIsFull(RingBuffer * rb_ptr)
{
	return (rb_ptr->rdIdx == ((rb_ptr->wrIdx + 1) % BUFFER_SIZE));
}

inline int ringBufferIsEmpty(RingBuffer * rb_ptr)
{
    return (rb_ptr->rdIdx == rb_ptr->wrIdx);
}

inline int ringBufferUsed(RingBuffer * rb_ptr)
{
	return((rb_ptr->wrIdx >= rb_ptr->rdIdx) ? (rb_ptr->wrIdx - rb_ptr->rdIdx) : (BUFFER_SIZE - (rb_ptr->rdIdx - rb_ptr->wrIdx)));
}

inline int ringBufferContigUsed(RingBuffer * rb_ptr)
{
    return((rb_ptr->wrIdx >= rb_ptr->rdIdx) ? (rb_ptr->wrIdx - rb_ptr->rdIdx) : (BUFFER_SIZE - rb_ptr->rdIdx));
}

inline int ringBufferEnque(RingBuffer * rb_ptr, uint8_t val)
{
    int isFull = ringBufferIsFull(rb_ptr);
    if (!isFull)
    {
    	rb_ptr->data[rb_ptr->wrIdx] = val;
    	rb_ptr->wrIdx++;
    	rb_ptr->wrIdx %= BUFFER_SIZE;
    }
    return isFull;
}

inline int ringBufferDeEnque(RingBuffer * rb_ptr)
{
	int isEmpty = ringBufferIsEmpty(rb_ptr);
	if (!isEmpty)
	{
		if (rb_ptr->wrIdx == 0)
			rb_ptr->wrIdx = BUFFER_SIZE;
		rb_ptr->wrIdx--;
		return 0;
	}
	return 1;
}

inline int ringBufferDeque(RingBuffer * rb_ptr, uint8_t* val_ptr)
{
    int isEmpty =  ringBufferIsEmpty(rb_ptr);
    if(!isEmpty)
    {
        *val_ptr = rb_ptr->data[rb_ptr->rdIdx];
        rb_ptr->rdIdx++;
        rb_ptr->rdIdx %= BUFFER_SIZE;
    }
    return(isEmpty);
}
