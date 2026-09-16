/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：LADC_Drv.c
文件说明：温度测量文件

作    者：WLZ
编写时间：2025.4
======================================== 修   改    历   史 ========================================
修 改 人：
修改日期：
修改说明：

修 改 人：
修改日期：
修改说明：
======================================== 其   它    说   明 ========================================
##系统资源
1、	TIM4一个16位计数器，用来计数LADC的V/F转换。对于1MHz频率最多能计65.536mS时间而不会溢出，因此每一次的转换时间不要超过60mS最好，不然可能会因为计数溢出而造成错误

##其它
1、 AD7740 的ADC驱动程序，AD7740为V/F转换器，特点如下：
	AD7740 输入0V时输出频率为100KHz，输入2.5V时输出频率为900KHz，灵敏度为320kHz/V
	AD8237的方大公式为VOUT = G(VIN+ - VIN-) + VREF ，其中G = 96.52381
	K型热电偶灵敏度约为41uV每摄氏度，每摄氏度放大后为4mV
	f=Cnt*100000/Tc  其中，Cnt为计数，Tc为周期，单位10us，f为测量频率，单位Hz
	V=(f-100KHz)/320kHz/V  V为V/F转换后的测量电压，单位V
	T=(V-200mV)/4mV/℃ T为温度，单位℃
	上述公式计算得出：T=Cnt*78.125/Tc-128.125 ，其中T为温度，单位℃，Cnt为计数，Tc为周期，单位10us
	补偿算法：
	AD8237的方大公式为VOUT = G(VIN+ - VIN-) + VREF ，其中G = 96.52381
	K型热电偶灵敏度约为41uV每摄氏度，每摄氏度放大后为4mV
	f=Cnt*100000/Tc  其中，Cnt为计数，Tc为周期，单位10us，f为测量频率，单位Hz
	V测=(f-100KHz)/320kHz/V  V为V/F转换后的测量电压，单位V
	V补=0.000063*G=0.000063*96.52381=0.006081V
	V=V测-V补
	T测=(V-200mV)/4mV/℃ T为温度，单位℃
	上述公式计算得出：T测=Cnt*78.125/Tc-129.64525 ，其中T为温度，单位℃，Cnt为计数，Tc为周期，单位10us
	T=1.0107*T测+1.5366℃
	计算得出：T=78.961*Cnt/Tc-129.496 其中T为温度，单位℃，Cnt为计数，Tc为周期，单位10us
	
2、LADC时序1：通道数9
	16通道5秒完成一轮,每通道555.55ms；
	稳定120ms--53ms转换(共8次)--下一通道(空11.55ms)；
	性能测试：通道1使用10.15mV基准源，通道2短接，测试时间20分钟(240次)，通道1-通道2的最大波动为0.23摄氏度	
	
3、LADC时序2：通道数1～8
	8通道5秒完成一轮,每通道625ms；
	稳定120ms--60ms转换(共8次)--下一通道(空25ms)；
	性能测试：通道1使用10.15mV基准源，通道2短接，测试时间20分钟(240次)，通道1-通道2的最大波动为0.15摄氏度	
	
	注：1)利用Time_Drv.h提供的计时函数，在主循环中判断检查各时序节点，因此时序中各时间都可能会存在ms级的
	误差。因此，一方面使用t=2000*Cnt/T该公式来计算温度，减少时间不准带来的误差；另一方面通过一通道转换理
	论时间小于0.625秒，而由定时中断每0.625秒准确启动一个通道的办法来保证一轮周期的准确性。
	2)每通道5秒产生一次温度值，经资源函数更新到对应温度变量中（经Bit31标示更新）。Temp.c中利用该时间周期
	准确的温度值刷新，启动一个通道的控温处理。因此，本驱动在做修改时，须保证此时序上与Temp.c中控温函数的
	协调。
	
4、滤波算法：8次VFC值，丢弃最大2个和最小1个，中间6个取平均值
5、有时序上的修改，须非常注意对Temp.c中温控函数的影响。
6、更新到资源的数据已做断电、断偶和超温检查，并转换成相应出错值（8888等）。
7、通道与硬件配置的对应关系为：通道1	对应HardConf[mHSN_LADC+0]；通道2	对应HardConf[mHSN_LADC+1]

8、通道切换使用3-8译码器，目前H3使用8组输入。
LAC_A1 PD10
LAC_A2 PD11
LAC_A3 PD12
LAC_A4 PB14
LAC_A5 PB15
****************************************************************************************************/
//#define mSysDebug		

#ifndef LADC_Drv_c
	#define LADC_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define mPwmPeriodL		T1msTo10us(20)					//PWM周期时间

#define mLADCVRef			330000		//参考源电压			单位10uV
#define mLADCVZero			20000		//0度时的电压偏移		单位10uVV
#define mCelsV				400			//每摄氏度对应的电压	单位10uV

#define mPwrOffAdc			100				//断电计数下限	小于则断电	如果参考源为3.3V，0摄氏度200mV电压对应AD值3787
#define mTherBrkAdc			50000			//断偶频率上限	大于则断偶	
#define mTempRange			480000			//温度量程		可设范围0-450、工作范围0-480

#define mLADC_ChanNumConf1	10				//通道数配置1	10通道
#define mLADC_ChanNumConf2	8				//通道数配置2	8通道

#define mLADCTi_Chan1		50000			//通道时间		500ms	一个通道的转换时间
#define mLADCTi_Chan2		62500			//通道时间		625ms	一个通道的转换时间
#define mLADCTi_ChanDly	T1msTo10us(185)	//通道延时时间	185ms	


//#define LADC_A1_3_ST(a) GPIO_BOP(GPIOC)	=((((a)&0x0007)<<0)|((((~(a))&0x0007))<<(0+16)))		//设地址
void LADC_A1_3_ST(U16 a) 
{
	a=(a<<1)|(a&0x000001);
	GPIO_BOP(GPIOC)	=((((a)&0x000f)<<0)|((((~(a))&0x000f))<<(0+16)));
}
#define LADC_A4_SET()   //GPIO_BOP(GPIOB)	=mBit14		
#define LADC_A4_CLR()   //GPIO_BC(GPIOB)	=mBit14
#define LADC_A5_SET()   //GPIO_BOP(GPIOB)	=mBit15		
#define LADC_A5_CLR()   //GPIO_BC(GPIOB)	=mBit15

/*======================================= 模块内有效变量定义 ======================================*/
static U16 CntL = 0, CntH = 0;
static Bool ADCMeasComp;	//ADC转换完成
static Bool MeasFlag;	//测量到上升和下降沿标志
static Bool EdgeFlag;	//有测量到边沿标志
static U8	MeasStep;
	#define	mLS_Rdy		0		//等待检测到一个下降沿，作为完成测量准备
	#define	mLS_Risi	1		//等待检测上升沿
	#define	mLS_Fall	2		//等待检测下降沿
static G10usTimer MeasEdgeTimer;		//边沿出现超时时间

U32 LADCSum;			//ADC值累加
U32 LADCTi_Chan;		//一通道转换时间	
U8 LADC_ChanNum;		//转换通道数		8或10
	
U8 LADC_Chan=1;			//当前进行VF转换的通道		1-16最多16通道，为0则无通道选中
	#define	mLADC_ChanNull	0	
	#define	mLADC_Chan1		1	
	#define	mLADC_Chan2		2	
	//……
U8 LADC_Step=12;		//ADC步骤
	#define mLADCStatr		1	//开始转换
	#define mChanDly		2	//通道延时				处于信号稳定，通道已经选择	80ms
	#define mLADC			10	//第一次ADC											60ms、30ms
	
	#define mTherBrkChk		250	//断偶检查兼切换延时		处理数据						30ms
	#define mDataCal		251	//数据计算				数据分2次处理，以减小资源占用
	#define mLADCFree		0	//空闲					等待启动新一轮ADC			40ms、30ms

Bool LADCPwrErrFlag=mFalse;		//电源出错标志

/*======================================= 模块内有效函数声明 ======================================*/
void LADCChanSel(U16 chan);//LADC通道选择

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
函数名称：LADC处理函数
函数说明：
输入参数： 
返 回 值：
其    它：
1、置于主循环。
2、通道与硬件配置相对应:	通道1	对应HardConf[mHard_LAD01+0]
							通道n	对应HardConf[mHard_LAD01+n]
3、提供软件校准，用软件校准在M4核里完成，主要是为了M4或M0核只有一个地方去引用机器参数。
****************************************************************************************************/
void LADC_Drv_Pcs(void)
{
	static G10usTimer LADC_StepTimer;	//步骤计时器		时间到转下一步骤
	static G10usTimer LADC_ChanTimer;	//通道计时器		时间到转下一通道
	U32 Temp;
	
    //根据硬件平台通道数配置		放在主循环目的是：重置后通道数立即更新
	if(HardConf_LADNum<=mLADC_ChanNumConf2)
	{	                                  //温度处理周期是5S,8个通道要在5S内完成一次采样，即每个通道采样周期625ms,每个通道一个周期转换8次滤波取均值
		LADCTi_Chan=mLADCTi_Chan2;				//通道时间		625ms    实际采样时间：120+60*8=600ms
		//LADCTi_LADC=mLADCTi_LADC2;				//转换次数
		LADC_ChanNum=mLADC_ChanNumConf2;	//转换通道数	8通道
	}
	else
	{                                   //温度处理周期是5S,10个通道要在5S内完成一次采样，即每个通道采样周期500ms每个通道一个周期转换8次滤波取均值
		LADCTi_Chan=mLADCTi_Chan1;				//通道时间		500ms 实际采样时间：120+45*8=480ms
		//LADCTi_LADC=mLADCTi_LADC1;				//转换次数
		LADC_ChanNum=mLADC_ChanNumConf1;	//转换通道数	10通道
	}
	//AD值测量出错检查
	if(EdgeFlag==mTrue)
	{
		EdgeFlag=mFalse;
		G10usTimerRes(&MeasEdgeTimer);
	}
	else if(G10usTimerOver(&MeasEdgeTimer,mPwmPeriodL+T1msTo10us(5)))
    {	//1.5倍PWM周期未检测到边沿，认为全高或全低
    	G10usTimerRes(&MeasEdgeTimer);
    	
    	if(GPIO_ISTAT(GPIOB)&mBit7)	Temp=0x3ffff;
    	else						Temp=0x00000;
    	MeasStep = mLS_Rdy;		//等待检测到一个下降沿，作为完成测量准备;
    	MeasFlag=mFalse;
    	
    	ADCMeasComp=mTrue;	//ADC测量完成标志
    }
    else if(MeasFlag)
    {
    	MeasFlag=mFalse;
    	Temp=(CntH<<16)/((U32)CntL+(U32)CntH);
    	
    	ADCMeasComp=mTrue;	//ADC测量完成标志
    }
	
	//转换流程
	if(LADC_Step==mLADCStatr)
	{	//开始转换	选择通道
		G10usTimerRes(&LADC_StepTimer);
		LADC_Step=mChanDly;
		LADCChanSel((LADC_Chan-1));//通道选中
	}
	else if(LADC_Step==mChanDly)
	{	//信号稳定
		if(G10usTimerOver(&LADC_StepTimer,mLADCTi_ChanDly))
		{	//稳定时间到	转下一步
			LADC_Step=mLADC;
			
			ADCMeasComp=mFalse;	//ADC测量完成标志
			LADCSum=0;			//ADC值累加
			G10usTimerRes(&LADC_StepTimer);
			
		}
	}	
	else if(LADC_Step>=mLADC)
	{	//VFC
		if(ADCMeasComp)	//ADC测量完成标志
		{	//完成一次测量
			ADCMeasComp=mFalse;
			LADCSum+=Temp;
			LADC_Step++;
		}
	}
	//else if(LADC_Step==mLADCFree)
	//{	//空闲
	//}
	//启动下一通道、刚才通道数据写入资源
	if(G10usTimerOver(&LADC_ChanTimer,LADCTi_Chan))
	{	//开始下一通道	后一条件是为了避免：如果主循环执行时间很长(持续大于3ms)，则可能在断电检查时一个循环就结束了，使得该通道被提前结束，产生异常
		G10usTimerRes(&LADC_ChanTimer);
		
		LADCSum/=(LADC_Step-mLADC);
		if(LADCSum==0)						//断电
			Temp=mLADC_PwrOff_001C;
		else if(LADCSum>mTherBrkAdc)				//断偶
			Temp=mLADC_TherBrk_001C;
		else
		{	//
			//Temp=((U64)LADCSum*mLADCVRef/65536-mLADCVZero)*1000/mCelsV;
			Temp=mLADCVRef/16;		//先约掉一点，不至于超出32位
			Temp=LADCSum*Temp;//	/(65536/16);
			if(Temp>(mLADCVZero*(65536/16)))	
			{
				Temp=(U64)(Temp-(mLADCVZero*(65536/16)))*1010/(65536/16);		//正常计数温度
				Temp/=mCelsV;
				//温度软件校准处理
				if((Para_TempCalK<=115)&&(Para_TempCalK>= 85)&&				//K值有效
				   (Para_TempCalB_N<=10000)&&(Para_TempCalB_P<=10000))		//B值有效
				{	
					Temp=Temp*Para_TempCalK/100+Para_TempCalB_P;	//用户修正	
					Temp=Sub_MinZero(Temp,Para_TempCalB_N);
				}
				if((Temp>mTempRange)&&(Temp!=mLADC_TherBrk_001C)&&(Temp!=mLADC_PwrOff_001C))
	   			{	//超量程检查
	   				Temp=mLADC_OverRange_001C;
	   			}
			}
			else				Temp=0;									//-26度以下温度
		}
			
		//当前通道的数据更新到资源
		WrResU32(HardConf[mHard_LAD01+LADC_Chan-1],Temp|mBit31);	//Temp_LADC已经是温度值，单位0.01C
		
		//当前通道调整
		if(LADC_Chan>=LADC_ChanNum)	LADC_Chan=mLADC_Chan1;				//注意是通道1开始
		else						LADC_Chan++;			
		LADC_Step=mLADCStatr;
	}
}
/****************************************************************************************************
函数名称：LADC初始化
函数说明：
输入参数：
返 回 值：
其    它：
1、必须在Time_Drv_Init()、及HardPlat_Drv_Init()之后执行。
2、TIM3的时钟为APB1的两倍，即100M。APB1为50M，APB2为100M。
****************************************************************************************************/
void LADC_Drv_Init(void)
{	
	timer_parameter_struct timer_initpara;    
    timer_ic_parameter_struct timer_icinitpara;
    
	/* 1. 启用外设时钟 */
    //rcu_periph_clock_enable(RCU_GPIOB);    // 启用GPIOB时钟
    rcu_periph_clock_enable(RCU_GPIOC);    // 启用GPIOC时钟
    rcu_periph_clock_enable(RCU_TIMER3);  // 启用TIMER3时钟

    /* 2. 配置GPIO引脚 - PB7 (TIMER3_CH1) */
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_7);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);
    gpio_af_set(GPIOB, GPIO_AF_2, GPIO_PIN_7);  // TIMER3_CH1的AF2
    
    //设置为输出：地址线A0～A2	PC0/PC2/PC3	
	gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, mBit0|mBit2|mBit3);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,mBit0|mBit2|mBit3);
    
    //设置为输出：地址线A4～A5	PB14-PB15	
	//gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, mBit14|mBit15);
    //gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,mBit14|mBit15);

    /* 3. 定时器基本参数配置 */
    timer_struct_para_init(&timer_initpara);
    
    timer_initpara.prescaler         = 64-1;      // 64分频   200M经64分频到3.125M	50HzPwm波分辨力达到62500
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 0xFFFFFFFF; // 32位最大值
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER3, &timer_initpara);

    /* 4. 配置输入捕获 */
    timer_channel_input_struct_para_init(&timer_icinitpara);
    
    timer_icinitpara.icpolarity  = TIMER_IC_POLARITY_FALLING; // 下降沿计数
    timer_icinitpara.icselection = TIMER_IC_SELECTION_DIRECTTI;
    timer_icinitpara.icprescaler = TIMER_IC_PSC_DIV1;
    timer_icinitpara.icfilter    = 0;  // 无滤波
    
    timer_input_capture_config(TIMER3, TIMER_CH_1, &timer_icinitpara);
	MeasStep = mLS_Rdy;		//等待检测到一个下降沿，作为完成测量准备;
    // 配置输入捕获中断
    timer_interrupt_flag_clear(TIMER3, TIMER_INT_FLAG_CH1);
    timer_interrupt_enable(TIMER3, TIMER_INT_CH1);
    nvic_irq_enable(TIMER3_IRQn, mIRQPriorityL, mIRQPriorityL);

    /* 6. 启用定时器 */
    timer_enable(TIMER3);
    
    G10usTimerRes(&MeasEdgeTimer);
}
void TIMER3_IRQHandler(void)
{
	static U16 CntRisi,CntFall;
	static U16 CL;
    if(timer_interrupt_flag_get(TIMER3, TIMER_INT_FLAG_CH1))
    {
        timer_interrupt_flag_clear(TIMER3, TIMER_INT_FLAG_CH1);
       	
       	//G10usTimerRes(&MeasEdgeTimer);
       	EdgeFlag=mTrue;
        switch(MeasStep)
        {
        case mLS_Risi: // 捕获上升沿
           
            CntRisi = TIMER_CH1CV(TIMER3);
            CL=CntRisi-CntFall;
            //设置成下降沿捕获
            TIMER_CHCTL2(TIMER3) &= (~(U32)(TIMER_CHCTL2_CH1P | TIMER_CHCTL2_CH1NP));
        	TIMER_CHCTL2(TIMER3) |= (U32)((U32)(TIMER_IC_POLARITY_FALLING) << 4U);
            MeasStep = mLS_Fall;
            break;

        case mLS_Fall: // 捕获下降沿
            CntFall = TIMER_CH1CV(TIMER3);
            CntH=CntFall-CntRisi;
            //设置成上升沿捕获
            TIMER_CHCTL2(TIMER3) &= (~(U32)(TIMER_CHCTL2_CH1P | TIMER_CHCTL2_CH1NP));
        	TIMER_CHCTL2(TIMER3) |= (U32)((U32)(TIMER_IC_POLARITY_RISING) << 4U);
        	MeasStep = mLS_Risi;
            CntL=CL;
            MeasFlag=mTrue;
            break;
        case mLS_Rdy:	//捕获一个下降沿，准备完成
        	CntFall = TIMER_CH1CV(TIMER3);          
            //设置成上升沿捕获
            TIMER_CHCTL2(TIMER3) &= (~(U32)(TIMER_CHCTL2_CH1P | TIMER_CHCTL2_CH1NP));
        	TIMER_CHCTL2(TIMER3) |= (U32)((U32)(TIMER_IC_POLARITY_RISING) << 4U);
        	MeasStep = mLS_Risi;
        break;
        }
    }
}
/****************************************************************************************************
函数名称：LADC电源检查
函数说明：
输入参数：
返 回 值：mTrue--电源正常	mFalse--未加电
其    它：
****************************************************************************************************/
Bool LADC_PwrChk(void)
{
	return(!LADCPwrErrFlag);
}
/****************************************************************************************************
函数名称：LADC通道选择
函数说明：
输入参数：chan：通道
返 回 值：
其    它：
****************************************************************************************************/
void LADCChanSel(U16 chan)
{
	if(chan<=7)//0-7通道使用38译码器输出
	{
		LADC_A4_CLR();//关通道8
		LADC_A5_CLR();//关通道9
		LADC_A1_3_ST(chan);
	}
	else if(chan==8)//8-9通道使用三极管输出
	{
		LADC_A5_CLR();//关通道9
		LADC_A4_SET();//开通道8
	}
	else if(chan==9)
	{
		LADC_A4_CLR();//关通道8
		LADC_A5_SET();//开通道9
	}
}
