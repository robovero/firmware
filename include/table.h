/*******************************************************************************
 * @file
 * @purpose        
 * @version        0.1
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
 *     list of conditions and the following disclaimer.
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

#ifndef __TABLE_H__
#define __TABLE_H__

#include "extras.h"
#include "_lpc17xx_pwm.h"
#include "_lpc17xx_spi.h"
#include "_lpc17xx_rtc.h"
#include "_lpc17xx_rit.h"
#include "_lpc17xx_ssp.h"
#include "_lpc17xx_i2c.h"
#include "_lpc17xx_can.h"
#include "_lpc17xx_exti.h"
#include "_lpc17xx_systick.h"
#include "_debug_frmwrk.h"
#include "_lpc17xx_i2s.h"
#include "_lpc17xx_emac.h"
#include "_lpc17xx_adc.h"
#include "_lpc17xx_mcpwm.h"
#include "_lpc17xx_clkpwr.h"
#include "_lpc17xx_dac.h"
#include "_lpc17xx_wdt.h"
#include "_lpc17xx_libcfg.h"
#include "_lpc17xx_timer.h"
#include "_lpc17xx_gpdma.h"
#include "_lpc17xx_qei.h"
#include "_lpc17xx_uart.h"
#include "_lpc17xx_gpio.h"
#include "_lpc17xx_pinsel.h"
#include "_lpc17xx_nvic.h"
#include "_LPC17xx.h"
#include "_core.h"
#include "_cr_dsplib.h"

typedef struct {
        uint8_t * fcn_name;
        int (*fcn_ptr)(uint8_t *);
} _nxp_function;

extern const _nxp_function driver_table[];
extern int driver_table_len;

#endif

