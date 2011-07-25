/**************************************************************************//**
 * @file     system_LPC17xx.c
 * @brief    CMSIS Cortex-M3 Device Peripheral Access Layer Source File
 *           for the NXP LPC17xx Device Series
 * @version  V1.03
 * @date     07. October 2009
 *
 * @note
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#include <stdint.h>
#include "LPC17xx.h"


/*
 * Clock Configuration
 */
#define CLOCK_SETUP           1
#define SCS_Val               0x00000020    /* Enable main 12MHz osc.         */
#define CLKSRCSEL_Val         0x00000001    /* Clock source is main osc.      */
#define PLL0_SETUP            1
#define PLL0CFG_Val           0x0000000E    /* Fcco = 12*15*2 = 360MHz  */
#define PLL1_SETUP            1
#define PLL1CFG_Val           0x00000023    /* USB PLL */
#define CCLKCFG_Val           0x00000002    /* CPU clock = 360/3 = 120 MHz    */
#define USBCLKCFG_Val         0x00000000    /* Not used since PLL1 is enabled */
#define PCLKSEL0_Val          0x00000000    /* All peripheral clocks operate  */
#define PCLKSEL1_Val          0x00000000    /* at 30MHz                       */
#define PCONP_Val             0x042887DE
#define CLKOUTCFG_Val         0x00000130    /* Enable CCLK/4 out              */

#define FLASHCFG_Val          0x0000403A    /* Flash access time 5 CPU cycles */


/*----------------------------------------------------------------------------
  Check the register settings
 *----------------------------------------------------------------------------*/
#define CHECK_RANGE(val, min, max)                ((val < min) || (val > max))
#define CHECK_RSVD(val, mask)                     (val & mask)

/* Clock Configuration -------------------------------------------------------*/
#if (CHECK_RSVD((SCS_Val),       ~0x00000030))
   #error "SCS: Invalid values of reserved bits!"
#endif

#if (CHECK_RANGE((CLKSRCSEL_Val), 0, 2))
   #error "CLKSRCSEL: Value out of range!"
#endif

#if (CHECK_RSVD((PLL0CFG_Val),   ~0x00FF7FFF))
   #error "PLL0CFG: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((PLL1CFG_Val),   ~0x0000007F))
   #error "PLL1CFG: Invalid values of reserved bits!"
#endif

//#if ((CCLKCFG_Val != 0) && (((CCLKCFG_Val - 1) % 2)))
//   #error "CCLKCFG: CCLKSEL field does not contain only odd values or 0!"
//#endif

#if (CHECK_RSVD((USBCLKCFG_Val), ~0x0000000F))
   #error "USBCLKCFG: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((PCLKSEL0_Val),   0x000C0C00))
   #error "PCLKSEL0: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((PCLKSEL1_Val),   0x03000300))
   #error "PCLKSEL1: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((PCONP_Val),      0x10100821))
   #error "PCONP: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((CLKOUTCFG_Val), ~0x000001FF))
   #error "CLKOUTCFG: Invalid values of reserved bits!"
#endif

/* Flash Accelerator Configuration -------------------------------------------*/
#if (CHECK_RSVD((FLASHCFG_Val), ~0x0000F07F))
   #error "FLASHCFG: Invalid values of reserved bits!"
#endif


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define XTAL        (12000000UL)        /* Oscillator frequency               */
//#define XTAL        (16000000UL)        /* Oscillator frequency               */
//#define XTAL        (24000000UL)        /* Oscillator frequency               */
#define OSC_CLK     (      XTAL)        /* Main oscillator frequency          */
#define RTC_CLK     (   32768UL)        /* RTC oscillator frequency           */
#define IRC_OSC     ( 4000000UL)        /* Internal RC oscillator frequency   */


/* F_cco0 = (2 * M * F_in) / N  */
#define __M               (((PLL0CFG_Val      ) & 0x7FFF) + 1)
#define __N               (((PLL0CFG_Val >> 16) & 0x00FF) + 1)
#define __FCCO(__F_IN)    ((2 * __M * __F_IN) / __N)
#define __CCLK_DIV        (((CCLKCFG_Val      ) & 0x00FF) + 1)

/* Determine core clock frequency according to settings */
 #if (PLL0_SETUP)
    #if   ((CLKSRCSEL_Val & 0x03) == 1)
        #define __CORE_CLK (__FCCO(OSC_CLK) / __CCLK_DIV)
    #elif ((CLKSRCSEL_Val & 0x03) == 2)
        #define __CORE_CLK (__FCCO(RTC_CLK) / __CCLK_DIV)
    #else
        #define __CORE_CLK (__FCCO(IRC_OSC) / __CCLK_DIV)
    #endif
 #else
    #if   ((CLKSRCSEL_Val & 0x03) == 1)
        #define __CORE_CLK (OSC_CLK         / __CCLK_DIV)
    #elif ((CLKSRCSEL_Val & 0x03) == 2)
        #define __CORE_CLK (RTC_CLK         / __CCLK_DIV)
    #else
        #define __CORE_CLK (IRC_OSC         / __CCLK_DIV)
    #endif
 #endif

 /**
  * @}
  */


/** @addtogroup LPC17xx_System_Public_Variables  LPC17xx System Public Variables
  @{
 */
/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = __CORE_CLK;/*!< System Clock Frequency (Core Clock)*/

/**
 * @}
 */


/** @addtogroup LPC17xx_System_Public_Functions  LPC17xx System Public Functions
  @{
 */

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/


void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
  /* Determine clock frequency according to clock register values             */
  if (((LPC_SC->PLL0STAT >> 24) & 3) == 3) { /* If PLL0 enabled and connected */
    switch (LPC_SC->CLKSRCSEL & 0x03) {
      case 0:                                /* Int. RC oscillator => PLL0    */
      case 3:                                /* Reserved, default to Int. RC  */
        SystemCoreClock = (IRC_OSC *
                          ((2 * ((LPC_SC->PLL0STAT & 0x7FFF) + 1)))  /
                          (((LPC_SC->PLL0STAT >> 16) & 0xFF) + 1)    /
                          ((LPC_SC->CCLKCFG & 0xFF)+ 1));
        break;
      case 1:                                /* Main oscillator => PLL0       */
        SystemCoreClock = (OSC_CLK *
                          ((2 * ((LPC_SC->PLL0STAT & 0x7FFF) + 1)))  /
                          (((LPC_SC->PLL0STAT >> 16) & 0xFF) + 1)    /
                          ((LPC_SC->CCLKCFG & 0xFF)+ 1));
        break;
      case 2:                                /* RTC oscillator => PLL0        */
        SystemCoreClock = (RTC_CLK *
                          ((2 * ((LPC_SC->PLL0STAT & 0x7FFF) + 1)))  /
                          (((LPC_SC->PLL0STAT >> 16) & 0xFF) + 1)    /
                          ((LPC_SC->CCLKCFG & 0xFF)+ 1));
        break;
    }
  } else {
    switch (LPC_SC->CLKSRCSEL & 0x03) {
      case 0:                                /* Int. RC oscillator => PLL0    */
      case 3:                                /* Reserved, default to Int. RC  */
        SystemCoreClock = IRC_OSC / ((LPC_SC->CCLKCFG & 0xFF)+ 1);
        break;
      case 1:                                /* Main oscillator => PLL0       */
        SystemCoreClock = OSC_CLK / ((LPC_SC->CCLKCFG & 0xFF)+ 1);
        break;
      case 2:                                /* RTC oscillator => PLL0        */
        SystemCoreClock = RTC_CLK / ((LPC_SC->CCLKCFG & 0xFF)+ 1);
        break;
    }
  }

}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
#if (CLOCK_SETUP)                       /* Clock Setup                        */
  LPC_SC->SCS       = SCS_Val;
  if (LPC_SC->SCS & (1 << 5)) {             /* If Main Oscillator is enabled  */
    while ((LPC_SC->SCS & (1<<6)) == 0);/* Wait for Oscillator to be ready    */
  }

  LPC_SC->CCLKCFG   = CCLKCFG_Val;      /* Setup Clock Divider                */
  /* Periphral clock must be selected before PLL0 enabling and connecting
   * - according errata.lpc1768-16.March.2010 -
   */
  LPC_SC->PCLKSEL0  = PCLKSEL0_Val;     /* Peripheral Clock Selection         */
  LPC_SC->PCLKSEL1  = PCLKSEL1_Val;

#if (PLL0_SETUP)
  LPC_SC->CLKSRCSEL = CLKSRCSEL_Val;    /* Select Clock Source for PLL0       */

  LPC_SC->PLL0CFG   = PLL0CFG_Val;      /* configure PLL0                     */
  LPC_SC->PLL0FEED  = 0xAA;
  LPC_SC->PLL0FEED  = 0x55;

  LPC_SC->PLL0CON   = 0x01;             /* PLL0 Enable                        */
  LPC_SC->PLL0FEED  = 0xAA;
  LPC_SC->PLL0FEED  = 0x55;
  while (!(LPC_SC->PLL0STAT & (1<<26)));/* Wait for PLOCK0                    */

  LPC_SC->PLL0CON   = 0x03;             /* PLL0 Enable & Connect              */
  LPC_SC->PLL0FEED  = 0xAA;
  LPC_SC->PLL0FEED  = 0x55;
  while (!(LPC_SC->PLL0STAT & ((1<<25) | (1<<24))));/* Wait for PLLC0_STAT & PLLE0_STAT */
#endif

#if (PLL1_SETUP)
  LPC_SC->PLL1CFG   = PLL1CFG_Val;
  LPC_SC->PLL1FEED  = 0xAA;
  LPC_SC->PLL1FEED  = 0x55;

  LPC_SC->PLL1CON   = 0x01;             /* PLL1 Enable                        */
  LPC_SC->PLL1FEED  = 0xAA;
  LPC_SC->PLL1FEED  = 0x55;
  while (!(LPC_SC->PLL1STAT & (1<<10)));/* Wait for PLOCK1                    */

  LPC_SC->PLL1CON   = 0x03;             /* PLL1 Enable & Connect              */
  LPC_SC->PLL1FEED  = 0xAA;
  LPC_SC->PLL1FEED  = 0x55;
  while (!(LPC_SC->PLL1STAT & ((1<< 9) | (1<< 8))));/* Wait for PLLC1_STAT & PLLE1_STAT */
#else
  LPC_SC->USBCLKCFG = USBCLKCFG_Val;    /* Setup USB Clock Divider            */
#endif
  LPC_SC->PCONP     = PCONP_Val;        /* Power Control for Peripherals      */

  LPC_SC->CLKOUTCFG = CLKOUTCFG_Val;    /* Clock Output Configuration         */
#endif

#if (FLASH_SETUP == 1)                  /* Flash Accelerator Setup            */
  LPC_SC->FLASHCFG  = FLASHCFG_Val;
#endif

//  Set Vector table offset value
#if (__RAM_MODE__==1)
  SCB->VTOR  = 0x10000000 & 0x3FFFFF80;
#else
  SCB->VTOR  = 0x00000000 & 0x3FFFFF80;
#endif
}

/**
 * @}
 */

/**
 * @}
 */
