/**
  ******************************************************************************
  * @file    system_stm32h7xx.c
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M7 Device Peripheral Access Layer System Source File.
  *          This provides system initialization template function is case of
  *          an application using a single core STM32H7 device
  *
  *   This file provides two functions and one global variable to be called from
  *   user application:
  *      - SystemInit(): This function is called at startup just after reset and
  *                      before branch to main program. This call is made inside
  *                      the "startup_stm32h7xx.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick
  *                                  timer or configure other parameters.
  *
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32h7xx_system
  * @{
  */

/** @addtogroup STM32H7xx_System_Private_Includes
  * @{
  */

#include "stm32h7xx.h"
#include <math.h>

#if !defined  (HSE_VALUE)
/* 注: 原 GD32 工程 HXTAL=10MHz (gd32f4xx.h L60), STM32H743 移植沿用 10MHz    */
/* 若硬件实际晶振不同, 待查证原理图后修改此值, 并相应调整 PLL1 参数          */
#define HSE_VALUE    ((uint32_t)10000000) /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (CSI_VALUE)
  #define CSI_VALUE    ((uint32_t)4000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* CSI_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    ((uint32_t)64000000) /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */


/**
  * @}
  */

/** @addtogroup STM32H7xx_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32H7xx_System_Private_Defines
  * @{
  */

/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to use initialized data in D2 domain SRAM (AHB SRAM) */
/* #define DATA_IN_D2_SRAM */

/*!< Uncomment the following line if you need to relocate your vector Table in
     Internal SRAM. */
/* #define VECT_TAB_SRAM */
/* 注: 原 GD32 工程不在 SystemInit 内设 VTOR, 而是在 Main.c L79 调用 IntVectTabRemap() */
/*     把向量表从 Flash(0x08020000) 拷贝到 SRAM(0x20000000) 并将 VTOR 指向 SRAM       */
/*     (见 Boot_IAP.h: mAppIntVectTabDsrAddr=0x20000000)                             */
/*     移植保持同一机制: SystemInit 不设 VTOR, 由 IntVectTabRemap() 完成              */
#define VECT_TAB_OFFSET  0x00000000UL /*!< Vector Table base offset field.
                                      This value must be a multiple of 0x200. */
/******************************************************************************/

/**
  * @}
  */

/** @addtogroup STM32H7xx_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32H7xx_System_Private_Variables
  * @{
  */
  /* This variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetHCLKFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
         Note: If you use this function to configure the system clock; then there
               is no need to call the 2 first functions listed above, since SystemCoreClock
               variable is updated automatically.
  */
  uint32_t SystemCoreClock = 200000000;
  uint32_t SystemD2Clock = 20000000;
  const  uint8_t D1CorePrescTable[16] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};

/**
  * @}
  */

/** @addtogroup STM32H7xx_System_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32H7xx_System_Private_Functions
  * @{
  */

/**
  * @brief  Setup the microcontroller system
  *         Initialize the FPU setting and  vector table location
  *         configuration.
  * @param  None
  * @retval None
  */
void SystemInit (void)
{
#if defined (DATA_IN_D2_SRAM)
 __IO uint32_t tmpreg;
#endif /* DATA_IN_D2_SRAM */

  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << (10*2))|(3UL << (11*2)));  /* set CP10 and CP11 Full Access */
  #endif
  /* Reset the RCC clock configuration to the default reset state ------------*/

   /* Increasing the CPU frequency */
  if(FLASH_LATENCY_DEFAULT  > (READ_BIT((FLASH->ACR), FLASH_ACR_LATENCY)))
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
	MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, (uint32_t)(FLASH_LATENCY_DEFAULT));
  }

  /* Set HSION bit */
  RCC->CR |= RCC_CR_HSION;

  /* Reset CFGR register */
  RCC->CFGR = 0x00000000;

  /* Reset HSEON, HSECSSON, CSION, HSI48ON, CSIKERON, PLL1ON, PLL2ON and PLL3ON bits */
  RCC->CR &= 0xEAF6ED7FU;

   /* Decreasing the number of wait states because of lower CPU frequency */
  if(FLASH_LATENCY_DEFAULT  < (READ_BIT((FLASH->ACR), FLASH_ACR_LATENCY)))
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
	MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, (uint32_t)(FLASH_LATENCY_DEFAULT));
  }

#if defined(D3_SRAM_BASE)
  /* Reset D1CFGR register */
  RCC->D1CFGR = 0x00000000;

  /* Reset D2CFGR register */
  RCC->D2CFGR = 0x00000000;

  /* Reset D3CFGR register */
  RCC->D3CFGR = 0x00000000;
#else
  /* Reset CDCFGR1 register */
  RCC->CDCFGR1 = 0x00000000;

  /* Reset CDCFGR2 register */
  RCC->CDCFGR2 = 0x00000000;

  /* Reset SRDCFGR register */
  RCC->SRDCFGR = 0x00000000;
#endif
  /* Reset PLLCKSELR register */
  RCC->PLLCKSELR = 0x02020200;

  /* Reset PLLCFGR register */
  RCC->PLLCFGR = 0x01FF0000;
  /* Reset PLL1DIVR register */
  RCC->PLL1DIVR = 0x01010280;
  /* Reset PLL1FRACR register */
  RCC->PLL1FRACR = 0x00000000;

  /* Reset PLL2DIVR register */
  RCC->PLL2DIVR = 0x01010280;

  /* Reset PLL2FRACR register */

  RCC->PLL2FRACR = 0x00000000;
  /* Reset PLL3DIVR register */
  RCC->PLL3DIVR = 0x01010280;

  /* Reset PLL3FRACR register */
  RCC->PLL3FRACR = 0x00000000;

  /* Reset HSEBYP bit */
  RCC->CR &= 0xFFFBFFFFU;

  /* Disable all interrupts */
  RCC->CIER = 0x00000000;

#if (STM32H7_DEV_ID == 0x450UL)
  /* single core line */
  if((DBGMCU->IDCODE & 0xFFFF0000U) < 0x20000000U)
  {
    /* if stm32h7 revY*/
    /* Change  the switch matrix read issuing capability to 1 for the AXI SRAM target (Target 7) */
    *((__IO uint32_t*)0x51008108) = 0x000000001U;
  }
#endif

#if defined (DATA_IN_D2_SRAM)
  /* in case of initialized data in D2 SRAM (AHB SRAM), enable the D2 SRAM clock (AHB SRAM clock) */
#if defined(RCC_AHB2ENR_D2SRAM3EN)
  RCC->AHB2ENR |= (RCC_AHB2ENR_D2SRAM1EN | RCC_AHB2ENR_D2SRAM2EN | RCC_AHB2ENR_D2SRAM3EN);
#elif defined(RCC_AHB2ENR_D2SRAM2EN)
  RCC->AHB2ENR |= (RCC_AHB2ENR_D2SRAM1EN | RCC_AHB2ENR_D2SRAM2EN);
#else
  RCC->AHB2ENR |= (RCC_AHB2ENR_AHBSRAM1EN | RCC_AHB2ENR_AHBSRAM2EN);
#endif /* RCC_AHB2ENR_D2SRAM3EN */
  tmpreg = RCC->AHB2ENR;
  (void) tmpreg;
#endif /* DATA_IN_D2_SRAM */

  /*
   * Disable the FMC bank1 (enabled after reset).
   * This, prevents CPU speculation access on this bank which blocks the use of FMC during
   * 24us. During this time the others FMC master (such as LTDC) cannot use it!
   */
  FMC_Bank1_R->BTCR[0] = 0x000030D2;

  /* Configure the Vector Table location add offset address ------------------*/
#ifdef VECT_TAB_SRAM
  SCB->VTOR = D1_AXISRAM_BASE  | VECT_TAB_OFFSET;       /* Vector Table Relocation in Internal AXI-RAM */
#else
  SCB->VTOR = FLASH_BANK1_BASE | VECT_TAB_OFFSET;       /* Vector Table Relocation in Internal FLASH */
#endif

  /* ======================================================================== */
  /* === STM32H743 时钟配置 (移植自原 GD32 system_clock_200m_25m_hxtal) ===== */
  /* ======================================================================== */
  /* 配置目标: sys_ck=200MHz, HCLK=200MHz, PCLK1=50MHz, PCLK2=100MHz          */
  /* HSE=10MHz (与原 GD32 工程一致), PLL1: M=5, N=200, P=2                    */
  /*   VCO_in = 10/5 = 2 MHz (PLL1VCIRANGE_1: 2-4MHz, 见下方步骤4)            */
  /*   VCO_out = 2*200 = 400 MHz (PLL1VCOWIDE: 192-836MHz)                   */
  /*   sys_ck  = 400/2 = 200 MHz                                              */
  /*                                                                          */
  /* 0. 电源配置: LDO 供电 + 电压调节 Scale1 (与 ST 200MHz 官方示例一致)       */
  /*    H743 PWR 时钟复位后默认使能 (RCC_APB4ENR 无 PWREN 位),可直接写寄存器   */
  /*    Scale1 支持最高 400MHz, 200MHz 运行余量充足                          */
  PWR->CR3 |= PWR_CR3_LDOEN;                                     /* LDO 供电 (复位默认已使能, 幂等) */
  MODIFY_REG(PWR->D3CR, PWR_D3CR_VOS, PWR_D3CR_VOS_1 | PWR_D3CR_VOS_0);  /* VOS = Scale1 */
  while((PWR->D3CR & PWR_D3CR_VOSRDY) == 0U) {}                  /* 等待电压调节稳定 */

  /* 1. 启用 HSE 并等待稳定                                                   */
  RCC->CR |= RCC_CR_HSEON;
  while((RCC->CR & RCC_CR_HSERDY) == 0U) {}

  /* 2. PLL1 时钟源选择为 HSE, PLL1M=5 (PLLCKSELR.PLLSRC=HSE, DIVM1=5)        */
  RCC->PLLCKSELR = RCC_PLLCKSELR_PLLSRC_HSE
                 | (5U << RCC_PLLCKSELR_DIVM1_Pos);

  /* 3. PLL1 N/P/Q/R 配置                                                     */
  /*    PLL1N=200, PLL1P=2, PLL1Q=5, PLL1R=2 (字段值=N-1)                    */
  RCC->PLL1DIVR = ((200U - 1U) << RCC_PLL1DIVR_N1_Pos)
                 | ((2U   - 1U) << RCC_PLL1DIVR_P1_Pos)
                 | ((5U   - 1U) << RCC_PLL1DIVR_Q1_Pos)
                 | ((2U   - 1U) << RCC_PLL1DIVR_R1_Pos);

  /* 4. PLL1 VCO 范围: WIDE (192-836MHz), VCO 输入范围: 2-4MHz (RANGE_1)      */
  /*    VCO_in = 2MHz → PLL1RGE_1 (2-4MHz档); VCOSEL=0 → WIDE VCO            */
  RCC->PLLCFGR = (RCC->PLLCFGR & ~(RCC_PLLCFGR_PLL1VCOSEL | RCC_PLLCFGR_PLL1RGE))
               | RCC_PLLCFGR_PLL1RGE_1;              /* VCO输入2-4MHz档 */

  /* 5. 启用 PLL1 并等待稳定                                                  */
  RCC->CR |= RCC_CR_PLL1ON;
  while((RCC->CR & RCC_CR_PLL1RDY) == 0U) {}

  /* 6. 配置 Flash latency = 4 WS (上电默认 VOS3, 200MHz HCLK 需 4 WS)         */
  /*    注意: 后续可切到 VOS0 + 2 WS 以提升性能                              */
  FLASH->ACR = (FLASH->ACR & ~FLASH_ACR_LATENCY) | FLASH_ACR_LATENCY_4WS;

  /* 7. 配置总线分频 (与原 GD32 工程一致: HCLK=200, APB1=50, APB2=100)        */
  /*    D1CPRE=1 (sys_ck → HCLK 不分频), HPRE=1  (HCLK=200MHz)               */
  /*    D1PPRE=4 (APB3=HCLK/2=100MHz, 字段值=4 即二进制100)                   */
  /*    D2PPRE1=5 (PCLK1=HCLK/4=50MHz, 字段值=5 即二进制101)                  */
  /*    D2PPRE2=4 (PCLK2=HCLK/2=100MHz, 字段值=4 即二进制100)                 */
  /*    D3PPRE=4  (APB4=HCLK/2=100MHz, 字段值=4 即二进制100)                  */
  RCC->D1CFGR = (0U  << RCC_D1CFGR_D1CPRE_Pos)    /* D1CPRE=1, sys_ck → 200MHz */
              | (0U  << RCC_D1CFGR_HPRE_Pos)      /* HPRE=1, HCLK=200MHz       */
              | (4U  << RCC_D1CFGR_D1PPRE_Pos);   /* D1PPRE=4 (100), APB3=100MHz */

  RCC->D2CFGR = (5U  << RCC_D2CFGR_D2PPRE1_Pos)  /* D2PPRE1=5 (101), PCLK1=50MHz */
              | (4U  << RCC_D2CFGR_D2PPRE2_Pos);  /* D2PPRE2=4 (100), PCLK2=100MHz */

  RCC->D3CFGR = (4U  << RCC_D3CFGR_D3PPRE_Pos);   /* D3PPRE=4 (100), APB4=100MHz */

  /* 8. 选择 PLL1 作为系统时钟 (SW=PLL1)                                      */
  RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_PLL1;
  while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL1) {}

  /* 9. 显式赋值 SystemCoreClock = 200MHz                                       */
  SystemCoreClock = 200000000U;
}

/**
   * @brief  Update SystemCoreClock variable according to Clock Register Values.
  *         The SystemCoreClock variable contains the core clock , it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  *
  * @note   Each time the core clock changes, this function must be called
  *         to update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.
  *
  * @note   - The system frequency computed by this function is not the real
  *           frequency in the chip. It is calculated based on the predefined
  *           constant and the selected clock source:
  *
  *           - If SYSCLK source is CSI, SystemCoreClock will contain the CSI_VALUE(*)
  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(**)
  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(***)
  *           - If SYSCLK source is PLL, SystemCoreClock will contain the CSI_VALUE(*),
  *             HSI_VALUE(**) or HSE_VALUE(***) multiplied/divided by the PLL factors.
  *
  *         (*) CSI_VALUE is a constant defined in stm32h7xx_hal.h file (default value
  *             4 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.
  *         (**) HSI_VALUE is a constant defined in stm32h7xx_hal.h file (default value
  *             64 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.
  *
  *         (***)HSE_VALUE is a constant defined in stm32h7xx_hal.h file (default value
  *              25 MHz), user has to ensure that HSE_VALUE is same as the real
  *              frequency of the crystal used. Otherwise, this function may
  *              have wrong result.
  *
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate (void)
{
  uint32_t pllp, pllsource, pllm, pllfracen, hsivalue, tmp;
  float_t fracn1, pllvco;

  /* Get SYSCLK source -------------------------------------------------------*/

  switch (RCC->CFGR & RCC_CFGR_SWS)
  {
  case RCC_CFGR_SWS_HSI:  /* HSI used as system clock source */
   SystemCoreClock = (uint32_t) (HSI_VALUE >> ((RCC->CR & RCC_CR_HSIDIV)>> 3));

    break;

  case RCC_CFGR_SWS_CSI:  /* CSI used as system clock  source */
    SystemCoreClock = CSI_VALUE;
    break;

  case RCC_CFGR_SWS_HSE:  /* HSE used as system clock  source */
    SystemCoreClock = HSE_VALUE;
    break;

  case RCC_CFGR_SWS_PLL1:  /* PLL1 used as system clock  source */

    /* PLL_VCO = (HSE_VALUE or HSI_VALUE or CSI_VALUE/ PLLM) * PLLN
    SYSCLK = PLL_VCO / PLLR
    */
    pllsource = (RCC->PLLCKSELR & RCC_PLLCKSELR_PLLSRC);
    pllm = ((RCC->PLLCKSELR & RCC_PLLCKSELR_DIVM1)>> 4)  ;
    pllfracen = ((RCC->PLLCFGR & RCC_PLLCFGR_PLL1FRACEN)>>RCC_PLLCFGR_PLL1FRACEN_Pos);
    fracn1 = (float_t)(uint32_t)(pllfracen* ((RCC->PLL1FRACR & RCC_PLL1FRACR_FRACN1)>> 3));

    if (pllm != 0U)
    {
      switch (pllsource)
      {
        case RCC_PLLCKSELR_PLLSRC_HSI:  /* HSI used as PLL clock source */

        hsivalue = (HSI_VALUE >> ((RCC->CR & RCC_CR_HSIDIV)>> 3)) ;
        pllvco = ( (float_t)hsivalue / (float_t)pllm) * ((float_t)(uint32_t)(RCC->PLL1DIVR & RCC_PLL1DIVR_N1) + (fracn1/(float_t)0x2000) +(float_t)1 );

        break;

        case RCC_PLLCKSELR_PLLSRC_CSI:  /* CSI used as PLL clock source */
          pllvco = ((float_t)CSI_VALUE / (float_t)pllm) * ((float_t)(uint32_t)(RCC->PLL1DIVR & RCC_PLL1DIVR_N1) + (fracn1/(float_t)0x2000) +(float_t)1 );
        break;

        case RCC_PLLCKSELR_PLLSRC_HSE:  /* HSE used as PLL clock source */
          pllvco = ((float_t)HSE_VALUE / (float_t)pllm) * ((float_t)(uint32_t)(RCC->PLL1DIVR & RCC_PLL1DIVR_N1) + (fracn1/(float_t)0x2000) +(float_t)1 );
        break;

      default:
          hsivalue = (HSI_VALUE >> ((RCC->CR & RCC_CR_HSIDIV)>> 3)) ;
          pllvco = ((float_t)hsivalue / (float_t)pllm) * ((float_t)(uint32_t)(RCC->PLL1DIVR & RCC_PLL1DIVR_N1) + (fracn1/(float_t)0x2000) +(float_t)1 );
        break;
      }
      pllp = (((RCC->PLL1DIVR & RCC_PLL1DIVR_P1) >>9) + 1U ) ;
      SystemCoreClock =  (uint32_t)(float_t)(pllvco/(float_t)pllp);
    }
    else
    {
      SystemCoreClock = 0U;
    }
    break;

  default:
    SystemCoreClock = (uint32_t) (HSI_VALUE >> ((RCC->CR & RCC_CR_HSIDIV)>> 3));
    break;
  }

  /* Compute SystemClock frequency --------------------------------------------------*/
#if defined (RCC_D1CFGR_D1CPRE)
  tmp = D1CorePrescTable[(RCC->D1CFGR & RCC_D1CFGR_D1CPRE)>> RCC_D1CFGR_D1CPRE_Pos];

  /* SystemCoreClock frequency : CM7 CPU frequency  */
  SystemCoreClock >>= tmp;

  /* SystemD2Clock frequency : AXI and AHBs Clock frequency  */
  SystemD2Clock = (SystemCoreClock >> ((D1CorePrescTable[(RCC->D1CFGR & RCC_D1CFGR_HPRE)>> RCC_D1CFGR_HPRE_Pos]) & 0x1FU));
#else
  tmp = D1CorePrescTable[(RCC->CDCFGR1 & RCC_CDCFGR1_CDCPRE)>> RCC_CDCFGR1_CDCPRE_Pos];

  SystemCoreClock >>= tmp;
  /* SystemD2Clock frequency : AXI and AHBs Clock frequency  */
  SystemD2Clock = (SystemCoreClock >> ((D1CorePrescTable[(RCC->CDCFGR1 & RCC_CDCFGR1_HPRE)>> RCC_CDCFGR1_HPRE_Pos]) & 0x1FU));
#endif
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
