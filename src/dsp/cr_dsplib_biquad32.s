/*****************************************************************************
 * $Id:: cr_dsplib_biquad32.s 3698 2010-06-10 23:29:17Z nxp27266       $   
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: Biquad (IIR) Filter Implementation
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
//
// Using 2.14 x 2.14 ->4.28 arithmetic with no saturation
//
#define pi_Output 	r0
#define pi_Input 	r1
#define pS_StateCoeff 	r2
#define i_NSamples 	r3
#define a1	 	r4
#define a2 		r5
#define b0 		r6
#define b1 		r7
#define b2 		r8
#define yn_1 		r9
#define yn_2 		r10
#define Acc1 		r11
#define xn 		r12
#define Acc2 		r14

	.thumb_func
	.global vF_dspl_biquad32

vF_dspl_biquad32:
	push {r4-r12,r14}

	ldrsh r4,[pS_StateCoeff]
	ldrsh r5,[pS_StateCoeff,#2]
	ldrsh r6,[pS_StateCoeff,#4]
	ldrsh r7,[pS_StateCoeff,#6]
	ldrsh r8,[pS_StateCoeff,#8]
	ldrsh r9,[pS_StateCoeff,#10]
	ldrsh r10,[pS_StateCoeff,#12]
	
InnerLoop:
	ldr xn,[pi_Input],#4
	
	//compute recusrive part
	mla Acc1,a1,yn_1,xn
	mla Acc1,a2,yn_2,Acc1

	//compute non-recursive part
	mov Acc1,Acc1,ASR#14		//normalize back to 2.14
	mul Acc2,b0,Acc1
	mla Acc2,b1,yn_1,Acc2
	mla Acc2,b2,yn_2,Acc2
	
	//update the state
	mov yn_2,yn_1
	mov yn_1,Acc1
	
	//store result
	str Acc2,[pi_Output],#4
	
	subs.n i_NSamples,i_NSamples,#1
	bne.n InnerLoop

	//store updated state to memory	
	strh yn_1, [pS_StateCoeff,#(2*5)]
	strh yn_2, [pS_StateCoeff,#(2*6)]
	
	pop {r4-r12,r14}
	bx lr

	.end
	
/*****************************************************************************
 **                            End Of File
 *****************************************************************************/	
