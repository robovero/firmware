/*****************************************************************************
 * $Id:: cr_dsplib_vectsumofsquares.s 3698 2010-06-10 23:29:17Z nxp272#$   
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: Vector Sum of Squares Implementation
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
#define pi_x 		r0
#define i_VectorLen 	r1
#define i_x 		r2
#define i_Acc 		r3

	.syntax unified
	.thumb

	.thumb_func
	.global iF_dspl_vectsumofsquares32

iF_dspl_vectsumofsquares32:
	mov i_Acc,#0

innerloop:
	ldr i_x,[pi_x],#4
	subs i_VectorLen,i_VectorLen,#1
  mul i_x,i_x,i_x
  add i_Acc,i_x,i_Acc
	bne innerloop

	mov r0,i_Acc	//return value
	bx lr

	.thumb_func
	.global iF_dspl_vectsumofsquares16

iF_dspl_vectsumofsquares16:
	mov i_Acc,#0

innerloop16:
	ldrsh i_x,[pi_x],#4
	subs i_VectorLen,i_VectorLen,#1
  mul i_x,i_x,i_x
  add i_Acc,i_x,i_Acc
  bne innerloop16

	mov r0,i_Acc	//return value			
	bx lr
	
	.end

/*****************************************************************************
 **                            End Of File
 *****************************************************************************/
	
