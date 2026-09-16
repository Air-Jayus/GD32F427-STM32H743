/* Copyright (C) 2019 *****************************************************************************
									 杭州科强智能控制系统有限公司
====================================================================================================
项目名称：T6H5型注塑机控制器
项目简介：新一代注塑机控制器的软、硬件平台。软件方面要达到易扩展、易维护之目的。

======================================== 文   件    信   息 ========================================
文件名称：HADC_Drv.c
文件说明：HADC驱动

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
1、	SPP1	SCK		PF.4										经隔离极性相同
			SSEL	GPIO 1.8用作CS，但须软件以IO方式控制		经隔离极性相同	
			MISO	P1.3										经隔离极性相同
			MOSI	P1.4										经隔离极性相同
	
	mSBA_HADCPwrSta	0x000c	R	HADC电源状态		Bit0:0-正常、1-异常	在SimBus.h定义
2、AD7689的0通道对应硬件配置HardConf[mHSN_HADC+0]，n通道对应硬件配置HardConf[mHSN_HADC+n]。

##其它
1、AD7689特性：
	250ksps、16bit、8通道、SPI接口最高20MHz、转换时间为3.2us(采用内部时钟)ADC芯片
	SDI:下降沿锁存
	SDO:上升沿移出
	CS :当CS低，AD7689的SPI接口有效
	SCK:模式00，CS为低，SCK发出指定的脉冲后(4、16或48，取决于设置)，后续SCK脉冲会忽略，除非CS再次由高变低。
2、本驱动，产生输入信号的电压值（单位1uV），或为电子尺位置、或为压力传感器、或为其它信号，取决于硬件配置定义。
3、AD7689有8个通道，实际参与转换使用的通道数可定义，取决于机器参数Para_HADCNum，即0～(Para_HADCNum-1)通
   道有效。
4、本驱动只用到定时器3中断，通过定时来控制采样（数据读写）、ADC转换时间。
5、在定时器中断中，只是简单的获取ADC数据，然后在主循环的处理函数中经滤波、转换为电压值、写到对应资源。
6、转换循环：0-0-1-1-2-2-3-3-4-4-5-5-6-6-7-7-0-0	(最大通道取决于Para_HADCNum-1)，即每个通道转换2次。
7、滤波算法：窗口滤波算法，通过宏mWinFilteNum定义窗口大小，通过mOneChanTimes定义每个通道连续转换次数。

AD7689性能测试： 
10K电位器调至最中间：经4次取平均后，数据最大跳动4-5，应有14-位精度。
					 经8次取平均后，数据最大跳动3-4，应有14+位精度。

8、转换时间：AD采样率为39.2kps，一次转换用时约25.5us。
12、转换顺序：动态可变，允许一或二路设为高优先级（机器参数设置），高优先级的每隔一个通道就轮到一次转换，详细如下。
			一路高优先级：P(8次)--1通道(8次)--P(8次)--2通道(8次)……	
						 高优先级的每隔205us产生一组数据
						 低优先级的每隔2.87ms产生一组数据(用8通道时)
						 低优先级的每隔1.23ms产生一组数据(用4通道时)
			二路高优先级：P1(4次)--P2(4次)--1通道(4次)--P1(4次)--P2(4次)--2通道(4次)……	
						 高优先级的每隔?us产生一组数据
						 低优先级的每隔?ms产生一组数据(用8通道时)
						 低优先级的每隔?ms产生一组数据(用4通道时)
						 此情况主要用于双色机，有两组位置尺相关动作同时进行	

****************************************************************************************************/
//#define mSysDebug	

#ifndef HADC_Drv_c
	#define HADC_Drv_c
#endif

#include "Include.h"
/*======================================== 模块内有效宏定义 =======================================*/
#define	mHadcSPI	SPI2

//#define mSPI_BPS			800000		//SPI-SCK频率	当mPCLK_SPI为24MHz时，范围3MHz～93.75KHz
#define	mHADCChanMax		8	    //最大通道数
#define mChanFilteNum		16			//滤波次数		每个通道

#define mHADCTimer_5us		500			//100M	5us定时

#define AD768x_CS_Set() 	GPIO_BOP(GPIOA)=mBit4								//GPIOA4 CS 置高
#define AD768x_CS_Clr()		GPIO_BOP(GPIOA)=((U32)mBit4<<16)		//GPIOA4 CS 置低

//AD7689相关宏定义
//AD768x相关宏定义
#define mAD768x_SEL0		(((7<<10)+(0<<7)+mAD768xCFR_DEF)<<2)	//选择通道0
#define mAD768x_SEL1		(((7<<10)+(1<<7)+mAD768xCFR_DEF)<<2)	//选择通道1
#define mAD768x_SEL2		(((7<<10)+(2<<7)+mAD768xCFR_DEF)<<2)	//选择通道2
#define mAD768x_SEL3		(((7<<10)+(3<<7)+mAD768xCFR_DEF)<<2)	//选择通道3
#define mAD768x_SEL4		(((7<<10)+(4<<7)+mAD768xCFR_DEF)<<2)	//选择通道4
#define mAD768x_SEL5		(((7<<10)+(5<<7)+mAD768xCFR_DEF)<<2)	//选择通道5
#define mAD768x_SEL6		(((7<<10)+(6<<7)+mAD768xCFR_DEF)<<2)	//选择通道6
#define mAD768x_SEL7		(((7<<10)+(7<<7)+mAD768xCFR_DEF)<<2)	//选择通道7
#define mAD768x_Temp		(((3<<10)+(0<<7)+mAD768xCFR_DEF)<<2)	//选择温度通道

#define mAD768xCFR_DEF		(mBit13+mBit6+mBit0)		//CFR寄存器在本项目中的默认设置
														//更新CFR、全带宽、2.5V片内基准源、禁用序列、不回读

#define mAD768x_TempMin		(283-(40+25))*65536/2500	//-40度		ADC内部温度传感器的温度下限，超限则异常
#define mAD768x_TempMax		(283+(80-25))*65536/2500	//+80度		ADC内部温度传感器的温度上限，超限则异常
														//			当25度时电压为283mV，变化为1mV/度
U16 HADCChan_CMRTab[]={	//通道对应AD768x的CFG
	mAD768x_SEL0,mAD768x_SEL1,mAD768x_SEL2,mAD768x_SEL3,mAD768x_SEL4,mAD768x_SEL5,mAD768x_SEL6,mAD768x_SEL7,mAD768x_Temp};
	#define mAD768x_TempChan	8	//温度通道

/*======================================= 模块内有效变量定义 ======================================*/
U16 HADC_ADCBuff[mHADCChanMax][mChanFilteNum];	//ADC缓冲			直接ADC结果，尚未处理
Bool HADC_NewADCFlag[mHADCChanMax];				//新的ADC标志

U8 HADC_UseChanNum;					//使用通道数

	#define mSeqLen			22			//队列长度		2路优先级时：6*3+1(温度)、1路优先级时：3*2+1(温度)
	#define mSeqEnd			0xff		//队列结束
U8 HADC_CurrSeq[mSeqLen];			//当前转换序列		值0xff即序列结束		一个序列完成后，更新为HADC_NextSeq[]
U8 HADC_NextSeq[mSeqLen];			//下一转换序列		值0xff即序列结束		优先级调整申请时改该序列
	
static U8 SeqCnt,SeqNum;			//序列进行次数		序列总次数
static Bool PriReqFalg;				//序列变化标志

Bool HADCErrFlag;					//HADC异常标志

static U8 SeqChan_Next=mAD768x_TempChan;				//下一步对应的通道赋,初值为温度通道

//static U16 ErrADCDataCnt;		//异常ADC数据计数	SPI读到数据为0x0000、0xffff为异常数据
								//					异常数据连续24*4次则认为ADC转换可能存在异常，插
								//					入一次温度检查，如果也异常则置位ADC转换硬件出错
			 					//					根据实际程序，异常时最多22*4+22*4会插入一次温度
								//					检查，因为插入发生在一个序列完成时
	#define mErrADCDataCnt_Max	24*4	//异常数据最大计数

/*======================================= 模块内有效函数声明 ======================================*/
void __inline SPISendData(U16 SendData);	//SPI数据发送


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
函数名称：HADC处理
函数说明：
输入参数：无
返 回 值：无
其    它：
1、置于主循环。
****************************************************************************************************/
void HADC_Drv_Pcs(void)
{
	U32 HadcDataSum,i,j;
	static U8 LastHADC_NewADCFlag[mHADCChanMax];
	//U16 Buff[mChanFilteNum],Temp;
	//U8 i;

	//HADC转换结果处理
	for(i=0;i<HADC_UseChanNum;i++)
	{	
		if(HADC_NewADCFlag[i]!=LastHADC_NewADCFlag[i])
		{	//数据已经更新
			DisPerIRQ(SPI2_IRQn);				//关闭HADC相关定时器中断
			LastHADC_NewADCFlag[i]=HADC_NewADCFlag[i];
			
			//滤波:对指定窗口大小的数据取平均值
			HadcDataSum=HADC_ADCBuff[i][0];
			for(j=1;j<mChanFilteNum;j++)
				HadcDataSum+=(U32)HADC_ADCBuff[i][j];
			EnPerIRQ(SPI2_IRQn);						//开启中断
			//写入资源		以16位AD值形式
			WrResU32(HardConf[mHard_HAD01+i],HadcDataSum/mChanFilteNum);	
		}
			
		
		/*改简单平均值
		if(HADC_NewADCFlag[i])
		{	//数据已经更新
			//复制
			DisPerIRQ(SPI3_IRQn);			//关闭中断	
			HADC_NewADCFlag[i]=mFalse;
			
			Buff[0]=HADC_ADCBuff[i][0];
			Buff[1]=HADC_ADCBuff[i][1];
			Buff[2]=HADC_ADCBuff[i][2];
			Buff[3]=HADC_ADCBuff[i][3];
			EnPerIRQ(SPI3_IRQn);			//开启中断	

			//滤波:复合滤波算法,4个结果中去掉最高1个和最低1个,然后将剩余的2个取平均值
			//排序
			if(Buff[0]>Buff[1])	Temp=Buff[1],	Buff[1]=Buff[0],	Buff[0]=Temp;
			if(Buff[0]>Buff[2])	Temp=Buff[2],	Buff[2]=Buff[0],	Buff[0]=Temp;
			if(Buff[0]>Buff[3])	Temp=Buff[3],	Buff[3]=Buff[0],	Buff[0]=Temp;

			if(Buff[1]>Buff[2])	Temp=Buff[2],	Buff[2]=Buff[1],	Buff[1]=Temp;
			if(Buff[1]>Buff[3])	Temp=Buff[3],	Buff[3]=Buff[1],	Buff[1]=Temp;

			if(Buff[2]>Buff[3])	Temp=Buff[3],	Buff[3]=Buff[2],	Buff[2]=Temp;
			//写入资源		以16位AD值形式
			WrResU32(HardConf[mHard_HAD01+i],(Buff[1]+Buff[2])>>1);	
		}*/
	}
	
	//通道数检查
	if(HADC_UseChanNum!=HardConf_HADNum)
	{	//通道数发生变化 	通常是进行了重置
		DisPerIRQ(SPI2_IRQn);										//关闭中断
		HADC_UseChanNum=HardConf_HADNum;							//通道数
		if((HADC_UseChanNum==0)||(HADC_UseChanNum>mHADCChanMax))
			HADC_UseChanNum=mHADCChanMax;
		for(i=0;i<HADC_UseChanNum;i++)	HADC_NextSeq[i]=i;			//转换队列
		for(;i<mSeqLen;i++)				HADC_NextSeq[i]=mSeqEnd;	//队列结束
		EnPerIRQ(SPI2_IRQn);											//开启中断
	}
}
/****************************************************************************************************
函数名称：HADC优先级申请
函数说明：用于调整HADC转换的优先级，通常在执行某个动作时调用，将本动作相关的电子尺通道优先级调高。
输入参数：U16 ResSn	资源序号
返 回 值：mTrue--成功	mFalse--失败
其    它：
****************************************************************************************************/
Bool HADC_PriReq(U16 ResSn)
{
	U8 Chan,i,j,p;

	if(ResSn==mHADCPR_DefSeq)	
	{	//恢复默认序列
		DisPerIRQ(SPI2_IRQn);										//关闭中断
		for(i=0;i<HADC_UseChanNum;i++)	HADC_NextSeq[i]=i;			//转换队列
		for(;i<mSeqLen;i++)				HADC_NextSeq[i]=mSeqEnd;	//队列结束
		EnPerIRQ(SPI2_IRQn);											//开启中断
	
		return mTrue;
	}
	
	//搜索ResSN对应HADC通道
	for(Chan=0;Chan<HADC_UseChanNum;Chan++)
	{
		if(HardConf[mHard_HAD01+Chan]==ResSn)
		{	//通道找到		调整优先级
			if(Para_HADPriNum==0)
			{	//1路优先级
				
				DisPerIRQ(SPI2_IRQn);			//关闭中断	
				for(i=0,j=0;i<HADC_UseChanNum;i++)	
				{
					if(i!=Chan)
					{
						HADC_NextSeq[j]=Chan;	j++;
						HADC_NextSeq[j]=i;		j++;
					}
				}
				for(;j<mSeqLen;j++)
					HADC_NextSeq[j]=mSeqEnd;
				EnPerIRQ(SPI2_IRQn);				//开启中断	
				
			}
			else
			{	//2路优先级				
				DisPerIRQ(SPI2_IRQn);			//关闭中断	
				for(i=0,j=0,p=HADC_NextSeq[0];i<HADC_UseChanNum;i++)
				{
					if((i!=Chan)&&(i!=p))
					{
						HADC_NextSeq[j]=Chan;	j++;
						HADC_NextSeq[j]=p;		j++;
						HADC_NextSeq[j]=i;		j++;
					}
				}
				for(;j<mSeqLen;j++)
					HADC_NextSeq[j]=mSeqEnd;
				EnPerIRQ(SPI2_IRQn);				//开启中断	
				
			}
			return mTrue;
		}
	}
	return mFalse;
}
/****************************************************************************************************
函数名称：HADC电源检查
函数说明：
输入参数：mTrue--正常	mFalse--出错
返 回 值：
其    它：
1、PC9--HADC电源状态:0-正常、1-异常
****************************************************************************************************/
Bool HADC_PwrChk(void)
{
	return (!gpio_input_bit_get(GPIOC, GPIO_PIN_9));
}
/****************************************************************************************************
函数名称：HADC模块检查
函数说明：
输入参数：mTrue--正常	mFalse--出错
返 回 值：
其    它：
****************************************************************************************************/
Bool HADC_ModuleChk(void)
{
	return !HADCErrFlag;
}
/****************************************************************************************************
以下是应用级驱动函数：基于部分硬件完成应用功能
****************************************************************************************************/
/****************************************************************************************************
以下是硬件级驱动函数：完全基于硬件
****************************************************************************************************/
/****************************************************************************************************
函数名称：HADC初始化
函数说明：
输入参数：
返 回 值：
其    它：
1)TIM12的时钟为APB1的两倍，即100M。APB1为50M，APB2为100M。
2)SPI2属于APB1的外设.时钟频率为50M。APB1为50M，APB2为100M。
****************************************************************************************************/
void HADC_Drv_Init(void)
{
	volatile U32 Buff;
	timer_parameter_struct timer_initpara;    
    timer_oc_parameter_struct timer_ocintpara;
    spi_parameter_struct spi_init_struct;
	
	//变量初始化
	HADC_UseChanNum=HardConf_HADNum;			//通道数
	if((HADC_UseChanNum==0)||(HADC_UseChanNum>mHADCChanMax))
		HADC_UseChanNum=mHADCChanMax;
	if((GetHardPlatLinkCode()==0x5C)||(GetHardPlatLinkCode()==0x60))//E2或E4为HADC由AD7682配为AD7689（默认通道为0-7顺序的，但AD7682和AD7689引脚差异，硬件不改时，由4通道AD7682替换为8通道的AD7689要改变通道顺序）	20220311
	{
		HADCChan_CMRTab[0]=mAD768x_SEL0;
		HADCChan_CMRTab[1]=mAD768x_SEL2;
		HADCChan_CMRTab[2]=mAD768x_SEL5;
		HADCChan_CMRTab[3]=mAD768x_SEL7;
	}
	for(Buff=0;Buff<HADC_UseChanNum;Buff++)		//转换队列
	{
		HADC_CurrSeq[Buff]=Buff;
		HADC_NextSeq[Buff]=Buff;
	}
	SeqNum=HADC_UseChanNum;
	for(;Buff<mSeqLen;Buff++)			
	{
		HADC_CurrSeq[Buff]=mSeqEnd;				//队列结束
		HADC_NextSeq[Buff]=mSeqEnd;
	}
	
	

	HADCErrFlag=mFalse;
	//IO端口初始化
	//SSEL		PA4	CS
	//SCK		  PC10
	//MISO		PC11
	//MOSI		PC12
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_GPIOD);
   	rcu_periph_clock_enable(RCU_SPI2);
   	
   	//PC10 复用功能	SPI_SCK
	gpio_af_set(GPIOC, GPIO_AF_6, GPIO_PIN_10);
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_10);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);    
    //PC11 复用功能	SPI_MISO
	gpio_af_set(GPIOC, GPIO_AF_6, GPIO_PIN_11);
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_11);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_11);	
    //PC12 复用功能	SPI_MOSI
	gpio_af_set(GPIOC, GPIO_AF_6, GPIO_PIN_12);
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_12);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_12);
    //PA4	CS	输出IO
    gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLUP, GPIO_PIN_4);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_4);
	//PD0	HADC电源状态输入引脚
	gpio_mode_set(GPIOD, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO_PIN_0);
	
	AD768x_CS_Set();
	
	//SPI初始化
    spi_init_struct.trans_mode           = SPI_TRANSMODE_FULLDUPLEX;//全双工模式	
    spi_init_struct.device_mode          = SPI_MASTER;				//SPI主机 
    spi_init_struct.frame_size           = SPI_FRAMESIZE_16BIT;		//16位数据格式
    spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_1EDGE;	//空闲模式下SCK为0 CPOL=0;CPHA=0,数据采样从第1个时间边沿开始
    spi_init_struct.nss                  = SPI_NSS_SOFT;			//软件nss管理
    spi_init_struct.prescale             = SPI_PSC_64;				//Fsck=Fpclk1/64
    spi_init_struct.endian               = SPI_ENDIAN_MSB;			//MSB First  
    spi_init(mHadcSPI, &spi_init_struct);
    
    spi_ti_mode_disable(mHadcSPI);									//禁用TI模式(摩托罗拉模式)
    spi_i2s_interrupt_enable(mHadcSPI,SPI_I2S_INT_RBNE);			//接收中断开
    nvic_irq_enable(SPI2_IRQn, mIRQPriorityL,mIRQPriorityL);		//配置NVIC
    
	spi_enable(mHadcSPI);
	//定时器12初始化
	rcu_periph_clock_enable(RCU_TIMER12);
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
    timer_struct_para_init(&timer_initpara);
    timer_deinit(TIMER12);
    
	timer_initpara.prescaler         = 2-1;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 0xffffffff;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER12,&timer_initpara);
    
 	//匹配中断设置
    timer_channel_output_struct_para_init(&timer_ocintpara);
    timer_ocintpara.ocpolarity  = TIMER_OC_POLARITY_HIGH;
    timer_ocintpara.outputstate = TIMER_CCX_ENABLE;
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER12,TIMER_CH_0,&timer_ocintpara);
    //设置通道0的比较值
    timer_channel_output_pulse_value_config(TIMER12, TIMER_CH_0, mHADCTimer_5us);
    timer_channel_output_mode_config(TIMER12, TIMER_CH_0, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER12, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);
    // 启用定时器更新中断和通道0匹配中断
    //timer_interrupt_enable(TIMERx, TIMER_INT_UP);
    timer_interrupt_enable(TIMER12, TIMER_INT_CH0);
    // 配置NVIC
    nvic_irq_enable(TIMER7_UP_TIMER12_IRQn,mIRQPriorityL,mIRQPriorityL);
    // TIMER12 enable 
    timer_enable(TIMER12);
	
}
/****************************************************************************************************
函数名称：SPI中断和Timer3中断
函数说明：
输入参数：
返 回 值：
其    它：
1、SPI+T12的中断周期无Ecat约25-30.1us，有Ecat约25-35.1us,平均估计在26us。其中：SPI收发约21us、SPI中断
   程序执行用时约0.54-2.38us,T12中断约5us、T12中断程序执行用时约0.38-0.98us。
2、中断部分对CPU时间的占用约9～19%，平均估计在12%左右。
3、通道间有一定的影响，主要是换通道后的第一次ADC。如果通道间电压相差大，影响很明显，会有8左右的偏差。
4、AD结果精度：	经4次取平均值后，有约14位精度，50%量程的长时间跳动约4-6。
****************************************************************************************************/
void SPI2_IRQHandler(void)
{
	U16 RecBuff;
	U32 i;
	U8 Temp;	
	static Bool NewSeqFlag;
	
	if(SPI_STAT(SPI2)&SPI_STAT_RBNE)
	{	//SPI接收中断
		RecBuff=SPI_DATA(SPI2);						//SPI接收数据
		//启动ADC转换
		AD768x_CS_Set();						//置高	结束本次通讯并启动ADC转换
		//开启5us定时中断	即等待5us后ADC转换完成
		timer_interrupt_flag_clear(TIMER12, TIMER_INT_FLAG_CH0);//清除中断标志位 
		//TIMER_CH0CV(TIMER12)=TIMER_CNT(TIMER12)+mHADCTimer_5us;		//5uS匹配中断
		TIMER_CNT(TIMER12)=0;
		EnPerIRQ(TIMER7_UP_TIMER12_IRQn);									//开启中断
		
//		if((RecBuff==0)||(RecBuff==0xffff))
//			ErrADCDataCnt++;					//异常数据
//		else
//			ErrADCDataCnt=0,HADCErrFlag=mFalse;	//正常数据		直接复位
		
		//ADC转换处理		
		if(SeqNum>=2)	//防下标超出	
		{	//完成一个通道
			if(SeqCnt>=2)	//-2是因为AD768x的CFG延迟2个周期才生效
			{
				Temp=SeqCnt-2;		
				Temp=HADC_CurrSeq[Temp];	//获取通道号
				HADC_ADCBuff[Temp][HADC_NewADCFlag[Temp]++]=RecBuff;
				if(HADC_NewADCFlag[Temp]>=mChanFilteNum)
					HADC_NewADCFlag[Temp]=0;
				
				NewSeqFlag=mFalse;	//复位新序列标志
			}
			else if(NewSeqFlag==mFalse)
			{
				Temp=SeqNum+SeqCnt-2;
				Temp=HADC_CurrSeq[Temp];	//获取通道号
				HADC_ADCBuff[Temp][HADC_NewADCFlag[Temp]++]=RecBuff;
				if(HADC_NewADCFlag[Temp]>=mChanFilteNum)
					HADC_NewADCFlag[Temp]=0;
			}
		}
		SeqCnt++;
    	
		//if(SeqCnt==mHADCChanMax-2)		//-2是因为AD768x的CFG延迟2个周期才生效
		{	//准备下一通道			
			if((SeqCnt>=SeqNum)||(SeqCnt>=mSeqLen))
			{	//一个序列即将结束		复制新的序列
				SeqCnt=0;
				if(PriReqFalg==mTrue)
				{	//启动新序列
					NewSeqFlag=mTrue;
					PriReqFalg=mFalse;
					for(i=0;i<mSeqLen;i++)	
					{
						HADC_CurrSeq[i]=HADC_NextSeq[i];
						if(HADC_NextSeq[i]==mSeqEnd)
						{
							SeqNum=i;		//记录有多少个有效序列
							break;
						}
    				}
    			}
//				if(ErrADCDataCnt>=mErrADCDataCnt_Max)
//				{	//ADC数据连续异常，插入一次温度检查
//					for(i=0;i<mSeqLen;i++)
//					{
//						if(HADC_CurrSeq[i]>mAD768x_TempChan)
//						{
//							HADC_CurrSeq[i]=mAD768x_TempChan;
//							ErrADCDataCnt=0;
//							SeqNum++;
//							break;
//						}
//					}
//				}
			}			
		}
		
		SeqChan_Next=HADC_CurrSeq[SeqCnt];
	}
}
void TIMER7_UP_TIMER12_IRQHandler(void)
{
	if(SET == timer_interrupt_flag_get(TIMER12, TIMER_INT_FLAG_CH0)) 
	{	
		timer_interrupt_flag_clear(TIMER12, TIMER_INT_FLAG_CH0);//清除中断标志位 
		DisPerIRQ(TIMER7_UP_TIMER12_IRQn);										//关闭中断
		SPISendData(HADCChan_CMRTab[SeqChan_Next]);	//发下一通道
	}
}

/****************************************************************************************************
函数名称：SPI发送数据
函数说明：
输入参数：
返 回 值：
其    它：
1、CS下降沿到SCK上升沿，延迟约900ns。
****************************************************************************************************/
void __inline SPISendData(U16 SendData)
{
	AD768x_CS_Clr();			//选中AD768x			开始数据发送
	SPI_DATA(SPI2)=SendData;	//SPI发送数据
}

