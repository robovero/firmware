/*****************************************************************************
 * $Id:: cr_dsplib.h 3698 2010-06-10 23:29:17Z nxp27266                $
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: Definition of DSP Library API
 *
 * Copyright(C) 2010, NXP Semiconductor
 * All rights reserved.
 *
 * Developed for NXP by Code Red Technologies Inc. www.code-red-tech.com
 *
 *****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 *****************************************************************************/
#ifndef CR_DSPLIB_H_
#define CR_DSPLIB_H_

typedef struct
{
	int i_Coeff_a1;
	int i_yn_1;
	int i_yn_2;
}tS_ResonatorStateCoeff;

void vF_dspl_resonator(int *psi_Output, void *pS_ResonatorStateCoeff, int i_NSamples);

typedef struct
{
	int *pi_Coeff;
	int NTaps;
}tS_blockfir32_Coeff;

void vF_dspl_blockfir32(int *pi_y, int *pi_x, tS_blockfir32_Coeff *pS_Coeff, int i_nsamples);

typedef struct
{
	short int pi_Coeff[5];
	short int pi_State[2];
}tS_biquad32_StateCoeff;

void vF_dspl_biquad32(int *pi_Output, int *pi_Input, tS_biquad32_StateCoeff *pS_StateCoeff, int i_NSamples);

typedef struct
{
	short int Kp;
	short int Ki;
	short int Kd;
	short int IntegratedError;
	short int LastError;
}tS_pid_Coeff;

short int vF_dspl_pid(short int si_Error, tS_pid_Coeff *pS_Coeff);

int iF_dspl_dotproduct32(int *pi_x, int *pi_y, int i_VectorLen);
void vF_dspl_biquad32c(int *pi_y, int *pi_x, int *pi_Coeff, int *pi_State, int i_nsamples);
int iF_RandomNumber(int i_Seed);

int iF_dspl_vectsumofsquares32(int *pi_x, int i_VectorLen);
int iF_dspl_vectsumofsquares16(short int *psi_x, int i_VectorLen);

void vF_dspl_vectmulconst32(int *pi_y, int *pi_x, int i_c, int i_VectorLen);
void vF_dspl_vectmulconst16(short int *psi_y, short int *psi_x, short int si_c, int i_VectorLen);

void vF_dspl_vectmulelement32(int *pi_z, int *pi_x, int *pi_y, int i_VectorLen);
void vF_dspl_vectmulelement16(int *psi_z, int *psi_x, int *psi_y, int i_VectorLen);

void vF_dspl_vectaddconst32(int *pi_y, int *pi_x, int i_c, int i_VectorLen);
void vF_dspl_vectaddconst16(int *psi_y, int *psi_x, int si_c, int i_VectorLen);

void vF_dspl_vectsub32(int *pi_z, int *pi_x, int *pi_y, int i_VectorLen);
void vF_dspl_vectsub16(int *psi_z, int *psi_x, int *psi_y, int i_VectorLen);

void vF_dspl_vectadd32(int *pi_z, int *pi_x, int *pi_y, int i_VectorLen);
void vF_dspl_vectadd16(int *psi_z, int *psi_x, int *psi_y, int i_VectorLen);

void vF_dspl_fftR4b16N64(short int *psi_Y, short int *psi_x);
void vF_dspl_fftR4b16N256(short int *psi_Y, short int *psi_x);
void vF_dspl_fftR4b16N1024(short int *psi_Y, short int *psi_x);
void vF_dspl_fftR4b16N4096(short int *psi_Y, short int *psi_x);

#endif /*CR_DSPLIB_H_*/

/*****************************************************************************
 **                            End Of File
 *****************************************************************************/
