/*****************************************************************************
 * $Id:: cr_dsplib_dotproduct.s 3698 2010-06-10 23:29:17Z nxp27266     $    
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: Dot Product Implementation
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
#define pi_y 		r1
#define i_VectorLen 		r2
#define i_Acc 		r3
#define i_x 		r4
#define i_y 		r5

	.syntax unified
	.thumb

	.thumb_func
  .global iF_dspl_dotproduct32

iF_dspl_dotproduct32:
	push {i_x,i_y}
	mov i_Acc,#0

innerloop:
	ldr i_x,[pi_x],#4
	ldr i_y,[pi_y],#4
  mul i_x,i_x,i_y
  add i_Acc,i_x,i_Acc
  subs i_VectorLen,i_VectorLen,#1
  bne innerloop

  mov r0,i_Acc	//return value
  pop {i_x,i_y}
  bx lr

	.end

/*****************************************************************************
 **                            End Of File
 *****************************************************************************/	
