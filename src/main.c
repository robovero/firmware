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

#include "return.h"
#include "table.h"

#include "LPC17xx.h"
#include "lpc_types.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_can.h"

/*****************************************************************************

	Generic Interrupt Service Routine

*****************************************************************************/
void IntHandler(void)
{
	unsigned long int_num;

  /* Get the interrupt number */
	__asm("mrs %0, ipsr;" : "=r"(int_num) );

  /* Disable the interrupt */
	//ROM_IntDisable(int_num);

  /* Send the interrupt signal and number */
  //usprintf(data, "\r\n%d\r\n", int_num);
  //USBBufferWrite(&g_sTxBuffer, data, strlen(data));

}

/*****************************************************************************

        Hardware Initialization Routine

*****************************************************************************/

void hwInit(void)
{
    /*
     * make the LED pin an output and turn it on
     */
    GPIO_SetDir(3, (1 << 25), 1);
    GPIO_ClearValue(3, (1 << 25));

    /*
     * start the usb device wait until configuration completes before proceeding
     */
    USB_Init();
    USB_Connect(TRUE);
    while (!USB_Configuration);

}

void heartbeat(void)
{
	unsigned long i;

    for (i = 0; i < 1200000; i++);
    GPIO_ClearValue(3, (1 << 25));
    for (i = 0; i < 800000; i++);
    GPIO_SetValue(3, (1 << 25));
    for (i = 0; i < 3200000; i++);
    GPIO_ClearValue(3, (1 << 25));
    for (i = 0; i < 800000; i++);
    GPIO_SetValue(3, (1 << 25));
}

extern int heartbeat_on;

int main(void)
{
	hwInit();

	/*
	 * let usbuser/robovero handle the rest
	 */
    while (1)
    {
        if (heartbeat_on)
            heartbeat();
    }

	return 0;
}

// CAN TEST
/*PINSEL_CFG_Type PinCfg;
CAN_MSG_Type TXMsg;
PinCfg.Funcnum = 3;
PinCfg.OpenDrain = 0;
PinCfg.Pinmode = 0;
PinCfg.Pinnum = 21;
PinCfg.Portnum = 0;
PINSEL_ConfigPin(&PinCfg);
PinCfg.Pinnum = 22;
PINSEL_ConfigPin(&PinCfg);
CAN_Init(LPC_CAN1, 100000);
CAN_SetAFMode(LPC_CANAF,CAN_AccBP);
TXMsg.format = EXT_ID_FORMAT;
TXMsg.id = 0x00001234;
TXMsg.len = 8;
TXMsg.type = DATA_FRAME;
TXMsg.dataA[0] = TXMsg.dataA[1] = TXMsg.dataA[2] = TXMsg.dataA[3] = 0x01234567;
TXMsg.dataB[0] = TXMsg.dataB[1] = TXMsg.dataB[2] = TXMsg.dataB[3] = 0x89ABCDEF;
while (1) {
    CAN_SendMsg(LPC_CAN1, &TXMsg);
    TXMsg.id ++;
}*/

// MASTER CLOCK TEST
/*//Initialize clockout pin
PinCfg.Portnum = 1;
PinCfg.Pinnum = 27;
PinCfg.Pinmode = 0;
PinCfg.OpenDrain = 0;
PinCfg.Funcnum = 1;
PINSEL_ConfigPin(&PinCfg);*/

///* Initialize UART1 */
//PINSEL_CFG_Type PinCfg;
//PinCfg.Portnum = 2;
//PinCfg.Pinnum = 0;
//PinCfg.Pinmode = 0;
//PinCfg.OpenDrain = 0;
//PinCfg.Funcnum = 2;
//PINSEL_ConfigPin(&PinCfg);
//PinCfg.Pinnum = 1;
//PINSEL_ConfigPin(&PinCfg);

//	UART_CFG_Type * UARTConfigStruct_ptr;
//	UARTConfigStruct_ptr = _UART_CFG_Type_malloc();
//	if (UARTConfigStruct_ptr == NULL)
//		while (1);
//	UART_ConfigStructInit(UARTConfigStruct_ptr);
//	_UART_CFG_Type_set_Baud_rate(UARTConfigStruct_ptr, 115200);
//	UART_Init(LPC_UART1, UARTConfigStruct_ptr);
//	UART_TxCmd(LPC_UART1, ENABLE);

