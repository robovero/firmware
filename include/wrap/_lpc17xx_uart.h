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

#ifndef ___LPC17XX_UART_H__
#define ___LPC17XX_UART_H__

#include "lpc_types.h"

int _UART_RS485SendSlvAddr(uint8_t * args);
int _UART_ABClearIntPending(uint8_t * args);
int _UART_IrDAPulseDivConfig(uint8_t * args);
int _UART_RS485Config(uint8_t * args);
int _UART_Receive(uint8_t * args);
int _UART_ReceiveByte(uint8_t * args);
int _UART_GetIntId(uint8_t * args);
int _UART_ForceBreak(uint8_t * args);
int _UART_FIFOConfig(uint8_t * args);
int _UART_DeInit(uint8_t * args);
int _UART_Send(uint8_t * args);
int _UART_FIFOConfigStructInit(uint8_t * args);
int _UART_FullModemForcePinState(uint8_t * args);
int _UART_RS485ReceiverCmd(uint8_t * args);
int _UART_CheckBusy(uint8_t * args);
int _UART_SendByte(uint8_t * args);
int _UART_ABCmd(uint8_t * args);
int _UART_GetLineStatus(uint8_t * args);
int _UART_FullModemConfigMode(uint8_t * args);
int _UART_FullModemGetStatus(uint8_t * args);
int _UART_Init(uint8_t * args);
int _UART_IrDACmd(uint8_t * args);
int _UART_TxCmd(uint8_t * args);
int _UART_ConfigStructInit(uint8_t * args);
int _UART_IntConfig(uint8_t * args);
int _UART_IrDAInvtInputCmd(uint8_t * args);
int _UART_RS485SendData(uint8_t * args);
int _UART_AB_MODE_Type_malloc(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_malloc(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_NormalMultiDropMode_State(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_Rx_State(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_AutoAddrDetect_State(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_AutoDirCtrl_State(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_DirCtrlPin(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_DirCtrlPol_Level(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_MatchAddrValue(uint8_t * args);
int _UART1_RS485_CTRLCFG_Type_DelayValue(uint8_t * args);
int _UART_IrDA_PULSE_Type_malloc(uint8_t * args);
int _UART_MODEM_PIN_Type_malloc(uint8_t * args);
int _UART_FIFO_CFG_Type_malloc(uint8_t * args);
int _UART_FIFO_CFG_Type_FIFO_ResetRxBuf(uint8_t * args);
int _UART_FIFO_CFG_Type_FIFO_ResetTxBuf(uint8_t * args);
int _UART_FIFO_CFG_Type_FIFO_DMAMode(uint8_t * args);
int _UART_FIFO_CFG_Type_FIFO_Level(uint8_t * args);
int _UART_STOPBIT_Type_malloc(uint8_t * args);
int _UART_ABEO_Type_malloc(uint8_t * args);
int _UART_RS485_DIRCTRL_PIN_Type_malloc(uint8_t * args);
int _UART1_SignalState_malloc(uint8_t * args);
int _UART_CFG_Type_malloc(uint8_t * args);
int _UART_CFG_Type_Baud_rate(uint8_t * args);
int _UART_CFG_Type_Parity(uint8_t * args);
int _UART_CFG_Type_Databits(uint8_t * args);
int _UART_CFG_Type_Stopbits(uint8_t * args);
int _UART_AB_CFG_Type_malloc(uint8_t * args);
int _UART_AB_CFG_Type_ABMode(uint8_t * args);
int _UART_AB_CFG_Type_AutoRestart(uint8_t * args);
int _UART_MODEM_MODE_Type_malloc(uint8_t * args);
int _UART_FITO_LEVEL_Type_malloc(uint8_t * args);
int _UART_INT_Type_malloc(uint8_t * args);
int _UART_LS_Type_malloc(uint8_t * args);
int _UART_DATABIT_Type_malloc(uint8_t * args);
int _UART_MODEM_STAT_type_malloc(uint8_t * args);
int _UART_PARITY_Type_malloc(uint8_t * args);

#endif
