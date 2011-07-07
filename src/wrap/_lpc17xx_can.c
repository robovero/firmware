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

#include "lpc17xx_can.h"

#include "return.h"

int _CAN_SetCommand(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    uint32_t CMRType;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CMRType = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

    CAN_SetCommand(CANx, CMRType);
    return 0;
}

int _CAN_IRQCmd(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    CAN_INT_EN_Type arg;
    FunctionalState NewState;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    arg = (CAN_INT_EN_Type) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

    CAN_IRQCmd(CANx, arg, NewState);
    return 0;
}

int _FCAN_ReadObj(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CANAF_TypeDef* CANAFx;
    CAN_MSG_Type* CAN_Msg;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANAFx = (LPC_CANAF_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_Msg = (CAN_MSG_Type*) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) FCAN_ReadObj(CANAFx, CAN_Msg));
    writeUSBOutString(str);
    return 0;
}

int _CAN_Init(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    uint32_t baudrate;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    baudrate = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);

    CAN_Init(CANx, baudrate);
    return 0;
}

int _CAN_ModeConfig(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    CAN_MODE_Type mode;
    FunctionalState NewState;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    mode = (CAN_MODE_Type) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    NewState = (FunctionalState) strtoul((char *) arg_ptr, NULL, 16);

    CAN_ModeConfig(CANx, mode, NewState);
    return 0;
}

int _CAN_LoadExplicitEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    uint32_t ID;
    CAN_ID_FORMAT_Type format;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    ID = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    format = (CAN_ID_FORMAT_Type) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_LoadExplicitEntry(CANx, ID, format));
    writeUSBOutString(str);
    return 0;
}

int _CAN_LoadFullCANEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    uint16_t ID;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    ID = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_LoadFullCANEntry(CANx, ID));
    writeUSBOutString(str);
    return 0;
}

int _CAN_IntGetStatus(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_IntGetStatus(CANx));
    writeUSBOutString(str);
    return 0;
}

int _CAN_SetAFMode(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CANAF_TypeDef* CANAFx;
    CAN_AFMODE_Type AFmode;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANAFx = (LPC_CANAF_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AFmode = (CAN_AFMODE_Type) strtoul((char *) arg_ptr, NULL, 16);

    CAN_SetAFMode(CANAFx, AFmode);
    return 0;
}

int _CAN_SendMsg(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    CAN_MSG_Type* CAN_Msg;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_Msg = (CAN_MSG_Type*) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_SendMsg(CANx, CAN_Msg));
    writeUSBOutString(str);
    return 0;
}

int _CAN_LoadGroupEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    uint32_t lowerID;
    uint32_t upperID;
    CAN_ID_FORMAT_Type format;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    lowerID = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    upperID = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    format = (CAN_ID_FORMAT_Type) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_LoadGroupEntry(CANx, lowerID, upperID, format));
    writeUSBOutString(str);
    return 0;
}

int _CAN_SetupAFLUT(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CANAF_TypeDef* CANAFx;
    AF_SectionDef* AFSection;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANAFx = (LPC_CANAF_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AFSection = (AF_SectionDef*) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_SetupAFLUT(CANAFx, AFSection));
    writeUSBOutString(str);
    return 0;
}

int _CAN_GetCTRLStatus(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    CAN_CTRL_STS_Type arg;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    arg = (CAN_CTRL_STS_Type) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_GetCTRLStatus(CANx, arg));
    writeUSBOutString(str);
    return 0;
}

int _CAN_DeInit(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

    CAN_DeInit(CANx);
    return 0;
}

int _CAN_ReceiveMsg(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CAN_TypeDef* CANx;
    CAN_MSG_Type* CAN_Msg;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANx = (LPC_CAN_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_Msg = (CAN_MSG_Type*) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_ReceiveMsg(CANx, CAN_Msg));
    writeUSBOutString(str);
    return 0;
}

int _CAN_FullCANPendGetStatus(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CANAF_TypeDef* CANAFx;
    FullCAN_IC_Type type;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANAFx = (LPC_CANAF_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    type = (FullCAN_IC_Type) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_FullCANPendGetStatus(CANAFx, type));
    writeUSBOutString(str);
    return 0;
}

int _CAN_GetCRStatus(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CANCR_TypeDef* CANCRx;
    CAN_CR_STS_Type arg;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANCRx = (LPC_CANCR_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    arg = (CAN_CR_STS_Type) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_GetCRStatus(CANCRx, arg));
    writeUSBOutString(str);
    return 0;
}

int _CAN_RemoveEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    AFLUT_ENTRY_Type EntryType;
    uint16_t position;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    EntryType = (AFLUT_ENTRY_Type) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    position = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_RemoveEntry(EntryType, position));
    writeUSBOutString(str);
    return 0;
}

int _CAN_FullCANIntGetStatus(uint8_t * args)
{
    uint8_t * arg_ptr;
    LPC_CANAF_TypeDef* CANAFx;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CANAFx = (LPC_CANAF_TypeDef*) strtoul((char *) arg_ptr, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) CAN_FullCANIntGetStatus(CANAFx));
    writeUSBOutString(str);
    return 0;
}

int _SFF_Entry_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(SFF_Entry)));
    writeUSBOutString(str);
    return 0;
}

int _SFF_Entry_controller(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_Entry* SFF_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_Entry_ptr = (SFF_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_Entry_ptr->controller);
        writeUSBOutString(str);
        return 0;
    }

    SFF_Entry_ptr->controller = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _SFF_Entry_disable(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_Entry* SFF_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_Entry_ptr = (SFF_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_Entry_ptr->disable);
        writeUSBOutString(str);
        return 0;
    }

    SFF_Entry_ptr->disable = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _SFF_Entry_id_11(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_Entry* SFF_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_Entry_ptr = (SFF_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_Entry_ptr->id_11);
        writeUSBOutString(str);
        return 0;
    }

    SFF_Entry_ptr->id_11 = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_MSG_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_MSG_Type)));
    writeUSBOutString(str);
    return 0;
}

int _CAN_MSG_Type_id(uint8_t * args)
{
    uint8_t * arg_ptr;
    CAN_MSG_Type* CAN_MSG_Type_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr = (CAN_MSG_Type *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) CAN_MSG_Type_ptr->id);
        writeUSBOutString(str);
        return 0;
    }

    CAN_MSG_Type_ptr->id = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_MSG_Type_dataA(uint8_t * args)
{
    uint8_t * arg_ptr;
    CAN_MSG_Type* CAN_MSG_Type_ptr;


    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr = (CAN_MSG_Type *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x %x %x %x\r\n",
            (unsigned int) CAN_MSG_Type_ptr->dataA[0],
            (unsigned int) CAN_MSG_Type_ptr->dataA[1],
            (unsigned int) CAN_MSG_Type_ptr->dataA[2],
            (unsigned int) CAN_MSG_Type_ptr->dataA[3]
            );
        writeUSBOutString(str);
        return 0;
    }

    CAN_MSG_Type_ptr->dataA[0] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr->dataA[1] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr->dataA[2] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr->dataA[3] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_MSG_Type_dataB(uint8_t * args)
{
    uint8_t * arg_ptr;
    CAN_MSG_Type* CAN_MSG_Type_ptr;


    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr = (CAN_MSG_Type *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x %x %x %x\r\n",
            (unsigned int) CAN_MSG_Type_ptr->dataB[0],
            (unsigned int) CAN_MSG_Type_ptr->dataB[1],
            (unsigned int) CAN_MSG_Type_ptr->dataB[2],
            (unsigned int) CAN_MSG_Type_ptr->dataB[3]
            );
        writeUSBOutString(str);
        return 0;
    }

    CAN_MSG_Type_ptr->dataB[0] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr->dataB[1] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr->dataB[2] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr->dataB[3] = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_MSG_Type_len(uint8_t * args)
{
    uint8_t * arg_ptr;
    CAN_MSG_Type* CAN_MSG_Type_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr = (CAN_MSG_Type *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) CAN_MSG_Type_ptr->len);
        writeUSBOutString(str);
        return 0;
    }

    CAN_MSG_Type_ptr->len = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_MSG_Type_format(uint8_t * args)
{
    uint8_t * arg_ptr;
    CAN_MSG_Type* CAN_MSG_Type_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr = (CAN_MSG_Type *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) CAN_MSG_Type_ptr->format);
        writeUSBOutString(str);
        return 0;
    }

    CAN_MSG_Type_ptr->format = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_MSG_Type_type(uint8_t * args)
{
    uint8_t * arg_ptr;
    CAN_MSG_Type* CAN_MSG_Type_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_MSG_Type_ptr = (CAN_MSG_Type *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) CAN_MSG_Type_ptr->type);
        writeUSBOutString(str);
        return 0;
    }

    CAN_MSG_Type_ptr->type = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_ERROR_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_ERROR)));
    writeUSBOutString(str);
    return 0;
}

int _CAN_AFMODE_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_AFMODE_Type)));
    writeUSBOutString(str);
    return 0;
}

int _CAN_CR_STS_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_CR_STS_Type)));
    writeUSBOutString(str);
    return 0;
}

int _CAN_CTRL_STS_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_CTRL_STS_Type)));
    writeUSBOutString(str);
    return 0;
}

int _AFLUT_ENTRY_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(AFLUT_ENTRY_Type)));
    writeUSBOutString(str);
    return 0;
}

int _CAN_ID_FORMAT_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_ID_FORMAT_Type)));
    writeUSBOutString(str);
    return 0;
}

int _FullCAN_Entry_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(FullCAN_Entry)));
    writeUSBOutString(str);
    return 0;
}

int _FullCAN_Entry_controller(uint8_t * args)
{
    uint8_t * arg_ptr;
    FullCAN_Entry* FullCAN_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    FullCAN_Entry_ptr = (FullCAN_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) FullCAN_Entry_ptr->controller);
        writeUSBOutString(str);
        return 0;
    }

    FullCAN_Entry_ptr->controller = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _FullCAN_Entry_disable(uint8_t * args)
{
    uint8_t * arg_ptr;
    FullCAN_Entry* FullCAN_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    FullCAN_Entry_ptr = (FullCAN_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) FullCAN_Entry_ptr->disable);
        writeUSBOutString(str);
        return 0;
    }

    FullCAN_Entry_ptr->disable = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _FullCAN_Entry_id_11(uint8_t * args)
{
    uint8_t * arg_ptr;
    FullCAN_Entry* FullCAN_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    FullCAN_Entry_ptr = (FullCAN_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) FullCAN_Entry_ptr->id_11);
        writeUSBOutString(str);
        return 0;
    }

    FullCAN_Entry_ptr->id_11 = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _EFF_GPR_Entry_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(EFF_GPR_Entry)));
    writeUSBOutString(str);
    return 0;
}

int _EFF_GPR_Entry_controller1(uint8_t * args)
{
    uint8_t * arg_ptr;
    EFF_GPR_Entry* EFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    EFF_GPR_Entry_ptr = (EFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) EFF_GPR_Entry_ptr->controller1);
        writeUSBOutString(str);
        return 0;
    }

    EFF_GPR_Entry_ptr->controller1 = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _EFF_GPR_Entry_controller2(uint8_t * args)
{
    uint8_t * arg_ptr;
    EFF_GPR_Entry* EFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    EFF_GPR_Entry_ptr = (EFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) EFF_GPR_Entry_ptr->controller2);
        writeUSBOutString(str);
        return 0;
    }

    EFF_GPR_Entry_ptr->controller2 = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _EFF_GPR_Entry_lowerEID(uint8_t * args)
{
    uint8_t * arg_ptr;
    EFF_GPR_Entry* EFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    EFF_GPR_Entry_ptr = (EFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) EFF_GPR_Entry_ptr->lowerEID);
        writeUSBOutString(str);
        return 0;
    }

    EFF_GPR_Entry_ptr->lowerEID = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _EFF_GPR_Entry_upperEID(uint8_t * args)
{
    uint8_t * arg_ptr;
    EFF_GPR_Entry* EFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    EFF_GPR_Entry_ptr = (EFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) EFF_GPR_Entry_ptr->upperEID);
        writeUSBOutString(str);
        return 0;
    }

    EFF_GPR_Entry_ptr->upperEID = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_INT_EN_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_INT_EN_Type)));
    writeUSBOutString(str);
    return 0;
}

int _CAN_PinCFG_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_PinCFG_Type)));
    writeUSBOutString(str);
    return 0;
}

int _CAN_PinCFG_Type_RD(uint8_t * args)
{
    uint8_t * arg_ptr;
    CAN_PinCFG_Type* CAN_PinCFG_Type_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_PinCFG_Type_ptr = (CAN_PinCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) CAN_PinCFG_Type_ptr->RD);
        writeUSBOutString(str);
        return 0;
    }

    CAN_PinCFG_Type_ptr->RD = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_PinCFG_Type_TD(uint8_t * args)
{
    uint8_t * arg_ptr;
    CAN_PinCFG_Type* CAN_PinCFG_Type_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    CAN_PinCFG_Type_ptr = (CAN_PinCFG_Type *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) CAN_PinCFG_Type_ptr->TD);
        writeUSBOutString(str);
        return 0;
    }

    CAN_PinCFG_Type_ptr->TD = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_FRAME_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_FRAME_Type)));
    writeUSBOutString(str);
    return 0;
}

int _FullCAN_IC_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(FullCAN_IC_Type)));
    writeUSBOutString(str);
    return 0;
}

int _SFF_GPR_Entry_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(SFF_GPR_Entry)));
    writeUSBOutString(str);
    return 0;
}

int _SFF_GPR_Entry_controller1(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_GPR_Entry* SFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_GPR_Entry_ptr = (SFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_GPR_Entry_ptr->controller1);
        writeUSBOutString(str);
        return 0;
    }

    SFF_GPR_Entry_ptr->controller1 = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _SFF_GPR_Entry_disable1(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_GPR_Entry* SFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_GPR_Entry_ptr = (SFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_GPR_Entry_ptr->disable1);
        writeUSBOutString(str);
        return 0;
    }

    SFF_GPR_Entry_ptr->disable1 = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _SFF_GPR_Entry_lowerID(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_GPR_Entry* SFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_GPR_Entry_ptr = (SFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_GPR_Entry_ptr->lowerID);
        writeUSBOutString(str);
        return 0;
    }

    SFF_GPR_Entry_ptr->lowerID = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _SFF_GPR_Entry_controller2(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_GPR_Entry* SFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_GPR_Entry_ptr = (SFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_GPR_Entry_ptr->controller2);
        writeUSBOutString(str);
        return 0;
    }

    SFF_GPR_Entry_ptr->controller2 = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _SFF_GPR_Entry_disable2(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_GPR_Entry* SFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_GPR_Entry_ptr = (SFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_GPR_Entry_ptr->disable2);
        writeUSBOutString(str);
        return 0;
    }

    SFF_GPR_Entry_ptr->disable2 = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _SFF_GPR_Entry_upperID(uint8_t * args)
{
    uint8_t * arg_ptr;
    SFF_GPR_Entry* SFF_GPR_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    SFF_GPR_Entry_ptr = (SFF_GPR_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) SFF_GPR_Entry_ptr->upperID);
        writeUSBOutString(str);
        return 0;
    }

    SFF_GPR_Entry_ptr->upperID = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _CAN_MODE_Type_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(CAN_MODE_Type)));
    writeUSBOutString(str);
    return 0;
}

int _EFF_Entry_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(EFF_Entry)));
    writeUSBOutString(str);
    return 0;
}

int _EFF_Entry_controller(uint8_t * args)
{
    uint8_t * arg_ptr;
    EFF_Entry* EFF_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    EFF_Entry_ptr = (EFF_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) EFF_Entry_ptr->controller);
        writeUSBOutString(str);
        return 0;
    }

    EFF_Entry_ptr->controller = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _EFF_Entry_ID_29(uint8_t * args)
{
    uint8_t * arg_ptr;
    EFF_Entry* EFF_Entry_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    EFF_Entry_ptr = (EFF_Entry *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) EFF_Entry_ptr->ID_29);
        writeUSBOutString(str);
        return 0;
    }

    EFF_Entry_ptr->ID_29 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_malloc(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(sizeof(AF_SectionDef)));
    writeUSBOutString(str);
    return 0;
}

int _AF_SectionDef_FullCAN_Sec(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->FullCAN_Sec);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->FullCAN_Sec = (FullCAN_Entry*) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_FC_NumEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->FC_NumEntry);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->FC_NumEntry = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_SFF_Sec(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->SFF_Sec);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->SFF_Sec = (SFF_Entry*) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_SFF_NumEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->SFF_NumEntry);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->SFF_NumEntry = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_SFF_GPR_Sec(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->SFF_GPR_Sec);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->SFF_GPR_Sec = (SFF_GPR_Entry*) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_SFF_GPR_NumEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->SFF_GPR_NumEntry);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->SFF_GPR_NumEntry = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_EFF_Sec(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->EFF_Sec);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->EFF_Sec = (EFF_Entry*) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_EFF_NumEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->EFF_NumEntry);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->EFF_NumEntry = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_EFF_GPR_Sec(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->EFF_GPR_Sec);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->EFF_GPR_Sec = (EFF_GPR_Entry*) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

int _AF_SectionDef_EFF_GPR_NumEntry(uint8_t * args)
{
    uint8_t * arg_ptr;
    AF_SectionDef* AF_SectionDef_ptr;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    AF_SectionDef_ptr = (AF_SectionDef *) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        sprintf((char *) str, "%x\r\n", (unsigned int) AF_SectionDef_ptr->EFF_GPR_NumEntry);
        writeUSBOutString(str);
        return 0;
    }

    AF_SectionDef_ptr->EFF_GPR_NumEntry = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    return 0;
}

