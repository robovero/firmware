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

#ifndef ___LPC17XX_I2C_H__
#define ___LPC17XX_I2C_H__

#include "lpc_types.h"

int _I2C_MonitorModeCmd(uint8_t * args);
int _I2C_IntCmd(uint8_t * args);
int _I2C_DeInit(uint8_t * args);
int _I2C_SlaveHandler(uint8_t * args);
int _I2C_MonitorModeConfig(uint8_t * args);
int _I2C_MasterTransferData(uint8_t * args);
int _I2C_SlaveTransferComplete(uint8_t * args);
int _I2C_SlaveTransferData(uint8_t * args);
int _I2C_SetOwnSlaveAddr(uint8_t * args);
int _I2C_MasterTransferComplete(uint8_t * args);
int _I2C_MasterHandler(uint8_t * args);
int _I2C_MonitorHandler(uint8_t * args);
int _I2C_Init(uint8_t * args);
int _I2C_MonitorGetDatabuffer(uint8_t * args);
int _I2C_GetLastStatusCode(uint8_t * args);
int _I2C_Cmd(uint8_t * args);
int _I2C_M_SETUP_Type_malloc(uint8_t * args);
int _I2C_M_SETUP_Type_sl_addr7bit(uint8_t * args);
int _I2C_M_SETUP_Type_tx_data(uint8_t * args);
int _I2C_M_SETUP_Type_tx_length(uint8_t * args);
int _I2C_M_SETUP_Type_tx_count(uint8_t * args);
int _I2C_M_SETUP_Type_rx_data(uint8_t * args);
int _I2C_M_SETUP_Type_rx_length(uint8_t * args);
int _I2C_M_SETUP_Type_rx_count(uint8_t * args);
int _I2C_M_SETUP_Type_retransmissions_max(uint8_t * args);
int _I2C_M_SETUP_Type_retransmissions_count(uint8_t * args);
int _I2C_M_SETUP_Type_status(uint8_t * args);
//int _I2C_M_SETUP_Type_(*callback)(void)(uint8_t * args);
int _I2C_OWNSLAVEADDR_CFG_Type_malloc(uint8_t * args);
int _I2C_OWNSLAVEADDR_CFG_Type_SlaveAddrChannel(uint8_t * args);
int _I2C_OWNSLAVEADDR_CFG_Type_SlaveAddr_7bit(uint8_t * args);
int _I2C_OWNSLAVEADDR_CFG_Type_GeneralCallState(uint8_t * args);
int _I2C_OWNSLAVEADDR_CFG_Type_SlaveAddrMaskValue(uint8_t * args);
int _I2C_TRANSFER_OPT_Type_malloc(uint8_t * args);
int _I2C_S_SETUP_Type_malloc(uint8_t * args);
int _I2C_S_SETUP_Type_tx_data(uint8_t * args);
int _I2C_S_SETUP_Type_tx_length(uint8_t * args);
int _I2C_S_SETUP_Type_tx_count(uint8_t * args);
int _I2C_S_SETUP_Type_rx_data(uint8_t * args);
int _I2C_S_SETUP_Type_rx_length(uint8_t * args);
int _I2C_S_SETUP_Type_rx_count(uint8_t * args);
int _I2C_S_SETUP_Type_status(uint8_t * args);
//int _I2C_S_SETUP_Type_(*callback)(void)(uint8_t * args);

#endif
