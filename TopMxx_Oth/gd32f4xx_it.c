/*!
    \file    gd32f4xx_it.c
    \brief   中断服务函数

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

#include "gd32f4xx_it.h"
//#include "gd32f427r_start.h"
#include "systick.h"

/*!
    \brief      NMI 异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void NMI_Handler(void)
{
}

/*!
    \brief      HardFault 硬件错误异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void HardFault_Handler(void)
{
    /* 若发生硬件错误异常，进入死循环 */
    while(1) {
    }
}

/*!
    \brief      MemManage 内存管理异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void MemManage_Handler(void)
{
    /* 若发生内存管理异常，进入死循环 */
    while(1) {
    }
}

/*!
    \brief      BusFault 总线错误异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void BusFault_Handler(void)
{
    /* 若发生总线错误异常，进入死循环 */
    while(1) {
    }
}

/*!
    \brief      UsageFault 用法错误异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void UsageFault_Handler(void)
{
    /* 若发生用法错误异常，进入死循环 */
    while(1) {
    }
}

/*!
    \brief      SVC 系统服务调用异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void SVC_Handler(void)
{
}

/*!
    \brief      DebugMon 调试监控异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void DebugMon_Handler(void)
{
}

/*!
    \brief      PendSV 挂起系统调用异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void PendSV_Handler(void)
{
}

/*!
    \brief      SysTick 系统节拍异常中断服务函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
void SysTick_Handler(void)
{
    delay_decrement();
}
