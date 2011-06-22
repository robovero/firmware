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

#ifndef ___LPC17XX_CAN_H__
#define ___LPC17XX_CAN_H__

#include "lpc_types.h"

int _CAN_SetCommand(uint8_t * args);
int _CAN_IRQCmd(uint8_t * args);
int _FCAN_ReadObj(uint8_t * args);
int _CAN_Init(uint8_t * args);
int _CAN_ModeConfig(uint8_t * args);
int _CAN_LoadExplicitEntry(uint8_t * args);
int _CAN_LoadFullCANEntry(uint8_t * args);
int _CAN_IntGetStatus(uint8_t * args);
int _CAN_SetAFMode(uint8_t * args);
int _CAN_SendMsg(uint8_t * args);
int _CAN_LoadGroupEntry(uint8_t * args);
int _CAN_SetupAFLUT(uint8_t * args);
int _CAN_GetCTRLStatus(uint8_t * args);
int _CAN_DeInit(uint8_t * args);
int _CAN_ReceiveMsg(uint8_t * args);
int _CAN_FullCANPendGetStatus(uint8_t * args);
int _CAN_GetCRStatus(uint8_t * args);
int _CAN_RemoveEntry(uint8_t * args);
int _CAN_FullCANIntGetStatus(uint8_t * args);
int _SFF_Entry_malloc(uint8_t * args);
int _SFF_Entry_controller(uint8_t * args);
int _SFF_Entry_disable(uint8_t * args);
int _SFF_Entry_id_11(uint8_t * args);
int _CAN_MSG_Type_malloc(uint8_t * args);
int _CAN_MSG_Type_id(uint8_t * args);
int _CAN_MSG_Type_dataA(uint8_t * args);
int _CAN_MSG_Type_dataB(uint8_t * args);
int _CAN_MSG_Type_len(uint8_t * args);
int _CAN_MSG_Type_format(uint8_t * args);
int _CAN_MSG_Type_type(uint8_t * args);
int _CAN_ERROR_malloc(uint8_t * args);
int _CAN_AFMODE_Type_malloc(uint8_t * args);
int _CAN_CR_STS_Type_malloc(uint8_t * args);
int _CAN_CTRL_STS_Type_malloc(uint8_t * args);
int _AFLUT_ENTRY_Type_malloc(uint8_t * args);
int _CAN_ID_FORMAT_Type_malloc(uint8_t * args);
int _FullCAN_Entry_malloc(uint8_t * args);
int _FullCAN_Entry_controller(uint8_t * args);
int _FullCAN_Entry_disable(uint8_t * args);
int _FullCAN_Entry_id_11(uint8_t * args);
int _EFF_GPR_Entry_malloc(uint8_t * args);
int _EFF_GPR_Entry_controller1(uint8_t * args);
int _EFF_GPR_Entry_controller2(uint8_t * args);
int _EFF_GPR_Entry_lowerEID(uint8_t * args);
int _EFF_GPR_Entry_upperEID(uint8_t * args);
int _CAN_INT_EN_Type_malloc(uint8_t * args);
int _CAN_PinCFG_Type_malloc(uint8_t * args);
int _CAN_PinCFG_Type_RD(uint8_t * args);
int _CAN_PinCFG_Type_TD(uint8_t * args);
int _CAN_FRAME_Type_malloc(uint8_t * args);
int _FullCAN_IC_Type_malloc(uint8_t * args);
int _SFF_GPR_Entry_malloc(uint8_t * args);
int _SFF_GPR_Entry_controller1(uint8_t * args);
int _SFF_GPR_Entry_disable1(uint8_t * args);
int _SFF_GPR_Entry_lowerID(uint8_t * args);
int _SFF_GPR_Entry_controller2(uint8_t * args);
int _SFF_GPR_Entry_disable2(uint8_t * args);
int _SFF_GPR_Entry_upperID(uint8_t * args);
int _CAN_MODE_Type_malloc(uint8_t * args);
int _EFF_Entry_malloc(uint8_t * args);
int _EFF_Entry_controller(uint8_t * args);
int _EFF_Entry_ID_29(uint8_t * args);
int _AF_SectionDef_malloc(uint8_t * args);
int _AF_SectionDef_FullCAN_Sec(uint8_t * args);
int _AF_SectionDef_FC_NumEntry(uint8_t * args);
int _AF_SectionDef_SFF_Sec(uint8_t * args);
int _AF_SectionDef_SFF_NumEntry(uint8_t * args);
int _AF_SectionDef_SFF_GPR_Sec(uint8_t * args);
int _AF_SectionDef_SFF_GPR_NumEntry(uint8_t * args);
int _AF_SectionDef_EFF_Sec(uint8_t * args);
int _AF_SectionDef_EFF_NumEntry(uint8_t * args);
int _AF_SectionDef_EFF_GPR_Sec(uint8_t * args);
int _AF_SectionDef_EFF_GPR_NumEntry(uint8_t * args);

#endif
