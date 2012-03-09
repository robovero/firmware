/*****************************************************************************
 * $Id:: cr_dsplib_vectormulconst.s 3698 2010-06-10 23:29:17Z nxp27266 $   
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: Vector Constant Multiplication Implementation
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
	.syntax unified
	.thumb

#define pi_y 		r0
#define pi_x 		r1
#define i_c 		r2
#define i_VectorLen 	r3
#define i_Acc 		r4

	.thumb_func
	.global vF_dspl_vectmulconst32

vF_dspl_vectmulconst32:
	push {r4}

innerloop:
	ldr i_Acc,[pi_x],#4
	subs i_VectorLen,i_VectorLen,#1
	mul i_Acc,i_Acc,i_c
	str i_Acc,[pi_y],#4
	bne innerloop
	
	pop {r4}
	bx lr
	
#define psi_y 		r0
#define psi_x 		r1
#define si_c 		r2

	.thumb_func
	.global vF_dspl_vectmulconst16

vF_dspl_vectmulconst16:
	push {r4}

innerloop16:
	ldrsh i_Acc,[psi_x],#2
	subs i_VectorLen,i_VectorLen,#1
	mul i_Acc,i_Acc,si_c
	strh i_Acc,[psi_y],#2
	bne innerloop16
	
	pop {r4}
	bx lr
	
	.end

/*****************************************************************************
 **                            End Of File
 *****************************************************************************/
