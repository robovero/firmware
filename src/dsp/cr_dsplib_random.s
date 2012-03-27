/*****************************************************************************
 * $Id:: cr_dsplib_random.s 3698 2010-06-10 23:29:17Z nxp27266         $   
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: Random Number Generator Implementation
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
//
//	Implements a linear-congruental random number generator
//	y = (a.Xn + c) mod m
//
//	From Knuth: a=16644525, c=32767
//
	.syntax unified
	.thumb
	.thumb_func

	.global iF_RandomNumber

iF_RandomNumber:
	ldr r1,=16644525	//a
	ldr r2,=32767		//c
	mla r0,r1,r0,r2		//(a*seed) + c
	bx lr
	.end

/*****************************************************************************
 **                            End Of File
 *****************************************************************************/	
