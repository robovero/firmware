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

#include "table.h"
#include "return.h"

#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_adc.h"
#include "lpc17xx_i2c.h"
#include "lpc17xx_uart.h"
#include "lpc17xx_can.h"
#include "lpc17xx_pwm.h"

/*
 * global variables used by wrapper functions and extras
 */

int prompt_on = TRUE;
int heartbeat_on = TRUE;


/*
 * Get the return status of the previously called function
 */
int _return(uint8_t * args)
{
    sprintf((char *) str, "%x\r\n", (unsigned int)ret);
    writeUSBOutString(str);
    return 0;
}

/*
 * This function is a special case in that it's argument hasn't been dynamically
 * allocated
 */
int _search(uint8_t * args)
{
    int i;
    int found = 0;
    int arg_len = strlen((char*)args);

    if (args == NULL)
    {
        return 1;
    }

    /*
     * if an argument was given, search
     */
    else
    {
        for (i = 1; i < driver_table_len; i++)
        {
            /*
             * show all matches
             */
            if (prompt_on)
            {
                if (memcmp(args, (char *) driver_table[i].fcn_name, arg_len) == 0)
                {
                    sprintf((char *) str, "%03x %s\r\n", i, driver_table[i].fcn_name);
                    writeUSBOutString(str);
                    found++;
                }
            }

            /*
             * only show an exact match
             */
            else
            {
                if (strcmp((char *) args, (char *) driver_table[i].fcn_name) == 0)
                {
                    sprintf((char *) str, "%03x\r\n", i);
                    writeUSBOutString(str);
                    found++;
                }
            }

        }
        if (!found)
            return 1;
    }
    return 0;
}

int _list(uint8_t * args)
{
    int i;
    int start = 1;
    int end = driver_table_len;
    uint8_t * arg;

    if ((arg = (uint8_t *) strtok(NULL, " ")) != NULL)
    {
        /*
         * argument 1 is the start entry
         */
        i = (int) strtoul((char *) arg, NULL, 16);
        if (i > 0 && i < driver_table_len)
            start = i;

        /*
         * argument 2 is the number of entries to display
         */
        if ((arg = (uint8_t *) strtok(NULL, " ")) != NULL)
        {
            i = (int) strtoul((char *) arg, NULL, 16);
                if (start + i <= driver_table_len)
                    end = start + i;
        }
    }

    /*
     * list all functions in the table with their index
     */
    for (i = start; i < end; i++)
    {
        sprintf((char *) str, "%03x %s\r\n", i, driver_table[i].fcn_name);
        writeUSBOutString(str);
    }
    return 0;
}

int _promptOn(uint8_t * args)
{
    prompt_on = TRUE;
    return 0;
}

int _promptOff(uint8_t * args)
{
    prompt_on = FALSE;
    return 0;
}

int _heartbeatOn(uint8_t * args)
{
    heartbeat_on = TRUE;
    return 0;
}

int _heartbeatOff(uint8_t * args)
{
    heartbeat_on = FALSE;
    return 0;
}

/*
 * Setup a match condition for count cycles on channel ch.
 */
int _initMatch(uint8_t * args)
{
    uint8_t * arg_ptr;
    uint8_t MatchChannel; 
    uint32_t MatchValue;
    PWM_MATCHCFG_Type PWMMatchCfgDat;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    MatchChannel = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    MatchValue = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);


    PWM_MatchUpdate(LPC_PWM1, MatchChannel, MatchValue, PWM_MATCH_UPDATE_NOW);
    PWMMatchCfgDat.IntOnMatch = DISABLE;
    PWMMatchCfgDat.MatchChannel = MatchChannel;
    if (!MatchChannel)
        PWMMatchCfgDat.ResetOnMatch = ENABLE;
    else
        PWMMatchCfgDat.ResetOnMatch = DISABLE;
    PWMMatchCfgDat.StopOnMatch = DISABLE;
    PWM_ConfigMatch(LPC_PWM1, &PWMMatchCfgDat);

    return 0;
}

int _malloc(uint8_t * args)
{
    uint8_t * arg;
    size_t size;

    if ((arg = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    size = (size_t) strtoul((char *) arg, NULL, 16);

    sprintf((char *) str, "%x\r\n", (unsigned int) malloc(size));
    writeUSBOutString(str);
    return 0;
}

int _free(uint8_t * args)
{
    uint8_t * arg;
    void * pointer;

    if ((arg = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    pointer = (void *) strtoul((char *) arg, NULL, 16);

    free(pointer);
    return 0;
}

int _deref(uint8_t * args)
{
    uint8_t * arg_ptr;
    void * ptr;
    uint8_t size;
    uint8_t * ptr8; 
    uint16_t * ptr16;
    uint32_t * ptr32;

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    ptr = (void *) strtoul((char *) arg_ptr, NULL, 16);
    ptr8 = ptr;
    ptr16 = ptr;
    ptr32 = ptr;    

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) return 1;
    size = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);

    if ((arg_ptr = (uint8_t *) strtok(NULL, " ")) == NULL) {
        if (size == 1)
            sprintf((char *) str, "%x\r\n", (unsigned int) *ptr8);
        else if (size == 2)
            sprintf((char *) str, "%x\r\n", (unsigned int) *ptr16);
        else if (size == 4)
            sprintf((char *) str, "%x\r\n", (unsigned int) *ptr32);
        else
            return 1;
        writeUSBOutString(str);
        return 0;
    }

    if (size == 1)
        *ptr8 = (uint8_t) strtoul((char *) arg_ptr, NULL, 16);
    else if (size == 2)
        *ptr16 = (uint16_t) strtoul((char *) arg_ptr, NULL, 16);
    else if (size == 4)
        *ptr32 = (uint32_t) strtoul((char *) arg_ptr, NULL, 16);
    else
        return 1;

    return 0;
}

static void configPin(uint8_t Portnum, uint8_t Pinnum, uint8_t Pinmode, uint8_t OpenDrain, uint8_t Funcnum)
{
    PINSEL_CFG_Type PinCfg;

    PinCfg.Portnum = Portnum;
    PinCfg.Pinnum = Pinnum;
    PinCfg.Pinmode = Pinmode;
    PinCfg.OpenDrain = OpenDrain;
    PinCfg.Funcnum = Funcnum;

    PINSEL_ConfigPin(&PinCfg);
}

static void configAllPins(void)
{
    /* PWM */
    configPin(1, 18, 0, 0, 2);      /* PWM 1 */
    configPin(1, 20, 0, 0, 2);      /* PWM 2 */
    configPin(3, 26, 0, 0, 3);      /* PWM 3 */
    configPin(1, 23, 0, 0, 2);      /* PWM 4 */
    configPin(1, 24, 0, 0, 2);      /* PWM 5 */
    configPin(2, 5, 0, 0, 1);       /* PWM 6 */

    /* Motor Control */
    configPin(1, 21, 0, 0, 1);      /* ABORT */
    configPin(1, 19, 0, 0, 1);      /* MC0_A0 */
    configPin(1, 25, 0, 0, 1);      /* MC0_A1 */
    configPin(1, 28, 0, 0, 1);      /* MC0_A2 */
    configPin(1, 22, 0, 0, 1);      /* MC0_B0 */
    configPin(1, 26, 0, 0, 1);      /* MC0_B1 */
    configPin(1, 29, 0, 0, 1);      /* MC0_B2 */
//    configPin()     /* P0_4 */
//    configPin()     /* P0_5 */
//    configPin()     /* P0_19 */

    /* Analog */
    configPin(0, 23, 0, 0, 1);      /* AD0_0 */
    configPin(0, 24, 0, 0, 1);      /* AD0_1 */
    configPin(0, 25, 0, 0, 1);      /* AD0_2 */
    configPin(0, 26, 0, 0, 1);      /* AD0_3 */
    configPin(1, 31, 0, 0, 3);      /* AD0_5 */
    configPin(0, 3, 0, 0, 2);       /* AD0_6 */
    configPin(0, 2, 0, 0, 2);       /* AD0_7 */

    /* SPI1 */
    configPin(0, 6, 0, 0, 2);       /* CS1 */
    configPin(0, 7, 0, 0, 2);       /* CLK1 */
    configPin(0, 8, 0, 0, 2);       /* MISO1 */
    configPin(0, 9, 0, 0, 2);       /* MOSI1 */
//    configPin()     /* P1_27 */
//    configPin()     /* P3_25 */
//    configPin()     /* P2_10 */
//    configPin()     /* P0_20 */
//    configPin()     /* P2_8 */
//    configPin()     /* P4_28 */
//    configPin()     /* P4_29 */

    /* UART */
    configPin(2, 0, 0, 0, 2);     /* TX1 */
    configPin(2, 1, 0, 0, 2);     /* RX1 */
    configPin(2, 7, 0, 0, 2);     /* RTS1 */
    configPin(2, 2, 0, 0, 2);     /* CTS1 */
    configPin(0, 10, 0, 0, 1);    /* TX2 */
    configPin(0, 11, 0, 0, 1);    /* RX2 */
    configPin(0, 0, 0, 0, 2);     /* TX3 */
    configPin(0, 1, 0, 0, 2);     /* RX3 */

    /* I2C */
    configPin(0, 27, 0, 0, 1);     /* SDA0 */
    configPin(0, 28, 0, 0, 1);     /* SCL0 */

    /* SPI0 */
    configPin(0, 17, 0, 0, 2);     /* MISO */
    configPin(0, 18, 0, 0, 2);     /* MOSI */
    configPin(0, 15, 0, 0, 2);     /* CS0 */
    configPin(0, 16, 0, 0, 2);     /* CLK */
//    configPin();     /* P2_6 */

    /* CAN */
    configPin(0, 21, 0, 0, 3);     /* CANH */
    configPin(0, 22, 0, 0, 3);     /* CANL */
//    configPin()     /* P2_3 */
//    configPin()     /* P2_4 */
}

/*
 * Configure the pins according to their intended default function
 */
int _roboveroConfig(uint8_t * args)
{
    int i;
    UART_CFG_Type UARTConfigStruct;
    PWM_TIMERCFG_Type PWMCfgDat;

    configAllPins();

    /*
     * Enable 7 analog inputs
     */
    ADC_Init(LPC_ADC, 200000);
    for (i = 0; i < 4; i++)
        ADC_ChannelCmd(LPC_ADC, i, ENABLE); 
    for (i = 5; i < 8; i++)
        ADC_ChannelCmd(LPC_ADC, i, ENABLE); 

    /*
     * Configure I2C0 for IMU communications
     */
    I2C_Init(LPC_I2C0, 100000);
    I2C_Cmd(LPC_I2C0, ENABLE);

    /*
     * Initialize CAN bus
     */
    CAN_Init(LPC_CAN1, 100000);

    /*
     * Initialize UART1 
     */
    UART_ConfigStructInit(&UARTConfigStruct);
    UARTConfigStruct.Baud_rate = 115200;
    UART_Init(LPC_UART1, &UARTConfigStruct);
    UART_TxCmd(LPC_UART1, ENABLE);

    /*
     * Initialize PWM
     *
     * Peripheral clock is 30MHz. Prescale by 30 cycles for 1us resolution.
     */    
    PWMCfgDat.PrescaleOption = PWM_TIMER_PRESCALE_TICKVAL;
    PWMCfgDat.PrescaleValue = 30;
    PWM_Init(LPC_PWM1, PWM_MODE_TIMER, &PWMCfgDat);

    return 0;
}

/*
 * Put pins back in their initial state to simulate a reset condition without
 * disconnecting USB
 */
int _resetConfig(uint8_t * args)
{
    int i;

    /* P0.0 - P0.11 */
    for (i = 0; i < 12; i++)
        configPin(0, i, 0, 0, 0);

    /*
     * P0.15 - P0.28
     * intentionally skip P0.29 (USB+) and P0.30 (USB-)
     */
    for (i = 15; i < 29; i++)
        configPin(0, i, 0, 0, 0);

    /*
     * P1.0, P1.1, P1.4, P1.8, P1.9, P1.10
     */
    configPin(1, 0, 0, 0, 0);
    configPin(1, 1, 0, 0, 0);
    configPin(1, 4, 0, 0, 0);
    configPin(1, 8, 0, 0, 0);
    configPin(1, 9, 0, 0, 0);
    configPin(1, 10, 0, 0, 0);

    /*
     * P1.14 - P1.31
     */
    for (i = 14; i < 32; i++)
        configPin(1, i, 0, 0, 0);

    /*
     * P2.0 - P2.8
     * intentionally skip P2.9 (USB_CONNECT)
     */
    for (i = 0; i < 9; i++)
        configPin(2, i, 0, 0, 0);

    /*
     * P2.10 - P2.14
     */
    for (i = 10; i < 15; i++)
        configPin(2, i, 0, 0, 0);

    /*
     * Intentionally skip P3.25 (LED)
     * P3.26
     */
    configPin(3, 26, 0, 0, 0);

    /* P4.28, P4.29 */
    configPin(4, 28, 0, 0, 0);
    configPin(4, 29, 0, 0, 0);

    return 0;
}


