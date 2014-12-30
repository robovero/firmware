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

uint8_t accel_ctrl_reg_1_a_value = 0;
uint8_t gyro_ctrl_reg_1_value    = 0;

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

static int WriteStI2CRegister (I2C_M_SETUP_Type* setup, uint8_t register_address, uint8_t value)
{
    uint8_t transmit_buffer[2];
    int     result;
    uint8_t receive_buffer;

    transmit_buffer[0] = register_address;
    transmit_buffer[1] = value;

    setup->tx_data   = transmit_buffer;
    setup->tx_length = 2;
    setup->rx_data   = &receive_buffer;
    setup->rx_length = 0;

    result = I2C_MasterTransferData(LPC_I2C0, setup, I2C_TRANSFER_POLLING);
    if(result == ERROR)
        return 1;

    setup->tx_length = 1;
    setup->rx_length = 1;

    result = I2C_MasterTransferData(LPC_I2C0, setup, I2C_TRANSFER_POLLING);
    if(result == ERROR || receive_buffer != value)
        return 1;

    return 0;
}

#define MAX_ST_I2C_RETRANSMISSIONS   3
#define ST_I2C_AUTOINCREMENT_ADDRESS 0x80

#define ACCEL_I2C_SLAVE_ADDRESS    0x18
#define ACCEL_CTRL_REG_1_A_ADDRESS 0x20
#define ACCEL_CTRL_REG_4_A_ADDRESS 0x23
#define ACCEL_DATA_ADDRESS         0x28

#define ACCEL_CTRL_REG_X_ENABLE 0x01
#define ACCEL_CTRL_REG_Y_ENABLE 0x02
#define ACCEL_CTRL_REG_Z_ENABLE 0x04

#define ACCEL_CTRL_REG_OUTPUT_HZ_50   0x00
#define ACCEL_CTRL_REG_OUTPUT_HZ_100  0x08
#define ACCEL_CTRL_REG_OUTPUT_HZ_400  0x10
#define ACCEL_CTRL_REG_OUTPUT_HZ_1000 0x18

#define ACCEL_CTRL_REG_POWER_ON 0x20

#define ACCEL_CTRL_REG_BLOCK_UPDATE 0x80

#define ACCEL_CTRL_REG_SCALE_2 0x00
#define ACCEL_CTRL_REG_SCALE_4 0x10
#define ACCEL_CTRL_REG_SCALE_8 0x30

#define ACCEL_VALUE_OFFSET 32768

int _configAccel (uint8_t* args)
{
    uint32_t         arguments[6];
    I2C_M_SETUP_Type setup;
    char*            arg_ptr;
    unsigned int     index;
    Status           result;
    uint8_t          ctrl_reg_1_a_value;
    uint8_t          ctrl_reg_4_a_value;

    for(index = 0; index < 6; index++)
    {
        arg_ptr = strtok(NULL, " ");
        if(arg_ptr == NULL)
            return 1;

        arguments[index] = strtoul(arg_ptr, NULL, 16);
    }

    ctrl_reg_1_a_value = 0;

    if(arguments[0] == 1)
        ctrl_reg_1_a_value |= ACCEL_CTRL_REG_POWER_ON;

    if(arguments[1] == 1)
        ctrl_reg_1_a_value |= ACCEL_CTRL_REG_X_ENABLE;
    if(arguments[2] == 1)
        ctrl_reg_1_a_value |= ACCEL_CTRL_REG_Y_ENABLE;
    if(arguments[3] == 1)
        ctrl_reg_1_a_value |= ACCEL_CTRL_REG_Z_ENABLE;

    switch(arguments[4])
    {
    case 50:
        ctrl_reg_1_a_value |= ACCEL_CTRL_REG_OUTPUT_HZ_50;
        break;

    case 100:
        ctrl_reg_1_a_value |= ACCEL_CTRL_REG_OUTPUT_HZ_100;
        break;

    case 400:
        ctrl_reg_1_a_value |= ACCEL_CTRL_REG_OUTPUT_HZ_400;
        break;

    case 1000:
        ctrl_reg_1_a_value |= ACCEL_CTRL_REG_OUTPUT_HZ_1000;
        break;

    default:
        return 1;
    }

    ctrl_reg_4_a_value = ACCEL_CTRL_REG_BLOCK_UPDATE;

    switch(arguments[5])
    {
    case 2:
        ctrl_reg_4_a_value |= ACCEL_CTRL_REG_SCALE_2;
        break;

    case 4:
        ctrl_reg_4_a_value |= ACCEL_CTRL_REG_SCALE_4;
        break;

    case 8:
        ctrl_reg_4_a_value |= ACCEL_CTRL_REG_SCALE_8;
        break;

    default:
        return 1;
    }

    setup.sl_addr7bit         = ACCEL_I2C_SLAVE_ADDRESS;
    setup.retransmissions_max = MAX_ST_I2C_RETRANSMISSIONS;

    result = WriteStI2CRegister(&setup, ACCEL_CTRL_REG_1_A_ADDRESS, ctrl_reg_1_a_value);
    if(result == 1)
        return 1;

    accel_ctrl_reg_1_a_value = ctrl_reg_1_a_value;

    result = WriteStI2CRegister(&setup, ACCEL_CTRL_REG_4_A_ADDRESS, ctrl_reg_4_a_value);
    if(result == 1)
        return 1;

    return 0;
}

int _readAccel(uint8_t* args)
{
    uint8_t          receive_buffer[6];
    I2C_M_SETUP_Type setup;
    int16_t*         axis_data;
    char*            formatted_string;
    Status           result;
    uint8_t          transmit_buffer;
    uint8_t          axis_enable_bit;

    setup.sl_addr7bit         = ACCEL_I2C_SLAVE_ADDRESS;
    setup.retransmissions_max = MAX_ST_I2C_RETRANSMISSIONS;

    setup.tx_data   = &transmit_buffer;
    setup.tx_length = 1;
    setup.rx_data   = receive_buffer;
    setup.rx_length = 6;

    transmit_buffer = ACCEL_DATA_ADDRESS|ST_I2C_AUTOINCREMENT_ADDRESS;

    result = I2C_MasterTransferData(LPC_I2C0, &setup, I2C_TRANSFER_POLLING);
    if(result == ERROR)
        return 1;

    axis_enable_bit = ACCEL_CTRL_REG_X_ENABLE;
    axis_data       = (int16_t*)receive_buffer;

    formatted_string = (char*)str;

    do
    {
        if(accel_ctrl_reg_1_a_value&axis_enable_bit)
        {
            unsigned int value;
            int          formatted_size;

            value = (unsigned int)(*axis_data+ACCEL_VALUE_OFFSET);

            formatted_size = sprintf(formatted_string, "%x\r\n", value);
            if(formatted_size > 0)
                formatted_string += formatted_size;
        }

        axis_enable_bit <<= 1;
        axis_data++;
    }while(axis_enable_bit <= ACCEL_CTRL_REG_Z_ENABLE);

    writeUSBOutString(str);

    return 0;
}

#define MAG_I2C_SLAVE_ADDRESS   0x1E
#define MAG_CRA_REG_M_ADDRESS   0x00
#define MAG_CRB_REG_M_ADDRESS   0x01
#define MAG_MR_REG_M_ADDRESS    0x02
#define MAG_DATA_ADDRESS        0x03

#define MAG_CTRL_REG_OUTPUT_CHZ_75   0x00
#define MAG_CTRL_REG_OUTPUT_CHZ_150  0x04
#define MAG_CTRL_REG_OUTPUT_CHZ_300  0x08
#define MAG_CTRL_REG_OUTPUT_CHZ_750  0x0C
#define MAG_CTRL_REG_OUTPUT_CHZ_1500 0x10
#define MAG_CTRL_REG_OUTPUT_CHZ_3000 0x14
#define MAG_CTRL_REG_OUTPUT_CHZ_7500 0x18

#define MAG_CTRL_REG_BIAS_NORMAL   0x00
#define MAG_CTRL_REG_BIAS_POSITIVE 0x01
#define MAG_CTRL_REG_BIAS_NEGATIVE 0x02

#define MAG_CTRL_REG_FIELD_RANGE_13 0x20
#define MAG_CTRL_REG_FIELD_RANGE_19 0x40
#define MAG_CTRL_REG_FIELD_RANGE_25 0x60
#define MAG_CTRL_REG_FIELD_RANGE_40 0x80
#define MAG_CTRL_REG_FIELD_RANGE_47 0xA0
#define MAG_CTRL_REG_FIELD_RANGE_56 0xC0
#define MAG_CTRL_REG_FIELD_RANGE_81 0xE0

#define MAG_CTRL_REG_SLEEP 0x03

#define MAG_VALUE_OFFSET 4096

int _configMag(uint8_t * args)
{
    uint32_t         arguments[4];
    I2C_M_SETUP_Type setup;
    char*            arg_ptr;
    unsigned int     index;
    Status           result;
    uint8_t          cra_reg_m_value;
    uint8_t          crb_reg_m_value;
    uint8_t          mr_reg_m_value;

    for(index = 0; index < 4; index++)
    {
        arg_ptr = strtok(NULL, " ");
        if(arg_ptr == NULL)
            return 1;

        arguments[index] = strtoul(arg_ptr, NULL, 16);
    }

    mr_reg_m_value = 0;

    if(arguments[0] != 1)
        mr_reg_m_value |= MAG_CTRL_REG_SLEEP;

    cra_reg_m_value = 0;

    switch(arguments[1])
    {
    case 0:
        cra_reg_m_value |= MAG_CTRL_REG_BIAS_NORMAL;
        break;

    case 1:
        cra_reg_m_value |= MAG_CTRL_REG_BIAS_POSITIVE;
        break;

    case 2:
        cra_reg_m_value |= MAG_CTRL_REG_BIAS_NEGATIVE;
        break;

    default:
        return 1;
    }

    switch(arguments[2])
    {
    case 75:
        cra_reg_m_value |= MAG_CTRL_REG_OUTPUT_CHZ_75;
        break;

    case 150:
        cra_reg_m_value |= MAG_CTRL_REG_OUTPUT_CHZ_150;
        break;

    case 300:
        cra_reg_m_value |= MAG_CTRL_REG_OUTPUT_CHZ_300;
        break;

    case 750:
        cra_reg_m_value |= MAG_CTRL_REG_OUTPUT_CHZ_750;
        break;

    case 1500:
        cra_reg_m_value |= MAG_CTRL_REG_OUTPUT_CHZ_1500;
        break;

    case 3000:
        cra_reg_m_value |= MAG_CTRL_REG_OUTPUT_CHZ_3000;
        break;

    case 7500:
        cra_reg_m_value |= MAG_CTRL_REG_OUTPUT_CHZ_7500;
        break;

    default:
        return 1;
    }

    crb_reg_m_value = 0;

    switch(arguments[3])
    {
    case 13:
        crb_reg_m_value |= MAG_CTRL_REG_FIELD_RANGE_13;
        break;

    case 19:
        crb_reg_m_value |= MAG_CTRL_REG_FIELD_RANGE_19;
        break;

    case 25:
        crb_reg_m_value |= MAG_CTRL_REG_FIELD_RANGE_25;
        break;

    case 40:
        crb_reg_m_value |= MAG_CTRL_REG_FIELD_RANGE_40;
        break;

    case 47:
        crb_reg_m_value |= MAG_CTRL_REG_FIELD_RANGE_47;
        break;

    case 56:
        crb_reg_m_value |= MAG_CTRL_REG_FIELD_RANGE_56;
        break;

    case 81:
        crb_reg_m_value |= MAG_CTRL_REG_FIELD_RANGE_81;
        break;

    default:
        return 1;
    }

    setup.sl_addr7bit         = MAG_I2C_SLAVE_ADDRESS;
    setup.retransmissions_max = MAX_ST_I2C_RETRANSMISSIONS;

    result = WriteStI2CRegister(&setup, MAG_MR_REG_M_ADDRESS, mr_reg_m_value);
    if(result == 1)
        return 1;

    result = WriteStI2CRegister(&setup, MAG_CRB_REG_M_ADDRESS, crb_reg_m_value);
    if(result == 1)
        return 1;

    result = WriteStI2CRegister(&setup, MAG_CRA_REG_M_ADDRESS, cra_reg_m_value);
    if(result == 1)
        return 1;

    return 0;
}

static unsigned int MagDataToUInt32 (uint8_t* data)
{
    unsigned int unsigned_value;
    int16_t      signed_value;

    signed_value   = (int16_t)(((uint16_t)data[0]<<8)|(uint16_t)data[1]);
    unsigned_value = (unsigned int)(signed_value+MAG_VALUE_OFFSET);

    return unsigned_value;
}

int _readMag(uint8_t * args)
{
    uint8_t          receive_buffer[6];
    I2C_M_SETUP_Type setup;
    unsigned int     x_value;
    unsigned int     y_value;
    unsigned int     z_value;
    Status           result;
    uint8_t          transmit_buffer;

    setup.sl_addr7bit         = MAG_I2C_SLAVE_ADDRESS;
    setup.retransmissions_max = MAX_ST_I2C_RETRANSMISSIONS;

    setup.tx_data   = &transmit_buffer;
    setup.tx_length = 1;
    setup.rx_data   = receive_buffer;
    setup.rx_length = 6;

    transmit_buffer = MAG_DATA_ADDRESS|ST_I2C_AUTOINCREMENT_ADDRESS;

    result = I2C_MasterTransferData(LPC_I2C0, &setup, I2C_TRANSFER_POLLING);
    if(result == ERROR)
        return 1;

    x_value = MagDataToUInt32(&receive_buffer[0]);
    y_value = MagDataToUInt32(&receive_buffer[2]);
    z_value = MagDataToUInt32(&receive_buffer[4]);

    sprintf((char*)str, "%x\r\n%x\r\n%x\r\n", x_value, y_value, z_value);
    writeUSBOutString(str);

    return 0;
}

#define GYRO_I2C_SLAVE_ADDRESS  0x68
#define GYRO_CTRL_REG_1_ADDRESS 0x20
#define GYRO_CTRL_REG_3_ADDRESS 0x22
#define GYRO_CTRL_REG_4_ADDRESS 0x23
#define GYRO_DATA_ADDRESS       0x28

#define GYRO_CTRL_REG_X_ENABLE 0x01
#define GYRO_CTRL_REG_Y_ENABLE 0x02
#define GYRO_CTRL_REG_Z_ENABLE 0x04

#define GYRO_CTRL_REG_POWER_ON 0x08

#define GYRO_CTRL_REG_OUTPUT_HZ_100 0x00
#define GYRO_CTRL_REG_OUTPUT_HZ_200 0x40
#define GYRO_CTRL_REG_OUTPUT_HZ_400 0x80
#define GYRO_CTRL_REG_OUTPUT_HZ_800 0xC0

#define GYRO_CTRL_REG_DATA_READY 0x08

#define GYRO_CTRL_REG_SCALE_250  0x00
#define GYRO_CTRL_REG_SCALE_500  0x10
#define GYRO_CTRL_REG_SCALE_2000 0x20

#define GYRO_CTRL_REG_BLOCK_UPDATE 0x80

#define GYRO_VALUE_OFFSET 32768

int _configGyro (uint8_t* args)
{
    uint32_t         arguments[6];
    I2C_M_SETUP_Type setup;
    char*            arg_ptr;
    unsigned int     index;
    Status           result;
    uint8_t          ctrl_reg_1_value;
    uint8_t          ctrl_reg_3_value;
    uint8_t          ctrl_reg_4_value;

    for(index = 0; index < 6; index++)
    {
        arg_ptr = strtok(NULL, " ");
        if(arg_ptr == NULL)
            return 1;

        arguments[index] = strtoul(arg_ptr, NULL, 16);
    }

    ctrl_reg_1_value = 0;

    if(arguments[0] == 1)
        ctrl_reg_1_value |= GYRO_CTRL_REG_POWER_ON;

    if(arguments[1] == 1)
        ctrl_reg_1_value |= GYRO_CTRL_REG_X_ENABLE;
    if(arguments[2] == 1)
        ctrl_reg_1_value |= GYRO_CTRL_REG_Y_ENABLE;
    if(arguments[3] == 1)
        ctrl_reg_1_value |= GYRO_CTRL_REG_Z_ENABLE;

    switch(arguments[4])
    {
    case 100:
        ctrl_reg_1_value |= GYRO_CTRL_REG_OUTPUT_HZ_100;
        break;

    case 200:
        ctrl_reg_1_value |= GYRO_CTRL_REG_OUTPUT_HZ_200;
        break;

    case 400:
        ctrl_reg_1_value |= GYRO_CTRL_REG_OUTPUT_HZ_400;
        break;

    case 800:
        ctrl_reg_1_value |= GYRO_CTRL_REG_OUTPUT_HZ_800;
        break;

    default:
        return 1;
    }

    ctrl_reg_3_value = GYRO_CTRL_REG_DATA_READY;
    ctrl_reg_4_value = GYRO_CTRL_REG_BLOCK_UPDATE;

    switch(arguments[5])
    {
    case 250:
        ctrl_reg_4_value |= GYRO_CTRL_REG_SCALE_250;
        break;

    case 500:
        ctrl_reg_4_value |= GYRO_CTRL_REG_SCALE_500;
        break;

    case 2000:
        ctrl_reg_4_value |= GYRO_CTRL_REG_SCALE_2000;
        break;

    default:
        return 1;
    }

    setup.sl_addr7bit         = GYRO_I2C_SLAVE_ADDRESS;
    setup.retransmissions_max = MAX_ST_I2C_RETRANSMISSIONS;

    result = WriteStI2CRegister(&setup, GYRO_CTRL_REG_1_ADDRESS, ctrl_reg_1_value);
    if(result == 1)
        return 1;

    gyro_ctrl_reg_1_value = ctrl_reg_1_value;

    result = WriteStI2CRegister(&setup, GYRO_CTRL_REG_3_ADDRESS, ctrl_reg_3_value);
    if(result == 1)
        return 1;

    result = WriteStI2CRegister(&setup, GYRO_CTRL_REG_4_ADDRESS, ctrl_reg_4_value);
    if(result == 1)
        return 1;

    return 0;
}

int _readGyro(uint8_t * args)
{
    uint8_t          receive_buffer[6];
    I2C_M_SETUP_Type setup;
    int16_t*         axis_data;
    char*            formatted_string;
    Status           result;
    uint8_t          transmit_buffer;
    uint8_t          axis_enable_bit;

    setup.sl_addr7bit         = GYRO_I2C_SLAVE_ADDRESS;
    setup.retransmissions_max = MAX_ST_I2C_RETRANSMISSIONS;

    setup.tx_data   = &transmit_buffer;
    setup.tx_length = 1;
    setup.rx_data   = receive_buffer;
    setup.rx_length = 6;

    transmit_buffer = GYRO_DATA_ADDRESS|ST_I2C_AUTOINCREMENT_ADDRESS;

    result = I2C_MasterTransferData(LPC_I2C0, &setup, I2C_TRANSFER_POLLING);
    if(result == ERROR)
        return 1;

    axis_enable_bit = GYRO_CTRL_REG_X_ENABLE;
    axis_data       = (int16_t*)receive_buffer;

    formatted_string = (char*)str;

    do
    {
        if(gyro_ctrl_reg_1_value&axis_enable_bit)
        {
            unsigned int value;
            int          formatted_size;

            value = (unsigned int)(*axis_data+GYRO_VALUE_OFFSET);

            formatted_size = sprintf(formatted_string, "%x\r\n", value);
            if(formatted_size > 0)
                formatted_string += formatted_size;
        }

        axis_enable_bit <<= 1;
        axis_data++;
    }while(axis_enable_bit <= GYRO_CTRL_REG_Z_ENABLE);

    writeUSBOutString(str);

    return 0;
}

