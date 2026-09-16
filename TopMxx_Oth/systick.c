/*!
    \file    systick.c
    \brief   SysTick 配置文件

    \version 2022-05-08, V2.0.0, GD32F4xx 示例
*/

/*
    Copyright (c) 2022, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#include "gd32f4xx.h"
#include "systick.h"

volatile static uint32_t delay;

/*!
    \brief      配置 SysTick
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void systick_config(void)
{
    /* 设置 SysTick 定时器为 1000Hz 中断频率 */
    if(SysTick_Config(SystemCoreClock / 1000U)) {
        /* 捕获错误，进入死循环 */
        while(1) {
        }
    }
    /* 配置 SysTick 中断优先级 */
    NVIC_SetPriority(SysTick_IRQn, 0x00U);
}

/*!
    \brief      毫秒级延时
    \param[in]  count: 延时毫秒数
    \param[out] 无
    \retval     无
*/
void delay_1ms(uint32_t count)
{
    delay = count;

    while(0U != delay) {
    }
}

/*!
    \brief      延时计数值递减
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void delay_decrement(void)
{
    if(0U != delay) {
        delay--;
    }
}
