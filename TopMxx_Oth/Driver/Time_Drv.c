/* Copyright (C) 2018 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：TopMxx型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：定时器驱动.c
文件说明：

作    者：WLZ
编写时间：2018.01
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================
##系统资源
1、TIMER1\TIMER4及其匹配寄存器。
2、TIMER0中断

##其它说明
1、本文件中驱动比较特殊，独立性较差，定时比较中断与其它驱动可能存在配合关系。
2、本文件中函数是本项目的基础，并且与其它模块存在密切配合关系，涉及定时周期等的程序修改务请谨慎。
3、定时器的定时单位10us，最大12.7h，各时间计算均以其为参考。
4、由于主循环周期不固定，为保证动作中延迟等的时间精度，不采用给出定时中断标志并以其为计时基础的方式，而采用
   保存系统时间（CNT），然后通过计算某时刻与系统时间差值的方式，来得到准确的经过时间。
5、本文件产生2ms定时中断。
6、本文件还定义计时器及其操作方法函数，需要注意使用时操作顺序。

****************************************************************************************************/
//#define mSysDebug				

#ifndef Time_Drv_c
	#define Time_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/


/*======================================= 模块内有效变量定义 ======================================*/


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
	do
	{
	}while(mTrue);
}
#endif	//mSysDebug


/****************************************************************************************************
函数名称：Time驱动初始化
函数说明：Timer2及其中断相关初始化
输入参数：
返 回 值：
其    它：
1)Timer2以10us为单位计时，计时不复位，即计时在0～0xffffffff循环
2)TIM2,TIM5的时钟为APB1的两倍，即100M。APB1为50M，APB2为100M。
****************************************************************************************************/
void Time_Drv_Init(void)
{	
	timer_parameter_struct timer_initpara;    
    //timer_oc_parameter_struct timer_ocintpara;
    
	//定时器1初始化，10us定时器
	rcu_periph_clock_enable(RCU_TIMER1);
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
    timer_struct_para_init(&timer_initpara);
    timer_deinit(TIMER1);
    
    timer_initpara.prescaler         = 2000-1;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 0xffffffff;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1,&timer_initpara);
    //匹配中断设置
    /*timer_channel_output_struct_para_init(&timer_ocintpara);
    timer_ocintpara.ocpolarity  = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER1,TIMER_CH_0,&timer_ocintpara);
    //设置通道0的比较值
    timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_0, 2000);
    timer_channel_output_mode_config(TIMER1, TIMER_CH_0, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);
    
    // 启用定时器更新中断和通道1匹配中断
    //timer_interrupt_enable(TIMERx, TIMER_INT_UP);
    timer_interrupt_enable(TIMER1, TIMER_INT_CH0);
    
    // 配置NVIC
    nvic_irq_enable(TIMER1_IRQn, 2, 0);
    */
    /* auto-reload preload enable */
    //timer_auto_reload_shadow_enable(TIMER1);
    /* TIMER1 enable */
    timer_enable(TIMER1);
  	
	//定时器4初始化，10ns定时器
	rcu_periph_clock_enable(RCU_TIMER4);
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
    timer_struct_para_init(&timer_initpara);
    timer_deinit(TIMER4);
    
    timer_initpara.prescaler         = 2-1;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 0xffffffff;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER4,&timer_initpara);
    
    /* auto-reload preload enable */
    timer_auto_reload_shadow_enable(TIMER4);
    /* TIMER1 enable */
    timer_enable(TIMER4);
    
    //定时器2配置成PWM输出  PC6、PC7、PC8、PC9输出IO
    /*rcu_periph_clock_enable(RCU_GPIOC);
    
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_6);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
    gpio_af_set(GPIOC, GPIO_AF_2,GPIO_PIN_6);
    
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_7);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);
    gpio_af_set(GPIOC, GPIO_AF_2,GPIO_PIN_7);
    
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_8);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
    gpio_af_set(GPIOC, GPIO_AF_2,GPIO_PIN_8);
    
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_9);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);
    gpio_af_set(GPIOC, GPIO_AF_2,GPIO_PIN_9);
    
    //定时器2初始化
	rcu_periph_clock_enable(RCU_TIMER2);
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
    timer_struct_para_init(&timer_initpara);
    timer_deinit(TIMER2);
    // TIMER2 configuration 
    timer_initpara.prescaler         = 400-1; //200M/4=50MHz
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 5000-1;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER2,&timer_initpara);

    // CH0-3 configuration in PWM mode 0 
    timer_channel_output_struct_para_init(&timer_ocintpara);
    timer_ocintpara.ocpolarity  = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;

    timer_channel_output_config(TIMER2,TIMER_CH_0,&timer_ocintpara);
    timer_channel_output_config(TIMER2,TIMER_CH_1,&timer_ocintpara);
    timer_channel_output_config(TIMER2,TIMER_CH_2,&timer_ocintpara);
    timer_channel_output_config(TIMER2,TIMER_CH_3,&timer_ocintpara);

    // CH0-3 configuration in PWM mode 0,duty cycle 25%~ 
    timer_channel_output_mode_config(TIMER2,TIMER_CH_0,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER2,TIMER_CH_0,TIMER_OC_SHADOW_DISABLE);
    
    timer_channel_output_mode_config(TIMER2,TIMER_CH_1,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER2,TIMER_CH_1,TIMER_OC_SHADOW_DISABLE);
    
    timer_channel_output_mode_config(TIMER2,TIMER_CH_2,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER2,TIMER_CH_2,TIMER_OC_SHADOW_DISABLE);
    
    timer_channel_output_mode_config(TIMER2,TIMER_CH_3,TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER2,TIMER_CH_3,TIMER_OC_SHADOW_DISABLE);
    
    timer_channel_output_pulse_value_config(TIMER2,TIMER_CH_0,2500);
    timer_channel_output_pulse_value_config(TIMER2,TIMER_CH_1,2500);
    timer_channel_output_pulse_value_config(TIMER2,TIMER_CH_2,2500);
    timer_channel_output_pulse_value_config(TIMER2,TIMER_CH_3,2500);
    
    // auto-reload preload enable 
    timer_auto_reload_shadow_enable(TIMER2);
    // TIMER2 enable 
    timer_enable(TIMER2);*/
}
/****************************************************************************************************
函数名称：Time2相关中断
函数说明：
输入参数：
返 回 值：
其    它：
1)调试过程中，如果断点设在本中断函数中，会出现计时中断失效的情况，这是由于Timer3在程序中断时计数不停所致。
2)中断周期为2ms。
****************************************************************************************************/
void TIMER1_IRQHandler(void)
{
    // 检查更新中断标志
    /*if(SET == timer_interrupt_flag_get(TIMERx, TIMER_INT_FLAG_UP)) 
    {
        timer_interrupt_count++;
        // 清除中断标志
        timer_interrupt_flag_clear(TIMERx, TIMER_INT_FLAG_UP);
    }*/
    
    // 检查通道1匹配中断标志
    if(SET == timer_interrupt_flag_get(TIMER1, TIMER_INT_FLAG_CH0)) 
    {
        TIMER_CH0CV(TIMER1)=TIMER_CH0CV(TIMER1)+100000;
        // 清除中断标志
        timer_interrupt_flag_clear(TIMER1, TIMER_INT_FLAG_CH0);
    }
    
    // 错误处理：检查定时器错误标志
    if(SET == timer_flag_get(TIMER1, TIMER_FLAG_CH0O)) {
        // 处理通道1溢出错误
        timer_flag_clear(TIMER1, TIMER_FLAG_CH0O);
    }
}
/****************************************************************************************************
函数名称：普通10ns计时器复位
函数说明：复位普通10ns计时器
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void G10nsTimerRes(G10nsTimer *Timer)
{
	Timer->StartTime=Get10nSTime();
}
/****************************************************************************************************
函数名称：普通10ns计时器时间计算函数
函数说明：计算经过的时间，单位10ns
输入参数：Timer--计时器
返 回 值：以10ns为单位的时间
其    它：
****************************************************************************************************/
U32 G10nsTimerCal(G10nsTimer *Timer)
{
	return (Get10nSTime()-Timer->StartTime);		//系统时间单位是10ns
}
/****************************************************************************************************
函数名称：普通10ns计时器时间超过比较函数
函数说明：比较是否已经超过期望时间，单位10ns
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool G10nsTimerOver(G10nsTimer *Timer,U32 CmpTime)
{
	return ((Get10nSTime()-Timer->StartTime)>CmpTime?mTrue:mFalse);	
}
/****************************************************************************************************
函数名称：普通10us计时器时间未到比较函数
函数说明：比较是否未到期望时间，单位10us
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool G10nsTimerLess(G10nsTimer *Timer,U32 CmpTime)
{
	return ((Get10nSTime()-Timer->StartTime)<CmpTime?mTrue:mFalse);	
}
/****************************************************************************************************
函数名称：延时n*1us
函数说明：
输入参数：DlyTi--延时时间，单位1us
返 回 值：无
其    它：
****************************************************************************************************/
void Dly1us(U32 DlyTi)
{
	G10nsTimer t;
	DlyTi=DlyTi*100;
	G10nsTimerRes(&t);
	while(G10nsTimerLess(&t,DlyTi)){;}
}
/****************************************************************************************************
函数名称：获取当前时间
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void GetCurrentTime(G10nsTimer *Timer)
{
	Timer->StartTime=Get10nSTime();
}
/****************************************************************************************************
函数名称：普通10us计时器复位
函数说明：复位普通10us计时器
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void G10usTimerRes(G10usTimer *Timer)
{
	Timer->StartTime=GetSysTime();
}
/****************************************************************************************************
函数名称：普通10us计时器时间计算函数
函数说明：计算经过的时间，单位10us
输入参数：Timer--计时器
返 回 值：以10us为单位的时间
其    它：
****************************************************************************************************/
U32 G10usTimerCal(G10usTimer *Timer)
{
	return (GetSysTime()-Timer->StartTime);		//系统时间单位是10us
}
/****************************************************************************************************
函数名称：普通10us计时器时间超过比较函数
函数说明：比较是否已经超过期望时间，单位10us
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool G10usTimerOver(G10usTimer *Timer,U32 CmpTime)
{
	return ((GetSysTime()-Timer->StartTime)>CmpTime?mTrue:mFalse);	
}
/****************************************************************************************************
函数名称：普通10us计时器时间未到比较函数
函数说明：比较是否未到期望时间，单位10us
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间未到；mFalse--时间已经超过
其    它：
****************************************************************************************************/
Bool G10usTimerLess(G10usTimer *Timer,U32 CmpTime)
{
	return ((GetSysTime()-Timer->StartTime)<CmpTime?mTrue:mFalse);	
}
/****************************************************************************************************
函数名称：普通10ms计时器复位
函数说明：复位普通10ms计时器
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void G10msTimerRes(G10msTimer *Timer)
{
	Timer->StartTime=GetSysTime();
}
/****************************************************************************************************
函数名称：普通100ms计时器复位
函数说明：复位普通100ms计时器
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void G100msTimerRes(G100msTimer *Timer)
{
	Timer->StartTime=GetSysTime();
}
/****************************************************************************************************
函数名称：普通10ms计时器时间计算函数
函数说明：计算经过的时间，单位10ms
输入参数：Timer--计时器
返 回 值：以10ms为单位的时间
其    它：
****************************************************************************************************/
U32 G10msTimerCal(G10msTimer *Timer)
{
	return (GetSysTime()-Timer->StartTime)/1000;		//系统时间单位是10us
}
/****************************************************************************************************
函数名称：普通100ms计时器时间计算函数
函数说明：计算经过的时间，单位100ms
输入参数：Timer--计时器
返 回 值：以100ms为单位的时间
其    它：
****************************************************************************************************/
U32 G100msTimerCal(G100msTimer *Timer)
{
	return (GetSysTime()-Timer->StartTime)/10000;	//系统时间单位是10us
}
/****************************************************************************************************
函数名称：普通10ms计时器时间超过比较函数
函数说明：比较是否已经超过期望时间，单位10ms
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool G10msTimerOver(G10msTimer *Timer,U32 CmpTime)
{
	return (GetSysTime()-Timer->StartTime)>(CmpTime*1000)?mTrue:mFalse;	
}
/****************************************************************************************************
函数名称：普通100ms计时器时间超过比较函数
函数说明：比较是否已经超过期望时间，单位100ms
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool G100msTimerOver(G100msTimer *Timer,U32 CmpTime)
{
	return (GetSysTime()-Timer->StartTime)>(CmpTime*10000)?mTrue:mFalse;	
}
/****************************************************************************************************
函数名称：普通10ms计时器时间未到比较函数
函数说明：比较是否未到期望时间，单位10ms
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool G10msTimerLess(G10msTimer *Timer,U32 CmpTime)
{
	return (GetSysTime()-Timer->StartTime)<(CmpTime*1000)?mTrue:mFalse;	
}
/****************************************************************************************************
函数名称：普通100ms计时器时间未到比较函数
函数说明：比较是否未到期望时间，单位100ms
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool G100msTimerLess(G100msTimer *Timer,U32 CmpTime)
{
	return (GetSysTime()-Timer->StartTime)<(CmpTime*10000)?mTrue:mFalse;	
}


/****************************************************************************************************
函数名称：超级10ms计时器复位
函数说明：复位超级10ms计时器
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void S10msTimerRes(S10msTimer *Timer)
{
	Timer->StartTime=GetSysTime();
	Timer->TotalTime=0;
	
	Timer->PauseFlag=mFalse;
}
/****************************************************************************************************
函数名称：超级100ms计时器复位
函数说明：复位超级100ms计时器
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void S100msTimerRes(S100msTimer *Timer)
{
	Timer->StartTime=GetSysTime();
	Timer->TotalTime=0;

	Timer->PauseFlag=mFalse;
}
/****************************************************************************************************
函数名称：超级10ms计时器计时暂停
函数说明：暂停计时
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void S10msTimerPause(S10msTimer *Timer)
{
	Timer->TotalTime+=GetSysTime()-Timer->StartTime;
	Timer->PauseFlag=mTrue;
}
/****************************************************************************************************
函数名称：超级100ms计时器计时暂停
函数说明：暂停计时
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void S100msTimerPause(S100msTimer *Timer)
{
	Timer->TotalTime+=GetSysTime()-Timer->StartTime;
	Timer->PauseFlag=mTrue;
}
/****************************************************************************************************
函数名称：超级10ms计时器计时继续
函数说明：继续计时
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void S10msTimerResume(S10msTimer *Timer)
{
	Timer->StartTime=GetSysTime();
	Timer->PauseFlag=mFalse;	
}
/****************************************************************************************************
函数名称：超级100ms计时器计时继续
函数说明：继续计时
输入参数：Timer--计时器
返 回 值：
其    它：
****************************************************************************************************/
void S100msTimerResume(S100msTimer *Timer)
{
	Timer->StartTime=GetSysTime();
	Timer->PauseFlag=mFalse;	
}
/****************************************************************************************************
函数名称：超级10ms计时器时间计算函数
函数说明：计算经过的时间，单位10ms
输入参数：Timer--计时器
返 回 值：以10ms为单位的时间
其    它：
****************************************************************************************************/
U32 S10msTimerCal(S10msTimer *Timer)
{
	if(Timer->PauseFlag)
		return Timer->TotalTime/1000;	//暂停状态
	else
		return (GetSysTime()-Timer->StartTime+Timer->TotalTime)/1000;		//系统时间单位是10us
	
}
/****************************************************************************************************
函数名称：超级100ms计时器时间计算函数
函数说明：计算经过的时间，单位100ms
输入参数：Timer--计时器
返 回 值：以100ms为单位的时间
其    它：
****************************************************************************************************/
U32 S100msTimerCal(S100msTimer *Timer)
{
	if(Timer->PauseFlag)
		return Timer->TotalTime/10000;	//暂停状态
	else
		return (GetSysTime()-Timer->StartTime+Timer->TotalTime)/10000;		//系统时间单位是10us
}
/****************************************************************************************************
函数名称：超级10ms计时器时间超过比较函数
函数说明：比较是否已经超过期望时间，单位10ms
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool S10msTimerOver(S10msTimer *Timer,U32 CmpTime)
{
	if(Timer->PauseFlag)
		return (Timer->TotalTime)>(CmpTime*1000)?mTrue:mFalse;	//暂停状态
	else
		return (GetSysTime()-Timer->StartTime+Timer->TotalTime)>(CmpTime*1000)?mTrue:mFalse;	
}
/****************************************************************************************************
函数名称：超级100ms计时器时间超过比较函数
函数说明：比较是否已经超过期望时间，单位100ms
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool S100msTimerOver(S100msTimer *Timer,U32 CmpTime)
{
	if(Timer->PauseFlag)
		return (Timer->TotalTime)>(CmpTime*10000)?mTrue:mFalse;	//暂停状态
	else
		return (GetSysTime()-Timer->StartTime+Timer->TotalTime)>(CmpTime*10000)?mTrue:mFalse;	
}
/****************************************************************************************************
函数名称：超级10ms计时器时间未到比较函数
函数说明：比较是否未到期望时间，单位10ms
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool S10msTimerLess(S10msTimer *Timer,U32 CmpTime)
{
	if(Timer->PauseFlag)
		return (Timer->TotalTime)<(CmpTime*1000)?mTrue:mFalse;	//暂停状态
	else
		return (GetSysTime()-Timer->StartTime+Timer->TotalTime)<(CmpTime*1000)?mTrue:mFalse;	
}
/****************************************************************************************************
函数名称：超级100ms计时器时间未到比较函数
函数说明：比较是否未到期望时间，单位100ms
输入参数：Timer--计时器；CmpTime--期望时间
返 回 值：mTrue--时间已经超过；mFalse--时间未到
其    它：
****************************************************************************************************/
Bool S100msTimerLess(S100msTimer *Timer,U32 CmpTime)
{
	if(Timer->PauseFlag)
		return (Timer->TotalTime)<(CmpTime*10000)?mTrue:mFalse;	//暂停状态
	else
		return (GetSysTime()-Timer->StartTime+Timer->TotalTime)<(CmpTime*10000)?mTrue:mFalse;	
}
/****************************************************************************************************
函数名称：延时n*1ms
函数说明：
输入参数：DlyTi--延时时间，单位1ms
返 回 值：无
其    它：
****************************************************************************************************/
void Dly1ms(U32 DlyTi)
{
	G10usTimer t;
	DlyTi=T1msTo10us(DlyTi);
	G10usTimerRes(&t);
	while(G10usTimerLess(&t,DlyTi)){;}
}
/****************************************************************************************************
函数名称：延时n*10us
函数说明：
输入参数：DlyTi--延时时间，单位10us
返 回 值：无
其    它：
****************************************************************************************************/
void Dly10us(U32 DlyTi)
{
	G10usTimer t;

	G10usTimerRes(&t);
	while(G10usTimerLess(&t,DlyTi)){;}
}
/****************************************************************************************************
函数名称：运行时间测量
函数说明：测量两个点之间程序执行时间，单位10us
输入参数：MeasStartFlag		mTrue-测量点开始	mFalse-测量点结束
返 回 值：运行时间
其    它：
****************************************************************************************************/
U32 RunTimeMeas_10us(Bool MeasStartFlag)
{
	static U32 RunTime_10us;
	
	if(MeasStartFlag)
	{	//设置测量开始点
		RunTime_10us=GetSysTime();
		return 0xffffffff;
	}
	else
	{	//测量结束点
		return GetSysTime()-RunTime_10us;
	}
}
/****************************************************************************************************
函数名称：时钟输出配置
函数说明：
输入参数：
返 回 值：
其    它：
****************************************************************************************************/
void clock_output_config(void)
{
    /* peripheral clock enable */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_PMU);
    //rcu_plli2s_config(200, 2);
    //rcu_osci_on(RCU_PLLI2S_CK);
    
    /* backup domain write enable */
    /*pmu_backup_write_enable();
    rcu_lxtal_drive_capability_config(RCU_LXTALDRI_HIGHER_DRIVE);
    rcu_osci_on(RCU_LXTAL);
    */
    /* configure clock output pin */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_8);
    //gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_9);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, GPIO_PIN_8);
    //gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, GPIO_PIN_9);
    gpio_af_set(GPIOA, GPIO_AF_0, GPIO_PIN_8);
    //gpio_af_set(GPIOC, GPIO_AF_0, GPIO_PIN_9);
    
    rcu_ckout0_config(RCU_CKOUT0SRC_PLLP, RCU_CKOUT0_DIV2);	//CLK0从主时钟，2分频
}



