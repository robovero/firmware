/*****************************************************************************
 * $Id:: cr_dsplib_blockfir32.s 3698 2010-06-10 23:29:17Z nxp27266     $   
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: FIR Filter Implementation
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

#define py 		r0	//pointer to the output samples
#define px 		r1	//pointer to the input samples
#define pcoeff 		r2	//pointer to the coefficients
#define nSamples 	r3
#define nTaps 		r4
#define c1 		r5
#define Acc0 		r6
#define Acc1 		r7
#define Acc2 		r8
#define Acc3 		r9
#define x0 		r10
#define x1 		r11
#define x2 		r12
#define x3 		r14

//Overloaded
#define c0 		r3	//can do this because we do not need the sample count in the inner loop
#define pS_Coeff 	r2

	.thumb_func
	.global vF_dspl_blockfir32

vF_dspl_blockfir32:
	push {r4-r12,lr}

	ldr nTaps,[pS_Coeff,#4]	//get pointer to the coeffs from the structure
	ldr pcoeff,[pS_Coeff]	//get pointer to the coeffs from the structure

LoopSample:
	mov Acc0,#0
	mov Acc1,Acc0
	mov Acc2,Acc0
	mov Acc3,Acc0
	ldmia px!,{x0,x1,x2,x3}

	push {nSamples, nTaps}	

LoopTaps:
	ldmia pcoeff!,{c0,c1}
	
	mla Acc0,x0,c0,Acc0
	mla Acc1,x1,c0,Acc1
	mla Acc2,x2,c0,Acc2
	mla Acc3,x3,c0,Acc3
	
	ldr x0,[px],#4
	ldr c0,[pcoeff],#4
	
	mla Acc0,x1,c1,Acc0
	mla Acc1,x2,c1,Acc1
	mla Acc2,x3,c1,Acc2
	mla Acc3,x0,c1,Acc3
	
	ldr x1,[px],#4
	ldr c1,[pcoeff],#4
	
	mla Acc0,x2,c0,Acc0
	mla Acc1,x3,c0,Acc1
	mla Acc2,x0,c0,Acc2
	mla Acc3,x1,c0,Acc3
	
	ldr x2,[px],#4

	subs nTaps,nTaps,#4		//hoisted up to avoid pipe delay before branch

	mla Acc0,x3,c1,Acc0
	mla Acc1,x0,c1,Acc1
	mla Acc2,x1,c1,Acc2
	mla Acc3,x2,c1,Acc3

	ldr x3,[px],#4
	
	bne LoopTaps
	
	pop {nSamples, nTaps}
	
	//Store the outputs
	stmia py!,{Acc0,Acc1,Acc2,Acc3}

	subs nSamples,nSamples,#4	//hoisted up to avoid pipe delay before branch
	
	//Reset Coeffs to start
	sub pcoeff,pcoeff,nTaps,LSL#2
	
	//Walk along the input data by 4 samples each LoopSample iteration
	sub px,px,nTaps,LSL#2
	
	bne LoopSample
	
	pop {r4-r12,lr}
	bx lr
	
	.end

/*****************************************************************************
 **                            End Of File
 *****************************************************************************/
	