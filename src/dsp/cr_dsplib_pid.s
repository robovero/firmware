/*****************************************************************************
 * $Id:: cr_dsplib_pid.s 3698 2010-06-10 23:29:17Z nxp27266            $   
 *
 * Project: NXP LPC1000 Cortex-M3 family DSP library
 *
 * Description: PID Controller Implementation
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

#define si_Error 	r0
#define pS_StateCoeff 	r1
#define Kp 		r3
#define Ki 		r4
#define Kd 		r5
#define IntegratedError r6
#define LastError 	r6
#define Temp 		r6
#define Acc 		r7

	.thumb_func
	.global vF_dspl_pid

vF_dspl_pid:
	push {r4-r7}

	ldrsh Kp,[pS_StateCoeff]
	ldrsh Ki,[pS_StateCoeff,#2]
	ldrsh Kd,[pS_StateCoeff,#4]
	ldrsh IntegratedError,[pS_StateCoeff,#6]

	mla Acc,Ki,si_Error,IntegratedError	//update integrated error
	strh Acc,[pS_StateCoeff,#6]		//store to state

	ldrsh LastError,[pS_StateCoeff,#8]
	strh si_Error,[pS_StateCoeff,#8]
	
  mla Acc,Kp,si_Error,Acc			//add in proportional part
	
	sub Temp,LastError,si_Error
	
  mla Acc,Kd,Temp,Acc			//add in the difference part
	
	//mov r0,Acc,ASR#16			//scale down to short int
	mov r0,Acc
  pop {r4-r7}
	bx lr

	.end
	
/*****************************************************************************
 **                            End Of File
 *****************************************************************************/
