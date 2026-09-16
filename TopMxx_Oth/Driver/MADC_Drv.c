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


1、相关硬件：	PC7/TIM2_CH1	计数输入	Tim3

2、MADC为中速ADC，更新周期20mS，最低测量电压20mV左右

3、实测信号跳动2-3个字

****************************************************************************************************/
//#define mSysDebug		

#ifndef MADC_Drv_c
	#define MADC_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define GetVFCCount()	TIMER_CH0CV(TIMER7)			//获取VF当前计数
#define mPwmPeriod		T1msTo10us(20)					//PWM周期时间
#define mMadcMax		0xffff							//MADC最大值

/*======================================= 模块内有效变量定义 ======================================*/

static U16 CntL = 0, CntH = 0;
static Bool MeasFlag;
static U8	MeasStep;
	#define	mMS_Risi	0		//等待检测上升沿
	#define	mMS_Fall	1		//等待检测下降沿
static G10usTimer MeasEdgeTimer;		//边沿出现超时时间


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
	timer_parameter_struct timer_initpara;    
    timer_ic_parameter_struct timer_icinitpara;
    
    if(HardConf_MADNum==0)
    	return;
   	/* 1. 启用外设时钟 */
    rcu_periph_clock_enable(RCU_GPIOC);	//PC6

    /* 2. 配置GPIO引脚 - PC6 (TIMER7_CH0) */
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_6);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
    gpio_af_set(GPIOC, GPIO_AF_3, GPIO_PIN_6);  // TIMER7_CH0的AF3

	rcu_periph_clock_enable(RCU_TIMER7);
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
    timer_deinit(TIMER7);
    /* 3. 定时器基本参数配置 */
    timer_struct_para_init(&timer_initpara);
    
    timer_initpara.prescaler         = 64-1;      // 64分频   200M经64分频到3.125M	50HzPwm波分辨力达到62500	
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 0xFFFFFFFF; // 32位最大值
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER7, &timer_initpara);

    /* 4. 配置输入捕获 */
    timer_channel_input_struct_para_init(&timer_icinitpara);
    
    MeasStep=mMS_Risi;
    timer_icinitpara.icpolarity  = TIMER_IC_POLARITY_RISING; // 上升沿计数
    timer_icinitpara.icselection = TIMER_IC_SELECTION_DIRECTTI;
    timer_icinitpara.icprescaler = TIMER_IC_PSC_DIV1;
    timer_icinitpara.icfilter    = 0;  // 无滤波
    
    timer_input_capture_config(TIMER7, TIMER_CH_0, &timer_icinitpara);
	MeasStep = mMS_Risi;
	
    // 配置输入捕获中断
    timer_interrupt_flag_clear(TIMER7, TIMER_INT_FLAG_CH0);
    timer_interrupt_enable(TIMER7, TIMER_INT_CH0);
    nvic_irq_enable(TIMER7_Channel_IRQn, mIRQPriorityL, mIRQPriorityL);

    /* 6. 启用定时器 */
    timer_enable(TIMER7);
    
    G10usTimerRes(&MeasEdgeTimer);
}
/****************************************************************************************************
函数名称：中断处理计数值
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void TIMER7_Channel_IRQHandler(void)
{
	static U16 CntRisi,CntFall;
	static U16 CL;
    if(timer_interrupt_flag_get(TIMER7, TIMER_INT_FLAG_CH0))
    {
        timer_interrupt_flag_clear(TIMER7, TIMER_INT_FLAG_CH0);
       	
       	G10usTimerRes(&MeasEdgeTimer);
        switch(MeasStep)
        {
        case mMS_Risi: // 捕获上升沿
           
            CntRisi = TIMER_CH0CV(TIMER7);
            CL=CntRisi-CntFall;
            //设置成下降沿捕获
            TIMER_CHCTL2(TIMER7) &= (~(U32)(TIMER_CHCTL2_CH0P | TIMER_CHCTL2_CH0NP));
        	TIMER_CHCTL2(TIMER7) |= (U32)((U32)(TIMER_IC_POLARITY_FALLING) << 0U);
            MeasStep = mMS_Fall;
            break;

        case mMS_Fall: // 捕获下降沿
            CntFall = TIMER_CH0CV(TIMER7);
            CntH=CntFall-CntRisi;
            //设置成上升沿捕获
            TIMER_CHCTL2(TIMER7) &= (~(U32)(TIMER_CHCTL2_CH0P | TIMER_CHCTL2_CH0NP));
        	TIMER_CHCTL2(TIMER7) |= (U32)((U32)(TIMER_IC_POLARITY_RISING) << 0U);
        	MeasStep = mMS_Risi;
            CntL=CL;
            MeasFlag=mTrue;
            break;
        }
    }
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
	
	 if(HardConf_MADNum==0)
    	return;
    if(G10usTimerOver(&MeasEdgeTimer,mPwmPeriod*3/2))
    {	//1.5倍PWM周期未检测到边沿，认为全高或全低
    	if(GPIO_ISTAT(GPIOC)&mBit6)
    		WrResU32(HardConf[mHard_HAD09],0xffff);
    	else
    		WrResU32(HardConf[mHard_HAD09],0x0000);
    }
    else if(MeasFlag)
    {
    	MeasFlag=mFalse;
    	Temp=((U32)CntH)<<16;
    	Temp/=((U32)CntL+(U32)CntH);
        Temp=Temp*2013/1000;    //电阻比值  3.3参考，分压5.1K/1K
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
