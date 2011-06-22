/*******************************************************************************
 * @file
 * @purpose		
 * @version		0.1
 *------------------------------------------------------------------------------
 * Copyright (C) 2011 Gumstix Inc.
 * All rights reserved.
 *
 * Contributer(s):
 *   Neil MacMunn   <neil@gumstix.com>
 *------------------------------------------------------------------------------
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * Redistributions of source code must retain the above copyright notice, this
 * 	list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#include "system_LPC17xx.h"


void ResetISR(void);
static void NmiSR(void);
static void FaultISR(void);
static void IntDefaultHandler(void);


extern void USB_IRQHandler(void);
extern void IntHandler(void);
extern int main(void);

/*
 * Reserve space for the stack and heap
 */
__attribute__ ((section(".stack")))
static unsigned long pulStack[0x400];

__attribute__ ((section(".heap")))
static unsigned long pulHeap[0x800];

/*
 * Vector table
 */
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
    (void (*)(void))((unsigned long)pulStack + sizeof(pulStack)),   /* SP     */
    ResetISR,                             /* Reset Handler                    */
    NmiSR,                                /* NMI Handler                      */
    FaultISR,                             /* Hard Fault Handler               */
    IntDefaultHandler,                    /* MPU Fault Handler                */
    IntDefaultHandler,                    /* Bus Fault Handler                */
    IntDefaultHandler,                    /* Usage Fault Handler              */
    0,                                    /* Reserved                         */
    0,                                    /* Reserved                         */
    0,                                    /* Reserved                         */
    0,                                    /* Reserved                         */
    IntDefaultHandler,                    /* SVCall Handler                   */
    IntDefaultHandler,                    /* Debug Monitor Handler            */
    0,                                    /* Reserved                         */
    IntDefaultHandler,                    /* PendSV Handler                   */
    IntDefaultHandler,                    /* SysTick Handler                  */

    IntHandler,                           /* 16: Watchdog Timer               */
    IntHandler,                           /* 17: Timer0                       */
    IntHandler,                           /* 18: Timer1                       */
    IntHandler,                           /* 19: Timer2                       */
    IntHandler,                           /* 20: Timer3                       */
    IntHandler,                           /* 21: UART0                        */
    IntHandler,                           /* 22: UART1                        */
    IntHandler,                           /* 23: UART2                        */
    IntHandler,                           /* 24: UART3                        */
    IntHandler,                           /* 25: PWM1                         */
    IntHandler,                           /* 26: I2C0                         */
    IntHandler,                           /* 27: I2C1                         */
    IntHandler,                           /* 28: I2C2                         */
    IntHandler,                           /* 29: SPI                          */
    IntHandler,                           /* 30: SSP0                         */
    IntHandler,                           /* 31: SSP1                         */
    IntHandler,                           /* 32: PLL0 Lock (Main PLL)         */
    IntHandler,                           /* 33: Real Time Clock              */
    IntHandler,                           /* 34: External Interrupt 0         */
    IntHandler,                           /* 35: External Interrupt 1         */
    IntHandler,                           /* 36: External Interrupt 2         */
    IntHandler,                           /* 37: External Interrupt 3         */
    IntHandler,                           /* 38: A/D Converter                */
    IntHandler,                           /* 39: Brown-Out Detect             */
    USB_IRQHandler,                       /* 40: USB                          */
    IntHandler,                           /* 41: CAN                          */
    IntHandler,                           /* 42: General Purpose DMA          */
    IntHandler,                           /* 43: I2S                          */
    IntHandler,                           /* 44: Ethernet                     */
    IntHandler,                           /* 45: Repetitive Interrupt Timer   */
    IntHandler,                           /* 46: Motor Control PWM            */
    IntHandler,                           /* 47: Quadrature Encoder Interface */
    IntHandler,                           /* 48: PLL1 Lock (USB PLL)          */
    IntHandler,                           /* 49: USB Activity                 */
    IntHandler                            /* 50: CAN Activity                 */
};

/*
 * Variables are created by the linker
 */
extern unsigned long _etext;
extern unsigned long _data;
extern unsigned long _edata;
extern unsigned long _bss;
extern unsigned long _ebss;
extern unsigned long _estack;

void ResetISR(void)
{
    unsigned long *pulSrc, *pulDest;

    /*
     * Set the stack pointer
     */
    __asm("    ldr     sp, =_estack\n");

    /*
     * Initialize the system clock
     */
    SystemInit();

    /*
     * Copy the data segment initializers from flash to SRAM.
     */
    pulSrc = &_etext;
    for(pulDest = &_data; pulDest < &_edata; )
    {
        *pulDest++ = *pulSrc++;
    }

    /*
     * Zero fill the bss segment.
     */
    __asm("    ldr     r0, =_bss\n"
          "    ldr     r1, =_ebss\n"
          "    mov     r2, #0\n"
          "    .thumb_func\n"
          "zero_loop:\n"
          "        cmp     r0, r1\n"
          "        it      lt\n"
          "        strlt   r2, [r0], #4\n"
          "        blt     zero_loop");


    /*
     * Call the application's entry point.
     */
    main();
}

/*
 * Non-maskable interrupt
 */
static void NmiSR(void)
{
    while(1);
}

/*
 * System fault
 */
static void FaultISR(void)
{
    while(1);
}


/*
 * Unexpected interrupt
 */
static void IntDefaultHandler(void)
{
    while(1);
}

