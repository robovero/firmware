/*****************************************************************************
 * $Id:: cr_dsplib_resonator.s 3698 2010-06-10 23:29:17Z nxp27266      $   
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: Resonator Implementation
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

#define psi_Output 	r0
#define pS_StateCoeff 	r1
#define i_NSamples 	r2
#define a1 		r3
#define yn_1 		r4
#define yn_2 		r5
#define Acc 		r6

	.thumb_func
	.global vF_dspl_resonator

vF_dspl_resonator:
	push {r3-r6}

	ldmia pS_StateCoeff,{r3-r5}
	mvn yn_2,yn_2,asl#14

InnerLoop:
	mla Acc,a1,yn_1,yn_2
	mvn yn_2,yn_1,ASL#14
	mov yn_1,Acc,ASR#14
	str yn_1,[psi_Output],#4
	subs.n i_NSamples,i_NSamples,#1
	bne.n InnerLoop
	
	str yn_1, [pS_StateCoeff,#8]
	mvn yn_2,yn_2,ASR#14
	str yn_2, [pS_StateCoeff,#12]
	
	pop {r3-r6}
	bx lr

	.end
	
/*****************************************************************************
 **                            End Of File
 *****************************************************************************/
