/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：MADC_Drv.c
文件说明：中速ADC驱动。

作    者：WLZ
编写时间：2025.11
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================


1、相关硬件：	PC7/TIM3_CH2	计数输入

2、MADC为中速ADC，更新周期20mS，最低测量电压20mV左右

3、实测信号跳动2-3个字

****************************************************************************************************/
//#define mSysDebug		

#ifndef MADC_Drv_c
	#define MADC_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define mMadcSampleTime	T1msTo10us(20)					//AD7740 V/F计数窗口时间，非PWM周期
#define mMadcMax		0xffff							//MADC最大值

/*======================================= 模块内有效变量定义 ======================================*/

static U16 CntLast = 0;
static G10usTimer MADC_SampleTimer;		//MADC采样窗口计时器


/*======================================= 模块内有效函数声明 ======================================*/


/****************************************************************************************************
函数名称：int main(void)
函数说明：主函数
输入参数：
返 回 值：
其    它：为方便本文件中函数调试而设
****************************************************************************************************/
#ifdef mSysDebug
int main(void)
{           
	do{
	}while(mTrue);
}
#endif	//mSysDebug

/****************************************************************************************************
函数名称：MADC初始化
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void MADC_Drv_Init(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct;

    if(HardConf_MADNum==0)
    	return;
   	/* 1. 启用外设时钟（H743：GPIO在AHB4总线，TIM3在D2域APB1） */
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOC);

    /* 2. 配置GPIO引脚 - PC7 (TIM3_CH2, AF2) */
    GPIO_InitStruct.Pin        = LL_GPIO_PIN_7;
	GPIO_InitStruct.Mode       = LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStruct.Speed      = LL_GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull       = LL_GPIO_PULL_NO;
	GPIO_InitStruct.Alternate  = LL_GPIO_AF_2;			// TIM3_CH2的AF2
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
    //rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);	//已由Time_Drv_Init()设置TIMPRE=4倍频
    LL_TIM_DeInit(TIM3);
    /* 3. 定时器基本参数配置 */
    /* AD7740输出为V/F脉冲，定时器直接对PC7上升沿计数 */
    LL_TIM_DisableCounter(TIM3);
    LL_TIM_DisableIT_CC2(TIM3);
    LL_TIM_SetPrescaler(TIM3, 0U);
    LL_TIM_SetCounterMode(TIM3, LL_TIM_COUNTERMODE_UP);
    LL_TIM_SetAutoReload(TIM3, 0xFFFFU);			// 16位定时器
    LL_TIM_SetClockDivision(TIM3, LL_TIM_CLOCKDIVISION_DIV1);
	LL_TIM_GenerateEvent_UPDATE(TIM3);					//软件更新，立即加载PSC/ARR

    /* 4. 配置CH2为外部时钟输入（TI2上升沿计数） */
    LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_IC_POLARITY_RISING);
    LL_TIM_IC_SetActiveInput(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_ACTIVEINPUT_DIRECTTI);
    LL_TIM_IC_SetFilter(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_IC_FILTER_FDIV1);		// 无滤波
    LL_TIM_IC_SetPrescaler(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_ICPSC_DIV1);
    LL_TIM_SetTriggerInput(TIM3, LL_TIM_TS_TI2FP2);
    LL_TIM_SetClockSource(TIM3, LL_TIM_CLOCKSOURCE_EXT_MODE1);
    LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH2);	//开启外部时钟输入通道
    LL_TIM_ClearFlag_UPDATE(TIM3);
    LL_TIM_SetCounter(TIM3, 0U);

    /* 6. 启用定时器 */
    LL_TIM_EnableCounter(TIM3);

    CntLast=(U16)TIM3->CNT;
    G10usTimerRes(&MADC_SampleTimer);
}
/****************************************************************************************************
函数名称：中断处理计数值
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void TIM3_IRQHandler(void)
{
	/* 外部时钟模式下由TIM3硬件累计PC7脉冲，此处无需处理捕获中断。 */
}
/****************************************************************************************************
函数名称：MADC数据采集处理
函数说明：
输入参数：
返 回 值：
其    它：

****************************************************************************************************/
void MADC_Drv_Pcs(void)
{
	U32 Temp;
	U32 SampleTime;
	U16 CntNow;
	U16 CntNum;
	
	 if(HardConf_MADNum==0)
    	return;
    if(G10usTimerOver(&MADC_SampleTimer,mMadcSampleTime))
    {
    	SampleTime=G10usTimerCal(&MADC_SampleTimer);
    	CntNow=(U16)TIM3->CNT;
    	CntNum=(U16)(CntNow-CntLast);				//U16减法自动处理16位回绕
    	CntLast=CntNow;
    	G10usTimerRes(&MADC_SampleTimer);

    	if(CntNum==0)
    	{	//无脉冲时，按输入电平区分全高或全低
    		if(LL_GPIO_IsInputPinSet(GPIOC,LL_GPIO_PIN_7))
    			Temp=mMadcMax;
    		else
    			Temp=0;
    	}
    	else if(CntNum<=SampleTime)
    	{	//AD7740最低输出100kHz，对应Cnt=Tc，低于基线按0处理
    		Temp=0;
    	}
    	else
    	{
			/* AD7740: 100kHz~900kHz对应0~2.5V，映射为0~10V的16位数据 */
    		/* f=Cnt*100kHz/Tc，故Data=(Cnt-Tc)*65535/(8*Tc) */
    		Temp=(U32)(((U64)(CntNum-SampleTime)*mMadcMax)/(SampleTime*8U));
    	}

		if(Temp>mMADC_DataMax)
        	WrResU32(HardConf[mHard_HAD09],mMADC_DataMax);
        else
    		WrResU32(HardConf[mHard_HAD09],Temp);
    }
}

/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
