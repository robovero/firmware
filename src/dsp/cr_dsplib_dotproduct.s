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
	.syntax unified
	.thumb
	.thumb_func
  .global iF_dspl_dotproduct32

iF_dspl_dotproduct32:
	push {r4,r5}

innerloop:
	ldr r4,[r0],#4
	ldr r5,[r1],#4
	mla r3,r4,r5,r3
	subs r2,r2,#1
	bne innerloop
	pop {r4,r5}
	bx lr

	.end
	
/*****************************************************************************
 **                            End Of File
 *****************************************************************************/	
