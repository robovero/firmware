/*******************************************************************************
 * @file
 * @purpose        
 * @version        0.1
 *------------------------------------------------------------------------------
 * Copyright (C) 2012 Gumstix Inc.
 * All rights reserved.
 *
 * Contributer(s):
 *   Danny Chan   <danny@gumstix.com>
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

#ifndef ___CR_DSPLIB_H__
#define ___CR_DSPLIB_H__

#include "lpc_types.h"

int _vF_dspl_resonator(uint8_t * args);
int _vF_dspl_blockfir32(uint8_t * args);
int _vF_dspl_biquad32(uint8_t * args);
int _vF_dspl_pid(uint8_t * args);
int _iF_dspl_dotproduct32(uint8_t * args);
int _vF_dspl_biquad32c(uint8_t * args);
int _iF_RandomNumber(uint8_t * args);
int _iF_dspl_vectsumofsquares32(uint8_t * args);
int _iF_dspl_vectsumofsquares16(uint8_t * args);
int _vF_dspl_vectmulconst32(uint8_t * args);
int _vF_dspl_vectmulconst16(uint8_t * args);
int _vF_dspl_vectmulelement32(uint8_t * args);
int _vF_dspl_vectmulelement16(uint8_t * args);
int _vF_dspl_vectaddconst32(uint8_t * args);
int _vF_dspl_vectaddconst16(uint8_t * args);
int _vF_dspl_vectsub32(uint8_t * args);
int _vF_dspl_vectsub16(uint8_t * args);
int _vF_dspl_vectadd32(uint8_t * args);
int _vF_dspl_vectadd16(uint8_t * args);
int _vF_dspl_fftR4b16N64(uint8_t * args);
int _vF_dspl_fftR4b16N256(uint8_t * args);
int _vF_dspl_fftR4b16N1024(uint8_t * args);
int _vF_dspl_fftR4b16N4096(uint8_t * args);
int _tS_ResonatorStateCoeff_malloc(uint8_t * args);
int _tS_ResonatorStateCoeff_i_Coeff_a1(uint8_t * args);
int _tS_ResonatorStateCoeff_i_yn_1(uint8_t * args);
int _tS_ResonatorStateCoeff_i_yn_2(uint8_t * args);
int _tS_blockfir32_Coeff_malloc(uint8_t * args);
int _tS_blockfir32_Coeff_pi_Coeff(uint8_t * args);
int _tS_blockfir32_Coeff_NTaps(uint8_t * args);
int _tS_biquad32_StateCoeff_malloc(uint8_t * args);
int _tS_biquad32_StateCoeff_pi_Coeff0(uint8_t * args);
int _tS_biquad32_StateCoeff_pi_Coeff1(uint8_t * args);
int _tS_biquad32_StateCoeff_pi_Coeff2(uint8_t * args);
int _tS_biquad32_StateCoeff_pi_Coeff3(uint8_t * args);
int _tS_biquad32_StateCoeff_pi_Coeff4(uint8_t * args);
int _tS_biquad32_StateCoeff_pi_State0(uint8_t * args);
int _tS_biquad32_StateCoeff_pi_State1(uint8_t * args);
int _tS_pid_Coeff_malloc(uint8_t * args);
int _tS_pid_Coeff_Kp(uint8_t * args);
int _tS_pid_Coeff_Ki(uint8_t * args);
int _tS_pid_Coeff_Kd(uint8_t * args);
int _tS_pid_Coeff_IntegratedError(uint8_t * args);
int _tS_pid_Coeff_LastError(uint8_t * args);

#endif /*___CR_DSPLIB_H__*/

/*****************************************************************************
 **                            End Of File
 *****************************************************************************/
