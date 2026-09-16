/*!
    \file    main.c
    \brief   GPIO 跑马灯示例

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

#ifndef Main_c
	#define Main_c
#endif

#include "Include.h"

#include "include.h"
#include "systick.h"
#include <stdio.h>

/*!
    \brief      主函数
    \param[in]  无
    \param[out] 无
    \retval     无
*/
int main(void)
{
    U32 i;
    // 配置 SysTick
    //systick_config();
    IntVectTabRemap();
    Time_Drv_Init();
    I2Cx_Drv_Init();			//I2C总线初始化		I2C_Drv.c				执行顺序固定
    Comm_Drv_Init();
    LADC_Drv_Init();
    //CanModule_Drv_Init();		//CAN模块初始化		CanModule_Drv_Init.c
    SimBus_Drv_Init();			//模拟总线初始化		SimBus_Drv.c			执行顺序固定
	HardPlat_Drv_Init();		//硬件平台初始化		HardPlat_Drv.c			执行顺序固定
	RPHA_Init();				//RPHA初始化			RPHA.c					执行顺序固定
	
	DigiLed_Init();				//数码LED初始化		DigiLed_Drv.	IDO_Drv_Init();			//DIDO驱动初始化		DIDO_Drv.c
	DIDO_Drv_Init();			//DIDO驱动初始化		DIDO_Drv.c
	//DAC_Drv_Init();				//DAC驱动初始化		DAC_Drv.c
	HADC_Drv_Init();			//HADC驱动初始化		HADC_Drv.c

    while(1)
    {
        
        Comm_Drv_Pcs();
        LADC_Drv_Pcs();
        //CanModule_Drv_Pcs();		//CAN模块处理			CanModule_Drv.c
       	HardPlat_Drv_Pcs();			//硬件平台处理			HardPlat_Drv.c	
		DigiLed_Pcs();				//数码LED显示处理		DigiLed_Drv.c	
		DIDO_Drv_Pcs();				//DIDO驱动处理			DIDO_Drv.c	
		//DAC_Drv_Pcs();				//DAC驱动处理			DAC_Drv.c		
		HADC_Drv_Pcs();				//HADC驱动处理			HADC_Drv.c
		
		RPHA_Pcs();					//RPHA参数处理			RPHA.c			机器参数保存时，最长周期用时约460us（累加和计算并保存周期）
        
    }
}
//这是一句废话


