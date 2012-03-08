/*******************************************************************************
 * @file
 * @purpose		
 * @version		0.1
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

#include "cr_dsplib.h"

#include "return.h"

int _vF_dspl_resonator(uint8_t * args)
{
  uint8_t * arg_ptr;
  int * psi_Output;
  void * pS_ResonatorStateCoeff;
	int i_NSamples;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_Output = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pS_ResonatorStateCoeff = (void *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_NSamples = (int) strtoul((char *) arg_ptr, NULL, 16);


  vF_dspl_resonator(psi_Output, pS_ResonatorStateCoeff, i_NSamples);
  return 0;
}

int _vF_dspl_blockfir32(uint8_t * args)
{
  uint8_t * arg_ptr;
  int * pi_y;
  int * pi_x;
  tS_blockfir32_Coeff *pS_Coeff;
	int i_NSamples;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pS_Coeff = (tS_blockfir32_Coeff *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_NSamples = (int) strtoul((char *) arg_ptr, NULL, 16);


  vF_dspl_blockfir32(pi_y, pi_x, pS_Coeff, i_NSamples);
  return 0;
}

int _vF_dspl_biquad32(uint8_t * args)
{
  uint8_t * arg_ptr;
  int * pi_Output;
  int * pi_Input;
	tS_biquad32_StateCoeff * pS_StateCoeff;
  int i_NSamples;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_Output = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_Input = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pS_StateCoeff = (tS_biquad32_StateCoeff *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_NSamples = (int) strtoul((char *) arg_ptr, NULL, 16);

  vF_dspl_biquad32(pi_Output, pi_Input, pS_StateCoeff, i_NSamples);
  return 0;
}

int _iF_dspl_dotproduct32(uint8_t * args)
{
	uint8_t * arg_ptr;
  int * pi_x;
  int * pi_y;
  int i_VectorLen;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%i\r\n", iF_dspl_dotproduct32(pi_x, pi_y, i_VectorLen));
	writeUSBOutString(str);
	return 0;
}

int _vF_dspl_pid(uint8_t * args)
{
  uint8_t * arg_ptr;
  uint8_t si_Error;
  tS_pid_Coeff * pS_Coeff;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	si_Error = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pS_Coeff = (tS_pid_Coeff *) strtoul((char *) arg_ptr, NULL, 16);

  sprintf((char *) str, "%x\r\n", (unsigned int) vF_dspl_pid(si_Error, pS_Coeff));
  writeUSBOutString(str);
  return 0;
}

int _iF_RandomNumber(uint8_t * args)
{
	uint8_t * arg_ptr;
	uint16_t i_Seed;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_Seed = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (uint16_t) iF_RandomNumber(i_Seed));
	writeUSBOutString(str);
	return 0;
}

int _iF_dspl_vectsumofsquares32(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * pi_x;
  int i_VectorLen;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) iF_dspl_vectsumofsquares32(pi_x, i_VectorLen));
	writeUSBOutString(str);
	return 0;
}

int _iF_dspl_vectsumofsquares16(uint8_t * args)
{
	uint8_t * arg_ptr;
	short int * psi_x;
  int i_VectorLen;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (short int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	sprintf((char *) str, "%x\r\n", (unsigned int) iF_dspl_vectsumofsquares16(psi_x, i_VectorLen));
	writeUSBOutString(str);
	return 0;
}

int _vF_dspl_vectmulconst32(uint8_t * args)
{
	uint8_t * arg_ptr;
  int * pi_y;
	int * pi_x;
  int i_c;
  int i_VectorLen;

	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_c = (int) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	iF_dspl_vectmulconst32(pi_y, pi_x, i_c, i_VectorLen);
	return 0;
}

int _vF_dspl_vectmulconst16(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * psi_y;
  int * psi_x;
  int si_c;
  int i_VectorLen;

  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	si_c = (int) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	iF_dspl_vectmulconst16(psi_y, psi_x, si_c, i_VectorLen);
	return 0;
}

int _vF_dspl_vectmulelement32(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * pi_z;
  int * pi_x;
  int * pi_y;
  int i_VectorLen;

  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_z = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	vF_dspl_vectmulelement32(pi_z, pi_x, pi_y, i_VectorLen);
	return 0;
}

int _vF_dspl_vectmulelement16(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * psi_z;
  int * psi_x;
  int * psi_y;
  int i_VectorLen;

  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_z = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	vF_dspl_vectmulelement16(psi_z, psi_x, psi_y, i_VectorLen);
	return 0;
}

int _vF_dspl_vectaddconst32(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * pi_y;
  int * pi_x;
  int i_c;
  int i_VectorLen;

  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_c = (int) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	vF_dspl_vectaddconst32(pi_y, pi_x, i_c, i_VectorLen);
	return 0;
}

int _vF_dspl_vectaddconst16(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * psi_y;
  int * psi_x;
  int si_c;
  int i_VectorLen;

  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	si_c = (int) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	vF_dspl_vectaddconst16(psi_y, psi_x, si_c, i_VectorLen);
	return 0;
}

int _vF_dspl_vectsub32(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * pi_z;
  int * pi_x;
  int * pi_y;
  int i_VectorLen;

  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_z = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	vF_dspl_vectsub32(pi_z, pi_x, pi_y, i_VectorLen);
	return 0;
}

int _vF_dspl_vectsub16(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * psi_z;
  int * psi_x;
  int * psi_y;
  int i_VectorLen;

  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	vF_dspl_vectsub16(psi_z, psi_x, psi_y, i_VectorLen);
	return 0;
}

int _vF_dspl_vectadd32(uint8_t * args)
{
	uint8_t * arg_ptr;
	int * pi_z;
  int * pi_x;
  int * pi_y;
  int i_VectorLen;

  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_z = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	pi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

	vF_dspl_vectadd32(pi_z, pi_x, pi_y, i_VectorLen);
	return 0;
}

int _vF_dspl_vectadd16(uint8_t * args)
{
  uint8_t * arg_ptr;
  int * psi_z;
  int * psi_x;
  int * psi_y;
  int i_VectorLen;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_z = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_y = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
  i_VectorLen = (int) strtoul((char *) arg_ptr, NULL, 16);

  vF_dspl_vectadd16(psi_z, psi_x, psi_y, i_VectorLen);
  return 0;
}

int _vF_dspl_fftR4b16N64(uint8_t * args)
{
  uint8_t * arg_ptr;
  int * psi_Y;
  int * psi_x;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_Y = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;

  vF_dspl_fftR4b16N64(psi_Y, psi_x);
  return 0;
}

int _vF_dspl_fftR4b16N256(uint8_t * args)
{
  uint8_t * arg_ptr;
  int * psi_Y;
  int * psi_x;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_Y = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;

  vF_dspl_fftR4b16N256(psi_Y, psi_x);
  return 0;
}

int _vF_dspl_fftR4b16N1024(uint8_t * args)
{
  uint8_t * arg_ptr;
  int * psi_Y;
  int * psi_x;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_Y = (int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;

  vF_dspl_fftR4b16N1024(psi_Y, psi_x);
  return 0;
}

int _vF_dspl_fftR4b16N4096(uint8_t * args)
{
  uint8_t * arg_ptr;
  short int * psi_Y;
  short int * psi_x;
  
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_Y = (short int *) strtoul((char *) arg_ptr, NULL, 16);
	if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
	psi_x = (short int *) strtoul((char *) arg_ptr, NULL, 16);
  if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;

  vF_dspl_fftR4b16N4096(psi_Y, psi_x);
  return 0;
}
